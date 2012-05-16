/*
    Copyright (c) 2009 NetAllied Systems GmbH

    This file is part of dae23ds.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "dae23dsStableHeaders.h"
#include "DAE23dsMeshLengthCalculator.h"


namespace DAE23ds
{

	//------------------------------
	MeshLengthCalculator::MeshLengthCalculator( Writer* writer3ds, const Writer::MeshData& meshData )
		: MeshBase(writer3ds, meshData)
	{
	}

	//------------------------------
	MeshLengthCalculator::~MeshLengthCalculator()
	{
	}

	//------------------------------
	bool MeshLengthCalculator::writeMeshIntoMultipleObjects( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoMultipleObjectsData& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance )
	{
		if ( !alreadyUsingInstance || getApplyTransformationsToMeshes() )
		{
			addToObjectAndMaterialBlockLength( data.editObjectLength );
		}
		return true;
	}

	//------------------------------
	bool MeshLengthCalculator::writeMeshIntoOneObject( const Writer::InstanceGeometryInfo& instanceGeometryInfo, const WriteMeshIntoOneObject& data, const COLLADAFW::InstanceGeometry* alreadyUsingInstance)
	{
		if ( !alreadyUsingInstance || getApplyTransformationsToMeshes() )
		{
			addToObjectAndMaterialBlockLength( data.editObjectLength);
		}
		return true;
	}

} // namespace DAE23ds
