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


namespace COLLADAMaya
{

    /** TODO Documentation */
	class EffectImporter : public BaseImporter
    {
    private:
	
        /** The standard name for a effect without name. */
        static const String EFFECT_NAME;

        /**
         * The enumeration of valid shader attributes. 
         * We need this for the connections of the effect attributes to textures.
         */
        enum ShaderAttribute
        {
            ATTR_COLOR, 
            ATTR_INCANDESCENE,
            ATTR_TRANSPARENCY,
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
            MayaDM::DependNode* mShaderNode;
            ShaderType mShaderType;
            ShaderAttribute mShaderAttribute;
        };

    private:

        typedef std::map<COLLADAFW::SamplerID, std::vector<ShaderNodeAttribute>> SamplerIdShaderNodesMap;

    private:

        /**
        * The list of the unique maya effect names.
        */
        COLLADABU::IDList mEffectIdList;

        /** 
        * The map holds the unique ids of the nodes to the maya effect name. 
        */
        UniqueIdNamesMap mMayaEffectNamesMap;

        /**
        * The map holds the maya effect objects for the connections.
        */
        UniqueIdDependNodeMap mMayaEffectMap;

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
        * The map holds the maya material objects.
        */
        MayaDM::DependNode* findMayaEffect ( const COLLADAFW::UniqueId& val ) const;

        /**
        * The map holds the maya material objects.
        */
        const UniqueIdDependNodeMap& getMayaEffectMap () const { return mMayaEffectMap; }

	private:

        /**
        * The map holds the maya material objects.
        */
        void appendEffect ( const COLLADAFW::UniqueId& id, MayaDM::DependNode* effectNode );

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
        template<class T>
        void importShaderAttributes ( 
            const ShaderType& shaderType, 
            T* shaderNode,
            const COLLADAFW::Effect* effect, 
            const COLLADAFW::EffectCommon* commonEffect )
        {
            // --------------------
            // Get the color and set it into the shader node (if it is a valid color).
            const COLLADAFW::Color& standardColor = effect->getStandardColor ();
            if ( standardColor.isValid () )
            {
                shaderNode->setColor ( MayaDM::float3 ( (float)standardColor.getRed (), (float)standardColor.getGreen (), (float)standardColor.getBlue ()) );
            }

            // --------------------
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
                appendShaderNodeAttribute ( texture, shaderType, shaderAttribute, shaderNode );
            }


            // --------------------
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
                appendShaderNodeAttribute ( texture, shaderType, shaderAttribute, shaderNode );
            }

            // --------------------
            // TODO 
            const COLLADAFW::FloatOrParam& indexOfRefraction = commonEffect->getIndexOfRefraction ();
            shaderNode->setRefractiveIndex ( indexOfRefraction );

            // --------------------
            const COLLADAFW::ColorOrTexture& reflective = commonEffect->getReflective ();
            if ( reflective.isColor () )
            {
                // Get the color and set it into the shader node (if it is a valid color).
                const COLLADAFW::Color& color = reflective.getColor ();
                // TODO
            }

            // --------------------
            // TODO
            {
                const COLLADAFW::FloatOrParam& reflectivity = commonEffect->getReflectivity ();
//                 const COLLADAFW::FloatOrParam::Type& type = reflectivity.getType ();
//                 switch ( type )
//                 {
//                 case COLLADAFW::FloatOrParam::FLOAT:
//                     break;
//                 case COLLADAFW::FloatOrParam::PARAM:
//                     break;
//                 default:
//                     MGlobal::displayError ( "Unknown param type!" );
//                     std::cerr << "Unknown param type!" << endl;
//                     break;
//                 }
            }

            // --------------------
            // TODO Not on lambert shader! Just phong and blinn!
            const COLLADAFW::FloatOrParam& shininess = commonEffect->getShininess ();

            // --------------------
            // TODO Not on lambert shader! Just phong and blinn!
            const COLLADAFW::ColorOrTexture& specular = commonEffect->getSpecular ();
            if ( specular.isColor () )
            {
                // Get the color and set it into the shader node (if it is a valid color).
                const COLLADAFW::Color& color = specular.getColor ();
                // TODO
            }

            // --------------------
            // TODO
            const COLLADAFW::FloatOrParam& transparency = commonEffect->getTransparency ();

            // --------------------
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
                ShaderAttribute shaderAttribute = ATTR_INCANDESCENE;

                // Create a shader node attribute and append it on the list of shader node 
                // attributes to the current sampler file id.
                appendShaderNodeAttribute ( texture, shaderType, shaderAttribute, shaderNode );
            }
        }

        /**
         * Create a shader node attribute and append it on the list of shader node attributes 
         * to the current sampler file id.
         */
        void appendShaderNodeAttribute ( 
            const COLLADAFW::Texture &texture, 
            const ShaderType& shaderType, 
            const ShaderAttribute& shaderAttribute, 
            MayaDM::DependNode* shaderNode );

        /** Disable default copy ctor. */
		EffectImporter( const EffectImporter& pre );

        /** Disable default assignment operator. */
		const EffectImporter& operator= ( const EffectImporter& pre );

	};

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_EFFECTIMPORTER_H__
