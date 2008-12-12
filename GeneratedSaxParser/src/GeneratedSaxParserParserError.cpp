#include "GeneratedSaxParserParserError.h"
#include <sstream>

namespace GeneratedSaxParser
{

	ParserError::ParserError( Severity severity, 
		                      ErrorType errorType, 
							  const char* elementName, 
							  const char* attributeName, 
							  size_t lineNumber, 
							  size_t columnNumber, 
							  String additionalText /*= ""*/ )
		: mSeverity(severity),
		mErrorType(errorType),
		mElementName(elementName),
		mAttributeName(attributeName),
		mLineNumber(lineNumber),
		mColumnNumber(columnNumber),
		mAdditionalText(additionalText)
	{

	}

	//--------------------------------------------------------------------
	ParserError::~ParserError()
	{
	}

	GeneratedSaxParser::String ParserError::getErrorMessage() const
	{
		std::stringstream errorMessage;
		if ( mSeverity == SEVERITY_CRITICAL )
			errorMessage << "Critical error: ";
		else
			errorMessage << "Error: ";


		switch ( mErrorType )
		{
		case ERROR_UNEXPECTED_ELEMENT:
			errorMessage << "ERROR_UNEXPECTED_ELEMENT ";
			break;
		case ERROR_UNKNOWN_ELEMENT:
			errorMessage << "ERROR_UNKNOWN_ELEMENT ";
			break;
		case ERROR_ELEMENT_MUST_BE_ROOT:
			errorMessage << "ERROR_ELEMENT_MUST_BE_ROOT ";
			break;
		case ERROR_ELEMENT_MUST_NOT_BE_ROOT:
			errorMessage << "ERROR_ELEMENT_MUST_NOT_BE_ROOT ";
			break;
		case ERROR_TEXTDATA_PARSING_FAILED:
			errorMessage << "ERROR_TEXTDATA_PARSING_FAILED ";
			break;
		case ERROR_UNKNOWN_ATTRIBUTE:
			errorMessage << "ERROR_UNKNOWN_ATTRIBUTE ";
			break;
		case ERROR_ATTRIBUTE_PARSING_FAILED:
			errorMessage << "ERROR_ATTRIBUTE_PARSING_FAILED ";
			break;
		}
		
		if ( mElementName )
			errorMessage << "Element: " << mElementName << ", ";
		
		if ( mAttributeName )
			errorMessage << "Attribute: " << mAttributeName << ", ";

		errorMessage << "Line: " <<  mLineNumber << ", ";
		errorMessage << "Column: " <<  mColumnNumber << ", ";
		errorMessage << "Additional: " << mAdditionalText;
		
		return errorMessage.str();
	}
} // namespace GeneratedSaxParser
