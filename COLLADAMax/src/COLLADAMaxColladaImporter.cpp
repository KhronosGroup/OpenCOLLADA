#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxColladaImporter.h"
#include "COLLADAMaxColladaPlugin.h"

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

	int ColladaImporter::DoImport(const TCHAR *name,ImpInterface *ii,Interface *i, BOOL suppressPrompts/*=FALSE*/)
	{
		return true;
	}

	ClassDesc2* getCOLLADAImporterDesc()
	{
		static ColladaImporterClassDesc description;
		return &description;
	}



} // namespace COLLADAMax
