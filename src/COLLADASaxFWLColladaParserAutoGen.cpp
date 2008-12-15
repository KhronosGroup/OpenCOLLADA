#include "COLLADASaxFWLStableHeaders.h"
#include "GeneratedSaxParserUtils.h"

#include "COLLADASaxFWLColladaParserAutoGen.h"
#include "COLLADASaxFWLColladaParserAutoGenPrivate.h"


namespace COLLADASaxFWL
{


//---------------------------------------------------------------------
const char* ColladaParserAutoGenPrivate::PARENT_CHILD_ELEMENT_SEPARATOR = "__";


//---------------------------------------------------------------------
ColladaParserAutoGenPrivate::ColladaParserAutoGenPrivate( ColladaParserAutoGen* impl,  GeneratedSaxParser::IErrorHandler* errorHandler )
: ParserTemplate(impl, errorHandler)
{
 //   initFunctionMap();
 //   initNameMap();
}

//---------------------------------------------------------------------
ColladaParserAutoGenPrivate::~ColladaParserAutoGenPrivate()
{
}




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
        if ( handleError(ParserError::SEVERITY_ERROR,ParserError::ERROR_ATTRIBUTE_PARSING_FAILED,HASH_ELEMENT_NODE__TRANSLATE , 0, attributeValue))
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
    return true;
}


}
