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
	bool InstanceGeometry::TextureCoordinateBinding::operator<( const TextureCoordinateBinding& rhs ) const
	{
		if ( textureMapId < rhs.textureMapId )
			return true;

		if ( textureMapId > rhs.textureMapId )
			return false;

		if ( setIndex < rhs.setIndex )
			return true;

		if ( setIndex > rhs.setIndex )
			return false;

		return false;
	}


	// ----------------------------------
	InstanceGeometry::MaterialBinding::MaterialBinding( const InstanceGeometry::MaterialBinding& pre )
		: mMaterialId( pre.mMaterialId )
		, mReferencedMaterial( pre.mReferencedMaterial )
		, mName( pre.mName )
		, mTextureCoordinateBindingArray()
	{
		pre.mTextureCoordinateBindingArray.cloneArray(mTextureCoordinateBindingArray);
	}

	// ----------------------------------
	const InstanceGeometry::MaterialBinding& InstanceGeometry::MaterialBinding::operator= ( const InstanceGeometry::MaterialBinding& pre )
	{
		mMaterialId = pre.mMaterialId;
		mReferencedMaterial = pre.mReferencedMaterial;
		mName = pre.mName;
		pre.mTextureCoordinateBindingArray.cloneArray(mTextureCoordinateBindingArray);
		return *this;
	}

	
    // ----------------------------------
	InstanceGeometry::InstanceGeometry( UniqueId instanciatedGeometryId )
		: InstanceSceneGraph(instanciatedGeometryId)
	{
	}

    // ----------------------------------
	InstanceGeometry::InstanceGeometry( const InstanceGeometry& pre )
		: InstanceSceneGraph(pre)
		, mMaterialBindings()
	{
		pre.mMaterialBindings.cloneArray(mMaterialBindings);
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
