#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxCOLLADAPlugin.h"

#include "COLLADABUVersionInfo.h"

namespace COLLADAMax
{

	const TCHAR* COLLADAPlugin::EXTENSIONNAME = __T("dae");
	const TCHAR* COLLADAPlugin::LONGDESCRIPTION = __T("New COLLADA Document");
	const TCHAR* COLLADAPlugin::SHORTDESCRIPTION = __T("OpenCOLLADA");
	const TCHAR* COLLADAPlugin::AUTHORNAME = __T("NetAllied Systems GmbH");
	const TCHAR* COLLADAPlugin::COPYRIGHTMESSAGE = __T("Copyright 2008-2011 NetAllied Systems GmbH.");
	const TCHAR* COLLADAPlugin::OTHERMESSAGE1 = __T("");
	const TCHAR* COLLADAPlugin::OTHERMESSAGE2 = __T("");

	const TCHAR* COLLADAPlugin::PLUGIN_VERSION_TCHAR = __T("Version: 1.4.1");
	const String COLLADAPlugin::PLUGIN_VERSION_STRING = "Version: 1.4.1";
	const String COLLADAPlugin::REVISION_STRING = (COLLADABU::CURRENT_REVISION.empty() ? "" : String("Revision: ") + COLLADABU::CURRENT_REVISION);

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
