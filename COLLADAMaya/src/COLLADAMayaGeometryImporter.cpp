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

#include "COLLADASWUtils.h"
#include "COLLADASWConstants.h"

#include "COLLADAFWPolylist.h"
#include "COLLADAFWTypes.h"

#include "COLLADAMeshReader.h"
#include "COLLADAException.h"

#include <dom/domPolylist.h>

#include <maya/MFnMesh.h>


namespace COLLADAMaya
{
    
    // --------------------------------------------
    GeometryImporter::GeometryImporter( DocumentImporter* documentImporter, daeDocument* daeDoc ) 
    : BaseImporter ( documentImporter, daeDoc )
    , mTransformObject ( MObject::kNullObj )
    {}

    // --------------------------------------------
    void GeometryImporter::importGeometries ( MObject& transformObject, domNode& node )
    {
        // Set the transformObject
        mTransformObject = transformObject;

        domInstance_geometry_Array geometryArray = node.getInstance_geometry_array ();

        size_t numGeometries = geometryArray.getCount ();
        for ( size_t i=0; i<numGeometries; ++i )
        {
            domInstance_geometryRef instanceGeometryRef = geometryArray.get ( i );
            importGeometry ( instanceGeometryRef );
        }
    }

    // --------------------------------------------
    void GeometryImporter::importGeometry ( domInstance_geometryRef instanceGeometryRef )
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
            daeDocument* daeDoc = getDaeDocument ();
            geometryURL.setContainer( daeDoc->getDomRoot() );
            geometryURL.resolveElement();
        }
        domGeometryRef geometry = daeSafeCast<domGeometry>( geometryURL.getElement() );

        // Set the current geometry member.
        mGeometryRef = geometry;

        xsNCName geometryName = geometry->getName ();
        daeString geometryId2 = geometry->getID ();

        domMeshRef meshRef = geometry->getMesh ();
        if ( meshRef != NULL ) 
        {
            // Create a COLLADAFramework mesh object
            COLLADADomHelper::MeshReader meshReader ( getDaeDocument () );
            COLLADAFW::Mesh* mesh = meshReader.createMeshObject ( meshRef );
            
            // Import the mesh object into maya
            importMesh ( mesh );
        }
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( const COLLADAFW::Mesh* mesh )
    {
        // Get the positions source element.
        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.
        const COLLADAFW::Source* positionsSource = 
            mesh->getSourceByInputSemantic ( COLLADAFW::InputSemantic::POSITION );
        if ( positionsSource == 0 ) 
            throw new COLLADADomHelper::Exception ( 
            COLLADADomHelper::Exception::ERR_INTERNAL_ERROR, 
            "Positions source is null!", 
            "GeometryImporter::importMesh ( const COLLADAFW::Mesh* mesh )" );

        // Create the maya mesh object from the polylist array, if it exist
        createMeshFromPolylist ( mesh, positionsSource );

        // Create the maya mesh object from the polylist array, if it exist
        // TODO 
        createMeshFromPolygons ( mesh, positionsSource );

        return true;
    }

    // --------------------------------------------
    void GeometryImporter::createMeshFromPolylist ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::Source* positionsSource )
    {
        // The number of vertices and polygons.
        size_t numVertices = 0, numPolygons = 0;
        // Array of vertex counts for each polygon.
        MFloatPointArray vertexArray;
        // Array of vertex counts for each polygon.
        MIntArray vertexCountsPerPolygon;
        // Go through the primitives, get the vertex connections for each 
        // polygon and write them into the array of vertex connections. 
        MIntArray polygonConnects;

        // The number of polylist elements in the current mesh
        size_t polylistCount;
        const COLLADAFW::PolylistArray& polylistArray = mesh->getPolylistArray ( polylistCount );
        for ( size_t i=0; i<polylistCount; ++i )
        {
            // Get a reference to the current polygons element.
            const COLLADAFW::Polylist& polylist = polylistArray [ i ];
            numPolygons += polylist.getCount ();

            // TODO Assign the material.
            String materialName = polylist.getMaterial ();

            // Fill the array of vertex counts for each polygon.
            getVertexArray ( positionsSource, vertexArray );

            // Get the polylists offset of the vertices 
            // and the maximum offset in the polygons list.
            size_t vertexOffset, vertexSet, maxOffset = 0;
            getPolygonsOffsetValues ( polylist, vertexOffset, vertexSet, maxOffset );

            // Fill the list with the count of vertices for every polygon and 
            // calculate the number of polygons and the sum of vertices for all polygons.
            getVertexCountsPerPolygon ( polylist, vertexCountsPerPolygon, numVertices );

            // Go through the primitives, get the vertex connections for each 
            // polygon and write them into the array of vertex connections. 
            getVertexConnections ( polylist, numPolygons, vertexCountsPerPolygon, 
                maxOffset, vertexOffset, polygonConnects );
        }

        // Just create a mesh object, if there exist one or more polylists.
        if ( polylistCount > 0 )
        {
            cout << "Create mesh from Polylist: " << endl;
            createMesh ( numVertices, numPolygons, vertexArray, 
                vertexCountsPerPolygon, polygonConnects );
        }
    }

    // --------------------------------------------
    void GeometryImporter::createMeshFromPolygons ( 
        const COLLADAFW::Mesh* mesh, 
        const COLLADAFW::Source* positionsSource )
    {
        // The number of vertices and polygons.
        size_t numVertices = 0, numPolygons = 0;
        // Array of vertex counts for each polygon.
        MFloatPointArray vertexArray;
        // Array of vertex counts for each polygon.
        MIntArray vertexCountsPerPolygon;
        // Go through the primitives, get the vertex connections for each 
        // polygon and write them into the array of vertex connections. 
        MIntArray polygonConnects;

        // The number of polylist elements in the current mesh
        size_t polygonsCount;
        const COLLADAFW::PolygonsArray& polygonsArray = mesh->getPolygonsArray ( polygonsCount );

        // Go through all poygons of the current mesh.
        for ( size_t i=0; i<polygonsCount; ++i )
        {
            // Get a reference to the current polygons element.
            const COLLADAFW::Polygons& polygons = polygonsArray [ i ];
            numPolygons = polygons.getCount ();

            // TODO Assign the material.
            String materialName = polygons.getMaterial ();

            // Fill the array of vertex counts for each polygon.
            getVertexArray ( positionsSource, vertexArray );

            // Get the polylists offset of the vertices 
            // and the maximum offset in the polygons list.
            size_t vertexOffset, vertexSet, maxOffset = 0;
            getPolygonsOffsetValues ( polygons, vertexOffset, vertexSet, maxOffset );

            // Fills the list with the count of vertices for every polygon and 
            // calculate the number of polygons and the sum of vertices for all polygons.
//             getVertexCountsPerPolygon ( polygons, maxOffset, 
//                 vertexCountsPerPolygon, numVertices );

            // Goes through the primitives, get the vertex connections for each 
            // polygon and write them into the array of vertex connections. 
            getVertexInformations ( polygons, numPolygons, maxOffset, vertexOffset, 
                numVertices, vertexCountsPerPolygon, polygonConnects );
        }

        cout << "Create mesh from Polygons: " << endl;
        createMesh ( numVertices, numPolygons, vertexArray, 
            vertexCountsPerPolygon, polygonConnects );
    }

//     // --------------------------------------------
//     void GeometryImporter::getVertexCountsPerPolygon ( 
//         const COLLADAFW::Polygons& polygons, 
//         const size_t numInputElements, 
//         MIntArray& vertexCountsPerPolygon, 
//         size_t& numVertices )
//     {
//         // Get the number of polygons in the current polygons element.
//         size_t numPolygons;
// 
//         // Contains a list of polygon lists. Each polygon list contains a list of UInts 
//         // that specifies the vertex attributes (indices) for an individual polygon.
//         const COLLADAFW::PArray& pArray = polygons.getPArray ( numPolygons );
// 
//         // Go through each polygon and count the vertices 
//         // per polygon and the sum of all vertices.
//         for ( size_t n=0; n<numPolygons; ++n )
//         {
//             // Get the list of vertices of the current polygon.
//             const COLLADAFW::PElement& pElement = pArray [ n ];
// 
//             // Get the values from the element.
//             size_t numAttributes;
//             const COLLADAFW::UIntValuesArray& vertexAttributes = pElement.getUIntValuesArray ( numAttributes );
// 
//             // Get the number of vertices of the current polygon.
//             size_t numPolygonVertices = numAttributes / numInputElements;
// 
//             // Count the number of all vertices.
//             numVertices += numPolygonVertices;
// 
//             // Write the number of vertices of the current polygon in the list.
//             vertexCountsPerPolygon.append ( ( int ) numPolygonVertices );
//         }
//     }

    // --------------------------------------------
    void GeometryImporter::getVertexCountsPerPolygon ( 
        const COLLADAFW::Polylist& polylist, 
        MIntArray& vertexCountsPerPolygon, 
        size_t& numVertices )
    {
        // Contains a list of integers, each specifying the number of
        // vertices for one polygon described by the <polylist> element.
        // Get the number of polygons in the current polylist.
        size_t numPolygons;
        const COLLADAFW::Polylist::VCountArray& vCountArray = polylist.getVCountArray ( numPolygons );

        // Go through each polygon and count the vertices 
        // per polygon and the sum of all vertices.
        for ( size_t n=0; n<numPolygons; ++n )
        {
            // Get the number of vertices of the current polygon
            int numPolygonVertices = vCountArray [ n ];

            // Count the number of all vertices.
            numVertices += numPolygonVertices;

            // Write the number of vertices of the current polygon in the list.
            vertexCountsPerPolygon.append ( (int) numPolygonVertices );
        }
    }

    // --------------------------------------------
    void GeometryImporter::getPolygonsOffsetValues ( 
        const COLLADAFW::Polygons& polygons, 
        size_t& vertexOffset, 
        size_t& vertexSet, 
        size_t& maxOffset )
    {
        size_t inputCount;
        const COLLADAFW::InputSharedArray& inputArray = polygons.getInputArray ( inputCount );

        for ( size_t n=0; n<inputCount; ++n )
        {
            const COLLADAFW::InputShared& input = inputArray [ n ];

            size_t currentOffset = input.getOffset ();
            const COLLADAFW::InputSemantic::Semantic& semantic = input.getSemantic ();
            
            if ( semantic == COLLADAFW::InputSemantic::VERTEX )
            {
                vertexOffset = currentOffset;
                vertexSet = ( size_t ) input.getSet ();
            }
            if ( currentOffset > maxOffset ) maxOffset = currentOffset; 
        }
    }

    // --------------------------------------------
    void GeometryImporter::getPolygonsOffsetValues ( 
        const COLLADAFW::Polylist& polylist, 
        size_t &vertexOffset, 
        size_t &vertexSet, 
        size_t &maxOffset )
    {
        size_t polylistInputCount;
        const COLLADAFW::InputSharedArray& inputArray = polylist.getInputArray ( polylistInputCount );

        for ( size_t n=0; n<polylistInputCount; ++n )
        {
            const COLLADAFW::InputShared& polylistInput = inputArray [ n ];

            size_t currentOffset = polylistInput.getOffset ();
            const COLLADAFW::InputSemantic::Semantic& semantic = polylistInput.getSemantic ();
            if ( semantic == COLLADAFW::InputSemantic::VERTEX )
            {
                vertexOffset = currentOffset;
                vertexSet = ( size_t ) polylistInput.getSet ();
            }
            if ( currentOffset > maxOffset ) maxOffset = currentOffset; 
        }
    }

    // --------------------------------------------
    void GeometryImporter::createMesh ( 
        const size_t numVertices, 
        const size_t numPolygons, 
        const MFloatPointArray vertexArray, 
        const MIntArray vertexCountsPerPolygon, 
        const MIntArray polygonConnects )
    {
        cout << "numVertices = " << numVertices << endl;
        cout << "numPolygons = " << numPolygons << endl;
        cout << "vertexArray = " << vertexArray << endl;
        cout << "vertexCountsPerPolygon = " << vertexCountsPerPolygon << endl;
        cout << "polygonConnects = " << polygonConnects << endl << endl;

        // Create the Maya mesh node
        MFnMesh meshFn;
        MObject mesh = meshFn.create ( 
            ( int ) numVertices, ( int ) numPolygons, 
            vertexArray, vertexCountsPerPolygon, 
            polygonConnects, mTransformObject );

        xsNCName geometryName = mGeometryRef->getName ();
        meshFn.setName ( geometryName );
    }

    // --------------------------------------------
    void GeometryImporter::getVertexArray ( 
        const COLLADAFW::Source* positionsSource, 
        MFloatPointArray &vertexArray )
    {
        // Get informations about the current positions array.
        const COLLADAFW::FloatArrayElement& floatArray = positionsSource->getFloatArrayElement ();
        size_t arrayCount = floatArray.getCount ();
        const float* positions = floatArray.getValues ( arrayCount );

        const COLLADAFW::TechniqueCommon& techniqueCommon = positionsSource->getTechniqueCommon ();
        const COLLADAFW::Accessor& accessor = techniqueCommon.getAccessor ();
        unsigned int accessorCount = accessor.getCount ();
        unsigned int accessorStride = accessor.getStride ();

        // This should include all the vertices in the mesh, and no extras.
        size_t index = 0;
        for ( size_t n=0; n<accessorCount; ++n )
        {
            if ( accessorStride != 3 ) 
            {
                throw new COLLADADomHelper::Exception ( COLLADADomHelper::Exception::ERR_INTERNAL_ERROR, 
                    "Accessor stride of position element not valid!", "GeometryImporter::getVertexArray(..)" );
            }
            vertexArray.append ( positions [ index ], positions [ index+1 ], positions [ index+2 ], 0.0f );
            index += ( size_t ) accessorStride;
        }
    }

    // --------------------------------------------
    void GeometryImporter::getVertexInformations ( 
        const COLLADAFW::Polygons& polygons, 
        const size_t numPolygons, 
        const size_t numInputElements, 
        const size_t vertexOffset, 
        size_t& numVertices,
        MIntArray& vertexCountsPerPolygon, 
        MIntArray &polygonConnects )
    {
        // Contains a list of polygon lists. Each polygon list contains a list of UInts 
        // that specifies the vertex attributes (indices) for an individual polygon.
        size_t numPPolygons;
        COLLADAFW::PArray pArray = polygons.getPArray ( numPPolygons );

        // Go through the primitives, get the vertex connections for each 
        // polygon and write them into the array of vertex connections. 
        for ( size_t m=0; m<numPPolygons; ++m )
        { 
            // Get the list of vertices of the current polygon.
            const COLLADAFW::PElement& pElement = pArray [ m ];

            // Contains a list of integers that specify the vertex attributes
            // (indices) for an individual polygon. 
            size_t numAttributes;
            const COLLADAFW::UIntValuesArray& vertexAttributes = pElement.getUIntValuesArray ( numAttributes );

            // Get the number of vertices of the current polygon.
            size_t numPolygonVertices = numAttributes / numInputElements;

            // Write the number of vertices of the current polygon in the list.
            vertexCountsPerPolygon.append ( ( int ) numPolygonVertices );

            // Add the count to the sum of all vertices.
            numVertices += numPolygonVertices;

            // For every vertex in the current polygon, get the connection of 
            // the current vertex polygon to the vertices array.
            for ( size_t n=0; n<numPolygonVertices; ++n )
            { 
                // TODO Be careful: offset and set is something different!
                // The current index for the vertex connection.
                size_t vertexIndex = n * numInputElements + vertexOffset;
                int connection = ( int ) vertexAttributes [ vertexIndex ];
                polygonConnects.append ( connection );
            }
        }

        // Contains a list of polygon hole lists. Each polygon hole list contains a list of UInts 
        // that specifies the vertex attributes (indices) for an individual polygon.
        size_t numPh;
        COLLADAFW::PHArray phArray = polygons.getPHArray ( numPh );

    }

    // --------------------------------------------
    void GeometryImporter::getVertexConnections ( 
        const COLLADAFW::Polylist& polylist, 
        const size_t numPolygons, 
        const MIntArray vertexCountsPerPolygon, 
        const size_t maxOffset, 
        const size_t vertexOffset, 
        MIntArray &polygonConnects )
    {
        // Contains a list of integers that specify the vertex attributes
        // (indices) for an individual polylist. ("p" stands for "primitive".)
        const COLLADAFW::PElement& pElement = polylist.getPElement ();

        // Get the values of the current p element.
        size_t numAttributes;
        COLLADAFW::UIntValuesArray vertexAttributes = pElement.getUIntValuesArray ( numAttributes );

        // Go through all polygons
        for ( size_t m=0; m<numPolygons; ++m )
        { 
            // For every vertex in the current polygon, get the connection of 
            // the current vertex polygon to the vertices array.
            size_t vertexCount = vertexCountsPerPolygon [ ( unsigned int ) m ];
            for ( size_t n=0; n<vertexCount; ++n )
            { 
                // TODO Be careful: offset and set is something different!
                // The current index for the vertex connection.
                size_t vertexIndex = n * ( maxOffset + 1 ) + vertexOffset;
                int connection = ( int ) vertexAttributes [ vertexIndex ];
                polygonConnects.append ( connection );
            }
        }
    }


}