/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_VERTICES_UTIL_H__
#define __COLLADA_VERTICES_UTIL_H__

#include "HelperPrerequisites.h"
#include <set>


namespace COLLADADH 
{

    class VerticesUtil;

    struct Vertex
    {
        double position[3];
        double normal[3];
        double color[4];
        double uv[2];

        Vertex();
    };

    bool operator==(const Vertex& v1, const Vertex& v2);
    bool operator<=(const Vertex& v1, const Vertex& v2);
    bool operator>=(const Vertex& v1, const Vertex& v2);
    bool operator>(const Vertex& v1, const Vertex& v2);
    bool operator<(const Vertex& v1, const Vertex& v2);


    typedef std::map<COLLADADH::Vertex, size_t> VertexIndexMap;
    typedef std::pair<VertexIndexMap::iterator, bool> VertexIndexMapResult;

    /** An iterator over vertices. */
    class VerticesIterator
    {
    private:
        VerticesUtil* mVertices;
        size_t mCount;
        size_t mCurrent;        

    public:
        VerticesIterator(VerticesUtil* vertices);
        VerticesIterator(const VerticesIterator& iterator);
        virtual ~VerticesIterator();

        bool hasNext() const;
        
        void getNext(double position[3], double normal[3], double color[4], double uv[2]);
        void getNext(Vertex& vertex);
        
        void peakNext(double position[3], double normal[3], double color[4], double uv[2]);
        void peakNext(Vertex& vertex);

        const VerticesIterator& operator=(const VerticesIterator& iterator);
    };

    /// A vector of indices.
    typedef std::vector<size_t> IndexVector;
    /// A set of indices.
    typedef std::set<size_t> IndexSet;

    /** Utility for processing <vertices>. */
    class VerticesUtil
    {
    private:
        domVertices* mVertices;

    public:
        static size_t getVertexCount(const domVerticesRef& vertices);

        VerticesUtil(const domVerticesRef& vertices);
        virtual ~VerticesUtil();

        void deleteVertex(size_t index);
        
        void deleteVertices(const IndexSet& indices);
        
        VerticesIterator getIterator();
        
        void getVertex(size_t index, double position[3], double normal[3], double color[4], double uv[2]);
        
        void getVertex(size_t index, Vertex& vertex);
        
        size_t getVertexCount() const;

        void setVertex(size_t index, double position[3], double normal[3], double color[4], double uv[2]);
        
        void setVertex(size_t index, Vertex& vertex);        
    };
} // namespace CPF

#endif //  __COLLADA_VERTICES_UTIL_H__
