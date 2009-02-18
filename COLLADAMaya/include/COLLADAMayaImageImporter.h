/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_IMAGEIMPORTER_H__
#define __COLLADAMAYA_IMAGEIMPORTER_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADABUIDList.h"

#include "COLLADAFWImage.h"

#include <MayaDMFile.h>


namespace COLLADAMaya
{

    /** TODO Documentation */
	class ImageImporter : BaseImporter
    {
    private:

        /** The standard name for image without name. */
        static const String IMAGE_NAME;
        static const String PLACE_2D_TEXTURE_NAME;
        static const String DEFAULT_TEXTURE_LIST;

    private:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::File> UniqueIdMayaImagesMap;
	private:
	
        /**
        * The list of the unique maya image names.
        */
        COLLADABU::IDList mImageIdList;

        /**
         * The list with the unique maya place2dtexture names.
         */
        COLLADABU::IDList mPlace2dTextureIdList;

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
        * Imports the data of the current light.
        */
        void importImage ( const COLLADAFW::Image* image );

        /**
         * Write the connections between files and defaultTextureList and effects.
         */
        void writeConnections ();

	private:

        /**
         * Returns a pointer to the maya image file with the given image id, 
         * or NULL, if it is not in the list.
         */
        const MayaDM::File* findMayaImageFile ( const COLLADAFW::UniqueId& imageId );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_IMAGEIMPORTER_H__
