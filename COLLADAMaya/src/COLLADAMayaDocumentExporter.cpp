/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
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
#include "COLLADAMayaControllerLibrary.h"
#include "COLLADAMayaDagHelper.h"
#include "COLLADAMayaShaderHelper.h"
#include "COLLADAMayaConvert.h"
#include "COLLADAMayaExportOptions.h"

#include "COLLADAAsset.h"
#include "COLLADAScene.h"
#include "COLLADAUtils.h"
#include "COLLADASWC.h"

#include <maya/MFileIO.h>


namespace COLLADAMaya
{

    //---------------------------------------------------------------
    DocumentExporter::DocumentExporter ( const String& _fileName )
            : mStreamWriter ( _fileName )
            , mFileName ( _fileName )
            , mSceneGraph ( NULL )
            , mUnitFactor ( 1.0f )
            , mIsImport ( true )
            , mAnimationCache ( NULL )
            , mMaterialExporter ( NULL )
            , mEffectExporter ( NULL )
            , mImageExporter ( NULL )
            , mGeometryExporter ( NULL )
            , mVisualSceneExporter ( NULL )
            , mAnimationExporter ( NULL )
            , mAnimationClipExporter ( NULL )
            , mControllerLibrary ( NULL )
            , mSceneId ( "MayaScene" )
    {
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

        mControllerLibrary = new ControllerLibrary ( &mStreamWriter, this );
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
        delete mControllerLibrary;
    }


    //---------------------------------------------------------------
    void DocumentExporter::exportCurrentScene ( bool selectionOnly )
    {
        // Create the import/export library helpers.
        mIsImport = false;
        createLibraries();

        // Get the UI unit type (internal units are centimeter)
        MDistance testDistance ( 1.0f, MDistance::uiUnit() );
        float conversionFactor = ( float ) testDistance.as ( MDistance::kMeters );
        mUnitFactor = 1.0f / conversionFactor;

        mStreamWriter.startDocument();

        if ( mSceneGraph->create ( selectionOnly ) )
        {
            // Export the asset of the document.
            exportAsset();

            // Export the material URLs and get the material list
            MaterialMap* materialMap = mMaterialExporter->exportMaterials();

            // Export the effects (materials)
            const ImageMap* imageMap = mEffectExporter->exportEffects ( materialMap );

            // Export the images
            mImageExporter->exportImages ( imageMap );

            // Export the geometries and the controllers
            mGeometryExporter->exportGeometries();

            // Export the visual scene
            mVisualSceneExporter->exportVisualScenes();

            // Export the animations
            const AnimationClipList* animationClips = mAnimationExporter->exportAnimations();

            // Export the animation clips
            mAnimationClipExporter->exportAnimationClips ( animationClips );

            // Export the scene
            exportScene();


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
        COLLADA::Asset asset ( &mStreamWriter );

        // Add contributor information
        // Set the author
        TCHAR* userName = getenv ( "USERNAME" );

        if ( userName == NULL || *userName == 0 ) userName = getenv ( "USER" );

        if ( userName != NULL && *userName != 0 ) asset.getContributor().mAuthor = String ( userName );

        //  asset.getContributor().mSourceData =
        //   COLLADA::Utils::FILE_PROTOCOL + COLLADA::Utils::UriEncode(fileName);

        // source is the scene we have exported from
        MString currentScene = MFileIO::currentFile();

        if ( currentScene.length() != 0 )
        {
            // Intentionally not relative
            //  FUUri uri(colladaDocument->GetFileManager()->GetCurrentUri().MakeAbsolute(MConvert::ToFChar(currentScene)));
            //  fstring sourceDocumentPath = uri.GetAbsolutePath();
            String sourceFile = COLLADA::Utils::FILE_PROTOCOL + COLLADA::Utils::UriEncode ( currentScene.asChar() );
            asset.getContributor().mSourceData = sourceFile;
        }

        asset.getContributor().mAuthoringTool = "COLLADA Maya2008";

        // comments
        MString optstr = MString ( "ColladaMaya export options: bakeTransforms=" ) + ExportOptions::bakeTransforms()
                         + ";exportPolygonMeshes=" + ExportOptions::exportPolygonMeshes() + ";bakeLighting=" + ExportOptions::bakeLighting()
                         + ";isSampling=" + ExportOptions::isSampling() + ";\ncurveConstrainSampling=" + ExportOptions::curveConstrainSampling()
                         + ";removeStaticCurves=" + ExportOptions::removeStaticCurves() + ";exportCameraAsLookat=" + ExportOptions::exportCameraAsLookat()
                         + ";\nexportLights=" + ExportOptions::exportLights() + ";exportCameras=" + ExportOptions::exportCameras()
                         + ";exportJointsAndSkin=" + ExportOptions::exportJointsAndSkin() + ";\nexportAnimations=" + ExportOptions::exportAnimations()
                         + ";exportTriangles=" + ExportOptions::exportTriangles() + ";exportInvisibleNodes=" + ExportOptions::exportInvisibleNodes()
                         + ";\nexportNormals=" + ExportOptions::exportNormals() + ";exportTexCoords=" + ExportOptions::exportTexCoords()
                         + ";\nexportVertexColors=" + ExportOptions::exportVertexColors()
                         + ";exportVertexColorsAnimation=" + ExportOptions::exportVertexColorAnimations()
                         + ";exportTangents=" + ExportOptions::exportTangents()
                         + ";\nexportTexTangents=" + ExportOptions::exportTexTangents() + ";exportConstraints=" + ExportOptions::ExportConstraints()
                         + ";exportPhysics=" + ExportOptions::ExportPhysics() + ";exportXRefs=" + ExportOptions::exportXRefs()
                         + ";\ndereferenceXRefs=" + ExportOptions::dereferenceXRefs() + ";cameraXFov=" + ExportOptions::cameraXFov()
                         + ";cameraYFov=" + ExportOptions::cameraYFov();
        asset.getContributor().mComments = optstr.asChar();

        // Up axis

        if ( MGlobal::isYAxisUp() ) asset.setUpAxisType ( COLLADA::Asset::Y_UP );
        else if ( MGlobal::isZAxisUp() ) asset.setUpAxisType ( COLLADA::Asset::Z_UP );

        // Retrieve the unit name and set the asset's unit information
        MString unitName;

        MGlobal::executeCommand ( "currentUnit -q -linear -fullName;", unitName );

        // Get the UI unit type (internal units are centimeter)
        MDistance testDistance ( 1.0f, MDistance::uiUnit() );

        float conversionFactor = ( float ) testDistance.as ( MDistance::kMeters );

        double uiUnitFactor = 1.0f / conversionFactor;

        asset.setUnit ( unitName.asChar(), conversionFactor );

        // TODO
        // FCDocumentTools::StandardizeUpAxisAndLength(colladaDocument, FMVector3::Origin, conversionFactor);

        // Asset herausschreiben
        asset.add();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportScene()
    {
        COLLADA::Scene scene ( &mStreamWriter );
        scene.mInstanceVisualSceneUrl = "#" + mSceneId;
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

    //---------------------------------------------------------------
    // Replace characters that are supported in Maya,
    // but not supported in collada names
    String DocumentExporter::mayaNameToColladaName ( const MString& str, bool removeNamespace )
    {
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

        MString returnString ( buffer );
        delete buffer;

        return returnString.asChar();
    }

    //---------------------------------------------------------------
    // Make an unique COLLADA Id from a dagPath.
    // We are free to use anything we want for Ids. For now use
    // a honking unique name for readability - but in future we
    // could just use an incrementing integer
    //
    String DocumentExporter::dagPathToColladaId ( const MDagPath& dagPath )
    {
        return mayaNameToColladaName ( dagPath.partialPathName(), false );
    }


    //---------------------------------------------------------------
    // Get a COLLADA suitable node name from a DAG path
    // For import/export symmetry, this should be exactly the
    // Maya node name. If we include any more of the path, we'll
    // get viral node names after repeated import/export.
    //
    String DocumentExporter::dagPathToColladaName ( const MDagPath& dagPath )
    {
        MFnDependencyNode node ( dagPath.node() );
        return mayaNameToColladaName ( node.name(), true );
    }


    //---------------------------------------------------------------
    // Make a COLLADA name suitable for a DAG name
    //
    String DocumentExporter::colladaNameToDagName ( const MString& dagPath )
    {
        int length = dagPath.length();
        char* tmp = new char[length + 1];
        const char* c = dagPath.asChar();

        for ( int i = 0; i <= length; i++ )
        {
            if ( ( tmp[i] = c[i] ) == '.' )
            {
                tmp[i] =  '_';
            }
        }

        MString rv ( tmp, length );

        delete[] tmp;
        return rv.asChar();
    }

}