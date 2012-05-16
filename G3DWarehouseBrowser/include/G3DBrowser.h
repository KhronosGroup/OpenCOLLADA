/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_BROWSER_H__
#define __G3D_BROWSER_H__

#include "G3DPrerequisites.h"
#include <windows.h>
#include <string>

#include "G3DOleInPlaceFrame.h"
#include "G3DOleInPlaceSite.h"
#include "G3DDocHostUiHandler.h"
#include "G3DOleClientSite.h"

#include <ExDisp.h>


namespace G3D
{

	class Browser 
	{
	private:
		static Browser* msSingleton;
		WideString mFilePath;

	private:		
		HWND mMainWindow;
		HWND hwndProgress;
		IOleObject* mBrowserObject;
		IWebBrowser2* mWebBrowser;
		OleInPlaceFrame* inPlaceFrame;
		OleInPlaceSite*  inPlaceSite;
		DocHostUiHandler* docHostUiHandler;
		OleClientSite* clientSite;

	public: 
		static Browser& getSingleton();
		static Browser* getSingletonPtr();

	private:
		static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK browserWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:
		Browser();
		virtual ~Browser();

		WideString openBrowser(HINSTANCE hInstance, const WideString& filePath, HWND parentWindow);
		void closeBrowser(){DestroyWindow(mMainWindow);}

	private:
		void setBrowserObject(IOleObject* browserObj);
		void setWebBrowser(IWebBrowser2* webBrowser);
	};
}
#endif // __G3DBROWSER_H__
