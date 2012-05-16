/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POLYGONS_H__
#define __COLLADAFW_POLYGONS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"


namespace COLLADAFW
{

    /** The Polygons class holds an arbitrary number of polygons. They can be convex or concave
	and can have holes.
	Data Format:
	The IntValuesArray returned by getFaceVertexCountArray() contains the number of vertices of each polygon
	or hole, respectively. Positive numbers indicate the number of vertices of a polygon, negative numbers the
	the number of vertices of holes. Each hole belongs to the last polygon found before itself. A polygon can
	have an arbitrary number of holes. The first value in the IntValuesArray must always be positive.
	*/
	class Polygons : public MeshPrimitiveWithFaceVertexCount<int>
	{
	private:

	public:

        /** Constructor. */
		Polygons ( const UniqueId& uniqueId ) 
            : MeshPrimitiveWithFaceVertexCount<int>( uniqueId, POLYGONS )
        {}

        /** Destructor. */
		virtual ~Polygons(){}

	private:

        /** Disable default copy ctor. */
		Polygons( const Polygons& pre );

        /** Disable default assignment operator. */
		const Polygons& operator= ( const Polygons& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_POLYGONS_H__
