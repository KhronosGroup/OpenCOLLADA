/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSaxFWLError.h"


namespace COLLADASaxFWL
{

    //------------------------------
	SaxFWLError::SaxFWLError( ErrorType errorType, String errorMessage, IError::Severity severity )
		: mErrorType(errorType)
		, mSeverity(severity)
		, mErrorMessage(errorMessage)
		, mLineNumber(0)
		, mColumnNumber(0)
	{
	}

    //------------------------------
	SaxFWLError::~SaxFWLError()
	{
	}

    //------------------------------
	String SaxFWLError::getFullErrorMessage() const
	{
		std::stringstream errorMessage;
		if ( mSeverity == IError::SEVERITY_CRITICAL )
			errorMessage << "Critical error: ";
		else
			errorMessage << "Error: ";


		switch ( mErrorType )
		{
		case ERROR_UNRESOLVED_REFERENCE:
        case ERROR_DATA_NOT_VALID:
			errorMessage << "ERROR_UNRESOLVED_REFERENCE";
			break;
		default:
			assert(false);
		}

		errorMessage << ": ";

		if ( mLineNumber > 0)
			errorMessage << " Line: " << mLineNumber;

		if ( mColumnNumber > 0)
			errorMessage << " Column: " << mColumnNumber;

		errorMessage << mErrorMessage ;

		return errorMessage.str();
	}

} // namespace COLLADASaxFWL
