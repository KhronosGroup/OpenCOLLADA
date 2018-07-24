
#ifndef __COLLADAFW_INTARRAY_H__
#define __COLLADAFW_INTARRAY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTypes.h"
#include "COLLADAFWAnimatable.h"
#include "COLLADAFWFloatDoubleOrIntType.h"


namespace COLLADAFW
{
	/** Holds a integer array. */
	class IntArray : public Animatable
	{
	private:
		/** The data type of the stored position values. */
		// DataType mType;
		FloatDoubleOrIntArray::DataType mType;

		/** The position values. */
        IntValuesArray mValuesI;

	public:

		/** Constructor. */
		IntArray();

		IntArray(FloatDoubleOrIntArray::DataType type);

		/** Default copy ctor. */
		IntArray( const IntArray& pre );

		/** The data type of the stored values. */
		FloatDoubleOrIntArray::DataType getType() const { return mType; }

		/** The data type of the stored values. */
		void setType( FloatDoubleOrIntArray::DataType Type ) { mType = Type; }

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
            if( mType == FloatDoubleOrIntArray::DataType::DATA_TYPE_INT ) return mValuesI; 
			return 0;
		}

		/** Returns the values array as a int array. */
        const IntValuesArray* getIntValues() const;

        IntValuesArray* getIntValues();
        
		/** Set the C-style data array.*/
		void setData( int* data, const size_t count );


		/** Appends the values of the input array to the end of values array.
		The programmer must ensure, that the memory allocated,
		was large enough to hold another element. No new memory is allocated.*/
		bool appendValues( const IntValuesArray& valuesArray );

		/** Destructor. */
		virtual ~IntArray();

	private:


		/** Disable default assignment operator. */
		const IntValuesArray& operator= ( const IntValuesArray& pre );
	};

} // namespace COLLADAFW

#endif // __COLLADAFW_INTARRAY_H__
