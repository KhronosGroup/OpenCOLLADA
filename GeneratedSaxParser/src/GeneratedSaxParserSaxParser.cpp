/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

    //--------------------------------------------------------------------
    void SaxParser::setParser( Parser* parser )
    {
        if ( parser )
        {
            mParser = parser;
            mParser->setSaxParser(this);
        }
    }

} // namespace COLLADAPARSER
