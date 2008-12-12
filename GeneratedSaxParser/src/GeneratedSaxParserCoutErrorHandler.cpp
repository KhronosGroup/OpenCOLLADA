#include "GeneratedSaxParserCoutErrorHandler.h"
#include <iostream>

namespace GeneratedSaxParser
{
	//--------------------------------------------------------------------
	CoutErrorHandler::CoutErrorHandler()
		: mHasErrors(false),
		mHasCriticalError(false)
	{
	}
	
	//--------------------------------------------------------------------
	CoutErrorHandler::~CoutErrorHandler()
	{
	}

	bool CoutErrorHandler::handleError( const ParserError& error )
	{
		if ( error.getSeverity() == ParserError::SEVERITY_ERROR )
			mHasErrors = true;
		else
			mHasCriticalError = true;
		std::cout << error.getErrorMessage() << std::endl;

		return false;
	}
} // namespace GeneratedSaxParser
