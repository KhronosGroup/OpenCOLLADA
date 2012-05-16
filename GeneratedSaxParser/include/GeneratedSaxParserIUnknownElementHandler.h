/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of GeneratedSaxParser.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_IUNKNOWNELEMENTHANDLER_H__
#define __GENERATEDSAXPARSER_IUNKNOWNELEMENTHANDLER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"

namespace GeneratedSaxParser
{
    /**
     * This interface allows implementers to handle XML elements not present in XSD.
     */
    class IUnknownElementHandler 	
    {
    public:
        IUnknownElementHandler(){}
        virtual ~IUnknownElementHandler(){}

        virtual bool elementBegin( const ParserChar* elementName, const xmlChar** attributes) = 0;
        virtual bool elementEnd(const ParserChar* elementName) = 0;
        virtual bool textData(const ParserChar* text, size_t textLength) = 0;

	private:
		/** Disable default copy ctor. */
		IUnknownElementHandler( const IUnknownElementHandler& pre );
		/** Disable default assignment operator. */
		const IUnknownElementHandler& operator= ( const IUnknownElementHandler& pre );

};

} // namespace COLLADASAXPARSER

#endif // __GENERATEDSAXPARSER_IUNKNOWNELEMENTHANDLER_H__
