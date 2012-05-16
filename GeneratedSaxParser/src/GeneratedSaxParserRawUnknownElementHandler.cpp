/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserRawUnknownElementHandler.h"

#include <cassert>

namespace GeneratedSaxParser
{
	//--------------------------------------------------------------------
	RawUnknownElementHandler::RawUnknownElementHandler()
	{
	}
	
	//--------------------------------------------------------------------
	RawUnknownElementHandler::~RawUnknownElementHandler()
	{
	}

	//---------------------------------------------------------------
	void RawUnknownElementHandler::prepareToAddContents()
	{
		if ( !mOpenTags.empty() && !mOpenTags.top().mHasContents )
		{
			mRawData.append( ">" );
			mOpenTags.top().mHasContents = true;
		}
	}


	//--------------------------------------------------------------------
	bool RawUnknownElementHandler::elementBegin( const ParserChar* elementName, const xmlChar** attributes )
	{
		prepareToAddContents();

		mRawData.append( "<" );
		mRawData.append( elementName );
		mOpenTags.push( OpenTag() );
		/* OpenTag& currentOpenTag = mOpenTags.top(); */ /* UNUSED */

		if ( attributes )
		{
			const xmlChar** currentAttribute = attributes;
			while ( *currentAttribute )
			{
				const xmlChar* attributeName = *currentAttribute;
				currentAttribute++;
				if ( !currentAttribute )
				{
					// should never occur, but we want to make sure
					break;
				}
				const xmlChar* attributeValue = *currentAttribute;

				mRawData.append( " " );
				mRawData.append( attributeName );
				mRawData.append( "=\"" );
				mRawData.append( attributeValue );
				mRawData.append( "\"" );

				currentAttribute++;
			}
		}
		return true;
	}

	//--------------------------------------------------------------------
	bool RawUnknownElementHandler::elementEnd( const ParserChar* elementName )
	{
		assert ( !mOpenTags.empty() );

		if ( mOpenTags.top().mHasContents )
		{
	/*		if ( !mOpenTags.top().mHasText )
			{
				appendNewLine();
				addWhiteSpace ( mLevel * mIndent );
			}

			*/
			mRawData.append( "</" );

			mRawData.append( elementName );
			mRawData.append( ">" );
		}

		else
		{
			mRawData.append( "/>" );
		}
		mOpenTags.pop();
		return true;
	}

	//--------------------------------------------------------------------
	bool RawUnknownElementHandler::textData( const ParserChar* text, size_t textLength )
	{
		prepareToAddContents();

		mRawData.append( text, textLength );

		mOpenTags.top().mHasText = true;
		return true;
	}

} // namespace GeneratedSaxParser
