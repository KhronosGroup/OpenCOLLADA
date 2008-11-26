#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxCOLLADAPlugin.h"

namespace COLLADAMax
{

	const String COLLADAPlugin::EXTENSIONNAME = "dae";
	const String COLLADAPlugin::LONGDESCRIPTION = "New COLLADA Document";
	const String COLLADAPlugin::SHORTDESCRIPTION = "NEWCOLLADA";
	const String COLLADAPlugin::AUTHORNAME = "netAllied";
	const String COLLADAPlugin::COPYRIGHTMESSAGE = "Copyright 2008 netAllied. Copyright 2006 Feeling Software. Based on Autodesk' 3dsMax COLLADASW Tools.";
	const String COLLADAPlugin::OTHERMESSAGE1 = "";
	const String COLLADAPlugin::OTHERMESSAGE2 = "";


	const String COLLADAPlugin::FATALERROR = "Fatal Error: exception caught.";

	const unsigned int COLLADAPlugin::PLUGINVERSION = 400;


	//--------------------------------------------------------------------
	COLLADAPlugin::COLLADAPlugin()
	{
	}
	
	//--------------------------------------------------------------------
	COLLADAPlugin::~COLLADAPlugin()
	{
	}

} // namespace COLLADAMax
