/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POINTERARRAY_H__
#define __COLLADAFW_POINTERARRAY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayPrimitiveType.h"


namespace COLLADAFW
{

	/**
	This array stores pointers to objects of type @T
	The memory will be allocated with malloc, freed with free and resized with realloc.
	In contrast to the base template ArrayPrimitiveType it provides a copy constructor and
	an assignment operator. Type T must have public copy constructor and assignment operator.
	It must also implement a public member T* clone() that clones the object.
	The array is always the owner the pointers.
	*/
	template<class T>
	class PointerArray 	: public ArrayPrimitiveType<T*>
	{
	private:

	public:

        /** Constructor. */
		PointerArray() : ArrayPrimitiveType<T*>(ArrayPrimitiveType<T*>::OWNER){}

        /** Destructor. */
		virtual ~PointerArray()
		{
			deleteContents();
		}

        /** Disable default copy ctor. */
		PointerArray( const PointerArray& pre )
			: ArrayPrimitiveType<T*>(ArrayPrimitiveType<T*>::OWNER)
		{
			// clone the array contents
			cloneContents(pre);
		}

		/** Clones the values in @a valuesArray and appends the pointers.*/
		void appendValues( const PointerArray<T>& valuesArray )
		{
			size_t newCount = ArrayPrimitiveType<T*>::mCount + valuesArray.getCount();
			ArrayPrimitiveType<T*>::reallocMemory(newCount);
			for ( size_t i = ArrayPrimitiveType<T*>::mCount, j = 0; i < newCount; ++i, ++j)
			{
				(*this)[i] = valuesArray[j]->clone();
			}
			ArrayPrimitiveType<T*>::mCount = newCount;
		}

        /** Disable default assignment operator. */
		const PointerArray& operator=( const PointerArray& pre )
		{
			if ( &pre != this )
			{
				// delete the old arrays contents
				deleteContents();
				// clone the array contents
				cloneContents(pre);
			}
			return *this;
		}

	private:
		/** Clones the contents of @a pre and stores the pointers to the objects in this array.*/
		void cloneContents(const PointerArray& pre)
		{
			size_t newCount = pre.getCount();
			ArrayPrimitiveType<T*>::reallocMemory(newCount);
			for ( size_t i = 0; i < newCount; ++i)
			{
				(*this)[i] = pre[i]->clone();
			}
			ArrayPrimitiveType<T*>::mCount = newCount;
		}

		/** Deletes the contents of this array.*/
		void deleteContents()
		{
			size_t oldCount = ArrayPrimitiveType<T*>::getCount();
			for ( size_t i = 0; i < oldCount; ++i)
				delete (*this)[i];
		}


	};

} // namespace COLLADAFW

#endif // __COLLADAFW_POINTERARRAY_H__
