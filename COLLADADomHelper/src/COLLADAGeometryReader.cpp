/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAGeometryReader.h"
#include "COLLADAMeshReader.h"

namespace COLLADADomHelper
{

    // --------------------------------------------
    void GeometryReader::importGeometry ( domInstance_geometryRef instanceGeometryRef )
    {
        //xsID geometryId = instanceGeometryRef->getId ();
        //xsName geometryName = instanceGeometryRef->getName ();
        daeString geometryId = instanceGeometryRef->getID ();
        xsNCName geometrySid = instanceGeometryRef->getSid ();
        xsAnyURI geometryURL = instanceGeometryRef->getUrl ();

        domBind_materialRef bindMaterialRef = instanceGeometryRef->getBind_material ();

        // Get the geometry.
        if ( geometryURL.getState() != daeURI::uri_success )
        {
            geometryURL.setContainer( mDoc.getDomRoot() );
            geometryURL.resolveElement();
        }
        domGeometryRef geometry = daeSafeCast<domGeometry>( geometryURL.getElement() );

        // Set the current geometry member.
        mGeometryRef = geometry;

        xsNCName geometryName = geometry->getName ();
        daeString geometryId2 = geometry->getID ();

        // The framework mesh object.
        COLLADAFW::Mesh* mesh;

        domMeshRef meshRef = geometry->getMesh ();
//        if ( meshRef != NULL ) mesh = MeshReader::createMeshObject ( meshRef );


    }

}