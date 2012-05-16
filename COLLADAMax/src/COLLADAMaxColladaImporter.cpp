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
#include "COLLADAMaxColladaImporter.h"
#include "COLLADAMaxColladaPlugin.h"
#include "COLLADAMaxDocumentImporter.h"

namespace COLLADAMax
{
	const Class_ID ColladaImporter::COLLADAIMPORTER_CLASS_ID (0x6cc0e3b, 0x28c77f86);

	const String ColladaImporter::PROGRESSSTART = "COLLADA import...";


	//--------------------------------------------------------------------
	ColladaImporter::ColladaImporter()
	{
	}
	
	//--------------------------------------------------------------------
	ColladaImporter::~ColladaImporter()
	{
	}


	//---------------------------------------------------------------
	int ColladaImporter::ExtCount()
	{
		return 1;
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::Ext ( int )
	{
		return COLLADAPlugin::EXTENSIONNAME.c_str();
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::LongDesc()
	{
		return COLLADAPlugin::LONGDESCRIPTION.c_str();
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::ShortDesc()
	{
		return COLLADAPlugin::SHORTDESCRIPTION.c_str();
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::AuthorName()
	{
		return COLLADAPlugin::AUTHORNAME.c_str();
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::CopyrightMessage()
	{
		return COLLADAPlugin::COPYRIGHTMESSAGE.c_str();
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::OtherMessage1()
	{
		return COLLADAPlugin::OTHERMESSAGE1.c_str();
	}

	//---------------------------------------------------------------
	const TCHAR* ColladaImporter::OtherMessage2()
	{
		return COLLADAPlugin::OTHERMESSAGE2.c_str();
	}

	//---------------------------------------------------------------
	unsigned int ColladaImporter::Version()
	{
		return COLLADAPlugin::PLUGINVERSION;
	}

	//---------------------------------------------------------------
	void ColladaImporter::ShowAbout ( HWND )
	{
		/// @todo add about dialog
	}

	//---------------------------------------------------------------
	BOOL ColladaImporter::SupportsOptions ( int, DWORD )
	{
		// @TODO Decide which options to support.  Simply return
		// true for each option supported by each Extension
		// the exporter supports.

		return TRUE;
	}

	//---------------------------------------------------------------
	DWORD WINAPI ColladaImporter::fn ( LPVOID )
	{
		return 0;
	}


	int ColladaImporter::DoImport(const TCHAR *fileName,ImpInterface *maxImportInterface,Interface *maxInterface, BOOL suppressPrompts/*=FALSE*/)
	{
		bool success = true;
		maxInterface->ProgressStart ( ( char * ) PROGRESSSTART.c_str(), true, fn, 0 );
//	    maxInterface->DisableSceneRedraw();

		try
		{
			NativeString nativeFileName(fileName);
			DocumentImporter documentImporter ( maxInterface, maxImportInterface, nativeFileName );

			documentImporter.import();

/*			if (documentImporter.showExportOptions(suppressPrompts != false) )
			{
				/// @todo handle errors here
				documentImporter.import();
			}
			else
			{
				// Set to TRUE although nothing happened in order to avoid the "generic failure" dialog.
				success = true; 
			}
*/
		}
/**		catch ( COLLADASW::StreamWriterException& streamWriterException  )
		{
			// Add some check, here, for full UI-mode or batch-mode only.
			MessageBox ( 0, streamWriterException.getMessage().c_str(), COLLADAPlugin::SHORTDESCRIPTION.c_str(), MB_OK );
		}
		*/

		catch ( ... )
		{
			// Add some check, here, for full UI-mode or batch-mode only.
			MessageBox ( 0, COLLADAPlugin::FATALERROR.c_str(), COLLADAPlugin::SHORTDESCRIPTION.c_str(), MB_OK );
		}

		maxInterface->ProgressEnd();

//		maxInterface->EnableSceneRedraw();
		return success;
	}

	ClassDesc2* getCOLLADAImporterDesc()
	{
		static ColladaImporterClassDesc description;
		return &description;
	}



} // namespace COLLADAMax
