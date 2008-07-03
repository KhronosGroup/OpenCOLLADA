/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxPrerequisites.h"

#include "ColladaMaxStableHeaders.h"
#include "COLLADAMaxColladaExporter.h"

HINSTANCE hInstance;
int controlsInit = FALSE;

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
    return "libdescription";
}

extern "C" __declspec ( dllexport ) int LibNumberClasses()
{
    return 1;
}

extern "C" __declspec ( dllexport ) ClassDesc* LibClassDesc ( int i )
{
    switch ( i )
    {

    case 0:
        return COLLADAMax::getCOLLADAExporterDesc();

    default:
        return NULL;
    }
}


extern "C" __declspec ( dllexport ) ULONG LibVersion()
{
    return VERSION_3DSMAX;
}


// Let the plug-in register itself for deferred loading
extern "C" __declspec ( dllexport ) ULONG CanAutoDefer()
{
    return 1;
}

TCHAR* GetString ( int id )
{
    static TCHAR buf[ 1024 ];
    return ( hInstance != NULL && LoadString ( hInstance, id, buf, sizeof ( buf ) ) ) ? buf : NULL;
}
