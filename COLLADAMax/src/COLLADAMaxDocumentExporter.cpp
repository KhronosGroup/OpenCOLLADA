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

#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxDocumentExporter.h"
#include "COLLADAMaxGeometryExporter.h"
#include "COLLADAMaxVisualSceneExporter.h"
#include "COLLADAMaxEffectExporter.h"
#include "COLLADAMaxAnimationExporter.h"
#include "COLLADAMaxMaterialExporter.h"
#include "COLLADAMaxImageExporter.h"

#include "COLLADAAsset.h"
#include "COLLADAScene.h"
#include "COLLADASWC.h"

namespace COLLADAMax
{

    const String DocumentExporter::SCENE_ID = "MaxScene";

    //---------------------------------------------------------------
    DocumentExporter::DocumentExporter ( Interface * i, const String &filepath )
            : mMaxInterface ( i ),
            mStreamWriter ( filepath ),
            mExportSceneGraph ( mMaxInterface->GetRootNode() )
    {}


    //---------------------------------------------------------------
    void DocumentExporter::exportCurrentMaxScene()
    {
        mStreamWriter.startDocument();

        if ( createExportSceneGraph() )
        {

            createExporters();

            exportAsset();
            exportEffects();
            exportMaterials();
            exportImages();
            exportGeometries();
            exportVisualScenes();
            exportAnimations();
            exportScene();

            deleteExporters();
        }

        mStreamWriter.endDocument();
    }

    //---------------------------------------------------------------
    bool DocumentExporter::createExportSceneGraph()
    {
        return mExportSceneGraph.create ( mOptions.exportSelected() );
    }

    //---------------------------------------------------------------
    void DocumentExporter::createExporters()
    {
        mEffectExporter = new EffectExporter ( &mStreamWriter, &mExportSceneGraph, this );
        mMaterialExporter = new MaterialExporter ( &mStreamWriter, this );
        mAnimationExporter = new AnimationExporter ( &mStreamWriter, this );

    }

    //---------------------------------------------------------------
    void DocumentExporter::exportAsset()
    {
        COLLADA::Asset asset ( &mStreamWriter );

        // Add contributor information
        // Set the author
        String userName = getEnvironmentVariable ( "USERNAME" );

        if ( userName.empty() )
            userName = getEnvironmentVariable ( "USER" );

        if ( !userName.empty() )
            asset.getContributor().mAuthor = String ( userName );

        const TSTR& filename = getMaxInterface() ->GetCurFilePath();

        asset.getContributor().mSourceData = COLLADA::Utils::FILE_PROTOCOL + COLLADA::Utils::UriEncode ( String ( filename.data() ) );

        asset.getContributor().mAuthoringTool = "COLLADAMax";


        // set *system* unit information
        int systemUnitType;

        float systemUnitScale;

        GetMasterUnitInfo ( &systemUnitType, &systemUnitScale );

        switch ( systemUnitType )
        {

        case UNITS_INCHES:
            asset.setUnit ( "inch", systemUnitScale * 0.0254f );
            break;

        case UNITS_FEET:
            asset.setUnit ( "feet", systemUnitScale * 0.3048f );
            break;

        case UNITS_MILES:
            asset.setUnit ( "mile", systemUnitScale * 1609.344f );
            break;

        case UNITS_MILLIMETERS:
            asset.setUnit ( "millimeter", systemUnitScale * 0.001f );
            break;

        case UNITS_CENTIMETERS:
            asset.setUnit ( "centimeter", systemUnitScale * 0.01f );
            break;

        case UNITS_METERS:
            asset.setUnit ( "meter", systemUnitScale );
            break;

        case UNITS_KILOMETERS:
            asset.setUnit ( "kilometer", systemUnitScale * 1000.0f );
            break;

        default:
            break;
        }

        asset.setUpAxisType ( COLLADA::Asset::Z_UP );

        asset.add();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportGeometries()
    {
        GeometriesExporter geometriesExporter ( &mStreamWriter, &mExportSceneGraph, this );
        geometriesExporter.doExport();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportEffects()
    {
        mEffectExporter->doExport();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportMaterials()
    {
        mMaterialExporter->doExport();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportImages()
    {
        ImageExporter imageExporter ( &mStreamWriter, this );
        imageExporter.doExport();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportVisualScenes()
    {
        VisualSceneExporter visualSceneExporter ( &mStreamWriter, &mExportSceneGraph, SCENE_ID, this );
        visualSceneExporter.doExport();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportAnimations()
    {
        mAnimationExporter->doExport();
    }

    //---------------------------------------------------------------
    void DocumentExporter::exportScene()
    {
        COLLADA::Scene scene ( &mStreamWriter );
        scene.mInstanceVisualSceneUrl = "#" + SCENE_ID;
        scene.add();
    }

    //---------------------------------------------------------------
    void DocumentExporter::deleteExporters()
    {
        delete mEffectExporter;
        mEffectExporter = 0;

        delete mMaterialExporter;
        mMaterialExporter = 0;

        delete mAnimationExporter;
        mAnimationExporter = 0;
    }

    //---------------------------------------------------------------
    String DocumentExporter::getEnvironmentVariable ( const String & variableName )
    {
        char * buffer;
        size_t numberOfElements;
        errno_t error = _dupenv_s ( &buffer, &numberOfElements, variableName.c_str() );

        if ( error != 0 )
        {
            free ( buffer );
            return String();
        }

        String variableValue ( buffer, numberOfElements-1 );

        free ( buffer );
        return variableValue;
    }
}
