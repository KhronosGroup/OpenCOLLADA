/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWBuffer.h"

#include <memory>


namespace COLLADASW
{


	//From Common Repo: Rev 31

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
	bool Buffer::copyToBuffer( const char* data, size_t length )
	{
		if ( length >= mDirectFlushSize )
		{
			// the data is large enough to flush directly
			// flush the buffer first
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}

			// flush the new data directly
			return mFlusher->receiveData( data, length );
		}

		if ( length > getBytesAvailable() )
		{
			// the new data does not fit into the buffer. We need to flush first.
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}
		}

		// copy data into buffer.
		memcpy( mCurrentPos, data, length );
		mCurrentPos += length;
		return true;
	}

	//--------------------------------------------------------------------
	bool Buffer::copyToBuffer( char c )
	{
		if ( mDirectFlushSize <= 1 )
		{
			// the data is large enough to flush directly
			// flush the buffer first
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}

			// flush the new data directly
			return mFlusher->receiveData( &c, 1 );
		}

		if ( getBytesAvailable() < 1)
		{
			// the new data does not fit into the buffer. We need to flush first.
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}
		}

		// copy data into buffer.
		*mCurrentPos = c;
		mCurrentPos++;
		return true;
	}

	//--------------------------------------------------------------------
	void Buffer::setDirectFlushSize( size_t directFlushSize )
	{
		mDirectFlushSize =  (directFlushSize > mBufferSize) ? mBufferSize : directFlushSize;
	}




} // namespace COLLADASW
