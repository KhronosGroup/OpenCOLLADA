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
