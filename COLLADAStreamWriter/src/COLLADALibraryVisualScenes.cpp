/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADAStreamWriter.h"
#include "COLLADALibraryVisualScenes.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    //---------------------------------------------------------------
    LibraryVisualScenes::LibraryVisualScenes ( COLLADA::StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_VISUAL_SCENES )
    {}


    //---------------------------------------------------------------
    void LibraryVisualScenes::openVisualScene ( const String &nodeId, const String &nodeName )
    {
        openLibrary();
        mCurrentVisualSceneCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_VISUAL_SCENE );

        if ( !nodeId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, nodeId );

        if ( !nodeName.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, nodeName );
    }


    //---------------------------------------------------------------
    void LibraryVisualScenes::closeVisualScene()
    {
        mCurrentVisualSceneCloser.close();
    }

} //namespace COLLADA
