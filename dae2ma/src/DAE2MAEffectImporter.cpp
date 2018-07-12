/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MAEffectImporter.h"
#include "DAE2MAImageImporter.h"
#include "DAE2MAMaterialImporter.h"

#include "COLLADAFWEffect.h"

#include <MayaDMPlace2dTexture.h>
#include <MayaDMPlace3dTexture.h>
#include <MayaDMDefaultTextureList.h>
#include <MayaDMCommands.h>


namespace DAE2MA
{

    const String EffectImporter::EFFECT_NAME = "effect";
    const String EffectImporter::PLACE_2D_TEXTURE_NAME = "place2dTexture";
    const String EffectImporter::PLACE_3D_TEXTURE_NAME = "place3dTexture";
    const String EffectImporter::DEFAULT_TEXTURE_LIST = "defaultTextureList1";


    //------------------------------
	EffectImporter::EffectImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{
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
            std::cerr << "No material for the current effect! " << std::endl;
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
                std::cerr << "Just one common effect can be imported!" << std::endl;
            }
            if ( numCommonEffects > 0 )
            {
                for ( size_t i=0; i<1; ++i )
                {
                    COLLADAFW::EffectCommon* commonEffect = commonEffects [i];

                    // Import shader data by type.
                    importShaderData ( effect, commonEffect, materialId );

                    // Create the texture placement and push it to the image in a map.
                    createTexturePlacements ( effect, commonEffect );
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
        String effectName = EMPTY_STRING;

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
            std::cerr <<  "Unknown shader type!" << std::endl;
            effectName = importLambertShader ( effect, commonEffect, materialId );
            break;
        }

        // Create the shader data and add the original collada ids to the new maya effect object.
        if ( !effectName.empty () )
        {
            // Adds the attributes with the original collada ids.
            addOriginalColladaIds ( effect, materialId, commonEffect );

            // TODO
//             // Add the effect attributes for all the extra tags to the maya effect.
//             const COLLADAFW::ExtraDataArray& effectExtraDataArray = effect->getExtraDataArray ();

            // Add the material attributes for all the extra tags to the maya effect.
            const COLLADAFW::Material* material = getDocumentImporter ()->getMaterialById ( materialId );
//             const COLLADAFW::ExtraDataArray& materialExtraDataArray = material->getExtraDataArray ();
// 
//             // Generate an array with all the extra data elements.
//             COLLADAFW::ExtraDataArray extraDataArray ( effectExtraDataArray );
//             extraDataArray.appendValues ( materialExtraDataArray );
// 
//             // Set the extra data elements.
//             setExtraData ( extraDataArray );

            // Create the shader data with the shading engine and the material info of the material.
            MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
            String shadingEngineName = effectName + "SG";
            materialImporter->createShaderData ( materialId, shadingEngineName );
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

//         // TODO Doesn't work on file import, just on file open!
//         // Check, if the name of the material is "lambert1". This is just possible, if we create a 
//         // shared lambert shader! Otherwise we need another name!
//         if ( COLLADABU::Utils::equals ( effectName, MaterialImporter::INITIAL_MATERIAL_NAME ) ) 
//         {
//             // Generate a new name and set it into the maya node.
//             effectName = generateUniqueDependNodeName ( effectName );
//             materialNode->setName ( effectName );
//         }

        // Create the effect and write it into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Blinn* blinn = new MayaDM::Blinn ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( blinn, effect );
        importLambertShaderAttributes ( SHADER_BLINN, blinn, effect, commonEffect );
        importReflectShaderAttributes ( SHADER_BLINN, blinn, effect, commonEffect );
        importBlinnShaderAttributes ( blinn, effect, commonEffect );

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

//         // TODO Doesn't work on file import, just on file open!
//         // Check, if the name of the material is "lambert1". This is just possible, if we create a 
//         // shared lambert shader! Otherwise we need another name!
//         if ( COLLADABU::Utils::equals ( effectName, MaterialImporter::INITIAL_MATERIAL_NAME ) ) 
//         {
//             // Generate a new name and set it into the maya node.
//             effectName = generateUniqueDependNodeName ( effectName );
//             materialNode->setName ( effectName );
//         }

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Phong* phong = new MayaDM::Phong ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( phong, effect );
        importLambertShaderAttributes ( SHADER_PHONG, phong, effect, commonEffect );
        importReflectShaderAttributes ( SHADER_PHONG, phong, effect, commonEffect );
        importPhongShaderAttributes ( phong, effect, commonEffect );

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

        bool shared = false;
//         // TODO Doesn't work on file import, just on file open!
//         // Check, if we want to creat a shared shader!
//         bool shared = false;
//         if ( COLLADABU::Utils::equals ( effectName, MaterialImporter::INITIAL_MATERIAL_NAME ) ) shared = true;

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Lambert* lambert = new MayaDM::Lambert ( file, effectName, EMPTY_STRING, shared );

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
            effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
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
                effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
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
            appendTextureInfo ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
        else
        {
            // The maya default color is grey. The framework/collada uses black.
            shaderNode->setAmbientColor ( MayaDM::float3 ( 0.0f,0.0f,0.0f ) );
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
                effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
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
            appendTextureInfo ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
        else
        {
            // The maya default color is grey. The framework/collada uses black.
            shaderNode->setColor ( MayaDM::float3 ( 0.0f,0.0f,0.0f ) );
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
                effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_EMISSION );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( emission.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = emission.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_INCANDESCENE;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureInfo ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
        else
        {
            // The maya default color is grey. The framework/collada uses black.
            shaderNode->setIncandescence ( MayaDM::float3 ( 0.0f,0.0f,0.0f ) );
        }

        // Index of refraction 
        const COLLADAFW::FloatOrParam& indexOfRefractionFOP = commonEffect->getIndexOfRefraction ();
        if ( indexOfRefractionFOP.getType () == COLLADAFW::FloatOrParam::FLOAT )
        {
            float indexOfRefraction = indexOfRefractionFOP.getFloatValue (); 
            if ( indexOfRefraction > 0 )
            {
                shaderNode->setRefractions ( true );
                shaderNode->setRefractiveIndex ( indexOfRefraction );

                // Push the animation id in a map, if it exist.
                const COLLADAFW::UniqueId& animationListId = indexOfRefractionFOP.getAnimationList ();
                if ( animationListId.isValid () )
                {
                    EffectAnimation effectAnimation;
                    effectAnimation.setAnimationListId ( animationListId );
                    effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
                    effectAnimation.setAnimatedValueType ( EffectAnimation::FLOAT_OR_PARAM_REFRACTIVE_INDEX );

                    mEffectAnimationMap [animationListId] = effectAnimation;
                }
            }
        }

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
                effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
                effectAnimation.setAnimatedValueType ( EffectAnimation::COLOR_OR_TEXTURE_TRANSPARENCY );

                mEffectAnimationMap [animationListId] = effectAnimation;
            }
        }
        else if ( opaque.isTexture () )
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = opaque.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_TRANSPARENT;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureInfo ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
        else
        {
            // The maya default color is grey. The framework/collada uses black.
            shaderNode->setTransparency ( MayaDM::float3 ( 0.0f,0.0f,0.0f ) );
        }
    }

    // --------------------------
    void EffectImporter::importBlinnShaderAttributes ( 
        MayaDM::Blinn* shaderNode, 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Shininess
        const COLLADAFW::FloatOrParam& shininessFoP = commonEffect->getShininess ();
        if ( shininessFoP.getType () == COLLADAFW::FloatOrParam::FLOAT )
        {
            float shininess = shininessFoP.getFloatValue (); 
            if ( shininess > 0 ) 
            {
                // Set the shininess to the blinn's eccentricity.
                shaderNode->setEccentricity ( shininess );

                // Push the animation id in a map, if it exist.
                const COLLADAFW::UniqueId& animationListId = shininessFoP.getAnimationList ();
                if ( animationListId.isValid () )
                {
                    EffectAnimation effectAnimation;
                    effectAnimation.setAnimationListId ( animationListId );
                    effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
                    effectAnimation.setAnimatedValueType ( EffectAnimation::FLOAT_OR_PARAM_ECCENTRICITY );

                    mEffectAnimationMap [animationListId] = effectAnimation;
                }
            }
        }
    }

    // --------------------------
    void EffectImporter::importPhongShaderAttributes ( 
        MayaDM::Phong* shaderNode, 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Shininess
        const COLLADAFW::FloatOrParam& shininessFoP = commonEffect->getShininess ();
        if ( shininessFoP.getType () == COLLADAFW::FloatOrParam::FLOAT )
        {
            float shininess = shininessFoP.getFloatValue (); 
            if ( shininess > 0 ) 
            {
                // Set the shininess to the phong's cosine power.
                shaderNode->setCosinePower ( shininess );

                // Push the animation id in a map, if it exist.
                const COLLADAFW::UniqueId& animationListId = shininessFoP.getAnimationList ();
                if ( animationListId.isValid () )
                {
                    EffectAnimation effectAnimation;
                    effectAnimation.setAnimationListId ( animationListId );
                    effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
                    effectAnimation.setAnimatedValueType ( EffectAnimation::FLOAT_OR_PARAM_COSINE_POWER );

                    mEffectAnimationMap [animationListId] = effectAnimation;
                }
            }
        }
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
                effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
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
            appendTextureInfo ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
        else
        {
            // The maya default color is grey. The framework/collada uses black.
            shaderNode->setReflectedColor ( MayaDM::float3 ( 0.0f,0.0f,0.0f ) );
        }

        // Reflectivity
        const COLLADAFW::FloatOrParam& reflectivityFoP = commonEffect->getReflectivity ();
        if ( reflectivityFoP.getType () == COLLADAFW::FloatOrParam::FLOAT )
        {
            float reflectivity = reflectivityFoP.getFloatValue (); 
            if ( reflectivity > 0 ) 
            {
                shaderNode->setReflectivity ( reflectivity );

                // Push the animation id in a map, if it exist.
                const COLLADAFW::UniqueId& animationListId = reflectivityFoP.getAnimationList ();
                if ( animationListId.isValid () )
                {
                    EffectAnimation effectAnimation;
                    effectAnimation.setAnimationListId ( animationListId );
                    effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
                    effectAnimation.setAnimatedValueType ( EffectAnimation::FLOAT_OR_PARAM_REFLECTIVITY );

                    mEffectAnimationMap [animationListId] = effectAnimation;
                }
            }
            else 
            {
                shaderNode->setReflectivity ( 0.0f );
            }
        }
        else if ( reflectivityFoP.getType () == COLLADAFW::FloatOrParam::PARAM )
        {
            // TODO
        }
        else
        {
            std::cerr << "Unknown param type!" << std::endl;
        }

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
                effectAnimation.setAnimationSourceId ( effect->getUniqueId () );
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
            appendTextureInfo ( effect, texture, shaderType, shaderAttribute, shaderNode );
        }
        else
        {
            // The maya default color is grey. The framework/collada uses black.
            shaderNode->setSpecularColor ( MayaDM::float3 ( 0.0f,0.0f,0.0f ) );
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
        if ( !colladaEffectId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_EFFECT_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_EFFECT_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaEffectId );
        }

        // Add the original id attribute of the material.
        MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
        String colladaMaterialId = materialImporter->findOriginalColladaId ( materialId );
        if ( !colladaMaterialId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_MATERIAL_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_MATERIAL_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaMaterialId );
        }

        // Add the original id attribute of the effect common.
        String colladaEffectCommonId = commonEffect->getOriginalId ();
        if ( !colladaEffectCommonId.empty () )
        {
            MayaDM::addAttr ( file, COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME, ATTRIBUTE_DATA_TYPE, ATTRIBUTE_TYPE_STRING );
            MayaDM::setAttr ( file, COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME, ATTRIBUTE_TYPE, ATTRIBUTE_TYPE_STRING, colladaEffectCommonId );
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
    void EffectImporter::appendTextureInfo ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::Texture &texture, 
        const ShaderType& shaderType, 
        const ShaderAttribute& shaderAttribute, 
        MayaDM::Lambert* shaderNode )
    {
        // Get the effect id.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();

        // Get the current sampler id.
        const COLLADAFW::SamplerID& samplerId = texture.getSamplerId ();

        // Get the id of the texture map, that should be used by this texture. It must be bounded 
        // to a set of texture coordinates, when the material is bounded to the geometry.
        const COLLADAFW::TextureMapId& textureMapId = texture.getTextureMapId ();

        // Save the samplerId to this effect, so we can do the connection one time later.
        TextureInfo textureInfo;
        textureInfo.setEffectId ( effectId );
        textureInfo.setSamplerId ( samplerId );
        textureInfo.setShaderType ( shaderType );
        textureInfo.setShaderAttribute ( shaderAttribute );
        textureInfo.setShaderNode ( *shaderNode );
        textureInfo.setTextureMapId ( textureMapId );

        // Push the shader node attribute data in the map to the effect.
        mEffectTextureInfosMap [ effectId ].push_back ( textureInfo );

    }

    // --------------------------
    void EffectImporter::createTexturePlacements ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // The effect id
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();

        // Get the texture info attributes of the current effect.
        std::vector<TextureInfo>* textureInfos = findTextureInfos ( effectId );
        if ( !textureInfos ) return;

        // Get the list of samplers of the current effect.
        const COLLADAFW::SamplerPointerArray& samplers = commonEffect->getSamplerPointerArray ();
        size_t numSamplers = samplers.getCount ();
        for ( size_t samplerId=0; samplerId<numSamplers; ++samplerId )
        {
            COLLADAFW::Sampler* sampler = samplers [samplerId];
            
            const COLLADAFW::UniqueId& imageId = sampler->getSourceImage ();
            COLLADAFW::Sampler::SamplerType samplerType = sampler->getSamplerType ();

            // Get the texture info which use this sampler.
            size_t numTextureInfos = textureInfos->size ();
            for ( size_t i=0; i<numTextureInfos; ++i )
            {
                // Check if the shader node uses the same sampler.
                TextureInfo& textureInfo = (*textureInfos) [i];
                if ( textureInfo.getSamplerId () == samplerId )
                {
                    switch ( samplerType )
                    {
                    case COLLADAFW::Sampler::SAMPLER_TYPE_2D:
                        {
                            // Create this in depend on the texture mapping of effects.
                            // createNode place2dTexture -n "place2dTexture1";
                            String place2dTextureName = generateUniqueDependNodeName ( PLACE_2D_TEXTURE_NAME, true, true );
                            MayaDM::Place2dTexture place2dTexture ( file, place2dTextureName );

                            // TODO What to do with this attributes???
                            sampler->getBorderColor ();
                            sampler->getMagFilter ();
                            sampler->getMinFilter ();
                            sampler->getMipFilter ();
                            sampler->getMipmapBias ();
                            sampler->getMipmapMaxlevel ();
                            //place2dTexture.setWrapU ( sampler->getWrapP () );
                            //place2dTexture.setWrapV ( sampler->getWrapS () );
                            sampler->getWrapT ();

                            // Set the image, the sampler type and the maya texture placement 
                            // into the shader node.
                            textureInfo.setImageId ( imageId );
                            textureInfo.setSamplerType ( samplerType );
                            textureInfo.setTexturePlacementNode ( place2dTexture );

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
                        std::cerr << "Sampler type not implemented: " << samplerType << std::endl;
                        break;
                    }
                }
            }
        }
    }

    // --------------------------
    std::vector< EffectImporter::TextureInfo >* EffectImporter::findTextureInfos ( 
        const COLLADAFW::UniqueId& effectId )
    {
        UniqueIdTextureInfosMap::iterator it = mEffectTextureInfosMap.find ( effectId );
        if ( it != mEffectTextureInfosMap.end () )
            return &it->second;
        return 0;
    }

    // --------------------------
    const EffectImporter::TextureInfo* EffectImporter::findTextureInfo ( 
        const COLLADAFW::UniqueId& effectId, 
        const COLLADAFW::TextureMapId& textureMapId )
    {
        const std::vector< EffectImporter::TextureInfo >* textureInfos = findTextureInfos ( effectId );
        if ( textureInfos == 0 ) return 0;

        std::vector< EffectImporter::TextureInfo >::const_iterator it = textureInfos->begin ();
        while ( it != textureInfos->end () )
        {
            const EffectImporter::TextureInfo& textureInfo = *it;
            if ( textureInfo.getTextureMapId () == textureMapId ) 
                return &textureInfo;

            ++it;
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

    //------------------------------
    const bool EffectImporter::isDefaultTextureConnected ( const String& imageName ) const
    {
        std::vector<String>::const_iterator it = mDefaultTextureImageList.begin ();
        while ( it != mDefaultTextureImageList.end () )
        {
            if ( COLLADABU::Utils::equals ( imageName , *it ) )
                return true;
            ++it;
        }
        return false;
    }

    // --------------------------
    const bool EffectImporter::isMaterialConnected ( 
        const COLLADAFW::UniqueId& materialId, 
        const String& imageName )
    {
        std::map<COLLADAFW::UniqueId, std::vector<String> >::const_iterator it = mMaterialImagesMap.find ( materialId );
        if ( it != mMaterialImagesMap.end () )
        {
            const std::vector<String>& imageNames = it->second;
            std::vector<String>::const_iterator it2 = imageNames.begin ();
            while ( it2!= imageNames.end () )
            {
                if ( COLLADABU::Utils::equals ( *it2, imageName ) )
                    return true;
                ++it2;
            }
        }
        return false;
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
        UniqueIdTextureInfosMap::const_iterator it = mEffectTextureInfosMap.begin ();
        while ( it != mEffectTextureInfosMap.end () )
        {
            const std::vector<TextureInfo>& textureInfos = it->second;
            for ( size_t i=0; i<textureInfos.size (); ++i )
            {
                const TextureInfo& textureInfo = textureInfos [i];

                const COLLADAFW::UniqueId& imageId = textureInfo.getImageId ();
                const MayaDM::File& imageFile = textureInfo.getImageNode ();
                if ( imageFile.getName ().empty () )
                {
                    std::cerr << "No image file for the shader node " << textureInfo.getShaderNode ().getName () << "!" << std::endl;
                    continue;
                }

                const size_t samplerId = textureInfo.getSamplerId ();
                const COLLADAFW::Sampler::SamplerType& samplerType = textureInfo.getSamplerType ();
                switch ( samplerType )
                {
                case COLLADAFW::Sampler::SAMPLER_TYPE_2D:
                    {
                        const MayaDM::Place2dTexture& place2dTexture = textureInfo.getTexturePlacementNode ();
                        connectAttr ( file, place2dTexture.getOutUV (), imageFile.getUvCoord () );
                        connectAttr ( file, place2dTexture.getOutUvFilterSize (), imageFile.getUvFilterSize () );
                        connectAttr ( file, place2dTexture.getVertexUvOne (), imageFile.getVertexUvOne () );
                        connectAttr ( file, place2dTexture.getVertexUvTwo (), imageFile.getVertexUvTwo () );
                        connectAttr ( file, place2dTexture.getVertexUvThree (), imageFile.getVertexUvThree () );
                        connectAttr ( file, place2dTexture.getVertexCameraOne (), imageFile.getVertexCameraOne () );
                        connectAttr ( file, place2dTexture.getOffset (), imageFile.getOffset () );
                        connectAttr ( file, place2dTexture.getStagger (), imageFile.getStagger () );
                        connectAttr ( file, place2dTexture.getCoverage (), imageFile.getCoverage () );
                        connectAttr ( file, place2dTexture.getTranslateFrame (), imageFile.getTranslateFrame () );
                        connectAttr ( file, place2dTexture.getMirrorU (), imageFile.getMirrorU () );
                        connectAttr ( file, place2dTexture.getMirrorV (), imageFile.getMirrorV () );
                        connectAttr ( file, place2dTexture.getWrapU (), imageFile.getWrapU () );
                        connectAttr ( file, place2dTexture.getWrapV (), imageFile.getWrapV () );
                        connectAttr ( file, place2dTexture.getNoiseUV (), imageFile.getNoiseUV () );
                        connectAttr ( file, place2dTexture.getRotateUV (), imageFile.getRotateUV () );
                        connectAttr ( file, place2dTexture.getRepeatUV (), imageFile.getRepeatUV () );
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
                    std::cerr << "Sampler type not implemented: " << samplerType << std::endl;
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
        MayaDM::DefaultTextureList defaultTextureList ( file, ":" + DEFAULT_TEXTURE_LIST, EMPTY_STRING, false, false );

        EffectImporter* effectImporter = getDocumentImporter ()->getEffectImporter ();
        const UniqueIdTextureInfosMap& textureInfos = effectImporter->getTextureInfosMap ();
        UniqueIdTextureInfosMap::const_iterator it = textureInfos.begin ();
        while ( it != textureInfos.end () )
        {
            const COLLADAFW::UniqueId& effectId = it->first;

            const std::vector<TextureInfo>& textureInfos = it->second;
            for ( size_t i=0; i<textureInfos.size (); ++i )
            {
                // Get the current shader node attribute.
                const TextureInfo& textureInfo = textureInfos [i];

                // Get the current sampler id.
                const COLLADAFW::SamplerID& samplerId = textureInfo.getSamplerId ();

                // Get the maya file object.
                const COLLADAFW::UniqueId& imageId = textureInfo.getImageId ();
                const MayaDM::File& imageFile = textureInfo.getImageNode ();
                if ( imageFile.getName ().empty () )
                {
                    std::cerr << "No image file for the shader node " << textureInfo.getShaderNode ().getName () << "!" << std::endl;
                    continue;
                }

                // Check if this connection already exist.
                String imageName = imageFile.getName ();
                // There can't be anymore some dublicate connections..
                //if ( !isDefaultTextureConnected ( imageName ) )
                {
                    // connectAttr "file1.message" ":defaultTextureList1.textures" -nextAvailable;
                    connectNextAttr ( file, imageFile.getMessage (), defaultTextureList.getTextures () );
                    //mDefaultTextureImageList.push_back ( imageName );
                }

                // Connect the image file out color with the material's texture attribute.
                // connectAttr "file1.outColor" "lambert2.color";
                connectTextureAttribute ( textureInfo, &imageFile );

                // Get the current effect's material materialInfo object.
                const UniqueIdVec* materialIds = effectImporter->findMaterialId ( effectId );
                if ( materialIds == 0 )
                {
                    std::cerr << "No material for the current effect! " << std::endl;
                    continue;
                }
                size_t numMaterials = materialIds->size ();
                for ( size_t i=0; i<numMaterials; ++i )
                {
                    const COLLADAFW::UniqueId& materialId = (*materialIds) [i];

                    // There can't be anymore some dublicate connections..
                    // Check if the connection between the image and the material already exist.
                    //if ( isMaterialConnected ( materialId, imageName ) ) continue;
                    //mMaterialImagesMap [materialId].push_back ( imageName );

                    // Get the maya materialInfo object.
                    MaterialImporter* materialImporter = getDocumentImporter ()->getMaterialImporter ();
                    MaterialImporter::ShadingData* shadingData = materialImporter->findShaderData ( materialId );
                    if ( shadingData == 0 ) 
                    {
                        std::cerr << "No material info for current material!" << std::endl;
                        continue;
                    }
                    const MayaDM::MaterialInfo& materialInfo = shadingData->getMaterialInfo ();

                    // Connect the image file message with the materials materialInfo texture attribute.
                    // connectAttr "file1.message" "materialInfo1.texture" -nextAvailable;
                    connectNextAttr ( file, imageFile.getMessage (), materialInfo.getTexture () );
                }
            }
            
            ++it;
        }
    }

    //------------------------------
    void EffectImporter::connectTextureAttribute ( 
        const TextureInfo& textureInfo, 
        const MayaDM::File* imageFile )
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        const MayaDM::Lambert& shaderNode = textureInfo.getShaderNode ();
        const EffectImporter::ShaderAttribute& shaderAttribute = textureInfo.getShaderAttribute ();

        switch ( shaderAttribute )
        {
        case EffectImporter::ATTR_COLOR:
            {
                connectAttr ( file, imageFile->getOutColor (), shaderNode.getColor () );
                break;
            }
        case EffectImporter::ATTR_AMBIENT:
            {
                connectAttr ( file, imageFile->getOutColor (), shaderNode.getAmbientColor () );
                break;
            }
        case EffectImporter::ATTR_INCANDESCENE:
            {
                connectAttr ( file, imageFile->getOutColor(), shaderNode.getIncandescence () );
                break;
            }
        case EffectImporter::ATTR_REFLECTIVE:
            {
                switch ( textureInfo.getShaderType () )
                {
                case EffectImporter::SHADER_BLINN:
                    {
                        MayaDM::Blinn* blinnNode = ( MayaDM::Blinn* ) (&shaderNode);
                        connectAttr ( file, imageFile->getOutColor (), blinnNode->getReflectedColor () );
                        break;
                    }
                case EffectImporter::SHADER_PHONG:
                    {
                        MayaDM::Phong* phongNode = ( MayaDM::Phong* ) (&shaderNode);
                        connectAttr ( file, imageFile->getOutColor (), phongNode->getReflectedColor () );
                        break;
                    }
                default:
                    std::cerr << "No valid shader type for shader node attribute ATTR_REFLECTIVE." << std::endl;
                    break;
                }
                break;
            }
        case EffectImporter::ATTR_SPECULAR:
            {
                switch ( textureInfo.getShaderType () )
                {
                case EffectImporter::SHADER_BLINN:
                    {
                        MayaDM::Blinn* blinnNode = ( MayaDM::Blinn* ) (&shaderNode);
                        connectAttr ( file, imageFile->getOutColor (), blinnNode->getSpecularColor () );
                        break;
                    }
                case EffectImporter::SHADER_PHONG:
                    {
                        MayaDM::Phong* phongNode = ( MayaDM::Phong* ) (&shaderNode);
                        connectAttr ( file, imageFile->getOutColor (), phongNode->getSpecularColor () );
                        break;
                    }
                default:
                    std::cerr << "No valid shader type for shader node attribute ATTR_SPECULAR." << std::endl;
                    break;
                }
                break;
            }
        case EffectImporter::ATTR_TRANSPARENT:
            {
                connectAttr ( file, imageFile->getOutTransparency (), shaderNode.getTransparency () );
                break;
            }
        case EffectImporter::ATTR_UNKNOWN:
        default:
            {
                std::cerr << "No valid shader node attribute!" << std::endl;
                break;
            }
        }
    }


} // namespace DAE2MA
