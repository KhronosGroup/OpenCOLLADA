/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_GEOMETRY_H__
#define __COLLADAFW_GEOMETRY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWGeometricElement.h"


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
    class Geometry
    {
    private:
	
        /** Pointer to the geometric element. Could be a mesh, spline or convex_mesh. */
        GeometricElement* mGeometricElement;

        /** A text string containing the unique identifier of the <geometry> element. This
        value must be unique within the instance document. Optional. */
        String mId;

        /** A text string containing the name of the <geometry> element. Optional. */
        String mName; 

	public:

        /** Constructor. */
		Geometry();

        /** Destructor. */
		virtual ~Geometry();

        /** A text string containing the unique identifier of the <geometry> element. This
        value must be unique within the instance document. Optional. */
        const String getId () const { return mId; }

        /** A text string containing the unique identifier of the <geometry> element. This
        value must be unique within the instance document. Optional. */
        void setId ( const String id ) { mId = id; }

        /** A text string containing the name of the <geometry> element. Optional. */
        const String getName () const { return mName; }

        /** A text string containing the name of the <geometry> element. Optional. */
        void setName ( const String name ) { mName = name; }

        /** Set the geometric element of the geometry. */
        void setGeometricElement ( GeometricElement* geometricElement );

        /** Returns the geometric element of the geometry. */
        GeometricElement* getGeometricElement ();

    private:

        /** Disable default copy ctor. */
		Geometry( const Geometry& pre );

        /** Disable default assignment operator. */
		const Geometry& operator= ( const Geometry& pre );

    };

} // namespace COLLADAFW

#endif // __COLLADAFW_GEOMETRY_H__
