/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_GEOMETRYLOADER_H__
#define __COLLADASAXFWL_GEOMETRYLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSource.h"

#include "COLLADASaxFWLFilePartLoader.h"


namespace COLLADASaxFWL
{

    /** 
    Base class that describes geometric data. Must be exactly one of:
     • <convex_mesh>
     • <mesh>
     • <spline> 
    More about, read the class Geometry documentation.
    */
	class GeometryLoader : public FilePartLoader
    {
	private:
		/** The id of the geometry.*/
		String mGeometryId;

		/** The name of the geometry.*/
		String mGeometryName;

	public:

        /** Constructor. */
		GeometryLoader ( IFilePartLoader* callingFilePartLoader, const char * geometryId, const char * geometryName);

        /** Destructor. */
		virtual ~GeometryLoader();

		/** Sax callback function for the beginning of a mesh.*/
		bool begin__mesh();

		/** Sax callback function for the ending of a geometry.*/
		bool end__geometry();



#if 0
        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        const SourceBase* getSourceById ( const String& sourceId ) const;

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        SourceBase* getSourceById ( const String& sourceId );
#endif

	private:

        /** Disable default copy ctor. */
		GeometryLoader( const GeometryLoader& pre );

        /** Disable default assignment operator. */
		const GeometryLoader& operator= ( const GeometryLoader& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADASAXFWL_GEOMETRYLOADER_H__
