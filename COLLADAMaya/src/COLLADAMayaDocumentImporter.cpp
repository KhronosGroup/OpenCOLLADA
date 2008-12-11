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
#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaReferenceManager.h"
#include "COLLADAMayaImportOptions.h"
#include "COLLADAMayaMaterialImporter.h"
#include "COLLADAMayaGeometryImporter.h"
#include "COLLADAMayaCameraImporter.h"
#include "COLLADAMayaVisualSceneImporter.h"

//#include "COLLADADHDocumentUtil.h"

//#include "dom/domTypes.h"

#include <maya/MFileIO.h>

#include "COLLADASaxFWLMeshLoader.h"
#include "COLLADASaxFWLSource.h"
#include "COLLADASaxFWLPolylist.h"
#include "COLLADASaxFWLPrimitiveBase.h"

//#include "COLLADASaxFWLVCountArray.h"


namespace COLLADAMaya
{
    static double positions[] = {-7.5, -2.5, 5, 7.5, -2.5, 5, -7.5, 2.5, 5, 7.5, 2.5, 5, -7.5, 2.5, -5, 7.5, 2.5, -5, -7.5, -2.5, -5, 7.5, -2.5, -5};
    static size_t positionsCount = 24;

    static double normals[] = {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0};
    static size_t normalsCount = 72;

    static double uvCoords[] = {0.375, 0, 0.625, 0, 0.375, 0.25, 0.625, 0.25, 0.375, 0.5, 0.625, 0.5, 0.375, 0.75, 0.625, 0.75, 0.375, 1, 0.625, 1, 0.875, 0, 0.875, 0.25, 0.125, 0, 0.125, 0.25};
    static size_t uvCoordsCount = 28;

    static unsigned int pElementValues[] = {0, 0, 0, 1, 1, 1, 3, 2, 3, 2, 3, 2, 2, 4, 2, 3, 5, 3, 5, 6, 5, 4, 7, 4, 4, 8, 4, 5, 9, 5, 7, 10, 7, 6, 11, 6, 6, 12, 6, 7, 13, 7, 1, 14, 9, 0, 15, 8, 1, 16, 1, 7, 17, 10, 5, 18, 11, 3, 19, 3, 6, 20, 12, 0, 21, 0, 2, 22, 2, 4, 23, 13};
    static size_t pElementValuesSize = 72;

    static unsigned int faceVertexCounts[] = {4, 4, 4, 4, 4, 4};
    static size_t faceCount = 6;

    //---------------------------------
    DocumentImporter::DocumentImporter ( const String& fileName )
        : mFileName ( fileName )
//         , mMaterialImporter ( NULL )
//         , mGeometryImporter ( NULL )
//         , mCameraImporter ( NULL )
//         , mVisualSceneImporter ( NULL )
        , mSceneId ( "MayaScene" )
    {
    }

    //---------------------------------
    DocumentImporter::~DocumentImporter()
    {
        releaseLibraries(); 
    }

    //---------------------------------
    void DocumentImporter::createLibraries()
    {
        // First release the existing libraries.
        releaseLibraries();

        // Get the sceneID (assign a name to the scene)
        MString sceneName = MFileIO::currentFile ();
        if ( sceneName.length() != 0 ) mSceneId = sceneName.asChar();

        // Initialize the reference manager
        ReferenceManager::getInstance()->initialize ();

//         // Parse the dae document, then create the libraries
//         // (the importers want to have a reference to the document).
//         String filename = getFilename ();
//         String fileUriString = COLLADASW::URI::nativePathToUri ( filename );
//         mColladaDoc = mDae.open ( fileUriString );
//         daeDocument* daeDoc = mColladaDoc->getDocument();

//         // Create the basic elements
//         mMaterialImporter = new MaterialImporter ( this );
//         mGeometryImporter = new GeometryImporter ( this );
//         mCameraImporter = new CameraImporter ();
//         mVisualSceneImporter = new VisualSceneImporter ( this );

    }

    //---------------------------------
    void DocumentImporter::releaseLibraries()
    {
//         delete mMaterialImporter;
//         delete mGeometryImporter;
//         delete mCameraImporter;
//         delete mVisualSceneImporter;
    }

    //-----------------------------
    void DocumentImporter::importCurrentScene()
    {
        // Create the import/export library helpers.
        createLibraries ();

        // Import the asset information.
        importAsset ();

//         // Load the collada document with the dom into the collada framework.
//         String filename = getFilename ();
//         String fileUriString = URI::nativePathToUri ( filename );
//         mDocumentLoader.loadDocument ( fileUriString, &mWriter );



        COLLADAFW::ObjectId objectId = 1;
        COLLADAFW::Geometry geometry ( objectId ); 
        geometry.setId ( "pCubeShape1" );
        geometry.setName ( "pCubeShape1" );

        // The mesh loader class ( fill it with sax!)
        COLLADASaxFWL::MeshLoader meshLoader ( &geometry );

        // Fill the source array
        {
            COLLADASaxFWL::SourceArray sourceArray;

            {
                // Positions
                COLLADASaxFWL::DoubleSource* positionsSource;
                positionsSource = new COLLADASaxFWL::DoubleSource ( objectId++, COLLADASaxFWL::SourceBase::DATA_TYPE_DOUBLE );
                positionsSource->setId ( "pCubeShape1-positions" );
                positionsSource->setStride ( 3 );
                COLLADASaxFWL::DoubleArrayElement* arrayElement = new COLLADASaxFWL::DoubleArrayElement ();
                arrayElement->setId ( "pCubeShape1-positions-array" );
                COLLADAFW::ArrayPrimitiveType<double>* valuesArray = new COLLADAFW::ArrayPrimitiveType<double>();
                valuesArray->setData ( positions, positionsCount );
                arrayElement->setValues ( *valuesArray );
                positionsSource->setArrayElement ( arrayElement );
                sourceArray.append ( positionsSource );
            }
            {
                // Normals
                COLLADASaxFWL::DoubleSource* normalsSource;
                normalsSource = new COLLADASaxFWL::DoubleSource ( objectId++, COLLADASaxFWL::SourceBase::DATA_TYPE_DOUBLE );
                normalsSource->setId ( "pCubeShape1-normals" );
                normalsSource->setStride ( 3 );
                COLLADASaxFWL::DoubleArrayElement* arrayElement = new COLLADASaxFWL::DoubleArrayElement ();
                arrayElement->setId ( "pCubeShape1-normals-array" );
                COLLADAFW::ArrayPrimitiveType<double>* valuesArray = new COLLADAFW::ArrayPrimitiveType<double>();
                valuesArray->setData ( normals, normalsCount );
                arrayElement->setValues ( *valuesArray );
                normalsSource->setArrayElement ( arrayElement );
                sourceArray.append ( normalsSource );
            }
            {
                // UV Coordinates
                COLLADASaxFWL::DoubleSource* uvCoordsSource;
                uvCoordsSource = new COLLADASaxFWL::DoubleSource ( objectId++, COLLADASaxFWL::SourceBase::DATA_TYPE_DOUBLE );
                uvCoordsSource->setId ( "pCubeShape1-map1" );
                uvCoordsSource->setStride ( 2 );
                COLLADASaxFWL::DoubleArrayElement* arrayElement = new COLLADASaxFWL::DoubleArrayElement ();
                arrayElement->setId ( "pCubeShape1-map1-array" );
                COLLADAFW::ArrayPrimitiveType<double>* valuesArray = new COLLADAFW::ArrayPrimitiveType<double>();
                valuesArray->setData ( uvCoords, uvCoordsCount );
                arrayElement->setValues ( *valuesArray );
                uvCoordsSource->setArrayElement ( arrayElement );
                sourceArray.append ( uvCoordsSource );
            }

            meshLoader.setSourceArray ( sourceArray );
        }

        // Fill the vertices
        {
            COLLADASaxFWL::Vertices vertices;
            {
                vertices.setId ( "pCubeShape1-vertices" );

                COLLADASaxFWL::InputUnsharedArray& inputArray = vertices.getInputArray ();

                COLLADABU::URI uri ( "#pCubeShape1-positions" );
                COLLADASaxFWL::InputUnshared* input;
                input = new COLLADASaxFWL::InputUnshared ( COLLADASaxFWL::InputSemantic::POSITION, uri  );
                inputArray.append ( input );
            }
            meshLoader.setVertices ( vertices );
        }

        // Fill a polylist element
        {
            COLLADASaxFWL::Polylist polylist ( &meshLoader );
            polylist.setFaceCount ( faceCount );

            COLLADAFW::UIntValuesArray& vCountArray = polylist.getVCountArray ();
            vCountArray.setData ( faceVertexCounts, faceCount );

            {
                // Vertices
                COLLADASaxFWL::InputShared* input;
                COLLADABU::URI uri ( "#pCubeShape1-vertices" );
                input = new COLLADASaxFWL::InputShared ( COLLADASaxFWL::InputSemantic::VERTEX, uri, 1  );
                polylist.appendInputElement ( input );
            }
            {
                // Normals
                COLLADASaxFWL::InputShared* input;
                COLLADABU::URI uri ( "#pCubeShape1-normals" );
                input = new COLLADASaxFWL::InputShared ( COLLADASaxFWL::InputSemantic::NORMAL, uri, 2  );
                polylist.appendInputElement ( input );
            }
            {
                // uv coordinates
                COLLADASaxFWL::InputShared* input;
                COLLADABU::URI uri ( "#pCubeShape1-map1" );
                input = new COLLADASaxFWL::InputShared ( COLLADASaxFWL::InputSemantic::UV, uri, 3  );
                polylist.appendInputElement ( input );
            }

            {
                // p-element
                COLLADASaxFWL::PElement* pElement;
                pElement = new COLLADASaxFWL::PElement ( pElementValues, pElementValuesSize );
                COLLADASaxFWL::PArray pArray;
                pArray.append ( pElement );
                polylist.setPArray ( pArray );
            }

            // Fill the mesh with the poly base element data.
            meshLoader.addPolyBaseElement ( &polylist );
        }

        // Get the mesh 
        COLLADAFW::Mesh* mesh = meshLoader.getMesh ();
        geometry.setGeometricElement ( mesh );

        mWriter.writeGeometry ( &geometry );


//         // Import the DAG entity libraries
//         mMaterialImporter->importMaterials ();

//        mCameraImporter->Import();
//        mLightImporter->Import();

//        mGeometryImporter->importGeometries ();

//        controllerLibrary->Import();

//        mVisualSceneImporter->importVisualScenes ();

    }

    //---------------------------------
    void DocumentImporter::importAsset()
    {
        // Up_axis
        if ( MGlobal::mayaState() != MGlobal::kBatch )
        {
            if ( ImportOptions::isOpenMode() && ImportOptions::importUpAxis() )
            {
                char upAxis = 'y';
                
//                 daeDocument* daeDoc = mDocumentLoader.getDaeDocument ();
//                 domUpAxisType upAxisType = COLLADADH::DocumentUtil::getUpAxis ( daeDoc );
//                 switch ( upAxisType )
//                 {
//                 case UPAXISTYPE_Z_UP: upAxis = 'z';
//                 case UPAXISTYPE_Y_UP: upAxis = 'y';
//                 case UPAXISTYPE_X_UP:
//                     MGlobal::displayWarning ( "An up_axis of 'X' is not supported by Maya." );
//                 default:
//                     MGlobal::displayWarning ( "Unknown up_axis value." );
//                 }
// 
//                 // Use the MEL commands to set the up_axis. Currently resets the view, if the axis must change..
//                 MString command ( "string $currentAxis = `upAxis -q -ax`; if ($currentAxis != \"" );
//                 command += upAxis; command += "\") { upAxis -ax \""; command += upAxis;
//                 command += "\"; viewSet -home persp; }";
//                 MGlobal::executeCommand ( command );
            }
        }

        // Retrieve Maya's current up-axis.
        MString result;
//        FMVector3 mayaUpAxis = FMVector3::Zero;
        if ( ImportOptions::importUpAxis() )
        {
            MGlobal::executeCommand ( "upAxis -q -ax;", result, false, false );
            // TODO
//             if ( result == "z" )
// 
//             mayaUpAxis = FMVector3::YAxis;
//             if (IsEquivalent(MConvert::ToFChar(result), FC("z"))) mayaUpAxis = FMVector3::ZAxis;
        }

        float mayaUnit = 0.0f;
        if ( ImportOptions::importUnits() ) mayaUnit = 0.01f;

        // TODO 
        // Standardize the COLLADA document on this up-axis and units (centimeters).
//        FCDocumentTools::StandardizeUpAxisAndLength(colladaDocument, mayaUpAxis, mayaUnit);

        // Get the UI unit factor, for parts of Maya that don't handle variable lengths correctly
        MDistance testDistance ( 1.0f, MDistance::uiUnit() );
        float uiUnitFactor = (float) testDistance.as ( MDistance::kCentimeters );
    }

    //---------------------------------
    const String& DocumentImporter::getFilename() const
    {
        return mFileName;
    }

//     //---------------------------------
//     GeometryImporter* DocumentImporter::getGeometryImporter()
//     {
//         return mGeometryImporter;
//     }
// 
//     //---------------------------------
//     VisualSceneImporter* DocumentImporter::getVisualSceneImporter()
//     {
//         return mVisualSceneImporter;
//     }

}