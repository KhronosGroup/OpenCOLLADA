/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_GEOMETRICELEMENT_H__
#define __COLLADAFW_GEOMETRICELEMENT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWSource.h"


namespace COLLADAFW
{

    /** 
    Base class that describes geometric data. Must be exactly one of:
     • <convex_mesh>
     • <mesh>
     • <spline> 
    More about, read the class Geometry documentation.
    */
	class GeometricElement
    {

    public:

        enum Type
        {
            GEO_TYPE_MESH, 
            GEO_TYPE_SPLINE,
            GEO_TYPE_CONVEX_MESH,
            GEO_TYPE_UNKNOWN
        };

	private:
	
        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        */
        SourceArray mSourceArray;

        /** Type of the geometric element. */
        Type mType;

	public:

        /** Constructor. */
		GeometricElement ( Type elementType );

        /** Destructor. */
		virtual ~GeometricElement();

        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        * @param sourceArraySize Parameter to get the size of the source array.
        * @return const SourceArray The source array.
        */
        const SourceArray& getSourceArray () const;

        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        * @param sourceArray The source array.
        * @param sourceArraySize The size of the source array.
        */
        void setSourceArray ( const SourceArray& sourceArray );

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        const SourceBase* getSourceById ( const String& sourceId ) const;


	private:

        /** Disable default copy ctor. */
		GeometricElement( const GeometricElement& pre );

        /** Disable default assignment operator. */
		const GeometricElement& operator= ( const GeometricElement& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_GEOMETRICELEMENT_H__
