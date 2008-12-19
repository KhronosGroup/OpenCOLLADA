/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_TRIANGLES_H__
#define __COLLADAFW_TRIANGLES_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWMeshPrimitive.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class Triangles : public MeshPrimitive
	{
	private:
	
	public:

        /** Constructor. */
		Triangles() : MeshPrimitive(TRIANGLES){}

        /** Destructor. */
		virtual ~Triangles(){};

	private:

        /** Disable default copy ctor. */
		Triangles( const Triangles& pre );

        /** Disable default assignment operator. */
		const Triangles& operator= ( const Triangles& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_TRIANGLES_H__
