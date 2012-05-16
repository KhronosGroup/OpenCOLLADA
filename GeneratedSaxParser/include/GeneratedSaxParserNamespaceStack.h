/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_NAMESPACESTACK_H__
#define __GENERATEDSAXPARSER_NAMESPACESTACK_H__


#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"

#include <stack>
#include <map>


namespace GeneratedSaxParser
{
    extern const char* XML_ATTRIBUTE_XMLNS;
    const StringHash XML_ATTRIBUTE_XMLNS_HASH = 8340307;

    typedef std::map< StringHash, StringHash > NamespacePrefixesMap;

    /**
     * Contains currently declared XML namespaces.
     */
    struct NamespaceStackFrame
    {
        /** Default c-tor. */
        NamespaceStackFrame() : counter(0) {}

        /** Contains namespace prefix hash (key) and hash of namespace itself (value). */
        NamespacePrefixesMap namespaces;
        /** Counts how many elements have been opened since last namespace declarations. */
        size_t counter;
    };

    typedef std::stack< NamespaceStackFrame > NamespacesStack;
}

#endif // __GENERATEDSAXPARSER_NAMESPACESTACK_H__
