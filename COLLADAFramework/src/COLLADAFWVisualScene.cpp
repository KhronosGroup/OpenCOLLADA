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
	VisualScene::VisualScene( ObjectId objectId )
		:ObjectTemplate< COLLADA_TYPE::VISUAL_SCENE >( objectId ) 
	{}

	//--------------------------------------------------------------------
	VisualScene::~VisualScene()
	{
	}


} // namespace COLLADAFW
