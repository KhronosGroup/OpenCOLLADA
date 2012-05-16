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

//#include "vld.h"
//#include <crtdbg.h> 

#include "COLLADAMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaFileTranslator.h"
#include "COLLADAMayaSyntax.h"

// TODO
#include "COLLADAMayaImportOptions.h"

#include "DAE2MADocumentImporter.h"
#include "DAE2MASyntax.h"

#include <maya/MItDependencyNodes.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFileIO.h>
#include <maya/MLibrary.h>

#include <fstream>
#include <time.h>


#define MAX_FILENAME_LEN 512

/**
* Method to check the filename and to proof, if the file should be overwritten, if it already exist.
*/
bool checkFileName ( std::string &mayaAsciiFileName )
{
    bool write = true;
    if ( mayaAsciiFileName.size () == 0 )
    {
        std::cout << "Filename not valid!" << std::endl;
#ifdef _DEBUG
        getchar();
#endif
        return false;
    }

    COLLADABU::URI mayaAsciiFileURI ( mayaAsciiFileName );
    if ( !COLLADABU::Utils::equalsIgnoreCase ( mayaAsciiFileURI.getPathExtension (), "ma" ) )
    {
        std::cout << "Just write \"ma\" files!" << std::endl;
        std::cout << "Please enter another output file name: ";
        std::cin >> mayaAsciiFileName;
        write = checkFileName ( mayaAsciiFileName );
    }

    if ( std::ifstream ( mayaAsciiFileName.c_str () ) )
    {
        write = false;
        std::cout << "File already exists. Do you want to overwrite? [j/n] ";
        char sign;
        std::cin >> sign;
        if ( sign != 'j' ) 
        {
            std::cout << "Please enter another output file name: ";
            std::cin >> mayaAsciiFileName;
            write = checkFileName ( mayaAsciiFileName );
        }
    }
    return write;
}


/**
 * Usage on export:
 * COLLADAMaya [infile.mb|infile.ma] [outfile.dae]
 * 
 * Usage on import:
 * COLLADAMaya -i [infile.dae] [outfile.ma] -v [Maya version (default is 2009)]
 */
#ifdef COLLADABU_OS_WIN
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

    //_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 
    //_CrtSetBreakAlloc ( 16787 ); 

//     // The default name of this file is OpenMayaErrorLog located in the 
//     // current directory. This can be changed, however, by calling:
//     std::string pathName = "C:/Temp/OpenMayaErrorLog.txt"; //MGlobal::errorLogPathName ().asChar ();
//     MGlobal::setErrorLogPathName ( pathName.c_str () );

    char inFileName[MAX_FILENAME_LEN]={0};
    char outFileName[MAX_FILENAME_LEN]={0};
    char mayaVersion[6];

    // Save the number of arguments 
    int inFileArgPos = 0;
    int outFileArgPos = 0;
    int mayaVersionArgPos = 0;

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
            if ( argc > 3 ) 
            {
                stream.clear ();
                stream << argv[3];
                if ( !COLLADABU::Utils::equals ( stream.str (), "-v" ) )
                    outFileArgPos = 3;
                else if ( argc > 4 ) mayaVersionArgPos = 4;
            }
            if ( argc > 4 )
            {
                stream.clear ();
                stream << argv[4];
                if ( COLLADABU::Utils::equals ( stream.str (), "-v" ) )
                    mayaVersionArgPos = 5;
            }
        }
        else
        {
            isImport = false;

            // Check for an input and - on export - for an output filename
            if ( argc > 1 ) inFileArgPos = 1;
            if ( argc > 2 ) outFileArgPos = 2;
        }
    }

    // If no output filename is set, the input filename will be used.
    bool hasOutFileName = false;

    // both an inputfile and outputfile specified as command line args
    if ( inFileArgPos > 0 && outFileArgPos > 0 )
    {
	    strcpy ( inFileName, argv[inFileArgPos] );
	    strcpy ( outFileName, argv[outFileArgPos] );
        hasOutFileName = true;
        if ( mayaVersionArgPos > 0 )
            strcpy ( mayaVersion, argv[mayaVersionArgPos] );
        else strcpy ( mayaVersion, DAE2MA::MAYA_VERSION_DEFAULT);
    }

    // Just a input file
    else if ( isImport && inFileArgPos > 0 )
    {
	    // got infile from command line args
	    strcpy ( inFileName, argv[inFileArgPos] );
        if ( mayaVersionArgPos > 0 )
            strcpy ( mayaVersion, argv[mayaVersionArgPos] );
        else strcpy ( mayaVersion, DAE2MA::MAYA_VERSION_DEFAULT);
    }
    
    else 
    {
        std::cerr << "[ERROR] Usage on export:\n\tCOLLADAMaya [infile.mb|infile.ma] [outfile.dae]\n";
        std::cerr << "[ERROR] Usage on import:\n\tCOLLADAMaya -i [infile.dae] [outfile.ma] -v [Maya version (default is 2009)]\n";
#ifdef _DEBUG
        getchar();
#endif
	    return EXIT_FAILURE;
    }

    // Convert backward to forward slashes
    char c;
    bool fileEnd = false;
    for ( size_t i=0; i<MAX_FILENAME_LEN && !fileEnd; ++i )
    {   
        c = inFileName[i];
        if ( c == '0' ) fileEnd = true;
        if ( c == '\\' ) inFileName[i] = '/';
    }
    fileEnd = false;
    for ( size_t i=0; i<MAX_FILENAME_LEN && !fileEnd; ++i )
    {   
        c = outFileName[i];
        if ( c == '0' ) fileEnd = true;
        if ( c == '\\' ) outFileName[i] = '/';
    }


    if ( isImport )
    {
        // Set the import options
        MString importOptions = DAE2MA::EMPTY_STRING.c_str ();
        COLLADAMaya::ImportOptions::set ( importOptions, MPxFileTranslator::kImportAccessMode );

        // Get the start time 
        clock_t startClock, endClock;
        startClock = clock();

        // Get the output filename.
        std::string mayaAsciiFileName;
        if ( !hasOutFileName )
        {
#ifdef NDEBUG
            std::cout << "Please enter an output file name: " << std::endl;
            std::cin >> mayaAsciiFileName;

            // Check if the filename is not empty and the file already exist.
            bool write = checkFileName ( mayaAsciiFileName );
            if ( !write ) return 0;
#else
            COLLADABU::URI mayaAsciiFileURI ( inFileName );
            mayaAsciiFileURI.setPathExtension ( ".opencollada.ma" );
            mayaAsciiFileName = mayaAsciiFileURI.getURIString ();
#endif
        }
        else
        {
            // Check if the filename is not empty and the file already exist.
            mayaAsciiFileName = outFileName;
            bool write = checkFileName ( mayaAsciiFileName );
            if ( !write ) return 0;
        }

        // Actually import the document
        DAE2MA::DocumentImporter documentImporter ( inFileName, mayaAsciiFileName, mayaVersion );
        documentImporter.importCurrentScene ();

        // Display some closing information.
        endClock = clock();
		std::cout << "Time to import file \"" << inFileName << "\": " << endClock - startClock << " ms" << std::endl;
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

            bool selectionOnly = false;
            documentExporter.exportCurrentScene ( selectionOnly );

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
