/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_PREREQUISITES_H__
#define __GENERATEDSAXPARSER_PREREQUISITES_H__

#define LIBXML_STATIC

#include <string>

#include "COLLADABUPlatform.h"

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

#if defined COLLADABU_OS_WIN
    // VisualStudio 2005 uses same sizes for 32 and 64 bit
    typedef signed char sint8;
    typedef signed short sint16;
    typedef signed int sint32;
    typedef signed long long sint64;

    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;

#elif defined COLLADABU_OS_LINUX
    typedef signed char sint8;
    typedef signed short sint16;
    typedef signed int sint32;
    typedef signed long long sint64;

    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;

#elif defined COLLADABU_OS_MAC
    // XCode uses same sizes for 32 and 64 bit
    typedef signed char sint8;
    typedef signed short sint16;
    typedef signed int sint32;
    typedef signed long long sint64;

    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;

#else
    // TODO 64 bit, compiler specific differences, e.g. mingw or intel compiler
#error "Specify primitive type sizes for your platform, please."
#endif

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_PREREQUISITES_H__
