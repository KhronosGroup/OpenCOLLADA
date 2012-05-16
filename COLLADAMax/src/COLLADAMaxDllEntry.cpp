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
#include "COLLADAMaxColladaImporter.h"
#include "COLLADAMaxGoogleWarehouse.h"

#include "COLLADAMaxColladaPlugin.h"

#include "COLLADAMaxVersionInfo.h"

HINSTANCE hInstance;
int controlsInit = FALSE;

static const COLLADAMax::String LIBDESCRIPTION = "OpenCOLLADA" + 
		(COLLADAMax::COLLADAPlugin::PLUGIN_VERSION_STRING.empty() ? "" : (COLLADAMax::String(" ") + COLLADAMax::COLLADAPlugin::PLUGIN_VERSION_STRING))+
		(COLLADAMax::COLLADAPlugin::REVISION_STRING.empty() ? "" : (COLLADAMax::String(" ") + COLLADAMax::COLLADAPlugin::REVISION_STRING));

BOOL WINAPI DllMain ( HINSTANCE hinstDLL, ULONG fdwReason, LPVOID UNUSED ( lpvReserved ) )
{
    switch ( fdwReason )
    {

    case DLL_PROCESS_ATTACH:
        hInstance = hinstDLL;
#if MAX_VERSION_MAJOR < 10

        InitCustomControls ( hInstance );
#endif // pre-Max 2008 only.

        break;

    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

extern "C" __declspec ( dllexport ) const TCHAR* LibDescription()
{
    return LIBDESCRIPTION.c_str();
}

extern "C" __declspec ( dllexport ) int LibNumberClasses()
{
	//return 2;
	return 3;
}

extern "C" __declspec ( dllexport ) ClassDesc* LibClassDesc ( int i )
{
    switch ( i )
    {

	case 0:
		return COLLADAMax::getCOLLADAExporterDesc();
	case 1:
		return COLLADAMax::getCOLLADAImporterDesc();
	case 2:
		return COLLADAMax::getGoogleWarehouseDesc();

    default:
        return 0;
    }
}


extern "C" __declspec ( dllexport ) ULONG LibVersion()
{
    return VERSION_3DSMAX;
}


// Let the plug-in register itself for deferred loading
extern "C" __declspec ( dllexport ) ULONG CanAutoDefer()
{
    return 0;
}

TCHAR* GetString ( int id )
{
    static TCHAR buf[ 1024 ];
    return ( hInstance  && LoadString ( hInstance, id, buf, sizeof ( buf ) ) ) ? buf : 0;
}
