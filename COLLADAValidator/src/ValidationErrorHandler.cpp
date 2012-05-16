#include "ValidationErrorHandler.h"
#include <iostream>

#include "COLLADASaxFWLIError.h"
#include "COLLADASaxFWLSaxParserError.h"
#include "COLLADASaxFWLSaxFWLError.h"

#include "GeneratedSaxParserParserError.h"

#include <string.h>

//--------------------------------------------------------------------
ValidationErrorHandler::ValidationErrorHandler()
	: mHasHandledSaxParserError(false)
	, mHasHandledSaxFWLError(false)
	, mFileNotFound(false)
{
}

//--------------------------------------------------------------------
ValidationErrorHandler::~ValidationErrorHandler()
{
}

//--------------------------------------------------------------------
bool ValidationErrorHandler::handleError( const COLLADASaxFWL::IError* error )
{
	if ( error->getErrorClass() == COLLADASaxFWL::IError::ERROR_SAXPARSER )
	{
		COLLADASaxFWL::SaxParserError* saxParserError = (COLLADASaxFWL::SaxParserError*) error;
		const GeneratedSaxParser::ParserError& parserError = saxParserError->getError();

		// Workaround to avoid wrong error
		if ( parserError.getErrorType() == GeneratedSaxParser::ParserError::ERROR_VALIDATION_MIN_OCCURS_UNMATCHED)
		{
			if ( strcmp(parserError.getElement(), "effect") == 0 )
			{
				return false;
			}
		}
		if ( parserError.getErrorType() == GeneratedSaxParser::ParserError::ERROR_VALIDATION_SEQUENCE_PREVIOUS_SIBLING_NOT_PRESENT)
		{
			if ( (strcmp(parserError.getElement(), "extra") == 0) 
				&& (strcmp(parserError.getAdditionalText().c_str(), "sibling: fx_profile_abstract") == 0)) 
			{

				return false;
			}
		}

		if ( parserError.getErrorType() == GeneratedSaxParser::ParserError::ERROR_COULD_NOT_OPEN_FILE)
		{
			mFileNotFound = true;
		}

		std::cout << "Schema validation error: " << parserError.getErrorMessage() << std::endl;
		mHasHandledSaxParserError = true;
	}
	else if ( error->getErrorClass() == COLLADASaxFWL::IError::ERROR_SAXFWL )
	{
		COLLADASaxFWL::SaxFWLError* saxFWLError = (COLLADASaxFWL::SaxFWLError*) error;
		std::cout << "Sax FWL Error: " << saxFWLError->getErrorMessage() << std::endl;
		mHasHandledSaxFWLError = true;
	}
	return false;
}
