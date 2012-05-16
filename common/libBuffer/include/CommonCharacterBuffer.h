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

namespace Common
{
	/** This is an extension Buffer, that can handle C++ built in types and copies there string representation.*/
	class CharacterBuffer : public Buffer
	{	
	public:
		static const char DEFAULT_TRUE_STRING[];
		static const char DEFAULT_FALSE_STRING[];

		/** The maximum length a UTF8 encoded character can have.*/
		static const size_t MAX_UTF8_CHAR_LENGTH = 4;

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

		/** Copies a string representation @a i into the buffer.*/
		bool copyToBufferAsChar( char i);
		bool copyToBufferAsChar( unsigned char i);

		bool copyToBufferAsChar( short i);
		bool copyToBufferAsChar( unsigned short i);

		bool copyToBufferAsChar( long i);
		bool copyToBufferAsChar( unsigned long i);

		bool copyToBufferAsChar( int i);
		bool copyToBufferAsChar( unsigned int i);

		bool copyToBufferAsChar( long long i);
		bool copyToBufferAsChar( unsigned long long i);

		/** Copies a string representation @a v into the buffer. Either 0 or 1*/
		bool copyToBufferAsChar( bool v);
	
		/** Copies a string  @a text into the buffer, encoded as UTF8.*/
		void copyToBufferAsChar( const wchar_t* text, size_t length );

		/** Converts the first @a sourceWideTextLength wide character in @a sourceWideText to UTF8 encoded char in @a targetTextBuffer. 
		The size of @a targetTextBuffer hast be at least MAX_UTF8_CHAR_LENGTH * sourceWideTextLength.*/
		static size_t convertWideStringToUTF8( const wchar_t* sourceWideText, size_t sourceWideTextLength, char* targetTextBuffer, size_t targetTextBufferLength);


	private:
        /** Disable default copy ctor. */
		CharacterBuffer( const CharacterBuffer& pre );
        /** Disable default assignment operator. */
		const CharacterBuffer& operator= ( const CharacterBuffer& pre );

		/** Copies a string representation @a i into the buffer.
		@tparam IntegerType The type of the integer to copy to the buffer.*/
		template<class IntegerType>
		bool copyIntegerToBufferAsChar( IntegerType i);

	};



} // namespace COMMON

#endif // __COMMON_CHARACTERBUFFER_H__
