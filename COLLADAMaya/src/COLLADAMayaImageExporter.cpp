/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"

#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaImageExporter.h"


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    ImageExporter::ImageExporter ( COLLADASW::StreamWriter* streamWriter )
            : COLLADASW::LibraryImages ( streamWriter )
    {}


    //---------------------------------------------------------------
    void ImageExporter::exportImages ( const ImageMap* imageMap )
    {
        // export the images
        ImageMap::const_iterator it = imageMap->begin();
        for ( ; it!=imageMap->end(); ++it )
        {
            // Create a new image structure
            COLLADASW::Image* colladaImage = it->second;

            // Add the image to the collada document.
            addImage ( *colladaImage );
        }

        closeLibrary();
    }

}