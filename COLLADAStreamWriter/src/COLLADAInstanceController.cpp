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
        mSW->appendURIAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mUrl );

		for ( SkeletonUrlList::const_iterator it = mSkeletonUrlList.begin(); it!=mSkeletonUrlList.end(); ++it)
			mSW->appendTextElement(CSWC::COLLADA_ELEMENT_SKELETON, it->getURIString());

        mBindMaterial.add();

        mSW->closeElement();
    }



} //namespace COLLADA
