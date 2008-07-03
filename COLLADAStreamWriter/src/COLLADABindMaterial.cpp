/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADABindMaterial.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    void InstanceMaterialList::add()
    {
        for ( List::iterator it = mList.begin(); it != mList.end(); ++it )
        {
            mSW->openElement ( CSWC::COLLADA_ELEMENT_INSTANCE_MATERIAL );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SYMBOL, it->getSymbol() );
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TARGET, it->getTarget() );
            mSW->closeElement();
        }
    }

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
