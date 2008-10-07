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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaEffectTextureExporter.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaExportOptions.h"

#include "COLLADAMathUtils.h"
#include "COLLADAStreamWriter.h"
#include "COLLADALibraryImages.h"
#include "COLLADASurface.h"

#include <maya/MFileIO.h>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;


namespace COLLADAMaya
{

    const String EffectTextureExporter::FORMAT = "A8R8G8B8";

    //------------------------------------------------------
    EffectTextureExporter::EffectTextureExporter ( DocumentExporter* _documentExporter )
    : mDocumentExporter ( _documentExporter )
    , mTechniqueIsOpen ( false )
    , mExtraSource ( NULL )
    , mTechniqueSource ( NULL )
    , mAnimationTargetPath ( "" )
    {}

    //---------------------------------------------------------------
    EffectTextureExporter::~EffectTextureExporter()
    {
        if ( !mExportedImageMap.empty() )
        {
            ImageMap::iterator it = mExportedImageMap.begin();
            for ( ; it!=mExportedImageMap.end(); ++it )
            {
                COLLADA::Image* image = it->second;
                delete image;
            }

            mExportedImageMap.clear();
        }
    }

    //---------------------------------------------------------------
    void EffectTextureExporter::exportTexture (
        COLLADA::Texture* colladaTexture,
        String channelSemantic,
        const MObject& texture,
        int blendMode,
        const String& targetPath )
    {
        mAnimationTargetPath = targetPath;

        // Set the image name
        String colladaImageId = exportImage ( texture );
        colladaTexture->setImageId ( colladaImageId );
        colladaTexture->setTexcoord ( channelSemantic );

        // Get the current stream writer
        COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Create the surface
        String surfaceSid = colladaImageId + COLLADA::Surface::SURFACE_SID_SUFFIX;
        COLLADA::Surface surface ( COLLADA::Surface::SURFACE_TYPE_2D, surfaceSid );
        surface.setFormat ( FORMAT );
        COLLADA::SurfaceInitOption initOption ( COLLADA::SurfaceInitOption::INIT_FROM );
        initOption.setImageReference ( colladaImageId );
        surface.setInitOption ( initOption );
        colladaTexture->setSurface ( surface );

        // Create the sampler
        String samplerSid = colladaImageId + COLLADA::Sampler::SAMPLER_SID_SUFFIX;
        COLLADA::Sampler sampler ( COLLADA::Sampler::SAMPLER_TYPE_2D, samplerSid );
        sampler.setSource ( surfaceSid );
        colladaTexture->setSampler ( sampler );

        // Add 2D placement parameters
        add2DPlacement ( colladaTexture, texture );

        // Check for 3D projection node
        MObject colorReceiver = DagHelper::getSourceNodeConnectedTo ( texture, ATTR_OUT_COLOR );
        if ( colorReceiver != MObject::kNullObj && colorReceiver.apiType() == MFn::kProjection )
        {
            add3DProjection ( colladaTexture, colorReceiver );
        }

        // Add blend mode information
        String blendModeString = getBlendMode ( blendMode );

        colladaTexture->addExtraTechniqueParameter (
            COLLADA::CSWC::COLLADA_PROFILE_MAYA, MAYA_TEXTURE_BLENDMODE_PARAMETER, blendModeString );

        // Wrap elements
        switch ( colladaTexture->getSurface().getSurfaceType() )
        {

        case COLLADA::Surface::SURFACE_TYPE_1D:
            sampler.setWrapS ( COLLADA::Sampler::WRAP_MODE_WRAP );
            break;

        case COLLADA::Surface::SURFACE_TYPE_2D:
        {
            sampler.setWrapS ( COLLADA::Sampler::WRAP_MODE_WRAP );
            sampler.setWrapT ( COLLADA::Sampler::WRAP_MODE_WRAP );
        }
        break;

        case COLLADA::Surface::SURFACE_TYPE_3D:
        case COLLADA::Surface::SURFACE_TYPE_CUBE:
        {
            sampler.setWrapS ( COLLADA::Sampler::WRAP_MODE_WRAP );
            sampler.setWrapT ( COLLADA::Sampler::WRAP_MODE_WRAP );
            sampler.setWrapP ( COLLADA::Sampler::WRAP_MODE_WRAP );
        }
        break;
        }

        sampler.setMinFilter ( COLLADA::Sampler::SAMPLER_FILTER_NONE );
        sampler.setMagFilter ( COLLADA::Sampler::SAMPLER_FILTER_NONE );
        sampler.setMipFilter ( COLLADA::Sampler::SAMPLER_FILTER_NONE );
    }

    //---------------------------------------------------------------
    String EffectTextureExporter::getBlendMode ( int blendMode )
    {
        switch ( blendMode )
        {
        case NONE:
            return MAYA_NONE_BLENDMODE;
        case OVER:
            return MAYA_OVER_BLENDMODE;
        case In:
            return MAYA_IN_BLENDMODE;
        case OUt:
            return MAYA_OUT_BLENDMODE;
        case ADD:
            return MAYA_ADD_BLENDMODE;
        case SUBTRACT:
            return MAYA_SUBTRACT_BLENDMODE;
        case MULTIPLY:
            return MAYA_MULTIPLY_BLENDMODE;
        case DIFFERENCe:
            return MAYA_DIFFERENCE_BLENDMODE;
        case LIGHTEN:
            return MAYA_LIGHTEN_BLENDMODE;
        case DARKEN:
            return MAYA_DARKEN_BLENDMODE;
        case SATURATE:
            return MAYA_SATURATE_BLENDMODE;
        case DESATURATE:
            return MAYA_DESATURATE_BLENDMODE;
        case ILLUMINATE:
            return MAYA_ILLUMINATE_BLENDMODE;
        default:
            return MAYA_NONE_BLENDMODE;
        }
    }

    //---------------------------------------------------------------
    String EffectTextureExporter::exportImage ( const MObject &texture )
    {
        // Retrieve the texture filename
        MFnDependencyNode dgFn ( texture );
        MString mayaName = dgFn.name(), mayaFileName;
        MPlug filenamePlug = dgFn.findPlug ( ATTR_FILE_TEXTURE_NAME );

        // Convert the image name
        String colladaImageId = mDocumentExporter->mayaNameToColladaName ( mayaName );

        // Get the maya filename with the path to the file.
        filenamePlug.getValue ( mayaFileName );
        if ( mayaFileName.length () == 0 ) return NULL;
        String sourceFile = mayaFileName.asChar ();
        COLLADA::URI sourceFileUri ( COLLADA::URI::nativePathToUri ( sourceFile ) );
        sourceFileUri.setScheme ( COLLADA::URI::SCHEME_FILE );

        COLLADA::Image* colladaImage = exportImage ( colladaImageId, sourceFileUri );
        if ( colladaImage == NULL ) return NULL;

        // Export the node type, because PSD textures don't behave the same as File textures.
        String nodeType = texture.hasFn ( MFn::kPsdFileTexture ) ? MAYA_TEXTURE_PSDTEXTURE : MAYA_TEXTURE_FILETEXTURE;
        colladaImage->addExtraTechniqueParameter (
            COLLADA::CSWC::COLLADA_PROFILE_MAYA, MAYA_TEXTURE_NODETYPE, nodeType );

        // Export whether this image is in fact an image sequence
        MPlug imgSeqPlug = dgFn.findPlug ( ATTR_IMAGE_SEQUENCE );
        bool isImgSeq = false;
        imgSeqPlug.getValue ( isImgSeq );
        colladaImage->addExtraTechniqueParameter (
            COLLADA::CSWC::COLLADA_PROFILE_MAYA, MAYA_TEXTURE_IMAGE_SEQUENCE, isImgSeq );

        return colladaImage->getImageId();
    }

    // -------------------------------
    COLLADA::Image* EffectTextureExporter::exportImage ( 
        const String& colladaImageId, 
        const COLLADA::URI& sourceUri )
    {
        // Get the file name and the URI
        COLLADA::URI fullFileNameURI;
        getTextureFileInfos ( sourceUri, fullFileNameURI );
        String fullFileName = fullFileNameURI.toNativePath ();

        // Have we seen this texture node before?
        ImageMap::iterator exportedImagesIter = mExportedImageMap.find ( fullFileName );
        if ( exportedImagesIter != mExportedImageMap.end() )
        {
            COLLADA::Image* colladaImage = ( *exportedImagesIter ).second;
            return colladaImage;
        }

        // Check, if we should copy the texture to the destination folder.
        if ( ExportOptions::copyTextures() )
        {
            // Get the target file from source file.
            COLLADA::URI targetUri = createTargetURI ( sourceUri );

            // Copy the texture, if it isn't already there...
            if ( !exists( targetUri.toNativePath () ) )
            {
                try 
                {
                    // Create the target directory, if necessary. 
                    // Note: some systems (window$) requires the string to be 
                    // enclosed in quotes when a space is present.
                    COLLADA::URI targetPathUri ( targetUri.getPathDir() );
                    create_directory ( targetPathUri.toNativePath() );

                    // Throws: basic_filesystem_error<Path> if
                    // from_fp.empty() || to_fp.empty() ||!exists(from_fp) || !is_regular(from_fp) || exists(to_fp)
                    copy_file ( path ( sourceUri.toNativePath() ), path ( targetUri.toNativePath() ) );
                }
                catch ( std::exception ex )
                {
                    String message = "Could not successful create directory and copy file: " + sourceUri.toNativePath();
                    MGlobal::displayError( message.c_str() );
                    MGlobal::displayError( ex.what() );
                    std::cerr << "[ERROR] Could not copy file " << sourceUri.toNativePath() << std::endl;
                }
            }
        }

        // Create a new image structure
        COLLADA::Image* colladaImage = new COLLADA::Image (
            fullFileNameURI, colladaImageId, colladaImageId );

        // Add this texture to our list of exported images
        mExportedImageMap[ fullFileName ] = colladaImage;

        return colladaImage;
    }

    // ------------------------------------------------------------
    COLLADA::URI EffectTextureExporter::createTargetURI ( const COLLADA::URI& sourceUri )
    {
        // Target file
        String targetFile = mDocumentExporter->getFilename();
        COLLADA::URI targetUri ( COLLADA::URI::nativePathToUri ( targetFile ) );

        // Get the pure file name of the source file and set 
        // the source file name to the target path
        targetUri.setPathFile ( sourceUri.getPathFile () );
        targetUri.setScheme ( COLLADA::URI::SCHEME_FILE );

        // Generate the target file name
        return targetUri;
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::add2DPlacement ( COLLADA::Texture* colladaTexture, MObject texture )
    {
        // Is there a texture placement applied to this texture?
        MObject placementNode = DagHelper::getSourceNodeConnectedTo ( texture, ATTR_UV_COORD );
        if ( placementNode.hasFn ( MFn::kPlace2dTexture ) )
        {
            MFnDependencyNode placement2d ( placementNode );

            addBoolParameter ( colladaTexture, MAYA_TEXTURE_WRAPU_PARAMETER, placement2d );
            addBoolParameter ( colladaTexture, MAYA_TEXTURE_WRAPV_PARAMETER, placement2d );
            addBoolParameter ( colladaTexture, MAYA_TEXTURE_MIRRORU_PARAMETER, placement2d );
            addBoolParameter ( colladaTexture, MAYA_TEXTURE_MIRRORV_PARAMETER, placement2d );

            addFloatParameter ( colladaTexture, MAYA_TEXTURE_COVERAGEU_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_COVERAGEV_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_TRANSFRAMEU_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_TRANSFRAMEV_PARAMETER, placement2d );
            addAngleParameter ( colladaTexture, MAYA_TEXTURE_ROTFRAME_PARAMETER, placement2d );

            addBoolParameter ( colladaTexture, MAYA_TEXTURE_STAGGER_PARAMETER, placement2d );
            addBoolParameter ( colladaTexture, MAYA_TEXTURE_FAST_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_REPEATU_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_REPEATV_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_OFFSETU_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_OFFSETV_PARAMETER, placement2d );
            addAngleParameter ( colladaTexture, MAYA_TEXTURE_ROTATEUV_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_NOISEU_PARAMETER, placement2d );
            addFloatParameter ( colladaTexture, MAYA_TEXTURE_NOISEV_PARAMETER, placement2d );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::add3DProjection ( COLLADA::Texture* colladaTexture, MObject projection )
    {
        int projectionType;
        DagHelper::getPlugValue ( projection, ATTR_PROJECTION_TYPE, projectionType );
        String strProjectionType = ShaderHelper::projectionTypeToString ( projectionType );
        colladaTexture->addExtraTechniqueChildParameter (
            COLLADA::CSWC::COLLADA_PROFILE_MAYA,
            MAYA_PROJECTION_ELEMENT,
            MAYA_PROJECTION_TYPE_PARAMETER,
            strProjectionType );

        MMatrix projectionMx;
        DagHelper::getPlugValue ( projection, ATTR_PLACEMENT_MATRIX, projectionMx );
        double sceneMatrix[4][4];
        convertMMatrixToDouble4x4 ( sceneMatrix, projectionMx );

        // Convert the  maya internal unit type of the transform part of the
        // matrix from centimeters into the working units of the current scene!
        for ( uint i=0; i<3; ++i)
            sceneMatrix [i][3] = MDistance::internalToUI ( sceneMatrix [i][3] );

        colladaTexture->addExtraTechniqueChildParameter (
            COLLADA::CSWC::COLLADA_PROFILE_MAYA,
            MAYA_PROJECTION_ELEMENT,
            MAYA_PROJECTION_MATRIX_PARAMETER,
            sceneMatrix );
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::addBoolParameter (
        COLLADA::Texture* colladaTexture,
        const char* plugName,
        MFnDependencyNode &placement2d )
    {
        MStatus status;
        MPlug plug = placement2d.findPlug ( plugName, &status );

        if ( status == MStatus::kSuccess )
        {
            bool value = false;
            plug.getValue ( value );

            // Get the animation exporter
            AnimationExporter* anim = mDocumentExporter->getAnimationExporter();
            // The target id for the animation
            String targetSid = mAnimationTargetPath + plugName;
            // Create the animation
            bool animated = anim->addPlugAnimation ( plug, targetSid, kBoolean );
            // Add the parameter
            String paramSid = ""; if ( animated ) paramSid = plugName;
            colladaTexture->addExtraTechniqueParameter ( COLLADA::CSWC::COLLADA_PROFILE_MAYA, plugName, value, paramSid );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::addFloatParameter (
        COLLADA::Texture* colladaTexture,
        const char* plugName,
        MFnDependencyNode &placement2d )
    {
        MStatus status;
        MPlug plug = placement2d.findPlug ( plugName, &status );

        if ( status == MStatus::kSuccess )
        {
            float value;
            plug.getValue ( value );

            // Get the animation exporter
            AnimationExporter* anim = mDocumentExporter->getAnimationExporter();
            // The target id for the animation
            String targetSid = mAnimationTargetPath + plugName;
            // Create the animation
            bool animated = anim->addPlugAnimation ( plug, targetSid, kBoolean );
            // Add the parameter
            String paramSid = ""; if ( animated ) paramSid = plugName;
            colladaTexture->addExtraTechniqueParameter ( COLLADA::CSWC::COLLADA_PROFILE_MAYA, plugName, value, paramSid );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::addAngleParameter (
        COLLADA::Texture* colladaTexture,
        const char* plugName,
        MFnDependencyNode &placement2d )
    {
        MStatus status;
        MPlug plug = placement2d.findPlug ( plugName, &status );

        if ( status == MStatus::kSuccess )
        {
            float value;
            plug.getValue ( value );

            // Get the animation exporter
            AnimationExporter* anim = mDocumentExporter->getAnimationExporter();
            // The target id for the animation
            String targetSid = mAnimationTargetPath + plugName;
            // Create the animation
            bool animated = anim->addPlugAnimation ( plug, targetSid, kBoolean );
            // Add the parameter
            String paramSid = ""; if ( animated ) paramSid = plugName;
            colladaTexture->addExtraTechniqueParameter ( COLLADA::CSWC::COLLADA_PROFILE_MAYA, plugName, value, paramSid );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::openTechnique()
    {
        if ( !mTechniqueIsOpen )
        {
            COLLADA::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

            mExtraSource = new COLLADA::Extra ( streamWriter );
            mExtraSource->openExtra();

            mTechniqueSource = new COLLADA::Technique ( streamWriter );
            mTechniqueSource->openTechnique ( COLLADA::CSWC::COLLADA_PROFILE_MAYA );

            mTechniqueIsOpen = true;
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::closeTechnique()
    {
        if ( mTechniqueIsOpen )
        {
            mTechniqueSource->closeTechnique();
            mExtraSource->closeExtra();

            mTechniqueIsOpen = false;
        }
    }

    // ------------------------------------------------------------
    bool EffectTextureExporter::getTextureFileInfos( 
        const COLLADA::URI &sourceUri, 
        COLLADA::URI &fullFileNameURI )
    {
        bool returnValue = true;

        // Check if the file exist!
        String sourceUriString = sourceUri.toNativePath();
        if ( !exists ( sourceUri.toNativePath() ) )
        {
            String message = "The texture file doesn't exist! Filename = " + sourceUri.toNativePath();
            MGlobal::displayWarning ( message.c_str() );
            std::cerr << message << std::endl;
            returnValue = false;
        }

        if ( ExportOptions::relativePaths() )
        {
            // Different filename and URI, if we copy the textures to the destination directory!
            if ( ExportOptions::copyTextures() )
            {
                // Get the URI of the COLLADA file.
                String targetColladaFile = mDocumentExporter->getFilename();
                COLLADA::URI targetColladaUri ( COLLADA::URI::nativePathToUri ( targetColladaFile ) );
                targetColladaUri.setScheme ( COLLADA::URI::SCHEME_FILE );

                // Get the URI of the copied texture file.
                COLLADA::URI textureUri = createTargetURI ( sourceUri );

                // Get the texture URI relative to the COLLADA file URI.
                bool success = false;
                COLLADA::URI targetUri = textureUri.getRelativeTo ( targetColladaUri, success );
                if ( !success ) 
                {
                    String message = "Not able to generate a relative path from " 
                        + textureUri.getURIString() + " to " + targetColladaUri.getURIString() 
                        + ". An absolute path will be written! ";
                    MGlobal::displayError ( message.c_str() );
                    targetUri = textureUri;
                    returnValue = false;
                }

                // Get the file URI
                fullFileNameURI = targetUri;
            }
            else
            {
                // Get the URI of the COLLADA file.
                String targetColladaFile = mDocumentExporter->getFilename();
                COLLADA::URI targetColladaUri ( COLLADA::URI::nativePathToUri ( targetColladaFile ) );
                targetColladaUri.setScheme ( COLLADA::URI::SCHEME_FILE );

                // Get the texture URI relative to the COLLADA file URI.
                bool success = false;
                COLLADA::URI targetUri = sourceUri.getRelativeTo ( targetColladaUri, success );
                if ( !success ) 
                {
                    String message = "Not able to generate a relative path from " 
                        + sourceUri.getURIString() + " to " + targetColladaUri.getURIString() 
                        + ". An absolute path will be written! ";
                    MGlobal::displayError ( message.c_str() );
                    targetUri = sourceUri;
                    returnValue = false;
                }

                // Get the file URI
                fullFileNameURI = targetUri;
            }
        }
        else
        {
            // Different filename and URI, if we copy the textures to the destination directory!
            if ( ExportOptions::copyTextures() )
            {
                // Get the texture URI relative to the COLLADA file URI.
                COLLADA::URI targetUri = createTargetURI ( sourceUri );

                // Get the file URI
                fullFileNameURI = targetUri;
            }
            else
            {
                // Get the file URI
                fullFileNameURI = sourceUri;
            }
        }

        return returnValue;
    }
}
