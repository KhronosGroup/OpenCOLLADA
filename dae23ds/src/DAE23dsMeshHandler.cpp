/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsMeshHandler.h"
#include "DAE23dsMeshAccessor.h"

namespace DAE23ds
{

    //------------------------------
	MeshHandler::MeshHandler( Writer* writer3ds, const COLLADAFW::Mesh* mesh )
		: BaseWriter(writer3ds)
		, mMesh(mesh)
	{
	}
	
    //------------------------------
	MeshHandler::~MeshHandler()
	{
	}

	//------------------------------
	bool MeshHandler::handle()
	{
		MeshAccessor meshAccessor( mMesh );
		Writer::MeshData meshData;
		meshData.meshUniqueId = mMesh->getUniqueId();
		meshData.trianglesCount = meshAccessor.getTrianglesCount();
		meshData.positionsCount = mMesh->getPositions().getValuesCount();
		meshData.name = mMesh->getName();
		addMeshData( meshData );
		return true;
	}


} // namespace DAE23ds
