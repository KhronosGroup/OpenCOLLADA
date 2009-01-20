/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCENODE_H__
#define __COLLADAFW_INSTANCENODE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWSceneGraphInstance.h"


namespace COLLADAFW
{

	/** Instantiates a node within a scene graph.*/
	typedef SceneGraphInstance InstanceNode;

	typedef ArrayPrimitiveType<InstanceNode*> InstanceNodeArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCENODE_H__
