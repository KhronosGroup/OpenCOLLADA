/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCECONTROLLER_H__
#define __COLLADAFW_INSTANCECONTROLLER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceGeometry.h"


namespace COLLADAFW
{

    /** Instantiates a node within a scene graph.*/
    typedef InstanceGeometry InstanceController;

    typedef ArrayPrimitiveType<InstanceController*> InstanceControllerArray;
    typedef PointerArray<InstanceController> InstanceControllerPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCECONTROLLER_H__
