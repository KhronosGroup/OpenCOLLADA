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

#if (defined(WIN64) || defined(_WIN64) || defined(__WIN64__)) || (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
#ifdef __GNUC__
#	include <tr1/unordered_map>
#else
#	include <unordered_map>
#endif
#else
#	include <tr1/unordered_map>
#endif

/* size_t for gcc, may want to move this include some place else - campbell */
#ifdef __GNUC__
#   include <cstdlib> /* size_t */
#   include <cstdio>  /* FILE */
#endif

#if (defined(__GNUC__) && !defined(__STRICT_ANSI__) && !defined(__MINGW32__)) || (__STDC_VERSION__ >= 199901L)
typedef int64_t __int64;
#endif

namespace Common
{
	class FWriteBufferFlusher : public IBufferFlusher
	{
	private:
#ifdef __APPLE__
		typedef off_t FilePosType;
#else
		typedef __int64 FilePosType;
#endif
		typedef std::tr1::unordered_map<MarkId, FilePosType > MarkIdToFilePos;
	public:
		static const size_t DEFAUL_BUFFER_SIZE = 64*1024;
	private:
		/** The buffer size of the stream.*/
		size_t mBufferSize;

		/** The buffer of the stream.*/
		char *mBuffer;

		/** The stream to write the data to.*/
		FILE* mStream;

		/** The error code of fopen_s.*/
		int mError;

		MarkId mLastMarkId;

		MarkIdToFilePos mMarkIds;

	public:
		FWriteBufferFlusher( const char* fileName, size_t bufferSize = DEFAUL_BUFFER_SIZE, const char* mode="wb" );
		FWriteBufferFlusher( const wchar_t* fileName, size_t bufferSize = DEFAUL_BUFFER_SIZE, const wchar_t* mode=L"wb" );
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

		void startMark();

		IBufferFlusher::MarkId endMark();

		bool jumpToMark(IBufferFlusher::MarkId markId, bool keepMarkId = false);

	private:
        /** Disable default copy ctor. */
		FWriteBufferFlusher( const FWriteBufferFlusher& pre );
        /** Disable default assignment operator. */
		const FWriteBufferFlusher& operator= ( const FWriteBufferFlusher& pre );

	};
} // namespace COMMON

#endif // __COMMON_FWRITEBUFFERFLUSHER_H__
