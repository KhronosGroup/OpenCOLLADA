/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaGeometryImporter.h"

#include <dom/domPolylist.h>

#include <maya/MFnMesh.h>


namespace COLLADAMaya
{
    
    // -----------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter ) 
    : BaseImporter ( documentImporter )
    {

    }

    // -----------------------------
    void GeometryImporter::importGeometries ( MObject& transformObject, domNode& node )
    {
        // Set the transformObject
//        mTransformObject = transformObject;

        domInstance_geometry_Array geometryArray = node.getInstance_geometry_array ();

        size_t numGeometries = geometryArray.getCount ();
        for ( size_t i=0; i<numGeometries; ++i )
        {
            domInstance_geometryRef instanceGeometryRef = geometryArray.get ( i );
            importGeometry ( instanceGeometryRef );
        }
    }

    // -----------------------------
    void GeometryImporter::importGeometry ( domInstance_geometryRef instanceGeometryRef )
    {
        //xsID geometryId = instanceGeometryRef->getId ();
        //xsName geometryName = instanceGeometryRef->getName ();
        daeString geometryId = instanceGeometryRef->getID ();
        xsNCName geometrySid = instanceGeometryRef->getSid ();
        xsAnyURI geometryURL = instanceGeometryRef->getUrl ();

        domBind_materialRef bindMaterialRef = instanceGeometryRef->getBind_material ();

        // TODO Get the geometry!
//         domMeshRef meshRef = instanceGeometryRef->getMesh ();
//         if ( meshRef != NULL ) importMesh ( meshRef );
    }

    // -----------------------------
    bool GeometryImporter::importMesh ( domMeshRef& meshRef )
    {

        domPolylist_Array polylistArray = meshRef->getPolylist_array ();
        size_t polylistCount = polylistArray.getCount ();
        for ( size_t i=0; i<polylistCount; ++i )
        {
            domPolylistRef polylistRef = polylistArray.get ( i );
            xsNCName materialName = polylistRef->getMaterial ();

            // The number of polygon primitives.
            domUint count = polylistRef->getCount ();
            domUint holeCount = 0;

            domInputLocalOffset_Array inputLocalOffsetArray = polylistRef->getInput_array ();
            size_t numOfInputs = inputLocalOffsetArray.getCount ();
            for ( size_t j=0; j<numOfInputs; ++j )
            {
                domInputLocalOffsetRef inputLocalOffsetRef = inputLocalOffsetArray.get ( j );
                xsNMTOKEN semantic = inputLocalOffsetRef->getSemantic ();
                domURIFragmentType sourceUri = inputLocalOffsetRef->getSource ();
                domUint offset = inputLocalOffsetRef->getOffset ();
                domUint set = inputLocalOffsetRef->getSet ();
            }

            // Contains a list of integers, each specifying the number of
            // vertices for one polygon described by the <polylist> element.
            domPolylist::domVcountRef vcountRef = polylistRef->getVcount ();
            domListOfUInts vCountList = vcountRef->getValue ();
            size_t numOfVCounts = vCountList.getCount ();
            uint numVertices = 0;
            for ( size_t n=0; n<numOfVCounts; ++n )
            {
                numVertices += ( uint ) vCountList.get ( n );
            }

            // Contains a list of integers that specify the vertex attributes
            // (indices) for an individual polylist. ("p" stands for "primitive".)
            domPRef pRef = polylistRef->getP ();
            domListOfUInts vertexAttributes = pRef->getValue ();

            // This should include all the vertices in the mesh, and no extras.
            MFloatPointArray vertexArray;

            size_t numVertexAttributes = vertexAttributes.getCount ();
            //vertexAttributes.get

            // Create the Maya mesh node
            MFnMesh meshFn;
            int numPolygons = (int) ( count + holeCount );
            MFnDagNode dummyNodeFn;
            dummyNodeFn.create( "transform", "___DummyTransform___" );
            // TODO
//             MObject mesh = meshFn.create( numVertices, numPolygons, geometry->points,
//                 geometry->faceVertexCounts, geometry->faceConnects, dummyNodeFn.object());
//             meshFn.setName(geometry->colladaGeometry->GetName().c_str());

        }

        domVerticesRef verticesRef = meshRef->getVertices ();
        verticesRef->getId ();

        meshRef->getPolygons_array ();
        meshRef->getTriangles_array ();
        meshRef->getTrifans_array ();
        meshRef->getTristrips_array ();

        domSource_Array sourceArray = meshRef->getSource_array ();

        return true;
    }

}