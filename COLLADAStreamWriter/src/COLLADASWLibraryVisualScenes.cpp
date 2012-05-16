/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryVisualScenes.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    LibraryVisualScenes::LibraryVisualScenes ( COLLADASW::StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_VISUAL_SCENES )
    {}


    //---------------------------------------------------------------
    void LibraryVisualScenes::openVisualScene ( const String &nodeId, const String &nodeName )
    {
        openLibrary();
        mCurrentVisualSceneCloser = mSW->openElement ( CSWC::CSW_ELEMENT_VISUAL_SCENE );

        if ( !nodeId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, nodeId );

        if ( !nodeName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, nodeName );
    }


    //---------------------------------------------------------------
    void LibraryVisualScenes::closeVisualScene()
    {
        mCurrentVisualSceneCloser.close();
    }

} //namespace COLLADASW
