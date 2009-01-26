/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_INSTANCEGEOMETRY_H__
#define __COLLADAFW_INSTANCEGEOMETRY_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWPointerArray.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWSceneGraphInstance.h"


namespace COLLADAFW
{
	/** Instantiates a geometry within a scene graph*/
	class InstanceGeometry 	: public SceneGraphInstance
	{
	public:
		/** Constructor. Creates an instance geometry, that does not instantiate a geometry.*/
		InstanceGeometry();

		/** Constructor. Creates an instance geometry, that instantiates the geometry with 
		UniqueId @a instanciatedGeometryId.
		@param instanceGeometry The UniqueId of the geometry instantiated.*/ 
		InstanceGeometry(UniqueId instanciatedGeometryId);

		virtual ~InstanceGeometry();

		/** Clones the matrix.*/
		InstanceGeometry* clone() const { return new InstanceGeometry(*this); }

	private:
        /** Disable default copy ctor. */
//		InstanceGeometry( const InstanceGeometry& pre );
        /** Disable default assignment operator. */
//		const InstanceGeometry& operator= ( const InstanceGeometry& pre );
	};

	typedef ArrayPrimitiveType<InstanceGeometry*> InstanceGeometryArray;
	typedef PointerArray<InstanceGeometry> InstanceGeometryPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEGEOMETRY_H__
