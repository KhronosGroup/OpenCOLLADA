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
#include "COLLADAFWTypes.h"
#include "COLLADAFWInstanceSceneGraph.h"


namespace COLLADAFW
{
	/** Instantiates a geometry within a scene graph*/
	class InstanceGeometry 	: public InstanceSceneGraph
	{
	public:
		/** Contains informations which set of texture coordinates is used by which texture, 
		when a common effect containing textures is binded to the material.*/
		struct TextureCoordinateBinding
		{	
			/** The id of a texture map. This id is used with EffectCommon to specify which texture coordinates
			should be used by which texture, especially if different parameters (diffuse, emission...) use different 
			texture coordinates. The TextureCoordinateBinding struct binds this  TextureMapId to the texture coordinates
			of the mesh, using setIndex. See also Texture*/
			TextureMapId textureMapId;

			/** The set index of the set of texture coordinates uses by the effect for parameter
			with parameter id. */
			size_t setIndex;

			bool operator<( const TextureCoordinateBinding& rhs) const;

		};
		typedef Array<TextureCoordinateBinding> TextureCoordinateBindingArray;

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

            /** The name of the shading engine. */
            String mName;

			/** A list of bindings of texture maps .*/
			TextureCoordinateBindingArray mTextureCoordinateBindingArray;

		public:

			MaterialBinding ( const MaterialId& materialId, const UniqueId& referencedMaterial ); 

			/** @return MaterialId of the mesh primitives that should get bind to a material.*/
			COLLADAFW::MaterialId getMaterialId() const { return mMaterialId; }

			/** Sets the MaterialId of the mesh primitives that should get bind to a material.*/
			void setMaterialId(COLLADAFW::MaterialId val) { mMaterialId = val; }

			/** @return Unique id of the material that should get bind to the mesh primitives.*/
			const COLLADAFW::UniqueId& getReferencedMaterial() const { return mReferencedMaterial; }

			/** Sets the Unique id of the material that should get bind to the mesh primitives.*/
			void setReferencedMaterial(const COLLADAFW::UniqueId& val) { mReferencedMaterial = val; }

			/** The comparison operator that only compares the material ids.*/
			bool operator<( const MaterialBinding& rhs) const { return mMaterialId < rhs.mMaterialId; }

            /** The name of the shading engine. */
            const String& getName () const { return mName; }
            void setName ( const String& val ) { mName = val; }

			/** Returns the list of bindings of texture maps .*/
			TextureCoordinateBindingArray& getTextureCoordinateBindingArray() { return  mTextureCoordinateBindingArray; }

			/** Returns the list of bindings of texture maps .*/
			const TextureCoordinateBindingArray& getTextureCoordinateBindingArray() const { return  mTextureCoordinateBindingArray; }

			/** Disable default copy ctor. */
			MaterialBinding( const MaterialBinding& pre );
			/** Disable default assignment operator. */
			const MaterialBinding& operator= ( const MaterialBinding& pre );

		private:
			friend class Array<MaterialBinding>;
			MaterialBinding(){} 

		};

		typedef Array<MaterialBinding> MaterialBindingArray;

	private:

		/** The list of all material bindings of this instance geometry. The Material bindings must be 
		order according to MaterialBinding::operator<.*/
		MaterialBindingArray mMaterialBindings;

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

		/** Returns the list of all material bindings.*/
		MaterialBindingArray& getMaterialBindings() { return mMaterialBindings; }

		/** Returns the list of all material bindings.*/
		const MaterialBindingArray& getMaterialBindings() const { return mMaterialBindings; }

	private:
        /** Disable default copy ctor. */
		InstanceGeometry( const InstanceGeometry& pre );
        /** Disable default assignment operator. */
		//const InstanceGeometry& operator= ( const InstanceGeometry& pre );
	};

	typedef ArrayPrimitiveType<InstanceGeometry*> InstanceGeometryArray;
	typedef PointerArray<InstanceGeometry> InstanceGeometryPointerArray;

} // namespace COLLADAFW

#endif // __COLLADAFW_INSTANCEGEOMETRY_H__
