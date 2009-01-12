/*
    Copyright (c) 2008 NetAllied Systems GmbH

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

    /** TODO Documentation */
	class Polygons : public MeshPrimitiveWithFaceVertexCount<long long>
		{
	private:
	
	public:

        /** Constructor. */
		Polygons() : MeshPrimitiveWithFaceVertexCount(POLYGONS){}

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
