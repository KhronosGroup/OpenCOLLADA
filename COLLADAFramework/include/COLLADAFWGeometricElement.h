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

        enum GeometricType
        {
            GEO_TYPE_MESH, 
            GEO_TYPE_SPLINE,
            GEO_TYPE_CONVEX_MESH,
            GEO_TYPE_UNKNOWN
        };

	private:
	
        /** Type of the geometric element. */
        GeometricType mType;

	public:

        /** Constructor. */
		GeometricElement ( GeometricType elementType );

        /** Destructor. */
		virtual ~GeometricElement();

        /** Type of the geometric element. */
        const GeometricElement::GeometricType getType () const { return mType; }

        /** Type of the geometric element. */
        void setType ( const GeometricElement::GeometricType Type ) { mType = Type; }

	private:

        /** Disable default copy ctor. */
		GeometricElement( const GeometricElement& pre );

        /** Disable default assignment operator. */
		const GeometricElement& operator= ( const GeometricElement& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_GEOMETRICELEMENT_H__
