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
		/** Holds informations how to bind a material to a mesh primitive.
		The material with UniqueId @a mReferencedMaterial gets bind to all mesh primitives 
		with material id @a mMaterialId.*/
		class MaterialBinding
		{
		private:
			/** The MaterialId of the mesh primitives that should get bind to a material.*/
			MaterialId mMaterialId;
			/** Unique id of the material that should get bind to the mesh primitives.*/
			UniqueId mReferencedMaterial;
		public:
			MaterialBinding(MaterialId materialId, UniqueId referencedMaterial); 

			/** @return MaterialId of the mesh primitives that should get bind to a material.*/
			COLLADAFW::MaterialId getMaterialId() const { return mMaterialId; }

			/** Sets the MaterialId of the mesh primitives that should get bind to a material.*/
			void setMaterialId(COLLADAFW::MaterialId val) { mMaterialId = val; }

			/** @return Unique id of the material that should get bind to the mesh primitives.*/
			const COLLADAFW::UniqueId& getReferencedMaterial() const { return mReferencedMaterial; }

			/** Sets the Unique id of the material that should get bind to the mesh primitives.*/
			void setReferencedMaterial(const COLLADAFW::UniqueId& val) { mReferencedMaterial = val; }
		};

	private:

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
