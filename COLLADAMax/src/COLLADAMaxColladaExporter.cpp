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


#include "COLLADAMaxStableHeaders.h"

#include "COLLADAMaxColladaExporter.h"
#include "COLLADAMaxDocumentExporter.h"
#include "COLLADASWException.h"

namespace COLLADAMax
{

    const Class_ID COLLADASWExporter::COLLADASWEXPORTER_CLASS_ID ( 0x7d656d57, 0x6f963848 );

    const String COLLADASWExporter::EXTENSIONNAME = "dae";
    const String COLLADASWExporter::LONGDESCRIPTION = "New COLLADA Document";
    const String COLLADASWExporter::SHORTDESCRIPTION = "NEWCOLLADA";
    const String COLLADASWExporter::AUTHORNAME = "netAllied";
    const String COLLADASWExporter::COPYRIGHTMESSAGE = "Copyright 2008 netAllied. Copyright 2006 Feeling Software. Based on Autodesk' 3dsMax COLLADASW Tools.";
    const String COLLADASWExporter::OTHERMESSAGE1 = "";
    const String COLLADASWExporter::OTHERMESSAGE2 = "";

    const String COLLADASWExporter::PROGRESSSTART = "COLLADA export...";

    const String COLLADASWExporter::FATALERROR = "Fatal Error: exception caught.";

    const unsigned int COLLADASWExporter::PLUGINVERSION = 400;


    //---------------------------------------------------------------
    COLLADASWExporter::COLLADASWExporter()
    {}

    //---------------------------------------------------------------
    COLLADASWExporter::~COLLADASWExporter()
    {}

    //---------------------------------------------------------------
    int COLLADASWExporter::ExtCount()
    {
        return 1;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::Ext ( int )
    {
        return EXTENSIONNAME.c_str();
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::LongDesc()
    {
        return LONGDESCRIPTION.c_str();
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::ShortDesc()
    {
        return SHORTDESCRIPTION.c_str();
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::AuthorName()
    {
        return AUTHORNAME.c_str();
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::CopyrightMessage()
    {
        return COPYRIGHTMESSAGE.c_str();
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::OtherMessage1()
    {
        return OTHERMESSAGE1.c_str();
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADASWExporter::OtherMessage2()
    {
        return OTHERMESSAGE2.c_str();
    }

    //---------------------------------------------------------------
    unsigned int COLLADASWExporter::Version()
    {
        return PLUGINVERSION;
    }

    //---------------------------------------------------------------
    void COLLADASWExporter::ShowAbout ( HWND )
    {
        /// @todo add about dialog
    }

    //---------------------------------------------------------------
    BOOL COLLADASWExporter::SupportsOptions ( int, DWORD )
    {
        // @TODO Decide which options to support.  Simply return
        // true for each option supported by each Extension
        // the exporter supports.

        return TRUE;
    }


    //---------------------------------------------------------------
    DWORD WINAPI fn ( LPVOID )
    {
        return 0;
    }

    //---------------------------------------------------------------
    int COLLADASWExporter::DoExport ( const TCHAR* name, ExpInterface* UNUSED ( ei ), Interface* maxInterface, BOOL suppressPrompts, DWORD options )
    {
        bool success = true;
        maxInterface->ProgressStart ( ( char * ) PROGRESSSTART.c_str(), true, fn, 0 );

        try
        {
			DocumentExporter document ( maxInterface, name, mXRefExportFileNames );
			if (document.showExportOptions(suppressPrompts != false) )
			{
				/// @todo handle errors here
				document.exportRootMaxScene();
			}
			else
			{
				// Set to TRUE although nothing happened in order to avoid the "generic failure" dialog.
				success = true; 
			}
        }
		catch ( COLLADASW::StreamWriterException& streamWriterException  )
		{
			// Add some check, here, for full UI-mode or batch-mode only.
			MessageBox ( 0, streamWriterException.getMessage().c_str(), SHORTDESCRIPTION.c_str(), MB_OK );
		}

        catch ( ... )
        {
            // Add some check, here, for full UI-mode or batch-mode only.
            MessageBox ( 0, FATALERROR.c_str(), SHORTDESCRIPTION.c_str(), MB_OK );
        }

        maxInterface->ProgressEnd();

        return success;
    }


    ClassDesc2* getCOLLADASWExporterDesc()
    {
        static ColladaExporterClassDesc description;
        return &description;
    }

}
