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
    * If the sort order of the vertex indices will be changed, the reverse flag will be set.
    */
    class Edge
    {
    private:

        /** The vertex indices of the points, which descripe the edge. */
        int mVertexIndices[2];

        /** Flag, if the edge is stored in reverse direction. */
        bool reverse;

    public:

        /** Constructor. */
        Edge () : reverse (false) {}

        /** Constructor. 
        Set the edge vertex indices sorted. */
        Edge ( int index1, int index2 ) : reverse ( false)
        {
            if ( index1 < index2 )
            {
                mVertexIndices[0] = index1;
                mVertexIndices[1] = index2;
            }
            else
            {
                mVertexIndices[0] = index2;
                mVertexIndices[1] = index1;
                reverse = true;
            }
        }

        /** Destructor. */
        virtual ~Edge () {}

        /** Set the edge vertex indices sorted. */
        void setVertexIndices ( int index1, int index2 ) 
        {
            if ( index1 < index2 )
            {
                mVertexIndices[0] = index1;
                mVertexIndices[1] = index2;
            }
            else
            {
                mVertexIndices[0] = index2;
                mVertexIndices[1] = index1;
                reverse = true;
            }
        }

        /** Returns the reverse flag. */
        const bool isReverse () const { return reverse; };

        int operator[](size_t i) const
        {
            assert( i < 2 );
            return mVertexIndices [i];
        }

        bool operator==(const Edge& e2)
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
