/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "G3DStableHeaders.h"
#include "G3DDownloadStatusCallback.h"
#include <commctrl.h>


//---------------------------------------------------------------------
HRESULT STDMETHODCALLTYPE DownloadStatusCallback::OnProgress( ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText)
{
	if(ulStatusCode == BINDSTATUS_BEGINDOWNLOADDATA)
	{
		ShowWindow(hwndProgress, 1);
		stepFactor = 1000. / ulProgressMax;
		SendMessage(hwndProgress, PBM_SETRANGE, 0, MAKELPARAM (0, 1000));
	}
	else if(ulStatusCode == BINDSTATUS_DOWNLOADINGDATA)
	{
		SendMessage(hwndProgress, PBM_SETPOS, (WPARAM)(ulProgress * stepFactor), 0);
	}
	else if(ulStatusCode == BINDSTATUS_ENDDOWNLOADDATA)
	{
		ShowWindow(hwndProgress, 0);
		SendMessage(hwndProgress, PBM_SETRANGE, 0, MAKELPARAM (0, 0));
		SendMessage(hwndProgress, PBM_SETPOS, 0, 0);
	}
	
	return S_OK;

}


