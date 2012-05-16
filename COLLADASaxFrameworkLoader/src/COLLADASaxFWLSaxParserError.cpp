/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSaxParserError.h"

#include "GeneratedSaxParserParserError.h"


namespace COLLADASaxFWL
{

    //------------------------------
	SaxParserError::SaxParserError( const GeneratedSaxParser::ParserError& error ) 
		: mError(error)
	{
	}

    //------------------------------
	SaxParserError::~SaxParserError()
	{
	}

    //------------------------------
	IError::Severity SaxParserError::getSeverity() const
	{
		bool isCritical = mError.getSeverity()== GeneratedSaxParser::ParserError::SEVERITY_CRITICAL;
		return isCritical ? IError::SEVERITY_CRITICAL : IError::SEVERITY_ERROR_NONCRITICAL;
	}

	//------------------------------
	String SaxParserError::getFullErrorMessage() const
	{
		return  mError.getErrorMessage();
	}
} // namespace COLLADASaxFWL
