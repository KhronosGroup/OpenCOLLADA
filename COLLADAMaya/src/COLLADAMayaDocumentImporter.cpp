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
#include "COLLADAMayaEffectImporter.h"
#include "COLLADAMayaGeometryImporter.h"
#include "COLLADAMayaCameraImporter.h"
#include "COLLADAMayaLightImporter.h"
#include "COLLADAMayaImageImporter.h"
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

    const String DocumentImporter::ASCII_PATH_EXTENSION = ".ma";
    const String DocumentImporter::ASCII_PATH_EXTENSION_DEBUG = ".nextgen.ma";


    //---------------------------------
    DocumentImporter::DocumentImporter ( const String& fileName )
        : mColladaFileName ( fileName )
        , mSceneId ( "MayaScene" )
        , mFile ( 0 )
        , mVisualSceneImporter (0)
        , mGeometryImporter (0)
        , mMaterialImporter (0)
        , mEffectImporter (0)
        , mCameraImporter (0)
        , mLightImporter (0)
        , mImageImporter (0)
        , mSceneGraphWritten (false)
        , mLibraryNodesWritten (false)
        , mAssetWritten (false)
        , mSceneGraphRead (false)
        , mLibraryNodesRead (false)
        , mGeometryRead (false)
        , mCameraRead (false)
        , mLightRead (false)
        , mImageRead (false)
        , mNumDocumentParses (0)
        , mUpAxisType ( COLLADAFW::FileInfo::Y_UP )
        , mLinearUnitMeter ( COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER )
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
        mMaterialImporter = new MaterialImporter ( this );
        mEffectImporter = new EffectImporter ( this );
        mCameraImporter = new CameraImporter ( this );
        mLightImporter = new LightImporter ( this );
        mImageImporter = new ImageImporter (this);

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
        delete mMaterialImporter;
        delete mEffectImporter;
        delete mCameraImporter;
        delete mLightImporter;
        delete mImageImporter;
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

        errno_t err = fopen_s ( &mFile, mayaAsciiFileName.c_str (), "w+" );
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
        bool retValue = createMayaAsciiFile ();
        assert ( retValue );

        // TODO Initialise the maya default objects.
        if ( retValue ) 
        {
            mLightImporter->initialiseDefaultLightObjects ();
        }
    }

    //-----------------------------
    void DocumentImporter::finish ()
    {
        // There has not to be a <library_nodes> tag in the document!
        if ( mAssetWritten && mSceneGraphWritten && !mLibraryNodesWritten )
        {
            mLibraryNodesWritten = true;

            // Write the node instances, when all nodes of the visual scene 
            // and the library nodes are already imported!
            if ( mSceneGraphWritten && mLibraryNodesWritten )
            {
                // Write all the node instances
                mVisualSceneImporter->writeNodeInstances ();
            }

            if ( mGeometryRead || mCameraRead || mLightRead || mImageRead )
            {
                mGeometryRead = false;
                mCameraRead = false;
                mLightRead = false;
                mImageRead = false;
                readColladaDocument ();
            }
        }

        // If the last read is ready, we can write the connections and close the file.
        --mNumDocumentParses;
        if ( mNumDocumentParses == 0 ) 
        {
            // TODO After the complete read of the collada document, 
            // the connections can be written into the maya file.
            mMaterialImporter->writeConnections ();
            mLightImporter->writeConnections ();
            mEffectImporter->writeConnections ();

            // Close the file
            closeMayaAsciiFile ();
        }
    }

    //-----------------------------
    void DocumentImporter::readColladaDocument ()
    {
        COLLADASaxFWL::Loader loader ( &mSaxParserErrorHandler );
        COLLADAFW::Root root ( &loader, this );
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
        if ( mAssetWritten ) return true;

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // The maya version
        String mayaVersion ( MGlobal::mayaVersion ().asChar () );
        fprintf_s ( mFile, "//Maya ASCII %s scene\n", mayaVersion.c_str () );

        // We have to change the name on 64 bit machines. 
        // For example from "2008 x64" to "2008" (64bit Maya doesn't understand it's own version).
        std::vector<String> words;
        String separator (" ");
        COLLADABU::Utils::split ( mayaVersion, separator, words );
        if ( words.size () == 2 && COLLADABU::Utils::equalsIgnoreCase ( words[1], "x64") ) 
        {
            fprintf_s ( mFile, "requires maya \"%s\";\n", words[0].c_str () );
        }
        else
        {
            fprintf_s ( mFile, "requires maya \"%s\";\n", mayaVersion.c_str () );
        }

        // Get the unit informations.
        const COLLADAFW::FileInfo::Unit& unit = asset->getUnit ();

        // Set the default value to meters.
        String linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
        if ( ImportOptions::importUnits () )
        {
            linearUnitName = unit.getLinearUnitName ();
            mLinearUnitMeter = unit.getLinearUnitMeter ();

            // Set the linear unit in meters.
            // Maya knows: millimeter, centimeter, meter, foot, inch and yard.
            switch ( unit.getLinearUnitUnit () )
            {
            case COLLADAFW::FileInfo::Unit::KILOMETER:
                {
                    // Convert to meters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitMeter = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_KILOMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER;;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::METER:
                {
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitMeter =  COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::DECIMETER:
                {
                    // Convert to meters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitMeter = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_DECIMETER;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::CENTIMETER:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                    mLinearUnitMeter =  COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::MILLIMETER:
                {
                    // Convert to centimeters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER_NAME;
                    mLinearUnitMeter = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_MILLIMETER / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_CENTIMETER;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::FOOT:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT_NAME;
                    mLinearUnitMeter =  COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_FOOT;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::INCH:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH_NAME;
                    mLinearUnitMeter =  COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_INCH;
                    break;
                }
            case COLLADAFW::FileInfo::Unit::YARD:
                {
                    // Don't convert 
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD_NAME;
                    mLinearUnitMeter =  COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD / COLLADAFW::FileInfo::Unit::LINEAR_UNIT_YARD;
                    break;
                }
            default:
                {
                    // Set to meters
                    linearUnitName = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER_NAME;
                    mLinearUnitMeter = COLLADAFW::FileInfo::Unit::LINEAR_UNIT_METER;
                    break;
                }
            }
        }

        fprintf_s ( mFile, "currentUnit -l %s -a %s -t %s;\n", 
            linearUnitName.c_str (), unit.getAngularUnitName ().c_str (), unit.getTimeUnitName ().c_str () );

        if ( ImportOptions::importUpAxis () )
        {
            mUpAxisType = asset->getUpAxisType ();
        }
        else
        {
            mUpAxisType = COLLADAFW::FileInfo::Y_UP;

            if ( asset->getUpAxisType () == COLLADAFW::FileInfo::Z_UP )
            {
//                 // TODO Create a root node with the global transformation.
//                 double convertMatrix[4][4] = { {1,0,0,0}, {0,0,1,0}, {0,-1,0,0}, {0,0,0,1} };
// 
//                 // Convert the matrix to a maya matrix.
//                 MMatrix matrix ( convertMatrix );
//                 MTransformationMatrix tm ( matrix );
// 
//                 // Create a transform node of the specific type.
//                 MayaDM::Transform transformNode ( mFile, "unitConversion" );
// 
//                 // TODO Add the name in the list of node names!
//                 // TODO No unique id! We have to push in list! (other node pathes)
// 
//                 MStatus status;
//                 MVector transVec = tm.getTranslation ( MSpace::kTransform, &status );
//                 transformNode.setTranslate ( ( MayaDM::double3 ( transVec.x, transVec.y, transVec.z ) ) );
//                 //transformNode.setTranslate ( toLinearUnit ( MayaDM::double3 ( transVec.x, transVec.y, transVec.z ) ) );
// 
//                 double rotation[3];
//                 MTransformationMatrix::RotationOrder order;
//                 tm.getRotation ( rotation, order, MSpace::kTransform );
//                 if ( ! ( MVector (0,0,0) == MVector ( rotation ) ) )
//                     transformNode.setRotate ( ( MayaDM::double3 ( COLLADABU::Math::Utils::radToDeg(rotation[0]), COLLADABU::Math::Utils::radToDeg(rotation[1]), COLLADABU::Math::Utils::radToDeg(rotation[2]) ) ) );
//                 //transformNode.setRotate ( toAngularUnit ( MayaDM::double3 ( rotation[0], rotation[1], rotation[2] ) ) );
// 
//                 double scale[3];
//                 tm.getScale ( scale, MSpace::kTransform );
//                 if ( ! ( MVector (1,1,1) == MVector ( scale ) ) )
//                     transformNode.setScale ( ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) ) );
//                 //transformNode.setScale ( toUpAxisTypeFactor ( MayaDM::double3 ( scale[0], scale[1], scale[2] ) ) );
// 
//                 double shear[3];
//                 tm.getShear ( shear, MSpace::kTransform );
//                 if ( ! ( MVector (0,0,0) == MVector ( shear ) ) )
//                     transformNode.setShear ( ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) ) );
//                 //transformNode.setShear ( toUpAxisTypeAxis ( MayaDM::double3 ( shear[0], shear[1], shear[2] ) ) );
            }
        }

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

        if ( mSceneGraphRead || mLibraryNodesRead || mGeometryRead || mCameraRead || mLightRead || mImageRead )
        {
            mSceneGraphRead = false;
            mLibraryNodesRead = false;
            mGeometryRead = false;
            mCameraRead = false;
            mLightRead = false;
            mImageRead = false;
            readColladaDocument ();
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
    {
        // Order: asset, scene graph, others
        if ( !mAssetWritten ) 
        {
            mSceneGraphRead = true;
            return true;
        }
        if ( mSceneGraphWritten ) return true;

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mVisualSceneImporter->importVisualScene ( visualScene );
        mSceneGraphWritten = true;

        // Write the node instances, when all nodes of the visual scene 
        // and the library nodes are already imported!
        if ( mSceneGraphWritten && mLibraryNodesWritten )
        {
            // Write all the node instances
            mVisualSceneImporter->writeNodeInstances ();
        }

        if ( mGeometryRead || mCameraRead || mLightRead || mImageRead )
        {
            mGeometryRead = false;
            mCameraRead = false;
            mLightRead = false;
            mImageRead = false;
            readColladaDocument ();
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes )
    {
        // Order: asset, scene graph, library nodes, others
        if ( !mAssetWritten ) 
        {
            mLibraryNodesRead = true;
            return true;
        }
        if ( mLibraryNodesWritten ) return true;

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mVisualSceneImporter->importLibraryNodes ( libraryNodes );
        mLibraryNodesWritten = true;

        // Write the node instances, when all nodes of the visual scene 
        // and the library nodes are already imported!
        if ( mSceneGraphWritten && mLibraryNodesWritten )
        {
            // Write all the node instances
            mVisualSceneImporter->writeNodeInstances ();
        }

        if ( mGeometryRead || mCameraRead || mLightRead || mImageRead )
        {
            mGeometryRead = false;
            mCameraRead = false;
            mLightRead = false;
            mImageRead = false;
            readColladaDocument ();
        }

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeGeometry ( const COLLADAFW::Geometry* geometry )
    {
        // Order: asset, scene graph, library nodes, others
        if ( !mAssetWritten || !mSceneGraphWritten || !mLibraryNodesWritten ) 
        {
            mGeometryRead = true;
            return true;
        }

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mGeometryImporter->importGeometry ( geometry );

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeMaterial ( const COLLADAFW::Material* material )
    {
        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mMaterialImporter->importMaterial ( material );

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeEffect ( const COLLADAFW::Effect* effect )
    {
        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mEffectImporter->importEffect ( effect );

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeCamera ( const COLLADAFW::Camera* camera )
    {
        // Order: asset, scene graph, library nodes, others
        if ( !mAssetWritten || !mSceneGraphWritten || !mLibraryNodesWritten ) 
        {
            mCameraRead = true;
            return true;
        }

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mCameraImporter->importCamera ( camera );

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeLight ( const COLLADAFW::Light* light )
    {
        // Order: asset, scene graph, library nodes, others
        if ( !mAssetWritten || !mSceneGraphWritten || !mLibraryNodesWritten ) 
        {
            mLightRead = true;
            return true;
        }

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mLightImporter->importLight ( light );

        return true;
    }

    //-----------------------------
    bool DocumentImporter::writeImage ( const COLLADAFW::Image* image )
    {
        // Order: asset, scene graph, library nodes, others
        if ( !mAssetWritten || !mSceneGraphWritten || !mLibraryNodesWritten ) 
        {
            mImageRead = true;
            return true;
        }

        // Create the file, if not already done.
        if ( mFile == 0 ) start();

        // Import the data.
        mImageImporter->importImage ( image );

        return true;
    }
}