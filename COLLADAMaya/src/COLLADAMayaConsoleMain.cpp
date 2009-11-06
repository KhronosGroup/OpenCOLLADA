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
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaException.h"
#include "COLLADAMayaFileTranslator.h"
#include "COLLADAMayaSyntax.h"

#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaImportOptions.h"

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

    // Convert backward to forward slashes
    for ( size_t i=0; i<MAX_FILENAME_LEN; ++i)
    {   
        if ( inFileName[i] == '\\' ) inFileName[i] = '/';
        if ( outFileName[i] == '\\' ) outFileName[i] = '/';
    }

    if ( isImport )
    {
        // Set the import options
        MString importOptions = COLLADAMaya::EMPTY_STRING.c_str ();
        COLLADAMaya::ImportOptions::set ( importOptions, MPxFileTranslator::kImportAccessMode );

        // Get the start time 
        clock_t startClock, endClock;
        startClock = clock();

        COLLADABU::URI mayaAsciiFileURI ( inFileName );
#ifdef NDEBUG
        mayaAsciiFileURI.setPathExtension ( COLLADAMaya::FileTranslator::ASCII_PATH_EXTENSION );
#else
        mayaAsciiFileURI.setPathExtension ( COLLADAMaya::FileTranslator::ASCII_PATH_EXTENSION_DEBUG );
#endif
        std::string mayaAsciiFileName = mayaAsciiFileURI.getURIString ();

        // Actually export the document
        COLLADAMaya::DocumentImporter documentImporter ( inFileName, mayaAsciiFileName );
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
    }
    else
    {
        // initialize the maya library - This basically starts up Maya
        MStatus stat;
        stat = MLibrary::initialize (argv[0]);
        if (!stat) {
            stat.perror("MLibrary::initialize");
            return 1;
        }

#ifdef _DEBUG
        // Activate the error logging. The default name of this file is OpenMayaErrorLog located in 
        // the current directory ( "$(MAYA_LOCATION)/bin/OpenMayaErrorLog.txt" ).
        MGlobal::startErrorLogging();
#endif

        // TODO If we want to export cgfx shaders, we have to load the cgfxShader plug-in!
//         MStringArray plugins;
//         MGlobal::executeCommand ( "loadPlugin \"$(MAYA_LOCATION)/bin/plug-ins/cgfxShader\";", plugins );
//         size_t num = plugins.length ();
// 
//         std::string command = "requires \"cgfxShader\" \"cgfxShader 4.4 for Maya 2009.0 (Sep 11 2008)\";";
//         MGlobal::executeCommand ( command.c_str () );

        // Check if the file exist, which open the file that the user specified
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
#ifdef _DEBUG
            cout << "Time to export into file \"" << outFileName << "\": " << endClock - startClock << " ms" << endl;
#endif
        }
        else 
        {
            std::cerr << "[ERROR] Could not open file " << inFileName << std::endl;
        }

#ifdef _DEBUG
        // Stop the error logging
        MGlobal::stopErrorLogging();
#endif

        // close down maya
        MLibrary::cleanup(0);
    }

#ifdef _DEBUG
    getchar();
#endif

    return 0;
}
