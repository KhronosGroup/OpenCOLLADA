/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADASTREAMWRITER_LIBRARY_GEOMETRY_H__
#define __COLLADASTREAMWRITER_LIBRARY_GEOMETRY_H__

#include "COLLADAPrerequisites.h"
#include "COLLADALibrary.h"
#include "COLLADAInputList.h"

namespace COLLADA
{

    /** Class to simply the creation of @a \<library_geometries\> and @a \<geometry\>'s*/

    class LibraryGeometries : public Library
    {

    public:

        static const String GEOMETRY_ID_PRAEFIX ;
        static const String POSITIONS_SOURCE_ID_SUFFIX;
        static const String NORMALS_SOURCE_ID_SUFFIX;
        static const String TEXTURE_CHANNEL_SOURCE_ID_SUFFIX;
        static const String ARRAY_ID_SUFFIX;
        static const String VERTICES_ID_SUFFIX;
        static const String GEOTANGENT_ID_SUFFIX;
        static const String GEOBINORMAL_ID_SUFFIX;

    private:

        TagCloser mCurrentGeometryCloser;  //!< Used to close the current geometry
        TagCloser mCurrentMeshCloser;   //!< Used to close the current mesh
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
        @param geoName The Name of the geometry
        @param meshId The id of the mesh*/
        void openMesh ( const String& geoId, const String& geoName = EMPTY_STRING, const String& meshId = EMPTY_STRING );

        /** Closes the tag opened by openMesh()*/
        void closeMesh();

        /** Writes the opening @a \<mesh\> tag and, if necessary the opening @a \<library_geometry\> tag.
        closeGeometry() must be use to close the opened tags.
        @param id The id of the geometry.
        @param name The name of the geometry.*/
        void openGeometry ( const String& id, const String& name = EMPTY_STRING );

        /** Closes the tag open by openGeometry()*/
        void closeGeometry();

        /** Returns the suffix string of the given type semantic. */
        static String getSuffixBySemantic ( Semantics type );

    };

} //namespace COLLADA

#endif //__COLLADASTREAMWRITER_LIBRARY_GEOMETRY_H__
