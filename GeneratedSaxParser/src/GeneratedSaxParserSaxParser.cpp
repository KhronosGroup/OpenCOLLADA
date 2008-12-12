/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserSaxParser.h"
#include "GeneratedSaxParserParser.h"

namespace GeneratedSaxParser
{

	SaxParser::SaxParser( Parser* parser )
		: mParser(parser)
	{
		if ( parser )
			mParser->setSaxParser(this);
	}

	//--------------------------------------------------------------------
	SaxParser::~SaxParser()
	{
	}

	void SaxParser::changeParser( Parser* parser )
	{
		mParser = parser;
		if ( parser )
			mParser->setSaxParser(this);
	}
} // namespace COLLADAPARSER
