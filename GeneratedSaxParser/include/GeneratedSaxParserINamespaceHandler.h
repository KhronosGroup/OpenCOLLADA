/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of GeneratedSaxParser.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_INAMESPACEHANDLER_H__
#define __GENERATEDSAXPARSER_INAMESPACEHANDLER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"

namespace GeneratedSaxParser
{
    /**
     * This interface allows implementors to handle XML elements 
     * present in different XML namespaces.
     * May be used in a part of a document where any element is allowed.
     * ElementNames are passed with namespace prefix.
     * ElementNameHashes are passed without namespace prefix.
     */
    class INamespaceHandler
    {
    public:
        INamespaceHandler(){}
        virtual ~INamespaceHandler(){}

        virtual bool elementBegin( const StringHash& elementNameHash, const ParserChar* elementName, const xmlChar** attributes ) = 0;
        virtual bool elementEnd( const StringHash& elementNameHash, const ParserChar* elementName ) = 0;
        virtual bool textData( const ParserChar* text, size_t textLength ) = 0;

    private:
        /** Disable default copy ctor. */
        INamespaceHandler( const INamespaceHandler& pre );
        /** Disable default assignment operator. */
        const INamespaceHandler& operator= ( const INamespaceHandler& pre );

    };

} // namespace COLLADASAXPARSER

#endif // __GENERATEDSAXPARSER_INAMESPACEHANDLER_H__
