/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWSceneGraphInstance.h"


namespace COLLADAFW
{


	//------------------------------
	SceneGraphInstance::SceneGraphInstance( UniqueId instanciatedObjectId )
		: mInstanciatedObjectId(instanciatedObjectId)
	{
	}


    //------------------------------
	SceneGraphInstance::~SceneGraphInstance()
	{
	}

} // namespace COLLADAFW
