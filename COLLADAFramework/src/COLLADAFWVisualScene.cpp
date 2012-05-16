/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

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
	VisualScene::VisualScene( const UniqueId& uniqueId )
		:ObjectTemplate< COLLADA_TYPE::VISUAL_SCENE >( uniqueId ) 
	{}

	//--------------------------------------------------------------------
	VisualScene::~VisualScene()
	{
	}


} // namespace COLLADAFW
