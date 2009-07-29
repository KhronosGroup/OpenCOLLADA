/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_EDGE_H__
#define __COLLADAFW_EDGE_H__

#include "COLLADAFWPrerequisites.h"

#include <assert.h>

namespace COLLADAFW
{

    /*
    * An edge contains two int values, which contains the vertex indices of the points, 
    * which descripe the edge.
    */
    class Edge
    {
    private:

        /** The vertex indices of the points, which descripe the edge. */
        int mVertexIndices[2];

    public:

        /** Constructor. */
        Edge () 
        {
            mVertexIndices[0] = -1;
            mVertexIndices[1] = -1;
        }

        /** Constructor. */
        Edge ( int index1, int index2 ) 
        {
            mVertexIndices[0] = index1;
            mVertexIndices[1] = index2;
        }

        /** Destructor. */
        virtual ~Edge () {}

        /** Set the edge vertex indices sorted. */
        void setVertexIndices ( int index1, int index2 ) 
        {
            mVertexIndices[0] = index1;
            mVertexIndices[1] = index2;
        }

        int operator[](size_t i) const
        {
            assert( i < 2 );
            return mVertexIndices [i];
        }

        bool operator==(const Edge& e2) const
        {
            if ( (*this)[0] != e2[0] ) return false;
            if ( (*this)[1] != e2[1] ) return false;

            return true;
        }

        bool operator<(const Edge& e2) const
        {
            if ( (*this)[0] > e2[0] ) return false;
            if ( (*this)[0] == e2[0] ) 
            {
                if ( (*this)[1] >= e2[1] ) return false;
            }
            return true;
        }

    };

} // namespace COLLADAFW

#endif // __COLLADAFW_EDGE_H__
