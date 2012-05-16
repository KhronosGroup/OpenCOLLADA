/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWFloatOrDoubleArray.h"


namespace COLLADAFW
{

    //------------------------------
	FloatOrDoubleArray::~FloatOrDoubleArray()
	{
	}

	//------------------------------
	FloatOrDoubleArray::FloatOrDoubleArray() 
		: mType ( DATA_TYPE_UNKNOWN )
		, mValuesF(FloatArray::OWNER)
		, mValuesD(DoubleArray::OWNER)
	{}

	//------------------------------
	FloatOrDoubleArray::FloatOrDoubleArray( DataType type ) 
		: mType ( type )
		, mValuesF(FloatArray::OWNER)
		, mValuesD(DoubleArray::OWNER)
	{}

	//------------------------------
	FloatOrDoubleArray::FloatOrDoubleArray( const FloatOrDoubleArray& pre )
		: Animatable( pre)
		, mType(pre.mType)
		, mValuesF(FloatArray::OWNER)
		, mValuesD(DoubleArray::OWNER)
	{
		if ( mType == DATA_TYPE_FLOAT )
		{
			pre.mValuesF.cloneArray( mValuesF );
		}
		else if ( mType == DATA_TYPE_DOUBLE )
		{
			pre.mValuesD.cloneArray( mValuesD );
		}
	}

	//------------------------------
	size_t FloatOrDoubleArray::getValuesCount() const
	{
		if ( mType == DATA_TYPE_FLOAT )
		{
			return mValuesF.getCount();
		}
		if ( mType == DATA_TYPE_DOUBLE ) 
		{
			return mValuesD.getCount();
		}
		return 0;
	}

	//------------------------------
	void FloatOrDoubleArray::clear()
	{
		if( mType == DATA_TYPE_FLOAT )
		{
			mValuesF.clear();
		}
		if( mType == DATA_TYPE_DOUBLE )
		{
			mValuesD.clear();
		}
	}

	//------------------------------
	const FloatArray* FloatOrDoubleArray::getFloatValues() const
	{
		if ( mType == DATA_TYPE_FLOAT )
		{
			return ( ArrayPrimitiveType<float>* ) &mValuesF;
		}
		return 0;
	}

	//------------------------------
	FloatArray* FloatOrDoubleArray::getFloatValues()
	{
		if ( mType == DATA_TYPE_FLOAT )
		{
			return ( ArrayPrimitiveType<float>* ) &mValuesF;
		}
		return 0;
	}

	//------------------------------
	const DoubleArray* FloatOrDoubleArray::getDoubleValues() const
	{
		if ( mType == DATA_TYPE_DOUBLE )
		{
			return ( ArrayPrimitiveType<double>* ) &mValuesD;
		}
		return 0;
	}

	//------------------------------
	DoubleArray* FloatOrDoubleArray::getDoubleValues()
	{
		if ( mType == DATA_TYPE_DOUBLE )
		{
			return ( ArrayPrimitiveType<double>* ) &mValuesD;
		}
		return 0;
	}

	//------------------------------
	void FloatOrDoubleArray::setData( float* data, const size_t count )
	{
		if ( mType == DATA_TYPE_FLOAT ) 
		{
			mValuesF.setData( data, count );
		}
	}

	//------------------------------
	void FloatOrDoubleArray::setData( double* data, const size_t count )
	{
		if ( mType == DATA_TYPE_DOUBLE ) 
		{
			mValuesD.setData( data, count );
		}
	}

	//------------------------------
	bool FloatOrDoubleArray::appendValues( const FloatArray& valuesArray )
	{
		if ( mType == DATA_TYPE_FLOAT )
		{
			mValuesF.appendValues( valuesArray );
			return true;
		}
		return false;
	}

	//------------------------------
	bool FloatOrDoubleArray::appendValues( const DoubleArray& valuesArray )
	{
		if ( mType == DATA_TYPE_DOUBLE )
		{
			mValuesD.appendValues( valuesArray );
			return true;
		}
		return false;
	}

} // namespace COLLADAFW
