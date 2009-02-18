/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaImageImporter.h"


namespace COLLADAMaya
{

    const String ImageImporter::IMAGE_NAME = "Image";


    //------------------------------
	ImageImporter::ImageImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	ImageImporter::~ImageImporter()
	{
	}

    //------------------------------
    void ImageImporter::importImage ( const COLLADAFW::Image* image )
    {
        // Check if the light is already imported.
        const COLLADAFW::UniqueId& imageId = image->getUniqueId ();
//        if ( findMayaLightNode ( imageId ) != 0 ) return;

        // Create a unique name.
        String imageName = image->getName ();
        if ( COLLADABU::Utils::equals ( imageName, "" ) ) 
            imageName = IMAGE_NAME;
        imageName = mImageIdList.addId ( imageName );

        


    }
} // namespace COLLADAMaya
