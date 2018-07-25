/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
	const String LibraryGeometries::INTANGENT_SOURCE_ID_SUFFIX = "-intangents";
	const String LibraryGeometries::OUTTANGENT_SOURCE_ID_SUFFIX = "-outtangents";
	const String LibraryGeometries::INTERPOLATION_SOURCE_ID_SUFFIX = "-interpolations";
    const String LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX = "-normals";
	const String LibraryGeometries::TEXCOORDS_SOURCE_ID_SUFFIX = "-map";
    const String LibraryGeometries::COLORS_SOURCE_ID_SUFFIX = "-colors";
	const String LibraryGeometries::TEXTANGENT_SOURCE_ID_SUFFIX = "-textangents";
	const String LibraryGeometries::TEXBINORMAL_SOURCE_ID_SUFFIX = "-texbinormals";
    const String LibraryGeometries::ARRAY_ID_SUFFIX = "-array";
    const String LibraryGeometries::VERTICES_ID_SUFFIX = "-vertices";
    const String LibraryGeometries::TANGENT_ID_SUFFIX = "-tangents";
    const String LibraryGeometries::BINORMAL_ID_SUFFIX = "-binormals";
    const String LibraryGeometries::_BATCHID_ID_SUFFIX = "-_batchid";


    //---------------------------------------------------------------
    LibraryGeometries::LibraryGeometries( COLLADASW::StreamWriter * streamWriter )
            : Library( streamWriter, CSWC::CSW_ELEMENT_LIBRARY_GEOMETRIES )
    {}

    //---------------------------------------------------------------
    String LibraryGeometries::getSuffixBySemantic( InputSemantic::Semantics type )
    {
        String suffix;

        switch( type )
        {
        case InputSemantic::POSITION:
            suffix = LibraryGeometries::POSITIONS_SOURCE_ID_SUFFIX;
            break;
        case InputSemantic::VERTEX:
            suffix = LibraryGeometries::VERTICES_ID_SUFFIX;
            break;
        case InputSemantic::NORMAL:
            suffix = LibraryGeometries::NORMALS_SOURCE_ID_SUFFIX;
            break;
        case InputSemantic::TEXCOORD:
            suffix = LibraryGeometries::TEXCOORDS_SOURCE_ID_SUFFIX;
            break;
        case InputSemantic::COLOR:
            suffix = LibraryGeometries::COLORS_SOURCE_ID_SUFFIX;
            break;
        case InputSemantic::TANGENT:
            suffix = LibraryGeometries::TANGENT_ID_SUFFIX;
            break;
        case InputSemantic::BINORMAL:
            suffix = LibraryGeometries::BINORMAL_ID_SUFFIX;
            break;
        case InputSemantic::_BATCHID:
            suffix = LibraryGeometries::_BATCHID_ID_SUFFIX;
            break;
        default:
            suffix = "unknown";
            break;
        }

        return suffix;
    }

	//---------------------------------------------------------------
	void LibraryGeometries::openMesh( const String & geoId, const String & geoName )
	{
		openGeometry( geoId, geoName );
		mCurrentMeshOrSplineCloser = mSW->openElement( CSWC::CSW_ELEMENT_MESH );

	}

	void LibraryGeometries::openConvexMesh(const String &convexHullOf, const String & geoId, const String & geoName)
	{
		mCurrentGeometryCloser = mSW->openElement(CSWC::CSW_ELEMENT_GEOMETRY);

		if (!geoId.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_ID, geoId + String("_"));

		if (!geoName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_NAME, geoName);

		mCurrentConvexMeshCloser = mSW->openElement(CSWC::CSW_ELEMENT_CONVEX_MESH);
		mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_CONVEX_HULL_OF, String("#") + convexHullOf);
	}

	//---------------------------------------------------------------
	void LibraryGeometries::openSpline( bool closed, const String & geoId, const String & geoName )
	{
		openGeometry( geoId, geoName );
		mCurrentMeshOrSplineCloser = mSW->openElement( CSWC::CSW_ELEMENT_SPLINE );

		mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_CLOSED, closed );
	}

    //---------------------------------------------------------------
    void LibraryGeometries::openGeometry( const String & id, const String & name )
    {
        openLibrary();
        mCurrentGeometryCloser = mSW->openElement( CSWC::CSW_ELEMENT_GEOMETRY );

        if( !id.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_ID, id );

        if( !name.empty() )
            mSW->appendAttribute( CSWC::CSW_ATTRIBUTE_NAME, name );
    }

	//---------------------------------------------------------------
	void LibraryGeometries::closeMesh()
	{
		mCurrentMeshOrSplineCloser.close();
	}

	void LibraryGeometries::closeConvexMesh()
	{
		mCurrentConvexMeshCloser.close();
        mCurrentGeometryCloser.close();
	}

	//---------------------------------------------------------------
	void LibraryGeometries::closeSpline()
	{
		mCurrentMeshOrSplineCloser.close();
	}

    //---------------------------------------------------------------
    void LibraryGeometries::closeGeometry()
    {
        mCurrentGeometryCloser.close();
    }


} //namespace COLLADASW
