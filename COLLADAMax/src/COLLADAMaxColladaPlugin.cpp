#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxCOLLADAPlugin.h"

#include "COLLADAMaxVersionInfo.h"

namespace COLLADAMax
{

	const TCHAR* COLLADAPlugin::EXTENSIONNAME = __T("dae");
	const TCHAR* COLLADAPlugin::LONGDESCRIPTION = __T("New COLLADA Document");
	const TCHAR* COLLADAPlugin::SHORTDESCRIPTION = __T("OpenCOLLADA");
	const TCHAR* COLLADAPlugin::AUTHORNAME = __T("NetAllied Systems GmbH");
	const TCHAR* COLLADAPlugin::COPYRIGHTMESSAGE = __T("Copyright 2008-2011 NetAllied Systems GmbH.");
	const TCHAR* COLLADAPlugin::OTHERMESSAGE1 = __T("");
	const TCHAR* COLLADAPlugin::OTHERMESSAGE2 = __T("");

	const TCHAR* COLLADAPlugin::PLUGIN_VERSION_TCHAR = __T("Version: 1.4.0");
	const String COLLADAPlugin::PLUGIN_VERSION_STRING = "Version: 1.4.0";
	const String COLLADAPlugin::REVISION_STRING = (CURRENT_REVISION.empty() ? "" : String("Revision: ") + CURRENT_REVISION);
	const String COLLADAPlugin::PLATFORM_STRING = String("Platform: ") + CURRENT_PLATFORM;
	const String COLLADAPlugin::CONFIGURATION_STRING = String("Configuration: ") + CURRENT_CONFIGURATION;


	const TCHAR* COLLADAPlugin::FATALERROR = __T("Fatal Error: exception caught.");

	const unsigned int COLLADAPlugin::PLUGINVERSION = 505;


	//--------------------------------------------------------------------
	COLLADAPlugin::COLLADAPlugin()
	{
	}
	
	//--------------------------------------------------------------------
	COLLADAPlugin::~COLLADAPlugin()
	{
	}

} // namespace COLLADAMax
