/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCESCENEGRAPH_H__
#define __COLLADAFW_INSTANCESCENEGRAPH_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceBase.h"
#include "COLLADAFWPointerArray.h"


namespace COLLADAFW
{

    /** Instantiates a node within an instance scene graph.*/
    typedef InstanceBase<COLLADA_TYPE::INSTANCE_SCENE_GRAPH> InstanceSceneGraph;

    typedef ArrayPrimitiveType<InstanceSceneGraph*> InstanceSceneGraphArray;
    typedef PointerArray<InstanceSceneGraph> InstanceSceneGraphPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCESCENEGRAPH_H__
