/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_PREREQUISITES_H__
#define __GENERATEDSAXPARSER_PREREQUISITES_H__

#include <string>


namespace GeneratedSaxParser
{
	typedef char xmlChar;

    /** Make std::string conformant with camelcase coding style. */
	typedef std::string String;

    /**
     * Wraps libxml character pointers.
     */
    struct  ParserAttributes
	{
		ParserAttributes(const xmlChar** _attributes): attributes(_attributes){}
		const xmlChar** attributes;
	};

    /**
     * Represents a xs:list when used as attribute.
     * @tparam T C++ Type of xs:list items.
     */
    template<typename T>
    struct XSList
    {
        /** Default ctor. */
        XSList() : data(0), size(0){}

        /** Points to buffer containing list items. */
        T* data;

        /** List length. */
        size_t size;
    };

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_PREREQUISITES_H__
