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

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaEffectTextureExporter.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaExportOptions.h"

#include "Math/COLLADABUMathUtils.h"

#include "COLLADASWStreamWriter.h"
#include "COLLADASWLibraryImages.h"

#include <boost/filesystem/config.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/filesystem/exception.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
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
    , mAnimationTargetPath ( EMPTY_STRING )
    {}

    //---------------------------------------------------------------
    EffectTextureExporter::~EffectTextureExporter()
    {
        if ( !mExportedImageMap.empty() )
        {
            ImageMap::iterator it = mExportedImageMap.begin();
            for ( ; it!=mExportedImageMap.end(); ++it )
            {
                COLLADASW::Image* image = it->second;
                delete image;
            }

            mExportedImageMap.clear();
        }
    }

    //---------------------------------------------------------------
    void EffectTextureExporter::exportTexture (
        COLLADASW::Texture* colladaTexture,
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
        COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

        // Create the sampler
        String samplerSid = colladaImageId + COLLADASW::Sampler::SAMPLER_SID_SUFFIX;
        String surfaceSid = colladaImageId + COLLADASW::Sampler::SURFACE_SID_SUFFIX;

        COLLADASW::Sampler sampler ( COLLADASW::Sampler::SAMPLER_TYPE_2D, samplerSid, surfaceSid );
        sampler.setFormat ( FORMAT );
        sampler.setImageId ( colladaImageId );

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
        colladaTexture->addExtraTechniqueParameter ( PROFILE_MAYA, MAYA_TEXTURE_BLENDMODE_PARAMETER, blendModeString );

        // Wrap elements
        switch ( colladaTexture->getSampler().getSamplerType() )
        {

        case COLLADASW::Sampler::SAMPLER_TYPE_1D:
            sampler.setWrapS ( COLLADASW::Sampler::WRAP_MODE_WRAP );
            break;

        case COLLADASW::Sampler::SAMPLER_TYPE_2D:
        {
            sampler.setWrapS ( COLLADASW::Sampler::WRAP_MODE_WRAP );
            sampler.setWrapT ( COLLADASW::Sampler::WRAP_MODE_WRAP );
        }
        break;

        case COLLADASW::Sampler::SAMPLER_TYPE_3D:
        case COLLADASW::Sampler::SAMPLER_TYPE_CUBE:
        {
            sampler.setWrapS ( COLLADASW::Sampler::WRAP_MODE_WRAP );
            sampler.setWrapT ( COLLADASW::Sampler::WRAP_MODE_WRAP );
            sampler.setWrapP ( COLLADASW::Sampler::WRAP_MODE_WRAP );
        }
        break;
        }

        sampler.setMinFilter ( COLLADASW::Sampler::SAMPLER_FILTER_NONE );
        sampler.setMagFilter ( COLLADASW::Sampler::SAMPLER_FILTER_NONE );
        sampler.setMipFilter ( COLLADASW::Sampler::SAMPLER_FILTER_NONE );
    }

    //---------------------------------------------------------------
    String EffectTextureExporter::getBlendMode ( int blendMode )
    {
        switch ( blendMode )
        {
        case NONE:
            return MAYA_BLENDMODE_NONE;
        case OVER:
            return MAYA_BLENDMODE_OVER;
        case In:
            return MAYA_BLENDMODE_IN;
        case OUt:
            return MAYA_BLENDMODE_OUT;
        case ADD:
            return MAYA_BLENDMODE_ADD;
        case SUBTRACT:
            return MAYA_BLENDMODE_SUBTRACT;
        case MULTIPLY:
            return MAYA_BLENDMODE_MULTIPLY;
        case DIFFERENCe:
            return MAYA_BLENDMODE_DIFFERENCE;
        case LIGHTEN:
            return MAYA_BLENDMODE_LIGHTEN;
        case DARKEN:
            return MAYA_BLENDMODE_DARKEN;
        case SATURATE:
            return MAYA_BLENDMODE_SATURATE;
        case DESATURATE:
            return MAYA_BLENDMODE_DESATURATE;
        case ILLUMINATE:
            return MAYA_BLENDMODE_ILLUMINATE;
        default:
            return MAYA_BLENDMODE_NONE;
        }
    }

    //---------------------------------------------------------------
    String EffectTextureExporter::exportImage ( const MObject &texture )
    {
        // Retrieve the texture filename
        MFnDependencyNode textureNode ( texture );
        MString mayaName = textureNode.name();
        MPlug filenamePlug = textureNode.findPlug ( ATTR_FILE_TEXTURE_NAME );

        // Get the maya image id.
        String mayaImageId = DocumentExporter::mayaNameToColladaName ( textureNode.name() );

        // Generate a COLLADA id for the new light object
        String colladaImageId;

        // Check if there is an extra attribute "colladaId" and use this as export id.
        MString attributeValue;
        DagHelper::getPlugValue ( texture, COLLADA_ID_ATTRIBUTE_NAME, attributeValue );
        if ( attributeValue != EMPTY_CSTRING )
        {
            // Generate a valid collada name, if necessary.
            colladaImageId = mDocumentExporter->mayaNameToColladaName ( attributeValue, false );
        }
        else
        {
            // Generate a COLLADA id for the new light object
            colladaImageId = DocumentExporter::mayaNameToColladaName ( textureNode.name() );
        }
        // Make the id unique and store it in a map for refernences.
        colladaImageId = mImageIdList.addId ( colladaImageId );
        mMayaIdColladaImageId [mayaImageId] = colladaImageId;

        // Get the maya filename with the path to the file.
        MString mayaFileName;
        filenamePlug.getValue ( mayaFileName );
        if ( mayaFileName.length () == 0 ) return NULL;
        String sourceFile = mayaFileName.asChar ();
        COLLADASW::URI sourceFileUri ( COLLADASW::URI::nativePathToUri ( sourceFile ) );
        if ( sourceFileUri.getScheme ().empty () )
            sourceFileUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

        COLLADASW::Image* colladaImage = exportImage ( mayaImageId, colladaImageId, sourceFileUri );
        if ( colladaImage == NULL ) return NULL;

        // Export the node type, because PSD textures don't behave the same as File textures.
        String nodeType = texture.hasFn ( MFn::kPsdFileTexture ) ? MAYA_TEXTURE_PSDTEXTURE : MAYA_TEXTURE_FILETEXTURE;
        colladaImage->addExtraTechniqueParameter ( PROFILE_MAYA, MAYA_TEXTURE_NODETYPE, nodeType );

        // Export whether this image is in fact an image sequence
        MPlug imgSeqPlug = textureNode.findPlug ( ATTR_IMAGE_SEQUENCE );
        bool isImgSeq = false;
        imgSeqPlug.getValue ( isImgSeq );
        colladaImage->addExtraTechniqueParameter ( PROFILE_MAYA, MAYA_TEXTURE_IMAGE_SEQUENCE, isImgSeq );

        return colladaImage->getImageId();
    }

    // -------------------------------
    COLLADASW::Image* EffectTextureExporter::exportImage ( 
        const String& mayaImageId, 
        const String& colladaImageId, 
        const COLLADASW::URI& sourceUri )
    {
        // Get the file name and the URI
        COLLADASW::URI fullFileNameURI;
        bool sourceFileExist = getTextureFileInfos ( sourceUri, fullFileNameURI );
        String fullFileName = fullFileNameURI.toNativePath ();

        // Have we seen this texture node before?
        ImageMap::iterator exportedImagesIter = mExportedImageMap.find ( fullFileName );
        if ( exportedImagesIter != mExportedImageMap.end() )
        {
            COLLADASW::Image* colladaImage = ( *exportedImagesIter ).second;
            return colladaImage;
        }

        // Check, if we should copy the texture to the destination folder.
        if ( ExportOptions::copyTextures() )
        {
            // Get the target file from source file.
            COLLADASW::URI targetUri = createTargetURI ( sourceUri );

            if ( !exists ( sourceUri.toNativePath() ) )
            {
                String message = "The source texture file doesn't exist! Filename = " + sourceUri.toNativePath();
                std::cerr << message << std::endl;
            }
            else
            {
                // Copy the texture, if it isn't already there...
                if ( !exists( targetUri.toNativePath () ) )
                {
                    try 
                    {
                        // Create the target directory, if necessary. 
                        // Note: some systems (window$) requires the string to be 
                        // enclosed in quotes when a space is present.
                        COLLADASW::URI targetPathUri ( targetUri.getPathDir() );
                        create_directory ( targetPathUri.toNativePath() );

                        // Throws: basic_filesystem_error<Path> if
                        // from_fp.empty() || to_fp.empty() ||!exists(from_fp) || !is_regular(from_fp) || exists(to_fp)
                        copy_file ( path ( sourceUri.toNativePath() ), path ( targetUri.toNativePath() ) );
                    }
                    catch ( std::exception ex )
                    {
                        String message = "Could not successful create directory and copy file: " + sourceUri.toNativePath();
                        MGlobal::displayError( message.c_str() );
                        std::cerr << "[ERROR] Could not copy file " << sourceUri.toNativePath() << std::endl;
                    }
                }
            }
        }

        // Create a new image structure
        COLLADASW::Image* colladaImage = new COLLADASW::Image ( fullFileNameURI, colladaImageId, mayaImageId );

        // Export the original maya name.
        colladaImage->addExtraTechniqueParameter ( PROFILE_MAYA, PARAMETER_MAYA_ID, mayaImageId );

        // Add this texture to our list of exported images
        mExportedImageMap[ fullFileName ] = colladaImage;

        return colladaImage;
    }

    // ------------------------------------------------------------
    COLLADASW::URI EffectTextureExporter::createTargetURI ( const COLLADASW::URI& sourceUri )
    {
        // Target file
        String targetFile = mDocumentExporter->getFilename();
        COLLADASW::URI targetUri ( COLLADASW::URI::nativePathToUri ( targetFile ) );
        const String& targetScheme = targetUri.getScheme ();

        // Get the pure file name of the source file and set 
        // the source file name to the target path
        targetUri.setPathFile ( sourceUri.getPathFile () );
        if ( !targetScheme.empty () )
            targetUri.setScheme ( targetScheme );
        else
            targetUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

        // Generate the target file name
        return targetUri;
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::add2DPlacement ( COLLADASW::Texture* colladaTexture, MObject texture )
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
    void EffectTextureExporter::add3DProjection ( COLLADASW::Texture* colladaTexture, MObject projection )
    {
        int projectionType;
        DagHelper::getPlugValue ( projection, ATTR_PROJECTION_TYPE, projectionType );
        String strProjectionType = ShaderHelper::projectionTypeToString ( projectionType );
        colladaTexture->addExtraTechniqueChildParameter (
            PROFILE_MAYA,
            MAYA_PROJECTION_ELEMENT,
            MAYA_PROJECTION_TYPE_PARAMETER,
            strProjectionType );

        MMatrix projectionMx;
        DagHelper::getPlugValue ( projection, ATTR_PLACEMENT_MATRIX, projectionMx );
        double sceneMatrix[4][4];
        convertMayaMatrixToTransposedDouble4x4 ( sceneMatrix, projectionMx, getTolerance () );

        // Convert the  maya internal unit type of the transform part of the
        // matrix from centimeters into the working units of the current scene!
        for ( uint i=0; i<3; ++i)
            sceneMatrix [i][3] = MDistance::internalToUI ( sceneMatrix [i][3] );

        colladaTexture->addExtraTechniqueChildParameter (
            PROFILE_MAYA,
            MAYA_PROJECTION_ELEMENT,
            MAYA_PROJECTION_MATRIX_PARAMETER,
            sceneMatrix );
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::addBoolParameter (
        COLLADASW::Texture* colladaTexture,
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
            String paramSid = EMPTY_STRING; if ( animated ) paramSid = plugName;
            colladaTexture->addExtraTechniqueParameter ( PROFILE_MAYA, plugName, value, paramSid );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::addFloatParameter (
        COLLADASW::Texture* colladaTexture,
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
            String paramSid = EMPTY_STRING; if ( animated ) paramSid = plugName;
            colladaTexture->addExtraTechniqueParameter ( PROFILE_MAYA, plugName, value, paramSid );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::addAngleParameter (
        COLLADASW::Texture* colladaTexture,
        const char* plugName,
        MFnDependencyNode &placement2d )
    {
        MStatus status;
        MPlug plug = placement2d.findPlug ( plugName, &status );
        if ( status == MStatus::kSuccess )
        {
            float angleRad;
            plug.getValue ( angleRad );
            float angleDeg = COLLADABU::Math::Utils::radToDegF ( angleRad );

            // The target id for the animation
            String targetSid = mAnimationTargetPath + plugName;

            // Create the animation
            AnimationExporter* animationExporter = mDocumentExporter->getAnimationExporter();
            bool animated = animationExporter->addPlugAnimation ( plug, targetSid, kBoolean );

            // Add the parameter
            String paramSid = EMPTY_STRING; 
            if ( animated ) paramSid = plugName;
            colladaTexture->addExtraTechniqueParameter ( PROFILE_MAYA, plugName, angleDeg, paramSid );
        }
    }

    // ------------------------------------------------------------
    void EffectTextureExporter::openTechnique()
    {
        if ( !mTechniqueIsOpen )
        {
            COLLADASW::StreamWriter* streamWriter = mDocumentExporter->getStreamWriter();

            mExtraSource = new COLLADASW::Extra ( streamWriter );
            mExtraSource->openExtra();

            mTechniqueSource = new COLLADASW::Technique ( streamWriter );
            mTechniqueSource->openTechnique ( PROFILE_MAYA );

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
    bool EffectTextureExporter::getTextureFileInfos ( 
        const COLLADASW::URI &sourceUri, 
        COLLADASW::URI &fullFileNameURI )
    {
        bool returnValue = true;

        // Check if the file exist!
        String sourceUriString = sourceUri.toNativePath();

        if ( ExportOptions::relativePaths() )
        {
            // Different filename and URI, if we copy the textures to the destination directory!
            if ( ExportOptions::copyTextures() )
            {
                // Get the URI of the COLLADA file.
                String targetColladaFile = mDocumentExporter->getFilename();
                COLLADASW::URI targetColladaUri ( COLLADASW::URI::nativePathToUri ( targetColladaFile ) );
                if ( targetColladaUri.getScheme ().empty () )
                    targetColladaUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

                // Get the URI of the copied texture file.
                COLLADASW::URI textureUri = createTargetURI ( sourceUri );

                // Get the texture URI relative to the COLLADA file URI.
                bool success = false;
                COLLADASW::URI targetUri = textureUri.getRelativeTo ( targetColladaUri, success );
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
                COLLADASW::URI targetColladaUri ( COLLADASW::URI::nativePathToUri ( targetColladaFile ) );
                if ( targetColladaUri.getScheme ().empty () )
                    targetColladaUri.setScheme ( COLLADASW::URI::SCHEME_FILE );

                // Get the texture URI relative to the COLLADA file URI.
                bool success = false;
                COLLADASW::URI targetUri = sourceUri.getRelativeTo ( targetColladaUri, success );
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
                COLLADASW::URI targetUri = createTargetURI ( sourceUri );

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
