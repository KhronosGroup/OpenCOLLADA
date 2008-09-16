/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADATechniqueFX.h"
#include "COLLADASWC.h"
#include "assert.h"

namespace COLLADA
{

    // ---------------------------------
    TechniqueFX::TechniqueFX( StreamWriter *sw, const String &sid, const String &id /*= "" */ ) 
        : ElementWriter ( sw )
//         , Annotation ()
//         , Include ()
//         , Code ()
        , mSidNC ( sid )
        , mId ( id )
    {

    }

    // ---------------------------------
    void TechniqueFX::openTechniqueFX ( const String &sidNC, const String id /*= "" */ )
    {
        mSW->openElement ( CSWC::COLLADA_ELEMENT_TECHNIQUE );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, id );

        mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_SID, sidNC );
    }

    // ---------------------------------
    void TechniqueFX::closeTechniqueFX()
    {
        mSW->closeElement();
    }

}