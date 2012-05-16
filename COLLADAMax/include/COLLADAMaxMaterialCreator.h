/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAMax.

Portions of the code are:
Copyright (c) 2005-2007 Feeling Software Inc.
Copyright (c) 2005-2007 Sony Computer Entertainment America

Based on the 3dsMax COLLADASW Tools:
Copyright (c) 2005-2006 Autodesk Media Entertainment

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_MATERIALCREATOR_H__
#define __COLLADAMAX_MATERIALCREATOR_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxImporterBase.h"


namespace COLLADAMax
{

    /** Creates and assigns all material previously been stored by the material and affect importers.*/
	class MaterialCreator : public ImporterBase 
	{
	public:
		/** A struct that uniquely identifies material created in Max.*/
		struct MaterialIdentifier
		{
			MaterialIdentifier();
			enum SlotFlags
			{
				NONE        = 0,
				AMBIENT     = 1,
				DIFFUSE     = 1<<1,
				SPECULAR    = 1<<2,
				SHININESS   = 1<<3,
				EMISSION    = 1<<4,   //self-illumination
				OPACITY     = 1<<5
			};

			/** The unique id of the frame work effect this material has been created from.*/
			COLLADAFW::UniqueId effectUniqueId;

			/** Flags indication which slot uses a max channel.*/
			unsigned char slotFlags;

			unsigned char ambientMapChannel;
			unsigned char diffuseMapChannel;
			unsigned char specularMapChannel;
			unsigned char shininessMapChannel;
			unsigned char emissionMapChannel;
			unsigned char opacityMapChannel;

			bool operator<( const MaterialIdentifier& rhs ) const;
		};

		/** Maps framework effects to max materials.*/
		typedef std::map<MaterialIdentifier, Mtl*> MaterialIdentifierMaxMaterialMap;
	private:

		/** Maps all the framework effects already created a max material for, to the max 
		material.*/
		MaterialIdentifierMaxMaterialMap mMaterialIdentifierMaxMaterialMap;

	public:

        /** Constructor. */
		MaterialCreator( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~MaterialCreator();

		/** Performs the creation of all material.
		@return True on success, false otherwise.*/
		bool create();

		/** Creates all the material referenced in @a materialBinding, if not already created and 
		assigns them to the node in @a materialBinding.*/
		bool createAndAssingMaxMaterial( const DocumentImporter::NodeMaterialBindingsPair& materialBinding );

		/** Creates a standard material from @a effectCommon.*/ 
		StdMat2* createStandardMaterial( const COLLADAFW::EffectCommon& effectCommon, const String& name, const MaterialCreator::MaterialIdentifier& materialIdentifier);

		/** Creates a material from @a effect.*/
		Mtl* createMaxMaterial( const COLLADAFW::Effect& effect, const MaterialCreator::MaterialIdentifier& materialIdentifier);

		/** Returns the material created for @a effect. If for the same effect a max material has already been 
		created for, the formally created one is returned, otherwise a new one is created.*/
		Mtl* getMaxMaterial( const COLLADAFW::Effect& effect, const COLLADAFW::MaterialBinding& materialBinding, const COLLADAFW::UniqueId& geometryUniqueId );

		/** Returns the effect used by @a materialBinding. It resolves first the material and than the effect.
		If the effect could not be resolved, null is returned.*/
		const COLLADAFW::Effect* getEffect( const COLLADAFW::MaterialBinding& materialBinding );

		/** Returns the MaterialIdentifierMaxMaterialMap.*/
		const MaterialIdentifierMaxMaterialMap& getMaterialIdentifierMaxMaterialMap() const { return mMaterialIdentifierMaxMaterialMap; }

	private:

        /** Disable default copy ctor. */
		MaterialCreator( const MaterialCreator& pre );

        /** Disable default assignment operator. */
		const MaterialCreator& operator= ( const MaterialCreator& pre );

		/** Creates a max texture from the frame work texture @a texture.*/
		BitmapTex* createTexture( const COLLADAFW::EffectCommon& effectCommon, const COLLADAFW::Texture& texture );

		/** Assigns @a texture to @a slot of @a material.*/
		void assignTextureToMaterial(  Mtl* material, int slot, BitmapTex* texture);
	
    	void createAndAssignTexture( Mtl* material, const COLLADAFW::EffectCommon& effectCommon, const COLLADAFW::ColorOrTexture& (COLLADAFW::EffectCommon::*f)()const, int slot, unsigned char mapChannel);


		/** Sets the vertex color flag for all nodes that use vertex color.*/
		void setVertexColorFlag();
	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_MATERIALCREATOR_H__
