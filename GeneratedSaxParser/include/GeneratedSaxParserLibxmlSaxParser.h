/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_LIBXMLSAXPARSER_H__
#define __GENERATEDSAXPARSER_LIBXMLSAXPARSER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserSaxParser.h"
#include "GeneratedSaxParserIErrorHandler.h"
#include <libxml/parser.h>


namespace GeneratedSaxParser
{

	class Parser;

	class LibxmlSaxParser  : public SaxParser
	{
	private:
		static xmlSAXHandler SAXHANDLER;

		xmlParserCtxtPtr mParserContext;

	public:
		LibxmlSaxParser(Parser* parser);
		virtual ~LibxmlSaxParser();

		bool parseFile(const char* fileName);
		bool parseBuffer(const char* uri, const char* buffer, int length);

		size_t getLineNumer()const;
		size_t getColumnNumer()const;

	private:
        /** Disable default copy ctor. */
		LibxmlSaxParser( const LibxmlSaxParser& pre );
        /** Disable default assignment operator. */
		const LibxmlSaxParser& operator= ( const LibxmlSaxParser& pre );

		static void startElement( void* user_data,	const ::xmlChar* name, const ::xmlChar** attrs);
		static void endElement( void* user_data, const ::xmlChar* name);

		static void characters( void* user_data, const ::xmlChar* name, int length );

		static void errorFunction (void *ctx,	const char *msg, ...);

		void initializeParserContext();

		void abortParsing();

	};
} // namespace COLLADASAXPARSER

#endif // __GENERATEDSAXPARSER_LIBXMLSAXPARSER_H__
