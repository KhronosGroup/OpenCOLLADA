/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaImageImporter.h"

#include <MayaDMPlace2dTexture.h>
#include <MayaDMDefaultTextureList.h>


namespace COLLADAMaya
{

    const String ImageImporter::IMAGE_NAME = "Image";
    const String ImageImporter::PLACE_2D_TEXTURE_NAME = "place2dTexture";
    const String ImageImporter::DEFAULT_TEXTURE_LIST = ":defaultTextureList1";


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
        if ( findMayaImageFile ( imageId ) != 0 ) return;

        // Create a unique name.
        String imageName = image->getName ();
        if ( COLLADABU::Utils::equals ( imageName, "" ) ) 
            imageName = IMAGE_NAME;
        imageName = mImageIdList.addId ( imageName );

        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the image uri
        const COLLADABU::URI& imageURI = image->getImageURI ();

        //createNode file -name "file1";
        //    setAttr ".fileTextureName" -type "string" "C:/netallied/projekte/COLLADA/TestdataMaya/Themes/Textures/tex/checkerRGB.jpg";
        MayaDM::File mayaImage ( file, imageName );
        mayaImage.setFileTextureName ( imageURI.getURIString () );

        // Push the maya image file in the map to the unique image id.
        mImageIdMayaImageFileMap [ imageId ] = mayaImage;
    }

    // -----------------------------------
    const MayaDM::File* ImageImporter::findMayaImageFile ( const COLLADAFW::UniqueId& imageId )
    {
        UniqueIdMayaImagesMap::const_iterator it = mImageIdMayaImageFileMap.find ( imageId );
        if ( it == mImageIdMayaImageFileMap.end () )
        {
            return 0;
        }

        return &(it->second);
    }

    //------------------------------
    void ImageImporter::writeConnections ()
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // TODO Create this in depend on the texture mapping of effects.
        // createNode place2dTexture -n "place2dTexture1";
        String place2dTextureName = mPlace2dTextureIdList.addId ( PLACE_2D_TEXTURE_NAME );
        MayaDM::Place2dTexture place2dTexture ( file, place2dTextureName );

        //  Create the defaultTextureList object
        MayaDM::DefaultTextureList defaultTextureList ( file, DEFAULT_TEXTURE_LIST, "", false );

        size_t textureIndex = 0;

        // Get the created images.
        UniqueIdMayaImagesMap::iterator it = mImageIdMayaImageFileMap.begin ();
        while ( it != mImageIdMayaImageFileMap.end () )
        {
            const COLLADAFW::UniqueId& imageId = it->first;
            const MayaDM::File& imageFile = it->second;

            //connectAttr "file1.message" ":defaultTextureList1.textures" -nextAvailable;
            connectAttr ( file, imageFile.getMessage (), defaultTextureList.getTextures ( textureIndex ) );
            ++textureIndex;

            //connectAttr "file1.outColor" ":lambert1.color";
            // TODO Get all effects, which use this image file.
//            findImageEffects ( imageId );
//            connectAttr ( file, imageFile.getOutColor (), effect.getColor () );

            //connectAttr "file1.message" ":initialMaterialInfo.texture" -nextAvailable;

            ++it;
        }

    }
} // namespace COLLADAMaya
