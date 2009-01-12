#include "COLLADASaxFWLStableHeaders.h"
#include "GeneratedSaxParserUtils.h"

#include "COLLADASaxFWLColladaParserAutoGenPrivate.h"


namespace  COLLADASaxFWL
{


//---------------------------------------------------------------------
const char* ColladaParserAutoGenPrivate::PARENT_CHILD_ELEMENT_SEPARATOR = "__";


//---------------------------------------------------------------------
ColladaParserAutoGenPrivate::ColladaParserAutoGenPrivate( COLLADASaxFWL::ColladaParserAutoGen* impl, GeneratedSaxParser::IErrorHandler* errorHandler 
)    : ParserTemplate<ColladaParserAutoGenPrivate, ColladaParserAutoGen>(impl, errorHandler)
{
    initFunctionMap();
    initNameMap();
}

//---------------------------------------------------------------------
ColladaParserAutoGenPrivate::~ColladaParserAutoGenPrivate()
{
}


//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA = "COLLADA";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_VERSION = "version";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_BASE = "base";

//---------------------------------------------------------------------
const COLLADA__AttributeData COLLADA__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__COLLADA( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__COLLADA( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
COLLADA__AttributeData* attributeData = newData<COLLADA__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_VERSION:
    {

attributeData->version = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_BASE:
    {

attributeData->base = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_COLLADA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__COLLADA()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET = "asset";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__ASSET = "COLLADA__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__COLLADA__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__COLLADA__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__COLLADA__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTRIBUTOR = "contributor";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__CONTRIBUTOR = "asset__contributor";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__contributor( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__contributor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__contributor()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_AUTHOR = "author";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTRIBUTOR__AUTHOR = "contributor__author";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__author( const ParserChar* text, size_t textLength )
{

return mImpl->data__author(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__author( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__author()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_AUTHORING_TOOL = "authoring_tool";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTRIBUTOR__AUTHORING_TOOL = "contributor__authoring_tool";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__authoring_tool( const ParserChar* text, size_t textLength )
{

return mImpl->data__authoring_tool(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__authoring_tool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__authoring_tool()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COMMENTS = "comments";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTRIBUTOR__COMMENTS = "contributor__comments";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__comments( const ParserChar* text, size_t textLength )
{

return mImpl->data__comments(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__comments( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__comments()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COPYRIGHT = "copyright";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTRIBUTOR__COPYRIGHT = "contributor__copyright";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__copyright( const ParserChar* text, size_t textLength )
{

return mImpl->data__copyright(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__copyright( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__copyright()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE_DATA = "source_data";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTRIBUTOR__SOURCE_DATA = "contributor__source_data";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__source_data( const ParserChar* text, size_t textLength )
{

return mImpl->data__source_data(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__source_data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__source_data()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CREATED = "created";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__CREATED = "asset__created";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__created( const ParserChar* text, size_t textLength )
{

return mImpl->data__created(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__created( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__created()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_KEYWORDS = "keywords";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__KEYWORDS = "asset__keywords";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__keywords( const ParserChar* text, size_t textLength )
{

return mImpl->data__keywords(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__keywords( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__keywords()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MODIFIED = "modified";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__MODIFIED = "asset__modified";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__modified( const ParserChar* text, size_t textLength )
{

return mImpl->data__modified(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__modified( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__modified()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_REVISION = "revision";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__REVISION = "asset__revision";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__revision( const ParserChar* text, size_t textLength )
{

return mImpl->data__revision(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__revision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__revision()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SUBJECT = "subject";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__SUBJECT = "asset__subject";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__subject( const ParserChar* text, size_t textLength )
{

return mImpl->data__subject(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__subject( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__subject()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TITLE = "title";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__TITLE = "asset__title";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__title( const ParserChar* text, size_t textLength )
{

return mImpl->data__title(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__title( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__title()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_UNIT = "unit";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__UNIT = "asset__unit";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_METER = "meter";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_NAME = "name";

//---------------------------------------------------------------------
const unit__AttributeData unit__AttributeData::DEFAULT = {1.0E0, (const GeneratedSaxParser::ParserChar *)"meter"};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__unit( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
unit__AttributeData* attributeData = newData<unit__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_METER:
    {
bool failed;
attributeData->meter = GeneratedSaxParser::Utils::toDouble(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_UNIT, HASH_ATTRIBUTE_METER, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_UNIT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__unit()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_UP_AXIS = "up_axis";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASSET__UP_AXIS = "asset__up_axis";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__up_axis( const ParserChar* text, size_t textLength )
{

return mImpl->data__up_axis(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__up_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__up_axis()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATIONS = "library_animations";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_ANIMATIONS = "COLLADA__library_animations";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_ID = "id";

//---------------------------------------------------------------------
const library_animations__AttributeData library_animations__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animations( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animations( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_animations__AttributeData* attributeData = newData<library_animations__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_ANIMATIONS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animations()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__ASSET = "library_animations__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animations__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animations__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animations__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION = "animation";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__ANIMATION = "library_animations__animation";

//---------------------------------------------------------------------
const library_animations__animation__AttributeData library_animations__animation__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animations__animation( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animations__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_animations__animation__AttributeData* attributeData = newData<library_animations__animation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_ANIMATIONS__ANIMATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animations__animation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION__ASSET = "animation__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE = "source";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION__SOURCE = "animation__source";

//---------------------------------------------------------------------
const animation__source__AttributeData animation__source__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation__source( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
animation__source__AttributeData* attributeData = newData<animation__source__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANIMATION__SOURCE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__ASSET = "source__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__source__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__source__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__source__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IDREF_ARRAY = "IDREF_array";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__IDREF_ARRAY = "source__IDREF_array";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_COUNT = "count";

//---------------------------------------------------------------------
const IDREF_array__AttributeData IDREF_array__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__IDREF_array( const ParserChar* text, size_t textLength )
{
return mImpl->data__IDREF_array(text, textLength);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__IDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
IDREF_array__AttributeData* attributeData = newData<IDREF_array__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_IDREF_ARRAY, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_IDREF_ARRAY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__IDREF_array()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NAME_ARRAY = "Name_array";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__NAME_ARRAY = "source__Name_array";

//---------------------------------------------------------------------
const Name_array__AttributeData Name_array__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__Name_array( const ParserChar* text, size_t textLength )
{
return mImpl->data__Name_array(text, textLength);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__Name_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
Name_array__AttributeData* attributeData = newData<Name_array__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_NAME_ARRAY, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NAME_ARRAY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__Name_array()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOOL_ARRAY = "bool_array";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__BOOL_ARRAY = "source__bool_array";

//---------------------------------------------------------------------
const bool_array__AttributeData bool_array__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bool_array( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__bool_array);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bool_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
bool_array__AttributeData* attributeData = newData<bool_array__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_BOOL_ARRAY, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_BOOL_ARRAY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bool_array()
{
return boolDataEnd( &ColladaParserAutoGen::data__bool_array );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT_ARRAY = "float_array";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__FLOAT_ARRAY = "source__float_array";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_DIGITS = "digits";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_MAGNITUDE = "magnitude";

//---------------------------------------------------------------------
const float_array__AttributeData float_array__AttributeData::DEFAULT = {0, 0, 0, 6, 38};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__float_array( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__float_array);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__float_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
float_array__AttributeData* attributeData = newData<float_array__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_FLOAT_ARRAY, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_DIGITS:
    {
bool failed;
attributeData->digits = GeneratedSaxParser::Utils::toInt(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_FLOAT_ARRAY, HASH_ATTRIBUTE_DIGITS, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MAGNITUDE:
    {
bool failed;
attributeData->magnitude = GeneratedSaxParser::Utils::toInt(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_FLOAT_ARRAY, HASH_ATTRIBUTE_MAGNITUDE, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FLOAT_ARRAY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__float_array()
{
return doubleDataEnd( &ColladaParserAutoGen::data__float_array );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INT_ARRAY = "int_array";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__INT_ARRAY = "source__int_array";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_MININCLUSIVE = "minInclusive";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_MAXINCLUSIVE = "maxInclusive";

//---------------------------------------------------------------------
const int_array__AttributeData int_array__AttributeData::DEFAULT = {0, 0, 0, -2147483648, 2147483647};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__int_array( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__int_array);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__int_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
int_array__AttributeData* attributeData = newData<int_array__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_INT_ARRAY, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MININCLUSIVE:
    {
bool failed;
attributeData->minInclusive = GeneratedSaxParser::Utils::toLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_INT_ARRAY, HASH_ATTRIBUTE_MININCLUSIVE, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MAXINCLUSIVE:
    {
bool failed;
attributeData->maxInclusive = GeneratedSaxParser::Utils::toLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_INT_ARRAY, HASH_ATTRIBUTE_MAXINCLUSIVE, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INT_ARRAY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__int_array()
{
return longDataEnd( &ColladaParserAutoGen::data__int_array );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON = "technique_common";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__TECHNIQUE_COMMON = "source__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__source__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__source__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__source__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ACCESSOR = "accessor";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__ACCESSOR = "technique_common__accessor";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_OFFSET = "offset";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_SOURCE = "source";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_STRIDE = "stride";

//---------------------------------------------------------------------
const accessor__AttributeData accessor__AttributeData::DEFAULT = {0, 0, 0, 1};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__accessor( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__accessor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
accessor__AttributeData* attributeData = newData<accessor__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_ACCESSOR, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_ACCESSOR, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_STRIDE:
    {
bool failed;
attributeData->stride = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_ACCESSOR, HASH_ATTRIBUTE_STRIDE, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ACCESSOR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__accessor()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PARAM = "param";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ACCESSOR__PARAM = "accessor__param";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_SID = "sid";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_SEMANTIC = "semantic";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_TYPE = "type";

//---------------------------------------------------------------------
const accessor__param__AttributeData accessor__param__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__accessor__param( const ParserChar* text, size_t textLength )
{

return mImpl->data__accessor__param(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__accessor__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
accessor__param__AttributeData* attributeData = newData<accessor__param__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ACCESSOR__PARAM, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__accessor__param()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE = "technique";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SOURCE__TECHNIQUE = "source__technique";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_PROFILE = "profile";

//---------------------------------------------------------------------
const source__technique__AttributeData source__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__source__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__source__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
source__technique__AttributeData* attributeData = newData<source__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SOURCE__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__source__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER = "sampler";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION__SAMPLER = "animation__sampler";

//---------------------------------------------------------------------
const sampler__AttributeData sampler__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
sampler__AttributeData* attributeData = newData<sampler__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLER, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INPUT = "input";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER__INPUT = "sampler__input";

//---------------------------------------------------------------------
const sampler__input__AttributeData sampler__input__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
sampler__input__AttributeData* attributeData = newData<sampler__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLER__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CHANNEL = "channel";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION__CHANNEL = "animation__channel";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_TARGET = "target";

//---------------------------------------------------------------------
const channel__AttributeData channel__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__channel( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__channel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
channel__AttributeData* attributeData = newData<channel__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TARGET:
    {

attributeData->target = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CHANNEL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__channel()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION__ANIMATION = "animation__animation";

//---------------------------------------------------------------------
const animation__animation__AttributeData animation__animation__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation__animation( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
animation__animation__AttributeData* attributeData = newData<animation__animation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANIMATION__ANIMATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation__animation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EXTRA = "extra";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION__EXTRA = "animation__extra";

//---------------------------------------------------------------------
const animation__extra__AttributeData animation__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
animation__extra__AttributeData* attributeData = newData<animation__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANIMATION__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EXTRA__ASSET = "extra__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__extra__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__extra__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__extra__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EXTRA__TECHNIQUE = "extra__technique";

//---------------------------------------------------------------------
const extra__technique__AttributeData extra__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__extra__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__extra__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
extra__technique__AttributeData* attributeData = newData<extra__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EXTRA__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__extra__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__EXTRA = "library_animations__extra";

//---------------------------------------------------------------------
const library_animations__extra__AttributeData library_animations__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animations__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animations__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_animations__extra__AttributeData* attributeData = newData<library_animations__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_ANIMATIONS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animations__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS = "library_animation_clips";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_ANIMATION_CLIPS = "COLLADA__library_animation_clips";

//---------------------------------------------------------------------
const library_animation_clips__AttributeData library_animation_clips__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animation_clips( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animation_clips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_animation_clips__AttributeData* attributeData = newData<library_animation_clips__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animation_clips()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__ASSET = "library_animation_clips__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animation_clips__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animation_clips__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animation_clips__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION_CLIP = "animation_clip";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__ANIMATION_CLIP = "library_animation_clips__animation_clip";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_START = "start";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_END = "end";

//---------------------------------------------------------------------
const animation_clip__AttributeData animation_clip__AttributeData::DEFAULT = {0, 0, 0.0E1, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation_clip( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation_clip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
animation_clip__AttributeData* attributeData = newData<animation_clip__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_START:
    {
bool failed;
attributeData->start = GeneratedSaxParser::Utils::toDouble(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_ANIMATION_CLIP, HASH_ATTRIBUTE_START, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_END:
    {
bool failed;
attributeData->end = GeneratedSaxParser::Utils::toDouble(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_ANIMATION_CLIP, HASH_ATTRIBUTE_END, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANIMATION_CLIP, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation_clip()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION_CLIP__ASSET = "animation_clip__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation_clip__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation_clip__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation_clip__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_ANIMATION = "instance_animation";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION_CLIP__INSTANCE_ANIMATION = "animation_clip__instance_animation";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_URL = "url";

//---------------------------------------------------------------------
const instance_animation__AttributeData instance_animation__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_animation( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_animation__AttributeData* attributeData = newData<instance_animation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_ANIMATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_animation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_ANIMATION__EXTRA = "instance_animation__extra";

//---------------------------------------------------------------------
const instance_animation__extra__AttributeData instance_animation__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_animation__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_animation__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_animation__extra__AttributeData* attributeData = newData<instance_animation__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_ANIMATION__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_animation__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANIMATION_CLIP__EXTRA = "animation_clip__extra";

//---------------------------------------------------------------------
const animation_clip__extra__AttributeData animation_clip__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__animation_clip__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__animation_clip__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
animation_clip__extra__AttributeData* attributeData = newData<animation_clip__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANIMATION_CLIP__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__animation_clip__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA = "library_animation_clips__extra";

//---------------------------------------------------------------------
const library_animation_clips__extra__AttributeData library_animation_clips__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_animation_clips__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_animation_clips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_animation_clips__extra__AttributeData* attributeData = newData<library_animation_clips__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_animation_clips__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CAMERAS = "library_cameras";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_CAMERAS = "COLLADA__library_cameras";

//---------------------------------------------------------------------
const library_cameras__AttributeData library_cameras__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_cameras( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_cameras( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_cameras__AttributeData* attributeData = newData<library_cameras__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_CAMERAS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_cameras()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CAMERAS__ASSET = "library_cameras__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_cameras__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_cameras__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_cameras__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAMERA = "camera";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CAMERAS__CAMERA = "library_cameras__camera";

//---------------------------------------------------------------------
const camera__AttributeData camera__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__camera( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
camera__AttributeData* attributeData = newData<camera__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CAMERA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__camera()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAMERA__ASSET = "camera__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__camera__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__camera__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__camera__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_OPTICS = "optics";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAMERA__OPTICS = "camera__optics";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__optics( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__optics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__optics()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_OPTICS__TECHNIQUE_COMMON = "optics__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__optics__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__optics__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__optics__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORTHOGRAPHIC = "orthographic";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__ORTHOGRAPHIC = "technique_common__orthographic";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__orthographic( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__orthographic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__orthographic()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_XMAG = "xmag";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORTHOGRAPHIC__XMAG = "orthographic__xmag";

//---------------------------------------------------------------------
const xmag__AttributeData xmag__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__xmag( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__xmag(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_XMAG, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__xmag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
xmag__AttributeData* attributeData = newData<xmag__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_XMAG, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__xmag()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_YMAG = "ymag";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORTHOGRAPHIC__YMAG = "orthographic__ymag";

//---------------------------------------------------------------------
const ymag__AttributeData ymag__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ymag( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__ymag(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_YMAG, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ymag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
ymag__AttributeData* attributeData = newData<ymag__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_YMAG, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ymag()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ASPECT_RATIO = "aspect_ratio";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO = "orthographic__aspect_ratio";

//---------------------------------------------------------------------
const orthographic__aspect_ratio__AttributeData orthographic__aspect_ratio__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__orthographic__aspect_ratio( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__orthographic__aspect_ratio(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__orthographic__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
orthographic__aspect_ratio__AttributeData* attributeData = newData<orthographic__aspect_ratio__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__orthographic__aspect_ratio()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ZNEAR = "znear";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORTHOGRAPHIC__ZNEAR = "orthographic__znear";

//---------------------------------------------------------------------
const orthographic__znear__AttributeData orthographic__znear__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__orthographic__znear( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__orthographic__znear(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ORTHOGRAPHIC__ZNEAR, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__orthographic__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
orthographic__znear__AttributeData* attributeData = newData<orthographic__znear__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ORTHOGRAPHIC__ZNEAR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__orthographic__znear()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ZFAR = "zfar";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORTHOGRAPHIC__ZFAR = "orthographic__zfar";

//---------------------------------------------------------------------
const orthographic__zfar__AttributeData orthographic__zfar__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__orthographic__zfar( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__orthographic__zfar(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ORTHOGRAPHIC__ZFAR, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__orthographic__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
orthographic__zfar__AttributeData* attributeData = newData<orthographic__zfar__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ORTHOGRAPHIC__ZFAR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__orthographic__zfar()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PERSPECTIVE = "perspective";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__PERSPECTIVE = "technique_common__perspective";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__perspective( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__perspective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__perspective()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_XFOV = "xfov";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PERSPECTIVE__XFOV = "perspective__xfov";

//---------------------------------------------------------------------
const xfov__AttributeData xfov__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__xfov( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__xfov(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_XFOV, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__xfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
xfov__AttributeData* attributeData = newData<xfov__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_XFOV, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__xfov()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_YFOV = "yfov";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PERSPECTIVE__YFOV = "perspective__yfov";

//---------------------------------------------------------------------
const yfov__AttributeData yfov__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__yfov( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__yfov(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_YFOV, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__yfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
yfov__AttributeData* attributeData = newData<yfov__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_YFOV, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__yfov()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PERSPECTIVE__ASPECT_RATIO = "perspective__aspect_ratio";

//---------------------------------------------------------------------
const perspective__aspect_ratio__AttributeData perspective__aspect_ratio__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__perspective__aspect_ratio( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__perspective__aspect_ratio(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_PERSPECTIVE__ASPECT_RATIO, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__perspective__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
perspective__aspect_ratio__AttributeData* attributeData = newData<perspective__aspect_ratio__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PERSPECTIVE__ASPECT_RATIO, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__perspective__aspect_ratio()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PERSPECTIVE__ZNEAR = "perspective__znear";

//---------------------------------------------------------------------
const perspective__znear__AttributeData perspective__znear__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__perspective__znear( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__perspective__znear(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_PERSPECTIVE__ZNEAR, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__perspective__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
perspective__znear__AttributeData* attributeData = newData<perspective__znear__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PERSPECTIVE__ZNEAR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__perspective__znear()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PERSPECTIVE__ZFAR = "perspective__zfar";

//---------------------------------------------------------------------
const perspective__zfar__AttributeData perspective__zfar__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__perspective__zfar( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__perspective__zfar(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_PERSPECTIVE__ZFAR, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__perspective__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
perspective__zfar__AttributeData* attributeData = newData<perspective__zfar__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PERSPECTIVE__ZFAR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__perspective__zfar()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_OPTICS__TECHNIQUE = "optics__technique";

//---------------------------------------------------------------------
const optics__technique__AttributeData optics__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__optics__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__optics__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
optics__technique__AttributeData* attributeData = newData<optics__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_OPTICS__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__optics__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_OPTICS__EXTRA = "optics__extra";

//---------------------------------------------------------------------
const optics__extra__AttributeData optics__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__optics__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__optics__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
optics__extra__AttributeData* attributeData = newData<optics__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_OPTICS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__optics__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGER = "imager";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAMERA__IMAGER = "camera__imager";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__imager( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__imager( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__imager()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGER__TECHNIQUE = "imager__technique";

//---------------------------------------------------------------------
const imager__technique__AttributeData imager__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__imager__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__imager__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
imager__technique__AttributeData* attributeData = newData<imager__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_IMAGER__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__imager__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGER__EXTRA = "imager__extra";

//---------------------------------------------------------------------
const imager__extra__AttributeData imager__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__imager__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__imager__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
imager__extra__AttributeData* attributeData = newData<imager__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_IMAGER__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__imager__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAMERA__EXTRA = "camera__extra";

//---------------------------------------------------------------------
const camera__extra__AttributeData camera__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__camera__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__camera__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
camera__extra__AttributeData* attributeData = newData<camera__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CAMERA__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__camera__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CAMERAS__EXTRA = "library_cameras__extra";

//---------------------------------------------------------------------
const library_cameras__extra__AttributeData library_cameras__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_cameras__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_cameras__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_cameras__extra__AttributeData* attributeData = newData<library_cameras__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_CAMERAS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_cameras__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CONTROLLERS = "library_controllers";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_CONTROLLERS = "COLLADA__library_controllers";

//---------------------------------------------------------------------
const library_controllers__AttributeData library_controllers__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_controllers( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_controllers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_controllers__AttributeData* attributeData = newData<library_controllers__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_CONTROLLERS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_controllers()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__ASSET = "library_controllers__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_controllers__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_controllers__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_controllers__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROLLER = "controller";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__CONTROLLER = "library_controllers__controller";

//---------------------------------------------------------------------
const controller__AttributeData controller__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__controller( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
controller__AttributeData* attributeData = newData<controller__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONTROLLER, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__controller()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROLLER__ASSET = "controller__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__controller__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__controller__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__controller__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKIN = "skin";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROLLER__SKIN = "controller__skin";

//---------------------------------------------------------------------
const skin__AttributeData skin__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__skin( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__skin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
skin__AttributeData* attributeData = newData<skin__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SKIN, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__skin()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_SHAPE_MATRIX = "bind_shape_matrix";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKIN__BIND_SHAPE_MATRIX = "skin__bind_shape_matrix";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bind_shape_matrix( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__bind_shape_matrix);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bind_shape_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bind_shape_matrix()
{
return doubleDataEnd( &ColladaParserAutoGen::data__bind_shape_matrix );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKIN__SOURCE = "skin__source";

//---------------------------------------------------------------------
const skin__source__AttributeData skin__source__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__skin__source( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__skin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
skin__source__AttributeData* attributeData = newData<skin__source__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SKIN__SOURCE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__skin__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_JOINTS = "joints";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKIN__JOINTS = "skin__joints";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__joints( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__joints()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_JOINTS__INPUT = "joints__input";

//---------------------------------------------------------------------
const joints__input__AttributeData joints__input__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__joints__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__joints__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
joints__input__AttributeData* attributeData = newData<joints__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_JOINTS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__joints__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_JOINTS__EXTRA = "joints__extra";

//---------------------------------------------------------------------
const joints__extra__AttributeData joints__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__joints__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__joints__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
joints__extra__AttributeData* attributeData = newData<joints__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_JOINTS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__joints__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTEX_WEIGHTS = "vertex_weights";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKIN__VERTEX_WEIGHTS = "skin__vertex_weights";

//---------------------------------------------------------------------
const vertex_weights__AttributeData vertex_weights__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__vertex_weights( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__vertex_weights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
vertex_weights__AttributeData* attributeData = newData<vertex_weights__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_VERTEX_WEIGHTS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VERTEX_WEIGHTS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__vertex_weights()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTEX_WEIGHTS__INPUT = "vertex_weights__input";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_SET = "set";

//---------------------------------------------------------------------
const vertex_weights__input__AttributeData vertex_weights__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__vertex_weights__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__vertex_weights__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
vertex_weights__input__AttributeData* attributeData = newData<vertex_weights__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_VERTEX_WEIGHTS__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_VERTEX_WEIGHTS__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VERTEX_WEIGHTS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__vertex_weights__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VCOUNT = "vcount";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTEX_WEIGHTS__VCOUNT = "vertex_weights__vcount";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__vertex_weights__vcount( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__vertex_weights__vcount);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__vertex_weights__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__vertex_weights__vcount()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__vertex_weights__vcount );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_V = "v";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTEX_WEIGHTS__V = "vertex_weights__v";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__v( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__v);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__v( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__v()
{
return longDataEnd( &ColladaParserAutoGen::data__v );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTEX_WEIGHTS__EXTRA = "vertex_weights__extra";

//---------------------------------------------------------------------
const vertex_weights__extra__AttributeData vertex_weights__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__vertex_weights__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__vertex_weights__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
vertex_weights__extra__AttributeData* attributeData = newData<vertex_weights__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VERTEX_WEIGHTS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__vertex_weights__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKIN__EXTRA = "skin__extra";

//---------------------------------------------------------------------
const skin__extra__AttributeData skin__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__skin__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__skin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
skin__extra__AttributeData* attributeData = newData<skin__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SKIN__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__skin__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MORPH = "morph";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROLLER__MORPH = "controller__morph";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_METHOD = "method";

//---------------------------------------------------------------------
const morph__AttributeData morph__AttributeData::DEFAULT = {(const GeneratedSaxParser::ParserChar *)"NORMALIZED", 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__morph( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__morph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
morph__AttributeData* attributeData = newData<morph__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_METHOD:
    {

attributeData->method = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MORPH, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__morph()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MORPH__SOURCE = "morph__source";

//---------------------------------------------------------------------
const morph__source__AttributeData morph__source__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__morph__source( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__morph__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
morph__source__AttributeData* attributeData = newData<morph__source__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MORPH__SOURCE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__morph__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TARGETS = "targets";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MORPH__TARGETS = "morph__targets";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__targets( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__targets( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__targets()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TARGETS__INPUT = "targets__input";

//---------------------------------------------------------------------
const targets__input__AttributeData targets__input__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__targets__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__targets__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
targets__input__AttributeData* attributeData = newData<targets__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TARGETS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__targets__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TARGETS__EXTRA = "targets__extra";

//---------------------------------------------------------------------
const targets__extra__AttributeData targets__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__targets__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__targets__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
targets__extra__AttributeData* attributeData = newData<targets__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TARGETS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__targets__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MORPH__EXTRA = "morph__extra";

//---------------------------------------------------------------------
const morph__extra__AttributeData morph__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__morph__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__morph__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
morph__extra__AttributeData* attributeData = newData<morph__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MORPH__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__morph__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROLLER__EXTRA = "controller__extra";

//---------------------------------------------------------------------
const controller__extra__AttributeData controller__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__controller__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__controller__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
controller__extra__AttributeData* attributeData = newData<controller__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONTROLLER__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__controller__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__EXTRA = "library_controllers__extra";

//---------------------------------------------------------------------
const library_controllers__extra__AttributeData library_controllers__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_controllers__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_controllers__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_controllers__extra__AttributeData* attributeData = newData<library_controllers__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_CONTROLLERS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_controllers__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_GEOMETRIES = "library_geometries";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_GEOMETRIES = "COLLADA__library_geometries";

//---------------------------------------------------------------------
const library_geometries__AttributeData library_geometries__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_geometries( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_geometries( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_geometries__AttributeData* attributeData = newData<library_geometries__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_GEOMETRIES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_geometries()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__ASSET = "library_geometries__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_geometries__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_geometries__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_geometries__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GEOMETRY = "geometry";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__GEOMETRY = "library_geometries__geometry";

//---------------------------------------------------------------------
const geometry__AttributeData geometry__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__geometry( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
geometry__AttributeData* attributeData = newData<geometry__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_GEOMETRY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__geometry()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GEOMETRY__ASSET = "geometry__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__geometry__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__geometry__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__geometry__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH = "convex_mesh";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GEOMETRY__CONVEX_MESH = "geometry__convex_mesh";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_CONVEX_HULL_OF = "convex_hull_of";

//---------------------------------------------------------------------
const convex_mesh__AttributeData convex_mesh__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__AttributeData* attributeData = newData<convex_mesh__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_CONVEX_HULL_OF:
    {

attributeData->convex_hull_of = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__SOURCE = "convex_mesh__source";

//---------------------------------------------------------------------
const convex_mesh__source__AttributeData convex_mesh__source__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__source( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__source__AttributeData* attributeData = newData<convex_mesh__source__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__SOURCE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTICES = "vertices";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__VERTICES = "convex_mesh__vertices";

//---------------------------------------------------------------------
const convex_mesh__vertices__AttributeData convex_mesh__vertices__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__vertices( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__vertices__AttributeData* attributeData = newData<convex_mesh__vertices__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__VERTICES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__vertices()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTICES__INPUT = "vertices__input";

//---------------------------------------------------------------------
const vertices__input__AttributeData vertices__input__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__vertices__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__vertices__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
vertices__input__AttributeData* attributeData = newData<vertices__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VERTICES__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__vertices__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VERTICES__EXTRA = "vertices__extra";

//---------------------------------------------------------------------
const vertices__extra__AttributeData vertices__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__vertices__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__vertices__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
vertices__extra__AttributeData* attributeData = newData<vertices__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VERTICES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__vertices__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINES = "lines";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__LINES = "convex_mesh__lines";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_MATERIAL = "material";

//---------------------------------------------------------------------
const convex_mesh__lines__AttributeData convex_mesh__lines__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__lines( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__lines__AttributeData* attributeData = newData<convex_mesh__lines__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__LINES, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__LINES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__lines()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINES__INPUT = "lines__input";

//---------------------------------------------------------------------
const lines__input__AttributeData lines__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__lines__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__lines__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
lines__input__AttributeData* attributeData = newData<lines__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LINES__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LINES__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINES__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__lines__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_P = "p";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINES__P = "lines__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__lines__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__lines__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__lines__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__lines__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__lines__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINES__EXTRA = "lines__extra";

//---------------------------------------------------------------------
const lines__extra__AttributeData lines__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__lines__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__lines__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
lines__extra__AttributeData* attributeData = newData<lines__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__lines__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINESTRIPS = "linestrips";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__LINESTRIPS = "convex_mesh__linestrips";

//---------------------------------------------------------------------
const convex_mesh__linestrips__AttributeData convex_mesh__linestrips__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__linestrips( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__linestrips__AttributeData* attributeData = newData<convex_mesh__linestrips__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__LINESTRIPS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__LINESTRIPS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__linestrips()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINESTRIPS__INPUT = "linestrips__input";

//---------------------------------------------------------------------
const linestrips__input__AttributeData linestrips__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linestrips__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linestrips__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linestrips__input__AttributeData* attributeData = newData<linestrips__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LINESTRIPS__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LINESTRIPS__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINESTRIPS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linestrips__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINESTRIPS__P = "linestrips__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linestrips__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__linestrips__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linestrips__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linestrips__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__linestrips__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINESTRIPS__EXTRA = "linestrips__extra";

//---------------------------------------------------------------------
const linestrips__extra__AttributeData linestrips__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linestrips__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linestrips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linestrips__extra__AttributeData* attributeData = newData<linestrips__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINESTRIPS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linestrips__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYGONS = "polygons";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__POLYGONS = "convex_mesh__polygons";

//---------------------------------------------------------------------
const convex_mesh__polygons__AttributeData convex_mesh__polygons__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__polygons( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__polygons__AttributeData* attributeData = newData<convex_mesh__polygons__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__POLYGONS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__POLYGONS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__polygons()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYGONS__INPUT = "polygons__input";

//---------------------------------------------------------------------
const polygons__input__AttributeData polygons__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polygons__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polygons__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
polygons__input__AttributeData* attributeData = newData<polygons__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_POLYGONS__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_POLYGONS__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POLYGONS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polygons__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYGONS__P = "polygons__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polygons__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__polygons__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polygons__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polygons__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__polygons__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PH = "ph";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYGONS__PH = "polygons__ph";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ph( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ph()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PH__P = "ph__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ph__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__ph__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ph__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ph__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__ph__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_H = "h";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PH__H = "ph__h";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__h( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__h);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__h( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__h()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__h );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYGONS__EXTRA = "polygons__extra";

//---------------------------------------------------------------------
const polygons__extra__AttributeData polygons__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polygons__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polygons__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
polygons__extra__AttributeData* attributeData = newData<polygons__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POLYGONS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polygons__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYLIST = "polylist";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__POLYLIST = "convex_mesh__polylist";

//---------------------------------------------------------------------
const convex_mesh__polylist__AttributeData convex_mesh__polylist__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__polylist( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__polylist__AttributeData* attributeData = newData<convex_mesh__polylist__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__POLYLIST, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__POLYLIST, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__polylist()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYLIST__INPUT = "polylist__input";

//---------------------------------------------------------------------
const polylist__input__AttributeData polylist__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polylist__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polylist__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
polylist__input__AttributeData* attributeData = newData<polylist__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_POLYLIST__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_POLYLIST__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POLYLIST__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polylist__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYLIST__VCOUNT = "polylist__vcount";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polylist__vcount( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__polylist__vcount);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polylist__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polylist__vcount()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__polylist__vcount );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYLIST__P = "polylist__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polylist__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__polylist__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polylist__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polylist__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__polylist__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POLYLIST__EXTRA = "polylist__extra";

//---------------------------------------------------------------------
const polylist__extra__AttributeData polylist__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__polylist__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__polylist__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
polylist__extra__AttributeData* attributeData = newData<polylist__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POLYLIST__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__polylist__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIANGLES = "triangles";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__TRIANGLES = "convex_mesh__triangles";

//---------------------------------------------------------------------
const convex_mesh__triangles__AttributeData convex_mesh__triangles__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__triangles( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__triangles__AttributeData* attributeData = newData<convex_mesh__triangles__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__TRIANGLES, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__TRIANGLES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__triangles()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIANGLES__INPUT = "triangles__input";

//---------------------------------------------------------------------
const triangles__input__AttributeData triangles__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__triangles__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__triangles__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
triangles__input__AttributeData* attributeData = newData<triangles__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_TRIANGLES__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_TRIANGLES__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TRIANGLES__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__triangles__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIANGLES__P = "triangles__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__triangles__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__triangles__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__triangles__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__triangles__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__triangles__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIANGLES__EXTRA = "triangles__extra";

//---------------------------------------------------------------------
const triangles__extra__AttributeData triangles__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__triangles__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__triangles__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
triangles__extra__AttributeData* attributeData = newData<triangles__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TRIANGLES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__triangles__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIFANS = "trifans";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__TRIFANS = "convex_mesh__trifans";

//---------------------------------------------------------------------
const convex_mesh__trifans__AttributeData convex_mesh__trifans__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__trifans( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__trifans__AttributeData* attributeData = newData<convex_mesh__trifans__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__TRIFANS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__TRIFANS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__trifans()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIFANS__INPUT = "trifans__input";

//---------------------------------------------------------------------
const trifans__input__AttributeData trifans__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__trifans__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__trifans__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
trifans__input__AttributeData* attributeData = newData<trifans__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_TRIFANS__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_TRIFANS__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TRIFANS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__trifans__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIFANS__P = "trifans__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__trifans__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__trifans__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__trifans__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__trifans__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__trifans__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRIFANS__EXTRA = "trifans__extra";

//---------------------------------------------------------------------
const trifans__extra__AttributeData trifans__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__trifans__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__trifans__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
trifans__extra__AttributeData* attributeData = newData<trifans__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TRIFANS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__trifans__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRISTRIPS = "tristrips";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__TRISTRIPS = "convex_mesh__tristrips";

//---------------------------------------------------------------------
const convex_mesh__tristrips__AttributeData convex_mesh__tristrips__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__tristrips( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__tristrips__AttributeData* attributeData = newData<convex_mesh__tristrips__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_CONVEX_MESH__TRISTRIPS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__TRISTRIPS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__tristrips()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRISTRIPS__INPUT = "tristrips__input";

//---------------------------------------------------------------------
const tristrips__input__AttributeData tristrips__input__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tristrips__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tristrips__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
tristrips__input__AttributeData* attributeData = newData<tristrips__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_OFFSET:
    {
bool failed;
attributeData->offset = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_TRISTRIPS__INPUT, HASH_ATTRIBUTE_OFFSET, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SET:
    {
bool failed;
attributeData->set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_TRISTRIPS__INPUT, HASH_ATTRIBUTE_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TRISTRIPS__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tristrips__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRISTRIPS__P = "tristrips__p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tristrips__p( const ParserChar* text, size_t textLength )
{
return characterData2UnsignedLongLongData(text, textLength, &ColladaParserAutoGen::data__tristrips__p);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tristrips__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tristrips__p()
{
return unsignedLongLongDataEnd( &ColladaParserAutoGen::data__tristrips__p );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRISTRIPS__EXTRA = "tristrips__extra";

//---------------------------------------------------------------------
const tristrips__extra__AttributeData tristrips__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tristrips__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tristrips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
tristrips__extra__AttributeData* attributeData = newData<tristrips__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TRISTRIPS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tristrips__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONVEX_MESH__EXTRA = "convex_mesh__extra";

//---------------------------------------------------------------------
const convex_mesh__extra__AttributeData convex_mesh__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__convex_mesh__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__convex_mesh__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
convex_mesh__extra__AttributeData* attributeData = newData<convex_mesh__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONVEX_MESH__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__convex_mesh__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH = "mesh";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GEOMETRY__MESH = "geometry__mesh";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__SOURCE = "mesh__source";

//---------------------------------------------------------------------
const mesh__source__AttributeData mesh__source__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__source( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__source__AttributeData* attributeData = newData<mesh__source__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__SOURCE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__VERTICES = "mesh__vertices";

//---------------------------------------------------------------------
const mesh__vertices__AttributeData mesh__vertices__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__vertices( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__vertices__AttributeData* attributeData = newData<mesh__vertices__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__VERTICES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__vertices()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__LINES = "mesh__lines";

//---------------------------------------------------------------------
const mesh__lines__AttributeData mesh__lines__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__lines( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__lines__AttributeData* attributeData = newData<mesh__lines__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__LINES, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__LINES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__lines()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__LINESTRIPS = "mesh__linestrips";

//---------------------------------------------------------------------
const mesh__linestrips__AttributeData mesh__linestrips__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__linestrips( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__linestrips__AttributeData* attributeData = newData<mesh__linestrips__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__LINESTRIPS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__LINESTRIPS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__linestrips()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__POLYGONS = "mesh__polygons";

//---------------------------------------------------------------------
const mesh__polygons__AttributeData mesh__polygons__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__polygons( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__polygons__AttributeData* attributeData = newData<mesh__polygons__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__POLYGONS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__POLYGONS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__polygons()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__POLYLIST = "mesh__polylist";

//---------------------------------------------------------------------
const mesh__polylist__AttributeData mesh__polylist__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__polylist( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__polylist__AttributeData* attributeData = newData<mesh__polylist__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__POLYLIST, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__POLYLIST, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__polylist()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__TRIANGLES = "mesh__triangles";

//---------------------------------------------------------------------
const mesh__triangles__AttributeData mesh__triangles__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__triangles( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__triangles__AttributeData* attributeData = newData<mesh__triangles__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__TRIANGLES, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__TRIANGLES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__triangles()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__TRIFANS = "mesh__trifans";

//---------------------------------------------------------------------
const mesh__trifans__AttributeData mesh__trifans__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__trifans( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__trifans__AttributeData* attributeData = newData<mesh__trifans__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__TRIFANS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__TRIFANS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__trifans()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__TRISTRIPS = "mesh__tristrips";

//---------------------------------------------------------------------
const mesh__tristrips__AttributeData mesh__tristrips__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__tristrips( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__tristrips__AttributeData* attributeData = newData<mesh__tristrips__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_COUNT:
    {
bool failed;
attributeData->count = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_MESH__TRISTRIPS, HASH_ATTRIBUTE_COUNT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_MATERIAL:
    {

attributeData->material = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__TRISTRIPS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__tristrips()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MESH__EXTRA = "mesh__extra";

//---------------------------------------------------------------------
const mesh__extra__AttributeData mesh__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mesh__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mesh__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mesh__extra__AttributeData* attributeData = newData<mesh__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MESH__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mesh__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPLINE = "spline";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GEOMETRY__SPLINE = "geometry__spline";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_CLOSED = "closed";

//---------------------------------------------------------------------
const spline__AttributeData spline__AttributeData::DEFAULT = {false};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spline( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spline__AttributeData* attributeData = newData<spline__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_CLOSED:
    {
bool failed;
attributeData->closed = GeneratedSaxParser::Utils::toBool(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_SPLINE, HASH_ATTRIBUTE_CLOSED, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPLINE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spline()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPLINE__SOURCE = "spline__source";

//---------------------------------------------------------------------
const spline__source__AttributeData spline__source__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spline__source( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spline__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spline__source__AttributeData* attributeData = newData<spline__source__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPLINE__SOURCE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spline__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROL_VERTICES = "control_vertices";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPLINE__CONTROL_VERTICES = "spline__control_vertices";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__control_vertices( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__control_vertices()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROL_VERTICES__INPUT = "control_vertices__input";

//---------------------------------------------------------------------
const control_vertices__input__AttributeData control_vertices__input__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__control_vertices__input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__control_vertices__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
control_vertices__input__AttributeData* attributeData = newData<control_vertices__input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SOURCE:
    {

attributeData->source = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONTROL_VERTICES__INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__control_vertices__input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONTROL_VERTICES__EXTRA = "control_vertices__extra";

//---------------------------------------------------------------------
const control_vertices__extra__AttributeData control_vertices__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__control_vertices__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__control_vertices__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
control_vertices__extra__AttributeData* attributeData = newData<control_vertices__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CONTROL_VERTICES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__control_vertices__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPLINE__EXTRA = "spline__extra";

//---------------------------------------------------------------------
const spline__extra__AttributeData spline__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spline__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spline__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spline__extra__AttributeData* attributeData = newData<spline__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPLINE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spline__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GEOMETRY__EXTRA = "geometry__extra";

//---------------------------------------------------------------------
const geometry__extra__AttributeData geometry__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__geometry__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__geometry__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
geometry__extra__AttributeData* attributeData = newData<geometry__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_GEOMETRY__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__geometry__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__EXTRA = "library_geometries__extra";

//---------------------------------------------------------------------
const library_geometries__extra__AttributeData library_geometries__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_geometries__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_geometries__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_geometries__extra__AttributeData* attributeData = newData<library_geometries__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_GEOMETRIES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_geometries__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_EFFECTS = "library_effects";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_EFFECTS = "COLLADA__library_effects";

//---------------------------------------------------------------------
const library_effects__AttributeData library_effects__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_effects( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_effects( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_effects__AttributeData* attributeData = newData<library_effects__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_EFFECTS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_effects()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_EFFECTS__ASSET = "library_effects__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_effects__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_effects__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_effects__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT = "effect";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_EFFECTS__EFFECT = "library_effects__effect";

//---------------------------------------------------------------------
const effect__AttributeData effect__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__effect( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
effect__AttributeData* attributeData = newData<effect__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EFFECT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__effect()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT__ASSET = "effect__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__effect__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__effect__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__effect__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE = "annotate";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT__ANNOTATE = "effect__annotate";

//---------------------------------------------------------------------
const effect__annotate__AttributeData effect__annotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__effect__annotate( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__effect__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
effect__annotate__AttributeData* attributeData = newData<effect__annotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EFFECT__ANNOTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__effect__annotate()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOOL = "bool";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__BOOL = "annotate__bool";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__bool( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__annotate__bool(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ANNOTATE__BOOL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__bool()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOOL2 = "bool2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__BOOL2 = "annotate__bool2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__bool2( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__annotate__bool2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__bool2()
{
return boolDataEnd( &ColladaParserAutoGen::data__annotate__bool2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOOL3 = "bool3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__BOOL3 = "annotate__bool3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__bool3( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__annotate__bool3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__bool3()
{
return boolDataEnd( &ColladaParserAutoGen::data__annotate__bool3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOOL4 = "bool4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__BOOL4 = "annotate__bool4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__bool4( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__annotate__bool4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__bool4()
{
return boolDataEnd( &ColladaParserAutoGen::data__annotate__bool4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INT = "int";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__INT = "annotate__int";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__int( const ParserChar* text, size_t textLength )
{
bool failed;
long parameter = GeneratedSaxParser::Utils::toLong(text, failed);
if (!failed)
    return mImpl->data__annotate__int(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ANNOTATE__INT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__int()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INT2 = "int2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__INT2 = "annotate__int2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__int2( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__annotate__int2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__int2()
{
return longDataEnd( &ColladaParserAutoGen::data__annotate__int2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INT3 = "int3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__INT3 = "annotate__int3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__int3( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__annotate__int3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__int3()
{
return longDataEnd( &ColladaParserAutoGen::data__annotate__int3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INT4 = "int4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__INT4 = "annotate__int4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__int4( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__annotate__int4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__int4()
{
return longDataEnd( &ColladaParserAutoGen::data__annotate__int4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT = "float";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT = "annotate__float";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__annotate__float(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ANNOTATE__FLOAT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT2 = "float2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT2 = "annotate__float2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__annotate__float2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__annotate__float2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT3 = "float3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT3 = "annotate__float3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__annotate__float3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__annotate__float3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT4 = "float4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT4 = "annotate__float4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__annotate__float4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__annotate__float4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT2X2 = "float2x2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT2X2 = "annotate__float2x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float2x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__annotate__float2x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float2x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__annotate__float2x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT3X3 = "float3x3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT3X3 = "annotate__float3x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float3x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__annotate__float3x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float3x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__annotate__float3x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT4X4 = "float4x4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__FLOAT4X4 = "annotate__float4x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__float4x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__annotate__float4x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__float4x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__annotate__float4x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_STRING = "string";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANNOTATE__STRING = "annotate__string";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__annotate__string( const ParserChar* text, size_t textLength )
{

return mImpl->data__annotate__string(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__annotate__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__annotate__string()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGE = "image";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT__IMAGE = "effect__image";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_FORMAT = "format";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_HEIGHT = "height";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_WIDTH = "width";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_DEPTH = "depth";

//---------------------------------------------------------------------
const effect__image__AttributeData effect__image__AttributeData::DEFAULT = {0, 0, 0, 0, 0, 1};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__effect__image( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__effect__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
effect__image__AttributeData* attributeData = newData<effect__image__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_FORMAT:
    {

attributeData->format = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_HEIGHT:
    {
bool failed;
attributeData->height = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_EFFECT__IMAGE, HASH_ATTRIBUTE_HEIGHT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_WIDTH:
    {
bool failed;
attributeData->width = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_EFFECT__IMAGE, HASH_ATTRIBUTE_WIDTH, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_DEPTH:
    {
bool failed;
attributeData->depth = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_EFFECT__IMAGE, HASH_ATTRIBUTE_DEPTH, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EFFECT__IMAGE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__effect__image()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGE__ASSET = "image__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__image__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__image__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__image__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DATA = "data";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGE__DATA = "image__data";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__data( const ParserChar* text, size_t textLength )
{
return mImpl->data__data(text, textLength);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__data()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_FROM = "init_from";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGE__INIT_FROM = "image__init_from";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__image__init_from( const ParserChar* text, size_t textLength )
{

return mImpl->data__image__init_from(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__image__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__image__init_from()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_IMAGE__EXTRA = "image__extra";

//---------------------------------------------------------------------
const image__extra__AttributeData image__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__image__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__image__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
image__extra__AttributeData* attributeData = newData<image__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_IMAGE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__image__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM = "newparam";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT__NEWPARAM = "effect__newparam";

//---------------------------------------------------------------------
const effect__newparam__AttributeData effect__newparam__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__effect__newparam( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__effect__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
effect__newparam__AttributeData* attributeData = newData<effect__newparam__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EFFECT__NEWPARAM, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__effect__newparam()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__ANNOTATE = "newparam__annotate";

//---------------------------------------------------------------------
const newparam__annotate__AttributeData newparam__annotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__annotate( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
newparam__annotate__AttributeData* attributeData = newData<newparam__annotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NEWPARAM__ANNOTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__annotate()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SEMANTIC = "semantic";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SEMANTIC = "newparam__semantic";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__semantic( const ParserChar* text, size_t textLength )
{

return mImpl->data__semantic(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__semantic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__semantic()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MODIFIER = "modifier";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__MODIFIER = "newparam__modifier";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__modifier( const ParserChar* text, size_t textLength )
{

return mImpl->data__modifier(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__modifier( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__modifier()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__BOOL = "newparam__bool";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__bool( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__newparam__bool(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_NEWPARAM__BOOL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__bool()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__BOOL2 = "newparam__bool2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__bool2( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__newparam__bool2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__bool2()
{
return boolDataEnd( &ColladaParserAutoGen::data__newparam__bool2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__BOOL3 = "newparam__bool3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__bool3( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__newparam__bool3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__bool3()
{
return boolDataEnd( &ColladaParserAutoGen::data__newparam__bool3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__BOOL4 = "newparam__bool4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__bool4( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__newparam__bool4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__bool4()
{
return boolDataEnd( &ColladaParserAutoGen::data__newparam__bool4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__INT = "newparam__int";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__int( const ParserChar* text, size_t textLength )
{
bool failed;
long parameter = GeneratedSaxParser::Utils::toLong(text, failed);
if (!failed)
    return mImpl->data__newparam__int(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_NEWPARAM__INT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__int()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__INT2 = "newparam__int2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__int2( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__newparam__int2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__int2()
{
return longDataEnd( &ColladaParserAutoGen::data__newparam__int2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__INT3 = "newparam__int3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__int3( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__newparam__int3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__int3()
{
return longDataEnd( &ColladaParserAutoGen::data__newparam__int3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__INT4 = "newparam__int4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__int4( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__newparam__int4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__int4()
{
return longDataEnd( &ColladaParserAutoGen::data__newparam__int4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT = "newparam__float";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__newparam__float(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_NEWPARAM__FLOAT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT2 = "newparam__float2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT3 = "newparam__float3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT4 = "newparam__float4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT1X1 = "float1x1";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT1X1 = "newparam__float1x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float1x1( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__newparam__float1x1(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_NEWPARAM__FLOAT1X1, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float1x1()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT1X2 = "float1x2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT1X2 = "newparam__float1x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float1x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float1x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float1x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float1x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT1X3 = "float1x3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT1X3 = "newparam__float1x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float1x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float1x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float1x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float1x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT1X4 = "float1x4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT1X4 = "newparam__float1x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float1x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float1x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float1x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float1x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT2X1 = "float2x1";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT2X1 = "newparam__float2x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float2x1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float2x1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float2x1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float2x1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT2X2 = "newparam__float2x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float2x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float2x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float2x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float2x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT2X3 = "float2x3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT2X3 = "newparam__float2x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float2x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float2x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float2x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float2x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT2X4 = "float2x4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT2X4 = "newparam__float2x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float2x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float2x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float2x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float2x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT3X1 = "float3x1";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT3X1 = "newparam__float3x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float3x1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float3x1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float3x1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float3x1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT3X2 = "float3x2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT3X2 = "newparam__float3x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float3x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float3x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float3x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float3x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT3X3 = "newparam__float3x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float3x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float3x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float3x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float3x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT3X4 = "float3x4";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT3X4 = "newparam__float3x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float3x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float3x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float3x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float3x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT4X1 = "float4x1";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT4X1 = "newparam__float4x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float4x1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float4x1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float4x1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float4x1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT4X2 = "float4x2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT4X2 = "newparam__float4x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float4x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float4x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float4x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float4x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FLOAT4X3 = "float4x3";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT4X3 = "newparam__float4x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float4x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float4x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float4x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float4x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__FLOAT4X4 = "newparam__float4x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__float4x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__newparam__float4x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__float4x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__newparam__float4x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE = "surface";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SURFACE = "newparam__surface";

//---------------------------------------------------------------------
const newparam__surface__AttributeData newparam__surface__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__surface( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
newparam__surface__AttributeData* attributeData = newData<newparam__surface__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NEWPARAM__SURFACE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__surface()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_AS_NULL = "init_as_null";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__INIT_AS_NULL = "surface__init_as_null";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_as_null( const ParserChar* text, size_t textLength )
{

return mImpl->data__init_as_null(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_as_null( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_as_null()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_AS_TARGET = "init_as_target";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__INIT_AS_TARGET = "surface__init_as_target";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_as_target( const ParserChar* text, size_t textLength )
{

return mImpl->data__init_as_target(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_as_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_as_target()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_CUBE = "init_cube";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__INIT_CUBE = "surface__init_cube";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_cube( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_cube( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_cube()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ALL = "all";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_CUBE__ALL = "init_cube__all";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_REF = "ref";

//---------------------------------------------------------------------
const init_cube__all__AttributeData init_cube__all__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_cube__all( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_cube__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
init_cube__all__AttributeData* attributeData = newData<init_cube__all__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INIT_CUBE__ALL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_cube__all()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PRIMARY = "primary";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_CUBE__PRIMARY = "init_cube__primary";

//---------------------------------------------------------------------
const init_cube__primary__AttributeData init_cube__primary__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_cube__primary( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_cube__primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
init_cube__primary__AttributeData* attributeData = newData<init_cube__primary__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INIT_CUBE__PRIMARY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_cube__primary()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ORDER = "order";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PRIMARY__ORDER = "primary__order";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__order( const ParserChar* text, size_t textLength )
{

return mImpl->data__order(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__order( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__order()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FACE = "face";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_CUBE__FACE = "init_cube__face";

//---------------------------------------------------------------------
const init_cube__face__AttributeData init_cube__face__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_cube__face( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_cube__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
init_cube__face__AttributeData* attributeData = newData<init_cube__face__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INIT_CUBE__FACE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_cube__face()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_VOLUME = "init_volume";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__INIT_VOLUME = "surface__init_volume";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_volume( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_volume( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_volume()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_VOLUME__ALL = "init_volume__all";

//---------------------------------------------------------------------
const init_volume__all__AttributeData init_volume__all__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_volume__all( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_volume__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
init_volume__all__AttributeData* attributeData = newData<init_volume__all__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INIT_VOLUME__ALL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_volume__all()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_VOLUME__PRIMARY = "init_volume__primary";

//---------------------------------------------------------------------
const init_volume__primary__AttributeData init_volume__primary__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_volume__primary( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_volume__primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
init_volume__primary__AttributeData* attributeData = newData<init_volume__primary__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INIT_VOLUME__PRIMARY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_volume__primary()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_PLANAR = "init_planar";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__INIT_PLANAR = "surface__init_planar";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_planar( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_planar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_planar()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INIT_PLANAR__ALL = "init_planar__all";

//---------------------------------------------------------------------
const init_planar__all__AttributeData init_planar__all__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__init_planar__all( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__init_planar__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
init_planar__all__AttributeData* attributeData = newData<init_planar__all__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INIT_PLANAR__ALL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__init_planar__all()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__INIT_FROM = "surface__init_from";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_MIP = "mip";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_SLICE = "slice";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_FACE = "face";

//---------------------------------------------------------------------
const surface__init_from__AttributeData surface__init_from__AttributeData::DEFAULT = {0, 0, (const GeneratedSaxParser::ParserChar *)"POSITIVE_X"};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__surface__init_from( const ParserChar* text, size_t textLength )
{

return mImpl->data__surface__init_from(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__surface__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
surface__init_from__AttributeData* attributeData = newData<surface__init_from__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_MIP:
    {
bool failed;
attributeData->mip = GeneratedSaxParser::Utils::toUnsignedLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_SURFACE__INIT_FROM, HASH_ATTRIBUTE_MIP, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_SLICE:
    {
bool failed;
attributeData->slice = GeneratedSaxParser::Utils::toUnsignedLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_SURFACE__INIT_FROM, HASH_ATTRIBUTE_SLICE, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_FACE:
    {

attributeData->face = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SURFACE__INIT_FROM, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__surface__init_from()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT = "format";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__FORMAT = "surface__format";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__format( const ParserChar* text, size_t textLength )
{

return mImpl->data__format(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__format()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT_HINT = "format_hint";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__FORMAT_HINT = "surface__format_hint";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__format_hint( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__format_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__format_hint()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CHANNELS = "channels";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT_HINT__CHANNELS = "format_hint__channels";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__channels( const ParserChar* text, size_t textLength )
{

return mImpl->data__channels(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__channels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__channels()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RANGE = "range";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT_HINT__RANGE = "format_hint__range";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__range( const ParserChar* text, size_t textLength )
{

return mImpl->data__range(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__range()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PRECISION = "precision";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT_HINT__PRECISION = "format_hint__precision";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__precision( const ParserChar* text, size_t textLength )
{

return mImpl->data__precision(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__precision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__precision()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_OPTION = "option";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT_HINT__OPTION = "format_hint__option";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__option( const ParserChar* text, size_t textLength )
{

return mImpl->data__option(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__option( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__option()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORMAT_HINT__EXTRA = "format_hint__extra";

//---------------------------------------------------------------------
const format_hint__extra__AttributeData format_hint__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__format_hint__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__format_hint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
format_hint__extra__AttributeData* attributeData = newData<format_hint__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FORMAT_HINT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__format_hint__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SIZE = "size";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__SIZE = "surface__size";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__surface__size( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__surface__size);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__surface__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__surface__size()
{
return longDataEnd( &ColladaParserAutoGen::data__surface__size );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VIEWPORT_RATIO = "viewport_ratio";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__VIEWPORT_RATIO = "surface__viewport_ratio";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__viewport_ratio( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__viewport_ratio);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__viewport_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__viewport_ratio()
{
return doubleDataEnd( &ColladaParserAutoGen::data__viewport_ratio );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MIP_LEVELS = "mip_levels";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__MIP_LEVELS = "surface__mip_levels";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mip_levels( const ParserChar* text, size_t textLength )
{
bool failed;
unsigned long parameter = GeneratedSaxParser::Utils::toUnsignedLong(text, failed);
if (!failed)
    return mImpl->data__mip_levels(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_MIP_LEVELS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mip_levels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mip_levels()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MIPMAP_GENERATE = "mipmap_generate";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__MIPMAP_GENERATE = "surface__mipmap_generate";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mipmap_generate( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__mipmap_generate(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_MIPMAP_GENERATE, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mipmap_generate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mipmap_generate()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SURFACE__EXTRA = "surface__extra";

//---------------------------------------------------------------------
const surface__extra__AttributeData surface__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__surface__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__surface__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
surface__extra__AttributeData* attributeData = newData<surface__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SURFACE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__surface__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D = "sampler1D";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SAMPLER1D = "newparam__sampler1D";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__sampler1D( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__sampler1D()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__SOURCE = "sampler1D__source";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__source( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler1D__source(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_WRAP_S = "wrap_s";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__WRAP_S = "sampler1D__wrap_s";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__wrap_s( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler1D__wrap_s(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__wrap_s()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MINFILTER = "minfilter";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__MINFILTER = "sampler1D__minfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__minfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler1D__minfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__minfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MAGFILTER = "magfilter";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__MAGFILTER = "sampler1D__magfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__magfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler1D__magfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__magfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MIPFILTER = "mipfilter";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__MIPFILTER = "sampler1D__mipfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__mipfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler1D__mipfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__mipfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BORDER_COLOR = "border_color";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__BORDER_COLOR = "sampler1D__border_color";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__border_color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__sampler1D__border_color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__border_color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__sampler1D__border_color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MIPMAP_MAXLEVEL = "mipmap_maxlevel";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL = "sampler1D__mipmap_maxlevel";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__mipmap_maxlevel( const ParserChar* text, size_t textLength )
{
bool failed;
unsigned short parameter = GeneratedSaxParser::Utils::toUnsignedShort(text, failed);
if (!failed)
    return mImpl->data__sampler1D__mipmap_maxlevel(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__mipmap_maxlevel()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MIPMAP_BIAS = "mipmap_bias";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__MIPMAP_BIAS = "sampler1D__mipmap_bias";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__mipmap_bias( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__sampler1D__mipmap_bias(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLER1D__MIPMAP_BIAS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__mipmap_bias()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER1D__EXTRA = "sampler1D__extra";

//---------------------------------------------------------------------
const sampler1D__extra__AttributeData sampler1D__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler1D__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler1D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
sampler1D__extra__AttributeData* attributeData = newData<sampler1D__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLER1D__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler1D__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D = "sampler2D";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SAMPLER2D = "newparam__sampler2D";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__sampler2D( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__sampler2D()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__SOURCE = "sampler2D__source";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__source( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler2D__source(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__WRAP_S = "sampler2D__wrap_s";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__wrap_s( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler2D__wrap_s(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__wrap_s()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_WRAP_T = "wrap_t";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__WRAP_T = "sampler2D__wrap_t";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__wrap_t( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler2D__wrap_t(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__wrap_t()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__MINFILTER = "sampler2D__minfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__minfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler2D__minfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__minfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__MAGFILTER = "sampler2D__magfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__magfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler2D__magfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__magfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__MIPFILTER = "sampler2D__mipfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__mipfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler2D__mipfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__mipfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__BORDER_COLOR = "sampler2D__border_color";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__border_color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__sampler2D__border_color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__border_color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__sampler2D__border_color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__MIPMAP_MAXLEVEL = "sampler2D__mipmap_maxlevel";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__mipmap_maxlevel( const ParserChar* text, size_t textLength )
{
bool failed;
unsigned short parameter = GeneratedSaxParser::Utils::toUnsignedShort(text, failed);
if (!failed)
    return mImpl->data__sampler2D__mipmap_maxlevel(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLER2D__MIPMAP_MAXLEVEL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__mipmap_maxlevel()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__MIPMAP_BIAS = "sampler2D__mipmap_bias";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__mipmap_bias( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__sampler2D__mipmap_bias(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLER2D__MIPMAP_BIAS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__mipmap_bias()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER2D__EXTRA = "sampler2D__extra";

//---------------------------------------------------------------------
const sampler2D__extra__AttributeData sampler2D__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler2D__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler2D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
sampler2D__extra__AttributeData* attributeData = newData<sampler2D__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLER2D__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler2D__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D = "sampler3D";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SAMPLER3D = "newparam__sampler3D";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__sampler3D( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__sampler3D()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__SOURCE = "sampler3D__source";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__source( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__source(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__WRAP_S = "sampler3D__wrap_s";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__wrap_s( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__wrap_s(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__wrap_s()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__WRAP_T = "sampler3D__wrap_t";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__wrap_t( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__wrap_t(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__wrap_t()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_WRAP_P = "wrap_p";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__WRAP_P = "sampler3D__wrap_p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__wrap_p( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__wrap_p(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__wrap_p()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__MINFILTER = "sampler3D__minfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__minfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__minfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__minfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__MAGFILTER = "sampler3D__magfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__magfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__magfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__magfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__MIPFILTER = "sampler3D__mipfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__mipfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__sampler3D__mipfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__mipfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__BORDER_COLOR = "sampler3D__border_color";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__border_color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__sampler3D__border_color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__border_color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__sampler3D__border_color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__MIPMAP_MAXLEVEL = "sampler3D__mipmap_maxlevel";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__mipmap_maxlevel( const ParserChar* text, size_t textLength )
{
bool failed;
unsigned short parameter = GeneratedSaxParser::Utils::toUnsignedShort(text, failed);
if (!failed)
    return mImpl->data__sampler3D__mipmap_maxlevel(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLER3D__MIPMAP_MAXLEVEL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__mipmap_maxlevel()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__MIPMAP_BIAS = "sampler3D__mipmap_bias";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__mipmap_bias( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__sampler3D__mipmap_bias(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLER3D__MIPMAP_BIAS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__mipmap_bias()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLER3D__EXTRA = "sampler3D__extra";

//---------------------------------------------------------------------
const sampler3D__extra__AttributeData sampler3D__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sampler3D__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sampler3D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
sampler3D__extra__AttributeData* attributeData = newData<sampler3D__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLER3D__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sampler3D__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE = "samplerCUBE";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SAMPLERCUBE = "newparam__samplerCUBE";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__samplerCUBE( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__samplerCUBE()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__SOURCE = "samplerCUBE__source";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__source( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__source(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__WRAP_S = "samplerCUBE__wrap_s";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__wrap_s( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__wrap_s(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__wrap_s()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__WRAP_T = "samplerCUBE__wrap_t";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__wrap_t( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__wrap_t(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__wrap_t()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__WRAP_P = "samplerCUBE__wrap_p";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__wrap_p( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__wrap_p(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__wrap_p()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__MINFILTER = "samplerCUBE__minfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__minfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__minfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__minfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__MAGFILTER = "samplerCUBE__magfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__magfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__magfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__magfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__MIPFILTER = "samplerCUBE__mipfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__mipfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerCUBE__mipfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__mipfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__BORDER_COLOR = "samplerCUBE__border_color";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__border_color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__samplerCUBE__border_color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__border_color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__samplerCUBE__border_color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__MIPMAP_MAXLEVEL = "samplerCUBE__mipmap_maxlevel";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__mipmap_maxlevel( const ParserChar* text, size_t textLength )
{
bool failed;
unsigned short parameter = GeneratedSaxParser::Utils::toUnsignedShort(text, failed);
if (!failed)
    return mImpl->data__samplerCUBE__mipmap_maxlevel(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLERCUBE__MIPMAP_MAXLEVEL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__mipmap_maxlevel()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__MIPMAP_BIAS = "samplerCUBE__mipmap_bias";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__mipmap_bias( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__samplerCUBE__mipmap_bias(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLERCUBE__MIPMAP_BIAS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__mipmap_bias()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERCUBE__EXTRA = "samplerCUBE__extra";

//---------------------------------------------------------------------
const samplerCUBE__extra__AttributeData samplerCUBE__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerCUBE__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerCUBE__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
samplerCUBE__extra__AttributeData* attributeData = newData<samplerCUBE__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLERCUBE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerCUBE__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT = "samplerRECT";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SAMPLERRECT = "newparam__samplerRECT";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__samplerRECT( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__samplerRECT()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__SOURCE = "samplerRECT__source";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__source( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerRECT__source(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__WRAP_S = "samplerRECT__wrap_s";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__wrap_s( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerRECT__wrap_s(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__wrap_s()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__WRAP_T = "samplerRECT__wrap_t";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__wrap_t( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerRECT__wrap_t(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__wrap_t()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__MINFILTER = "samplerRECT__minfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__minfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerRECT__minfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__minfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__MAGFILTER = "samplerRECT__magfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__magfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerRECT__magfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__magfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__MIPFILTER = "samplerRECT__mipfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__mipfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerRECT__mipfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__mipfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__BORDER_COLOR = "samplerRECT__border_color";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__border_color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__samplerRECT__border_color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__border_color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__samplerRECT__border_color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__MIPMAP_MAXLEVEL = "samplerRECT__mipmap_maxlevel";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__mipmap_maxlevel( const ParserChar* text, size_t textLength )
{
bool failed;
unsigned short parameter = GeneratedSaxParser::Utils::toUnsignedShort(text, failed);
if (!failed)
    return mImpl->data__samplerRECT__mipmap_maxlevel(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLERRECT__MIPMAP_MAXLEVEL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__mipmap_maxlevel()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__MIPMAP_BIAS = "samplerRECT__mipmap_bias";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__mipmap_bias( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__samplerRECT__mipmap_bias(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SAMPLERRECT__MIPMAP_BIAS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__mipmap_bias()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERRECT__EXTRA = "samplerRECT__extra";

//---------------------------------------------------------------------
const samplerRECT__extra__AttributeData samplerRECT__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerRECT__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerRECT__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
samplerRECT__extra__AttributeData* attributeData = newData<samplerRECT__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLERRECT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerRECT__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH = "samplerDEPTH";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__SAMPLERDEPTH = "newparam__samplerDEPTH";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__samplerDEPTH( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__samplerDEPTH()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH__SOURCE = "samplerDEPTH__source";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerDEPTH__source( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerDEPTH__source(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerDEPTH__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerDEPTH__source()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH__WRAP_S = "samplerDEPTH__wrap_s";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerDEPTH__wrap_s( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerDEPTH__wrap_s(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerDEPTH__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerDEPTH__wrap_s()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH__WRAP_T = "samplerDEPTH__wrap_t";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerDEPTH__wrap_t( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerDEPTH__wrap_t(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerDEPTH__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerDEPTH__wrap_t()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH__MINFILTER = "samplerDEPTH__minfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerDEPTH__minfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerDEPTH__minfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerDEPTH__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerDEPTH__minfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH__MAGFILTER = "samplerDEPTH__magfilter";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerDEPTH__magfilter( const ParserChar* text, size_t textLength )
{

return mImpl->data__samplerDEPTH__magfilter(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerDEPTH__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerDEPTH__magfilter()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SAMPLERDEPTH__EXTRA = "samplerDEPTH__extra";

//---------------------------------------------------------------------
const samplerDEPTH__extra__AttributeData samplerDEPTH__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__samplerDEPTH__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__samplerDEPTH__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
samplerDEPTH__extra__AttributeData* attributeData = newData<samplerDEPTH__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SAMPLERDEPTH__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__samplerDEPTH__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ENUM = "enum";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NEWPARAM__ENUM = "newparam__enum";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__newparam__enum( const ParserChar* text, size_t textLength )
{

return mImpl->data__newparam__enum(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__newparam__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__newparam__enum()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FX_PROFILE_ABSTRACT = "fx_profile_abstract";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT = "effect__fx_profile_abstract";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__fx_profile_abstract( const ParserChar* text, size_t textLength )
{

return mImpl->data__fx_profile_abstract(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__fx_profile_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__fx_profile_abstract()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EFFECT__EXTRA = "effect__extra";

//---------------------------------------------------------------------
const effect__extra__AttributeData effect__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__effect__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__effect__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
effect__extra__AttributeData* attributeData = newData<effect__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EFFECT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__effect__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_EFFECTS__EXTRA = "library_effects__extra";

//---------------------------------------------------------------------
const library_effects__extra__AttributeData library_effects__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_effects__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_effects__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_effects__extra__AttributeData* attributeData = newData<library_effects__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_EFFECTS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_effects__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS = "library_force_fields";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS = "COLLADA__library_force_fields";

//---------------------------------------------------------------------
const library_force_fields__AttributeData library_force_fields__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_force_fields( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_force_fields( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_force_fields__AttributeData* attributeData = newData<library_force_fields__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_FORCE_FIELDS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_force_fields()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__ASSET = "library_force_fields__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_force_fields__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_force_fields__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_force_fields__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORCE_FIELD = "force_field";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__FORCE_FIELD = "library_force_fields__force_field";

//---------------------------------------------------------------------
const force_field__AttributeData force_field__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__force_field( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
force_field__AttributeData* attributeData = newData<force_field__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FORCE_FIELD, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__force_field()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORCE_FIELD__ASSET = "force_field__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__force_field__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__force_field__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__force_field__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORCE_FIELD__TECHNIQUE = "force_field__technique";

//---------------------------------------------------------------------
const force_field__technique__AttributeData force_field__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__force_field__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__force_field__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
force_field__technique__AttributeData* attributeData = newData<force_field__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FORCE_FIELD__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__force_field__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FORCE_FIELD__EXTRA = "force_field__extra";

//---------------------------------------------------------------------
const force_field__extra__AttributeData force_field__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__force_field__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__force_field__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
force_field__extra__AttributeData* attributeData = newData<force_field__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FORCE_FIELD__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__force_field__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA = "library_force_fields__extra";

//---------------------------------------------------------------------
const library_force_fields__extra__AttributeData library_force_fields__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_force_fields__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_force_fields__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_force_fields__extra__AttributeData* attributeData = newData<library_force_fields__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_force_fields__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_IMAGES = "library_images";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_IMAGES = "COLLADA__library_images";

//---------------------------------------------------------------------
const library_images__AttributeData library_images__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_images( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_images( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_images__AttributeData* attributeData = newData<library_images__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_IMAGES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_images()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_IMAGES__ASSET = "library_images__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_images__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_images__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_images__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_IMAGES__IMAGE = "library_images__image";

//---------------------------------------------------------------------
const library_images__image__AttributeData library_images__image__AttributeData::DEFAULT = {0, 0, 0, 0, 0, 1};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_images__image( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_images__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_images__image__AttributeData* attributeData = newData<library_images__image__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_FORMAT:
    {

attributeData->format = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_HEIGHT:
    {
bool failed;
attributeData->height = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LIBRARY_IMAGES__IMAGE, HASH_ATTRIBUTE_HEIGHT, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_WIDTH:
    {
bool failed;
attributeData->width = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LIBRARY_IMAGES__IMAGE, HASH_ATTRIBUTE_WIDTH, attributeValue))
{return false;}
    break;
    }
    case HASH_ATTRIBUTE_DEPTH:
    {
bool failed;
attributeData->depth = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_LIBRARY_IMAGES__IMAGE, HASH_ATTRIBUTE_DEPTH, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_IMAGES__IMAGE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_images__image()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_IMAGES__EXTRA = "library_images__extra";

//---------------------------------------------------------------------
const library_images__extra__AttributeData library_images__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_images__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_images__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_images__extra__AttributeData* attributeData = newData<library_images__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_IMAGES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_images__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_LIGHTS = "library_lights";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_LIGHTS = "COLLADA__library_lights";

//---------------------------------------------------------------------
const library_lights__AttributeData library_lights__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_lights( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_lights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_lights__AttributeData* attributeData = newData<library_lights__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_LIGHTS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_lights()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_LIGHTS__ASSET = "library_lights__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_lights__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_lights__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_lights__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIGHT = "light";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_LIGHTS__LIGHT = "library_lights__light";

//---------------------------------------------------------------------
const light__AttributeData light__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__light( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
light__AttributeData* attributeData = newData<light__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIGHT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__light()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIGHT__ASSET = "light__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__light__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__light__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__light__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIGHT__TECHNIQUE_COMMON = "light__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__light__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__light__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__light__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_AMBIENT = "ambient";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__AMBIENT = "technique_common__ambient";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__technique_common__ambient( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__technique_common__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__technique_common__ambient()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLOR = "color";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_AMBIENT__COLOR = "ambient__color";

//---------------------------------------------------------------------
const ambient__color__AttributeData ambient__color__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ambient__color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__ambient__color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ambient__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
ambient__color__AttributeData* attributeData = newData<ambient__color__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_AMBIENT__COLOR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ambient__color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__ambient__color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DIRECTIONAL = "directional";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__DIRECTIONAL = "technique_common__directional";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__directional( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__directional( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__directional()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DIRECTIONAL__COLOR = "directional__color";

//---------------------------------------------------------------------
const directional__color__AttributeData directional__color__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__directional__color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__directional__color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__directional__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
directional__color__AttributeData* attributeData = newData<directional__color__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_DIRECTIONAL__COLOR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__directional__color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__directional__color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POINT = "point";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__POINT = "technique_common__point";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__point( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__point( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__point()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POINT__COLOR = "point__color";

//---------------------------------------------------------------------
const point__color__AttributeData point__color__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__point__color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__point__color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__point__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
point__color__AttributeData* attributeData = newData<point__color__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POINT__COLOR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__point__color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__point__color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CONSTANT_ATTENUATION = "constant_attenuation";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POINT__CONSTANT_ATTENUATION = "point__constant_attenuation";

//---------------------------------------------------------------------
const point__constant_attenuation__AttributeData point__constant_attenuation__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__point__constant_attenuation( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__point__constant_attenuation(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_POINT__CONSTANT_ATTENUATION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__point__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
point__constant_attenuation__AttributeData* attributeData = newData<point__constant_attenuation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POINT__CONSTANT_ATTENUATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__point__constant_attenuation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR_ATTENUATION = "linear_attenuation";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POINT__LINEAR_ATTENUATION = "point__linear_attenuation";

//---------------------------------------------------------------------
const point__linear_attenuation__AttributeData point__linear_attenuation__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__point__linear_attenuation( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__point__linear_attenuation(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_POINT__LINEAR_ATTENUATION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__point__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
point__linear_attenuation__AttributeData* attributeData = newData<point__linear_attenuation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POINT__LINEAR_ATTENUATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__point__linear_attenuation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_QUADRATIC_ATTENUATION = "quadratic_attenuation";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_POINT__QUADRATIC_ATTENUATION = "point__quadratic_attenuation";

//---------------------------------------------------------------------
const point__quadratic_attenuation__AttributeData point__quadratic_attenuation__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__point__quadratic_attenuation( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__point__quadratic_attenuation(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_POINT__QUADRATIC_ATTENUATION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__point__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
point__quadratic_attenuation__AttributeData* attributeData = newData<point__quadratic_attenuation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_POINT__QUADRATIC_ATTENUATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__point__quadratic_attenuation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT = "spot";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPOT = "technique_common__spot";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spot( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spot()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT__COLOR = "spot__color";

//---------------------------------------------------------------------
const spot__color__AttributeData spot__color__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spot__color( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__spot__color);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spot__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spot__color__AttributeData* attributeData = newData<spot__color__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPOT__COLOR, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spot__color()
{
return doubleDataEnd( &ColladaParserAutoGen::data__spot__color );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT__CONSTANT_ATTENUATION = "spot__constant_attenuation";

//---------------------------------------------------------------------
const spot__constant_attenuation__AttributeData spot__constant_attenuation__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spot__constant_attenuation( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__spot__constant_attenuation(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SPOT__CONSTANT_ATTENUATION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spot__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spot__constant_attenuation__AttributeData* attributeData = newData<spot__constant_attenuation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPOT__CONSTANT_ATTENUATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spot__constant_attenuation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT__LINEAR_ATTENUATION = "spot__linear_attenuation";

//---------------------------------------------------------------------
const spot__linear_attenuation__AttributeData spot__linear_attenuation__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spot__linear_attenuation( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__spot__linear_attenuation(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SPOT__LINEAR_ATTENUATION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spot__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spot__linear_attenuation__AttributeData* attributeData = newData<spot__linear_attenuation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPOT__LINEAR_ATTENUATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spot__linear_attenuation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT__QUADRATIC_ATTENUATION = "spot__quadratic_attenuation";

//---------------------------------------------------------------------
const spot__quadratic_attenuation__AttributeData spot__quadratic_attenuation__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spot__quadratic_attenuation( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__spot__quadratic_attenuation(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SPOT__QUADRATIC_ATTENUATION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spot__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
spot__quadratic_attenuation__AttributeData* attributeData = newData<spot__quadratic_attenuation__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPOT__QUADRATIC_ATTENUATION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spot__quadratic_attenuation()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FALLOFF_ANGLE = "falloff_angle";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT__FALLOFF_ANGLE = "spot__falloff_angle";

//---------------------------------------------------------------------
const falloff_angle__AttributeData falloff_angle__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__falloff_angle( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__falloff_angle(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_FALLOFF_ANGLE, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__falloff_angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
falloff_angle__AttributeData* attributeData = newData<falloff_angle__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FALLOFF_ANGLE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__falloff_angle()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_FALLOFF_EXPONENT = "falloff_exponent";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPOT__FALLOFF_EXPONENT = "spot__falloff_exponent";

//---------------------------------------------------------------------
const falloff_exponent__AttributeData falloff_exponent__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__falloff_exponent( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__falloff_exponent(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_FALLOFF_EXPONENT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__falloff_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
falloff_exponent__AttributeData* attributeData = newData<falloff_exponent__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_FALLOFF_EXPONENT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__falloff_exponent()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIGHT__TECHNIQUE = "light__technique";

//---------------------------------------------------------------------
const light__technique__AttributeData light__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__light__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__light__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
light__technique__AttributeData* attributeData = newData<light__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIGHT__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__light__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIGHT__EXTRA = "light__extra";

//---------------------------------------------------------------------
const light__extra__AttributeData light__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__light__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__light__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
light__extra__AttributeData* attributeData = newData<light__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIGHT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__light__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_LIGHTS__EXTRA = "library_lights__extra";

//---------------------------------------------------------------------
const library_lights__extra__AttributeData library_lights__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_lights__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_lights__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_lights__extra__AttributeData* attributeData = newData<library_lights__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_LIGHTS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_lights__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_MATERIALS = "library_materials";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_MATERIALS = "COLLADA__library_materials";

//---------------------------------------------------------------------
const library_materials__AttributeData library_materials__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_materials( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_materials__AttributeData* attributeData = newData<library_materials__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_MATERIALS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_materials()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_MATERIALS__ASSET = "library_materials__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_materials__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_materials__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_materials__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MATERIAL = "material";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_MATERIALS__MATERIAL = "library_materials__material";

//---------------------------------------------------------------------
const material__AttributeData material__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
material__AttributeData* attributeData = newData<material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MATERIAL__ASSET = "material__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__material__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__material__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__material__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_EFFECT = "instance_effect";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MATERIAL__INSTANCE_EFFECT = "material__instance_effect";

//---------------------------------------------------------------------
const material__instance_effect__AttributeData material__instance_effect__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__material__instance_effect( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__material__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
material__instance_effect__AttributeData* attributeData = newData<material__instance_effect__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MATERIAL__INSTANCE_EFFECT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__material__instance_effect()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_HINT = "technique_hint";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_EFFECT__TECHNIQUE_HINT = "instance_effect__technique_hint";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_PLATFORM = "platform";

//---------------------------------------------------------------------
const technique_hint__AttributeData technique_hint__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__technique_hint( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__technique_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
technique_hint__AttributeData* attributeData = newData<technique_hint__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PLATFORM:
    {

attributeData->platform = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TECHNIQUE_HINT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__technique_hint()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM = "setparam";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_EFFECT__SETPARAM = "instance_effect__setparam";

//---------------------------------------------------------------------
const instance_effect__setparam__AttributeData instance_effect__setparam__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_effect__setparam( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_effect__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_effect__setparam__AttributeData* attributeData = newData<instance_effect__setparam__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_REF:
    {

attributeData->ref = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_EFFECT__SETPARAM, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_effect__setparam()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__BOOL = "setparam__bool";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__bool( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__setparam__bool(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SETPARAM__BOOL, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__bool()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__BOOL2 = "setparam__bool2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__bool2( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__setparam__bool2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__bool2()
{
return boolDataEnd( &ColladaParserAutoGen::data__setparam__bool2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__BOOL3 = "setparam__bool3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__bool3( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__setparam__bool3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__bool3()
{
return boolDataEnd( &ColladaParserAutoGen::data__setparam__bool3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__BOOL4 = "setparam__bool4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__bool4( const ParserChar* text, size_t textLength )
{
return characterData2BoolData(text, textLength, &ColladaParserAutoGen::data__setparam__bool4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__bool4()
{
return boolDataEnd( &ColladaParserAutoGen::data__setparam__bool4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__INT = "setparam__int";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__int( const ParserChar* text, size_t textLength )
{
bool failed;
long parameter = GeneratedSaxParser::Utils::toLong(text, failed);
if (!failed)
    return mImpl->data__setparam__int(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SETPARAM__INT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__int()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__INT2 = "setparam__int2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__int2( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__setparam__int2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__int2()
{
return longDataEnd( &ColladaParserAutoGen::data__setparam__int2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__INT3 = "setparam__int3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__int3( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__setparam__int3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__int3()
{
return longDataEnd( &ColladaParserAutoGen::data__setparam__int3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__INT4 = "setparam__int4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__int4( const ParserChar* text, size_t textLength )
{
return characterData2LongData(text, textLength, &ColladaParserAutoGen::data__setparam__int4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__int4()
{
return longDataEnd( &ColladaParserAutoGen::data__setparam__int4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT = "setparam__float";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__setparam__float(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SETPARAM__FLOAT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT2 = "setparam__float2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT3 = "setparam__float3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT4 = "setparam__float4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT1X1 = "setparam__float1x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float1x1( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__setparam__float1x1(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SETPARAM__FLOAT1X1, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float1x1()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT1X2 = "setparam__float1x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float1x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float1x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float1x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float1x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT1X3 = "setparam__float1x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float1x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float1x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float1x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float1x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT1X4 = "setparam__float1x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float1x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float1x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float1x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float1x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT2X1 = "setparam__float2x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float2x1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float2x1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float2x1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float2x1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT2X2 = "setparam__float2x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float2x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float2x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float2x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float2x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT2X3 = "setparam__float2x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float2x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float2x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float2x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float2x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT2X4 = "setparam__float2x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float2x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float2x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float2x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float2x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT3X1 = "setparam__float3x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float3x1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float3x1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float3x1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float3x1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT3X2 = "setparam__float3x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float3x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float3x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float3x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float3x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT3X3 = "setparam__float3x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float3x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float3x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float3x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float3x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT3X4 = "setparam__float3x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float3x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float3x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float3x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float3x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT4X1 = "setparam__float4x1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float4x1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float4x1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float4x1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float4x1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT4X2 = "setparam__float4x2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float4x2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float4x2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float4x2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float4x2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT4X3 = "setparam__float4x3";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float4x3( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float4x3);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float4x3()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float4x3 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__FLOAT4X4 = "setparam__float4x4";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__float4x4( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__setparam__float4x4);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__float4x4()
{
return doubleDataEnd( &ColladaParserAutoGen::data__setparam__float4x4 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SURFACE = "setparam__surface";

//---------------------------------------------------------------------
const setparam__surface__AttributeData setparam__surface__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__surface( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
setparam__surface__AttributeData* attributeData = newData<setparam__surface__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SETPARAM__SURFACE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__surface()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SAMPLER1D = "setparam__sampler1D";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__sampler1D( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__sampler1D()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SAMPLER2D = "setparam__sampler2D";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__sampler2D( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__sampler2D()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SAMPLER3D = "setparam__sampler3D";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__sampler3D( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__sampler3D()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SAMPLERCUBE = "setparam__samplerCUBE";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__samplerCUBE( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__samplerCUBE()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SAMPLERRECT = "setparam__samplerRECT";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__samplerRECT( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__samplerRECT()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__SAMPLERDEPTH = "setparam__samplerDEPTH";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__samplerDEPTH( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__samplerDEPTH()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SETPARAM__ENUM = "setparam__enum";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__setparam__enum( const ParserChar* text, size_t textLength )
{

return mImpl->data__setparam__enum(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__setparam__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__setparam__enum()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_EFFECT__EXTRA = "instance_effect__extra";

//---------------------------------------------------------------------
const instance_effect__extra__AttributeData instance_effect__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_effect__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_effect__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_effect__extra__AttributeData* attributeData = newData<instance_effect__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_EFFECT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_effect__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MATERIAL__EXTRA = "material__extra";

//---------------------------------------------------------------------
const material__extra__AttributeData material__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__material__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
material__extra__AttributeData* attributeData = newData<material__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MATERIAL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__material__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_MATERIALS__EXTRA = "library_materials__extra";

//---------------------------------------------------------------------
const library_materials__extra__AttributeData library_materials__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_materials__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_materials__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_materials__extra__AttributeData* attributeData = newData<library_materials__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_MATERIALS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_materials__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_NODES = "library_nodes";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_NODES = "COLLADA__library_nodes";

//---------------------------------------------------------------------
const library_nodes__AttributeData library_nodes__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_nodes( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_nodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_nodes__AttributeData* attributeData = newData<library_nodes__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_NODES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_nodes()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_NODES__ASSET = "library_nodes__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_nodes__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_nodes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_nodes__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE = "node";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_NODES__NODE = "library_nodes__node";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_LAYER = "layer";

//---------------------------------------------------------------------
const library_nodes__node__AttributeData library_nodes__node__AttributeData::DEFAULT = {0, 0, 0, (const GeneratedSaxParser::ParserChar *)"NODE", 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_nodes__node( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_nodes__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_nodes__node__AttributeData* attributeData = newData<library_nodes__node__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_LAYER:
    {

attributeData->layer = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_NODES__NODE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_nodes__node()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__ASSET = "node__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__node__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__node__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__node__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LOOKAT = "lookat";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__LOOKAT = "node__lookat";

//---------------------------------------------------------------------
const lookat__AttributeData lookat__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__lookat( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__lookat);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__lookat( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
lookat__AttributeData* attributeData = newData<lookat__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LOOKAT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__lookat()
{
return doubleDataEnd( &ColladaParserAutoGen::data__lookat );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MATRIX = "matrix";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__MATRIX = "node__matrix";

//---------------------------------------------------------------------
const matrix__AttributeData matrix__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__matrix( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__matrix);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
matrix__AttributeData* attributeData = newData<matrix__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MATRIX, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__matrix()
{
return doubleDataEnd( &ColladaParserAutoGen::data__matrix );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ROTATE = "rotate";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__ROTATE = "node__rotate";

//---------------------------------------------------------------------
const node__rotate__AttributeData node__rotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__node__rotate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__node__rotate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__node__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
node__rotate__AttributeData* attributeData = newData<node__rotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NODE__ROTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__node__rotate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__node__rotate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SCALE = "scale";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__SCALE = "node__scale";

//---------------------------------------------------------------------
const scale__AttributeData scale__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__scale( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__scale);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__scale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
scale__AttributeData* attributeData = newData<scale__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SCALE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__scale()
{
return doubleDataEnd( &ColladaParserAutoGen::data__scale );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKEW = "skew";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__SKEW = "node__skew";

//---------------------------------------------------------------------
const skew__AttributeData skew__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__skew( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__skew);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__skew( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
skew__AttributeData* attributeData = newData<skew__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SKEW, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__skew()
{
return doubleDataEnd( &ColladaParserAutoGen::data__skew );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TRANSLATE = "translate";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__TRANSLATE = "node__translate";

//---------------------------------------------------------------------
const node__translate__AttributeData node__translate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__node__translate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__node__translate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__node__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
node__translate__AttributeData* attributeData = newData<node__translate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NODE__TRANSLATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__node__translate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__node__translate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_CAMERA = "instance_camera";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__INSTANCE_CAMERA = "node__instance_camera";

//---------------------------------------------------------------------
const instance_camera__AttributeData instance_camera__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_camera( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_camera__AttributeData* attributeData = newData<instance_camera__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_CAMERA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_camera()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_CAMERA__EXTRA = "instance_camera__extra";

//---------------------------------------------------------------------
const instance_camera__extra__AttributeData instance_camera__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_camera__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_camera__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_camera__extra__AttributeData* attributeData = newData<instance_camera__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_CAMERA__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_camera__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_CONTROLLER = "instance_controller";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__INSTANCE_CONTROLLER = "node__instance_controller";

//---------------------------------------------------------------------
const instance_controller__AttributeData instance_controller__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_controller( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_controller__AttributeData* attributeData = newData<instance_controller__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_CONTROLLER, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_controller()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SKELETON = "skeleton";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_CONTROLLER__SKELETON = "instance_controller__skeleton";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__skeleton( const ParserChar* text, size_t textLength )
{

return mImpl->data__skeleton(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__skeleton( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__skeleton()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_MATERIAL = "bind_material";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_CONTROLLER__BIND_MATERIAL = "instance_controller__bind_material";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_controller__bind_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_controller__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_controller__bind_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_MATERIAL__PARAM = "bind_material__param";

//---------------------------------------------------------------------
const bind_material__param__AttributeData bind_material__param__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bind_material__param( const ParserChar* text, size_t textLength )
{

return mImpl->data__bind_material__param(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bind_material__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
bind_material__param__AttributeData* attributeData = newData<bind_material__param__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_BIND_MATERIAL__PARAM, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bind_material__param()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON = "bind_material__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bind_material__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bind_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bind_material__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_MATERIAL = "instance_material";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__INSTANCE_MATERIAL = "technique_common__instance_material";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_SYMBOL = "symbol";

//---------------------------------------------------------------------
const instance_material__AttributeData instance_material__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_material__AttributeData* attributeData = newData<instance_material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SYMBOL:
    {

attributeData->symbol = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TARGET:
    {

attributeData->target = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND = "bind";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_MATERIAL__BIND = "instance_material__bind";

//---------------------------------------------------------------------
const instance_material__bind__AttributeData instance_material__bind__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_material__bind( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_material__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_material__bind__AttributeData* attributeData = newData<instance_material__bind__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TARGET:
    {

attributeData->target = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_MATERIAL__BIND, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_material__bind()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_VERTEX_INPUT = "bind_vertex_input";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_MATERIAL__BIND_VERTEX_INPUT = "instance_material__bind_vertex_input";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_INPUT_SEMANTIC = "input_semantic";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_INPUT_SET = "input_set";

//---------------------------------------------------------------------
const bind_vertex_input__AttributeData bind_vertex_input__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bind_vertex_input( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bind_vertex_input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
bind_vertex_input__AttributeData* attributeData = newData<bind_vertex_input__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SEMANTIC:
    {

attributeData->semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_INPUT_SEMANTIC:
    {

attributeData->input_semantic = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_INPUT_SET:
    {
bool failed;
attributeData->input_set = GeneratedSaxParser::Utils::toUnsignedLongLong(attributeValue, failed);
if ( failed && handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_BIND_VERTEX_INPUT, HASH_ATTRIBUTE_INPUT_SET, attributeValue))
{return false;}
    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_BIND_VERTEX_INPUT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bind_vertex_input()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_MATERIAL__EXTRA = "instance_material__extra";

//---------------------------------------------------------------------
const instance_material__extra__AttributeData instance_material__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_material__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_material__extra__AttributeData* attributeData = newData<instance_material__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_MATERIAL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_material__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_MATERIAL__TECHNIQUE = "bind_material__technique";

//---------------------------------------------------------------------
const bind_material__technique__AttributeData bind_material__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bind_material__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bind_material__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
bind_material__technique__AttributeData* attributeData = newData<bind_material__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bind_material__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BIND_MATERIAL__EXTRA = "bind_material__extra";

//---------------------------------------------------------------------
const bind_material__extra__AttributeData bind_material__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__bind_material__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__bind_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
bind_material__extra__AttributeData* attributeData = newData<bind_material__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_BIND_MATERIAL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__bind_material__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_CONTROLLER__EXTRA = "instance_controller__extra";

//---------------------------------------------------------------------
const instance_controller__extra__AttributeData instance_controller__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_controller__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_controller__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_controller__extra__AttributeData* attributeData = newData<instance_controller__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_CONTROLLER__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_controller__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_GEOMETRY = "instance_geometry";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__INSTANCE_GEOMETRY = "node__instance_geometry";

//---------------------------------------------------------------------
const node__instance_geometry__AttributeData node__instance_geometry__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__node__instance_geometry( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__node__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
node__instance_geometry__AttributeData* attributeData = newData<node__instance_geometry__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NODE__INSTANCE_GEOMETRY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__node__instance_geometry()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_GEOMETRY__BIND_MATERIAL = "instance_geometry__bind_material";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_geometry__bind_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_geometry__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_geometry__bind_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_GEOMETRY__EXTRA = "instance_geometry__extra";

//---------------------------------------------------------------------
const instance_geometry__extra__AttributeData instance_geometry__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_geometry__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_geometry__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_geometry__extra__AttributeData* attributeData = newData<instance_geometry__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_GEOMETRY__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_geometry__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_LIGHT = "instance_light";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__INSTANCE_LIGHT = "node__instance_light";

//---------------------------------------------------------------------
const instance_light__AttributeData instance_light__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_light( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_light__AttributeData* attributeData = newData<instance_light__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_LIGHT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_light()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_LIGHT__EXTRA = "instance_light__extra";

//---------------------------------------------------------------------
const instance_light__extra__AttributeData instance_light__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_light__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_light__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_light__extra__AttributeData* attributeData = newData<instance_light__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_LIGHT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_light__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_NODE = "instance_node";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__INSTANCE_NODE = "node__instance_node";

//---------------------------------------------------------------------
const instance_node__AttributeData instance_node__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_node( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_node__AttributeData* attributeData = newData<instance_node__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_NODE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_node()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_NODE__EXTRA = "instance_node__extra";

//---------------------------------------------------------------------
const instance_node__extra__AttributeData instance_node__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_node__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_node__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_node__extra__AttributeData* attributeData = newData<instance_node__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_NODE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_node__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__NODE = "node__node";

//---------------------------------------------------------------------
const node__node__AttributeData node__node__AttributeData::DEFAULT = {0, 0, 0, (const GeneratedSaxParser::ParserChar *)"NODE", 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__node__node( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__node__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
node__node__AttributeData* attributeData = newData<node__node__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_LAYER:
    {

attributeData->layer = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NODE__NODE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__node__node()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_NODE__EXTRA = "node__extra";

//---------------------------------------------------------------------
const node__extra__AttributeData node__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__node__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__node__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
node__extra__AttributeData* attributeData = newData<node__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_NODE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__node__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_NODES__EXTRA = "library_nodes__extra";

//---------------------------------------------------------------------
const library_nodes__extra__AttributeData library_nodes__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_nodes__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_nodes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_nodes__extra__AttributeData* attributeData = newData<library_nodes__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_NODES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_nodes__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS = "library_physics_materials";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_MATERIALS = "COLLADA__library_physics_materials";

//---------------------------------------------------------------------
const library_physics_materials__AttributeData library_physics_materials__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_materials( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_materials__AttributeData* attributeData = newData<library_physics_materials__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_materials()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__ASSET = "library_physics_materials__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_materials__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_materials__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_materials__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MATERIAL = "physics_material";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL = "library_physics_materials__physics_material";

//---------------------------------------------------------------------
const library_physics_materials__physics_material__AttributeData library_physics_materials__physics_material__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_materials__physics_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_materials__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_materials__physics_material__AttributeData* attributeData = newData<library_physics_materials__physics_material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_materials__physics_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MATERIAL__ASSET = "physics_material__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_material__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_material__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_material__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON = "physics_material__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_material__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_material__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DYNAMIC_FRICTION = "dynamic_friction";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__DYNAMIC_FRICTION = "technique_common__dynamic_friction";

//---------------------------------------------------------------------
const dynamic_friction__AttributeData dynamic_friction__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__dynamic_friction( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__dynamic_friction(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_DYNAMIC_FRICTION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__dynamic_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
dynamic_friction__AttributeData* attributeData = newData<dynamic_friction__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_DYNAMIC_FRICTION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__dynamic_friction()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RESTITUTION = "restitution";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__RESTITUTION = "technique_common__restitution";

//---------------------------------------------------------------------
const restitution__AttributeData restitution__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__restitution( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__restitution(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_RESTITUTION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__restitution( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
restitution__AttributeData* attributeData = newData<restitution__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RESTITUTION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__restitution()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_STATIC_FRICTION = "static_friction";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__STATIC_FRICTION = "technique_common__static_friction";

//---------------------------------------------------------------------
const static_friction__AttributeData static_friction__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__static_friction( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__static_friction(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_STATIC_FRICTION, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__static_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
static_friction__AttributeData* attributeData = newData<static_friction__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_STATIC_FRICTION, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__static_friction()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE = "physics_material__technique";

//---------------------------------------------------------------------
const physics_material__technique__AttributeData physics_material__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_material__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_material__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_material__technique__AttributeData* attributeData = newData<physics_material__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_material__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MATERIAL__EXTRA = "physics_material__extra";

//---------------------------------------------------------------------
const physics_material__extra__AttributeData physics_material__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_material__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_material__extra__AttributeData* attributeData = newData<physics_material__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_MATERIAL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_material__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA = "library_physics_materials__extra";

//---------------------------------------------------------------------
const library_physics_materials__extra__AttributeData library_physics_materials__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_materials__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_materials__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_materials__extra__AttributeData* attributeData = newData<library_physics_materials__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_materials__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS = "library_physics_models";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_MODELS = "COLLADA__library_physics_models";

//---------------------------------------------------------------------
const library_physics_models__AttributeData library_physics_models__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_models( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_models__AttributeData* attributeData = newData<library_physics_models__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_MODELS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_models()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__ASSET = "library_physics_models__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_models__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_models__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_models__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MODEL = "physics_model";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__PHYSICS_MODEL = "library_physics_models__physics_model";

//---------------------------------------------------------------------
const physics_model__AttributeData physics_model__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_model( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_model__AttributeData* attributeData = newData<physics_model__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_MODEL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_model()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MODEL__ASSET = "physics_model__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_model__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_model__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_model__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_BODY = "rigid_body";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MODEL__RIGID_BODY = "physics_model__rigid_body";

//---------------------------------------------------------------------
const rigid_body__AttributeData rigid_body__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_body( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
rigid_body__AttributeData* attributeData = newData<rigid_body__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RIGID_BODY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_body()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON = "rigid_body__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_body__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_body__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DYNAMIC = "dynamic";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__DYNAMIC = "technique_common__dynamic";

//---------------------------------------------------------------------
const dynamic__AttributeData dynamic__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__dynamic( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__dynamic(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_DYNAMIC, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
dynamic__AttributeData* attributeData = newData<dynamic__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_DYNAMIC, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__dynamic()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MASS = "mass";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS = "technique_common__mass";

//---------------------------------------------------------------------
const technique_common__mass__AttributeData technique_common__mass__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__technique_common__mass( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__technique_common__mass(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_TECHNIQUE_COMMON__MASS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__technique_common__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
technique_common__mass__AttributeData* attributeData = newData<technique_common__mass__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TECHNIQUE_COMMON__MASS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__technique_common__mass()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MASS_FRAME = "mass_frame";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME = "technique_common__mass_frame";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mass_frame( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mass_frame()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MASS_FRAME__TRANSLATE = "mass_frame__translate";

//---------------------------------------------------------------------
const mass_frame__translate__AttributeData mass_frame__translate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mass_frame__translate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__mass_frame__translate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mass_frame__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mass_frame__translate__AttributeData* attributeData = newData<mass_frame__translate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MASS_FRAME__TRANSLATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mass_frame__translate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__mass_frame__translate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MASS_FRAME__ROTATE = "mass_frame__rotate";

//---------------------------------------------------------------------
const mass_frame__rotate__AttributeData mass_frame__rotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__mass_frame__rotate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__mass_frame__rotate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__mass_frame__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
mass_frame__rotate__AttributeData* attributeData = newData<mass_frame__rotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_MASS_FRAME__ROTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__mass_frame__rotate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__mass_frame__rotate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INERTIA = "inertia";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__INERTIA = "technique_common__inertia";

//---------------------------------------------------------------------
const inertia__AttributeData inertia__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__inertia( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__inertia);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__inertia( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
inertia__AttributeData* attributeData = newData<inertia__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INERTIA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__inertia()
{
return doubleDataEnd( &ColladaParserAutoGen::data__inertia );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MATERIAL = "instance_physics_material";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL = "technique_common__instance_physics_material";

//---------------------------------------------------------------------
const technique_common__instance_physics_material__AttributeData technique_common__instance_physics_material__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__technique_common__instance_physics_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__technique_common__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
technique_common__instance_physics_material__AttributeData* attributeData = newData<technique_common__instance_physics_material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__technique_common__instance_physics_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA = "instance_physics_material__extra";

//---------------------------------------------------------------------
const instance_physics_material__extra__AttributeData instance_physics_material__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_physics_material__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_physics_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_physics_material__extra__AttributeData* attributeData = newData<instance_physics_material__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_physics_material__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL = "technique_common__physics_material";

//---------------------------------------------------------------------
const technique_common__physics_material__AttributeData technique_common__physics_material__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__technique_common__physics_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__technique_common__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
technique_common__physics_material__AttributeData* attributeData = newData<technique_common__physics_material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__technique_common__physics_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE = "shape";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__SHAPE = "technique_common__shape";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_HOLLOW = "hollow";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__HOLLOW = "shape__hollow";

//---------------------------------------------------------------------
const hollow__AttributeData hollow__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__hollow( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__hollow(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_HOLLOW, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
hollow__AttributeData* attributeData = newData<hollow__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_HOLLOW, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__hollow()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__MASS = "shape__mass";

//---------------------------------------------------------------------
const shape__mass__AttributeData shape__mass__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__mass( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__shape__mass(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SHAPE__MASS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__mass__AttributeData* attributeData = newData<shape__mass__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__MASS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__mass()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DENSITY = "density";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__DENSITY = "shape__density";

//---------------------------------------------------------------------
const density__AttributeData density__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__density( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__density(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_DENSITY, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
density__AttributeData* attributeData = newData<density__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_DENSITY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__density()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__INSTANCE_PHYSICS_MATERIAL = "shape__instance_physics_material";

//---------------------------------------------------------------------
const shape__instance_physics_material__AttributeData shape__instance_physics_material__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__instance_physics_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__instance_physics_material__AttributeData* attributeData = newData<shape__instance_physics_material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__INSTANCE_PHYSICS_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__instance_physics_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__PHYSICS_MATERIAL = "shape__physics_material";

//---------------------------------------------------------------------
const shape__physics_material__AttributeData shape__physics_material__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__physics_material( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__physics_material__AttributeData* attributeData = newData<shape__physics_material__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__PHYSICS_MATERIAL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__physics_material()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__INSTANCE_GEOMETRY = "shape__instance_geometry";

//---------------------------------------------------------------------
const shape__instance_geometry__AttributeData shape__instance_geometry__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__instance_geometry( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__instance_geometry__AttributeData* attributeData = newData<shape__instance_geometry__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__INSTANCE_GEOMETRY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__instance_geometry()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PLANE = "plane";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__PLANE = "shape__plane";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__plane( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__plane()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EQUATION = "equation";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PLANE__EQUATION = "plane__equation";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__equation( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__equation);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__equation()
{
return doubleDataEnd( &ColladaParserAutoGen::data__equation );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PLANE__EXTRA = "plane__extra";

//---------------------------------------------------------------------
const plane__extra__AttributeData plane__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__plane__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__plane__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
plane__extra__AttributeData* attributeData = newData<plane__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PLANE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__plane__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOX = "box";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__BOX = "shape__box";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__box( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__box( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__box()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_HALF_EXTENTS = "half_extents";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOX__HALF_EXTENTS = "box__half_extents";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__half_extents( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__half_extents);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__half_extents( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__half_extents()
{
return doubleDataEnd( &ColladaParserAutoGen::data__half_extents );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_BOX__EXTRA = "box__extra";

//---------------------------------------------------------------------
const box__extra__AttributeData box__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__box__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__box__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
box__extra__AttributeData* attributeData = newData<box__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_BOX__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__box__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPHERE = "sphere";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__SPHERE = "shape__sphere";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sphere( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sphere( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sphere()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RADIUS = "radius";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPHERE__RADIUS = "sphere__radius";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sphere__radius( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__sphere__radius(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_SPHERE__RADIUS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sphere__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sphere__radius()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPHERE__EXTRA = "sphere__extra";

//---------------------------------------------------------------------
const sphere__extra__AttributeData sphere__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__sphere__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__sphere__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
sphere__extra__AttributeData* attributeData = newData<sphere__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SPHERE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__sphere__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CYLINDER = "cylinder";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__CYLINDER = "shape__cylinder";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__cylinder( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__cylinder()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_HEIGHT = "height";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CYLINDER__HEIGHT = "cylinder__height";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__cylinder__height( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__cylinder__height(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_CYLINDER__HEIGHT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__cylinder__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__cylinder__height()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CYLINDER__RADIUS = "cylinder__radius";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__cylinder__radius( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__cylinder__radius);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__cylinder__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__cylinder__radius()
{
return doubleDataEnd( &ColladaParserAutoGen::data__cylinder__radius );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CYLINDER__EXTRA = "cylinder__extra";

//---------------------------------------------------------------------
const cylinder__extra__AttributeData cylinder__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__cylinder__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__cylinder__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
cylinder__extra__AttributeData* attributeData = newData<cylinder__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CYLINDER__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__cylinder__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CYLINDER = "tapered_cylinder";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__TAPERED_CYLINDER = "shape__tapered_cylinder";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_cylinder( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_cylinder()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CYLINDER__HEIGHT = "tapered_cylinder__height";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_cylinder__height( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__tapered_cylinder__height(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_TAPERED_CYLINDER__HEIGHT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_cylinder__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_cylinder__height()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RADIUS1 = "radius1";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CYLINDER__RADIUS1 = "tapered_cylinder__radius1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_cylinder__radius1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__tapered_cylinder__radius1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_cylinder__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_cylinder__radius1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__tapered_cylinder__radius1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RADIUS2 = "radius2";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CYLINDER__RADIUS2 = "tapered_cylinder__radius2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_cylinder__radius2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__tapered_cylinder__radius2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_cylinder__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_cylinder__radius2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__tapered_cylinder__radius2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CYLINDER__EXTRA = "tapered_cylinder__extra";

//---------------------------------------------------------------------
const tapered_cylinder__extra__AttributeData tapered_cylinder__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_cylinder__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_cylinder__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
tapered_cylinder__extra__AttributeData* attributeData = newData<tapered_cylinder__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TAPERED_CYLINDER__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_cylinder__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAPSULE = "capsule";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__CAPSULE = "shape__capsule";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__capsule( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__capsule()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAPSULE__HEIGHT = "capsule__height";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__capsule__height( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__capsule__height(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_CAPSULE__HEIGHT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__capsule__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__capsule__height()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAPSULE__RADIUS = "capsule__radius";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__capsule__radius( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__capsule__radius);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__capsule__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__capsule__radius()
{
return doubleDataEnd( &ColladaParserAutoGen::data__capsule__radius );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_CAPSULE__EXTRA = "capsule__extra";

//---------------------------------------------------------------------
const capsule__extra__AttributeData capsule__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__capsule__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__capsule__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
capsule__extra__AttributeData* attributeData = newData<capsule__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_CAPSULE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__capsule__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CAPSULE = "tapered_capsule";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__TAPERED_CAPSULE = "shape__tapered_capsule";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_capsule( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_capsule()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CAPSULE__HEIGHT = "tapered_capsule__height";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_capsule__height( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__tapered_capsule__height(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_TAPERED_CAPSULE__HEIGHT, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_capsule__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_capsule__height()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CAPSULE__RADIUS1 = "tapered_capsule__radius1";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_capsule__radius1( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__tapered_capsule__radius1);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_capsule__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_capsule__radius1()
{
return doubleDataEnd( &ColladaParserAutoGen::data__tapered_capsule__radius1 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CAPSULE__RADIUS2 = "tapered_capsule__radius2";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_capsule__radius2( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__tapered_capsule__radius2);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_capsule__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_capsule__radius2()
{
return doubleDataEnd( &ColladaParserAutoGen::data__tapered_capsule__radius2 );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TAPERED_CAPSULE__EXTRA = "tapered_capsule__extra";

//---------------------------------------------------------------------
const tapered_capsule__extra__AttributeData tapered_capsule__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__tapered_capsule__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__tapered_capsule__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
tapered_capsule__extra__AttributeData* attributeData = newData<tapered_capsule__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TAPERED_CAPSULE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__tapered_capsule__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__TRANSLATE = "shape__translate";

//---------------------------------------------------------------------
const shape__translate__AttributeData shape__translate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__translate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__shape__translate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__translate__AttributeData* attributeData = newData<shape__translate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__TRANSLATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__translate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__shape__translate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__ROTATE = "shape__rotate";

//---------------------------------------------------------------------
const shape__rotate__AttributeData shape__rotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__rotate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__shape__rotate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__rotate__AttributeData* attributeData = newData<shape__rotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__ROTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__rotate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__shape__rotate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SHAPE__EXTRA = "shape__extra";

//---------------------------------------------------------------------
const shape__extra__AttributeData shape__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__shape__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__shape__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
shape__extra__AttributeData* attributeData = newData<shape__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SHAPE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__shape__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE = "rigid_body__technique";

//---------------------------------------------------------------------
const rigid_body__technique__AttributeData rigid_body__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_body__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_body__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
rigid_body__technique__AttributeData* attributeData = newData<rigid_body__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RIGID_BODY__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_body__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_BODY__EXTRA = "rigid_body__extra";

//---------------------------------------------------------------------
const rigid_body__extra__AttributeData rigid_body__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_body__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_body__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
rigid_body__extra__AttributeData* attributeData = newData<rigid_body__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RIGID_BODY__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_body__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_CONSTRAINT = "rigid_constraint";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MODEL__RIGID_CONSTRAINT = "physics_model__rigid_constraint";

//---------------------------------------------------------------------
const rigid_constraint__AttributeData rigid_constraint__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_constraint( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
rigid_constraint__AttributeData* attributeData = newData<rigid_constraint__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RIGID_CONSTRAINT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_constraint()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_REF_ATTACHMENT = "ref_attachment";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_CONSTRAINT__REF_ATTACHMENT = "rigid_constraint__ref_attachment";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_RIGID_BODY = "rigid_body";

//---------------------------------------------------------------------
const ref_attachment__AttributeData ref_attachment__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ref_attachment( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ref_attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
ref_attachment__AttributeData* attributeData = newData<ref_attachment__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_RIGID_BODY:
    {

attributeData->rigid_body = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_REF_ATTACHMENT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ref_attachment()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_REF_ATTACHMENT__TRANSLATE = "ref_attachment__translate";

//---------------------------------------------------------------------
const ref_attachment__translate__AttributeData ref_attachment__translate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ref_attachment__translate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__ref_attachment__translate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ref_attachment__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
ref_attachment__translate__AttributeData* attributeData = newData<ref_attachment__translate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_REF_ATTACHMENT__TRANSLATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ref_attachment__translate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__ref_attachment__translate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_REF_ATTACHMENT__ROTATE = "ref_attachment__rotate";

//---------------------------------------------------------------------
const ref_attachment__rotate__AttributeData ref_attachment__rotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ref_attachment__rotate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__ref_attachment__rotate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ref_attachment__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
ref_attachment__rotate__AttributeData* attributeData = newData<ref_attachment__rotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_REF_ATTACHMENT__ROTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ref_attachment__rotate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__ref_attachment__rotate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_REF_ATTACHMENT__EXTRA = "ref_attachment__extra";

//---------------------------------------------------------------------
const ref_attachment__extra__AttributeData ref_attachment__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__ref_attachment__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__ref_attachment__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
ref_attachment__extra__AttributeData* attributeData = newData<ref_attachment__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_REF_ATTACHMENT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__ref_attachment__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ATTACHMENT = "attachment";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_CONSTRAINT__ATTACHMENT = "rigid_constraint__attachment";

//---------------------------------------------------------------------
const attachment__AttributeData attachment__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__attachment( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
attachment__AttributeData* attributeData = newData<attachment__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_RIGID_BODY:
    {

attributeData->rigid_body = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ATTACHMENT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__attachment()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ATTACHMENT__TRANSLATE = "attachment__translate";

//---------------------------------------------------------------------
const attachment__translate__AttributeData attachment__translate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__attachment__translate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__attachment__translate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__attachment__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
attachment__translate__AttributeData* attributeData = newData<attachment__translate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ATTACHMENT__TRANSLATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__attachment__translate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__attachment__translate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ATTACHMENT__ROTATE = "attachment__rotate";

//---------------------------------------------------------------------
const attachment__rotate__AttributeData attachment__rotate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__attachment__rotate( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__attachment__rotate);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__attachment__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
attachment__rotate__AttributeData* attributeData = newData<attachment__rotate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ATTACHMENT__ROTATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__attachment__rotate()
{
return doubleDataEnd( &ColladaParserAutoGen::data__attachment__rotate );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ATTACHMENT__EXTRA = "attachment__extra";

//---------------------------------------------------------------------
const attachment__extra__AttributeData attachment__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__attachment__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__attachment__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
attachment__extra__AttributeData* attributeData = newData<attachment__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ATTACHMENT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__attachment__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON = "rigid_constraint__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_constraint__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_constraint__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_constraint__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ENABLED = "enabled";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__ENABLED = "technique_common__enabled";

//---------------------------------------------------------------------
const enabled__AttributeData enabled__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__enabled( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__enabled(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ENABLED, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__enabled( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
enabled__AttributeData* attributeData = newData<enabled__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ENABLED, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__enabled()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INTERPENETRATE = "interpenetrate";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__INTERPENETRATE = "technique_common__interpenetrate";

//---------------------------------------------------------------------
const interpenetrate__AttributeData interpenetrate__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__interpenetrate( const ParserChar* text, size_t textLength )
{
bool failed;
bool parameter = GeneratedSaxParser::Utils::toBool(text, failed);
if (!failed)
    return mImpl->data__interpenetrate(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_INTERPENETRATE, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__interpenetrate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
interpenetrate__AttributeData* attributeData = newData<interpenetrate__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INTERPENETRATE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__interpenetrate()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIMITS = "limits";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__LIMITS = "technique_common__limits";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__limits( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__limits( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__limits()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SWING_CONE_AND_TWIST = "swing_cone_and_twist";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIMITS__SWING_CONE_AND_TWIST = "limits__swing_cone_and_twist";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__swing_cone_and_twist( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__swing_cone_and_twist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__swing_cone_and_twist()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MIN = "min";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MIN = "swing_cone_and_twist__min";

//---------------------------------------------------------------------
const swing_cone_and_twist__min__AttributeData swing_cone_and_twist__min__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__swing_cone_and_twist__min( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__swing_cone_and_twist__min);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__swing_cone_and_twist__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
swing_cone_and_twist__min__AttributeData* attributeData = newData<swing_cone_and_twist__min__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SWING_CONE_AND_TWIST__MIN, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__swing_cone_and_twist__min()
{
return doubleDataEnd( &ColladaParserAutoGen::data__swing_cone_and_twist__min );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_MAX = "max";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MAX = "swing_cone_and_twist__max";

//---------------------------------------------------------------------
const swing_cone_and_twist__max__AttributeData swing_cone_and_twist__max__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__swing_cone_and_twist__max( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__swing_cone_and_twist__max);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__swing_cone_and_twist__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
swing_cone_and_twist__max__AttributeData* attributeData = newData<swing_cone_and_twist__max__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SWING_CONE_AND_TWIST__MAX, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__swing_cone_and_twist__max()
{
return doubleDataEnd( &ColladaParserAutoGen::data__swing_cone_and_twist__max );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR = "linear";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIMITS__LINEAR = "limits__linear";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__limits__linear( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__limits__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__limits__linear()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR__MIN = "linear__min";

//---------------------------------------------------------------------
const linear__min__AttributeData linear__min__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linear__min( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__linear__min);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linear__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linear__min__AttributeData* attributeData = newData<linear__min__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINEAR__MIN, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linear__min()
{
return doubleDataEnd( &ColladaParserAutoGen::data__linear__min );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR__MAX = "linear__max";

//---------------------------------------------------------------------
const linear__max__AttributeData linear__max__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linear__max( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__linear__max);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linear__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linear__max__AttributeData* attributeData = newData<linear__max__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINEAR__MAX, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linear__max()
{
return doubleDataEnd( &ColladaParserAutoGen::data__linear__max );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPRING = "spring";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPRING = "technique_common__spring";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spring( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spring( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spring()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANGULAR = "angular";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPRING__ANGULAR = "spring__angular";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__angular( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__angular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__angular()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_STIFFNESS = "stiffness";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANGULAR__STIFFNESS = "angular__stiffness";

//---------------------------------------------------------------------
const angular__stiffness__AttributeData angular__stiffness__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__angular__stiffness( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__angular__stiffness(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ANGULAR__STIFFNESS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__angular__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
angular__stiffness__AttributeData* attributeData = newData<angular__stiffness__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANGULAR__STIFFNESS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__angular__stiffness()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_DAMPING = "damping";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANGULAR__DAMPING = "angular__damping";

//---------------------------------------------------------------------
const angular__damping__AttributeData angular__damping__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__angular__damping( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__angular__damping(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ANGULAR__DAMPING, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__angular__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
angular__damping__AttributeData* attributeData = newData<angular__damping__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANGULAR__DAMPING, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__angular__damping()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TARGET_VALUE = "target_value";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANGULAR__TARGET_VALUE = "angular__target_value";

//---------------------------------------------------------------------
const angular__target_value__AttributeData angular__target_value__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__angular__target_value( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__angular__target_value(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_ANGULAR__TARGET_VALUE, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__angular__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
angular__target_value__AttributeData* attributeData = newData<angular__target_value__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_ANGULAR__TARGET_VALUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__angular__target_value()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SPRING__LINEAR = "spring__linear";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__spring__linear( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__spring__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__spring__linear()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR__STIFFNESS = "linear__stiffness";

//---------------------------------------------------------------------
const linear__stiffness__AttributeData linear__stiffness__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linear__stiffness( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__linear__stiffness(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_LINEAR__STIFFNESS, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linear__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linear__stiffness__AttributeData* attributeData = newData<linear__stiffness__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINEAR__STIFFNESS, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linear__stiffness()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR__DAMPING = "linear__damping";

//---------------------------------------------------------------------
const linear__damping__AttributeData linear__damping__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linear__damping( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__linear__damping(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_LINEAR__DAMPING, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linear__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linear__damping__AttributeData* attributeData = newData<linear__damping__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINEAR__DAMPING, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linear__damping()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LINEAR__TARGET_VALUE = "linear__target_value";

//---------------------------------------------------------------------
const linear__target_value__AttributeData linear__target_value__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__linear__target_value( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__linear__target_value(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_LINEAR__TARGET_VALUE, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__linear__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
linear__target_value__AttributeData* attributeData = newData<linear__target_value__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LINEAR__TARGET_VALUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__linear__target_value()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE = "rigid_constraint__technique";

//---------------------------------------------------------------------
const rigid_constraint__technique__AttributeData rigid_constraint__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_constraint__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_constraint__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
rigid_constraint__technique__AttributeData* attributeData = newData<rigid_constraint__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_constraint__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RIGID_CONSTRAINT__EXTRA = "rigid_constraint__extra";

//---------------------------------------------------------------------
const rigid_constraint__extra__AttributeData rigid_constraint__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__rigid_constraint__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__rigid_constraint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
rigid_constraint__extra__AttributeData* attributeData = newData<rigid_constraint__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RIGID_CONSTRAINT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__rigid_constraint__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL = "instance_physics_model";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL = "physics_model__instance_physics_model";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_PARENT = "parent";

//---------------------------------------------------------------------
const physics_model__instance_physics_model__AttributeData physics_model__instance_physics_model__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_model__instance_physics_model( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_model__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_model__instance_physics_model__AttributeData* attributeData = newData<physics_model__instance_physics_model__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_PARENT:
    {

attributeData->parent = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_model__instance_physics_model()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD = "instance_force_field";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD = "instance_physics_model__instance_force_field";

//---------------------------------------------------------------------
const instance_physics_model__instance_force_field__AttributeData instance_physics_model__instance_force_field__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_physics_model__instance_force_field( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_physics_model__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_physics_model__instance_force_field__AttributeData* attributeData = newData<instance_physics_model__instance_force_field__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_physics_model__instance_force_field()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA = "instance_force_field__extra";

//---------------------------------------------------------------------
const instance_force_field__extra__AttributeData instance_force_field__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_force_field__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_force_field__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_force_field__extra__AttributeData* attributeData = newData<instance_force_field__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_force_field__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_RIGID_BODY = "instance_rigid_body";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_BODY = "instance_physics_model__instance_rigid_body";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_BODY = "body";

//---------------------------------------------------------------------
const instance_rigid_body__AttributeData instance_rigid_body__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_rigid_body( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_rigid_body__AttributeData* attributeData = newData<instance_rigid_body__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_BODY:
    {

attributeData->body = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TARGET:
    {

attributeData->target = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_RIGID_BODY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_rigid_body()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON = "instance_rigid_body__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_rigid_body__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_rigid_body__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_ANGULAR_VELOCITY = "angular_velocity";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__ANGULAR_VELOCITY = "technique_common__angular_velocity";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__angular_velocity( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__angular_velocity);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__angular_velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__angular_velocity()
{
return doubleDataEnd( &ColladaParserAutoGen::data__angular_velocity );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VELOCITY = "velocity";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__VELOCITY = "technique_common__velocity";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__velocity( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__velocity);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__velocity()
{
return doubleDataEnd( &ColladaParserAutoGen::data__velocity );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE = "instance_rigid_body__technique";

//---------------------------------------------------------------------
const instance_rigid_body__technique__AttributeData instance_rigid_body__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_rigid_body__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_rigid_body__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_rigid_body__technique__AttributeData* attributeData = newData<instance_rigid_body__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_rigid_body__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__EXTRA = "instance_rigid_body__extra";

//---------------------------------------------------------------------
const instance_rigid_body__extra__AttributeData instance_rigid_body__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_rigid_body__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_rigid_body__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_rigid_body__extra__AttributeData* attributeData = newData<instance_rigid_body__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_RIGID_BODY__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_rigid_body__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_RIGID_CONSTRAINT = "instance_rigid_constraint";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_CONSTRAINT = "instance_physics_model__instance_rigid_constraint";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_CONSTRAINT = "constraint";

//---------------------------------------------------------------------
const instance_rigid_constraint__AttributeData instance_rigid_constraint__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_rigid_constraint( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_rigid_constraint__AttributeData* attributeData = newData<instance_rigid_constraint__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_CONSTRAINT:
    {

attributeData->constraint = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_rigid_constraint()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_RIGID_CONSTRAINT__EXTRA = "instance_rigid_constraint__extra";

//---------------------------------------------------------------------
const instance_rigid_constraint__extra__AttributeData instance_rigid_constraint__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_rigid_constraint__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_rigid_constraint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_rigid_constraint__extra__AttributeData* attributeData = newData<instance_rigid_constraint__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_rigid_constraint__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA = "instance_physics_model__extra";

//---------------------------------------------------------------------
const instance_physics_model__extra__AttributeData instance_physics_model__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_physics_model__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_physics_model__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_physics_model__extra__AttributeData* attributeData = newData<instance_physics_model__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_physics_model__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_MODEL__EXTRA = "physics_model__extra";

//---------------------------------------------------------------------
const physics_model__extra__AttributeData physics_model__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_model__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_model__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_model__extra__AttributeData* attributeData = newData<physics_model__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_MODEL__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_model__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA = "library_physics_models__extra";

//---------------------------------------------------------------------
const library_physics_models__extra__AttributeData library_physics_models__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_models__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_models__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_models__extra__AttributeData* attributeData = newData<library_physics_models__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_models__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES = "library_physics_scenes";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_SCENES = "COLLADA__library_physics_scenes";

//---------------------------------------------------------------------
const library_physics_scenes__AttributeData library_physics_scenes__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_scenes( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_scenes__AttributeData* attributeData = newData<library_physics_scenes__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_SCENES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_scenes()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__ASSET = "library_physics_scenes__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_scenes__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_scenes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_scenes__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE = "physics_scene";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__PHYSICS_SCENE = "library_physics_scenes__physics_scene";

//---------------------------------------------------------------------
const physics_scene__AttributeData physics_scene__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_scene__AttributeData* attributeData = newData<physics_scene__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_SCENE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE__ASSET = "physics_scene__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD = "physics_scene__instance_force_field";

//---------------------------------------------------------------------
const physics_scene__instance_force_field__AttributeData physics_scene__instance_force_field__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene__instance_force_field( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_scene__instance_force_field__AttributeData* attributeData = newData<physics_scene__instance_force_field__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene__instance_force_field()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL = "physics_scene__instance_physics_model";

//---------------------------------------------------------------------
const physics_scene__instance_physics_model__AttributeData physics_scene__instance_physics_model__AttributeData::DEFAULT = {0, 0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene__instance_physics_model( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_scene__instance_physics_model__AttributeData* attributeData = newData<physics_scene__instance_physics_model__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_PARENT:
    {

attributeData->parent = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene__instance_physics_model()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON = "physics_scene__technique_common";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene__technique_common( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene__technique_common()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_GRAVITY = "gravity";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__GRAVITY = "technique_common__gravity";

//---------------------------------------------------------------------
const gravity__AttributeData gravity__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__gravity( const ParserChar* text, size_t textLength )
{
return characterData2DoubleData(text, textLength, &ColladaParserAutoGen::data__gravity);
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__gravity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
gravity__AttributeData* attributeData = newData<gravity__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_GRAVITY, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__gravity()
{
return doubleDataEnd( &ColladaParserAutoGen::data__gravity );
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TIME_STEP = "time_step";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_TECHNIQUE_COMMON__TIME_STEP = "technique_common__time_step";

//---------------------------------------------------------------------
const time_step__AttributeData time_step__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__time_step( const ParserChar* text, size_t textLength )
{
bool failed;
double parameter = GeneratedSaxParser::Utils::toDouble(text, failed);
if (!failed)
    return mImpl->data__time_step(parameter);
else
    return !handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_TEXTDATA_PARSING_FAILED, HASH_ELEMENT_TIME_STEP, 0, text);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__time_step( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
time_step__AttributeData* attributeData = newData<time_step__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_TIME_STEP, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__time_step()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE__TECHNIQUE = "physics_scene__technique";

//---------------------------------------------------------------------
const physics_scene__technique__AttributeData physics_scene__technique__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene__technique( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_scene__technique__AttributeData* attributeData = newData<physics_scene__technique__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_PROFILE:
    {

attributeData->profile = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene__technique()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_PHYSICS_SCENE__EXTRA = "physics_scene__extra";

//---------------------------------------------------------------------
const physics_scene__extra__AttributeData physics_scene__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__physics_scene__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__physics_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
physics_scene__extra__AttributeData* attributeData = newData<physics_scene__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_PHYSICS_SCENE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__physics_scene__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA = "library_physics_scenes__extra";

//---------------------------------------------------------------------
const library_physics_scenes__extra__AttributeData library_physics_scenes__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_physics_scenes__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_physics_scenes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_physics_scenes__extra__AttributeData* attributeData = newData<library_physics_scenes__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_physics_scenes__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES = "library_visual_scenes";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__LIBRARY_VISUAL_SCENES = "COLLADA__library_visual_scenes";

//---------------------------------------------------------------------
const library_visual_scenes__AttributeData library_visual_scenes__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_visual_scenes( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_visual_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_visual_scenes__AttributeData* attributeData = newData<library_visual_scenes__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_VISUAL_SCENES, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_visual_scenes()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__ASSET = "library_visual_scenes__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_visual_scenes__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_visual_scenes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_visual_scenes__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VISUAL_SCENE = "visual_scene";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__VISUAL_SCENE = "library_visual_scenes__visual_scene";

//---------------------------------------------------------------------
const visual_scene__AttributeData visual_scene__AttributeData::DEFAULT = {0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__visual_scene( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
visual_scene__AttributeData* attributeData = newData<visual_scene__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VISUAL_SCENE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__visual_scene()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VISUAL_SCENE__ASSET = "visual_scene__asset";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__visual_scene__asset( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__visual_scene__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__visual_scene__asset()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VISUAL_SCENE__NODE = "visual_scene__node";

//---------------------------------------------------------------------
const visual_scene__node__AttributeData visual_scene__node__AttributeData::DEFAULT = {0, 0, 0, (const GeneratedSaxParser::ParserChar *)"NODE", 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__visual_scene__node( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__visual_scene__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
visual_scene__node__AttributeData* attributeData = newData<visual_scene__node__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_LAYER:
    {

attributeData->layer = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VISUAL_SCENE__NODE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__visual_scene__node()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EVALUATE_SCENE = "evaluate_scene";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VISUAL_SCENE__EVALUATE_SCENE = "visual_scene__evaluate_scene";

//---------------------------------------------------------------------
const evaluate_scene__AttributeData evaluate_scene__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__evaluate_scene( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__evaluate_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
evaluate_scene__AttributeData* attributeData = newData<evaluate_scene__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_EVALUATE_SCENE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__evaluate_scene()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RENDER = "render";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_EVALUATE_SCENE__RENDER = "evaluate_scene__render";

//---------------------------------------------------------------------
const char* NAME_ATTRIBUTE_CAMERA_NODE = "camera_node";

//---------------------------------------------------------------------
const render__AttributeData render__AttributeData::DEFAULT = {0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__render( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__render( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
render__AttributeData* attributeData = newData<render__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_CAMERA_NODE:
    {

attributeData->camera_node = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RENDER, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__render()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LAYER = "layer";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RENDER__LAYER = "render__layer";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__layer( const ParserChar* text, size_t textLength )
{

return mImpl->data__layer(text, textLength);

}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__layer( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__layer()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_RENDER__INSTANCE_EFFECT = "render__instance_effect";

//---------------------------------------------------------------------
const render__instance_effect__AttributeData render__instance_effect__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__render__instance_effect( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__render__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
render__instance_effect__AttributeData* attributeData = newData<render__instance_effect__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_RENDER__INSTANCE_EFFECT, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__render__instance_effect()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_VISUAL_SCENE__EXTRA = "visual_scene__extra";

//---------------------------------------------------------------------
const visual_scene__extra__AttributeData visual_scene__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__visual_scene__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__visual_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
visual_scene__extra__AttributeData* attributeData = newData<visual_scene__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_VISUAL_SCENE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__visual_scene__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA = "library_visual_scenes__extra";

//---------------------------------------------------------------------
const library_visual_scenes__extra__AttributeData library_visual_scenes__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__library_visual_scenes__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__library_visual_scenes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
library_visual_scenes__extra__AttributeData* attributeData = newData<library_visual_scenes__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__library_visual_scenes__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SCENE = "scene";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__SCENE = "COLLADA__scene";

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__scene( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__scene()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_SCENE = "instance_physics_scene";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SCENE__INSTANCE_PHYSICS_SCENE = "scene__instance_physics_scene";

//---------------------------------------------------------------------
const instance_physics_scene__AttributeData instance_physics_scene__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_physics_scene( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_physics_scene__AttributeData* attributeData = newData<instance_physics_scene__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_PHYSICS_SCENE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_physics_scene()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_PHYSICS_SCENE__EXTRA = "instance_physics_scene__extra";

//---------------------------------------------------------------------
const instance_physics_scene__extra__AttributeData instance_physics_scene__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_physics_scene__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_physics_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_physics_scene__extra__AttributeData* attributeData = newData<instance_physics_scene__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_PHYSICS_SCENE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_physics_scene__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_VISUAL_SCENE = "instance_visual_scene";

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SCENE__INSTANCE_VISUAL_SCENE = "scene__instance_visual_scene";

//---------------------------------------------------------------------
const instance_visual_scene__AttributeData instance_visual_scene__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_visual_scene( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_visual_scene__AttributeData* attributeData = newData<instance_visual_scene__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_URL:
    {

attributeData->url = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_SID:
    {

attributeData->sid = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_VISUAL_SCENE, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_visual_scene()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_INSTANCE_VISUAL_SCENE__EXTRA = "instance_visual_scene__extra";

//---------------------------------------------------------------------
const instance_visual_scene__extra__AttributeData instance_visual_scene__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__instance_visual_scene__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__instance_visual_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
instance_visual_scene__extra__AttributeData* attributeData = newData<instance_visual_scene__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_INSTANCE_VISUAL_SCENE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__instance_visual_scene__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_SCENE__EXTRA = "scene__extra";

//---------------------------------------------------------------------
const scene__extra__AttributeData scene__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__scene__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
scene__extra__AttributeData* attributeData = newData<scene__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_SCENE__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__scene__extra()
{
    return true;
}

//---------------------------------------------------------------------
const char* NAME_ELEMENT_COLLADA__EXTRA = "COLLADA__extra";

//---------------------------------------------------------------------
const COLLADA__extra__AttributeData COLLADA__extra__AttributeData::DEFAULT = {0, 0, 0};

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_data__COLLADA__extra( const ParserChar* text, size_t textLength )
{
    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateBegin__COLLADA__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr )
{
COLLADA__extra__AttributeData* attributeData = newData<COLLADA__extra__AttributeData>(attributeDataPtr);

const ParserChar** attributeArray = attributes.attributes;
if ( attributeArray )
{
    while (true)
    {
        const ParserChar * attribute = *attributeArray;
        if ( !attribute ) 
            break;
        StringHash hash = GeneratedSaxParser::Utils::calculateStringHash(attribute);
        attributeArray++;
        if ( !attributeArray )
            return false;
        const ParserChar* attributeValue = *attributeArray;
        attributeArray++;


    switch ( hash )
    {
    case HASH_ATTRIBUTE_ID:
    {

attributeData->id = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_NAME:
    {

attributeData->name = attributeValue;

    break;
    }
    case HASH_ATTRIBUTE_TYPE:
    {

attributeData->type = attributeValue;

    break;
    }
    default:
    {
        if ( handleError(ParserError::SEVERITY_ERROR, ParserError::ERROR_UNKNOWN_ATTRIBUTE, HASH_ELEMENT_COLLADA__EXTRA, 0, attributeValue))
            {return false;}
    }
    }
    }
}

    return true;
}

//---------------------------------------------------------------------
bool ColladaParserAutoGenPrivate::_validateEnd__COLLADA__extra()
{
    return true;
}




}
