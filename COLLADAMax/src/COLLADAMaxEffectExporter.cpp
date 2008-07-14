/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxEffectExporter.h"
#include "COLLADANode.h"

#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxMultiMtl.h"

#include <algorithm>

#include <IDxMaterial.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <stdmat.h>
#include <shaders.h>

namespace COLLADAMax
{


    const String EffectExporter::COLOR_EFFECT_ID_PREFIX = "ColorEffect";
    const String EffectExporter::TEXCOORD_BASE = "CHANNEL";

    const String EffectExporter::DAE_AMBIENT_TEXTURE_CHANNEL = "AMBIENT";
    const String EffectExporter::DAE_BUMP_TEXTURE_CHANNEL = "BUMP";
    const String EffectExporter::DAE_DIFFUSE_TEXTURE_CHANNEL = "DIFFUSE";
    const String EffectExporter::DAE_DISPLACEMENT_TEXTURE_CHANNEL = "DISPLACEMENT";
    const String EffectExporter::DAE_EMISSION_TEXTURE_CHANNEL = "GLOW";
    const String EffectExporter::DAE_FILTER_TEXTURE_CHANNEL = "FILTER";
    //#defineDAE_OPACITY_TEXTURE_CHANNEL = "OPACITY";
    const String EffectExporter::DAE_REFLECTION_TEXTURE_CHANNEL = "REFLECTION";
    const String EffectExporter::DAE_REFRACTION_TEXTURE_CHANNEL = "REFRACTION";
    const String EffectExporter::DAE_SHININESS_TEXTURE_CHANNEL = "SHININESS";
    const String EffectExporter::DAE_SPECULAR_TEXTURE_CHANNEL = "SPECULAR";
    const String EffectExporter::DAE_SPECULARLEVEL_TEXTURE_CHANNEL = "SPECULAR-LEVEL";
    const String EffectExporter::DAE_TRANSPARENT_TEXTURE_CHANNEL = "TRANSPARENT";

    const String EffectExporter::EMPTY_STRING = "";


    //---------------------------------------------------------------
    EffectExporter::EffectExporter ( COLLADA::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADA::LibraryEffects ( streamWriter ),
            mExportSceneGraph ( exportSceneGraph ),
            mDocumentExporter ( documentExporter )
    {}

    //---------------------------------------------------------------
    void EffectExporter::doExport()
    {
        mExportedEffectIdList = & ( mDocumentExporter->getMaterialExporter() ->getEffectIdList() );

        exportEffect ( mExportSceneGraph->getRootExportNode() );
        closeLibrary();
    }

    //---------------------------------------------------------------
    void EffectExporter::exportEffect ( ExportNode* exportNode )
    {
        INode * iNode = exportNode->getINode();
        Mtl * material = iNode->GetMtl();

        // If the node has material export it. If not, export the wire color.

        if ( material )
        {
            exportEffect ( exportNode, material );
        }

        else
        {
            exportColorEffect ( exportNode, iNode->GetWireColor() );
        }

        //export the child nodes materials
        size_t numberOfChildren = exportNode->getNumberOfChildren();

        for ( size_t i = 0; i < numberOfChildren; ++i )
            exportEffect ( exportNode->getChild ( i ) );
    }

    //---------------------------------------------------------------
    void EffectExporter::exportEffect ( ExportNode* exportNode, Mtl* material )
    {
        if ( material->IsMultiMtl() )
        {
            // This material type is used for meshes with multiple materials:
            // only export the individual materials.

            for ( int j = 0; j < material->NumSubMtls(); j++ )
            {
                Mtl* submat = material->GetSubMtl ( j );

                if ( submat != NULL )
                    exportEffect ( exportNode, submat );
            }
        }

        else
        {
            // add <material> node for this material to the library
            exportSimpleEffect ( exportNode, material );
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportSimpleEffect ( ExportNode* exportNode, Mtl* baseMaterial )
    {
        // check if this is not an XRef
#if 0

        if ( XRefFunctions::IsXRefMaterial ( baseMaterial ) )
        {
            if ( OPTS->ExportXRefs() )
            {
                // don't generate the FCDMaterial
                return ;
            }

            else
            {
                baseMaterial = XRefFunctions::GetXRefMaterialSource ( baseMaterial );
            }
        }

#endif

        EffectMap::iterator it = mEffectMap.find ( baseMaterial );

        if ( it != mEffectMap.end() )
        {
            exportNode->addSymbol ( baseMaterial, it->second );
            return ;
        }


        // Add it to the exported materials list
        String effectId = mEffectIdList.addId ( baseMaterial->GetName().data() );

        exportNode->addSymbol ( baseMaterial, effectId );

        mEffectMap[ baseMaterial ] = effectId;

        mExportedEffectIdList->push_back ( effectId );

        openEffect ( effectId );

        COLLADA::EffectProfile effectProfile ( mSW );


        // Write out the custom attributes
        //  ExportCustomAttributes(baseMaterial, material);

        /// @TODO Handle other types of material properly
        // does the material have an HLSL profile?
        IDxMaterial* dxm = static_cast<IDxMaterial*> ( baseMaterial->GetInterface ( IDXMATERIAL_INTERFACE ) );

        if ( dxm != NULL && dxm->GetEffectFilename() != NULL )
        {
            if ( baseMaterial->NumSubMtls() > 0 && baseMaterial->GetSubMtl ( 0 ) != NULL )
            {
                // Create common profile
                Mtl * workingMaterial = baseMaterial->GetSubMtl ( 0 );
                //   ExportCustomAttributes(workingMaterial, material);
                //    exportCommonEffect((FCDEffectStandard*)matEffect->AddProfile(FUDaeProfileType::COMMON), workingMaterial);
                exportCommonEffect ( effectProfile, exportNode, workingMaterial, effectId );
            }

            // Create HLSL profile and add the effect instantiation elements
            //   ExportEffectHLSL(material, baseMaterial);
        }

        //  else if (baseMaterial->ClassID() == COLLADA_EFFECT_ID)
        //  {
        //   exportColladaEffect(material, (ColladaEffect*)baseMaterial);
        //  }

        else
        {
            // Create common profile
            exportCommonEffect ( effectProfile, exportNode, baseMaterial, effectId );
        }

        addEffectProfile ( effectProfile );

        closeEffect();

    }

    //---------------------------------------------------------------
    void EffectExporter::exportCommonEffect ( COLLADA::EffectProfile & effectProfile, ExportNode* exportNode, Mtl* material, const String & effectId, float weight, bool inited )
    {
        // Export all submaterials first.
        int subMaterialCount = material->NumSubMtls();

        for ( int i = 0; i < subMaterialCount; ++i )
        {
            Mtl* subMaterial = material->GetSubMtl ( i );
            float subMtlWeight = weight;

            if ( material->ClassID() == CompositeMtl::classID )
            {
                IParamBlock2 * pblock = material->GetParamBlock ( 0 );

                if ( pblock != NULL )
                {
                    if ( !pblock->GetInt ( CompositeMtl::compmat_map_on ) )
                        subMtlWeight = 0;
                    else
                        subMtlWeight *= pblock->GetFloat ( CompositeMtl::compmat_amount ) / 100.0f;
                }
            }

            if ( subMaterial != NULL )
            {
                exportCommonEffect ( effectProfile, exportNode, subMaterial, effectId, subMtlWeight, inited );
                inited = true;
            }
        }

        Class_ID materialId = material->ClassID();

        if ( materialId.PartA() == DMTL2_CLASS_ID || materialId.PartA() == DMTL_CLASS_ID )
        {
            exportStandardEffect ( effectProfile, exportNode, ( StdMat2* ) material, effectId, weight, inited );
        }

        else
        {
            // This must be some strange 'RayTrace' or render-only material
            // Export whatever information we can from the Max material interface
            exportUnknownEffect ( effectProfile, exportNode, material, effectId );
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportStandardEffect ( COLLADA::EffectProfile & effectProfile, ExportNode* exportNode, StdMat2* material, const String & effectId, float weight, bool inited )
    {
        assert ( material != 0 );

        // TODO ensure that effect id unique
        //  String effectId = mEffectIdList.addId(material->GetName().data());

#if 0

        EffectMap::iterator effectIterator = mEffectMap.find ( ( Mtl* ) material );


        if ( effectIterator != mEffectMap.end() )
        {
            exportNode->addSymbol ( ( Mtl* ) material, effectId );
            return ;
        }

#endif
        exportNode->addSymbol ( material, material->GetName().data() );

        mEffectMap[ material ] = effectId;

        Shader* shader = material->GetShader();

        TimeValue time = 0;

        if ( !inited )
        {
            effectProfile.setShaderType ( maxShaderToShaderType ( shader->ClassID() ) );
        }

        // Retrieve the interesting parameter blocks
        IParamBlock2* shaderParameters = ( IParamBlock2* ) shader->GetReference ( 0 );

        IParamBlock2* extendedParameters = ( IParamBlock2* ) material->GetReference ( StandardMaterial::EXTENDED_PB_REF );

        TimeValue initTime = 0; //TIME_EXPORT_START;

        if ( !inited )
        {
            // effectProfile.setShaderType(COLLADA::EffectProfile::PHONG);
            effectProfile.setAmbient ( maxColor2ColorOrTexture ( shader->GetAmbientClr ( time ), weight ) );
            effectProfile.setDiffuse ( maxColor2ColorOrTexture ( shader->GetDiffuseClr ( time ), weight ) );
            effectProfile.setTransparent ( COLLADA::ColorOrTexture ( COLLADA::Color::WHITE ) );
            effectProfile.setTransparency ( material->GetOpacity ( time ) * weight );
            effectProfile.setReflective ( COLLADA::ColorOrTexture ( COLLADA::Color::BLACK ) );
            effectProfile.setSpecular ( maxColor2ColorOrTexture ( shader->GetSpecularClr ( time ), weight ) );
            effectProfile.setShininess ( shader->GetGlossiness ( time ) * 100 * weight );
        }

        // Export child maps
        int numSubTexMaps = material->NumSubTexmaps();

        for ( int i = 0; i < numSubTexMaps; i++ )
        {
            Channel channel = maxIdToEffectChannel ( material, i );

            if ( channel == EffectExporter::UNKNOWN )
                continue;

            Texmap* map = material->GetSubTexmap ( i );

            // special cases
            switch ( channel )
            {

            case EMISSION:

                if ( !material->GetSelfIllumColorOn() )     // Emission
                {
                    // emission factor
                    //    ANIM->ExportProperty(_T("self_illum_level"), shaderParameters, FSStandardMaterial::shdr_self_illum_amnt, 0, stdProfile->GetEmissionFactorParam()->GetValue(), NULL);
                    //TODO: check what this is good for
                    //stdProfile->SetIsEmissionFactor(true);
                    continue;
                }

                break;

            case TRANSPARENt:
                effectProfile.setOpacity ( getOpacity ( map ) );
                break;
            }

            // Calculate weight here.  Let execution continue
            // even if map is disabled, in order to manage colour blending
            float colorAmount, mapAmount = 0;

            bool exportThisMap = material->GetMapState ( i ) == 2;

            if ( exportThisMap )
            {
                mapAmount = material->GetTexmapAmt ( i, 0 );
                colorAmount = weight * ( 1.0f - mapAmount );
                mapAmount *= weight;
            }

            else
                colorAmount = weight;

            // If our id maps to a colour value, modulate that by our colourAmount.
            // TODO: add this later
            switch ( channel )
            {

            case AMBIENT:
                blendColor ( effectProfile.getAmbient(), material->GetAmbient ( initTime ), colorAmount );
                break;

            case DIFFUSE:
                blendColor ( effectProfile.getDiffuse(), material->GetDiffuse ( initTime ), colorAmount );
                break;

            case SPECULAR:
                blendColor ( effectProfile.getSpecular(), material->GetSpecular ( initTime ), colorAmount );
                break;
            }

            // export now.

            if ( exportThisMap )
                exportMap ( channel, map, effectProfile, weight * mapAmount );
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportMap ( unsigned int index, Texmap* texMap, COLLADA::EffectProfile & profile, float weight )
    {
        if ( texMap == NULL )
            return ;

        //if (weight <= 0) return;

        // Get any weight control directly on this texmap
        float amount = weight;

        Control* weightControl = NULL;

        if ( texMap != NULL && GetIBitmapTextInterface ( texMap ) != NULL )
        {
            try
            {
                BitmapTex * bmTex = ( BitmapTex* ) texMap;
                TextureOutput* texOut = bmTex->GetTexout();
                IParamBlock* params = ( IParamBlock* ) texOut->GetReference ( TextureOutputIDs::param_block_ref_id );

                if ( index == ID_BU )
                {
                    weightControl = params->GetController ( TextureOutputIDs::bump_amount );
                    amount *= params->GetFloat ( TextureOutputIDs::bump_amount );
                }

                else
                {
                    weightControl = params->GetController ( TextureOutputIDs::output_amount );
                    amount *= params->GetFloat ( TextureOutputIDs::output_amount );
                }
            }

            catch ( ... )
            {
                /// @TODO error handling
            }
        }

        // Export image
        String imageId = exportImage ( texMap );

        if ( !imageId.empty() )
        {
            COLLADA::Texture texture ( imageId, COLLADA::Texture::SURFACE_TYPE_2D );

            int mapChannel = 1;

            if ( texMap != NULL )
            {
                mapChannel = texMap->GetMapChannel();

                // TODO: add extra tag
            }

            String semantic = TEXCOORD_BASE + COLLADA::Utils::toString ( mapChannel );

            texture.setTexcoord ( semantic );

            //TODO: extra tag

            switch ( index )
            {

            case AMBIENT:
                profile.setAmbient ( COLLADA::ColorOrTexture ( texture ) );
                break;
                // case BUMP: bumpTextures.push_back(COLLADA::ColorOrTexture(texture)); break;

            case DIFFUSE:
                profile.setDiffuse ( COLLADA::ColorOrTexture ( texture ) );
                break;
                // case DISPLACEMENT: displacementTextures.push_back(COLLADA::ColorOrTexture(texture)); break;

            case EMISSION:
                profile.setEmission ( COLLADA::ColorOrTexture ( texture ) );
                break;
                // case FILTER: filterTextures.push_back(COLLADA::ColorOrTexture(texture)); break;
                // case REFLECTION: reflectivityTextures.push_back(COLLADA::ColorOrTexture(texture)); break;
                // case REFRACTION: refractionTextures.push_back(COLLADA::ColorOrTexture(texture)); break;
                // case SHININESS: shininessTextures.push_back(COLLADA::ColorOrTexture(texture)); break;

            case SPECULAR:
                profile.setSpecular ( COLLADA::ColorOrTexture ( texture ) );
                break;
                // case SPECULAR_LEVEL: specularFactorTextures.push_back(COLLADA::ColorOrTexture(texture)); break;

            case TRANSPARENT:
                profile.setTransparent ( COLLADA::ColorOrTexture ( texture ) );
                break;

            default:
                ;
                //@TODO error handling
            }

        }

        // Export any and all submaps
        float subAmount = amount;

        int numSubTex = texMap->NumSubTexmaps();

        for ( int subIdx = 0; subIdx < numSubTex; subIdx++ )
        {
            Texmap* subMap = texMap->GetSubTexmap ( subIdx );

            // Handle special cases.
            Class_ID mapClassId = texMap->ClassID();

            if ( mapClassId.PartB() == 0 )
            {
                switch ( mapClassId.PartA() )
                {

                case MIX_CLASS_ID:
                {
                    IParamBlock2 * mixParams = texMap->GetParamBlock ( 0 );

                    if ( !mixParams )
                        break;

                    Color color;

                    switch ( subIdx )
                    {

                    case 0:
                        subAmount = amount;
                        color = mixParams->GetColor ( MixMap::mix_color1 );
                        break;

                    case 1:
                        subAmount = amount * mixParams->GetFloat ( MixMap::mix_mix );
                        color = mixParams->GetColor ( MixMap::mix_color2 );
                        break;

                    case 2:
                        // Scale to 0, as this isn't an actual texture, but a mix modifier
                        // In that case, we want to keep a texture reference for the user
                        // to figure out if they want
                        subAmount = 0;
                        break;
                    }

                    // Handle the simple case, which is blending colors.

                    if ( subMap == NULL && subAmount > 0 )
                    {
                        switch ( index )
                        {

                        case AMBIENT:
                            blendColor ( profile.getAmbient(), color, subAmount );
                            break;

                        case DIFFUSE:
                            blendColor ( profile.getDiffuse(), color, subAmount );
                            break;

                        case SPECULAR:
                            blendColor ( profile.getSpecular(), color, subAmount );
                            break;
                        }
                    }
                }

                break;
                }
            }

            else
                subAmount = amount;

            if ( subMap != NULL )
            {
                if ( texMap->SubTexmapOn ( subIdx ) == 0 )
                    subAmount = 0;

                exportMap ( index, subMap, profile, subAmount );
            }
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportUnknownEffect ( COLLADA::EffectProfile & effectProfile, ExportNode* exportNode, Mtl* material, const String & effectId )
    {
        assert ( material != 0 );

        /* TODO: think about this*/

        if ( effectProfile.getShaderType() == COLLADA::EffectProfile::UNSPECIFIED )
        {
            float specularLevel = material->GetShinStr();
            bool isPhong = specularLevel > 0.2f;
            effectProfile.setShaderType ( isPhong ? COLLADA::EffectProfile::PHONG : COLLADA::EffectProfile::BLINN );
        }

        if ( material->GetSelfIllumColorOn() && !effectProfile.getEmission().isValid() )
            effectProfile.setEmission ( maxColor2ColorOrTexture ( material->GetSelfIllumColor() ) );

        if ( !effectProfile.getAmbient().isValid() )
            effectProfile.setAmbient ( maxColor2ColorOrTexture ( material->GetAmbient() ) );

        if ( !effectProfile.getDiffuse().isValid() )
            effectProfile.setDiffuse ( maxColor2ColorOrTexture ( material->GetDiffuse() ) );


        if ( effectProfile.getShaderType() == COLLADA::EffectProfile::PHONG )
        {
            if ( !effectProfile.getSpecular().isValid() )
                effectProfile.setSpecular ( maxColor2ColorOrTexture ( material->GetSpecular() ) );

            /// TODO: think about this
            if ( effectProfile.getShininess() < 0 )
                effectProfile.setShininess ( material->GetShininess() * 100.0f );

            /* if (!material->GetSelfIllumColorOn())
             {
              stdProfile->SetIsEmissionFactor(true);
              float emissionFactor = material->GetSelfIllum();
              stdProfile->SetEmissionFactor(emissionFactor);
             }*/

            // stdProfile->SetSpecularFactor(specularLevel);
        }

        exportNode->addSymbol ( material, material->GetName().data() );

        mEffectMap[ material ] = effectId;
    }

    //---------------------------------------------------------------
    void EffectExporter::exportColorEffect ( ExportNode* exportNode, DWORD color )
    {
        String effectId = getEffectId ( color );

        if ( find ( mWireFrameColorEffectList.begin(), mWireFrameColorEffectList.end(), color ) == mWireFrameColorEffectList.end() )
        {
            String effectId = getEffectId ( color );

            openEffect ( effectId );

            COLLADA::EffectProfile effectProfile ( mSW );
            effectProfile.setShaderType ( COLLADA::EffectProfile::PHONG );
            COLLADA::Color commonColor ( GetRValue ( color ) / 255.0f, GetGValue ( color ) / 255.0f, GetBValue ( color ) / 255.0f );
            effectProfile.setAmbient ( COLLADA::ColorOrTexture ( commonColor ) );
            effectProfile.setDiffuse ( COLLADA::ColorOrTexture ( commonColor ) );
            effectProfile.setTransparent ( COLLADA::ColorOrTexture ( COLLADA::Color::WHITE ) );
            effectProfile.setTransparency ( 1.0 );
            effectProfile.setReflective ( COLLADA::ColorOrTexture ( COLLADA::Color::BLACK ) );
            effectProfile.setSpecular ( COLLADA::ColorOrTexture ( COLLADA::Color::WHITE ) );
            effectProfile.setShininess ( 10.0 );

            addEffectProfile ( effectProfile );

            closeEffect();

            mWireFrameColorEffectList.push_back ( color );
        }

        exportNode->setWireFrameColor ( color );
    }

    //---------------------------------------------------------------
    String EffectExporter::getEffectId ( DWORD color )
    {
        std::ostringstream name;
        name << COLOR_EFFECT_ID_PREFIX << "R" << ( int ) GetRValue ( color ) << "G" << ( int ) GetGValue ( color )
        << "B" << ( int ) GetBValue ( color );
        return name.str();
    }

    //---------------------------------------------------------------
    COLLADA::ColorOrTexture EffectExporter::maxColor2ColorOrTexture ( const Color & color, double scale )
    {
        return COLLADA::ColorOrTexture ( COLLADA::Color ( color.r * scale, color.g * scale, color.b * scale, scale ) );
    }

    //---------------------------------------------------------------
    EffectExporter::Channel EffectExporter::maxIdToEffectChannel ( StdMat2* material, int id )
    {
        assert ( material != NULL );

        // Order of channels depends on shader.
        bool stdShader = true;
        Shader* shader = material->GetShader();

        if ( shader )
        {
            Class_ID shaderClassId = shader->ClassID();
            unsigned long partA = shaderClassId.PartA();

            if ( shaderClassId.PartB() != 0 ||
                    ! (
                        partA == EffectExporter::STD2_PHONG_CLASS_ID ||
                        partA == EffectExporter::STD2_BLINN_SHADER_CLASS_ID ||
                        partA == EffectExporter::STD2_METAL_SHADER_CLASS_ID ||
                        partA == EffectExporter::STD2_ANISOTROPIC_SHADER_CLASS_ID ||
                        partA == EffectExporter::STD2_MULTI_LAYER_SHADER_CLASS_ID ||
                        partA == EffectExporter::STD2_OREN_NAYER_BLINN_CLASS_ID
                    )
               )
            {
                stdShader = false;
            }
        }

        if ( !stdShader )
        {
            // First attempt for a non-max shader is name-matching.
            // this is because StdIDToChannel may need some extra help
            // if for some weird reason there are several different texture
            // slots for the same effect.  Quite why that happens is
            // completely beyond me, but it does happen...  Also, as it
            // turns out, it is better not to trust the 3rd party implementations
            TSTR subName = material->GetSubTexmapSlotName ( id );

            if ( subName.Length() > 0 )
            {
                String upperName = subName;
                std::transform ( upperName.begin(), upperName.end(), upperName.begin(), toupper );
                size_t firstSpace = upperName.find ( ' ' );

                if ( firstSpace != String::npos )
                    upperName.resize ( firstSpace );

                if ( upperName == "BASE" )
                    return EffectExporter::DIFFUSE;
                else if ( upperName == "GLOSS" )
                    return EffectExporter::SPECULAR;
                else
                {
                    EffectExporter::Channel channel = EffectExporter::channelFromString ( upperName );

                    if ( channel != EffectExporter::UNKNOWN )
                        return channel;
                }
            }
        }

#ifdef _DEBUG
        else
        {
            // What do we have here, ay?
            TSTR subName = material->GetSubTexmapSlotName ( id );
            subName;
        }

#endif

        // If we are here, we are either a std max mtl, or a
        // non-std mtl we couldnt match a name to.
        int classId = -1;

        for ( int i = 0; i < NTEXMAPS; i++ )
        {
            //int x = material->StdIDToChannel(i);

            if ( material->StdIDToChannel ( i ) == id )
            {
                classId = i;
                break;
            }
        }

        switch ( classId )
        {

        case ID_AM:
            return EffectExporter::AMBIENT;

        case ID_DI:
            return EffectExporter::DIFFUSE;

        case ID_SP:
            return EffectExporter::SPECULAR;

        case ID_SH:
            return EffectExporter::SHININESS;

        case ID_SS:
            return EffectExporter::SPECULAR_LEVEL;

        case ID_SI:
            return EffectExporter::EMISSION;

        case ID_OP:
            return EffectExporter::TRANSPARENt;

        case ID_FI:
            return EffectExporter::FILTER;

        case ID_BU:
            return EffectExporter::BUMP;

        case ID_RL:
            return EffectExporter::REFLECTION;

        case ID_RR:
            return EffectExporter::REFRACTION;

        case ID_DP:
            return EffectExporter::DISPLACEMENT;

        default:
            return EffectExporter::UNKNOWN;
        }

    };

    //---------------------------------------------------------------
    EffectExporter::Channel EffectExporter::channelFromString ( const String & value )
    {
        if ( value == DAE_AMBIENT_TEXTURE_CHANNEL )
            return EffectExporter::AMBIENT;
        else if ( value == DAE_BUMP_TEXTURE_CHANNEL )
            return EffectExporter::BUMP;
        else if ( value == DAE_DIFFUSE_TEXTURE_CHANNEL )
            return EffectExporter::DIFFUSE;
        else if ( value == DAE_DISPLACEMENT_TEXTURE_CHANNEL )
            return EffectExporter::DISPLACEMENT;
        else if ( value == DAE_EMISSION_TEXTURE_CHANNEL )
            return EffectExporter::EMISSION;
        else if ( value == DAE_FILTER_TEXTURE_CHANNEL )
            return EffectExporter::FILTER;

        //  else if (value == DAE_OPACITY_TEXTURE_CHANNEL) return OPACITY;
        else if ( value == DAE_REFLECTION_TEXTURE_CHANNEL )
            return EffectExporter::REFLECTION;
        else if ( value == DAE_REFRACTION_TEXTURE_CHANNEL )
            return EffectExporter::REFRACTION;
        else if ( value == DAE_SHININESS_TEXTURE_CHANNEL )
            return EffectExporter::SHININESS;
        else if ( value == DAE_SPECULAR_TEXTURE_CHANNEL )
            return EffectExporter::SPECULAR;
        else if ( value == DAE_SPECULARLEVEL_TEXTURE_CHANNEL )
            return EffectExporter::SPECULAR_LEVEL;
        else if ( value == DAE_TRANSPARENT_TEXTURE_CHANNEL )
            return EffectExporter::TRANSPARENt;
        else
            return UNKNOWN;
    }

    //---------------------------------------------------------------
    COLLADA::EffectProfile::Opaque EffectExporter::getOpacity ( Texmap *texMap )
    {
        // Only one transparency factor is supported, so retrieve only the first texture from this bucket.

        if ( texMap == NULL )
            return COLLADA::EffectProfile::UNSPECIFIED_OPAQUE;

        BitmapTex* bmap = GetIBitmapTextInterface ( texMap );

        BOOL isAlphaTransparency = true;

        if ( bmap != NULL )
            isAlphaTransparency = bmap->GetAlphaAsMono ( TRUE );

        // As far as my tests are concerned, the only real way to get alpha-transparency is through
        // the mono-channel output as Alpha.
        return isAlphaTransparency ? COLLADA::EffectProfile::A_ONE : COLLADA::EffectProfile::RGB_ZERO;
    }

    //---------------------------------------------------------------
    COLLADA::EffectProfile::ShaderTypes EffectExporter::maxShaderToShaderType ( Class_ID id )
    {
        switch ( id.PartA() )
        {

        case StandardMaterial::STD2_BLINN_SHADER_CLASS_ID:

        case StandardMaterial::STD2_OREN_NAYER_BLINN_CLASS_ID:

        case StandardMaterial::STD2_METAL_SHADER_CLASS_ID:
            return COLLADA::EffectProfile::BLINN;

        case StandardMaterial::STD2_PHONG_CLASS_ID:
            return COLLADA::EffectProfile::PHONG;

        default:
            return COLLADA::EffectProfile::PHONG;
        }
    }

    //---------------------------------------------------------------
    String EffectExporter::exportImage ( Texmap* map )
    {
        if ( map == NULL )
            return NULL;

        if ( map->ClassID() == Class_ID ( BMTEX_CLASS_ID, 0x00 ) )
        {
            BitmapTex * baseBitmap = ( BitmapTex* ) map;

            if ( baseBitmap == NULL )
                return NULL;

            // get a valid filename
            BitmapInfo bitmapInfo;

            bitmapInfo.SetName ( baseBitmap->GetMapName() );

            return exportImage ( bitmapInfo );
        }

        else if ( map->ClassID() == Class_ID ( MIX_CLASS_ID, 0x00 ) )
        {
            return EMPTY_STRING;
        }

        // not recognized
        return EMPTY_STRING;
    }

    //---------------------------------------------------------------
    String EffectExporter::exportImage ( BitmapInfo& bitmapInfo )
    {
        const TCHAR * fileName = bitmapInfo.Name();

        if ( fileName != NULL && _tcslen ( fileName ) != 0 && _tcsicmp ( fileName, _T ( "none" ) ) != 0 )
        {

            BMMGetFullFilename ( &bitmapInfo );
            String fullFileName ( bitmapInfo.Name() );
            String fullFileNameURI = COLLADA::Utils::FILE_PROTOCOL + COLLADA::Utils::UriEncode ( fullFileName );
            String imageId;
            // Export the equivalent <image> node in the image library and add
            // the <init_from> element to the sampler's surface definition.
            // "None" is a special Max token, to indicate no texture assigned
            ExportedImageMap::iterator it = mExportedImageMap.find ( fullFileNameURI );

            if ( it == mExportedImageMap.end() )
            {
                // generate an interesting name: strip the filename away from the filepath.
                size_t slashIndex = fullFileName.rfind ( '/' );
                size_t backSlashIndex = fullFileName.rfind ( '\\' );

                if ( slashIndex == String::npos )
                    slashIndex = backSlashIndex;
                else if ( backSlashIndex != String::npos && backSlashIndex > slashIndex )
                    slashIndex = backSlashIndex;

                imageId = ( slashIndex != String::npos ) ? fullFileName.substr ( slashIndex + 1 ) : fullFileName;

                imageId = COLLADA::Utils::replaceDot ( imageId );

                // image not exported
                mExportedImageMap[ fullFileNameURI ] = imageId;
            }

            else
                imageId = it->second;

            return imageId;
        }

        return EMPTY_STRING;
    }

    //---------------------------------------------------------------
    void EffectExporter::blendColor ( COLLADA::ColorOrTexture & colorOrTexture, Color blendColor, double ammount )
    {
        if ( colorOrTexture.isColor() )
        {
            COLLADA::Color & color = colorOrTexture.getColor();

            color.set ( color.getRed() + ( blendColor[ 0 ] - color.getRed() ) * ammount,
                        color.getGreen() + ( blendColor[ 1 ] - color.getGreen() ) * ammount,
                        color.getBlue() + ( blendColor[ 2 ] - color.getBlue() ) * ammount,
                        color.getAlpha()
                      );
        }
    }




}
