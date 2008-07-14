/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_URL, mUrl );

        mBindMaterial.add();

        mSW->closeElement();
    }



} //namespace COLLADA
