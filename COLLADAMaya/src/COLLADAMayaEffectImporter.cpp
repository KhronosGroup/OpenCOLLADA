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

#include "COLLADAFWEffect.h"

#include <MayaDMPlace2dTexture.h>
#include <MayaDMPlace3dTexture.h>


namespace COLLADAMaya
{

    const String EffectImporter::EFFECT_NAME = "Effect";
    const String EffectImporter::PLACE_2D_TEXTURE_NAME = "place2dTexture";
    const String EffectImporter::PLACE_3D_TEXTURE_NAME = "place3dTexture";


    //------------------------------
	EffectImporter::EffectImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{}
	
    //------------------------------
	EffectImporter::~EffectImporter()
	{
        UniqueIdLambertMap::iterator it = mMayaEffectMap.begin ();
        while ( it != mMayaEffectMap.end () )
        {
            MayaDM::Lambert* lambert = it->second;
            delete lambert;
            ++it;
        }

        for ( size_t i=0; i<mTexturePlacements.size (); ++i )
        {
            TexturePlacement* texturePlacementAssignment = mTexturePlacements [i];
            MayaDM::DependNode* dependNode = texturePlacementAssignment->mTexturePlacementNode;
            delete dependNode;
            delete texturePlacementAssignment;
        }
        mTexturePlacements.clear ();
    }

    //------------------------------
    bool EffectImporter::importEffect ( const COLLADAFW::Effect* effect )
    {
        // Check if the current effect is already imported.
        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        if ( findMayaEffect ( effectId ) != 0 ) return false;

        // Create the maya effect in depend on the shader type.
        const COLLADAFW::CommonEffectPointerArray& commonEffects = effect->getCommonEffects ();
        size_t numCommonEffects = commonEffects.getCount ();
        for ( size_t i=0; i<numCommonEffects; ++i )
        {
            COLLADAFW::EffectCommon* commonEffect = commonEffects [i];

            // Import shader data by type.
            importShaderData ( commonEffect, effect );

            // Create the texture placement and push it to the image in a map.
            importTexturePlacement ( commonEffect );
        }

        return true;
    }

    // --------------------------
    void EffectImporter::importShaderData ( 
        const COLLADAFW::EffectCommon* commonEffect, 
        const COLLADAFW::Effect* effect )
    {
        const COLLADAFW::EffectCommon::ShaderType& shaderType = commonEffect->getShaderType ();
        switch ( shaderType )
        {
        case COLLADAFW::EffectCommon::SHADER_BLINN:
            importBlinnShader ( effect, commonEffect );
            break;
        case COLLADAFW::EffectCommon::SHADER_CONSTANT:
            // Import as a lambert shader.
            importLambertShader ( effect, commonEffect );
            break;
        case COLLADAFW::EffectCommon::SHADER_PHONG:
            importPhongShader ( effect, commonEffect );
            break;
        case COLLADAFW::EffectCommon::SHADER_LAMBERT:
            importLambertShader ( effect, commonEffect );
            break;
        case COLLADAFW::EffectCommon::SHADER_UNKNOWN:
        default:
            // Import as a lambert shader.
            importLambertShader ( effect, commonEffect );
            break;
        }
    }

    //------------------------------
    void EffectImporter::importBlinnShader ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Get the material name.
        String effectName ( effect->getName () );
        if ( COLLADABU::Utils::equals ( effectName, COLLADABU::Utils::EMPTY_STRING ) )
            effectName = EFFECT_NAME;
        effectName = DocumentImporter::frameworkNameToMayaName ( effectName );
        effectName = mEffectIdList.addId ( effectName );

        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        mMayaEffectNamesMap [effectId] = effectName;

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Blinn* blinn = new MayaDM::Blinn ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( blinn, effect );
        importLambertShaderAttributes ( SHADER_BLINN, blinn, commonEffect );
        importReflectShaderAttributes ( SHADER_BLINN, blinn, commonEffect );
        importBlinnShaderAttributes ( blinn, commonEffect );

        // Push it into the map.
        appendEffect ( effectId, blinn );
    }

    //------------------------------
    void EffectImporter::importPhongShader ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Get the material name.
        String effectName ( effect->getName () );
        if ( COLLADABU::Utils::equals ( effectName, COLLADABU::Utils::EMPTY_STRING ) )
            effectName = EFFECT_NAME;
        effectName = DocumentImporter::frameworkNameToMayaName ( effectName );
        effectName = mEffectIdList.addId ( effectName );

        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        mMayaEffectNamesMap [effectId] = effectName;

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Phong* phong = new MayaDM::Phong ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( phong, effect );
        importLambertShaderAttributes ( SHADER_PHONG, phong, commonEffect );
        importReflectShaderAttributes ( SHADER_PHONG, phong, commonEffect );
        importPhongShaderAttributes ( phong, commonEffect );

        // Push it into the map.
        appendEffect ( effectId, phong );
    }

    //------------------------------
    void EffectImporter::importLambertShader ( 
        const COLLADAFW::Effect* effect, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Get the material name.
        String effectName ( effect->getName () );
        if ( COLLADABU::Utils::equals ( effectName, COLLADABU::Utils::EMPTY_STRING ) )
            effectName = EFFECT_NAME;
        effectName = DocumentImporter::frameworkNameToMayaName ( effectName );
        effectName = mEffectIdList.addId ( effectName );

        const COLLADAFW::UniqueId& effectId = effect->getUniqueId ();
        mMayaEffectNamesMap [effectId] = effectName;

        // Write the effect into the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();
        MayaDM::Lambert* lambert = new MayaDM::Lambert ( file, effectName );

        // Import the shader attributes.
        importStandardShaderAttributes ( lambert, effect );
        importLambertShaderAttributes ( SHADER_LAMBERT, lambert, commonEffect );

        // Push it into the map.
        appendEffect ( effectId, lambert );
    }

    // --------------------------
    void EffectImporter::importStandardShaderAttributes ( 
        MayaDM::Lambert* shaderNode, 
        const COLLADAFW::Effect* effect )
    {
        // Get the color and set it into the shader node (if it is a valid color).
        const COLLADAFW::Color& standardColor = effect->getStandardColor ();
        if ( standardColor.isValid () )
        {
            shaderNode->setColor ( MayaDM::float3 ( (float)standardColor.getRed (), (float)standardColor.getGreen (), (float)standardColor.getBlue ()) );
        }
    }

    // --------------------------
    void EffectImporter::importLambertShaderAttributes ( 
        const ShaderType& shaderType, 
        MayaDM::Lambert* shaderNode, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Diffuse color
        const COLLADAFW::ColorOrTexture& diffuse = commonEffect->getDiffuse ();
        if ( diffuse.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = diffuse.getColor ();
            if ( color.isValid () )
                shaderNode->setColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );
        }
        else 
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = diffuse.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_COLOR;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( texture, shaderType, shaderAttribute, shaderNode );
        }

        // Emission
        const COLLADAFW::ColorOrTexture& emission = commonEffect->getEmission ();
        if ( emission.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = emission.getColor ();
            if ( color.isValid () )
                shaderNode->setIncandescence ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );
        }
        else
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = diffuse.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_INCANDESCENE;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( texture, shaderType, shaderAttribute, shaderNode );
        }

        // Index of refraction 
        const COLLADAFW::FloatOrParam& indexOfRefraction = commonEffect->getIndexOfRefraction ();
        if ( indexOfRefraction > 0 ) shaderNode->setRefractiveIndex ( indexOfRefraction );

        // TODO What about the opaque mode???
        // Transparency
        const COLLADAFW::FloatOrParam& transparency = commonEffect->getTransparency ();

        // Transparent color
        const COLLADAFW::ColorOrTexture& transparent = commonEffect->getTransparent();
        if ( transparent.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = transparent.getColor ();
            if ( color.isValid () )
                shaderNode->setTransparency ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );
        }
        else
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = diffuse.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_TRANSPARENT;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( texture, shaderType, shaderAttribute, shaderNode );
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
    }

    // --------------------------
    void EffectImporter::importPhongShaderAttributes ( 
        MayaDM::Phong* shaderNode, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Shininess
        const COLLADAFW::FloatOrParam& shininess = commonEffect->getShininess ();
        if ( shininess > 0 ) shaderNode->setCosinePower ( shininess );
    }

    // --------------------------
    void EffectImporter::importReflectShaderAttributes ( 
        const ShaderType& shaderType, 
        MayaDM::Reflect* shaderNode, 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Reflective
        const COLLADAFW::ColorOrTexture& reflective = commonEffect->getReflective ();
        if ( reflective.isColor () )
        {
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& color = reflective.getColor ();
            if ( color.isValid () )
                shaderNode->setReflectedColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );
        }
        else
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = reflective.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_REFLECTIVE;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( texture, shaderType, shaderAttribute, shaderNode );
        }

        // Reflectivity
        const COLLADAFW::FloatOrParam& reflectivity = commonEffect->getReflectivity ();
        if ( reflectivity > 0 ) shaderNode->setReflectivity ( reflectivity );

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
            if ( color.isValid () )
                shaderNode->setSpecularColor ( MayaDM::float3 ( (float)color.getRed (), (float)color.getGreen (), (float)color.getBlue ()) );
        }
        else
        {
            // Get the texure and the current shader attribute.
            const COLLADAFW::Texture& texture = specular.getTexture ();
            ShaderAttribute shaderAttribute = ATTR_SPECULAR;

            // Create a shader node attribute and append it on the list of shader node 
            // attributes to the current sampler file id.
            appendTextureAttribute ( texture, shaderType, shaderAttribute, shaderNode );
        }
    }

    // --------------------------
    MayaDM::Lambert* EffectImporter::findMayaEffect ( const COLLADAFW::UniqueId& effectId ) const
    {
        UniqueIdLambertMap::const_iterator it = mMayaEffectMap.find ( effectId );
        if ( it != mMayaEffectMap.end () )
        {
            return it->second;
        }
        return 0;
    }

    // --------------------------
    void EffectImporter::appendEffect ( 
        const COLLADAFW::UniqueId& effectId, 
        MayaDM::Lambert* effectNode )
    {
        mMayaEffectMap [effectId] = effectNode;
    }

    // --------------------------
    void EffectImporter::appendTextureAttribute ( 
        const COLLADAFW::Texture &texture, 
        const ShaderType& shaderType, 
        const ShaderAttribute& shaderAttribute, 
        MayaDM::Lambert* shaderNode )
    {
        // Get the current sampler id.
        COLLADAFW::SamplerID samplerId = texture.getSamplerId ();

        // Save the samplerId to this effect, so we can do the connection one time later.
        TextureAttribute shaderNodeAttribute;
        shaderNodeAttribute.mShaderType = shaderType;
        shaderNodeAttribute.mShaderAttribute = shaderAttribute;
        shaderNodeAttribute.mShaderNode = shaderNode;

        // Push the shader node attribute data in the map to the sampler id.
        mSamplerIdShaderNodesMap [ samplerId ].push_back ( shaderNodeAttribute );
    }

    // --------------------------
    void EffectImporter::importTexturePlacement ( 
        const COLLADAFW::EffectCommon* commonEffect )
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        const COLLADAFW::SamplerPointerArray& samplers = commonEffect->getSamplerPointerArray ();
        size_t numSamplers = samplers.getCount ();
        for ( size_t i=0; i<numSamplers; ++i )
        {
            COLLADAFW::Sampler* sampler = samplers [i];

            size_t samplerId = i;
            const COLLADAFW::UniqueId& imageId = sampler->getSourceImage ();
            COLLADAFW::Sampler::SamplerType samplerType = sampler->getSamplerType ();

            switch ( samplerType )
            {
            case COLLADAFW::Sampler::SAMPLER_TYPE_2D:
                {
                    // TODO Create this in depend on the texture mapping of effects.
                    // createNode place2dTexture -n "place2dTexture1";
                    String place2dTextureName = mPlace2dTextureIdList.addId ( PLACE_2D_TEXTURE_NAME );
                    MayaDM::Place2dTexture* place2dTexture = new MayaDM::Place2dTexture ( file, place2dTextureName );

                    // TODO What to do with this attributes???
                    sampler->getBorderColor ();
                    sampler->getMagFilter ();
                    sampler->getMinFilter ();
                    sampler->getMipFilter ();
                    sampler->getMipmapBias ();
                    sampler->getMipmapMaxlevel ();
                    place2dTexture->setWrapU ( sampler->getWrapP () );
                    place2dTexture->setWrapV ( sampler->getWrapS () );
                    sampler->getWrapT ();

                    // TODO Push the texure placement informations in a list.
                    TexturePlacement* texturePlacement = new TexturePlacement ();
                    texturePlacement->mImageId = imageId;
                    texturePlacement->mSamplerType = samplerType;
                    texturePlacement->mTexturePlacementNode = place2dTexture;
                    
                    mTexturePlacements.push_back ( texturePlacement );
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

    // --------------------------
    void EffectImporter::writeConnections ()
    {
        // Get the maya ascii file.
        FILE* file = getDocumentImporter ()->getFile ();

        // Writes the connections of the effect texture placements to the image files.  
        size_t numPlacements = mTexturePlacements.size ();
        for ( size_t i=0; i<numPlacements; ++i )
        {
            TexturePlacement* texturePlacement = mTexturePlacements [i];

            COLLADAFW::UniqueId& imageId = texturePlacement->mImageId;
            ImageImporter* imageImporter = getDocumentImporter ()->getImageImporter ();
            const MayaDM::File* imageFile = imageImporter->findMayaImageFile ( imageId );

            COLLADAFW::Sampler::SamplerType samplerType = texturePlacement->mSamplerType;
            switch ( samplerType )
            {
            case COLLADAFW::Sampler::SAMPLER_TYPE_2D:
                {
                    MayaDM::Place2dTexture* place2dTexture = ( MayaDM::Place2dTexture* ) texturePlacement->mTexturePlacementNode;
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
    }

} // namespace COLLADAMaya
