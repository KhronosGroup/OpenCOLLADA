/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADAMaxColladaPlugin.h"

namespace COLLADAMax
{

    const Class_ID COLLADAExporter::COLLADASWEXPORTER_CLASS_ID ( 0x7d656d57, 0x6f963848 );

	const TCHAR* COLLADAExporter::PROGRESSSTART = __T("COLLADA export...");


    //---------------------------------------------------------------
    COLLADAExporter::COLLADAExporter()
    {}

    //---------------------------------------------------------------
    COLLADAExporter::~COLLADAExporter()
    {}

    //---------------------------------------------------------------
    int COLLADAExporter::ExtCount()
    {
        return 1;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::Ext ( int )
    {
        return COLLADAPlugin::EXTENSIONNAME;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::LongDesc()
    {
        return COLLADAPlugin::LONGDESCRIPTION;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::ShortDesc()
    {
        return COLLADAPlugin::SHORTDESCRIPTION;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::AuthorName()
    {
        return COLLADAPlugin::AUTHORNAME;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::CopyrightMessage()
    {
        return COLLADAPlugin::COPYRIGHTMESSAGE;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::OtherMessage1()
    {
        return COLLADAPlugin::OTHERMESSAGE1;
    }

    //---------------------------------------------------------------
    const TCHAR* COLLADAExporter::OtherMessage2()
    {
        return COLLADAPlugin::OTHERMESSAGE2;
    }

    //---------------------------------------------------------------
    unsigned int COLLADAExporter::Version()
    {
        return COLLADAPlugin::PLUGINVERSION;
    }

    //---------------------------------------------------------------
    void COLLADAExporter::ShowAbout ( HWND )
    {
        /// @todo add about dialog
    }

    //---------------------------------------------------------------
    BOOL COLLADAExporter::SupportsOptions ( int, DWORD )
    {
        // @TODO Decide which options to support.  Simply return
        // true for each option supported by each Extension
        // the exporter supports.

        return TRUE;
    }


    //---------------------------------------------------------------
    DWORD WINAPI COLLADAExporter::fn ( LPVOID )
    {
        return 0;
    }

    //---------------------------------------------------------------
    int COLLADAExporter::DoExport ( const TCHAR* name, ExpInterface* UNUSED ( ei ), Interface* maxInterface, BOOL suppressPrompts, DWORD options )
    {
        bool success = true;
        maxInterface->ProgressStart ( const_cast<TCHAR*>(PROGRESSSTART), true, fn, 0 );

        try
        {
			bool exportOnlySelected = (options & SCENE_EXPORT_SELECTED) == SCENE_EXPORT_SELECTED;
			DocumentExporter document ( maxInterface, NativeString(name), mXRefExportFileNames, exportOnlySelected );
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
#ifdef UNICODE
			WideString exceptionMessage = COLLADABU::StringUtils::toWideString( streamWriterException.getMessage().c_str() );
			MessageBox ( 0, exceptionMessage.c_str(), COLLADAPlugin::SHORTDESCRIPTION, MB_OK );
#else
			MessageBox ( 0, streamWriterException.getMessage().c_str(), COLLADAPlugin::SHORTDESCRIPTION, MB_OK );
#endif
		}

        catch ( ... )
        {
            // Add some check, here, for full UI-mode or batch-mode only.
            MessageBox ( 0, COLLADAPlugin::FATALERROR, COLLADAPlugin::SHORTDESCRIPTION, MB_OK );
        }

        maxInterface->ProgressEnd();

        return success;
    }


    ClassDesc2* getCOLLADAExporterDesc()
    {
        static ColladaExporterClassDesc description;
        return &description;
    }

}
