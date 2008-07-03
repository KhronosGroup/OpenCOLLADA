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

#ifndef __COLLADAMAX_IMAGE_EXPORTER_H__
#define __COLLADAMAX_IMAGE_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"

#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxDocumentExporter.h"

namespace COLLADAMax
{


    /** This class writes the @a \<library_images\>. It uses informations created by an effect exporter.*/

    class ImageExporter : public COLLADA::LibraryImages
    {

    private:
        /** Map of image filenames and image ids.*/
        const ExportedImageMap & mExportedImageMap;

    public:
        /**
        @param streamWriter The stream the output will be written to
        @param documentExporter The document exporter this material exporter is used in*/
        ImageExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter );
        virtual ~ImageExporter()
        {}

        /** Exports the library images.*/
        void doExport();

    private:
        ImageExporter ( const ImageExporter & imageExporter );
        ImageExporter &operator= ( const ImageExporter & imageExporter );

    };
}

#endif //__COLLADAMAX_IMAGE_EXPORTER_H__
