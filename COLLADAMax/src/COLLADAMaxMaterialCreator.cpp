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

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxMaterialCreator.h"

#include "COLLADAMaxConversionFunctor.h"

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


	void setMaterialIdentifierMapChannel( const COLLADAFW::ColorOrTexture& colorOrTexture,
										  const COLLADAFW::TextureCoordinateBindingArray& texCoordBindings,
										  const DocumentImporter::SetMapChannelMap& setMapChannelMap,
										  MaterialCreator::MaterialIdentifier::SlotFlags slot,
										  unsigned char& slotFlags,
										  unsigned char& mapChannel)
	{
		if ( !colorOrTexture.isTexture() )
		{
			mapChannel = 0;
			return;
		}

		slotFlags |= slot;

		const COLLADAFW::Texture& texture = colorOrTexture.getTexture();

		COLLADAFW::TextureMapId mapId = texture.getTextureMapId();

		// find the map id in the list of bind texture coordinates
		size_t texCoordBindingsCount = texCoordBindings.getCount();
		size_t setIndex;
		bool found = false;
		for ( size_t i = 0; i < texCoordBindingsCount; ++i)
		{
			const COLLADAFW::TextureCoordinateBinding& texCoordBinding = texCoordBindings[i];
			if ( texCoordBinding.getTextureMapId () == mapId )
			{
				setIndex = texCoordBinding.getSetIndex ();
				found = true;
				break;
			}
		}

		if ( !found || setMapChannelMap.empty() )
		{
			// if we could not resolve we need to guess and chose 1.*/
			mapChannel = 1;
		}
		else
		{
			DocumentImporter::SetMapChannelMap::const_iterator it = setMapChannelMap.find( setIndex );
			if ( it == setMapChannelMap.end() )
			{
				// could not find a map channel, take the first
				mapChannel = setMapChannelMap.begin()->second;
			}
			else
			{
				mapChannel = (unsigned char) it->second;
			}
		}
	}

	/** Creates an material identifier for the first EffectCommon in @a effect. It is assumed, that there is at least
	one EffectCommon.*/
	MaterialCreator::MaterialIdentifier getMaterialIdentifier( const COLLADAFW::Effect& effect,
															   const COLLADAFW::MaterialBinding& materialBinding,
															   const DocumentImporter::SetMapChannelMap& setMapChannelMap)
	{
//		assert( !effect.getCommonEffects().empty() );
		MaterialCreator::MaterialIdentifier materialIdentifier;
		materialIdentifier.slotFlags = 0;

		const COLLADAFW::UniqueId& effectUniqueId = effect.getUniqueId();

		materialIdentifier.effectUniqueId = effect.getUniqueId();

		const COLLADAFW::CommonEffectPointerArray& commonEffects = effect.getCommonEffects();

		if ( !commonEffects.empty() )
		{
			const COLLADAFW::EffectCommon* commonEffect = effect.getCommonEffects()[0];

			const COLLADAFW::TextureCoordinateBindingArray& texCoordBindings =  materialBinding.getTextureCoordinateBindingArray();

			setMaterialIdentifierMapChannel( commonEffect->getAmbient(), texCoordBindings, setMapChannelMap, MaterialCreator::MaterialIdentifier::AMBIENT, materialIdentifier.slotFlags, materialIdentifier.ambientMapChannel);
			setMaterialIdentifierMapChannel( commonEffect->getDiffuse(), texCoordBindings, setMapChannelMap, MaterialCreator::MaterialIdentifier::DIFFUSE, materialIdentifier.slotFlags, materialIdentifier.diffuseMapChannel);
			setMaterialIdentifierMapChannel( commonEffect->getSpecular(), texCoordBindings, setMapChannelMap, MaterialCreator::MaterialIdentifier::SPECULAR, materialIdentifier.slotFlags, materialIdentifier.specularMapChannel);
	//		setMaterialIdentifierMapChannel( commonEffect->getShininess(), texCoordBindings, setMapChannelMap, MaterialCreator::MaterialIdentifier::SHININESS, materialIdentifier.slotFlags, materialIdentifier.shininessMapChannel);
			setMaterialIdentifierMapChannel( commonEffect->getEmission(), texCoordBindings, setMapChannelMap, MaterialCreator::MaterialIdentifier::EMISSION, materialIdentifier.slotFlags, materialIdentifier.emissionMapChannel);
			setMaterialIdentifierMapChannel( commonEffect->getOpacity(), texCoordBindings, setMapChannelMap, MaterialCreator::MaterialIdentifier::OPACITY, materialIdentifier.slotFlags, materialIdentifier.opacityMapChannel);
		}

		return materialIdentifier;
	}


	//------------------------------
	MaterialCreator::MaterialIdentifier::MaterialIdentifier()
		: slotFlags(0)
		, ambientMapChannel(0)
		, diffuseMapChannel(0)
		, specularMapChannel(0)
		, shininessMapChannel(0)
		, emissionMapChannel(0)
		, opacityMapChannel(0)
	{
	}


	//------------------------------
	bool MaterialCreator::MaterialIdentifier::operator<( const MaterialIdentifier& rhs ) const
	{
		if ( effectUniqueId < rhs.effectUniqueId )
			return true;
		if ( effectUniqueId > rhs.effectUniqueId )
			return false;

		if ( slotFlags < rhs.slotFlags )
			return true;
		if ( slotFlags > rhs.slotFlags )
			return false;

		if ( (slotFlags & AMBIENT) == AMBIENT )
		{
			if ( ambientMapChannel < rhs.ambientMapChannel )
				return true;
			if ( ambientMapChannel > rhs.ambientMapChannel )
				return false;
		}

		if ( (slotFlags & DIFFUSE) == DIFFUSE )
		{
			if ( diffuseMapChannel < rhs.diffuseMapChannel )
				return true;
			if ( diffuseMapChannel > rhs.diffuseMapChannel )
				return false;
		}

		if ( (slotFlags & SPECULAR) == SPECULAR )
		{
			if ( specularMapChannel < rhs.specularMapChannel )
				return true;
			if ( specularMapChannel > rhs.specularMapChannel )
				return false;
		}

		if ( (slotFlags & SHININESS) == SHININESS )
		{
			if ( shininessMapChannel < rhs.shininessMapChannel )
				return true;
			if ( shininessMapChannel > rhs.shininessMapChannel )
				return false;
		}

		if ( (slotFlags & EMISSION) == EMISSION )
		{
			if ( emissionMapChannel < rhs.emissionMapChannel )
				return true;
			if ( emissionMapChannel > rhs.emissionMapChannel )
				return false;
		}

		if ( (slotFlags & OPACITY) == OPACITY )
		{
			if ( opacityMapChannel < rhs.opacityMapChannel )
				return true;
			if ( opacityMapChannel > rhs.opacityMapChannel )
				return false;
		}

		return false;
	}

	//------------------------------
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
		DocumentImporter::NodeMaterialBindingsList::const_iterator itEnd = materialBindings.end();


		//int index = 0;
		//double max = 0;
		//int maxIndex = 0;
		//double min = 10000000000;
		//int minIndex = 0;

		for ( ; it != materialBindings.end(); ++it)
		{
			const DocumentImporter::NodeMaterialBindingsPair& materialBinding = *it;

//			double start = getElapsedTime();
			if ( !createAndAssingMaxMaterial(materialBinding) )
				return false;

			//if ( ((getElapsedTime()-start)*1000) > max) 
			//{
			//	max = (getElapsedTime()-start)*1000;
			//	maxIndex = index;
			//}

			//if ( ((getElapsedTime()-start)*1000) < min) 
			//{
			//	min = (getElapsedTime()-start)*1000;
			//	minIndex = index;
			//}

			//index++;
		}


		//printMessage(String("MaterialCreator::create() ") 
		//	+ "  max: time  "
		//	+ COLLADABU::Utils::toString(max)
		//	+ "  index  "
		//	+ COLLADABU::Utils::toString(maxIndex)
		//	+ "  min: time  "
		//	+ COLLADABU::Utils::toString(min)
		//	+ "  index  "
		//	+ COLLADABU::Utils::toString(minIndex) );

		//printMessage("MaterialCreator::create() " 
		//	+ COLLADABU::Utils::toString((getElapsedTime()-start)*1000)
		//	+ "  count  "
		//	+ COLLADABU::Utils::toString(materialBindings.size()) );


		// assign materials to cloned nodes
		const DocumentImporter::INodeINodePairList& clonedInodeOriginalInodeList = getClonedINodeOriginalINodePairList();
		DocumentImporter::INodeINodePairList::const_iterator itClone = clonedInodeOriginalInodeList.begin();
		for ( ; itClone != clonedInodeOriginalInodeList.end(); ++itClone)
		{
			itClone->first->SetMtl(itClone->second->GetMtl());
		}
		
		setVertexColorFlag();

		return true;
	}

	//------------------------------
	bool MaterialCreator::createAndAssingMaxMaterial( const DocumentImporter::NodeMaterialBindingsPair& materialBindingPair )
	{
		const DocumentImporter::MaterialBindingVector& materialBindings = materialBindingPair.materialBindings;
		INode* maxNode = materialBindingPair.maxNode;

		if ( materialBindings.size() == 0 )
			return true;

		const COLLADAFW::UniqueId& geometryUniqueId = getUniqueIdByObjectINode( maxNode );
		assert( geometryUniqueId.isValid() );

		// calculate largest material id
		int largestMaterialId = 0;
		DocumentImporter::MaterialBindingVector::const_iterator it = materialBindings.begin();

		for ( ; it != materialBindings.end(); ++it)
		{
			int materialId = (int)it->getMaterialId();
			largestMaterialId = materialId;
		}

		if ( !materialBindings.empty() )
		{
			if ( materialBindings.size() == 1 )
			{
				const COLLADAFW::MaterialBinding& materialBinding = materialBindings[0];
				const COLLADAFW::Effect* effect = getEffect(materialBinding);
				if ( !effect )
					return true;
				Mtl* newMaterial = getMaxMaterial(*effect, materialBinding, geometryUniqueId);
				maxNode->SetMtl( newMaterial );
			}
			else
			{
				MultiMtl * multiMaterial = NewDefaultMultiMtl();
				multiMaterial->SetNumSubMtls( largestMaterialId + 1 );
				String multiMaterialName = String(maxNode->GetName()) + "-MultiMaterial";
				multiMaterial->SetName(multiMaterialName.c_str());

				it = materialBindings.begin();
				for ( ; it != materialBindings.end(); ++it)
				{
					const COLLADAFW::MaterialBinding& materialBinding = *it;
					const COLLADAFW::Effect* effect = getEffect(materialBinding);
					if ( !effect )
						continue;
					Mtl* newMaterial = getMaxMaterial(*effect, materialBinding, geometryUniqueId);
					multiMaterial->SetSubMtl( materialBinding.getMaterialId(), newMaterial);
				}
				maxNode->SetMtl( multiMaterial );
			}
		}
		return true;
	}


	//------------------------------
	Mtl* MaterialCreator::createMaxMaterial( const COLLADAFW::Effect& effect, const MaterialCreator::MaterialIdentifier& materialIdentifier )
	{
		const COLLADAFW::CommonEffectPointerArray& commonEffects = effect.getCommonEffects();
		if ( commonEffects.getCount() > 0)
		{
			return createStandardMaterial(*commonEffects[0], effect.getName(), materialIdentifier);
		}

		return 0;
	}

	//------------------------------
	Mtl* MaterialCreator::getMaxMaterial( const COLLADAFW::Effect& effect, const COLLADAFW::MaterialBinding& materialBinding, const COLLADAFW::UniqueId& geometryUniqueId )
	{
		const DocumentImporter::SetMapChannelMap& setMapChannelMap = getSetMapChannelByGeometryUniqueId( geometryUniqueId );

		MaterialCreator::MaterialIdentifier materialIdentifier = getMaterialIdentifier( effect, materialBinding, setMapChannelMap );

		MaterialIdentifierMaxMaterialMap::const_iterator it = mMaterialIdentifierMaxMaterialMap.find(materialIdentifier);
		if ( it == mMaterialIdentifierMaxMaterialMap.end() )
		{
			// we need to create a new material
			Mtl* newMaterial = createMaxMaterial( effect, materialIdentifier );
			mMaterialIdentifierMaxMaterialMap.insert(std::make_pair(materialIdentifier, newMaterial));
			return newMaterial;
		}
		else
		{
			return it->second;
		}
	}


	//------------------------------
	void MaterialCreator::createAndAssignTexture( Mtl* material, 
												  const COLLADAFW::EffectCommon& effectCommon, 
												  const COLLADAFW::ColorOrTexture& (COLLADAFW::EffectCommon::*f)() const, 
												  int slot,
												  unsigned char mapChannel)
	{
		const COLLADAFW::ColorOrTexture& colorOrTexture = (effectCommon.*f)();
		if ( colorOrTexture.isTexture() )
		{
			BitmapTex* texture = createTexture( effectCommon, colorOrTexture.getTexture() );
			texture->GetUVGen()->SetMapChannel( mapChannel );

			assignTextureToMaterial(material, slot, texture);
		}
	}

	//------------------------------
	StdMat2* MaterialCreator::createStandardMaterial( const COLLADAFW::EffectCommon& effectCommon, const String& name, const MaterialCreator::MaterialIdentifier& materialIdentifier )
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

		float maxOpacity = 1;
		const COLLADAFW::ColorOrTexture& opacity = effectCommon.getOpacity();
		if ( opacity.isColor() )
		{
			const COLLADAFW::Color& opacityColor = opacity.getColor(); 
			float averageTransparent = (float)(opacityColor.getRed() + opacityColor.getGreen() + opacityColor.getBlue())/3; 
			maxOpacity = averageTransparent;
		}

		if ( getDocumentImporter()->getInvertTransparency() )
		{
			maxOpacity = 1 - maxOpacity;
		}

		// Max seems to like to have opacity 0 for opacity textures
		if ( opacity.isTexture() )
		{
			material->SetOpacity( 0, 0);
		}
		else
		{
			material->SetOpacity( maxOpacity, 0);
		}

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

		const COLLADAFW::ColorOrTexture& specular = effectCommon.getSpecular();
		const COLLADAFW::FloatOrParam& shininessFloatOrParam = effectCommon.getShininess();
		float shininess = 1;
		if ( shininessFloatOrParam.getType() == COLLADAFW::FloatOrParam::FLOAT )
		{
			shininess = shininessFloatOrParam.getFloatValue();
		}
		if ( shaderType == COLLADAFW::EffectCommon::SHADER_PHONG || shaderType == COLLADAFW::EffectCommon::SHADER_BLINN)
		{
			// Phong material parameters
			if ( specular.isColor() )
				material->SetSpecular( toMaxColor(specular), 0 );

			material->SetShininess(ConversionFunctors::fromPercent(shininess), 0);
			material->SetShinStr(ConversionFunctors::fromPercent(shininess), 0);
		}

		//create and assign textures
		createAndAssignTexture( material, effectCommon, &COLLADAFW::EffectCommon::getAmbient, ID_AM, materialIdentifier.ambientMapChannel);
		createAndAssignTexture( material, effectCommon, &COLLADAFW::EffectCommon::getDiffuse, ID_DI, materialIdentifier.diffuseMapChannel);
		createAndAssignTexture( material, effectCommon, &COLLADAFW::EffectCommon::getSpecular, ID_SP, materialIdentifier.specularMapChannel);
		createAndAssignTexture( material, effectCommon, &COLLADAFW::EffectCommon::getEmission, ID_SI, materialIdentifier.emissionMapChannel);
		createAndAssignTexture( material, effectCommon, &COLLADAFW::EffectCommon::getOpacity, ID_OP, materialIdentifier.opacityMapChannel);

		return material;
	}

	//------------------------------
	const COLLADAFW::Effect* MaterialCreator::getEffect( const COLLADAFW::MaterialBinding& materialBinding )
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

		UVGen* uvGen = bitmapTexture->GetTheUVGen();
		StdUVGen* stdUVGen = (StdUVGen*)uvGen;

		// reset all flags
		//stdUVGen->SetFlag(U_WRAP|V_WRAP, 1);
		//stdUVGen->SetFlag(U_MIRROR|V_MIRROR, 0);
		int tiling = 0;
		
		if ( sampler->getWrapS() == COLLADAFW::Sampler::WRAP_MODE_WRAP )
		{
			tiling += 1<<0;
		}
		else if ( sampler->getWrapS() == COLLADAFW::Sampler::WRAP_MODE_MIRROR )
		{
			tiling += 1<<2;
		}

		if ( sampler->getWrapT() == COLLADAFW::Sampler::WRAP_MODE_WRAP )
		{
			tiling += 1<<1;
		}
		else if ( sampler->getWrapT() == COLLADAFW::Sampler::WRAP_MODE_MIRROR )
		{
			tiling += 1<<3;
		}

		stdUVGen->SetTextureTiling(tiling);


		return bitmapTexture;
	}

	//------------------------------
	void MaterialCreator::assignTextureToMaterial( Mtl* material, int slot, BitmapTex* texture )
	{
		if ( !material ) 
			return;

		assert( (slot >= 0) && (slot < NTEXMAPS) );

		// Assign it to the material
		material->SetSubTexmap(slot, texture);

		// For diffuse textures, view them in the viewport
		if (slot == ID_DI)
		{
			// From Sparks Knowledge-base: "Topic: How to Activate a Texmap in viewport using API ??"
			material->SetActiveTexmap(texture);
			material->SetMtlFlag(MTL_TEX_DISPLAY_ENABLED);
			material->NotifyDependents(FOREVER, (PartID) PART_ALL, REFMSG_CHANGE);
		}

		// Read in the transparency mode for opacity textures
		if (slot == ID_OP)
		{
			//				BOOL isAlphaTranslucency = effect->GetTransparencyMode() == FCDEffectStandard::A_ONE;
			//				texture->SetAlphaAsMono(isAlphaTranslucency);
			//				texture->SetAlphaAsRGB(!isAlphaTranslucency); 
		}

		if (material->ClassID().PartA() == DMTL2_CLASS_ID || material->ClassID().PartA() == DMTL_CLASS_ID)
		{
			StdMat2* stdMat = (StdMat2*) material;
			// Override the default amount set here, the final amount will
			// be decided by the amount multipliers on the textures them selves
			stdMat->SetTexmapAmt(slot, 1.0f, 0);
		}
	}

	//------------------------------
	void MaterialCreator::setVertexColorFlag()
	{
		const DocumentImporter::UniqueIdList& vertexColorObjects = getVertexColorObjects();
		DocumentImporter::UniqueIdList::const_iterator it = vertexColorObjects.begin();
		for (; it != vertexColorObjects.end(); ++it)
		{
			const COLLADAFW::UniqueId& uniqueId = *it;
			INodeList iNodes;
			getObjectINodesByUniqueId( uniqueId, iNodes );
			INodeList::iterator nodeIt = iNodes.begin();
			for ( ; nodeIt != iNodes.end(); ++nodeIt )
			{
				INode* vertexObjectINode = *nodeIt;
				vertexObjectINode->SetCVertMode(true);
				vertexObjectINode->SetShadeCVerts(true);
			}
			
		}
		
	}


} // namespace COLLADAMax
