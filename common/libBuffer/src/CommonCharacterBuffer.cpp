/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonCharacterBuffer.h"
#include "Commonftoa.h"
#include "Commondtoa.h"
#include <cassert>

#include <string.h>


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

} // namespace Common
