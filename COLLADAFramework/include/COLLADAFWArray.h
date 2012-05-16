/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License,
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ARRAY_H__
#define __COLLADAFW_ARRAY_H__

#include "COLLADAFWPrerequisites.h"

#include "COLLADABUPlatform.h"

#include <cassert>


namespace COLLADAFW
{
	/** Array template that simplifies handling of C-arrays.*/
	template<class Type>
	class Array
	{
	public:
		/** Flags to control the behavior of the array.*/
		enum Flags
		{
			NO_FLAGS						= 0x0000,

			/** The memory will be released in the destructor. The memory must be allocated using
			allocateMemory()*/
			RELEASE_MEMORY					= 0x0001,
			/** Keep the ownership of the data, when this array is assigned to another one, i.e.
			it will release the memory on destruction, if the RELEASE_MEMORY flag is set.*/
			KEEP_OWNERSHIP_ON_ASSIGNEMNT    = 0x0002
		};

		enum FlagCombinations
		{
			/** The Default flags used for allocateMemory().*/
			DEFAULT_ALLOC_FLAGS = RELEASE_MEMORY,

			/** The Default flags used for constructor.*/
			DEFAULT_CONSTRUCTOR_FLAGS = NO_FLAGS,

			/** The array ons the data and keeps ownership on assignement.*/
			OWNER = RELEASE_MEMORY | KEEP_OWNERSHIP_ON_ASSIGNEMNT
		};

	private:

		/** The data C-array. */
		Type* mData;

		/** The number of stored data elements in the array. */
		size_t mCount;

        /** The number of elements, for which is currently memory allocated. */
        size_t mCapacity;

		/** The arrays flags.*/
		int mFlags;

	public:

        /** Constructor. */
		Array()
            : mData (0)
            , mCount (0)
            , mCapacity (0)
            , mFlags(DEFAULT_CONSTRUCTOR_FLAGS)
        {}

		/** Constructor. */
		Array(int flags)
			: mData (0)
			, mCount (0)
			, mCapacity (0)
			, mFlags(flags)
		{}

		/** Constructor. */
        Array ( Type* data, size_t count )
            : mData ( data )
            , mCapacity ( count )
            , mCount ( count )
            , mFlags(DEFAULT_CONSTRUCTOR_FLAGS)
        {}

        /** Destructor. */
        ~Array ()
        {
			clear();
		}

		/** Clears the array, i.e. releasese memory if nescesary and reset all members.*/
		void clear()
		{
			if ( mFlags & RELEASE_MEMORY)
				releaseMemory();
		}

        /** Returns the C-style data array.*/
        Type* getData () { return mData; }

        /** Returns the C-style data array.*/
        const Type* getData () const { return mData; }

		/** Set the C-style data array.*/
		void setData ( Type* data, const size_t count )
        {
            mData = data;
            mCount = count;
            mCapacity = count;
        }

		/** Set the C-style data array and count.*/
		void setData ( Type* data, const size_t count, const size_t capacity )
        {
            mData = data;
            mCount = count;
            mCapacity = capacity;
        }

        /** Returns the number of elements in the array.*/
        const size_t getCount() const { return mCount; }

		/** Returns the number of elements in the array.*/
		void setCount(size_t count) {  mCount = count; }


        /** The number of elements, for which is currently memory allocated. */
        size_t getCapacity () const { return mCapacity; }

        /** The number of elements, for which is currently memory allocated. */
        void setCapacity ( const size_t capacity ) { mCapacity = capacity; }

		/** Allocates memory for @a size elements of type DataType.
        Must not be called more than once, without calling releaseMemory() in between.
		The memory must be released using releaseMemory().
		@param size The size of the array
		@param flags Flags that allow to control, how the memory should be released.*/
		void allocMemory ( size_t count, int flags = DEFAULT_ALLOC_FLAGS )
        {
            setData ( new Type[count], 0, count );
            mFlags |= flags;
        }

		/** Releases the memory that has been allocated by allocateMemory().
        Must not be called, if the memory has not been allocated by allocateMemory().*/
		virtual void releaseMemory ()
        {
            delete[] mData;
            setData ( 0, 0, 0 );
        }

		/** Returns true if the array is empty, false otherwise.*/
		bool empty() const { return mCount == 0; }

		/** Return s the index'th element in the array. No check is performed, if the index is out of bounds.*/
		Type& operator[] ( size_t index ) { COLLADABU_ASSERT(index < mCapacity); return mData[index]; }

        /** Return s the index'th element in the array. No check is performed, if the index is out of bounds.*/
        const Type& operator[] ( size_t index ) const { return mData[index]; }

		/** Returns a reference to the last element in the array. The array must not be empty.*/
		Type& back() { COLLADABU_ASSERT(mData && (mCount > 0)); return mData[mCount - 1]; }

		/** Returns a reference to the last element in the array. The array must not be empty.*/
		const Type& back() const { COLLADABU_ASSERT(mData && (mCount > 0)); return mData[mCount - 1]; }

		/** Clones the array inti @a clonedArray.*/
		void cloneArray( Array<Type>& clonedArray ) const
		{
			clonedArray.allocMemory(getCapacity());
			size_t count = getCount();
			clonedArray.setCount(count);
			for ( size_t i = 0; i < count; ++i)
				clonedArray[i] = (*this)[i];
		}

        /** Disable default copy ctor. */
		Array( const Array& pre );

	};



} // namespace COLLADAFW

#endif // __COLLADAFW_ARRAY_H__
