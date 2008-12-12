/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxGeometryImporter.h"
#include "COLLADAFWGeometry.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAMax
{

	GeometryImporter::GeometryImporter( DocumentImporter* documentImporter, const COLLADAFW::Geometry* geometry )
		:	ImporterBase(documentImporter),
		mGeometry(geometry)
	{

	}

    //------------------------------
	GeometryImporter::~GeometryImporter()
	{
	}

	bool GeometryImporter::import()
	{
		TriObject* triangleObject = CreateNewTriObject();

		Mesh& triangleMesh = triangleObject->GetMesh();

		triangleMesh.setNumVerts(3);
		triangleMesh.setVert(0, 0, 0, 0);
		triangleMesh.setVert(1, 100, 0, 0);
		triangleMesh.setVert(2, 100, 100, 0);

		triangleMesh.setNumFaces(1);
		Face& face = triangleMesh.faces[0];
		face.setVerts(0, 1, 2);
		triangleMesh.InvalidateGeomCache();

		INodeList nodeList;
		getINodesByUniqueId(COLLADAFW::UniqueId(COLLADAFW::Geometry::ID(), 0), nodeList);
		for ( size_t i = 0, count = nodeList.size(); i<count; ++i)
			nodeList[i]->SetObjectRef(triangleObject);


		return true;
	}

} // namespace COLLADAMax
