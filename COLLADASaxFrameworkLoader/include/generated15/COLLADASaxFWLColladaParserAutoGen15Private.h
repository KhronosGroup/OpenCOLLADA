/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15PRIVATE_H__
#define __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15PRIVATE_H__


#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserParserTemplate.h"
#include "pcre.h"
#include "COLLADASaxFWLColladaParserAutoGen15Attributes.h"
#include "COLLADASaxFWLColladaParserAutoGen15.h"
#include "COLLADASaxFWLColladaParserAutoGen15ValidationData.h"


namespace COLLADASaxFWL15
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


class ColladaParserAutoGen15Private : public GeneratedSaxParser::ParserTemplate<ColladaParserAutoGen15Private, ColladaParserAutoGen15>
{
public:
ColladaParserAutoGen15Private( COLLADASaxFWL15::ColladaParserAutoGen15* impl, GeneratedSaxParser::IErrorHandler* errorHandler = 0 );
virtual ~ColladaParserAutoGen15Private();


private:
friend class FunctionMapFactory;


bool _begin__COLLADA( void* attributeData ){return mImpl->begin__COLLADA(*static_cast<COLLADA__AttributeData*>(attributeData));}
bool _data__COLLADA( const ParserChar* text, size_t textLength );
bool _end__COLLADA(){return mImpl->end__COLLADA();}
bool _preBegin__COLLADA( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__COLLADA();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__COLLADA( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__COLLADA();
#endif
bool _freeAttributes__COLLADA( void* attributeData );


ENUM__version_enum toEnumDataPrefix_ENUM__version_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__version_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__version_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__version_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__version_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__version_enum*, size_t ),
    const std::pair<StringHash, ENUM__version_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__version_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__version_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__asset( void* attributeData ){return mImpl->begin__asset();}
bool _data__asset( const ParserChar* text, size_t textLength );
bool _end__asset(){return mImpl->end__asset();}
bool _preBegin__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__asset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__asset();
#endif
bool _freeAttributes__asset( void* attributeData );

bool _begin__contributor( void* attributeData ){return mImpl->begin__contributor();}
bool _data__contributor( const ParserChar* text, size_t textLength );
bool _end__contributor(){return mImpl->end__contributor();}
bool _preBegin__contributor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__contributor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__contributor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__contributor();
#endif
bool _freeAttributes__contributor( void* attributeData );

bool _begin__author( void* attributeData ){return mImpl->begin__author();}
bool _data__author( const ParserChar* text, size_t textLength );
bool _end__author(){return mImpl->end__author();}
bool _preBegin__author( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__author();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__author( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__author();
#endif
bool _freeAttributes__author( void* attributeData );

bool _begin__author_email( void* attributeData ){return mImpl->begin__author_email();}
bool _data__author_email( const ParserChar* text, size_t textLength );
bool _end__author_email(){return mImpl->end__author_email();}
bool _preBegin__author_email( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__author_email();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__author_email( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__author_email();
#endif
bool _freeAttributes__author_email( void* attributeData );

bool _begin__author_website( void* attributeData ){return mImpl->begin__author_website();}
bool _data__author_website( const ParserChar* text, size_t textLength );
bool _end__author_website(){return mImpl->end__author_website();}
bool _preBegin__author_website( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__author_website();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__author_website( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__author_website();
#endif
bool _freeAttributes__author_website( void* attributeData );

bool _begin__authoring_tool( void* attributeData ){return mImpl->begin__authoring_tool();}
bool _data__authoring_tool( const ParserChar* text, size_t textLength );
bool _end__authoring_tool(){return mImpl->end__authoring_tool();}
bool _preBegin__authoring_tool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__authoring_tool();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__authoring_tool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__authoring_tool();
#endif
bool _freeAttributes__authoring_tool( void* attributeData );

bool _begin__comments( void* attributeData ){return mImpl->begin__comments();}
bool _data__comments( const ParserChar* text, size_t textLength );
bool _end__comments(){return mImpl->end__comments();}
bool _preBegin__comments( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__comments();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__comments( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__comments();
#endif
bool _freeAttributes__comments( void* attributeData );

bool _begin__copyright( void* attributeData ){return mImpl->begin__copyright();}
bool _data__copyright( const ParserChar* text, size_t textLength );
bool _end__copyright(){return mImpl->end__copyright();}
bool _preBegin__copyright( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__copyright();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__copyright( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__copyright();
#endif
bool _freeAttributes__copyright( void* attributeData );

bool _begin__source_data( void* attributeData ){return mImpl->begin__source_data();}
bool _data__source_data( const ParserChar* text, size_t textLength );
bool _end__source_data(){return mImpl->end__source_data();}
bool _preBegin__source_data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__source_data();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__source_data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__source_data();
#endif
bool _freeAttributes__source_data( void* attributeData );

bool _begin__coverage( void* attributeData ){return mImpl->begin__coverage();}
bool _data__coverage( const ParserChar* text, size_t textLength );
bool _end__coverage(){return mImpl->end__coverage();}
bool _preBegin__coverage( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__coverage();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__coverage( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__coverage();
#endif
bool _freeAttributes__coverage( void* attributeData );

bool _begin__geographic_location( void* attributeData ){return mImpl->begin__geographic_location();}
bool _data__geographic_location( const ParserChar* text, size_t textLength );
bool _end__geographic_location(){return mImpl->end__geographic_location();}
bool _preBegin__geographic_location( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__geographic_location();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__geographic_location( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__geographic_location();
#endif
bool _freeAttributes__geographic_location( void* attributeData );

bool _begin__longitude( void* attributeData ){return mImpl->begin__longitude();}
bool _data__longitude( const ParserChar* text, size_t textLength );
bool _end__longitude(){return mImpl->end__longitude();}
bool _preBegin__longitude( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__longitude();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__longitude( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__longitude();
#endif
bool _freeAttributes__longitude( void* attributeData );

bool _begin__latitude( void* attributeData ){return mImpl->begin__latitude();}
bool _data__latitude( const ParserChar* text, size_t textLength );
bool _end__latitude(){return mImpl->end__latitude();}
bool _preBegin__latitude( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__latitude();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__latitude( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__latitude();
#endif
bool _freeAttributes__latitude( void* attributeData );

bool _begin__altitude( void* attributeData ){return mImpl->begin__altitude(*static_cast<altitude__AttributeData*>(attributeData));}
bool _data__altitude( const ParserChar* text, size_t textLength );
bool _end__altitude(){return mImpl->end__altitude();}
bool _preBegin__altitude( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__altitude();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__altitude( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__altitude();
#endif
bool _freeAttributes__altitude( void* attributeData );


ENUM__altitude_mode_enum toEnumDataPrefix_ENUM__altitude_mode_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__altitude_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__altitude_mode_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__altitude_mode_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__altitude_mode_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__altitude_mode_enum*, size_t ),
    const std::pair<StringHash, ENUM__altitude_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__altitude_mode_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__altitude_mode_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__created( void* attributeData ){return mImpl->begin__created();}
bool _data__created( const ParserChar* text, size_t textLength );
bool _end__created(){return mImpl->end__created();}
bool _preBegin__created( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__created();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__created( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__created();
#endif
bool _freeAttributes__created( void* attributeData );

bool _begin__keywords( void* attributeData ){return mImpl->begin__keywords();}
bool _data__keywords( const ParserChar* text, size_t textLength );
bool _end__keywords(){return mImpl->end__keywords();}
bool _preBegin__keywords( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__keywords();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__keywords( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__keywords();
#endif
bool _freeAttributes__keywords( void* attributeData );

bool _begin__modified( void* attributeData ){return mImpl->begin__modified();}
bool _data__modified( const ParserChar* text, size_t textLength );
bool _end__modified(){return mImpl->end__modified();}
bool _preBegin__modified( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__modified();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__modified( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__modified();
#endif
bool _freeAttributes__modified( void* attributeData );

bool _begin__revision( void* attributeData ){return mImpl->begin__revision();}
bool _data__revision( const ParserChar* text, size_t textLength );
bool _end__revision(){return mImpl->end__revision();}
bool _preBegin__revision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__revision();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__revision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__revision();
#endif
bool _freeAttributes__revision( void* attributeData );

bool _begin__subject( void* attributeData ){return mImpl->begin__subject();}
bool _data__subject( const ParserChar* text, size_t textLength );
bool _end__subject(){return mImpl->end__subject();}
bool _preBegin__subject( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__subject();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__subject( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__subject();
#endif
bool _freeAttributes__subject( void* attributeData );

bool _begin__title( void* attributeData ){return mImpl->begin__title();}
bool _data__title( const ParserChar* text, size_t textLength );
bool _end__title(){return mImpl->end__title();}
bool _preBegin__title( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__title();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__title( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__title();
#endif
bool _freeAttributes__title( void* attributeData );

bool _begin__unit( void* attributeData ){return mImpl->begin__unit(*static_cast<unit__AttributeData*>(attributeData));}
bool _data__unit( const ParserChar* text, size_t textLength );
bool _end__unit(){return mImpl->end__unit();}
bool _preBegin__unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__unit();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__unit();
#endif
bool _freeAttributes__unit( void* attributeData );

bool _begin__up_axis( void* attributeData ){return mImpl->begin__up_axis();}
bool _data__up_axis( const ParserChar* text, size_t textLength );
bool _end__up_axis(){return mImpl->end__up_axis();}
bool _preBegin__up_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__up_axis();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__up_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__up_axis();
#endif
bool _freeAttributes__up_axis( void* attributeData );


ENUM__up_axis_enum toEnumDataPrefix_ENUM__up_axis_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__up_axis_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__up_axis_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__up_axis_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__up_axis_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__up_axis_enum*, size_t ),
    const std::pair<StringHash, ENUM__up_axis_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__up_axis_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__up_axis_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__extra( void* attributeData ){return mImpl->begin__extra(*static_cast<extra__AttributeData*>(attributeData));}
bool _data__extra( const ParserChar* text, size_t textLength );
bool _end__extra(){return mImpl->end__extra();}
bool _preBegin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__extra();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__extra();
#endif
bool _freeAttributes__extra( void* attributeData );

bool _begin__technique____technique_type( void* attributeData ){return mImpl->begin__technique____technique_type(*static_cast<technique____technique_type__AttributeData*>(attributeData));}
bool _data__technique____technique_type( const ParserChar* text, size_t textLength );
bool _end__technique____technique_type(){return mImpl->end__technique____technique_type();}
bool _preBegin__technique____technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique____technique_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique____technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique____technique_type();
#endif
bool _freeAttributes__technique____technique_type( void* attributeData );

bool _begin__library_animations( void* attributeData ){return mImpl->begin__library_animations(*static_cast<library_animations__AttributeData*>(attributeData));}
bool _data__library_animations( const ParserChar* text, size_t textLength );
bool _end__library_animations(){return mImpl->end__library_animations();}
bool _preBegin__library_animations( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_animations();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_animations( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_animations();
#endif
bool _freeAttributes__library_animations( void* attributeData );

bool _begin__animation( void* attributeData ){return mImpl->begin__animation(*static_cast<animation__AttributeData*>(attributeData));}
bool _data__animation( const ParserChar* text, size_t textLength );
bool _end__animation(){return mImpl->end__animation();}
bool _preBegin__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__animation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__animation();
#endif
bool _freeAttributes__animation( void* attributeData );

bool _begin__source( void* attributeData ){return mImpl->begin__source(*static_cast<source__AttributeData*>(attributeData));}
bool _data__source( const ParserChar* text, size_t textLength );
bool _end__source(){return mImpl->end__source();}
bool _preBegin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__source();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__source();
#endif
bool _freeAttributes__source( void* attributeData );

bool _begin__token_array( void* attributeData ){return mImpl->begin__token_array(*static_cast<token_array__AttributeData*>(attributeData));}
bool _data__token_array( const ParserChar* text, size_t textLength );
bool _end__token_array(){return mImpl->end__token_array();}
bool _preBegin__token_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__token_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__token_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__token_array();
#endif
bool _freeAttributes__token_array( void* attributeData );

bool _begin__IDREF_array( void* attributeData ){return mImpl->begin__IDREF_array(*static_cast<IDREF_array__AttributeData*>(attributeData));}
bool _data__IDREF_array( const ParserChar* text, size_t textLength );
bool _end__IDREF_array(){return mImpl->end__IDREF_array();}
bool _preBegin__IDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__IDREF_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__IDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__IDREF_array();
#endif
bool _freeAttributes__IDREF_array( void* attributeData );

bool _begin__Name_array( void* attributeData ){return mImpl->begin__Name_array(*static_cast<Name_array__AttributeData*>(attributeData));}
bool _data__Name_array( const ParserChar* text, size_t textLength );
bool _end__Name_array(){return mImpl->end__Name_array();}
bool _preBegin__Name_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__Name_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__Name_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__Name_array();
#endif
bool _freeAttributes__Name_array( void* attributeData );

bool _begin__bool_array( void* attributeData ){return mImpl->begin__bool_array(*static_cast<bool_array__AttributeData*>(attributeData));}
bool _data__bool_array( const ParserChar* text, size_t textLength );
bool _end__bool_array(){return mImpl->end__bool_array();}
bool _preBegin__bool_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool_array();
#endif
bool _freeAttributes__bool_array( void* attributeData );

bool _begin__float_array( void* attributeData ){return mImpl->begin__float_array(*static_cast<float_array__AttributeData*>(attributeData));}
bool _data__float_array( const ParserChar* text, size_t textLength );
bool _end__float_array(){return mImpl->end__float_array();}
bool _preBegin__float_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float_array();
#endif
bool _freeAttributes__float_array( void* attributeData );

bool _begin__int_array( void* attributeData ){return mImpl->begin__int_array(*static_cast<int_array__AttributeData*>(attributeData));}
bool _data__int_array( const ParserChar* text, size_t textLength );
bool _end__int_array(){return mImpl->end__int_array();}
bool _preBegin__int_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int_array();
#endif
bool _freeAttributes__int_array( void* attributeData );

bool _begin__SIDREF_array( void* attributeData ){return mImpl->begin__SIDREF_array(*static_cast<SIDREF_array__AttributeData*>(attributeData));}
bool _data__SIDREF_array( const ParserChar* text, size_t textLength );
bool _end__SIDREF_array(){return mImpl->end__SIDREF_array();}
bool _preBegin__SIDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__SIDREF_array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__SIDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__SIDREF_array();
#endif
bool _freeAttributes__SIDREF_array( void* attributeData );

bool _begin__source_type____technique_common( void* attributeData ){return mImpl->begin__source_type____technique_common();}
bool _data__source_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__source_type____technique_common(){return mImpl->end__source_type____technique_common();}
bool _preBegin__source_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__source_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__source_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__source_type____technique_common();
#endif
bool _freeAttributes__source_type____technique_common( void* attributeData );

bool _begin__accessor( void* attributeData ){return mImpl->begin__accessor(*static_cast<accessor__AttributeData*>(attributeData));}
bool _data__accessor( const ParserChar* text, size_t textLength );
bool _end__accessor(){return mImpl->end__accessor();}
bool _preBegin__accessor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__accessor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__accessor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__accessor();
#endif
bool _freeAttributes__accessor( void* attributeData );

bool _begin__param____param_type( void* attributeData ){return mImpl->begin__param____param_type(*static_cast<param____param_type__AttributeData*>(attributeData));}
bool _data__param____param_type( const ParserChar* text, size_t textLength );
bool _end__param____param_type(){return mImpl->end__param____param_type();}
bool _preBegin__param____param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__param____param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__param____param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__param____param_type();
#endif
bool _freeAttributes__param____param_type( void* attributeData );

bool _begin__sampler( void* attributeData ){return mImpl->begin__sampler(*static_cast<sampler__AttributeData*>(attributeData));}
bool _data__sampler( const ParserChar* text, size_t textLength );
bool _end__sampler(){return mImpl->end__sampler();}
bool _preBegin__sampler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler();
#endif
bool _freeAttributes__sampler( void* attributeData );


ENUM__sampler_behavior_enum toEnumDataPrefix_ENUM__sampler_behavior_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__sampler_behavior_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__sampler_behavior_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__sampler_behavior_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__sampler_behavior_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__sampler_behavior_enum*, size_t ),
    const std::pair<StringHash, ENUM__sampler_behavior_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__sampler_behavior_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__sampler_behavior_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__input____input_local_type( void* attributeData ){return mImpl->begin__input____input_local_type(*static_cast<input____input_local_type__AttributeData*>(attributeData));}
bool _data__input____input_local_type( const ParserChar* text, size_t textLength );
bool _end__input____input_local_type(){return mImpl->end__input____input_local_type();}
bool _preBegin__input____input_local_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__input____input_local_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__input____input_local_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__input____input_local_type();
#endif
bool _freeAttributes__input____input_local_type( void* attributeData );

bool _begin__channel( void* attributeData ){return mImpl->begin__channel(*static_cast<channel__AttributeData*>(attributeData));}
bool _data__channel( const ParserChar* text, size_t textLength );
bool _end__channel(){return mImpl->end__channel();}
bool _preBegin__channel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__channel();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__channel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__channel();
#endif
bool _freeAttributes__channel( void* attributeData );

bool _begin__library_animation_clips( void* attributeData ){return mImpl->begin__library_animation_clips(*static_cast<library_animation_clips__AttributeData*>(attributeData));}
bool _data__library_animation_clips( const ParserChar* text, size_t textLength );
bool _end__library_animation_clips(){return mImpl->end__library_animation_clips();}
bool _preBegin__library_animation_clips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_animation_clips();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_animation_clips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_animation_clips();
#endif
bool _freeAttributes__library_animation_clips( void* attributeData );

bool _begin__animation_clip( void* attributeData ){return mImpl->begin__animation_clip(*static_cast<animation_clip__AttributeData*>(attributeData));}
bool _data__animation_clip( const ParserChar* text, size_t textLength );
bool _end__animation_clip(){return mImpl->end__animation_clip();}
bool _preBegin__animation_clip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__animation_clip();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__animation_clip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__animation_clip();
#endif
bool _freeAttributes__animation_clip( void* attributeData );

bool _begin__instance_animation( void* attributeData ){return mImpl->begin__instance_animation(*static_cast<instance_animation__AttributeData*>(attributeData));}
bool _data__instance_animation( const ParserChar* text, size_t textLength );
bool _end__instance_animation(){return mImpl->end__instance_animation();}
bool _preBegin__instance_animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_animation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_animation();
#endif
bool _freeAttributes__instance_animation( void* attributeData );

bool _begin__instance_formula( void* attributeData ){return mImpl->begin__instance_formula(*static_cast<instance_formula__AttributeData*>(attributeData));}
bool _data__instance_formula( const ParserChar* text, size_t textLength );
bool _end__instance_formula(){return mImpl->end__instance_formula();}
bool _preBegin__instance_formula( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_formula();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_formula( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_formula();
#endif
bool _freeAttributes__instance_formula( void* attributeData );

bool _begin__setparam____formula_setparam_type( void* attributeData ){return mImpl->begin__setparam____formula_setparam_type(*static_cast<setparam____formula_setparam_type__AttributeData*>(attributeData));}
bool _data__setparam____formula_setparam_type( const ParserChar* text, size_t textLength );
bool _end__setparam____formula_setparam_type(){return mImpl->end__setparam____formula_setparam_type();}
bool _preBegin__setparam____formula_setparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__setparam____formula_setparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__setparam____formula_setparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____formula_setparam_type();
#endif
bool _freeAttributes__setparam____formula_setparam_type( void* attributeData );

bool _begin__float____float_type( void* attributeData ){return mImpl->begin__float____float_type();}
bool _data__float____float_type( const ParserChar* text, size_t textLength );
bool _end__float____float_type(){return mImpl->end__float____float_type();}
bool _preBegin__float____float_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float____float_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float____float_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float____float_type();
#endif
bool _freeAttributes__float____float_type( void* attributeData );

bool _begin__int____int_type( void* attributeData ){return mImpl->begin__int____int_type();}
bool _data__int____int_type( const ParserChar* text, size_t textLength );
bool _end__int____int_type(){return mImpl->end__int____int_type();}
bool _preBegin__int____int_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int____int_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int____int_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int____int_type();
#endif
bool _freeAttributes__int____int_type( void* attributeData );

bool _begin__SIDREF( void* attributeData ){return mImpl->begin__SIDREF();}
bool _data__SIDREF( const ParserChar* text, size_t textLength );
bool _end__SIDREF(){return mImpl->end__SIDREF();}
bool _preBegin__SIDREF( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__SIDREF();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__SIDREF( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__SIDREF();
#endif
bool _freeAttributes__SIDREF( void* attributeData );

bool _begin__bool( void* attributeData ){return mImpl->begin__bool();}
bool _data__bool( const ParserChar* text, size_t textLength );
bool _end__bool(){return mImpl->end__bool();}
bool _preBegin__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool();
#endif
bool _freeAttributes__bool( void* attributeData );

bool _begin__connect_param( void* attributeData ){return mImpl->begin__connect_param(*static_cast<connect_param__AttributeData*>(attributeData));}
bool _data__connect_param( const ParserChar* text, size_t textLength );
bool _end__connect_param(){return mImpl->end__connect_param();}
bool _preBegin__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__connect_param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__connect_param();
#endif
bool _freeAttributes__connect_param( void* attributeData );

bool _begin__library_cameras( void* attributeData ){return mImpl->begin__library_cameras(*static_cast<library_cameras__AttributeData*>(attributeData));}
bool _data__library_cameras( const ParserChar* text, size_t textLength );
bool _end__library_cameras(){return mImpl->end__library_cameras();}
bool _preBegin__library_cameras( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_cameras();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_cameras( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_cameras();
#endif
bool _freeAttributes__library_cameras( void* attributeData );

bool _begin__camera( void* attributeData ){return mImpl->begin__camera(*static_cast<camera__AttributeData*>(attributeData));}
bool _data__camera( const ParserChar* text, size_t textLength );
bool _end__camera(){return mImpl->end__camera();}
bool _preBegin__camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__camera();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__camera();
#endif
bool _freeAttributes__camera( void* attributeData );

bool _begin__optics( void* attributeData ){return mImpl->begin__optics();}
bool _data__optics( const ParserChar* text, size_t textLength );
bool _end__optics(){return mImpl->end__optics();}
bool _preBegin__optics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__optics();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__optics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__optics();
#endif
bool _freeAttributes__optics( void* attributeData );

bool _begin__optics__technique_common( void* attributeData ){return mImpl->begin__optics__technique_common();}
bool _data__optics__technique_common( const ParserChar* text, size_t textLength );
bool _end__optics__technique_common(){return mImpl->end__optics__technique_common();}
bool _preBegin__optics__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__optics__technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__optics__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__optics__technique_common();
#endif
bool _freeAttributes__optics__technique_common( void* attributeData );

bool _begin__orthographic( void* attributeData ){return mImpl->begin__orthographic();}
bool _data__orthographic( const ParserChar* text, size_t textLength );
bool _end__orthographic(){return mImpl->end__orthographic();}
bool _preBegin__orthographic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__orthographic();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__orthographic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__orthographic();
#endif
bool _freeAttributes__orthographic( void* attributeData );

bool _begin__xmag( void* attributeData ){return mImpl->begin__xmag(*static_cast<xmag__AttributeData*>(attributeData));}
bool _data__xmag( const ParserChar* text, size_t textLength );
bool _end__xmag(){return mImpl->end__xmag();}
bool _preBegin__xmag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__xmag();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__xmag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__xmag();
#endif
bool _freeAttributes__xmag( void* attributeData );

bool _begin__ymag( void* attributeData ){return mImpl->begin__ymag(*static_cast<ymag__AttributeData*>(attributeData));}
bool _data__ymag( const ParserChar* text, size_t textLength );
bool _end__ymag(){return mImpl->end__ymag();}
bool _preBegin__ymag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ymag();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ymag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ymag();
#endif
bool _freeAttributes__ymag( void* attributeData );

bool _begin__aspect_ratio( void* attributeData ){return mImpl->begin__aspect_ratio(*static_cast<aspect_ratio__AttributeData*>(attributeData));}
bool _data__aspect_ratio( const ParserChar* text, size_t textLength );
bool _end__aspect_ratio(){return mImpl->end__aspect_ratio();}
bool _preBegin__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__aspect_ratio();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__aspect_ratio();
#endif
bool _freeAttributes__aspect_ratio( void* attributeData );

bool _begin__znear( void* attributeData ){return mImpl->begin__znear(*static_cast<znear__AttributeData*>(attributeData));}
bool _data__znear( const ParserChar* text, size_t textLength );
bool _end__znear(){return mImpl->end__znear();}
bool _preBegin__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__znear();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__znear();
#endif
bool _freeAttributes__znear( void* attributeData );

bool _begin__zfar( void* attributeData ){return mImpl->begin__zfar(*static_cast<zfar__AttributeData*>(attributeData));}
bool _data__zfar( const ParserChar* text, size_t textLength );
bool _end__zfar(){return mImpl->end__zfar();}
bool _preBegin__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__zfar();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__zfar();
#endif
bool _freeAttributes__zfar( void* attributeData );

bool _begin__perspective( void* attributeData ){return mImpl->begin__perspective();}
bool _data__perspective( const ParserChar* text, size_t textLength );
bool _end__perspective(){return mImpl->end__perspective();}
bool _preBegin__perspective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__perspective();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__perspective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__perspective();
#endif
bool _freeAttributes__perspective( void* attributeData );

bool _begin__xfov( void* attributeData ){return mImpl->begin__xfov(*static_cast<xfov__AttributeData*>(attributeData));}
bool _data__xfov( const ParserChar* text, size_t textLength );
bool _end__xfov(){return mImpl->end__xfov();}
bool _preBegin__xfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__xfov();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__xfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__xfov();
#endif
bool _freeAttributes__xfov( void* attributeData );

bool _begin__yfov( void* attributeData ){return mImpl->begin__yfov(*static_cast<yfov__AttributeData*>(attributeData));}
bool _data__yfov( const ParserChar* text, size_t textLength );
bool _end__yfov(){return mImpl->end__yfov();}
bool _preBegin__yfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__yfov();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__yfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__yfov();
#endif
bool _freeAttributes__yfov( void* attributeData );

bool _begin__imager( void* attributeData ){return mImpl->begin__imager();}
bool _data__imager( const ParserChar* text, size_t textLength );
bool _end__imager(){return mImpl->end__imager();}
bool _preBegin__imager( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__imager();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__imager( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__imager();
#endif
bool _freeAttributes__imager( void* attributeData );

bool _begin__library_controllers( void* attributeData ){return mImpl->begin__library_controllers(*static_cast<library_controllers__AttributeData*>(attributeData));}
bool _data__library_controllers( const ParserChar* text, size_t textLength );
bool _end__library_controllers(){return mImpl->end__library_controllers();}
bool _preBegin__library_controllers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_controllers();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_controllers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_controllers();
#endif
bool _freeAttributes__library_controllers( void* attributeData );

bool _begin__controller( void* attributeData ){return mImpl->begin__controller(*static_cast<controller__AttributeData*>(attributeData));}
bool _data__controller( const ParserChar* text, size_t textLength );
bool _end__controller(){return mImpl->end__controller();}
bool _preBegin__controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__controller();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__controller();
#endif
bool _freeAttributes__controller( void* attributeData );

bool _begin__skin( void* attributeData ){return mImpl->begin__skin(*static_cast<skin__AttributeData*>(attributeData));}
bool _data__skin( const ParserChar* text, size_t textLength );
bool _end__skin(){return mImpl->end__skin();}
bool _preBegin__skin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__skin();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__skin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__skin();
#endif
bool _freeAttributes__skin( void* attributeData );

bool _begin__bind_shape_matrix( void* attributeData ){return mImpl->begin__bind_shape_matrix();}
bool _data__bind_shape_matrix( const ParserChar* text, size_t textLength );
bool _end__bind_shape_matrix(){return mImpl->end__bind_shape_matrix();}
bool _preBegin__bind_shape_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind_shape_matrix();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind_shape_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_shape_matrix();
#endif
bool _freeAttributes__bind_shape_matrix( void* attributeData );

bool _begin__joints( void* attributeData ){return mImpl->begin__joints();}
bool _data__joints( const ParserChar* text, size_t textLength );
bool _end__joints(){return mImpl->end__joints();}
bool _preBegin__joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__joints();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__joints();
#endif
bool _freeAttributes__joints( void* attributeData );

bool _begin__vertex_weights( void* attributeData ){return mImpl->begin__vertex_weights(*static_cast<vertex_weights__AttributeData*>(attributeData));}
bool _data__vertex_weights( const ParserChar* text, size_t textLength );
bool _end__vertex_weights(){return mImpl->end__vertex_weights();}
bool _preBegin__vertex_weights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vertex_weights();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vertex_weights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vertex_weights();
#endif
bool _freeAttributes__vertex_weights( void* attributeData );

bool _begin__input____input_local_offset_type( void* attributeData ){return mImpl->begin__input____input_local_offset_type(*static_cast<input____input_local_offset_type__AttributeData*>(attributeData));}
bool _data__input____input_local_offset_type( const ParserChar* text, size_t textLength );
bool _end__input____input_local_offset_type(){return mImpl->end__input____input_local_offset_type();}
bool _preBegin__input____input_local_offset_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__input____input_local_offset_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__input____input_local_offset_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__input____input_local_offset_type();
#endif
bool _freeAttributes__input____input_local_offset_type( void* attributeData );

bool _begin__vcount( void* attributeData ){return mImpl->begin__vcount();}
bool _data__vcount( const ParserChar* text, size_t textLength );
bool _end__vcount(){return mImpl->end__vcount();}
bool _preBegin__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vcount();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vcount();
#endif
bool _freeAttributes__vcount( void* attributeData );

bool _begin__v( void* attributeData ){return mImpl->begin__v();}
bool _data__v( const ParserChar* text, size_t textLength );
bool _end__v(){return mImpl->end__v();}
bool _preBegin__v( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__v();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__v( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__v();
#endif
bool _freeAttributes__v( void* attributeData );

bool _begin__morph( void* attributeData ){return mImpl->begin__morph(*static_cast<morph__AttributeData*>(attributeData));}
bool _data__morph( const ParserChar* text, size_t textLength );
bool _end__morph(){return mImpl->end__morph();}
bool _preBegin__morph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__morph();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__morph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__morph();
#endif
bool _freeAttributes__morph( void* attributeData );


ENUM__morph_method_enum toEnumDataPrefix_ENUM__morph_method_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__morph_method_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__morph_method_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__morph_method_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__morph_method_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__morph_method_enum*, size_t ),
    const std::pair<StringHash, ENUM__morph_method_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__morph_method_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__morph_method_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__targets( void* attributeData ){return mImpl->begin__targets();}
bool _data__targets( const ParserChar* text, size_t textLength );
bool _end__targets(){return mImpl->end__targets();}
bool _preBegin__targets( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__targets();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__targets( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__targets();
#endif
bool _freeAttributes__targets( void* attributeData );

bool _begin__library_geometries( void* attributeData ){return mImpl->begin__library_geometries(*static_cast<library_geometries__AttributeData*>(attributeData));}
bool _data__library_geometries( const ParserChar* text, size_t textLength );
bool _end__library_geometries(){return mImpl->end__library_geometries();}
bool _preBegin__library_geometries( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_geometries();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_geometries( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_geometries();
#endif
bool _freeAttributes__library_geometries( void* attributeData );

bool _begin__geometry( void* attributeData ){return mImpl->begin__geometry(*static_cast<geometry__AttributeData*>(attributeData));}
bool _data__geometry( const ParserChar* text, size_t textLength );
bool _end__geometry(){return mImpl->end__geometry();}
bool _preBegin__geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__geometry();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__geometry();
#endif
bool _freeAttributes__geometry( void* attributeData );

bool _begin__convex_mesh( void* attributeData ){return mImpl->begin__convex_mesh(*static_cast<convex_mesh__AttributeData*>(attributeData));}
bool _data__convex_mesh( const ParserChar* text, size_t textLength );
bool _end__convex_mesh(){return mImpl->end__convex_mesh();}
bool _preBegin__convex_mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__convex_mesh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__convex_mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__convex_mesh();
#endif
bool _freeAttributes__convex_mesh( void* attributeData );

bool _begin__vertices( void* attributeData ){return mImpl->begin__vertices(*static_cast<vertices__AttributeData*>(attributeData));}
bool _data__vertices( const ParserChar* text, size_t textLength );
bool _end__vertices(){return mImpl->end__vertices();}
bool _preBegin__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vertices();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vertices();
#endif
bool _freeAttributes__vertices( void* attributeData );

bool _begin__lines( void* attributeData ){return mImpl->begin__lines(*static_cast<lines__AttributeData*>(attributeData));}
bool _data__lines( const ParserChar* text, size_t textLength );
bool _end__lines(){return mImpl->end__lines();}
bool _preBegin__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lines();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lines();
#endif
bool _freeAttributes__lines( void* attributeData );

bool _begin__p( void* attributeData ){return mImpl->begin__p();}
bool _data__p( const ParserChar* text, size_t textLength );
bool _end__p(){return mImpl->end__p();}
bool _preBegin__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__p();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__p();
#endif
bool _freeAttributes__p( void* attributeData );

bool _begin__linestrips( void* attributeData ){return mImpl->begin__linestrips(*static_cast<linestrips__AttributeData*>(attributeData));}
bool _data__linestrips( const ParserChar* text, size_t textLength );
bool _end__linestrips(){return mImpl->end__linestrips();}
bool _preBegin__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__linestrips();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__linestrips();
#endif
bool _freeAttributes__linestrips( void* attributeData );

bool _begin__polygons( void* attributeData ){return mImpl->begin__polygons(*static_cast<polygons__AttributeData*>(attributeData));}
bool _data__polygons( const ParserChar* text, size_t textLength );
bool _end__polygons(){return mImpl->end__polygons();}
bool _preBegin__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygons();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygons();
#endif
bool _freeAttributes__polygons( void* attributeData );

bool _begin__ph( void* attributeData ){return mImpl->begin__ph();}
bool _data__ph( const ParserChar* text, size_t textLength );
bool _end__ph(){return mImpl->end__ph();}
bool _preBegin__ph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ph();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ph();
#endif
bool _freeAttributes__ph( void* attributeData );

bool _begin__h( void* attributeData ){return mImpl->begin__h();}
bool _data__h( const ParserChar* text, size_t textLength );
bool _end__h(){return mImpl->end__h();}
bool _preBegin__h( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__h();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__h( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__h();
#endif
bool _freeAttributes__h( void* attributeData );

bool _begin__polylist( void* attributeData ){return mImpl->begin__polylist(*static_cast<polylist__AttributeData*>(attributeData));}
bool _data__polylist( const ParserChar* text, size_t textLength );
bool _end__polylist(){return mImpl->end__polylist();}
bool _preBegin__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polylist();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polylist();
#endif
bool _freeAttributes__polylist( void* attributeData );

bool _begin__triangles( void* attributeData ){return mImpl->begin__triangles(*static_cast<triangles__AttributeData*>(attributeData));}
bool _data__triangles( const ParserChar* text, size_t textLength );
bool _end__triangles(){return mImpl->end__triangles();}
bool _preBegin__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__triangles();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__triangles();
#endif
bool _freeAttributes__triangles( void* attributeData );

bool _begin__trifans( void* attributeData ){return mImpl->begin__trifans(*static_cast<trifans__AttributeData*>(attributeData));}
bool _data__trifans( const ParserChar* text, size_t textLength );
bool _end__trifans(){return mImpl->end__trifans();}
bool _preBegin__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__trifans();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__trifans();
#endif
bool _freeAttributes__trifans( void* attributeData );

bool _begin__tristrips( void* attributeData ){return mImpl->begin__tristrips(*static_cast<tristrips__AttributeData*>(attributeData));}
bool _data__tristrips( const ParserChar* text, size_t textLength );
bool _end__tristrips(){return mImpl->end__tristrips();}
bool _preBegin__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__tristrips();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tristrips();
#endif
bool _freeAttributes__tristrips( void* attributeData );

bool _begin__mesh( void* attributeData ){return mImpl->begin__mesh();}
bool _data__mesh( const ParserChar* text, size_t textLength );
bool _end__mesh(){return mImpl->end__mesh();}
bool _preBegin__mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mesh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mesh();
#endif
bool _freeAttributes__mesh( void* attributeData );

bool _begin__spline( void* attributeData ){return mImpl->begin__spline(*static_cast<spline__AttributeData*>(attributeData));}
bool _data__spline( const ParserChar* text, size_t textLength );
bool _end__spline(){return mImpl->end__spline();}
bool _preBegin__spline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__spline();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__spline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spline();
#endif
bool _freeAttributes__spline( void* attributeData );

bool _begin__spline_type____control_vertices( void* attributeData ){return mImpl->begin__spline_type____control_vertices();}
bool _data__spline_type____control_vertices( const ParserChar* text, size_t textLength );
bool _end__spline_type____control_vertices(){return mImpl->end__spline_type____control_vertices();}
bool _preBegin__spline_type____control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__spline_type____control_vertices();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__spline_type____control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spline_type____control_vertices();
#endif
bool _freeAttributes__spline_type____control_vertices( void* attributeData );

bool _begin__brep( void* attributeData ){return mImpl->begin__brep();}
bool _data__brep( const ParserChar* text, size_t textLength );
bool _end__brep(){return mImpl->end__brep();}
bool _preBegin__brep( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__brep();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__brep( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__brep();
#endif
bool _freeAttributes__brep( void* attributeData );

bool _begin__curves( void* attributeData ){return mImpl->begin__curves();}
bool _data__curves( const ParserChar* text, size_t textLength );
bool _end__curves(){return mImpl->end__curves();}
bool _preBegin__curves( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__curves();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__curves( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__curves();
#endif
bool _freeAttributes__curves( void* attributeData );

bool _begin__curve( void* attributeData ){return mImpl->begin__curve(*static_cast<curve__AttributeData*>(attributeData));}
bool _data__curve( const ParserChar* text, size_t textLength );
bool _end__curve(){return mImpl->end__curve();}
bool _preBegin__curve( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__curve();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__curve( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__curve();
#endif
bool _freeAttributes__curve( void* attributeData );

bool _begin__line( void* attributeData ){return mImpl->begin__line();}
bool _data__line( const ParserChar* text, size_t textLength );
bool _end__line(){return mImpl->end__line();}
bool _preBegin__line( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__line();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__line( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__line();
#endif
bool _freeAttributes__line( void* attributeData );

bool _begin__origin____float3_type( void* attributeData ){return mImpl->begin__origin____float3_type();}
bool _data__origin____float3_type( const ParserChar* text, size_t textLength );
bool _end__origin____float3_type(){return mImpl->end__origin____float3_type();}
bool _preBegin__origin____float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__origin____float3_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__origin____float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__origin____float3_type();
#endif
bool _freeAttributes__origin____float3_type( void* attributeData );

bool _begin__direction( void* attributeData ){return mImpl->begin__direction();}
bool _data__direction( const ParserChar* text, size_t textLength );
bool _end__direction(){return mImpl->end__direction();}
bool _preBegin__direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__direction();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__direction();
#endif
bool _freeAttributes__direction( void* attributeData );

bool _begin__circle( void* attributeData ){return mImpl->begin__circle();}
bool _data__circle( const ParserChar* text, size_t textLength );
bool _end__circle(){return mImpl->end__circle();}
bool _preBegin__circle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__circle();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__circle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__circle();
#endif
bool _freeAttributes__circle( void* attributeData );

bool _begin__radius____float_type( void* attributeData ){return mImpl->begin__radius____float_type();}
bool _data__radius____float_type( const ParserChar* text, size_t textLength );
bool _end__radius____float_type(){return mImpl->end__radius____float_type();}
bool _preBegin__radius____float_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__radius____float_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__radius____float_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius____float_type();
#endif
bool _freeAttributes__radius____float_type( void* attributeData );

bool _begin__ellipse( void* attributeData ){return mImpl->begin__ellipse();}
bool _data__ellipse( const ParserChar* text, size_t textLength );
bool _end__ellipse(){return mImpl->end__ellipse();}
bool _preBegin__ellipse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ellipse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ellipse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ellipse();
#endif
bool _freeAttributes__ellipse( void* attributeData );

bool _begin__radius____float2_type( void* attributeData ){return mImpl->begin__radius____float2_type();}
bool _data__radius____float2_type( const ParserChar* text, size_t textLength );
bool _end__radius____float2_type(){return mImpl->end__radius____float2_type();}
bool _preBegin__radius____float2_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__radius____float2_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__radius____float2_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius____float2_type();
#endif
bool _freeAttributes__radius____float2_type( void* attributeData );

bool _begin__parabola( void* attributeData ){return mImpl->begin__parabola();}
bool _data__parabola( const ParserChar* text, size_t textLength );
bool _end__parabola(){return mImpl->end__parabola();}
bool _preBegin__parabola( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__parabola();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__parabola( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__parabola();
#endif
bool _freeAttributes__parabola( void* attributeData );

bool _begin__focal( void* attributeData ){return mImpl->begin__focal();}
bool _data__focal( const ParserChar* text, size_t textLength );
bool _end__focal(){return mImpl->end__focal();}
bool _preBegin__focal( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__focal();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__focal( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__focal();
#endif
bool _freeAttributes__focal( void* attributeData );

bool _begin__hyperbola( void* attributeData ){return mImpl->begin__hyperbola();}
bool _data__hyperbola( const ParserChar* text, size_t textLength );
bool _end__hyperbola(){return mImpl->end__hyperbola();}
bool _preBegin__hyperbola( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__hyperbola();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__hyperbola( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__hyperbola();
#endif
bool _freeAttributes__hyperbola( void* attributeData );

bool _begin__nurbs( void* attributeData ){return mImpl->begin__nurbs(*static_cast<nurbs__AttributeData*>(attributeData));}
bool _data__nurbs( const ParserChar* text, size_t textLength );
bool _end__nurbs(){return mImpl->end__nurbs();}
bool _preBegin__nurbs( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__nurbs();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__nurbs( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__nurbs();
#endif
bool _freeAttributes__nurbs( void* attributeData );

bool _begin__nurbs_type____control_vertices( void* attributeData ){return mImpl->begin__nurbs_type____control_vertices();}
bool _data__nurbs_type____control_vertices( const ParserChar* text, size_t textLength );
bool _end__nurbs_type____control_vertices(){return mImpl->end__nurbs_type____control_vertices();}
bool _preBegin__nurbs_type____control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__nurbs_type____control_vertices();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__nurbs_type____control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__nurbs_type____control_vertices();
#endif
bool _freeAttributes__nurbs_type____control_vertices( void* attributeData );

bool _begin__orient( void* attributeData ){return mImpl->begin__orient();}
bool _data__orient( const ParserChar* text, size_t textLength );
bool _end__orient(){return mImpl->end__orient();}
bool _preBegin__orient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__orient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__orient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__orient();
#endif
bool _freeAttributes__orient( void* attributeData );

bool _begin__origin____origin_type( void* attributeData ){return mImpl->begin__origin____origin_type();}
bool _data__origin____origin_type( const ParserChar* text, size_t textLength );
bool _end__origin____origin_type(){return mImpl->end__origin____origin_type();}
bool _preBegin__origin____origin_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__origin____origin_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__origin____origin_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__origin____origin_type();
#endif
bool _freeAttributes__origin____origin_type( void* attributeData );

bool _begin__surface_curves( void* attributeData ){return mImpl->begin__surface_curves();}
bool _data__surface_curves( const ParserChar* text, size_t textLength );
bool _end__surface_curves(){return mImpl->end__surface_curves();}
bool _preBegin__surface_curves( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__surface_curves();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__surface_curves( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface_curves();
#endif
bool _freeAttributes__surface_curves( void* attributeData );

bool _begin__surfaces( void* attributeData ){return mImpl->begin__surfaces();}
bool _data__surfaces( const ParserChar* text, size_t textLength );
bool _end__surfaces(){return mImpl->end__surfaces();}
bool _preBegin__surfaces( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__surfaces();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__surfaces( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surfaces();
#endif
bool _freeAttributes__surfaces( void* attributeData );

bool _begin__surface( void* attributeData ){return mImpl->begin__surface(*static_cast<surface__AttributeData*>(attributeData));}
bool _data__surface( const ParserChar* text, size_t textLength );
bool _end__surface(){return mImpl->end__surface();}
bool _preBegin__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__surface();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface();
#endif
bool _freeAttributes__surface( void* attributeData );

bool _begin__plane( void* attributeData ){return mImpl->begin__plane();}
bool _data__plane( const ParserChar* text, size_t textLength );
bool _end__plane(){return mImpl->end__plane();}
bool _preBegin__plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__plane();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__plane();
#endif
bool _freeAttributes__plane( void* attributeData );

bool _begin__equation( void* attributeData ){return mImpl->begin__equation();}
bool _data__equation( const ParserChar* text, size_t textLength );
bool _end__equation(){return mImpl->end__equation();}
bool _preBegin__equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__equation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__equation();
#endif
bool _freeAttributes__equation( void* attributeData );

bool _begin__sphere( void* attributeData ){return mImpl->begin__sphere();}
bool _data__sphere( const ParserChar* text, size_t textLength );
bool _end__sphere(){return mImpl->end__sphere();}
bool _preBegin__sphere( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sphere();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sphere( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sphere();
#endif
bool _freeAttributes__sphere( void* attributeData );

bool _begin__torus( void* attributeData ){return mImpl->begin__torus();}
bool _data__torus( const ParserChar* text, size_t textLength );
bool _end__torus(){return mImpl->end__torus();}
bool _preBegin__torus( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__torus();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__torus( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__torus();
#endif
bool _freeAttributes__torus( void* attributeData );

bool _begin__swept_surface( void* attributeData ){return mImpl->begin__swept_surface();}
bool _data__swept_surface( const ParserChar* text, size_t textLength );
bool _end__swept_surface(){return mImpl->end__swept_surface();}
bool _preBegin__swept_surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__swept_surface();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__swept_surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__swept_surface();
#endif
bool _freeAttributes__swept_surface( void* attributeData );

bool _begin__axis____float3_type( void* attributeData ){return mImpl->begin__axis____float3_type();}
bool _data__axis____float3_type( const ParserChar* text, size_t textLength );
bool _end__axis____float3_type(){return mImpl->end__axis____float3_type();}
bool _preBegin__axis____float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__axis____float3_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__axis____float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__axis____float3_type();
#endif
bool _freeAttributes__axis____float3_type( void* attributeData );

bool _begin__nurbs_surface( void* attributeData ){return mImpl->begin__nurbs_surface(*static_cast<nurbs_surface__AttributeData*>(attributeData));}
bool _data__nurbs_surface( const ParserChar* text, size_t textLength );
bool _end__nurbs_surface(){return mImpl->end__nurbs_surface();}
bool _preBegin__nurbs_surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__nurbs_surface();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__nurbs_surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__nurbs_surface();
#endif
bool _freeAttributes__nurbs_surface( void* attributeData );

bool _begin__nurbs_surface_type____control_vertices( void* attributeData ){return mImpl->begin__nurbs_surface_type____control_vertices();}
bool _data__nurbs_surface_type____control_vertices( const ParserChar* text, size_t textLength );
bool _end__nurbs_surface_type____control_vertices(){return mImpl->end__nurbs_surface_type____control_vertices();}
bool _preBegin__nurbs_surface_type____control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__nurbs_surface_type____control_vertices();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__nurbs_surface_type____control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__nurbs_surface_type____control_vertices();
#endif
bool _freeAttributes__nurbs_surface_type____control_vertices( void* attributeData );

bool _begin__cone( void* attributeData ){return mImpl->begin__cone();}
bool _data__cone( const ParserChar* text, size_t textLength );
bool _end__cone(){return mImpl->end__cone();}
bool _preBegin__cone( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cone();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cone( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cone();
#endif
bool _freeAttributes__cone( void* attributeData );

bool _begin__angle( void* attributeData ){return mImpl->begin__angle();}
bool _data__angle( const ParserChar* text, size_t textLength );
bool _end__angle(){return mImpl->end__angle();}
bool _preBegin__angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__angle();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__angle();
#endif
bool _freeAttributes__angle( void* attributeData );

bool _begin__surface_type____cylinder( void* attributeData ){return mImpl->begin__surface_type____cylinder();}
bool _data__surface_type____cylinder( const ParserChar* text, size_t textLength );
bool _end__surface_type____cylinder(){return mImpl->end__surface_type____cylinder();}
bool _preBegin__surface_type____cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__surface_type____cylinder();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__surface_type____cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface_type____cylinder();
#endif
bool _freeAttributes__surface_type____cylinder( void* attributeData );

bool _begin__edges( void* attributeData ){return mImpl->begin__edges(*static_cast<edges__AttributeData*>(attributeData));}
bool _data__edges( const ParserChar* text, size_t textLength );
bool _end__edges(){return mImpl->end__edges();}
bool _preBegin__edges( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__edges();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__edges( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__edges();
#endif
bool _freeAttributes__edges( void* attributeData );

bool _begin__wires( void* attributeData ){return mImpl->begin__wires(*static_cast<wires__AttributeData*>(attributeData));}
bool _data__wires( const ParserChar* text, size_t textLength );
bool _end__wires(){return mImpl->end__wires();}
bool _preBegin__wires( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__wires();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__wires( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wires();
#endif
bool _freeAttributes__wires( void* attributeData );

bool _begin__faces( void* attributeData ){return mImpl->begin__faces(*static_cast<faces__AttributeData*>(attributeData));}
bool _data__faces( const ParserChar* text, size_t textLength );
bool _end__faces(){return mImpl->end__faces();}
bool _preBegin__faces( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__faces();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__faces( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__faces();
#endif
bool _freeAttributes__faces( void* attributeData );

bool _begin__pcurves( void* attributeData ){return mImpl->begin__pcurves(*static_cast<pcurves__AttributeData*>(attributeData));}
bool _data__pcurves( const ParserChar* text, size_t textLength );
bool _end__pcurves(){return mImpl->end__pcurves();}
bool _preBegin__pcurves( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__pcurves();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__pcurves( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__pcurves();
#endif
bool _freeAttributes__pcurves( void* attributeData );

bool _begin__shells( void* attributeData ){return mImpl->begin__shells(*static_cast<shells__AttributeData*>(attributeData));}
bool _data__shells( const ParserChar* text, size_t textLength );
bool _end__shells(){return mImpl->end__shells();}
bool _preBegin__shells( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__shells();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__shells( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__shells();
#endif
bool _freeAttributes__shells( void* attributeData );

bool _begin__solids( void* attributeData ){return mImpl->begin__solids(*static_cast<solids__AttributeData*>(attributeData));}
bool _data__solids( const ParserChar* text, size_t textLength );
bool _end__solids(){return mImpl->end__solids();}
bool _preBegin__solids( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__solids();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__solids( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__solids();
#endif
bool _freeAttributes__solids( void* attributeData );

bool _begin__library_effects( void* attributeData ){return mImpl->begin__library_effects(*static_cast<library_effects__AttributeData*>(attributeData));}
bool _data__library_effects( const ParserChar* text, size_t textLength );
bool _end__library_effects(){return mImpl->end__library_effects();}
bool _preBegin__library_effects( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_effects();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_effects( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_effects();
#endif
bool _freeAttributes__library_effects( void* attributeData );

bool _begin__effect( void* attributeData ){return mImpl->begin__effect(*static_cast<effect__AttributeData*>(attributeData));}
bool _data__effect( const ParserChar* text, size_t textLength );
bool _end__effect(){return mImpl->end__effect();}
bool _preBegin__effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__effect();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__effect();
#endif
bool _freeAttributes__effect( void* attributeData );

bool _begin__annotate( void* attributeData ){return mImpl->begin__annotate(*static_cast<annotate__AttributeData*>(attributeData));}
bool _data__annotate( const ParserChar* text, size_t textLength );
bool _end__annotate(){return mImpl->end__annotate();}
bool _preBegin__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__annotate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__annotate();
#endif
bool _freeAttributes__annotate( void* attributeData );

bool _begin__bool2( void* attributeData ){return mImpl->begin__bool2();}
bool _data__bool2( const ParserChar* text, size_t textLength );
bool _end__bool2(){return mImpl->end__bool2();}
bool _preBegin__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2();
#endif
bool _freeAttributes__bool2( void* attributeData );

bool _begin__bool3( void* attributeData ){return mImpl->begin__bool3();}
bool _data__bool3( const ParserChar* text, size_t textLength );
bool _end__bool3(){return mImpl->end__bool3();}
bool _preBegin__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3();
#endif
bool _freeAttributes__bool3( void* attributeData );

bool _begin__bool4( void* attributeData ){return mImpl->begin__bool4();}
bool _data__bool4( const ParserChar* text, size_t textLength );
bool _end__bool4(){return mImpl->end__bool4();}
bool _preBegin__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4();
#endif
bool _freeAttributes__bool4( void* attributeData );

bool _begin__int2( void* attributeData ){return mImpl->begin__int2();}
bool _data__int2( const ParserChar* text, size_t textLength );
bool _end__int2(){return mImpl->end__int2();}
bool _preBegin__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2();
#endif
bool _freeAttributes__int2( void* attributeData );

bool _begin__int3( void* attributeData ){return mImpl->begin__int3();}
bool _data__int3( const ParserChar* text, size_t textLength );
bool _end__int3(){return mImpl->end__int3();}
bool _preBegin__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3();
#endif
bool _freeAttributes__int3( void* attributeData );

bool _begin__int4( void* attributeData ){return mImpl->begin__int4();}
bool _data__int4( const ParserChar* text, size_t textLength );
bool _end__int4(){return mImpl->end__int4();}
bool _preBegin__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4();
#endif
bool _freeAttributes__int4( void* attributeData );

bool _begin__float2( void* attributeData ){return mImpl->begin__float2();}
bool _data__float2( const ParserChar* text, size_t textLength );
bool _end__float2(){return mImpl->end__float2();}
bool _preBegin__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2();
#endif
bool _freeAttributes__float2( void* attributeData );

bool _begin__float3( void* attributeData ){return mImpl->begin__float3();}
bool _data__float3( const ParserChar* text, size_t textLength );
bool _end__float3(){return mImpl->end__float3();}
bool _preBegin__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3();
#endif
bool _freeAttributes__float3( void* attributeData );

bool _begin__float4( void* attributeData ){return mImpl->begin__float4();}
bool _data__float4( const ParserChar* text, size_t textLength );
bool _end__float4(){return mImpl->end__float4();}
bool _preBegin__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4();
#endif
bool _freeAttributes__float4( void* attributeData );

bool _begin__float2x2( void* attributeData ){return mImpl->begin__float2x2();}
bool _data__float2x2( const ParserChar* text, size_t textLength );
bool _end__float2x2(){return mImpl->end__float2x2();}
bool _preBegin__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float2x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x2();
#endif
bool _freeAttributes__float2x2( void* attributeData );

bool _begin__float3x3( void* attributeData ){return mImpl->begin__float3x3();}
bool _data__float3x3( const ParserChar* text, size_t textLength );
bool _end__float3x3(){return mImpl->end__float3x3();}
bool _preBegin__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float3x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x3();
#endif
bool _freeAttributes__float3x3( void* attributeData );

bool _begin__float4x4( void* attributeData ){return mImpl->begin__float4x4();}
bool _data__float4x4( const ParserChar* text, size_t textLength );
bool _end__float4x4(){return mImpl->end__float4x4();}
bool _preBegin__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float4x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x4();
#endif
bool _freeAttributes__float4x4( void* attributeData );

bool _begin__string( void* attributeData ){return mImpl->begin__string();}
bool _data__string( const ParserChar* text, size_t textLength );
bool _end__string(){return mImpl->end__string();}
bool _preBegin__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__string();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__string();
#endif
bool _freeAttributes__string( void* attributeData );

bool _begin__newparam____fx_newparam_type( void* attributeData ){return mImpl->begin__newparam____fx_newparam_type(*static_cast<newparam____fx_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____fx_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____fx_newparam_type(){return mImpl->end__newparam____fx_newparam_type();}
bool _preBegin__newparam____fx_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____fx_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____fx_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____fx_newparam_type();
#endif
bool _freeAttributes__newparam____fx_newparam_type( void* attributeData );

bool _begin__semantic____NCName( void* attributeData ){return mImpl->begin__semantic____NCName();}
bool _data__semantic____NCName( const ParserChar* text, size_t textLength );
bool _end__semantic____NCName(){return mImpl->end__semantic____NCName();}
bool _preBegin__semantic____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__semantic____NCName();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__semantic____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__semantic____NCName();
#endif
bool _freeAttributes__semantic____NCName( void* attributeData );

bool _begin__modifier( void* attributeData ){return mImpl->begin__modifier();}
bool _data__modifier( const ParserChar* text, size_t textLength );
bool _end__modifier(){return mImpl->end__modifier();}
bool _preBegin__modifier( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__modifier();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__modifier( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__modifier();
#endif
bool _freeAttributes__modifier( void* attributeData );


ENUM__fx_modifier_enum toEnumDataPrefix_ENUM__fx_modifier_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_modifier_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_modifier_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_modifier_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_modifier_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_modifier_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_modifier_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_modifier_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_modifier_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__float2x1( void* attributeData ){return mImpl->begin__float2x1();}
bool _data__float2x1( const ParserChar* text, size_t textLength );
bool _end__float2x1(){return mImpl->end__float2x1();}
bool _preBegin__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float2x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x1();
#endif
bool _freeAttributes__float2x1( void* attributeData );

bool _begin__float2x3( void* attributeData ){return mImpl->begin__float2x3();}
bool _data__float2x3( const ParserChar* text, size_t textLength );
bool _end__float2x3(){return mImpl->end__float2x3();}
bool _preBegin__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float2x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x3();
#endif
bool _freeAttributes__float2x3( void* attributeData );

bool _begin__float2x4( void* attributeData ){return mImpl->begin__float2x4();}
bool _data__float2x4( const ParserChar* text, size_t textLength );
bool _end__float2x4(){return mImpl->end__float2x4();}
bool _preBegin__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float2x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x4();
#endif
bool _freeAttributes__float2x4( void* attributeData );

bool _begin__float3x1( void* attributeData ){return mImpl->begin__float3x1();}
bool _data__float3x1( const ParserChar* text, size_t textLength );
bool _end__float3x1(){return mImpl->end__float3x1();}
bool _preBegin__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float3x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x1();
#endif
bool _freeAttributes__float3x1( void* attributeData );

bool _begin__float3x2( void* attributeData ){return mImpl->begin__float3x2();}
bool _data__float3x2( const ParserChar* text, size_t textLength );
bool _end__float3x2(){return mImpl->end__float3x2();}
bool _preBegin__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float3x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x2();
#endif
bool _freeAttributes__float3x2( void* attributeData );

bool _begin__float3x4( void* attributeData ){return mImpl->begin__float3x4();}
bool _data__float3x4( const ParserChar* text, size_t textLength );
bool _end__float3x4(){return mImpl->end__float3x4();}
bool _preBegin__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float3x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x4();
#endif
bool _freeAttributes__float3x4( void* attributeData );

bool _begin__float4x1( void* attributeData ){return mImpl->begin__float4x1();}
bool _data__float4x1( const ParserChar* text, size_t textLength );
bool _end__float4x1(){return mImpl->end__float4x1();}
bool _preBegin__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float4x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x1();
#endif
bool _freeAttributes__float4x1( void* attributeData );

bool _begin__float4x2( void* attributeData ){return mImpl->begin__float4x2();}
bool _data__float4x2( const ParserChar* text, size_t textLength );
bool _end__float4x2(){return mImpl->end__float4x2();}
bool _preBegin__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float4x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x2();
#endif
bool _freeAttributes__float4x2( void* attributeData );

bool _begin__float4x3( void* attributeData ){return mImpl->begin__float4x3();}
bool _data__float4x3( const ParserChar* text, size_t textLength );
bool _end__float4x3(){return mImpl->end__float4x3();}
bool _preBegin__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float4x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x3();
#endif
bool _freeAttributes__float4x3( void* attributeData );

bool _begin__sampler1D( void* attributeData ){return mImpl->begin__sampler1D();}
bool _data__sampler1D( const ParserChar* text, size_t textLength );
bool _end__sampler1D(){return mImpl->end__sampler1D();}
bool _preBegin__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler1D();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler1D();
#endif
bool _freeAttributes__sampler1D( void* attributeData );

bool _begin__instance_image( void* attributeData ){return mImpl->begin__instance_image(*static_cast<instance_image__AttributeData*>(attributeData));}
bool _data__instance_image( const ParserChar* text, size_t textLength );
bool _end__instance_image(){return mImpl->end__instance_image();}
bool _preBegin__instance_image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_image();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_image();
#endif
bool _freeAttributes__instance_image( void* attributeData );

bool _begin__wrap_s____fx_sampler_wrap_enum( void* attributeData ){return mImpl->begin__wrap_s____fx_sampler_wrap_enum();}
bool _data__wrap_s____fx_sampler_wrap_enum( const ParserChar* text, size_t textLength );
bool _end__wrap_s____fx_sampler_wrap_enum(){return mImpl->end__wrap_s____fx_sampler_wrap_enum();}
bool _preBegin__wrap_s____fx_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__wrap_s____fx_sampler_wrap_enum();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__wrap_s____fx_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_s____fx_sampler_wrap_enum();
#endif
bool _freeAttributes__wrap_s____fx_sampler_wrap_enum( void* attributeData );


ENUM__fx_sampler_wrap_enum toEnumDataPrefix_ENUM__fx_sampler_wrap_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_sampler_wrap_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_wrap_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_sampler_wrap_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_wrap_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_sampler_wrap_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_sampler_wrap_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__wrap_t____fx_sampler_wrap_enum( void* attributeData ){return mImpl->begin__wrap_t____fx_sampler_wrap_enum();}
bool _data__wrap_t____fx_sampler_wrap_enum( const ParserChar* text, size_t textLength );
bool _end__wrap_t____fx_sampler_wrap_enum(){return mImpl->end__wrap_t____fx_sampler_wrap_enum();}
bool _preBegin__wrap_t____fx_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__wrap_t____fx_sampler_wrap_enum();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__wrap_t____fx_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_t____fx_sampler_wrap_enum();
#endif
bool _freeAttributes__wrap_t____fx_sampler_wrap_enum( void* attributeData );

bool _begin__wrap_p( void* attributeData ){return mImpl->begin__wrap_p();}
bool _data__wrap_p( const ParserChar* text, size_t textLength );
bool _end__wrap_p(){return mImpl->end__wrap_p();}
bool _preBegin__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__wrap_p();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_p();
#endif
bool _freeAttributes__wrap_p( void* attributeData );

bool _begin__minfilter( void* attributeData ){return mImpl->begin__minfilter();}
bool _data__minfilter( const ParserChar* text, size_t textLength );
bool _end__minfilter(){return mImpl->end__minfilter();}
bool _preBegin__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__minfilter();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__minfilter();
#endif
bool _freeAttributes__minfilter( void* attributeData );


ENUM__fx_sampler_min_filter_enum toEnumDataPrefix_ENUM__fx_sampler_min_filter_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_sampler_min_filter_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_min_filter_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_sampler_min_filter_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_min_filter_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_sampler_min_filter_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__magfilter( void* attributeData ){return mImpl->begin__magfilter();}
bool _data__magfilter( const ParserChar* text, size_t textLength );
bool _end__magfilter(){return mImpl->end__magfilter();}
bool _preBegin__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__magfilter();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__magfilter();
#endif
bool _freeAttributes__magfilter( void* attributeData );


ENUM__fx_sampler_mag_filter_enum toEnumDataPrefix_ENUM__fx_sampler_mag_filter_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_sampler_mag_filter_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_mag_filter_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_sampler_mag_filter_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_mag_filter_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_sampler_mag_filter_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__mipfilter( void* attributeData ){return mImpl->begin__mipfilter();}
bool _data__mipfilter( const ParserChar* text, size_t textLength );
bool _end__mipfilter(){return mImpl->end__mipfilter();}
bool _preBegin__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mipfilter();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mipfilter();
#endif
bool _freeAttributes__mipfilter( void* attributeData );


ENUM__fx_sampler_mip_filter_enum toEnumDataPrefix_ENUM__fx_sampler_mip_filter_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_sampler_mip_filter_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_mip_filter_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_sampler_mip_filter_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_sampler_mip_filter_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_sampler_mip_filter_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__border_color( void* attributeData ){return mImpl->begin__border_color();}
bool _data__border_color( const ParserChar* text, size_t textLength );
bool _end__border_color(){return mImpl->end__border_color();}
bool _preBegin__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__border_color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__border_color();
#endif
bool _freeAttributes__border_color( void* attributeData );

bool _begin__mip_max_level( void* attributeData ){return mImpl->begin__mip_max_level();}
bool _data__mip_max_level( const ParserChar* text, size_t textLength );
bool _end__mip_max_level(){return mImpl->end__mip_max_level();}
bool _preBegin__mip_max_level( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mip_max_level();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mip_max_level( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mip_max_level();
#endif
bool _freeAttributes__mip_max_level( void* attributeData );

bool _begin__mip_min_level( void* attributeData ){return mImpl->begin__mip_min_level();}
bool _data__mip_min_level( const ParserChar* text, size_t textLength );
bool _end__mip_min_level(){return mImpl->end__mip_min_level();}
bool _preBegin__mip_min_level( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mip_min_level();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mip_min_level( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mip_min_level();
#endif
bool _freeAttributes__mip_min_level( void* attributeData );

bool _begin__mip_bias( void* attributeData ){return mImpl->begin__mip_bias();}
bool _data__mip_bias( const ParserChar* text, size_t textLength );
bool _end__mip_bias(){return mImpl->end__mip_bias();}
bool _preBegin__mip_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mip_bias();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mip_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mip_bias();
#endif
bool _freeAttributes__mip_bias( void* attributeData );

bool _begin__max_anisotropy( void* attributeData ){return mImpl->begin__max_anisotropy();}
bool _data__max_anisotropy( const ParserChar* text, size_t textLength );
bool _end__max_anisotropy(){return mImpl->end__max_anisotropy();}
bool _preBegin__max_anisotropy( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__max_anisotropy();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__max_anisotropy( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__max_anisotropy();
#endif
bool _freeAttributes__max_anisotropy( void* attributeData );

bool _begin__sampler2D____fx_sampler2D_type( void* attributeData ){return mImpl->begin__sampler2D____fx_sampler2D_type();}
bool _data__sampler2D____fx_sampler2D_type( const ParserChar* text, size_t textLength );
bool _end__sampler2D____fx_sampler2D_type(){return mImpl->end__sampler2D____fx_sampler2D_type();}
bool _preBegin__sampler2D____fx_sampler2D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler2D____fx_sampler2D_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler2D____fx_sampler2D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler2D____fx_sampler2D_type();
#endif
bool _freeAttributes__sampler2D____fx_sampler2D_type( void* attributeData );

bool _begin__sampler3D( void* attributeData ){return mImpl->begin__sampler3D();}
bool _data__sampler3D( const ParserChar* text, size_t textLength );
bool _end__sampler3D(){return mImpl->end__sampler3D();}
bool _preBegin__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler3D();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler3D();
#endif
bool _freeAttributes__sampler3D( void* attributeData );

bool _begin__samplerCUBE( void* attributeData ){return mImpl->begin__samplerCUBE();}
bool _data__samplerCUBE( const ParserChar* text, size_t textLength );
bool _end__samplerCUBE(){return mImpl->end__samplerCUBE();}
bool _preBegin__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__samplerCUBE();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerCUBE();
#endif
bool _freeAttributes__samplerCUBE( void* attributeData );

bool _begin__samplerRECT( void* attributeData ){return mImpl->begin__samplerRECT();}
bool _data__samplerRECT( const ParserChar* text, size_t textLength );
bool _end__samplerRECT(){return mImpl->end__samplerRECT();}
bool _preBegin__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__samplerRECT();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerRECT();
#endif
bool _freeAttributes__samplerRECT( void* attributeData );

bool _begin__samplerDEPTH( void* attributeData ){return mImpl->begin__samplerDEPTH();}
bool _data__samplerDEPTH( const ParserChar* text, size_t textLength );
bool _end__samplerDEPTH(){return mImpl->end__samplerDEPTH();}
bool _preBegin__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__samplerDEPTH();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerDEPTH();
#endif
bool _freeAttributes__samplerDEPTH( void* attributeData );

bool _begin__enum____string( void* attributeData ){return mImpl->begin__enum____string();}
bool _data__enum____string( const ParserChar* text, size_t textLength );
bool _end__enum____string(){return mImpl->end__enum____string();}
bool _preBegin__enum____string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__enum____string();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__enum____string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enum____string();
#endif
bool _freeAttributes__enum____string( void* attributeData );

bool _begin__profile_COMMON( void* attributeData ){return mImpl->begin__profile_COMMON(*static_cast<profile_COMMON__AttributeData*>(attributeData));}
bool _data__profile_COMMON( const ParserChar* text, size_t textLength );
bool _end__profile_COMMON(){return mImpl->end__profile_COMMON();}
bool _preBegin__profile_COMMON( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_COMMON();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_COMMON( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_COMMON();
#endif
bool _freeAttributes__profile_COMMON( void* attributeData );

bool _begin__newparam____fx_common_newparam_type( void* attributeData ){return mImpl->begin__newparam____fx_common_newparam_type(*static_cast<newparam____fx_common_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____fx_common_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____fx_common_newparam_type(){return mImpl->end__newparam____fx_common_newparam_type();}
bool _preBegin__newparam____fx_common_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____fx_common_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____fx_common_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____fx_common_newparam_type();
#endif
bool _freeAttributes__newparam____fx_common_newparam_type( void* attributeData );

bool _begin__profile_common_type____technique( void* attributeData ){return mImpl->begin__profile_common_type____technique(*static_cast<profile_common_type____technique__AttributeData*>(attributeData));}
bool _data__profile_common_type____technique( const ParserChar* text, size_t textLength );
bool _end__profile_common_type____technique(){return mImpl->end__profile_common_type____technique();}
bool _preBegin__profile_common_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_common_type____technique();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_common_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_common_type____technique();
#endif
bool _freeAttributes__profile_common_type____technique( void* attributeData );

bool _begin__profile_COMMON__technique__constant( void* attributeData ){return mImpl->begin__profile_COMMON__technique__constant();}
bool _data__profile_COMMON__technique__constant( const ParserChar* text, size_t textLength );
bool _end__profile_COMMON__technique__constant(){return mImpl->end__profile_COMMON__technique__constant();}
bool _preBegin__profile_COMMON__technique__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_COMMON__technique__constant();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_COMMON__technique__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_COMMON__technique__constant();
#endif
bool _freeAttributes__profile_COMMON__technique__constant( void* attributeData );

bool _begin__emission( void* attributeData ){return mImpl->begin__emission();}
bool _data__emission( const ParserChar* text, size_t textLength );
bool _end__emission(){return mImpl->end__emission();}
bool _preBegin__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__emission();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__emission();
#endif
bool _freeAttributes__emission( void* attributeData );

bool _begin__fx_common_color_or_texture_type____color( void* attributeData ){return mImpl->begin__fx_common_color_or_texture_type____color(*static_cast<fx_common_color_or_texture_type____color__AttributeData*>(attributeData));}
bool _data__fx_common_color_or_texture_type____color( const ParserChar* text, size_t textLength );
bool _end__fx_common_color_or_texture_type____color(){return mImpl->end__fx_common_color_or_texture_type____color();}
bool _preBegin__fx_common_color_or_texture_type____color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fx_common_color_or_texture_type____color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fx_common_color_or_texture_type____color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_common_color_or_texture_type____color();
#endif
bool _freeAttributes__fx_common_color_or_texture_type____color( void* attributeData );

bool _begin__fx_common_color_or_texture_type____param( void* attributeData ){return mImpl->begin__fx_common_color_or_texture_type____param(*static_cast<fx_common_color_or_texture_type____param__AttributeData*>(attributeData));}
bool _data__fx_common_color_or_texture_type____param( const ParserChar* text, size_t textLength );
bool _end__fx_common_color_or_texture_type____param(){return mImpl->end__fx_common_color_or_texture_type____param();}
bool _preBegin__fx_common_color_or_texture_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fx_common_color_or_texture_type____param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fx_common_color_or_texture_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_common_color_or_texture_type____param();
#endif
bool _freeAttributes__fx_common_color_or_texture_type____param( void* attributeData );

bool _begin__texture( void* attributeData ){return mImpl->begin__texture(*static_cast<texture__AttributeData*>(attributeData));}
bool _data__texture( const ParserChar* text, size_t textLength );
bool _end__texture(){return mImpl->end__texture();}
bool _preBegin__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture();
#endif
bool _freeAttributes__texture( void* attributeData );

bool _begin__reflective( void* attributeData ){return mImpl->begin__reflective();}
bool _data__reflective( const ParserChar* text, size_t textLength );
bool _end__reflective(){return mImpl->end__reflective();}
bool _preBegin__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__reflective();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__reflective();
#endif
bool _freeAttributes__reflective( void* attributeData );

bool _begin__reflectivity( void* attributeData ){return mImpl->begin__reflectivity();}
bool _data__reflectivity( const ParserChar* text, size_t textLength );
bool _end__reflectivity(){return mImpl->end__reflectivity();}
bool _preBegin__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__reflectivity();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__reflectivity();
#endif
bool _freeAttributes__reflectivity( void* attributeData );

bool _begin__fx_common_float_or_param_type____float( void* attributeData ){return mImpl->begin__fx_common_float_or_param_type____float(*static_cast<fx_common_float_or_param_type____float__AttributeData*>(attributeData));}
bool _data__fx_common_float_or_param_type____float( const ParserChar* text, size_t textLength );
bool _end__fx_common_float_or_param_type____float(){return mImpl->end__fx_common_float_or_param_type____float();}
bool _preBegin__fx_common_float_or_param_type____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fx_common_float_or_param_type____float();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fx_common_float_or_param_type____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_common_float_or_param_type____float();
#endif
bool _freeAttributes__fx_common_float_or_param_type____float( void* attributeData );

bool _begin__fx_common_float_or_param_type____param( void* attributeData ){return mImpl->begin__fx_common_float_or_param_type____param(*static_cast<fx_common_float_or_param_type____param__AttributeData*>(attributeData));}
bool _data__fx_common_float_or_param_type____param( const ParserChar* text, size_t textLength );
bool _end__fx_common_float_or_param_type____param(){return mImpl->end__fx_common_float_or_param_type____param();}
bool _preBegin__fx_common_float_or_param_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fx_common_float_or_param_type____param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fx_common_float_or_param_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_common_float_or_param_type____param();
#endif
bool _freeAttributes__fx_common_float_or_param_type____param( void* attributeData );

bool _begin__transparent( void* attributeData ){return mImpl->begin__transparent(*static_cast<transparent__AttributeData*>(attributeData));}
bool _data__transparent( const ParserChar* text, size_t textLength );
bool _end__transparent(){return mImpl->end__transparent();}
bool _preBegin__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__transparent();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__transparent();
#endif
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
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_opaque_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_opaque_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_opaque_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_opaque_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__transparency( void* attributeData ){return mImpl->begin__transparency();}
bool _data__transparency( const ParserChar* text, size_t textLength );
bool _end__transparency(){return mImpl->end__transparency();}
bool _preBegin__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__transparency();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__transparency();
#endif
bool _freeAttributes__transparency( void* attributeData );

bool _begin__index_of_refraction( void* attributeData ){return mImpl->begin__index_of_refraction();}
bool _data__index_of_refraction( const ParserChar* text, size_t textLength );
bool _end__index_of_refraction(){return mImpl->end__index_of_refraction();}
bool _preBegin__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__index_of_refraction();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__index_of_refraction();
#endif
bool _freeAttributes__index_of_refraction( void* attributeData );

bool _begin__lambert( void* attributeData ){return mImpl->begin__lambert();}
bool _data__lambert( const ParserChar* text, size_t textLength );
bool _end__lambert(){return mImpl->end__lambert();}
bool _preBegin__lambert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lambert();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lambert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lambert();
#endif
bool _freeAttributes__lambert( void* attributeData );

bool _begin__ambient____fx_common_color_or_texture_type( void* attributeData ){return mImpl->begin__ambient____fx_common_color_or_texture_type();}
bool _data__ambient____fx_common_color_or_texture_type( const ParserChar* text, size_t textLength );
bool _end__ambient____fx_common_color_or_texture_type(){return mImpl->end__ambient____fx_common_color_or_texture_type();}
bool _preBegin__ambient____fx_common_color_or_texture_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ambient____fx_common_color_or_texture_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ambient____fx_common_color_or_texture_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ambient____fx_common_color_or_texture_type();
#endif
bool _freeAttributes__ambient____fx_common_color_or_texture_type( void* attributeData );

bool _begin__diffuse( void* attributeData ){return mImpl->begin__diffuse();}
bool _data__diffuse( const ParserChar* text, size_t textLength );
bool _end__diffuse(){return mImpl->end__diffuse();}
bool _preBegin__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__diffuse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__diffuse();
#endif
bool _freeAttributes__diffuse( void* attributeData );

bool _begin__phong( void* attributeData ){return mImpl->begin__phong();}
bool _data__phong( const ParserChar* text, size_t textLength );
bool _end__phong(){return mImpl->end__phong();}
bool _preBegin__phong( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__phong();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__phong( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__phong();
#endif
bool _freeAttributes__phong( void* attributeData );

bool _begin__specular( void* attributeData ){return mImpl->begin__specular();}
bool _data__specular( const ParserChar* text, size_t textLength );
bool _end__specular(){return mImpl->end__specular();}
bool _preBegin__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__specular();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__specular();
#endif
bool _freeAttributes__specular( void* attributeData );

bool _begin__shininess( void* attributeData ){return mImpl->begin__shininess();}
bool _data__shininess( const ParserChar* text, size_t textLength );
bool _end__shininess(){return mImpl->end__shininess();}
bool _preBegin__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__shininess();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__shininess();
#endif
bool _freeAttributes__shininess( void* attributeData );

bool _begin__blinn( void* attributeData ){return mImpl->begin__blinn();}
bool _data__blinn( const ParserChar* text, size_t textLength );
bool _end__blinn(){return mImpl->end__blinn();}
bool _preBegin__blinn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__blinn();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__blinn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blinn();
#endif
bool _freeAttributes__blinn( void* attributeData );

bool _begin__profile_BRIDGE( void* attributeData ){return mImpl->begin__profile_BRIDGE(*static_cast<profile_BRIDGE__AttributeData*>(attributeData));}
bool _data__profile_BRIDGE( const ParserChar* text, size_t textLength );
bool _end__profile_BRIDGE(){return mImpl->end__profile_BRIDGE();}
bool _preBegin__profile_BRIDGE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_BRIDGE();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_BRIDGE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_BRIDGE();
#endif
bool _freeAttributes__profile_BRIDGE( void* attributeData );

bool _begin__profile_GLES2( void* attributeData ){return mImpl->begin__profile_GLES2(*static_cast<profile_GLES2__AttributeData*>(attributeData));}
bool _data__profile_GLES2( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2(){return mImpl->end__profile_GLES2();}
bool _preBegin__profile_GLES2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2();
#endif
bool _freeAttributes__profile_GLES2( void* attributeData );

bool _begin__include( void* attributeData ){return mImpl->begin__include(*static_cast<include__AttributeData*>(attributeData));}
bool _data__include( const ParserChar* text, size_t textLength );
bool _end__include(){return mImpl->end__include();}
bool _preBegin__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__include();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__include();
#endif
bool _freeAttributes__include( void* attributeData );

bool _begin__code( void* attributeData ){return mImpl->begin__code(*static_cast<code__AttributeData*>(attributeData));}
bool _data__code( const ParserChar* text, size_t textLength );
bool _end__code(){return mImpl->end__code();}
bool _preBegin__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__code();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__code();
#endif
bool _freeAttributes__code( void* attributeData );

bool _begin__profile_gles2_type____newparam( void* attributeData ){return mImpl->begin__profile_gles2_type____newparam(*static_cast<profile_gles2_type____newparam__AttributeData*>(attributeData));}
bool _data__profile_gles2_type____newparam( const ParserChar* text, size_t textLength );
bool _end__profile_gles2_type____newparam(){return mImpl->end__profile_gles2_type____newparam();}
bool _preBegin__profile_gles2_type____newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_gles2_type____newparam();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_gles2_type____newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_gles2_type____newparam();
#endif
bool _freeAttributes__profile_gles2_type____newparam( void* attributeData );

bool _begin__bvec2( void* attributeData ){return mImpl->begin__bvec2();}
bool _data__bvec2( const ParserChar* text, size_t textLength );
bool _end__bvec2(){return mImpl->end__bvec2();}
bool _preBegin__bvec2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bvec2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bvec2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bvec2();
#endif
bool _freeAttributes__bvec2( void* attributeData );

bool _begin__bvec3( void* attributeData ){return mImpl->begin__bvec3();}
bool _data__bvec3( const ParserChar* text, size_t textLength );
bool _end__bvec3(){return mImpl->end__bvec3();}
bool _preBegin__bvec3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bvec3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bvec3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bvec3();
#endif
bool _freeAttributes__bvec3( void* attributeData );

bool _begin__bvec4( void* attributeData ){return mImpl->begin__bvec4();}
bool _data__bvec4( const ParserChar* text, size_t textLength );
bool _end__bvec4(){return mImpl->end__bvec4();}
bool _preBegin__bvec4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bvec4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bvec4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bvec4();
#endif
bool _freeAttributes__bvec4( void* attributeData );

bool _begin__vec2( void* attributeData ){return mImpl->begin__vec2();}
bool _data__vec2( const ParserChar* text, size_t textLength );
bool _end__vec2(){return mImpl->end__vec2();}
bool _preBegin__vec2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vec2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vec2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vec2();
#endif
bool _freeAttributes__vec2( void* attributeData );

bool _begin__vec3( void* attributeData ){return mImpl->begin__vec3();}
bool _data__vec3( const ParserChar* text, size_t textLength );
bool _end__vec3(){return mImpl->end__vec3();}
bool _preBegin__vec3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vec3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vec3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vec3();
#endif
bool _freeAttributes__vec3( void* attributeData );

bool _begin__vec4( void* attributeData ){return mImpl->begin__vec4();}
bool _data__vec4( const ParserChar* text, size_t textLength );
bool _end__vec4(){return mImpl->end__vec4();}
bool _preBegin__vec4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vec4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vec4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vec4();
#endif
bool _freeAttributes__vec4( void* attributeData );

bool _begin__mat2( void* attributeData ){return mImpl->begin__mat2();}
bool _data__mat2( const ParserChar* text, size_t textLength );
bool _end__mat2(){return mImpl->end__mat2();}
bool _preBegin__mat2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mat2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mat2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mat2();
#endif
bool _freeAttributes__mat2( void* attributeData );

bool _begin__mat3( void* attributeData ){return mImpl->begin__mat3();}
bool _data__mat3( const ParserChar* text, size_t textLength );
bool _end__mat3(){return mImpl->end__mat3();}
bool _preBegin__mat3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mat3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mat3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mat3();
#endif
bool _freeAttributes__mat3( void* attributeData );

bool _begin__mat4( void* attributeData ){return mImpl->begin__mat4();}
bool _data__mat4( const ParserChar* text, size_t textLength );
bool _end__mat4(){return mImpl->end__mat4();}
bool _preBegin__mat4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mat4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mat4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mat4();
#endif
bool _freeAttributes__mat4( void* attributeData );

bool _begin__ivec2( void* attributeData ){return mImpl->begin__ivec2();}
bool _data__ivec2( const ParserChar* text, size_t textLength );
bool _end__ivec2(){return mImpl->end__ivec2();}
bool _preBegin__ivec2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ivec2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ivec2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ivec2();
#endif
bool _freeAttributes__ivec2( void* attributeData );

bool _begin__ivec3( void* attributeData ){return mImpl->begin__ivec3();}
bool _data__ivec3( const ParserChar* text, size_t textLength );
bool _end__ivec3(){return mImpl->end__ivec3();}
bool _preBegin__ivec3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ivec3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ivec3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ivec3();
#endif
bool _freeAttributes__ivec3( void* attributeData );

bool _begin__ivec4( void* attributeData ){return mImpl->begin__ivec4();}
bool _data__ivec4( const ParserChar* text, size_t textLength );
bool _end__ivec4(){return mImpl->end__ivec4();}
bool _preBegin__ivec4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ivec4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ivec4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ivec4();
#endif
bool _freeAttributes__ivec4( void* attributeData );

bool _begin__enum____gl_enumeration_type( void* attributeData ){return mImpl->begin__enum____gl_enumeration_type();}
bool _data__enum____gl_enumeration_type( const ParserChar* text, size_t textLength );
bool _end__enum____gl_enumeration_type(){return mImpl->end__enum____gl_enumeration_type();}
bool _preBegin__enum____gl_enumeration_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__enum____gl_enumeration_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__enum____gl_enumeration_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enum____gl_enumeration_type();
#endif
bool _freeAttributes__enum____gl_enumeration_type( void* attributeData );


ENUM__gl_blend_enum toEnumDataPrefix_ENUM__gl_blend_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_blend_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_blend_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_blend_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_blend_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_blend_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_blend_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_blend_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_face_enum toEnumDataPrefix_ENUM__gl_face_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_face_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_face_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_face_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_face_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_face_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_face_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_blend_equation_enum toEnumDataPrefix_ENUM__gl_blend_equation_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_equation_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_blend_equation_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_blend_equation_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_blend_equation_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_blend_equation_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_blend_equation_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_blend_equation_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_blend_equation_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_func_enum toEnumDataPrefix_ENUM__gl_func_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_func_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_func_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_func_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_func_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_func_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_func_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_func_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_func_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_stencil_op_enum toEnumDataPrefix_ENUM__gl_stencil_op_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_stencil_op_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_stencil_op_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_stencil_op_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_stencil_op_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_stencil_op_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_stencil_op_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_material_enum toEnumDataPrefix_ENUM__gl_material_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_material_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_material_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_material_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_material_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_material_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_material_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_material_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_material_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_fog_enum toEnumDataPrefix_ENUM__gl_fog_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_fog_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_fog_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_fog_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_fog_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_fog_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_fog_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_fog_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_fog_coord_src_enum toEnumDataPrefix_ENUM__gl_fog_coord_src_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_coord_src_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_fog_coord_src_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_fog_coord_src_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_fog_coord_src_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_fog_coord_src_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_fog_coord_src_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_fog_coord_src_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_fog_coord_src_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_front_face_enum toEnumDataPrefix_ENUM__gl_front_face_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_front_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_front_face_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_front_face_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_front_face_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_front_face_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_front_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_front_face_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_front_face_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_light_model_color_control_enum toEnumDataPrefix_ENUM__gl_light_model_color_control_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_light_model_color_control_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_light_model_color_control_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_light_model_color_control_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_light_model_color_control_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_light_model_color_control_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_light_model_color_control_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_light_model_color_control_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_light_model_color_control_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_logic_op_enum toEnumDataPrefix_ENUM__gl_logic_op_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_logic_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_logic_op_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_logic_op_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_logic_op_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_logic_op_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_logic_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_logic_op_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_logic_op_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_polygon_mode_enum toEnumDataPrefix_ENUM__gl_polygon_mode_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_polygon_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_polygon_mode_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_polygon_mode_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_polygon_mode_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_polygon_mode_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_polygon_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_polygon_mode_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_polygon_mode_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_shade_model_enum toEnumDataPrefix_ENUM__gl_shade_model_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_shade_model_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_shade_model_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_shade_model_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_shade_model_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gl_shade_model_enum*, size_t ),
    const std::pair<StringHash, ENUM__gl_shade_model_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_shade_model_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_shade_model_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




UNION__gl_enumeration_type toUnionPrefix_UNION__gl_enumeration_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed
);



bool _begin__profile_GLES2__newparam__usertype( void* attributeData ){return mImpl->begin__profile_GLES2__newparam__usertype(*static_cast<profile_GLES2__newparam__usertype__AttributeData*>(attributeData));}
bool _data__profile_GLES2__newparam__usertype( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__newparam__usertype(){return mImpl->end__profile_GLES2__newparam__usertype();}
bool _preBegin__profile_GLES2__newparam__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__newparam__usertype();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__newparam__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__newparam__usertype();
#endif
bool _freeAttributes__profile_GLES2__newparam__usertype( void* attributeData );

bool _begin__profile_GLES2__newparam__usertype__setparam( void* attributeData ){return mImpl->begin__profile_GLES2__newparam__usertype__setparam(*static_cast<profile_GLES2__newparam__usertype__setparam__AttributeData*>(attributeData));}
bool _data__profile_GLES2__newparam__usertype__setparam( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__newparam__usertype__setparam(){return mImpl->end__profile_GLES2__newparam__usertype__setparam();}
bool _preBegin__profile_GLES2__newparam__usertype__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__newparam__usertype__setparam();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__newparam__usertype__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__newparam__usertype__setparam();
#endif
bool _freeAttributes__profile_GLES2__newparam__usertype__setparam( void* attributeData );

bool _begin__profile_GLES2__newparam__usertype__setparam__array( void* attributeData ){return mImpl->begin__profile_GLES2__newparam__usertype__setparam__array(*static_cast<profile_GLES2__newparam__usertype__setparam__array__AttributeData*>(attributeData));}
bool _data__profile_GLES2__newparam__usertype__setparam__array( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__newparam__usertype__setparam__array(){return mImpl->end__profile_GLES2__newparam__usertype__setparam__array();}
bool _preBegin__profile_GLES2__newparam__usertype__setparam__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__newparam__usertype__setparam__array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__newparam__usertype__setparam__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__newparam__usertype__setparam__array();
#endif
bool _freeAttributes__profile_GLES2__newparam__usertype__setparam__array( void* attributeData );

bool _begin__profile_gles2_type____technique( void* attributeData ){return mImpl->begin__profile_gles2_type____technique(*static_cast<profile_gles2_type____technique__AttributeData*>(attributeData));}
bool _data__profile_gles2_type____technique( const ParserChar* text, size_t textLength );
bool _end__profile_gles2_type____technique(){return mImpl->end__profile_gles2_type____technique();}
bool _preBegin__profile_gles2_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_gles2_type____technique();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_gles2_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_gles2_type____technique();
#endif
bool _freeAttributes__profile_gles2_type____technique( void* attributeData );

bool _begin__pass____gles2_pass_type( void* attributeData ){return mImpl->begin__pass____gles2_pass_type(*static_cast<pass____gles2_pass_type__AttributeData*>(attributeData));}
bool _data__pass____gles2_pass_type( const ParserChar* text, size_t textLength );
bool _end__pass____gles2_pass_type(){return mImpl->end__pass____gles2_pass_type();}
bool _preBegin__pass____gles2_pass_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__pass____gles2_pass_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__pass____gles2_pass_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__pass____gles2_pass_type();
#endif
bool _freeAttributes__pass____gles2_pass_type( void* attributeData );

bool _begin__gles2_pass_type____states( void* attributeData ){return mImpl->begin__gles2_pass_type____states();}
bool _data__gles2_pass_type____states( const ParserChar* text, size_t textLength );
bool _end__gles2_pass_type____states(){return mImpl->end__gles2_pass_type____states();}
bool _preBegin__gles2_pass_type____states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gles2_pass_type____states();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gles2_pass_type____states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gles2_pass_type____states();
#endif
bool _freeAttributes__gles2_pass_type____states( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_color( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_color(*static_cast<profile_GLES2__technique__pass__states__blend_color__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_color(){return mImpl->end__profile_GLES2__technique__pass__states__blend_color();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_color();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_color( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_equation( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_equation(*static_cast<profile_GLES2__technique__pass__states__blend_equation__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_equation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_equation(){return mImpl->end__profile_GLES2__technique__pass__states__blend_equation();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_equation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_equation();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_equation( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_equation_separate( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_equation_separate();}
bool _data__profile_GLES2__technique__pass__states__blend_equation_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_equation_separate(){return mImpl->end__profile_GLES2__technique__pass__states__blend_equation_separate();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_equation_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_equation_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_equation_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_equation_separate();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_equation_separate( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_equation_separate__rgb( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_equation_separate__rgb(*static_cast<profile_GLES2__technique__pass__states__blend_equation_separate__rgb__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_equation_separate__rgb( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_equation_separate__rgb(){return mImpl->end__profile_GLES2__technique__pass__states__blend_equation_separate__rgb();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_equation_separate__rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_equation_separate__rgb();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_equation_separate__rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_equation_separate__rgb();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_equation_separate__rgb( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_equation_separate__alpha( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_equation_separate__alpha(*static_cast<profile_GLES2__technique__pass__states__blend_equation_separate__alpha__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_equation_separate__alpha( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_equation_separate__alpha(){return mImpl->end__profile_GLES2__technique__pass__states__blend_equation_separate__alpha();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_equation_separate__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_equation_separate__alpha();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_equation_separate__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_equation_separate__alpha();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_equation_separate__alpha( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func();}
bool _data__profile_GLES2__technique__pass__states__blend_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func__src( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func__src(*static_cast<profile_GLES2__technique__pass__states__blend_func__src__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_func__src( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func__src(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func__src();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func__src();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func__src();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func__src( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func__dest( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func__dest(*static_cast<profile_GLES2__technique__pass__states__blend_func__dest__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_func__dest( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func__dest(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func__dest();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func__dest();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func__dest();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func__dest( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func_separate( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func_separate();}
bool _data__profile_GLES2__technique__pass__states__blend_func_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func_separate(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func_separate();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func_separate();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func_separate( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb(*static_cast<profile_GLES2__technique__pass__states__blend_func_separate__src_rgb__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb(*static_cast<profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha(*static_cast<profile_GLES2__technique__pass__states__blend_func_separate__src_alpha__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha(*static_cast<profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha(){return mImpl->end__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__color_mask( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__color_mask(*static_cast<profile_GLES2__technique__pass__states__color_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__color_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__color_mask(){return mImpl->end__profile_GLES2__technique__pass__states__color_mask();}
bool _preBegin__profile_GLES2__technique__pass__states__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__color_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__color_mask();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__color_mask( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__cull_face( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__cull_face(*static_cast<profile_GLES2__technique__pass__states__cull_face__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__cull_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__cull_face(){return mImpl->end__profile_GLES2__technique__pass__states__cull_face();}
bool _preBegin__profile_GLES2__technique__pass__states__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__cull_face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__cull_face();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__cull_face( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__depth_func( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__depth_func(*static_cast<profile_GLES2__technique__pass__states__depth_func__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__depth_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__depth_func(){return mImpl->end__profile_GLES2__technique__pass__states__depth_func();}
bool _preBegin__profile_GLES2__technique__pass__states__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__depth_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__depth_func();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__depth_func( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__depth_mask( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__depth_mask(*static_cast<profile_GLES2__technique__pass__states__depth_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__depth_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__depth_mask(){return mImpl->end__profile_GLES2__technique__pass__states__depth_mask();}
bool _preBegin__profile_GLES2__technique__pass__states__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__depth_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__depth_mask();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__depth_mask( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__depth_range( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__depth_range(*static_cast<profile_GLES2__technique__pass__states__depth_range__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__depth_range( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__depth_range(){return mImpl->end__profile_GLES2__technique__pass__states__depth_range();}
bool _preBegin__profile_GLES2__technique__pass__states__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__depth_range();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__depth_range();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__depth_range( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__front_face( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__front_face(*static_cast<profile_GLES2__technique__pass__states__front_face__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__front_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__front_face(){return mImpl->end__profile_GLES2__technique__pass__states__front_face();}
bool _preBegin__profile_GLES2__technique__pass__states__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__front_face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__front_face();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__front_face( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__line_width( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__line_width(*static_cast<profile_GLES2__technique__pass__states__line_width__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__line_width( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__line_width(){return mImpl->end__profile_GLES2__technique__pass__states__line_width();}
bool _preBegin__profile_GLES2__technique__pass__states__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__line_width();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__line_width();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__line_width( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__polygon_offset( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__polygon_offset(*static_cast<profile_GLES2__technique__pass__states__polygon_offset__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__polygon_offset( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__polygon_offset(){return mImpl->end__profile_GLES2__technique__pass__states__polygon_offset();}
bool _preBegin__profile_GLES2__technique__pass__states__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__polygon_offset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__polygon_offset();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__polygon_offset( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__point_size( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__point_size(*static_cast<profile_GLES2__technique__pass__states__point_size__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__point_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__point_size(){return mImpl->end__profile_GLES2__technique__pass__states__point_size();}
bool _preBegin__profile_GLES2__technique__pass__states__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__point_size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__point_size();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__point_size( void* attributeData );

bool _begin__sample_coverage( void* attributeData ){return mImpl->begin__sample_coverage();}
bool _data__sample_coverage( const ParserChar* text, size_t textLength );
bool _end__sample_coverage(){return mImpl->end__sample_coverage();}
bool _preBegin__sample_coverage( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sample_coverage();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sample_coverage( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sample_coverage();
#endif
bool _freeAttributes__sample_coverage( void* attributeData );

bool _begin__sample_coverage__value( void* attributeData ){return mImpl->begin__sample_coverage__value(*static_cast<sample_coverage__value__AttributeData*>(attributeData));}
bool _data__sample_coverage__value( const ParserChar* text, size_t textLength );
bool _end__sample_coverage__value(){return mImpl->end__sample_coverage__value();}
bool _preBegin__sample_coverage__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sample_coverage__value();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sample_coverage__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sample_coverage__value();
#endif
bool _freeAttributes__sample_coverage__value( void* attributeData );

bool _begin__invert( void* attributeData ){return mImpl->begin__invert(*static_cast<invert__AttributeData*>(attributeData));}
bool _data__invert( const ParserChar* text, size_t textLength );
bool _end__invert(){return mImpl->end__invert();}
bool _preBegin__invert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__invert();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__invert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__invert();
#endif
bool _freeAttributes__invert( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__scissor( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__scissor(*static_cast<profile_GLES2__technique__pass__states__scissor__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__scissor( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__scissor(){return mImpl->end__profile_GLES2__technique__pass__states__scissor();}
bool _preBegin__profile_GLES2__technique__pass__states__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__scissor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__scissor();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__scissor( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func();}
bool _data__profile_GLES2__technique__pass__states__stencil_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func__func( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func__func(*static_cast<profile_GLES2__technique__pass__states__stencil_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func__func(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func__func();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func__func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func__func();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func__func( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func__ref( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func__ref(*static_cast<profile_GLES2__technique__pass__states__stencil_func__ref__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func__ref(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func__ref();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func__ref();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func__ref();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func__ref( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func__mask( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func__mask(*static_cast<profile_GLES2__technique__pass__states__stencil_func__mask__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func__mask(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func__mask();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func__mask();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func__mask( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func_separate( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func_separate();}
bool _data__profile_GLES2__technique__pass__states__stencil_func_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func_separate(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func_separate();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func_separate();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func_separate( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func_separate__front( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func_separate__front(*static_cast<profile_GLES2__technique__pass__states__stencil_func_separate__front__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func_separate__front( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func_separate__front(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func_separate__front();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func_separate__front( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func_separate__front();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func_separate__front( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func_separate__front();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func_separate__front( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func_separate__back( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func_separate__back(*static_cast<profile_GLES2__technique__pass__states__stencil_func_separate__back__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func_separate__back( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func_separate__back(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func_separate__back();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func_separate__back( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func_separate__back();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func_separate__back( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func_separate__back();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func_separate__back( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func_separate__ref( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func_separate__ref(*static_cast<profile_GLES2__technique__pass__states__stencil_func_separate__ref__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func_separate__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func_separate__ref(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func_separate__ref();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func_separate__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func_separate__ref();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func_separate__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func_separate__ref();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func_separate__ref( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_func_separate__mask( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_func_separate__mask(*static_cast<profile_GLES2__technique__pass__states__stencil_func_separate__mask__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_func_separate__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_func_separate__mask(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_func_separate__mask();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_func_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_func_separate__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_func_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_func_separate__mask();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_func_separate__mask( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_mask( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_mask(*static_cast<profile_GLES2__technique__pass__states__stencil_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_mask(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_mask();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_mask();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_mask( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_mask_separate( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_mask_separate();}
bool _data__profile_GLES2__technique__pass__states__stencil_mask_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_mask_separate(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_mask_separate();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_mask_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_mask_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_mask_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_mask_separate();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_mask_separate( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_mask_separate__face( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_mask_separate__face(*static_cast<profile_GLES2__technique__pass__states__stencil_mask_separate__face__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_mask_separate__face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_mask_separate__face(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_mask_separate__face();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_mask_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_mask_separate__face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_mask_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_mask_separate__face();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_mask_separate__face( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_mask_separate__mask( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_mask_separate__mask(*static_cast<profile_GLES2__technique__pass__states__stencil_mask_separate__mask__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_mask_separate__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_mask_separate__mask(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_mask_separate__mask();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_mask_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_mask_separate__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_mask_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_mask_separate__mask();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_mask_separate__mask( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op();}
bool _data__profile_GLES2__technique__pass__states__stencil_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op__fail( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op__fail(*static_cast<profile_GLES2__technique__pass__states__stencil_op__fail__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op__fail(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op__fail();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op__fail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op__fail();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op__fail( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op__zfail( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op__zfail(*static_cast<profile_GLES2__technique__pass__states__stencil_op__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op__zfail(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op__zfail();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op__zfail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op__zfail();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op__zfail( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op__zpass( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op__zpass(*static_cast<profile_GLES2__technique__pass__states__stencil_op__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op__zpass(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op__zpass();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op__zpass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op__zpass();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op__zpass( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op_separate( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op_separate();}
bool _data__profile_GLES2__technique__pass__states__stencil_op_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op_separate(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op_separate();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op_separate();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op_separate( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op_separate__face( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op_separate__face(*static_cast<profile_GLES2__technique__pass__states__stencil_op_separate__face__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op_separate__face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op_separate__face(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op_separate__face();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op_separate__face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op_separate__face();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op_separate__face( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op_separate__fail( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op_separate__fail(*static_cast<profile_GLES2__technique__pass__states__stencil_op_separate__fail__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op_separate__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op_separate__fail(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op_separate__fail();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op_separate__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op_separate__fail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op_separate__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op_separate__fail();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op_separate__fail( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op_separate__zfail( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op_separate__zfail(*static_cast<profile_GLES2__technique__pass__states__stencil_op_separate__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op_separate__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op_separate__zfail(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op_separate__zfail();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op_separate__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op_separate__zfail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op_separate__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op_separate__zfail();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op_separate__zfail( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_op_separate__zpass( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_op_separate__zpass(*static_cast<profile_GLES2__technique__pass__states__stencil_op_separate__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_op_separate__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_op_separate__zpass(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_op_separate__zpass();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_op_separate__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_op_separate__zpass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_op_separate__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_op_separate__zpass();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_op_separate__zpass( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__blend_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__blend_enable(*static_cast<profile_GLES2__technique__pass__states__blend_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__blend_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__blend_enable(){return mImpl->end__profile_GLES2__technique__pass__states__blend_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__blend_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__blend_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__blend_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__cull_face_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__cull_face_enable(*static_cast<profile_GLES2__technique__pass__states__cull_face_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__cull_face_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__cull_face_enable(){return mImpl->end__profile_GLES2__technique__pass__states__cull_face_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__cull_face_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__cull_face_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__cull_face_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__depth_test_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__depth_test_enable(*static_cast<profile_GLES2__technique__pass__states__depth_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__depth_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__depth_test_enable(){return mImpl->end__profile_GLES2__technique__pass__states__depth_test_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__depth_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__depth_test_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__depth_test_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__dither_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__dither_enable(*static_cast<profile_GLES2__technique__pass__states__dither_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__dither_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__dither_enable(){return mImpl->end__profile_GLES2__technique__pass__states__dither_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__dither_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__dither_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__dither_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__polygon_offset_fill_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__polygon_offset_fill_enable(*static_cast<profile_GLES2__technique__pass__states__polygon_offset_fill_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__polygon_offset_fill_enable(){return mImpl->end__profile_GLES2__technique__pass__states__polygon_offset_fill_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__polygon_offset_fill_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__polygon_offset_fill_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__polygon_offset_fill_enable( void* attributeData );

bool _begin__point_size_enable( void* attributeData ){return mImpl->begin__point_size_enable(*static_cast<point_size_enable__AttributeData*>(attributeData));}
bool _data__point_size_enable( const ParserChar* text, size_t textLength );
bool _end__point_size_enable(){return mImpl->end__point_size_enable();}
bool _preBegin__point_size_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__point_size_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__point_size_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__point_size_enable();
#endif
bool _freeAttributes__point_size_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable(*static_cast<profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable(){return mImpl->end__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__sample_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__sample_coverage_enable(*static_cast<profile_GLES2__technique__pass__states__sample_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__sample_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__sample_coverage_enable(){return mImpl->end__profile_GLES2__technique__pass__states__sample_coverage_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__sample_coverage_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__sample_coverage_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__sample_coverage_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__scissor_test_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__scissor_test_enable(*static_cast<profile_GLES2__technique__pass__states__scissor_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__scissor_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__scissor_test_enable(){return mImpl->end__profile_GLES2__technique__pass__states__scissor_test_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__scissor_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__scissor_test_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__scissor_test_enable( void* attributeData );

bool _begin__profile_GLES2__technique__pass__states__stencil_test_enable( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__states__stencil_test_enable(*static_cast<profile_GLES2__technique__pass__states__stencil_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__states__stencil_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__states__stencil_test_enable(){return mImpl->end__profile_GLES2__technique__pass__states__stencil_test_enable();}
bool _preBegin__profile_GLES2__technique__pass__states__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__states__stencil_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__states__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__states__stencil_test_enable();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__states__stencil_test_enable( void* attributeData );

bool _begin__program____gles2_program_type( void* attributeData ){return mImpl->begin__program____gles2_program_type();}
bool _data__program____gles2_program_type( const ParserChar* text, size_t textLength );
bool _end__program____gles2_program_type(){return mImpl->end__program____gles2_program_type();}
bool _preBegin__program____gles2_program_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__program____gles2_program_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__program____gles2_program_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__program____gles2_program_type();
#endif
bool _freeAttributes__program____gles2_program_type( void* attributeData );

bool _begin__shader____gles2_shader_type( void* attributeData ){return mImpl->begin__shader____gles2_shader_type(*static_cast<shader____gles2_shader_type__AttributeData*>(attributeData));}
bool _data__shader____gles2_shader_type( const ParserChar* text, size_t textLength );
bool _end__shader____gles2_shader_type(){return mImpl->end__shader____gles2_shader_type();}
bool _preBegin__shader____gles2_shader_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__shader____gles2_shader_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__shader____gles2_shader_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__shader____gles2_shader_type();
#endif
bool _freeAttributes__shader____gles2_shader_type( void* attributeData );


ENUM__fx_pipeline_stage_enum toEnumDataPrefix_ENUM__fx_pipeline_stage_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_pipeline_stage_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_pipeline_stage_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_pipeline_stage_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_pipeline_stage_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__fx_pipeline_stage_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_pipeline_stage_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_pipeline_stage_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_pipeline_stage_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__gles2_shader_type____sources( void* attributeData ){return mImpl->begin__gles2_shader_type____sources(*static_cast<gles2_shader_type____sources__AttributeData*>(attributeData));}
bool _data__gles2_shader_type____sources( const ParserChar* text, size_t textLength );
bool _end__gles2_shader_type____sources(){return mImpl->end__gles2_shader_type____sources();}
bool _preBegin__gles2_shader_type____sources( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gles2_shader_type____sources();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gles2_shader_type____sources( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gles2_shader_type____sources();
#endif
bool _freeAttributes__gles2_shader_type____sources( void* attributeData );

bool _begin__inline( void* attributeData ){return mImpl->begin__inline();}
bool _data__inline( const ParserChar* text, size_t textLength );
bool _end__inline(){return mImpl->end__inline();}
bool _preBegin__inline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__inline();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__inline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__inline();
#endif
bool _freeAttributes__inline( void* attributeData );

bool _begin__import( void* attributeData ){return mImpl->begin__import(*static_cast<import__AttributeData*>(attributeData));}
bool _data__import( const ParserChar* text, size_t textLength );
bool _end__import(){return mImpl->end__import();}
bool _preBegin__import( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__import();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__import( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__import();
#endif
bool _freeAttributes__import( void* attributeData );

bool _begin__compiler( void* attributeData ){return mImpl->begin__compiler(*static_cast<compiler__AttributeData*>(attributeData));}
bool _data__compiler( const ParserChar* text, size_t textLength );
bool _end__compiler(){return mImpl->end__compiler();}
bool _preBegin__compiler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__compiler();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__compiler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__compiler();
#endif
bool _freeAttributes__compiler( void* attributeData );

bool _begin__binary( void* attributeData ){return mImpl->begin__binary();}
bool _data__binary( const ParserChar* text, size_t textLength );
bool _end__binary(){return mImpl->end__binary();}
bool _preBegin__binary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__binary();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__binary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__binary();
#endif
bool _freeAttributes__binary( void* attributeData );

bool _begin__ref____anyURI( void* attributeData ){return mImpl->begin__ref____anyURI();}
bool _data__ref____anyURI( const ParserChar* text, size_t textLength );
bool _end__ref____anyURI(){return mImpl->end__ref____anyURI();}
bool _preBegin__ref____anyURI( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ref____anyURI();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ref____anyURI( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ref____anyURI();
#endif
bool _freeAttributes__ref____anyURI( void* attributeData );

bool _begin__binary__hex( void* attributeData ){return mImpl->begin__binary__hex(*static_cast<binary__hex__AttributeData*>(attributeData));}
bool _data__binary__hex( const ParserChar* text, size_t textLength );
bool _end__binary__hex(){return mImpl->end__binary__hex();}
bool _preBegin__binary__hex( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__binary__hex();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__binary__hex( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__binary__hex();
#endif
bool _freeAttributes__binary__hex( void* attributeData );

bool _begin__linker( void* attributeData ){return mImpl->begin__linker(*static_cast<linker__AttributeData*>(attributeData));}
bool _data__linker( const ParserChar* text, size_t textLength );
bool _end__linker(){return mImpl->end__linker();}
bool _preBegin__linker( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__linker();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__linker( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__linker();
#endif
bool _freeAttributes__linker( void* attributeData );

bool _begin__gles2_program_type____bind_attribute( void* attributeData ){return mImpl->begin__gles2_program_type____bind_attribute(*static_cast<gles2_program_type____bind_attribute__AttributeData*>(attributeData));}
bool _data__gles2_program_type____bind_attribute( const ParserChar* text, size_t textLength );
bool _end__gles2_program_type____bind_attribute(){return mImpl->end__gles2_program_type____bind_attribute();}
bool _preBegin__gles2_program_type____bind_attribute( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gles2_program_type____bind_attribute();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gles2_program_type____bind_attribute( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gles2_program_type____bind_attribute();
#endif
bool _freeAttributes__gles2_program_type____bind_attribute( void* attributeData );

bool _begin__semantic____token( void* attributeData ){return mImpl->begin__semantic____token();}
bool _data__semantic____token( const ParserChar* text, size_t textLength );
bool _end__semantic____token(){return mImpl->end__semantic____token();}
bool _preBegin__semantic____token( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__semantic____token();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__semantic____token( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__semantic____token();
#endif
bool _freeAttributes__semantic____token( void* attributeData );

bool _begin__gles2_program_type____bind_uniform( void* attributeData ){return mImpl->begin__gles2_program_type____bind_uniform(*static_cast<gles2_program_type____bind_uniform__AttributeData*>(attributeData));}
bool _data__gles2_program_type____bind_uniform( const ParserChar* text, size_t textLength );
bool _end__gles2_program_type____bind_uniform(){return mImpl->end__gles2_program_type____bind_uniform();}
bool _preBegin__gles2_program_type____bind_uniform( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gles2_program_type____bind_uniform();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gles2_program_type____bind_uniform( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gles2_program_type____bind_uniform();
#endif
bool _freeAttributes__gles2_program_type____bind_uniform( void* attributeData );

bool _begin__profile_GLES2__technique__pass__program__bind_uniform__param( void* attributeData ){return mImpl->begin__profile_GLES2__technique__pass__program__bind_uniform__param(*static_cast<profile_GLES2__technique__pass__program__bind_uniform__param__AttributeData*>(attributeData));}
bool _data__profile_GLES2__technique__pass__program__bind_uniform__param( const ParserChar* text, size_t textLength );
bool _end__profile_GLES2__technique__pass__program__bind_uniform__param(){return mImpl->end__profile_GLES2__technique__pass__program__bind_uniform__param();}
bool _preBegin__profile_GLES2__technique__pass__program__bind_uniform__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES2__technique__pass__program__bind_uniform__param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES2__technique__pass__program__bind_uniform__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES2__technique__pass__program__bind_uniform__param();
#endif
bool _freeAttributes__profile_GLES2__technique__pass__program__bind_uniform__param( void* attributeData );

bool _begin__gles2_pass_type____evaluate( void* attributeData ){return mImpl->begin__gles2_pass_type____evaluate();}
bool _data__gles2_pass_type____evaluate( const ParserChar* text, size_t textLength );
bool _end__gles2_pass_type____evaluate(){return mImpl->end__gles2_pass_type____evaluate();}
bool _preBegin__gles2_pass_type____evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gles2_pass_type____evaluate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gles2_pass_type____evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gles2_pass_type____evaluate();
#endif
bool _freeAttributes__gles2_pass_type____evaluate( void* attributeData );

bool _begin__color_target( void* attributeData ){return mImpl->begin__color_target(*static_cast<color_target__AttributeData*>(attributeData));}
bool _data__color_target( const ParserChar* text, size_t textLength );
bool _end__color_target(){return mImpl->end__color_target();}
bool _preBegin__color_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__color_target();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__color_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_target();
#endif
bool _freeAttributes__color_target( void* attributeData );


ENUM__image_face_enum toEnumDataPrefix_ENUM__image_face_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__image_face_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_face_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__image_face_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_face_enum*, size_t ),
    const std::pair<StringHash, ENUM__image_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__image_face_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__image_face_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__fx_colortarget_type____param( void* attributeData ){return mImpl->begin__fx_colortarget_type____param(*static_cast<fx_colortarget_type____param__AttributeData*>(attributeData));}
bool _data__fx_colortarget_type____param( const ParserChar* text, size_t textLength );
bool _end__fx_colortarget_type____param(){return mImpl->end__fx_colortarget_type____param();}
bool _preBegin__fx_colortarget_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fx_colortarget_type____param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fx_colortarget_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_colortarget_type____param();
#endif
bool _freeAttributes__fx_colortarget_type____param( void* attributeData );

bool _begin__depth_target( void* attributeData ){return mImpl->begin__depth_target(*static_cast<depth_target__AttributeData*>(attributeData));}
bool _data__depth_target( const ParserChar* text, size_t textLength );
bool _end__depth_target(){return mImpl->end__depth_target();}
bool _preBegin__depth_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__depth_target();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__depth_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_target();
#endif
bool _freeAttributes__depth_target( void* attributeData );

bool _begin__stencil_target( void* attributeData ){return mImpl->begin__stencil_target(*static_cast<stencil_target__AttributeData*>(attributeData));}
bool _data__stencil_target( const ParserChar* text, size_t textLength );
bool _end__stencil_target(){return mImpl->end__stencil_target();}
bool _preBegin__stencil_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__stencil_target();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__stencil_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_target();
#endif
bool _freeAttributes__stencil_target( void* attributeData );

bool _begin__color_clear( void* attributeData ){return mImpl->begin__color_clear(*static_cast<color_clear__AttributeData*>(attributeData));}
bool _data__color_clear( const ParserChar* text, size_t textLength );
bool _end__color_clear(){return mImpl->end__color_clear();}
bool _preBegin__color_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__color_clear();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__color_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_clear();
#endif
bool _freeAttributes__color_clear( void* attributeData );

bool _begin__stencil_clear( void* attributeData ){return mImpl->begin__stencil_clear(*static_cast<stencil_clear__AttributeData*>(attributeData));}
bool _data__stencil_clear( const ParserChar* text, size_t textLength );
bool _end__stencil_clear(){return mImpl->end__stencil_clear();}
bool _preBegin__stencil_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__stencil_clear();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__stencil_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_clear();
#endif
bool _freeAttributes__stencil_clear( void* attributeData );

bool _begin__depth_clear( void* attributeData ){return mImpl->begin__depth_clear(*static_cast<depth_clear__AttributeData*>(attributeData));}
bool _data__depth_clear( const ParserChar* text, size_t textLength );
bool _end__depth_clear(){return mImpl->end__depth_clear();}
bool _preBegin__depth_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__depth_clear();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__depth_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_clear();
#endif
bool _freeAttributes__depth_clear( void* attributeData );

bool _begin__draw( void* attributeData ){return mImpl->begin__draw();}
bool _data__draw( const ParserChar* text, size_t textLength );
bool _end__draw(){return mImpl->end__draw();}
bool _preBegin__draw( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__draw();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__draw( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__draw();
#endif
bool _freeAttributes__draw( void* attributeData );

bool _begin__profile_GLSL( void* attributeData ){return mImpl->begin__profile_GLSL(*static_cast<profile_GLSL__AttributeData*>(attributeData));}
bool _data__profile_GLSL( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL(){return mImpl->end__profile_GLSL();}
bool _preBegin__profile_GLSL( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL();
#endif
bool _freeAttributes__profile_GLSL( void* attributeData );

bool _begin__newparam____glsl_newparam_type( void* attributeData ){return mImpl->begin__newparam____glsl_newparam_type(*static_cast<newparam____glsl_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____glsl_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____glsl_newparam_type(){return mImpl->end__newparam____glsl_newparam_type();}
bool _preBegin__newparam____glsl_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____glsl_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____glsl_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____glsl_newparam_type();
#endif
bool _freeAttributes__newparam____glsl_newparam_type( void* attributeData );

bool _begin__array____glsl_array_type( void* attributeData ){return mImpl->begin__array____glsl_array_type(*static_cast<array____glsl_array_type__AttributeData*>(attributeData));}
bool _data__array____glsl_array_type( const ParserChar* text, size_t textLength );
bool _end__array____glsl_array_type(){return mImpl->end__array____glsl_array_type();}
bool _preBegin__array____glsl_array_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__array____glsl_array_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__array____glsl_array_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__array____glsl_array_type();
#endif
bool _freeAttributes__array____glsl_array_type( void* attributeData );

bool _begin__profile_glsl_type____technique( void* attributeData ){return mImpl->begin__profile_glsl_type____technique(*static_cast<profile_glsl_type____technique__AttributeData*>(attributeData));}
bool _data__profile_glsl_type____technique( const ParserChar* text, size_t textLength );
bool _end__profile_glsl_type____technique(){return mImpl->end__profile_glsl_type____technique();}
bool _preBegin__profile_glsl_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_glsl_type____technique();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_glsl_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_glsl_type____technique();
#endif
bool _freeAttributes__profile_glsl_type____technique( void* attributeData );

bool _begin__profile_GLSL__technique__pass( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass(*static_cast<profile_GLSL__technique__pass__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass(){return mImpl->end__profile_GLSL__technique__pass();}
bool _preBegin__profile_GLSL__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass();
#endif
bool _freeAttributes__profile_GLSL__technique__pass( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states();}
bool _data__profile_GLSL__technique__pass__states( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states(){return mImpl->end__profile_GLSL__technique__pass__states();}
bool _preBegin__profile_GLSL__technique__pass__states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__alpha_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__alpha_func();}
bool _data__profile_GLSL__technique__pass__states__alpha_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__alpha_func(){return mImpl->end__profile_GLSL__technique__pass__states__alpha_func();}
bool _preBegin__profile_GLSL__technique__pass__states__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__alpha_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__alpha_func();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__alpha_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__alpha_func__func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__alpha_func__func(*static_cast<profile_GLSL__technique__pass__states__alpha_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__alpha_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__alpha_func__func(){return mImpl->end__profile_GLSL__technique__pass__states__alpha_func__func();}
bool _preBegin__profile_GLSL__technique__pass__states__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__alpha_func__func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__alpha_func__func();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__alpha_func__func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__alpha_func__value( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__alpha_func__value(*static_cast<profile_GLSL__technique__pass__states__alpha_func__value__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__alpha_func__value( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__alpha_func__value(){return mImpl->end__profile_GLSL__technique__pass__states__alpha_func__value();}
bool _preBegin__profile_GLSL__technique__pass__states__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__alpha_func__value();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__alpha_func__value();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__alpha_func__value( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func();}
bool _data__profile_GLSL__technique__pass__states__blend_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func__src( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func__src(*static_cast<profile_GLSL__technique__pass__states__blend_func__src__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_func__src( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func__src(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func__src();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func__src();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func__src();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func__src( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func__dest( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func__dest(*static_cast<profile_GLSL__technique__pass__states__blend_func__dest__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_func__dest( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func__dest(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func__dest();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func__dest();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func__dest();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func__dest( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func_separate( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func_separate();}
bool _data__profile_GLSL__technique__pass__states__blend_func_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func_separate(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func_separate();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func_separate();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func_separate( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb(*static_cast<profile_GLSL__technique__pass__states__blend_func_separate__src_rgb__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb(*static_cast<profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha(*static_cast<profile_GLSL__technique__pass__states__blend_func_separate__src_alpha__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha(*static_cast<profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha(){return mImpl->end__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_equation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_equation(*static_cast<profile_GLSL__technique__pass__states__blend_equation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_equation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_equation(){return mImpl->end__profile_GLSL__technique__pass__states__blend_equation();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_equation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_equation();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_equation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_equation_separate( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_equation_separate();}
bool _data__profile_GLSL__technique__pass__states__blend_equation_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_equation_separate(){return mImpl->end__profile_GLSL__technique__pass__states__blend_equation_separate();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_equation_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_equation_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_equation_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_equation_separate();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_equation_separate( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_equation_separate__rgb( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_equation_separate__rgb(*static_cast<profile_GLSL__technique__pass__states__blend_equation_separate__rgb__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_equation_separate__rgb( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_equation_separate__rgb(){return mImpl->end__profile_GLSL__technique__pass__states__blend_equation_separate__rgb();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_equation_separate__rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_equation_separate__rgb();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_equation_separate__rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_equation_separate__rgb();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_equation_separate__rgb( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_equation_separate__alpha( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_equation_separate__alpha(*static_cast<profile_GLSL__technique__pass__states__blend_equation_separate__alpha__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_equation_separate__alpha( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_equation_separate__alpha(){return mImpl->end__profile_GLSL__technique__pass__states__blend_equation_separate__alpha();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_equation_separate__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_equation_separate__alpha();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_equation_separate__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_equation_separate__alpha();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_equation_separate__alpha( void* attributeData );

bool _begin__color_material( void* attributeData ){return mImpl->begin__color_material();}
bool _data__color_material( const ParserChar* text, size_t textLength );
bool _end__color_material(){return mImpl->end__color_material();}
bool _preBegin__color_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__color_material();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__color_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_material();
#endif
bool _freeAttributes__color_material( void* attributeData );

bool _begin__color_material__face( void* attributeData ){return mImpl->begin__color_material__face(*static_cast<color_material__face__AttributeData*>(attributeData));}
bool _data__color_material__face( const ParserChar* text, size_t textLength );
bool _end__color_material__face(){return mImpl->end__color_material__face();}
bool _preBegin__color_material__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__color_material__face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__color_material__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_material__face();
#endif
bool _freeAttributes__color_material__face( void* attributeData );

bool _begin__color_material__mode( void* attributeData ){return mImpl->begin__color_material__mode(*static_cast<color_material__mode__AttributeData*>(attributeData));}
bool _data__color_material__mode( const ParserChar* text, size_t textLength );
bool _end__color_material__mode(){return mImpl->end__color_material__mode();}
bool _preBegin__color_material__mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__color_material__mode();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__color_material__mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_material__mode();
#endif
bool _freeAttributes__color_material__mode( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__cull_face( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__cull_face(*static_cast<profile_GLSL__technique__pass__states__cull_face__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__cull_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__cull_face(){return mImpl->end__profile_GLSL__technique__pass__states__cull_face();}
bool _preBegin__profile_GLSL__technique__pass__states__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__cull_face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__cull_face();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__cull_face( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__depth_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__depth_func(*static_cast<profile_GLSL__technique__pass__states__depth_func__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__depth_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__depth_func(){return mImpl->end__profile_GLSL__technique__pass__states__depth_func();}
bool _preBegin__profile_GLSL__technique__pass__states__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__depth_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__depth_func();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__depth_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__fog_mode( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__fog_mode(*static_cast<profile_GLSL__technique__pass__states__fog_mode__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__fog_mode( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__fog_mode(){return mImpl->end__profile_GLSL__technique__pass__states__fog_mode();}
bool _preBegin__profile_GLSL__technique__pass__states__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__fog_mode();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__fog_mode();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__fog_mode( void* attributeData );

bool _begin__fog_coord_src( void* attributeData ){return mImpl->begin__fog_coord_src(*static_cast<fog_coord_src__AttributeData*>(attributeData));}
bool _data__fog_coord_src( const ParserChar* text, size_t textLength );
bool _end__fog_coord_src(){return mImpl->end__fog_coord_src();}
bool _preBegin__fog_coord_src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fog_coord_src();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fog_coord_src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fog_coord_src();
#endif
bool _freeAttributes__fog_coord_src( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__front_face( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__front_face(*static_cast<profile_GLSL__technique__pass__states__front_face__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__front_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__front_face(){return mImpl->end__profile_GLSL__technique__pass__states__front_face();}
bool _preBegin__profile_GLSL__technique__pass__states__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__front_face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__front_face();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__front_face( void* attributeData );

bool _begin__light_model_color_control( void* attributeData ){return mImpl->begin__light_model_color_control(*static_cast<light_model_color_control__AttributeData*>(attributeData));}
bool _data__light_model_color_control( const ParserChar* text, size_t textLength );
bool _end__light_model_color_control(){return mImpl->end__light_model_color_control();}
bool _preBegin__light_model_color_control( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__light_model_color_control();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__light_model_color_control( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_model_color_control();
#endif
bool _freeAttributes__light_model_color_control( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__logic_op( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__logic_op(*static_cast<profile_GLSL__technique__pass__states__logic_op__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__logic_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__logic_op(){return mImpl->end__profile_GLSL__technique__pass__states__logic_op();}
bool _preBegin__profile_GLSL__technique__pass__states__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__logic_op();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__logic_op();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__logic_op( void* attributeData );

bool _begin__polygon_mode( void* attributeData ){return mImpl->begin__polygon_mode();}
bool _data__polygon_mode( const ParserChar* text, size_t textLength );
bool _end__polygon_mode(){return mImpl->end__polygon_mode();}
bool _preBegin__polygon_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_mode();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_mode();
#endif
bool _freeAttributes__polygon_mode( void* attributeData );

bool _begin__polygon_mode__face( void* attributeData ){return mImpl->begin__polygon_mode__face(*static_cast<polygon_mode__face__AttributeData*>(attributeData));}
bool _data__polygon_mode__face( const ParserChar* text, size_t textLength );
bool _end__polygon_mode__face(){return mImpl->end__polygon_mode__face();}
bool _preBegin__polygon_mode__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_mode__face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_mode__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_mode__face();
#endif
bool _freeAttributes__polygon_mode__face( void* attributeData );

bool _begin__polygon_mode__mode( void* attributeData ){return mImpl->begin__polygon_mode__mode(*static_cast<polygon_mode__mode__AttributeData*>(attributeData));}
bool _data__polygon_mode__mode( const ParserChar* text, size_t textLength );
bool _end__polygon_mode__mode(){return mImpl->end__polygon_mode__mode();}
bool _preBegin__polygon_mode__mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_mode__mode();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_mode__mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_mode__mode();
#endif
bool _freeAttributes__polygon_mode__mode( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__shade_model( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__shade_model(*static_cast<profile_GLSL__technique__pass__states__shade_model__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__shade_model( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__shade_model(){return mImpl->end__profile_GLSL__technique__pass__states__shade_model();}
bool _preBegin__profile_GLSL__technique__pass__states__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__shade_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__shade_model();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__shade_model( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func();}
bool _data__profile_GLSL__technique__pass__states__stencil_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func__func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func__func(*static_cast<profile_GLSL__technique__pass__states__stencil_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func__func(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func__func();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func__func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func__func();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func__func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func__ref( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func__ref(*static_cast<profile_GLSL__technique__pass__states__stencil_func__ref__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func__ref(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func__ref();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func__ref();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func__ref();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func__ref( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func__mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func__mask(*static_cast<profile_GLSL__technique__pass__states__stencil_func__mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func__mask(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func__mask();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func__mask();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func__mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op();}
bool _data__profile_GLSL__technique__pass__states__stencil_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op__fail( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op__fail(*static_cast<profile_GLSL__technique__pass__states__stencil_op__fail__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op__fail(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op__fail();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op__fail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op__fail();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op__fail( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op__zfail( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op__zfail(*static_cast<profile_GLSL__technique__pass__states__stencil_op__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op__zfail(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op__zfail();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op__zfail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op__zfail();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op__zfail( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op__zpass( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op__zpass(*static_cast<profile_GLSL__technique__pass__states__stencil_op__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op__zpass(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op__zpass();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op__zpass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op__zpass();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op__zpass( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func_separate( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func_separate();}
bool _data__profile_GLSL__technique__pass__states__stencil_func_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func_separate(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func_separate();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func_separate();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func_separate( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func_separate__front( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func_separate__front(*static_cast<profile_GLSL__technique__pass__states__stencil_func_separate__front__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func_separate__front( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func_separate__front(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func_separate__front();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func_separate__front( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func_separate__front();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func_separate__front( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func_separate__front();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func_separate__front( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func_separate__back( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func_separate__back(*static_cast<profile_GLSL__technique__pass__states__stencil_func_separate__back__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func_separate__back( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func_separate__back(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func_separate__back();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func_separate__back( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func_separate__back();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func_separate__back( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func_separate__back();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func_separate__back( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func_separate__ref( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func_separate__ref(*static_cast<profile_GLSL__technique__pass__states__stencil_func_separate__ref__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func_separate__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func_separate__ref(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func_separate__ref();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func_separate__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func_separate__ref();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func_separate__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func_separate__ref();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func_separate__ref( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_func_separate__mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_func_separate__mask(*static_cast<profile_GLSL__technique__pass__states__stencil_func_separate__mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_func_separate__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_func_separate__mask(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_func_separate__mask();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_func_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_func_separate__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_func_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_func_separate__mask();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_func_separate__mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op_separate( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op_separate();}
bool _data__profile_GLSL__technique__pass__states__stencil_op_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op_separate(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op_separate();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op_separate();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op_separate( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op_separate__face( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op_separate__face(*static_cast<profile_GLSL__technique__pass__states__stencil_op_separate__face__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op_separate__face( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op_separate__face(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op_separate__face();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op_separate__face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op_separate__face();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op_separate__face( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op_separate__fail( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op_separate__fail(*static_cast<profile_GLSL__technique__pass__states__stencil_op_separate__fail__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op_separate__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op_separate__fail(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op_separate__fail();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op_separate__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op_separate__fail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op_separate__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op_separate__fail();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op_separate__fail( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op_separate__zfail( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op_separate__zfail(*static_cast<profile_GLSL__technique__pass__states__stencil_op_separate__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op_separate__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op_separate__zfail(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op_separate__zfail();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op_separate__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op_separate__zfail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op_separate__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op_separate__zfail();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op_separate__zfail( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_op_separate__zpass( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_op_separate__zpass(*static_cast<profile_GLSL__technique__pass__states__stencil_op_separate__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_op_separate__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_op_separate__zpass(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_op_separate__zpass();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_op_separate__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_op_separate__zpass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_op_separate__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_op_separate__zpass();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_op_separate__zpass( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_mask_separate( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_mask_separate();}
bool _data__profile_GLSL__technique__pass__states__stencil_mask_separate( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_mask_separate(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_mask_separate();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_mask_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_mask_separate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_mask_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_mask_separate();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_mask_separate( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_mask_separate__face( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_mask_separate__face(*static_cast<profile_GLSL__technique__pass__states__stencil_mask_separate__face__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_mask_separate__face( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_mask_separate__face(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_mask_separate__face();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_mask_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_mask_separate__face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_mask_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_mask_separate__face();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_mask_separate__face( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_mask_separate__mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_mask_separate__mask(*static_cast<profile_GLSL__technique__pass__states__stencil_mask_separate__mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_mask_separate__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_mask_separate__mask(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_mask_separate__mask();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_mask_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_mask_separate__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_mask_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_mask_separate__mask();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_mask_separate__mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_enable(*static_cast<profile_GLSL__technique__pass__states__light_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_enable(){return mImpl->end__profile_GLSL__technique__pass__states__light_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_ambient( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_ambient(*static_cast<profile_GLSL__technique__pass__states__light_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_ambient(){return mImpl->end__profile_GLSL__technique__pass__states__light_ambient();}
bool _preBegin__profile_GLSL__technique__pass__states__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_ambient();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_ambient( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_diffuse( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_diffuse(*static_cast<profile_GLSL__technique__pass__states__light_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_diffuse(){return mImpl->end__profile_GLSL__technique__pass__states__light_diffuse();}
bool _preBegin__profile_GLSL__technique__pass__states__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_diffuse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_diffuse();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_diffuse( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_specular( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_specular(*static_cast<profile_GLSL__technique__pass__states__light_specular__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_specular(){return mImpl->end__profile_GLSL__technique__pass__states__light_specular();}
bool _preBegin__profile_GLSL__technique__pass__states__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_specular();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_specular();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_specular( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_position( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_position(*static_cast<profile_GLSL__technique__pass__states__light_position__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_position( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_position(){return mImpl->end__profile_GLSL__technique__pass__states__light_position();}
bool _preBegin__profile_GLSL__technique__pass__states__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_position();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_position();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_position( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_constant_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_constant_attenuation(*static_cast<profile_GLSL__technique__pass__states__light_constant_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_constant_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_constant_attenuation(){return mImpl->end__profile_GLSL__technique__pass__states__light_constant_attenuation();}
bool _preBegin__profile_GLSL__technique__pass__states__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_constant_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_constant_attenuation();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_constant_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_linear_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_linear_attenuation(*static_cast<profile_GLSL__technique__pass__states__light_linear_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_linear_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_linear_attenuation(){return mImpl->end__profile_GLSL__technique__pass__states__light_linear_attenuation();}
bool _preBegin__profile_GLSL__technique__pass__states__light_linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_linear_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_linear_attenuation();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_linear_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_quadratic_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_quadratic_attenuation(*static_cast<profile_GLSL__technique__pass__states__light_quadratic_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_quadratic_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_quadratic_attenuation(){return mImpl->end__profile_GLSL__technique__pass__states__light_quadratic_attenuation();}
bool _preBegin__profile_GLSL__technique__pass__states__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_quadratic_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_quadratic_attenuation();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_quadratic_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_spot_cutoff( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_spot_cutoff(*static_cast<profile_GLSL__technique__pass__states__light_spot_cutoff__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_spot_cutoff( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_spot_cutoff(){return mImpl->end__profile_GLSL__technique__pass__states__light_spot_cutoff();}
bool _preBegin__profile_GLSL__technique__pass__states__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_spot_cutoff();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_spot_cutoff();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_spot_cutoff( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_spot_direction( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_spot_direction(*static_cast<profile_GLSL__technique__pass__states__light_spot_direction__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_spot_direction( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_spot_direction(){return mImpl->end__profile_GLSL__technique__pass__states__light_spot_direction();}
bool _preBegin__profile_GLSL__technique__pass__states__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_spot_direction();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_spot_direction();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_spot_direction( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_spot_exponent( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_spot_exponent(*static_cast<profile_GLSL__technique__pass__states__light_spot_exponent__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_spot_exponent( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_spot_exponent(){return mImpl->end__profile_GLSL__technique__pass__states__light_spot_exponent();}
bool _preBegin__profile_GLSL__technique__pass__states__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_spot_exponent();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_spot_exponent();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_spot_exponent( void* attributeData );

bool _begin__texture1D( void* attributeData ){return mImpl->begin__texture1D(*static_cast<texture1D__AttributeData*>(attributeData));}
bool _data__texture1D( const ParserChar* text, size_t textLength );
bool _end__texture1D(){return mImpl->end__texture1D();}
bool _preBegin__texture1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture1D();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture1D();
#endif
bool _freeAttributes__texture1D( void* attributeData );

bool _begin__value____fx_sampler1D_type( void* attributeData ){return mImpl->begin__value____fx_sampler1D_type();}
bool _data__value____fx_sampler1D_type( const ParserChar* text, size_t textLength );
bool _end__value____fx_sampler1D_type(){return mImpl->end__value____fx_sampler1D_type();}
bool _preBegin__value____fx_sampler1D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____fx_sampler1D_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____fx_sampler1D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____fx_sampler1D_type();
#endif
bool _freeAttributes__value____fx_sampler1D_type( void* attributeData );

bool _begin__param____NCName( void* attributeData ){return mImpl->begin__param____NCName();}
bool _data__param____NCName( const ParserChar* text, size_t textLength );
bool _end__param____NCName(){return mImpl->end__param____NCName();}
bool _preBegin__param____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__param____NCName();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__param____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__param____NCName();
#endif
bool _freeAttributes__param____NCName( void* attributeData );

bool _begin__texture2D( void* attributeData ){return mImpl->begin__texture2D(*static_cast<texture2D__AttributeData*>(attributeData));}
bool _data__texture2D( const ParserChar* text, size_t textLength );
bool _end__texture2D(){return mImpl->end__texture2D();}
bool _preBegin__texture2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture2D();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture2D();
#endif
bool _freeAttributes__texture2D( void* attributeData );

bool _begin__value____fx_sampler2D_type( void* attributeData ){return mImpl->begin__value____fx_sampler2D_type();}
bool _data__value____fx_sampler2D_type( const ParserChar* text, size_t textLength );
bool _end__value____fx_sampler2D_type(){return mImpl->end__value____fx_sampler2D_type();}
bool _preBegin__value____fx_sampler2D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____fx_sampler2D_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____fx_sampler2D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____fx_sampler2D_type();
#endif
bool _freeAttributes__value____fx_sampler2D_type( void* attributeData );

bool _begin__texture3D( void* attributeData ){return mImpl->begin__texture3D(*static_cast<texture3D__AttributeData*>(attributeData));}
bool _data__texture3D( const ParserChar* text, size_t textLength );
bool _end__texture3D(){return mImpl->end__texture3D();}
bool _preBegin__texture3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture3D();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture3D();
#endif
bool _freeAttributes__texture3D( void* attributeData );

bool _begin__value____fx_sampler3D_type( void* attributeData ){return mImpl->begin__value____fx_sampler3D_type();}
bool _data__value____fx_sampler3D_type( const ParserChar* text, size_t textLength );
bool _end__value____fx_sampler3D_type(){return mImpl->end__value____fx_sampler3D_type();}
bool _preBegin__value____fx_sampler3D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____fx_sampler3D_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____fx_sampler3D_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____fx_sampler3D_type();
#endif
bool _freeAttributes__value____fx_sampler3D_type( void* attributeData );

bool _begin__textureCUBE( void* attributeData ){return mImpl->begin__textureCUBE(*static_cast<textureCUBE__AttributeData*>(attributeData));}
bool _data__textureCUBE( const ParserChar* text, size_t textLength );
bool _end__textureCUBE(){return mImpl->end__textureCUBE();}
bool _preBegin__textureCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__textureCUBE();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__textureCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureCUBE();
#endif
bool _freeAttributes__textureCUBE( void* attributeData );

bool _begin__value____fx_samplerCUBE_type( void* attributeData ){return mImpl->begin__value____fx_samplerCUBE_type();}
bool _data__value____fx_samplerCUBE_type( const ParserChar* text, size_t textLength );
bool _end__value____fx_samplerCUBE_type(){return mImpl->end__value____fx_samplerCUBE_type();}
bool _preBegin__value____fx_samplerCUBE_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____fx_samplerCUBE_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____fx_samplerCUBE_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____fx_samplerCUBE_type();
#endif
bool _freeAttributes__value____fx_samplerCUBE_type( void* attributeData );

bool _begin__textureRECT( void* attributeData ){return mImpl->begin__textureRECT(*static_cast<textureRECT__AttributeData*>(attributeData));}
bool _data__textureRECT( const ParserChar* text, size_t textLength );
bool _end__textureRECT(){return mImpl->end__textureRECT();}
bool _preBegin__textureRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__textureRECT();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__textureRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureRECT();
#endif
bool _freeAttributes__textureRECT( void* attributeData );

bool _begin__value____fx_samplerRECT_type( void* attributeData ){return mImpl->begin__value____fx_samplerRECT_type();}
bool _data__value____fx_samplerRECT_type( const ParserChar* text, size_t textLength );
bool _end__value____fx_samplerRECT_type(){return mImpl->end__value____fx_samplerRECT_type();}
bool _preBegin__value____fx_samplerRECT_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____fx_samplerRECT_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____fx_samplerRECT_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____fx_samplerRECT_type();
#endif
bool _freeAttributes__value____fx_samplerRECT_type( void* attributeData );

bool _begin__textureDEPTH( void* attributeData ){return mImpl->begin__textureDEPTH(*static_cast<textureDEPTH__AttributeData*>(attributeData));}
bool _data__textureDEPTH( const ParserChar* text, size_t textLength );
bool _end__textureDEPTH(){return mImpl->end__textureDEPTH();}
bool _preBegin__textureDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__textureDEPTH();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__textureDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureDEPTH();
#endif
bool _freeAttributes__textureDEPTH( void* attributeData );

bool _begin__value____fx_samplerDEPTH_type( void* attributeData ){return mImpl->begin__value____fx_samplerDEPTH_type();}
bool _data__value____fx_samplerDEPTH_type( const ParserChar* text, size_t textLength );
bool _end__value____fx_samplerDEPTH_type(){return mImpl->end__value____fx_samplerDEPTH_type();}
bool _preBegin__value____fx_samplerDEPTH_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____fx_samplerDEPTH_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____fx_samplerDEPTH_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____fx_samplerDEPTH_type();
#endif
bool _freeAttributes__value____fx_samplerDEPTH_type( void* attributeData );

bool _begin__texture1D_enable( void* attributeData ){return mImpl->begin__texture1D_enable(*static_cast<texture1D_enable__AttributeData*>(attributeData));}
bool _data__texture1D_enable( const ParserChar* text, size_t textLength );
bool _end__texture1D_enable(){return mImpl->end__texture1D_enable();}
bool _preBegin__texture1D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture1D_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture1D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture1D_enable();
#endif
bool _freeAttributes__texture1D_enable( void* attributeData );

bool _begin__texture2D_enable( void* attributeData ){return mImpl->begin__texture2D_enable(*static_cast<texture2D_enable__AttributeData*>(attributeData));}
bool _data__texture2D_enable( const ParserChar* text, size_t textLength );
bool _end__texture2D_enable(){return mImpl->end__texture2D_enable();}
bool _preBegin__texture2D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture2D_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture2D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture2D_enable();
#endif
bool _freeAttributes__texture2D_enable( void* attributeData );

bool _begin__texture3D_enable( void* attributeData ){return mImpl->begin__texture3D_enable(*static_cast<texture3D_enable__AttributeData*>(attributeData));}
bool _data__texture3D_enable( const ParserChar* text, size_t textLength );
bool _end__texture3D_enable(){return mImpl->end__texture3D_enable();}
bool _preBegin__texture3D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture3D_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture3D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture3D_enable();
#endif
bool _freeAttributes__texture3D_enable( void* attributeData );

bool _begin__textureCUBE_enable( void* attributeData ){return mImpl->begin__textureCUBE_enable(*static_cast<textureCUBE_enable__AttributeData*>(attributeData));}
bool _data__textureCUBE_enable( const ParserChar* text, size_t textLength );
bool _end__textureCUBE_enable(){return mImpl->end__textureCUBE_enable();}
bool _preBegin__textureCUBE_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__textureCUBE_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__textureCUBE_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureCUBE_enable();
#endif
bool _freeAttributes__textureCUBE_enable( void* attributeData );

bool _begin__textureRECT_enable( void* attributeData ){return mImpl->begin__textureRECT_enable(*static_cast<textureRECT_enable__AttributeData*>(attributeData));}
bool _data__textureRECT_enable( const ParserChar* text, size_t textLength );
bool _end__textureRECT_enable(){return mImpl->end__textureRECT_enable();}
bool _preBegin__textureRECT_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__textureRECT_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__textureRECT_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureRECT_enable();
#endif
bool _freeAttributes__textureRECT_enable( void* attributeData );

bool _begin__textureDEPTH_enable( void* attributeData ){return mImpl->begin__textureDEPTH_enable(*static_cast<textureDEPTH_enable__AttributeData*>(attributeData));}
bool _data__textureDEPTH_enable( const ParserChar* text, size_t textLength );
bool _end__textureDEPTH_enable(){return mImpl->end__textureDEPTH_enable();}
bool _preBegin__textureDEPTH_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__textureDEPTH_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__textureDEPTH_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureDEPTH_enable();
#endif
bool _freeAttributes__textureDEPTH_enable( void* attributeData );

bool _begin__texture_env_color( void* attributeData ){return mImpl->begin__texture_env_color(*static_cast<texture_env_color__AttributeData*>(attributeData));}
bool _data__texture_env_color( const ParserChar* text, size_t textLength );
bool _end__texture_env_color(){return mImpl->end__texture_env_color();}
bool _preBegin__texture_env_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture_env_color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture_env_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_env_color();
#endif
bool _freeAttributes__texture_env_color( void* attributeData );

bool _begin__texture_env_mode( void* attributeData ){return mImpl->begin__texture_env_mode(*static_cast<texture_env_mode__AttributeData*>(attributeData));}
bool _data__texture_env_mode( const ParserChar* text, size_t textLength );
bool _end__texture_env_mode(){return mImpl->end__texture_env_mode();}
bool _preBegin__texture_env_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture_env_mode();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture_env_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_env_mode();
#endif
bool _freeAttributes__texture_env_mode( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__clip_plane( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__clip_plane(*static_cast<profile_GLSL__technique__pass__states__clip_plane__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__clip_plane( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__clip_plane(){return mImpl->end__profile_GLSL__technique__pass__states__clip_plane();}
bool _preBegin__profile_GLSL__technique__pass__states__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__clip_plane();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__clip_plane();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__clip_plane( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__clip_plane_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__clip_plane_enable(*static_cast<profile_GLSL__technique__pass__states__clip_plane_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__clip_plane_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__clip_plane_enable(){return mImpl->end__profile_GLSL__technique__pass__states__clip_plane_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__clip_plane_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__clip_plane_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__clip_plane_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_color( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_color(*static_cast<profile_GLSL__technique__pass__states__blend_color__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_color(){return mImpl->end__profile_GLSL__technique__pass__states__blend_color();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_color();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_color( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__color_mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__color_mask(*static_cast<profile_GLSL__technique__pass__states__color_mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__color_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__color_mask(){return mImpl->end__profile_GLSL__technique__pass__states__color_mask();}
bool _preBegin__profile_GLSL__technique__pass__states__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__color_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__color_mask();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__color_mask( void* attributeData );

bool _begin__depth_bounds( void* attributeData ){return mImpl->begin__depth_bounds(*static_cast<depth_bounds__AttributeData*>(attributeData));}
bool _data__depth_bounds( const ParserChar* text, size_t textLength );
bool _end__depth_bounds(){return mImpl->end__depth_bounds();}
bool _preBegin__depth_bounds( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__depth_bounds();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__depth_bounds( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_bounds();
#endif
bool _freeAttributes__depth_bounds( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__depth_mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__depth_mask(*static_cast<profile_GLSL__technique__pass__states__depth_mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__depth_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__depth_mask(){return mImpl->end__profile_GLSL__technique__pass__states__depth_mask();}
bool _preBegin__profile_GLSL__technique__pass__states__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__depth_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__depth_mask();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__depth_mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__depth_range( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__depth_range(*static_cast<profile_GLSL__technique__pass__states__depth_range__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__depth_range( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__depth_range(){return mImpl->end__profile_GLSL__technique__pass__states__depth_range();}
bool _preBegin__profile_GLSL__technique__pass__states__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__depth_range();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__depth_range();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__depth_range( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__fog_density( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__fog_density(*static_cast<profile_GLSL__technique__pass__states__fog_density__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__fog_density( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__fog_density(){return mImpl->end__profile_GLSL__technique__pass__states__fog_density();}
bool _preBegin__profile_GLSL__technique__pass__states__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__fog_density();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__fog_density();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__fog_density( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__fog_start( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__fog_start(*static_cast<profile_GLSL__technique__pass__states__fog_start__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__fog_start( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__fog_start(){return mImpl->end__profile_GLSL__technique__pass__states__fog_start();}
bool _preBegin__profile_GLSL__technique__pass__states__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__fog_start();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__fog_start();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__fog_start( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__fog_end( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__fog_end(*static_cast<profile_GLSL__technique__pass__states__fog_end__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__fog_end( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__fog_end(){return mImpl->end__profile_GLSL__technique__pass__states__fog_end();}
bool _preBegin__profile_GLSL__technique__pass__states__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__fog_end();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__fog_end();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__fog_end( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__fog_color( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__fog_color(*static_cast<profile_GLSL__technique__pass__states__fog_color__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__fog_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__fog_color(){return mImpl->end__profile_GLSL__technique__pass__states__fog_color();}
bool _preBegin__profile_GLSL__technique__pass__states__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__fog_color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__fog_color();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__fog_color( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_model_ambient( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_model_ambient(*static_cast<profile_GLSL__technique__pass__states__light_model_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_model_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_model_ambient(){return mImpl->end__profile_GLSL__technique__pass__states__light_model_ambient();}
bool _preBegin__profile_GLSL__technique__pass__states__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_model_ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_model_ambient();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_model_ambient( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__lighting_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__lighting_enable(*static_cast<profile_GLSL__technique__pass__states__lighting_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__lighting_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__lighting_enable(){return mImpl->end__profile_GLSL__technique__pass__states__lighting_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__lighting_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__lighting_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__lighting_enable( void* attributeData );

bool _begin__line_stipple( void* attributeData ){return mImpl->begin__line_stipple(*static_cast<line_stipple__AttributeData*>(attributeData));}
bool _data__line_stipple( const ParserChar* text, size_t textLength );
bool _end__line_stipple(){return mImpl->end__line_stipple();}
bool _preBegin__line_stipple( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__line_stipple();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__line_stipple( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__line_stipple();
#endif
bool _freeAttributes__line_stipple( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__line_width( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__line_width(*static_cast<profile_GLSL__technique__pass__states__line_width__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__line_width( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__line_width(){return mImpl->end__profile_GLSL__technique__pass__states__line_width();}
bool _preBegin__profile_GLSL__technique__pass__states__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__line_width();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__line_width();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__line_width( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__material_ambient( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__material_ambient(*static_cast<profile_GLSL__technique__pass__states__material_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__material_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__material_ambient(){return mImpl->end__profile_GLSL__technique__pass__states__material_ambient();}
bool _preBegin__profile_GLSL__technique__pass__states__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__material_ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__material_ambient();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__material_ambient( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__material_diffuse( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__material_diffuse(*static_cast<profile_GLSL__technique__pass__states__material_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__material_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__material_diffuse(){return mImpl->end__profile_GLSL__technique__pass__states__material_diffuse();}
bool _preBegin__profile_GLSL__technique__pass__states__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__material_diffuse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__material_diffuse();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__material_diffuse( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__material_emission( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__material_emission(*static_cast<profile_GLSL__technique__pass__states__material_emission__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__material_emission( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__material_emission(){return mImpl->end__profile_GLSL__technique__pass__states__material_emission();}
bool _preBegin__profile_GLSL__technique__pass__states__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__material_emission();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__material_emission();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__material_emission( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__material_shininess( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__material_shininess(*static_cast<profile_GLSL__technique__pass__states__material_shininess__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__material_shininess( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__material_shininess(){return mImpl->end__profile_GLSL__technique__pass__states__material_shininess();}
bool _preBegin__profile_GLSL__technique__pass__states__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__material_shininess();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__material_shininess();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__material_shininess( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__material_specular( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__material_specular(*static_cast<profile_GLSL__technique__pass__states__material_specular__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__material_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__material_specular(){return mImpl->end__profile_GLSL__technique__pass__states__material_specular();}
bool _preBegin__profile_GLSL__technique__pass__states__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__material_specular();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__material_specular();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__material_specular( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__model_view_matrix( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__model_view_matrix(*static_cast<profile_GLSL__technique__pass__states__model_view_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__model_view_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__model_view_matrix(){return mImpl->end__profile_GLSL__technique__pass__states__model_view_matrix();}
bool _preBegin__profile_GLSL__technique__pass__states__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__model_view_matrix();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__model_view_matrix();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__model_view_matrix( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__point_distance_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__point_distance_attenuation(*static_cast<profile_GLSL__technique__pass__states__point_distance_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__point_distance_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__point_distance_attenuation(){return mImpl->end__profile_GLSL__technique__pass__states__point_distance_attenuation();}
bool _preBegin__profile_GLSL__technique__pass__states__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__point_distance_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__point_distance_attenuation();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__point_distance_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__point_fade_threshold_size( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__point_fade_threshold_size(*static_cast<profile_GLSL__technique__pass__states__point_fade_threshold_size__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__point_fade_threshold_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__point_fade_threshold_size(){return mImpl->end__profile_GLSL__technique__pass__states__point_fade_threshold_size();}
bool _preBegin__profile_GLSL__technique__pass__states__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__point_fade_threshold_size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__point_fade_threshold_size();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__point_fade_threshold_size( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__point_size( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__point_size(*static_cast<profile_GLSL__technique__pass__states__point_size__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__point_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__point_size(){return mImpl->end__profile_GLSL__technique__pass__states__point_size();}
bool _preBegin__profile_GLSL__technique__pass__states__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__point_size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__point_size();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__point_size( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__point_size_min( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__point_size_min(*static_cast<profile_GLSL__technique__pass__states__point_size_min__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__point_size_min( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__point_size_min(){return mImpl->end__profile_GLSL__technique__pass__states__point_size_min();}
bool _preBegin__profile_GLSL__technique__pass__states__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__point_size_min();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__point_size_min();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__point_size_min( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__point_size_max( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__point_size_max(*static_cast<profile_GLSL__technique__pass__states__point_size_max__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__point_size_max( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__point_size_max(){return mImpl->end__profile_GLSL__technique__pass__states__point_size_max();}
bool _preBegin__profile_GLSL__technique__pass__states__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__point_size_max();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__point_size_max();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__point_size_max( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__polygon_offset( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__polygon_offset(*static_cast<profile_GLSL__technique__pass__states__polygon_offset__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__polygon_offset( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__polygon_offset(){return mImpl->end__profile_GLSL__technique__pass__states__polygon_offset();}
bool _preBegin__profile_GLSL__technique__pass__states__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__polygon_offset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__polygon_offset();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__polygon_offset( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__projection_matrix( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__projection_matrix(*static_cast<profile_GLSL__technique__pass__states__projection_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__projection_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__projection_matrix(){return mImpl->end__profile_GLSL__technique__pass__states__projection_matrix();}
bool _preBegin__profile_GLSL__technique__pass__states__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__projection_matrix();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__projection_matrix();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__projection_matrix( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__scissor( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__scissor(*static_cast<profile_GLSL__technique__pass__states__scissor__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__scissor( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__scissor(){return mImpl->end__profile_GLSL__technique__pass__states__scissor();}
bool _preBegin__profile_GLSL__technique__pass__states__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__scissor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__scissor();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__scissor( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_mask(*static_cast<profile_GLSL__technique__pass__states__stencil_mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_mask(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_mask();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_mask();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__alpha_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__alpha_test_enable(*static_cast<profile_GLSL__technique__pass__states__alpha_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__alpha_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__alpha_test_enable(){return mImpl->end__profile_GLSL__technique__pass__states__alpha_test_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__alpha_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__alpha_test_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__alpha_test_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__blend_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__blend_enable(*static_cast<profile_GLSL__technique__pass__states__blend_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__blend_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__blend_enable(){return mImpl->end__profile_GLSL__technique__pass__states__blend_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__blend_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__blend_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__blend_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__color_logic_op_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__color_logic_op_enable(*static_cast<profile_GLSL__technique__pass__states__color_logic_op_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__color_logic_op_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__color_logic_op_enable(){return mImpl->end__profile_GLSL__technique__pass__states__color_logic_op_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__color_logic_op_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__color_logic_op_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__color_logic_op_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__color_material_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__color_material_enable(*static_cast<profile_GLSL__technique__pass__states__color_material_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__color_material_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__color_material_enable(){return mImpl->end__profile_GLSL__technique__pass__states__color_material_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__color_material_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__color_material_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__color_material_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__cull_face_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__cull_face_enable(*static_cast<profile_GLSL__technique__pass__states__cull_face_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__cull_face_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__cull_face_enable(){return mImpl->end__profile_GLSL__technique__pass__states__cull_face_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__cull_face_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__cull_face_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__cull_face_enable( void* attributeData );

bool _begin__depth_bounds_enable( void* attributeData ){return mImpl->begin__depth_bounds_enable(*static_cast<depth_bounds_enable__AttributeData*>(attributeData));}
bool _data__depth_bounds_enable( const ParserChar* text, size_t textLength );
bool _end__depth_bounds_enable(){return mImpl->end__depth_bounds_enable();}
bool _preBegin__depth_bounds_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__depth_bounds_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__depth_bounds_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_bounds_enable();
#endif
bool _freeAttributes__depth_bounds_enable( void* attributeData );

bool _begin__depth_clamp_enable( void* attributeData ){return mImpl->begin__depth_clamp_enable(*static_cast<depth_clamp_enable__AttributeData*>(attributeData));}
bool _data__depth_clamp_enable( const ParserChar* text, size_t textLength );
bool _end__depth_clamp_enable(){return mImpl->end__depth_clamp_enable();}
bool _preBegin__depth_clamp_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__depth_clamp_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__depth_clamp_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_clamp_enable();
#endif
bool _freeAttributes__depth_clamp_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__depth_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__depth_test_enable(*static_cast<profile_GLSL__technique__pass__states__depth_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__depth_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__depth_test_enable(){return mImpl->end__profile_GLSL__technique__pass__states__depth_test_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__depth_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__depth_test_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__depth_test_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__dither_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__dither_enable(*static_cast<profile_GLSL__technique__pass__states__dither_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__dither_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__dither_enable(){return mImpl->end__profile_GLSL__technique__pass__states__dither_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__dither_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__dither_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__dither_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__fog_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__fog_enable(*static_cast<profile_GLSL__technique__pass__states__fog_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__fog_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__fog_enable(){return mImpl->end__profile_GLSL__technique__pass__states__fog_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__fog_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__fog_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__fog_enable( void* attributeData );

bool _begin__light_model_local_viewer_enable( void* attributeData ){return mImpl->begin__light_model_local_viewer_enable(*static_cast<light_model_local_viewer_enable__AttributeData*>(attributeData));}
bool _data__light_model_local_viewer_enable( const ParserChar* text, size_t textLength );
bool _end__light_model_local_viewer_enable(){return mImpl->end__light_model_local_viewer_enable();}
bool _preBegin__light_model_local_viewer_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__light_model_local_viewer_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__light_model_local_viewer_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_model_local_viewer_enable();
#endif
bool _freeAttributes__light_model_local_viewer_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__light_model_two_side_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__light_model_two_side_enable(*static_cast<profile_GLSL__technique__pass__states__light_model_two_side_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__light_model_two_side_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__light_model_two_side_enable(){return mImpl->end__profile_GLSL__technique__pass__states__light_model_two_side_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__light_model_two_side_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__light_model_two_side_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__light_model_two_side_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__line_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__line_smooth_enable(*static_cast<profile_GLSL__technique__pass__states__line_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__line_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__line_smooth_enable(){return mImpl->end__profile_GLSL__technique__pass__states__line_smooth_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__line_smooth_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__line_smooth_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__line_smooth_enable( void* attributeData );

bool _begin__line_stipple_enable( void* attributeData ){return mImpl->begin__line_stipple_enable(*static_cast<line_stipple_enable__AttributeData*>(attributeData));}
bool _data__line_stipple_enable( const ParserChar* text, size_t textLength );
bool _end__line_stipple_enable(){return mImpl->end__line_stipple_enable();}
bool _preBegin__line_stipple_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__line_stipple_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__line_stipple_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__line_stipple_enable();
#endif
bool _freeAttributes__line_stipple_enable( void* attributeData );

bool _begin__logic_op_enable( void* attributeData ){return mImpl->begin__logic_op_enable(*static_cast<logic_op_enable__AttributeData*>(attributeData));}
bool _data__logic_op_enable( const ParserChar* text, size_t textLength );
bool _end__logic_op_enable(){return mImpl->end__logic_op_enable();}
bool _preBegin__logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__logic_op_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__logic_op_enable();
#endif
bool _freeAttributes__logic_op_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__multisample_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__multisample_enable(*static_cast<profile_GLSL__technique__pass__states__multisample_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__multisample_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__multisample_enable(){return mImpl->end__profile_GLSL__technique__pass__states__multisample_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__multisample_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__multisample_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__multisample_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__normalize_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__normalize_enable(*static_cast<profile_GLSL__technique__pass__states__normalize_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__normalize_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__normalize_enable(){return mImpl->end__profile_GLSL__technique__pass__states__normalize_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__normalize_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__normalize_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__normalize_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__point_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__point_smooth_enable(*static_cast<profile_GLSL__technique__pass__states__point_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__point_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__point_smooth_enable(){return mImpl->end__profile_GLSL__technique__pass__states__point_smooth_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__point_smooth_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__point_smooth_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__point_smooth_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__polygon_offset_fill_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__polygon_offset_fill_enable(*static_cast<profile_GLSL__technique__pass__states__polygon_offset_fill_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__polygon_offset_fill_enable(){return mImpl->end__profile_GLSL__technique__pass__states__polygon_offset_fill_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__polygon_offset_fill_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__polygon_offset_fill_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__polygon_offset_fill_enable( void* attributeData );

bool _begin__polygon_offset_line_enable( void* attributeData ){return mImpl->begin__polygon_offset_line_enable(*static_cast<polygon_offset_line_enable__AttributeData*>(attributeData));}
bool _data__polygon_offset_line_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_offset_line_enable(){return mImpl->end__polygon_offset_line_enable();}
bool _preBegin__polygon_offset_line_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_offset_line_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_offset_line_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_offset_line_enable();
#endif
bool _freeAttributes__polygon_offset_line_enable( void* attributeData );

bool _begin__polygon_offset_point_enable( void* attributeData ){return mImpl->begin__polygon_offset_point_enable(*static_cast<polygon_offset_point_enable__AttributeData*>(attributeData));}
bool _data__polygon_offset_point_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_offset_point_enable(){return mImpl->end__polygon_offset_point_enable();}
bool _preBegin__polygon_offset_point_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_offset_point_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_offset_point_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_offset_point_enable();
#endif
bool _freeAttributes__polygon_offset_point_enable( void* attributeData );

bool _begin__polygon_smooth_enable( void* attributeData ){return mImpl->begin__polygon_smooth_enable(*static_cast<polygon_smooth_enable__AttributeData*>(attributeData));}
bool _data__polygon_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_smooth_enable(){return mImpl->end__polygon_smooth_enable();}
bool _preBegin__polygon_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_smooth_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_smooth_enable();
#endif
bool _freeAttributes__polygon_smooth_enable( void* attributeData );

bool _begin__polygon_stipple_enable( void* attributeData ){return mImpl->begin__polygon_stipple_enable(*static_cast<polygon_stipple_enable__AttributeData*>(attributeData));}
bool _data__polygon_stipple_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_stipple_enable(){return mImpl->end__polygon_stipple_enable();}
bool _preBegin__polygon_stipple_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__polygon_stipple_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__polygon_stipple_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_stipple_enable();
#endif
bool _freeAttributes__polygon_stipple_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__rescale_normal_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__rescale_normal_enable(*static_cast<profile_GLSL__technique__pass__states__rescale_normal_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__rescale_normal_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__rescale_normal_enable(){return mImpl->end__profile_GLSL__technique__pass__states__rescale_normal_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__rescale_normal_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__rescale_normal_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__rescale_normal_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable(*static_cast<profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable(){return mImpl->end__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable(*static_cast<profile_GLSL__technique__pass__states__sample_alpha_to_one_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable(){return mImpl->end__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__sample_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__sample_coverage_enable(*static_cast<profile_GLSL__technique__pass__states__sample_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__sample_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__sample_coverage_enable(){return mImpl->end__profile_GLSL__technique__pass__states__sample_coverage_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__sample_coverage_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__sample_coverage_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__sample_coverage_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__scissor_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__scissor_test_enable(*static_cast<profile_GLSL__technique__pass__states__scissor_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__scissor_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__scissor_test_enable(){return mImpl->end__profile_GLSL__technique__pass__states__scissor_test_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__scissor_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__scissor_test_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__scissor_test_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__states__stencil_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__states__stencil_test_enable(*static_cast<profile_GLSL__technique__pass__states__stencil_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__states__stencil_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__states__stencil_test_enable(){return mImpl->end__profile_GLSL__technique__pass__states__stencil_test_enable();}
bool _preBegin__profile_GLSL__technique__pass__states__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__states__stencil_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__states__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__states__stencil_test_enable();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__states__stencil_test_enable( void* attributeData );

bool _begin__program____glsl_program_type( void* attributeData ){return mImpl->begin__program____glsl_program_type();}
bool _data__program____glsl_program_type( const ParserChar* text, size_t textLength );
bool _end__program____glsl_program_type(){return mImpl->end__program____glsl_program_type();}
bool _preBegin__program____glsl_program_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__program____glsl_program_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__program____glsl_program_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__program____glsl_program_type();
#endif
bool _freeAttributes__program____glsl_program_type( void* attributeData );

bool _begin__shader____glsl_shader_type( void* attributeData ){return mImpl->begin__shader____glsl_shader_type(*static_cast<shader____glsl_shader_type__AttributeData*>(attributeData));}
bool _data__shader____glsl_shader_type( const ParserChar* text, size_t textLength );
bool _end__shader____glsl_shader_type(){return mImpl->end__shader____glsl_shader_type();}
bool _preBegin__shader____glsl_shader_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__shader____glsl_shader_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__shader____glsl_shader_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__shader____glsl_shader_type();
#endif
bool _freeAttributes__shader____glsl_shader_type( void* attributeData );

bool _begin__sources____fx_sources_type( void* attributeData ){return mImpl->begin__sources____fx_sources_type();}
bool _data__sources____fx_sources_type( const ParserChar* text, size_t textLength );
bool _end__sources____fx_sources_type(){return mImpl->end__sources____fx_sources_type();}
bool _preBegin__sources____fx_sources_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sources____fx_sources_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sources____fx_sources_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sources____fx_sources_type();
#endif
bool _freeAttributes__sources____fx_sources_type( void* attributeData );

bool _begin__glsl_program_type____bind_attribute( void* attributeData ){return mImpl->begin__glsl_program_type____bind_attribute(*static_cast<glsl_program_type____bind_attribute__AttributeData*>(attributeData));}
bool _data__glsl_program_type____bind_attribute( const ParserChar* text, size_t textLength );
bool _end__glsl_program_type____bind_attribute(){return mImpl->end__glsl_program_type____bind_attribute();}
bool _preBegin__glsl_program_type____bind_attribute( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__glsl_program_type____bind_attribute();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__glsl_program_type____bind_attribute( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__glsl_program_type____bind_attribute();
#endif
bool _freeAttributes__glsl_program_type____bind_attribute( void* attributeData );

bool _begin__glsl_program_type____bind_uniform( void* attributeData ){return mImpl->begin__glsl_program_type____bind_uniform(*static_cast<glsl_program_type____bind_uniform__AttributeData*>(attributeData));}
bool _data__glsl_program_type____bind_uniform( const ParserChar* text, size_t textLength );
bool _end__glsl_program_type____bind_uniform(){return mImpl->end__glsl_program_type____bind_uniform();}
bool _preBegin__glsl_program_type____bind_uniform( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__glsl_program_type____bind_uniform();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__glsl_program_type____bind_uniform( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__glsl_program_type____bind_uniform();
#endif
bool _freeAttributes__glsl_program_type____bind_uniform( void* attributeData );

bool _begin__profile_GLSL__technique__pass__program__bind_uniform__param( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__program__bind_uniform__param(*static_cast<profile_GLSL__technique__pass__program__bind_uniform__param__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__program__bind_uniform__param( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__program__bind_uniform__param(){return mImpl->end__profile_GLSL__technique__pass__program__bind_uniform__param();}
bool _preBegin__profile_GLSL__technique__pass__program__bind_uniform__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__program__bind_uniform__param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__program__bind_uniform__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__program__bind_uniform__param();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__program__bind_uniform__param( void* attributeData );

bool _begin__profile_GLSL__technique__pass__evaluate( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__evaluate();}
bool _data__profile_GLSL__technique__pass__evaluate( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__evaluate(){return mImpl->end__profile_GLSL__technique__pass__evaluate();}
bool _preBegin__profile_GLSL__technique__pass__evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLSL__technique__pass__evaluate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLSL__technique__pass__evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__evaluate();
#endif
bool _freeAttributes__profile_GLSL__technique__pass__evaluate( void* attributeData );

bool _begin__profile_CG( void* attributeData ){return mImpl->begin__profile_CG(*static_cast<profile_CG__AttributeData*>(attributeData));}
bool _data__profile_CG( const ParserChar* text, size_t textLength );
bool _end__profile_CG(){return mImpl->end__profile_CG();}
bool _preBegin__profile_CG( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_CG();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_CG( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG();
#endif
bool _freeAttributes__profile_CG( void* attributeData );

bool _begin__newparam____cg_newparam_type( void* attributeData ){return mImpl->begin__newparam____cg_newparam_type(*static_cast<newparam____cg_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____cg_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____cg_newparam_type(){return mImpl->end__newparam____cg_newparam_type();}
bool _preBegin__newparam____cg_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____cg_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____cg_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____cg_newparam_type();
#endif
bool _freeAttributes__newparam____cg_newparam_type( void* attributeData );

bool _begin__bool2x1( void* attributeData ){return mImpl->begin__bool2x1();}
bool _data__bool2x1( const ParserChar* text, size_t textLength );
bool _end__bool2x1(){return mImpl->end__bool2x1();}
bool _preBegin__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool2x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x1();
#endif
bool _freeAttributes__bool2x1( void* attributeData );

bool _begin__bool2x2( void* attributeData ){return mImpl->begin__bool2x2();}
bool _data__bool2x2( const ParserChar* text, size_t textLength );
bool _end__bool2x2(){return mImpl->end__bool2x2();}
bool _preBegin__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool2x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x2();
#endif
bool _freeAttributes__bool2x2( void* attributeData );

bool _begin__bool2x3( void* attributeData ){return mImpl->begin__bool2x3();}
bool _data__bool2x3( const ParserChar* text, size_t textLength );
bool _end__bool2x3(){return mImpl->end__bool2x3();}
bool _preBegin__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool2x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x3();
#endif
bool _freeAttributes__bool2x3( void* attributeData );

bool _begin__bool2x4( void* attributeData ){return mImpl->begin__bool2x4();}
bool _data__bool2x4( const ParserChar* text, size_t textLength );
bool _end__bool2x4(){return mImpl->end__bool2x4();}
bool _preBegin__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool2x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x4();
#endif
bool _freeAttributes__bool2x4( void* attributeData );

bool _begin__bool3x1( void* attributeData ){return mImpl->begin__bool3x1();}
bool _data__bool3x1( const ParserChar* text, size_t textLength );
bool _end__bool3x1(){return mImpl->end__bool3x1();}
bool _preBegin__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool3x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x1();
#endif
bool _freeAttributes__bool3x1( void* attributeData );

bool _begin__bool3x2( void* attributeData ){return mImpl->begin__bool3x2();}
bool _data__bool3x2( const ParserChar* text, size_t textLength );
bool _end__bool3x2(){return mImpl->end__bool3x2();}
bool _preBegin__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool3x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x2();
#endif
bool _freeAttributes__bool3x2( void* attributeData );

bool _begin__bool3x3( void* attributeData ){return mImpl->begin__bool3x3();}
bool _data__bool3x3( const ParserChar* text, size_t textLength );
bool _end__bool3x3(){return mImpl->end__bool3x3();}
bool _preBegin__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool3x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x3();
#endif
bool _freeAttributes__bool3x3( void* attributeData );

bool _begin__bool3x4( void* attributeData ){return mImpl->begin__bool3x4();}
bool _data__bool3x4( const ParserChar* text, size_t textLength );
bool _end__bool3x4(){return mImpl->end__bool3x4();}
bool _preBegin__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool3x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x4();
#endif
bool _freeAttributes__bool3x4( void* attributeData );

bool _begin__bool4x1( void* attributeData ){return mImpl->begin__bool4x1();}
bool _data__bool4x1( const ParserChar* text, size_t textLength );
bool _end__bool4x1(){return mImpl->end__bool4x1();}
bool _preBegin__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool4x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x1();
#endif
bool _freeAttributes__bool4x1( void* attributeData );

bool _begin__bool4x2( void* attributeData ){return mImpl->begin__bool4x2();}
bool _data__bool4x2( const ParserChar* text, size_t textLength );
bool _end__bool4x2(){return mImpl->end__bool4x2();}
bool _preBegin__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool4x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x2();
#endif
bool _freeAttributes__bool4x2( void* attributeData );

bool _begin__bool4x3( void* attributeData ){return mImpl->begin__bool4x3();}
bool _data__bool4x3( const ParserChar* text, size_t textLength );
bool _end__bool4x3(){return mImpl->end__bool4x3();}
bool _preBegin__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool4x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x3();
#endif
bool _freeAttributes__bool4x3( void* attributeData );

bool _begin__bool4x4( void* attributeData ){return mImpl->begin__bool4x4();}
bool _data__bool4x4( const ParserChar* text, size_t textLength );
bool _end__bool4x4(){return mImpl->end__bool4x4();}
bool _preBegin__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bool4x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x4();
#endif
bool _freeAttributes__bool4x4( void* attributeData );

bool _begin__int2x1( void* attributeData ){return mImpl->begin__int2x1();}
bool _data__int2x1( const ParserChar* text, size_t textLength );
bool _end__int2x1(){return mImpl->end__int2x1();}
bool _preBegin__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int2x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x1();
#endif
bool _freeAttributes__int2x1( void* attributeData );

bool _begin__int2x2( void* attributeData ){return mImpl->begin__int2x2();}
bool _data__int2x2( const ParserChar* text, size_t textLength );
bool _end__int2x2(){return mImpl->end__int2x2();}
bool _preBegin__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int2x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x2();
#endif
bool _freeAttributes__int2x2( void* attributeData );

bool _begin__int2x3( void* attributeData ){return mImpl->begin__int2x3();}
bool _data__int2x3( const ParserChar* text, size_t textLength );
bool _end__int2x3(){return mImpl->end__int2x3();}
bool _preBegin__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int2x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x3();
#endif
bool _freeAttributes__int2x3( void* attributeData );

bool _begin__int2x4( void* attributeData ){return mImpl->begin__int2x4();}
bool _data__int2x4( const ParserChar* text, size_t textLength );
bool _end__int2x4(){return mImpl->end__int2x4();}
bool _preBegin__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int2x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x4();
#endif
bool _freeAttributes__int2x4( void* attributeData );

bool _begin__int3x1( void* attributeData ){return mImpl->begin__int3x1();}
bool _data__int3x1( const ParserChar* text, size_t textLength );
bool _end__int3x1(){return mImpl->end__int3x1();}
bool _preBegin__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int3x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x1();
#endif
bool _freeAttributes__int3x1( void* attributeData );

bool _begin__int3x2( void* attributeData ){return mImpl->begin__int3x2();}
bool _data__int3x2( const ParserChar* text, size_t textLength );
bool _end__int3x2(){return mImpl->end__int3x2();}
bool _preBegin__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int3x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x2();
#endif
bool _freeAttributes__int3x2( void* attributeData );

bool _begin__int3x3( void* attributeData ){return mImpl->begin__int3x3();}
bool _data__int3x3( const ParserChar* text, size_t textLength );
bool _end__int3x3(){return mImpl->end__int3x3();}
bool _preBegin__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int3x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x3();
#endif
bool _freeAttributes__int3x3( void* attributeData );

bool _begin__int3x4( void* attributeData ){return mImpl->begin__int3x4();}
bool _data__int3x4( const ParserChar* text, size_t textLength );
bool _end__int3x4(){return mImpl->end__int3x4();}
bool _preBegin__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int3x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x4();
#endif
bool _freeAttributes__int3x4( void* attributeData );

bool _begin__int4x1( void* attributeData ){return mImpl->begin__int4x1();}
bool _data__int4x1( const ParserChar* text, size_t textLength );
bool _end__int4x1(){return mImpl->end__int4x1();}
bool _preBegin__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int4x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x1();
#endif
bool _freeAttributes__int4x1( void* attributeData );

bool _begin__int4x2( void* attributeData ){return mImpl->begin__int4x2();}
bool _data__int4x2( const ParserChar* text, size_t textLength );
bool _end__int4x2(){return mImpl->end__int4x2();}
bool _preBegin__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int4x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x2();
#endif
bool _freeAttributes__int4x2( void* attributeData );

bool _begin__int4x3( void* attributeData ){return mImpl->begin__int4x3();}
bool _data__int4x3( const ParserChar* text, size_t textLength );
bool _end__int4x3(){return mImpl->end__int4x3();}
bool _preBegin__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int4x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x3();
#endif
bool _freeAttributes__int4x3( void* attributeData );

bool _begin__int4x4( void* attributeData ){return mImpl->begin__int4x4();}
bool _data__int4x4( const ParserChar* text, size_t textLength );
bool _end__int4x4(){return mImpl->end__int4x4();}
bool _preBegin__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int4x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x4();
#endif
bool _freeAttributes__int4x4( void* attributeData );

bool _begin__half( void* attributeData ){return mImpl->begin__half();}
bool _data__half( const ParserChar* text, size_t textLength );
bool _end__half(){return mImpl->end__half();}
bool _preBegin__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half();
#endif
bool _freeAttributes__half( void* attributeData );

bool _begin__half2( void* attributeData ){return mImpl->begin__half2();}
bool _data__half2( const ParserChar* text, size_t textLength );
bool _end__half2(){return mImpl->end__half2();}
bool _preBegin__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2();
#endif
bool _freeAttributes__half2( void* attributeData );

bool _begin__half3( void* attributeData ){return mImpl->begin__half3();}
bool _data__half3( const ParserChar* text, size_t textLength );
bool _end__half3(){return mImpl->end__half3();}
bool _preBegin__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3();
#endif
bool _freeAttributes__half3( void* attributeData );

bool _begin__half4( void* attributeData ){return mImpl->begin__half4();}
bool _data__half4( const ParserChar* text, size_t textLength );
bool _end__half4(){return mImpl->end__half4();}
bool _preBegin__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4();
#endif
bool _freeAttributes__half4( void* attributeData );

bool _begin__half2x1( void* attributeData ){return mImpl->begin__half2x1();}
bool _data__half2x1( const ParserChar* text, size_t textLength );
bool _end__half2x1(){return mImpl->end__half2x1();}
bool _preBegin__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half2x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x1();
#endif
bool _freeAttributes__half2x1( void* attributeData );

bool _begin__half2x2( void* attributeData ){return mImpl->begin__half2x2();}
bool _data__half2x2( const ParserChar* text, size_t textLength );
bool _end__half2x2(){return mImpl->end__half2x2();}
bool _preBegin__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half2x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x2();
#endif
bool _freeAttributes__half2x2( void* attributeData );

bool _begin__half2x3( void* attributeData ){return mImpl->begin__half2x3();}
bool _data__half2x3( const ParserChar* text, size_t textLength );
bool _end__half2x3(){return mImpl->end__half2x3();}
bool _preBegin__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half2x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x3();
#endif
bool _freeAttributes__half2x3( void* attributeData );

bool _begin__half2x4( void* attributeData ){return mImpl->begin__half2x4();}
bool _data__half2x4( const ParserChar* text, size_t textLength );
bool _end__half2x4(){return mImpl->end__half2x4();}
bool _preBegin__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half2x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x4();
#endif
bool _freeAttributes__half2x4( void* attributeData );

bool _begin__half3x1( void* attributeData ){return mImpl->begin__half3x1();}
bool _data__half3x1( const ParserChar* text, size_t textLength );
bool _end__half3x1(){return mImpl->end__half3x1();}
bool _preBegin__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half3x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x1();
#endif
bool _freeAttributes__half3x1( void* attributeData );

bool _begin__half3x2( void* attributeData ){return mImpl->begin__half3x2();}
bool _data__half3x2( const ParserChar* text, size_t textLength );
bool _end__half3x2(){return mImpl->end__half3x2();}
bool _preBegin__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half3x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x2();
#endif
bool _freeAttributes__half3x2( void* attributeData );

bool _begin__half3x3( void* attributeData ){return mImpl->begin__half3x3();}
bool _data__half3x3( const ParserChar* text, size_t textLength );
bool _end__half3x3(){return mImpl->end__half3x3();}
bool _preBegin__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half3x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x3();
#endif
bool _freeAttributes__half3x3( void* attributeData );

bool _begin__half3x4( void* attributeData ){return mImpl->begin__half3x4();}
bool _data__half3x4( const ParserChar* text, size_t textLength );
bool _end__half3x4(){return mImpl->end__half3x4();}
bool _preBegin__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half3x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x4();
#endif
bool _freeAttributes__half3x4( void* attributeData );

bool _begin__half4x1( void* attributeData ){return mImpl->begin__half4x1();}
bool _data__half4x1( const ParserChar* text, size_t textLength );
bool _end__half4x1(){return mImpl->end__half4x1();}
bool _preBegin__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half4x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x1();
#endif
bool _freeAttributes__half4x1( void* attributeData );

bool _begin__half4x2( void* attributeData ){return mImpl->begin__half4x2();}
bool _data__half4x2( const ParserChar* text, size_t textLength );
bool _end__half4x2(){return mImpl->end__half4x2();}
bool _preBegin__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half4x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x2();
#endif
bool _freeAttributes__half4x2( void* attributeData );

bool _begin__half4x3( void* attributeData ){return mImpl->begin__half4x3();}
bool _data__half4x3( const ParserChar* text, size_t textLength );
bool _end__half4x3(){return mImpl->end__half4x3();}
bool _preBegin__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half4x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x3();
#endif
bool _freeAttributes__half4x3( void* attributeData );

bool _begin__half4x4( void* attributeData ){return mImpl->begin__half4x4();}
bool _data__half4x4( const ParserChar* text, size_t textLength );
bool _end__half4x4(){return mImpl->end__half4x4();}
bool _preBegin__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half4x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x4();
#endif
bool _freeAttributes__half4x4( void* attributeData );

bool _begin__fixed( void* attributeData ){return mImpl->begin__fixed();}
bool _data__fixed( const ParserChar* text, size_t textLength );
bool _end__fixed(){return mImpl->end__fixed();}
bool _preBegin__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed();
#endif
bool _freeAttributes__fixed( void* attributeData );

bool _begin__fixed2( void* attributeData ){return mImpl->begin__fixed2();}
bool _data__fixed2( const ParserChar* text, size_t textLength );
bool _end__fixed2(){return mImpl->end__fixed2();}
bool _preBegin__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2();
#endif
bool _freeAttributes__fixed2( void* attributeData );

bool _begin__fixed3( void* attributeData ){return mImpl->begin__fixed3();}
bool _data__fixed3( const ParserChar* text, size_t textLength );
bool _end__fixed3(){return mImpl->end__fixed3();}
bool _preBegin__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3();
#endif
bool _freeAttributes__fixed3( void* attributeData );

bool _begin__fixed4( void* attributeData ){return mImpl->begin__fixed4();}
bool _data__fixed4( const ParserChar* text, size_t textLength );
bool _end__fixed4(){return mImpl->end__fixed4();}
bool _preBegin__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4();
#endif
bool _freeAttributes__fixed4( void* attributeData );

bool _begin__fixed2x1( void* attributeData ){return mImpl->begin__fixed2x1();}
bool _data__fixed2x1( const ParserChar* text, size_t textLength );
bool _end__fixed2x1(){return mImpl->end__fixed2x1();}
bool _preBegin__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed2x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x1();
#endif
bool _freeAttributes__fixed2x1( void* attributeData );

bool _begin__fixed2x2( void* attributeData ){return mImpl->begin__fixed2x2();}
bool _data__fixed2x2( const ParserChar* text, size_t textLength );
bool _end__fixed2x2(){return mImpl->end__fixed2x2();}
bool _preBegin__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed2x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x2();
#endif
bool _freeAttributes__fixed2x2( void* attributeData );

bool _begin__fixed2x3( void* attributeData ){return mImpl->begin__fixed2x3();}
bool _data__fixed2x3( const ParserChar* text, size_t textLength );
bool _end__fixed2x3(){return mImpl->end__fixed2x3();}
bool _preBegin__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed2x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x3();
#endif
bool _freeAttributes__fixed2x3( void* attributeData );

bool _begin__fixed2x4( void* attributeData ){return mImpl->begin__fixed2x4();}
bool _data__fixed2x4( const ParserChar* text, size_t textLength );
bool _end__fixed2x4(){return mImpl->end__fixed2x4();}
bool _preBegin__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed2x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x4();
#endif
bool _freeAttributes__fixed2x4( void* attributeData );

bool _begin__fixed3x1( void* attributeData ){return mImpl->begin__fixed3x1();}
bool _data__fixed3x1( const ParserChar* text, size_t textLength );
bool _end__fixed3x1(){return mImpl->end__fixed3x1();}
bool _preBegin__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed3x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x1();
#endif
bool _freeAttributes__fixed3x1( void* attributeData );

bool _begin__fixed3x2( void* attributeData ){return mImpl->begin__fixed3x2();}
bool _data__fixed3x2( const ParserChar* text, size_t textLength );
bool _end__fixed3x2(){return mImpl->end__fixed3x2();}
bool _preBegin__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed3x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x2();
#endif
bool _freeAttributes__fixed3x2( void* attributeData );

bool _begin__fixed3x3( void* attributeData ){return mImpl->begin__fixed3x3();}
bool _data__fixed3x3( const ParserChar* text, size_t textLength );
bool _end__fixed3x3(){return mImpl->end__fixed3x3();}
bool _preBegin__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed3x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x3();
#endif
bool _freeAttributes__fixed3x3( void* attributeData );

bool _begin__fixed3x4( void* attributeData ){return mImpl->begin__fixed3x4();}
bool _data__fixed3x4( const ParserChar* text, size_t textLength );
bool _end__fixed3x4(){return mImpl->end__fixed3x4();}
bool _preBegin__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed3x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x4();
#endif
bool _freeAttributes__fixed3x4( void* attributeData );

bool _begin__fixed4x1( void* attributeData ){return mImpl->begin__fixed4x1();}
bool _data__fixed4x1( const ParserChar* text, size_t textLength );
bool _end__fixed4x1(){return mImpl->end__fixed4x1();}
bool _preBegin__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed4x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x1();
#endif
bool _freeAttributes__fixed4x1( void* attributeData );

bool _begin__fixed4x2( void* attributeData ){return mImpl->begin__fixed4x2();}
bool _data__fixed4x2( const ParserChar* text, size_t textLength );
bool _end__fixed4x2(){return mImpl->end__fixed4x2();}
bool _preBegin__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed4x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x2();
#endif
bool _freeAttributes__fixed4x2( void* attributeData );

bool _begin__fixed4x3( void* attributeData ){return mImpl->begin__fixed4x3();}
bool _data__fixed4x3( const ParserChar* text, size_t textLength );
bool _end__fixed4x3(){return mImpl->end__fixed4x3();}
bool _preBegin__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed4x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x3();
#endif
bool _freeAttributes__fixed4x3( void* attributeData );

bool _begin__fixed4x4( void* attributeData ){return mImpl->begin__fixed4x4();}
bool _data__fixed4x4( const ParserChar* text, size_t textLength );
bool _end__fixed4x4(){return mImpl->end__fixed4x4();}
bool _preBegin__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__fixed4x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x4();
#endif
bool _freeAttributes__fixed4x4( void* attributeData );

bool _begin__array____cg_array_type( void* attributeData ){return mImpl->begin__array____cg_array_type(*static_cast<array____cg_array_type__AttributeData*>(attributeData));}
bool _data__array____cg_array_type( const ParserChar* text, size_t textLength );
bool _end__array____cg_array_type(){return mImpl->end__array____cg_array_type();}
bool _preBegin__array____cg_array_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__array____cg_array_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__array____cg_array_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__array____cg_array_type();
#endif
bool _freeAttributes__array____cg_array_type( void* attributeData );

bool _begin__usertype____cg_user_type( void* attributeData ){return mImpl->begin__usertype____cg_user_type(*static_cast<usertype____cg_user_type__AttributeData*>(attributeData));}
bool _data__usertype____cg_user_type( const ParserChar* text, size_t textLength );
bool _end__usertype____cg_user_type(){return mImpl->end__usertype____cg_user_type();}
bool _preBegin__usertype____cg_user_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__usertype____cg_user_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__usertype____cg_user_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__usertype____cg_user_type();
#endif
bool _freeAttributes__usertype____cg_user_type( void* attributeData );

bool _begin__setparam____cg_setparam_type( void* attributeData ){return mImpl->begin__setparam____cg_setparam_type(*static_cast<setparam____cg_setparam_type__AttributeData*>(attributeData));}
bool _data__setparam____cg_setparam_type( const ParserChar* text, size_t textLength );
bool _end__setparam____cg_setparam_type(){return mImpl->end__setparam____cg_setparam_type();}
bool _preBegin__setparam____cg_setparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__setparam____cg_setparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__setparam____cg_setparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____cg_setparam_type();
#endif
bool _freeAttributes__setparam____cg_setparam_type( void* attributeData );

bool _begin__profile_cg_type____technique( void* attributeData ){return mImpl->begin__profile_cg_type____technique(*static_cast<profile_cg_type____technique__AttributeData*>(attributeData));}
bool _data__profile_cg_type____technique( const ParserChar* text, size_t textLength );
bool _end__profile_cg_type____technique(){return mImpl->end__profile_cg_type____technique();}
bool _preBegin__profile_cg_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_cg_type____technique();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_cg_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_cg_type____technique();
#endif
bool _freeAttributes__profile_cg_type____technique( void* attributeData );

bool _begin__pass____cg_pass_type( void* attributeData ){return mImpl->begin__pass____cg_pass_type(*static_cast<pass____cg_pass_type__AttributeData*>(attributeData));}
bool _data__pass____cg_pass_type( const ParserChar* text, size_t textLength );
bool _end__pass____cg_pass_type(){return mImpl->end__pass____cg_pass_type();}
bool _preBegin__pass____cg_pass_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__pass____cg_pass_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__pass____cg_pass_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__pass____cg_pass_type();
#endif
bool _freeAttributes__pass____cg_pass_type( void* attributeData );

bool _begin__cg_pass_type____states( void* attributeData ){return mImpl->begin__cg_pass_type____states();}
bool _data__cg_pass_type____states( const ParserChar* text, size_t textLength );
bool _end__cg_pass_type____states(){return mImpl->end__cg_pass_type____states();}
bool _preBegin__cg_pass_type____states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cg_pass_type____states();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cg_pass_type____states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cg_pass_type____states();
#endif
bool _freeAttributes__cg_pass_type____states( void* attributeData );

bool _begin__cg_pass_type____program( void* attributeData ){return mImpl->begin__cg_pass_type____program();}
bool _data__cg_pass_type____program( const ParserChar* text, size_t textLength );
bool _end__cg_pass_type____program(){return mImpl->end__cg_pass_type____program();}
bool _preBegin__cg_pass_type____program( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cg_pass_type____program();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cg_pass_type____program( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cg_pass_type____program();
#endif
bool _freeAttributes__cg_pass_type____program( void* attributeData );

bool _begin__profile_CG__technique__pass__program__shader( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__program__shader(*static_cast<profile_CG__technique__pass__program__shader__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__program__shader( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__program__shader(){return mImpl->end__profile_CG__technique__pass__program__shader();}
bool _preBegin__profile_CG__technique__pass__program__shader( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_CG__technique__pass__program__shader();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_CG__technique__pass__program__shader( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__program__shader();
#endif
bool _freeAttributes__profile_CG__technique__pass__program__shader( void* attributeData );

bool _begin__profile_CG__technique__pass__program__shader__sources( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__program__shader__sources(*static_cast<profile_CG__technique__pass__program__shader__sources__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__program__shader__sources( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__program__shader__sources(){return mImpl->end__profile_CG__technique__pass__program__shader__sources();}
bool _preBegin__profile_CG__technique__pass__program__shader__sources( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_CG__technique__pass__program__shader__sources();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_CG__technique__pass__program__shader__sources( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__program__shader__sources();
#endif
bool _freeAttributes__profile_CG__technique__pass__program__shader__sources( void* attributeData );

bool _begin__profile_CG__technique__pass__program__shader__bind_uniform( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__program__shader__bind_uniform(*static_cast<profile_CG__technique__pass__program__shader__bind_uniform__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__program__shader__bind_uniform( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__program__shader__bind_uniform(){return mImpl->end__profile_CG__technique__pass__program__shader__bind_uniform();}
bool _preBegin__profile_CG__technique__pass__program__shader__bind_uniform( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_CG__technique__pass__program__shader__bind_uniform();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_CG__technique__pass__program__shader__bind_uniform( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__program__shader__bind_uniform();
#endif
bool _freeAttributes__profile_CG__technique__pass__program__shader__bind_uniform( void* attributeData );

bool _begin__profile_CG__technique__pass__program__shader__bind_uniform__param( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__program__shader__bind_uniform__param(*static_cast<profile_CG__technique__pass__program__shader__bind_uniform__param__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__program__shader__bind_uniform__param( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__program__shader__bind_uniform__param(){return mImpl->end__profile_CG__technique__pass__program__shader__bind_uniform__param();}
bool _preBegin__profile_CG__technique__pass__program__shader__bind_uniform__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_CG__technique__pass__program__shader__bind_uniform__param();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_CG__technique__pass__program__shader__bind_uniform__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__program__shader__bind_uniform__param();
#endif
bool _freeAttributes__profile_CG__technique__pass__program__shader__bind_uniform__param( void* attributeData );

bool _begin__cg_pass_type____evaluate( void* attributeData ){return mImpl->begin__cg_pass_type____evaluate();}
bool _data__cg_pass_type____evaluate( const ParserChar* text, size_t textLength );
bool _end__cg_pass_type____evaluate(){return mImpl->end__cg_pass_type____evaluate();}
bool _preBegin__cg_pass_type____evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cg_pass_type____evaluate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cg_pass_type____evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cg_pass_type____evaluate();
#endif
bool _freeAttributes__cg_pass_type____evaluate( void* attributeData );

bool _begin__profile_GLES( void* attributeData ){return mImpl->begin__profile_GLES(*static_cast<profile_GLES__AttributeData*>(attributeData));}
bool _data__profile_GLES( const ParserChar* text, size_t textLength );
bool _end__profile_GLES(){return mImpl->end__profile_GLES();}
bool _preBegin__profile_GLES( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES();
#endif
bool _freeAttributes__profile_GLES( void* attributeData );

bool _begin__newparam____gles_newparam_type( void* attributeData ){return mImpl->begin__newparam____gles_newparam_type(*static_cast<newparam____gles_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____gles_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____gles_newparam_type(){return mImpl->end__newparam____gles_newparam_type();}
bool _preBegin__newparam____gles_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____gles_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____gles_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____gles_newparam_type();
#endif
bool _freeAttributes__newparam____gles_newparam_type( void* attributeData );

bool _begin__float1x1( void* attributeData ){return mImpl->begin__float1x1();}
bool _data__float1x1( const ParserChar* text, size_t textLength );
bool _end__float1x1(){return mImpl->end__float1x1();}
bool _preBegin__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float1x1();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x1();
#endif
bool _freeAttributes__float1x1( void* attributeData );

bool _begin__float1x2( void* attributeData ){return mImpl->begin__float1x2();}
bool _data__float1x2( const ParserChar* text, size_t textLength );
bool _end__float1x2(){return mImpl->end__float1x2();}
bool _preBegin__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float1x2();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x2();
#endif
bool _freeAttributes__float1x2( void* attributeData );

bool _begin__float1x3( void* attributeData ){return mImpl->begin__float1x3();}
bool _data__float1x3( const ParserChar* text, size_t textLength );
bool _end__float1x3(){return mImpl->end__float1x3();}
bool _preBegin__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float1x3();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x3();
#endif
bool _freeAttributes__float1x3( void* attributeData );

bool _begin__float1x4( void* attributeData ){return mImpl->begin__float1x4();}
bool _data__float1x4( const ParserChar* text, size_t textLength );
bool _end__float1x4(){return mImpl->end__float1x4();}
bool _preBegin__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__float1x4();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x4();
#endif
bool _freeAttributes__float1x4( void* attributeData );

bool _begin__sampler2D____gles_sampler_type( void* attributeData ){return mImpl->begin__sampler2D____gles_sampler_type();}
bool _data__sampler2D____gles_sampler_type( const ParserChar* text, size_t textLength );
bool _end__sampler2D____gles_sampler_type(){return mImpl->end__sampler2D____gles_sampler_type();}
bool _preBegin__sampler2D____gles_sampler_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler2D____gles_sampler_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler2D____gles_sampler_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler2D____gles_sampler_type();
#endif
bool _freeAttributes__sampler2D____gles_sampler_type( void* attributeData );

bool _begin__texcoord( void* attributeData ){return mImpl->begin__texcoord(*static_cast<texcoord__AttributeData*>(attributeData));}
bool _data__texcoord( const ParserChar* text, size_t textLength );
bool _end__texcoord(){return mImpl->end__texcoord();}
bool _preBegin__texcoord( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texcoord();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texcoord( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texcoord();
#endif
bool _freeAttributes__texcoord( void* attributeData );

bool _begin__wrap_s____gles_sampler_wrap_enum( void* attributeData ){return mImpl->begin__wrap_s____gles_sampler_wrap_enum();}
bool _data__wrap_s____gles_sampler_wrap_enum( const ParserChar* text, size_t textLength );
bool _end__wrap_s____gles_sampler_wrap_enum(){return mImpl->end__wrap_s____gles_sampler_wrap_enum();}
bool _preBegin__wrap_s____gles_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__wrap_s____gles_sampler_wrap_enum();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__wrap_s____gles_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_s____gles_sampler_wrap_enum();
#endif
bool _freeAttributes__wrap_s____gles_sampler_wrap_enum( void* attributeData );


ENUM__gles_sampler_wrap_enum toEnumDataPrefix_ENUM__gles_sampler_wrap_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_sampler_wrap_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_sampler_wrap_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_sampler_wrap_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_sampler_wrap_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_sampler_wrap_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_sampler_wrap_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__wrap_t____gles_sampler_wrap_enum( void* attributeData ){return mImpl->begin__wrap_t____gles_sampler_wrap_enum();}
bool _data__wrap_t____gles_sampler_wrap_enum( const ParserChar* text, size_t textLength );
bool _end__wrap_t____gles_sampler_wrap_enum(){return mImpl->end__wrap_t____gles_sampler_wrap_enum();}
bool _preBegin__wrap_t____gles_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__wrap_t____gles_sampler_wrap_enum();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__wrap_t____gles_sampler_wrap_enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_t____gles_sampler_wrap_enum();
#endif
bool _freeAttributes__wrap_t____gles_sampler_wrap_enum( void* attributeData );

bool _begin__enum____gles_enumeration_type( void* attributeData ){return mImpl->begin__enum____gles_enumeration_type();}
bool _data__enum____gles_enumeration_type( const ParserChar* text, size_t textLength );
bool _end__enum____gles_enumeration_type(){return mImpl->end__enum____gles_enumeration_type();}
bool _preBegin__enum____gles_enumeration_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__enum____gles_enumeration_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__enum____gles_enumeration_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enum____gles_enumeration_type();
#endif
bool _freeAttributes__enum____gles_enumeration_type( void* attributeData );


UNION__gles_enumeration_type toUnionPrefix_UNION__gles_enumeration_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed
);



bool _begin__profile_gles_type____technique( void* attributeData ){return mImpl->begin__profile_gles_type____technique(*static_cast<profile_gles_type____technique__AttributeData*>(attributeData));}
bool _data__profile_gles_type____technique( const ParserChar* text, size_t textLength );
bool _end__profile_gles_type____technique(){return mImpl->end__profile_gles_type____technique();}
bool _preBegin__profile_gles_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_gles_type____technique();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_gles_type____technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_gles_type____technique();
#endif
bool _freeAttributes__profile_gles_type____technique( void* attributeData );

bool _begin__profile_GLES__technique__pass( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass(*static_cast<profile_GLES__technique__pass__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass(){return mImpl->end__profile_GLES__technique__pass();}
bool _preBegin__profile_GLES__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass();
#endif
bool _freeAttributes__profile_GLES__technique__pass( void* attributeData );

bool _begin__profile_GLES__technique__pass__states( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states();}
bool _data__profile_GLES__technique__pass__states( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states(){return mImpl->end__profile_GLES__technique__pass__states();}
bool _preBegin__profile_GLES__technique__pass__states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__alpha_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__alpha_func();}
bool _data__profile_GLES__technique__pass__states__alpha_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__alpha_func(){return mImpl->end__profile_GLES__technique__pass__states__alpha_func();}
bool _preBegin__profile_GLES__technique__pass__states__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__alpha_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__alpha_func();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__alpha_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__alpha_func__func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__alpha_func__func(*static_cast<profile_GLES__technique__pass__states__alpha_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__alpha_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__alpha_func__func(){return mImpl->end__profile_GLES__technique__pass__states__alpha_func__func();}
bool _preBegin__profile_GLES__technique__pass__states__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__alpha_func__func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__alpha_func__func();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__alpha_func__func( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__alpha_func__value( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__alpha_func__value(*static_cast<profile_GLES__technique__pass__states__alpha_func__value__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__alpha_func__value( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__alpha_func__value(){return mImpl->end__profile_GLES__technique__pass__states__alpha_func__value();}
bool _preBegin__profile_GLES__technique__pass__states__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__alpha_func__value();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__alpha_func__value();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__alpha_func__value( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__blend_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__blend_func();}
bool _data__profile_GLES__technique__pass__states__blend_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__blend_func(){return mImpl->end__profile_GLES__technique__pass__states__blend_func();}
bool _preBegin__profile_GLES__technique__pass__states__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__blend_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__blend_func();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__blend_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__blend_func__src( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__blend_func__src(*static_cast<profile_GLES__technique__pass__states__blend_func__src__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__blend_func__src( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__blend_func__src(){return mImpl->end__profile_GLES__technique__pass__states__blend_func__src();}
bool _preBegin__profile_GLES__technique__pass__states__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__blend_func__src();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__blend_func__src();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__blend_func__src( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__blend_func__dest( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__blend_func__dest(*static_cast<profile_GLES__technique__pass__states__blend_func__dest__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__blend_func__dest( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__blend_func__dest(){return mImpl->end__profile_GLES__technique__pass__states__blend_func__dest();}
bool _preBegin__profile_GLES__technique__pass__states__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__blend_func__dest();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__blend_func__dest();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__blend_func__dest( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__clip_plane( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__clip_plane(*static_cast<profile_GLES__technique__pass__states__clip_plane__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__clip_plane( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__clip_plane(){return mImpl->end__profile_GLES__technique__pass__states__clip_plane();}
bool _preBegin__profile_GLES__technique__pass__states__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__clip_plane();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__clip_plane();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__clip_plane( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__color_mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__color_mask(*static_cast<profile_GLES__technique__pass__states__color_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__color_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__color_mask(){return mImpl->end__profile_GLES__technique__pass__states__color_mask();}
bool _preBegin__profile_GLES__technique__pass__states__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__color_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__color_mask();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__color_mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__cull_face( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__cull_face(*static_cast<profile_GLES__technique__pass__states__cull_face__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__cull_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__cull_face(){return mImpl->end__profile_GLES__technique__pass__states__cull_face();}
bool _preBegin__profile_GLES__technique__pass__states__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__cull_face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__cull_face();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__cull_face( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__depth_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__depth_func(*static_cast<profile_GLES__technique__pass__states__depth_func__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__depth_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__depth_func(){return mImpl->end__profile_GLES__technique__pass__states__depth_func();}
bool _preBegin__profile_GLES__technique__pass__states__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__depth_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__depth_func();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__depth_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__depth_mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__depth_mask(*static_cast<profile_GLES__technique__pass__states__depth_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__depth_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__depth_mask(){return mImpl->end__profile_GLES__technique__pass__states__depth_mask();}
bool _preBegin__profile_GLES__technique__pass__states__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__depth_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__depth_mask();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__depth_mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__depth_range( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__depth_range(*static_cast<profile_GLES__technique__pass__states__depth_range__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__depth_range( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__depth_range(){return mImpl->end__profile_GLES__technique__pass__states__depth_range();}
bool _preBegin__profile_GLES__technique__pass__states__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__depth_range();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__depth_range();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__depth_range( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__fog_color( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__fog_color(*static_cast<profile_GLES__technique__pass__states__fog_color__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__fog_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__fog_color(){return mImpl->end__profile_GLES__technique__pass__states__fog_color();}
bool _preBegin__profile_GLES__technique__pass__states__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__fog_color();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__fog_color();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__fog_color( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__fog_density( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__fog_density(*static_cast<profile_GLES__technique__pass__states__fog_density__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__fog_density( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__fog_density(){return mImpl->end__profile_GLES__technique__pass__states__fog_density();}
bool _preBegin__profile_GLES__technique__pass__states__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__fog_density();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__fog_density();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__fog_density( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__fog_mode( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__fog_mode(*static_cast<profile_GLES__technique__pass__states__fog_mode__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__fog_mode( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__fog_mode(){return mImpl->end__profile_GLES__technique__pass__states__fog_mode();}
bool _preBegin__profile_GLES__technique__pass__states__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__fog_mode();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__fog_mode();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__fog_mode( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__fog_start( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__fog_start(*static_cast<profile_GLES__technique__pass__states__fog_start__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__fog_start( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__fog_start(){return mImpl->end__profile_GLES__technique__pass__states__fog_start();}
bool _preBegin__profile_GLES__technique__pass__states__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__fog_start();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__fog_start();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__fog_start( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__fog_end( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__fog_end(*static_cast<profile_GLES__technique__pass__states__fog_end__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__fog_end( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__fog_end(){return mImpl->end__profile_GLES__technique__pass__states__fog_end();}
bool _preBegin__profile_GLES__technique__pass__states__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__fog_end();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__fog_end();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__fog_end( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__front_face( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__front_face(*static_cast<profile_GLES__technique__pass__states__front_face__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__front_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__front_face(){return mImpl->end__profile_GLES__technique__pass__states__front_face();}
bool _preBegin__profile_GLES__technique__pass__states__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__front_face();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__front_face();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__front_face( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__logic_op( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__logic_op(*static_cast<profile_GLES__technique__pass__states__logic_op__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__logic_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__logic_op(){return mImpl->end__profile_GLES__technique__pass__states__logic_op();}
bool _preBegin__profile_GLES__technique__pass__states__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__logic_op();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__logic_op();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__logic_op( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_ambient( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_ambient(*static_cast<profile_GLES__technique__pass__states__light_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_ambient(){return mImpl->end__profile_GLES__technique__pass__states__light_ambient();}
bool _preBegin__profile_GLES__technique__pass__states__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_ambient();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_ambient( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_diffuse( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_diffuse(*static_cast<profile_GLES__technique__pass__states__light_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_diffuse(){return mImpl->end__profile_GLES__technique__pass__states__light_diffuse();}
bool _preBegin__profile_GLES__technique__pass__states__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_diffuse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_diffuse();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_diffuse( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_specular( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_specular(*static_cast<profile_GLES__technique__pass__states__light_specular__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_specular(){return mImpl->end__profile_GLES__technique__pass__states__light_specular();}
bool _preBegin__profile_GLES__technique__pass__states__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_specular();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_specular();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_specular( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_position( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_position(*static_cast<profile_GLES__technique__pass__states__light_position__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_position( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_position(){return mImpl->end__profile_GLES__technique__pass__states__light_position();}
bool _preBegin__profile_GLES__technique__pass__states__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_position();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_position();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_position( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_constant_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_constant_attenuation(*static_cast<profile_GLES__technique__pass__states__light_constant_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_constant_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_constant_attenuation(){return mImpl->end__profile_GLES__technique__pass__states__light_constant_attenuation();}
bool _preBegin__profile_GLES__technique__pass__states__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_constant_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_constant_attenuation();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_constant_attenuation( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_linear_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_linear_attenuation(*static_cast<profile_GLES__technique__pass__states__light_linear_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_linear_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_linear_attenuation(){return mImpl->end__profile_GLES__technique__pass__states__light_linear_attenuation();}
bool _preBegin__profile_GLES__technique__pass__states__light_linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_linear_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_linear_attenuation();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_linear_attenuation( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_quadratic_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_quadratic_attenuation(*static_cast<profile_GLES__technique__pass__states__light_quadratic_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_quadratic_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_quadratic_attenuation(){return mImpl->end__profile_GLES__technique__pass__states__light_quadratic_attenuation();}
bool _preBegin__profile_GLES__technique__pass__states__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_quadratic_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_quadratic_attenuation();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_quadratic_attenuation( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_spot_cutoff( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_spot_cutoff(*static_cast<profile_GLES__technique__pass__states__light_spot_cutoff__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_spot_cutoff( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_spot_cutoff(){return mImpl->end__profile_GLES__technique__pass__states__light_spot_cutoff();}
bool _preBegin__profile_GLES__technique__pass__states__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_spot_cutoff();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_spot_cutoff();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_spot_cutoff( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_spot_direction( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_spot_direction(*static_cast<profile_GLES__technique__pass__states__light_spot_direction__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_spot_direction( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_spot_direction(){return mImpl->end__profile_GLES__technique__pass__states__light_spot_direction();}
bool _preBegin__profile_GLES__technique__pass__states__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_spot_direction();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_spot_direction();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_spot_direction( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_spot_exponent( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_spot_exponent(*static_cast<profile_GLES__technique__pass__states__light_spot_exponent__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_spot_exponent( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_spot_exponent(){return mImpl->end__profile_GLES__technique__pass__states__light_spot_exponent();}
bool _preBegin__profile_GLES__technique__pass__states__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_spot_exponent();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_spot_exponent();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_spot_exponent( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_model_ambient( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_model_ambient(*static_cast<profile_GLES__technique__pass__states__light_model_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_model_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_model_ambient(){return mImpl->end__profile_GLES__technique__pass__states__light_model_ambient();}
bool _preBegin__profile_GLES__technique__pass__states__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_model_ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_model_ambient();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_model_ambient( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__line_width( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__line_width(*static_cast<profile_GLES__technique__pass__states__line_width__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__line_width( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__line_width(){return mImpl->end__profile_GLES__technique__pass__states__line_width();}
bool _preBegin__profile_GLES__technique__pass__states__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__line_width();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__line_width();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__line_width( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__material_ambient( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__material_ambient(*static_cast<profile_GLES__technique__pass__states__material_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__material_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__material_ambient(){return mImpl->end__profile_GLES__technique__pass__states__material_ambient();}
bool _preBegin__profile_GLES__technique__pass__states__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__material_ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__material_ambient();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__material_ambient( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__material_diffuse( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__material_diffuse(*static_cast<profile_GLES__technique__pass__states__material_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__material_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__material_diffuse(){return mImpl->end__profile_GLES__technique__pass__states__material_diffuse();}
bool _preBegin__profile_GLES__technique__pass__states__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__material_diffuse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__material_diffuse();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__material_diffuse( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__material_emission( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__material_emission(*static_cast<profile_GLES__technique__pass__states__material_emission__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__material_emission( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__material_emission(){return mImpl->end__profile_GLES__technique__pass__states__material_emission();}
bool _preBegin__profile_GLES__technique__pass__states__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__material_emission();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__material_emission();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__material_emission( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__material_shininess( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__material_shininess(*static_cast<profile_GLES__technique__pass__states__material_shininess__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__material_shininess( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__material_shininess(){return mImpl->end__profile_GLES__technique__pass__states__material_shininess();}
bool _preBegin__profile_GLES__technique__pass__states__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__material_shininess();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__material_shininess();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__material_shininess( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__material_specular( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__material_specular(*static_cast<profile_GLES__technique__pass__states__material_specular__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__material_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__material_specular(){return mImpl->end__profile_GLES__technique__pass__states__material_specular();}
bool _preBegin__profile_GLES__technique__pass__states__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__material_specular();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__material_specular();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__material_specular( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__model_view_matrix( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__model_view_matrix(*static_cast<profile_GLES__technique__pass__states__model_view_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__model_view_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__model_view_matrix(){return mImpl->end__profile_GLES__technique__pass__states__model_view_matrix();}
bool _preBegin__profile_GLES__technique__pass__states__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__model_view_matrix();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__model_view_matrix();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__model_view_matrix( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__point_distance_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__point_distance_attenuation(*static_cast<profile_GLES__technique__pass__states__point_distance_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__point_distance_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__point_distance_attenuation(){return mImpl->end__profile_GLES__technique__pass__states__point_distance_attenuation();}
bool _preBegin__profile_GLES__technique__pass__states__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__point_distance_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__point_distance_attenuation();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__point_distance_attenuation( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__point_fade_threshold_size( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__point_fade_threshold_size(*static_cast<profile_GLES__technique__pass__states__point_fade_threshold_size__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__point_fade_threshold_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__point_fade_threshold_size(){return mImpl->end__profile_GLES__technique__pass__states__point_fade_threshold_size();}
bool _preBegin__profile_GLES__technique__pass__states__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__point_fade_threshold_size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__point_fade_threshold_size();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__point_fade_threshold_size( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__point_size( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__point_size(*static_cast<profile_GLES__technique__pass__states__point_size__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__point_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__point_size(){return mImpl->end__profile_GLES__technique__pass__states__point_size();}
bool _preBegin__profile_GLES__technique__pass__states__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__point_size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__point_size();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__point_size( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__point_size_min( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__point_size_min(*static_cast<profile_GLES__technique__pass__states__point_size_min__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__point_size_min( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__point_size_min(){return mImpl->end__profile_GLES__technique__pass__states__point_size_min();}
bool _preBegin__profile_GLES__technique__pass__states__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__point_size_min();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__point_size_min();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__point_size_min( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__point_size_max( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__point_size_max(*static_cast<profile_GLES__technique__pass__states__point_size_max__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__point_size_max( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__point_size_max(){return mImpl->end__profile_GLES__technique__pass__states__point_size_max();}
bool _preBegin__profile_GLES__technique__pass__states__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__point_size_max();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__point_size_max();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__point_size_max( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__polygon_offset( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__polygon_offset(*static_cast<profile_GLES__technique__pass__states__polygon_offset__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__polygon_offset( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__polygon_offset(){return mImpl->end__profile_GLES__technique__pass__states__polygon_offset();}
bool _preBegin__profile_GLES__technique__pass__states__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__polygon_offset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__polygon_offset();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__polygon_offset( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__projection_matrix( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__projection_matrix(*static_cast<profile_GLES__technique__pass__states__projection_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__projection_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__projection_matrix(){return mImpl->end__profile_GLES__technique__pass__states__projection_matrix();}
bool _preBegin__profile_GLES__technique__pass__states__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__projection_matrix();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__projection_matrix();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__projection_matrix( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__scissor( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__scissor(*static_cast<profile_GLES__technique__pass__states__scissor__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__scissor( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__scissor(){return mImpl->end__profile_GLES__technique__pass__states__scissor();}
bool _preBegin__profile_GLES__technique__pass__states__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__scissor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__scissor();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__scissor( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__shade_model( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__shade_model(*static_cast<profile_GLES__technique__pass__states__shade_model__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__shade_model( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__shade_model(){return mImpl->end__profile_GLES__technique__pass__states__shade_model();}
bool _preBegin__profile_GLES__technique__pass__states__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__shade_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__shade_model();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__shade_model( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_func();}
bool _data__profile_GLES__technique__pass__states__stencil_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_func(){return mImpl->end__profile_GLES__technique__pass__states__stencil_func();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_func();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_func__func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_func__func(*static_cast<profile_GLES__technique__pass__states__stencil_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_func__func(){return mImpl->end__profile_GLES__technique__pass__states__stencil_func__func();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_func__func();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_func__func();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_func__func( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_func__ref( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_func__ref(*static_cast<profile_GLES__technique__pass__states__stencil_func__ref__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_func__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_func__ref(){return mImpl->end__profile_GLES__technique__pass__states__stencil_func__ref();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_func__ref();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_func__ref();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_func__ref( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_func__mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_func__mask(*static_cast<profile_GLES__technique__pass__states__stencil_func__mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_func__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_func__mask(){return mImpl->end__profile_GLES__technique__pass__states__stencil_func__mask();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_func__mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_func__mask();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_func__mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_mask(*static_cast<profile_GLES__technique__pass__states__stencil_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_mask(){return mImpl->end__profile_GLES__technique__pass__states__stencil_mask();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_mask();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_mask();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_op( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_op();}
bool _data__profile_GLES__technique__pass__states__stencil_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_op(){return mImpl->end__profile_GLES__technique__pass__states__stencil_op();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_op();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_op();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_op( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_op__fail( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_op__fail(*static_cast<profile_GLES__technique__pass__states__stencil_op__fail__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_op__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_op__fail(){return mImpl->end__profile_GLES__technique__pass__states__stencil_op__fail();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_op__fail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_op__fail();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_op__fail( void* attributeData );


ENUM__gles_stencil_op_enum toEnumDataPrefix_ENUM__gles_stencil_op_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_stencil_op_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_stencil_op_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_stencil_op_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_stencil_op_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_stencil_op_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_stencil_op_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__profile_GLES__technique__pass__states__stencil_op__zfail( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_op__zfail(*static_cast<profile_GLES__technique__pass__states__stencil_op__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_op__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_op__zfail(){return mImpl->end__profile_GLES__technique__pass__states__stencil_op__zfail();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_op__zfail();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_op__zfail();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_op__zfail( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_op__zpass( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_op__zpass(*static_cast<profile_GLES__technique__pass__states__stencil_op__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_op__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_op__zpass(){return mImpl->end__profile_GLES__technique__pass__states__stencil_op__zpass();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_op__zpass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_op__zpass();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_op__zpass( void* attributeData );

bool _begin__texture_pipeline( void* attributeData ){return mImpl->begin__texture_pipeline();}
bool _data__texture_pipeline( const ParserChar* text, size_t textLength );
bool _end__texture_pipeline(){return mImpl->end__texture_pipeline();}
bool _preBegin__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texture_pipeline();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_pipeline();
#endif
bool _freeAttributes__texture_pipeline( void* attributeData );

bool _begin__value____gles_texture_pipeline_type( void* attributeData ){return mImpl->begin__value____gles_texture_pipeline_type(*static_cast<value____gles_texture_pipeline_type__AttributeData*>(attributeData));}
bool _data__value____gles_texture_pipeline_type( const ParserChar* text, size_t textLength );
bool _end__value____gles_texture_pipeline_type(){return mImpl->end__value____gles_texture_pipeline_type();}
bool _preBegin__value____gles_texture_pipeline_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____gles_texture_pipeline_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____gles_texture_pipeline_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gles_texture_pipeline_type();
#endif
bool _freeAttributes__value____gles_texture_pipeline_type( void* attributeData );

bool _begin__texcombiner( void* attributeData ){return mImpl->begin__texcombiner();}
bool _data__texcombiner( const ParserChar* text, size_t textLength );
bool _end__texcombiner(){return mImpl->end__texcombiner();}
bool _preBegin__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texcombiner();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texcombiner();
#endif
bool _freeAttributes__texcombiner( void* attributeData );

bool _begin__constant____gles_texture_constant_type( void* attributeData ){return mImpl->begin__constant____gles_texture_constant_type(*static_cast<constant____gles_texture_constant_type__AttributeData*>(attributeData));}
bool _data__constant____gles_texture_constant_type( const ParserChar* text, size_t textLength );
bool _end__constant____gles_texture_constant_type(){return mImpl->end__constant____gles_texture_constant_type();}
bool _preBegin__constant____gles_texture_constant_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__constant____gles_texture_constant_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__constant____gles_texture_constant_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__constant____gles_texture_constant_type();
#endif
bool _freeAttributes__constant____gles_texture_constant_type( void* attributeData );

bool _begin__RGB( void* attributeData ){return mImpl->begin__RGB(*static_cast<RGB__AttributeData*>(attributeData));}
bool _data__RGB( const ParserChar* text, size_t textLength );
bool _end__RGB(){return mImpl->end__RGB();}
bool _preBegin__RGB( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__RGB();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__RGB( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__RGB();
#endif
bool _freeAttributes__RGB( void* attributeData );


ENUM__gles_texcombiner_operator_rgb_enum toEnumDataPrefix_ENUM__gles_texcombiner_operator_rgb_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operator_rgb_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operator_rgb_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operator_rgb_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operator_rgb_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operator_rgb_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__argument____gles_texcombiner_argument_rgb_type( void* attributeData ){return mImpl->begin__argument____gles_texcombiner_argument_rgb_type(*static_cast<argument____gles_texcombiner_argument_rgb_type__AttributeData*>(attributeData));}
bool _data__argument____gles_texcombiner_argument_rgb_type( const ParserChar* text, size_t textLength );
bool _end__argument____gles_texcombiner_argument_rgb_type(){return mImpl->end__argument____gles_texcombiner_argument_rgb_type();}
bool _preBegin__argument____gles_texcombiner_argument_rgb_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__argument____gles_texcombiner_argument_rgb_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__argument____gles_texcombiner_argument_rgb_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__argument____gles_texcombiner_argument_rgb_type();
#endif
bool _freeAttributes__argument____gles_texcombiner_argument_rgb_type( void* attributeData );


ENUM__gles_texcombiner_source_enum toEnumDataPrefix_ENUM__gles_texcombiner_source_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_source_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_source_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_source_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_source_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_source_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_source_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gles_texcombiner_operand_rgb_enum toEnumDataPrefix_ENUM__gles_texcombiner_operand_rgb_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operand_rgb_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operand_rgb_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operand_rgb_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operand_rgb_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operand_rgb_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__alpha____gles_texcombiner_command_alpha_type( void* attributeData ){return mImpl->begin__alpha____gles_texcombiner_command_alpha_type(*static_cast<alpha____gles_texcombiner_command_alpha_type__AttributeData*>(attributeData));}
bool _data__alpha____gles_texcombiner_command_alpha_type( const ParserChar* text, size_t textLength );
bool _end__alpha____gles_texcombiner_command_alpha_type(){return mImpl->end__alpha____gles_texcombiner_command_alpha_type();}
bool _preBegin__alpha____gles_texcombiner_command_alpha_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__alpha____gles_texcombiner_command_alpha_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__alpha____gles_texcombiner_command_alpha_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__alpha____gles_texcombiner_command_alpha_type();
#endif
bool _freeAttributes__alpha____gles_texcombiner_command_alpha_type( void* attributeData );


ENUM__gles_texcombiner_operator_alpha_enum toEnumDataPrefix_ENUM__gles_texcombiner_operator_alpha_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operator_alpha_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operator_alpha_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operator_alpha_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operator_alpha_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operator_alpha_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__argument____gles_texcombiner_argument_alpha_type( void* attributeData ){return mImpl->begin__argument____gles_texcombiner_argument_alpha_type(*static_cast<argument____gles_texcombiner_argument_alpha_type__AttributeData*>(attributeData));}
bool _data__argument____gles_texcombiner_argument_alpha_type( const ParserChar* text, size_t textLength );
bool _end__argument____gles_texcombiner_argument_alpha_type(){return mImpl->end__argument____gles_texcombiner_argument_alpha_type();}
bool _preBegin__argument____gles_texcombiner_argument_alpha_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__argument____gles_texcombiner_argument_alpha_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__argument____gles_texcombiner_argument_alpha_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__argument____gles_texcombiner_argument_alpha_type();
#endif
bool _freeAttributes__argument____gles_texcombiner_argument_alpha_type( void* attributeData );


ENUM__gles_texcombiner_operand_alpha_enum toEnumDataPrefix_ENUM__gles_texcombiner_operand_alpha_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operand_alpha_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operand_alpha_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operand_alpha_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texcombiner_operand_alpha_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operand_alpha_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__texenv( void* attributeData ){return mImpl->begin__texenv(*static_cast<texenv__AttributeData*>(attributeData));}
bool _data__texenv( const ParserChar* text, size_t textLength );
bool _end__texenv(){return mImpl->end__texenv();}
bool _preBegin__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__texenv();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texenv();
#endif
bool _freeAttributes__texenv( void* attributeData );


ENUM__gles_texenv_mode_enum toEnumDataPrefix_ENUM__gles_texenv_mode_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texenv_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texenv_mode_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texenv_mode_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texenv_mode_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__gles_texenv_mode_enum*, size_t ),
    const std::pair<StringHash, ENUM__gles_texenv_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texenv_mode_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texenv_mode_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__profile_GLES__technique__pass__states__alpha_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__alpha_test_enable(*static_cast<profile_GLES__technique__pass__states__alpha_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__alpha_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__alpha_test_enable(){return mImpl->end__profile_GLES__technique__pass__states__alpha_test_enable();}
bool _preBegin__profile_GLES__technique__pass__states__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__alpha_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__alpha_test_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__alpha_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__blend_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__blend_enable(*static_cast<profile_GLES__technique__pass__states__blend_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__blend_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__blend_enable(){return mImpl->end__profile_GLES__technique__pass__states__blend_enable();}
bool _preBegin__profile_GLES__technique__pass__states__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__blend_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__blend_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__blend_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__clip_plane_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__clip_plane_enable(*static_cast<profile_GLES__technique__pass__states__clip_plane_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__clip_plane_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__clip_plane_enable(){return mImpl->end__profile_GLES__technique__pass__states__clip_plane_enable();}
bool _preBegin__profile_GLES__technique__pass__states__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__clip_plane_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__clip_plane_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__clip_plane_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__color_logic_op_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__color_logic_op_enable(*static_cast<profile_GLES__technique__pass__states__color_logic_op_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__color_logic_op_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__color_logic_op_enable(){return mImpl->end__profile_GLES__technique__pass__states__color_logic_op_enable();}
bool _preBegin__profile_GLES__technique__pass__states__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__color_logic_op_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__color_logic_op_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__color_logic_op_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__color_material_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__color_material_enable(*static_cast<profile_GLES__technique__pass__states__color_material_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__color_material_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__color_material_enable(){return mImpl->end__profile_GLES__technique__pass__states__color_material_enable();}
bool _preBegin__profile_GLES__technique__pass__states__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__color_material_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__color_material_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__color_material_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__cull_face_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__cull_face_enable(*static_cast<profile_GLES__technique__pass__states__cull_face_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__cull_face_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__cull_face_enable(){return mImpl->end__profile_GLES__technique__pass__states__cull_face_enable();}
bool _preBegin__profile_GLES__technique__pass__states__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__cull_face_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__cull_face_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__cull_face_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__depth_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__depth_test_enable(*static_cast<profile_GLES__technique__pass__states__depth_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__depth_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__depth_test_enable(){return mImpl->end__profile_GLES__technique__pass__states__depth_test_enable();}
bool _preBegin__profile_GLES__technique__pass__states__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__depth_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__depth_test_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__depth_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__dither_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__dither_enable(*static_cast<profile_GLES__technique__pass__states__dither_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__dither_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__dither_enable(){return mImpl->end__profile_GLES__technique__pass__states__dither_enable();}
bool _preBegin__profile_GLES__technique__pass__states__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__dither_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__dither_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__dither_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__fog_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__fog_enable(*static_cast<profile_GLES__technique__pass__states__fog_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__fog_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__fog_enable(){return mImpl->end__profile_GLES__technique__pass__states__fog_enable();}
bool _preBegin__profile_GLES__technique__pass__states__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__fog_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__fog_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__fog_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_enable(*static_cast<profile_GLES__technique__pass__states__light_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_enable(){return mImpl->end__profile_GLES__technique__pass__states__light_enable();}
bool _preBegin__profile_GLES__technique__pass__states__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__lighting_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__lighting_enable(*static_cast<profile_GLES__technique__pass__states__lighting_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__lighting_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__lighting_enable(){return mImpl->end__profile_GLES__technique__pass__states__lighting_enable();}
bool _preBegin__profile_GLES__technique__pass__states__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__lighting_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__lighting_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__lighting_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__light_model_two_side_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__light_model_two_side_enable(*static_cast<profile_GLES__technique__pass__states__light_model_two_side_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__light_model_two_side_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__light_model_two_side_enable(){return mImpl->end__profile_GLES__technique__pass__states__light_model_two_side_enable();}
bool _preBegin__profile_GLES__technique__pass__states__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__light_model_two_side_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__light_model_two_side_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__light_model_two_side_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__line_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__line_smooth_enable(*static_cast<profile_GLES__technique__pass__states__line_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__line_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__line_smooth_enable(){return mImpl->end__profile_GLES__technique__pass__states__line_smooth_enable();}
bool _preBegin__profile_GLES__technique__pass__states__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__line_smooth_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__line_smooth_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__line_smooth_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__multisample_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__multisample_enable(*static_cast<profile_GLES__technique__pass__states__multisample_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__multisample_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__multisample_enable(){return mImpl->end__profile_GLES__technique__pass__states__multisample_enable();}
bool _preBegin__profile_GLES__technique__pass__states__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__multisample_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__multisample_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__multisample_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__normalize_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__normalize_enable(*static_cast<profile_GLES__technique__pass__states__normalize_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__normalize_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__normalize_enable(){return mImpl->end__profile_GLES__technique__pass__states__normalize_enable();}
bool _preBegin__profile_GLES__technique__pass__states__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__normalize_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__normalize_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__normalize_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__point_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__point_smooth_enable(*static_cast<profile_GLES__technique__pass__states__point_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__point_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__point_smooth_enable(){return mImpl->end__profile_GLES__technique__pass__states__point_smooth_enable();}
bool _preBegin__profile_GLES__technique__pass__states__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__point_smooth_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__point_smooth_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__point_smooth_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__polygon_offset_fill_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__polygon_offset_fill_enable(*static_cast<profile_GLES__technique__pass__states__polygon_offset_fill_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__polygon_offset_fill_enable(){return mImpl->end__profile_GLES__technique__pass__states__polygon_offset_fill_enable();}
bool _preBegin__profile_GLES__technique__pass__states__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__polygon_offset_fill_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__polygon_offset_fill_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__polygon_offset_fill_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__rescale_normal_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__rescale_normal_enable(*static_cast<profile_GLES__technique__pass__states__rescale_normal_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__rescale_normal_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__rescale_normal_enable(){return mImpl->end__profile_GLES__technique__pass__states__rescale_normal_enable();}
bool _preBegin__profile_GLES__technique__pass__states__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__rescale_normal_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__rescale_normal_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__rescale_normal_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable(*static_cast<profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable(){return mImpl->end__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable();}
bool _preBegin__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__sample_alpha_to_one_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__sample_alpha_to_one_enable(*static_cast<profile_GLES__technique__pass__states__sample_alpha_to_one_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__sample_alpha_to_one_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__sample_alpha_to_one_enable(){return mImpl->end__profile_GLES__technique__pass__states__sample_alpha_to_one_enable();}
bool _preBegin__profile_GLES__technique__pass__states__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__sample_alpha_to_one_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__sample_alpha_to_one_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__sample_alpha_to_one_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__sample_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__sample_coverage_enable(*static_cast<profile_GLES__technique__pass__states__sample_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__sample_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__sample_coverage_enable(){return mImpl->end__profile_GLES__technique__pass__states__sample_coverage_enable();}
bool _preBegin__profile_GLES__technique__pass__states__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__sample_coverage_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__sample_coverage_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__sample_coverage_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__scissor_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__scissor_test_enable(*static_cast<profile_GLES__technique__pass__states__scissor_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__scissor_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__scissor_test_enable(){return mImpl->end__profile_GLES__technique__pass__states__scissor_test_enable();}
bool _preBegin__profile_GLES__technique__pass__states__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__scissor_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__scissor_test_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__scissor_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__states__stencil_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__states__stencil_test_enable(*static_cast<profile_GLES__technique__pass__states__stencil_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__states__stencil_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__states__stencil_test_enable(){return mImpl->end__profile_GLES__technique__pass__states__stencil_test_enable();}
bool _preBegin__profile_GLES__technique__pass__states__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__states__stencil_test_enable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__states__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__states__stencil_test_enable();
#endif
bool _freeAttributes__profile_GLES__technique__pass__states__stencil_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__evaluate( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__evaluate();}
bool _data__profile_GLES__technique__pass__evaluate( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__evaluate(){return mImpl->end__profile_GLES__technique__pass__evaluate();}
bool _preBegin__profile_GLES__technique__pass__evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__profile_GLES__technique__pass__evaluate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__profile_GLES__technique__pass__evaluate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__evaluate();
#endif
bool _freeAttributes__profile_GLES__technique__pass__evaluate( void* attributeData );

bool _begin__library_force_fields( void* attributeData ){return mImpl->begin__library_force_fields(*static_cast<library_force_fields__AttributeData*>(attributeData));}
bool _data__library_force_fields( const ParserChar* text, size_t textLength );
bool _end__library_force_fields(){return mImpl->end__library_force_fields();}
bool _preBegin__library_force_fields( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_force_fields();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_force_fields( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_force_fields();
#endif
bool _freeAttributes__library_force_fields( void* attributeData );

bool _begin__force_field( void* attributeData ){return mImpl->begin__force_field(*static_cast<force_field__AttributeData*>(attributeData));}
bool _data__force_field( const ParserChar* text, size_t textLength );
bool _end__force_field(){return mImpl->end__force_field();}
bool _preBegin__force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__force_field();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__force_field();
#endif
bool _freeAttributes__force_field( void* attributeData );

bool _begin__library_images( void* attributeData ){return mImpl->begin__library_images(*static_cast<library_images__AttributeData*>(attributeData));}
bool _data__library_images( const ParserChar* text, size_t textLength );
bool _end__library_images(){return mImpl->end__library_images();}
bool _preBegin__library_images( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_images();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_images( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_images();
#endif
bool _freeAttributes__library_images( void* attributeData );

bool _begin__image____image_type( void* attributeData ){return mImpl->begin__image____image_type(*static_cast<image____image_type__AttributeData*>(attributeData));}
bool _data__image____image_type( const ParserChar* text, size_t textLength );
bool _end__image____image_type(){return mImpl->end__image____image_type();}
bool _preBegin__image____image_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__image____image_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__image____image_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__image____image_type();
#endif
bool _freeAttributes__image____image_type( void* attributeData );

bool _begin__renderable( void* attributeData ){return mImpl->begin__renderable(*static_cast<renderable__AttributeData*>(attributeData));}
bool _data__renderable( const ParserChar* text, size_t textLength );
bool _end__renderable(){return mImpl->end__renderable();}
bool _preBegin__renderable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__renderable();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__renderable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__renderable();
#endif
bool _freeAttributes__renderable( void* attributeData );

bool _begin__image_type____init_from( void* attributeData ){return mImpl->begin__image_type____init_from(*static_cast<image_type____init_from__AttributeData*>(attributeData));}
bool _data__image_type____init_from( const ParserChar* text, size_t textLength );
bool _end__image_type____init_from(){return mImpl->end__image_type____init_from();}
bool _preBegin__image_type____init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__image_type____init_from();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__image_type____init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__image_type____init_from();
#endif
bool _freeAttributes__image_type____init_from( void* attributeData );

bool _begin__library_images__image__init_from__hex( void* attributeData ){return mImpl->begin__library_images__image__init_from__hex(*static_cast<library_images__image__init_from__hex__AttributeData*>(attributeData));}
bool _data__library_images__image__init_from__hex( const ParserChar* text, size_t textLength );
bool _end__library_images__image__init_from__hex(){return mImpl->end__library_images__image__init_from__hex();}
bool _preBegin__library_images__image__init_from__hex( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_images__image__init_from__hex();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_images__image__init_from__hex( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_images__image__init_from__hex();
#endif
bool _freeAttributes__library_images__image__init_from__hex( void* attributeData );

bool _begin__create_2d( void* attributeData ){return mImpl->begin__create_2d();}
bool _data__create_2d( const ParserChar* text, size_t textLength );
bool _end__create_2d(){return mImpl->end__create_2d();}
bool _preBegin__create_2d( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_2d();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_2d( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_2d();
#endif
bool _freeAttributes__create_2d( void* attributeData );

bool _begin__size_exact( void* attributeData ){return mImpl->begin__size_exact(*static_cast<size_exact__AttributeData*>(attributeData));}
bool _data__size_exact( const ParserChar* text, size_t textLength );
bool _end__size_exact(){return mImpl->end__size_exact();}
bool _preBegin__size_exact( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__size_exact();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__size_exact( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__size_exact();
#endif
bool _freeAttributes__size_exact( void* attributeData );

bool _begin__size_ratio( void* attributeData ){return mImpl->begin__size_ratio(*static_cast<size_ratio__AttributeData*>(attributeData));}
bool _data__size_ratio( const ParserChar* text, size_t textLength );
bool _end__size_ratio(){return mImpl->end__size_ratio();}
bool _preBegin__size_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__size_ratio();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__size_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__size_ratio();
#endif
bool _freeAttributes__size_ratio( void* attributeData );

bool _begin__mips( void* attributeData ){return mImpl->begin__mips(*static_cast<mips__AttributeData*>(attributeData));}
bool _data__mips( const ParserChar* text, size_t textLength );
bool _end__mips(){return mImpl->end__mips();}
bool _preBegin__mips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mips();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mips();
#endif
bool _freeAttributes__mips( void* attributeData );

bool _begin__unnormalized( void* attributeData ){return mImpl->begin__unnormalized(*static_cast<unnormalized__AttributeData*>(attributeData));}
bool _data__unnormalized( const ParserChar* text, size_t textLength );
bool _end__unnormalized(){return mImpl->end__unnormalized();}
bool _preBegin__unnormalized( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__unnormalized();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__unnormalized( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__unnormalized();
#endif
bool _freeAttributes__unnormalized( void* attributeData );

bool _begin__create_2d__array( void* attributeData ){return mImpl->begin__create_2d__array(*static_cast<create_2d__array__AttributeData*>(attributeData));}
bool _data__create_2d__array( const ParserChar* text, size_t textLength );
bool _end__create_2d__array(){return mImpl->end__create_2d__array();}
bool _preBegin__create_2d__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_2d__array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_2d__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_2d__array();
#endif
bool _freeAttributes__create_2d__array( void* attributeData );

bool _begin__create_2d__format( void* attributeData ){return mImpl->begin__create_2d__format();}
bool _data__create_2d__format( const ParserChar* text, size_t textLength );
bool _end__create_2d__format(){return mImpl->end__create_2d__format();}
bool _preBegin__create_2d__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_2d__format();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_2d__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_2d__format();
#endif
bool _freeAttributes__create_2d__format( void* attributeData );

bool _begin__create_2d__format__hint( void* attributeData ){return mImpl->begin__create_2d__format__hint(*static_cast<create_2d__format__hint__AttributeData*>(attributeData));}
bool _data__create_2d__format__hint( const ParserChar* text, size_t textLength );
bool _end__create_2d__format__hint(){return mImpl->end__create_2d__format__hint();}
bool _preBegin__create_2d__format__hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_2d__format__hint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_2d__format__hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_2d__format__hint();
#endif
bool _freeAttributes__create_2d__format__hint( void* attributeData );


ENUM__image_format_hint_channels_enum toEnumDataPrefix_ENUM__image_format_hint_channels_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__image_format_hint_channels_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_format_hint_channels_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__image_format_hint_channels_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_format_hint_channels_enum*, size_t ),
    const std::pair<StringHash, ENUM__image_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__image_format_hint_channels_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__image_format_hint_channels_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__image_format_hint_range_enum toEnumDataPrefix_ENUM__image_format_hint_range_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__image_format_hint_range_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_format_hint_range_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__image_format_hint_range_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_format_hint_range_enum*, size_t ),
    const std::pair<StringHash, ENUM__image_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__image_format_hint_range_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__image_format_hint_range_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__image_format_hint_precision_enum toEnumDataPrefix_ENUM__image_format_hint_precision_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__image_format_hint_precision_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_format_hint_precision_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__image_format_hint_precision_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__image_format_hint_precision_enum*, size_t ),
    const std::pair<StringHash, ENUM__image_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__image_format_hint_precision_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__image_format_hint_precision_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__exact( void* attributeData ){return mImpl->begin__exact();}
bool _data__exact( const ParserChar* text, size_t textLength );
bool _end__exact(){return mImpl->end__exact();}
bool _preBegin__exact( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__exact();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__exact( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__exact();
#endif
bool _freeAttributes__exact( void* attributeData );

bool _begin__create_2d__init_from( void* attributeData ){return mImpl->begin__create_2d__init_from(*static_cast<create_2d__init_from__AttributeData*>(attributeData));}
bool _data__create_2d__init_from( const ParserChar* text, size_t textLength );
bool _end__create_2d__init_from(){return mImpl->end__create_2d__init_from();}
bool _preBegin__create_2d__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_2d__init_from();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_2d__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_2d__init_from();
#endif
bool _freeAttributes__create_2d__init_from( void* attributeData );

bool _begin__create_3d( void* attributeData ){return mImpl->begin__create_3d();}
bool _data__create_3d( const ParserChar* text, size_t textLength );
bool _end__create_3d(){return mImpl->end__create_3d();}
bool _preBegin__create_3d( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_3d();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_3d( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_3d();
#endif
bool _freeAttributes__create_3d( void* attributeData );

bool _begin__create_3d__size( void* attributeData ){return mImpl->begin__create_3d__size(*static_cast<create_3d__size__AttributeData*>(attributeData));}
bool _data__create_3d__size( const ParserChar* text, size_t textLength );
bool _end__create_3d__size(){return mImpl->end__create_3d__size();}
bool _preBegin__create_3d__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_3d__size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_3d__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_3d__size();
#endif
bool _freeAttributes__create_3d__size( void* attributeData );

bool _begin__create_3d__array( void* attributeData ){return mImpl->begin__create_3d__array(*static_cast<create_3d__array__AttributeData*>(attributeData));}
bool _data__create_3d__array( const ParserChar* text, size_t textLength );
bool _end__create_3d__array(){return mImpl->end__create_3d__array();}
bool _preBegin__create_3d__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_3d__array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_3d__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_3d__array();
#endif
bool _freeAttributes__create_3d__array( void* attributeData );

bool _begin__create_3d__format( void* attributeData ){return mImpl->begin__create_3d__format();}
bool _data__create_3d__format( const ParserChar* text, size_t textLength );
bool _end__create_3d__format(){return mImpl->end__create_3d__format();}
bool _preBegin__create_3d__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_3d__format();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_3d__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_3d__format();
#endif
bool _freeAttributes__create_3d__format( void* attributeData );

bool _begin__create_3d__format__hint( void* attributeData ){return mImpl->begin__create_3d__format__hint(*static_cast<create_3d__format__hint__AttributeData*>(attributeData));}
bool _data__create_3d__format__hint( const ParserChar* text, size_t textLength );
bool _end__create_3d__format__hint(){return mImpl->end__create_3d__format__hint();}
bool _preBegin__create_3d__format__hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_3d__format__hint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_3d__format__hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_3d__format__hint();
#endif
bool _freeAttributes__create_3d__format__hint( void* attributeData );

bool _begin__create_3d__init_from( void* attributeData ){return mImpl->begin__create_3d__init_from(*static_cast<create_3d__init_from__AttributeData*>(attributeData));}
bool _data__create_3d__init_from( const ParserChar* text, size_t textLength );
bool _end__create_3d__init_from(){return mImpl->end__create_3d__init_from();}
bool _preBegin__create_3d__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_3d__init_from();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_3d__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_3d__init_from();
#endif
bool _freeAttributes__create_3d__init_from( void* attributeData );

bool _begin__create_cube( void* attributeData ){return mImpl->begin__create_cube();}
bool _data__create_cube( const ParserChar* text, size_t textLength );
bool _end__create_cube(){return mImpl->end__create_cube();}
bool _preBegin__create_cube( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_cube();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_cube( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_cube();
#endif
bool _freeAttributes__create_cube( void* attributeData );

bool _begin__create_cube__size( void* attributeData ){return mImpl->begin__create_cube__size(*static_cast<create_cube__size__AttributeData*>(attributeData));}
bool _data__create_cube__size( const ParserChar* text, size_t textLength );
bool _end__create_cube__size(){return mImpl->end__create_cube__size();}
bool _preBegin__create_cube__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_cube__size();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_cube__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_cube__size();
#endif
bool _freeAttributes__create_cube__size( void* attributeData );

bool _begin__create_cube__array( void* attributeData ){return mImpl->begin__create_cube__array(*static_cast<create_cube__array__AttributeData*>(attributeData));}
bool _data__create_cube__array( const ParserChar* text, size_t textLength );
bool _end__create_cube__array(){return mImpl->end__create_cube__array();}
bool _preBegin__create_cube__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_cube__array();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_cube__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_cube__array();
#endif
bool _freeAttributes__create_cube__array( void* attributeData );

bool _begin__create_cube__format( void* attributeData ){return mImpl->begin__create_cube__format();}
bool _data__create_cube__format( const ParserChar* text, size_t textLength );
bool _end__create_cube__format(){return mImpl->end__create_cube__format();}
bool _preBegin__create_cube__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_cube__format();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_cube__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_cube__format();
#endif
bool _freeAttributes__create_cube__format( void* attributeData );

bool _begin__create_cube__format__hint( void* attributeData ){return mImpl->begin__create_cube__format__hint(*static_cast<create_cube__format__hint__AttributeData*>(attributeData));}
bool _data__create_cube__format__hint( const ParserChar* text, size_t textLength );
bool _end__create_cube__format__hint(){return mImpl->end__create_cube__format__hint();}
bool _preBegin__create_cube__format__hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_cube__format__hint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_cube__format__hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_cube__format__hint();
#endif
bool _freeAttributes__create_cube__format__hint( void* attributeData );

bool _begin__create_cube__init_from( void* attributeData ){return mImpl->begin__create_cube__init_from(*static_cast<create_cube__init_from__AttributeData*>(attributeData));}
bool _data__create_cube__init_from( const ParserChar* text, size_t textLength );
bool _end__create_cube__init_from(){return mImpl->end__create_cube__init_from();}
bool _preBegin__create_cube__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__create_cube__init_from();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__create_cube__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__create_cube__init_from();
#endif
bool _freeAttributes__create_cube__init_from( void* attributeData );

bool _begin__library_lights( void* attributeData ){return mImpl->begin__library_lights(*static_cast<library_lights__AttributeData*>(attributeData));}
bool _data__library_lights( const ParserChar* text, size_t textLength );
bool _end__library_lights(){return mImpl->end__library_lights();}
bool _preBegin__library_lights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_lights();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_lights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_lights();
#endif
bool _freeAttributes__library_lights( void* attributeData );

bool _begin__light( void* attributeData ){return mImpl->begin__light(*static_cast<light__AttributeData*>(attributeData));}
bool _data__light( const ParserChar* text, size_t textLength );
bool _end__light(){return mImpl->end__light();}
bool _preBegin__light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__light();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light();
#endif
bool _freeAttributes__light( void* attributeData );

bool _begin__light_type____technique_common( void* attributeData ){return mImpl->begin__light_type____technique_common();}
bool _data__light_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__light_type____technique_common(){return mImpl->end__light_type____technique_common();}
bool _preBegin__light_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__light_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__light_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_type____technique_common();
#endif
bool _freeAttributes__light_type____technique_common( void* attributeData );

bool _begin__light__technique_common__ambient( void* attributeData ){return mImpl->begin__light__technique_common__ambient();}
bool _data__light__technique_common__ambient( const ParserChar* text, size_t textLength );
bool _end__light__technique_common__ambient(){return mImpl->end__light__technique_common__ambient();}
bool _preBegin__light__technique_common__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__light__technique_common__ambient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__light__technique_common__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light__technique_common__ambient();
#endif
bool _freeAttributes__light__technique_common__ambient( void* attributeData );

bool _begin__color____targetable_float3_type( void* attributeData ){return mImpl->begin__color____targetable_float3_type(*static_cast<color____targetable_float3_type__AttributeData*>(attributeData));}
bool _data__color____targetable_float3_type( const ParserChar* text, size_t textLength );
bool _end__color____targetable_float3_type(){return mImpl->end__color____targetable_float3_type();}
bool _preBegin__color____targetable_float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__color____targetable_float3_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__color____targetable_float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color____targetable_float3_type();
#endif
bool _freeAttributes__color____targetable_float3_type( void* attributeData );

bool _begin__directional( void* attributeData ){return mImpl->begin__directional();}
bool _data__directional( const ParserChar* text, size_t textLength );
bool _end__directional(){return mImpl->end__directional();}
bool _preBegin__directional( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__directional();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__directional( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__directional();
#endif
bool _freeAttributes__directional( void* attributeData );

bool _begin__point( void* attributeData ){return mImpl->begin__point();}
bool _data__point( const ParserChar* text, size_t textLength );
bool _end__point(){return mImpl->end__point();}
bool _preBegin__point( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__point();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__point( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__point();
#endif
bool _freeAttributes__point( void* attributeData );

bool _begin__constant_attenuation( void* attributeData ){return mImpl->begin__constant_attenuation(*static_cast<constant_attenuation__AttributeData*>(attributeData));}
bool _data__constant_attenuation( const ParserChar* text, size_t textLength );
bool _end__constant_attenuation(){return mImpl->end__constant_attenuation();}
bool _preBegin__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__constant_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__constant_attenuation();
#endif
bool _freeAttributes__constant_attenuation( void* attributeData );

bool _begin__linear_attenuation( void* attributeData ){return mImpl->begin__linear_attenuation(*static_cast<linear_attenuation__AttributeData*>(attributeData));}
bool _data__linear_attenuation( const ParserChar* text, size_t textLength );
bool _end__linear_attenuation(){return mImpl->end__linear_attenuation();}
bool _preBegin__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__linear_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__linear_attenuation();
#endif
bool _freeAttributes__linear_attenuation( void* attributeData );

bool _begin__quadratic_attenuation( void* attributeData ){return mImpl->begin__quadratic_attenuation(*static_cast<quadratic_attenuation__AttributeData*>(attributeData));}
bool _data__quadratic_attenuation( const ParserChar* text, size_t textLength );
bool _end__quadratic_attenuation(){return mImpl->end__quadratic_attenuation();}
bool _preBegin__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__quadratic_attenuation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__quadratic_attenuation();
#endif
bool _freeAttributes__quadratic_attenuation( void* attributeData );

bool _begin__spot( void* attributeData ){return mImpl->begin__spot();}
bool _data__spot( const ParserChar* text, size_t textLength );
bool _end__spot(){return mImpl->end__spot();}
bool _preBegin__spot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__spot();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__spot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spot();
#endif
bool _freeAttributes__spot( void* attributeData );

bool _begin__falloff_angle( void* attributeData ){return mImpl->begin__falloff_angle(*static_cast<falloff_angle__AttributeData*>(attributeData));}
bool _data__falloff_angle( const ParserChar* text, size_t textLength );
bool _end__falloff_angle(){return mImpl->end__falloff_angle();}
bool _preBegin__falloff_angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__falloff_angle();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__falloff_angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__falloff_angle();
#endif
bool _freeAttributes__falloff_angle( void* attributeData );

bool _begin__falloff_exponent( void* attributeData ){return mImpl->begin__falloff_exponent(*static_cast<falloff_exponent__AttributeData*>(attributeData));}
bool _data__falloff_exponent( const ParserChar* text, size_t textLength );
bool _end__falloff_exponent(){return mImpl->end__falloff_exponent();}
bool _preBegin__falloff_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__falloff_exponent();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__falloff_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__falloff_exponent();
#endif
bool _freeAttributes__falloff_exponent( void* attributeData );

bool _begin__library_materials( void* attributeData ){return mImpl->begin__library_materials(*static_cast<library_materials__AttributeData*>(attributeData));}
bool _data__library_materials( const ParserChar* text, size_t textLength );
bool _end__library_materials(){return mImpl->end__library_materials();}
bool _preBegin__library_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_materials();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_materials();
#endif
bool _freeAttributes__library_materials( void* attributeData );

bool _begin__material( void* attributeData ){return mImpl->begin__material(*static_cast<material__AttributeData*>(attributeData));}
bool _data__material( const ParserChar* text, size_t textLength );
bool _end__material(){return mImpl->end__material();}
bool _preBegin__material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__material();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__material();
#endif
bool _freeAttributes__material( void* attributeData );

bool _begin__instance_effect( void* attributeData ){return mImpl->begin__instance_effect(*static_cast<instance_effect__AttributeData*>(attributeData));}
bool _data__instance_effect( const ParserChar* text, size_t textLength );
bool _end__instance_effect(){return mImpl->end__instance_effect();}
bool _preBegin__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_effect();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_effect();
#endif
bool _freeAttributes__instance_effect( void* attributeData );

bool _begin__technique_hint( void* attributeData ){return mImpl->begin__technique_hint(*static_cast<technique_hint__AttributeData*>(attributeData));}
bool _data__technique_hint( const ParserChar* text, size_t textLength );
bool _end__technique_hint(){return mImpl->end__technique_hint();}
bool _preBegin__technique_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique_hint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_hint();
#endif
bool _freeAttributes__technique_hint( void* attributeData );

bool _begin__instance_effect_type____setparam( void* attributeData ){return mImpl->begin__instance_effect_type____setparam(*static_cast<instance_effect_type____setparam__AttributeData*>(attributeData));}
bool _data__instance_effect_type____setparam( const ParserChar* text, size_t textLength );
bool _end__instance_effect_type____setparam(){return mImpl->end__instance_effect_type____setparam();}
bool _preBegin__instance_effect_type____setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_effect_type____setparam();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_effect_type____setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_effect_type____setparam();
#endif
bool _freeAttributes__instance_effect_type____setparam( void* attributeData );

bool _begin__sampler_image( void* attributeData ){return mImpl->begin__sampler_image(*static_cast<sampler_image__AttributeData*>(attributeData));}
bool _data__sampler_image( const ParserChar* text, size_t textLength );
bool _end__sampler_image(){return mImpl->end__sampler_image();}
bool _preBegin__sampler_image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler_image();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler_image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler_image();
#endif
bool _freeAttributes__sampler_image( void* attributeData );

bool _begin__sampler_states( void* attributeData ){return mImpl->begin__sampler_states();}
bool _data__sampler_states( const ParserChar* text, size_t textLength );
bool _end__sampler_states(){return mImpl->end__sampler_states();}
bool _preBegin__sampler_states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sampler_states();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sampler_states( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler_states();
#endif
bool _freeAttributes__sampler_states( void* attributeData );

bool _begin__library_nodes( void* attributeData ){return mImpl->begin__library_nodes(*static_cast<library_nodes__AttributeData*>(attributeData));}
bool _data__library_nodes( const ParserChar* text, size_t textLength );
bool _end__library_nodes(){return mImpl->end__library_nodes();}
bool _preBegin__library_nodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_nodes();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_nodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_nodes();
#endif
bool _freeAttributes__library_nodes( void* attributeData );

bool _begin__node( void* attributeData ){return mImpl->begin__node(*static_cast<node__AttributeData*>(attributeData));}
bool _data__node( const ParserChar* text, size_t textLength );
bool _end__node(){return mImpl->end__node();}
bool _preBegin__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__node();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__node();
#endif
bool _freeAttributes__node( void* attributeData );


ENUM__node_enum toEnumDataPrefix_ENUM__node_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__node_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__node_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__node_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__node_enum (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__node_enum*, size_t ),
    const std::pair<StringHash, ENUM__node_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__node_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__node_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__lookat( void* attributeData ){return mImpl->begin__lookat(*static_cast<lookat__AttributeData*>(attributeData));}
bool _data__lookat( const ParserChar* text, size_t textLength );
bool _end__lookat(){return mImpl->end__lookat();}
bool _preBegin__lookat( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lookat();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lookat( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lookat();
#endif
bool _freeAttributes__lookat( void* attributeData );

bool _begin__matrix____matrix_type( void* attributeData ){return mImpl->begin__matrix____matrix_type(*static_cast<matrix____matrix_type__AttributeData*>(attributeData));}
bool _data__matrix____matrix_type( const ParserChar* text, size_t textLength );
bool _end__matrix____matrix_type(){return mImpl->end__matrix____matrix_type();}
bool _preBegin__matrix____matrix_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__matrix____matrix_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__matrix____matrix_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__matrix____matrix_type();
#endif
bool _freeAttributes__matrix____matrix_type( void* attributeData );

bool _begin__rotate( void* attributeData ){return mImpl->begin__rotate(*static_cast<rotate__AttributeData*>(attributeData));}
bool _data__rotate( const ParserChar* text, size_t textLength );
bool _end__rotate(){return mImpl->end__rotate();}
bool _preBegin__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rotate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rotate();
#endif
bool _freeAttributes__rotate( void* attributeData );

bool _begin__scale( void* attributeData ){return mImpl->begin__scale(*static_cast<scale__AttributeData*>(attributeData));}
bool _data__scale( const ParserChar* text, size_t textLength );
bool _end__scale(){return mImpl->end__scale();}
bool _preBegin__scale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__scale();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__scale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__scale();
#endif
bool _freeAttributes__scale( void* attributeData );

bool _begin__skew( void* attributeData ){return mImpl->begin__skew(*static_cast<skew__AttributeData*>(attributeData));}
bool _data__skew( const ParserChar* text, size_t textLength );
bool _end__skew(){return mImpl->end__skew();}
bool _preBegin__skew( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__skew();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__skew( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__skew();
#endif
bool _freeAttributes__skew( void* attributeData );

bool _begin__translate( void* attributeData ){return mImpl->begin__translate(*static_cast<translate__AttributeData*>(attributeData));}
bool _data__translate( const ParserChar* text, size_t textLength );
bool _end__translate(){return mImpl->end__translate();}
bool _preBegin__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__translate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__translate();
#endif
bool _freeAttributes__translate( void* attributeData );

bool _begin__instance_camera( void* attributeData ){return mImpl->begin__instance_camera(*static_cast<instance_camera__AttributeData*>(attributeData));}
bool _data__instance_camera( const ParserChar* text, size_t textLength );
bool _end__instance_camera(){return mImpl->end__instance_camera();}
bool _preBegin__instance_camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_camera();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_camera();
#endif
bool _freeAttributes__instance_camera( void* attributeData );

bool _begin__instance_controller( void* attributeData ){return mImpl->begin__instance_controller(*static_cast<instance_controller__AttributeData*>(attributeData));}
bool _data__instance_controller( const ParserChar* text, size_t textLength );
bool _end__instance_controller(){return mImpl->end__instance_controller();}
bool _preBegin__instance_controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_controller();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_controller();
#endif
bool _freeAttributes__instance_controller( void* attributeData );

bool _begin__skeleton( void* attributeData ){return mImpl->begin__skeleton();}
bool _data__skeleton( const ParserChar* text, size_t textLength );
bool _end__skeleton(){return mImpl->end__skeleton();}
bool _preBegin__skeleton( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__skeleton();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__skeleton( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__skeleton();
#endif
bool _freeAttributes__skeleton( void* attributeData );

bool _begin__bind_material( void* attributeData ){return mImpl->begin__bind_material();}
bool _data__bind_material( const ParserChar* text, size_t textLength );
bool _end__bind_material(){return mImpl->end__bind_material();}
bool _preBegin__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind_material();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_material();
#endif
bool _freeAttributes__bind_material( void* attributeData );

bool _begin__bind_material_type____technique_common( void* attributeData ){return mImpl->begin__bind_material_type____technique_common();}
bool _data__bind_material_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__bind_material_type____technique_common(){return mImpl->end__bind_material_type____technique_common();}
bool _preBegin__bind_material_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind_material_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind_material_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_material_type____technique_common();
#endif
bool _freeAttributes__bind_material_type____technique_common( void* attributeData );

bool _begin__instance_material____instance_material_type( void* attributeData ){return mImpl->begin__instance_material____instance_material_type(*static_cast<instance_material____instance_material_type__AttributeData*>(attributeData));}
bool _data__instance_material____instance_material_type( const ParserChar* text, size_t textLength );
bool _end__instance_material____instance_material_type(){return mImpl->end__instance_material____instance_material_type();}
bool _preBegin__instance_material____instance_material_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_material____instance_material_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_material____instance_material_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_material____instance_material_type();
#endif
bool _freeAttributes__instance_material____instance_material_type( void* attributeData );

bool _begin__instance_material_type____bind( void* attributeData ){return mImpl->begin__instance_material_type____bind(*static_cast<instance_material_type____bind__AttributeData*>(attributeData));}
bool _data__instance_material_type____bind( const ParserChar* text, size_t textLength );
bool _end__instance_material_type____bind(){return mImpl->end__instance_material_type____bind();}
bool _preBegin__instance_material_type____bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_material_type____bind();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_material_type____bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_material_type____bind();
#endif
bool _freeAttributes__instance_material_type____bind( void* attributeData );

bool _begin__bind_vertex_input( void* attributeData ){return mImpl->begin__bind_vertex_input(*static_cast<bind_vertex_input__AttributeData*>(attributeData));}
bool _data__bind_vertex_input( const ParserChar* text, size_t textLength );
bool _end__bind_vertex_input(){return mImpl->end__bind_vertex_input();}
bool _preBegin__bind_vertex_input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind_vertex_input();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind_vertex_input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_vertex_input();
#endif
bool _freeAttributes__bind_vertex_input( void* attributeData );

bool _begin__instance_geometry( void* attributeData ){return mImpl->begin__instance_geometry(*static_cast<instance_geometry__AttributeData*>(attributeData));}
bool _data__instance_geometry( const ParserChar* text, size_t textLength );
bool _end__instance_geometry(){return mImpl->end__instance_geometry();}
bool _preBegin__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_geometry();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_geometry();
#endif
bool _freeAttributes__instance_geometry( void* attributeData );

bool _begin__instance_light( void* attributeData ){return mImpl->begin__instance_light(*static_cast<instance_light__AttributeData*>(attributeData));}
bool _data__instance_light( const ParserChar* text, size_t textLength );
bool _end__instance_light(){return mImpl->end__instance_light();}
bool _preBegin__instance_light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_light();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_light();
#endif
bool _freeAttributes__instance_light( void* attributeData );

bool _begin__instance_node( void* attributeData ){return mImpl->begin__instance_node(*static_cast<instance_node__AttributeData*>(attributeData));}
bool _data__instance_node( const ParserChar* text, size_t textLength );
bool _end__instance_node(){return mImpl->end__instance_node();}
bool _preBegin__instance_node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_node();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_node();
#endif
bool _freeAttributes__instance_node( void* attributeData );

bool _begin__library_physics_materials( void* attributeData ){return mImpl->begin__library_physics_materials(*static_cast<library_physics_materials__AttributeData*>(attributeData));}
bool _data__library_physics_materials( const ParserChar* text, size_t textLength );
bool _end__library_physics_materials(){return mImpl->end__library_physics_materials();}
bool _preBegin__library_physics_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_physics_materials();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_physics_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_physics_materials();
#endif
bool _freeAttributes__library_physics_materials( void* attributeData );

bool _begin__physics_material( void* attributeData ){return mImpl->begin__physics_material(*static_cast<physics_material__AttributeData*>(attributeData));}
bool _data__physics_material( const ParserChar* text, size_t textLength );
bool _end__physics_material(){return mImpl->end__physics_material();}
bool _preBegin__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__physics_material();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_material();
#endif
bool _freeAttributes__physics_material( void* attributeData );

bool _begin__physics_material_type____technique_common( void* attributeData ){return mImpl->begin__physics_material_type____technique_common();}
bool _data__physics_material_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__physics_material_type____technique_common(){return mImpl->end__physics_material_type____technique_common();}
bool _preBegin__physics_material_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__physics_material_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__physics_material_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_material_type____technique_common();
#endif
bool _freeAttributes__physics_material_type____technique_common( void* attributeData );

bool _begin__dynamic_friction( void* attributeData ){return mImpl->begin__dynamic_friction(*static_cast<dynamic_friction__AttributeData*>(attributeData));}
bool _data__dynamic_friction( const ParserChar* text, size_t textLength );
bool _end__dynamic_friction(){return mImpl->end__dynamic_friction();}
bool _preBegin__dynamic_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__dynamic_friction();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__dynamic_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__dynamic_friction();
#endif
bool _freeAttributes__dynamic_friction( void* attributeData );

bool _begin__restitution( void* attributeData ){return mImpl->begin__restitution(*static_cast<restitution__AttributeData*>(attributeData));}
bool _data__restitution( const ParserChar* text, size_t textLength );
bool _end__restitution(){return mImpl->end__restitution();}
bool _preBegin__restitution( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__restitution();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__restitution( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__restitution();
#endif
bool _freeAttributes__restitution( void* attributeData );

bool _begin__static_friction( void* attributeData ){return mImpl->begin__static_friction(*static_cast<static_friction__AttributeData*>(attributeData));}
bool _data__static_friction( const ParserChar* text, size_t textLength );
bool _end__static_friction(){return mImpl->end__static_friction();}
bool _preBegin__static_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__static_friction();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__static_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__static_friction();
#endif
bool _freeAttributes__static_friction( void* attributeData );

bool _begin__library_physics_models( void* attributeData ){return mImpl->begin__library_physics_models(*static_cast<library_physics_models__AttributeData*>(attributeData));}
bool _data__library_physics_models( const ParserChar* text, size_t textLength );
bool _end__library_physics_models(){return mImpl->end__library_physics_models();}
bool _preBegin__library_physics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_physics_models();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_physics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_physics_models();
#endif
bool _freeAttributes__library_physics_models( void* attributeData );

bool _begin__physics_model( void* attributeData ){return mImpl->begin__physics_model(*static_cast<physics_model__AttributeData*>(attributeData));}
bool _data__physics_model( const ParserChar* text, size_t textLength );
bool _end__physics_model(){return mImpl->end__physics_model();}
bool _preBegin__physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__physics_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_model();
#endif
bool _freeAttributes__physics_model( void* attributeData );

bool _begin__rigid_body( void* attributeData ){return mImpl->begin__rigid_body(*static_cast<rigid_body__AttributeData*>(attributeData));}
bool _data__rigid_body( const ParserChar* text, size_t textLength );
bool _end__rigid_body(){return mImpl->end__rigid_body();}
bool _preBegin__rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_body();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body();
#endif
bool _freeAttributes__rigid_body( void* attributeData );

bool _begin__rigid_body_type____technique_common( void* attributeData ){return mImpl->begin__rigid_body_type____technique_common();}
bool _data__rigid_body_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__rigid_body_type____technique_common(){return mImpl->end__rigid_body_type____technique_common();}
bool _preBegin__rigid_body_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_body_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_body_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body_type____technique_common();
#endif
bool _freeAttributes__rigid_body_type____technique_common( void* attributeData );

bool _begin__rigid_body__technique_common__dynamic( void* attributeData ){return mImpl->begin__rigid_body__technique_common__dynamic(*static_cast<rigid_body__technique_common__dynamic__AttributeData*>(attributeData));}
bool _data__rigid_body__technique_common__dynamic( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__dynamic(){return mImpl->end__rigid_body__technique_common__dynamic();}
bool _preBegin__rigid_body__technique_common__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_body__technique_common__dynamic();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_body__technique_common__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__dynamic();
#endif
bool _freeAttributes__rigid_body__technique_common__dynamic( void* attributeData );

bool _begin__mass( void* attributeData ){return mImpl->begin__mass(*static_cast<mass__AttributeData*>(attributeData));}
bool _data__mass( const ParserChar* text, size_t textLength );
bool _end__mass(){return mImpl->end__mass();}
bool _preBegin__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mass();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mass();
#endif
bool _freeAttributes__mass( void* attributeData );

bool _begin__rigid_body__technique_common__mass_frame( void* attributeData ){return mImpl->begin__rigid_body__technique_common__mass_frame();}
bool _data__rigid_body__technique_common__mass_frame( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__mass_frame(){return mImpl->end__rigid_body__technique_common__mass_frame();}
bool _preBegin__rigid_body__technique_common__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_body__technique_common__mass_frame();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_body__technique_common__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__mass_frame();
#endif
bool _freeAttributes__rigid_body__technique_common__mass_frame( void* attributeData );

bool _begin__inertia( void* attributeData ){return mImpl->begin__inertia(*static_cast<inertia__AttributeData*>(attributeData));}
bool _data__inertia( const ParserChar* text, size_t textLength );
bool _end__inertia(){return mImpl->end__inertia();}
bool _preBegin__inertia( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__inertia();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__inertia( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__inertia();
#endif
bool _freeAttributes__inertia( void* attributeData );

bool _begin__instance_physics_material( void* attributeData ){return mImpl->begin__instance_physics_material(*static_cast<instance_physics_material__AttributeData*>(attributeData));}
bool _data__instance_physics_material( const ParserChar* text, size_t textLength );
bool _end__instance_physics_material(){return mImpl->end__instance_physics_material();}
bool _preBegin__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_physics_material();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_physics_material();
#endif
bool _freeAttributes__instance_physics_material( void* attributeData );

bool _begin__rigid_body__technique_common__shape( void* attributeData ){return mImpl->begin__rigid_body__technique_common__shape();}
bool _data__rigid_body__technique_common__shape( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__shape(){return mImpl->end__rigid_body__technique_common__shape();}
bool _preBegin__rigid_body__technique_common__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_body__technique_common__shape();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_body__technique_common__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__shape();
#endif
bool _freeAttributes__rigid_body__technique_common__shape( void* attributeData );

bool _begin__rigid_body__technique_common__shape__hollow( void* attributeData ){return mImpl->begin__rigid_body__technique_common__shape__hollow(*static_cast<rigid_body__technique_common__shape__hollow__AttributeData*>(attributeData));}
bool _data__rigid_body__technique_common__shape__hollow( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__shape__hollow(){return mImpl->end__rigid_body__technique_common__shape__hollow();}
bool _preBegin__rigid_body__technique_common__shape__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_body__technique_common__shape__hollow();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_body__technique_common__shape__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__shape__hollow();
#endif
bool _freeAttributes__rigid_body__technique_common__shape__hollow( void* attributeData );

bool _begin__density( void* attributeData ){return mImpl->begin__density(*static_cast<density__AttributeData*>(attributeData));}
bool _data__density( const ParserChar* text, size_t textLength );
bool _end__density(){return mImpl->end__density();}
bool _preBegin__density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__density();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__density();
#endif
bool _freeAttributes__density( void* attributeData );

bool _begin__box( void* attributeData ){return mImpl->begin__box();}
bool _data__box( const ParserChar* text, size_t textLength );
bool _end__box(){return mImpl->end__box();}
bool _preBegin__box( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__box();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__box( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__box();
#endif
bool _freeAttributes__box( void* attributeData );

bool _begin__half_extents( void* attributeData ){return mImpl->begin__half_extents();}
bool _data__half_extents( const ParserChar* text, size_t textLength );
bool _end__half_extents(){return mImpl->end__half_extents();}
bool _preBegin__half_extents( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__half_extents();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__half_extents( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half_extents();
#endif
bool _freeAttributes__half_extents( void* attributeData );

bool _begin__cylinder____cylinder_type( void* attributeData ){return mImpl->begin__cylinder____cylinder_type();}
bool _data__cylinder____cylinder_type( const ParserChar* text, size_t textLength );
bool _end__cylinder____cylinder_type(){return mImpl->end__cylinder____cylinder_type();}
bool _preBegin__cylinder____cylinder_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cylinder____cylinder_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cylinder____cylinder_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cylinder____cylinder_type();
#endif
bool _freeAttributes__cylinder____cylinder_type( void* attributeData );

bool _begin__height( void* attributeData ){return mImpl->begin__height();}
bool _data__height( const ParserChar* text, size_t textLength );
bool _end__height(){return mImpl->end__height();}
bool _preBegin__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__height();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__height();
#endif
bool _freeAttributes__height( void* attributeData );

bool _begin__capsule( void* attributeData ){return mImpl->begin__capsule();}
bool _data__capsule( const ParserChar* text, size_t textLength );
bool _end__capsule(){return mImpl->end__capsule();}
bool _preBegin__capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__capsule();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__capsule();
#endif
bool _freeAttributes__capsule( void* attributeData );

bool _begin__radius____float3_type( void* attributeData ){return mImpl->begin__radius____float3_type();}
bool _data__radius____float3_type( const ParserChar* text, size_t textLength );
bool _end__radius____float3_type(){return mImpl->end__radius____float3_type();}
bool _preBegin__radius____float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__radius____float3_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__radius____float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius____float3_type();
#endif
bool _freeAttributes__radius____float3_type( void* attributeData );

bool _begin__rigid_constraint( void* attributeData ){return mImpl->begin__rigid_constraint(*static_cast<rigid_constraint__AttributeData*>(attributeData));}
bool _data__rigid_constraint( const ParserChar* text, size_t textLength );
bool _end__rigid_constraint(){return mImpl->end__rigid_constraint();}
bool _preBegin__rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_constraint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_constraint();
#endif
bool _freeAttributes__rigid_constraint( void* attributeData );

bool _begin__ref_attachment( void* attributeData ){return mImpl->begin__ref_attachment(*static_cast<ref_attachment__AttributeData*>(attributeData));}
bool _data__ref_attachment( const ParserChar* text, size_t textLength );
bool _end__ref_attachment(){return mImpl->end__ref_attachment();}
bool _preBegin__ref_attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ref_attachment();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ref_attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ref_attachment();
#endif
bool _freeAttributes__ref_attachment( void* attributeData );

bool _begin__attachment( void* attributeData ){return mImpl->begin__attachment(*static_cast<attachment__AttributeData*>(attributeData));}
bool _data__attachment( const ParserChar* text, size_t textLength );
bool _end__attachment(){return mImpl->end__attachment();}
bool _preBegin__attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__attachment();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__attachment();
#endif
bool _freeAttributes__attachment( void* attributeData );

bool _begin__rigid_constraint_type____technique_common( void* attributeData ){return mImpl->begin__rigid_constraint_type____technique_common();}
bool _data__rigid_constraint_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__rigid_constraint_type____technique_common(){return mImpl->end__rigid_constraint_type____technique_common();}
bool _preBegin__rigid_constraint_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_constraint_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_constraint_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_constraint_type____technique_common();
#endif
bool _freeAttributes__rigid_constraint_type____technique_common( void* attributeData );

bool _begin__enabled( void* attributeData ){return mImpl->begin__enabled(*static_cast<enabled__AttributeData*>(attributeData));}
bool _data__enabled( const ParserChar* text, size_t textLength );
bool _end__enabled(){return mImpl->end__enabled();}
bool _preBegin__enabled( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__enabled();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__enabled( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enabled();
#endif
bool _freeAttributes__enabled( void* attributeData );

bool _begin__interpenetrate( void* attributeData ){return mImpl->begin__interpenetrate(*static_cast<interpenetrate__AttributeData*>(attributeData));}
bool _data__interpenetrate( const ParserChar* text, size_t textLength );
bool _end__interpenetrate(){return mImpl->end__interpenetrate();}
bool _preBegin__interpenetrate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__interpenetrate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__interpenetrate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__interpenetrate();
#endif
bool _freeAttributes__interpenetrate( void* attributeData );

bool _begin__rigid_constraint__technique_common__limits( void* attributeData ){return mImpl->begin__rigid_constraint__technique_common__limits();}
bool _data__rigid_constraint__technique_common__limits( const ParserChar* text, size_t textLength );
bool _end__rigid_constraint__technique_common__limits(){return mImpl->end__rigid_constraint__technique_common__limits();}
bool _preBegin__rigid_constraint__technique_common__limits( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_constraint__technique_common__limits();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_constraint__technique_common__limits( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_constraint__technique_common__limits();
#endif
bool _freeAttributes__rigid_constraint__technique_common__limits( void* attributeData );

bool _begin__swing_cone_and_twist( void* attributeData ){return mImpl->begin__swing_cone_and_twist();}
bool _data__swing_cone_and_twist( const ParserChar* text, size_t textLength );
bool _end__swing_cone_and_twist(){return mImpl->end__swing_cone_and_twist();}
bool _preBegin__swing_cone_and_twist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__swing_cone_and_twist();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__swing_cone_and_twist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__swing_cone_and_twist();
#endif
bool _freeAttributes__swing_cone_and_twist( void* attributeData );

bool _begin__min____targetable_float3_type( void* attributeData ){return mImpl->begin__min____targetable_float3_type(*static_cast<min____targetable_float3_type__AttributeData*>(attributeData));}
bool _data__min____targetable_float3_type( const ParserChar* text, size_t textLength );
bool _end__min____targetable_float3_type(){return mImpl->end__min____targetable_float3_type();}
bool _preBegin__min____targetable_float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__min____targetable_float3_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__min____targetable_float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__min____targetable_float3_type();
#endif
bool _freeAttributes__min____targetable_float3_type( void* attributeData );

bool _begin__max____targetable_float3_type( void* attributeData ){return mImpl->begin__max____targetable_float3_type(*static_cast<max____targetable_float3_type__AttributeData*>(attributeData));}
bool _data__max____targetable_float3_type( const ParserChar* text, size_t textLength );
bool _end__max____targetable_float3_type(){return mImpl->end__max____targetable_float3_type();}
bool _preBegin__max____targetable_float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__max____targetable_float3_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__max____targetable_float3_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__max____targetable_float3_type();
#endif
bool _freeAttributes__max____targetable_float3_type( void* attributeData );

bool _begin__rigid_constraint__technique_common__limits__linear( void* attributeData ){return mImpl->begin__rigid_constraint__technique_common__limits__linear();}
bool _data__rigid_constraint__technique_common__limits__linear( const ParserChar* text, size_t textLength );
bool _end__rigid_constraint__technique_common__limits__linear(){return mImpl->end__rigid_constraint__technique_common__limits__linear();}
bool _preBegin__rigid_constraint__technique_common__limits__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rigid_constraint__technique_common__limits__linear();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rigid_constraint__technique_common__limits__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_constraint__technique_common__limits__linear();
#endif
bool _freeAttributes__rigid_constraint__technique_common__limits__linear( void* attributeData );

bool _begin__spring( void* attributeData ){return mImpl->begin__spring();}
bool _data__spring( const ParserChar* text, size_t textLength );
bool _end__spring(){return mImpl->end__spring();}
bool _preBegin__spring( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__spring();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__spring( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spring();
#endif
bool _freeAttributes__spring( void* attributeData );

bool _begin__angular( void* attributeData ){return mImpl->begin__angular();}
bool _data__angular( const ParserChar* text, size_t textLength );
bool _end__angular(){return mImpl->end__angular();}
bool _preBegin__angular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__angular();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__angular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__angular();
#endif
bool _freeAttributes__angular( void* attributeData );

bool _begin__stiffness( void* attributeData ){return mImpl->begin__stiffness(*static_cast<stiffness__AttributeData*>(attributeData));}
bool _data__stiffness( const ParserChar* text, size_t textLength );
bool _end__stiffness(){return mImpl->end__stiffness();}
bool _preBegin__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__stiffness();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stiffness();
#endif
bool _freeAttributes__stiffness( void* attributeData );

bool _begin__damping( void* attributeData ){return mImpl->begin__damping(*static_cast<damping__AttributeData*>(attributeData));}
bool _data__damping( const ParserChar* text, size_t textLength );
bool _end__damping(){return mImpl->end__damping();}
bool _preBegin__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__damping();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__damping();
#endif
bool _freeAttributes__damping( void* attributeData );

bool _begin__target_value( void* attributeData ){return mImpl->begin__target_value(*static_cast<target_value__AttributeData*>(attributeData));}
bool _data__target_value( const ParserChar* text, size_t textLength );
bool _end__target_value(){return mImpl->end__target_value();}
bool _preBegin__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__target_value();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__target_value();
#endif
bool _freeAttributes__target_value( void* attributeData );

bool _begin__spring__linear( void* attributeData ){return mImpl->begin__spring__linear();}
bool _data__spring__linear( const ParserChar* text, size_t textLength );
bool _end__spring__linear(){return mImpl->end__spring__linear();}
bool _preBegin__spring__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__spring__linear();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__spring__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spring__linear();
#endif
bool _freeAttributes__spring__linear( void* attributeData );

bool _begin__instance_physics_model( void* attributeData ){return mImpl->begin__instance_physics_model(*static_cast<instance_physics_model__AttributeData*>(attributeData));}
bool _data__instance_physics_model( const ParserChar* text, size_t textLength );
bool _end__instance_physics_model(){return mImpl->end__instance_physics_model();}
bool _preBegin__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_physics_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_physics_model();
#endif
bool _freeAttributes__instance_physics_model( void* attributeData );

bool _begin__instance_force_field( void* attributeData ){return mImpl->begin__instance_force_field(*static_cast<instance_force_field__AttributeData*>(attributeData));}
bool _data__instance_force_field( const ParserChar* text, size_t textLength );
bool _end__instance_force_field(){return mImpl->end__instance_force_field();}
bool _preBegin__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_force_field();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_force_field();
#endif
bool _freeAttributes__instance_force_field( void* attributeData );

bool _begin__instance_rigid_body( void* attributeData ){return mImpl->begin__instance_rigid_body(*static_cast<instance_rigid_body__AttributeData*>(attributeData));}
bool _data__instance_rigid_body( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body(){return mImpl->end__instance_rigid_body();}
bool _preBegin__instance_rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_body();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body();
#endif
bool _freeAttributes__instance_rigid_body( void* attributeData );

bool _begin__instance_rigid_body_type____technique_common( void* attributeData ){return mImpl->begin__instance_rigid_body_type____technique_common();}
bool _data__instance_rigid_body_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body_type____technique_common(){return mImpl->end__instance_rigid_body_type____technique_common();}
bool _preBegin__instance_rigid_body_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_body_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_body_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body_type____technique_common();
#endif
bool _freeAttributes__instance_rigid_body_type____technique_common( void* attributeData );

bool _begin__angular_velocity( void* attributeData ){return mImpl->begin__angular_velocity();}
bool _data__angular_velocity( const ParserChar* text, size_t textLength );
bool _end__angular_velocity(){return mImpl->end__angular_velocity();}
bool _preBegin__angular_velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__angular_velocity();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__angular_velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__angular_velocity();
#endif
bool _freeAttributes__angular_velocity( void* attributeData );

bool _begin__velocity( void* attributeData ){return mImpl->begin__velocity();}
bool _data__velocity( const ParserChar* text, size_t textLength );
bool _end__velocity(){return mImpl->end__velocity();}
bool _preBegin__velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__velocity();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__velocity();
#endif
bool _freeAttributes__velocity( void* attributeData );

bool _begin__instance_rigid_body__technique_common__dynamic( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__dynamic(*static_cast<instance_rigid_body__technique_common__dynamic__AttributeData*>(attributeData));}
bool _data__instance_rigid_body__technique_common__dynamic( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__dynamic(){return mImpl->end__instance_rigid_body__technique_common__dynamic();}
bool _preBegin__instance_rigid_body__technique_common__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_body__technique_common__dynamic();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_body__technique_common__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__dynamic();
#endif
bool _freeAttributes__instance_rigid_body__technique_common__dynamic( void* attributeData );

bool _begin__instance_rigid_body__technique_common__mass_frame( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__mass_frame();}
bool _data__instance_rigid_body__technique_common__mass_frame( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__mass_frame(){return mImpl->end__instance_rigid_body__technique_common__mass_frame();}
bool _preBegin__instance_rigid_body__technique_common__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_body__technique_common__mass_frame();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_body__technique_common__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__mass_frame();
#endif
bool _freeAttributes__instance_rigid_body__technique_common__mass_frame( void* attributeData );

bool _begin__instance_rigid_body__technique_common__shape( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__shape();}
bool _data__instance_rigid_body__technique_common__shape( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__shape(){return mImpl->end__instance_rigid_body__technique_common__shape();}
bool _preBegin__instance_rigid_body__technique_common__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_body__technique_common__shape();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_body__technique_common__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__shape();
#endif
bool _freeAttributes__instance_rigid_body__technique_common__shape( void* attributeData );

bool _begin__instance_rigid_body__technique_common__shape__hollow( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__shape__hollow(*static_cast<instance_rigid_body__technique_common__shape__hollow__AttributeData*>(attributeData));}
bool _data__instance_rigid_body__technique_common__shape__hollow( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__shape__hollow(){return mImpl->end__instance_rigid_body__technique_common__shape__hollow();}
bool _preBegin__instance_rigid_body__technique_common__shape__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_body__technique_common__shape__hollow();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_body__technique_common__shape__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__shape__hollow();
#endif
bool _freeAttributes__instance_rigid_body__technique_common__shape__hollow( void* attributeData );

bool _begin__instance_rigid_constraint( void* attributeData ){return mImpl->begin__instance_rigid_constraint(*static_cast<instance_rigid_constraint__AttributeData*>(attributeData));}
bool _data__instance_rigid_constraint( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_constraint(){return mImpl->end__instance_rigid_constraint();}
bool _preBegin__instance_rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_rigid_constraint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_constraint();
#endif
bool _freeAttributes__instance_rigid_constraint( void* attributeData );

bool _begin__library_physics_scenes( void* attributeData ){return mImpl->begin__library_physics_scenes(*static_cast<library_physics_scenes__AttributeData*>(attributeData));}
bool _data__library_physics_scenes( const ParserChar* text, size_t textLength );
bool _end__library_physics_scenes(){return mImpl->end__library_physics_scenes();}
bool _preBegin__library_physics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_physics_scenes();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_physics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_physics_scenes();
#endif
bool _freeAttributes__library_physics_scenes( void* attributeData );

bool _begin__physics_scene( void* attributeData ){return mImpl->begin__physics_scene(*static_cast<physics_scene__AttributeData*>(attributeData));}
bool _data__physics_scene( const ParserChar* text, size_t textLength );
bool _end__physics_scene(){return mImpl->end__physics_scene();}
bool _preBegin__physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__physics_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_scene();
#endif
bool _freeAttributes__physics_scene( void* attributeData );

bool _begin__physics_scene_type____technique_common( void* attributeData ){return mImpl->begin__physics_scene_type____technique_common();}
bool _data__physics_scene_type____technique_common( const ParserChar* text, size_t textLength );
bool _end__physics_scene_type____technique_common(){return mImpl->end__physics_scene_type____technique_common();}
bool _preBegin__physics_scene_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__physics_scene_type____technique_common();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__physics_scene_type____technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_scene_type____technique_common();
#endif
bool _freeAttributes__physics_scene_type____technique_common( void* attributeData );

bool _begin__gravity( void* attributeData ){return mImpl->begin__gravity(*static_cast<gravity__AttributeData*>(attributeData));}
bool _data__gravity( const ParserChar* text, size_t textLength );
bool _end__gravity(){return mImpl->end__gravity();}
bool _preBegin__gravity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gravity();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gravity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gravity();
#endif
bool _freeAttributes__gravity( void* attributeData );

bool _begin__time_step( void* attributeData ){return mImpl->begin__time_step(*static_cast<time_step__AttributeData*>(attributeData));}
bool _data__time_step( const ParserChar* text, size_t textLength );
bool _end__time_step(){return mImpl->end__time_step();}
bool _preBegin__time_step( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__time_step();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__time_step( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__time_step();
#endif
bool _freeAttributes__time_step( void* attributeData );

bool _begin__library_visual_scenes( void* attributeData ){return mImpl->begin__library_visual_scenes(*static_cast<library_visual_scenes__AttributeData*>(attributeData));}
bool _data__library_visual_scenes( const ParserChar* text, size_t textLength );
bool _end__library_visual_scenes(){return mImpl->end__library_visual_scenes();}
bool _preBegin__library_visual_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_visual_scenes();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_visual_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_visual_scenes();
#endif
bool _freeAttributes__library_visual_scenes( void* attributeData );

bool _begin__visual_scene( void* attributeData ){return mImpl->begin__visual_scene(*static_cast<visual_scene__AttributeData*>(attributeData));}
bool _data__visual_scene( const ParserChar* text, size_t textLength );
bool _end__visual_scene(){return mImpl->end__visual_scene();}
bool _preBegin__visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__visual_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__visual_scene();
#endif
bool _freeAttributes__visual_scene( void* attributeData );

bool _begin__evaluate_scene( void* attributeData ){return mImpl->begin__evaluate_scene(*static_cast<evaluate_scene__AttributeData*>(attributeData));}
bool _data__evaluate_scene( const ParserChar* text, size_t textLength );
bool _end__evaluate_scene(){return mImpl->end__evaluate_scene();}
bool _preBegin__evaluate_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__evaluate_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__evaluate_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__evaluate_scene();
#endif
bool _freeAttributes__evaluate_scene( void* attributeData );

bool _begin__render( void* attributeData ){return mImpl->begin__render(*static_cast<render__AttributeData*>(attributeData));}
bool _data__render( const ParserChar* text, size_t textLength );
bool _end__render(){return mImpl->end__render();}
bool _preBegin__render( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__render();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__render( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__render();
#endif
bool _freeAttributes__render( void* attributeData );

bool _begin__layer( void* attributeData ){return mImpl->begin__layer();}
bool _data__layer( const ParserChar* text, size_t textLength );
bool _end__layer(){return mImpl->end__layer();}
bool _preBegin__layer( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__layer();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__layer( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__layer();
#endif
bool _freeAttributes__layer( void* attributeData );

bool _begin__render__instance_material( void* attributeData ){return mImpl->begin__render__instance_material(*static_cast<render__instance_material__AttributeData*>(attributeData));}
bool _data__render__instance_material( const ParserChar* text, size_t textLength );
bool _end__render__instance_material(){return mImpl->end__render__instance_material();}
bool _preBegin__render__instance_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__render__instance_material();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__render__instance_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__render__instance_material();
#endif
bool _freeAttributes__render__instance_material( void* attributeData );

bool _begin__technique_override( void* attributeData ){return mImpl->begin__technique_override(*static_cast<technique_override__AttributeData*>(attributeData));}
bool _data__technique_override( const ParserChar* text, size_t textLength );
bool _end__technique_override(){return mImpl->end__technique_override();}
bool _preBegin__technique_override( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique_override();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique_override( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_override();
#endif
bool _freeAttributes__technique_override( void* attributeData );

bool _begin__render__instance_material__bind( void* attributeData ){return mImpl->begin__render__instance_material__bind(*static_cast<render__instance_material__bind__AttributeData*>(attributeData));}
bool _data__render__instance_material__bind( const ParserChar* text, size_t textLength );
bool _end__render__instance_material__bind(){return mImpl->end__render__instance_material__bind();}
bool _preBegin__render__instance_material__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__render__instance_material__bind();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__render__instance_material__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__render__instance_material__bind();
#endif
bool _freeAttributes__render__instance_material__bind( void* attributeData );

bool _begin__library_joints( void* attributeData ){return mImpl->begin__library_joints(*static_cast<library_joints__AttributeData*>(attributeData));}
bool _data__library_joints( const ParserChar* text, size_t textLength );
bool _end__library_joints(){return mImpl->end__library_joints();}
bool _preBegin__library_joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_joints();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_joints();
#endif
bool _freeAttributes__library_joints( void* attributeData );

bool _begin__joint( void* attributeData ){return mImpl->begin__joint(*static_cast<joint__AttributeData*>(attributeData));}
bool _data__joint( const ParserChar* text, size_t textLength );
bool _end__joint(){return mImpl->end__joint();}
bool _preBegin__joint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__joint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__joint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__joint();
#endif
bool _freeAttributes__joint( void* attributeData );

bool _begin__prismatic( void* attributeData ){return mImpl->begin__prismatic(*static_cast<prismatic__AttributeData*>(attributeData));}
bool _data__prismatic( const ParserChar* text, size_t textLength );
bool _end__prismatic(){return mImpl->end__prismatic();}
bool _preBegin__prismatic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__prismatic();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__prismatic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__prismatic();
#endif
bool _freeAttributes__prismatic( void* attributeData );

bool _begin__axis____axis_type( void* attributeData ){return mImpl->begin__axis____axis_type(*static_cast<axis____axis_type__AttributeData*>(attributeData));}
bool _data__axis____axis_type( const ParserChar* text, size_t textLength );
bool _end__axis____axis_type(){return mImpl->end__axis____axis_type();}
bool _preBegin__axis____axis_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__axis____axis_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__axis____axis_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__axis____axis_type();
#endif
bool _freeAttributes__axis____axis_type( void* attributeData );

bool _begin__limits____joint_limits_type( void* attributeData ){return mImpl->begin__limits____joint_limits_type();}
bool _data__limits____joint_limits_type( const ParserChar* text, size_t textLength );
bool _end__limits____joint_limits_type(){return mImpl->end__limits____joint_limits_type();}
bool _preBegin__limits____joint_limits_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__limits____joint_limits_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__limits____joint_limits_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__limits____joint_limits_type();
#endif
bool _freeAttributes__limits____joint_limits_type( void* attributeData );

bool _begin__min____minmax_type( void* attributeData ){return mImpl->begin__min____minmax_type(*static_cast<min____minmax_type__AttributeData*>(attributeData));}
bool _data__min____minmax_type( const ParserChar* text, size_t textLength );
bool _end__min____minmax_type(){return mImpl->end__min____minmax_type();}
bool _preBegin__min____minmax_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__min____minmax_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__min____minmax_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__min____minmax_type();
#endif
bool _freeAttributes__min____minmax_type( void* attributeData );

bool _begin__max____minmax_type( void* attributeData ){return mImpl->begin__max____minmax_type(*static_cast<max____minmax_type__AttributeData*>(attributeData));}
bool _data__max____minmax_type( const ParserChar* text, size_t textLength );
bool _end__max____minmax_type(){return mImpl->end__max____minmax_type();}
bool _preBegin__max____minmax_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__max____minmax_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__max____minmax_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__max____minmax_type();
#endif
bool _freeAttributes__max____minmax_type( void* attributeData );

bool _begin__revolute( void* attributeData ){return mImpl->begin__revolute(*static_cast<revolute__AttributeData*>(attributeData));}
bool _data__revolute( const ParserChar* text, size_t textLength );
bool _end__revolute(){return mImpl->end__revolute();}
bool _preBegin__revolute( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__revolute();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__revolute( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__revolute();
#endif
bool _freeAttributes__revolute( void* attributeData );

bool _begin__library_kinematics_models( void* attributeData ){return mImpl->begin__library_kinematics_models(*static_cast<library_kinematics_models__AttributeData*>(attributeData));}
bool _data__library_kinematics_models( const ParserChar* text, size_t textLength );
bool _end__library_kinematics_models(){return mImpl->end__library_kinematics_models();}
bool _preBegin__library_kinematics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_kinematics_models();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_kinematics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_kinematics_models();
#endif
bool _freeAttributes__library_kinematics_models( void* attributeData );

bool _begin__kinematics_model( void* attributeData ){return mImpl->begin__kinematics_model(*static_cast<kinematics_model__AttributeData*>(attributeData));}
bool _data__kinematics_model( const ParserChar* text, size_t textLength );
bool _end__kinematics_model(){return mImpl->end__kinematics_model();}
bool _preBegin__kinematics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__kinematics_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__kinematics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__kinematics_model();
#endif
bool _freeAttributes__kinematics_model( void* attributeData );

bool _begin__technique_common____kinematics_model_technique_type( void* attributeData ){return mImpl->begin__technique_common____kinematics_model_technique_type();}
bool _data__technique_common____kinematics_model_technique_type( const ParserChar* text, size_t textLength );
bool _end__technique_common____kinematics_model_technique_type(){return mImpl->end__technique_common____kinematics_model_technique_type();}
bool _preBegin__technique_common____kinematics_model_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique_common____kinematics_model_technique_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique_common____kinematics_model_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_common____kinematics_model_technique_type();
#endif
bool _freeAttributes__technique_common____kinematics_model_technique_type( void* attributeData );

bool _begin__newparam____kinematics_newparam_type( void* attributeData ){return mImpl->begin__newparam____kinematics_newparam_type(*static_cast<newparam____kinematics_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____kinematics_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____kinematics_newparam_type(){return mImpl->end__newparam____kinematics_newparam_type();}
bool _preBegin__newparam____kinematics_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____kinematics_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____kinematics_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____kinematics_newparam_type();
#endif
bool _freeAttributes__newparam____kinematics_newparam_type( void* attributeData );

bool _begin__instance_joint( void* attributeData ){return mImpl->begin__instance_joint(*static_cast<instance_joint__AttributeData*>(attributeData));}
bool _data__instance_joint( const ParserChar* text, size_t textLength );
bool _end__instance_joint(){return mImpl->end__instance_joint();}
bool _preBegin__instance_joint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_joint();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_joint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_joint();
#endif
bool _freeAttributes__instance_joint( void* attributeData );

bool _begin__link( void* attributeData ){return mImpl->begin__link(*static_cast<link__AttributeData*>(attributeData));}
bool _data__link( const ParserChar* text, size_t textLength );
bool _end__link(){return mImpl->end__link();}
bool _preBegin__link( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__link();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__link( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__link();
#endif
bool _freeAttributes__link( void* attributeData );

bool _begin__attachment_full( void* attributeData ){return mImpl->begin__attachment_full(*static_cast<attachment_full__AttributeData*>(attributeData));}
bool _data__attachment_full( const ParserChar* text, size_t textLength );
bool _end__attachment_full(){return mImpl->end__attachment_full();}
bool _preBegin__attachment_full( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__attachment_full();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__attachment_full( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__attachment_full();
#endif
bool _freeAttributes__attachment_full( void* attributeData );

bool _begin__attachment_start( void* attributeData ){return mImpl->begin__attachment_start(*static_cast<attachment_start__AttributeData*>(attributeData));}
bool _data__attachment_start( const ParserChar* text, size_t textLength );
bool _end__attachment_start(){return mImpl->end__attachment_start();}
bool _preBegin__attachment_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__attachment_start();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__attachment_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__attachment_start();
#endif
bool _freeAttributes__attachment_start( void* attributeData );

bool _begin__attachment_end( void* attributeData ){return mImpl->begin__attachment_end(*static_cast<attachment_end__AttributeData*>(attributeData));}
bool _data__attachment_end( const ParserChar* text, size_t textLength );
bool _end__attachment_end(){return mImpl->end__attachment_end();}
bool _preBegin__attachment_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__attachment_end();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__attachment_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__attachment_end();
#endif
bool _freeAttributes__attachment_end( void* attributeData );

bool _begin__formula( void* attributeData ){return mImpl->begin__formula(*static_cast<formula__AttributeData*>(attributeData));}
bool _data__formula( const ParserChar* text, size_t textLength );
bool _end__formula(){return mImpl->end__formula();}
bool _preBegin__formula( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__formula();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__formula( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__formula();
#endif
bool _freeAttributes__formula( void* attributeData );

bool _begin__newparam____formula_newparam_type( void* attributeData ){return mImpl->begin__newparam____formula_newparam_type(*static_cast<newparam____formula_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____formula_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____formula_newparam_type(){return mImpl->end__newparam____formula_newparam_type();}
bool _preBegin__newparam____formula_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__newparam____formula_newparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__newparam____formula_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____formula_newparam_type();
#endif
bool _freeAttributes__newparam____formula_newparam_type( void* attributeData );

bool _begin__target( void* attributeData ){return mImpl->begin__target();}
bool _data__target( const ParserChar* text, size_t textLength );
bool _end__target(){return mImpl->end__target();}
bool _preBegin__target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__target();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__target();
#endif
bool _freeAttributes__target( void* attributeData );

bool _begin__param____common_param_type( void* attributeData ){return mImpl->begin__param____common_param_type();}
bool _data__param____common_param_type( const ParserChar* text, size_t textLength );
bool _end__param____common_param_type(){return mImpl->end__param____common_param_type();}
bool _preBegin__param____common_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__param____common_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__param____common_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__param____common_param_type();
#endif
bool _freeAttributes__param____common_param_type( void* attributeData );

bool _begin__technique_common____formula_technique_type( void* attributeData ){return mImpl->begin__technique_common____formula_technique_type();}
bool _data__technique_common____formula_technique_type( const ParserChar* text, size_t textLength );
bool _end__technique_common____formula_technique_type(){return mImpl->end__technique_common____formula_technique_type();}
bool _preBegin__technique_common____formula_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique_common____formula_technique_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique_common____formula_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_common____formula_technique_type();
#endif
bool _freeAttributes__technique_common____formula_technique_type( void* attributeData );

bool _begin__math( void* attributeData ){return mImpl->begin__math(*static_cast<math__AttributeData*>(attributeData));}
bool _data__math( const ParserChar* text, size_t textLength );
bool _end__math(){return mImpl->end__math();}
bool _preBegin__math( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__math();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__math( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__math();
#endif
bool _freeAttributes__math( void* attributeData );


ENUM__mathml__overflow toEnumDataPrefix_ENUM__mathml__overflow (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__overflow>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__mathml__overflow (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__overflow*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__mathml__overflow (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__overflow*, size_t ),
    const std::pair<StringHash, ENUM__mathml__overflow>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__mathml__overflow (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__mathml__overflow>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__mathml__display toEnumDataPrefix_ENUM__mathml__display (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__display>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__mathml__display (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__display*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__mathml__display (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__display*, size_t ),
    const std::pair<StringHash, ENUM__mathml__display>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__mathml__display (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__mathml__display>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__cn( void* attributeData ){return mImpl->begin__cn(*static_cast<cn__AttributeData*>(attributeData));}
bool _data__cn( const ParserChar* text, size_t textLength );
bool _end__cn(){return mImpl->end__cn();}
bool _preBegin__cn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cn();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cn();
#endif
bool _freeAttributes__cn( void* attributeData );


ENUM__mathml__cn__type toEnumDataPrefix_ENUM__mathml__cn__type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__cn__type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__mathml__cn__type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__cn__type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__mathml__cn__type (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__cn__type*, size_t ),
    const std::pair<StringHash, ENUM__mathml__cn__type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__mathml__cn__type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__mathml__cn__type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__ci( void* attributeData ){return mImpl->begin__ci(*static_cast<ci__AttributeData*>(attributeData));}
bool _data__ci( const ParserChar* text, size_t textLength );
bool _end__ci(){return mImpl->end__ci();}
bool _preBegin__ci( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ci();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ci( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ci();
#endif
bool _freeAttributes__ci( void* attributeData );

bool _begin__csymbol( void* attributeData ){return mImpl->begin__csymbol(*static_cast<csymbol__AttributeData*>(attributeData));}
bool _data__csymbol( const ParserChar* text, size_t textLength );
bool _end__csymbol(){return mImpl->end__csymbol();}
bool _preBegin__csymbol( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__csymbol();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__csymbol( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__csymbol();
#endif
bool _freeAttributes__csymbol( void* attributeData );

bool _begin__abs( void* attributeData ){return mImpl->begin__abs(*static_cast<abs__AttributeData*>(attributeData));}
bool _data__abs( const ParserChar* text, size_t textLength );
bool _end__abs(){return mImpl->end__abs();}
bool _preBegin__abs( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__abs();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__abs( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__abs();
#endif
bool _freeAttributes__abs( void* attributeData );

bool _begin__conjugate( void* attributeData ){return mImpl->begin__conjugate(*static_cast<conjugate__AttributeData*>(attributeData));}
bool _data__conjugate( const ParserChar* text, size_t textLength );
bool _end__conjugate(){return mImpl->end__conjugate();}
bool _preBegin__conjugate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__conjugate();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__conjugate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__conjugate();
#endif
bool _freeAttributes__conjugate( void* attributeData );

bool _begin__factorial( void* attributeData ){return mImpl->begin__factorial(*static_cast<factorial__AttributeData*>(attributeData));}
bool _data__factorial( const ParserChar* text, size_t textLength );
bool _end__factorial(){return mImpl->end__factorial();}
bool _preBegin__factorial( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__factorial();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__factorial( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__factorial();
#endif
bool _freeAttributes__factorial( void* attributeData );

bool _begin__arg( void* attributeData ){return mImpl->begin__arg(*static_cast<arg__AttributeData*>(attributeData));}
bool _data__arg( const ParserChar* text, size_t textLength );
bool _end__arg(){return mImpl->end__arg();}
bool _preBegin__arg( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arg();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arg( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arg();
#endif
bool _freeAttributes__arg( void* attributeData );

bool _begin__real( void* attributeData ){return mImpl->begin__real(*static_cast<real__AttributeData*>(attributeData));}
bool _data__real( const ParserChar* text, size_t textLength );
bool _end__real(){return mImpl->end__real();}
bool _preBegin__real( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__real();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__real( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__real();
#endif
bool _freeAttributes__real( void* attributeData );

bool _begin__imaginary( void* attributeData ){return mImpl->begin__imaginary(*static_cast<imaginary__AttributeData*>(attributeData));}
bool _data__imaginary( const ParserChar* text, size_t textLength );
bool _end__imaginary(){return mImpl->end__imaginary();}
bool _preBegin__imaginary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__imaginary();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__imaginary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__imaginary();
#endif
bool _freeAttributes__imaginary( void* attributeData );

bool _begin__floor( void* attributeData ){return mImpl->begin__floor(*static_cast<floor__AttributeData*>(attributeData));}
bool _data__floor( const ParserChar* text, size_t textLength );
bool _end__floor(){return mImpl->end__floor();}
bool _preBegin__floor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__floor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__floor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__floor();
#endif
bool _freeAttributes__floor( void* attributeData );

bool _begin__ceiling( void* attributeData ){return mImpl->begin__ceiling(*static_cast<ceiling__AttributeData*>(attributeData));}
bool _data__ceiling( const ParserChar* text, size_t textLength );
bool _end__ceiling(){return mImpl->end__ceiling();}
bool _preBegin__ceiling( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ceiling();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ceiling( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ceiling();
#endif
bool _freeAttributes__ceiling( void* attributeData );

bool _begin__quotient( void* attributeData ){return mImpl->begin__quotient(*static_cast<quotient__AttributeData*>(attributeData));}
bool _data__quotient( const ParserChar* text, size_t textLength );
bool _end__quotient(){return mImpl->end__quotient();}
bool _preBegin__quotient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__quotient();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__quotient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__quotient();
#endif
bool _freeAttributes__quotient( void* attributeData );

bool _begin__divide( void* attributeData ){return mImpl->begin__divide(*static_cast<divide__AttributeData*>(attributeData));}
bool _data__divide( const ParserChar* text, size_t textLength );
bool _end__divide(){return mImpl->end__divide();}
bool _preBegin__divide( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__divide();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__divide( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__divide();
#endif
bool _freeAttributes__divide( void* attributeData );

bool _begin__rem( void* attributeData ){return mImpl->begin__rem(*static_cast<rem__AttributeData*>(attributeData));}
bool _data__rem( const ParserChar* text, size_t textLength );
bool _end__rem(){return mImpl->end__rem();}
bool _preBegin__rem( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rem();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rem( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rem();
#endif
bool _freeAttributes__rem( void* attributeData );

bool _begin__minus( void* attributeData ){return mImpl->begin__minus(*static_cast<minus__AttributeData*>(attributeData));}
bool _data__minus( const ParserChar* text, size_t textLength );
bool _end__minus(){return mImpl->end__minus();}
bool _preBegin__minus( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__minus();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__minus( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__minus();
#endif
bool _freeAttributes__minus( void* attributeData );

bool _begin__plus( void* attributeData ){return mImpl->begin__plus(*static_cast<plus__AttributeData*>(attributeData));}
bool _data__plus( const ParserChar* text, size_t textLength );
bool _end__plus(){return mImpl->end__plus();}
bool _preBegin__plus( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__plus();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__plus( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__plus();
#endif
bool _freeAttributes__plus( void* attributeData );

bool _begin__times( void* attributeData ){return mImpl->begin__times(*static_cast<times__AttributeData*>(attributeData));}
bool _data__times( const ParserChar* text, size_t textLength );
bool _end__times(){return mImpl->end__times();}
bool _preBegin__times( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__times();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__times( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__times();
#endif
bool _freeAttributes__times( void* attributeData );

bool _begin__power( void* attributeData ){return mImpl->begin__power(*static_cast<power__AttributeData*>(attributeData));}
bool _data__power( const ParserChar* text, size_t textLength );
bool _end__power(){return mImpl->end__power();}
bool _preBegin__power( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__power();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__power( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__power();
#endif
bool _freeAttributes__power( void* attributeData );

bool _begin__root( void* attributeData ){return mImpl->begin__root(*static_cast<root__AttributeData*>(attributeData));}
bool _data__root( const ParserChar* text, size_t textLength );
bool _end__root(){return mImpl->end__root();}
bool _preBegin__root( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__root();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__root( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__root();
#endif
bool _freeAttributes__root( void* attributeData );

bool _begin__max____Arith_type( void* attributeData ){return mImpl->begin__max____Arith_type(*static_cast<max____Arith_type__AttributeData*>(attributeData));}
bool _data__max____Arith_type( const ParserChar* text, size_t textLength );
bool _end__max____Arith_type(){return mImpl->end__max____Arith_type();}
bool _preBegin__max____Arith_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__max____Arith_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__max____Arith_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__max____Arith_type();
#endif
bool _freeAttributes__max____Arith_type( void* attributeData );

bool _begin__min____Arith_type( void* attributeData ){return mImpl->begin__min____Arith_type(*static_cast<min____Arith_type__AttributeData*>(attributeData));}
bool _data__min____Arith_type( const ParserChar* text, size_t textLength );
bool _end__min____Arith_type(){return mImpl->end__min____Arith_type();}
bool _preBegin__min____Arith_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__min____Arith_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__min____Arith_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__min____Arith_type();
#endif
bool _freeAttributes__min____Arith_type( void* attributeData );

bool _begin__gcd( void* attributeData ){return mImpl->begin__gcd(*static_cast<gcd__AttributeData*>(attributeData));}
bool _data__gcd( const ParserChar* text, size_t textLength );
bool _end__gcd(){return mImpl->end__gcd();}
bool _preBegin__gcd( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gcd();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gcd( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gcd();
#endif
bool _freeAttributes__gcd( void* attributeData );

bool _begin__lcm( void* attributeData ){return mImpl->begin__lcm(*static_cast<lcm__AttributeData*>(attributeData));}
bool _data__lcm( const ParserChar* text, size_t textLength );
bool _end__lcm(){return mImpl->end__lcm();}
bool _preBegin__lcm( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lcm();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lcm( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lcm();
#endif
bool _freeAttributes__lcm( void* attributeData );

bool _begin__sum( void* attributeData ){return mImpl->begin__sum(*static_cast<sum__AttributeData*>(attributeData));}
bool _data__sum( const ParserChar* text, size_t textLength );
bool _end__sum(){return mImpl->end__sum();}
bool _preBegin__sum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sum();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sum();
#endif
bool _freeAttributes__sum( void* attributeData );

bool _begin__product( void* attributeData ){return mImpl->begin__product(*static_cast<product__AttributeData*>(attributeData));}
bool _data__product( const ParserChar* text, size_t textLength );
bool _end__product(){return mImpl->end__product();}
bool _preBegin__product( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__product();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__product( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__product();
#endif
bool _freeAttributes__product( void* attributeData );

bool _begin__compose( void* attributeData ){return mImpl->begin__compose(*static_cast<compose__AttributeData*>(attributeData));}
bool _data__compose( const ParserChar* text, size_t textLength );
bool _end__compose(){return mImpl->end__compose();}
bool _preBegin__compose( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__compose();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__compose( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__compose();
#endif
bool _freeAttributes__compose( void* attributeData );

bool _begin__domain( void* attributeData ){return mImpl->begin__domain(*static_cast<domain__AttributeData*>(attributeData));}
bool _data__domain( const ParserChar* text, size_t textLength );
bool _end__domain(){return mImpl->end__domain();}
bool _preBegin__domain( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__domain();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__domain( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__domain();
#endif
bool _freeAttributes__domain( void* attributeData );

bool _begin__codomain( void* attributeData ){return mImpl->begin__codomain(*static_cast<codomain__AttributeData*>(attributeData));}
bool _data__codomain( const ParserChar* text, size_t textLength );
bool _end__codomain(){return mImpl->end__codomain();}
bool _preBegin__codomain( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__codomain();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__codomain( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__codomain();
#endif
bool _freeAttributes__codomain( void* attributeData );

bool _begin__image____Functions_type( void* attributeData ){return mImpl->begin__image____Functions_type(*static_cast<image____Functions_type__AttributeData*>(attributeData));}
bool _data__image____Functions_type( const ParserChar* text, size_t textLength );
bool _end__image____Functions_type(){return mImpl->end__image____Functions_type();}
bool _preBegin__image____Functions_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__image____Functions_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__image____Functions_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__image____Functions_type();
#endif
bool _freeAttributes__image____Functions_type( void* attributeData );

bool _begin__domainofapplication( void* attributeData ){return mImpl->begin__domainofapplication(*static_cast<domainofapplication__AttributeData*>(attributeData));}
bool _data__domainofapplication( const ParserChar* text, size_t textLength );
bool _end__domainofapplication(){return mImpl->end__domainofapplication();}
bool _preBegin__domainofapplication( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__domainofapplication();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__domainofapplication( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__domainofapplication();
#endif
bool _freeAttributes__domainofapplication( void* attributeData );

bool _begin__ident( void* attributeData ){return mImpl->begin__ident(*static_cast<ident__AttributeData*>(attributeData));}
bool _data__ident( const ParserChar* text, size_t textLength );
bool _end__ident(){return mImpl->end__ident();}
bool _preBegin__ident( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ident();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ident( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ident();
#endif
bool _freeAttributes__ident( void* attributeData );

bool _begin__and( void* attributeData ){return mImpl->begin__and(*static_cast<and__AttributeData*>(attributeData));}
bool _data__and( const ParserChar* text, size_t textLength );
bool _end__and(){return mImpl->end__and();}
bool _preBegin__and( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__and();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__and( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__and();
#endif
bool _freeAttributes__and( void* attributeData );

bool _begin__or( void* attributeData ){return mImpl->begin__or(*static_cast<or__AttributeData*>(attributeData));}
bool _data__or( const ParserChar* text, size_t textLength );
bool _end__or(){return mImpl->end__or();}
bool _preBegin__or( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__or();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__or( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__or();
#endif
bool _freeAttributes__or( void* attributeData );

bool _begin__xor( void* attributeData ){return mImpl->begin__xor(*static_cast<xor__AttributeData*>(attributeData));}
bool _data__xor( const ParserChar* text, size_t textLength );
bool _end__xor(){return mImpl->end__xor();}
bool _preBegin__xor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__xor();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__xor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__xor();
#endif
bool _freeAttributes__xor( void* attributeData );

bool _begin__not( void* attributeData ){return mImpl->begin__not(*static_cast<not__AttributeData*>(attributeData));}
bool _data__not( const ParserChar* text, size_t textLength );
bool _end__not(){return mImpl->end__not();}
bool _preBegin__not( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__not();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__not( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__not();
#endif
bool _freeAttributes__not( void* attributeData );

bool _begin__exists( void* attributeData ){return mImpl->begin__exists(*static_cast<exists__AttributeData*>(attributeData));}
bool _data__exists( const ParserChar* text, size_t textLength );
bool _end__exists(){return mImpl->end__exists();}
bool _preBegin__exists( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__exists();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__exists( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__exists();
#endif
bool _freeAttributes__exists( void* attributeData );

bool _begin__forall( void* attributeData ){return mImpl->begin__forall(*static_cast<forall__AttributeData*>(attributeData));}
bool _data__forall( const ParserChar* text, size_t textLength );
bool _end__forall(){return mImpl->end__forall();}
bool _preBegin__forall( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__forall();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__forall( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__forall();
#endif
bool _freeAttributes__forall( void* attributeData );

bool _begin__implies( void* attributeData ){return mImpl->begin__implies(*static_cast<implies__AttributeData*>(attributeData));}
bool _data__implies( const ParserChar* text, size_t textLength );
bool _end__implies(){return mImpl->end__implies();}
bool _preBegin__implies( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__implies();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__implies( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__implies();
#endif
bool _freeAttributes__implies( void* attributeData );

bool _begin__naturalnumbers( void* attributeData ){return mImpl->begin__naturalnumbers(*static_cast<naturalnumbers__AttributeData*>(attributeData));}
bool _data__naturalnumbers( const ParserChar* text, size_t textLength );
bool _end__naturalnumbers(){return mImpl->end__naturalnumbers();}
bool _preBegin__naturalnumbers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__naturalnumbers();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__naturalnumbers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__naturalnumbers();
#endif
bool _freeAttributes__naturalnumbers( void* attributeData );

bool _begin__primes( void* attributeData ){return mImpl->begin__primes(*static_cast<primes__AttributeData*>(attributeData));}
bool _data__primes( const ParserChar* text, size_t textLength );
bool _end__primes(){return mImpl->end__primes();}
bool _preBegin__primes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__primes();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__primes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__primes();
#endif
bool _freeAttributes__primes( void* attributeData );

bool _begin__integers( void* attributeData ){return mImpl->begin__integers(*static_cast<integers__AttributeData*>(attributeData));}
bool _data__integers( const ParserChar* text, size_t textLength );
bool _end__integers(){return mImpl->end__integers();}
bool _preBegin__integers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__integers();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__integers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__integers();
#endif
bool _freeAttributes__integers( void* attributeData );

bool _begin__rationals( void* attributeData ){return mImpl->begin__rationals(*static_cast<rationals__AttributeData*>(attributeData));}
bool _data__rationals( const ParserChar* text, size_t textLength );
bool _end__rationals(){return mImpl->end__rationals();}
bool _preBegin__rationals( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__rationals();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__rationals( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rationals();
#endif
bool _freeAttributes__rationals( void* attributeData );

bool _begin__reals( void* attributeData ){return mImpl->begin__reals(*static_cast<reals__AttributeData*>(attributeData));}
bool _data__reals( const ParserChar* text, size_t textLength );
bool _end__reals(){return mImpl->end__reals();}
bool _preBegin__reals( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__reals();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__reals( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__reals();
#endif
bool _freeAttributes__reals( void* attributeData );

bool _begin__complexes( void* attributeData ){return mImpl->begin__complexes(*static_cast<complexes__AttributeData*>(attributeData));}
bool _data__complexes( const ParserChar* text, size_t textLength );
bool _end__complexes(){return mImpl->end__complexes();}
bool _preBegin__complexes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__complexes();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__complexes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__complexes();
#endif
bool _freeAttributes__complexes( void* attributeData );

bool _begin__emptyset( void* attributeData ){return mImpl->begin__emptyset(*static_cast<emptyset__AttributeData*>(attributeData));}
bool _data__emptyset( const ParserChar* text, size_t textLength );
bool _end__emptyset(){return mImpl->end__emptyset();}
bool _preBegin__emptyset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__emptyset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__emptyset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__emptyset();
#endif
bool _freeAttributes__emptyset( void* attributeData );

bool _begin__exponentiale( void* attributeData ){return mImpl->begin__exponentiale(*static_cast<exponentiale__AttributeData*>(attributeData));}
bool _data__exponentiale( const ParserChar* text, size_t textLength );
bool _end__exponentiale(){return mImpl->end__exponentiale();}
bool _preBegin__exponentiale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__exponentiale();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__exponentiale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__exponentiale();
#endif
bool _freeAttributes__exponentiale( void* attributeData );

bool _begin__imaginaryi( void* attributeData ){return mImpl->begin__imaginaryi(*static_cast<imaginaryi__AttributeData*>(attributeData));}
bool _data__imaginaryi( const ParserChar* text, size_t textLength );
bool _end__imaginaryi(){return mImpl->end__imaginaryi();}
bool _preBegin__imaginaryi( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__imaginaryi();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__imaginaryi( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__imaginaryi();
#endif
bool _freeAttributes__imaginaryi( void* attributeData );

bool _begin__pi( void* attributeData ){return mImpl->begin__pi(*static_cast<pi__AttributeData*>(attributeData));}
bool _data__pi( const ParserChar* text, size_t textLength );
bool _end__pi(){return mImpl->end__pi();}
bool _preBegin__pi( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__pi();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__pi( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__pi();
#endif
bool _freeAttributes__pi( void* attributeData );

bool _begin__eulergamma( void* attributeData ){return mImpl->begin__eulergamma(*static_cast<eulergamma__AttributeData*>(attributeData));}
bool _data__eulergamma( const ParserChar* text, size_t textLength );
bool _end__eulergamma(){return mImpl->end__eulergamma();}
bool _preBegin__eulergamma( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__eulergamma();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__eulergamma( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__eulergamma();
#endif
bool _freeAttributes__eulergamma( void* attributeData );

bool _begin__true( void* attributeData ){return mImpl->begin__true(*static_cast<true__AttributeData*>(attributeData));}
bool _data__true( const ParserChar* text, size_t textLength );
bool _end__true(){return mImpl->end__true();}
bool _preBegin__true( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__true();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__true( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__true();
#endif
bool _freeAttributes__true( void* attributeData );

bool _begin__false( void* attributeData ){return mImpl->begin__false(*static_cast<false__AttributeData*>(attributeData));}
bool _data__false( const ParserChar* text, size_t textLength );
bool _end__false(){return mImpl->end__false();}
bool _preBegin__false( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__false();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__false( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__false();
#endif
bool _freeAttributes__false( void* attributeData );

bool _begin__infinity( void* attributeData ){return mImpl->begin__infinity(*static_cast<infinity__AttributeData*>(attributeData));}
bool _data__infinity( const ParserChar* text, size_t textLength );
bool _end__infinity(){return mImpl->end__infinity();}
bool _preBegin__infinity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__infinity();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__infinity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__infinity();
#endif
bool _freeAttributes__infinity( void* attributeData );

bool _begin__notanumber( void* attributeData ){return mImpl->begin__notanumber(*static_cast<notanumber__AttributeData*>(attributeData));}
bool _data__notanumber( const ParserChar* text, size_t textLength );
bool _end__notanumber(){return mImpl->end__notanumber();}
bool _preBegin__notanumber( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__notanumber();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__notanumber( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__notanumber();
#endif
bool _freeAttributes__notanumber( void* attributeData );

bool _begin__set( void* attributeData ){return mImpl->begin__set(*static_cast<set__AttributeData*>(attributeData));}
bool _data__set( const ParserChar* text, size_t textLength );
bool _end__set(){return mImpl->end__set();}
bool _preBegin__set( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__set();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__set( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__set();
#endif
bool _freeAttributes__set( void* attributeData );

bool _begin__list( void* attributeData ){return mImpl->begin__list(*static_cast<list__AttributeData*>(attributeData));}
bool _data__list( const ParserChar* text, size_t textLength );
bool _end__list(){return mImpl->end__list();}
bool _preBegin__list( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__list();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__list( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__list();
#endif
bool _freeAttributes__list( void* attributeData );


ENUM__mathml__list__order toEnumDataPrefix_ENUM__mathml__list__order (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__list__order>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__mathml__list__order (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__list__order*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__mathml__list__order (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__list__order*, size_t ),
    const std::pair<StringHash, ENUM__mathml__list__order>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__mathml__list__order (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__mathml__list__order>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__union( void* attributeData ){return mImpl->begin__union(*static_cast<union__AttributeData*>(attributeData));}
bool _data__union( const ParserChar* text, size_t textLength );
bool _end__union(){return mImpl->end__union();}
bool _preBegin__union( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__union();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__union( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__union();
#endif
bool _freeAttributes__union( void* attributeData );

bool _begin__intersect( void* attributeData ){return mImpl->begin__intersect(*static_cast<intersect__AttributeData*>(attributeData));}
bool _data__intersect( const ParserChar* text, size_t textLength );
bool _end__intersect(){return mImpl->end__intersect();}
bool _preBegin__intersect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__intersect();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__intersect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__intersect();
#endif
bool _freeAttributes__intersect( void* attributeData );

bool _begin__in( void* attributeData ){return mImpl->begin__in(*static_cast<in__AttributeData*>(attributeData));}
bool _data__in( const ParserChar* text, size_t textLength );
bool _end__in(){return mImpl->end__in();}
bool _preBegin__in( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__in();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__in( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__in();
#endif
bool _freeAttributes__in( void* attributeData );

bool _begin__notin( void* attributeData ){return mImpl->begin__notin(*static_cast<notin__AttributeData*>(attributeData));}
bool _data__notin( const ParserChar* text, size_t textLength );
bool _end__notin(){return mImpl->end__notin();}
bool _preBegin__notin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__notin();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__notin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__notin();
#endif
bool _freeAttributes__notin( void* attributeData );

bool _begin__subset( void* attributeData ){return mImpl->begin__subset(*static_cast<subset__AttributeData*>(attributeData));}
bool _data__subset( const ParserChar* text, size_t textLength );
bool _end__subset(){return mImpl->end__subset();}
bool _preBegin__subset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__subset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__subset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__subset();
#endif
bool _freeAttributes__subset( void* attributeData );

bool _begin__prsubset( void* attributeData ){return mImpl->begin__prsubset(*static_cast<prsubset__AttributeData*>(attributeData));}
bool _data__prsubset( const ParserChar* text, size_t textLength );
bool _end__prsubset(){return mImpl->end__prsubset();}
bool _preBegin__prsubset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__prsubset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__prsubset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__prsubset();
#endif
bool _freeAttributes__prsubset( void* attributeData );

bool _begin__notsubset( void* attributeData ){return mImpl->begin__notsubset(*static_cast<notsubset__AttributeData*>(attributeData));}
bool _data__notsubset( const ParserChar* text, size_t textLength );
bool _end__notsubset(){return mImpl->end__notsubset();}
bool _preBegin__notsubset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__notsubset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__notsubset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__notsubset();
#endif
bool _freeAttributes__notsubset( void* attributeData );

bool _begin__notprsubset( void* attributeData ){return mImpl->begin__notprsubset(*static_cast<notprsubset__AttributeData*>(attributeData));}
bool _data__notprsubset( const ParserChar* text, size_t textLength );
bool _end__notprsubset(){return mImpl->end__notprsubset();}
bool _preBegin__notprsubset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__notprsubset();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__notprsubset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__notprsubset();
#endif
bool _freeAttributes__notprsubset( void* attributeData );

bool _begin__setdiff( void* attributeData ){return mImpl->begin__setdiff(*static_cast<setdiff__AttributeData*>(attributeData));}
bool _data__setdiff( const ParserChar* text, size_t textLength );
bool _end__setdiff(){return mImpl->end__setdiff();}
bool _preBegin__setdiff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__setdiff();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__setdiff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setdiff();
#endif
bool _freeAttributes__setdiff( void* attributeData );

bool _begin__card( void* attributeData ){return mImpl->begin__card(*static_cast<card__AttributeData*>(attributeData));}
bool _data__card( const ParserChar* text, size_t textLength );
bool _end__card(){return mImpl->end__card();}
bool _preBegin__card( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__card();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__card( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__card();
#endif
bool _freeAttributes__card( void* attributeData );

bool _begin__cartesianproduct( void* attributeData ){return mImpl->begin__cartesianproduct(*static_cast<cartesianproduct__AttributeData*>(attributeData));}
bool _data__cartesianproduct( const ParserChar* text, size_t textLength );
bool _end__cartesianproduct(){return mImpl->end__cartesianproduct();}
bool _preBegin__cartesianproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cartesianproduct();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cartesianproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cartesianproduct();
#endif
bool _freeAttributes__cartesianproduct( void* attributeData );

bool _begin__eq( void* attributeData ){return mImpl->begin__eq(*static_cast<eq__AttributeData*>(attributeData));}
bool _data__eq( const ParserChar* text, size_t textLength );
bool _end__eq(){return mImpl->end__eq();}
bool _preBegin__eq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__eq();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__eq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__eq();
#endif
bool _freeAttributes__eq( void* attributeData );

bool _begin__neq( void* attributeData ){return mImpl->begin__neq(*static_cast<neq__AttributeData*>(attributeData));}
bool _data__neq( const ParserChar* text, size_t textLength );
bool _end__neq(){return mImpl->end__neq();}
bool _preBegin__neq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__neq();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__neq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__neq();
#endif
bool _freeAttributes__neq( void* attributeData );

bool _begin__leq( void* attributeData ){return mImpl->begin__leq(*static_cast<leq__AttributeData*>(attributeData));}
bool _data__leq( const ParserChar* text, size_t textLength );
bool _end__leq(){return mImpl->end__leq();}
bool _preBegin__leq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__leq();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__leq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__leq();
#endif
bool _freeAttributes__leq( void* attributeData );

bool _begin__lt( void* attributeData ){return mImpl->begin__lt(*static_cast<lt__AttributeData*>(attributeData));}
bool _data__lt( const ParserChar* text, size_t textLength );
bool _end__lt(){return mImpl->end__lt();}
bool _preBegin__lt( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lt();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lt( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lt();
#endif
bool _freeAttributes__lt( void* attributeData );

bool _begin__geq( void* attributeData ){return mImpl->begin__geq(*static_cast<geq__AttributeData*>(attributeData));}
bool _data__geq( const ParserChar* text, size_t textLength );
bool _end__geq(){return mImpl->end__geq();}
bool _preBegin__geq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__geq();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__geq( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__geq();
#endif
bool _freeAttributes__geq( void* attributeData );

bool _begin__gt( void* attributeData ){return mImpl->begin__gt(*static_cast<gt__AttributeData*>(attributeData));}
bool _data__gt( const ParserChar* text, size_t textLength );
bool _end__gt(){return mImpl->end__gt();}
bool _preBegin__gt( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__gt();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__gt( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gt();
#endif
bool _freeAttributes__gt( void* attributeData );

bool _begin__equivalent( void* attributeData ){return mImpl->begin__equivalent(*static_cast<equivalent__AttributeData*>(attributeData));}
bool _data__equivalent( const ParserChar* text, size_t textLength );
bool _end__equivalent(){return mImpl->end__equivalent();}
bool _preBegin__equivalent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__equivalent();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__equivalent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__equivalent();
#endif
bool _freeAttributes__equivalent( void* attributeData );

bool _begin__approx( void* attributeData ){return mImpl->begin__approx(*static_cast<approx__AttributeData*>(attributeData));}
bool _data__approx( const ParserChar* text, size_t textLength );
bool _end__approx(){return mImpl->end__approx();}
bool _preBegin__approx( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__approx();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__approx( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__approx();
#endif
bool _freeAttributes__approx( void* attributeData );

bool _begin__factorof( void* attributeData ){return mImpl->begin__factorof(*static_cast<factorof__AttributeData*>(attributeData));}
bool _data__factorof( const ParserChar* text, size_t textLength );
bool _end__factorof(){return mImpl->end__factorof();}
bool _preBegin__factorof( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__factorof();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__factorof( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__factorof();
#endif
bool _freeAttributes__factorof( void* attributeData );

bool _begin__exp( void* attributeData ){return mImpl->begin__exp(*static_cast<exp__AttributeData*>(attributeData));}
bool _data__exp( const ParserChar* text, size_t textLength );
bool _end__exp(){return mImpl->end__exp();}
bool _preBegin__exp( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__exp();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__exp( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__exp();
#endif
bool _freeAttributes__exp( void* attributeData );

bool _begin__ln( void* attributeData ){return mImpl->begin__ln(*static_cast<ln__AttributeData*>(attributeData));}
bool _data__ln( const ParserChar* text, size_t textLength );
bool _end__ln(){return mImpl->end__ln();}
bool _preBegin__ln( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__ln();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__ln( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ln();
#endif
bool _freeAttributes__ln( void* attributeData );

bool _begin__log( void* attributeData ){return mImpl->begin__log(*static_cast<log__AttributeData*>(attributeData));}
bool _data__log( const ParserChar* text, size_t textLength );
bool _end__log(){return mImpl->end__log();}
bool _preBegin__log( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__log();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__log( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__log();
#endif
bool _freeAttributes__log( void* attributeData );

bool _begin__logbase( void* attributeData ){return mImpl->begin__logbase(*static_cast<logbase__AttributeData*>(attributeData));}
bool _data__logbase( const ParserChar* text, size_t textLength );
bool _end__logbase(){return mImpl->end__logbase();}
bool _preBegin__logbase( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__logbase();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__logbase( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__logbase();
#endif
bool _freeAttributes__logbase( void* attributeData );

bool _begin__sin( void* attributeData ){return mImpl->begin__sin(*static_cast<sin__AttributeData*>(attributeData));}
bool _data__sin( const ParserChar* text, size_t textLength );
bool _end__sin(){return mImpl->end__sin();}
bool _preBegin__sin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sin();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sin();
#endif
bool _freeAttributes__sin( void* attributeData );

bool _begin__cos( void* attributeData ){return mImpl->begin__cos(*static_cast<cos__AttributeData*>(attributeData));}
bool _data__cos( const ParserChar* text, size_t textLength );
bool _end__cos(){return mImpl->end__cos();}
bool _preBegin__cos( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cos();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cos( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cos();
#endif
bool _freeAttributes__cos( void* attributeData );

bool _begin__tan( void* attributeData ){return mImpl->begin__tan(*static_cast<tan__AttributeData*>(attributeData));}
bool _data__tan( const ParserChar* text, size_t textLength );
bool _end__tan(){return mImpl->end__tan();}
bool _preBegin__tan( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__tan();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__tan( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tan();
#endif
bool _freeAttributes__tan( void* attributeData );

bool _begin__sec( void* attributeData ){return mImpl->begin__sec(*static_cast<sec__AttributeData*>(attributeData));}
bool _data__sec( const ParserChar* text, size_t textLength );
bool _end__sec(){return mImpl->end__sec();}
bool _preBegin__sec( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sec();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sec( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sec();
#endif
bool _freeAttributes__sec( void* attributeData );

bool _begin__csc( void* attributeData ){return mImpl->begin__csc(*static_cast<csc__AttributeData*>(attributeData));}
bool _data__csc( const ParserChar* text, size_t textLength );
bool _end__csc(){return mImpl->end__csc();}
bool _preBegin__csc( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__csc();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__csc( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__csc();
#endif
bool _freeAttributes__csc( void* attributeData );

bool _begin__cot( void* attributeData ){return mImpl->begin__cot(*static_cast<cot__AttributeData*>(attributeData));}
bool _data__cot( const ParserChar* text, size_t textLength );
bool _end__cot(){return mImpl->end__cot();}
bool _preBegin__cot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cot();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cot();
#endif
bool _freeAttributes__cot( void* attributeData );

bool _begin__arcsin( void* attributeData ){return mImpl->begin__arcsin(*static_cast<arcsin__AttributeData*>(attributeData));}
bool _data__arcsin( const ParserChar* text, size_t textLength );
bool _end__arcsin(){return mImpl->end__arcsin();}
bool _preBegin__arcsin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arcsin();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arcsin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arcsin();
#endif
bool _freeAttributes__arcsin( void* attributeData );

bool _begin__arccos( void* attributeData ){return mImpl->begin__arccos(*static_cast<arccos__AttributeData*>(attributeData));}
bool _data__arccos( const ParserChar* text, size_t textLength );
bool _end__arccos(){return mImpl->end__arccos();}
bool _preBegin__arccos( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arccos();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arccos( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arccos();
#endif
bool _freeAttributes__arccos( void* attributeData );

bool _begin__arctan( void* attributeData ){return mImpl->begin__arctan(*static_cast<arctan__AttributeData*>(attributeData));}
bool _data__arctan( const ParserChar* text, size_t textLength );
bool _end__arctan(){return mImpl->end__arctan();}
bool _preBegin__arctan( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arctan();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arctan( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arctan();
#endif
bool _freeAttributes__arctan( void* attributeData );

bool _begin__arcsec( void* attributeData ){return mImpl->begin__arcsec(*static_cast<arcsec__AttributeData*>(attributeData));}
bool _data__arcsec( const ParserChar* text, size_t textLength );
bool _end__arcsec(){return mImpl->end__arcsec();}
bool _preBegin__arcsec( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arcsec();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arcsec( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arcsec();
#endif
bool _freeAttributes__arcsec( void* attributeData );

bool _begin__arccsc( void* attributeData ){return mImpl->begin__arccsc(*static_cast<arccsc__AttributeData*>(attributeData));}
bool _data__arccsc( const ParserChar* text, size_t textLength );
bool _end__arccsc(){return mImpl->end__arccsc();}
bool _preBegin__arccsc( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arccsc();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arccsc( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arccsc();
#endif
bool _freeAttributes__arccsc( void* attributeData );

bool _begin__arccot( void* attributeData ){return mImpl->begin__arccot(*static_cast<arccot__AttributeData*>(attributeData));}
bool _data__arccot( const ParserChar* text, size_t textLength );
bool _end__arccot(){return mImpl->end__arccot();}
bool _preBegin__arccot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arccot();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arccot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arccot();
#endif
bool _freeAttributes__arccot( void* attributeData );

bool _begin__sinh( void* attributeData ){return mImpl->begin__sinh(*static_cast<sinh__AttributeData*>(attributeData));}
bool _data__sinh( const ParserChar* text, size_t textLength );
bool _end__sinh(){return mImpl->end__sinh();}
bool _preBegin__sinh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sinh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sinh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sinh();
#endif
bool _freeAttributes__sinh( void* attributeData );

bool _begin__cosh( void* attributeData ){return mImpl->begin__cosh(*static_cast<cosh__AttributeData*>(attributeData));}
bool _data__cosh( const ParserChar* text, size_t textLength );
bool _end__cosh(){return mImpl->end__cosh();}
bool _preBegin__cosh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__cosh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__cosh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cosh();
#endif
bool _freeAttributes__cosh( void* attributeData );

bool _begin__tanh( void* attributeData ){return mImpl->begin__tanh(*static_cast<tanh__AttributeData*>(attributeData));}
bool _data__tanh( const ParserChar* text, size_t textLength );
bool _end__tanh(){return mImpl->end__tanh();}
bool _preBegin__tanh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__tanh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__tanh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tanh();
#endif
bool _freeAttributes__tanh( void* attributeData );

bool _begin__sech( void* attributeData ){return mImpl->begin__sech(*static_cast<sech__AttributeData*>(attributeData));}
bool _data__sech( const ParserChar* text, size_t textLength );
bool _end__sech(){return mImpl->end__sech();}
bool _preBegin__sech( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sech();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sech( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sech();
#endif
bool _freeAttributes__sech( void* attributeData );

bool _begin__csch( void* attributeData ){return mImpl->begin__csch(*static_cast<csch__AttributeData*>(attributeData));}
bool _data__csch( const ParserChar* text, size_t textLength );
bool _end__csch(){return mImpl->end__csch();}
bool _preBegin__csch( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__csch();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__csch( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__csch();
#endif
bool _freeAttributes__csch( void* attributeData );

bool _begin__coth( void* attributeData ){return mImpl->begin__coth(*static_cast<coth__AttributeData*>(attributeData));}
bool _data__coth( const ParserChar* text, size_t textLength );
bool _end__coth(){return mImpl->end__coth();}
bool _preBegin__coth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__coth();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__coth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__coth();
#endif
bool _freeAttributes__coth( void* attributeData );

bool _begin__arccosh( void* attributeData ){return mImpl->begin__arccosh(*static_cast<arccosh__AttributeData*>(attributeData));}
bool _data__arccosh( const ParserChar* text, size_t textLength );
bool _end__arccosh(){return mImpl->end__arccosh();}
bool _preBegin__arccosh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arccosh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arccosh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arccosh();
#endif
bool _freeAttributes__arccosh( void* attributeData );

bool _begin__arccoth( void* attributeData ){return mImpl->begin__arccoth(*static_cast<arccoth__AttributeData*>(attributeData));}
bool _data__arccoth( const ParserChar* text, size_t textLength );
bool _end__arccoth(){return mImpl->end__arccoth();}
bool _preBegin__arccoth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arccoth();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arccoth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arccoth();
#endif
bool _freeAttributes__arccoth( void* attributeData );

bool _begin__arccsch( void* attributeData ){return mImpl->begin__arccsch(*static_cast<arccsch__AttributeData*>(attributeData));}
bool _data__arccsch( const ParserChar* text, size_t textLength );
bool _end__arccsch(){return mImpl->end__arccsch();}
bool _preBegin__arccsch( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arccsch();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arccsch( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arccsch();
#endif
bool _freeAttributes__arccsch( void* attributeData );

bool _begin__arcsech( void* attributeData ){return mImpl->begin__arcsech(*static_cast<arcsech__AttributeData*>(attributeData));}
bool _data__arcsech( const ParserChar* text, size_t textLength );
bool _end__arcsech(){return mImpl->end__arcsech();}
bool _preBegin__arcsech( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arcsech();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arcsech( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arcsech();
#endif
bool _freeAttributes__arcsech( void* attributeData );

bool _begin__arcsinh( void* attributeData ){return mImpl->begin__arcsinh(*static_cast<arcsinh__AttributeData*>(attributeData));}
bool _data__arcsinh( const ParserChar* text, size_t textLength );
bool _end__arcsinh(){return mImpl->end__arcsinh();}
bool _preBegin__arcsinh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arcsinh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arcsinh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arcsinh();
#endif
bool _freeAttributes__arcsinh( void* attributeData );

bool _begin__arctanh( void* attributeData ){return mImpl->begin__arctanh(*static_cast<arctanh__AttributeData*>(attributeData));}
bool _data__arctanh( const ParserChar* text, size_t textLength );
bool _end__arctanh(){return mImpl->end__arctanh();}
bool _preBegin__arctanh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__arctanh();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__arctanh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__arctanh();
#endif
bool _freeAttributes__arctanh( void* attributeData );

bool _begin__int____int_type____mathml( void* attributeData ){return mImpl->begin__int____int_type____mathml(*static_cast<int____int_type____mathml__AttributeData*>(attributeData));}
bool _data__int____int_type____mathml( const ParserChar* text, size_t textLength );
bool _end__int____int_type____mathml(){return mImpl->end__int____int_type____mathml();}
bool _preBegin__int____int_type____mathml( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__int____int_type____mathml();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__int____int_type____mathml( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int____int_type____mathml();
#endif
bool _freeAttributes__int____int_type____mathml( void* attributeData );

bool _begin__diff( void* attributeData ){return mImpl->begin__diff(*static_cast<diff__AttributeData*>(attributeData));}
bool _data__diff( const ParserChar* text, size_t textLength );
bool _end__diff(){return mImpl->end__diff();}
bool _preBegin__diff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__diff();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__diff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__diff();
#endif
bool _freeAttributes__diff( void* attributeData );

bool _begin__partialdiff( void* attributeData ){return mImpl->begin__partialdiff(*static_cast<partialdiff__AttributeData*>(attributeData));}
bool _data__partialdiff( const ParserChar* text, size_t textLength );
bool _end__partialdiff(){return mImpl->end__partialdiff();}
bool _preBegin__partialdiff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__partialdiff();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__partialdiff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__partialdiff();
#endif
bool _freeAttributes__partialdiff( void* attributeData );

bool _begin__limit( void* attributeData ){return mImpl->begin__limit(*static_cast<limit__AttributeData*>(attributeData));}
bool _data__limit( const ParserChar* text, size_t textLength );
bool _end__limit(){return mImpl->end__limit();}
bool _preBegin__limit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__limit();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__limit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__limit();
#endif
bool _freeAttributes__limit( void* attributeData );

bool _begin__lowlimit( void* attributeData ){return mImpl->begin__lowlimit(*static_cast<lowlimit__AttributeData*>(attributeData));}
bool _data__lowlimit( const ParserChar* text, size_t textLength );
bool _end__lowlimit(){return mImpl->end__lowlimit();}
bool _preBegin__lowlimit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lowlimit();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lowlimit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lowlimit();
#endif
bool _freeAttributes__lowlimit( void* attributeData );

bool _begin__uplimit( void* attributeData ){return mImpl->begin__uplimit(*static_cast<uplimit__AttributeData*>(attributeData));}
bool _data__uplimit( const ParserChar* text, size_t textLength );
bool _end__uplimit(){return mImpl->end__uplimit();}
bool _preBegin__uplimit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__uplimit();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__uplimit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__uplimit();
#endif
bool _freeAttributes__uplimit( void* attributeData );

bool _begin__tendsto( void* attributeData ){return mImpl->begin__tendsto(*static_cast<tendsto__AttributeData*>(attributeData));}
bool _data__tendsto( const ParserChar* text, size_t textLength );
bool _end__tendsto(){return mImpl->end__tendsto();}
bool _preBegin__tendsto( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__tendsto();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__tendsto( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tendsto();
#endif
bool _freeAttributes__tendsto( void* attributeData );

bool _begin__vector( void* attributeData ){return mImpl->begin__vector(*static_cast<vector__AttributeData*>(attributeData));}
bool _data__vector( const ParserChar* text, size_t textLength );
bool _end__vector(){return mImpl->end__vector();}
bool _preBegin__vector( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vector();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vector( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vector();
#endif
bool _freeAttributes__vector( void* attributeData );

bool _begin__matrix____matrix_type____mathml( void* attributeData ){return mImpl->begin__matrix____matrix_type____mathml(*static_cast<matrix____matrix_type____mathml__AttributeData*>(attributeData));}
bool _data__matrix____matrix_type____mathml( const ParserChar* text, size_t textLength );
bool _end__matrix____matrix_type____mathml(){return mImpl->end__matrix____matrix_type____mathml();}
bool _preBegin__matrix____matrix_type____mathml( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__matrix____matrix_type____mathml();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__matrix____matrix_type____mathml( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__matrix____matrix_type____mathml();
#endif
bool _freeAttributes__matrix____matrix_type____mathml( void* attributeData );

bool _begin__matrixrow( void* attributeData ){return mImpl->begin__matrixrow(*static_cast<matrixrow__AttributeData*>(attributeData));}
bool _data__matrixrow( const ParserChar* text, size_t textLength );
bool _end__matrixrow(){return mImpl->end__matrixrow();}
bool _preBegin__matrixrow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__matrixrow();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__matrixrow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__matrixrow();
#endif
bool _freeAttributes__matrixrow( void* attributeData );

bool _begin__determinant( void* attributeData ){return mImpl->begin__determinant(*static_cast<determinant__AttributeData*>(attributeData));}
bool _data__determinant( const ParserChar* text, size_t textLength );
bool _end__determinant(){return mImpl->end__determinant();}
bool _preBegin__determinant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__determinant();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__determinant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__determinant();
#endif
bool _freeAttributes__determinant( void* attributeData );

bool _begin__transpose( void* attributeData ){return mImpl->begin__transpose(*static_cast<transpose__AttributeData*>(attributeData));}
bool _data__transpose( const ParserChar* text, size_t textLength );
bool _end__transpose(){return mImpl->end__transpose();}
bool _preBegin__transpose( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__transpose();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__transpose( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__transpose();
#endif
bool _freeAttributes__transpose( void* attributeData );

bool _begin__selector( void* attributeData ){return mImpl->begin__selector(*static_cast<selector__AttributeData*>(attributeData));}
bool _data__selector( const ParserChar* text, size_t textLength );
bool _end__selector(){return mImpl->end__selector();}
bool _preBegin__selector( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__selector();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__selector( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__selector();
#endif
bool _freeAttributes__selector( void* attributeData );

bool _begin__vectorproduct( void* attributeData ){return mImpl->begin__vectorproduct(*static_cast<vectorproduct__AttributeData*>(attributeData));}
bool _data__vectorproduct( const ParserChar* text, size_t textLength );
bool _end__vectorproduct(){return mImpl->end__vectorproduct();}
bool _preBegin__vectorproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__vectorproduct();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__vectorproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vectorproduct();
#endif
bool _freeAttributes__vectorproduct( void* attributeData );

bool _begin__scalarproduct( void* attributeData ){return mImpl->begin__scalarproduct(*static_cast<scalarproduct__AttributeData*>(attributeData));}
bool _data__scalarproduct( const ParserChar* text, size_t textLength );
bool _end__scalarproduct(){return mImpl->end__scalarproduct();}
bool _preBegin__scalarproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__scalarproduct();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__scalarproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__scalarproduct();
#endif
bool _freeAttributes__scalarproduct( void* attributeData );

bool _begin__outerproduct( void* attributeData ){return mImpl->begin__outerproduct(*static_cast<outerproduct__AttributeData*>(attributeData));}
bool _data__outerproduct( const ParserChar* text, size_t textLength );
bool _end__outerproduct(){return mImpl->end__outerproduct();}
bool _preBegin__outerproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__outerproduct();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__outerproduct( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__outerproduct();
#endif
bool _freeAttributes__outerproduct( void* attributeData );

bool _begin__divergence( void* attributeData ){return mImpl->begin__divergence(*static_cast<divergence__AttributeData*>(attributeData));}
bool _data__divergence( const ParserChar* text, size_t textLength );
bool _end__divergence(){return mImpl->end__divergence();}
bool _preBegin__divergence( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__divergence();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__divergence( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__divergence();
#endif
bool _freeAttributes__divergence( void* attributeData );

bool _begin__grad( void* attributeData ){return mImpl->begin__grad(*static_cast<grad__AttributeData*>(attributeData));}
bool _data__grad( const ParserChar* text, size_t textLength );
bool _end__grad(){return mImpl->end__grad();}
bool _preBegin__grad( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__grad();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__grad( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__grad();
#endif
bool _freeAttributes__grad( void* attributeData );

bool _begin__curl( void* attributeData ){return mImpl->begin__curl(*static_cast<curl__AttributeData*>(attributeData));}
bool _data__curl( const ParserChar* text, size_t textLength );
bool _end__curl(){return mImpl->end__curl();}
bool _preBegin__curl( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__curl();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__curl( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__curl();
#endif
bool _freeAttributes__curl( void* attributeData );

bool _begin__laplacian( void* attributeData ){return mImpl->begin__laplacian(*static_cast<laplacian__AttributeData*>(attributeData));}
bool _data__laplacian( const ParserChar* text, size_t textLength );
bool _end__laplacian(){return mImpl->end__laplacian();}
bool _preBegin__laplacian( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__laplacian();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__laplacian( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__laplacian();
#endif
bool _freeAttributes__laplacian( void* attributeData );

bool _begin__mean( void* attributeData ){return mImpl->begin__mean(*static_cast<mean__AttributeData*>(attributeData));}
bool _data__mean( const ParserChar* text, size_t textLength );
bool _end__mean(){return mImpl->end__mean();}
bool _preBegin__mean( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mean();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mean( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mean();
#endif
bool _freeAttributes__mean( void* attributeData );

bool _begin__sdev( void* attributeData ){return mImpl->begin__sdev(*static_cast<sdev__AttributeData*>(attributeData));}
bool _data__sdev( const ParserChar* text, size_t textLength );
bool _end__sdev(){return mImpl->end__sdev();}
bool _preBegin__sdev( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sdev();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sdev( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sdev();
#endif
bool _freeAttributes__sdev( void* attributeData );

bool _begin__variance( void* attributeData ){return mImpl->begin__variance(*static_cast<variance__AttributeData*>(attributeData));}
bool _data__variance( const ParserChar* text, size_t textLength );
bool _end__variance(){return mImpl->end__variance();}
bool _preBegin__variance( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__variance();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__variance( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__variance();
#endif
bool _freeAttributes__variance( void* attributeData );

bool _begin__median( void* attributeData ){return mImpl->begin__median(*static_cast<median__AttributeData*>(attributeData));}
bool _data__median( const ParserChar* text, size_t textLength );
bool _end__median(){return mImpl->end__median();}
bool _preBegin__median( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__median();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__median( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__median();
#endif
bool _freeAttributes__median( void* attributeData );

bool _begin__mode____mode_type( void* attributeData ){return mImpl->begin__mode____mode_type(*static_cast<mode____mode_type__AttributeData*>(attributeData));}
bool _data__mode____mode_type( const ParserChar* text, size_t textLength );
bool _end__mode____mode_type(){return mImpl->end__mode____mode_type();}
bool _preBegin__mode____mode_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__mode____mode_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__mode____mode_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mode____mode_type();
#endif
bool _freeAttributes__mode____mode_type( void* attributeData );

bool _begin__moment( void* attributeData ){return mImpl->begin__moment(*static_cast<moment__AttributeData*>(attributeData));}
bool _data__moment( const ParserChar* text, size_t textLength );
bool _end__moment(){return mImpl->end__moment();}
bool _preBegin__moment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__moment();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__moment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__moment();
#endif
bool _freeAttributes__moment( void* attributeData );

bool _begin__momentabout( void* attributeData ){return mImpl->begin__momentabout(*static_cast<momentabout__AttributeData*>(attributeData));}
bool _data__momentabout( const ParserChar* text, size_t textLength );
bool _end__momentabout(){return mImpl->end__momentabout();}
bool _preBegin__momentabout( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__momentabout();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__momentabout( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__momentabout();
#endif
bool _freeAttributes__momentabout( void* attributeData );

bool _begin__apply( void* attributeData ){return mImpl->begin__apply(*static_cast<apply__AttributeData*>(attributeData));}
bool _data__apply( const ParserChar* text, size_t textLength );
bool _end__apply(){return mImpl->end__apply();}
bool _preBegin__apply( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__apply();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__apply( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__apply();
#endif
bool _freeAttributes__apply( void* attributeData );

bool _begin__interval( void* attributeData ){return mImpl->begin__interval(*static_cast<interval__AttributeData*>(attributeData));}
bool _data__interval( const ParserChar* text, size_t textLength );
bool _end__interval(){return mImpl->end__interval();}
bool _preBegin__interval( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__interval();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__interval( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__interval();
#endif
bool _freeAttributes__interval( void* attributeData );


ENUM__mathml__interval__closure toEnumDataPrefix_ENUM__mathml__interval__closure (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__interval__closure>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__mathml__interval__closure (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__interval__closure*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__mathml__interval__closure (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__interval__closure*, size_t ),
    const std::pair<StringHash, ENUM__mathml__interval__closure>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__mathml__interval__closure (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__mathml__interval__closure>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__inverse( void* attributeData ){return mImpl->begin__inverse(*static_cast<inverse__AttributeData*>(attributeData));}
bool _data__inverse( const ParserChar* text, size_t textLength );
bool _end__inverse(){return mImpl->end__inverse();}
bool _preBegin__inverse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__inverse();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__inverse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__inverse();
#endif
bool _freeAttributes__inverse( void* attributeData );

bool _begin__condition( void* attributeData ){return mImpl->begin__condition(*static_cast<condition__AttributeData*>(attributeData));}
bool _data__condition( const ParserChar* text, size_t textLength );
bool _end__condition(){return mImpl->end__condition();}
bool _preBegin__condition( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__condition();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__condition( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__condition();
#endif
bool _freeAttributes__condition( void* attributeData );

bool _begin__declare( void* attributeData ){return mImpl->begin__declare(*static_cast<declare__AttributeData*>(attributeData));}
bool _data__declare( const ParserChar* text, size_t textLength );
bool _end__declare(){return mImpl->end__declare();}
bool _preBegin__declare( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__declare();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__declare( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__declare();
#endif
bool _freeAttributes__declare( void* attributeData );


ENUM__mathml__declare__occurrence toEnumDataPrefix_ENUM__mathml__declare__occurrence (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__declare__occurrence>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__mathml__declare__occurrence (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__declare__occurrence*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__mathml__declare__occurrence (
    bool ( ColladaParserAutoGen15::*dataFunction )(const ENUM__mathml__declare__occurrence*, size_t ),
    const std::pair<StringHash, ENUM__mathml__declare__occurrence>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__mathml__declare__occurrence (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__mathml__declare__occurrence>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__lambda( void* attributeData ){return mImpl->begin__lambda(*static_cast<lambda__AttributeData*>(attributeData));}
bool _data__lambda( const ParserChar* text, size_t textLength );
bool _end__lambda(){return mImpl->end__lambda();}
bool _preBegin__lambda( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__lambda();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__lambda( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lambda();
#endif
bool _freeAttributes__lambda( void* attributeData );

bool _begin__piecewise( void* attributeData ){return mImpl->begin__piecewise(*static_cast<piecewise__AttributeData*>(attributeData));}
bool _data__piecewise( const ParserChar* text, size_t textLength );
bool _end__piecewise(){return mImpl->end__piecewise();}
bool _preBegin__piecewise( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__piecewise();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__piecewise( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__piecewise();
#endif
bool _freeAttributes__piecewise( void* attributeData );

bool _begin__piece( void* attributeData ){return mImpl->begin__piece();}
bool _data__piece( const ParserChar* text, size_t textLength );
bool _end__piece(){return mImpl->end__piece();}
bool _preBegin__piece( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__piece();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__piece( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__piece();
#endif
bool _freeAttributes__piece( void* attributeData );

bool _begin__bvar( void* attributeData ){return mImpl->begin__bvar(*static_cast<bvar__AttributeData*>(attributeData));}
bool _data__bvar( const ParserChar* text, size_t textLength );
bool _end__bvar(){return mImpl->end__bvar();}
bool _preBegin__bvar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bvar();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bvar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bvar();
#endif
bool _freeAttributes__bvar( void* attributeData );

bool _begin__degree( void* attributeData ){return mImpl->begin__degree(*static_cast<degree__AttributeData*>(attributeData));}
bool _data__degree( const ParserChar* text, size_t textLength );
bool _end__degree(){return mImpl->end__degree();}
bool _preBegin__degree( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__degree();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__degree( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__degree();
#endif
bool _freeAttributes__degree( void* attributeData );

bool _begin__semantics( void* attributeData ){return mImpl->begin__semantics(*static_cast<semantics__AttributeData*>(attributeData));}
bool _data__semantics( const ParserChar* text, size_t textLength );
bool _end__semantics(){return mImpl->end__semantics();}
bool _preBegin__semantics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__semantics();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__semantics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__semantics();
#endif
bool _freeAttributes__semantics( void* attributeData );

bool _begin__annotation( void* attributeData ){return mImpl->begin__annotation(*static_cast<annotation__AttributeData*>(attributeData));}
bool _data__annotation( const ParserChar* text, size_t textLength );
bool _end__annotation(){return mImpl->end__annotation();}
bool _preBegin__annotation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__annotation();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__annotation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__annotation();
#endif
bool _freeAttributes__annotation( void* attributeData );

bool _begin__annotation_xml( void* attributeData ){return mImpl->begin__annotation_xml(*static_cast<annotation_xml__AttributeData*>(attributeData));}
bool _data__annotation_xml( const ParserChar* text, size_t textLength );
bool _end__annotation_xml(){return mImpl->end__annotation_xml();}
bool _preBegin__annotation_xml( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__annotation_xml();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__annotation_xml( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__annotation_xml();
#endif
bool _freeAttributes__annotation_xml( void* attributeData );

bool _begin__otherwise( void* attributeData ){return mImpl->begin__otherwise(*static_cast<otherwise__AttributeData*>(attributeData));}
bool _data__otherwise( const ParserChar* text, size_t textLength );
bool _end__otherwise(){return mImpl->end__otherwise();}
bool _preBegin__otherwise( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__otherwise();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__otherwise( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__otherwise();
#endif
bool _freeAttributes__otherwise( void* attributeData );

bool _begin__sep( void* attributeData ){return mImpl->begin__sep();}
bool _data__sep( const ParserChar* text, size_t textLength );
bool _end__sep(){return mImpl->end__sep();}
bool _preBegin__sep( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__sep();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__sep( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sep();
#endif
bool _freeAttributes__sep( void* attributeData );

bool _begin__library_articulated_systems( void* attributeData ){return mImpl->begin__library_articulated_systems(*static_cast<library_articulated_systems__AttributeData*>(attributeData));}
bool _data__library_articulated_systems( const ParserChar* text, size_t textLength );
bool _end__library_articulated_systems(){return mImpl->end__library_articulated_systems();}
bool _preBegin__library_articulated_systems( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_articulated_systems();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_articulated_systems( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_articulated_systems();
#endif
bool _freeAttributes__library_articulated_systems( void* attributeData );

bool _begin__articulated_system( void* attributeData ){return mImpl->begin__articulated_system(*static_cast<articulated_system__AttributeData*>(attributeData));}
bool _data__articulated_system( const ParserChar* text, size_t textLength );
bool _end__articulated_system(){return mImpl->end__articulated_system();}
bool _preBegin__articulated_system( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__articulated_system();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__articulated_system( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__articulated_system();
#endif
bool _freeAttributes__articulated_system( void* attributeData );

bool _begin__kinematics( void* attributeData ){return mImpl->begin__kinematics();}
bool _data__kinematics( const ParserChar* text, size_t textLength );
bool _end__kinematics(){return mImpl->end__kinematics();}
bool _preBegin__kinematics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__kinematics();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__kinematics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__kinematics();
#endif
bool _freeAttributes__kinematics( void* attributeData );

bool _begin__instance_kinematics_model( void* attributeData ){return mImpl->begin__instance_kinematics_model(*static_cast<instance_kinematics_model__AttributeData*>(attributeData));}
bool _data__instance_kinematics_model( const ParserChar* text, size_t textLength );
bool _end__instance_kinematics_model(){return mImpl->end__instance_kinematics_model();}
bool _preBegin__instance_kinematics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_kinematics_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_kinematics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_kinematics_model();
#endif
bool _freeAttributes__instance_kinematics_model( void* attributeData );

bool _begin__bind____kinematics_bind_type( void* attributeData ){return mImpl->begin__bind____kinematics_bind_type(*static_cast<bind____kinematics_bind_type__AttributeData*>(attributeData));}
bool _data__bind____kinematics_bind_type( const ParserChar* text, size_t textLength );
bool _end__bind____kinematics_bind_type(){return mImpl->end__bind____kinematics_bind_type();}
bool _preBegin__bind____kinematics_bind_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind____kinematics_bind_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind____kinematics_bind_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind____kinematics_bind_type();
#endif
bool _freeAttributes__bind____kinematics_bind_type( void* attributeData );

bool _begin__param____kinematics_param_type( void* attributeData ){return mImpl->begin__param____kinematics_param_type(*static_cast<param____kinematics_param_type__AttributeData*>(attributeData));}
bool _data__param____kinematics_param_type( const ParserChar* text, size_t textLength );
bool _end__param____kinematics_param_type(){return mImpl->end__param____kinematics_param_type();}
bool _preBegin__param____kinematics_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__param____kinematics_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__param____kinematics_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__param____kinematics_param_type();
#endif
bool _freeAttributes__param____kinematics_param_type( void* attributeData );

bool _begin__setparam____kinematics_setparam_type( void* attributeData ){return mImpl->begin__setparam____kinematics_setparam_type(*static_cast<setparam____kinematics_setparam_type__AttributeData*>(attributeData));}
bool _data__setparam____kinematics_setparam_type( const ParserChar* text, size_t textLength );
bool _end__setparam____kinematics_setparam_type(){return mImpl->end__setparam____kinematics_setparam_type();}
bool _preBegin__setparam____kinematics_setparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__setparam____kinematics_setparam_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__setparam____kinematics_setparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____kinematics_setparam_type();
#endif
bool _freeAttributes__setparam____kinematics_setparam_type( void* attributeData );

bool _begin__technique_common____kinematics_technique_type( void* attributeData ){return mImpl->begin__technique_common____kinematics_technique_type();}
bool _data__technique_common____kinematics_technique_type( const ParserChar* text, size_t textLength );
bool _end__technique_common____kinematics_technique_type(){return mImpl->end__technique_common____kinematics_technique_type();}
bool _preBegin__technique_common____kinematics_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique_common____kinematics_technique_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique_common____kinematics_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_common____kinematics_technique_type();
#endif
bool _freeAttributes__technique_common____kinematics_technique_type( void* attributeData );

bool _begin__axis_info____kinematics_axis_info_type( void* attributeData ){return mImpl->begin__axis_info____kinematics_axis_info_type(*static_cast<axis_info____kinematics_axis_info_type__AttributeData*>(attributeData));}
bool _data__axis_info____kinematics_axis_info_type( const ParserChar* text, size_t textLength );
bool _end__axis_info____kinematics_axis_info_type(){return mImpl->end__axis_info____kinematics_axis_info_type();}
bool _preBegin__axis_info____kinematics_axis_info_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__axis_info____kinematics_axis_info_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__axis_info____kinematics_axis_info_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__axis_info____kinematics_axis_info_type();
#endif
bool _freeAttributes__axis_info____kinematics_axis_info_type( void* attributeData );

bool _begin__active( void* attributeData ){return mImpl->begin__active();}
bool _data__active( const ParserChar* text, size_t textLength );
bool _end__active(){return mImpl->end__active();}
bool _preBegin__active( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__active();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__active( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__active();
#endif
bool _freeAttributes__active( void* attributeData );

bool _begin__locked( void* attributeData ){return mImpl->begin__locked();}
bool _data__locked( const ParserChar* text, size_t textLength );
bool _end__locked(){return mImpl->end__locked();}
bool _preBegin__locked( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__locked();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__locked( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__locked();
#endif
bool _freeAttributes__locked( void* attributeData );

bool _begin__index( void* attributeData ){return mImpl->begin__index(*static_cast<index__AttributeData*>(attributeData));}
bool _data__index( const ParserChar* text, size_t textLength );
bool _end__index(){return mImpl->end__index();}
bool _preBegin__index( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__index();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__index( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__index();
#endif
bool _freeAttributes__index( void* attributeData );

bool _begin__limits____kinematics_limits_type( void* attributeData ){return mImpl->begin__limits____kinematics_limits_type();}
bool _data__limits____kinematics_limits_type( const ParserChar* text, size_t textLength );
bool _end__limits____kinematics_limits_type(){return mImpl->end__limits____kinematics_limits_type();}
bool _preBegin__limits____kinematics_limits_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__limits____kinematics_limits_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__limits____kinematics_limits_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__limits____kinematics_limits_type();
#endif
bool _freeAttributes__limits____kinematics_limits_type( void* attributeData );

bool _begin__min____common_float_or_param_type( void* attributeData ){return mImpl->begin__min____common_float_or_param_type();}
bool _data__min____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__min____common_float_or_param_type(){return mImpl->end__min____common_float_or_param_type();}
bool _preBegin__min____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__min____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__min____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__min____common_float_or_param_type();
#endif
bool _freeAttributes__min____common_float_or_param_type( void* attributeData );

bool _begin__max____common_float_or_param_type( void* attributeData ){return mImpl->begin__max____common_float_or_param_type();}
bool _data__max____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__max____common_float_or_param_type(){return mImpl->end__max____common_float_or_param_type();}
bool _preBegin__max____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__max____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__max____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__max____common_float_or_param_type();
#endif
bool _freeAttributes__max____common_float_or_param_type( void* attributeData );

bool _begin__frame_origin( void* attributeData ){return mImpl->begin__frame_origin(*static_cast<frame_origin__AttributeData*>(attributeData));}
bool _data__frame_origin( const ParserChar* text, size_t textLength );
bool _end__frame_origin(){return mImpl->end__frame_origin();}
bool _preBegin__frame_origin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__frame_origin();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__frame_origin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__frame_origin();
#endif
bool _freeAttributes__frame_origin( void* attributeData );

bool _begin__frame_tip( void* attributeData ){return mImpl->begin__frame_tip(*static_cast<frame_tip__AttributeData*>(attributeData));}
bool _data__frame_tip( const ParserChar* text, size_t textLength );
bool _end__frame_tip(){return mImpl->end__frame_tip();}
bool _preBegin__frame_tip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__frame_tip();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__frame_tip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__frame_tip();
#endif
bool _freeAttributes__frame_tip( void* attributeData );

bool _begin__frame_tcp( void* attributeData ){return mImpl->begin__frame_tcp(*static_cast<frame_tcp__AttributeData*>(attributeData));}
bool _data__frame_tcp( const ParserChar* text, size_t textLength );
bool _end__frame_tcp(){return mImpl->end__frame_tcp();}
bool _preBegin__frame_tcp( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__frame_tcp();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__frame_tcp( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__frame_tcp();
#endif
bool _freeAttributes__frame_tcp( void* attributeData );

bool _begin__frame_object( void* attributeData ){return mImpl->begin__frame_object(*static_cast<frame_object__AttributeData*>(attributeData));}
bool _data__frame_object( const ParserChar* text, size_t textLength );
bool _end__frame_object(){return mImpl->end__frame_object();}
bool _preBegin__frame_object( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__frame_object();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__frame_object( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__frame_object();
#endif
bool _freeAttributes__frame_object( void* attributeData );

bool _begin__motion( void* attributeData ){return mImpl->begin__motion();}
bool _data__motion( const ParserChar* text, size_t textLength );
bool _end__motion(){return mImpl->end__motion();}
bool _preBegin__motion( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__motion();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__motion( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__motion();
#endif
bool _freeAttributes__motion( void* attributeData );

bool _begin__instance_articulated_system( void* attributeData ){return mImpl->begin__instance_articulated_system(*static_cast<instance_articulated_system__AttributeData*>(attributeData));}
bool _data__instance_articulated_system( const ParserChar* text, size_t textLength );
bool _end__instance_articulated_system(){return mImpl->end__instance_articulated_system();}
bool _preBegin__instance_articulated_system( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_articulated_system();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_articulated_system( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_articulated_system();
#endif
bool _freeAttributes__instance_articulated_system( void* attributeData );

bool _begin__technique_common____motion_technique_type( void* attributeData ){return mImpl->begin__technique_common____motion_technique_type();}
bool _data__technique_common____motion_technique_type( const ParserChar* text, size_t textLength );
bool _end__technique_common____motion_technique_type(){return mImpl->end__technique_common____motion_technique_type();}
bool _preBegin__technique_common____motion_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__technique_common____motion_technique_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__technique_common____motion_technique_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_common____motion_technique_type();
#endif
bool _freeAttributes__technique_common____motion_technique_type( void* attributeData );

bool _begin__axis_info____motion_axis_info_type( void* attributeData ){return mImpl->begin__axis_info____motion_axis_info_type(*static_cast<axis_info____motion_axis_info_type__AttributeData*>(attributeData));}
bool _data__axis_info____motion_axis_info_type( const ParserChar* text, size_t textLength );
bool _end__axis_info____motion_axis_info_type(){return mImpl->end__axis_info____motion_axis_info_type();}
bool _preBegin__axis_info____motion_axis_info_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__axis_info____motion_axis_info_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__axis_info____motion_axis_info_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__axis_info____motion_axis_info_type();
#endif
bool _freeAttributes__axis_info____motion_axis_info_type( void* attributeData );

bool _begin__speed____common_float_or_param_type( void* attributeData ){return mImpl->begin__speed____common_float_or_param_type();}
bool _data__speed____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__speed____common_float_or_param_type(){return mImpl->end__speed____common_float_or_param_type();}
bool _preBegin__speed____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__speed____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__speed____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__speed____common_float_or_param_type();
#endif
bool _freeAttributes__speed____common_float_or_param_type( void* attributeData );

bool _begin__acceleration____common_float_or_param_type( void* attributeData ){return mImpl->begin__acceleration____common_float_or_param_type();}
bool _data__acceleration____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__acceleration____common_float_or_param_type(){return mImpl->end__acceleration____common_float_or_param_type();}
bool _preBegin__acceleration____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__acceleration____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__acceleration____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__acceleration____common_float_or_param_type();
#endif
bool _freeAttributes__acceleration____common_float_or_param_type( void* attributeData );

bool _begin__deceleration____common_float_or_param_type( void* attributeData ){return mImpl->begin__deceleration____common_float_or_param_type();}
bool _data__deceleration____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__deceleration____common_float_or_param_type(){return mImpl->end__deceleration____common_float_or_param_type();}
bool _preBegin__deceleration____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__deceleration____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__deceleration____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__deceleration____common_float_or_param_type();
#endif
bool _freeAttributes__deceleration____common_float_or_param_type( void* attributeData );

bool _begin__jerk____common_float_or_param_type( void* attributeData ){return mImpl->begin__jerk____common_float_or_param_type();}
bool _data__jerk____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__jerk____common_float_or_param_type(){return mImpl->end__jerk____common_float_or_param_type();}
bool _preBegin__jerk____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__jerk____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__jerk____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__jerk____common_float_or_param_type();
#endif
bool _freeAttributes__jerk____common_float_or_param_type( void* attributeData );

bool _begin__effector_info( void* attributeData ){return mImpl->begin__effector_info(*static_cast<effector_info__AttributeData*>(attributeData));}
bool _data__effector_info( const ParserChar* text, size_t textLength );
bool _end__effector_info(){return mImpl->end__effector_info();}
bool _preBegin__effector_info( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__effector_info();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__effector_info( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__effector_info();
#endif
bool _freeAttributes__effector_info( void* attributeData );

bool _begin__speed____common_float2_or_param_type( void* attributeData ){return mImpl->begin__speed____common_float2_or_param_type();}
bool _data__speed____common_float2_or_param_type( const ParserChar* text, size_t textLength );
bool _end__speed____common_float2_or_param_type(){return mImpl->end__speed____common_float2_or_param_type();}
bool _preBegin__speed____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__speed____common_float2_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__speed____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__speed____common_float2_or_param_type();
#endif
bool _freeAttributes__speed____common_float2_or_param_type( void* attributeData );

bool _begin__acceleration____common_float2_or_param_type( void* attributeData ){return mImpl->begin__acceleration____common_float2_or_param_type();}
bool _data__acceleration____common_float2_or_param_type( const ParserChar* text, size_t textLength );
bool _end__acceleration____common_float2_or_param_type(){return mImpl->end__acceleration____common_float2_or_param_type();}
bool _preBegin__acceleration____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__acceleration____common_float2_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__acceleration____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__acceleration____common_float2_or_param_type();
#endif
bool _freeAttributes__acceleration____common_float2_or_param_type( void* attributeData );

bool _begin__deceleration____common_float2_or_param_type( void* attributeData ){return mImpl->begin__deceleration____common_float2_or_param_type();}
bool _data__deceleration____common_float2_or_param_type( const ParserChar* text, size_t textLength );
bool _end__deceleration____common_float2_or_param_type(){return mImpl->end__deceleration____common_float2_or_param_type();}
bool _preBegin__deceleration____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__deceleration____common_float2_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__deceleration____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__deceleration____common_float2_or_param_type();
#endif
bool _freeAttributes__deceleration____common_float2_or_param_type( void* attributeData );

bool _begin__jerk____common_float2_or_param_type( void* attributeData ){return mImpl->begin__jerk____common_float2_or_param_type();}
bool _data__jerk____common_float2_or_param_type( const ParserChar* text, size_t textLength );
bool _end__jerk____common_float2_or_param_type(){return mImpl->end__jerk____common_float2_or_param_type();}
bool _preBegin__jerk____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__jerk____common_float2_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__jerk____common_float2_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__jerk____common_float2_or_param_type();
#endif
bool _freeAttributes__jerk____common_float2_or_param_type( void* attributeData );

bool _begin__library_kinematics_scenes( void* attributeData ){return mImpl->begin__library_kinematics_scenes(*static_cast<library_kinematics_scenes__AttributeData*>(attributeData));}
bool _data__library_kinematics_scenes( const ParserChar* text, size_t textLength );
bool _end__library_kinematics_scenes(){return mImpl->end__library_kinematics_scenes();}
bool _preBegin__library_kinematics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_kinematics_scenes();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_kinematics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_kinematics_scenes();
#endif
bool _freeAttributes__library_kinematics_scenes( void* attributeData );

bool _begin__kinematics_scene( void* attributeData ){return mImpl->begin__kinematics_scene(*static_cast<kinematics_scene__AttributeData*>(attributeData));}
bool _data__kinematics_scene( const ParserChar* text, size_t textLength );
bool _end__kinematics_scene(){return mImpl->end__kinematics_scene();}
bool _preBegin__kinematics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__kinematics_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__kinematics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__kinematics_scene();
#endif
bool _freeAttributes__kinematics_scene( void* attributeData );

bool _begin__library_formulas( void* attributeData ){return mImpl->begin__library_formulas(*static_cast<library_formulas__AttributeData*>(attributeData));}
bool _data__library_formulas( const ParserChar* text, size_t textLength );
bool _end__library_formulas(){return mImpl->end__library_formulas();}
bool _preBegin__library_formulas( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__library_formulas();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__library_formulas( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_formulas();
#endif
bool _freeAttributes__library_formulas( void* attributeData );

bool _begin__scene( void* attributeData ){return mImpl->begin__scene();}
bool _data__scene( const ParserChar* text, size_t textLength );
bool _end__scene(){return mImpl->end__scene();}
bool _preBegin__scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__scene();
#endif
bool _freeAttributes__scene( void* attributeData );

bool _begin__instance_physics_scene( void* attributeData ){return mImpl->begin__instance_physics_scene(*static_cast<instance_physics_scene__AttributeData*>(attributeData));}
bool _data__instance_physics_scene( const ParserChar* text, size_t textLength );
bool _end__instance_physics_scene(){return mImpl->end__instance_physics_scene();}
bool _preBegin__instance_physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_physics_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_physics_scene();
#endif
bool _freeAttributes__instance_physics_scene( void* attributeData );

bool _begin__instance_visual_scene( void* attributeData ){return mImpl->begin__instance_visual_scene(*static_cast<instance_visual_scene__AttributeData*>(attributeData));}
bool _data__instance_visual_scene( const ParserChar* text, size_t textLength );
bool _end__instance_visual_scene(){return mImpl->end__instance_visual_scene();}
bool _preBegin__instance_visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_visual_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_visual_scene();
#endif
bool _freeAttributes__instance_visual_scene( void* attributeData );

bool _begin__instance_kinematics_scene( void* attributeData ){return mImpl->begin__instance_kinematics_scene(*static_cast<instance_kinematics_scene__AttributeData*>(attributeData));}
bool _data__instance_kinematics_scene( const ParserChar* text, size_t textLength );
bool _end__instance_kinematics_scene(){return mImpl->end__instance_kinematics_scene();}
bool _preBegin__instance_kinematics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__instance_kinematics_scene();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__instance_kinematics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_kinematics_scene();
#endif
bool _freeAttributes__instance_kinematics_scene( void* attributeData );

bool _begin__bind_kinematics_model( void* attributeData ){return mImpl->begin__bind_kinematics_model(*static_cast<bind_kinematics_model__AttributeData*>(attributeData));}
bool _data__bind_kinematics_model( const ParserChar* text, size_t textLength );
bool _end__bind_kinematics_model(){return mImpl->end__bind_kinematics_model();}
bool _preBegin__bind_kinematics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind_kinematics_model();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind_kinematics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_kinematics_model();
#endif
bool _freeAttributes__bind_kinematics_model( void* attributeData );

bool _begin__bind_joint_axis( void* attributeData ){return mImpl->begin__bind_joint_axis(*static_cast<bind_joint_axis__AttributeData*>(attributeData));}
bool _data__bind_joint_axis( const ParserChar* text, size_t textLength );
bool _end__bind_joint_axis(){return mImpl->end__bind_joint_axis();}
bool _preBegin__bind_joint_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__bind_joint_axis();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__bind_joint_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_joint_axis();
#endif
bool _freeAttributes__bind_joint_axis( void* attributeData );

bool _begin__axis____common_sidref_or_param_type( void* attributeData ){return mImpl->begin__axis____common_sidref_or_param_type();}
bool _data__axis____common_sidref_or_param_type( const ParserChar* text, size_t textLength );
bool _end__axis____common_sidref_or_param_type(){return mImpl->end__axis____common_sidref_or_param_type();}
bool _preBegin__axis____common_sidref_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__axis____common_sidref_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__axis____common_sidref_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__axis____common_sidref_or_param_type();
#endif
bool _freeAttributes__axis____common_sidref_or_param_type( void* attributeData );

bool _begin__value____common_float_or_param_type( void* attributeData ){return mImpl->begin__value____common_float_or_param_type();}
bool _data__value____common_float_or_param_type( const ParserChar* text, size_t textLength );
bool _end__value____common_float_or_param_type(){return mImpl->end__value____common_float_or_param_type();}
bool _preBegin__value____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _preEnd__value____common_float_or_param_type();
#ifdef GENERATEDSAXPARSER_VALIDATION
bool _validateBegin__value____common_float_or_param_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____common_float_or_param_type();
#endif
bool _freeAttributes__value____common_float_or_param_type( void* attributeData );



private:
/** Disable default copy ctor. */
ColladaParserAutoGen15Private( const ColladaParserAutoGen15Private& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGen15Private& operator= ( const ColladaParserAutoGen15Private& pre );

void initFunctionMap();
void initNameMap();

protected:
virtual bool findElementHash( ElementData& elementData );
virtual bool isXsAnyAllowed( const StringHash& elementHash );
virtual bool isDifferentNamespaceAllowed();

};

} // namespace
#endif
