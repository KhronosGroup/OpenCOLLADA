/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLSourceArrayLoader.h"
#include "COLLADAFWTypes.h"

namespace COLLADASaxFWL
{

#ifdef COLLADASAXFWL_REAL_IS_FLOAT
	const COLLADAFW::FloatOrDoubleArray::DataType SourceArrayLoader::DATA_TYPE_REAL = COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT;
#else
	const COLLADAFW::FloatOrDoubleArray::DataType SourceArrayLoader::DATA_TYPE_REAL = COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE;
#endif


	//------------------------------
	SourceArrayLoader::SourceArrayLoader(IFilePartLoader* callingFilePartLoader)
		:FilePartLoader(callingFilePartLoader),
		 mSourceArray( SourceArray::OWNER ),
		 mCurrentSoure(0)
	{
	}

	//------------------------------
	SourceArrayLoader::~SourceArrayLoader()
	{
		clearSources();
	}

	/** Copies the values contained in @a realSource into @a realsArray .*/
	//------------------------------
	void SourceArrayLoader::setRealValues( COLLADAFW::FloatOrDoubleArray& realsArray, const RealSource* realSource )
	{
		if ( !realsArray.empty() )
		{
			// There already must have been an input with semantic INPUT. We ignore all following.
			return;
		}
		realsArray.setType( SourceArrayLoader::DATA_TYPE_REAL );
		const RealArrayElement& realArrayElement = realSource->getArrayElement();
		realsArray.appendValues(realArrayElement.getValues());
	}


	//------------------------------
	void SourceArrayLoader::clearSources()
	{
		for ( size_t i = 0, count = mSourceArray.getCount(); i < count; ++i)
			delete mSourceArray[i];
		mSourceArray.setCount(0);
	}

	//------------------------------
	bool SourceArrayLoader::assignSourceValuesToFloatOrDoubleArray( SourceBase* sourceBase, COLLADAFW::FloatOrDoubleArray& floatOrDoubleArray )
	{
		if (sourceBase->getDataType() == SourceBase::DATA_TYPE_FLOAT)
		{
			floatOrDoubleArray.setType( COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT);
			COLLADAFW::FloatArray* values = floatOrDoubleArray.getFloatValues();
			FloatSource* source = ( FloatSource* ) sourceBase;
			FloatArrayElement& arrayElement = source->getArrayElement();
			COLLADAFW::FloatArray& valuesArray = arrayElement.getValues();
			values->setData ( valuesArray.getData (), valuesArray.getCount () );
			valuesArray.yieldOwnerShip();
			return true;
		}
		else if (sourceBase->getDataType() == SourceBase::DATA_TYPE_DOUBLE)
		{
			floatOrDoubleArray.setType( COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE);
			COLLADAFW::DoubleArray* values = floatOrDoubleArray.getDoubleValues();
			DoubleSource* source = ( DoubleSource* ) sourceBase;
			DoubleArrayElement& arrayElement = source->getArrayElement();
			COLLADAFW::DoubleArray& valuesArray = arrayElement.getValues();
			values->setData ( valuesArray.getData (), valuesArray.getCount () );
			valuesArray.yieldOwnerShip();
			return true;
		}
		else
		{
			return false;
		}
	}

	//------------------------------
	COLLADAFW::String SourceArrayLoader::getIdFromURIFragmentType( const char* uriFragment )
	{
		if ( !uriFragment )
			return "";

		const char* startPos = uriFragment;
		while ( *startPos && GeneratedSaxParser::Utils::isWhiteSpace(*startPos))
			startPos++;

		// skip leading '#' if present. (the uriFragment would be invalid if there is no '#', but we are tolerant)
		if ( *startPos == '#' )
			startPos++;

		const char* endPos = startPos;
		while ( *endPos && !GeneratedSaxParser::Utils::isWhiteSpace(*endPos) )
			endPos++;

		return String(startPos, endPos - startPos);
	}

    //------------------------------
    const SourceArray& SourceArrayLoader::getSourceArray () const
    {
        return mSourceArray;
    }

    //------------------------------
    void SourceArrayLoader::setSourceArray ( const SourceArray& sourceArray )
    {
        mSourceArray = sourceArray;
    }

    //------------------------------
    const SourceBase* SourceArrayLoader::getSourceById ( const String& sourceId ) const
    {
        for ( size_t i=0; i<mSourceArray.getCount (); ++i )
        {
            const SourceBase* source = mSourceArray [ i ];
            if ( COLLADABU::Utils::equals ( source->getId (), sourceId ) )
                return source;
        }
        return 0;
    }

    //------------------------------
    SourceBase* SourceArrayLoader::getSourceById ( const String& sourceId ) 
    {
        for ( size_t i=0; i<mSourceArray.getCount (); ++i )
        {
            SourceBase* source = mSourceArray [ i ];
            if ( COLLADABU::Utils::equals ( source->getId (), sourceId ) )
                return source;
        }
        return 0;
    }

	//------------------------------
	bool SourceArrayLoader::beginSource( const source__AttributeData& attributes )
	{
		if ( attributes.id )
			mCurrentSourceId = attributes.id;
		return true;
	}


	//------------------------------
	bool SourceArrayLoader::endSource( )
	{
		if ( mCurrentSoure )
		{
			mSourceArray.append(mCurrentSoure);
		}
		mCurrentSoure = 0;
		mCurrentSourceId.clear();
		mCurrentArrayId.clear();
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::begin__float_array( const float_array__AttributeData& attributeData )
	{
		return beginArray<FloatSource>( attributeData.count, attributeData.id ) != 0;
	}

	//------------------------------
	bool SourceArrayLoader::end__float_array()
	{
		// we don't need to do anything here
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::data__float_array( const float* data, size_t length )
	{
		FloatSource* source = (FloatSource*)mCurrentSoure;
		COLLADAFW::FloatArray& array  = source->getArrayElement().getValues();
		array.appendValues(data, length);
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::begin__animation__source__technique_common()
	{
		//we don't need to do anything here
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::end__animation__source__technique_common()
	{
		//we don't need to do anything here
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::begin__accessor( const accessor__AttributeData& attributeData )
	{
		// As soon as we support all array types, remove this check
		if ( mCurrentSoure )
			mCurrentSoure->setStride((int)attributeData.stride);
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::end__accessor()
	{
		//we don't need to do anything here
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::begin__param( const param__AttributeData& attributeData )
	{
		if ( mCurrentSoure )
		{
			SourceBase::AccessorParameter accessorParameter;
			if ( attributeData.name && *attributeData.name )
			{
				accessorParameter.name = attributeData.name;
			}

			// the type is required. We don't need to check
			accessorParameter.type = attributeData.type;
			mCurrentSoure->appendAccessorParameter( accessorParameter );
		}
		return true;
	}


} // namespace COLLADAFW
