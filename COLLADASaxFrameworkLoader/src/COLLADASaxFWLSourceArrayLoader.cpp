/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		for ( size_t i = 0, count = mSourceArray.getCount(); i < count; ++i)
			delete mSourceArray[i];
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
	bool SourceArrayLoader::beginSource( const animation__source__AttributeData& attributes )
	{
		if ( attributes.id )
			mCurrentSourceId = (const char*)attributes.id;
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
		SaxVirtualFunctionTest(begin__float_array(attributeData));
		FloatSource* newSource = new FloatSource();
		newSource->getArrayElement().getValues().allocMemory((size_t)attributeData.count);
		newSource->setId(mCurrentSourceId);
		mCurrentSoure = newSource;
		if ( attributeData.id )
			mCurrentArrayId = (const char*)attributeData.id;
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::end__float_array()
	{
		// we don't need to do anything here
		SaxVirtualFunctionTest(end__float_array());	
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::data__float_array( const float* data, size_t length )
	{
		SaxVirtualFunctionTest(data__float_array(data, length));
		FloatSource* source = (FloatSource*)mCurrentSoure;
		COLLADAFW::FloatArray& array  = source->getArrayElement().getValues();
		array.appendValues(data, length);
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::begin__animation__source__technique_common()
	{
		//we don't need to do anything here
		SaxVirtualFunctionTest(begin__animation__source__technique_common());
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::end__animation__source__technique_common()
	{
		//we don't need to do anything here
		SaxVirtualFunctionTest(end__animation__source__technique_common());
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::begin__accessor( const accessor__AttributeData& attributeData )
	{
		SaxVirtualFunctionTest(begin__accessor(attributeData));
		// As soon as we support all array types, remove this check
		if ( mCurrentSoure )
			mCurrentSoure->setStride((int)attributeData.stride);
		return true;
	}

	//------------------------------
	bool SourceArrayLoader::end__accessor()
	{
		//we don't need to do anything here
		SaxVirtualFunctionTest(end__accessor());
		return true;
	}

} // namespace COLLADAFW
