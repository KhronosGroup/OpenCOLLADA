/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_EXTRADATAELEMENTHANDLER_H__
#define __COLLADASAXFWL_EXTRADATAELEMENTHANDLER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "GeneratedSaxParserIUnknownElementHandler.h"


namespace COLLADASaxFWL
{

    /** The element handler for the extra data preservation. */
    class ExtraDataElementHandler : public GeneratedSaxParser::IUnknownElementHandler 
    {
	private:
	
        /** List of registered extra data callback handlers. */
        ExtraDataCallbackHandlerList mExtraDataCallbackHandlerList;

        /** Array of bool elements to store the info, if the parsing methods 
        of the callback handlers has to be called. */
        bool* mCallbackHandlersCallingList;

	public:

        /** Constructor. */
		ExtraDataElementHandler();

        /** Destructor. */
		virtual ~ExtraDataElementHandler();

        /** List of registered extra data callback handlers. */
        void setExtraDataCallbackHandlerList ( const COLLADASaxFWL::ExtraDataCallbackHandlerList& val );

        /** List of registered extra data callback handlers. */
        const ExtraDataCallbackHandlerList& getExtraDataCallbackHandlerList () const { return mExtraDataCallbackHandlerList; }

        /** Set the flag, if the callback handler on the given index position should be called. */
        void setExtraDataCallbackHandlerCalling ( const size_t index, const bool calling );

        /** Implementation of IUnknownElementHandler. */
        virtual bool elementBegin( const ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes);
        virtual bool elementEnd(const ParserChar* elementName);
        virtual bool textData(const ParserChar* text, size_t textLength);

	private:

        /** Disable default copy ctor. */
		ExtraDataElementHandler( const ExtraDataElementHandler& pre );

        /** Disable default assignment operator. */
		const ExtraDataElementHandler& operator= ( const ExtraDataElementHandler& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_EXTRADATAELEMENTHANDLER_H__
