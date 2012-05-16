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


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxImageExporter.h"
#include "COLLADASWNode.h"

#include "COLLADAMaxExportSceneGraph.h"

namespace COLLADAMax
{


    //---------------------------------------------------------------
    ImageExporter::ImageExporter ( COLLADASW::StreamWriter * streamWriter, DocumentExporter * documentExporter )
            : COLLADASW::LibraryImages ( streamWriter ),
            mExportedImageMap ( documentExporter->getEffectExporter() ->getExportedImageMap() )
    {}


    //---------------------------------------------------------------
    void ImageExporter::doExport()
    {
        // export all wire frame color materials

        for ( ExportedImageMap::const_iterator it = mExportedImageMap.begin(); it != mExportedImageMap.end(); ++it )
        {
			const ImageInfo& imageInfo = it->second;
            addImage ( COLLADASW::Image ( imageInfo.fileLocation, imageInfo.imageId ) );
        }

        closeLibrary();
    }



}
