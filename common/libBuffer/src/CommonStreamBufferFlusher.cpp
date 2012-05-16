/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonStreamBufferFlusher.h"

namespace Common
{
	//--------------------------------------------------------------------
	StreamBufferFlusher::StreamBufferFlusher( const char* fileName, size_t bufferSize )
		: mBufferSize(bufferSize)
		, mBuffer( new char[mBufferSize] )
	{
		mStream.rdbuf()->pubsetbuf ( mBuffer, (std::streamsize)mBufferSize );
		mStream.open ( fileName );
	}

	//--------------------------------------------------------------------
	StreamBufferFlusher::~StreamBufferFlusher()
	{
		mStream.close();
		delete[] mBuffer;
	}

	//--------------------------------------------------------------------
	bool StreamBufferFlusher::receiveData( const char* buffer, size_t length )
	{
		mStream.write( buffer, (std::streamsize)length );
		return !mStream.bad(); 
	}

	//--------------------------------------------------------------------
	bool StreamBufferFlusher::flush()
	{
		mStream.flush();
		return !mStream.bad(); 
	}


} // namespace Common
