/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_COLLADASWEXPORTER_H__
#define __COLLADAMAX_COLLADASWEXPORTER_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADASWIDList.h"

#include <max.h>
#include <iparamb2.h>

// Exporter class ID
//#define COLLADASWEXPORTER_CLASS_ID Class_ID(0x7d656d57, 0x6f963848)

namespace COLLADAMax
{

    // main exporter class

    class COLLADASWExporter : public SceneExport
    {

    public:
        static const Class_ID COLLADASWEXPORTER_CLASS_ID;

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


	private:
		/** Holds the unique file names of the exported XRef files. This is necessary if all files
		are exported into the same directory.*/
		COLLADASW::IDList mXRefExportFileNames;

    public:
        COLLADASWExporter();
        virtual ~COLLADASWExporter();

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
        COLLADASWExporter ( const COLLADASWExporter & colladaExporter );

        /** Disable assignment operator*/
        COLLADASWExporter & operator= ( const COLLADASWExporter & colladaExporter );

    };

    ClassDesc2* getCOLLADASWExporterDesc();


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
            return new COLLADASWExporter();
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
            return COLLADASWExporter::COLLADASWEXPORTER_CLASS_ID;
        }

        const TCHAR* Category()
        {
            return "Export";
        } //GetString(IDS_CATEGORY_E); }

        const TCHAR* InternalName()
        {
            return _T ( "COLLADASWExporter" );
        } // returns fixed parsable name (scripter-visible name)

        HINSTANCE HInstance()
        {
            return hInstance;
        }    // returns owning module handle

    };



}


#endif // __COLLADAMAX_COLLADASWEXPORTER_H__
