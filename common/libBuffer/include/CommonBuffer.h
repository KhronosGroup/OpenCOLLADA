/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_BUFFER_H__
#define __COMMON_BUFFER_H__

#include "CommonIBufferFlusher.h"
#include <string.h>

namespace Common
{
	class Buffer 	
	{
	private:
		/** Pointer to the buffer.*/
		char* mBuffer;

		/** The size of the buffer.*/
		size_t mBufferSize;

		/** Pointer to the first unused byte in the buffer.*/
		char* mCurrentPos;
		
		/** Minimum size of data that will be flushed directly without copying to the buffer. The current buffer will 
		be flushed before. */
		size_t mDirectFlushSize;

		/** Total number of bytes already passed to the flusher.*/
		size_t mBytesFlushed;

		/** The flusher used to flush the buffer.*/
		IBufferFlusher* mFlusher;

		bool mMarkSet;

		bool mIsOverwriting;

	public:
		Buffer(size_t bufferSize, IBufferFlusher* flusher);

		virtual ~Buffer();

		/** The flusher used to flush the buffer.*/
		IBufferFlusher* getFlusher() const { return mFlusher; }

		/** Flushes the to using the buffer flusher.
		@return True on success, false otherwise. 
		@note Calling this method does not force to flusher to flush its data. To force this call flushFlusher instead.*/
		bool flushBuffer();

		/** Flushes the flusher. Call this to ensure that the data is really been handled by the flusher. 
		This method implicitly calls flushBuffer.*/
		bool flushFlusher();

		/** Copies @a length bytes into the buffer, starting at @a data .*/
		template<class T>
		bool copyToBuffer( const T* data, size_t length);

		/** Copies null terminated @a text  into the buffer.*/
		bool copyToBuffer( const char* text);

		/** Copies @a c  into the buffer.*/
		template<class T>
		bool copyToBuffer( const T& c);

		size_t getBufferSize() const { return mBufferSize; }

		/** The number of bytes currently in the buffer.*/
		size_t getBytesUsed() const;

		/** The number of bytes currently available in the buffer.*/
		size_t getBytesAvailable() const;

		/** The number of bytes already copied to the buffer.*/
		size_t getBytesCopiedToBuffer() const;

		/** @return True, if the buffer does not contain any data, false otherwise.*/
		size_t isEmpty() const;

		/** Minimum size of data that will be flushed directly without copying to the buffer. The current buffer will 
		be flushed before. */
		size_t getDirectFlushSize() const;

		/** Minimum size of data that will be flushed directly without copying to the buffer. The current buffer will 
		be flushed before. If @a directFlushSize is larger than the buffer size, the direct flush size will be set
		to the buffer size. */
		void setDirectFlushSize(size_t directFlushSize);

		/**
		* Setting the start mark.
		* @return True if start mark could be set, otherwise false.
		*/
		bool startMark();

		IBufferFlusher::MarkId endMark();

	    bool jumpToMark(IBufferFlusher::MarkId markId, bool keepMarkId = false);

	protected:

		/** Provides access to the current position of the buffer for derived classes. Might be useful for 
		implementations that want to write into the buffer directly. Use increaseCurrentPosition to tell the buffer
		how many bytes have been added to the buffer. Before writing into the buffer directly, use 
		getBytesAvailable to ensure there is enough space available.*/
		char* getCurrentPosition() { return mCurrentPos; }

		/** Shifts the current position in the buffer by @a addedBytes bytes. No check is performed if the 
		new position is beyond the buffers end.*/
		void increaseCurrentPosition( size_t addedBytes); 
	
		/** Shifts the current position in the buffer by 1 byte. No check is performed if the 
		new position is beyond the buffers end.*/
		void increaseCurrentPosition(); 

	private:
        /** Disable default copy ctor. */
		Buffer( const Buffer& pre );
        /** Disable default assignment operator. */
		const Buffer& operator= ( const Buffer& pre );

		bool sendDataToFlusher( const char* buffer, size_t length);
	};


	//--------------------------------------------------------------------
	template<class T>
	bool Buffer::copyToBuffer( const T* data, size_t length )
	{
		static const size_t typeSize = sizeof(T);
		size_t arraySize = length * typeSize;

		if ( arraySize >= mDirectFlushSize )
		{
			// the data is large enough to flush directly
			// flush the buffer first
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}

			// flush the new data directly
			return sendDataToFlusher( (const char *)data, arraySize );
		}

		if ( arraySize > getBytesAvailable() )
		{
			// the new data does not fit into the buffer. We need to flush first.
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}
		}

		// copy data into buffer.
		memcpy( mCurrentPos, data, arraySize );
		mCurrentPos += arraySize;
		return true;
	}

	//--------------------------------------------------------------------
	template<class T>
	bool Buffer::copyToBuffer( const T& c )
	{
		static const size_t typeSize = sizeof(T);
		if ( mDirectFlushSize <= typeSize )
		{
			// the data is large enough to flush directly
			// flush the buffer first
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}

			// flush the new data directly
			return sendDataToFlusher( (const char *)&c, typeSize );
		}

		if ( getBytesAvailable() < typeSize)
		{
			// the new data does not fit into the buffer. We need to flush first.
			if ( !flushBuffer() )
			{
				// the buffer could not be flushed
				return false;
			}
		}

		// copy data into buffer.
		T* typePos = (T*)mCurrentPos;
		*typePos = c;
		mCurrentPos += typeSize;
		return true;
	}



} // namespace COMMON

#endif // __COMMON_BUFFER_H__
