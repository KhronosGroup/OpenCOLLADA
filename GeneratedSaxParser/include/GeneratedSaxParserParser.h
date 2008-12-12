#ifndef __GENERATEDSAXPARSER_PARSER_H__
#define __GENERATEDSAXPARSER_PARSER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"

namespace GeneratedSaxParser
{

	class SaxParser;

	class Parser 	
	{
	private:
		SaxParser* mSaxParser;
	public:
		Parser();
		virtual ~Parser();

		virtual bool elementBegin(const ParserChar* elementName, const ParserAttributes& attributes )=0;

		virtual bool elementEnd(const ParserChar* elementName )=0;

		virtual bool textData(const ParserChar* text, size_t textLength)=0;

	protected:
		size_t getLineNumber()const;
		size_t getColumnNumber()const;

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
