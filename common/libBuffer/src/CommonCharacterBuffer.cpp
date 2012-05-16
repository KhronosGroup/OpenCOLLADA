/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonCharacterBuffer.h"

#include <string.h>
#include <algorithm>
#include <Commonftoa.h>
#include <Commondtoa.h>
#include <Commonitoa.h>
#include <ConvertUTF.h>

namespace Common
{

	const char CharacterBuffer::DEFAULT_TRUE_STRING[] = "1";
	const char CharacterBuffer::DEFAULT_FALSE_STRING[] = "0";


	//--------------------------------------------------------------------
	CharacterBuffer::CharacterBuffer( size_t bufferSize, IBufferFlusher* flusher )
		: Buffer(bufferSize, flusher)
		, mTrueString(DEFAULT_TRUE_STRING)
		, mTrueStringLength(sizeof(DEFAULT_TRUE_STRING)-1)
		, mFalseString(DEFAULT_FALSE_STRING)
		, mFalseStringLength(sizeof(DEFAULT_FALSE_STRING)-1)
	{

	}

	//--------------------------------------------------------------------
	void CharacterBuffer::setTrueString( const char* trueString )
	{
		mTrueString = trueString;
		mTrueStringLength = strlen( trueString );
	}

	//--------------------------------------------------------------------
	void CharacterBuffer::setFalseString( const char* falseString )
	{
		mFalseString = falseString;
		mFalseStringLength = strlen( falseString );
	}

	//--------------------------------------------------------------------
	bool CharacterBuffer::copyToBufferAsChar( float f )
	{
		if ( getBytesAvailable() < FTOA_BUFFERSIZE )
		{
			//The float might not fit into the buffer. We need to flush first.
			flushBuffer();
		}
		
		// Check if the buffer size is large enough
//		assert(getBytesAvailable() >= FTOA_BUFFERSIZE);
		if ( getBytesAvailable() < FTOA_BUFFERSIZE )
		{
			//No chance to convert the float with this buffer
			return false;
		}

		size_t bytesWritten = ftoa( f, getCurrentPosition() );

		increaseCurrentPosition( bytesWritten );

		return true;
	}

	//--------------------------------------------------------------------
	bool CharacterBuffer::copyToBufferAsChar( double d, bool doublePrecision /*= false*/ )
	{
		if ( getBytesAvailable() < DTOA_BUFFERSIZE )
		{
			//The double might not fit into the buffer. We need to flush first.
			flushBuffer();
		}

		// Check if the buffer size is large enough
//		assert(getBytesAvailable() >= DTOA_BUFFERSIZE);
		if ( getBytesAvailable() < DTOA_BUFFERSIZE )
		{
			//No chance to convert the double with this buffer
			return false;
		}

		size_t bytesWritten = dtoa( d, getCurrentPosition(), doublePrecision );

		increaseCurrentPosition( bytesWritten );

		return true;
	}

	//--------------------------------------------------------------------
	bool CharacterBuffer::copyToBufferAsChar( bool v )
	{
		const char* string = v ? mTrueString : mFalseString;
		size_t length = v ? mTrueStringLength : mFalseStringLength;

		if ( getBytesAvailable() < length )
		{
			//The string might not fit into the buffer. We need to flush first.
			flushBuffer();
		}

		// Check if the buffer size is large enough
//		assert(getBytesAvailable() >= length);
		if ( getBytesAvailable() < length )
		{
			//No chance to convert the bool with this buffer
			return false;
		}

		copyToBuffer( string, length );

		return true;
	}

	//------------------------------
	void CharacterBuffer::copyToBufferAsChar( const wchar_t* text, size_t length )
	{
		static const size_t CHARACTERS_IN_BUFFER = 100;
		static const size_t BUFFER_SIZE = CharacterBuffer::MAX_UTF8_CHAR_LENGTH * CHARACTERS_IN_BUFFER;
		char buffer[BUFFER_SIZE];
		size_t charactersLeft = length;
		const wchar_t* p = text;
		while ( charactersLeft > 0 )
		{
			size_t charactersToConvert = std::min(CHARACTERS_IN_BUFFER, charactersLeft);
			size_t bytesConverted = convertWideStringToUTF8(p, charactersToConvert, buffer, BUFFER_SIZE);
			copyToBuffer( buffer, bytesConverted );
			charactersLeft -= charactersToConvert;
			p += charactersToConvert;
		}
	}

	//------------------------------
	size_t CharacterBuffer::convertWideStringToUTF8( const wchar_t* sourceWideText, size_t sourceWideTextLength, char* targetTextBuffer, size_t targetTextBufferLength )
	{
//		assert((targetTextBufferLength >= MAX_UTF8_CHAR_LENGTH*sourceWideTextLength));
		if((targetTextBufferLength < MAX_UTF8_CHAR_LENGTH*sourceWideTextLength))
			return 0;

		if ( !sourceWideText || (sourceWideTextLength==0) || !targetTextBuffer || (targetTextBufferLength < MAX_UTF8_CHAR_LENGTH*sourceWideTextLength))
		{
			return 0;
		}

		UTF8* targetstart = reinterpret_cast<UTF8*>( targetTextBuffer );
		UTF8* thisFirstWChar = targetstart;
		UTF8* targetend = targetstart + targetTextBufferLength;
		ConversionResult res = conversionOK;

		if ( sizeof( wchar_t ) == 2 )
		{
			const UTF16* sourcestart = reinterpret_cast<const UTF16*>( sourceWideText );
			const UTF16* sourceend = sourcestart + sourceWideTextLength;
			res = ConvertUTF16toUTF8( &sourcestart, sourceend, &targetstart, targetend, strictConversion );
		}
		else if ( sizeof( wchar_t ) == 4 )
		{
			const UTF32* sourcestart = reinterpret_cast<const UTF32*>( sourceWideText );
			const UTF32* sourceend = sourcestart + sourceWideTextLength;
			res = ConvertUTF32toUTF8( &sourcestart, sourceend, &targetstart, targetend, strictConversion );
		}
		else
		{
			return 0;
			//"Could not convert from wide string to UTF8."
		}

		if ( res != conversionOK )
		{
			return 0;
			//"Could not convert from wide string to UTF8."
		}
		return targetstart - thisFirstWChar;
	}


	//--------------------------------------------------------------------
	template<class IntegerType>
	bool CharacterBuffer::copyIntegerToBufferAsChar( IntegerType i)
	{
		size_t maxIntLength = Itoa<IntegerType>::MINIMUM_BUFFERSIZE_10; 

		if ( getBytesAvailable() < maxIntLength )
		{
			//The int might not fit into the buffer. We need to flush first.
			flushBuffer();
		}

		// Check if the buffer size is large enough
//		assert(getBytesAvailable() >= maxIntLength);
		if ( getBytesAvailable() < maxIntLength )
		{
			//No chance to convert the double with this buffer
			return false;
		}

		increaseCurrentPosition( itoa( i, getCurrentPosition(), 10) );

		return true;
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( char i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( unsigned char i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( short i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( unsigned short i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( long i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( unsigned long i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( int i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( unsigned int i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( long long i )
	{
		return copyIntegerToBufferAsChar(i);
	}

	//------------------------------
	bool CharacterBuffer::copyToBufferAsChar( unsigned long long i )
	{
		return copyIntegerToBufferAsChar(i);
	}



} // namespace Common
