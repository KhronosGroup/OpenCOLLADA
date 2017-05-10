/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonLogFileBufferFlusher.h"
#include <stdio.h>
#include <errno.h>

#ifndef _WIN32
       FILE *_wfopen(const wchar_t *path, const char *mode)
       {
               const wchar_t *src = path;
               char *path_mbs;
               int n;
               FILE *file;

               n = (int)wcsrtombs(NULL, &src, 0, NULL);

               if (n < 0)
                       return NULL;

               path_mbs = (char *)malloc(n + 1);
               wcsrtombs(path_mbs, &path, n, NULL);
               path_mbs[n] = 0;

               file = fopen(path_mbs, mode);

               free(path_mbs);

               return file;
       }
#endif

namespace Common
{
	//--------------------------------------------------------------------
	LogFileBufferFlusher::LogFileBufferFlusher( const char* fileName )
		: mFileName(fileName)
		, mUseWideFileName(false)
	{
		FILE* stream;
#ifdef _WIN32
		mError = (int)fopen_s( &stream, fileName, "wb" );
#else
		stream = fopen( fileName, "wb" );
		mError = stream ? 0 : errno;
#endif
	}
	//-----------------------------------------------------------------------
	LogFileBufferFlusher::LogFileBufferFlusher( const wchar_t* fileName )
		: mWideFileName(fileName)
		, mUseWideFileName(true)
	{
		// create and empty the file if existing
		FILE* stream;
#ifdef _WIN32
		mError = (int)_wfopen_s( &stream, fileName, L"wb" );
#else
               stream = _wfopen( fileName, "wb" );
		mError = stream ? 0 : errno;
#endif
		if ( !mError )
		{
			fclose(stream);
		}
	}
	//--------------------------------------------------------------------
	LogFileBufferFlusher::~LogFileBufferFlusher()
	{
	}

	//--------------------------------------------------------------------
	bool LogFileBufferFlusher::receiveData( const char* buffer, size_t length )
	{

		FILE* stream;
#ifdef _WIN32
		if ( mUseWideFileName )
		{
			mError = (int)_wfopen_s( &stream, mWideFileName.c_str(), L"a" );
		}
		else
		{
			mError = (int)fopen_s( &stream, mFileName.c_str(), "a" );
		}
#else
		if ( mUseWideFileName )
		{
                       stream = _wfopen( mWideFileName.c_str(), "a" );
		}
		else
		{
			stream = fopen( mFileName.c_str(), "a" );
		}
		mError = stream ? 0 : errno;
#endif
		if ( mError != 0 )
		{
			return false;
		}

		bool writeSuccess = fwrite( buffer, 1, length, stream ) == length;
		if ( !writeSuccess )
		{
			return false;
		}
		return fclose(stream) == 0; 
	}

	//--------------------------------------------------------------------
	bool LogFileBufferFlusher::flush()
	{
		return true;
	}

	//------------------------------
	void LogFileBufferFlusher::startMark()
	{

	}

	//------------------------------
	IBufferFlusher::MarkId LogFileBufferFlusher::endMark()
	{
		return IBufferFlusher::END_OF_STREAM;
	}

	//------------------------------
	bool LogFileBufferFlusher::jumpToMark( MarkId markId, bool keepMarkId /*= false*/ )
	{
		return false;
	}

} // namespace Common
