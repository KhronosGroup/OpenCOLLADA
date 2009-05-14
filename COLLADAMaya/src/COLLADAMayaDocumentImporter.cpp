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
#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaReferenceManager.h"
#include "COLLADAMayaImportOptions.h"
#include "COLLADAMayaMaterialImporter.h"
#include "COLLADAMayaEffectImporter.h"
#include "COLLADAMayaGeometryImporter.h"
#include "COLLADAMayaCameraImporter.h"
#include "COLLADAMayaLightImporter.h"
#include "COLLADAMayaImageImporter.h"
#include "COLLADAMayaAnimationImporter.h"
#include "COLLADAMayaControllerImporter.h"
#include "COLLADAMayaVisualSceneImporter.h"

#include "COLLADAFWRoot.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWScene.h"

#include <maya/MFileIO.h>

#include <fstream>
#include <time.h>

#include "MayaDMScript.h"

#include "COLLADASaxFWLLoader.h"


namespace COLLADAMaya
{

    const String DocumentImporter::ASCII_PATH_EXTENSION = ".ma";
    const String DocumentImporter::ASCII_PATH_EXTENSION_DEBUG = ".nextgen.ma";
    const int DocumentImporter::BUFFERSIZE = 2097152;


    //---------------------------------
    DocumentImporter::DocumentImporter ( const String& fileName )
        : mColladaFileName ( fileName )
        , mSaxLoader ( &mSaxParserErrorHandler )
        , mParseStep ( NO_PARSING )
        , mVisualScenesList (0)
        , mLibraryNodesList (0)
        , mMaterialsList (0)
        , mSceneId ( "MayaScene" )
        , mFile ( 0 )
        , mVisualSceneImporter (0)
        , mGeometryImporter (0)
        , mMaterialImporter (0)
        , mEffectImporter (0)
        , mCameraImporter (0)
        , mLightImporter (0)
        , mImageImporter (0)
        , mAnimationImporter (0)
        , mControllerImporter (0)
        , mNumDocumentParses (0)
        , mUpAxisType ( COLLADAFW::FileInfo::Y_UP )
        , mLinearUnitConvertFactor ( 1.0 )
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

        // Get the sceneID (assign a name to the scene)
        MString sceneName = MFileIO::currentFile ();
        if ( sceneName.length() != 0 ) mSceneId = sceneName.asChar();

        // Create the maya file.

        // Create the libraries.
        mVisualSceneImporter = new VisualSceneImporter ( this );
        mGeometryImporter = new GeometryImporter ( this );
        mMaterialImporter = new MaterialImporter ( this );
        mEffectImporter = new EffectImporter ( this );
        mCameraImporter = new CameraImporter ( this );
        mLightImporter = new LightImporter ( this );
        mImageImporter = new ImageImporter (this);
        mAnimationImporter = new AnimationImporter (this);
        mControllerImporter = new ControllerImporter (this);

        // Initialize the reference manager
        ReferenceManager::getInstance()->initialize ();
    }

    //---------------------------------
    void DocumentImporter::releaseLibraries()
    {
        delete mVisualSceneImporter;
        delete mGeometryImporter;
        delete mMaterialImporter;
        delete mEffectImporter;
        delete mCameraImporter;
        delete mLightImporter;
        delete mImageImporter;
        delete mAnimationImporter;
        delete mControllerImporter;
    }

    //-----------------------------
    void DocumentImporter::importCurrentScene()
    {
        // Create the import/export library helpers.
        createLibraries ();

        // Load the collada document into the collada framework.
        mParseStep = FIRST_PARSING;

        // TODO
        int objectFlags = 
            COLLADASaxFWL::Loader::SCENE_FLAG | 
            COLLADASaxFWL::Loader::ASSET_FLAG | 
            COLLADASaxFWL::Loader::VISUAL_SCENES_FLAG |
            COLLADASaxFWL::Loader::LIBRARY_NODES_FLAG |
            COLLADASaxFWL::Loader::MATERIAL_FLAG;
        //mSaxLoader.setObjectFlags ( objectFlags );

        readColladaDocument();

        // Close the maya file.
        closeMayaAsciiFile ();
    }

    //-----------------------------
    bool DocumentImporter::createMayaAsciiFile ()
    {
        // TODO
        mMayaAsciiFileURI.set ( mColladaFileName );

#ifdef NDEBUG
        mMayaAsciiFileURI.setPathExtension ( ASCII_PATH_EXTENSION );
#else
        mMayaAsciiFileURI.setPathExtension ( ASCII_PATH_EXTENSION_DEBUG );
#endif

        String mayaAsciiFileName = mMayaAsciiFileURI.getURIString ();

        // Check if the file already exist.
        if ( std::ifstream ( mayaAsciiFileName.c_str () ) )
        {
            // TODO Open a dialog and ask the user to save the file under an other name.
            //MGlobal::displayError ( "File already exists!\n" );
            MGlobal::doErrorLogEntry ( "File already exists!\n" );
        }

        // Get the current locale value
        mLocale = setlocale ( LC_NUMERIC, 0 );
        setlocale ( LC_NUMERIC, "C" );

        mFile = fopen ( mayaAsciiFileName.c_str (), "w" );
        if ( mFile == 0 ) 
        {
            MGlobal::displayError ( "Can't open maya ascii file!\n" );
            return false;
        }

        // Set the buffer
        mBuffer = new char[BUFFERSIZE];
        bool failed = ( setvbuf ( mFile , mBuffer, _IOFBF, BUFFERSIZE ) != 0 );
        if ( failed )
        {
            delete[] mBuffer;
            MGlobal::displayError ( "Could not set buffer for writing." );
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
        bool retValue = createMayaAsciiFile ();
        assert ( retValue );

        // Initialise the maya default objects.
        if ( retValue ) 
        {
            mLightImporter->initialiseDefaultLightObjects ();
        }
    }

    //-----------------------------
    void DocumentImporter::finish ()
    {
        // First parse is done.
        if ( mParseStep < AFTER_FIRST_PARSING )
        {
            // The order of the steps here is very important!
            mParseStep = AFTER_FIRST_PARSING;

            // Import referenced visual scene
            importVisualScene ();

            // Import referenced library nodes
            importLibraryNodes ();

            // Import the node instances, when all nodes of the visual scene 
            // and the library nodes are already imported.
            mVisualSceneImporter->writeNodeInstances ();

            // Import materials
            importMaterials ();

            // Start the next parsing.
            mParseStep = SECOND_PARSING;

            // TODO
            int objectFlags = 
                COLLADASaxFWL::Loader::GEOMETRY_FLAG |
                COLLADASaxFWL::Loader::EFFECT_FLAG |
                COLLADASaxFWL::Loader::CAMERA_FLAG |
                COLLADASaxFWL::Loader::IMAGE_FLAG |
                COLLADASaxFWL::Loader::LIGHT_FLAG |
                COLLADASaxFWL::Loader::ANIMATION_FLAG |
                COLLADASaxFWL::Loader::ANIMATION_LIST_FLAG;
            //mSaxLoader.setObjectFlags ( objectFlags );

            readColladaDocument ();
        }

        // If the last read is ready, we can write the connections and close the file.
        --mNumDocumentParses;
        if ( mNumDocumentParses == 0 ) 
        {
            mParseStep = AFTER_SECOND_PARSING;

            // After the complete read of the collada document, 
            // the connections can be written into the maya file.
            if ( mFile != 0 )
            {
                mMaterialImporter->writeConnections ();
                mLightImporter->writeConnections ();
                mEffectImporter->writeConnections ();
                mControllerImporter->writeConnections ();
            }

            // Close the file
            closeMayaAsciiFile ();
        }
    }

    //-----------------------------
    void DocumentImporter::readColladaDocument ()
    {
        COLLADASaxFWL::Loader saxLoader;
        COLLADAFW::Root root ( &saxLoader, this );

        // TODO
//        COLLADAFW::Root root ( &mSaxLoader, this );
        String filename = getColladaFilename ();
        String fileUriString = URI::nativePathToUri ( filename );

        ++mNumDocumentParses;
        root.loadDocument ( fileUriString );
    }

    //-----------------------------
    const COLLADABU::URI& DocumentImporter::getMayaAsciiFileURI () const
    {
        return mMayaAsciiFileURI;
    }

    //-----------------------------
    COLLADAMaya::String DocumentImporter::frameworkNameToMayaName ( const String& name )
    {
        // Replace offending characters by some that are supported within maya:
        // ':', '|', '-', '!' are replaced by '_'.

        const char* c = name.c_str ();
        size_t length = name.length();
        char* tmp = new char[length + 1];

        for ( size_t i = 0; i <= length; i++ )
        {
            char d = c[i];
            if ( d == '.' || d == '-' || d == '|' || d == ':' || d == '/' || d == '\\' || d == '(' || d == ')' || d == '[' || d == ']' )
            {
                d =  '_';
            }
            tmp[i] = d;
        }

        String newName = COLLADABU::Utils::checkNCName ( tmp );
        delete[] tmp;
        return newName;
    }

    //-----------------------------
    bool DocumentImporter::writeGlobalAsset ( const COLLADAFW::FileInfo* asset )
    {
        if ( mParseStep >= IMPORT_ASSET ) return true;
        mParseStep = IMPORT_ASSET;

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // The maya version
        String mayaVersion ( MGlobal::mayaVersion ().asChar () );
        fprintf ( mFile, "//Maya ASCII %s scene\n", mayaVersion.c_str () );

        // We have to change the name on 64 bit machines. 
        // For example from "2008 x64" to "2008" or from "2008 Extension 2" to "2008".
        std::vector<String> words;
        String separator (" ");
        COLLADABU::Utils::split ( mayaVersion, separator, words );
        if ( words.size () > 1 ) 
        {
            fprintf ( mFile, "requires maya \"%s\";\n", words[0].c_str () );
        }
        else
        {
            fprintf ( mFile, "requires maya \"%s\";\n", mayaVersion.c_str () );
        }

        // Get the unit informations.
        const COLLADAFW::FileInfo::Unit& unit = asset->getUnit ();
        mLinearUnitConvertFactor = 1.0;

        // Set the default value to centimeters.
        String linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
        if ( ImportOptions::importUnits () )
        {
            linearUnitName = unit.getLinearUnitName ();
            double linearUnitMeter = unit.getLinearUnitMeter ();

            // Set the linear unit in meters.
            // Maya knows: millimeter, centimeter, meter, foot, inch and yard.
            switch ( unit.getLinearUnitUnit () )
            {
            case COLLADAFW::FileInfo::Unit::KILOMETER:
                {
                    // Convert to meters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_KILOMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER; // 1 km = 1000m ==> cf = 1000
                    break;
                }
            case COLLADAFW::FileInfo::Unit::METER:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::DECIMETER:
                {
                    // Convert to meters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_DECIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER; // 1 dm = 0.1 m ==> cf = 0.1
                    break;
                }
            case COLLADAFW::FileInfo::Unit::CENTIMETER:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME; 
                    mLinearUnitConvertFactor =  1.0;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::MILLIMETER:
                {
                    // Convert to centimeters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                    mLinearUnitConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_MILLIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1 mm = 0.01 m ==> cf = 0.1
                    break;
                }
            case COLLADAFW::FileInfo::Unit::FOOT:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::INCH:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::YARD:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    break;
                }
            default:
                {
                    if ( linearUnitMeter >= COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER )
                    {
                        // Set to meter
                        linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                        mLinearUnitConvertFactor = linearUnitMeter / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER;  // 1 ? = 1 m
                    }
                    else 
                    {
                        // Set to centimeters
                        linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                        mLinearUnitConvertFactor = linearUnitMeter / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER;  // 1 ? = 0.01 m
                    }
                    break;
                }
            }
        }

        fprintf ( mFile, "currentUnit -l %s -a %s -t %s;\n", 
            linearUnitName.c_str (), unit.getAngularUnitName ().c_str (), unit.getTimeUnitName ().c_str () );

        if ( ImportOptions::importUpAxis () )
        {
            mUpAxisType = asset->getUpAxisType ();
        }
        else
        {
            mUpAxisType = asset->getUpAxisType ();
            String upAxis = "y";
            switch ( mUpAxisType )
            {
            case COLLADAFW::FileInfo::Y_UP:
                upAxis = "y"; break;
            case COLLADAFW::FileInfo::Z_UP:
                upAxis = "z"; break;
            default:
                upAxis = "y"; break;
            }
            // createNode script -name "upAxisScriptNode";
            //      setAttr ".before" -type "string" "string $currentAxis = `upAxis -q -ax`; if ($currentAxis != \"z\") { upAxis -ax \"z\"; viewSet -home persp; }";
            //      setAttr ".scriptType" 2;
            MayaDM::Script scriptNode ( mFile, "upAxisScriptNode" );
            String scriptValue = "string $currentAxis = `upAxis -q -ax`; if ($currentAxis != \\\"" + upAxis + "\\\") { upAxis -ax \\\"" + upAxis + "\\\"; viewSet -home persp; }"; // -rv
            
            scriptNode.setBefore ( scriptValue );
            scriptNode.setScriptType ( 2 );
        }

//         String application ( MGlobal::executeCommandStringResult ( "about -application" ).asChar () );
//         fprintf ( mFile, "fileInfo \"application\" \"%s\";\n", application.c_str () );
//         String product ( MGlobal::executeCommandStringResult ( "about -product" ).asChar () );
//         fprintf ( mFile, "fileInfo \"product\" \"%s\";\n", product.c_str () );
//         fprintf ( mFile, "fileInfo \"version\" \"%s\";\n", mayaVersion.c_str () );
//         String cutIdentifier ( MGlobal::executeCommandStringResult ( "product -cutIdentifier" ).asChar () );
//         fprintf ( mFile, "fileInfo \"cutIdentifier\" \"%s\";\n", cutIdentifier.c_str () );
//         String operatingSystemVersion ( MGlobal::executeCommandStringResult ( "product -operatingSystemVersion" ).asChar () );
//         fprintf ( mFile, "fileInfo \"osv\" \"%s\";\n", operatingSystemVersion.c_str () );

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeScene ( const COLLADAFW::Scene* scene )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeScene(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep <= COPY_FIRST_ELEMENTS ) 
        {
            // Make a copy of the instantiated visual scene element.
            mParseStep = COPY_FIRST_ELEMENTS;
            mInstanceVisualScene = *scene->getInstanceVisualScene ();
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeScene(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep <= COPY_FIRST_ELEMENTS )
        {
            // Make a copy of the visual scene element and push it into the list of visual scenes.
            mParseStep = COPY_FIRST_ELEMENTS;
            mVisualScenesList.push_back ( new COLLADAFW::VisualScene ( *visualScene ) );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importVisualScene ()
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::importVisualScene(..): Cant't import, no maya file exist!" << endl;
            return;
        }

        // Get the visual scene element to import.
        for ( size_t i=0; i<mVisualScenesList.size (); ++i )
        {
            const COLLADAFW::VisualScene* visualScene = mVisualScenesList [i];
            if ( mInstanceVisualScene.getInstanciatedObjectId () == visualScene->getUniqueId () )
            {
                // Import the data.
                mVisualSceneImporter->importVisualScene ( visualScene );
            }
        }
    }

    //-----------------------------
    bool DocumentImporter::writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeLibraryNodes(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep <= COPY_FIRST_ELEMENTS )
        {
            // Make a copy of the visual scene element and push it into the list of visual scenes.
            mParseStep = COPY_FIRST_ELEMENTS;
            mLibraryNodesList.push_back ( new COLLADAFW::LibraryNodes ( *libraryNodes ) );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importLibraryNodes ()
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::importLibraryNodes(..): Cant't import, no maya file exist!" << endl;
            return;
        }

        // Import the library notes data.
        for ( size_t i=0; i<mLibraryNodesList.size (); ++i )
        {
            const COLLADAFW::LibraryNodes* libraryNodes = mLibraryNodesList [i];
            mVisualSceneImporter->importLibraryNodes ( libraryNodes );
        }
    }

    //-----------------------------
    bool DocumentImporter::writeMaterial ( const COLLADAFW::Material* material )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeMaterial(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep <= COPY_FIRST_ELEMENTS )
        {
            // Make a copy of the material element and push it into the list.
            mParseStep = COPY_FIRST_ELEMENTS;
            mMaterialsList.push_back ( new COLLADAFW::Material ( *material ) );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importMaterials ()
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::importMaterials(..): Cant't import, no maya file exist!" << endl;
            return;
        }

        // Import the materials data.
        for ( size_t i=0; i<mMaterialsList.size (); ++i )
        {
            const COLLADAFW::Material* material = mMaterialsList [i];
            mMaterialImporter->importMaterial ( material );
        }
    }

    //-----------------------------
    bool DocumentImporter::writeGeometry ( const COLLADAFW::Geometry* geometry )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeGeometry(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            // Import the data.
            mGeometryImporter->importGeometry ( geometry );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeEffect ( const COLLADAFW::Effect* effect )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeEffect(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            // Import the data.
            mEffectImporter->importEffect ( effect );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeCamera ( const COLLADAFW::Camera* camera )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeCamera(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            // Import the data.
            mCameraImporter->importCamera ( camera );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeLight ( const COLLADAFW::Light* light )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeLight(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            // Import the data.
            mLightImporter->importLight ( light );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeImage ( const COLLADAFW::Image* image )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeImage(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            // Import the data.
            mImageImporter->importImage ( image );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeAnimation ( const COLLADAFW::Animation* animation )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeAnimation(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            mAnimationImporter->importAnimation ( animation );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeAnimationList ( const COLLADAFW::AnimationList* animationList )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            cerr << "DocumentImporter::writeAnimationList(..): Cant't import, no maya file exist!" << endl;
            return false;
        }

        if ( mParseStep == SECOND_PARSING )
        {
            getAnimationImporter ()->writeConnections ( animationList );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeSkinControllerData ( 
        const COLLADAFW::SkinControllerData* skinControllerData )
    {
        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeController ( 
        const COLLADAFW::Controller* controller )
    {
        return true;
    }

}