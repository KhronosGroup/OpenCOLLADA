/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MESH_READER_H__
#define __COLLADA_MESH_READER_H__

#include "COLLADADHStableHeaders.h"
#include "COLLADADHBaseLoader.h"

#include "COLLADAFWMesh.h"

#include "dom/domMesh.h"


namespace COLLADADH
{

    /** Reads the geometry of the dom and creates a COLLADAFW::Mesh object. */
    class MeshLoader : BaseLoader
    {

    private:

        /** A pointer to the current mesh object to import. */
        domMeshRef mMeshRef;

        /** The COLLADAFramework mesh object. */
        COLLADAFW::Mesh* mMesh;

    public:

        /** Constructor. */
        MeshLoader ( Loader* colladaLoader, domCOLLADA* colladaRoot ) : BaseLoader ( colladaLoader, colladaRoot ) {}

        /** Destructor. */
        virtual ~MeshLoader () {}

        /** 
         * Reads the data of the domMesh and creates and fills a new  COLLADAFramework mesh object. 
         */
        COLLADAFW::Mesh* createMeshObject ( domMeshRef& meshRef );

    private:

        /**
        * Fills the COLLADAFramework name array, if the name array in the domSourceRef exists.
        * @param sourceRef Pointer to the domSourceRef.
        * @param source The COLLADAFramework name array to fill.
        */
        COLLADAFW::SourceBase* createNameArrayElementSource ( const domSourceRef& sourceRef );
        COLLADAFW::SourceBase* createBoolArrayElementSource ( const domSourceRef& sourceRef );
        COLLADAFW::SourceBase* createIntArrayElementSource ( const domSourceRef& sourceRef );
        COLLADAFW::SourceBase* createFloatArrayElementSource ( const domSourceRef& sourceRef );
        COLLADAFW::SourceBase* createIDREFArrayElementSource ( const domSourceRef& sourceRef );

        /** One vertices input must specify semantic="POSITION" to establish the 
        topological identity of each vertex in the mesh. */
        domSourceRef getPositionsRef ();

        /**
         * Create the mesh from the current polylist.
         * @param polylistArray The dom array with the polylists.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillMeshPolylistArray ( 
            const domPolylist_Array& polylistArray, 
            size_t& faceIndex );

        /**
         * Fills the primitives array of the polylist.
         * @param polylistRef Reference to the current dom polylist element.
         * @param polylist The COLLADAFramework polylist element.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillPolylistPrimitivesArray ( 
            const domPolylistRef polylistRef, 
            COLLADAFW::Polylist& polylist, 
            size_t& faceIndex );

        /**
         * Fills the polylist polygons vertex count list.
         */
        void fillPolylistVCountArray ( 
            const domPolylistRef polylistRef, 
            COLLADAFW::Polylist& polylist );

        /** Create the mesh from the current polygons array. */
        /**
         * Create the mesh from the current polygons array.
         * @param polygonsArray Array with the dom polygons.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillMeshPolygonsArray ( 
            const domPolygons_Array& polygonsArray, 
            size_t& faceIndex );

        /**
         * Fills all the primitives arrays of the polygons element (p and ph elements).
         * @param polygonsRef Reference to the dom polygons element.
         * @param polygons Reference to the COLLADAFramwork polygons element.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillPolygonsPrimitivesElements ( 
            const domPolygonsRef polygonsRef, 
            COLLADAFW::Polygons& polygons, 
            size_t& faceIndex );

        /**
         * Fills the p list element values.
         * @param pRef Reference to the current dom element.
         * @param pElement Reference to the COLLADAFramework element.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillPListValues ( 
            const domPRef pRef, 
            COLLADAFW::PElement &pElement, 
            size_t& faceIndex );

        /**
         * Fills the h list element values.
         * @param hRef Reference to the current dom element.
         * @param hElement Reference to the COLLADAFramework element.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillHListValues ( 
            const domPolygons::domPh::domHRef hRef, 
            COLLADAFW::HElement &hElement, 
            size_t& faceIndex );

        /**
         * Fills the p elements of the polygon element.
         * @param polygonsRef Reference to the dom polygons element.
         * @param polygons Reference to the COLLADAFramwork polygons element.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillPolygonsPArrays ( 
            const domPolygonsRef polygonsRef, 
            COLLADAFW::Polygons &polygons, 
            size_t& faceIndex );

        /**
         * Fills the ph elements of the polygon element.
         * @param polygonsRef Reference to the dom polygons element.
         * @param polygons Reference to the COLLADAFramwork polygons element.
         * @param faceIndex Reference to a size_t of the next face index to use. 
         *                  Has to be count up for every added face.
         */
        void fillPolygonsPHArrays ( 
            const domPolygonsRef polygonsRef, 
            COLLADAFW::Polygons &polygons, 
            size_t& faceIndex );

        /** Fills the input array of the polylist. */
        void fillPolylistInputArray ( 
            const domPolylistRef polylistRef, 
            COLLADAFW::Polylist& polylist );

        /** Fills the input array of the polygons. */
        void fillPolygonsInputArray ( 
            const domPolygonsRef polygonsRef, 
            COLLADAFW::Polygons& polygons );

        /** Fills the input array elements. */
        void fillInputArray ( 
            const domInputLocalOffset_Array& domInputArray, 
            COLLADAFW::InputSharedArray& inputArray );

        /**
        * Fill the mesh vertex element.
        */
        void fillVertexElement ();

        /**
         * Reads all collada dae source objects and writes it in the COLLADAFramework source object.
         */
        void fillSourceElements ();

        /**
         * Fills the current COLLADAFramework source object with the data of the current source 
         * object of the collada dae file.
         * @param sourceRef The dom source element.
         * @param source The COLLADAFramework source element.
         */
        COLLADAFW::SourceBase* createSourceElement ( const domSourceRef& sourceRef );

        /**
         * Fills the current technique_common data.
         * @param sourceRef The dom source element.
         * @param source The COLLADAFramework source element.
         */
        void fillTechniqueCommon ( const domSourceRef& sourceRef, COLLADAFW::SourceBase* source );
    };
}

#endif // __COLLADA_MESH_READER_H__