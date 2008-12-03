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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaSceneTraverserListener.h"
#include "COLLADAMayaVisualSceneImporter.h"

namespace COLLADAMaya
{


    bool SceneTraverserListener::preDetectedNode( domNode& node, int level )
    {
        return true;
    }

    bool SceneTraverserListener::postDetectedNode( domNode& node, int level )
    {
        return true;
    }

    bool SceneTraverserListener::detectedInstanceNode( domInstance_node& instance, int level )
    {
        return true;
    }

    bool SceneTraverserListener::detectedInstanceGeometry( domInstance_geometry& instance, int level )
    {
        return true;
    }

    bool SceneTraverserListener::detectedInstanceLight( domInstance_light& instance, int level )
    {
        return true;
    }

    bool SceneTraverserListener::detectedInstanceCamera( domInstance_camera& instance, int level )
    {
        return true;
    }

    bool SceneTraverserListener::detectedNodeExtra( domExtra& extra, int level )
    {
        return true;
    }
}