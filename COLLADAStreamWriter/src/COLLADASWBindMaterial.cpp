/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWBindMaterial.h"
#include "COLLADASWInstanceMaterial.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    void BindMaterial::add()
    {
        if ( !mInstanceMaterialList.empty() )
        {
            mBindMaterialCloser = mSW->openElement ( CSWC::CSW_ELEMENT_BIND_MATERIAL );
            mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE_COMMON );

            mInstanceMaterialList.add();

            mBindMaterialCloser.close();
        }
    }


} //namespace COLLADASW
