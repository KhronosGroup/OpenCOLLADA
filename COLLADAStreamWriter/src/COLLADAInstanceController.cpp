/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADAInstanceController.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void InstanceController::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_CONTROLLER );
        mSW->appendURLAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mUrl );

        if ( !mSkeletonId.empty() )
        {
            mSW->openElement( CSWC::COLLADA_ELEMENT_SKELETON );
            if ( mSkeletonId[0] != '#' ) 
                mSW->appendText( "#" + mSkeletonId );
            else 
                mSW->appendValues( mSkeletonId );
            mSW->closeElement();
        }

        mBindMaterial.add();

        mSW->closeElement();
    }



} //namespace COLLADA
