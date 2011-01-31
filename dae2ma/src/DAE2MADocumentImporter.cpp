/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "DAE2MAStableHeaders.h"
#include "DAE2MADocumentImporter.h"
#include "DAE2MAImportOptions.h"
#include "DAE2MAMaterialImporter.h"
#include "DAE2MAEffectImporter.h"
#include "DAE2MAGeometryImporter.h"
#include "DAE2MACameraImporter.h"
#include "DAE2MALightImporter.h"
#include "DAE2MAImageImporter.h"
#include "DAE2MAAnimationImporter.h"
#include "DAE2MAControllerImporter.h"
#include "DAE2MAVisualSceneImporter.h"
#include "DAE2MANodeImporter.h"

#include "COLLADAFWRoot.h"
#include "COLLADAFWAnimationList.h"
#include "COLLADAFWScene.h"

#include <fstream>
#include <time.h>

#include "MayaDMScript.h"

#include "COLLADASaxFWLLoader.h"


namespace DAE2MA
{

    /** This names are reserved. Maya nodes can't have this names! */
    const size_t DocumentImporter::NUM_RESERVED_NAMES = 43;
    const String DocumentImporter::RESERVED_NAMES[] = 
    { 
        "default", 
        "defaultShaderList1", 
        "renderPartition", 
        "initialShadingGroup", 
        "initialMaterialInfo", 
        "lightList1", 
        "defaultLightSet", 
        "lightLinker1", 
        "defaultTextureList1", 
        "lambert1", 
        "particleCloud1",
        "shaderGlow1",
        "initialParticleSE",
        "layerManager",
        "defaultLayer",
        "defaultObjectSet",
        "dof1",
        "dynController1",
        "globalCacheControl",
        "hardwareRenderGlobals",
        "defaultHardwareRenderGlobals",
        "ikSystem",
        "ikSCsolver",
        "ikRPsolver",
        "ikSplineSolver",
        "hikSolver",
        "characterPartition",
        "renderPartition",
        "defaultRenderLayer",
        "renderLayerManager",
        "strokeGlobals",
        "time1",
        "persp",     
        "top",       
        "side",      
        "front",     
        "perspShape",
        "topShape",  
        "sideShape", 
        "frontShape",
        "int",
        "float",
        "string"
    };

    /** The Buffersize for the document to write. */
    const int DocumentImporter::BUFFERSIZE = 2097152;


    //---------------------------------
    DocumentImporter::DocumentImporter ( 
        const String& fileName, 
        const String& mayaAsciiFileName, 
        const char* mayaVersion /*= MAYA_VERSION_2009*/ )
        : mColladaFileName ( fileName )
        , mMayaAsciiFileURI ( mayaAsciiFileName )
        , mMayaVersion ( mayaVersion )
//        , mSaxLoader ( &mSaxParserErrorHandler )
        , mParseStep ( NO_PARSING )
        , mVisualScenesList (0)
        , mLibraryNodesList (0)
        , mMaterialsList (0)
        , mEffectsList (0)
        , mAnimationListsList (0)
        , mFile ( 0 )
        , mNodeImporter (0)
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
        , mLinearUnitMayaBindShapeBugConvertFactor ( 1.0 )
        , mDigitTolerance (FLOAT_TOLERANCE)
        , mBuffer (0)
        , mInstanceVisualScene (0)
    {
        // Maya already use some names for the default maya objects.
        for ( size_t i=0; i<NUM_RESERVED_NAMES; ++i )
        {
            mGlobalNodeIdList.addId ( RESERVED_NAMES[i] );
            mDependNodeIdList.addId ( RESERVED_NAMES[i] );
        }
    }

    //---------------------------------
    DocumentImporter::~DocumentImporter()
    {
        // Close the maya ascii file
        closeMayaAsciiFile ();

        // Don't delete the objects earlier, other parts use the elements!
        delete mInstanceVisualScene;

        // A copy of the framework's library visual scenes elements. 
        for ( size_t i=0; i< mVisualScenesList.size (); ++i )
        {
            COLLADAFW::VisualScene* visualScene = mVisualScenesList [i];
            delete visualScene;
        }
        mVisualScenesList.clear ();

        // A copy of the framework's library nodes elements. 
        for ( size_t i=0; i< mLibraryNodesList.size (); ++i )
        {
            COLLADAFW::LibraryNodes* libraryNodes = mLibraryNodesList [i];
            delete libraryNodes;
        }
        mLibraryNodesList.clear ();

        // A copy of the framework's library materials elements. 
        for ( size_t i=0; i< mMaterialsList.size (); ++i )
        {
            COLLADAFW::Material* material = mMaterialsList [i];
            delete material;
        }
        mMaterialsList.clear ();

        // A copy of the framework's library effect elements. 
        for ( size_t i=0; i< mEffectsList.size (); ++i )
        {
            COLLADAFW::Effect* effect = mEffectsList [i];
            delete effect;
        }
        mEffectsList.clear ();

        // A copy of the framework's library animationList elements. 
        for ( size_t i=0; i< mAnimationListsList.size (); ++i )
        {
            COLLADAFW::AnimationList* animationList = mAnimationListsList [i];
            delete animationList;
        }
        mAnimationListsList.clear ();
        
        // Delete the library elements.
        releaseLibraries(); 

        // Release the buffer memory
        delete[] mBuffer;
        mBuffer = 0;
    }

    //---------------------------------
    void DocumentImporter::createLibraries()
    {
        // First release the existing libraries.
        releaseLibraries();

        // Create the libraries.
        mNodeImporter = new NodeImporter ( this );
        mVisualSceneImporter = new VisualSceneImporter ( this );
        mGeometryImporter = new GeometryImporter ( this );
        mMaterialImporter = new MaterialImporter ( this );
        mEffectImporter = new EffectImporter ( this );
        mCameraImporter = new CameraImporter ( this );
        mLightImporter = new LightImporter ( this );
        mImageImporter = new ImageImporter (this);
        mAnimationImporter = new AnimationImporter (this);
        mControllerImporter = new ControllerImporter (this);

//         // TODO Initialize the reference manager
//         ReferenceManager::getInstance()->initialize ();
    }

    //---------------------------------
    void DocumentImporter::releaseLibraries()
    {
        delete mNodeImporter;
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
            COLLADASaxFWL::Loader::MATERIAL_FLAG |
            COLLADASaxFWL::Loader::CONTROLLER_FLAG;
        //mSaxLoader.setObjectFlags ( objectFlags );

        readColladaDocument();

        // Close the maya file.
        closeMayaAsciiFile ();
    }

    //-----------------------------
    bool DocumentImporter::createMayaAsciiFile ()
    {
        String mayaAsciiFileName = mMayaAsciiFileURI.getURIString ();

        // Check if the file already exist.
        if ( std::ifstream ( mayaAsciiFileName.c_str () ) )
        {
            // TODO Open a dialog and ask the user to save the file under an other name.
            //MGlobal::displayError ( "File already exists!\n" );
            //MGlobal::doErrorLogEntry ( "File already exists!\n" );
            std::cerr << "Overwrite existing file!" << std::endl;
        }

        // Get the current locale value
        mLocale = setlocale ( LC_NUMERIC, 0 );
        setlocale ( LC_NUMERIC, "C" );

        mFile = fopen ( mayaAsciiFileName.c_str (), "w" );
        if ( mFile == 0 ) 
        {
            std::cerr << "Can't open output file!\n" << std::endl;
            return false;
        }

        // Set the buffer
        mBuffer = new char[BUFFERSIZE];
        bool failed = ( setvbuf ( mFile , mBuffer, _IOFBF, BUFFERSIZE ) != 0 );
        if ( failed )
        {
            delete[] mBuffer;
            mBuffer = 0;
            std::cerr << "Could not set buffer for writing." << std::endl;
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
    void DocumentImporter::initialize ()
    {
        // Create the maya file.
        bool retValue = createMayaAsciiFile ();
        if ( !retValue )
            std::cerr << "Error: could not create output file! " << std::endl;

        // Initialise the maya default objects.
        if ( retValue ) 
        {
            mLightImporter->initialiseDefaultLightObjects ();
        }
    }

    //-----------------------------
    void DocumentImporter::cancel ( const String& errorMessage )
    {
        std::cerr << "Error: " << errorMessage << std::endl;
    }

    //-----------------------------
    void DocumentImporter::finish ()
    {
        // First parse is done.
        if ( mParseStep <= COPY_ELEMENTS )
        {
            // The order of the steps here is very important!
            mParseStep = ELEMENTS_COPIED;

            // Create the scene graph and map the unique node ids to the framwork node objects.
            importNodes ();

            // Import referenced visual scene
            importVisualScene ();

            // After the import of the visual scene, we can determine the scale animations.
            detectScaleAnimations ();

            // Import morph controllers 
            importMorphControllers ();

            // First import materials, then effects and after this images.
            // The order of the import is relevant, about we have to know which effects are used 
            // by this material. After the import of the effects, we know which images we need.
            // We have to import this before we write the animations in the second parsing, about
            // to know the animated effects.
            importMaterials ();
            importEffects ();
            importImages ();

            // Get the minimum and the maximum time values of the animations to get the start 
            // time and the end time of the animation. This times we have to set as the 
            // "playbackOptions" in the "sceneConfigurationScriptNode".
            importPlaybackOptions ();

            // Start the next parsing.
            mParseStep = SECOND_PARSING;

            // TODO Not active in the current implementation!
            int objectFlags = 
                COLLADASaxFWL::Loader::GEOMETRY_FLAG |
                COLLADASaxFWL::Loader::EFFECT_FLAG |
                COLLADASaxFWL::Loader::CAMERA_FLAG |
                COLLADASaxFWL::Loader::IMAGE_FLAG |
                COLLADASaxFWL::Loader::LIGHT_FLAG |
                COLLADASaxFWL::Loader::ANIMATION_FLAG |
                COLLADASaxFWL::Loader::ANIMATION_LIST_FLAG | 
                COLLADASaxFWL::Loader::SKIN_CONTROLLER_DATA_FLAG;
            //mSaxLoader.setObjectFlags ( objectFlags );

            readColladaDocument ();
        }

        // If the last read is ready, we can write the connections and close the file.
        --mNumDocumentParses;
        if ( mNumDocumentParses == 0 ) 
        {
            mParseStep = GEOMETRY_IMPORTED;

            // After we have imported the geometries, we can create the necessary uv-choosers.
            // We can't create them earlier, about we need to know, if the geometry has more than 
            // one uv-set (texture coordinates).
            createUvChoosers ();

            // After the complete read of the collada document, 
            // the connections can be written into the maya file.
            mParseStep = MAKE_CONNECTIONS;
            writeConnections ();

            // Close the file
            closeMayaAsciiFile ();
        }
    }

    //-----------------------------
    void DocumentImporter::createUvChoosers ()
    {
        // After we have imported the geometries, we can create the necessary uv-choosers.
        if ( mParseStep < GEOMETRY_IMPORTED )
        {
            std::cerr << "Geometries not imported! Can't create the uv-choosers!" << std::endl;
            return;
        }

        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::createUvChoosers(): Cant't import, no maya file exist!" << std::endl;
            return;
        }

        // Create the uv-choosers.
        mMaterialImporter->createUVChoosers ();
    }

    //-----------------------------
    void DocumentImporter::writeConnections ()
    {
        if ( mParseStep == MAKE_CONNECTIONS )
        {
            // The file must already exist.
            if ( mFile == 0 )
            {
                std::cerr << "DocumentImporter::writeConnections(): Cant't import, no maya file exist!" << std::endl;
                return;
            }

            // If we have one or more controllers, the material groupIds have to 
            // connect to the geometry object groups on a later index position.
            mControllerImporter->writeConnections ();
            mMaterialImporter->writeConnections ();
            mLightImporter->writeConnections ();
            mEffectImporter->writeConnections ();
            mGeometryImporter->writeConnections ();

            // We have to connect the stored animations.
            importAnimationLists ();
        }
    }

    //-----------------------------
    void DocumentImporter::readColladaDocument ()
    {
        // See revision 511 (generate new loader object without setting object flags).
        COLLADASaxFWL::Loader saxLoader ( &mSaxParserErrorHandler );

        if ( mParseStep == FIRST_PARSING )
            saxLoader.registerExtraDataCallbackHandler ( &mMayaIdCallbackHandler );

        // TODO
        COLLADAFW::Root root ( &saxLoader, this );
//        COLLADAFW::Root root ( &mSaxLoader, this );
        String filename = getColladaFilename ();
        String fileUriString = URI::nativePathToUri ( filename );

        ++mNumDocumentParses;
        root.loadDocument ( fileUriString );
    }

    //-----------------------------
    String DocumentImporter::frameworkNameToMayaName ( const String& name )
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
        if ( mParseStep >= IMPORT_ASSET ) 
		{
			return true;
		}
        mParseStep = IMPORT_ASSET;

        // Create the file, if not already done.
        if ( mFile == 0 ) 
		{
			initialize();
		}

		if ( mFile == 0 ) 
		{
			return false;
		}

        // The maya version
        //String mayaVersion ( MGlobal::mayaVersion ().asChar () );
        fprintf ( mFile, "//Maya ASCII %s scene\n", mMayaVersion );
        fprintf ( mFile, "requires maya \"%s\";\n", mMayaVersion );

        // Get the unit informations.
        const COLLADAFW::FileInfo::Unit& unit = asset->getUnit ();
        mLinearUnitConvertFactor = 1.0;
        mLinearUnitMayaBindShapeBugConvertFactor = 1.0;

        // Set the default value to centimeters.
        String linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
        if ( ImportOptions::importUnits () )
        {
            linearUnitName = unit.getLinearUnitName ();
            double linearUnitMeter = unit.getLinearUnitMeter ();

            // Set the valid maya values in depend on the current precision.
            linearUnitMeter = toMayaUnitValue ( linearUnitMeter );

            // Set the linear unit in meters.
            // Maya knows: millimeter, centimeter, meter, foot, inch and yard.
            switch ( unit.getLinearUnitUnit () )
            {
            case COLLADAFW::FileInfo::Unit::KILOMETER:
                {
                    // Convert to meters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_KILOMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER; // 1km = 1000m ==> cf = 1000
                    mLinearUnitMayaBindShapeBugConvertFactor  = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_KILOMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1km = 100.000m ==> cf = 100.000
                    break;
                }
            case COLLADAFW::FileInfo::Unit::METER:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    mLinearUnitMayaBindShapeBugConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1m = 100cm ==> cf = 100
                    break;
                }
            case COLLADAFW::FileInfo::Unit::DECIMETER:
                {
                    // Convert to centimeters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                    mLinearUnitConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_DECIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1dm = 10cm ==> cf = 10
                    mLinearUnitMayaBindShapeBugConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_DECIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1dm = 10cm ==> cf = 10
                    break;
                }
            case COLLADAFW::FileInfo::Unit::CENTIMETER:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME; 
                    mLinearUnitConvertFactor =  1.0;
                    mLinearUnitMayaBindShapeBugConvertFactor = 1.0;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::MILLIMETER:
                {
                    // Convert to centimeters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                    mLinearUnitConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_MILLIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1mm = 0.01m ==> cf = 0.1
                    mLinearUnitMayaBindShapeBugConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_MILLIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; // 1mm = 0.01m ==> cf = 0.1
                    break;
                }
            case COLLADAFW::FileInfo::Unit::FOOT:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    mLinearUnitMayaBindShapeBugConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; 
                    break;
                }
            case COLLADAFW::FileInfo::Unit::INCH:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    mLinearUnitMayaBindShapeBugConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; 
                    break;
                }
            case COLLADAFW::FileInfo::Unit::YARD:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD_NAME;
                    mLinearUnitConvertFactor =  1.0;
                    mLinearUnitMayaBindShapeBugConvertFactor = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; 
                    break;
                }
            default:
                {
                    if ( linearUnitMeter >= COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER )
                    {
                        // Set to meter
                        linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                        mLinearUnitConvertFactor = linearUnitMeter / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER;  // 1 ? = 1 m
                        mLinearUnitMayaBindShapeBugConvertFactor = linearUnitMeter / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER; 
                    }
                    else 
                    {
                        // Set to centimeters
                        linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                        mLinearUnitConvertFactor = linearUnitMeter / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER;  // 1 ? = 0.01 m
                        mLinearUnitMayaBindShapeBugConvertFactor = linearUnitMeter / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER;  // 1 ? = 0.01 m
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
            MayaDM::Script scriptNode ( mFile, SCRIPT_NODE_UP_AXIS );
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
    double DocumentImporter::toMayaUnitValue ( double unitValue )
    {
        if ( COLLADABU::Math::Utils::equalsZero ( unitValue, getTolerance () ) )
            unitValue = 0.0;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_KILOMETER, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_KILOMETER;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_DECIMETER, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_DECIMETER;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH;
        else if ( COLLADABU::Math::Utils::equals ( unitValue, COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD, getTolerance () ) )
            unitValue = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD;
        return unitValue;
    }

    //-----------------------------
    bool DocumentImporter::writeScene ( const COLLADAFW::Scene* scene )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeScene(..): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep <= COPY_ELEMENTS ) 
        {
            // Make a copy of the instantiated visual scene element.
            mParseStep = COPY_ELEMENTS;
            mInstanceVisualScene = scene->getInstanceVisualScene ()->clone ();
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importNodes ()
    {
        if ( mParseStep >= ELEMENTS_COPIED )
        {
            // Get the visual scene element to import.
            for ( size_t i=0; i<mVisualScenesList.size (); ++i )
            {
                const COLLADAFW::VisualScene* visualScene = mVisualScenesList [i];
                if ( mInstanceVisualScene->getInstanciatedObjectId () == visualScene->getUniqueId () )
                {
                    const COLLADAFW::NodePointerArray& nodePointerArray = visualScene->getRootNodes ();

                    // Store the unique node ids in a map to the framework nodes.
                    mNodeImporter->importNodes ( nodePointerArray );
                }
            }

            // Import the library notes data.
            for ( size_t i=0; i<mLibraryNodesList.size (); ++i )
            {
                const COLLADAFW::LibraryNodes* libraryNodes = mLibraryNodesList [i];
                const COLLADAFW::NodePointerArray& nodePointerArray = libraryNodes->getNodes ();

                // Store the unique node ids in a map to the framework nodes.
                mNodeImporter->importNodes ( nodePointerArray );
            }
        }
    }

    //-----------------------------
    bool DocumentImporter::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeScene(..): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the visual scene element and push it into the list of visual scenes.
            mParseStep = COPY_ELEMENTS;
            mVisualScenesList.push_back ( new COLLADAFW::VisualScene ( *visualScene ) );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importVisualScene ()
    {
        if ( mParseStep >= ELEMENTS_COPIED )
        {
            // The file must already exist.
            if ( mFile == 0 )
            {
                std::cerr << "DocumentImporter::importVisualScene(..): Cant't import, no maya file exist!" << std::endl;
                return;
            }

            // Get the referenced visual scene element to import.
            for ( size_t i=0; i<mVisualScenesList.size (); ++i )
            {
                const COLLADAFW::VisualScene* visualScene = mVisualScenesList [i];
                if ( mInstanceVisualScene->getInstanciatedObjectId () == visualScene->getUniqueId () )
                {
                    // Import the data.
                    mVisualSceneImporter->importVisualScene ( visualScene );
                }
            }
            mParseStep = VISUAL_SCENE_IMPORTED;
        }
    }

    //-----------------------------
    bool DocumentImporter::writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeLibraryNodes(..): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the library nodes element and push it into the list of library nodes.
            mParseStep = COPY_ELEMENTS;
            mLibraryNodesList.push_back ( new COLLADAFW::LibraryNodes ( *libraryNodes ) );
        }

        return true;
    }

//     //-----------------------------
//     void DocumentImporter::importLibraryNodes ()
//     {
//         // The file must already exist.
//         if ( mFile == 0 )
//         {
//             std::cerr << "DocumentImporter::importLibraryNodes(..): Cant't import, no maya file exist!" << std::endl;
//             return;
//         }
// 
//         // Import the library notes data.
//         for ( size_t i=0; i<mLibraryNodesList.size (); ++i )
//         {
//             const COLLADAFW::LibraryNodes* libraryNodes = mLibraryNodesList [i];
//             mVisualSceneImporter->importLibraryNodes ( libraryNodes );
//         }
//     }

    //-----------------------------
    bool DocumentImporter::writeMaterial ( const COLLADAFW::Material* material )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeMaterial(..): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the material element and push it into the list.
            mParseStep = COPY_ELEMENTS;
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
            std::cerr << "DocumentImporter::importMaterials(..): Cant't import, no maya file exist!" << std::endl;
            return;
        }

        // Import the materials data.
        if ( mParseStep >= ELEMENTS_COPIED )
        {
            for ( size_t i=0; i<mMaterialsList.size (); ++i )
            {
                const COLLADAFW::Material* material = mMaterialsList [i];
                mMaterialImporter->importMaterial ( material );
            }
        }
    }

    //-----------------------------
    bool DocumentImporter::writeEffect ( const COLLADAFW::Effect* effect )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeEffect(..): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the effect element and push it into the list.
            mParseStep = COPY_ELEMENTS;
            mEffectsList.push_back ( new COLLADAFW::Effect ( *effect ) );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importEffects ()
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::importEffects(): Cant't import, no maya file exist!" << std::endl;
            return;
        }

        // Import the effects data.
        if ( mParseStep >= ELEMENTS_COPIED )
        {
            for ( size_t i=0; i<mEffectsList.size (); ++i )
            {
                const COLLADAFW::Effect* effect = mEffectsList [i];
                mEffectImporter->importEffect ( effect );
            }
        }
    }

    //-----------------------------
    bool DocumentImporter::writeImage ( const COLLADAFW::Image* image )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeImage(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        // We first should copy the images, about it's possible, that we have to create an 
        // image for more than one time. This happens if:
        // a) one image is referenced from multiple effects 
        // b) one image is referenced in multiple samplers in one effect 
        // c) one effect uses the same sampler multiple times.
        // We have to dublicate the image, about the possibility to create multiple uv-sets on it.
        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the material element and push it into the list.
            mParseStep = COPY_ELEMENTS;
            mImageImporter->storeImage ( image );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importImages ()
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::importImages(): Cant't import, no maya file exist!" << std::endl;
            return;
        }

        // Import the images data.
        if ( mParseStep >= ELEMENTS_COPIED )
        {
            mImageImporter->importImages ();
        }
    }

    //-----------------------------
    bool DocumentImporter::writeGeometry ( const COLLADAFW::Geometry* geometry )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeGeometry(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep >= SECOND_PARSING )
        {
            // Import the data.
            mGeometryImporter->importGeometry ( geometry );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeCamera ( const COLLADAFW::Camera* camera )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeCamera(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep >= SECOND_PARSING )
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
            std::cerr << "DocumentImporter::writeLight(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep >= SECOND_PARSING )
        {
            // Import the data.
            mLightImporter->importLight ( light );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeAnimation ( const COLLADAFW::Animation* animation )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeAnimation(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep >= SECOND_PARSING )
        {
            getAnimationImporter ()->importAnimation ( animation );
            mParseStep = ANIMATIONS_IMPORTED;
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeAnimationList ( const COLLADAFW::AnimationList* animationList )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeAnimationList(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        // We need the information about scale animations to adjust the physical dimension of a 
        // scale animation. To get this info, we have to get the transformations of the transform 
        // animations and have to check for scale animations. Scale animations must have a physical 
        // dimension number (double) instead of length (distance)!
        // The transformations exist after the first parsing, after the visual scene is imported.
        // So we have to store the animation lists in the first parsing. After the visual scene 
        // import we can iterate over the animation lists and determine the scale animations. After 
        // we know the scale animations, we can import the animations with the correct physical 
        // dimension. After we have imported all animations, we can write the animation connections
        // from the stored animation lists.
        // Order of the parse steps:
        // COPY_ELEMENTS
        // VISUAL_SCENE_IMPORTED
        // SECOND_PARSING
        // ANIMATIONS_IMPORTED
        // MAKE_CONNECTIONS


        // On first parsing, we have to store the animation lists.
        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the visual scene element and push it into the list of visual scenes.
            mParseStep = COPY_ELEMENTS;
            mAnimationListsList.push_back ( new COLLADAFW::AnimationList ( *animationList ) );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importAnimationLists ()
    {
        // After we have imported the visual scene, we can detect the scale animations.
        if ( mParseStep == MAKE_CONNECTIONS )
        {
            std::vector<COLLADAFW::AnimationList*>::const_iterator it = mAnimationListsList.begin ();
            while ( it != mAnimationListsList.end () )
            {
                const COLLADAFW::AnimationList* animationList = *it;
                getAnimationImporter ()->writeConnections ( animationList );
                ++it;
            }
        }
    }

    //-----------------------------
    void DocumentImporter::detectScaleAnimations ()
    {
        // After we have imported the visual scene, we can detect the scale animations.
        if ( mParseStep >= VISUAL_SCENE_IMPORTED )
        {
            std::vector<COLLADAFW::AnimationList*>::const_iterator it = mAnimationListsList.begin ();
            while ( it != mAnimationListsList.end () )
            {
                const COLLADAFW::AnimationList* animationList = *it;
                getAnimationImporter ()->detectScaleAnimations ( animationList );
                ++it;
            }
        }
    }

    //-----------------------------
    void DocumentImporter::importPlaybackOptions ()
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writePlaybackOptions(): Cant't import, no maya file exist!" << std::endl;
            return;
        }

        if ( mParseStep >= ANIMATIONS_IMPORTED )
        {
            mAnimationImporter->importPlaybackOptions ();
        }

    }

    //-----------------------------
    bool DocumentImporter::writeSkinControllerData ( 
        const COLLADAFW::SkinControllerData* skinControllerData )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeSkinControllerData(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }
        
        if ( mParseStep >= SECOND_PARSING )
        {
            mControllerImporter->importSkinControllerData ( skinControllerData );
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeController ( 
        const COLLADAFW::Controller* controller )
    {
        // The file must already exist.
        if ( mFile == 0 )
        {
            std::cerr << "DocumentImporter::writeController(): Cant't import, no maya file exist!" << std::endl;
            return false;
        }

        if ( mParseStep <= COPY_ELEMENTS )
        {
            // Make a copy of the controller element and push it into the list.
            mParseStep = COPY_ELEMENTS;
            mControllerImporter->storeController ( controller );
        }

        return true;
    }

    //-----------------------------
    void DocumentImporter::importMorphControllers ()
    {
        if ( mParseStep >= ELEMENTS_COPIED )
        {
            // The file must already exist.
            if ( mFile == 0 )
            {
                std::cerr << "DocumentImporter::importMorphControllers(): Cant't import, no maya file exist!" << std::endl;
                return;
            }

            // Import the morph controllers.
            mControllerImporter->importMorphControllers ();
        }
    }

    //-----------------------------
    bool DocumentImporter::writeFormulas ( const COLLADAFW::Formulas* formulas )
    {
        return true;
    }

    //-----------------------------
	bool DocumentImporter::writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene )
	{
        return true;
	}

    //-----------------------------
    const COLLADAFW::Node* DocumentImporter::findNode ( 
        const COLLADAFW::UniqueId& nodeId, 
        const COLLADAFW::NodePointerArray& nodes )
    {
        size_t numNodes = nodes.getCount ();
        for ( size_t i=0; i<numNodes; ++i )
        {
            const COLLADAFW::Node* node = nodes [i];
            if ( nodeId != node->getUniqueId () ) 
            {
                // Recursive call
                const COLLADAFW::NodePointerArray& childNodes = node->getChildNodes ();
                const COLLADAFW::Node* searchedNode = findNode ( nodeId, childNodes );
                if ( searchedNode ) return searchedNode;
            }
            else return node;
        }
        return 0;
    }

    //-----------------------------
    String DocumentImporter::addGlobalNodeId ( 
        const String& newId, 
        bool returnConverted /*= true*/, 
        bool alwaysAddNumberSuffix /*= false */ )
    {
        return mGlobalNodeIdList.addId ( newId, returnConverted, alwaysAddNumberSuffix );
    }

    //-----------------------------
    bool DocumentImporter::containsGlobalNodeId ( const String& id )
    {
        return mGlobalNodeIdList.containsId ( id );
    }

    //-----------------------------
    String DocumentImporter::addDependNodeId ( 
        const String& newId, 
        bool returnConverted /*= true*/, 
        bool alwaysAddNumberSuffix /*= false */ )
    {
        return mDependNodeIdList.addId ( newId, returnConverted, alwaysAddNumberSuffix );
    }

    //-----------------------------
    bool DocumentImporter::containsDependNodeId ( const String& id )
    {
        return mDependNodeIdList.containsId ( id );
    }

    //-----------------------------
    void DocumentImporter::addDagNodeId ( const String& newId )
    {
        mDagNodeIdSet.insert ( newId );
    }

    //-----------------------------
    bool DocumentImporter::containsDagNodeId ( const String& id )
    {
        std::set<String>::const_iterator it = mDagNodeIdSet.find ( id );
        if ( it != mDagNodeIdSet.end () ) return true;
        return false;
    }

    //-----------------------------
    const COLLADAFW::Material* DocumentImporter::getMaterialById ( const COLLADAFW::UniqueId& materialId )
    {
        std::vector<COLLADAFW::Material*>::const_iterator it = mMaterialsList.begin ();
        while ( it != mMaterialsList.end () )
        {
            if ( materialId == (*it)->getUniqueId () )
                return (*it);
            ++it;
        }
        return 0;
    }

	//------------------------------
	void DocumentImporter::start()
	{

	}

}