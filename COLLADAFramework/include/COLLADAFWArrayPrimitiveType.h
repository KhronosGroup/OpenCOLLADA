/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ARRAYPRIMITIVETYPE_H__
#define __COLLADAFW_ARRAYPRIMITIVETYPE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArray.h"


namespace COLLADAFW
{
	/** 
    Array template that simplifies handling of C-arrays.
    The memory will be allocated with malloc, freed with free and resized with realloc. 
    Don't take this class for other data types then the primitives data types, because no 
    constructors and destructors will be called!
    */
	template<class Type>
    class ArrayPrimitiveType : public Array<Type>
	{
	public:

        /** Constructor. */
        ArrayPrimitiveType() 
            : Array ()
        {}


		/** Constructor. */
		ArrayPrimitiveType(int flags) 
			: Array (flags)
		{}

		/** Constructor. */
        ArrayPrimitiveType ( Type* data, size_t capacity ) 
            : Array ( data, capacity )
        {}

        /** Destructor. */
        virtual ~ArrayPrimitiveType ()
        {
        }

		/** Allocates memory for @a size elements of type DataType. 
        Must not be called more than once, without calling releaseMemory() in between. 
		The memory must be released using releaseMemory().
		@param size The size of the array
		@param flags Flags that allow to control, how the memory should be released.*/
		void allocMemory ( size_t capacity, int flags = DEFAULT_ALLOC_FLAGS )
        {
			if ( capacity == 0 )
				setData ( 0, 0, 0 ); 
			else
				setData ( ( Type* ) ( malloc ( capacity * sizeof (Type) ) ), 0, capacity );
            mFlags |= flags;
        }

		/** Releases the memory that has been allocated by allocateMemory(). 
        Must not be called, if the memory has not been allocated by allocateMemory().*/
		void releaseMemory ()
        { 
            free ( mData ); 
            setData ( 0, 0, 0 ); 
        }

        /**      
        * Increases the capacity of the array, if necessary, to ensure that it can hold at least 
        * the number of elements specified by the minimum capacity argument.
        * @param minCapacity the desired minimum capacity
        */
        void reallocMemory ( size_t minCapacity )
        {
			if ( minCapacity <= mCapacity)
				return;
            size_t newCapacity = ( mCapacity * 3 ) / 2 + 1;
            if (newCapacity < minCapacity)
                newCapacity = minCapacity;
            mCapacity = newCapacity;

			if ( mData )
			{
				mData = ( Type* ) realloc ( mData, mCapacity * sizeof ( Type ) );
				if ( mCount > mCapacity ) 
					mCount = mCapacity;
			}
			else
			{
				allocMemory(newCapacity, mFlags);
			}
        }

		/** Appends @a newValue to the end of array. If not enough memory was allocated, a resize 
        of the array will be done! */
		Type& append ( const Type& newValue )
        { 
            if ( mCount >= mCapacity ) 
				reallocMemory (mCount + 1); 

            return mData [ mCount++ ] = newValue;	
        }

        /** Appends @a newValue to the end of array. If not enough memory was allocated, 
        a resize of the array will be done! */
        ArrayPrimitiveType<Type>* appendValues ( const ArrayPrimitiveType<Type>& valuesArray )
        { 
			return appendValues(valuesArray.getData(), valuesArray.getCount());
        }


		/** Appends @a newValue to the end of array. If not enough memory was allocated, 
		a resize of the array will be done! */
		ArrayPrimitiveType<Type>* appendValues ( const Type* data, size_t length  )
		{ 
			reallocMemory ( mCount + length );

			memcpy ( mData + mCount, data, length * sizeof (Type) );
			mCount += length;

			return this;
		}

		
		
		/** Disable default copy ctor. */
		ArrayPrimitiveType ( const Array& pre );

	};


} // namespace COLLADAFW

#endif // __COLLADAFW_ARRAYPRIMITIVETYPE_H__
