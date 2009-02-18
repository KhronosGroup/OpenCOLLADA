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


namespace COLLADAMaya
{

    /** TODO Documentation */
	class ImageImporter : BaseImporter
    {
    private:

        /** The standard name for image without name. */
        static const String IMAGE_NAME;

	private:
	
        /**
        * The list of the unique maya image names.
        */
        COLLADABU::IDList mImageIdList;

	public:

        /** Constructor. */
		ImageImporter ( DocumentImporter* documentImporter  );

        /** Destructor. */
		virtual ~ImageImporter();

        /**
        * Imports the data of the current light.
        */
        void importImage ( const COLLADAFW::Image* image );

	private:

        /** Disable default copy ctor. */
		ImageImporter( const ImageImporter& pre );

        /** Disable default assignment operator. */
		const ImageImporter& operator= ( const ImageImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_IMAGEIMPORTER_H__
