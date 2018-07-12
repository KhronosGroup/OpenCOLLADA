/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_EFFECTIMPORTER_H__
#define __DAE2MA_EFFECTIMPORTER_H__

#include "DAE2MAStableHeaders.h"
#include "DAE2MABaseImporter.h"
#include "DAE2MAEffectAnimation.h"

#include "COLLADAFWEffectCommon.h"
#include "COLLADAFWFloatOrParam.h"

#include "MayaDMLambert.h"
#include "MayaDMBlinn.h"
#include "MayaDMPhong.h"
#include "MayaDMFile.h"
#include "MayaDMPlace2dTexture.h"


namespace DAE2MA
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
        * This struct holds the sampler informations, the texture placement informations and 
        * the attribute of an effect. The type of the effect depends on the attribute. 
        * It's either an lambert, blinn or phong shader.
        */
        struct TextureInfo
        {
        private:
            COLLADAFW::UniqueId mEffectId;
            COLLADAFW::SamplerID mSamplerId;
            COLLADAFW::Sampler::SamplerType mSamplerType;
            COLLADAFW::UniqueId mImageId;
            MayaDM::File mImageNode;
            MayaDM::Lambert mShaderNode;
            ShaderType mShaderType;
            ShaderAttribute mShaderAttribute;
            COLLADAFW::TextureMapId mTextureMapId;
            MayaDM::Place2dTexture mTexturePlacementNode;

        public:
            TextureInfo () {}
            virtual ~TextureInfo () {}

            const COLLADAFW::UniqueId& getEffectId () const { return mEffectId; }
            void setEffectId ( const COLLADAFW::UniqueId& val ) { mEffectId = val; }

            const COLLADAFW::SamplerID& getSamplerId () const { return mSamplerId; }
            void setSamplerId ( const COLLADAFW::SamplerID& val ) { mSamplerId = val; }

            const COLLADAFW::Sampler::SamplerType& getSamplerType () const { return mSamplerType; }
            void setSamplerType ( const COLLADAFW::Sampler::SamplerType& val ) { mSamplerType = val; }

            const COLLADAFW::UniqueId& getImageId () const { return mImageId; }
            void setImageId ( const COLLADAFW::UniqueId& val ) { mImageId = val; }

            const MayaDM::File& getImageNode () const { return mImageNode; }
            void setImageNode ( const MayaDM::File val ) { mImageNode = val; }

            const MayaDM::Lambert& getShaderNode () const { return mShaderNode; }
            void setShaderNode ( const MayaDM::Lambert val ) { mShaderNode = val; }

            const EffectImporter::ShaderType& getShaderType () const { return mShaderType; }
            void setShaderType ( const EffectImporter::ShaderType& val ) { mShaderType = val; }

            const EffectImporter::ShaderAttribute& getShaderAttribute () const { return mShaderAttribute; }
            void setShaderAttribute ( const EffectImporter::ShaderAttribute& val ) { mShaderAttribute = val; }

            const COLLADAFW::TextureMapId& getTextureMapId () const { return mTextureMapId; }
            void setTextureMapId ( const COLLADAFW::TextureMapId& val ) { mTextureMapId = val; }

            const MayaDM::Place2dTexture& getTexturePlacementNode () const { return mTexturePlacementNode; }
            void setTexturePlacementNode ( const MayaDM::Place2dTexture val ) { mTexturePlacementNode = val; }
        };

    public:

        typedef std::map< COLLADAFW::UniqueId, std::vector<TextureInfo> > UniqueIdTextureInfosMap;

        typedef std::map<COLLADAFW::UniqueId, EffectAnimation> EffectAnimationMap;

    private:

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
         * The map holds for every effect the shader node attributes with the sampler image file.
         */
        UniqueIdTextureInfosMap mEffectTextureInfosMap;

        /**
         * The map holds for every animation id the information about the animated effect element.
         */
        EffectAnimationMap mEffectAnimationMap;

        /**
         * The list contains all image ids, which are already connected to the default texture list.
         */
        std::vector<String> mDefaultTextureImageList;

        /** 
         * Store the materialId of the materialInfo with the imageId of the file 
         * in a list of connected elements, to avoid dublicate connections between them.
         */
        std::map<COLLADAFW::UniqueId, std::vector<String> > mMaterialImagesMap;

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

        /**
        * The map holds for every effect the shader node attributes with the sampler image file.
        */
        UniqueIdTextureInfosMap& getTextureInfosMap () { return mEffectTextureInfosMap; }

        /**
        * The map holds for every effect the shader node attributes with the sampler image file.
        */
        std::vector<TextureInfo>* findTextureInfos ( const COLLADAFW::UniqueId& effectId );

        /**
        * The map holds for every effect the shader node attributes with the sampler image file.
        */
        const TextureInfo* findTextureInfo ( 
            const COLLADAFW::UniqueId& effectId, 
            const COLLADAFW::TextureMapId& textureMapId );


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
        void createTexturePlacements ( 
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
        void appendTextureInfo ( 
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
            const EffectImporter::TextureInfo& shaderNodeAttribute, 
            const MayaDM::File* imageFile );

        /**
         * Check if the image is already in the list of the connected images.
         */
        const bool isDefaultTextureConnected ( const String& imageName ) const;

        /** 
        * Store the imageId of the file with the materialId of the materialInfo 
        * in a list of connected elements, to avoid dublicate connections between them.
        */
        const bool isMaterialConnected (
            const COLLADAFW::UniqueId& materialId, 
            const String& imageName );

	};

} // namespace DAE2MA

#endif // __DAE2MA_EFFECTIMPORTER_H__
