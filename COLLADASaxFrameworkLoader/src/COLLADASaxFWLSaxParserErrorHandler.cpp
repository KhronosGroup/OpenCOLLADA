/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSaxParserErrorHandler.h"
#include "COLLADASaxFWLSaxParserError.h"

#include "COLLADASaxFWLIErrorHandler.h"


namespace COLLADASaxFWL
{


	SaxParserErrorHandler::SaxParserErrorHandler( COLLADASaxFWL::IErrorHandler* errorHandler )
		: mErrorHandler(errorHandler)
	{
	}

    //------------------------------
	SaxParserErrorHandler::~SaxParserErrorHandler()
	{
	}

	bool SaxParserErrorHandler::handleError( const GeneratedSaxParser::ParserError& error )
	{
		SaxParserError saxParserError(error);

		if ( mErrorHandler)
			return mErrorHandler->handleError(&saxParserError);
		else
			return false;
	}
} // namespace COLLADASaxFWL
