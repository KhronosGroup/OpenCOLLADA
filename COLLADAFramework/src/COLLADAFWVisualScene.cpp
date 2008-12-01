/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWVisualScene.h"

namespace COLLADAFW
{
	//--------------------------------------------------------------------
	VisualScene::VisualScene()
	{
	}
	
	//--------------------------------------------------------------------
	VisualScene::~VisualScene()
	{
		//delete all root node
		for ( size_t i = 0, count = mRootNodes.getCount(); i < count; ++i)
			delete mRootNodes[i];
	}


} // namespace COLLADAFW
