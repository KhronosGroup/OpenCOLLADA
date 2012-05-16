/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_IMAGE_EXPORTER_H__
#define __COLLADAMAX_IMAGE_EXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryImages.h"

#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxDocumentExporter.h"

namespace COLLADAMax
{


    /** This class writes the @a \<library_images\>. It uses informations created by an effect exporter.*/

    class ImageExporter : public COLLADASW::LibraryImages
    {

    private:
        /** Map of image filenames and image ids.*/
        const ExportedImageMap & mExportedImageMap;

    public:
        /**
        @param streamWriter The stream the output will be written to
        @param documentExporter The document exporter this material exporter is used in*/
        ImageExporter ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter );
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
