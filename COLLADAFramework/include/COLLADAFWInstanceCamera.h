/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCECAMERA_H__
#define __COLLADAFW_INSTANCECAMERA_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceSceneGraph.h"
#include "COLLADAFWPointerArray.h"


namespace COLLADAFW
{

	/** Instantiates a node within a scene graph.*/
	typedef InstanceSceneGraph InstanceCamera;

	typedef ArrayPrimitiveType<InstanceCamera*> InstanceCameraArray;
	typedef PointerArray<InstanceCamera> InstanceCameraPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCECAMERA_H__
