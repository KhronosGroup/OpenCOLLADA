/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_FWRITEBUFFERFLUSHER_H__
#define __COMMON_FWRITEBUFFERFLUSHER_H__

#include "CommonIBufferFlusher.h"
#include <iostream>

namespace Common
{
	class FWriteBufferFlusher : public IBufferFlusher
	{
	private:
		/** The buffer size of the stream.*/
		size_t mBufferSize;

		/** The buffer of the stream.*/
		char *mBuffer;

		/** The stream to write the data to.*/
		FILE* mStream;

		/** The error code of fopen_s.*/
		int mError;

	public:
		FWriteBufferFlusher( const char* fileName, size_t bufferSize, const char* mode="wb" );
		FWriteBufferFlusher( const wchar_t* fileName, size_t bufferSize, const wchar_t* mode=L"wb" );
		virtual ~FWriteBufferFlusher();

		/** The error code of fopen_s.*/
		int getError() const { return mError; }

		/** Receives and handles @a length bytes starting at @a buffer.
		@return True on success, false otherwise.*/
		virtual bool receiveData( const char* buffer, size_t length);

		/** Flushes all the data previously received by receiveData.*/
		virtual bool flush();

		/** Internal method that 
		    @return FILE*
		*/
		FILE* _getFileHandle() const { return mStream; }


	private:
        /** Disable default copy ctor. */
		FWriteBufferFlusher( const FWriteBufferFlusher& pre );
        /** Disable default assignment operator. */
		const FWriteBufferFlusher& operator= ( const FWriteBufferFlusher& pre );

	};
} // namespace COMMON

#endif // __COMMON_FWRITEBUFFERFLUSHER_H__
