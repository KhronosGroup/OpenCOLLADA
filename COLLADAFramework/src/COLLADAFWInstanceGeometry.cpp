/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWInstanceGeometry.h"

namespace COLLADAFW
{
	
    // ----------------------------------
	InstanceGeometry::InstanceGeometry( UniqueId instanciatedGeometryId )
		: SceneGraphInstance(instanciatedGeometryId)
	{
	}

    // ----------------------------------
	InstanceGeometry::InstanceGeometry( const InstanceGeometry& pre )
		: SceneGraphInstance(pre)
		, mMaterialBindings()
	{
		mMaterialBindings.allocMemory(pre.mMaterialBindings.getCapacity());
		size_t count = pre.mMaterialBindings.getCount();
		mMaterialBindings.setCount(count);
		for ( size_t i = 0; i < count; ++i)
			mMaterialBindings[i] = pre.mMaterialBindings[i];
	}

	// ----------------------------------
	InstanceGeometry::~InstanceGeometry()
	{
	}

    // ----------------------------------
	InstanceGeometry::MaterialBinding::MaterialBinding ( const MaterialId& materialId, const UniqueId& referencedMaterial )
		: mMaterialId(materialId)
		, mReferencedMaterial(referencedMaterial)
	{
	}
} // namespace COLLADAFW
