/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserExpatSaxParser.h"


#define XML_STATIC  // to link against static version of expat
#include "expat.h"
#undef XML_STATIC  
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "GeneratedSaxParserParser.h"


namespace GeneratedSaxParser
{
	


	//--------------------------------------------------------------------
	ExpatSaxParser::ExpatSaxParser(Parser* parser, size_t bufferSize)
		: SaxParser(parser)
		, mParser(0)
		, mBufferSize(bufferSize)
	{
	}

	//--------------------------------------------------------------------
	ExpatSaxParser::~ExpatSaxParser()
	{
	}

	//--------------------------------------------------------------------
	bool ExpatSaxParser::parseBuffer(const char* uri, const char* buffer, int length)
	{
		
		mParser = XML_ParserCreate(0);

		XML_SetUserData(mParser, this);
		XML_SetElementHandler(mParser, startElement, endElement);
		XML_SetCharacterDataHandler(mParser, characters);


		XML_Status status = XML_STATUS_OK;
		bool isFinal = true;
		XML_Parse(mParser, buffer, (int)length, isFinal);

		XML_ParserFree(mParser);

		return status != XML_STATUS_ERROR;
	}
	bool ExpatSaxParser::parseFile( const char* fileName )
	{
		FILE *fd;
		fd = fopen(fileName, "rb");
		if (!fd)
			return false;

		//XML_ParserCreate(const XML_Char *encoding);
		mParser = XML_ParserCreate(0);

		XML_SetUserData(mParser, this);
		XML_SetElementHandler(mParser, startElement, endElement);
		XML_SetCharacterDataHandler(mParser, characters);


		char * buffer;
		buffer = (char*) malloc (sizeof(char)*mBufferSize);


		XML_Status status = XML_STATUS_OK;
		while (!feof(fd) && (status != XML_STATUS_ERROR) )
		{
			size_t length = fread(buffer, 1,  mBufferSize, fd);
			status = XML_Parse(mParser, buffer, (int)length, feof(fd));
		}

		fclose (fd);
		free (buffer);
		XML_ParserFree(mParser);

		return status != XML_STATUS_ERROR;
	}

	//--------------------------------------------------------------------
	void ExpatSaxParser::startElement( void* user_data, const XML_Char* name, const XML_Char** attrs )
	{
		ExpatSaxParser* thisObject = (ExpatSaxParser*)user_data;
		Parser* parser = thisObject->getParser();
		if ( !parser->elementBegin((const ParserChar*)name, (const ParserChar**)attrs) )
			thisObject->abortParsing();

	}

	//--------------------------------------------------------------------
	void ExpatSaxParser::endElement( void* user_data, const XML_Char* name)
	{
		ExpatSaxParser* thisObject = (ExpatSaxParser*)user_data;
		Parser* parser = thisObject->getParser();
		if ( !parser->elementEnd((const ParserChar*)name) )
			thisObject->abortParsing();
	}


	//--------------------------------------------------------------------
	void ExpatSaxParser::characters( void* user_data, const XML_Char* name, int length )
	{
		ExpatSaxParser* thisObject = (ExpatSaxParser*)user_data;
		Parser* parser = thisObject->getParser();
		if ( !parser->textData((const ParserChar*)name, (size_t)length) )
			thisObject->abortParsing();
	}

	//--------------------------------------------------------------------
	size_t ExpatSaxParser::getLineNumer() const
	{
		return (size_t) XML_GetCurrentLineNumber(mParser);

	}

	//--------------------------------------------------------------------
	size_t ExpatSaxParser::getColumnNumer() const
	{
		return (size_t) XML_GetCurrentColumnNumber(mParser);
	}

	//--------------------------------------------------------------------
	void ExpatSaxParser::abortParsing()
	{
		XML_StopParser(mParser, false);
	}

} // namespace GeneratedSaxParser
