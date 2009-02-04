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

#include <fstream>
#include <time.h>


namespace COLLADAMaya
{
    //---------------------------------
    DocumentImporter::DocumentImporter ( const String& fileName )
        : mColladaFileName ( fileName )
        , mSceneId ( "MayaScene" )
        , mFile ( 0 )
        , mVisualSceneImporter (0)
        , mGeometryImporter (0)
        , mSceneGraphWritten ( false )
        , mGeometryWritten ( false )
        , mAssetWritten ( false )
        , mSceneGraphRead ( false )
        , mGeometryRead ( false )
    {
    }

    //---------------------------------
    DocumentImporter::~DocumentImporter()
    {
        releaseLibraries(); 

        // Close the maya ascii file
        closeMayaAsciiFile ();
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

        // Load the collada document into the collada framework.
        readColladaDocument();

        // Close the maya file.
        closeMayaAsciiFile ();
    }

    //-----------------------------
    bool DocumentImporter::createMayaAsciiFile ()
    {
        // TODO
        mMayaAsciiFileURI.set ( mColladaFileName );
        mMayaAsciiFileURI.setPathExtension ( ".netallied.import.ma" );
        String mayaFileName = mMayaAsciiFileURI.getURIString ();

        // Check if the file already exist.
        if ( std::ifstream ( mayaFileName.c_str () ) )
        {
            // TODO Open a dialog and ask the user to save the file under an other name.
            std::cerr << "File already exists!";
        }

        // Get the current locale value
        mLocale = setlocale ( LC_NUMERIC, 0 );
        setlocale ( LC_NUMERIC, "C" );

        errno_t err = fopen_s ( &mFile, mayaFileName.c_str (), "w+" );
        if ( err != 0 ) 
        {
            std::cerr << "Can't open maya ascii file! " << endl; 
            return false;
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::closeMayaAsciiFile ()
    {
        if ( mFile ) 
        {
            fclose ( mFile );
            mFile = 0;

            setlocale ( LC_NUMERIC, mLocale.c_str() );
        }
    }

    //---------------------------------
    const String& DocumentImporter::getColladaFilename() const
    {
        return mColladaFileName;
    }

    //-----------------------------
    void DocumentImporter::cancel ( const String& errorMessage )
    {

    }

    //-----------------------------
    void DocumentImporter::start ()
    {
        // Create the maya file.
        assert ( createMayaAsciiFile() );
    }

    //-----------------------------
    void DocumentImporter::finish ()
    {
        // Close the file.
        if ( mFile != 0 ) fclose ( mFile );
    }

    //-----------------------------
    bool DocumentImporter::writeGlobalAsset ( const COLLADAFW::FileInfo* asset )
    {
        if ( mAssetWritten ) return true;

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // TODO
        String mayaVersion ( MGlobal::mayaVersion ().asChar () );
        fprintf_s ( mFile, "//Maya ASCII %s scene\n", mayaVersion.c_str () );
//         fprintf_s ( mFile, "//Name: %s\n", mMayaAsciiFileURI.getPathFile ().c_str () );

//         std::stringstream curDate;
//         getCurrentDate ( curDate );
//         fprintf_s ( mFile, "//Last modified: %s\n", curDate.str () );
//         String codeset ( MGlobal::executeCommandStringResult ( "about -codeset" ).asChar () );
//         fprintf_s ( mFile, "//Codeset: %s\n", codeset.c_str() );

        fprintf_s ( mFile, "requires maya \"%s\";\n", mayaVersion.c_str () );

        // TODO Default values for the units!
        const COLLADAFW::FileInfo::Unit& unit = asset->getUnit ();
        fprintf_s ( mFile, "currentUnit -l %s -a %s -t %s;\n", unit.mLinearUnit.c_str (), unit.mAngularUnit.c_str (), unit.mTimeUnit.c_str () );

//         String application ( MGlobal::executeCommandStringResult ( "about -application" ).asChar () );
//         fprintf_s ( mFile, "fileInfo \"application\" \"%s\";\n", application.c_str () );
//         String product ( MGlobal::executeCommandStringResult ( "about -product" ).asChar () );
//         fprintf_s ( mFile, "fileInfo \"product\" \"%s\";\n", product.c_str () );
//         fprintf_s ( mFile, "fileInfo \"version\" \"%s\";\n", mayaVersion.c_str () );
//         String cutIdentifier ( MGlobal::executeCommandStringResult ( "product -cutIdentifier" ).asChar () );
//         fprintf_s ( mFile, "fileInfo \"cutIdentifier\" \"%s\";\n", cutIdentifier.c_str () );
//         String operatingSystemVersion ( MGlobal::executeCommandStringResult ( "product -operatingSystemVersion" ).asChar () );
//         fprintf_s ( mFile, "fileInfo \"osv\" \"%s\";\n", operatingSystemVersion.c_str () );

        mAssetWritten = true;

        if ( mSceneGraphRead || mGeometryRead )
        {
            mSceneGraphRead = false;
            mGeometryRead = false;
            readColladaDocument ();
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        bool retValue = false;

        // Order: asset, scene graph, geometry
        if ( !mAssetWritten ) 
        {
            mSceneGraphRead = true;
        }

        if ( mSceneGraphWritten ) return true;

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        retValue = mVisualSceneImporter->importVisualScene ( visualScene );
        mSceneGraphWritten = true;

        if ( mGeometryRead )
        {
            mGeometryRead = false;
            readColladaDocument ();
        }

        return retValue;
    }

    //-----------------------------
    bool DocumentImporter::writeGeometry ( const COLLADAFW::Geometry* geometry )
    {
        bool retValue = false;

        // Order: asset, scene graph, geometry
        if ( !mAssetWritten || !mSceneGraphWritten ) 
        {
            mGeometryRead = true;
            return false;
        }

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        retValue = mGeometryImporter->importGeometry ( geometry );
        mGeometryWritten = true;

        return retValue;
    }

    //-----------------------------
    void DocumentImporter::readColladaDocument ()
    {
        COLLADASaxFWL::Loader loader;
        COLLADAFW::Root root ( &loader, this );
        String filename = getColladaFilename ();
        String fileUriString = URI::nativePathToUri ( filename );
        root.loadDocument ( fileUriString );
    }

    //-----------------------------
    const COLLADABU::URI& DocumentImporter::getMayaAsciiFileURI () const
    {
        return mMayaAsciiFileURI;
    }

    //-----------------------------
    void DocumentImporter::setMayaAsciiFileURI ( const COLLADABU::URI& fileURI )
    {
        mMayaAsciiFileURI.set ( fileURI.getURIString () );
    }

    //-----------------------------
    void DocumentImporter::getCurrentDate ( std::stringstream& curDate )
    {
        // create a stringstream containing the current date and time in ISO 8601 format
        time_t _t;
        time ( &_t );
        struct tm *t = localtime ( &_t );

        int weekDay = t->tm_wday; // days since Sunday - [0,6]
        switch ( weekDay )
        {
        case 0: curDate << "Sun, "; break;
        case 1: curDate << "Mon, "; break;
        case 2: curDate << "Tue, "; break;
        case 3: curDate << "Wed, "; break;
        case 4: curDate << "Thu, "; break;
        case 5: curDate << "Fri, "; break;
        case 6: curDate << "Sat, "; break;
        default: assert ( weekDay < 7 );
        }

        int month = t->tm_mon; // months since January - [0,11]
        switch ( month )
        {
        case 0: curDate << "Jan "; break;
        case 1: curDate << "Feb "; break;
        case 2: curDate << "Mar "; break;
        case 3: curDate << "Apr "; break;
        case 4: curDate << "Mai "; break;
        case 5: curDate << "Jun "; break;
        case 6: curDate << "Jul "; break;
        case 7: curDate << "Aug "; break;
        case 8: curDate << "Sep "; break;
        case 9: curDate << "Oct "; break;
        case 10: curDate << "Nov "; break;
        case 11: curDate << "Dec "; break;
        default: assert ( month < 12 );
        }

        // Mon, Dec 01, 2008 02:02:39 PM
        curDate << t->tm_mday << " "; // day of the month - [1,31]
        if ( t->tm_hour < 12 )
            curDate << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << " AM\n";
        else if ( t->tm_hour == 12 )
            curDate << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << " PM\n";
        else 
            curDate << t->tm_hour-12 << ":" << t->tm_min << ":" << t->tm_sec << " AM\n";
    }

    //-----------------------------
    bool DocumentImporter::writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes )
    {
        // TODO
        return false;
    }
}