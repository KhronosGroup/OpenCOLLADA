/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWInstanceKinematicsScene.h"


namespace COLLADAFW
{

	//------------------------------
	InstanceKinematicsScene::InstanceKinematicsScene( const UniqueId& uniqueId, const UniqueId& instanciatedObjectId ) 
		: InstanceBase<COLLADA_TYPE::INSTANCE_KINEMATICS_SCENE>(uniqueId, instanciatedObjectId)
		, mBoundNodes(UniqueIdArray::OWNER)
	{

	}


    //------------------------------
	InstanceKinematicsScene::~InstanceKinematicsScene()
	{
	}

} // namespace COLLADAFW
