/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaEffectImporter.h"

#include "MayaDMLambert.h"
#include "MayaDMBlinn.h"
#include "MayaDMPhong.h"

#include "COLLADAFWEffect.h"


namespace COLLADAMaya
{

    const String EffectImporter::EFFECT_NAME = "Effect";

    //------------------------------
	EffectImporter::EffectImporter ( DocumentImporter* documentImporter )
        : BaseImporter ( documentImporter )
	{}
	
    //------------------------------
	EffectImporter::~EffectImporter()
	{
        {
            UniqueIdDependNodeMap::iterator it = mMayaEffectMap.begin ();
            while ( it != mMayaEffectMap.end () )
            {
                MayaDM::DependNode* dependNode = it->second;
                delete dependNode;
                ++it;
            }
        }
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
            const COLLADAFW::EffectCommon::ShaderType& shaderType = commonEffect->getShaderType ();
            switch ( shaderType )
            {
            case COLLADAFW::EffectCommon::SHADER_BLINN:
                importBlinnShader ( effect, commonEffect );
                break;
            case COLLADAFW::EffectCommon::SHADER_CONSTANT:
                // TODO
                break;
            case COLLADAFW::EffectCommon::SHADER_PHONG:
                importPhongShader ( effect, commonEffect );
                break;
            case COLLADAFW::EffectCommon::SHADER_LAMBERT:
                importLambertShader ( effect, commonEffect );
                break;
            case COLLADAFW::EffectCommon::SHADER_UNKNOWN:
            default:
                // Standard shader (lambert?)
                break;
            }
        }

        return true;
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
        importShaderAttributes ( blinn, effect, commonEffect );

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
        importShaderAttributes ( phong, effect, commonEffect );

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
        importShaderAttributes ( lambert, effect, commonEffect );

        // Push it into the map.
        appendEffect ( effectId, lambert );
    }

    // --------------------------
    MayaDM::DependNode* EffectImporter::findMayaEffect ( const COLLADAFW::UniqueId& val ) const
    {
        UniqueIdDependNodeMap::const_iterator it = mMayaEffectMap.find ( val );
        if ( it != mMayaEffectMap.end () )
        {
            return it->second;
        }
        return 0;
    }

    // --------------------------
    void EffectImporter::appendEffect ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* effectNode )
    {
        mMayaEffectMap [id] = effectNode;
    }


} // namespace COLLADAMaya
