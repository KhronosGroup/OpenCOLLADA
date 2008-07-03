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

#include "COLLADAPrimitves.h"

namespace COLLADA
{
    //---------------------------------------------------------------
    void PrimitivesBase::prepareBaseToAppendValues ( const String * primitiveName, bool openPolylistElement )
    {
        mPrimitiveCloser = mSW->openElement ( *primitiveName );

        if ( !mMaterial.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_MATERIAL, mMaterial );

        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_COUNT, mCount );

        mInputList.add();

        // write <vcount>
        if ( !mVCountList.empty() )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_VCOUNT );

            for ( VCountList::iterator it = mVCountList.begin(); it != mVCountList.end(); ++it )
                mSW->appendValues ( *it );

            mSW->closeElement();
        }

        if ( openPolylistElement )
            mSW->openElement ( CSWC::COLLADA_ELEMENT_P );
    }


    //---------------------------------------------------------------
    void PrimitivesBase::finish()
    {
        mPrimitiveCloser.close();
    }



} //namespace COLLADA

