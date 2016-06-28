/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_TYPES_H__
#define __GENERATEDSAXPARSER_TYPES_H__


#include "GeneratedSaxParserPrerequisites.h"


namespace GeneratedSaxParser
{

	typedef char ParserChar;

	typedef unsigned long StringHash;


    /**
     * Special string for unions. They cannot have c-tors.
     */
    struct UnionString
    {
        /** Pointer to the start of the string. It is not null terminated. */
        const ParserChar* str;

        /** Length of the string. */
        size_t length;
    };

    /**
     * Represents a string somewhere in a XML buffer.
     */
    struct ParserString : public UnionString
    {
        /** Default c-tor, */
        ParserString()
        {
            UnionString::str = 0;
            UnionString::length = 0;
        }

        /** 
         * Convenience C-tor allowing usage of this class in 
         * GeneratedSaxParserParserTemplate::characterData2Data. 
         */
        ParserString(const int& val)
        {
			UnionString::str = 0;
			UnionString::length = 0;
        }
    };


} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_TYPES_H__
