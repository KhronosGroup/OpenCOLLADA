/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MESH_UTIL_H__
#define __COLLADA_MESH_UTIL_H__

#include "HelperPrerequisites.h"
#include "COLLADAInputUtil.h"

namespace COLLADADomHelper
{
    /** A utility to process COLLADA meshes. */
    class MeshUtil
    {

    private:

        /** A vector of domSource pointers. */
        typedef std::vector<domSource*> SourceVector;

    public:
        /** Retrieves the bounds information that can be used for
            axis aligned bounding boxes.
        	@param geo The geometry to get the bounds.
        	@param min[3] An array of three doubles to store the minimum vector.
        	@param max[3] An array of three doubles to store the maximum vector.
        */
        static void getBounds(const domGeometryRef& geo, double min[3], double max[3]);

        /** Retrieves the bounds information that can be used for
        axis aligned bounding boxes.
        @param mesh The mesh to get the bounds.
        @param min[3] An array of three doubles to store the minimum vector.
        @param max[3] An array of three doubles to store the maximum vector.
        */
        static void getBounds(const domMeshRef& mesh, double min[3], double max[3]);

    private:
        /** Searches the given vertices for input data of semantic "POSITION"
            and retrieves the referenced source.
        	@param vertices The vertices to inspect.
        	@param sources The vector to store found sources.
        */
        static void findPositionSources( const domVerticesRef& vertices, SourceVector& sources );
        
        /** Searches the given primitives for input data of semantic "POSITION"
            and retrieves the referenced source.
        	@param array The array to iterate.
        	@param sources The vector to store found sources.
        */
        template <class T>
        static void findPositionSources( daeTArray< daeSmartRef<T> >& array, SourceVector& sources )
        {
            for ( size_t i = 0, count = array.getCount(); i < count; ++i )
            {
                daeSmartRef<T> primitives = array.get( i );
                domInputLocalOffsetRef inputVertex = InputUtil::getInputLocalOffset<T>( primitives, COMMON_PROFILE_INPUT_VERTEX );

                if ( inputVertex == 0 )
                {
                    continue;
                }

                domVerticesRef vertices = daeSafeCast<domVertices>( inputVertex->getSource().getElement() );

                if ( vertices == 0 )
                {
                    continue;
                }

                domInputLocalRef inputPosition = InputUtil::getInputLocal( vertices, COMMON_PROFILE_INPUT_POSITION );

                if ( inputPosition == 0 )
                {
                    continue;
                }

                domSourceRef source = InputUtil::getSource( inputPosition );

                if ( source == 0 )
                {
                    continue;
                }

                if ( source != 0 )
                {
                    sources.push_back( source );
                }
            }
        }
        
        /** Searches the given mesh for position data referenced in the 
            primitives and vertices.
        	@param mesh The mesh to inspect.
        	@param sources The vector to store found sources.
        */
        static void findPositionData(const domMeshRef& mesh, SourceVector& sources);
        
        /** Iterates over the given values and compares every tuple3 with 
            min and max.
            @par Note:
                 To get correct results min and max must be initialized with
                 reasonable values. E.g. with the first tuple in the given values.
        	@param values The values to iterate. getCount/3 must be the number of
                          n*tuple3.
            @param min[3] An array of three doubles to store the minimum vector.
            @param max[3] An array of three doubles to store the maximum vector.
        */
        static void getBounds( const domListOfFloats& values, double min[3], double max[3] );
    };
}

#endif // __COLLADA_MESH_UTIL_H__
