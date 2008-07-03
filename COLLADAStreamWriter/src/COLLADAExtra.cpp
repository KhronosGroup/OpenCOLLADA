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

#include "COLLADAExtra.h"
#include "COLLADASWC.h"

namespace COLLADA
{
    //---------------------------------------------------------------
    void Extra::openExtra ( const String &extraId, const String &extraName, const String &extraType )
    {
        mExtraCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_EXTRA );

        if ( !extraId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, extraId );

        if ( !extraName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, extraName );

        if ( !extraType.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_TYPE, extraType );
    }

    //---------------------------------------------------------------
    void Extra::closeExtra()
    {
        mExtraCloser.close();
    }

} //namespace COLLADA
