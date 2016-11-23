/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_EFFECT_EXPORTER_H__
#define __COLLADA_MAYA_EFFECT_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneElement.h"
#include "COLLADAMayaMaterialExporter.h"
#include "COLLADAMayaEffectTextureExporter.h"

#include <map>

#include "COLLADASWStreamWriter.h"
#include "COLLADASWEffectProfile.h"
#include "COLLADASWLibraryEffects.h"

#include "COLLADABUIDList.h"

#include "COLLADASaxFWLLibraryEffectsLoader.h"

#include <maya/MObject.h>

namespace COLLADAMaya
{

#ifdef BLINN_EXPONENT_MODEL

    class BlinnEccentricityToShininess : public ConversionFunctor
    {

    public:
        virtual float operator() ( float v )
        {
            return 100.0f - 99.0f * sqrtf ( v );
        }
    };

    class BlinnShininessToEccentricity : public ConversionFunctor
    {

    public:
        virtual float operator() ( float v )
        {
            float out = ( 100.0f - v ) / 99.0f;
            return out * out;
        }
    };

#endif // BLINN_EXPONENT_MODEL


    class EffectTextureExporter;

    /** Map to store effects. */
    typedef std::map<String, String> EffectMap;


    /** This class writes the <library_materials>. It uses informations created my an effect exporter*/
    class EffectExporter : public COLLADASW::LibraryEffects
    {

    public:

        /** Suffix for the effect. */
        static const String EFFECT_ID_SUFFIX;

        /** Suffix for to build the tex-coordinate id. */
        static const String TEXCOORD_BASE;

    private:

        /** Prefix for the color effect. */
        static const String COLOR_EFFECT_ID_PREFIX;

        /** Holds information about an already exported effect*/
        struct ExportedEffect
        {
            MObject* shader; // The shader object, that was use to export the effect
            unsigned long mColor;  // The color that was used to export the effect
        };

    private:

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** For export the textures */
        EffectTextureExporter mTextureExporter;

        /** maps already exported materials to the corresponding collada effect id */
        MaterialMap* mMaterialMap;

        /** The std::map which stores all already exported effects */
        EffectMap mExportedEffectMap;

    public:

        /** A texture channel.
        Used by standard effects to assign textures to channels.
        Multi-texturing is done by assigning more than one texture per slot.
        Defaults to diffuse texture slot. */
        enum Channel
        {
            AMBIENT = 0, // ATTR_AMBIENT_COLOR /**< The texels will be modulated with the ambient light colors. */
            BUMP, // ATTR_NORMAL_CAMERA /**< The texels will re-orient the geometric normals. */
            DIFFUSE, // ATTR_COLOR /**< The texels will be modulated with the non-ambient light colors. */
            EMISSION, // ATTR_OUT_COLOR || ATTR_INCANDESCENCE /**< The texels will be added to the final color directly. */
            REFLECTION, // ATTR_REFLECTED_COLOR /**< The texels will modify the pixel reflection factor. */
            REFRACTION, /**< The texels will modify the pixel refraction factor. */
            SHININESS, /**< The texels will modify the specular shininess of the pixel. */
            SPECULAR, // ATTR_SPECULAR_COLOR /**< The texels will be modulated with the specular light colors. */
            TRANSPARENt, /**< The texels will be modify the final color alpha. */
            UNKNOWN, /**< An unknown texture channel. */
            DEFAULT = DIFFUSE
        };


    public:

        /**
        * @param streamWriter The stream the output will be written to
        * @param documentExporter The document exporter this material exporter is used in
        */
        EffectExporter ( COLLADASW::StreamWriter* _streamWriter, DocumentExporter* _documentExporter );
        virtual ~EffectExporter() {}

        /** Gets all the shaders and exports the effects of each */
        const ImageMap* exportEffects ( MaterialMap* materialMap=NULL );

        /**
         * Exports the effects from the scene graph.
         */
        void exportEffectsBySceneGraph();

        /**
        * Returns the std::map with the exported images.
        * @return const ImageMap*
        *   Returns a const pointer to the image map, managed and released
        *   in the class @EffectTextureExporter
        */
        const ImageMap* getExportedImageMap() const { return mTextureExporter.getExportedImageMap(); }

        /** For export the textures */
        EffectTextureExporter* getTextureExporter () { return &mTextureExporter; }

        /**
        * A collada id for every maya id.
        */
        const String findColladaImageId ( const String& mayaImageId );

        /**
        * Find any textures connected to a material attribute and create the
        * associated texture elements.
        * @param node The maya node object.
        * @param attributeName The name of the attribute
        * @param effectProfile The collada effect profile.
        * @param channel The channel to export.
        * @param nextTextureIndex The texture index
        * @return MObject If exported, the texture element, otherwise NULL.
        */
        MObject exportTexturedParameter ( 
            const String& effectId, 
            COLLADASW::EffectProfile* effectProfile, 
            const MObject& node, 
            const char* attributeName, 
            EffectExporter::Channel channel, 
            int& nextTextureIndex, 
            bool animated = false );

		void exportTexturedParameter(
			const String& effectId,
			COLLADASW::EffectProfile* effectProfile,
			int& nextTextureIndex,
			const URI & fileURI);

        /**
        * Retrieve any texture (file or layered) associated with a material attribute.
        * @param shader The maya shader object.
        * @param attributeName The name of the attribute.
        * @param textures Array of textures.
        * @param blendModes Array of blend modes.
        */
        void getShaderTextures ( const MObject& shader,
            const char* attributeName,
            MObjectArray& textures,
            MIntArray& blendModes );

//         /** Get the extra key in depend on the current effect profile type and export the user 
//         defined effect extra data from import (extra preservation) */
//         void exportExtraData ( 
//             COLLADASW::EffectProfile* effectProfile, 
//             const MObject& shader );

    private:

        /** Exports the effects of a shader */
        void exportEffect ( MObject& shadingEngine );

		/** Exports material extra attributes. */
		void exportExtraAttributes(const MObject& shader, COLLADASW::EffectProfile& effectProfile);

        /** Generated the collada effect id. */
        const String generateColladaEffectId ( 
            const MObject& shader, 
            const String& mayaMaterialId );

        /** Export a shader, by type */
        void exportConstantShader ( 
            const String& effectId, 
            COLLADASW::EffectProfile* effectProfile,
            MObject shadingNetwork );

        /** Exports an standard shader */
        void exportStandardShader ( 
            const String& effectId, 
            COLLADASW::EffectProfile* effectProfile,
            MObject shadingNetwork,
            bool initialized=false );

        /** Export a hardware shader node. */
        bool exportHwShaderNode (
            const String &effectId, 
            COLLADASW::EffectProfile *effectProfile,
            MObject shadingNetwork );

#if MAYA_API_VERSION >= 201500
		/** Export a shaderfx shader node. */
		void exportShaderFXShader(
			const String & effectId,
			COLLADASW::EffectProfile* effectProfile,
			MObject & shader);
#endif

        /**
         * Exports the transparency.
         * @param shadingNetwork Maya object to export.
         * @param transparentColor Color to export.
         * @param effectProfile Pointer to the collada effect profile.
         * @param attributeName Name of the attribute.
         * @param nextTextureIndex Index of the texture.
         */
        void exportTransparency ( 
            const String& effectId, 
            COLLADASW::EffectProfile* effectProfile, 
            MObject shadingNetwork, 
            const MColor& transparentColor, 
            const String& targetSid, 
            const char* attributeName, 
            int& nextTextureIndex );

        /** Blends the color on colorOrTexture with blendColor an amount @a amount*/
        void blendColor ( COLLADASW::ColorOrTexture &colorOrTexture, COLLADASW::Color blendColor, double ammount );

        /** Converts a maya color to a common ColorOrTexture type*/
        COLLADASW::ColorOrTexture mayaColor2ColorOrTexture ( const MColor &color, double scale=1.0 );

        /** Exports all materials from the current mesh */
        void exportMeshEffects ( SceneElement* sceneElement );

        /**
        * Returns the index of the channel in the sax framework loader.
        * @param const Channel & channel
        * @return COLLADASaxFWL::LibraryEffectsLoader::ShaderParameterTypes&
        */
        size_t getShaderParameterTypeByChannel ( const Channel& channel );

    };

}

#endif //__COLLADA_MAYA_EFFECT_EXPORTER_H__
