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

#ifndef __COLLADA_MAYA_TEXTURE_EXPORTER_H__
#define __COLLADA_MAYA_TEXTURE_EXPORTER_H__

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaDagHelper.h"
#include <map>

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryEffects.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWExtra.h"
#include "COLLADASWEffectProfile.h"
#include "COLLADASWUtils.h"
#include "COLLADASWLibraryImages.h"

#include <maya/MFnDependencyNode.h>

namespace COLLADAMaya
{

    typedef std::map<String, COLLADASW::Image*> ImageMap;

    /**
    * Class which manages the textures.
    */

    class EffectTextureExporter
    {

    private:

        /** The standard format for materials. */
        static const String FORMAT;

        /** A multi-texture blend mode. */
        enum Mode
        {
            NONE, /**< No blending. This is the default blend mode. */
            OVER, /**< Replaces the previous texture with the current one. */
            In, /**< ?. */
            OUt, /**< ?. */
            ADD, /**< Adds the color values from the previous texture to the current one. */
            SUBTRACT, /**< Substracts the color values from the current texture to the previous one. */
            MULTIPLY, /**< Modulates the previous texture with the current one. */
            DIFFERENCe, /**< Substracts the color values from the previous texture to the current one. */
            LIGHTEN, /**< ?. */
            DARKEN, /**< ?. */
            SATURATE, /**< ?. */
            DESATURATE, /**< ?. */
            ILLUMINATE, /**< ?. */

            UNKNOWN, /**< An unknown blend mode. */
            DEFAULT = NONE,
        };

        /** Pointer to the document exporter */
        DocumentExporter* mDocumentExporter;

        /** maps already exported image file names to the corresponding image id */
        ImageMap mExportedImageMap;

        /** true, if the <extra> and a <technique> tags are already open */
        bool mTechniqueIsOpen;

        /** The <extra> tag */
        COLLADASW::Extra* mExtraSource;

        /** The <technique> tag */
        COLLADASW::Technique* mTechniqueSource;

        /** The target path for animated elements. */
        String mAnimationTargetPath;

    public:

        /** Constructor. */
        EffectTextureExporter ( DocumentExporter* _documentExporter );
        virtual ~EffectTextureExporter();

        /**
        * Exports the current texture.
        * The parameters @shader and @attribute have to be set in the special case for bump maps:
        * export the bump height in the "amount" texture parameter.
        * Exists currently within the ColladaMax profile.
        */
        void exportTexture ( COLLADASW::Texture* colladaTexture,
                             String channelSemantic,
                             const MObject &texture,
                             int blendMode,
                             const String &targetPath );

        /**
        * Returns the std::map with the exported images.
        * @return const ImageMap*
        *   Returns a const pointer to the image map, managed and released
        *   in the class @EffectTextureExporter
        */
        const ImageMap* getExportedImageMap() const
        {
            return &mExportedImageMap;
        }

        /** Exports the texture image */
        String exportImage ( const MObject &texture );

        /** Exports the texture image */
        COLLADASW::Image* exportImage ( const String &colladaImageId, const COLLADASW::URI &sourceFile );

    private:

        /** Checks if the source file exist and is valid. If not, the method 
        returns false. Fills the full file URI of the texture in dependency
        of the current export options. */
        bool getTextureFileInfos( 
            const COLLADASW::URI &sourceUri, 
            COLLADASW::URI &fullFileNameURI );

        /**
         * Returns the target file name of the given source file name.
         * @param sourceFileName The source file name.
         * @return String The target file name.
         */
        COLLADASW::URI createTargetURI ( const COLLADASW::URI &sourceUri );

        /** Dump a place2dTexture node */
        void add2DPlacement ( COLLADASW::Texture* colladaTexture, MObject texture );

        /** Dump a place2dTexture 3DProjection */
        void add3DProjection ( COLLADASW::Texture* colladaTexture, MObject projection );

        /** Opens an <extra> and a <technique> tag in the collada document */
        void openTechnique();

        /** Closes the <extra> and a <technique> tag in the collada document, if open */
        void closeTechnique();

        /** Adds an bool parameter into the <technique> tag */
        void addBoolParameter ( COLLADASW::Texture* colladaTexture,
                                const char* plugName,
                                MFnDependencyNode &placement2d );

        /** Adds an float parameter into the <technique> tag */
        void addFloatParameter ( COLLADASW::Texture* colladaTexture,
                                 const char* plugName,
                                 MFnDependencyNode &placement2d );

        /** Adds an angle parameter into the <technique> tag */
        void addAngleParameter ( COLLADASW::Texture* colladaTexture,
                                 const char* plugName,
                                 MFnDependencyNode &placement2d );

        String getBlendMode ( int blendMode );

    };

}

#endif // __COLLADA_MAYA_TEXTURE_EXPORTER_H__