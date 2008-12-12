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

		virtual size_t getLineNumer()const=0;
		virtual size_t getColumnNumer()const=0;

		Parser* getParser(){return mParser;}

		/** Changes the parser that receives the sax parser callbacks.*/
		void changeParser(Parser* parser);
	
	private:
        /** Disable default copy ctor. */
		SaxParser( const SaxParser& pre );
        /** Disable default assignment operator. */
		const SaxParser& operator= ( const SaxParser& pre );

	};
} // namespace COLLADAPARSER

#endif // __COLLADAPARSER_SAXPARSER_H__
