/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEGEOMETRY_H__
#define __COLLADAFW_INSTANCEGEOMETRY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWInstanceBindingBase.h"
#include "COLLADAFWPointerArray.h"


namespace COLLADAFW
{

    /** Instantiates a node within a scene graph.*/
    typedef InstanceBindingBase<COLLADA_TYPE::INSTANCE_GEOMETRY> InstanceGeometry;

	typedef ArrayPrimitiveType<InstanceGeometry*> InstanceGeometryArray;
	typedef PointerArray<InstanceGeometry> InstanceGeometryPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEGEOMETRY_H__
