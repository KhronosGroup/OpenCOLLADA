
#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWIntArray.h"
#include "COLLADAFWFloatOrDoubleArray.h"


namespace COLLADAFW
{

    //------------------------------
	IntArray::~IntArray()
	{
	}

	//------------------------------
	IntArray::IntArray() 
		: mType ( DFI::DataType::DATA_TYPE_UNKNOWN )
        , mValuesI(IntValuesArray::OWNER)
	{}

	//------------------------------
	IntArray::IntArray( DFI::DataType type ) 
		: mType ( type )
        , mValuesI(IntValuesArray::OWNER)
	{}

	//------------------------------
	IntArray::IntArray( const IntArray& pre )
		: Animatable( pre)
		, mType(pre.mType)
        , mValuesI(IntValuesArray::OWNER)
	{
        pre.mValuesI.cloneArray( mValuesI );
	}

	//------------------------------
	size_t IntArray::getValuesCount() const
	{
        if( mType == DFI::DataType::DATA_TYPE_INT )
        {
            return mValuesI.getCount();
        }
		return 0;
	}

	//------------------------------
	void IntArray::clear()
	{
        if( mType == DFI::DataType::DATA_TYPE_INT )
        {
            mValuesI.clear();
        }
	}

	//------------------------------
    const IntValuesArray* IntArray::getIntValues() const
    {
        if ( mType == DFI::DataType::DATA_TYPE_INT )
        {
            return ( ArrayPrimitiveType<int>* ) &mValuesI;
        }
        return 0;
    }

	//------------------------------
    IntValuesArray* IntArray::getIntValues()
    {
        if (mType == DFI::DataType::DATA_TYPE_INT )
        {
            return ( ArrayPrimitiveType<int>* ) &mValuesI;
        }
    }
	//------------------------------
	void IntArray::setData( int* data, const size_t count )
	{
		if ( mType == DFI::DataType::DATA_TYPE_INT ) 
		{
			mValuesI.setData( data, count );
		}
	}


	//------------------------------
	bool IntArray::appendValues( const IntValuesArray& valuesArray )
	{
		if ( mType == DFI::DataType::DATA_TYPE_INT )
		{
			mValuesI.appendValues( valuesArray );
			return true;
		}
		return false;
	}

} // namespace COLLADAFW
