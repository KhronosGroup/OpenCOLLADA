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
#include "COLLADAMaxVisualSceneImporter.h"

#include "COLLADAFWVisualScene.h"
#include "COLLADAFWNode.h"

#include <max.h>


namespace COLLADAMax
{


	VisualSceneImporter::VisualSceneImporter( DocumentImporter* documentImporter, const COLLADAFW::VisualScene* visualScene )
		:	NodeImporter(documentImporter),
		mVisualScene( new COLLADAFW::VisualScene( *visualScene ) )
	{
		addVisualScene( mVisualScene );
	}

    //------------------------------
	VisualSceneImporter::~VisualSceneImporter()
	{
	}

	//------------------------------
	bool VisualSceneImporter::import()
	{
		const COLLADAFW::NodePointerArray& rootNodes = mVisualScene->getRootNodes();
		return importNodes( rootNodes );
	}


} // namespace COLLADAMax
