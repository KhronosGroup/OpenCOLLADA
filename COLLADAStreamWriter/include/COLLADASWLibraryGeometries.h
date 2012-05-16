/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_GEOMETRY_H__
#define __COLLADASTREAMWRITER_LIBRARY_GEOMETRY_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWInputList.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_geometries\> and @a \<geometry\>'s*/

    class LibraryGeometries : public Library
    {

    public:

        static const String GEOMETRY_ID_PRAEFIX ;
		static const String POSITIONS_SOURCE_ID_SUFFIX;
		static const String INTANGENT_SOURCE_ID_SUFFIX;
		static const String OUTTANGENT_SOURCE_ID_SUFFIX;
		static const String INTERPOLATION_SOURCE_ID_SUFFIX;
        static const String NORMALS_SOURCE_ID_SUFFIX;
		static const String TEXCOORDS_SOURCE_ID_SUFFIX;
        static const String COLORS_SOURCE_ID_SUFFIX;
		static const String TEXTANGENT_SOURCE_ID_SUFFIX;
		static const String TEXBINORMAL_SOURCE_ID_SUFFIX;
        static const String ARRAY_ID_SUFFIX;
        static const String VERTICES_ID_SUFFIX;
        static const String TANGENT_ID_SUFFIX;
        static const String BINORMAL_ID_SUFFIX;

    private:

        TagCloser mCurrentGeometryCloser;  //!< Used to close the current geometry
        TagCloser mCurrentMeshOrSplineCloser;   //!< Used to close the current mesh
        TagCloser mCurrentExtraCloser;   //!< Used to close the current extra

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_geometries\> and @a \<geometry\>'s
        should be written to.
        */
        LibraryGeometries ( StreamWriter* streamWriter );

        virtual ~LibraryGeometries() {}

    protected:
        /** Writes the opening @a \<geometry\> and @a \<mesh\> tags and, if necessary the opening @a \<library_geometry\> tag.
        closeMesh() must be use to close the opened tags.
        @param geoId The id of the geometry
        @param geoName The Name of the geometry*/
        void openMesh ( const String& geoId, const String& geoName = EMPTY_STRING );

		/** Writes the opening @a \<geometry\> and @a \<spline\> tags and, if necessary the opening @a \<library_geometry\> tag.
		closeMesh() must be use to close the opened tags.
		@param closed Indicates if the spline si closed or open
		@param geoName The Name of the geometry*/
		void openSpline ( bool closed, const String & geoId, const String & geoName );

		/** Closes the tag opened by openMesh()*/
		void closeMesh();

		/** Closes the tag opened by openSpline()*/
		void closeSpline();

        /** Writes the opening @a \<mesh\> tag and, if necessary the opening @a \<library_geometry\> tag.
        closeGeometry() must be use to close the opened tags.
        @param id The id of the geometry.
        @param name The name of the geometry.*/
        void openGeometry ( const String& id, const String& name = EMPTY_STRING );

        /** Closes the tag open by openGeometry()*/
        void closeGeometry();

        /** Returns the suffix string of the given type semantic. */
        static String getSuffixBySemantic ( InputSemantic::Semantics type );
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_GEOMETRY_H__
