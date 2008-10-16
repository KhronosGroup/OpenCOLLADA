//--------------------------------------------------------------------------------------------
/// \file	main.cpp
/// \author	Rob Bateman
/// \brief	Probably the simplest maya exporter code possible. This will work on both linux
/// 		and win32, makes sure that your VisualC++ options has set the correct paths to
/// 		the maya includes and libraries. When compiling on linux, make sure you have
/// 		set the correct paths contained within the makefile that is included.
///
/// 		When compiling under linux, you will need to have gtk2 installed (the file dialog
/// 		code uses it. It would be fairly trivial to strip that out however).
//--------------------------------------------------------------------------------------------
#include "ColladaMayaStableHeaders.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"
#include "COLLADAMayaDocumentImporter.h"
#include "COLLADAMayaImportOptions.h"

#include <maya/MItDependencyNodes.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFileIO.h>
#include <maya/MLibrary.h>

#include <fstream>
#include <time.h>

// generic linux(gtk2) & win32 file dialog code
#include "COLLADAMayaConsoleFileDialog.h"
#include "COLLADAMayaException.h"
#include "COLLADAUtils.h"

// link to some fairly funky maya libs. NOTE: The Image library only became part of maya
// from version 4.01 onwards. It is not available in version 4.0
//
#ifdef WIN32
	#pragma comment(lib,"Foundation.lib")
	#pragma comment(lib,"OpenMaya.lib")
	#pragma comment(lib,"OpenMayaFx.lib")
	#pragma comment(lib,"Image.lib")
	#pragma comment(lib,"OpenMayaAnim.lib")
#endif

// defines
#define MAX_FILENAME_LEN 512

#ifdef WIN32
int main(int argc,char** argv)
{
#else // hack for linux & gtk

// gtk needs the command line args for initialisation
int   g_argc=0;
char** g_argv=0;

int main(int argc,char** argv)
{
    g_argc=argc;
    g_argv=argv;
#endif
    char inFileName[MAX_FILENAME_LEN]={0};
    char outFileName[MAX_FILENAME_LEN]={0};

    // Save the number of arguments 
    int inFileArgPos = 0;
    int outFileArgPos = 0;
    char* inFileExtension;
    char* outFileExtension;

    // Check if we want to import...
    bool isImport = false;
    if ( argc > 1 )
    {
        std::ostringstream stream; 
        stream << argv[1];

        std::string message ( stream.str().c_str() );
        if ( COLLADA::Utils::equalsIgnoreCase ( message, "-i" ) )
        {
            isImport = true;
            inFileExtension = "dae file\0*.dae\0\0";
            outFileExtension = "mb file\0*.mb\0\0";

            // Check for an input and an output filename
            if ( argc > 2 ) inFileArgPos = 2;
            if ( argc > 3 ) outFileArgPos = 3;
        }
        else
        {
            isImport = false;
            inFileExtension = "mb file\0*.mb\0\0";
            outFileExtension = "dae file\0*.dae\0\0";

            // Check for an input and an output filename
            if ( argc > 1 ) inFileArgPos = 1;
            if ( argc > 2 ) outFileArgPos = 2;
        }
    }

    // both an infile and outfile specified as command line args
    if ( inFileArgPos > 0 && outFileArgPos > 0 )
    {
	    strcpy ( inFileName, argv[inFileArgPos] );
	    strcpy ( outFileName, argv[outFileArgPos] );
    }

    // Just a input file
    else if ( inFileArgPos > 0 )
    {
	    // got infile from command line args
	    strcpy ( inFileName, argv[inFileArgPos] );

	    // ask for an outfile
        if ( !COLLADAMaya::saveFileDialog ( outFileName, outFileExtension ) ) 
        {
		    return EXIT_FAILURE;
	    }
    }
    
    // no args specified so pop up a couple fo file dialogs
    else if ( ( !isImport && argc == 1 ) || ( isImport && argc == 2) )
    {
	    // get in file name
        if ( !COLLADAMaya::openFileDialog ( inFileName, inFileExtension ) ) 
        {
		    return EXIT_FAILURE;
	    }

	    // get out file name
        if ( !COLLADAMaya::saveFileDialog ( outFileName, outFileExtension ) ) 
        {
		    return EXIT_FAILURE;
	    }
    }
    else 
    {
        std::cerr << "[ERROR] Usage on export:\n\tCOLLADAMaya [infile.mb|infile.ma] [outfile.dae]\n";
        std::cerr << "[ERROR] Usage on import:\n\tCOLLADAMaya -i [infile.dae] [outfile.mb|outfile.ma]\n";
	    return EXIT_FAILURE;
    }

    // initialise the maya library - This basically starts up Maya
    MLibrary::initialize(argv[0]);

    // Convert backward to forward slashes
    for ( size_t i=0; i<MAX_FILENAME_LEN; ++i)
    {   
        if ( inFileName[i] == '\\' ) inFileName[i] = '/';
        if ( outFileName[i] == '\\' ) outFileName[i] = '/';
    }

    if ( isImport )
    {
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
            COLLADAMaya::DocumentExporter documentExporter ( outFileName );
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

    return 0;
}
