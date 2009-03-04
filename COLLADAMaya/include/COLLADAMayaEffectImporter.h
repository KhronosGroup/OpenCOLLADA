/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_EFFECTIMPORTER_H__
#define __COLLADAMAYA_EFFECTIMPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaBaseImporter.h"

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
    private:
	
        /** The standard name for a effect without name. */
        static const String EFFECT_NAME;

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

        typedef std::map<COLLADAFW::UniqueId, std::vector<ShaderNodeAttribute>> UniqueIdShaderNodesMap;

        typedef std::map<COLLADAFW::UniqueId, MayaDM::Lambert*> UniqueIdLambertMap;

        typedef std::vector<SamplerInfo> SamplerInfos;
        typedef std::map<COLLADAFW::UniqueId, SamplerInfos> UniqueIdSamplerInfosMap;

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
        * The map holds the unique ids of the nodes to the maya effect name. 
        */
        UniqueIdNamesMap mMayaEffectNamesMap;

        /**
        * The map holds the maya effect objects for the connections.
        */
        UniqueIdLambertMap mMayaEffectMap;

        /**
        * The map holds the unique material id to a effect id.
        */
        UniqueIdUniqueIdMap mEffectIdMaterialIdMap;

        /**
         * The map holds for every unique image id the list of placed2dTextures, which use this image.
         */
        std::vector<TexturePlacement*> mTexturePlacements;

        /**
         * The map holds for every effect the shader node attributes with the sampler image file.
         */
        UniqueIdShaderNodesMap mEffectShaderNodesMap;

        /**
         * Holds for every effect a list with sampler infos.
         */
        UniqueIdSamplerInfosMap mEffectSamplerInfosMap;

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
        * The map holds the maya material objects.
        */
        MayaDM::Lambert* findMayaEffect ( const COLLADAFW::UniqueId& effectId ) const;

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdLambertMap& getMayaEffectMap () const { return mMayaEffectMap; }

        /**
        * Assigns the given material to the current effect.
        */
        void assignMaterial ( const COLLADAFW::UniqueId& effectId, const COLLADAFW::UniqueId& materialId );

	private:

        /**
        * Import shader data by type.
        */
        void importShaderData ( 
            const COLLADAFW::Effect* effect, 
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
        void appendEffect ( const COLLADAFW::UniqueId& effectId, MayaDM::Lambert* effectNode );

        /**
         * Imports a blinn shader effect.
         */
        void importBlinnShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports a phong shader effect.
        */
        void importPhongShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports a lambert shader effect.
        */
        void importLambertShader ( 
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect );

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
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports the shader attributes.
        */
        void importPhongShaderAttributes ( 
            MayaDM::Phong* shaderNode, 
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
        const COLLADAFW::UniqueId* findMaterialId ( const COLLADAFW::UniqueId& effectId );

        /**
        * The map holds for every effect the shader node attributes with the sampler image file.
        */
        const UniqueIdShaderNodesMap& getEffectShaderNodesMap () const { return mEffectShaderNodesMap; }

        /**
        * Returns the effect's sampler infos list.
        */
        const SamplerInfos* findEffectSamplerInfos ( const COLLADAFW::UniqueId& effectId );

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
