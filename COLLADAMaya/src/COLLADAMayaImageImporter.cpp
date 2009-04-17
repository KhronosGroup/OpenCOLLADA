/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaImageImporter.h"
#include "COLLADAMayaMaterialImporter.h"


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
        // Check if the image is already imported.
        const COLLADAFW::UniqueId& imageId = image->getUniqueId ();
        if ( findMayaImageFile ( imageId ) != 0 ) return;

        // Create a unique name.
        String imageName = image->getName ();
        if ( COLLADABU::Utils::equals ( imageName, "" ) ) 
            imageName = IMAGE_NAME;
        imageName = DocumentImporter::frameworkNameToMayaName ( imageName );
        imageName = mImageIdList.addId ( imageName );

        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the image uri
        const COLLADABU::URI& imageURI = image->getImageURI ();
        String fileTextureName = imageURI.toNativePath ();
        COLLADABU::Utils::stringFindAndReplace ( fileTextureName, "\\", "/" );
        
        //createNode file -name "file1";
        //    setAttr ".fileTextureName" -type "string" "./tex/checkerRGB.jpg";
        MayaDM::File mayaImage ( file, imageName );
        mayaImage.setFileTextureName ( fileTextureName );
        
        // Push the maya image file in the map to the unique image id.
        mImageIdMayaImageFileMap [ imageId ] = mayaImage;

        // TODO Create a texture placement for every image.

    }

    //------------------------------
    const MayaDM::File* ImageImporter::findMayaImageFile ( const COLLADAFW::UniqueId& imageId )
    {
        UniqueIdMayaImagesMap::const_iterator it = mImageIdMayaImageFileMap.find ( imageId );
        if ( it != mImageIdMayaImageFileMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

} // namespace COLLADAMaya
