/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLExtraDataElementHandler.h"
#include "COLLADASaxFWLIExtraDataCallbackHandler.h"


namespace COLLADASaxFWL
{

    //------------------------------
    ExtraDataElementHandler::ExtraDataElementHandler() 
        : mExtraDataCallbackHandlerList (0)
        , mCallbackHandlersCallingList (0)
	{
	}
	
    //------------------------------
	ExtraDataElementHandler::~ExtraDataElementHandler()
	{
        if ( mCallbackHandlersCallingList ) 
        {
            delete[] mCallbackHandlersCallingList;
            mCallbackHandlersCallingList = 0;
        }
	}

    //------------------------------
    void ExtraDataElementHandler::setExtraDataCallbackHandlerList ( 
        const COLLADASaxFWL::ExtraDataCallbackHandlerList& val )
    {
        mExtraDataCallbackHandlerList = val; 

        if ( mCallbackHandlersCallingList ) 
        {
            delete[] mCallbackHandlersCallingList;
            mCallbackHandlersCallingList = 0;
        }
        mCallbackHandlersCallingList = new bool [mExtraDataCallbackHandlerList.size ()];
    }

    //------------------------------
    void ExtraDataElementHandler::setExtraDataCallbackHandlerCalling ( const size_t index, const bool calling )
    {
        if ( mCallbackHandlersCallingList && index <= mExtraDataCallbackHandlerList.size () )
            mCallbackHandlersCallingList [index] = calling;
    }

    //------------------------------
    bool ExtraDataElementHandler::elementBegin( const ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes )
    {
        // Go through the list of extra data callback handlers and call the elementBegin method.
        const size_t numHandlers = mExtraDataCallbackHandlerList.size ();
        if ( numHandlers > 0 && !mCallbackHandlersCallingList ) return false;

        for ( size_t i=0; i<numHandlers; ++i )
        {
            if ( mCallbackHandlersCallingList[i] )
            {
                IExtraDataCallbackHandler* callbackHandler = mExtraDataCallbackHandlerList [i];
                callbackHandler->elementBegin ( elementName, attributes );
            }
        }
        return true;
    }

    //------------------------------
    bool ExtraDataElementHandler::elementEnd( const ParserChar* elementName )
    {
        // Go through the list of extra data callback handlers and call the elementEnd method.
        const size_t numHandlers = mExtraDataCallbackHandlerList.size ();
        if ( numHandlers > 0 && !mCallbackHandlersCallingList ) return false;

        for ( size_t i=0; i<numHandlers; ++i )
        {
            if ( mCallbackHandlersCallingList[i] )
            {
                IExtraDataCallbackHandler* callbackHandler = mExtraDataCallbackHandlerList [i];
                callbackHandler->elementEnd ( elementName );
            }
        }
        return true;
    }

    //------------------------------
    bool ExtraDataElementHandler::textData( const ParserChar* text, size_t textLength )
    {
        // Go through the list of extra data callback handlers and call the textData method.
        const size_t numHandlers = mExtraDataCallbackHandlerList.size ();
        if ( numHandlers > 0 && !mCallbackHandlersCallingList ) return false;

        for ( size_t i=0; i<numHandlers; ++i )
        {
            if ( mCallbackHandlersCallingList[i] )
            {
                IExtraDataCallbackHandler* callbackHandler = mExtraDataCallbackHandlerList [i];
                callbackHandler->textData ( text, textLength );
            }
        }
        return true;
    }

} // namespace COLLADASaxFWL
