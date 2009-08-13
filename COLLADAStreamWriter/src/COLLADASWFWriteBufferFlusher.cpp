/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWFWriteBufferFlusher.h"

#include <errno.h>

namespace COLLADASW
{

	//From Common Repo: Rev 31

	//--------------------------------------------------------------------
	FWriteBufferFlusher::FWriteBufferFlusher( const char* fileName, size_t bufferSize )
		: mBufferSize(bufferSize)
		, mBuffer( new char[bufferSize] )
#ifdef WIN32
		, mError( (int)fopen_s( &mStream, fileName, "wb" ) )
#else
		, mStream(fopen( fileName, "wb" ))
		, mError( mStream ? 0 : errno )
#endif
	{
		if ( mError == 0 )
		{
			( setvbuf( mStream , mBuffer, _IOFBF, mBufferSize ) != 0 );
		}
	}

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




} // namespace COLLADASW
