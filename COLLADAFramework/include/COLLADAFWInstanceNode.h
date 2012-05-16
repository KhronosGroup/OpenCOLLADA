/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCENODE_H__
#define __COLLADAFW_INSTANCENODE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceSceneGraph.h"
#include "COLLADAFWPointerArray.h"


namespace COLLADAFW
{

	/** Instantiates a node within a scene graph.*/
	typedef InstanceBase<COLLADA_TYPE::INSTANCE_NODE> InstanceNode;

	typedef ArrayPrimitiveType<InstanceNode*> InstanceNodeArray;
	typedef PointerArray<InstanceNode> InstanceNodePointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCENODE_H__
