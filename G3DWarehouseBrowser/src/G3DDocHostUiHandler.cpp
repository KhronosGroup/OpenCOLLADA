/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "G3DStableHeaders.h"
#include "G3DDocHostUiHandler.h"
#include "G3DDownloadFile.h"
#include "G3DBrowser.h"

#include <map>
#include <string>


namespace G3D
{
	//---------------------------------------------------------------------
	void DocHostUiHandler::setClientSite(IOleClientSite* o) {
	  mClientSite = o;
	}
	//---------------------------------------------------------------------
	HRESULT STDMETHODCALLTYPE DocHostUiHandler::TranslateUrl (
		 DWORD                         dwTranslate, 
		 OLECHAR __RPC_FAR*            pchURLIn, 
		 OLECHAR __RPC_FAR* __RPC_FAR* ppchURLOut) {
		
		OLECHAR* src = pchURLIn;

		//	determine length of URL
		while ( (*(src)++) );
		--src;
		size_t len = src - pchURLIn;
		size_t urlStartStringLen = wcslen(URL_START_STRING);
		size_t urlStartStringLen2 = wcslen(URL_START_STRING2);

		if ( ( ( len >=  urlStartStringLen ) &&  
			   !_wcsnicmp(pchURLIn, URL_START_STRING , urlStartStringLen) 
			 ) || 
			 ( ( len >=  urlStartStringLen2 ) && 
			   !_wcsnicmp(pchURLIn, URL_START_STRING2 , urlStartStringLen2)
			 )
			 )
		{
			//	modify URL
			WideString inString ( pchURLIn );
			size_t fromPos = inString.find( L"rtyp=" );
			size_t lenPos = inString.find( L"&fn=" );
			inString.replace(fromPos,lenPos-fromPos, L"rtyp=zs" );
			inString = inString.substr(inString.find( L"http://" ));
		
			//	get filename
			fromPos = inString.find( L"&fn=" ) + 4;
			lenPos = inString.find( L"&ctyp=" );
			WideString fileName = inString.substr(fromPos, lenPos-fromPos);
			for ( UINT i = 0; i < fileName.length(); i++)
			{
				if (fileName[i] =='+')
				{
					fileName.replace(i,1,L"_");
					i++;
				}
			}
			fileName.append(L".zip");

			mFilePath.append(fileName.c_str());
			
			DownloadFile test;
			test.getFile(inString.c_str(), mFilePath.c_str(), mHwndProgress);
			
			
			// close Browser
			Browser::getSingletonPtr()->closeBrowser();

			return cancelNavigation(ppchURLOut);
		}
		else if (len >=  4 && !_wcsnicmp(pchURLIn, L"skp:" , 4))
		{
			MessageBox(0,L"This operation is not supported!", L"Error", MB_OK );
			return cancelNavigation(ppchURLOut);
		}

		//	do nothing
		*ppchURLOut = 0;
		return S_FALSE;		
 	}
	//---------------------------------------------------------------------
	HRESULT DocHostUiHandler::cancelNavigation(OLECHAR __RPC_FAR* __RPC_FAR* ppchURLOut)
	{
		OLECHAR* dest;
		if ((dest = (OLECHAR *)CoTaskMemAlloc(2 << 1)))
		{
			*ppchURLOut = dest;
			CopyMemory(dest, L" ", 2 << 1);
			return S_OK;
		}
		*ppchURLOut = 0;
		return S_FALSE;
	}


	//---------------------------------------------------------------------
	/* Be sure to use CoTaskMemAlloc to allocate strings for pchHostCss or pchHostNS.  */
	HRESULT DocHostUiHandler::GetHostInfo(DOCHOSTUIINFO __RPC_FAR *pInfo) {
	  pInfo->cbSize = sizeof(DOCHOSTUIINFO);

	  pInfo->dwFlags = 
	   // DOCHOSTUIFLAG_DIALOG                     |
	   // DOCHOSTUIFLAG_DISABLE_HELP_MENU          |
		  DOCHOSTUIFLAG_NO3DBORDER                 |  /* No 3D Border   */
	   // DOCHOSTUIFLAG_SCROLL_NO                  |  /* Hide Scrollbar */
	   // DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE    |
	   // DOCHOSTUIFLAG_OPENNEWWIN                 |
	   // DOCHOSTUIFLAG_DISABLE_OFFSCREEN          |
	   // DOCHOSTUIFLAG_FLAT_SCROLLBAR             |
	   // DOCHOSTUIFLAG_DIV_BLOCKDEFAULT           |
	   // DOCHOSTUIFLAG_ACTIVATE_CLIENTHIT_ONLY    |
	   // DOCHOSTUIFLAG_OVERRIDEBEHAVIORFACTORY    |
	   // DOCHOSTUIFLAG_CODEPAGELINKEDFONTS        |
	   // DOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8  |
	   // DOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8   |
	   // DOCHOSTUIFLAG_ENABLE_FORMS_AUTOCOMPLETE  |
	   // DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION  | 
	   // DOCHOSTUIFLAG_IME_ENABLE_RECONVERSION    |
	   // DOCHOSTUIFLAG_THEME                      |
	   // DOCHOSTUIFLAG_NOTHEME                    |
	   // DOCHOSTUIFLAG_NOPICS                     |
		  DOCHOSTUIFLAG_NO3DOUTERBORDER            |
		  0                                        ;

	  // What happens if user double clicks?
	  pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

	  return S_OK ;
	}
}