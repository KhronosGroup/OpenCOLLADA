/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_IMAGEIMPORTER_H__
#define __DAE2MA_IMAGEIMPORTER_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseImporter.h"
#include "DAE2MAEffectImporter.h"

#include "COLLADAFWImage.h"

#include <MayaDMFile.h>


namespace DAE2MA
{

    /** Imports the image textures. */
	class ImageImporter : BaseImporter
    {
    private:

        /** The standard name for image without name. */
        static const String IMAGE_NAME;

    private:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::File> UniqueIdMayaImagesMap;

	private:

        /** 
         * A copy of the framework's library image elements. 
         */
        std::map<COLLADAFW::UniqueId, COLLADAFW::Image*> mImagesMap;
	
        /**
         * The map holds the Maya image file objects for the unique image file ids.
         */
        UniqueIdMayaImagesMap mImageIdMayaImageFileMap;

	public:

        /** Constructor. */
		ImageImporter ( DocumentImporter* documentImporter  );

        /** Destructor. */
		virtual ~ImageImporter();

        /**
        * Store's the data of the current image.
        */
        void storeImage ( const COLLADAFW::Image* image );

        /**
        * Imports the data of the used images.
        */
        void importImages ();

        /**
        * Returns a pointer to the maya image file with the given image id, 
        * or NULL, if it is not in the list.
        */
        const MayaDM::File* findMayaImageFile ( const COLLADAFW::UniqueId& imageId );

    private:

        /**
        * Imports the data of the current image and stores the generated maya node into 
        * the texture info object.
        */
        void importImage ( 
            const COLLADAFW::Image* image, 
            EffectImporter::TextureInfo& textureInfo );

        /**
        * Get the framework image element of the given id.
        */
        const COLLADAFW::Image* findImage ( const COLLADAFW::UniqueId& imageId );

    };

} // namespace DAE2MA

#endif // __DAE2MA_IMAGEIMPORTER_H__
