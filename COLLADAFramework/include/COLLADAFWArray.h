/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ARRAY_H__
#define __COLLADAFW_ARRAY_H__

#include "COLLADAFWPrerequisites.h"

namespace COLLADAFW
{
	/** Array template that simplifies handling of C-arrays.*/
	template<class DataType>
	class Array 	
	{
	public:
		/** Flags to control the behavior of the array.*/
		enum Flags
		{
			NO_FLAGS        = 0x0000,

			/** The memory will be released in the destructor. The memory must be allocated using 
			allocateMemory()*/
			RELEASE_MEMORY   = 0x0001 
		};

		enum DefaultFlags
		{
			/** The Default flags used for allocateMemory().*/
			DEFAULT_ALLOC_FLAGS = RELEASE_MEMORY,

			/** The Default flags used for constructor.*/
			DEFAULT_CONSTRUCTOR_FLAGS = NO_FLAGS
		};

	private:

		/** The data C-array.*/
		DataType* mData;

		/** The number of elements in the array.*/
		size_t mCount;

		/** The arrays flags.*/
		int mFlags;

	public:

        /** Constructor. */
		Array() : mData(0), mCount(0), mFlags(DEFAULT_CONSTRUCTOR_FLAGS) {}

        /** Constructor. */
        Array ( DataType* data, size_t count ) : mData(data), mCount(count), mFlags(DEFAULT_CONSTRUCTOR_FLAGS){}

        /** Destructor. */
        virtual ~Array();

        /** Returns the C-style data array.*/
        DataType* getData() { return mData; }

        /** Returns the C-style data array.*/
        const DataType* getData() const { return mData; }

		/** Set the C-style data array.*/
		void setData( DataType* data, size_t count ) { mData = data; mCount = count; }

		/** Set the C-style data array and count.*/
		void setDataAndCount( DataType* data, size_t count ) { mData = data; mCount = count; }

        /** Returns the number of elements in the array.*/
        size_t getCount() const { return mCount; }

		/** Allocates memory for @a size elements of type DataType. Must not be called more than once, without calling
		releaseMemory() in between. 
		The memory must be released using releaseMemory().
		@param size The size of the array
		@param flags Flags that allow to control, how the memory should be released.*/
		void allocateMemory(size_t size, int flags = DEFAULT_ALLOC_FLAGS);

		/** Releases the memory that has been allocated by allocateMemory(). Must not be called, if the memory has not been 
		allocated by allocateMemory().*/
		void releaseMemory() { delete mData; setDataAndCount(0,0); }

		/** Appends @a newValue to the end of array. The programmer must ensure, that the memory allocated, 
		was large enough to hold another element. No new memory is allocated.*/
		DataType& append(const DataType& newValue) { return mData[mCount++] = newValue;	}

		/** Return s the index'th element in the array. No check is performed, if the index is out of bounds.*/
        DataType& operator[](size_t index) { return mData[index]; }

        /** Return s the index'th element in the array. No check is performed, if the index is out of bounds.*/
        const DataType& operator[](size_t index) const { return mData[index]; }

        /** Disable default copy ctor. */
		Array( const Array& pre );

	};

	template<class DataType>
	COLLADAFW::Array<DataType>::~Array()
	{
		if ( mFlags & RELEASE_MEMORY)
			releaseMemory();
	}

	template<class DataType>
	void COLLADAFW::Array<DataType>::allocateMemory( size_t size, int flags )
	{
		setDataAndCount(new DataType[size], 0);
		mFlags |= flags;
	}

} // namespace COLLADAFW

#endif // __COLLADAFW_ARRAY_H__
