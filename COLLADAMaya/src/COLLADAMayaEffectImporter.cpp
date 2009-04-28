/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaEffectImporter.h"
#include "COLLADAMayaImageImporter.h"
#include "COLLADAMayaMaterialImporter.h"

#include "COLLADAFWEffect.h"

#include <MayaDMPlace2dTexture.h>
#include <MayaDMPlace3dTexture.h>
#include <MayaDMDefaultTextureList.h>
#include <MayaDMCommands.h>


namespace COLLADAMaya
{

    const String EffectImporter::COLLADA_EFFECT_ID_ATTRIBUTE_NAME = "colladaEffectId";
    const String EffectImporter::COLLADA_MATERIAL_ID_ATTRIBUTE_NAME = "colladaMaterialId";
    const String EffectImporter::COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME = "colladaEffectCommonId";

    const String EffectImporter::INITIAL_DEFAULT_EFFECT_NAME = "lambert1";
    const String EffectImporter::EFFECT_NAME = "effect";
    const String EffectImporter::PLACE_2D_TEXTURE_NAME = "place2dTexture";
    const String EffectImporter::PLACE_3D_TEXTURE_NAME = "place3dTexture";
    const String EffectImporter::DEFAULT_TEXTURE_LIST = ":defaultTextureList1";


    //------------------------------
	EffectImporter::EffectImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
        // "lambert1" is the maya default effect...
        mEffectIdList.addId ( INITIAL_DEFAULT_EFFECT_NAME );
    }
	
    //------------------------------
	EffectImporter::~EffectImporter()
	{
        UniqueIdMayaEffectsMap::iterator it = mMayaEffectsMap.begin ();
        while ( it != mMayaEffectsMap.end () )
        {
            MayaEffectList mayaEffectList = it->second;
            for ( size_t i=0; i<mayaEffectList.size (); ++i )
            {
                MayaDM::Lambert* lambert = mayaEffectList[i];
                delete lambert;
            }
            ++it;
        }

        TexturePlacementsMap::iterator it2 = mTexturePlacementsMap.begin ();
        while ( it2 != mTexturePlacementsMap.end () )
        {
            std::vector<TexturePlacement>& texturePlacements = it2->second;
            for ( size_t i=0; i<texturePlacements.size (); ++i )
            {
                TexturePlacement& texturePlacement = texturePlacements [i];
                MayaDM::DependNode* dependNode = texturePlacement.mTexturePlacementNode;
                delete dependNode;
            }
            texturePlacements.clear ();
            ++it2;
        }
        mTexturePlacementsMap.clear ();
    }

    //------------------------------
    bool EffectImporter::importEffect ( const COLLADAFW::Effect* effect )
    {
        // Check if the current effect is already imported.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        if ( findMayaEffects ( effectId ) != 0 ) return false;

        // Check how many collada materials use this effect 
        // and create one maya material for every collada material. 
        const UniqueIdVec* materialIds = findMaterialId ( effectId );
        if ( materialIds == 0 )
        {
            MGlobal::displayInfo ( "No material for the current effect! ");
            return false;
        }
        size_t numMaterials = materialIds->size ();
        for ( size_t i=0; i<numMaterials; ++i )
        {
            const COLLADAFW::UniqueId& materialId = (*materialIds) [i];

            // Create the maya effect in depend on the shader type.
            const COLLADAFW::CommonEffectPointerArray& commonEffects = effect->getCommonEffects ();
            size_t numCommonEffects = commonEffects.getCount ();
            if ( numCommonEffects > 1 )
            {
                MGlobal::displayWarning ( "Just one common effect can be imported!" );
            }
            if ( numCommonEffects > 0 )
            {
                for ( size_t i=0; i<1; ++i )
                {
                    COLLADAFW::EffectCommon* commonEffect = commonEffects [i];

                    // Import shader data by type.
                    importShaderData ( effect, commonEffect, materialId );

                    // Create the texture placement and push it to the image in a map.
                    importTexturePlacement ( effect, commonEffect );
                }
            }
        }

        return true;
    }

    // --------------------------
    void EffectImporter::importShaderData ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect,
        const COLLADAFW::UniqueId& materialId )
    {
        String effectName = "";

        const COLLADAFW::EffectCommon::ShaderType& shaderType = commonEffect->getShaderType ();
        switch ( shaderType )
        {
        case COLLADAFW::EffectCommon::SHADER_BLINN:
            effectName = importBlinnShader ( effect, commonEffect, materialId );
            break;
        case COLLADAFW::EffectCommon::SHADER_CONSTANT:
            // Import as a lambert shader.
            effectName = importLambertShader ( effect, commonEffect, materialId );
            break;
        case COLLADAFW::EffectCommon::SHADER_PHONG:
            effectName = importPhongShader ( effect, commonEffect, materialId );
            break;
        case COLLADAFW::EffectCommon::SHADER_LAMBERT:
            effectName = importLambertShader ( effect, commonEffect, materialId );
            break;
        case COLLADAFW::EffectCommon::SHADER_UNKNOWN:
        default:
            // Import as a lambert shader.
            MGlobal::displayWarning ( "Unknown shader type!");
            effectName = importLambertShader ( effect, commonEffect, materialId );
            break;
        }

        // Add the original collada ids to the new maya effect object.
        if ( !COLLADABU::Utils::equals ( effectName, COLLADABU::Utils::EMPTY_STRING ) )
        {
            // Adds the attributes with the original collada ids.
            addOriginalColladaIds ( effect, materialId, commonEffect );

            // Create the shader data with the shading engine and the material info of the material.
            MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
            MaterialImporter::ShadingData* shaderData = materialImporter->createShaderData ( materialId );
        }
    }

    //------------------------------
    String EffectImporter::importBlinnShader ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect, 
        const COLLADAFW::UniqueId& materialId )
    {
        // Get the material name, which references this effect.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        MayaNode* materialNode = materialImporter->findMayaMaterialNode ( materialId );
        String effectName = materialNode->getName ();
        effectName = mEffectIdList.addId ( effectName );

//         // Get the effect name.
//         String effectName = effect->getName ();
//         if ( COLLADABU::Utils::equals ( effectName, COLLADABU::Utils::EMPTY_STRING ) )
//             effectName = EFFECT_NAME;
//         effectName = DocumentImporter::frameworkNameToMayaName ( effectName );
//         effectName = mEffectIdList.addId ( effectName );

        // Create the effect and write it into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Blinn* blinn = new MayaDM::Blinn ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( blinn, effect );
        importLambertShaderAttributes ( SHADER_BLINN, blinn, effect, commonEffect );
        importReflectShaderAttributes ( SHADER_BLINN, blinn, effect, commonEffect );
        importBlinnShaderAttributes ( blinn, commonEffect );

        // Push it into the map.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        appendMayaEffect ( effectId, blinn );

        return effectName;
    }

    //------------------------------
    String EffectImporter::importPhongShader ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect,
        const COLLADAFW::UniqueId& materialId )
    {
        // Get the material name, which references this effect.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        MayaNode* materialNode = materialImporter->findMayaMaterialNode ( materialId );
        String effectName = materialNode->getName ();
        effectName = mEffectIdList.addId ( effectName );

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Phong* phong = new MayaDM::Phong ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( phong, effect );
        importLambertShaderAttributes ( SHADER_PHONG, phong, effect, commonEffect );
        importReflectShaderAttributes ( SHADER_PHONG, phong, effect, commonEffect );
        importPhongShaderAttributes ( phong, commonEffect );

        // Push it into the map.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        appendMayaEffect ( effectId, phong );

        return effectName;
    }

    //------------------------------
    String EffectImporter::importLambertShader ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect, 
        const COLLADAFW::UniqueId& materialId )
    {
        // Get the material name, which references this effect.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        MayaNode* materialNode = materialImporter->findMayaMaterialNode ( materialId );
        String effectName = materialNode->getName ();
        effectName = mEffectIdList.addId ( effectName );

        // A "lambert1" has to be a lambert effect.
        if ( COLLADABU::Utils::equalsIgnoreCase ( effectName, INITIAL_DEFAULT_EFFECT_NAME ) ) 
            mEffectIdList.addId ( INITIAL_DEFAULT_EFFECT_NAME );

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Lambert* lambert = new MayaDM::Lambert ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( lambert, effect );
        importLambertShaderAttributes ( SHADER_LAMBERT, lambert, effect, commonEffect );

        // Push it into the map.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        appendMayaEffect ( effectId, lambert );

        return effectName;
    }

    // --------------------------
    void EffectImporter::importStandardShaderAttributes ( 
        MayaDM::Lambert* shaderNode, 
        const COLLADAFW::Effect* effect )
    {
        // Get the color and set it into the shader node (if it is a valid color).
        const COLLADAFW::Color& standardColor = effect->getStandardColor ();
        if ( standardColor.isValid () && standardColor != COLLADAFW::Color::GREY )
        {
            shaderNode->setColor ( MayaDM::float3 ( (float)standardColor.getRed (), (float)standardColor.getGreen (), (float)standardColor.getBlue ()) );
        }

        // Push the animation id in a map, if it exist.
        const COLLADAFW::UniqueId& animationListId = standardColor.getAnimationList ();
        if ( animationListId.isValid () )
        {
            EffectAnimation effectAnimation;
            effectAnimation.setAnimationListId ( animationListId );
            effectAnimation.setEffectId ( effect->getUniqueId () );
            effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_STANDARD );

            mEffectAnimationMap [animationListId] = effectAnimation;
        }

        // Set the diffuse factor to one.
        shaderNode->setDiffuse ( 1.0f );
    }

    // --------------------------
    void EffectImporter::importLambertShaderAttributes ( 
        const ShaderType& shaderType, 
        MayaDM::Lambert* shaderNode, 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Ambient color
        const COLLADAFW::ColorOrTexture& ambientColor = commonEffect->getAmbient ();
        if ( ambientColor.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = ambientColor.getColor ();
            if ( color.isValid () && color != COLLADAFW::Color::BLACK )
                shaderNode->setAmbientColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );

            // Push the animation id in a map, if it exist.
            const COLLADAFW::UniqueId& animationListId = color.getAnimationList ();
            if ( animationListId.isValid () )
            {
                EffectAnimation effectAnimation;
                effectAnimation.setAnimationListId ( animationListId );
                effectAnimation.setEffectId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_AMBIENT );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( ambientColor.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = ambientColor.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_AMBIENT;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }

        // Diffuse color
        const COLLADAFW::ColorOrTexture& diffuse = commonEffect->getDiffuse ();
        if ( diffuse.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = diffuse.getColor ();
            if ( color.isValid () && color != COLLADAFW::Color::BLACK )
                shaderNode->setColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );

            // Push the animation id in a map, if it exist.
            const COLLADAFW::UniqueId& animationListId = color.getAnimationList ();
            if ( animationListId.isValid () )
            {
                EffectAnimation effectAnimation;
                effectAnimation.setAnimationListId ( animationListId );
                effectAnimation.setEffectId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_DIFFUSE );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( diffuse.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = diffuse.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_COLOR;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }

        // Emission
        const COLLADAFW::ColorOrTexture& emission = commonEffect->getEmission ();
        if ( emission.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = emission.getColor ();
            if ( color.isValid () && color != COLLADAFW::Color::BLACK )
                shaderNode->setIncandescence ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );

            // Push the animation id in a map, if it exist.
            const COLLADAFW::UniqueId& animationListId = color.getAnimationList ();
            if ( animationListId.isValid () )
            {
                EffectAnimation effectAnimation;
                effectAnimation.setAnimationListId ( animationListId );
                effectAnimation.setEffectId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_EMISSION );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( emission.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = diffuse.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_INCANDESCENE;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }

        // Index of refraction 
        const COLLADAFW::FloatOrParam& indexOfRefraction = commonEffect->getIndexOfRefraction ();
        if ( indexOfRefraction > 0 ) shaderNode->setRefractiveIndex ( indexOfRefraction );
//         if ( indexOfRefraction.getType () == COLLADAFW::FloatOrParam::FLOAT )
//         {
//             float val = indexOfRefraction.getFloatValue (); 
//             if ( val > 0 ) shaderNode->setRefractiveIndex ( val );
//         }
        // TODO Animation import

        // Opaque color
        const COLLADAFW::ColorOrTexture& opaque = commonEffect->getOpacity();
        if ( opaque.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = opaque.getColor ();
            if ( color.isValid () && color != COLLADAFW::Color::WHITE )
            {
                // Maya handels the transparency, not the opaque, so we have to invert the color.
                COLLADAFW::Color transparency ( 1-color.getRed (), 1-color.getGreen (), 1-color.getBlue (), color.getAlpha () );
                shaderNode->setTransparency ( MayaDM::float3 ( (float)transparency.getRed (), (float)transparency.getGreen (), (float)transparency.getBlue ()) );
            }
            // Push the animation id in a map, if it exist.
            const COLLADAFW::UniqueId& animationListId = color.getAnimationList ();
            if ( animationListId.isValid () )
            {
                EffectAnimation effectAnimation;
                effectAnimation.setAnimationListId ( animationListId );
                effectAnimation.setEffectId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_TRANSPARENCY );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( opaque.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = diffuse.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_TRANSPARENT;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
    }

    // --------------------------
    void EffectImporter::importBlinnShaderAttributes ( 
        MayaDM::Blinn* shaderNode, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Shininess
        const COLLADAFW::FloatOrParam& shininess = commonEffect->getShininess ();
        if ( shininess > 0 ) shaderNode->setEccentricity ( shininess );
//         if ( shininess.getType () == COLLADAFW::FloatOrParam::FLOAT )
//         {
//             float val = shininess.getFloatValue (); 
//             if ( val > 0 ) shaderNode->setEccentricity ( val );
//         }
        // TODO Animation import
    }

    // --------------------------
    void EffectImporter::importPhongShaderAttributes ( 
        MayaDM::Phong* shaderNode, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Shininess
        const COLLADAFW::FloatOrParam& shininess = commonEffect->getShininess ();
        if ( shininess > 0 ) shaderNode->setCosinePower ( shininess );
//         if ( shininess.getType () == COLLADAFW::FloatOrParam::FLOAT )
//         {
//             float val = shininess.getFloatValue (); 
//             if ( val > 0 ) shaderNode->setCosinePower ( val );
//         }
        // TODO Animation import
    }

    // --------------------------
    void EffectImporter::importReflectShaderAttributes ( 
        const ShaderType& shaderType, 
        MayaDM::Reflect* shaderNode, 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Reflective
        const COLLADAFW::ColorOrTexture& reflective = commonEffect->getReflective ();
        if ( reflective.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = reflective.getColor ();
            if ( color.isValid () && color != COLLADAFW::Color::BLACK )
                shaderNode->setReflectedColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );

            // Push the animation id in a map, if it exist.
            const COLLADAFW::UniqueId& animationListId = color.getAnimationList ();
            if ( animationListId.isValid () )
            {
                EffectAnimation effectAnimation;
                effectAnimation.setAnimationListId ( animationListId );
                effectAnimation.setEffectId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_REFLECTED );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }

        }
        else if ( reflective.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = reflective.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_REFLECTIVE;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }

        // Reflectivity
        const COLLADAFW::FloatOrParam& reflectivity = commonEffect->getReflectivity ();
        if ( reflectivity > 0 ) shaderNode->setReflectivity ( reflectivity );
//         if ( reflectivity.getType () == COLLADAFW::FloatOrParam::FLOAT )
//         {
//             float val = reflectivity.getFloatValue (); 
//             if ( val > 0 ) shaderNode->setReflectivity ( val );
//         }
        // TODO Animation import

        // TODO
//         const COLLADAFW::FloatOrParam::Type& type = reflectivity.getType ();
//         switch ( type )
//         {
//         case COLLADAFW::FloatOrParam::FLOAT:
//             break;
//         case COLLADAFW::FloatOrParam::PARAM:
//             break;
//         default:
//             MGlobal::displayError ( "Unknown param type!" );
//             std::cerr << "Unknown param type!" << endl;
//             break;
//         }

        // Specular
        const COLLADAFW::ColorOrTexture& specular = commonEffect->getSpecular ();
        if ( specular.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = specular.getColor ();
            if ( color.isValid () && color != COLLADAFW::Color::GREY )
                shaderNode->setSpecularColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );

            // Push the animation id in a map, if it exist.
            const COLLADAFW::UniqueId& animationListId = color.getAnimationList ();
            if ( animationListId.isValid () )
            {
                EffectAnimation effectAnimation;
                effectAnimation.setAnimationListId ( animationListId );
                effectAnimation.setEffectId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_SPECULAR );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( specular.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = specular.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_SPECULAR;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
    }

    //------------------------------
    void EffectImporter::addOriginalColladaIds ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::UniqueId& materialId, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        FILE* file = getDocumentImporter ()->getFile ();

        // Add the original effect id attribute.
        String colladaEffectId = effect->getOriginalId ();
        if ( !COLLADABU::Utils::equals ( colladaEffectId, "" ) )
        {
            MayaDM::addAttr ( file, COLLADA_EFFECT_ID_ATTRIBUTE_NAME, "", "string" );
            MayaDM::setAttr ( file, COLLADA_EFFECT_ID_ATTRIBUTE_NAME, "", "string", colladaEffectId );
        }

        // Add the original id attribute of the material.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        String colladaMaterialId = materialImporter->findOriginalColladaId ( materialId );
        if ( !COLLADABU::Utils::equals ( colladaMaterialId, "" ) )
        {
            MayaDM::addAttr ( file, COLLADA_MATERIAL_ID_ATTRIBUTE_NAME, "", "string" );
            MayaDM::setAttr ( file, COLLADA_MATERIAL_ID_ATTRIBUTE_NAME, "", "string", colladaMaterialId );
        }

        // Add the original id attribute of the effect common.
        String colladaEffectCommonId = commonEffect->getOriginalId ();
        if ( !COLLADABU::Utils::equals ( colladaEffectCommonId, "" ) )
        {
            MayaDM::addAttr ( file, COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME, "", "string" );
            MayaDM::setAttr ( file, COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME, "", "string", colladaEffectCommonId );
        }
    }

    // --------------------------
    const EffectImporter::MayaEffectList* EffectImporter::findMayaEffects ( const COLLADAFW::UniqueId& effectId ) const
    {
        UniqueIdMayaEffectsMap::const_iterator it = mMayaEffectsMap.find ( effectId );
        if ( it != mMayaEffectsMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // -----------------------------------
    const EffectImporter::UniqueIdVec* EffectImporter::findMaterialId ( const COLLADAFW::UniqueId& effectId )
    {
        UniqueIdUniqueIdsMap::const_iterator it = mEffectIdMaterialIdsMap.find ( effectId );
        if ( it == mEffectIdMaterialIdsMap.end () )
        {
            return 0;
        }

        return &(it->second);
    }

    // --------------------------
    void EffectImporter::appendMayaEffect ( 
        const COLLADAFW::UniqueId& effectId, 
        MayaDM::Lambert* effectNode )
    {
        mMayaEffectsMap [effectId].push_back ( effectNode );
    }

    // --------------------------
    void EffectImporter::assignMaterial ( 
        const COLLADAFW::UniqueId& effectId, 
        const COLLADAFW::UniqueId& materialId )
    {
        mEffectIdMaterialIdsMap [effectId].push_back ( materialId );
    }

    // --------------------------
    void EffectImporter::appendTextureAttribute ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::Texture &texture, 
        const ShaderType& shaderType, 
        const ShaderAttribute& shaderAttribute, 
        MayaDM::Lambert* shaderNode )
    {
        // Get the effect id.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();

        // Get the current sampler id.
        COLLADAFW::SamplerID samplerId = texture.getSamplerId ();

        // Save the samplerId to this effect, so we can do the connection one time later.
        ShaderNodeAttribute shaderNodeAttribute;
        shaderNodeAttribute.mSamplerId = samplerId;
        shaderNodeAttribute.mShaderType = shaderType;
        shaderNodeAttribute.mShaderAttribute = shaderAttribute;
        shaderNodeAttribute.mShaderNode = shaderNode;

        // Push the shader node attribute data in the map to the effect.
        mEffectShaderNodesMap [ effectId ].push_back ( shaderNodeAttribute );

    }

    // --------------------------
    void EffectImporter::importTexturePlacement ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        const COLLADAFW::SamplerPointerArray& samplers = commonEffect->getSamplerPointerArray ();
        size_t numSamplers = samplers.getCount ();
        for ( size_t samplerId=0; samplerId<numSamplers; ++samplerId )
        {
            COLLADAFW::Sampler* sampler = samplers [samplerId];
            
            const COLLADAFW::UniqueId& imageId = sampler->getSourceImage ();
            COLLADAFW::Sampler::SamplerType samplerType = sampler->getSamplerType ();

            // Create a sampler info object.
            SamplerInfo samplerInfo;
            samplerInfo.mImageId = imageId;
            samplerInfo.mSamplerId = samplerId;

            // Push the sampler info in the effect's list of sampler infos.
            const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
            mEffectSamplerInfosMap [effectId].push_back (samplerInfo);

            // Every image needs one texture placement for every sampler, which use this image.
            UniqueIdSamplerIdPair uniquePair ( imageId, samplerId );
            if ( findTexturePlacements ( uniquePair ) == 0 )
            {
                switch ( samplerType )
                {
                case COLLADAFW::Sampler::SAMPLER_TYPE_2D:
                    {
                        // TODO Create this in depend on the texture mapping of effects.
                        // createNode place2dTexture -n "place2dTexture1";
                        String place2dTextureName = mPlace2dTextureIdList.addId ( PLACE_2D_TEXTURE_NAME, true, true );
                        MayaDM::Place2dTexture* place2dTexture = new MayaDM::Place2dTexture ( file, place2dTextureName );

                        // TODO What to do with this attributes???
                        sampler->getBorderColor ();
                        sampler->getMagFilter ();
                        sampler->getMinFilter ();
                        sampler->getMipFilter ();
                        sampler->getMipmapBias ();
                        sampler->getMipmapMaxlevel ();
//                     place2dTexture->setWrapU ( sampler->getWrapP () );
//                     place2dTexture->setWrapV ( sampler->getWrapS () );
                        sampler->getWrapT ();

                        // TODO Push the texure placement informations in a list.
                        TexturePlacement texturePlacement;
                        texturePlacement.mImageId = imageId;
                        texturePlacement.mSamplerId = samplerId;
                        texturePlacement.mSamplerType = samplerType;
                        texturePlacement.mTexturePlacementNode = place2dTexture;

                        mTexturePlacementsMap [uniquePair].push_back ( texturePlacement );
                        break;
                    }
                case COLLADAFW::Sampler::SAMPLER_TYPE_1D:
                case COLLADAFW::Sampler::SAMPLER_TYPE_3D:
                case COLLADAFW::Sampler::SAMPLER_TYPE_CUBE:
                case COLLADAFW::Sampler::SAMPLER_TYPE_DEPTH:
                case COLLADAFW::Sampler::SAMPLER_TYPE_RECT:
                case COLLADAFW::Sampler::SAMPLER_TYPE_STATE:
                case COLLADAFW::Sampler::SAMPLER_TYPE_UNSPECIFIED:
                default:
                    MGlobal::displayError ( "Sampler type not implemented: " + samplerType );
                    MGlobal::doErrorLogEntry ( "Sampler type not implemented: " + samplerType );
                    std::cerr << "Sampler type not implemented: " << samplerType << endl;
                    break;
                }
            }
        }
    }

    // --------------------------
    const EffectImporter::SamplerInfos* EffectImporter::findEffectSamplerInfos ( 
        const COLLADAFW::UniqueId& effectId )
    {
        UniqueIdSamplerInfosMap::const_iterator it = mEffectSamplerInfosMap.find ( effectId );
        if ( it == mEffectSamplerInfosMap.end () )
        {
            return 0;
        }
        return &(it->second);
    }

    //------------------------------
    EffectImporter::TexturePlacements* EffectImporter::findTexturePlacements ( 
        const UniqueIdSamplerIdPair& key )
    {
        TexturePlacementsMap::iterator it = mTexturePlacementsMap.find ( key );
        if ( it != mTexturePlacementsMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    //------------------------------
    const EffectAnimation* EffectImporter::findEffectAnimation ( const COLLADAFW::UniqueId& animationListId )
    {
        const EffectAnimationMap::const_iterator it = mEffectAnimationMap.find ( animationListId );
        if ( it != mEffectAnimationMap.end () )
        {
            return &(it->second);
        }
        return 0;
    }

    // --------------------------
    void EffectImporter::writeConnections ()
    {
        // Connect the texture placements.
        connectTexturePlacements ();
        
        // Connect the file textures and the effects.
        connectTextures ();
    }

    // --------------------------
    void EffectImporter::connectTexturePlacements ()
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Writes the connections of the effect texture placements to the image files.  
        TexturePlacementsMap::const_iterator it = mTexturePlacementsMap.begin ();
        while ( it != mTexturePlacementsMap.end () )
        {
            const std::vector<TexturePlacement>& texturePlacements = it->second;
            for ( size_t i=0; i<texturePlacements.size (); ++i )
            {
                const TexturePlacement& texturePlacement = texturePlacements [i];

                const COLLADAFW::UniqueId& imageId = texturePlacement.mImageId;
                ImageImporter* imageImporter = getDocumentImporter ()->getImageImporter ();
                const MayaDM::File* imageFile = imageImporter->findMayaImageFile ( imageId );

                const size_t samplerId = texturePlacement.mSamplerId;

                const COLLADAFW::Sampler::SamplerType samplerType = texturePlacement.mSamplerType;
                switch ( samplerType )
                {
                case COLLADAFW::Sampler::SAMPLER_TYPE_2D:
                    {
                        MayaDM::Place2dTexture* place2dTexture = ( MayaDM::Place2dTexture* ) texturePlacement.mTexturePlacementNode;
                        connectAttr ( file, place2dTexture->getOutUV (), imageFile->getUvCoord () );
                        connectAttr ( file, place2dTexture->getOutUvFilterSize (), imageFile->getUvFilterSize () );
                        connectAttr ( file, place2dTexture->getVertexUvOne (), imageFile->getVertexUvOne () );
                        connectAttr ( file, place2dTexture->getVertexUvTwo (), imageFile->getVertexUvTwo () );
                        connectAttr ( file, place2dTexture->getVertexUvThree (), imageFile->getVertexUvThree () );
                        connectAttr ( file, place2dTexture->getVertexCameraOne (), imageFile->getVertexCameraOne () );
                        connectAttr ( file, place2dTexture->getOffset (), imageFile->getOffset () );
                        connectAttr ( file, place2dTexture->getStagger (), imageFile->getStagger () );
                        connectAttr ( file, place2dTexture->getCoverage (), imageFile->getCoverage () );
                        connectAttr ( file, place2dTexture->getTranslateFrame (), imageFile->getTranslateFrame () );
                        connectAttr ( file, place2dTexture->getMirrorU (), imageFile->getMirrorU () );
                        connectAttr ( file, place2dTexture->getMirrorV (), imageFile->getMirrorV () );
                        connectAttr ( file, place2dTexture->getWrapU (), imageFile->getWrapU () );
                        connectAttr ( file, place2dTexture->getWrapV (), imageFile->getWrapV () );
                        connectAttr ( file, place2dTexture->getNoiseUV (), imageFile->getNoiseUV () );
                        connectAttr ( file, place2dTexture->getRotateUV (), imageFile->getRotateUV () );
                        connectAttr ( file, place2dTexture->getRepeatUV (), imageFile->getRepeatUV () );
                        break;
                    }
                case COLLADAFW::Sampler::SAMPLER_TYPE_1D:
                case COLLADAFW::Sampler::SAMPLER_TYPE_3D:
                case COLLADAFW::Sampler::SAMPLER_TYPE_CUBE:
                case COLLADAFW::Sampler::SAMPLER_TYPE_DEPTH:
                case COLLADAFW::Sampler::SAMPLER_TYPE_RECT:
                case COLLADAFW::Sampler::SAMPLER_TYPE_STATE:
                case COLLADAFW::Sampler::SAMPLER_TYPE_UNSPECIFIED:
                default:
                    MGlobal::displayError ( "Sampler type not implemented: " + samplerType );
                    MGlobal::doErrorLogEntry ( "Sampler type not implemented: " + samplerType );
                    std::cerr << "Sampler type not implemented: " << samplerType << endl;
                    break;
                }
            }
            ++it;
        }
    }

    //------------------------------
    void EffectImporter::connectTextures ()
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Get the current image importer.
        ImageImporter* imageImporter = getDocumentImporter ()->getImageImporter ();

        //  Create the defaultTextureList object
        MayaDM::DefaultTextureList defaultTextureList ( file, DEFAULT_TEXTURE_LIST, "", false );

        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        const UniqueIdShaderNodesMap& effectShaderNodesMap = effectImporter->getEffectShaderNodesMap ();
        UniqueIdShaderNodesMap::const_iterator it = effectShaderNodesMap.begin ();
        while ( it != effectShaderNodesMap.end () )
        {
            const COLLADAFW::UniqueId& effectId = it->first;

            const std::vector<ShaderNodeAttribute>& shaderNodeAttributes = it->second;
            for ( size_t i=0; i<shaderNodeAttributes.size (); ++i )
            {
                // Get the current shader node attribute.
                const ShaderNodeAttribute& shaderNodeAttribute = shaderNodeAttributes [i];

                // Get the current sampler id.
                const COLLADAFW::SamplerID& samplerId = shaderNodeAttribute.mSamplerId;

                // Get the effect's sampler infos
                const SamplerInfos* samplerInfos = effectImporter->findEffectSamplerInfos ( effectId );
                if ( samplerInfos == 0 )
                {
                    MGlobal::displayError ( "No sampler info for effect available! ");
                    continue;
                }

                size_t numSamplers = samplerInfos->size ();
                for ( size_t i=0; i<numSamplers; ++i )
                {
                    const SamplerInfo samplerInfo = (*samplerInfos) [i];

                    if ( samplerId == samplerInfo.mSamplerId )
                    {
                        const COLLADAFW::UniqueId& imageId = samplerInfo.mImageId;
                        const MayaDM::File* imageFile = imageImporter->findMayaImageFile ( imageId );

                        // TODO Check if this connection already exist.
                        // connectAttr "file1.message" ":defaultTextureList1.textures" -nextAvailable;
                        connectNextAttr ( file, imageFile->getMessage (), defaultTextureList.getTextures () );

                        // Connect the image file out color with the material's texture attribute.
                        // connectAttr "file1.outColor" "lambert2.color";
                        connectTextureAttribute ( shaderNodeAttribute, imageFile );

                        // Get the current effect's material materialInfo object.
                        const UniqueIdVec* materialIds = effectImporter->findMaterialId ( effectId );
                        if ( materialIds == 0 )
                        {
                            MGlobal::displayInfo ( "No material for the current effect! ");
                            continue;
                        }
                        size_t numMaterials = materialIds->size ();
                        for ( size_t i=0; i<numMaterials; ++i )
                        {
                            const COLLADAFW::UniqueId& materialId = (*materialIds) [i];

                            // Get the maya materialInfo object.
                            MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
                            MaterialImporter::ShadingData* shadingData = materialImporter->findShaderData ( materialId );
                            if ( shadingData == 0 ) 
                            {
                                MGlobal::displayError ( "No material info for current material!" );
                                continue;
                            }
                            const MayaDM::MaterialInfo& materialInfo = shadingData->getMaterialInfo ();

                            // Connect the image file message with the materials materialInfo texture attribute.
                            // connectAttr "file1.message" "materialInfo1.texture" -nextAvailable;
                            connectNextAttr ( file, imageFile->getMessage (), materialInfo.getTexture () );
                        }
                    }
                }
            }

            ++it;
        }
    }

    //------------------------------
    void EffectImporter::connectTextureAttribute ( 
        const ShaderNodeAttribute& shaderNodeAttribute, 
        const MayaDM::File* imageFile )
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        const EffectImporter::ShaderAttribute& shaderAttribute = shaderNodeAttribute.mShaderAttribute;
        switch ( shaderAttribute )
        {
        case EffectImporter::ATTR_COLOR:
            {
                MayaDM::Lambert* shaderNode = shaderNodeAttribute.mShaderNode;
                connectAttr ( file, imageFile->getOutColor (), shaderNode->getColor () );
                break;
            }
        case EffectImporter::ATTR_AMBIENT:
            {
                MayaDM::Lambert* shaderNode = shaderNodeAttribute.mShaderNode;
                connectAttr ( file, imageFile->getOutColor (), shaderNode->getAmbientColor () );
                break;
            }
        case EffectImporter::ATTR_INCANDESCENE:
            {
                MayaDM::Lambert* shaderNode = shaderNodeAttribute.mShaderNode;
                connectAttr ( file, imageFile->getOutColor(), shaderNode->getIncandescence () );
                break;
            }
        case EffectImporter::ATTR_REFLECTIVE:
            {
                MayaDM::Lambert* shaderNode = shaderNodeAttribute.mShaderNode;
                switch ( shaderNodeAttribute.mShaderType )
                {
                case EffectImporter::SHADER_BLINN:
                    {
                        MayaDM::Blinn* blinnNode = ( MayaDM::Blinn* ) shaderNode;
                        connectAttr ( file, imageFile->getOutColor (), blinnNode->getReflectedColor () );
                        break;
                    }
                case EffectImporter::SHADER_PHONG:
                    {
                        MayaDM::Phong* phongNode = ( MayaDM::Phong* ) shaderNode;
                        connectAttr ( file, imageFile->getOutColor (), phongNode->getReflectedColor () );
                        break;
                    }
                default:
                    MGlobal::displayWarning ( "No valid shader type for shader node attribute ATTR_REFLECTIVE.\n");
                    break;
                }
                break;
            }
        case EffectImporter::ATTR_SPECULAR:
            {
                MayaDM::Lambert* shaderNode = shaderNodeAttribute.mShaderNode;
                switch ( shaderNodeAttribute.mShaderType )
                {
                case EffectImporter::SHADER_BLINN:
                    {
                        MayaDM::Blinn* blinnNode = ( MayaDM::Blinn* ) shaderNode;
                        connectAttr ( file, imageFile->getOutColor (), blinnNode->getSpecularColor () );
                        break;
                    }
                case EffectImporter::SHADER_PHONG:
                    {
                        MayaDM::Phong* phongNode = ( MayaDM::Phong* ) shaderNode;
                        connectAttr ( file, imageFile->getOutColor (), phongNode->getSpecularColor () );
                        break;
                    }
                default:
                    MGlobal::displayWarning ( "No valid shader type for shader node attribute ATTR_SPECULAR.\n");
                    break;
                }
                break;
            }
        case EffectImporter::ATTR_TRANSPARENT:
            {
                MayaDM::Lambert* shaderNode = shaderNodeAttribute.mShaderNode;
                connectAttr ( file, imageFile->getOutColor (), shaderNode->getTransparency () );
                break;
            }
        case EffectImporter::ATTR_UNKNOWN:
        default:
            {
                MGlobal::displayWarning ( "No valid shader node attribute!\n");
                break;
            }
        }
    }

} // namespace COLLADAMaya
