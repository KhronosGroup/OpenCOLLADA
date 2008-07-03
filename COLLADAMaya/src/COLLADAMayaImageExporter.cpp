/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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