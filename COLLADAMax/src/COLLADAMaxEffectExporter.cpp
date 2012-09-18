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

#include "COLLADAMaxEffectExporter.h"

#include "COLLADAMaxExportSceneGraph.h"
#include "COLLADAMaxMultiMtl.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxConversionFunctor.h"
#include "COLLADAMaxHwShaderExporter.h"

#include "COLLADAMaxXRefFunctions.h"

#include "COLLADASWNode.h"
//#include "COLLADASWTextureModifier.h"

#include <algorithm>

#include <IDxMaterial.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <stdmat.h>
#include <shaders.h>
#include <imtl.h> 

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

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

	const String EffectExporter::DAE_BUMP_TYPE_ATTRIBUTE = "bumptype";
	const String EffectExporter::DAE_BUMP_TYPE_NORMALMAP = "NORMALMAP";
	const String EffectExporter::DAE_BUMP_TYPE_HEIGHTFIELD = "HEIGHTFIELD";

    const String EffectExporter::EMPTY_STRING = "";

	const String EffectExporter::SELF_ILLUMINATION_PARAMETER = "self_illumination";

	const String EffectExporter::COLOR_PARAMETERS[ 4 ] =
	{"R", "G", "B", "A"
	};

	const String EffectExporter::SHADER_ELEMENT = "shader";
	const int EffectExporter::SHADER_PARAMETER_COUNT = 7;
	const Extra::ExtraParameter EffectExporter::SHADER_PARAMETERS[] =
	{
		{TYPE_BOOL, 3, "ambient_diffuse_texture_lock"},
		{TYPE_BOOL, 4, "ambient_diffuse_lock"},
		{TYPE_BOOL, 5, "diffuse_specular_lock"},
		{TYPE_BOOL, 6, "use_self_illum_color"},
		{TYPE_PCNT_FRAC, 7, "self_illumination"},
		{TYPE_PCNT_FRAC, 9, "specular_level"},
		{TYPE_FLOAT, 11, "soften"}
	};


	const String EffectExporter::EXTENDED_SHADER_ELEMENT = "extended_shader";
	const int EffectExporter::EXTENDED_SHADER_PARAMETER_COUNT = 11;
	const Extra::ExtraParameter EffectExporter::EXTENDED_SHADER_PARAMETERS[] =
	{
		{TYPE_INT, 0, "opacity_type"},
		{TYPE_RGBA, 2, "filter_color"},
		{TYPE_TEXMAP, 3, "filtert_map"},
		{TYPE_INT, 4, "falloff_type"},
		{TYPE_PCNT_FRAC, 5, "falloff"},
		{TYPE_FLOAT, 6, "index_of_refraction"},
		{TYPE_FLOAT, 7, "wire_size"},
		{TYPE_INT, 8, "wire_units"},
		{TYPE_BOOL, 9, "apply_reflection_dimming"},
		{TYPE_FLOAT, 10, "dim_level"},
		{TYPE_FLOAT, 11, "reflection_level"}
	};



	//---------------------------------------------------------------
	String EffectExporter::createTexcoordSementicFromMapchannel( int mapChannel )
	{
		return TEXCOORD_BASE + COLLADASW::Utils::toString ( mapChannel );
	}

    //---------------------------------------------------------------
    EffectExporter::EffectExporter ( COLLADASW::StreamWriter * streamWriter, ExportSceneGraph * exportSceneGraph, DocumentExporter * documentExporter )
            : COLLADASW::LibraryEffects ( streamWriter ),
			Extra(streamWriter, documentExporter),
            mExportSceneGraph ( exportSceneGraph ),
            mDocumentExporter ( documentExporter ),
            mTextureExporter ( documentExporter ),
			mAnimationExporter( documentExporter->getAnimationExporter() )
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
		if ( !exportNode->getIsInVisualScene() && !exportNode->getIsReferenced() )
			return;

        INode * iNode = exportNode->getINode();
        Mtl * material = iNode->GetMtl();

        // If the node has material export it. If not, export the wire color.

        if ( material )
        {
            exportEffect ( exportNode, material );
        }

        else 
        {
			// export wire frame material only for meshes
			if ( exportNode->getType() == ExportNode::MESH )
			{
				exportColorEffect ( exportNode, iNode->GetWireColor() );
			}
        }

        //export the child nodes materials
        size_t numberOfChildren = exportNode->getNumberOfChildren();

        for ( size_t i = 0; i < numberOfChildren; ++i )
            exportEffect ( exportNode->getChild ( i ) );
    }

    //---------------------------------------------------------------
    void EffectExporter::exportEffect ( ExportNode* exportNode, Mtl* material )
    {

		// check for XRefs
		if (XRefFunctions::isXRefMaterial(material))
		{
			if ( mDocumentExporter->getOptions().getIncludeXRefs() )
			{
				// we don't export XRef materials, but remember them for later use
				material = XRefFunctions::getXRefMaterialSource(material);
			}
			else
			{
				assert(false);
//				xRefedMaterialList.push_back(mat);
				return;
			}
		}


        if ( material->IsMultiMtl() )
        {
            // This material type is used for meshes with multiple materials:
            // only export the individual materials.

            for ( int j = 0; j < material->NumSubMtls(); j++ )
            {
                Mtl* submat = material->GetSubMtl ( j );

                if ( submat )
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

        if ( XRefFunctions::isXRefMaterial ( baseMaterial ) )
        {
            if ( mDocumentExporter->getOptions().getIncludeXRefs() )
            {
                // don't generate the FCDMaterial
				baseMaterial = XRefFunctions::getXRefMaterialSource( baseMaterial );
            }

            else
            {
				return ;
            }
        }


        EffectMap::iterator it = mEffectMap.find ( baseMaterial );

        if ( it != mEffectMap.end() )
        {
            exportNode->addSymbol ( baseMaterial, it->second );
            return ;
        }


		String materialName = NativeString(baseMaterial->GetName().data());
        // Add it to the exported materials list
        String effectId = mEffectIdList.addId ( materialName );

        exportNode->addSymbol ( baseMaterial, effectId );

        mEffectMap[ baseMaterial ] = effectId;

        mExportedEffectIdList->push_back ( EffectIdAndName(effectId, materialName) );

        openEffect ( effectId );

		setExtraTechnique(this);

		//COLLADASW::EffectProfile effectCommonProfile ( LibraryEffects::mSW );


        // Write out the custom attributes
        //  ExportCustomAttributes(baseMaterial, material);

        /// @TODO Handle other types of material properly
        // does the material have an HLSL profile?
        //bool itHasHardwareShader = false;
        IDxMaterial* dxm = static_cast<IDxMaterial*> ( baseMaterial->GetInterface( IDXMATERIAL_INTERFACE ) );

#ifdef MAX_2010_OR_NEWER
		const char* effectFileName = dxm ? dxm->GetEffectFile().GetFileName().data() : 0;
#else
		const char* effectFileName = dxm ? dxm->GetEffectFilename() : 0;
#endif


        if ( effectFileName && *effectFileName )
        {
            /*
            if ( baseMaterial->NumSubMtls() > 0 && baseMaterial->GetSubMtl( 0 ) )
            {
                // Create common profile
                Mtl * workingMaterial = baseMaterial->GetSubMtl ( 0 );
                //   ExportCustomAttributes(workingMaterial, material);
                //    exportCommonEffect((FCDEffectStandard*)matEffect->AddProfile(FUDaeProfileType::COMMON), workingMaterial);
                exportCommonEffect ( effectCommonProfile, exportNode, workingMaterial, effectId );
            }
            */

            // Create HLSL profile and add the effect instantiation elements
            COLLADASW::EffectProfile effectHLSLProfile ( LibraryEffects::mSW );

            COLLADASW::URI  shaderFxFileUri ( COLLADASW::URI::nativePathToUri ( effectFileName ) );
            effectHLSLProfile.setInclude ( shaderFxFileUri, shaderFxFileUri.getPathFileBase() );
            exportHLSLEffect ( effectHLSLProfile, exportNode, baseMaterial, effectId );
            //itHasHardwareShader = true;
        }

        //  else if (baseMaterial->ClassID() == COLLADASW_EFFECT_ID)
        //  {
        //   exportColladaEffect(material, (ColladaEffect*)baseMaterial);
        //  }

        else
        {
            // Create common profile
            COLLADASW::EffectProfile effectCommonProfile ( LibraryEffects::mSW );
            exportCommonEffect ( effectCommonProfile, exportNode, baseMaterial, effectId );
            addEffectProfile ( effectCommonProfile );

        }

        //addEffectProfile ( effectCommonProfile );
        
        //if ( itHasHardwareShader )
        //{
        //    effectHLSLProfile.openProfile ();
        //    effectHLSLProfile.addProfileElements ();

        //    exportEffectParameters ( shaderNode, cgEffect );

        //    // Find if effect parameter is used by any program of the selected technique
        //    CGtechnique cgTechnique = cgGetFirstTechnique ( cgEffect );
        //    while ( cgTechnique )
        //    {
        //        exportTechnique ( cgTechnique );
        //        cgTechnique = cgGetNextTechnique ( cgTechnique );
        //    }

        //    effectHLSLProfile.closeProfile ();
        //}

		addExtraTechniques(ElementWriter::mSW);

        closeEffect();

    }

    //---------------------------------------------------------------
    void EffectExporter::exportCommonEffect ( COLLADASW::EffectProfile & effectProfile, ExportNode* exportNode, Mtl* material, const String & effectId, float weight, bool inited )
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
    void logEffectParameters ( 
        Mtl* material 
        )
    {
        int numParamBlocks = material->NumParamBlocks();

        for ( int i = 0; i < numParamBlocks; i++ )
        {
            IParamBlock2 * pblock = material->GetParamBlock ( i );
            int parameterCount = pblock->NumParams();

            fprintf( stdout, "Param block = %i;\n", i );

            for ( int j = 0; j < parameterCount; j++ )
            {
                ParamID parameterID = pblock->IndextoID( j );
                ParamType2 parameterType = pblock->GetParameterType( parameterID );
                ParamDef parameterDef = pblock->GetParamDef( parameterID );

                const char* paramName = parameterDef.int_name;
                fprintf( stdout, "\tParam name = %s; Type = %i;\n", paramName, (int)parameterType );
            }
        }
    }

    void EffectExporter::exportHLSLEffect ( COLLADASW::EffectProfile & effectProfile, ExportNode* exportNode, Mtl* material, const String & effectId, float weight, bool inited )
    {
        // Export all submaterials first.
        int subMaterialCount = material->NumSubMtls();
        logEffectParameters( material );

        /*
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
                exportHLSLEffect ( effectProfile, exportNode, subMaterial, effectId, subMtlWeight, inited );
                inited = true;
            }
        }

        Class_ID materialId = material->ClassID();

        if ( materialId.PartA() == DMTL2_CLASS_ID || materialId.PartA() == DMTL_CLASS_ID )
        */
        {
            HwShaderExporter hwShaderExporter ( mDocumentExporter );
            hwShaderExporter.exportPluginHwShaderNode ( effectId, &effectProfile, exportNode, ( StdMat2* ) material, weight );
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportStandardEffect ( COLLADASW::EffectProfile & effectProfile, ExportNode* exportNode, StdMat2* material, const String & effectId, float weight, bool inited )
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
        exportNode->addSymbol ( material, NativeString(material->GetName().data()) );

        mEffectMap[ material ] = effectId;

        Shader* shader = material->GetShader();

        TimeValue animationStart = mDocumentExporter->getOptions().getAnimationStart();

        if ( !inited )
        {
            effectProfile.setShaderType ( maxShaderToShaderType ( shader->ClassID() ) );
        }

        // Retrieve the interesting parameter blocks
        IParamBlock2* shaderParameters = ( IParamBlock2* ) shader->GetReference ( 0 );

        IParamBlock2* extendedParameters = ( IParamBlock2* ) material->GetReference ( StandardMaterial::EXTENDED_PB_REF );

        TimeValue initTime = mDocumentExporter->getOptions().getAnimationStart();

        if ( !inited )
        {
			ScaleConversionFunctor scaleConversion(weight);

            // effectProfile.setShaderType(COLLADASW::EffectProfile::PHONG);
			bool isAmbientAnimated = mAnimationExporter->addAnimatedParameter(shaderParameters, ShaderParameterIndices::AMBIENT_COLOR, effectId, effectProfile.getAmbientDefaultSid(), COLOR_PARAMETERS, true, &scaleConversion);
            effectProfile.setAmbient ( maxColor2ColorOrTexture ( shader->GetAmbientClr ( animationStart ), weight ), isAmbientAnimated );

			bool isDiffuseAnimated = mAnimationExporter->addAnimatedParameter(shaderParameters, ShaderParameterIndices::DIFFUSE_COLOR, effectId, effectProfile.getDiffuseDefaultSid(), COLOR_PARAMETERS, true, &scaleConversion);
            effectProfile.setDiffuse ( maxColor2ColorOrTexture ( shader->GetDiffuseClr ( animationStart ), weight ), isDiffuseAnimated );

			effectProfile.setTransparent ( COLLADASW::ColorOrTexture ( COLLADASW::Color::WHITE ) );

			bool isOpacityAnimated = mAnimationExporter->addAnimatedParameter(extendedParameters, ExtendedParameterIndices::OPACITY, effectId, effectProfile.getSpecularDefaultSid(), COLOR_PARAMETERS);
            effectProfile.setTransparency ( material->GetOpacity ( animationStart ) * weight );

            effectProfile.setReflective ( COLLADASW::ColorOrTexture ( COLLADASW::Color::BLACK ) );

			bool isSpecularAnimated = mAnimationExporter->addAnimatedParameter(shaderParameters, ShaderParameterIndices::SPECULAR_COLOR, effectId, effectProfile.getSpecularDefaultSid(), COLOR_PARAMETERS, true, &scaleConversion);
			effectProfile.setSpecular ( maxColor2ColorOrTexture ( shader->GetSpecularClr ( animationStart ), weight ), isSpecularAnimated );

			bool isGlossinessAnimated = mAnimationExporter->addAnimatedParameter(shaderParameters, ShaderParameterIndices::GLOSSINESS, effectId, effectProfile.getShininessDefaultSid(), 0, true, &ConversionFunctors::toPercent);
			effectProfile.setShininess ( ConversionFunctors::toPercent(shader->GetGlossiness ( animationStart )) * weight, isGlossinessAnimated );

			bool useEmissionColor = shader->IsSelfIllumClrOn() != false;
			if (useEmissionColor)
			{
				bool isEmissionAnimated = mAnimationExporter->addAnimatedParameter(shaderParameters, ShaderParameterIndices::SELF_ILLUMINATION_COLOR, effectId, effectProfile.getEmissionDefaultSid(), COLOR_PARAMETERS, true, &scaleConversion);
				effectProfile.setEmission( maxColor2ColorOrTexture ( shader->GetSelfIllumClr ( animationStart ), weight ), isEmissionAnimated );
			}
			else
			{
				bool isEmissionAnimated = mAnimationExporter->addAnimatedParameter(shaderParameters, ShaderParameterIndices::SELF_ILLUMINATION_COLOR, effectId, effectProfile.getEmissionDefaultSid(), COLOR_PARAMETERS);
				effectProfile.setEmission( maxColor2ColorOrTexture ( shader->GetSelfIllumClr ( animationStart ) ), isEmissionAnimated );
			}

			addParamBlockAnimatedExtraParameters(SHADER_ELEMENT, SHADER_PARAMETERS, SHADER_PARAMETER_COUNT, shaderParameters, effectId);
			
			addParamBlockAnimatedExtraParameters(EXTENDED_SHADER_ELEMENT, EXTENDED_SHADER_PARAMETERS, EXTENDED_SHADER_PARAMETER_COUNT, extendedParameters, effectId);
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

       /*         if ( !material->GetSelfIllumColorOn() )     // Emission
                {
                    // emission factor
                    //    ANIM->ExportProperty(_T("self_illum_level"), shaderParameters, FSStandardMaterial::shdr_self_illum_amnt, 0, stdProfile->GetEmissionFactorParam()->GetValue(), NULL);
                    //TODO: check what this is good for
                    //stdProfile->SetIsEmissionFactor(true);
                    continue;
                }*/

                break;

            case TRANSPARENt:
                effectProfile.setOpaque ( getOpacity ( map ) );
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
                exportMap (material, channel, map, effectProfile, weight * mapAmount );
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportMap ( Mtl * material, unsigned int index, Texmap* texMap, COLLADASW::EffectProfile & profile, float weight )
    {
        if ( !texMap )
            return ;

        //if (weight <= 0) return;

        // Get any weight control directly on this texmap
        float amount = weight;

        Control* weightControl = 0;

        if ( texMap  && GetIBitmapTextInterface ( texMap ) != 0 )
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
		String fullFileName;
        String imageId = exportImage ( texMap, fullFileName );

        if ( !imageId.empty() )
        {
            COLLADASW::Texture texture ( imageId );

            // Create the sampler
            String samplerSid = imageId + COLLADASW::Sampler::SAMPLER_SID_SUFFIX;
            String surfaceSid = imageId + COLLADASW::Sampler::SURFACE_SID_SUFFIX;
            COLLADASW::Sampler sampler( COLLADASW::Sampler::SAMPLER_TYPE_2D, samplerSid, surfaceSid );
			sampler.setImageId( imageId );
			//sampler.setFormat( FORMAT );
            //texture.setSampler( sampler );

            int mapChannel = 1;

            if ( texMap )
            {
				mapChannel = texMap->GetMapChannel();

				UVGen* uvCoordinatesGenerator = texMap->GetTheUVGen();
				if (uvCoordinatesGenerator && uvCoordinatesGenerator->ClassID().PartA() == STDUV_CLASS_ID)
				{
					StdUVGen* uvGenParameters = (StdUVGen*)uvCoordinatesGenerator;
					int uvFlags = uvGenParameters->GetTextureTiling();
					
					sampler.setWrapS(COLLADASW::Sampler::WRAP_MODE_CLAMP);
					sampler.setWrapT(COLLADASW::Sampler::WRAP_MODE_CLAMP);

					if ( uvFlags & U_WRAP )
					{
						//Indicates the texture map is tiled in the U direction. 
						sampler.setWrapS(COLLADASW::Sampler::WRAP_MODE_WRAP);
					}
					if ( uvFlags & V_WRAP )
					{
						//Indicates the texture map is tiled in the V direction. 
						sampler.setWrapT(COLLADASW::Sampler::WRAP_MODE_WRAP);
					}
					if ( uvFlags & U_MIRROR )
					{
						//Indicates the texture map is mirrored in the U direction. 
						sampler.setWrapS(COLLADASW::Sampler::WRAP_MODE_MIRROR);
					}
					if ( uvFlags & V_MIRROR )
					{
						//Indicates the texture map is mirrored in the V direction. 
						sampler.setWrapT(COLLADASW::Sampler::WRAP_MODE_MIRROR);
					}

					IParamBlock* uvParams = (IParamBlock*)uvGenParameters->GetReference(StdUVGenEnums::pblock);	


					
/*
					float rotationAngle = uvParams->GetFloat(StdUVGenEnums::w_angle);

					String textureFileName;
					String textureDir;
					DocumentExporter::splitFilePath(fullFileName, textureDir, textureFileName);
					COLLADASW::TextureModifier textureModifier(fullFileName, mDocumentExporter->getOutputDir() + textureFileName);	
				
					textureModifier.setRotationAngle(rotationAngle);

					textureModifier.performModifications();
*/
					mMaterialChannelPairParamBlockMap[MaterialChannelPair(material, index)] = uvParams;

				}


                // TODO: add extra tag
            }
			
			texture.setSampler( sampler );

			String semantic = createTexcoordSementicFromMapchannel( mapChannel );

            texture.setTexcoord ( semantic );

            //TODO: extra tag

            switch ( index )
            {

            case AMBIENT:
                profile.setAmbient ( COLLADASW::ColorOrTexture ( texture ) );
                break;
			case DIFFUSE:
                profile.setDiffuse ( COLLADASW::ColorOrTexture ( texture ) );
                break;
            case SPECULAR:
                profile.setSpecular ( COLLADASW::ColorOrTexture ( texture ) );
                break;
			case SPECULAR_LEVEL: 
				texture.setProfileName(Extra::TECHNIQUE_PROFILE_3DSMAX);
				texture.setChildElementName("specularLevel");
				profile.addExtraTechniqueColorOrTexture(COLLADASW::ColorOrTexture(texture)); 
				break;
			case SHININESS:		// Glossiness
				texture.setProfileName(Extra::TECHNIQUE_PROFILE_3DSMAX);
				texture.setChildElementName("gloss");
				profile.addExtraTechniqueColorOrTexture(COLLADASW::ColorOrTexture(texture)); 
				break;
            case EMISSION:		// Self-illumination
                profile.setEmission ( COLLADASW::ColorOrTexture ( texture ) );
                break;
			case TRANSPARENt:		// Opacity
                profile.setTransparent ( COLLADASW::ColorOrTexture ( texture ) );
                break;
            case FILTER:
				texture.setProfileName(Extra::TECHNIQUE_PROFILE_3DSMAX);
				texture.setChildElementName("filter");
				profile.addExtraTechniqueColorOrTexture(COLLADASW::ColorOrTexture(texture)); 
				break;
			case BUMP: 
				{
					texture.setProfileName(Extra::TECHNIQUE_PROFILE_3DSMAX);
					texture.setChildElementName("bump");
					COLLADASW::EffectProfile::StringPairList attributes;
					attributes.push_back(std::make_pair(DAE_BUMP_TYPE_ATTRIBUTE, DAE_BUMP_TYPE_HEIGHTFIELD));
					profile.addExtraTechniqueColorOrTexture(COLLADASW::ColorOrTexture(texture), attributes); 
					break;
				}
			case REFLECTION: 
				profile.setReflective( COLLADASW::ColorOrTexture ( texture ) );
				break;
			case REFRACTION:
				texture.setProfileName(Extra::TECHNIQUE_PROFILE_3DSMAX);
				texture.setChildElementName("refraction");
				profile.addExtraTechniqueColorOrTexture(COLLADASW::ColorOrTexture(texture)); 
				break;
            case DISPLACEMENT: 
				texture.setProfileName(Extra::TECHNIQUE_PROFILE_3DSMAX);
				texture.setChildElementName("displacement");
				profile.addExtraTechniqueColorOrTexture(COLLADASW::ColorOrTexture(texture)); 
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

                exportMap (material, index, subMap, profile, subAmount );
            }
        }
    }

    //---------------------------------------------------------------
    void EffectExporter::exportUnknownEffect ( COLLADASW::EffectProfile & effectProfile, ExportNode* exportNode, Mtl* material, const String & effectId )
    {
        assert ( material != 0 );

        /* TODO: think about this*/

        if ( effectProfile.getShaderType() == COLLADASW::EffectProfile::UNSPECIFIED )
        {
            float specularLevel = material->GetShinStr();
            bool isPhong = specularLevel > 0.2f;
            effectProfile.setShaderType ( isPhong ? COLLADASW::EffectProfile::PHONG : COLLADASW::EffectProfile::BLINN );
        }

        if ( material->GetSelfIllumColorOn() && !effectProfile.getEmission().isValid() )
            effectProfile.setEmission ( maxColor2ColorOrTexture ( material->GetSelfIllumColor() ) );

        if ( !effectProfile.getAmbient().isValid() )
            effectProfile.setAmbient ( maxColor2ColorOrTexture ( material->GetAmbient() ) );

        if ( !effectProfile.getDiffuse().isValid() )
            effectProfile.setDiffuse ( maxColor2ColorOrTexture ( material->GetDiffuse() ) );


        if ( effectProfile.getShaderType() == COLLADASW::EffectProfile::PHONG )
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

        exportNode->addSymbol ( material, NativeString(material->GetName().data()) );

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
			setExtraTechnique(this);

			COLLADASW::EffectProfile effectProfile ( LibraryEffects::mSW );
            effectProfile.setShaderType ( COLLADASW::EffectProfile::PHONG );
            COLLADASW::Color commonColor ( GetRValue ( color ) / 255.0f, GetGValue ( color ) / 255.0f, GetBValue ( color ) / 255.0f );
            effectProfile.setAmbient ( COLLADASW::ColorOrTexture ( commonColor ) );
            effectProfile.setDiffuse ( COLLADASW::ColorOrTexture ( commonColor ) );
            effectProfile.setTransparent ( COLLADASW::ColorOrTexture ( COLLADASW::Color::WHITE ) );
            effectProfile.setTransparency ( 1.0 );
            effectProfile.setReflective ( COLLADASW::ColorOrTexture ( COLLADASW::Color::BLACK ) );
            effectProfile.setSpecular ( COLLADASW::ColorOrTexture ( COLLADASW::Color::WHITE ) );
            effectProfile.setShininess ( 10.0 );

            addEffectProfile ( effectProfile );

			addExtraTechniques(ElementWriter::mSW);

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
	COLLADASW::Color EffectExporter::maxColor2Color ( const Color & color, double scale )
	{
		return  COLLADASW::Color ( color.r * scale, color.g * scale, color.b * scale, scale );
	}


    //---------------------------------------------------------------
    COLLADASW::ColorOrTexture EffectExporter::maxColor2ColorOrTexture ( const Color & color, double scale )
    {
        return COLLADASW::ColorOrTexture ( maxColor2Color( color, scale ) );
    }

    //---------------------------------------------------------------
    EffectExporter::Channel EffectExporter::maxIdToEffectChannel ( StdMat2* material, int id )
    {
        assert ( material );

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
                String upperName = NativeString(subName.data());
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
    COLLADASW::EffectProfile::Opaque EffectExporter::getOpacity ( Texmap *texMap )
    {
        // Only one transparency factor is supported, so retrieve only the first texture from this bucket.

        if ( texMap == NULL )
            return COLLADASW::EffectProfile::A_ONE;

        BitmapTex* bmap = GetIBitmapTextInterface ( texMap );

        BOOL isAlphaTransparency = true;

        if ( bmap != NULL )
            isAlphaTransparency = bmap->GetAlphaAsMono ( TRUE );

        // As far as my tests are concerned, the only real way to get alpha-transparency is through
        // the mono-channel output as Alpha.
        return isAlphaTransparency ? COLLADASW::EffectProfile::A_ONE : COLLADASW::EffectProfile::RGB_ZERO;
    }

    //---------------------------------------------------------------
    COLLADASW::EffectProfile::ShaderType EffectExporter::maxShaderToShaderType ( Class_ID id )
    {
        switch ( id.PartA() )
        {

        case StandardMaterial::STD2_BLINN_SHADER_CLASS_ID:

        case StandardMaterial::STD2_OREN_NAYER_BLINN_CLASS_ID:

        case StandardMaterial::STD2_METAL_SHADER_CLASS_ID:
            return COLLADASW::EffectProfile::BLINN;

        case StandardMaterial::STD2_PHONG_CLASS_ID:
            return COLLADASW::EffectProfile::PHONG;

        default:
            return COLLADASW::EffectProfile::PHONG;
        }
    }

    //---------------------------------------------------------------
    String EffectExporter::exportImage ( Texmap* map, String& fullFileName  )
    {
        if ( !map  )
            return EMPTY_STRING;

        if ( map->ClassID() == Class_ID ( BMTEX_CLASS_ID, 0x00 ) )
        {
            BitmapTex * baseBitmap = ( BitmapTex* ) map;

            if ( !baseBitmap )
                return EMPTY_STRING;

            // get a valid filename
            BitmapInfo bitmapInfo;

            bitmapInfo.SetName ( baseBitmap->GetMapName() );

            return exportImage ( bitmapInfo, fullFileName );
        }

        else if ( map->ClassID() == Class_ID ( MIX_CLASS_ID, 0x00 ) )
        {
            return EMPTY_STRING;
        }

        // not recognized
        return EMPTY_STRING;
    }

    //---------------------------------------------------------------
    String EffectExporter::exportImage ( BitmapInfo& bitmapInfo, String& fullFileName )
    {
		const TCHAR * fileNamePtr = bitmapInfo.Name();

		String fileName;
		if ( fileNamePtr )
			fileName = NativeString(fileNamePtr);

		static const String noneString("none"); 
		if ( !fileName.empty() && !StringUtils::equals(fileName, noneString) )
        {

            BMMGetFullFilename ( &bitmapInfo );
            NativeString fullNativeFileName  = NativeString(bitmapInfo.Name());
			fullFileName = fullNativeFileName;
			COLLADABU::URI fullFileNameURI = URI::nativePathToUri( fullNativeFileName.toUtf8String() );
			if ( fullFileNameURI.getScheme().empty() )
				fullFileNameURI.setScheme(COLLADASW::URI::SCHEME_FILE);

            // Export the equivalent <image> node in the image library and add
            // the <init_from> element to the sampler's surface definition.
            // "None" is a special Max token, to indicate no texture assigned
            ExportedImageMap::iterator it = mExportedImageMap.find ( fullFileNameURI );

            if ( it == mExportedImageMap.end() )
            {
                // generate an interesting name: strip the filename away from the filepath.
                size_t slashIndex = fullFileName.rfind ( '/' );
                size_t backSlashIndex = fullFileName.rfind ( '\\' );

				ImageInfo imageInfo;

				if ( slashIndex == String::npos )
                    slashIndex = backSlashIndex;
                else if ( backSlashIndex != String::npos && backSlashIndex > slashIndex )
                    slashIndex = backSlashIndex;

                imageInfo.imageId = ( slashIndex != String::npos ) ? fullFileName.substr ( slashIndex + 1 ) : fullFileName;

				imageInfo.imageId = COLLADASW::Utils::replaceDot ( COLLADASW::Utils::checkID(imageInfo.imageId) );

				if ( mDocumentExporter->getOptions().getCopyImages() )
				{
					// we need to copy the image in  output directory/images
					COLLADASW::URI imageTargetPath = createTargetURI(fullFileNameURI);
					// Copy the texture, if it isn't already there...
					if ( !boost::filesystem::exists( imageTargetPath.toNativePath () ) )
					{
						try 
						{
							// Create the target directory, if necessary. 
							// Note: some systems (window$) requires the string to be 
							// enclosed in quotes when a space is present.
							COLLADASW::URI imageTargetPathDir ( imageTargetPath.getPathDir() );
							boost::filesystem::create_directory ( imageTargetPathDir.toNativePath() );

							// Throws: basic_filesystem_error<Path> if
							// from_fp.empty() || to_fp.empty() ||!exists(from_fp) || !is_regular(from_fp) || exists(to_fp)
							boost::filesystem::copy_file ( boost::filesystem::path ( fullFileNameURI.toNativePath() ), 
								                           boost::filesystem::path ( imageTargetPath.toNativePath() ) );
						}
						catch ( ... )
						{
							// todo handle error
						}
					}

					if ( mDocumentExporter->getOptions().getExportRelativePaths() )
					{
						bool success = true;
						imageInfo.fileLocation = imageTargetPath.getRelativeTo(mDocumentExporter->getOutputFileUri(),success, true);
					}
					else
					{
						imageInfo.fileLocation = imageTargetPath;
					}
				}
				else
				{
					if ( mDocumentExporter->getOptions().getExportRelativePaths() )
					{
						bool success = true;
						imageInfo.fileLocation = fullFileNameURI.getRelativeTo(mDocumentExporter->getOutputFileUri(),success, true);
					}
					else
					{
						imageInfo.fileLocation = fullFileNameURI;
					}
				}

                // image not exported
                mExportedImageMap[ fullFileNameURI ] = imageInfo;
				return imageInfo.imageId;
            }
            else
			{
                return it->second.imageId;
			}

        }

        return EMPTY_STRING;
    }

	// ------------------------------------------------------------
	COLLADASW::URI EffectExporter::createTargetURI ( const COLLADASW::URI& sourceUri )
	{
		// Target file
		const COLLADABU::URI& outputFile = mDocumentExporter->getOutputFileUri();
		
		String relativePath = mDocumentExporter->getOptions().getImageDirectory();
		relativePath.append("/");
		relativePath.append( sourceUri.getPathFile() );

		COLLADASW::URI targetUri ( outputFile, relativePath);

		// Get the pure file name of the source file and set 
		// the source file name to the target path
//		targetUri.setPathFile ( sourceUri.getPathFile () );
		targetUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

		// Generate the target file name
		return targetUri;
	}


    //---------------------------------------------------------------
    void EffectExporter::blendColor ( COLLADASW::ColorOrTexture & colorOrTexture, Color blendColor, double ammount )
    {
        if ( colorOrTexture.isColor() )
        {
            COLLADASW::Color & color = colorOrTexture.getColor();

            color.set ( color.getRed() + ( blendColor[ 0 ] - color.getRed() ) * ammount,
                        color.getGreen() + ( blendColor[ 1 ] - color.getGreen() ) * ammount,
                        color.getBlue() + ( blendColor[ 2 ] - color.getBlue() ) * ammount,
                        color.getAlpha()
                      );
        }
    }



	bool EffectExporter::MaterialChannelPair::operator<( const EffectExporter::MaterialChannelPair & rhs ) const
	{
		if ( mMaterial < rhs.mMaterial )
			return true;
		if ( mMaterial > rhs.mMaterial )
			return false;

		if ( mChannel < rhs.mChannel )
			return true;
		if ( mChannel > rhs.mChannel )
			return false;

		return false;
	}
}
