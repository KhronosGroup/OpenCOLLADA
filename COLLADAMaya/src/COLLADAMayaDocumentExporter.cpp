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
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaSceneGraph.h"
#include "COLLADAMayaGeometryExporter.h"
#include "COLLADAMayaVisualSceneExporter.h"
#include "COLLADAMayaEffectExporter.h"
#include "COLLADAMayaImageExporter.h"
#include "COLLADAMayaMaterialExporter.h"
#include "COLLADAMayaAnimationExporter.h"
#include "COLLADAMayaAnimationClipExporter.h"
#include "COLLADAMayaAnimationSampleCache.h"
#include "COLLADAMayaControllerExporter.h"
#include "COLLADAMayaLightExporter.h"
#include "COLLADAMayaCameraExporter.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaConversion.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaReferenceManager.h"

#include "COLLADASWAsset.h"
#include "COLLADASWScene.h"
#include "COLLADASWConstants.h"

#include <maya/MFileIO.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    DocumentExporter::DocumentExporter ( const NativeString& fileName )
        : mStreamWriter ( fileName, ExportOptions::doublePrecision () )
            , mFileName ( fileName )
            , mSceneGraph ( NULL )
            , mIsImport ( true )
            , mAnimationCache ( NULL )
            , mMaterialExporter ( NULL )
            , mEffectExporter ( NULL )
            , mImageExporter ( NULL )
            , mGeometryExporter ( NULL )
            , mVisualSceneExporter ( NULL )
            , mAnimationExporter ( NULL )
            , mAnimationClipExporter ( NULL )
            , mControllerExporter ( NULL )
            , mLightExporter ( NULL )
            , mCameraExporter ( NULL )
            , mSceneId ( "MayaScene" )
            , mDigitTolerance (FLOAT_TOLERANCE)
    {
        if ( ExportOptions::doublePrecision () )
        {
            mDigitTolerance = DOUBLE_TOLERANCE;
        }
    }

    //---------------------------------------------------------------
    DocumentExporter::~DocumentExporter()
    {
        releaseLibraries(); // The libraries should already have been released
    }

    //---------------------------------------------------------------
    // Create the parsing libraries: we want access to the libraries only during import/export time.
    void DocumentExporter::createLibraries()
    {
        releaseLibraries();
        
        // Get the sceneID (assign a name to the scene)
        MString sceneName;
        MGlobal::executeCommand ( MString ( "file -q -ns" ), sceneName );
        if ( sceneName.length() != 0 ) mSceneId = sceneName.asChar();

        // Initialize the reference manager
        ReferenceManager::getInstance()->initialize ();

        // Create the cache for the animations
        mAnimationCache = new AnimationSampleCache();

        // Create the basic elements
        mSceneGraph = new SceneGraph ( this );
        mMaterialExporter = new MaterialExporter ( &mStreamWriter, this );
        mEffectExporter = new EffectExporter ( &mStreamWriter, this );
        mImageExporter = new ImageExporter ( &mStreamWriter );
        mGeometryExporter = new GeometryExporter ( &mStreamWriter, this );
        mVisualSceneExporter = new VisualSceneExporter ( &mStreamWriter, this, mSceneId );
        mAnimationExporter = new AnimationExporter ( &mStreamWriter, this );
        mAnimationClipExporter = new AnimationClipExporter ( &mStreamWriter );
        mControllerExporter = new ControllerExporter ( &mStreamWriter, this );
        mLightExporter = new LightExporter ( &mStreamWriter, this );
        mCameraExporter = new CameraExporter ( &mStreamWriter, this );
    }

    //---------------------------------------------------------------
    void DocumentExporter::releaseLibraries()
    {
        delete mAnimationCache;
        delete mSceneGraph;
        delete mMaterialExporter;
        delete mEffectExporter;
        delete mImageExporter;
        delete mGeometryExporter;
        delete mVisualSceneExporter;
        delete mAnimationExporter;
        delete mAnimationClipExporter;
        delete mControllerExporter;
        delete mLightExporter;
        delete mCameraExporter;
    }


    //---------------------------------------------------------------
    void DocumentExporter::exportCurrentScene ( bool selectionOnly )
    {
        mIsImport = false;

        // Create the import/export library helpers.
        createLibraries();

        mStreamWriter.startDocument();

        // Build the scene graph
        if ( mSceneGraph->create ( selectionOnly ) )
        {
            // Start by caching the expressions that will be sampled
            mSceneGraph->sampleAnimationExpressions();

            // Export the asset of the document.
            exportAsset();

            // Export the lights.
            mLightExporter->exportLights();

            // Export the cameras.
            mCameraExporter->exportCameras();

            // Export the material URLs and get the material list
            MaterialMap* materialMap = mMaterialExporter->exportMaterials();

            // Export the effects (materials)
            const ImageMap* imageMap = mEffectExporter->exportEffects ( materialMap );

            // Export the images
            mImageExporter->exportImages ( imageMap );

            // Export the controllers. Must be done before the geometries, to decide, which
            // geometries have to be exported (for example, if the controller need an invisible 
            // geometry, we also have to export it).
            mControllerExporter->exportControllers();

            // Export the geometries
            mGeometryExporter->exportGeometries();

            // Export the visual scene
            bool visualSceneExported = mVisualSceneExporter->exportVisualScenes();

            // Export the animations
            const AnimationClipList* animationClips = mAnimationExporter->exportAnimations();

            // Export the animation clips
            mAnimationClipExporter->exportAnimationClips ( animationClips );

            // Export the scene
            if ( visualSceneExported ) exportScene();

            // TODO
            /*
            // Export rigid constraints if required.
            if (CExportOptions::ExportPhysics())
            {
             // save non physics animation library in case want to use again
             DaeAnimationLibrary* nonPhysAnimationLibrary = animationLibrary;
             animationLibrary = new DaeAnimationLibrary(this, false);

             nativePhysicsScene->finish();
             ageiaPhysicsScene->finish();

             //  animationLibrary->ExportAnimations();
             SAFE_DELETE(animationLibrary);
             animationLibrary = nonPhysAnimationLibrary;
            }

            // Retrieve the unit name and set the asset's unit information
            MString unitName;
            MGlobal::executeCommand("currentUnit -q -linear -fullName;", unitName);
            colladaDocument->GetAsset()->SetUnitName(MConvert::ToFChar(unitName));
            FCDocumentTools::StandardizeUpAxisAndLength(colladaDocument, FMVector3::Origin, conversionFactor);

            // Write out the FCollada document.
            colladaDocument->GetFileManager()->SetForceAbsoluteFlag(!CExportOptions::RelativePaths());
            FCollada::SaveDocument(colladaDocument, MConvert::ToFChar(filename));

            // Release the import/export library helpers
            ReleaseLibraries();
            colladaNode->ReleaseAllEntityNodes();
            */
        }

        mStreamWriter.endDocument();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportAsset()
    {
        COLLADASW::Asset asset ( &mStreamWriter );

        // Add contributor information
        // Set the author
        char* userName = getenv ( USERNAME );

        if ( userName == NULL || *userName == 0 ) userName = getenv ( USER );
        if ( userName != NULL && *userName != 0 ) asset.getContributor().mAuthor = String ( userName );

        // Source is the scene we have exported from
        String currentScene = MFileIO::currentFile().asChar();
        if ( currentScene.size() > 0 )
        {
            COLLADASW::URI sourceFileUri ( COLLADASW::URI::nativePathToUri ( currentScene ) );
            sourceFileUri.setScheme ( COLLADASW::URI::SCHEME_FILE );
            asset.getContributor().mSourceData = sourceFileUri.getURIString();
        }

        asset.getContributor().mAuthoringTool = AUTHORING_TOOL_NAME + MGlobal::mayaVersion().asChar();

        // comments
        MString optstr = MString ( "ColladaMaya export options: \nbakeTransforms=" ) + ExportOptions::bakeTransforms()
                         + ";exportPolygonMeshes=" + ExportOptions::exportPolygonMeshes() + ";bakeLighting=" + ExportOptions::bakeLighting()
                         + ";\nisSampling=" + ExportOptions::isSampling() + ";curveConstrainSampling=" + ExportOptions::curveConstrainSampling()
                         + ";removeStaticCurves=" + ExportOptions::removeStaticCurves() + ";\nexportCameras=" + ExportOptions::exportCameras() 
                         + ";exportCameraAsLookat=" + ExportOptions::exportCameraAsLookat() + ";exportLights=" + ExportOptions::exportLights() 
                         + ";exportJointsAndSkin=" + ExportOptions::exportJointsAndSkin() + ";\nexportAnimations=" + ExportOptions::exportAnimations()
                         + ";exportTriangles=" + ExportOptions::exportTriangles() + ";exportInvisibleNodes=" + ExportOptions::exportInvisibleNodes()
                         + ";\nexportNormals=" + ExportOptions::exportNormals() + ";exportTexCoords=" + ExportOptions::exportTexCoords()
                         + ";\nexportVertexColors=" + ExportOptions::exportVertexColors() + ";exportVertexColorsAnimation=" + ExportOptions::exportVertexColorAnimations()
                         + ";exportTangents=" + ExportOptions::exportTangents() + ";exportTexTangents=" + ExportOptions::exportTexTangents() 
                         + ";\nexportXRefs=" + ExportOptions::exportXRefs() + ";dereferenceXRefs=" + ExportOptions::dereferenceXRefs() 
                         + ";\ncameraXFov=" + ExportOptions::cameraXFov() + ";cameraYFov=" + ExportOptions::cameraYFov() 
                         + "doublePrecision=" + ExportOptions::doublePrecision ();
        asset.getContributor().mComments = optstr.asChar();

        // Up axis
        if ( MGlobal::isYAxisUp() ) 
            asset.setUpAxisType ( COLLADASW::Asset::Y_UP );
        else if ( MGlobal::isZAxisUp() ) 
            asset.setUpAxisType ( COLLADASW::Asset::Z_UP );

        // Retrieve the linear unit name
        MString mayaLinearUnitName;
        MGlobal::executeCommand ( "currentUnit -q -linear -fullName;", mayaLinearUnitName );
        String linearUnitName = mayaLinearUnitName.asChar();

        // Get the UI unit type (internal units are centimeter, collada want
        // a number relative to meters).
        // All transform components with units will be in maya's internal units
        // (radians for rotations and centimeters for translations).
        MDistance testDistance ( 1.0f, MDistance::uiUnit() );

        // Get the conversion factor relative to meters for the collada document.
        // For example, 1.0 for the name "meter"; 1000 for the name "kilometer";
        // 0.3048 for the name "foot".
        double colladaConversionFactor = ( float ) testDistance.as ( MDistance::kMeters );
        float colladaUnitFactor = float ( 1.0 / colladaConversionFactor );
        asset.setUnit ( linearUnitName, colladaConversionFactor );

        // Asset heraus schreiben
        asset.add();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportScene()
    {
        COLLADASW::Scene scene ( &mStreamWriter, COLLADASW::URI ( COLLADABU::Utils::EMPTY_STRING, VISUAL_SCENE_NODE_ID ) );
        scene.add();
    }

    //---------------------------------------------------------------
    void DocumentExporter::endExport()
    {
        // TODO

        // Complete the export of controllers and animations
        // doc->GetControllerLibrary()->CompleteControllerExport();
        //  doc->GetAnimationCache()->SamplePlugs();
        //  doc->GetAnimationLibrary()->PostSampling();


        // Write out the scene parameters
        //  CDOC->SetStartTime((float) AnimationHelper::AnimationStartTime().as(MTime::kSeconds));
        //  CDOC->SetEndTime((float) AnimationHelper::AnimationEndTime().as(MTime::kSeconds));
    }

    //---------------------------
    String DocumentExporter::mayaNameToColladaName ( const MString& str, bool removeNamespace )
    {
        // Replace characters that are supported in Maya,
        // but not supported in collada names

        // NathanM: Strip off namespace prefixes
        // TODO: Should really be exposed as an option in the Exporter
        MString mayaName;
        if ( removeNamespace )
        {
            int prefixIndex = str.rindex ( ':' );
            mayaName = ( prefixIndex < 0 ) ? str : str.substring ( prefixIndex + 1, str.length() );
        }
        else mayaName = str;

        const char* c = mayaName.asChar();
        uint length = mayaName.length();
        char* buffer = new char[length+1];

        // Replace offending characters by some that are supported within xml:
        // ':', '|' are replaced by '_'.
        // Ideally, these should be encoded as '%3A' for ':', etc. and decoded at import time.
        //
        for ( uint i = 0; i < length; ++i )
        {
            char d = c[i];

            if ( d == '|' || d == ':' || d == '/' || d == '\\' || d == '(' || d == ')' || d == '[' || d == ']' )
                d = '_';

            buffer[i] = d;
        }
        buffer[length] = '\0';

        MString mayaReturnString ( buffer );
        delete buffer;

        return COLLADABU::Utils::checkNCName( mayaReturnString.asChar() );
    }

    //---------------------------
    String DocumentExporter::dagPathToColladaId ( const MDagPath& dagPath )
    {
        // Make an unique COLLADA Id from a dagPath.
        // We are free to use anything we want for Ids. For now use
        // a honking unique name for readability - but in future we
        // could just use an incrementing integer
        return mayaNameToColladaName ( dagPath.partialPathName(), false );
    }

    //---------------------------
    String DocumentExporter::dagPathToColladaName ( const MDagPath& dagPath )
    {
        // Get a COLLADA suitable node name from a DAG path
        // For import/export symmetry, this should be exactly the
        // Maya node name. If we include any more of the path, we'll
        // get viral node names after repeated import/export.
        MFnDependencyNode node ( dagPath.node() );
        return mayaNameToColladaName ( node.name(), true );
    }

    //---------------------------
    SceneGraph* DocumentExporter::getSceneGraph()
    {
        return mSceneGraph;
    }

    //---------------------------
    const SceneGraph* DocumentExporter::getSceneGraph() const
    {
        return mSceneGraph;
    }

    //---------------------------
    const String& DocumentExporter::getFilename() const
    {
        return mFileName;
    }

    //---------------------------
    COLLADASW::StreamWriter* DocumentExporter::getStreamWriter()
    {
        return &mStreamWriter;
    }

    //---------------------------
    AnimationSampleCache* DocumentExporter::getAnimationCache()
    {
        return mAnimationCache;
    }

    //---------------------------
    MaterialExporter* DocumentExporter::getMaterialExporter()
    {
        return mMaterialExporter;
    }

    //---------------------------
    EffectExporter* DocumentExporter::getEffectExporter()
    {
        return mEffectExporter;
    }

    //---------------------------
    ImageExporter* DocumentExporter::getImageExporter()
    {
        return mImageExporter;
    }

    //---------------------------
    GeometryExporter* DocumentExporter::getGeometryExporter()
    {
        return mGeometryExporter;
    }

    //---------------------------
    VisualSceneExporter* DocumentExporter::getVisualSceneExporter()
    {
        return mVisualSceneExporter;
    }

    //---------------------------
    AnimationExporter* DocumentExporter::getAnimationExporter()
    {
        return mAnimationExporter;
    }

    //---------------------------
    AnimationClipExporter* DocumentExporter::getAnimationClipExporter()
    {
        return mAnimationClipExporter;
    }

    //---------------------------
    ControllerExporter* DocumentExporter::getControllerExporter()
    {
        return mControllerExporter;
    }

    //---------------------------
    LightExporter* DocumentExporter::getLightExporter()
    {
        return mLightExporter;
    }

    //---------------------------
    CameraExporter* DocumentExporter::getCameraExporter()
    {
        return mCameraExporter;
    }

    //---------------------------
    const String& DocumentExporter::getSceneID()
    {
        return mSceneId;
    }

    //---------------------------
    const bool DocumentExporter::getExportSelectedOnly () const
    {
        return getSceneGraph ()->getExportSelectedOnly ();
    }
}
