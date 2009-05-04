/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_EFFECTIMPORTER_H__
#define __COLLADAMAYA_EFFECTIMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"
#include "COLLADAMayaEffectAnimation.h"

#include "COLLADABUIDList.h"

#include "COLLADAFWEffectCommon.h"
//#include "COLLADAFWFloatOrParam.h"

#include "MayaDMLambert.h"
#include "MayaDMBlinn.h"
#include "MayaDMPhong.h"
#include "MayaDMFile.h"


namespace COLLADAMaya
{

    /** TODO Documentation */
	class EffectImporter : public BaseImporter
    {
    public:
	
        /** The standard name for the collada id attribute. */
        static const String COLLADA_EFFECT_ID_ATTRIBUTE_NAME;

        /** The standard name for the collada id attribute. */
        static const String COLLADA_MATERIAL_ID_ATTRIBUTE_NAME;

        /** The standard name for the collada id attribute. */
        static const String COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME;

    private:

        /** The standard name for a effect without name. */
        static const String EFFECT_NAME;

        /** The default initial effect name. */
        static const String INITIAL_DEFAULT_EFFECT_NAME;

        /** The standard name for a place2dTexture. */
        static const String PLACE_2D_TEXTURE_NAME;

        /** The standard name for a place2dTexture. */
        static const String PLACE_3D_TEXTURE_NAME;

        /** The name of the default texture list. */
        static const String DEFAULT_TEXTURE_LIST;

    public:

        /**
         * The enumeration of valid shader attributes. 
         * We need this for the connections of the effect attributes to textures.
         */
        enum ShaderAttribute
        {
            ATTR_COLOR, 
            ATTR_AMBIENT, 
            ATTR_INCANDESCENE,
            ATTR_TRANSPARENT,
            ATTR_REFLECTIVE,
            ATTR_SPECULAR,
            ATTR_UNKNOWN
        };

        /**
         * The maya shader type of the current effect.
         */
        enum ShaderType
        {
            SHADER_LAMBERT, 
            SHADER_BLINN,
            SHADER_PHONG,
            SHADER_UNKNOWN
        };

        /**
         * This struct holds the attribute of an effect. 
         * The type of the effect depends on the attribute. 
         * It's either an lambert, blinn or phong shader.
         */
        struct ShaderNodeAttribute
        {
            size_t mSamplerId;
            MayaDM::Lambert* mShaderNode;
            ShaderType mShaderType;
            ShaderAttribute mShaderAttribute;
        };

        /**
         * Texture placement infos.
         */
        struct TexturePlacement
        {
            COLLADAFW::UniqueId mImageId;
            size_t mSamplerId;
            COLLADAFW::Sampler::SamplerType mSamplerType;
            MayaDM::DependNode* mTexturePlacementNode;
        };

        /**
         * Sampler infos.
         */
        struct SamplerInfo
        {
            COLLADAFW::SamplerID mSamplerId;
            COLLADAFW::UniqueId mImageId;
        };

    public:

        typedef std::map< COLLADAFW::UniqueId, std::vector<ShaderNodeAttribute> > UniqueIdShaderNodesMap;

        typedef std::vector<SamplerInfo> SamplerInfos;
        typedef std::map< COLLADAFW::UniqueId, SamplerInfos > UniqueIdSamplerInfosMap;

        typedef std::pair<COLLADAFW::UniqueId,size_t> UniqueIdSamplerIdPair;
        typedef std::vector<TexturePlacement> TexturePlacements;
        typedef std::map< UniqueIdSamplerIdPair, TexturePlacements > TexturePlacementsMap;

        typedef std::map<COLLADAFW::UniqueId, EffectAnimation> EffectAnimationMap;

    private:

        /**
        * The list of the unique maya effect names.
        */
        COLLADABU::IDList mEffectIdList;

        /**
        * The list with the unique maya place2dtexture names.
        */
        COLLADABU::IDList mPlace2dTextureIdList;

        /**
        * The map holds the maya effect objects for everx effect id. Used to make the connections.
        * There can be multiple maya effect objects for one effect id, about a collada effect can 
        * be referenced by multiple materials and for every referenced effect will be one maya
        * effect object created.
        */
        UniqueIdMayaEffectsMap mMayaEffectsMap;

        /**
        * The map holds the unique material ids of a effect id.
        */
        UniqueIdUniqueIdsMap mEffectIdMaterialIdsMap;

        /**
         * The map holds for every unique image id the list of placed2dTextures, which use this image.
         */
        TexturePlacementsMap mTexturePlacementsMap;

        /**
         * The map holds for every effect the shader node attributes with the sampler image file.
         */
        UniqueIdShaderNodesMap mEffectShaderNodesMap;

        /**
         * Holds for every effect a list with sampler infos.
         */
        UniqueIdSamplerInfosMap mEffectSamplerInfosMap;

        /**
         * The map holds for every animation id the information about the animated effect element.
         */
        EffectAnimationMap mEffectAnimationMap;

    public:

        /** Constructor. */
		EffectImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~EffectImporter ();

        /** Imports the given material. */
        bool importEffect ( const COLLADAFW::Effect* effect );

        /**
         * Write the connections between files and defaultTextureList and effects.
         */
        void writeConnections ();

        /**
        * The map holds the maya effect objects.
        */
        const MayaEffectList* findMayaEffects ( const COLLADAFW::UniqueId& effectId ) const;

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdMayaEffectsMap& getMaterialIdMayaEffectMap () const { return mMayaEffectsMap; }

        /**
        * Assigns the given material to the current effect.
        */
        void assignMaterial ( const COLLADAFW::UniqueId& effectId, const COLLADAFW::UniqueId& materialId );

        /**
        * The map holds for every animation id the information about the animated effect element.
        */
        const EffectAnimation* findEffectAnimation ( const COLLADAFW::UniqueId& animationListId );

	private:

        /**
        * Import shader data by type.
        */
        void importShaderData ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect, 
            const COLLADAFW::UniqueId& materialId );

        /**
         * Adds the attributes with the original collada ids.
         */
        void addOriginalColladaIds ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::UniqueId& materialId, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Create the texture placement and push it to the image in a map.
        */
        void importTexturePlacement ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * The map holds the maya material objects.
        */
        void appendMayaEffect ( 
            const COLLADAFW::UniqueId& materialId, 
            MayaDM::Lambert* effectNode );

        /**
         * Imports a blinn shader effect.
         */
        String importBlinnShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect, 
            const COLLADAFW::UniqueId& materialId );

        /**
        * Imports a phong shader effect.
        */
        String importPhongShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect, 
            const COLLADAFW::UniqueId& materialId );

        /**
        * Imports a lambert shader effect.
        */
        String importLambertShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect, 
            const COLLADAFW::UniqueId& materialId );

        /**
        * Imports the shader attributes.
        */
        void importStandardShaderAttributes ( 
            MayaDM::Lambert* shaderNode,
            const COLLADAFW::Effect* effect );

        /**
        * Imports the shader attributes.
        */
        void importLambertShaderAttributes ( 
            const ShaderType& shaderType, 
            MayaDM::Lambert* shaderNode,
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports the shader attributes.
        */
        void importReflectShaderAttributes ( 
            const ShaderType& shaderType, 
            MayaDM::Reflect* shaderNode, 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports the shader attributes.
        */
        void importBlinnShaderAttributes ( 
            MayaDM::Blinn* shaderNode, 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports the shader attributes.
        */
        void importPhongShaderAttributes ( 
            MayaDM::Phong* shaderNode, 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
         * Create a shader node attribute and append it on the list of shader node attributes 
         * to the current sampler file id.
         */
        void appendTextureAttribute ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::Texture& texture, 
            const ShaderType& shaderType, 
            const ShaderAttribute& shaderAttribute, 
            MayaDM::Lambert* shaderNode );

        /**
        * The map holds the unique material id to a effect id.
        */
        const UniqueIdVec* findMaterialId ( const COLLADAFW::UniqueId& effectId );

        /**
        * The map holds for every effect the shader node attributes with the sampler image file.
        */
        const UniqueIdShaderNodesMap& getEffectShaderNodesMap () const { return mEffectShaderNodesMap; }

        /**
        * Returns the effect's sampler infos list.
        */
        const SamplerInfos* findEffectSamplerInfos ( const COLLADAFW::UniqueId& effectId );

        /**
        * The map holds for every unique image id the list of placed2dTextures, which use this image.
        */
        TexturePlacements* findTexturePlacements ( const UniqueIdSamplerIdPair& key );

        /**
        * Writes the connections of the effect texture placements to the image files.  
        */
        void connectTexturePlacements ();

        /**
        * Writes the connections of the textures to the effects.  
        */
        void connectTextures ();

        /**
        * Connects the image file with the shader node attribute.
        */
        void connectTextureAttribute ( 
            const EffectImporter::ShaderNodeAttribute& shaderNodeAttribute, 
            const MayaDM::File* imageFile );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_EFFECTIMPORTER_H__
