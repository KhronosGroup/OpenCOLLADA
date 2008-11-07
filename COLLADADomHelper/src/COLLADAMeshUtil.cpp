/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "HelperStableHeaders.h"
#include "COLLADAMeshUtil.h"

namespace COLLADADomHelper
{
    //-----------------------------------------------------------------------
    void MeshUtil::getBounds( const domGeometryRef& geo, double min[3], double max[3] )
    {
        getBounds(geo->getMesh(), min, max);
    }
    //-----------------------------------------------------------------------
    void MeshUtil::getBounds( const domMeshRef& mesh, double min[3], double max[3] )
    {
        if(mesh == 0)
            return;

        SourceVector sources;
        findPositionData(mesh, sources);
        
        // this should never happen!
        assert( sources.size() > 0 );

        bool firstSet = false;

        for ( size_t i = 0, size = sources.size(); i < size; ++i )
        {
            domSourceRef source = sources.at( i );
            domListOfFloats& values = source->getFloat_array() ->getValue();

            if ( values.getCount() > 3 && firstSet == false )
            {
                min[ 0 ] = values[ 0 ];
                min[ 1 ] = values[ 1 ];
                min[ 2 ] = values[ 2 ];
                max[ 0 ] = values[ 0 ];
                max[ 1 ] = values[ 1 ];
                max[ 2 ] = values[ 2 ];
                firstSet = true;
            }

            getBounds( values, min, max );
        }
    }
    //-----------------------------------------------------------------------
    void MeshUtil::getBounds( const domListOfFloats& values, double min[3], double max[3] )
    {
        if ( values.getCount() == 0 )
            return ;

        for ( size_t i = 3, count = values.getCount(); i < count; )
        {
            domFloat x = values[ i++ ];
            domFloat y = values[ i++ ];
            domFloat z = values[ i++ ];

            if ( x < min[ 0 ] )
                min[ 0 ] = ( float ) x;

            if ( y < min[ 1 ] )
                min[ 1 ] = ( float ) y;

            if ( z < min[ 2 ] )
                min[ 2 ] = ( float ) z;

            if ( x > max[ 0 ] )
                max[ 0 ] = ( float ) x;

            if ( y > max[ 1 ] )
                max[ 1 ] = ( float ) y;

            if ( z > max[ 2 ] )
                max[ 2 ] = ( float ) z;
        }
    }
    //-----------------------------------------------------------------------
    void MeshUtil::findPositionSources( const domVerticesRef& vertices, SourceVector& sources )
    {
        domInputLocalRef input = InputUtil::getInputLocal( vertices, COMMON_PROFILE_INPUT_POSITION );
        if(input==0)
        {
            return;
        }
        domSourceRef positionSource = InputUtil::getSource( input );
        if(positionSource==0)
        {
            return;
        }
        sources.push_back( positionSource );
    }
    //-----------------------------------------------------------------------
    void MeshUtil::findPositionData( const domMeshRef& mesh, SourceVector& sources )
    {
        findPositionSources<domLines>(mesh->getLines_array(), sources);
        findPositionSources<domLinestrips>(mesh->getLinestrips_array(), sources);
        findPositionSources<domPolygons>(mesh->getPolygons_array(), sources);
        findPositionSources<domPolylist>(mesh->getPolylist_array(), sources);
        findPositionSources<domTriangles>( mesh->getTriangles_array(), sources );
        findPositionSources<domTrifans>( mesh->getTrifans_array(), sources );
        findPositionSources<domTristrips>( mesh->getTristrips_array(), sources );

        if ( sources.size() == 0 )
        {
            // fallback
            findPositionSources(mesh->getVertices(), sources);
        }
    }
}
