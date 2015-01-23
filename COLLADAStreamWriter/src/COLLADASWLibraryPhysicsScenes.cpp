/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryPhysicsScenes.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    //---------------------------------------------------------------
    LibraryPhysicsScenes::LibraryPhysicsScenes ( COLLADASW::StreamWriter *streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_PHYSICS_SCENES )
    {}


    //---------------------------------------------------------------
    void LibraryPhysicsScenes::openPhysicsScene ( const String &nodeId, const String &nodeName)
    {
        openLibrary();
        mCurrentPhysicsSceneCloser = mSW->openElement ( CSWC::CSW_ELEMENT_PHYSICS_SCENE );

        if ( !nodeId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, nodeId );

        if ( !nodeName.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, nodeName );
    }


    //---------------------------------------------------------------
    void LibraryPhysicsScenes::closePhysicsScene()
    {
        mCurrentPhysicsSceneCloser.close();
    }

	void LibraryPhysicsScenes::closeLibraryPhysicsScene()
	{
		closeLibrary();
	}

} //namespace COLLADASW
