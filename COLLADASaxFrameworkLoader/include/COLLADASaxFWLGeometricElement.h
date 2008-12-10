/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_GEOMETRICELEMENT_H__
#define __COLLADASAXFWL_GEOMETRICELEMENT_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLSource.h"

#include "COLLADAFWGeometricElement.h"


namespace COLLADASaxFWL
{

    /** 
    Base class that describes geometric data. Must be exactly one of:
     • <convex_mesh>
     • <mesh>
     • <spline> 
    More about, read the class Geometry documentation.
    */
    class ColladaGeometricElement : public COLLADAFW::GeometricElement
    {

	private:
	
        /**
        * Provides the bulk of the mesh’s vertex data. See main entry.
        */
        SourceArray mSourceArray;

	public:

        /** Constructor. */
		ColladaGeometricElement ( GeometricType elementType );

        /** Destructor. */
		virtual ~ColladaGeometricElement();

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

        /**
        * Returns the source element of the source array with the given id or 0 if it not exist.
        * @param sourceId The source id of the searched source element.
        * @return COLLADAFW::Source The source element with the given id or 0 if it not exist.
        */
        SourceBase* getSourceById ( const String& sourceId );


	private:

        /** Disable default copy ctor. */
		ColladaGeometricElement( const GeometricElement& pre );

        /** Disable default assignment operator. */
		const ColladaGeometricElement& operator= ( const GeometricElement& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADASAXFWL_GEOMETRICELEMENT_H__
