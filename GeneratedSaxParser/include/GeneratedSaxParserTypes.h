/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
     * Represents a string somewhere in a XML buffer.
     */
    struct ParserString
    {
        /** Default c-tor, */
        ParserString() : str(0), length(0) {}

        /** 
         * Convenience C-tor allowing usage of this class in 
         * GeneratedSaxParserParserTemplate::characterData2Data. 
         */
        ParserString(const int& val) : str(0), length(0) {}

        /** Pointer to the start of the string. It is not null terminated. */
        const ParserChar* str;

        /** Length of the string. */
        size_t length;
    };



} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_TYPES_H__
