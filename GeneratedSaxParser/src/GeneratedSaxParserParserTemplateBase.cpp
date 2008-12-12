/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of GeneratedSaxParser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "GeneratedSaxParserParserTemplateBase.h"
#include "GeneratedSaxParserIErrorHandler.h"

namespace GeneratedSaxParser
{


	//--------------------------------------------------------------------
	float ParserTemplateBase::toFloatPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<float, Utils::toFloat>(prefixedBuffer, buffer, bufferEnd, failed);
	}


	//--------------------------------------------------------------------
	char ParserTemplateBase::toCharPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<char, Utils::toChar>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned char ParserTemplateBase::toUnsignedCharPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<unsigned char, Utils::toUnsignedChar>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	short ParserTemplateBase::toShortPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<short, Utils::toShort>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned short ParserTemplateBase::toUnsignedShortPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<unsigned short, Utils::toUnsignedShort>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	int ParserTemplateBase::toIntPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<int, Utils::toInt>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned int ParserTemplateBase::toUnsignedIntPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<unsigned int, Utils::toUnsignedInt>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	long ParserTemplateBase::toLongPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<long, Utils::toLong>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned long ParserTemplateBase::toUnsignedLongPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<unsigned long, Utils::toUnsignedLong>(prefixedBuffer, buffer, bufferEnd, failed);
	}


	//--------------------------------------------------------------------
	long long ParserTemplateBase::toLongLongPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<long long, Utils::toLongLong>(prefixedBuffer, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	unsigned long long ParserTemplateBase::toUnsignedLongLongPrefix( const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<unsigned long long, Utils::toUnsignedLongLong>(prefixedBuffer, buffer, bufferEnd, failed);
	}


	//--------------------------------------------------------------------
	template<class DataType,
			 DataType (*toData)(const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)>
	DataType ParserTemplateBase::toDataPrefix(const ParserChar* prefixedBuffer, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
	{
		const ParserChar* prefixBufferPos = prefixedBuffer;
		const ParserChar* prefixBufferStartPos = 0;
		bool onlyWhiteSpaceFound = true;
		while ( *prefixBufferPos )
		{
			if (!Utils::isWhiteSpace(*prefixBufferPos ) && !prefixBufferStartPos)
				prefixBufferStartPos = prefixBufferPos;
			++prefixBufferPos;
		}

		//if prefixedBuffer contains only white spaces, we can ignore it.
		if ( !prefixBufferStartPos )
			return toData(buffer, bufferEnd, failed);

		//find first whitespace in buffer 
		const ParserChar* bufferPos = *buffer;
		while ( !Utils::isWhiteSpace(*bufferPos) )
			++bufferPos;

		size_t prefixBufferSize = prefixBufferPos - prefixBufferStartPos;
		size_t bufferSize = bufferPos - *buffer;
		size_t newBufferSize = prefixBufferSize + bufferSize;
		ParserChar* newBuffer =  (ParserChar*)mStackMemoryManager.newObject((newBufferSize + 1)*sizeof(ParserChar));
		memcpy(newBuffer, prefixBufferStartPos, prefixBufferSize*sizeof(ParserChar));
		memcpy(newBuffer + prefixBufferSize, *buffer, bufferSize*sizeof(ParserChar));
		newBuffer[newBufferSize] = ' ';
		ParserChar* newBufferPostParse = newBuffer;
		DataType value = toData( (const ParserChar**)&newBufferPostParse, newBuffer + newBufferSize + 1, failed);
		*buffer += (newBufferPostParse - newBuffer - prefixBufferSize);
		mStackMemoryManager.deleteObject();
		return value;
	}

	//--------------------------------------------------------------------
	bool ParserTemplateBase::handleError( ParserError::Severity severity, 
												 ParserError::ErrorType errorType, 
												 StringHash elementHash, 
												 StringHash attributeHash, 
												 const ParserChar* additionalText /*= ""*/ )
	{
		if ( !mErrorHandler )
			return (severity == ParserError::SEVERITY_CRITICAL) ? true : false;
		
		bool handlerWantsToAbort = mErrorHandler->handleError(ParserError(severity, 
																		  errorType, 
																		  getNameByStringHash(elementHash), 
																		  getNameByStringHash(attributeHash), 
																		  getLineNumber(),
																		  getColumnNumber(),
																		  additionalText ? (const char*)additionalText : ""));

		return (severity == ParserError::SEVERITY_CRITICAL) ? true : handlerWantsToAbort;
	}

	//--------------------------------------------------------------------
	bool ParserTemplateBase::handleError( ParserError::Severity severity, 
												 ParserError::ErrorType errorType, 
												 StringHash attributeHash, 
												 const ParserChar* additionalText )
	{
		StringHash elementHash = mElementDataStack.empty() ? 0 : mElementDataStack.top().elementHash; 

		return handleError(severity, 
			errorType, 
			elementHash, 
			attributeHash, 
			additionalText);
	}

	//--------------------------------------------------------------------
	const char* ParserTemplateBase::getNameByStringHash( const StringHash& hash ) const
	{
		if ( hash == 0 )
			return 0;
		ElementNameMap::const_iterator it = mHashNameMap.find(hash);
		if ( it == mHashNameMap.end() )
			return 0;
		else 
			return it->second;
	}

} // namespace GeneratedSaxParser
