/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADADHStableHeaders.h"
#include "COLLADADHGeometryLoader.h"
#include "COLLADADHMeshLoader.h"
#include "COLLADADHLoader.h"

namespace COLLADADH
{

    // --------------------------------------------
    COLLADAFW::Geometry* GeometryLoader::loadGeometry ( const domGeometryRef domGeometry )
    {
        // Create a new COLLADAFramework Geometry object 
		COLLADAFW::ObjectId geometryObjectId = getUniqueId(domGeometry, COLLADAFW::Geometry::getClassId()).getObjectId();
		COLLADAFW::Geometry* geometry = new COLLADAFW::Geometry (geometryObjectId);

        // Set the id and the name
        daeString geometryId = domGeometry->getID ();
        if ( geometryId != 0 ) geometry->setId ( geometryId );

        xsNCName geometryName = domGeometry->getName ();
        if ( geometryName != 0 ) geometry->setName ( geometryName );

        // Look for an element <mesh>
        domMeshRef meshRef = domGeometry->getMesh ();
        if ( meshRef != NULL ) 
        {
            // Create a COLLADAFramework mesh object
            COLLADADH::MeshLoader meshReader ( getColladaLoader(), getDomCollada() );

            // The framework mesh object.
            COLLADAFW::Mesh* mesh = meshReader.createMeshObject ( meshRef );

            // Set the mesh object into the geometry
            geometry->setGeometricElement ( mesh );
        }

        return geometry;
    }

}