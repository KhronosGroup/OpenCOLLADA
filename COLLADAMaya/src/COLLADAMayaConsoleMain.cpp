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
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaException.h"

#ifdef CREATE_IMPORT_PLUGIN
#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaImportOptions.h"
#endif // CREATE_IMPORT_PLUGIN

#include <maya/MItDependencyNodes.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFileIO.h>
#include <maya/MLibrary.h>

#include <fstream>
#include <time.h>


#define MAX_FILENAME_LEN 512

/**
 * Usage on export:
 * COLLADAMaya [infile.mb|infile.ma] [outfile.dae]
 * 
 * Usage on import:
 * COLLADAMaya -i [infile.dae]
 */
#ifdef WIN32
int main(int argc,char** argv)
{
#else 
// hack for linux & gtk
// gtk needs the command line args for initialization
int   g_argc=0;
char** g_argv=0;

int main(int argc,char** argv)
{
    g_argc=argc;
    g_argv=argv;
#endif

    // Activate the error logging. The default name of this file is OpenMayaErrorLog located in 
    // the current directory ( "$(MAYA_LOCATION)/bin/OpenMayaErrorLog.txt" ).
    MGlobal::startErrorLogging();

//     // The default name of this file is OpenMayaErrorLog located in the 
//     // current directory. This can be changed, however, by calling:
//     std::string pathName = "C:/Temp/OpenMayaErrorLog.txt"; //MGlobal::errorLogPathName ().asChar ();
//     MGlobal::setErrorLogPathName ( pathName.c_str () );

    char inFileName[MAX_FILENAME_LEN]={0};
    char outFileName[MAX_FILENAME_LEN]={0};

    // Save the number of arguments 
    int inFileArgPos = 0;
    int outFileArgPos = 0;

    // Check if we want to import...
    bool isImport = false;
    if ( argc > 1 )
    {
        std::ostringstream stream; 
        stream << argv[1];

        std::string message ( stream.str().c_str() );
        if ( COLLADASW::Utils::equalsIgnoreCase ( message, "-i" ) )
        {
            isImport = true;

            // Check for an input and an output filename
            if ( argc > 2 ) inFileArgPos = 2;
        }
        else
        {
            isImport = false;

            // Check for an input and - on export - for an output filename
            if ( argc > 1 ) inFileArgPos = 1;
            if ( argc > 2 ) outFileArgPos = 2;
        }
    }

    // both an inputfile and outputfile specified as command line args
    if ( inFileArgPos > 0 && outFileArgPos > 0 )
    {
	    strcpy ( inFileName, argv[inFileArgPos] );
	    strcpy ( outFileName, argv[outFileArgPos] );
    }

    // Just a input file
    else if ( isImport && inFileArgPos > 0 )
    {
	    // got infile from command line args
	    strcpy ( inFileName, argv[inFileArgPos] );
    }
    
    else 
    {
        std::cerr << "[ERROR] Usage on export:\n\tCOLLADAMaya [infile.mb|infile.ma] [outfile.dae]\n";
        std::cerr << "[ERROR] Usage on import:\n\tCOLLADAMaya -i [infile.dae]\n";
	    return EXIT_FAILURE;
    }

    // initialize the maya library - This basically starts up Maya
    MLibrary::initialize(argv[0]);

    // Convert backward to forward slashes
    for ( size_t i=0; i<MAX_FILENAME_LEN; ++i)
    {   
        if ( inFileName[i] == '\\' ) inFileName[i] = '/';
        if ( outFileName[i] == '\\' ) outFileName[i] = '/';
    }

    if ( isImport )
    {
#ifdef CREATE_IMPORT_PLUGIN
        // Set the import options
        MString importOptions = "";
        COLLADAMaya::ImportOptions::set ( importOptions, MPxFileTranslator::kImportAccessMode );

        // Get the start time 
        clock_t startClock, endClock;
        startClock = clock();

        // Actually export the document
        COLLADAMaya::DocumentImporter documentImporter ( inFileName );
        try
        {
            documentImporter.importCurrentScene ();
        }
        catch ( COLLADAMaya::ColladaMayaException* ex )
        {
            std::cerr << "[COLLADAMayaException] " << ex->getMessage() << std::endl;
        }
        catch ( ... )
        {
            std::cerr << "Import not successful! " << std::endl;
        }

        // Display some closing information.
        endClock = clock();
        cout << "Time to import file \"" << inFileName << "\": " << endClock - startClock << " ms" << endl;
#endif
#ifndef CREATE_IMPORT_PLUGIN
        cout << "No import options available! Please define the \"CREATE_IMPORT_PLUGIN\" preprocessor flag!" << endl;
#endif
    }
    else
    {
        // open the file that the user specified
        if ( MS::kSuccess == MFileIO::open(inFileName, NULL, true) )
        {
            // Set the export options
            MString exportOptions = "relativePaths=false;";
            COLLADAMaya::ExportOptions::set ( exportOptions );

            // Get the start time 
            clock_t startClock, endClock;
            startClock = clock();

            // Actually export the document
			COLLADASW::NativeString nativeOutFileName(outFileName);
			COLLADAMaya::DocumentExporter documentExporter ( nativeOutFileName );
            try
            {
                bool selectionOnly = false;
                documentExporter.exportCurrentScene ( selectionOnly );
            }
            catch ( COLLADAMaya::ColladaMayaException* ex )
            {
                std::cerr << "[COLLADAMayaException] " << ex->getMessage() << std::endl;
            }
            catch ( ... )
            {
                std::cerr << "Export not successful! " << std::endl;
            }

            // Display some closing information.
            endClock = clock();
            cout << "Time to export into file \"" << outFileName << "\": " << endClock - startClock << " ms" << endl;
        }
        else 
        {
            std::cerr << "[ERROR] Could not open file " << inFileName << std::endl;
        }
    }


    // close down maya
    MLibrary::cleanup(0);

    // Stop the error logging
    MGlobal::stopErrorLogging();


    return 0;
}
