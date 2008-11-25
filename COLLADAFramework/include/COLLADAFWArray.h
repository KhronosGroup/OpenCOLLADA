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

	private:
		/** The data C-array.*/
		DataType* mData;

		/** The number of elements in the array.*/
		size_t mCount;

		/** Returns the number of elements in the array.*/
		size_t getCount() const { return mCount; }

		/** Returns the C-style data array.*/
		DataType* getData() { return mData; }

		/** Returns the C-style data array.*/
		const DataType* getData() const { return mData; }

		/** Return s the index'th element in the array. No check is performed, if the index is out of bounds.*/
		DataType& operator[](size_t index) { return mData[index]; }

		/** Return s the index'th element in the array. No check is performed, if the index is out of bounds.*/
		const DataType& operator[](size_t index) const { return mData[index]; }

	public:
		Array() : mData(0), mCount(0) {}
		Array(DataType* data, size_t count) : mData(data), mCount(count){}

		virtual ~Array();

	private:
        /** Disable default copy ctor. */
		Array( const Array& pre );
        /** Disable default assignment operator. */
		const Array& operator= ( const Array& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_ARRAY_H__
