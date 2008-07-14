/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAStreamWriter.h"
#include "COLLADALibraryGeometries.h"
#include "COLLADASWC.h"
#include "COLLADAUtils.h"

namespace COLLADA
{

    const String LibraryGeometries::GEOMETRY_ID_PRAEFIX = "geom-";
    const String LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX = "-positions";
    const String LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX = "-normals";
    const String LibraryGeometries::TEXTURE_CHANNEL_SOURCE_ID_SUFFIX = "-map-channel";
    const String LibraryGeometries::ARRAY_ID_SUFFIX = "-array";
    const String LibraryGeometries::VERTICES_ID_SUFFIX = "-vertices";
    const String LibraryGeometries::GEOTANGENT_ID_SUFFIX = "-geotangent";
    const String LibraryGeometries::GEOBINORMAL_ID_SUFFIX = "-geobinormal";


    //---------------------------------------------------------------
    LibraryGeometries::LibraryGeometries ( COLLADA::StreamWriter * streamWriter )
            : Library ( streamWriter, CSWC::COLLADA_ELEMENT_LIBRARY_GEOMETRIES )
    {}

    //---------------------------------------------------------------
    String LibraryGeometries::getSuffixBySemantic ( Semantics type )
    {
        String suffix;

        switch ( type )
        {

        case ( COLLADA::POSITION ) :
            suffix = LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX;
            break;

        case ( COLLADA::VERTEX ) :
            suffix = LibraryGeometries::VERTICES_ID_SUFFIX;
            break;

        case ( COLLADA::NORMAL ) :
            suffix = LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX;
            break;

        case ( COLLADA::TEXCOORD ) :
            suffix = LibraryGeometries::TEXTURE_CHANNEL_SOURCE_ID_SUFFIX;
            break;

        case ( COLLADA::GEOTANGENT ) :
            suffix = LibraryGeometries::GEOTANGENT_ID_SUFFIX;
            break;

        case ( COLLADA::GEOBINORMAL ) :
            suffix = LibraryGeometries::GEOBINORMAL_ID_SUFFIX;
            break;

        default:
            suffix = "unknown";
            break;
        }

        return suffix;
    }

    //---------------------------------------------------------------
    void LibraryGeometries::openMesh ( const String & geoId, const String & geoName, const String & meshId )
    {
        openGeometry ( geoId, geoName );
        mCurrentMeshCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_MESH );

        if ( !meshId.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, meshId );
    }

    //---------------------------------------------------------------
    void LibraryGeometries::openGeometry ( const String & id, const String & name )
    {
        openLibrary();
        mCurrentGeometryCloser = mSW->openElement ( CSWC::COLLADA_ELEMENT_GEOMETRY );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_ID, id );

        if ( !name.empty() )
            mSW->appendAttribute ( CSWC::COLLADA_ATTRIBUTE_NAME, name );
    }

    //---------------------------------------------------------------
    void LibraryGeometries::closeMesh()
    {
        mCurrentMeshCloser.close();
    }

    //---------------------------------------------------------------
    void LibraryGeometries::closeGeometry()
    {
        mCurrentGeometryCloser.close();
    }


} //namespace COLLADA
