/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWMesh.h"

namespace COLLADAFW
{


	Mesh::~Mesh()
	{
		for ( size_t i = 0, count = mMeshPrimitives.getCount(); i < count; ++i)
			delete mMeshPrimitives[i];
	}


	//---------------------------------------------------------------
	size_t Mesh::getTrianglesCount()
	{
		size_t trianglesCount = 0;
		for ( size_t i = 0, count = mMeshPrimitives.getCount(); i < count; ++i)
		{
			MeshPrimitive* primitive = mMeshPrimitives[i];
			if ( !primitive )
				continue;
			trianglesCount += primitive->getFaceCount();
		}
		return trianglesCount;
	}

	//---------------------------------------------------------------
	bool Mesh::hasNormals( )const
	{
		return getNormals().getNormalsCount() != 0;
	}

	//---------------------------------------------------------------
	bool Mesh::hasColors( ) const
	{
		return getColors().getColorsCount() != 0;
	}

	//---------------------------------------------------------------
	bool Mesh::hasUVCoords() const
	{
		return getColors().getColorsCount() != 0;
	}

	Mesh::Mesh( ObjectId objectId ) 
		: Geometry ( objectId, Geometry::GEO_TYPE_MESH ),
		mMeshPrimitives(MeshPrimitiveArray::OWNER)
	{

	}
} // namespace COLLADAFW
