/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWImage.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
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
        sw->openElement ( CSWC::CSW_ELEMENT_IMAGE );

        if ( !mId.empty() )
            sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, mId );

        if ( !mNameNC.empty() )
            sw->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, mNameNC );

		if ( sw->getCOLLADAVersion() == StreamWriter::COLLADA_1_4_1 )
		{
			if ( !mData.empty() )
				sw->appendTextElement ( CSWC::CSW_ELEMENT_DATA, mData );
			else
				sw->appendURIElement( CSWC::CSW_ELEMENT_INIT_FROM, mFileURI );
		}
		else if ( sw->getCOLLADAVersion() == StreamWriter::COLLADA_1_5_0 )
		{
//			sw->openElement ( CSWC::CSW_ELEMENT_CREATE_2D);

			if ( !mFormat.empty() )
			{
				sw->appendTextElement ( CSWC::CSW_ELEMENT_FORMAT, mFormat);
			}
			sw->openElement ( CSWC::CSW_ELEMENT_INIT_FROM);

			sw->appendURIElement( CSWC::CSW_ELEMENT_REF, mFileURI );

			sw->closeElement(); // CSW_ELEMENT_INIT_FROM

//			sw->closeElement(); // CSW_ELEMENT_CREATE_2D
		}
		else
		{
			COLLADABU_ASSERT(false);
		}

        addExtraTechniques ( sw );

        sw->closeElement();
    }


}
