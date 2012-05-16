/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_IBUFFERFLUSHER_H__
#define __COMMON_IBUFFERFLUSHER_H__

/* size_t for gcc, may want to move this include some place else - campbell */
#ifdef __GNUC__
#  include <cstdlib> /* size_t */
#  include <cstring> /* memcpy */
#endif

namespace Common
{
	/** Derived classes of this interface are used by Buffer.*/
	class IBufferFlusher 	
	{
	public:
		typedef unsigned long MarkId;
	public:
		static const MarkId END_OF_STREAM = 0;
		static const MarkId INVALID_ID = -1;
	public:
		IBufferFlusher(){}
		virtual ~IBufferFlusher(){}

		/** Receives and handles @a length bytes starting at @a buffer.
		@return True on success, false otherwise.*/
		virtual bool receiveData( const char* buffer, size_t length) = 0;

		/** Flushes all the data previously received by receiveData.*/
		virtual bool flush() = 0;

		virtual void startMark() = 0;

		virtual MarkId endMark() = 0;

		virtual bool jumpToMark(MarkId markId, bool keepMarkId = false) = 0;

		virtual int getError() const = 0;

	private:
        /** Disable default copy ctor. */
		IBufferFlusher( const IBufferFlusher& pre );
        /** Disable default assignment operator. */
		const IBufferFlusher& operator= ( const IBufferFlusher& pre );

	};

} // namespace COMMON

#endif // __COMMON_IBUFFERFLUSHER_H__
