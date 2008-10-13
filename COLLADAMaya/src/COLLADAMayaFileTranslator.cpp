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
#include "ColladaMayaPlatform.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaFileTranslator.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAStreamWriterException.h"
#include <time.h>

#include <maya/MFnPlugin.h>
#include <maya/MFileIO.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MGlobal.h>

#if MAYA_API_VERSION >= 700
#include <maya/MHWShaderSwatchGenerator.h>
#endif

//#include <DAE.h>
//#include <dom/domCOLLADA.h>
//#include <dom/domElements.h>


    // This is a nasty bit of hackyness for compilation under Windows. Under Win32 you need
    // to compile a dll project and change the extension from "dll" to "mll". One additional
    // thing we have to do is 'export' the initializePlugin and uninitializePlugin functions.
    // This basically means that when maya loads the dll, it can see the two Functions it needs.
    // If for some reason your plugin fails to load, it may be this thats causing the problems.
    // Under linux we simply need to compile it with the -shared flag.
    //
#ifdef WIN32
#define MLL_EXPORT __declspec(dllexport)
#else
#define MLL_EXPORT
#endif

    //
    // Description:
    //  this method is called when the plug-in is loaded into Maya.
    //  It registers all of the services that this plug-in provides with Maya.
    //
    // Arguments:
    //  obj - a handle to the plug-in object (use MFnPlugin to access it)
    //
    MStatus MLL_EXPORT initializePlugin ( MObject obj )
    {
        MStatus   status;

        MFnPlugin plugin ( obj, 
            COLLADAMaya::TRANSLATOR_VENDOR, 
            COLLADAMaya::TRANSLATOR_VERSION, 
            COLLADAMaya::TRANSLATOR_MAYA_API_VERSION );

        // --------------------------------------------------------------
        // Register the import and the export file translator plug-ins.

        // Export-Plugin
        status = plugin.registerFileTranslator ( 
                 COLLADAMaya::COLLADA_EXPORTER,
                 "", // pathname of the icon used in file selection dialogs
                 COLLADAMaya::FileTranslator::createExporter, // this class implements the new file type
                 COLLADAMaya::MEL_EXPORT_OPTS, // name of a MEL script that will be used to display the contents of the options dialog during file open and save
                 NULL ); // defaultOptionsString

        if ( !status )
        {
            status.perror ( "registerFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to register COLLADA exporter: " ) + status );
            return status;
        }

//         // Import-Plugin
//         status = plugin.registerFileTranslator ( 
//                 COLLADA_IMPORTER,
//                  "",
//                  FileTranslator::createImporter,
//                  MEL_IMPORT_OPTS,
//                  NULL );
// 
//         if ( !status )
//         {
//             status.perror ( "registerFileTranslator" );
//             MGlobal::displayError ( MString ( "Unable to register COLLADA importer: " ) + status );
//         }

        // TODO
        MString UserClassify("shader/surface/utility");

        #if MAYA_API_VERSION >= 700
        // Don't initialize swatches in batch mode
        if (MGlobal::mayaState() != MGlobal::kBatch)
        {
         const MString& swatchName = MHWShaderSwatchGenerator::initialize();
         UserClassify = MString("shader/surface/utility/:swatch/"+swatchName);
        }
        #endif // MAYA_API_VERSION >= 700

        return status;
    }


    //
    // Description:
    //  this method is called when the plug-in is unloaded from Maya. It
    //  deregisters all of the services that it was providing.
    //
    // Arguments:
    //  obj - a handle to the plug-in object (use MFnPlugin to access it)
    //
    MStatus MLL_EXPORT uninitializePlugin ( MObject obj )
    {
        MStatus   status;
        MFnPlugin plugin ( obj );

        // Add plug-in feature de-registration here
        //

        // Export-Plugin
        status = plugin.deregisterFileTranslator ( COLLADAMaya::COLLADA_EXPORTER );
        if ( !status )
        {
            status.perror ( "deregisterFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to unregister COLLADA exporter: " ) + status );
            return status;
        }

//         // Import-Plugin
//         status = plugin.deregisterFileTranslator ( COLLADA_IMPORTER );
//         if ( !status )
//         {
//             status.perror ( "deregisterFileTranslator" );
//             MGlobal::displayError ( MString ( "Unable to unregister COLLADA importer: " ) + status );
//             return status;
//         }

#if MAYA_API_VERSION >= 800
        // Disable the shared-reference node options.
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsSharedReference\" 0;" );
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsShareDisplayLayers\" 0;" );
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsShareShaders\" 0;" );
#endif // MAYA 8.0 and 8.5

        return status;
    }


namespace COLLADAMaya
{

    /************************************************************************/
    /* Constructor and Destructor of the DaeFileTranslator class                                                                     */
    /************************************************************************/
    uint FileTranslator::readDepth = 0;

    FileTranslator::FileTranslator ( bool _isImporter )
    {
        isImporter = _isImporter;
    }

    FileTranslator::~FileTranslator()
    {
    }



    // Create a new instance of the translator
    // These two methods are registered to Maya's plugin module in the above initializePlugin function.
    void* FileTranslator::createExporter()
    {
        return new FileTranslator ( false );
    }

    void* FileTranslator::createImporter()
    {
        return new FileTranslator ( true );
    }

    /************************************************************************/
    /* The writer() method provides a message through the script editor and
    /* returns a status to indicate the results.
    /* In this example, only "export all" and "export selection" options are
    /* allowed when trying to save data. Other options will result in the
    /* display of a failure message through the script editor and returns a
    /* MS:kFailure, which indicates that the file type cannot be understood
    /* by the translator.
    /************************************************************************/
    MStatus FileTranslator::writer ( const MFileObject& file,
                                     const MString& options,
                                     MPxFileTranslator::FileAccessMode mode )
    {
        MStatus status = MStatus::kFailure;

        try
        {
            // Extract the filename
#if defined (OSMac_)
            char nameBuffer[MAXPATHLEN];
            strcpy ( nameBuffer, file.fullName().asChar() );
            const MString fileName ( nameBuffer );
#else
            const MString fileName = file.fullName();
#endif // OSMac

            // TODO Export the referenced files!
            // Maya forces the write of all the references, on export.
            // Intentionally skip known reference file paths.
            for ( MItDependencyNodes it ( MFn::kReference ); !it.isDone(); it.next() )
            {
                MObject refNode = it.item();
                MString refNodeName = MFnDependencyNode ( refNode ).name();

                MString refNodeFilename;
                MGlobal::executeCommand ( MString ( "reference -rfn \"" ) + refNodeName + MString ( "\" -q -filename" ),
                                          refNodeFilename );

                if ( refNodeFilename == fileName ) return MStatus::kSuccess;

                if ( ExportOptions::exportXRefs() )
                {
                    // TODO Open file export dialog ( !? HOW ?! ) to get a DAE filename 
                    // to export the referenced file.
                    
                }
            }

            // Parse the export options
            ExportOptions::set ( options );

            // Check, if we should just export the selected Objects
            exportSelection = mode == MPxFileTranslator::kExportActiveAccessMode;

            // Do the actual export now
            status = exportIntoFile ( fileName, exportSelection );

            MGlobal::displayInfo ( "Export successful!" );
        }
        catch ( COLLADA::StreamWriterException* swException  )
        {
            String message = "StreamWriterException: " + swException->getMessage();
            MGlobal::displayError ( message.c_str() );
        }
        catch ( ... )
        {
            MGlobal::displayError ( "ColladaMaya has thrown an exception!" );
        }

        return status;
    }


    /************************************************************************/
    /* Parses the Maya DAG/DG graphs and writes out a COLLADA document                                                                     */
    /************************************************************************/
    MStatus FileTranslator::exportIntoFile ( const MString& filename, const bool selectionOnly )
    {
        MStatus status = MS::kSuccess;

        /** To get the time */
        clock_t startClock, endClock;
        startClock = clock();

        // Actually export the document
        DocumentExporter documentExporter ( ( const String ) filename.asChar() );
        documentExporter.exportCurrentScene ( selectionOnly );

        // Display some closing information.
        endClock = clock();
        std::ostringstream stream; 
        stream << "Time to export into file \"" << filename << "\": " << endClock - startClock << endl;
        MString message( stream.str().c_str() );
        MGlobal::displayInfo ( message );

        return status;
    }



    /************************************************************************/
    /* The reader() method reads each line of the file and returns a
    /* MS::kFailure if it cannot be opened by the translator. If a file type
    /* cannot be recognized by the translator, the method creates a new
    /* object via MEL to support the data in that file.
    /************************************************************************/
    MStatus FileTranslator::reader ( const MFileObject& file,
                                     const MString& options,
                                     MPxFileTranslator::FileAccessMode mode )
    {

#if MAYA_API_VERSION >= 800

        if ( mode == MPxFileTranslator::kReferenceAccessMode )
        {
            int optionValue;
            MGlobal::executeCommand ( "optionVar -q \"referenceOptionsSharedReference\";", optionValue );

            if ( optionValue != 0 )
            {
#ifdef WIN32
                MessageBox ( NULL, "Maya may now hang. Do disable the reference option named: \"Shared Reference Nodes\".", "POSSIBLE HANG", MB_OK );
#endif
            }
        }

#endif // Maya 8.0 and 8.5


#if defined (OSMac_)
        char nameBuffer[MAXPATHLEN];
        strcpy ( nameBuffer, file.fullName().asChar() );
        const MString fname ( nameBuffer );
#else
        const MString fname = file.fullName();
#endif  // OSMac


        // TODO Process the import options
//        ImportOptions::set ( options, mode );

        MStatus rval ( MS::kSuccess );

        // Import the COLLADA DAE file
        rval = importFromFile ( fname );

        return rval;
    }

    // ------------------------------
    MStatus FileTranslator::importFromFile ( const MString& filename )
    {
        MStatus status = MS::kSuccess;

//         // Actually import the document
//         DocumentExporter documentExporter ( ( const String ) filename.asChar() );
// 
//         DAE dae;
//         domCOLLADA* colladaDocument = dae.open ( filename.asChar() );
// 
//         domLibrary_visual_scenes_Array visualScenesArray = colladaDocument->getLibrary_visual_scenes_array();
// 
//         // TODO Import the COLLADA DAE file!
//         size_t numOfScenes = visualScenesArray.getCount();
//         for ( size_t i=0; i<numOfScenes; ++i )
//         {
//             domLibrary_visual_scenesRef vsRef = visualScenesArray.get ( i );
//             const domVisual_scene_Array vs = vsRef->getVisual_scene_array();
//             for (size_t j = 0; j < vs.getCount(); j++)
//             {
//             }
// 
//             // TODO
//            documentExporter.importScene ();
//        }


        // Importing our scene
//         DaeDoc* document = colladaNode->NewDocument(filename);
//         document->Import(CImportOptions::IsReferenceMode() && readDepth > 1);

        //if (CImportOptions::HasError()) status = MStatus::kFailure;

        return status;
    }


    /************************************************************************/
    /* Check the given file to see if it is COLLADA data
    /************************************************************************/
    MPxFileTranslator::MFileKind FileTranslator::identifyFile ( 
        const MFileObject &fileObject,
        const char *buffer,
        short size )
    const
    {
        // Just check for the proper extension for now
        MFileKind rval = kNotMyFileType;
        int extLocation = fileObject.name().rindex ( '.' );

        if ( extLocation > 0 )
        {
            MString ext = fileObject.name().substring ( extLocation + 1, fileObject.name().length()-1 ).toLowerCase();

            if ( ext == "dae" || ext == "xml" )
            {
                rval = kIsMyFileType;
            }
        }

        return rval;
    }

    // Return the default extension for COLLADA files
    MString FileTranslator::defaultExtension() const
    {
        return "dae";
    }

    MString FileTranslator::filter() const
    {
        return "*.dae;*.xml";
    }


}// namespace COLLADA