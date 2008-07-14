/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"

#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaImageExporter.h"


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    ImageExporter::ImageExporter ( COLLADA::StreamWriter* streamWriter )
            : COLLADA::LibraryImages ( streamWriter )
    {}


    //---------------------------------------------------------------
    void ImageExporter::exportImages ( const ImageMap* imageMap )
    {
        // export the images
        ImageMap::const_iterator it = imageMap->begin();

        for ( ; it != imageMap->end(); ++it )
        {
            // Create a new image structure
            COLLADA::Image* colladaImage = it->second;

            // Add the image to the collada document.
            addImage ( *colladaImage );
        }

        closeLibrary();
    }

}