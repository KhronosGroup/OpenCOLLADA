/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryGeometries.h"
#include "COLLADASWConstants.h"
#include "COLLADABUUtils.h"

namespace COLLADASW
{

    const String LibraryGeometries::GEOMETRY_ID_PRAEFIX = "geom-";
    const String LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX = "-positions";
    const String LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX = "-normals";
	const String LibraryGeometries::TEXTURE_CHANNEL_SOURCE_ID_SUFFIX = "-map-channel";
	const String LibraryGeometries::TEXTANGENT_SOURCE_ID_SUFFIX = "-textangent";
	const String LibraryGeometries::TEXBINORMAL_SOURCE_ID_SUFFIX = "-texbinormal";
    const String LibraryGeometries::ARRAY_ID_SUFFIX = "-array";
    const String LibraryGeometries::VERTICES_ID_SUFFIX = "-vertices";
    const String LibraryGeometries::TANGENT_ID_SUFFIX = "-tangent";
    const String LibraryGeometries::BINORMAL_ID_SUFFIX = "-binormal";


    //---------------------------------------------------------------
    LibraryGeometries::LibraryGeometries ( COLLADASW::StreamWriter * streamWriter )
            : Library ( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_GEOMETRIES )
    {}

    //---------------------------------------------------------------
    String LibraryGeometries::getSuffixBySemantic ( Semantics type )
    {
        String suffix;

        switch ( type )
        {

        case ( COLLADASW::POSITION ) :
            suffix = LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX;
            break;

        case ( COLLADASW::VERTEX ) :
            suffix = LibraryGeometries::VERTICES_ID_SUFFIX;
            break;

        case ( COLLADASW::NORMAL ) :
            suffix = LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX;
            break;

        case ( COLLADASW::TEXCOORD ) :
            suffix = LibraryGeometries::TEXTURE_CHANNEL_SOURCE_ID_SUFFIX;
            break;

        case ( COLLADASW::TANGENT ) :
            suffix = LibraryGeometries::TANGENT_ID_SUFFIX;
            break;

        case ( COLLADASW::BINORMAL ) :
            suffix = LibraryGeometries::BINORMAL_ID_SUFFIX;
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
        mCurrentMeshCloser = mSW->openElement ( CSWC::CSW_ELEMENT_MESH );

        if ( !meshId.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, meshId );
    }

    //---------------------------------------------------------------
    void LibraryGeometries::openGeometry ( const String & id, const String & name )
    {
        openLibrary();
        mCurrentGeometryCloser = mSW->openElement ( CSWC::CSW_ELEMENT_GEOMETRY );

        if ( !id.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_ID, id );

        if ( !name.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_NAME, name );
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


} //namespace COLLADASW
