/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_IMAGE_EXPORTER_H__
#define __COLLADA_MAYA_IMAGE_EXPORTER_H__

#include "COLLADAMayaPrerequisites.h"
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
