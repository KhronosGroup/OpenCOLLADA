/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASource.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    void SourceBase::prepareBaseToAppendValues ( const String *arrayName )
    {
        mSourceCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_SOURCE );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mNodeId );
        if ( !mNodeName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, mNodeName );
        mSW->openElement ( *arrayName );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mArrayId );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mAccessorCount * mAccessorStride );
    }

    //---------------------------------------------------------------
    void SourceBase::finishBase ( const String* parameterTypeName, bool closeSourceElement )
    {
        closeArray();

        addBaseTechnique ( parameterTypeName );

        if ( closeSourceElement ) closeSource();
    }

    //---------------------------------------------------------------
    void SourceBase::closeArray()
    {
        mSW->closeElement();
    }

    //---------------------------------------------------------------
    void SourceBase::closeSource()
    {
        mSourceCloser.close();
    }

    //---------------------------------------------------------------
    void SourceBase::addBaseTechnique ( const String* parameterTypeName )
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );
        mSW->openElement ( CSWC::COLLADA_ELEMENT_ACCESSOR );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SOURCE, "#" + mArrayId );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mAccessorCount );
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_STRIDE, mAccessorStride );

        for ( ParameterNameList::iterator it = mParameterNameList.begin(); it != mParameterNameList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_PARAM );
			if ( !it->empty() )
				mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, *it );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, *parameterTypeName );
            mSW->closeElement();
        }

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
