/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_PARSER_H__
#define __GENERATEDSAXPARSER_PARSER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"

namespace GeneratedSaxParser
{

	class SaxParser;
	class IErrorHandler;

	class Parser 	
	{
	private:
		SaxParser* mSaxParser;
		IErrorHandler* mErrorHandler;
	public:
		Parser(IErrorHandler* errorHandler);
		virtual ~Parser();

		virtual bool elementBegin(const ParserChar* elementName, const ParserAttributes& attributes )=0;

		virtual bool elementEnd(const ParserChar* elementName )=0;

		virtual bool textData(const ParserChar* text, size_t textLength)=0;

		IErrorHandler* getErrorHandler() { return mErrorHandler; }

	protected:
		size_t getLineNumber()const;
		size_t getColumnNumber()const;
        SaxParser* getSaxParser() {return mSaxParser;}

	private:
        /** Disable default copy ctor. */
		Parser( const Parser& pre );
        /** Disable default assignment operator. */
		const Parser& operator= ( const Parser& pre );


		static size_t stringLength(const xmlChar* string);

		friend class SaxParser;
		void setSaxParser(SaxParser* saxParser) { mSaxParser = saxParser; }

	};
} // namespace GeneratedSaxParser

#endif // __GENERATEDSAXPARSER_PARSER_H__
