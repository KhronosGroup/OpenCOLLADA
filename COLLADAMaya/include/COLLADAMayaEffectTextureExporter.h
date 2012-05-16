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
#include "COLLADASWLibraryImages.h"

#include "COLLADABUIDList.h"

#include <maya/MFnDependencyNode.h>

namespace COLLADAMaya
{

    typedef std::map<String, COLLADASW::Image*> ImageMap;


    /**
    * Class which manages the textures.
    */
    class EffectTextureExporter
    {

    public:

        /** The standard format for materials. */
        static const String FORMAT;

    private:

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

    private:

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList mImageIdList;

        /** 
         * Pointer to the document exporter 
         */
        DocumentExporter* mDocumentExporter;

        /** 
         * Maps already exported image file names to the corresponding image id 
         */
        ImageMap mExportedImageMap;

        /**
         * The map holds the collada id for the maya id.
         */
        StringToStringMap mMayaIdColladaImageId;

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
        const ImageMap* getExportedImageMap() const { return &mExportedImageMap; }

        /** Exports the texture image */
        String exportImage ( const MObject &texture );

        /** Exports the texture image */
        COLLADASW::Image* exportImage ( 
            const String& mayaImageId, 
            const String& colladaImageId, 
            const COLLADASW::URI& sourceFile );

        /**
        * The list of the unique collada ids.
        */
        COLLADABU::IDList& getImageIdList () { return mImageIdList; }

        /**
        * The map holds the collada id for the maya id.
        */
        COLLADAMaya::StringToStringMap& getMayaIdColladaImageId () { return mMayaIdColladaImageId; }

    private:

        /** Returns the tolerance value for double value comparison. */
        const double getTolerance () const 
        {
            return mDocumentExporter->getTolerance ();
        }

        /** Checks if the source file exist and is valid. If not, the method 
        returns false. Fills the full file URI of the texture in dependency
        of the current export options. */
        bool getTextureFileInfos ( 
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

        /**
         * Use the Blend Mode to control how successive layers of textures are combined together. 
         * There are a number of blend modes which can specify exactly how to blend a texture with 
         * the textures beneath it.
         * Here we present two descriptions of the different blend modes. The first description is 
         * a non-technical definition of each blend mode for the benefit of someone who wants to 
         * know what each one does. The second is a technical definition of each blend mode for the 
         * benefit of someone who is attempting to imitate their function in hardware. In both cases 
         * we will refer to the texture whose blend mode is being specified as the "foreground" 
         * texture, and the result of all of the underlying textures blended together (according to 
         * their particular blend modes) as the "background" texture.
         * 
         * The non-technical definitions are as follows:
         * 
         * * None: The foreground texture covers up the background texture entirely.
         * * Over: The foreground texture is applied like a decal to the background. The shape of 
         *          the decal is determined by the foreground alpha.
         * * In: The result is the background texture cut in the shape of the foreground alpha.
         * * Out: The result is the opposite of In. It is as if the shape of the foreground alpha 
         *          has been cut out of the background.
         * * Add: The result color is the foreground color added to the background color as if being 
         *          projected on the background through a slide projector. The result color is then 
         *          applied over the background color using the foreground alpha to define the 
         *          opacity of the result.
         * * Subtract: The result color is the foreground color subtracted from the background 
         *          color. The result color is then applied over the background color using the 
         *          foreground alpha to define the opacity of the result.
         * * Multiply: The result color is the foreground color multiplied by the background color. 
         *          The result color is then applied over the background color using the foreground 
         *          alpha to define the opacity of the result.
         * * Difference: The result color is the difference between the foreground color and the 
         *          background color. The result color is then applied over the background color 
         *          using the foreground alpha to define the opacity of the result. Difference is 
         *          not supported by hardware texturing.
         * * Lighten: The result color of each pixel is the background color or foreground color, 
         *          whichever is lighter. The result color is then applied over the background 
         *          color using the foreground alpha to define the opacity of the result. Lighten 
         *          is not supported by hardware texturing.
         * * Darken: The result color of each pixel is the background color or foreground color, 
         *          whichever is darker. The result color is then applied over the background color 
         *          using the foreground alpha to define the opacity of the result. Darken is not 
         *          supported by hardware texturing.
         * * Saturate: The result color is the background color with saturation increased in 
         *          proportion to the foreground color scaled by foreground alpha. If the 
         *          foreground color is red, for example, the result color will be the background 
         *          color with more saturated reds.
         * * Desaturate: The result color is the background color with saturation decreased in 
         *          proportion to the foreground color scaled by foreground alpha. If the foreground 
         *          color is red, for example, the result color will be the background color with 
         *          desaturated reds.
         * * Illuminate: The result color is the background color mixed with the foreground color, 
         *          brighter where the foreground is bright and darker where the foreground is dark. 
         *          It is as if the foreground texture represents the light falling on the 
         *          background. The result color is then applied over the background color using the 
         *          foreground alpha to define the opacity of the result.
         */
        String getBlendMode ( int blendMode );

    };

}

#endif // __COLLADA_MAYA_TEXTURE_EXPORTER_H__