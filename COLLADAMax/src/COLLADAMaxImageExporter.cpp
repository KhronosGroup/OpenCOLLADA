/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxImageExporter.h"
#include "COLLADANode.h"

#include "COLLADAMaxExportSceneGraph.h"

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ImageExporter::ImageExporter ( COLLADA::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADA::LibraryImages ( streamWriter ),
            mExportedImageMap ( documentExporter->getEffectExporter() ->getExportedImageMap() )
    {}


    //---------------------------------------------------------------
    void ImageExporter::doExport()
    {
        // export all wire frame color materials

        for ( ExportedImageMap::const_iterator it = mExportedImageMap.begin(); it != mExportedImageMap.end(); ++it )
        {
            addImage ( COLLADA::Image ( it->first, it->second ) );
        }

        closeLibrary();
    }



}
