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

#include <libxml/parser.h>

namespace GeneratedSaxParser
{
//	typedef char xmlChar;

	typedef std::string String;
	struct  ParserAttributes
	{
		ParserAttributes(const xmlChar** _attributes): attributes(_attributes){}
		const xmlChar** attributes;
	};
	

} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_PREREQUISITES_H__
