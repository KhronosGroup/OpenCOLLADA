/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonBuffer.h"
#include <memory>
#include <string.h>


namespace Common
{
	//--------------------------------------------------------------------
	Buffer::Buffer( size_t bufferSize, IBufferFlusher* flusher )
		: mBuffer( new char[bufferSize] )
		, mBufferSize(bufferSize)
		, mCurrentPos( mBuffer )
		, mDirectFlushSize( mBufferSize )
		, mFlusher(flusher)
	{

	}

	//--------------------------------------------------------------------
	Buffer::~Buffer()
	{
		flushFlusher();
		delete[] mBuffer;
	}


	//--------------------------------------------------------------------
	bool Buffer::flushBuffer()
	{
		if ( isEmpty() )
		{
			// there is nothing to flush
			return true;
		}

		// flush the buffer
		bool success = mFlusher->receiveData( mBuffer, getBytesUsed() );

		// reset the buffer
		mCurrentPos = mBuffer;

		return success;
	}

	//--------------------------------------------------------------------
	bool Buffer::flushFlusher()
	{
		if ( !flushBuffer() )
		{ 
			return false;
		}

		return mFlusher->flush();
	}

	//--------------------------------------------------------------------
	bool Buffer::copyToBuffer( const char* text )
	{
		size_t length = strlen( text );
		return copyToBuffer( text, length);
	}


	//--------------------------------------------------------------------
	void Buffer::setDirectFlushSize( size_t directFlushSize )
	{
		mDirectFlushSize =  (directFlushSize > mBufferSize) ? mBufferSize : directFlushSize;
	}

} // namespace Common
