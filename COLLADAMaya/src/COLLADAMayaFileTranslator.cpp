/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "COLLADAMayaStableHeaders.h"
#include "ColladaMayaPlatform.h"
#include "COLLADAMayaSyntax.h"
#include "COLLADAMayaFileTranslator.h"
#include "COLLADAMayaDocumentExporter.h"
#include "COLLADAMayaExportOptions.h"

#include <maya/MFnPlugin.h>
#include <maya/MFileIO.h>
#include <maya/MItDependencyNodes.h>
#include <maya/MFnDependencyNode.h>

#if MAYA_API_VERSION >= 700
#include <maya/MHWShaderSwatchGenerator.h>
#endif

namespace COLLADAMaya
{

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

        MFnPlugin plugin ( obj, TRANSLATOR_VENDOR, TRANSLATOR_VERSION, TRANSLATOR_MAYA_API_VERSION );

        // Add plug-in feature registration here
        //

//         // Register the COLLADA document node
//         // This node is needed by the translator: register it before the translation plug-in.
//         status = plugin.registerNode ( COLLADA_DOCUMENT,
//                                        DocumentNode::id,
//                                        DocumentNode::creator,
//                                        DocumentNode::initialize,
//                                        MPxNode::kDependNode );
// 
//         if ( status != MStatus::kSuccess )
//         {
//             status.perror ( "registerNode" );
//             return status;
//         }

        // --------------------------------------------------------------
        // Register the import and the export file translator plug-ins.

        // Export-Plugin
        status = plugin.registerFileTranslator ( 
                 COLLADA_EXPORTER,
                 "", // pathname of the icon used in file selection dialogs
                 FileTranslator::createExporter, // this class implements the new file type
                 MEL_EXPORT_OPTS, // name of a MEL script that will be used to display the contents of the options dialog during file open and save
                 NULL ); // defaultOptionsString

        if ( !status )
        {
            status.perror ( "registerFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to register COLLADA exporter: " ) + status );
            return status;
        }

        // Import-Plugin
        status = plugin.registerFileTranslator ( 
                COLLADA_IMPORTER,
                 "",
                 FileTranslator::createImporter,
                 MEL_IMPORT_OPTS,
                 NULL );

        if ( !status )
        {
            status.perror ( "registerFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to register COLLADA importer: " ) + status );
        }

        /*
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

        status = plugin.registerNode("colladafxShader", CFXShaderNode::id, CFXShaderNode::creator,
         CFXShaderNode::initialize, MPxNode::kHwShaderNode,
         &UserClassify);
        if (!status) {
         status.perror("registerNode");
         return status;
        }

        status = plugin.registerNode("colladafxPasses", CFXPasses::id, CFXPasses::creator,
         CFXPasses::initialize, MPxNode::kHwShaderNode,
         &UserClassify);

        if (!status) {
         status.perror("registerNode");
         return status;
        }
        */

        /*
        // TODO
        plugin.registerCommand("colladafxShaderCmd", CFXShaderCommand::creator, CFXShaderCommand::newSyntax);

        plugin.registerDragAndDropBehavior("CFXBehavior", CFXBehavior::creator);

        MGlobal::executeCommand("if (`pluginInfo -query -loaded cgfxShader.mll`){ print(\"cgfxShader.mll must be unloaded to use ColladaFX shader plug-in.\");unloadPlugin cgfxShader.mll; }");
        MGlobal::executeCommand("source AEcolladafxShaderTemplate.mel");
        MGlobal::executeCommand("source AEcolladafxPassesTemplate.mel");
        */
        // needed in CFXParameter::loadDefaultTexture()


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
        status = plugin.deregisterFileTranslator ( COLLADA_EXPORTER );
        if ( !status )
        {
            status.perror ( "deregisterFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to unregister COLLADA exporter: " ) + status );
            return status;
        }

        // Import-Plugin
        status = plugin.deregisterFileTranslator ( COLLADA_IMPORTER );
        if ( !status )
        {
            status.perror ( "deregisterFileTranslator" );
            MGlobal::displayError ( MString ( "Unable to unregister COLLADA importer: " ) + status );
            return status;
        }

        /*
        status = plugin.deregisterNode(CFXShaderNode::id);
        if (!status)
        {
         status.perror("deregisterNode");
         return status;
        }

        status = plugin.deregisterNode(CFXPasses::id);
        if (!status)
        {
         status.perror("deregisterNode");
         return status;
        }

        plugin.deregisterCommand("CFXShaderCommand");
        plugin.deregisterDragAndDropBehavior("CFXBehavior");
        plugin.deregisterNode(DaeDocNode::id);
        */

#if MAYA_API_VERSION >= 800
        // Disable the shared-reference node options.
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsSharedReference\" 0;" );
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsShareDisplayLayers\" 0;" );
        MGlobal::executeCommand ( "optionVar -iv \"referenceOptionsShareShaders\" 0;" );
#endif // MAYA 8.0 and 8.5


//         status = plugin.deregisterNode ( DocumentNode::id );
//         if ( !status )
//         {
//             status.perror ( "deregisterNode" );
//             return status;
//         }

        return status;
    }


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
    /* In this example, only ‘export all’ and ‘export selection’ options are
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

#ifndef _DEBUG

        try
        {
#endif

            // Extract the filename
#if defined (OSMac_)
            char nameBuffer[MAXPATHLEN];
            strcpy ( nameBuffer, file.fullName().asChar() );
            const MString fileName ( nameBuffer );
#else
            const MString fileName = file.fullName();
#endif // OSMac

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
            }

            // Parse the export options
            ExportOptions::set ( options );

            exportSelection = mode == MPxFileTranslator::kExportActiveAccessMode;

            // Do the actual export now
            status = exportIntoFile ( fileName, exportSelection );

#ifndef _DEBUG
        }

        catch ( ... )
        {
            MGlobal::displayError ( "ColladaMaya has thrown an exception!" );
        }

#endif

        /*
        if (MPxFileTranslator::kExportAccessMode == mode) {
         if (MStatus::kFailure == exportAll(newFile)) {
          return MStatus::kFailure;
         }
        } else if (MPxFileTranslator::kExportActiveAccessMode == mode) {
         if (MStatus::kFailure == exportSelection(newFile)) {
          return MStatus::kFailure;
         }
        } else {
         return MStatus::kFailure;
        }
        */

        MGlobal::displayInfo ( "Export successful!" );

        return status;
    }


    /************************************************************************/
    /* Parses the Maya DAG/DG graphs and writes out a COLLADA document                                                                     */
    /************************************************************************/
    MStatus FileTranslator::exportIntoFile ( const MString& filename, const bool selectionOnly )
    {
        MStatus status = MS::kSuccess;

//   if (MPxFileTranslator::kExportAccessMode == mode) {
//    if (MStatus::kFailure == exportAll(newFile)) {
//     return MStatus::kFailure;
//    }
//   } else if (MPxFileTranslator::kExportActiveAccessMode == mode) {
//    if (MStatus::kFailure == exportSelection(newFile)) {
//     return MStatus::kFailure;
//    }
//   } else {
//    return MStatus::kFailure;
//   }

        // Actually export the document
        DocumentExporter* documentExporter = new DocumentExporter ( ( const String ) filename.asChar() );
        documentExporter->exportCurrentScene ( selectionOnly );
        delete documentExporter;

        // Display some closing information.
        MString message;
        message = "ColladaMaya export finished:  \"" + filename + "\"";
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

        MStatus rval ( MS::kSuccess );

        /*
        const int maxLineSize = 1024;
        char buf[maxLineSize];
        ifstream inputfile(fname.asChar(), ios::in);
        if (!inputfile) {
         // open failed
         cerr << fname << ": could not be opened for reading\n";
         return MS::kFailure;
        }
        if (!inputfile.getline (buf, maxLineSize)) {
         cerr << "file " << fname << " contained no lines ... aborting\n";
         return MS::kFailure;
        }
        if (0 != strncmp(buf, magic.asChar(), magic.length())) {
         cerr << "first line of file " << fname;
         cerr << " did not contain " << magic.asChar() << " ... aborting\n";
         return MS::kFailure;
        }
        while (inputfile.getline (buf, maxLineSize)) {
         //processing each line of the file
         MString cmdString;
         cmdString.set(buf);
         if (!MGlobal::executeCommand(cmdString))
          rval = MS::kFailure;
        }
        inputfile.close();
        */

        return rval;
    }

    /************************************************************************/
    /* Check the given file to see if it is COLLADA data
    /************************************************************************/
    MPxFileTranslator::MFileKind FileTranslator::identifyFile ( const MFileObject &fileObject,
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
}