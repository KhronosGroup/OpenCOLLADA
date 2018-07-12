/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAImageImporter.h"
#include "DAE2MAMaterialImporter.h"

#include <MayaDMCommands.h>


namespace DAE2MA
{

    const String ImageImporter::IMAGE_NAME = "image";


    //------------------------------
	ImageImporter::ImageImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	ImageImporter::~ImageImporter()
	{
        // A copy of the framework's library image elements. 
        std::map<COLLADAFW::UniqueId, COLLADAFW::Image*>::iterator it = mImagesMap.begin ();
        while ( it != mImagesMap.end () )
        {
            COLLADAFW::Image* image = it->second;
            delete image;
            ++it;
        }
        mImagesMap.clear ();
	}

    //------------------------------
    void ImageImporter::storeImage ( const COLLADAFW::Image* image )
    {
        const COLLADAFW::UniqueId& imageId = image->getUniqueId ();
        mImagesMap [imageId] = new COLLADAFW::Image ( *image );
    }

    //------------------------------
    void ImageImporter::importImages ()
    {
        // TODO We have look for images, we have to import multiple times!
        // It's possible, that we have to create an image for more than one time. This happens if:
        // a) one image is referenced from multiple effects 
        // b) one image is referenced in multiple samplers in one effect 
        // c) one effect uses the same sampler multiple times.
        // We have to dublicate the image, about the possibility to create multiple uv-sets on it.

        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        EffectImporter::UniqueIdTextureInfosMap& effectTextureInfosMap = effectImporter->getTextureInfosMap ();
        size_t numTextureInfos = effectTextureInfosMap.size ();

        // We have to generate a separate maya file for every texture info, which use an image.
        EffectImporter::UniqueIdTextureInfosMap::iterator it = effectTextureInfosMap.begin ();
        while ( it != effectTextureInfosMap.end () )
        {
            const COLLADAFW::UniqueId& effectId = it->first;
            std::vector<EffectImporter::TextureInfo>& textureInfos = it->second;
            for ( size_t i=0; i<textureInfos.size (); ++i )
            {
                EffectImporter::TextureInfo& textureInfo = textureInfos [i];
                const COLLADAFW::UniqueId& imageId = textureInfo.getImageId ();

                const COLLADAFW::Image* image = findImage ( imageId );
                if ( image == 0 ) 
                {
                    std::cerr << "The image was not imported! " << std::endl;
                    continue;
                }

                // Import the images data.
                importImage ( image, textureInfo );
            }

            ++it;
        }
    }

    //------------------------------
    void ImageImporter::importImage ( 
        const COLLADAFW::Image* image, 
        EffectImporter::TextureInfo& textureInfo )
    {
        // Check if the image is already imported.
        const COLLADAFW::UniqueId& imageId = image->getUniqueId ();

        // Create a unique name.
        String imageName = image->getName ();
        if ( imageName.empty () ) imageName = IMAGE_NAME;
        imageName = DocumentImporter::frameworkNameToMayaName ( imageName );
        const ExtraDataCallbackHandler& callbackHandler = getDocumentImporter ()->getMayaIdCallbackHandler ();
        String originalMayaId = getOriginalMayaId ( callbackHandler, imageId, COLLADASaxFWL15::HASH_ELEMENT_IMAGE );
        if ( !originalMayaId.empty () ) imageName = originalMayaId;
        imageName = generateUniqueDependNodeName ( imageName );

        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the image uri
        const COLLADABU::URI& imageURI = image->getImageURI ();
        String fileTextureName = imageURI.toNativePath ();
        COLLADABU::Utils::stringFindAndReplace ( fileTextureName, "\\", "/" );
        if ( fileTextureName.at(0) == '/' )
            fileTextureName = "." + fileTextureName;
        
        //createNode file -name "file1";
        //    setAttr ".fileTextureName" -type "string" "./tex/checkerRGB.jpg";
        MayaDM::File mayaImage ( file, imageName );
        mayaImage.setFileTextureName ( fileTextureName );

        // Add the original id attribute.
        String colladaId = image->getOriginalId ();
        if ( !colladaId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaId );
        }
//         // TODO Add the attributes for all the extra tags.
//         setExtraData ( image->getExtraDataArray () );

        // Push the maya image file in the map to the unique image id.
        mImageIdMayaImageFileMap [ imageId ] = mayaImage;

        // Set the generated maya image node into the current texture info element.
        textureInfo.setImageNode ( mayaImage );
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

    //------------------------------
    const COLLADAFW::Image* ImageImporter::findImage ( const COLLADAFW::UniqueId& imageId )
    {
        std::map<COLLADAFW::UniqueId, COLLADAFW::Image*>::iterator it = mImagesMap.find ( imageId );
        if ( it != mImagesMap.end () ) 
            return it->second;
        return 0;
    }

} // namespace DAE2MA
