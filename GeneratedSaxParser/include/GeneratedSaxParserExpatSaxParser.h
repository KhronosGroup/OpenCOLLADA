/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __GENERATEDSAXPARSER_EXPATSAXPARSER_H__
#define __GENERATEDSAXPARSER_EXPATSAXPARSER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserSaxParser.h"



struct XML_ParserStruct;
typedef struct XML_ParserStruct *XML_Parser;


namespace GeneratedSaxParser 
{
	class Parser;

	class ExpatSaxParser : public SaxParser
	{

	private:
		typedef char XML_Char;
	private:
		XML_Parser mParser;
		size_t mBufferSize;

	public:
		ExpatSaxParser(Parser* parser, size_t bufferSize);
		virtual ~ExpatSaxParser();

		bool parseFile(const char* fileName);
		virtual bool parseBuffer(const char* uri, const char* buffer, int length);

		size_t getLineNumer()const;
		size_t getColumnNumer()const;

	private:
		/** Disable default copy ctor. */
		ExpatSaxParser( const SaxParser& pre );
		/** Disable default assignment operator. */
		const ExpatSaxParser& operator= ( const SaxParser& pre );

		static void startElement( void* user_data,	const XML_Char* name, const XML_Char** attrs);
		static void endElement( void* user_data, const XML_Char* name);

		static void characters( void* user_data, const XML_Char* name, int length );


		void abortParsing();

	};
} // namespace GENERATEDSAXPARSER

#endif // __GENERATEDSAXPARSER_EXPATSAXPARSER_H__
