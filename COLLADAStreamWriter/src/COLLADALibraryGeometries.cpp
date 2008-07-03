/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
