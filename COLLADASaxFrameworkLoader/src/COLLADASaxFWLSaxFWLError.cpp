/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSaxFWLError.h"


#define ERRORTYPE2STRING(typename) case typename: errorMessage << #typename; break;

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
			ERRORTYPE2STRING(ERROR_UNRESOLVED_REFERENCE);
			ERRORTYPE2STRING(ERROR_UNRESOLVED_FORMULA);
			ERRORTYPE2STRING(ERROR_UNRESOLVED_PARAMETER);
			ERRORTYPE2STRING(ERROR_PARAMETER_COUNT_DOESNOT_MATCH);
			ERRORTYPE2STRING(ERROR_DATA_NOT_VALID);
		default:
			COLLADABU_ASSERT(false);
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
