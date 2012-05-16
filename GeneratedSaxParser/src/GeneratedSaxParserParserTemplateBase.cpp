/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
	bool ParserTemplateBase::handleError( ParserError::Severity severity,
												 ParserError::ErrorType errorType,
												 StringHash elementHash,
												 StringHash attributeHash,
												 const ParserChar* additionalText /*= ""*/ )
	{
        return handleError(severity,
            errorType,
            elementHash,
            getNameByStringHash(attributeHash),
            additionalText);
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
    bool ParserTemplateBase::handleError( ParserError::Severity severity,
        ParserError::ErrorType errorType,
        StringHash elementHash,
        const ParserChar* attribute,
        const ParserChar* additionalText /*= ""*/ )
    {
        IErrorHandler* errorHandler = getErrorHandler();
        if ( !errorHandler )
            return (severity == ParserError::SEVERITY_CRITICAL) ? true : false;

        ParserError error(severity,
            errorType,
            getNameByStringHash(elementHash),
            attribute,
            getLineNumber(),
            getColumnNumber(),
            additionalText ? (const char*)additionalText : "");
        bool handlerWantsToAbort = errorHandler->handleError(error);

        return (severity == ParserError::SEVERITY_CRITICAL) ? true : handlerWantsToAbort;
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

	//--------------------------------------------------------------------
	StringHash ParserTemplateBase::getElementHash( size_t level /*= 0 */ )const
	{
		size_t elementDataStackSize = mElementDataStack.size();
		if ( level < elementDataStackSize )
		{
			return mElementDataStack[elementDataStackSize - 1 - level].elementHash;
		}
		else
		{
			return 0;
		}
	}
} // namespace GeneratedSaxParser
