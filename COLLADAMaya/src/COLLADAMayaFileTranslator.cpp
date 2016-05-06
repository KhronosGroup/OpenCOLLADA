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
#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaPlatform.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaFileTranslator.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaSyntax.h"

#include "DAE2MADocumentImporter.h"

// TODO
#include "COLLADAMayaImportOptions.h"

#include "COLLADASWException.h"

#include "COLLADABUVersionInfo.h"

#include <time.h>

#include <maya/MFnPlugin.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MGlobal.h>
#include <maya/MFileIO.h>
#if MAYA_API_VERSION >= 700
#include <maya/MHWShaderSwatchGenerator.h>
#endif

#include <fstream>


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
        //_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 

        MStatus status;

#ifdef _DEBUG
        // Activate the error logging
        MGlobal::startErrorLogging();
#endif
        // The default name of this file is OpenMayaErrorLog located in the 
        // current directory. This can be changed, however, by calling:
        //MGlobal::setErrorLogPathName("...");
  
        std::ostringstream stream; 
        stream << MAYA_API_VERSION;

        MFnPlugin plugin ( obj, 
            COLLADAMaya::TRANSLATOR_VENDOR, 
			COLLADABU::CURRENT_REVISION.c_str(),
            stream.str ().c_str () );

        // --------------------------------------------------------------
        // Register the import and the export file translator plug-ins.

        // Export plug-in
        status = plugin.registerFileTranslator ( 
            COLLADAMaya::COLLADA_EXPORTER,
            "", // pathname of the icon used in file selection dialogs
            COLLADAMaya::FileTranslator::createExporter, // this class implements the new file type
            (char*)COLLADAMaya::MEL_EXPORT_OPTS, // name of a MEL script that will be used to display the contents of the options dialog during file open and save
            NULL ); // defaultOptionsString
        if ( !status )
        {
            status.perror ( "registerFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to register OpenCOLLADA exporter: " ) + status );
            return status;
        }

        // Import plug-in
        status = plugin.registerFileTranslator ( 
            COLLADAMaya::COLLADA_IMPORTER,
            "",
            COLLADAMaya::FileTranslator::createImporter,
            (char*)COLLADAMaya::MEL_IMPORT_OPTS,
            NULL );
        if ( !status )
        {
            status.perror ( "registerFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to register OpenCOLLADA importer: " ) + status );
        }

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

        // Export plug-in
        status = plugin.deregisterFileTranslator ( COLLADAMaya::COLLADA_EXPORTER );
        if ( !status )
        {
            status.perror ( "deregisterFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to unregister OpenCOLLADA exporter: " ) + status );
            return status;
        }

        // Import plug-in
        status = plugin.deregisterFileTranslator ( COLLADAMaya::COLLADA_IMPORTER );
        if ( !status )
        {
            status.perror ( "deregisterFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to unregister OpenCOLLADA importer: " ) + status );
            return status;
        }

#if MAYA_API_VERSION >= 800
        // Disable the shared-reference node options.
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsSharedReference\" 0;" );
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsShareDisplayLayers\" 0;" );
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsShareShaders\" 0;" );
#endif // MAYA 8.0 and 8.5

#ifdef _DEBUG
        // Stop the error logging
        MGlobal::stopErrorLogging();
#endif

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
            // Save current selection
            MSelectionList selection;
            MGlobal::getActiveSelectionList(selection);

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

            // Restore selection
            MGlobal::setActiveSelectionList(selection);
        }
        catch ( COLLADASW::StreamWriterException* swException  )
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
        DocumentExporter documentExporter ( NativeString(filename.asChar()) );
        documentExporter.exportCurrentScene ( selectionOnly );

        // Display some closing information.
        endClock = clock();
        std::ostringstream stream; 
        stream << "Time to export into file \"" << filename.asChar() << "\": " << endClock - startClock << std::endl;
        MString message( stream.str().c_str() );
        std::cerr << message.asChar() << std::endl;

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
        MStatus status ( MS::kSuccess );

        try
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
            const MString filename ( nameBuffer );
#else
            const MString filename = file.fullName();
#endif  // OSMac

            // Process the import options
            ImportOptions::set ( options, mode );
            if (ImportOptions::hasError()) status = MStatus::kFailure;

            // Import the COLLADA DAE file
			status = importFromFile ( filename.asChar() );
        }
        catch ( COLLADABU::Exception* exception  )
        {
            MGlobal::displayError ( exception->getMessage().c_str() );
        }
        catch ( ... )
        {
            MGlobal::displayError ( "ColladaMaya has thrown an exception!" );
        }

        return status;
    }

    // ------------------------------
    MStatus FileTranslator::importFromFile ( const String& importFileName )
    {
        MStatus status = MS::kSuccess;

        // Get the time 
        clock_t startClock, endClock;
        startClock = clock();

        // Set the imported file name and path.
        COLLADABU::URI mayaAsciiFileURI ( importFileName ); 
        mayaAsciiFileURI.setPathExtension ( ".opencollada.ma" );

        String mayaAsciiFileName = mayaAsciiFileURI.getURIString ();
		const char* cpMayaAsciiFileName = mayaAsciiFileName.c_str();

        // Get the current maya version
        String mayaVersion ( MGlobal::mayaVersion ().asChar () );

        // We have to change the name on 64 bit machines. 
        // For example from "2008 x64" to "2008" or from "2008 Extension 2" to "2008".
        std::vector<String> words;
        String separator (" ");
        COLLADABU::Utils::split ( mayaVersion, separator, words );
        if ( words.size () > 1 ) 
        {
            mayaVersion = words[0];
        }

        // Actually import the document
		{
			DAE2MA::DocumentImporter documentImporter ( importFileName, mayaAsciiFileURI.getURIString (), mayaVersion.c_str () );
			documentImporter.importCurrentScene ();
		}

        // Display some closing information.
        endClock = clock();

        std::ostringstream stream; 
        stream << "Time to import into file \"" << mayaAsciiFileName << "\": " << endClock - startClock << std::endl;
        String message( stream.str() );
        std::cerr << message << std::endl;

        // TODO Open the maya ascii file in the maya instance
		MFileIO::importFile ( cpMayaAsciiFileName );
		//MFileIO::open ( mayaAsciiFileName.c_str (), "mayaAscii", true ); 

		//         mayaAsciiFileURI.setPathExtension ( ".opencollada.mb" );
		//         mayaFileName = mayaAsciiFileURI.getURIString ();
		//         MFileIO::saveAs ( mayaFileName.c_str () );
		//         MGlobal::displayInfo ( "File saved as maya binary: " );
		//         MGlobal::displayInfo ( mayaFileName.c_str () 
        
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

	// ------------------------------
    MString FileTranslator::filter() const
    {
        return "*.dae;*.xml";
    }


}// namespace COLLADA
