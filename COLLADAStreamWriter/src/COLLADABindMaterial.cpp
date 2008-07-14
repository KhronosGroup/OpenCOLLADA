/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADABindMaterial.h"
#include "COLLADAInstanceMaterial.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    void BindMaterial::add()
    {
        if ( !mInstanceMaterialList.empty() )
        {
            mBindMaterialCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_BIND_MATERIAL );
            mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON );

            mInstanceMaterialList.add();

            mBindMaterialCloser.close();
        }
    }


} //namespace COLLADA
