/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "CommonFWriteBufferFlusher.h"

#include <cerrno>

namespace Common
{
	//--------------------------------------------------------------------
	FWriteBufferFlusher::FWriteBufferFlusher( const char* fileName, size_t bufferSize, const char* mode/*="wb"*/ )
		: mBufferSize(bufferSize)
		, mBuffer( new char[bufferSize] )
#if defined(_WIN32) && !defined(__GNUC__)
		, mError( (int)fopen_s( &mStream, fileName, mode ) )
#else
		, mStream(fopen( fileName, mode ))
		, mError( mStream ? 0 : errno )
#endif
		, mLastMarkId(END_OF_STREAM)
		, mMarkIds()
	{
		if ( mError == 0 )
		{
			mError = ( setvbuf( mStream , mBuffer, _IOFBF, mBufferSize ) != 0 );
		}
	}
	//-----------------------------------------------------------------------

	/* note: Unix has no _wfopen_s equivalent if its important we could
	 * impliment our own but most likely this function is only needed
	 * by windows developers - campbell */
#if defined(_WIN32) && !defined(__GNUC__)
	FWriteBufferFlusher::FWriteBufferFlusher( const wchar_t* fileName, size_t bufferSize, const wchar_t* mode/*=L"wb"*/ )
		: mBufferSize(bufferSize)
		, mBuffer( new char[bufferSize] )
		, mError( (int)_wfopen_s( &mStream, fileName, mode ) )
		, mLastMarkId(END_OF_STREAM)
		, mMarkIds()
	{
		if ( mError == 0 )
		{
			mError = ( setvbuf( mStream , mBuffer, _IOFBF, mBufferSize ) != 0 );
		}
	}
#endif
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

	//------------------------------
	void FWriteBufferFlusher::startMark()
	{
		// store the current file position
#ifdef _WIN32
		FilePosType currentPos = _ftelli64(mStream);
#elif defined (__APPLE__)
		FilePosType currentPos = ftello(mStream);
#else
		FilePosType currentPos = ftello64(mStream);
#endif

		mLastMarkId++;
		mMarkIds.insert(std::make_pair(mLastMarkId, currentPos));		
	}

	//------------------------------
	IBufferFlusher::MarkId FWriteBufferFlusher::endMark()
	{
		return mLastMarkId;
	}

	//------------------------------
	bool FWriteBufferFlusher::jumpToMark( IBufferFlusher::MarkId markId, bool keepMarkId /*= false*/ )
	{
		if ( markId == END_OF_STREAM )
		{
#ifdef _WIN32
			return (_fseeki64(mStream, 0, SEEK_END) == 0);
#elif defined (__APPLE__)
			return (fseeko(mStream, 0, SEEK_END) == 0);
#else
			return (fseeko64(mStream, 0, SEEK_END) == 0);
#endif
		}
		else
		{
			MarkIdToFilePos::const_iterator markIdIt = mMarkIds.find(markId);
			if ( markIdIt == mMarkIds.end() )
			{
				return false;
			}
			else
			{
				FilePosType pos = markIdIt->second;
#ifdef _WIN32
				bool success = (_fseeki64(mStream, pos, SEEK_SET) == 0);
#elif defined (__APPLE__)
				bool success = (fseeko(mStream, pos, SEEK_SET) == 0);
#else
				bool success = (fseeko64(mStream, pos, SEEK_SET) == 0);
#endif
				if ( !keepMarkId )
				{
					mMarkIds.erase(markIdIt);
				}
				return success;
			}
		}
	}

} // namespace Common
