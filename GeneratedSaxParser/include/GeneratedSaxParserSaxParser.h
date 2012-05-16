/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAPARSER_SAXPARSER_H__
#define __COLLADAPARSER_SAXPARSER_H__

#include "GeneratedSaxParserPrerequisites.h"


namespace GeneratedSaxParser
{
	class Parser;

	class SaxParser
	{

	private:
		Parser* mParser;
	public:
		SaxParser(Parser* parser);
		virtual ~SaxParser();
		
		virtual bool parseFile(const char* fileName)=0;
		virtual bool parseBuffer(const char* uri, const char* buffer, int length)=0;

		virtual size_t getLineNumer()const=0;
		virtual size_t getColumnNumer()const=0;

		Parser* getParser(){return mParser;}
        void setParser( Parser* parser );

	private:
        /** Disable default copy ctor. */
		SaxParser( const SaxParser& pre );
        /** Disable default assignment operator. */
		const SaxParser& operator= ( const SaxParser& pre );

	};
} // namespace COLLADAPARSER

#endif // __COLLADAPARSER_SAXPARSER_H__
