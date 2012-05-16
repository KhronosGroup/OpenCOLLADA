/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstanceCamera.h"
#include "COLLADASWConstants.h"


namespace COLLADASW
{

    //---------------------------------------------------------------
    void InstanceCamera::add()
    {
        mSW->openElement ( CSWC::CSW_ELEMENT_INSTANCE_CAMERA );
        mSW->appendURIAttribute ( CSWC::CSW_ATTRIBUTE_URL, mUrl );
        mSW->closeElement();
    }



} //namespace COLLADASW
