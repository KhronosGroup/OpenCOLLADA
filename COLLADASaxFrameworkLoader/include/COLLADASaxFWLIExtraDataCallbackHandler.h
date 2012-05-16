/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_IEXTRADATACALLBACKHANDLER_H__
#define __COLLADASAXFWL_IEXTRADATACALLBACKHANDLER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLXmlTypes.h"


namespace COLLADASaxFWL
{

    /** The callback handler to handle the reading of extra data. */
	class IExtraDataCallbackHandler 	
    {
	
	public:

        /** Constructor. */
		IExtraDataCallbackHandler ();

        /** Destructor. */
		virtual ~IExtraDataCallbackHandler ();

        /** The methods to get the extra data tags to the registered callback handlers. */
        virtual bool elementBegin( const ParserChar* elementName, const GeneratedSaxParser::xmlChar** attributes) = 0;
        virtual bool elementEnd(const ParserChar* elementName ) = 0;
        virtual bool textData(const ParserChar* text, size_t textLength) = 0;

        /** Method to ask, if the current callback handler want to read the data of the given extra element. */
        virtual bool parseElement ( 
            const ParserChar* profileName, 
            const StringHash& elementHash, 
            const COLLADAFW::UniqueId& uniqueId ) = 0;

	private:

        /** Disable default copy constructor. */
		IExtraDataCallbackHandler( const IExtraDataCallbackHandler& pre );

        /** Disable default assignment operator. */
		const IExtraDataCallbackHandler& operator= ( const IExtraDataCallbackHandler& pre );

	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_IEXTRADATACALLBACKHANDLER_H__
