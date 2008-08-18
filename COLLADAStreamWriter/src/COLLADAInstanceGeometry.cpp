/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAInstanceGeometry.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void InstanceGeometry::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_GEOMETRY );
        mSW->appendURIAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mUrl );

        mBindMaterial.add();

        mSW->closeElement();
    }



} //namespace COLLADA
