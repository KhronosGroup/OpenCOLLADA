/*
    Copyright (c) 2008-20013 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_POLYLIST_H__
#define __COLLADAFW_POLYLIST_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitiveWithFaceVertexCount.h"


namespace COLLADAFW
{

    /** The Polylist class holds an arbitrary number of polygons. They can be convex or concave. Holes are
	not supported by this type.
	Data Format:
	The IntValuesArray returned by getFaceVertexCountArray() contains the number of vertices of each polygon
	or hole, respectively. Positive numbers indicate the number of vertices of a polygon.
	*/
	class Polylist : public MeshPrimitiveWithFaceVertexCount<int>
	{
	private:

	public:

        /** Constructor. */
		Polylist ( const UniqueId& uniqueId ) 
            : MeshPrimitiveWithFaceVertexCount<int>( uniqueId, POLYLIST )
        {}

        /** Destructor. */
		virtual ~Polylist(){}

	private:

        /** Disable default copy ctor. */
		Polylist( const Polylist& pre );

        /** Disable default assignment operator. */
		const Polylist& operator= ( const Polylist& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_POLYLIST_H__
