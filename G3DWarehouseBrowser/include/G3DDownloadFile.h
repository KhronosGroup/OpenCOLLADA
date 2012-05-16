/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_DOWNLOAD_FILE_H__
#define __G3D_DOWNLOAD_FILE_H__

#include "G3DPrerequisites.h"
#include <urlmon.h>
#pragma comment(lib,"urlmon") //	link against urlmon.lib

#include "G3DDownloadStatusCallback.h"

class DownloadFile 
{
public:
	void getFile( const wchar_t* url, const wchar_t* fileName, HWND hwndProgress )
	{
				//	initialize COM
				if ( FAILED( CoInitialize(NULL) ) ) {
					return;
				}

				DownloadStatusCallback callback(hwndProgress);
				HRESULT hResult = URLDownloadToFile(
					NULL, url, fileName, 0, &callback );

				CoUninitialize();
				if ( FAILED(hResult) ) {
					return;
				}
	}
};
#endif // __G3D_DOWNLOAD_FILE_H__
