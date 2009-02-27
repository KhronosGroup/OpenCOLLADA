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

    public:

        typedef std::map<COLLADAFW::UniqueId, MayaDM::Lambert*> UniqueIdLambertMap;

    private:

        /**
         * The enumeration of valid shader attributes. 
         * We need this for the connections of the effect attributes to textures.
         */
        enum ShaderAttribute
        {
            ATTR_COLOR, 
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
        struct TextureAttribute
        {
            MayaDM::Lambert* mShaderNode;
            ShaderType mShaderType;
            ShaderAttribute mShaderAttribute;
        };

    private:

        typedef std::map<COLLADAFW::SamplerID, std::vector<TextureAttribute>> SamplerIdShaderNodesMap;

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
         * The map holds for every unique image id the list of placed2dTextures, which use this image.
         */
        // TODO Push the texure placement in the list of texture placements of the image.
        struct TexturePlacement
        {
            COLLADAFW::UniqueId mImageId;
            size_t mSamplerId;
            COLLADAFW::Sampler::SamplerType mSamplerType;
            MayaDM::DependNode* mTexturePlacementNode;
        };
        std::vector<TexturePlacement*> mTexturePlacements;

        /**
         * The map holds for every sampler id the shader node attributes, 
         * which use this sampler image file.
         */
        SamplerIdShaderNodesMap mSamplerIdShaderNodesMap;

    public:

        /** Constructor. */
		EffectImporter ( DocumentImporter* documentImporter );

        /** Destructor. */
		virtual ~EffectImporter ();

        /** Imports the given material. */
        bool importEffect ( const COLLADAFW::Effect* effect );

        /**
         * Writes the connections of the effect texture placements to the image files.  
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

	private:

        /**
        * Import shader data by type.
        */
        void importShaderData ( 
            const COLLADAFW::EffectCommon* commonEffect, 
            const COLLADAFW::Effect* effect );

        /**
        * Create the texture placement and push it to the image in a map.
        */
        void importTexturePlacement ( const COLLADAFW::EffectCommon* commonEffect );

        /**
        * The map holds the maya material objects.
        */
        void appendEffect ( const COLLADAFW::UniqueId& efefctId, MayaDM::Lambert* effectNode );

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
            const COLLADAFW::EffectCommon* commonEffect );

        /**
        * Imports the shader attributes.
        */
        void importReflectShaderAttributes ( 
            const ShaderType& shaderType, 
            MayaDM::Reflect* shaderNode, 
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
            const COLLADAFW::Texture &texture, 
            const ShaderType& shaderType, 
            const ShaderAttribute& shaderAttribute, 
            MayaDM::Lambert* shaderNode );

        /** Disable default copy ctor. */
		EffectImporter( const EffectImporter& pre );

        /** Disable default assignment operator. */
		const EffectImporter& operator= ( const EffectImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_EFFECTIMPORTER_H__
