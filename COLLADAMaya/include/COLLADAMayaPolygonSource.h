/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_POLYGON_SOURCE_H__
#define __COLLADA_MAYA_POLYGON_SOURCE_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaGeometryPolygonExporter.h"


namespace COLLADAMaya
{

    /** The list of v-counts. */
    typedef std::vector<unsigned long> VCountList;

    /**
    * The class for the lists of vertex indexes of each polygon.
    */
    class PolygonSource
    {

    public:

        /**
        * Defines the export binding type of geometric primitives and vertex attributes for a mesh.
        */
        enum exportType
        {
            POLYLIST = 0,   // Export a polylist
            POLYGONS,       // Export a polygon (just used with holes)
            TRIANGLES       // Export triangles
        };


    private:

        /** The export type of the current polygon (POLYLIST, POLYGONS OR TRIANGLES) */
        uint mExportType;

        /** The list with the count of vertex attributes of the polygon. */
        VCountList mVertexCountList;

        /** The list of the vertex attributes of the polygon. */
        Sources mVertexAttributes;

        /** Vector with the number of vertexes for every face. */
        std::vector<uint> mFaceVertexCounts;

        /** Vector with the indices of faces which are holes. */
        std::vector<uint> mHoleFaces;

        /** True, if the current polygon has one or more holes. */
        bool mIsHoled;

        /** To store the number of indices (don't hold the indices directly) */
        uint numVertexIndexes;

    public:

        /** Constructor */
        PolygonSource ( const Sources& vertexAttributes, uint exportType=POLYLIST )
            : mVertexAttributes ( vertexAttributes )
            , mExportType ( exportType )
            , mIsHoled ( false )
        {}

        /** Destructor */
        virtual ~PolygonSource(){};

        /**
        * Returns a reference to the list with the counts of vertex attributes of the polygon.
        * @return std::vector<unsigned long>& 
        *          Reference to the list with the counts of vertex attributes of the polygon. 
        */
        VCountList& getVertexCountList() { return mVertexCountList; }

        /**
        * Returns the list with the counts of vertex attributes of the polygon.
        * @return std::vector<unsigned long>& 
        *          The list with the counts of vertex attributes of the polygon. 
        */
        const VCountList getVertexCountList() const { return mVertexCountList; }

        /**
        * Returns true, if the current polygon has one or more holes.
        * @return bool True, if the current polygon has one or more holes.
        */
        bool isHoled() const { return mIsHoled; }

        /**
        * Set the @mIsHoled flag.
        * @param holed Value for the @mIsHoled flag.
        */
        void isHoled( bool holed ) { mIsHoled = holed; }

        /**
        * Returns the list of the vertex attributes of the polygon.
        * @return Sources The list of the vertex attributes of the polygon.
        */
        const Sources& getVertexAttributes() const { return mVertexAttributes; }

        /**
        * Returns a reference to the list of the vertex attributes of the polygon.
        * @return Sources& Reference to the list of the vertex attributes of the polygon.
        */
        Sources& getVertexAttributes() { return mVertexAttributes; }

        /**
        * Returns a reference to the Vector with the number of vertexes for every face.
        * @return std::vector<uint> 
        *              Reference to the Vector with the number of vertexes for every face.
        */
        std::vector<uint>& getFaceVertexCounts() { return mFaceVertexCounts; }

        /**
        * Returns a const of the Vector with the number of vertexes for every face.
        * @return const std::vector<uint>
        *          Const of the Vector with the number of vertexes for every face.
        */
        const std::vector<uint> getFaceVertexCounts() const { return mFaceVertexCounts; }

        /** Vector with the indices of faces which are holes. */
        /**
        * Returns a reference to the vector with the indices of faces which are holes.
        * @return std::vector<uint>&
        *          Reference to the vector with the indices of faces which are holes.
        */
        std::vector<uint>& getHoleFaces() { return mHoleFaces; }

        /**
        * Returns the const vector with the indices of faces which are holes.
        * @return const std::vector<uint>
        *          Const vector with the indices of faces which are holes.
        */
        const std::vector<uint> getHoleFaces() const { return mHoleFaces; }

    };

    typedef std::vector<PolygonSource*> PolygonSourceList;
}

#endif //__COLLADA_MAYA_POLYGON_SOURCE_H__
