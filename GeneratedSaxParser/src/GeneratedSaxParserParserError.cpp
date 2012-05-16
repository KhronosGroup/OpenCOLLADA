/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

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
		case ERROR_COULD_NOT_OPEN_FILE:
			errorMessage << "ERROR_COULD_NOT_OPEN_FILE ";
			break;
		case ERROR_UNKNOWN_ELEMENT:
			errorMessage << "ERROR_UNKNOWN_ELEMENT ";
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
        case ERROR_REQUIRED_ATTRIBUTE_MISSING:
            errorMessage << "ERROR_REQUIRED_ATTRIBUTE_MISSING ";
            break;
        case ERROR_VALIDATION_MAX_OCCURS_EXCEEDED:
            errorMessage << "ERROR_VALIDATION_MAX_OCCURS_EXCEEDED ";
            break;
        case ERROR_VALIDATION_MIN_OCCURS_UNMATCHED:
            errorMessage << "ERROR_VALIDATION_MIN_OCCURS_UNMATCHED ";
            break;
        case ERROR_VALIDATION_SEQUENCE_PREVIOUS_SIBLING_NOT_PRESENT:
            errorMessage << "ERROR_VALIDATION_SEQUENCE_PREVIOUS_SIBLING_NOT_PRESENT ";
            break;
        case ERROR_VALIDATION_SEQUENCE_NEXT_SIBLING_ALREADY_PRESENT:
            errorMessage << "ERROR_VALIDATION_SEQUENCE_NEXT_SIBLING_ALREADY_PRESENT ";
            break;
        case ERROR_VALIDATION_CHOICE_SIBLING_ALREADY_PRESENT:
            errorMessage << "ERROR_VALIDATION_CHOICE_SIBLING_ALREADY_PRESENT ";
            break;
        case ERROR_VALIDATION_CHOICE_NO_CHILD_PRESENT:
            errorMessage << "ERROR_VALIDATION_CHOICE_NO_CHILD_PRESENT ";
            break;
        case ERROR_VALIDATION_UNEXPECTED_ELEMENT:
            errorMessage << "ERROR_VALIDATION_UNEXPECTED_ELEMENT ";
            break;
        case ERROR_VALIDATION_UNEXPECTED_CLOSING_TAG:
            errorMessage << "ERROR_VALIDATION_UNEXPECTED_CLOSING_TAG ";
            break;
        case ERROR_VALIDATION_MIN_INCLUSIVE:
            errorMessage << "ERROR_VALIDATION_MIN_INCLUSIVE ";
            break;
        case ERROR_VALIDATION_MAX_INCLUSIVE:
            errorMessage << "ERROR_VALIDATION_MAX_INCLUSIVE ";
            break;
        case ERROR_VALIDATION_MIN_EXCLUSIVE:
            errorMessage << "ERROR_VALIDATION_MIN_EXCLUSIVE ";
            break;
        case ERROR_VALIDATION_MAX_EXCLUSIVE:
            errorMessage << "ERROR_VALIDATION_MAX_EXCLUSIVE ";
            break;
        case ERROR_VALIDATION_LENGTH:
            errorMessage << "ERROR_VALIDATION_LENGTH ";
            break;
        case ERROR_VALIDATION_MIN_LENGTH:
            errorMessage << "ERROR_VALIDATION_MIN_LENGTH ";
            break;
        case ERROR_VALIDATION_MAX_LENGTH:
            errorMessage << "ERROR_VALIDATION_MAX_LENGTH ";
            break;
        case ERROR_VALIDATION_PATTERN:
            errorMessage << "ERROR_VALIDATION_PATTERN ";
            break;
        case SIMPLE_TYPE_VALIDATION_OK:
            errorMessage << "SIMPLE_TYPE_VALIDATION_OK ";
            break;

		}
		
		if ( mElementName )
			errorMessage << "Element: " << mElementName << ", ";
		
		if ( mAttributeName )
			errorMessage << "Attribute: " << mAttributeName << ", ";

		if ( mLineNumber > 0)
		{
			errorMessage << "Line: " <<  mLineNumber << ", ";
		}
		if ( mColumnNumber > 0)
		{
			errorMessage << "Column: " <<  mColumnNumber << ", ";
		}
		errorMessage << "Additional: " << mAdditionalText;
		
		return errorMessage.str();
	}
} // namespace GeneratedSaxParser
