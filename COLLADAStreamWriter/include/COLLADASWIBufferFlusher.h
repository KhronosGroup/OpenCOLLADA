/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	  This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASW_IBUFFERFLUSHER_H__
#define __COLLADASW_IBUFFERFLUSHER_H__

#include "COLLADASWPrerequisites.h"

#include <stdlib.h>

namespace COLLADASW
{

	//From Common Repo: Rev 31

	/** Derived classes of this interface are used by Buffer.*/
	class IBufferFlusher 	
	{
	public:
		IBufferFlusher(){}
		virtual ~IBufferFlusher(){}

		/** Receives and handles @a length bytes starting at @a buffer.
		@return True on success, false otherwise.*/
		virtual bool receiveData( const char* buffer, size_t length) = 0;

		/** Flushes all the data previously received by receiveData.*/
		virtual bool flush() = 0;

	private:
		/** Disable default copy ctor. */
		IBufferFlusher( const IBufferFlusher& pre );
		/** Disable default assignment operator. */
		const IBufferFlusher& operator= ( const IBufferFlusher& pre );

	};




} // namespace COLLADASW

#endif // __COLLADASW_IBUFFERFLUSHER_H__
