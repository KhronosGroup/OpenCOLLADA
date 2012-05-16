/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_STREAMBUFFERFLUSHER_H__
#define __COMMON_STREAMBUFFERFLUSHER_H__

#include "CommonIBufferFlusher.h"
#include <fstream>


namespace Common
{
	class StreamBufferFlusher : public IBufferFlusher	
	{
	private:
		/** The stream to write the data to.*/
		std::ofstream mStream;

		/** The buffer size of the stream.*/
		size_t mBufferSize;

		/** The buffer of the stream.*/
		char *mBuffer;

	public:
		StreamBufferFlusher(const char* fileName, size_t bufferSize);
		virtual ~StreamBufferFlusher();

		/** Receives and handles @a length bytes starting at @a buffer.
		@return True on success, false otherwise.*/
		virtual bool receiveData( const char* buffer, size_t length);

		/** Flushes all the data previously received by receiveData.*/
		virtual bool flush();


	private:
        /** Disable default copy ctor. */
		StreamBufferFlusher( const StreamBufferFlusher& pre );
        /** Disable default assignment operator. */
		const StreamBufferFlusher& operator= ( const StreamBufferFlusher& pre );

	};
} // namespace COMMON

#endif // __COMMON_STREAMBUFFERFLUSHER_H__
