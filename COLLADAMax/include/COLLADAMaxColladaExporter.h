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


#ifndef __COLLADAMAX_COLLADAEXPORTER_H__
#define __COLLADAMAX_COLLADAEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"

#include <max.h>
#include <iparamb2.h>

// Exporter class ID
//#define COLLADAEXPORTER_CLASS_ID Class_ID(0x7d656d57, 0x6f963848)

namespace COLLADAMax
{

    // main exporter class

    class COLLADAExporter : public SceneExport
    {

    public:
        static const Class_ID COLLADAEXPORTER_CLASS_ID;

        static const String EXTENSIONNAME;
        static const String LONGDESCRIPTION;
        static const String SHORTDESCRIPTION;
        static const String AUTHORNAME;
        static const String COPYRIGHTMESSAGE;
        static const String OTHERMESSAGE1;
        static const String OTHERMESSAGE2;

        static const String PROGRESSSTART;
        static const String FATALERROR;


        static const unsigned int PLUGINVERSION;


    public:
        COLLADAExporter();
        virtual ~COLLADAExporter();

        // from SceneExport
        int ExtCount();     // Returns the number of file name extensions supported by the plug-in.
        const TCHAR* Ext ( int n );    // Return the 'i-th' file name extension (i.e. "dae").
        const TCHAR* LongDesc();     // Long ASCII description (i.e. "Autodesk 3D Studio File")
        const TCHAR* ShortDesc();    // Short ASCII description (i.e. "3D Studio")
        const TCHAR* AuthorName();    // ASCII Author name
        const TCHAR* CopyrightMessage();   // ASCII Copyright message
        const TCHAR* OtherMessage1();   // Other message #1
        const TCHAR* OtherMessage2();   // Other message #2
        unsigned int Version();     // Version number * 100 (i.e. v3.01 = 301)
        void ShowAbout ( HWND hWnd ); // Show DLL's "About..." box

        BOOL SupportsOptions ( int ext, DWORD options );
        int DoExport ( const TCHAR* name, ExpInterface* ei, Interface* i, BOOL suppressPrompts = FALSE, DWORD options = 0 );

    private:
        /** Disable copy constructor*/
        COLLADAExporter ( const COLLADAExporter & colladaExporter );

        /** Disable assignment operator*/
        COLLADAExporter & operator= ( const COLLADAExporter & colladaExporter );

    };

    ClassDesc2* getCOLLADAExporterDesc();


    //
    // ColladaExporterClassDesc
    //

    class ColladaExporterClassDesc : public ClassDesc2
    {

    public:
        int IsPublic()
        {
            return TRUE;
        }

        void * Create ( BOOL isLoading = FALSE )
        {
            isLoading;
            return new COLLADAExporter();
        }

        const TCHAR * ClassName()
        {
            return "NewCollada";
        }

        SClass_ID SuperClassID()
        {
            return SCENE_EXPORT_CLASS_ID;
        }

        Class_ID ClassID()
        {
            return COLLADAExporter::COLLADAEXPORTER_CLASS_ID;
        }

        const TCHAR* Category()
        {
            return "Export";
        } //GetString(IDS_CATEGORY_E); }

        const TCHAR* InternalName()
        {
            return _T ( "COLLADAExporter" );
        } // returns fixed parsable name (scripter-visible name)

        HINSTANCE HInstance()
        {
            return hInstance;
        }    // returns owning module handle

    };



}


#endif // __COLLADAMAX_COLLADAEXPORTER_H__
