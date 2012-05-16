/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserParser.h"
#include "GeneratedSaxParserSaxParser.h"

//#include <libxml/parser.h>


namespace GeneratedSaxParser
{


	//--------------------------------------------------------------------
	Parser::Parser(IErrorHandler* errorHandler)
		:mSaxParser(0)
		, mErrorHandler(errorHandler)
	{
	}

	//--------------------------------------------------------------------
	Parser::~Parser()
	{
	}



	size_t Parser::stringLength( const xmlChar* string )
	{
		if ( !string )
			return 0;
		const xmlChar* pos = string;
		while ( *pos != 0)
			pos++;
		return pos - string;
	}

	size_t Parser::getLineNumber() const
	{
		return mSaxParser ? mSaxParser->getLineNumer() : 0;
	}

	size_t Parser::getColumnNumber() const
	{
		return mSaxParser ? mSaxParser->getColumnNumer() : 0;
	}

} // namespace GeneratedSaxParser
