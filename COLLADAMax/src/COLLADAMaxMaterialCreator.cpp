/*
Copyright (c) 2008 NetAllied Systems GmbH

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

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxMaterialCreator.h"

#include "COLLADAMaxMultiMtl.h"

#include <max.h>


namespace COLLADAMax
{

	/** Converts @a color to a max color. @a color must be valid.*/
	Color toMaxColor( const COLLADAFW::Color& color )
	{
		assert(color.isValid());
		return Color(color.getRed(), color.getGreen(), color.getBlue());
	}

	/** Converts @a colorOrTexture to a max color. @a colorOrTexture must be a valid color.*/
	Color toMaxColor( const COLLADAFW::ColorOrTexture& colorOrTexture )
	{
		assert(colorOrTexture.isColor());
		return toMaxColor(colorOrTexture.getColor());
	}



	//------------------------------
	bool MaterialCreator::MaterialIdentifier::operator<( const MaterialIdentifier& rhs ) const
	{
		if ( effectUniqueId < rhs.effectUniqueId )
			return true;
		if ( effectUniqueId > rhs.effectUniqueId )
			return false;

		if ( slotflags < rhs.slotflags )
			return true;
		if ( slotflags > rhs.slotflags )
			return false;

		if ( (slotflags & AMBIENT) == AMBIENT )
		{
			if ( ambientMapChannel < rhs.ambientMapChannel )
				return true;
			if ( ambientMapChannel > rhs.ambientMapChannel )
				return false;
		}

		if ( (slotflags & DIFFUSE) == DIFFUSE )
		{
			if ( diffuseMapChannel < rhs.diffuseMapChannel )
				return true;
			if ( diffuseMapChannel > rhs.diffuseMapChannel )
				return false;
		}

		if ( (slotflags & SPECULAR) == SPECULAR )
		{
			if ( specularMapChannel < rhs.specularMapChannel )
				return true;
			if ( specularMapChannel > rhs.specularMapChannel )
				return false;
		}

		if ( (slotflags & SHININESS) == SHININESS )
		{
			if ( shininessMapChannel < rhs.shininessMapChannel )
				return true;
			if ( shininessMapChannel > rhs.shininessMapChannel )
				return false;
		}

		if ( (slotflags & EMISSION) == EMISSION )
		{
			if ( emissionMapChannel < rhs.emissionMapChannel )
				return true;
			if ( emissionMapChannel > rhs.emissionMapChannel )
				return false;
		}

		if ( (slotflags & OPACITY) == OPACITY )
		{
			if ( opacityMapChannel < rhs.opacityMapChannel )
				return true;
			if ( opacityMapChannel > rhs.opacityMapChannel )
				return false;
		}

		return false;
	}


	MaterialCreator::MaterialCreator( DocumentImporter* documentImporter )
		: ImporterBase(documentImporter)
	{
	}

    //------------------------------
	MaterialCreator::~MaterialCreator()
	{
	}

	//------------------------------
	bool MaterialCreator::create()
	{
		const DocumentImporter::NodeMaterialBindingsList& materialBindings = getNodeMaterialBindings();
		DocumentImporter::NodeMaterialBindingsList::const_iterator it = materialBindings.begin();
		for ( ; it != materialBindings.end(); ++it)
		{
			const DocumentImporter::NodeMaterialBindingsPair& materialBinding = *it;
			if ( !createAndAssingMaxMaterial(materialBinding) )
				return false;
		}

		// assign materials to cloned nodes
		const DocumentImporter::INodeINodePairList& clonedInodeOriginalInodeList = getClonedINodeOriginalINodePairList();
		DocumentImporter::INodeINodePairList::const_iterator itClone = clonedInodeOriginalInodeList.begin();
		for ( ; itClone != clonedInodeOriginalInodeList.end(); ++itClone)
		{
			itClone->first->SetMtl(itClone->second->GetMtl());
		}
		

		return true;
	}

	//------------------------------
	bool MaterialCreator::createAndAssingMaxMaterial( const DocumentImporter::NodeMaterialBindingsPair& materialBinding )
	{
		const DocumentImporter::MaterialBindingVector& materialBindings = materialBinding.materialBindings;
		INode* maxNode = materialBinding.maxNode;

		if ( materialBindings.size() == 0 )
			return true;

		// calculate largest material id
		int largestMaterialId = 0;
		DocumentImporter::MaterialBindingVector::const_iterator it = materialBindings.begin();

		for ( ; it != materialBindings.end(); ++it)
		{
			int materialId = (int)it->getMaterialId();
			if ( materialId > largestMaterialId )
				largestMaterialId = materialId;
		}

		if ( largestMaterialId == 1 && false )
		{
			const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding = materialBindings[0];
			const COLLADAFW::Effect* effect = getEffect(materialBinding);
			if ( !effect )
				return true;
			Mtl* newMaterial = getMaxMaterial(*effect);
			maxNode->SetMtl( newMaterial );
			return true;
		}

		MultiMtl * multiMaterial = NewDefaultMultiMtl();
		multiMaterial->SetNumSubMtls( largestMaterialId + 1 );
		multiMaterial->SetName("MultiMaterial");

		it = materialBindings.begin();
		for ( ; it != materialBindings.end(); ++it)
		{
			const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding = *it;
			const COLLADAFW::Effect* effect = getEffect(materialBinding);
			if ( !effect )
				continue;
			Mtl* newMaterial = getMaxMaterial(*effect);
			multiMaterial->SetSubMtl( materialBinding.getMaterialId(), newMaterial);
		}
		maxNode->SetMtl( multiMaterial );
		return true;
	}


	//------------------------------
	Mtl* MaterialCreator::createMaxMaterial( const COLLADAFW::Effect& effect )
	{
		const COLLADAFW::CommonEffectPointerArray& commonEffects = effect.getCommonEffects();
		if ( commonEffects.getCount() > 0)
		{
			return createStandardMaterial(*commonEffects[0], effect.getName());
		}

		return 0;
	}

	//------------------------------
	Mtl* MaterialCreator::getMaxMaterial( const COLLADAFW::Effect& effect )
	{
		const COLLADAFW::UniqueId& effectUniqueId = effect.getUniqueId();
		UniqueIdMaxMaterialMap::const_iterator it = mUniqueIdMaxMaterialMap.find(effectUniqueId);
		if ( it == mUniqueIdMaxMaterialMap.end() )
		{
			// we need to create a new material
			Mtl* newMaterial = createMaxMaterial(effect);
			mUniqueIdMaxMaterialMap.insert(std::pair<COLLADAFW::UniqueId, Mtl*>(effectUniqueId, newMaterial));
			return newMaterial;
		}
		else
		{
			return it->second;
		}
	}


	//------------------------------
	StdMat2* MaterialCreator::createStandardMaterial( const COLLADAFW::EffectCommon& effectCommon, const String& name )
	{
		StdMat2* material = NewDefaultStdMat();


		COLLADAFW::EffectCommon::ShaderType shaderType = effectCommon.getShaderType();
		switch ( shaderType )
		{
		case COLLADAFW::EffectCommon::SHADER_CONSTANT: 
			material->SetFaceted(true); // BUG393: Max actually does not support a constant shader!
		case COLLADAFW::EffectCommon::SHADER_BLINN: 
			material->SwitchShader(Class_ID(StandardMaterial::STD2_BLINN_SHADER_CLASS_ID, 0)); 
			break;
		case COLLADAFW::EffectCommon::SHADER_LAMBERT:
		case COLLADAFW::EffectCommon::SHADER_PHONG:
		case COLLADAFW::EffectCommon::SHADER_UNKNOWN:
		default: 
			material->SwitchShader(Class_ID(StandardMaterial::STD2_PHONG_CLASS_ID, 0)); 
			break;
		}


		// Retrieve the shader parameter blocks
		Shader* materialShader = material->GetShader();
		IParamBlock2* shaderParameters = (IParamBlock2*) materialShader->GetReference(0);
		IParamBlock2* extendedParameters = (IParamBlock2*) material->GetReference(StandardMaterial::EXTENDED_PB_REF);

		// Common material parameters
		material->SetName(name.c_str());
		const COLLADAFW::ColorOrTexture& diffuse = effectCommon.getDiffuse();

		if ( diffuse.isColor() )
			material->SetDiffuse( toMaxColor(diffuse), 0);

		const COLLADAFW::ColorOrTexture& emission = effectCommon.getEmission();
		if ( emission.isColor() )
		{
			material->SetSelfIllumColorOn(TRUE);
			material->SetSelfIllumColor( toMaxColor(emission), 0);
		}
		else
		{
			material->SetSelfIllumColorOn(FALSE);
			material->SetSelfIllum( 0, 0 );
		}


		// TODO: handle opacity a bit smarter (evaluate opacity)
		float opacity;
		float transparency = (float)effectCommon.getTransparency();
		const COLLADAFW::ColorOrTexture& transparent = effectCommon.getTransparent();
		if ( transparent.isColor() )
		{
			const COLLADAFW::Color& transparentColor = transparent.getColor(); 
			float averageTransparent = (float)(transparentColor.getRed() + transparentColor.getGreen() + transparentColor.getBlue())/3; 
			if ( transparency > 0)
				opacity = averageTransparent * transparency;
			else
				opacity = averageTransparent;
		}
		else
		{
			if ( transparency > 0)
				opacity = transparency;
			else
				opacity = 0;
		}
		// todo include and fix
	//	material->SetOpacity( opacity, 0);

		if (shaderType != COLLADAFW::EffectCommon::SHADER_CONSTANT && shaderType != COLLADAFW::EffectCommon::SHADER_UNKNOWN)
		{
			// Unlock the ambient and diffuse colors
			materialShader->SetLockAD(FALSE);
			materialShader->SetLockADTex(FALSE);
			material->LockAmbDiffTex(FALSE);
			material->SyncADTexLock(FALSE);

			// Lambert/Phong material parameters
			const COLLADAFW::ColorOrTexture& ambient = effectCommon.getAmbient();
			if ( ambient.isColor() )
				material->SetAmbient( toMaxColor(ambient), 0);
		}
		else
		{
			// Approximate constant shader, specular is the same color
			if ( diffuse.isColor() )
				material->SetSpecular( toMaxColor(diffuse), 0 );
		}

		//TODO specular

		//create and assign textures

		const COLLADAFW::ColorOrTexture& colorOrTexture = effectCommon.getDiffuse();
		if ( colorOrTexture.isTexture() )
		{
			BitmapTex* texture = createTexture( effectCommon, colorOrTexture.getTexture() );
			assignTextureToMaterial(material, ID_DI, texture);
		}

		return material;
	}

	//------------------------------
	const COLLADAFW::Effect* MaterialCreator::getEffect( const COLLADAFW::InstanceGeometry::MaterialBinding& materialBinding )
	{
		const COLLADAFW::UniqueId& materialUniqueId = materialBinding.getReferencedMaterial();
		if ( !materialUniqueId.isValid() )
			return 0;

		const COLLADAFW::Material* material = getFWMaterialByUniqueId(materialUniqueId);
		if ( !material )
			return 0;

		const COLLADAFW::UniqueId& effectUniqueId = material->getInstantiatedEffect();
		if ( !effectUniqueId.isValid() )
			return 0;

		return getFWEffectByUniqueId(effectUniqueId);
	}

	//------------------------------
	BitmapTex* MaterialCreator::createTexture( const COLLADAFW::EffectCommon& effectCommon, const COLLADAFW::Texture& texture )
	{
		BitmapTex* bitmapTexture = NewDefaultBitmapTex();
		COLLADAFW::SamplerID samplerId = texture.getSamplerId();
		const COLLADAFW::Sampler* sampler = effectCommon.getSamplerPointerArray()[ samplerId ];

		const COLLADAFW::UniqueId& imageUniqueId = sampler->getSourceImage();
		const COLLADAFW::Image* image = getFWImageByUniqueId( imageUniqueId );

		if ( !image )
			return 0;
		COLLADABU::URI imageUri( getFileInfo().absoluteFileUri, image->getImageURI().getURIString() );
		COLLADABU::NativeString imageFileName( imageUri.toNativePath().c_str(), COLLADABU::NativeString::ENCODING_UTF8 );
		bitmapTexture->SetMapName(const_cast<char*>(imageFileName.c_str()));
		bitmapTexture->LoadMapFiles(0);


		return bitmapTexture;
	}

	//------------------------------
	void MaterialCreator::assignTextureToMaterial( Mtl* material, int slot, BitmapTex* texture )
	{

	}

} // namespace COLLADAMax
