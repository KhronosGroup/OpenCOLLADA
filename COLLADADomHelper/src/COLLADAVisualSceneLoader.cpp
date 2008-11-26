/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAVisualSceneLoader.h"

namespace COLLADADH
{
	//--------------------------------------------------------------------
	VisualSceneLoader::VisualSceneLoader(Loader* colladaLoader, domVisual_scene* colladaVisualScene)
		 : mColladaVisualScene(colladaVisualScene),
		 mColladaLoader(colladaLoader)
	{
	}
	
	//--------------------------------------------------------------------
	VisualSceneLoader::~VisualSceneLoader()
	{
	}

	COLLADAFW::VisualScene* VisualSceneLoader::load()
	{
		mVisualScene = new COLLADAFW::VisualScene ();

		const domNode_Array& nodeArray = mColladaVisualScene->getNode_array();

		//COLLADAFW::NodeArray rootNodes(new );

		mVisualScene->setRootNodes(rootNodes);


		COLLADADH::NodeTraverser traverser(*mColladaVisualScene);
		if ( !traverser.traverse(*this) )
		{
			delete mVisualScene;
			return 0;
		}

		return mVisualScene;
	}

	bool VisualSceneLoader::detectedInstanceGeometry( domInstance_geometry& instance, int level )
	{
		return true;
	}

	bool VisualSceneLoader::preDetectedNode( domNode& node, int level )
	{
		return true;
	}

	bool VisualSceneLoader::postDetectedNode( domNode& node, int level )
	{
		return true;
	}
} // namespace COLLADA
