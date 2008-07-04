/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
