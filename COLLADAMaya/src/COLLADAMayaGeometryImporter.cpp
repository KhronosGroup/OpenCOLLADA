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
        if ( meshRef != NULL ) importMesh ( meshRef );
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( const COLLADAFW::Mesh* mesh )
    {
        size_t polygonsCount;
        const COLLADAFW::Polylist* polylistArray;
        polylistArray = mesh->getPolylistArray ( polygonsCount );
        cout << "read polylistList = " << polylistArray << endl;
        
        // Get the material name
        String materialName = polylistArray->getMaterial ();

        // Get the polygons count
        size_t count = polylistArray->getCount ();

        // Get the input array.
        size_t inputArraySize;
        COLLADAFW::InputArray inputArray;
        inputArray = polylistArray->getInputArray ( inputArraySize );

        // Get the vcount list
        size_t vCountArraySize;
        COLLADAFW::Polylist::VCountArray vCountArray;
        vCountArray = polylistArray->getVCountArray ( vCountArraySize );

        // Get the p list
        size_t pArraySize;
        COLLADAFW::Polylist::PArray pArray;
        pArray = polylistArray->getPArray ( pArraySize );

        return true;
    }

    // --------------------------------------------
    bool GeometryImporter::importMesh ( domMeshRef& meshRef )
    {
        COLLADADomHelper::MeshReader meshReader ( getDaeDocument () );
        meshReader.createMeshObject ( meshRef );

        // Set the current mesh.
        mMeshRef = meshRef;

        // Get the array of polylists
        domPolylist_Array polylistArray = mMeshRef->getPolylist_array ();
        if ( polylistArray.getCount () != 0 )
        {
            createMeshFromPolylist ( polylistArray );
        }

        // Get the array of polygons
        domPolygons_Array polygonsArray = mMeshRef->getPolygons_array ();
        if ( polygonsArray.getCount () != 0 )
        {
            createMeshFromPolygons (  polygonsArray  );
        }

        meshRef->getTriangles_array ();
        meshRef->getTrifans_array ();
        meshRef->getTristrips_array ();

        domSource_Array sourceArray = mMeshRef->getSource_array ();
        domSourceRef sourceRef = sourceArray.get ( 0 );
        xsNCName sourceName = sourceRef->getName ();

        return true;
    }

    // --------------------------------------------
    void GeometryImporter::createMeshFromPolylist ( domPolylist_Array& polylistArray ) 
    {
        // Fill the COLLADAFramework data

        // TODO Create a COLLADAFramework::Mesh element with 
        // the dom from the collada document data.
        COLLADAFW::Mesh* mesh = new COLLADAFW::Mesh ();

        // Fill the required attributes to create the current mesh.

        // The number of vertices and polygons.
        size_t numVertices = 0, numPolygons = 0;
        // Array of vertex counts for each polygon.
        MFloatPointArray vertexArray;
        // Array of vertex counts for each polygon.
        MIntArray vertexCountsPerPolygon;
        // Go through the primitives, get the vertex connections for each 
        // polygon and write them into the array of vertex connections. 
        MIntArray polygonConnects;


        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.
        domSourceRef positionsRef = getPositionsRef ();

        domFloat_arrayRef positionsArray = positionsRef->getFloat_array ();
        domListOfFloats positions = positionsArray->getValue ();
        domAccessorRef posAccessorRef = positionsRef->getTechnique_common ()->getAccessor ();
        domUint posAccessorCount = posAccessorRef->getCount ();
        domUint posAccessorStride = posAccessorRef->getStride ();

        // The number of polylist elements in the current mesh
        size_t polylistCount = polylistArray.getCount ();

        // Fill the COLLADAFramework data
        COLLADAFW::Polylist* polylistList = new COLLADAFW::Polylist [ polylistCount ]; 
        mesh->setPolylistArray ( polylistList, polylistCount );

        for ( size_t i=0; i<polylistCount; ++i )
        {
            // Create the polylist element.
            COLLADAFW::Polylist polylist;

            // Create a polylist element for the framework mesh object.
            polylistList [ i ] = polylist;

            // Get the current polylist element
            domPolylistRef polylistRef = polylistArray.get ( i );
            numPolygons = ( size_t ) polylistRef->getCount ();
            // Fill the COLLADAFramework data
            polylist.setCount ( numPolygons );

            // TODO Assign the material.
            xsNCName materialName = polylistRef->getMaterial ();
            // Fill the COLLADAFramework data
            polylist.setMaterial ( materialName );

            // Fill the COLLADAFramework pList data
            domPRef pRef = polylistRef->getP ();
            domListOfUInts domPList = pRef->getValue ();
            size_t pListSize = domPList.getCount ();
            COLLADAFW::Polylist::PArray pList = new int [ pListSize ];
            for ( size_t m=0; m<pListSize; ++m )
            {
                pList [ m ] = ( int ) domPList.get ( m );
            }
            polylist.setPArray ( pList, pListSize );

            // Fill the COLLADAFramework vCountList data
            domPolylist::domVcountRef vCountRef = polylistRef->getVcount ();
            domListOfUInts domVCountList = vCountRef->getValue ();
            size_t vCountListSize = domVCountList.getCount ();
            COLLADAFW::Polylist::VCountArray vCountList = new int [ vCountListSize ];
            for ( size_t m=0; m<vCountListSize; ++m )
            {
                vCountList [ m ] = ( int ) domVCountList.get ( m );
            }
            polylist.setVCountArray ( vCountList, vCountListSize );

            // Fill the array of vertex counts for each polygon.
            getVertexArray ( positionsRef, vertexArray );

            // Fill the list with the count of vertices for every polygon and 
            // calculate the number of polygons and the sum of vertices for all polygons.
            getVertexCountsPerPolygon ( polylistRef, vertexCountsPerPolygon, numVertices );

            // Get the polylists offset of the vertices 
            // and the maximum offset in the polygons list.
            size_t vertexOffset, vertexSet, maxOffset = 0;
            getPolygonsOffsetValues(polylistRef, vertexOffset, vertexSet, maxOffset);

            // Go through the primitives, get the vertex connections for each 
            // polygon and write them into the array of vertex connections. 
            getVertexConnections ( polylistRef, numPolygons, vertexCountsPerPolygon, 
                maxOffset, vertexOffset, polygonConnects );
        }

        cout << "write polylistList = " << polylistList << endl;

        cout << "Create mesh from Polylist: " << endl;
        createMesh ( numVertices, numPolygons, vertexArray, 
            vertexCountsPerPolygon, polygonConnects );

        importMesh ( mesh );
    }

    // --------------------------------------------
    domInputLocal_Array GeometryImporter::getVerticesInputArray ()
    {
        // Get the vertices (there is only one per mesh!)
        domVerticesRef verticesRef = mMeshRef->getVertices ();
        xsNCName verticesName = verticesRef->getName ();
        xsID verticesId = verticesRef->getID ();

        return verticesRef->getInput_array ();
    }

    // --------------------------------------------
    domSourceRef GeometryImporter::getPositionsRef ()
    {
        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.

        // Get the vertices input array (there is only one per mesh).
        domInputLocal_Array verticesInputArray = getVerticesInputArray ();

        // Get the point positions of the vertexes
        daeDocument* daeDocument = getDaeDocument ();
        domURIFragmentType positionUri ( * ( daeDocument->getDAE () ) );
        size_t numOfInputs = verticesInputArray.getCount ();
        for ( size_t j=0; j<numOfInputs; ++j )
        {
            domInputLocalRef vertexInputRef = verticesInputArray.get ( j );
            xsNMTOKEN semantic = vertexInputRef->getSemantic ();
            if ( COLLADASW::Utils::equalsIgnoreCase ( semantic, COLLADASW::CSWC::CSW_SEMANTIC_POSITION ) )
            {
                positionUri = vertexInputRef->getSource ();
            }
        }
        if ( positionUri.getState() != daeURI::uri_success )
        {
            positionUri.setContainer( getDaeDocument ()->getDomRoot() );
            positionUri.resolveElement();
        }

        return daeSafeCast<domSource>( positionUri.getElement() );
    }

    // --------------------------------------------
    void GeometryImporter::createMeshFromPolygons ( domPolygons_Array& polygonsArray )
    {
        // Fill the required attributes to create the current mesh.

        // The number of vertices and polygons.
        size_t numVertices = 0, numPolygons = 0;
        // Array of vertex counts for each polygon.
        MFloatPointArray vertexArray;
        // Array of vertex counts for each polygon.
        MIntArray vertexCountsPerPolygon;
        // Go through the primitives, get the vertex connections for each 
        // polygon and write them into the array of vertex connections. 
        MIntArray polygonConnects;

        // One vertices input must specify semantic="POSITION" to establish the 
        // topological identity of each vertex in the mesh.
        domSourceRef positionsRef = getPositionsRef ();

        // Go through all poygons of the current mesh.
        size_t numPolygonsArrays = polygonsArray.getCount ();
        for ( size_t i=0; i<numPolygonsArrays; ++i )
        {
            // Get a reference to the current polygons element.
            domPolygonsRef polygonsRef = polygonsArray.get ( i );
            numPolygons = ( size_t ) polygonsRef->getCount ();

            // TODO Assign the material.
            xsNCName materialName = polygonsRef->getMaterial ();

            // Fill the array of vertex counts for each polygon.
            getVertexArray ( positionsRef, vertexArray );

            // Get the polylists offset of the vertices 
            // and the maximum offset in the polygons list.
            size_t vertexOffset, vertexSet, maxOffset = 0;
            getPolygonsOffsetValues ( polygonsRef, vertexOffset, vertexSet, maxOffset );

            // Fill the list with the count of vertices for every polygon and 
            // calculate the number of polygons and the sum of vertices for all polygons.
            getVertexCountsPerPolygon ( polygonsRef, maxOffset, 
                                        vertexCountsPerPolygon, numVertices );

            // Go through the primitives, get the vertex connections for each 
            // polygon and write them into the array of vertex connections. 
            getVertexConnections ( polygonsRef, numPolygons, vertexCountsPerPolygon, 
                                   maxOffset-1, vertexOffset, polygonConnects );
        }

        cout << "Create mesh from Polygons: " << endl;
        createMesh ( numVertices, numPolygons, vertexArray, 
                     vertexCountsPerPolygon, polygonConnects );
    }

    // --------------------------------------------
    void GeometryImporter::getVertexCountsPerPolygon ( 
        const domPolygonsRef polygonsRef, 
        const size_t numInputElements, 
        MIntArray& vertexCountsPerPolygon, 
        size_t& numVertices )
    {
        // Contains a list of polygon lists. Each polygon list contains a list of UInts 
        // that specifies the vertex attributes (indices) for an individual polygon.
        domP_Array pArray = polygonsRef->getP_array ();

        // Get the number of polygons in the current polygons element.
        size_t numPolygons = pArray.getCount ();

        // Go through each polygon and count the vertices 
        // per polygon and the sum of all vertices.
        for ( size_t n=0; n<numPolygons; ++n )
        {
            // Get the list of vertices of the current polygon.
            domPRef pRef = pArray.get ( n );
            domListOfUInts pValues = pRef->getValue ();

            // Get the number of vertices of the current polygon
            size_t numPolygonVertices = pValues.getCount () / numInputElements;

            // Count the number of all vertices.
            numVertices += numPolygonVertices;

            // Write the number of vertices of the current polygon in the list.
            vertexCountsPerPolygon.append ( ( int ) numPolygonVertices );
        }
    }

    // --------------------------------------------
    void GeometryImporter::getVertexCountsPerPolygon ( 
        const domPolylistRef polylistRef, 
        MIntArray& vertexCountsPerPolygon, 
        size_t& numVertices )
    {
        // Contains a list of integers, each specifying the number of
        // vertices for one polygon described by the <polylist> element.
        domPolylist::domVcountRef vcountRef = polylistRef->getVcount ();
        domListOfUInts vCountList = vcountRef->getValue ();

        // Get the number of polygons in the current polylist.
        size_t numPolygons = vCountList.getCount ();

        // Go through each polygon and count the vertices 
        // per polygon and the sum of all vertices.
        for ( size_t n=0; n<numPolygons; ++n )
        {
            // Get the number of vertices of the current polygon
            size_t numPolygonVertices = ( size_t ) vCountList.get ( n );

            // Count the number of all vertices.
            numVertices += numPolygonVertices;

            // Write the number of vertices of the current polygon in the list.
            vertexCountsPerPolygon.append ( (int) numPolygonVertices );
        }
    }

    // --------------------------------------------
    void GeometryImporter::getPolygonsOffsetValues ( 
        const domPolygonsRef polygonsRef, 
        size_t& vertexOffset, 
        size_t& vertexSet, 
        size_t& maxOffset )
    {
        domInputLocalOffset_Array polygonsInputArray;
        polygonsInputArray = polygonsRef->getInput_array ();
        size_t polylistInputCount = polygonsInputArray.getCount ();
        for ( size_t n=0; n<polylistInputCount; ++n )
        {
            domInputLocalOffsetRef polygonsInputRef;
            polygonsInputRef = polygonsInputArray.get ( n );
            size_t currentOffset = ( size_t ) polygonsInputRef->getOffset ();
            xsNMTOKEN semantic = polygonsInputRef->getSemantic ();
            if ( COLLADASW::Utils::equalsIgnoreCase ( semantic, COLLADASW::CSWC::CSW_SEMANTIC_VERTEX ) )
            {
                vertexOffset = currentOffset;
                vertexSet = ( size_t ) polygonsInputRef->getSet ();
            }
            if ( currentOffset > maxOffset ) maxOffset = currentOffset; 
        }
    }

    // --------------------------------------------
    void GeometryImporter::getPolygonsOffsetValues ( 
        const domPolylistRef polylistRef, 
        size_t &vertexOffset, 
        size_t &vertexSet, 
        size_t &maxOffset )
    {
        domInputLocalOffset_Array polylistInputArray;
        polylistInputArray = polylistRef->getInput_array ();
        size_t polylistInputCount = polylistInputArray.getCount ();
        for ( size_t n=0; n<polylistInputCount; ++n )
        {
            domInputLocalOffsetRef polylistInputRef;
            polylistInputRef = polylistInputArray.get ( n );
            size_t currentOffset = ( size_t ) polylistInputRef->getOffset ();
            xsNMTOKEN semantic = polylistInputRef->getSemantic ();
            if ( COLLADASW::Utils::equalsIgnoreCase ( semantic, COLLADASW::CSWC::CSW_SEMANTIC_VERTEX ) )
            {
                vertexOffset = currentOffset;
                vertexSet = ( size_t ) polylistInputRef->getSet ();
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
        const domSourceRef positionsRef, 
        MFloatPointArray &vertexArray )
    {
        // Get informations about the current positions array.
        domFloat_arrayRef positionsArray = positionsRef->getFloat_array ();
        domListOfFloats positions = positionsArray->getValue ();
        domAccessorRef posAccessorRef = positionsRef->getTechnique_common ()->getAccessor ();
        domUint posAccessorCount = posAccessorRef->getCount ();
        domUint posAccessorStride = posAccessorRef->getStride ();

        // This should include all the vertices in the mesh, and no extras.
        size_t positionIndex = 0;
        for ( size_t n=0; n<posAccessorCount; ++n )
        {
            domFloat one, two, three;
            // TODO different accessor strides!
            if ( posAccessorStride == 3 ) 
            {
                positions.get3at ( positionIndex, one, two, three );
                vertexArray.append ( (float) one, (float) two, (float) three, 0.0f );
                positionIndex += ( size_t ) posAccessorStride;
            }
        }
    }

    // --------------------------------------------
    void GeometryImporter::getVertexConnections ( 
        const domPolygonsRef polygonsRef, 
        const size_t numPolygons, 
        const MIntArray vertexCountsPerPolygon, 
        const size_t maxOffset, 
        const size_t vertexOffset, 
        MIntArray &polygonConnects )
    {
        // Contains a list of polygon lists. Each polygon list contains a list of UInts 
        // that specifies the vertex attributes (indices) for an individual polygon.
        domP_Array pArray = polygonsRef->getP_array ();
        size_t numPPolygons = pArray.getCount ();

        // Go through the primitives, get the vertex connections for each 
        // polygon and write them into the array of vertex connections. 
        for ( size_t m=0; m<numPPolygons; ++m )
        { 
            // Contains a list of integers that specify the vertex attributes
            // (indices) for an individual polygon. ("p" stands for "primitive".)
            domPRef pRef = pArray.get ( m );
            domListOfUInts vertexAttributes = pRef->getValue ();
            size_t numAttributes = vertexAttributes.getCount ();

            // For every vertex in the current polygon, get the connection of 
            // the current vertex polygon to the vertices array.
            size_t vertexCount = vertexCountsPerPolygon [ ( unsigned int ) m ];
            for ( size_t n=0; n<vertexCount; ++n )
            { 
                // TODO Be careful: offset and set is something different!
                // The current index for the vertex connection.
                size_t vertexIndex = n * ( maxOffset + 1 ) + vertexOffset;
                int connection = ( int ) vertexAttributes.get ( vertexIndex );
                polygonConnects.append ( connection );
            }
        }

        // Contains a list of polygon hole lists. Each polygon hole list contains a list of UInts 
        // that specifies the vertex attributes (indices) for an individual polygon.
        domPolygons::domPh_Array phArray = polygonsRef->getPh_array ();
        size_t numPh = phArray.getCount ();
    }

    // --------------------------------------------
    void GeometryImporter::getVertexConnections ( 
        const domPolylistRef polylistRef, 
        const size_t numPolygons, 
        const MIntArray vertexCountsPerPolygon, 
        const size_t maxOffset, 
        const size_t vertexOffset, 
        MIntArray &polygonConnects )
    {
        // Contains a list of integers that specify the vertex attributes
        // (indices) for an individual polylist. ("p" stands for "primitive".)
        domPRef pRef = polylistRef->getP ();
        domListOfUInts vertexAttributes = pRef->getValue ();
        size_t numAttributes = vertexAttributes.getCount ();

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
                int connection = ( int ) vertexAttributes.get ( vertexIndex );
                polygonConnects.append ( connection );
            }
        }
    }

}