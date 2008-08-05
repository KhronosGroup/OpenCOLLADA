/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaSyntax.h"

#include <assert.h>

#include <maya/MItMeshPolygon.h>
#include <maya/MFnLambertShader.h>
#include <maya/MFnMesh.h>
#include <maya/MFnReflectShader.h>
#include <maya/MFnPhongShader.h>
#include <maya/MFnBlinnShader.h>
#ifndef _MPxHwShaderNode
#include <maya/MPxHwShaderNode.h>
#endif // _MPxHwShaderNode

#include "COLLADANode.h"
#include "COLLADAUtils.h"
#include "COLLADAEffectProfile.h"
#include "COLLADAExtraTechnique.h"

namespace COLLADAMaya
{

    const String EffectExporter::EFFECT_ID_SUFFIX = "-fx";
    const String EffectExporter::COLOR_EFFECT_ID_PREFIX = "ColorEffect";
    const String EffectExporter::TEXCOORD_BASE = "CHANNEL";


    //------------------------------------------------------
    EffectExporter::EffectExporter ( COLLADA::StreamWriter* _streamWriter, DocumentExporter* _documentExporter )
            : COLLADA::LibraryEffects ( _streamWriter ),
            mDocumentExporter ( _documentExporter ),
            mTextureExporter ( _documentExporter ),
            mMaterialMap ( NULL )
    {
    }


    //------------------------------------------------------
    const ImageMap* EffectExporter::exportEffects ( MaterialMap* materialMap/*=NULL*/ )
    {
        // Look for the material std::map to export
        if ( materialMap == NULL )
        {
            MaterialExporter* materialExporter = mDocumentExporter->getMaterialExporter();
            mMaterialMap = materialExporter->getExportedMaterialsMap();
        }
        else
        {
            mMaterialMap = materialMap;
        }

        // Iterate through the list of materials and export them
        MaterialMap::iterator materialsIter = mMaterialMap->begin();
        for ( ; materialsIter != mMaterialMap->end(); ++materialsIter )
        {
            MObject* shadingEngine = & ( ( *materialsIter ).second );
            exportEffect ( *shadingEngine );
        }

        closeLibrary();

        // Return the list with the images to export.
        return mTextureExporter.getExportedImageMap();
    }

    //------------------------------------------------------
    void EffectExporter::exportEffectsBySceneGraph()
    {
        SceneGraph* sceneGraph = mDocumentExporter->getSceneGraph();
        SceneElementsList* rootExportNodes = sceneGraph->getExportNodesTree();

        // Export all/selected DAG nodes
        uint length = rootExportNodes->size();

        for ( uint i = 0; i < length; ++i )
        {
            SceneElement* sceneElement = ( *rootExportNodes ) [i];

            exportMeshEffects ( sceneElement );
        }
    }

    //------------------------------------------------------
    void EffectExporter::exportMeshEffects ( SceneElement* sceneElement )
    {
        const MDagPath dagPath = sceneElement->getPath();

        // Check if it is a mesh and an export node

        if ( sceneElement->getType() == SceneElement::MESH &&
                sceneElement->getIsExportNode() )
        {
            MStatus status;
            MFnMesh fnMesh ( dagPath.node(), &status );

            if ( status != MStatus::kSuccess ) return;

            // Find how many shaders are used by this instance of the mesh
            MObjectArray shaders;

            MIntArray shaderIndices;
            unsigned instanceNumber = dagPath.instanceNumber();
            fnMesh.getConnectedShaders ( instanceNumber, shaders, shaderIndices );

            // Find the polygons that correspond to each materials and export them
            uint realShaderCount = ( uint ) shaders.length();
            uint numShaders = ( uint ) max ( ( size_t ) 1, ( size_t ) shaders.length() );

            for ( uint shaderPosition = 0; shaderPosition < numShaders; ++shaderPosition )
            {
                if ( shaderPosition < realShaderCount )
                {
                    // Add shader-specific parameters (TexCoords sets).
                    // Add symbolic name for the material used on this polygon set.
                    MObject shadingEngine = shaders[shaderPosition];
                    MObject shader = DagHelper::getSourceNodeConnectedTo ( shadingEngine, ATTR_SURFACE_SHADER );
                    exportEffect ( shader );
                }
            }
        }

        // recursive call for all the child elements

        for ( uint i=0; i<sceneElement->getChildCount(); ++i )
        {
            SceneElement* childElement = sceneElement->getChild ( i );
            exportMeshEffects ( childElement );
        }
    }

    //------------------------------------------------------
    // Add a shading network to this library and return the export Id
    //
    void EffectExporter::exportEffect ( MObject &shader )
    {
        // Find the actual shader node, since this function received shading sets as input
        MStatus status;
        MFnDependencyNode shaderNode ( shader, &status );

        if ( status != MStatus::kSuccess ) return;

        // Get the name of the current material
        String materialName = mDocumentExporter->mayaNameToColladaName ( shaderNode.name(), true );

        // Have we seen this shader before?
        MaterialMap::iterator materialMapIter;
        materialMapIter = ( *mMaterialMap ).find ( materialName );
        if ( materialMapIter == ( *mMaterialMap ).end() )
        {
            // This is a new shading engine
            ( *mMaterialMap ) [materialName] = shader;
        }

        // Check if this effect is already exported
        EffectMap::iterator effectMapIter;
        effectMapIter = mExportedEffectMap.find ( materialName );
        if ( effectMapIter != mExportedEffectMap.end() ) return;

        // Push the shader into the mExportedEffectMap
        mExportedEffectMap[materialName] = &shader;

        // Open a tag for the current effect in the collada document
        String effectId = materialName + EffectExporter::EFFECT_ID_SUFFIX;

        openEffect ( effectId );
        
        // Add the correct effect for the material
        COLLADA::EffectProfile effectProfile ( mSW );

        if ( shader.hasFn ( MFn::kLambert ) )
        {
            exportStandardShader ( &effectProfile, shader );
        }
        else if ( shader.hasFn ( MFn::kPluginHwShaderNode ) && shaderNode.typeName() == COLLADA_FX_SHADER )
        {
            // TODO
            //  exportColladaFXShader(&effectProfile, shader, colladaMaterial);
            MGlobal::displayError("Export of ColladaFXShader not implemented!"); 
        }
        else if ( shader.hasFn ( MFn::kPluginHwShaderNode ) && shaderNode.typeName() == COLLADA_FX_PASSES )
        {
            // TODO
            //  effect = ExportColladaFXPasses(&effectProfile, shader, colladaMaterial);
            MGlobal::displayError("Export of ColladaFXPasses not implemented!"); 
        }
        else
        {
            // For the constant shader, you should use the "surface shader" node in Maya
            // But always export some material parameters, even if we don't know this material.
            exportConstantShader ( &effectProfile, shader );
        }

        // Writes the current effect profile into the collada document
        addEffectProfile ( effectProfile );

        // Closes the current effect tag
        closeEffect();
    }

    //------------------------------------------------------
    void EffectExporter::exportConstantShader ( 
        COLLADA::EffectProfile* effectProfile,
        MObject shadingNetwork )
    {
        // Create the constant effect
        effectProfile->setShaderType ( COLLADA::EffectProfile::CONSTANT );

        // Set the constant color/texture
        MColor outColor;
        DagHelper::getPlugValue ( shadingNetwork, ATTR_OUT_COLOR, outColor );
        effectProfile->setEmission ( mayaColor2ColorOrTexture ( outColor ) );

        int nextTextureIndex = 0;
        exportTexturedParameter ( shadingNetwork, ATTR_OUT_COLOR, effectProfile, EffectExporter::EMISSION, nextTextureIndex );

        // TODO Test
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        animationExporter->addPlugAnimation ( shadingNetwork, ATTR_OUT_COLOR, RGBA_PARAMETERS, kColour );

        // Transparent color
        MColor transparentColor;
        DagHelper::getPlugValue ( shadingNetwork, ATTR_OUT_TRANSPARENCY, transparentColor );
        exportTransparency ( shadingNetwork, transparentColor, effectProfile, ATTR_OUT_TRANSPARENCY, nextTextureIndex );
    }

    //------------------------------------------------------
    void EffectExporter::exportStandardShader ( 
        COLLADA::EffectProfile* effectProfile,
        MObject shadingNetwork,
        bool initialized )
    {
        MFnDependencyNode shaderNode ( shadingNetwork );
        MFnLambertShader matFn ( shadingNetwork );

        int nextTextureIndex = 0;

        // Add the shader element: <constant> and the <extra><technique profile="MAYA"> elements
        if ( shadingNetwork.hasFn ( MFn::kPhong ) )
            effectProfile->setShaderType ( COLLADA::EffectProfile::PHONG );
        else if ( shadingNetwork.hasFn ( MFn::kBlinn ) )
            effectProfile->setShaderType ( COLLADA::EffectProfile::BLINN );
        else effectProfile->setShaderType ( COLLADA::EffectProfile::LAMBERT );

        // Get the animation exporter
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();

        // Emission color / Incandescence
        effectProfile->setEmission ( mayaColor2ColorOrTexture ( matFn.incandescence() ) );
        exportTexturedParameter ( shadingNetwork, ATTR_INCANDESCENCE, effectProfile, EffectExporter::EMISSION, nextTextureIndex );
        // TODO Test
        animationExporter->addPlugAnimation ( shadingNetwork, ATTR_INCANDESCENCE, RGBA_PARAMETERS, kColour );

        // Ambient color
        effectProfile->setAmbient ( mayaColor2ColorOrTexture ( matFn.ambientColor() ) );
        exportTexturedParameter ( shadingNetwork, ATTR_AMBIENT_COLOR, effectProfile, EffectExporter::AMBIENT, nextTextureIndex );
        // TODO Test
        animationExporter->addPlugAnimation ( shadingNetwork, ATTR_AMBIENT_COLOR, RGBA_PARAMETERS, kColour );

        // Diffuse color
        effectProfile->setDiffuse ( mayaColor2ColorOrTexture ( matFn.color(), matFn.diffuseCoeff() ) );
        exportTexturedParameter ( shadingNetwork, ATTR_COLOR, effectProfile, EffectExporter::DIFFUSE, nextTextureIndex );
        // TODO Test
        ConversionFunctor* conversion = new ConversionScaleFunctor ( matFn.diffuseCoeff() );
        animationExporter->addPlugAnimation ( shadingNetwork, ATTR_COLOR, RGBA_PARAMETERS, kColour, false, conversion );

        // Transparent color
        exportTransparency ( shadingNetwork, matFn.transparency(), effectProfile, ATTR_TRANSPARENCY, nextTextureIndex );

        float coeff = matFn.translucenceCoeff();
        effectProfile->setTransparency ( 1.0f );

        // Bump textures
        exportTexturedParameter ( shadingNetwork, ATTR_NORMAL_CAMERA, effectProfile, EffectExporter::BUMP, nextTextureIndex );

        if ( shadingNetwork.hasFn ( MFn::kReflect ) ) // includes Phong and Blinn
        {
            // Specular color
            MFnReflectShader reflectFn ( shadingNetwork );
            effectProfile->setSpecular ( mayaColor2ColorOrTexture ( reflectFn.specularColor() ) );
            exportTexturedParameter ( shadingNetwork, ATTR_SPECULAR_COLOR, effectProfile, EffectExporter::SPECULAR, nextTextureIndex );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_SPECULAR_COLOR, RGBA_PARAMETERS, kColour );

            // Reflected color
            effectProfile->setReflective ( mayaColor2ColorOrTexture ( reflectFn.reflectedColor() ) );
            exportTexturedParameter ( shadingNetwork, ATTR_REFLECTED_COLOR, effectProfile, EffectExporter::REFLECTION, nextTextureIndex );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_REFLECTED_COLOR, RGBA_PARAMETERS, kColour );

            // Reflectivity factor
            effectProfile->setReflectivity ( reflectFn.reflectivity() );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_REFLECTIVITY, EMPTY_PARAMETER, kSingle );
            //  ANIM->AddPlugAnimation(shadingNetwork, "reflectivity", effectProfile->GetReflectivityFactorParam()->GetValue(), kSingle);
        }

        // index of refraction
        bool refractive;
        DagHelper::getPlugValue ( shadingNetwork, ATTR_REFRACTIONS, refractive );
        if ( refractive )
        {
            effectProfile->setIndexOfRefrection ( matFn.refractiveIndex() );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_REFRACTIVE_INDEX, EMPTY_PARAMETER, kSingle );
        }

        // Phong and Blinn's specular factor
        if ( shadingNetwork.hasFn ( MFn::kPhong ) )
        {
            MFnPhongShader phongFn ( shadingNetwork );
            effectProfile->setShininess ( phongFn.cosPower() );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_COSINE_POWER, EMPTY_PARAMETER, kSingle );
        }

        else if ( shadingNetwork.hasFn ( MFn::kBlinn ) )
        {
#ifdef BLINN_EXPONENT_MODEL
            MFnBlinnShader blinnFn ( shadingNetwork );
            BlinnEccentricityToShininess* converter = new BlinnEccentricityToShininess();
            effectProfile->setShininess ( ( *converter ) ( blinnFn.eccentricity() ) );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_ECCENTRICITY, EMPTY_PARAMETER, kSingle, converter );
#else
            MFnBlinnShader blinnFn ( shadingNetwork );
            effectProfile->setShininess ( blinnFn.eccentricity() );
            // TODO Test
            animationExporter->addPlugAnimation ( shadingNetwork, ATTR_ECCENTRICITY, EMPTY_PARAMETER, kSingle );
#endif // BLINN_EXPONENT_MODEL  
        }
    }


    //---------------------------------------------------------------
    // Find any textures connected to a material attribute and create the
    // associated texture elements.
    MObject EffectExporter::exportTexturedParameter ( 
        const MObject& node,
        const char* attributeName,
        COLLADA::EffectProfile* effectProfile,
        EffectExporter::Channel channel,
        int& nextTextureIndex )
    {
        // Retrieve all the file textures
        MObjectArray fileTextures;
        MIntArray blendModes;
        getShaderTextures ( node, attributeName, fileTextures, blendModes );

        // What the hell??? Collada tells me, that there can be only
        // one texture for every related shader element!!!
        uint fileTextureCount = fileTextures.length();
        for ( uint i = 0; i < fileTextureCount; ++i )
        {
            // Verify that the texture is linked to a filename: COLLADA doesn't like empty file texture nodes.
            MFnDependencyNode nodeFn ( fileTextures[i] );
            MPlug filenamePlug = nodeFn.findPlug ( ATTR_FILE_TEXTURE_NAME );
            MString filename;
            filenamePlug.getValue ( filename );

            if ( filename.length() == 0 ) continue;

            // Create the texture linking object.
            MObject fileTexture = fileTextures[i];
            int blendMode = blendModes[i];
            String channelSemantic = TEXCOORD_BASE + COLLADA::Utils::toString ( channel );

            COLLADA::Texture colladaTexture;
            mTextureExporter.exportTexture ( &colladaTexture,
                                             channelSemantic,
                                             fileTextures[i],
                                             blendModes[i],
                                             nextTextureIndex++ );

            // Special case for bump maps: export the bump height in the "amount" texture parameter.
            // Exists currently within the ColladaMax profile.
            if ( channel == EffectExporter::BUMP )
            {
                MObject bumpNode = DagHelper::getNodeConnectedTo ( node, attributeName );
                if ( !bumpNode.isNull() && ( bumpNode.hasFn ( MFn::kBump ) || bumpNode.hasFn ( MFn::kBump3d ) ) )
                {
                    float amount = 1.0f;
                    MFnDependencyNode ( bumpNode ).findPlug ( ATTR_BUMP_DEPTH ).getValue ( amount );
                    colladaTexture.addExtraTechniqueParameter ( MAX_PROFILE, MAX_AMOUNT_TEXTURE_PARAMETER, amount );

                    // Get the animation exporter
                    AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
                    // TODO Test
                    animationExporter->addPlugAnimation ( bumpNode, ATTR_BUMP_DEPTH, EMPTY_PARAMETER, kSingle );

                    int interp = 0;
                    MFnDependencyNode ( bumpNode ).findPlug ( ATTR_BUMP_INTERP ).getValue ( interp );
                    colladaTexture.addExtraTechniqueParameter ( MAX_PROFILE, MAX_BUMP_INTERP_TEXTURE_PARAMETER, interp );
                }
            }

            // Change the color values to textures

            switch ( channel )
            {
                // TODO

            case AMBIENT:
                effectProfile->setAmbient ( COLLADA::ColorOrTexture ( colladaTexture ) );
                break;

            case BUMP: 
            {
                // Set the profile name and the child element name to the texture.
                // Then we can add it as the extra technique texture.
                colladaTexture.setProfileName(COLLADA_PROFILE);
                colladaTexture.setChildElementName(MAYA_BUMP_PARAMETER);
                effectProfile->setExtraTechniqueColorOrTexture(COLLADA::ColorOrTexture(colladaTexture));
                break;
            }

            case DIFFUSE:
            {
                COLLADA::ColorOrTexture colorOrTexture ( colladaTexture );
                effectProfile->setDiffuse ( colorOrTexture );
                break;
            }

            //  case DISPLACEMENT: displacementTextures.push_back(COLLADA::ColorOrTexture(colladaTexture)); break;

            case EMISSION:
                effectProfile->setEmission ( COLLADA::ColorOrTexture ( colladaTexture ) );
                break;
                //  case FILTER: filterTextures.push_back(COLLADA::ColorOrTexture(colladaTexture)); break;

            case REFLECTION:
                effectProfile->setReflective ( COLLADA::ColorOrTexture ( colladaTexture ) );
                break;
                //  case REFRACTION: refractionTextures.push_back(COLLADA::ColorOrTexture(colladaTexture)); break;
                //  case SHININESS: shininessTextures.push_back(COLLADA::ColorOrTexture(colladaTexture)); break;

            case SPECULAR:
                effectProfile->setSpecular ( COLLADA::ColorOrTexture ( colladaTexture ) );
                break;
                //  case SPECULAR_LEVEL: specularFactorTextures.push_back(COLLADA::ColorOrTexture(colladaTexture)); break;

            case TRANSPARENt:
                effectProfile->setTransparent ( COLLADA::ColorOrTexture ( colladaTexture ) );
                break;

            default:
                break;
            }

        }

        return ( fileTextures.length() > 0 ) ? fileTextures[0] : MObject::kNullObj;
    }

    //---------------------------------------------------------------
    // Retrieve any texture (file or layered) associated with a material attribute
    //
    void EffectExporter::getShaderTextures ( const MObject& shader,
            const char* attributeName,
            MObjectArray& textures,
            MIntArray& blendModes )
    {
        MObject texture = DagHelper::getSourceNodeConnectedTo ( shader, attributeName );

        while ( texture != MObject::kNullObj &&
                !texture.hasFn ( MFn::kLayeredTexture ) &&
                !texture.hasFn ( MFn::kFileTexture ) )
        {
            // Bypass the bump and projection nodes
            if ( texture.hasFn ( MFn::kBump ) || texture.hasFn ( MFn::kBump3d ) )
            {
                texture = DagHelper::getSourceNodeConnectedTo ( texture, ATTR_BUMP_VALUE );
            }
            else if ( texture.hasFn ( MFn::kProjection ) )
            {
                texture = DagHelper::getSourceNodeConnectedTo ( texture, ATTR_IMAGE );
            }

            else break;
        }

        // Verify that we have a supported texture type: file or layered.
        bool isFileTexture = texture.hasFn ( MFn::kFileTexture );
        bool isLayeredTexture = texture.hasFn ( MFn::kLayeredTexture );
        if ( !isFileTexture && !isLayeredTexture ) return;

        // Return the textures and blend modes
        if ( isFileTexture )
        {
            textures.append ( texture );
            blendModes.append ( 0 ); // 0 -> No blending
        }

        else if ( isLayeredTexture )
        {
            ShaderHelper::getLayeredTextures ( texture, textures, blendModes );
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::blendColor ( COLLADA::ColorOrTexture &colorOrTexture,
                                      COLLADA::Color blendColor,
                                      double ammount )
    {
        assert ( colorOrTexture.isColor() );

        COLLADA::Color& color = colorOrTexture.getColor();

        color.set ( color.getRed() + ( blendColor.getRed()-color.getRed() ) * ammount,
                    color.getGreen() + ( blendColor.getGreen()-color.getGreen() ) * ammount,
                    color.getBlue() + ( blendColor.getBlue()-color.getBlue() ) * ammount,
                    color.getAlpha() );
    }

    //---------------------------------------------------------------
    COLLADA::ColorOrTexture EffectExporter::mayaColor2ColorOrTexture ( const MColor &color, double scale )
    {
        return COLLADA::ColorOrTexture ( COLLADA::Color ( color.r * scale, color.g * scale, color.b * scale, scale ) );
    }

    //---------------------------------------------------------------
    void EffectExporter::exportTransparency ( MObject shadingNetwork,
            const MColor& transparentColor,
            COLLADA::EffectProfile* effectProfile,
            const char* attributeName,
            int& nextTextureIndex )
    {
        effectProfile->setTransparent ( mayaColor2ColorOrTexture ( transparentColor ) );

        MObject transparentTextureNode =
            exportTexturedParameter ( shadingNetwork, attributeName, effectProfile, EffectExporter::TRANSPARENt, nextTextureIndex );

        // Get the animation exporter
        AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
        // TODO Test
        animationExporter->addPlugAnimation ( shadingNetwork, attributeName, EMPTY_PARAMETER, kColour );

        // For the 'opaque' attribute, check the plug's name, that's connected to
        // the shader's 'transparency' plug.
        MPlug connectedPlug;

        if ( !transparentTextureNode.isNull() )
        {
            // DO NOTE: We're missing 2 transparency mode that were wrongly deemed useless in COLLADA 1.4.1.
            // Until then, we cannot use the 'invert' attribute or correctly export the transparency mode.
            MFnDependencyNode texture2DFn ( transparentTextureNode );
            bool isInverted = false;
            texture2DFn.findPlug ( ATTR_INVERT ).getValue ( isInverted );

            DagHelper::getPlugConnectedTo ( shadingNetwork, attributeName, connectedPlug );
            String partialName = connectedPlug.partialName().asChar();

            if ( connectedPlug.partialName() == ATTR_OPAQUE_OC )
                effectProfile->setOpacity ( COLLADA::EffectProfile::RGB_ZERO ); // should be RGB_ONE.
            else if ( connectedPlug.partialName() == ATTR_OPAQUE_OT )
                effectProfile->setOpacity ( COLLADA::EffectProfile::A_ONE );
            else if ( connectedPlug.partialName() == ATTR_OPAQUE_OA )
                effectProfile->setOpacity ( COLLADA::EffectProfile::A_ONE ); // valid?

            if ( effectProfile->getOpacity() == COLLADA::EffectProfile::A_ONE )
            {
                // Get the animation cache
                AnimationSampleCache* animationCache = mDocumentExporter->getAnimationCache();

                // Export any animation on the alpha gain/alpha offset

                if ( AnimationHelper::isAnimated ( animationCache, transparentTextureNode, ATTR_ALPHA_GAIN ) )
                {
                    // TODO Test
                    animationExporter->addPlugAnimation ( transparentTextureNode, ATTR_ALPHA_GAIN, EMPTY_PARAMETER, kSingle );
                }

                else
                {
                    // TODO Test
                    animationExporter->addPlugAnimation ( transparentTextureNode, ATTR_ALPHA_OFFSET, EMPTY_PARAMETER, kSingle, false, new ConversionOffsetFunctor ( 1.0f ) );
                }
            }
        }

        else
        {
            effectProfile->setOpacity ( COLLADA::EffectProfile::RGB_ZERO ); // correctly RGB_zero.
        }
    }

    //---------------------------------------------------------------
    // Export ColladaFX shader
    void EffectExporter::exportColladaFXShader ( COLLADA::EffectProfile* effectProfile,
            MObject shadingNetwork
            /*FCDMaterial* instance*/ )
    {
        // FCDEffect* effect = colladaDocument->GetEffectLibrary()->AddEntity();
        MFnDependencyNode nodeFn ( shadingNetwork );
        /*
        CFXShaderNode* fxShader = (CFXShaderNode*) nodeFn.userNode();

        // Retrieve the ColladaFX shader node and force its loading.
        CFXShaderNode* colladaFxNode = (CFXShaderNode*) nodeFn.userNode();
        if (colladaFxNode == NULL) return effect;
        if (!colladaFxNode->IsLoaded()) colladaFxNode->forceLoad();

        FCDEffectProfileFX* profile = (FCDEffectProfileFX*) effect->AddProfile(FUDaeProfileType::CG);

        // export effect parameters
        ExportNewParameters(profile, shadingNetwork, instance);

        // add effect technique node
        FCDEffectTechnique* technique = profile->AddTechnique();
        technique->SetName(fxShader->getTechniqueName());
        FCDEffectPass* pass = technique->AddPass();
        pass->SetPassName(fxShader->getPassName());
        ExportPass(profile, pass, shadingNetwork, instance);

        // Export a <technique_hint>.
        FCDMaterialTechniqueHint hint;
        hint.platform = FC("PC-OGL");
        hint.technique = TO_STRING(fxShader->getTechniqueName());
        instance->GetTechniqueHints().push_back(hint);
        */
    }


    /*
    void DaeMaterialLibrary::ExportPass(FCDEffectProfileFX* profile, FCDEffectPass* pass, MObject shaderObj, FCDMaterial* instance)
    {
     profile->SetPlatform(FC("PC-OGL"));

     // Retrieve the ColladaFX shader node and make sure it is loaded.
     MFnDependencyNode shaderFn(shaderObj);
     CFXShaderNode* pNode = (CFXShaderNode*)shaderFn.userNode();
     if (pNode == NULL) return;
     if (!pNode->IsLoaded()) pNode->forceLoad();

     pass->SetPassName(MConvert::ToFChar(doc->MayaNameToColladaName(shaderFn.name())));
     FCDEffectPassShader* vertexShader = pass->AddVertexShader();
     FCDEffectPassShader* fragmentShader = pass->AddFragmentShader();

     vertexShader->SetName(pNode->getVertexEntry());
     fragmentShader->SetName(pNode->getFragmentEntry());

     MString f_strM;
     DagHelper::GetPlugValue(shaderObj, "vertexProgram", f_strM);
     FCDEffectCode* vCode = profile->AddCode();
     vCode->SetFilename(MConvert::ToFChar(f_strM));
     vertexShader->SetCode(vCode);

     DagHelper::GetPlugValue(shaderObj, "fragmentProgram", f_strM);
     vCode = profile->AddCode();
     vCode->SetFilename(MConvert::ToFChar(f_strM));
     fragmentShader->SetCode(vCode);

     ExportProgramBinding(vertexShader, MString("vertParam"), shaderFn);
     ExportProgramBinding(fragmentShader, MString("fragParam"), shaderFn);

     // Export the pass render states.
     for (CFXRenderStateList::iterator it = pNode->GetRenderStates().begin(); it != pNode->GetRenderStates().end(); ++it)
     {
      const FCDEffectPassState* fxState = (*it)->GetData();
      FCDEffectPassState* colladaState = pass->AddRenderState(fxState->GetType());
      fxState->Clone(colladaState);
     }
    }
    */

    /*
    void DaeMaterialLibrary::ExportNewParameters(FCDEffectProfileFX* profile, const MObject& shader, FCDMaterial* instance)
    {
     MFnDependencyNode shaderFn(shader);
     CFXShaderNode* pNode = (CFXShaderNode*)shaderFn.userNode();
     CFXParameterList& parameters = pNode->GetParameters();
     size_t parameterCount = parameters.size();
     for (size_t i = 0; i < parameterCount; ++i)
     {
      CFXParameter* attrib = parameters[i];
      fm::String reference = (shaderFn.name() + attrib->getName()).asChar();

      switch (attrib->getType())
      {
      case CFXParameter::kBool: {
       bool bval;
       DagHelper::GetPlugValue(attrib->getPlug(), bval);

       FCDEffectParameterBool* parameter = (FCDEffectParameterBool*) profile->AddEffectParameter(FCDEffectParameter::BOOLEAN);
       parameter->SetGenerator();
       parameter->SetSemantic(attrib->getSemanticStringForFXC());
       parameter->SetValue(bval);
       parameter->SetReference(reference);
       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UINAME), FCDEffectParameter::STRING, attrib->getName());

       parameter = (FCDEffectParameterBool*) instance->AddEffectParameter(FCDEffectParameter::BOOLEAN);
       parameter->SetModifier();
       parameter->SetReference(reference);
       parameter->SetValue(bval);
       break; }

      case CFXParameter::kHalf:
      case CFXParameter::kFloat: {
       FCDEffectParameterFloat* parameter = (FCDEffectParameterFloat*) profile->AddEffectParameter(FCDEffectParameter::FLOAT);
       parameter->SetGenerator();
       parameter->SetSemantic(attrib->getSemanticStringForFXC());
       parameter->SetValue(attrib->getFloatValue());
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat ? FCDEffectParameterFloat::FLOAT : FCDEffectParameterFloat::HALF);

       MFnNumericAttribute fnum(attrib->getAttribute());
       double fmin, fmax;
       fnum.getMin(fmin);
       fnum.getMax(fmax);

       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UINAME), FCDEffectParameter::STRING, attrib->getName());
       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UIMIN), FCDEffectParameter::FLOAT, (float)fmin);
       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UIMAX), FCDEffectParameter::FLOAT, (float)fmax);

       if (attrib->getSemantic() != CFXParameter::kTIME)
       {
        FCDAnimated* animated = parameter->GetValue().GetAnimated();
        ANIM->AddPlugAnimation(shader, attrib->getAttributeName(), animated, kSingle);
       }

       parameter = (FCDEffectParameterFloat*) instance->AddEffectParameter(FCDEffectParameter::FLOAT);
       parameter->SetModifier();
       parameter->SetValue(attrib->getFloatValue());
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat ? FCDEffectParameterFloat::FLOAT : FCDEffectParameterFloat::HALF);
       break; }

      case CFXParameter::kFloat2:
      case CFXParameter::kHalf2: {
       FCDEffectParameterFloat2* parameter = (FCDEffectParameterFloat2*) profile->AddEffectParameter(FCDEffectParameter::FLOAT2);
       parameter->SetGenerator();
       parameter->SetSemantic(attrib->getSemanticStringForFXC());
       parameter->SetValue(FMVector2(attrib->getFloatValueX(), attrib->getFloatValueY()));
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat2 ? FCDEffectParameterFloat2::FLOAT : FCDEffectParameterFloat2::HALF);

       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UINAME), FCDEffectParameter::STRING, attrib->getName());

       parameter = (FCDEffectParameterFloat2*) instance->AddEffectParameter(FCDEffectParameter::FLOAT2);
       parameter->SetModifier();
       parameter->SetValue(FMVector2(attrib->getFloatValueX(), attrib->getFloatValueY()));
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat2 ? FCDEffectParameterFloat2::FLOAT : FCDEffectParameterFloat2::HALF);
       break; }

      case CFXParameter::kHalf3:
      case CFXParameter::kFloat3: {
       FCDEffectParameterFloat3* parameter = (FCDEffectParameterFloat3*) profile->AddEffectParameter(FCDEffectParameter::FLOAT3);
       parameter->SetGenerator();
       parameter->SetSemantic(attrib->getSemanticStringForFXC());
       parameter->SetValue(FMVector3(attrib->getFloatValueX(), attrib->getFloatValueY(), attrib->getFloatValueZ()));
       parameter->SetReference(reference);

       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UINAME), FCDEffectParameter::STRING, attrib->getName());
       fstring s = TO_FSTRING(attrib->getUIType().asChar());
       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UITYPE), FCDEffectParameter::STRING, s.c_str());

       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat3 ? FCDEffectParameterFloat3::FLOAT : FCDEffectParameterFloat3::HALF);

       ANIM->AddPlugAnimation(shader, attrib->getAttributeName(), parameter->GetValue().GetAnimated(), kColour);

       parameter = (FCDEffectParameterFloat3*) instance->AddEffectParameter(FCDEffectParameter::FLOAT3);
       parameter->SetModifier();
       parameter->SetValue(FMVector3(attrib->getFloatValueX(), attrib->getFloatValueY(), attrib->getFloatValueZ()));
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat3 ? FCDEffectParameterFloat3::FLOAT : FCDEffectParameterFloat3::HALF);
       break; }

      case CFXParameter::kFloat4:
      case CFXParameter::kHalf4: {
       FCDEffectParameterVector* parameter = (FCDEffectParameterVector*) profile->AddEffectParameter(FCDEffectParameter::VECTOR);
       parameter->SetGenerator();
       parameter->SetSemantic(attrib->getSemanticStringForFXC());
       parameter->SetValue(FMVector4(attrib->getFloatValueX(), attrib->getFloatValueY(), attrib->getFloatValueZ(), 0.0f));
       parameter->SetReference(reference);

       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UINAME), FCDEffectParameter::STRING, attrib->getName());
       fstring s = TO_FSTRING(attrib->getUIType().asChar());
       parameter->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UITYPE), FCDEffectParameter::STRING, s.c_str());

       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat4 ? FCDEffectParameterVector::FLOAT : FCDEffectParameterVector::HALF);

       ANIM->AddPlugAnimation(shader, attrib->getAttributeName(), parameter->GetValue().GetAnimated(), kColour);

       parameter = (FCDEffectParameterVector*) instance->AddEffectParameter(FCDEffectParameter::VECTOR);
       parameter->SetModifier();
       parameter->SetValue(FMVector4(attrib->getFloatValueX(), attrib->getFloatValueY(), attrib->getFloatValueZ(), 0.0f));
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat4 ? FCDEffectParameterVector::FLOAT : FCDEffectParameterVector::HALF);
       break; }

      case CFXParameter::kHalf4x4:
      case CFXParameter::kFloat4x4: {
       FCDEffectParameterMatrix* parameter = (FCDEffectParameterMatrix*) profile->AddEffectParameter(FCDEffectParameter::MATRIX);
       parameter->SetGenerator();
       parameter->SetSemantic(attrib->getSemanticStringForFXC());
       parameter->SetValue(FMMatrix44::Identity);
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat4x4 ? FCDEffectParameterMatrix::FLOAT : FCDEffectParameterMatrix::HALF);

       parameter = (FCDEffectParameterMatrix*) instance->AddEffectParameter(FCDEffectParameter::MATRIX);
       parameter->SetModifier();
       parameter->SetValue(FMMatrix44::Identity);
       parameter->SetReference(reference);
       parameter->SetFloatType(attrib->getType() == CFXParameter::kFloat4x4 ? FCDEffectParameterMatrix::FLOAT : FCDEffectParameterMatrix::HALF);
       break; }

      case CFXParameter::kSampler2D:
      case CFXParameter::kSamplerCUBE:
       {
        MPlug tex_plug;
        if (DagHelper::GetPlugConnectedTo(attrib->getPlug(), tex_plug))
        {
         FCDEffectParameterSampler* parameter1 = (FCDEffectParameterSampler*) profile->AddEffectParameter(FCDEffectParameter::SAMPLER);
         parameter1->SetGenerator();
         parameter1->SetSemantic(attrib->getSemanticStringForFXC());
         parameter1->SetReference(reference);
         parameter1->AddAnnotation(TO_FSTRING(CFX_ANNOTATION_UINAME), FCDEffectParameter::STRING, attrib->getName());
         parameter1->SetSamplerType(attrib->getType() == CFXParameter::kSampler2D ? FCDEffectParameterSampler::SAMPLER2D : FCDEffectParameterSampler::SAMPLERCUBE);

         FCDEffectParameterSampler* parameter2 = (FCDEffectParameterSampler*) instance->AddEffectParameter(FCDEffectParameter::SAMPLER);
         parameter2->SetModifier();
         parameter2->SetReference(reference);
         parameter2->SetSamplerType(attrib->getType() == CFXParameter::kSampler2D ? FCDEffectParameterSampler::SAMPLER2D : FCDEffectParameterSampler::SAMPLERCUBE);

         const char* type = attrib->getType() == CFXParameter::kSampler2D ? "2D" : "CUBE";

         // Export the surface.
         FCDEffectParameterSurface* surfaceParameter = writeSurfaceTexture(profile, tex_plug.node(), instance, type);
         parameter1->SetSurface(surfaceParameter);
         parameter2->SetSurface(surfaceParameter);
        }
        break;
       }
      case CFXParameter::kSurface:
      case CFXParameter::kStruct:
      case CFXParameter::kUnknown:
      default:
       // FUFail?
       break;
      }
     }
    }

    */
}