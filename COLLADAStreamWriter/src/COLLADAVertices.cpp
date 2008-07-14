/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADAVertices.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void Vertices::add()
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_VERTICES );

        if ( !mNodeId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mNodeId );

        if ( !mNodeName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, mNodeName );

        mInputList.add();

        mSW->closeElement();
    }

} //namespace COLLADA
