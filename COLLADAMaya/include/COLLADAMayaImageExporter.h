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

#ifndef __COLLADA_MAYA_IMAGE_EXPORTER_H__
#define __COLLADA_MAYA_IMAGE_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"

#include "COLLADAMayaEffectTextureExporter.h"
#include "COLLADAMayaDocumentExporter.h"


namespace COLLADAMaya
{

    /** This class writes the <library_images>. It uses informations created my an effect exporter*/

    class ImageExporter : public COLLADA::LibraryImages
    {

    public:
        /**
        @param streamWriter The stream the output will be written to
        @param documentExporter The document exporter this material exporter is used in*/
        ImageExporter ( COLLADA::StreamWriter* streamWriter );
        virtual ~ImageExporter() {};

        /** Exports the given list of images. */
        void exportImages ( const ImageMap* imageMap );
    };

}

#endif //__COLLADA_MAYA_IMAGE_EXPORTER_H__
