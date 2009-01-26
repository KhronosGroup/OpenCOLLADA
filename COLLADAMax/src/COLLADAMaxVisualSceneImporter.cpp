/*
Copyright (c) 2008 NetAllied Systems GmbH

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
#include "COLLADAMaxVisualSceneImporter.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWNode.h"

#include <max.h>


namespace COLLADAMax
{


	VisualSceneImporter::VisualSceneImporter( DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene )
		:	NodeImporter(documentImporter),
			mVisualScene(visualScene)
	{}

    //------------------------------
	VisualSceneImporter::~VisualSceneImporter()
	{
	}

	//------------------------------
	bool VisualSceneImporter::import()
	{
		if ( !mVisualScene )
			return false;


		// make a new node for each visual scene (it might happen, that we receive more than one)
		// we remove unused visual scenes at the end of the import
		ImpNode* visualSceneRootNode = getMaxImportInterface()->CreateNode();
		getMaxImportInterface()->AddNodeToScene(visualSceneRootNode);
		RefResult res = visualSceneRootNode->Reference( getDummyObject() );
		
		String visualScenenName = mVisualScene->getName();
		if ( !visualScenenName.empty() )
			visualSceneRootNode->SetName(visualScenenName.c_str());

		importNodes(mVisualScene->getRootNodes(), visualSceneRootNode);

		return true;
	}


} // namespace COLLADAMax
