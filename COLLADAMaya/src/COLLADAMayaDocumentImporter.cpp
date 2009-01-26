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

#include "COLLADAMayaVisualSceneImporter.h"
#include "COLLADAMayaGeometryImporter.h"

#include "COLLADAFWRoot.h"

#include "COLLADASaxFWLLoader.h"

#include <maya/MFileIO.h>

namespace COLLADAMaya
{
    //---------------------------------
    DocumentImporter::DocumentImporter ( const String& fileName )
        : mFileName ( fileName )
        , mSceneId ( "MayaScene" )
        , mFile ( 0 )
        , mVisualSceneImporter (0)
        , mGeometryImporter (0)
        , mSceneGraphCreated ( false )
        , mGeometryRead ( false )
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

        mVisualSceneImporter = new VisualSceneImporter ( this );
        mGeometryImporter = new GeometryImporter ( this );

        // Get the sceneID (assign a name to the scene)
        MString sceneName = MFileIO::currentFile ();
        if ( sceneName.length() != 0 ) mSceneId = sceneName.asChar();

        // Initialize the reference manager
        ReferenceManager::getInstance()->initialize ();
    }

    //---------------------------------
    void DocumentImporter::releaseLibraries()
    {
        delete mVisualSceneImporter;
        delete mGeometryImporter;
    }

    //-----------------------------
    void DocumentImporter::importCurrentScene()
    {
        // Create the import/export library helpers.
        createLibraries ();

        // Import the asset information.
        importAsset ();

        // Load the collada document into the collada framework.
        readColladaDocument();
    }

    //-----------------------------
    bool DocumentImporter::createFile()
    {
        // TODO Create the maya ascii file (where with which name???)
        errno_t err = fopen_s ( &mFile, "c:\\temp\\cube_test.ma", "w+" );
        if ( err != 0 ) 
        {
            std::cerr << "Can't open maya ascii file! " << endl; 
            return false;
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::writeHeader( FILE* file )
    {
        // TODO
        fprintf_s ( file, "//Maya ASCII 2008 scene\n" );
        fprintf_s ( file, "//Name: inMeshTest.ma\n" );
        fprintf_s ( file, "//Last modified: Mon, Dec 01, 2008 02:02:39 PM\n" );
        fprintf_s ( file, "//Codeset: 1252\n" );
        fprintf_s ( file, "requires maya \"2008\";\n" );
        fprintf_s ( file, "currentUnit -l centimeter -a degree -t film;\n" );
        fprintf_s ( file, "fileInfo \"application\" \"maya\";\n" );
        fprintf_s ( file, "fileInfo \"product\" \"Maya Unlimited 2008\";\n" );
        fprintf_s ( file, "fileInfo \"version\" \"2008\";\n" );
        fprintf_s ( file, "fileInfo \"cutIdentifier\" \"200708022245-704165\";\n" );
        fprintf_s ( file, "fileInfo \"osv\" \"Microsoft Windows XP Service Pack 3 (Build 2600)\\n\";\n" );
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

    //-----------------------------
    void DocumentImporter::cancel ( const String& errorMessage )
    {

    }

    //-----------------------------
    void DocumentImporter::start ()
    {
        // Create the maya file.
        assert ( createFile() );

        // TODO Write the header informations and the asset into the file.
        writeHeader ( mFile );
    }

    //-----------------------------
    void DocumentImporter::finish ()
    {
        // Close the file.
        if ( mFile != 0 ) fclose ( mFile );
    }

    //-----------------------------
    bool DocumentImporter::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        bool retValue = false;
        if ( mSceneGraphCreated ) return retValue;

        // TODO
        if ( mFile == 0 ) start();

        retValue = mVisualSceneImporter->importVisualScene ( visualScene );
        mSceneGraphCreated = true;

        // Nochmal lesen, zwecks Reihenfolge...
        if ( mGeometryRead == true )
        {
            readColladaDocument ();
        }
        
        return retValue;
    }

    //-----------------------------
    bool DocumentImporter::writeGeometry ( const COLLADAFW::Geometry* geometry )
    {
        bool retValue = false;

        // First the scene graph!
        if ( !mSceneGraphCreated )
        {
            mGeometryRead = true;
            return retValue;
        }

        // TODO
        if ( mFile == 0 ) start();

        retValue = mGeometryImporter->importGeometry ( geometry );

        return retValue;
    }

    //-----------------------------
    void DocumentImporter::readColladaDocument ()
    {
        COLLADASaxFWL::Loader loader;
        COLLADAFW::Root root ( &loader, this );
        String filename = getFilename ();
        String fileUriString = URI::nativePathToUri ( filename );
        root.loadDocument ( fileUriString );
    }
}