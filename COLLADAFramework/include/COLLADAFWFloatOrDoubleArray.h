/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_FLOATORDOUBLEARRAY_H__
#define __COLLADAFW_FLOATORDOUBLEARRAY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWAnimatable.h"


namespace COLLADAFW
{

	/** Holds either a float or a double array */
	class FloatOrDoubleArray : public Animatable
	{
	public:
		/** Values can be stored as float or double values. */
		enum DataType
		{
			DATA_TYPE_FLOAT = 0,
			DATA_TYPE_DOUBLE = 1,
			DATA_TYPE_UNKNOWN = 2,
		};



	private:
		/** The data type of the stored position values. */
		DataType mType;

		/** The position values. */
		FloatArray mValuesF;
		DoubleArray mValuesD;

	public:

		/** Constructor. */
		FloatOrDoubleArray();

		FloatOrDoubleArray(DataType type);

		/** Default copy ctor. */
		FloatOrDoubleArray( const FloatOrDoubleArray& pre );

		/** The data type of the stored values. */
		DataType getType() const { return mType; }

		/** The data type of the stored values. */
		void setType( DataType Type ) { mType = Type; }

		/** Returns the count of stored elements in the array. For DATA_TYPE_UNKNOWN 0 is returned.*/
		size_t getValuesCount() const;

		/** Returns if the array is empty. If type is DATA_TYPE_UNKNOWN, true is returned. Otherwise the array 
		of the set type is checked.*/
		bool empty() const { return getValuesCount() == 0; }

		/** Clears the values in the set number array. The data type remains unchanged.*/
		void clear();

		/** Returns the values array as a template array. */
		template <class T>
		ArrayPrimitiveType<T>& getValues()
		{
			if( mType == DATA_TYPE_FLOAT ) return mValuesF;
			if( mType == DATA_TYPE_DOUBLE ) return mValuesD;
			return 0;
		}

		/** Returns the values array as a float array. */
		const FloatArray* getFloatValues() const;

		/** Returns the values array as a double array. */
		const DoubleArray* getDoubleValues() const;

		/** Returns the values array as a float array. */
		FloatArray* getFloatValues();

		/** Returns the values array as a double array. */
		DoubleArray* getDoubleValues();


		/** Set the C-style data array.*/
		void setData( float* data, const size_t count );

		/** Set the C-style data array.*/
		void setData( double* data, const size_t count );

		/** Appends the values of the input array to the end of values array.
		The programmer must ensure, that the memory allocated,
		was large enough to hold another element. No new memory is allocated.*/
		bool appendValues( const FloatArray& valuesArray );

		/** Appends the values of the input array to the end of values array.
		The programmer must ensure, that the memory allocated,
		was large enough to hold another element. No new memory is allocated.*/
		bool appendValues( const DoubleArray& valuesArray );


		/** Destructor. */
		virtual ~FloatOrDoubleArray();

	private:


		/** Disable default assignment operator. */
		const FloatOrDoubleArray& operator= ( const FloatOrDoubleArray& pre );
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_FLOATORDOUBLEARRAY_H__
