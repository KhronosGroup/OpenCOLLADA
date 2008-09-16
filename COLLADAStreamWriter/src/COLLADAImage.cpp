/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAImage.h"
#include "COLLADASWC.h"

namespace COLLADA
{

    //--------------------------------------
    Image::Image ( const URI& fileName, const String& imageId, const String& imageName )
        : BaseExtraTechnique(), mFileURI ( fileName )
        , mId ( imageId )
        , mNameNC ( imageName )
        , mDepth ( 1 )
        , mHeight ( -1 )
        , mWeight ( -1 )
        , mData ( "" )
    {}


    //---------------------------------------------------------------
    void Image::add ( StreamWriter* sw ) const
    {
        sw->openElement ( CSWC::COLLADA_ELEMENT_IMAGE );

        if ( !mId.empty() )
            sw->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, mId );

        if ( !mNameNC.empty() )
            sw->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, mNameNC );

        if ( !mData.empty() )
            sw->appendTextElement ( CSWC::COLLADA_ELEMENT_DATA, mData );
        else
            sw->appendURIElement( CSWC::COLLADA_ELEMENT_INIT_FROM, mFileURI );

        addExtraTechniques ( sw );

        sw->closeElement();
    }


}