/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

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
		if ( error.getSeverity() == ParserError::SEVERITY_ERROR_NONCRITICAL )
			mHasErrors = true;
		else
			mHasCriticalError = true;
		std::cerr << error.getErrorMessage() << std::endl;

		return false;
	}
} // namespace GeneratedSaxParser
