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
	float ParserTemplateBase::toFloatPrefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<float, Utils::toFloat>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}


	//--------------------------------------------------------------------
	double ParserTemplateBase::toDoublePrefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<double, Utils::toDouble>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}



	//--------------------------------------------------------------------
	sint8 ParserTemplateBase::toSint8Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<sint8, Utils::toSint8>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	uint8 ParserTemplateBase::toUint8Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<uint8, Utils::toUint8>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	sint16 ParserTemplateBase::toSint16Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<sint16, Utils::toSint16>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	uint16 ParserTemplateBase::toUint16Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<uint16, Utils::toUint16>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	sint32 ParserTemplateBase::toSint32Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<sint32, Utils::toSint32>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	uint32 ParserTemplateBase::toUint32Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<uint32, Utils::toUint32>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	sint64 ParserTemplateBase::toSint64Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<sint64, Utils::toSint64>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	uint64 ParserTemplateBase::toUint64Prefix( const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
	{
		return toDataPrefix<uint64, Utils::toUint64>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

	//--------------------------------------------------------------------
	bool ParserTemplateBase::toBoolPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
	{
		return toDataPrefix<bool, Utils::toBool>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
	}

    //--------------------------------------------------------------------
    ParserString ParserTemplateBase::toStringListPrefix(const ParserChar* prefixedBuffer, const ParserChar* prefixedBufferEnd, const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed)
    {
        return toDataPrefix<ParserString, Utils::toStringListItem>(prefixedBuffer, prefixedBufferEnd, buffer, bufferEnd, failed);
    }

    //--------------------------------------------------------------------
	template<class DataType,
			 DataType (*toData)( const ParserChar**, const ParserChar*, bool& )>
	DataType ParserTemplateBase::toDataPrefix(
                const ParserChar* prefixedBuffer,
                const ParserChar* prefixedBufferEnd,
                const ParserChar** buffer,
                const ParserChar* bufferEnd,
                bool& failed
                )
	{
		const ParserChar* prefixBufferPos = prefixedBuffer;
		const ParserChar* prefixBufferStartPos = 0;
        while ( prefixBufferPos != prefixedBufferEnd )
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
		IErrorHandler* errorHandler = getErrorHandler();
		if ( !errorHandler )
			return (severity == ParserError::SEVERITY_CRITICAL) ? true : false;

		ParserError error(severity,
						  errorType,
						  getNameByStringHash(elementHash),
						  getNameByStringHash(attributeHash),
						  getLineNumber(),
						  getColumnNumber(),
						  additionalText ? (const char*)additionalText : "");
		bool handlerWantsToAbort = errorHandler->handleError(error);

		return (severity == ParserError::SEVERITY_CRITICAL) ? true : handlerWantsToAbort;
	}

	//--------------------------------------------------------------------
	bool ParserTemplateBase::handleError( ParserError::Severity severity,
												 ParserError::ErrorType errorType,
												 StringHash attributeHash,
												 const ParserChar* additionalText )
	{
		StringHash elementHash = mElementDataStack.empty() ? 0 : mElementDataStack.back().elementHash;

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
