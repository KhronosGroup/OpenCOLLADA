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
