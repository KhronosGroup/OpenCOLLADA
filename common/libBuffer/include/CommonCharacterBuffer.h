/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of Common libBuffer.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COMMON_CHARACTERBUFFER_H__
#define __COMMON_CHARACTERBUFFER_H__

#include "CommonBuffer.h"
#include "Commonitoa.h"

#include <cassert>

namespace Common
{
	/** This is an extension Buffer, that can handle C++ built in types and copies there string representation.*/
	class CharacterBuffer : public Buffer
	{	
	public:
		static const char DEFAULT_TRUE_STRING[];
		static const char DEFAULT_FALSE_STRING[];

	private:
		/** Text copied into the buffer for a true boolean.*/
		const char* mTrueString;

		/** Length of mTrueString without null termination.*/
		size_t mTrueStringLength;

		/** Text copied into the buffer for a false boolean.*/
		const char* mFalseString;

		/** Length of mFalseString without null termination.*/
		size_t mFalseStringLength;

	public:
		CharacterBuffer(size_t bufferSize, IBufferFlusher* flusher);
		virtual ~CharacterBuffer(){}


		/** Returns the text copied into the buffer for a true boolean.*/
		const char* getTrueString() const { return mTrueString; }

		/** Sets the Text copied into the buffer for a true boolean. @a trueString must persist at least as long
		as the CharacterBuffer object.*/
		void setTrueString( const char* trueString);

		/** Returns the Text copied into the buffer for a false boolean.*/
		const char* getFalseString() const { return mFalseString; }

		/** Sets the Text copied into the buffer for a false boolean. @a falseString must persist at least as long
		as the CharacterBuffer object.*/
		void setFalseString( const char* falseString);


		/** Copies a string representation @a f  into the buffer.*/
		bool copyToBufferAsChar( float f);

		/** Copies a string representation @a d into the buffer. Uses double precision representation 
		( 16 digits ) if @a doublePrecision is true, otherwise single precision as the float version.*/
		bool copyToBufferAsChar( double d, bool doublePrecision = false);

		/** Copies a string representation @a i into the buffer.
		@tparam IntegerType The type of the integer to copy to the buffer.*/
		template<class IntegerType>
		bool copyToBufferAsChar( IntegerType i);

		/** Copies a string representation @a v into the buffer. Either 0 or 1*/
		bool copyToBufferAsChar( bool v);


	private:
        /** Disable default copy ctor. */
		CharacterBuffer( const CharacterBuffer& pre );
        /** Disable default assignment operator. */
		const CharacterBuffer& operator= ( const CharacterBuffer& pre );

	};


	//--------------------------------------------------------------------
	template<class IntegerType>
	bool CharacterBuffer::copyToBufferAsChar( IntegerType i)
	{
		size_t maxIntLength = Itoa<IntegerType>::MINIMUM_BUFFERSIZE_10; 

		if ( getBytesAvailable() < maxIntLength )
		{
			//The int might not fit into the buffer. We need to flush first.
			flushBuffer();
		}

		// Check if the buffer size is large enough
		assert(getBytesAvailable() >= maxIntLength);
		if ( getBytesAvailable() < maxIntLength )
		{
			//No chance to convert the double with this buffer
			return false;
		}

		increaseCurrentPosition( itoa( i, getCurrentPosition(), 10) );

		return true;
	}



} // namespace COMMON

#endif // __COMMON_CHARACTERBUFFER_H__
