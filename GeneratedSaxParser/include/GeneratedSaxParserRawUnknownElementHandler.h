/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __GENERATEDSAXPARSER_RAWUNKNOWNELEMENTHANDLER_H__
#define __GENERATEDSAXPARSER_RAWUNKNOWNELEMENTHANDLER_H__

#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserIUnknownElementHandler.h"

#include <stack>

namespace GeneratedSaxParser
{
	/** This is an implementation of the IUnknownElementHandler, that stores the part of the xml file,
	that is reported through the IUnknownElementHandler in a string.*/
	class RawUnknownElementHandler : public IUnknownElementHandler 
	{
	private:
		struct OpenTag
		{
			OpenTag ( ) :  mHasContents ( false ), mHasText ( false ) {}

			bool mHasContents;    //!< true, if contents, i.e. elements or text has been added to the element
			bool mHasText;     //!< true, if text has been added to the element
		};


		typedef std::stack<OpenTag> OpenTagsStack;  //!< A stack that holds all the open tags.


	private:
		String mRawData;

		OpenTagsStack mOpenTags;  //!< A stack that holds all the open tags.

	public:
		RawUnknownElementHandler();
		virtual ~RawUnknownElementHandler();

	public:
		
		// Implementation of IUnknownElementHandler
		virtual bool elementBegin( const ParserChar* elementName, const xmlChar** attributes);
		virtual bool elementEnd(const ParserChar* elementName);
		virtual bool textData(const ParserChar* text, size_t textLength);

		/** Clears the string containing the raw data.*/
		void clearRawData() {mRawData.clear();}

		/** Returns the raw data.*/
		const String& getRawData() { return mRawData; }


	private:
		/** Disable default copy ctor. */
		RawUnknownElementHandler( const RawUnknownElementHandler& pre );
		/** Disable default assignment operator. */
		const RawUnknownElementHandler& operator= ( const RawUnknownElementHandler& pre );
	
		void prepareToAddContents();
	};
} // namespace GENERATEDSAXPARSER

#endif // __GENERATEDSAXPARSER_RAWUNKNOWNELEMENTHANDLER_H__
