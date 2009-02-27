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
#include <string.h>


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
            : Array<Type> ()
        {}


		/** Constructor. */
		ArrayPrimitiveType(int flags)
			: Array<Type> (flags)
		{}

		/** Constructor. */
        ArrayPrimitiveType ( Type* data, size_t capacity )
            : Array<Type> ( data, capacity )
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
		void allocMemory ( size_t capacity, int flags = Array<Type>::DEFAULT_ALLOC_FLAGS )
        {
			if ( capacity == 0 )
				Array<Type>::setData ( 0, 0, 0 );
			else
				setData ( ( Type* ) ( malloc ( capacity * sizeof (Type) ) ), 0, capacity );
			Array<Type>::mFlags |= flags;
        }

		/** Releases the memory that has been allocated by allocateMemory().
        Must not be called, if the memory has not been allocated by allocateMemory().*/
		void releaseMemory ()
        {
			free ( Array<Type>::mData );
			Array<Type>::setData ( 0, 0, 0 );
        }

        /**
        * Increases the capacity of the array, if necessary, to ensure that it can hold at least
        * the number of elements specified by the minimum capacity argument.
        * @param minCapacity the desired minimum capacity
        */
        void reallocMemory ( size_t minCapacity )
        {
			if ( minCapacity <= Array<Type>::mCapacity)
				return;
            size_t newCapacity = ( Array<Type>::mCapacity * 3 ) / 2 + 1;
            if (newCapacity < minCapacity)
                newCapacity = minCapacity;
            Array<Type>::mCapacity = newCapacity;

			if ( Array<Type>::mData )
			{
				Array<Type>::mData = ( Type* ) realloc ( Array<Type>::mData, Array<Type>::mCapacity * sizeof ( Type ) );
				if ( Array<Type>::mCount > Array<Type>::mCapacity )
					Array<Type>::mCount = Array<Type>::mCapacity;
			}
			else
			{
				allocMemory(newCapacity, Array<Type>::mFlags);
			}
        }

		/** Appends @a newValue to the end of array. If not enough memory was allocated, a resize
        of the array will be done! */
		Type& append ( const Type& newValue )
        {
            if ( Array<Type>::mCount >= Array<Type>::mCapacity )
				reallocMemory (Array<Type>::mCount + 1);

            return Array<Type>::mData [ Array<Type>::mCount++ ] = newValue;
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
			reallocMemory ( Array<Type>::mCount + length );

			memcpy ( Array<Type>::mData + Array<Type>::mCount, data, length * sizeof (Type) );
			Array<Type>::mCount += length;

			return this;
		}

		/** Erases the last n elements of the array. It does nothing but changing the mCount member.*/
		void erase(size_t n)
		{
			Array<Type>::mCount =  n > Array<Type>::mCount ? 0 : (Array<Type>::mCount - n);
		}


		/** Disable default copy ctor. */
		ArrayPrimitiveType ( const Array<Type>& pre );

	};


} // namespace COLLADAFW

#endif // __COLLADAFW_ARRAYPRIMITIVETYPE_H__
