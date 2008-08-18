/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAInstanceCamera.h"
#include "COLLADASWC.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void InstanceCamera::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_CAMERA );
        mSW->appendURIAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mUrl );
        mSW->closeElement();
    }



} //namespace COLLADA
