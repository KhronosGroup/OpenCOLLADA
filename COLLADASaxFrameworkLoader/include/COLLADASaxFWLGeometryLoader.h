/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_GEOMETRYLOADER_H__
#define __COLLADASAXFWL_GEOMETRYLOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLXmlTypes.h"
#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLSplineLoader.h"
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

		/** The mesh loader used to load the mesh inside the geometry.*/
        MeshLoader* mMeshLoader;

        /** The mesh loader used to load the mesh inside the geometry.*/
        SplineLoader* mSplineLoader;

	public:

        /** Constructor. */
		GeometryLoader ( IFilePartLoader* callingFilePartLoader);

        /** Destructor. */
		virtual ~GeometryLoader();

        /** Returns the unique id of the current parsed object. */
        virtual const COLLADAFW::UniqueId& getUniqueId();

        /** Sets the id of the geometry.*/
		void setGeometryId( const String& geometryId ) { mGeometryId = geometryId; }

		/** Returns the geometry id.*/
		const String& getGeometryId() const { return mGeometryId; }

		/** Sets the name of the geometry.*/
		void setGeometryName( const String& geometryName ) { mGeometryName = geometryName; }

		/** Returns the geometry name.*/
		const String& getGeometryName() const { return mGeometryName; }

        /** Sax callback function for the beginning of a mesh.*/
		virtual bool begin__mesh();

        /** Sax callback function for the beginning of a spline.*/
        virtual bool begin__spline(const spline__AttributeData & attributeData);

        /** Sax callback function for the ending of a geometry.*/
		virtual bool end__geometry();

	private:

        /** Disable default copy ctor. */
		GeometryLoader( const GeometryLoader& pre );

        /** Disable default assignment operator. */
		const GeometryLoader& operator= ( const GeometryLoader& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADASAXFWL_GEOMETRYLOADER_H__
