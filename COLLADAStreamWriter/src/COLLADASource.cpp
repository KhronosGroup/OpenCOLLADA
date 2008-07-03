/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mId );
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
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, *it );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, *parameterTypeName );
            mSW->closeElement();
        }

        mSW->closeElement();

        mSW->closeElement();
    }


} //namespace COLLADA
