/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonFWriteBufferFlusher.h"

#include <cstdio>
#include <errno.h>

namespace Common
{
	//--------------------------------------------------------------------
	FWriteBufferFlusher::FWriteBufferFlusher( const char* fileName, size_t bufferSize, const char* mode/*="wb"*/ )
		: mBufferSize(bufferSize)
		, mBuffer( new char[bufferSize] )
#ifdef WIN32
		, mError( (int)fopen_s( &mStream, fileName, mode ) )
#else
		, mStream(fopen( fileName, mode ))
		, mError( mStream ? 0 : errno )
#endif
	{
		if ( mError == 0 )
		{
			( setvbuf( mStream , mBuffer, _IOFBF, mBufferSize ) != 0 );
		}
	}
    /* Not possible on mac os!
	//-----------------------------------------------------------------------
	FWriteBufferFlusher::FWriteBufferFlusher( const wchar_t* fileName, size_t bufferSize, const wchar_t* mode/*=L"wb"* )
		: mBufferSize(bufferSize)
		, mBuffer( new char[bufferSize] )
#ifdef WIN32
		, mError( (int)_wfopen_s( &mStream, fileName, mode ) )
#else
		, mStream(_wfopen( fileName, mode ))
		, mError( mStream ? 0 : errno )
#endif
	{
		if ( mError == 0 )
		{
			( setvbuf( mStream , mBuffer, _IOFBF, mBufferSize ) != 0 );
		}
	}
    */
	//--------------------------------------------------------------------
	FWriteBufferFlusher::~FWriteBufferFlusher()
	{
		if ( mStream )
		{
			fclose(mStream);
		}

		delete[] mBuffer;
	}

	//--------------------------------------------------------------------
	bool FWriteBufferFlusher::receiveData( const char* buffer, size_t length )
	{
		if ( !mStream )
		{
			return false;
		}
		return fwrite( buffer, 1, length, mStream ) == length;
	}

	//--------------------------------------------------------------------
	bool FWriteBufferFlusher::flush()
	{
		if ( !mStream )
		{
			return false;
		}
		return fflush( mStream ) == 0;
	}
} // namespace Common
