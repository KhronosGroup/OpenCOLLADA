/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSaxParserErrorHandler.h"

#include "GeneratedSaxParserParserError.h"


namespace COLLADAMaya
{

    //------------------------------
    SaxParserErrorHandler::SaxParserErrorHandler() 
        : COLLADASaxFWL::IErrorHandler ()
	{
	}
	
    //------------------------------
	SaxParserErrorHandler::~SaxParserErrorHandler()
	{
	}

    //------------------------------
    bool SaxParserErrorHandler::handleError ( const COLLADASaxFWL::IError* error )
    {
        COLLADASaxFWL::IError::ErrorType errorType = error->getErrorType ();
        switch ( errorType )
        {
        case COLLADASaxFWL::IError::ERROR_SAXPARSER:
            {
                COLLADASaxFWL::SaxParserError* parserError = ( COLLADASaxFWL::SaxParserError* ) error;
                //MGlobal::displayError ( "Error: " + MString ( parserError->getError ().getErrorMessage ().c_str () ) );
                MGlobal::doErrorLogEntry ( "Error: " + MString ( parserError->getError ().getErrorMessage ().c_str () ) );
                //std::cerr << "Error: " << parserError->getError ().getErrorMessage () << endl;
                break;
            }
        default:
            {
                MGlobal::displayError ( "Unknown Error!" );
                break;
            }
        }

        // Don't break parsing!
        return false;
    }

} // namespace COLLADAMaya
