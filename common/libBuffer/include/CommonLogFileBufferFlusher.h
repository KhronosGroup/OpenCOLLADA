/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_LogFileBufferFlusher_H__
#define __COMMON_LogFileBufferFlusher_H__

#include "CommonIBufferFlusher.h"

#include <string>

namespace Common
{
	class LogFileBufferFlusher : public IBufferFlusher
	{
	private:
		/** The name of the file.*/
		std::string mFileName;

		/** The name of the file.*/
		std::wstring mWideFileName;

		/** The error code of fopen_s.*/
		int mError;

		/** .*/
		bool mUseWideFileName;

	public:
		LogFileBufferFlusher( const char* fileName);
		LogFileBufferFlusher( const wchar_t* fileName);
		virtual ~LogFileBufferFlusher();

		/** The error code of fopen_s.*/
		int getError() const { return mError; }

		/** Receives and handles @a length bytes starting at @a buffer.
		@return True on success, false otherwise.*/
		virtual bool receiveData( const char* buffer, size_t length);

		/** Flushes all the data previously received by receiveData.*/
		virtual bool flush();

		void startMark();

		MarkId endMark();

		bool jumpToMark(MarkId markId, bool keepMarkId = false);


	private:
        /** Disable default copy ctor. */
		LogFileBufferFlusher( const LogFileBufferFlusher& pre );
        /** Disable default assignment operator. */
		const LogFileBufferFlusher& operator= ( const LogFileBufferFlusher& pre );

	};
} // namespace COMMON

#endif // __COMMON_LogFileBufferFlusher_H__
