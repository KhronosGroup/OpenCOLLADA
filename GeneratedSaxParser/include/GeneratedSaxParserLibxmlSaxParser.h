#ifndef __GENERATEDSAXPARSER_LIBXMLSAXPARSER_H__
#define __GENERATEDSAXPARSER_LIBXMLSAXPARSER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserSaxParser.h"
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

		size_t getLineNumer()const;
		size_t getColumnNumer()const;

	private:
        /** Disable default copy ctor. */
		LibxmlSaxParser( const LibxmlSaxParser& pre );
        /** Disable default assignment operator. */
		const LibxmlSaxParser& operator= ( const LibxmlSaxParser& pre );

		static void startElement( void* user_data,	const xmlChar* name, const xmlChar** attrs);
		static void endElement( void* user_data, const xmlChar* name);

		static void characters( void* user_data, const xmlChar* name, int length );

		void initializeParserContext();

		void abortParsing();

	};
} // namespace COLLADASAXPARSER

#endif // __GENERATEDSAXPARSER_LIBXMLSAXPARSER_H__
