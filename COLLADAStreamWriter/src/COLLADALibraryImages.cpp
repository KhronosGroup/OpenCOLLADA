/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    Image::Image ( const String& fileName, const String& imageId, const String& imageName )
            : BaseExtraTechnique(), mFileName ( fileName ),
            mImageId ( imageId ),
            mImageName ( imageName )
    {}


    //---------------------------------------------------------------
    LibraryImages::LibraryImages ( COLLADA::StreamWriter* streamWriter )
            : Library ( streamWriter,CSWC::COLLADA_ELEMENT_LIBRARY_IMAGES )
    {}


    //---------------------------------------------------------------
    void LibraryImages::addImage ( const Image& image )
    {
        openLibrary();
        mSW->openElement ( CSWC::COLLADA_ELEMENT_IMAGE );

        if ( !image.getImageId().empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, image.getImageId() );

        if ( !image.getImageName().empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, image.getImageName() );

        mSW->appendTextElement ( CSWC::COLLADA_ELEMENT_INIT_FROM, image.getFileName() );

        image.addTextureExtraTechniques ( *mSW );

        mSW->closeElement();
    }


} //namespace COLLADA
