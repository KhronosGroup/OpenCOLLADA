/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaControllerImporter.h"

//#include "COLLADAFWController.h"


namespace COLLADAMaya
{

    const String ControllerImporter::CONTROLLER_NAME = "Controller";


    //------------------------------
	ControllerImporter::ControllerImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
	}
	
    //------------------------------
	ControllerImporter::~ControllerImporter()
	{
        UniqueIdMayaNodeMap::iterator it = mMayaControllerNodesMap.begin ();
        while ( it != mMayaControllerNodesMap.end () )
        {
            MayaNode* mayaNode = it->second;
            delete mayaNode;
            ++it;
        }
        mMayaControllerNodesMap.clear ();
	}

    //------------------------------
//     void CameraImporter::importController ( const COLLADAFW::Controller* controller )
//     {
//     }

    // --------------------------------------------
    MayaNode* ControllerImporter::findMayaControllerNode ( const COLLADAFW::UniqueId& controllerId ) 
    {
        UniqueIdMayaNodeMap::iterator it = mMayaControllerNodesMap.find ( controllerId );
        if ( it != mMayaControllerNodesMap.end () )
            return it->second;

        return 0;
    }


} // namespace COLLADAMaya
