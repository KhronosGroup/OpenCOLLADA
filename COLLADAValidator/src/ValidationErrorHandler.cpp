#include "ValidationErrorHandler.h"
#include <iostream>

#include "COLLADASaxFWLIError.h"
#include "COLLADASaxFWLSaxParserError.h"

#include "GeneratedSaxParserParserError.h"

//--------------------------------------------------------------------
ValidationErrorHandler::ValidationErrorHandler()
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
		if ( parserError.getErrorType() == GeneratedSaxParser::ParserError::ERROR_VALIDATION_MIN_OCCURS_UNMATCHED )
		{
			if ( strcmp(parserError.getElement(), "effect") == 0 )
			{
				return true;
			}
		}

		std::cout << parserError.getErrorMessage() << std::endl;
	}
	return true;
}
