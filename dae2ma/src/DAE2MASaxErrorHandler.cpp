/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MASaxErrorHandler.h"

#include "GeneratedSaxParserParserError.h"

#include "COLLADASaxFWLSaxFWLError.h"


namespace DAE2MA
{

    //------------------------------
    SaxErrorHandler::SaxErrorHandler() 
        : COLLADASaxFWL::IErrorHandler ()
	{
	}
	
    //------------------------------
	SaxErrorHandler::~SaxErrorHandler()
	{
	}

    //------------------------------
    bool SaxErrorHandler::handleError ( const COLLADASaxFWL::IError* error )
    {
        COLLADASaxFWL::IError::ErrorClass errorClass = error->getErrorClass ();
        switch ( errorClass )
        {
        case COLLADASaxFWL::IError::ERROR_SAXPARSER:
            {
                COLLADASaxFWL::SaxParserError* parserError = ( COLLADASaxFWL::SaxParserError* ) error;
                //std::cerr << "Error: " << parserError->getError ().getErrorMessage () << std::endl;
            }
            break;
        case COLLADASaxFWL::IError::ERROR_SAXFWL:
            {
                COLLADASaxFWL::SaxFWLError* fwlError = ( COLLADASaxFWL::SaxFWLError* ) error;
                String message = fwlError->getFullErrorMessage ();
                std::cerr << "Error: " << fwlError->getFullErrorMessage () << std::endl;
            }
            break;
        default:
            {
                std::cerr << "Unknown Error!" << std::endl;
                break;
            }
        }

        // Don't break parsing!
        return false;
    }

} // namespace DAE2MA
