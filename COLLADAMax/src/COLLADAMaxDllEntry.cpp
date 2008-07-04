/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
