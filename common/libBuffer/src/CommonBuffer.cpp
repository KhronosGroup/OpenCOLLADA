/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonBuffer.h"
#include <string.h>

namespace Common
{
	//--------------------------------------------------------------------
	Buffer::Buffer( size_t bufferSize, IBufferFlusher* flusher )
		: mBuffer( new char[bufferSize] )
		, mBufferSize(bufferSize)
		, mCurrentPos( mBuffer )
		, mDirectFlushSize( mBufferSize )
		, mBytesFlushed(0)
		, mFlusher(flusher)
		, mMarkSet(false)
		, mIsOverwriting(false)
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
		bool success = sendDataToFlusher( mBuffer, getBytesUsed() );

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

	//------------------------------
	size_t Buffer::getBytesUsed() const
	{
		return mCurrentPos - mBuffer;
	}

	//------------------------------
	size_t Buffer::getBytesAvailable() const
	{
		return getBufferSize()-getBytesUsed();
	}

	//------------------------------
	size_t Buffer::isEmpty() const
	{
		return mBuffer == mCurrentPos;
	}

	//------------------------------
	size_t Buffer::getDirectFlushSize() const
	{
		return mDirectFlushSize;
	}

	//------------------------------
	void Buffer::increaseCurrentPosition( size_t addedBytes )
	{
		mCurrentPos += addedBytes;
	}

	//------------------------------
	void Buffer::increaseCurrentPosition()
	{
		mCurrentPos++;
	}

	//------------------------------
	bool Buffer::startMark()
	{
//		assert(!mMarkSet);
		if(mMarkSet)
			return false; 

		flushBuffer();
		mMarkSet = true;
		mFlusher->startMark();

		return true;
	}

	//------------------------------
	IBufferFlusher::MarkId Buffer::endMark()
	{
//		assert(mMarkSet);
		if(!mMarkSet)
			return IBufferFlusher::INVALID_ID;

		mMarkSet = false;
		flushBuffer();
		return mFlusher->endMark();
	}

	//------------------------------
	bool Buffer::jumpToMark( IBufferFlusher::MarkId markId, bool keepMarkId /*= false*/ )
	{
		flushBuffer();
		if ( markId == IBufferFlusher::END_OF_STREAM )
		{
			mIsOverwriting = false;
		}
		else
		{
			mIsOverwriting = true;
		}
		return mFlusher->jumpToMark(markId, keepMarkId);
	}

	//------------------------------
	size_t Buffer::getBytesCopiedToBuffer() const
	{
		return mBytesFlushed + getBytesUsed();
	}

	//------------------------------
	bool Buffer::sendDataToFlusher( const char* buffer, size_t length )
	{
		if ( !mIsOverwriting )
		{
			mBytesFlushed += length;
		}
		return mFlusher->receiveData( buffer, length );
	}

} // namespace Common
