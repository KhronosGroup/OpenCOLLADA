/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_GEOMETRY_H__
#define __COLLADAFW_GEOMETRY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"
#include "COLLADAFWTypes.h"


namespace COLLADAFW
{

    /** 
     Describes the visual shape and appearance of an object in a scene.
      
     The <geometry> element categorizes the declaration of geometric information. Geometry is a branch of
     mathematics that deals with the measurement, properties, and relationships of points, lines, angles,
     surfaces, and solids. The <geometry> element contains a declaration of a mesh, convex mesh, or spline.
     There are many forms of geometric description. Computer graphics hardware has been normalized,
     primarily, to accept vertex position information with varying degrees of attribution (color, normals, etc.).
     Geometric descriptions provide this vertex data with relative directness or efficiency. Some of the more
     common forms of geometry are:
     • B-Spline
     • Bézier
     • Mesh
     • NURBS
     • Patch
     This is by no means an exhaustive list. Currently, COLLADA supports only polygonal meshes and splines.
    */
	class Geometry : public ObjectTemplate < COLLADA_TYPE::GEOMETRY >
    {
	public:

		enum GeometryType
		{
			GEO_TYPE_MESH, 
			GEO_TYPE_SPLINE,
			GEO_TYPE_CONVEX_MESH,
			GEO_TYPE_UNKNOWN
		};

    private:
	
        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** A text string containing the name of the <geometry> element. Optional. */
        String mName; 

		/** Geometry type. */
		GeometryType mType;

	public:

        /** Constructor. */
		Geometry ( const UniqueId& uniqueId, GeometryType geometryType );

        /** Destructor. */
		virtual ~Geometry();

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

        /** A text string containing the name of the <geometry> element. Optional. */
        const String getName () const { return mName; }

        /** A text string containing the name of the <geometry> element. Optional. */
        void setName ( const String name ) { mName = name; }

		/** Type of the geometric element. */
		const GeometryType getType () const { return mType; }

		/** Type of the geometric element. */
		void setType ( const GeometryType Type ) { mType = Type; }

		Geometry* clone() const { return new Geometry(*this); }


    private:

        /** Disable default copy ctor. */
		Geometry( const Geometry& pre );

        /** Disable default assignment operator. */
		const Geometry& operator= ( const Geometry& pre );

    };

} // namespace COLLADAFW

#endif // __COLLADAFW_GEOMETRY_H__
