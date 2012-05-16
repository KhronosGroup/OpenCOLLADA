/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxFWLErrorHandler.h"
#include "COLLADASaxFWLSaxParserError.h"
#include "COLLADASaxFWLSaxFWLError.h"

#include "GeneratedSaxParserParserError.h"


namespace COLLADAMax
{

    //------------------------------
	FWLErrorHandler::FWLErrorHandler()
	{
	}
	
    //------------------------------
	FWLErrorHandler::~FWLErrorHandler()
	{
	}

	bool FWLErrorHandler::handleError( const COLLADASaxFWL::IError* error )
	{
		std::string msg;
		switch ( error->getErrorClass())
		{
		case COLLADASaxFWL::IError::ERROR_SAXPARSER:
			msg = ((COLLADASaxFWL::SaxParserError*)error)->getError().getErrorMessage();
			break;
		case COLLADASaxFWL::IError::ERROR_SAXFWL:
			msg = ((COLLADASaxFWL::SaxFWLError*)error)->getFullErrorMessage();
			break;
		}
		msg;
		return false;
	}
} // namespace COLLADAMax
