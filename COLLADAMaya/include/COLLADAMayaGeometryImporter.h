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

#ifndef __COLLADA_MAYA_GEOMETRY_IMPORTER_H__
#define __COLLADA_MAYA_GEOMETRY_IMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

#include "COLLADAFWMesh.h"

#include "MayaDMTypes.h"
#include "MayaDMMesh.h"

#include <map>
#include <vector>


namespace COLLADAMaya
{

    /** Declares the importer implementation to import the geometries. */
    class GeometryImporter : public BaseImporter
    {

    private:

        /** The current transform object, for which the geometries should be created. */
        MObject mTransformObject;

        /** Pointer to the current framework geometry object. */
        const COLLADAFW::Geometry* mGeometry;

    public:

        /** Constructor. */
        GeometryImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
        virtual ~GeometryImporter () {}

        /** Imports the geometry element. */
        bool importGeometry ( const COLLADAFW::Geometry* geometry );

    private:

        /** 
         * Imports the data of the current mesh element. 
         */
        bool importMesh ( const COLLADAFW::Mesh* mesh );

        /*
         *	Write the face informations into the maya file.
         */
        bool writeFaces ( 
            const COLLADAFW::Mesh* mesh, 
            const std::map<COLLADAFW::Edge,int>& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the face values of the given primitive element into the maya file.
         */
        bool appendPolyFaces ( 
            const COLLADAFW::MeshPrimitive* primitiveElement, 
            const std::map<COLLADAFW::Edge,int>& edgeIndicesMap, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the edges into the maya file.
         */
        bool writeEdges ( 
            const std::vector<COLLADAFW::Edge> &edgeIndices, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the uv coordinates into the maya file.
         */
        bool writeUVCoords ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode );

        /*
         *	Write the normals values into the maya file.
         */
        bool writeNormals ( const COLLADAFW::Mesh* mesh, MayaDM::Mesh &meshNode );

        /*
         *	Appends the normal values of all mesh primitive elements into the maya file.
         */
        bool appendNormalValues ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode );

        /*
         *	Write the vertex position values into the maya file.
         */
        bool writeVertexPositions ( 
            const COLLADAFW::Mesh* mesh, 
            MayaDM::Mesh &meshNode );

        /*
         * Gets the index value of the current edge. 
         * Returns false, if the search for the index value was not sucessful.
         */
        bool getEdgeIndex ( 
            const COLLADAFW::Edge& edge, 
            const std::map<COLLADAFW::Edge,int>& edgeIndicesMap, 
            int& edgeIndex );
    };

}

#endif // __COLLADA_MAYA_GEOMETRY_IMPORTER_H__