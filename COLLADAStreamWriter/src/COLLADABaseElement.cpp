/*
    Copyright (c) 2008 NetAllied Systems GmbH

    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADABaseElement.h"
#include "COLLADASWC.h"


namespace COLLADA
{

    //---------------------------------------------------------------
    void BaseElement::add()
    {
        mSW->openElement ( mElementName );

        if ( !mNodeId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mNodeId );

        if ( !mNodeName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, mNodeName );

        mSW->closeElement();
    }

} //namespace COLLADA
