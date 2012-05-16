/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstanceController.h"


namespace COLLADASW
{

    //---------------------------------------------------------------
    void InstanceController::add()
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_CONTROLLER );
        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mUrl );

		for ( SkeletonUrlList::const_iterator it = mSkeletonUrlList.begin(); it!=mSkeletonUrlList.end(); ++it)
			mSW->appendTextElement(CSWC::CSW_ELEMENT_SKELETON, it->getURIString());

        mBindMaterial.add();

        mSW->closeElement();
    }



} //namespace COLLADASW
