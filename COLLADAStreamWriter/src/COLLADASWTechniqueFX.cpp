/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASWTechniqueFX.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
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
        mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, id );

        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_SID, sidNC );
    }

    // ---------------------------------
    void TechniqueFX::closeTechniqueFX()
    {
        mSW->closeElement();
    }

}
