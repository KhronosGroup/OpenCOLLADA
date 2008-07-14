/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
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
            mSW->appendValues ( mVCountList );
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

