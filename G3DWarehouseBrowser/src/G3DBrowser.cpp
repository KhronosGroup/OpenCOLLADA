/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "G3DStableHeaders.h"
#include "G3DBrowser.h"
#include "G3DOleInPlaceFrame.h"
#include "G3DOleInPlaceSite.h"
#include "G3DOleClientSite.h"
#include "G3DDocHostUiHandler.h"

#include <windows.h>
#include <commctrl.h>
#include <string>

namespace G3D
{
	static const wchar_t* CLASS_NAME = L"Browser Example";
	static const wchar_t* BROWSER_CLASS_NAME = L"Browser Object";
	static const wchar_t* WINDOW_TITLE = L"G3D Warehouse Collada Browser";
	static const wchar_t* HOST_NAME =L"Host Name";
    static const LPTSTR   HOME = L"http://sketchup.google.com/3dwarehouse/?ctyp=sm&cv=p8.0.4811&hl=en_US";
	//static const LPTSTR   HOME = L"http://sketchup.google.com/3dwarehouse/?ctyp=sxample&cv=p8.0.4811&rtyppref=s6&hl=en US";
	//static const LPTSTR   HOME = L"http://sketchup.google.com/3dwarehouse/?ctyp=sxample&cv=su_6&rtyppref=s6&hl=en ";



	//---------------------------------------------------------------------
	Browser* Browser::msSingleton = 0;
	//---------------------------------------------------------------------
	Browser& Browser::getSingleton()
	{
		assert(msSingleton);
		return *msSingleton;
	}
	//---------------------------------------------------------------------
	Browser* Browser::getSingletonPtr()
	{
		return msSingleton;
	}
	//---------------------------------------------------------------------
	Browser::Browser()
		: mMainWindow(0)
		, mWebBrowser(0)
		, mBrowserObject(0)
		, inPlaceFrame(0)
		, inPlaceSite(0)
		, docHostUiHandler(0)
		, clientSite(0)
	{
		assert(msSingleton == 0);
		msSingleton = this;
	}
	//---------------------------------------------------------------------
	Browser::~Browser()
	{
		delete inPlaceFrame;
		delete inPlaceSite;
		delete docHostUiHandler;
		delete clientSite;
		if ( mWebBrowser )
		{
			mWebBrowser->Release();
		}
		if ( mBrowserObject )
		{
			mBrowserObject->Release();
		}
		msSingleton = 0;
	}
	//---------------------------------------------------------------------
	WideString Browser::openBrowser(HINSTANCE hInstance, const WideString& filePath, HWND parentWindow = HWND_DESKTOP ){
		MSG	msg;
		HRESULT result = OleInitialize(NULL);

		mFilePath = filePath;

		if(SUCCEEDED(result))
		{
			WNDCLASSEX		wc;
			// Register the class of our Main window.
			ZeroMemory(&wc, sizeof(WNDCLASSEX));
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.hInstance = hInstance;
			wc.lpfnWndProc = windowProc;
			wc.lpszClassName = CLASS_NAME;
			wc.style = CS_CLASSDC|CS_HREDRAW|CS_VREDRAW|CS_PARENTDC|CS_BYTEALIGNCLIENT|CS_DBLCLKS;
			RegisterClassEx(&wc);

			// Register the class of our window to host the browser.
			wc.lpfnWndProc = browserWindowProc;
			wc.lpszClassName = BROWSER_CLASS_NAME;
			wc.style = CS_HREDRAW|CS_VREDRAW;
			RegisterClassEx(&wc);

			// Create a Main window.
			mMainWindow = CreateWindowEx(0, CLASS_NAME, WINDOW_TITLE,
				WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, parentWindow, NULL, hInstance, 0);
			if (mMainWindow)
			{
				// Create a "Back" button.
				msg.hwnd = CreateWindow(L"Button", L"Back",
					WS_TABSTOP|BS_PUSHBUTTON|BS_TEXT|WS_CHILD|BS_VCENTER|WS_VISIBLE,
					6, 6,				// X, Y position
					70, 26,				// Width, Height
					mMainWindow,
					(HMENU)1001, hInstance, 0);
				
				// Create a "Forward" button.
				msg.hwnd = CreateWindow(L"Button", L"Forward",
					WS_TABSTOP|BS_PUSHBUTTON|BS_TEXT|WS_CHILD|BS_VCENTER|WS_VISIBLE,
					6 + 70 + 10, 6,		// X, Y position
					70, 26,				// Width, Height
					mMainWindow,
					(HMENU)1002, hInstance, 0);

				// Create a "Home" button.
				msg.hwnd = CreateWindow(L"Button", L"Home",
					WS_TABSTOP|BS_PUSHBUTTON|BS_TEXT|WS_CHILD|BS_VCENTER|WS_VISIBLE,
					6 + 2*70 + 2*10 , 6,		// X, Y position
					70, 26,							// Width, Height
					mMainWindow,
					(HMENU)1003, hInstance, 0);
				
				// Create a Progress bar
				InitCommonControls();
				hwndProgress = CreateWindowEx(0, PROGRESS_CLASS,
					L"", WS_CHILD | PBS_SMOOTH//| WS_VISIBLE 
					,6 + 3*70 + 3*10 ,  10,
					300, 18,
					mMainWindow, NULL,
					hInstance, NULL);

				// Create a child window to host the browser object. 
				if ((msg.hwnd = CreateWindowEx(0, BROWSER_CLASS_NAME, 0, WS_CHILD|WS_VISIBLE,
					0, 40, 0, 0,
					mMainWindow, (HMENU)1000, hInstance, 0)))
				{
					// Show the Main window.
					ShowWindow(mMainWindow, 1);
					UpdateWindow(mMainWindow);
					
					VARIANT	myURL;
					VariantInit(&myURL);
					myURL.vt = VT_BSTR;
					myURL.bstrVal = SysAllocString(HOME);
					mWebBrowser->Navigate(myURL.bstrVal,0, 0, 0, 0);
					VariantClear(&myURL);

					// Do a message loop until WM_QUIT.
					while (GetMessage(&msg, 0, 0, 0) == 1)
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
				}
				else
				{
					MessageBox(mMainWindow, L"Can't create browser child window!", L"ERROR", MB_OK);				
				}
				DestroyWindow(mMainWindow);
			}
			DestroyWindow(mMainWindow);
			OleUninitialize();
		}

		if ( mFilePath == filePath )
		{
			return WideString();
		}
		else
		{
			return mFilePath;
		}
	}
	//---------------------------------------------------------------------
	LRESULT CALLBACK  Browser::windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
		Browser* _this = Browser::getSingletonPtr();
		switch (uMsg)
		{
			case WM_CLOSE:
				{
					DestroyWindow(hwnd);
					return(1);
				}

			case WM_DESTROY:
				{
					// Post the WM_QUIT message to quit the message loop in WinMain()
					PostQuitMessage(0);
					return(1);
				}	

			case WM_SIZE:
				{
					// Resize the browser child window, leaving room for our buttons.
					MoveWindow(GetDlgItem(hwnd, 1000), 0, 40, LOWORD(lParam), HIWORD(lParam) - 40, TRUE);
					return(0);
				}
			case WM_ERASEBKGND:
				{
					HBRUSH	hBrush;
					HGDIOBJ	orig;
					RECT	rec;
					// Erase the background behind the buttons. Note: The browser object takes care
					// of completely redrawing its area, so we don't need to erase there.
					hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
					GetClientRect(hwnd, &rec);
					orig = SelectObject((HDC)wParam, hBrush);
					Rectangle((HDC)wParam, 0, 0, rec.right, 40);
					SelectObject((HDC)wParam, orig);
					return(TRUE);
				}
			case WM_COMMAND:
				{
					switch (LOWORD(wParam))
					{
					case 1001:
						{
							_this->mWebBrowser->GoBack();
							break;
						}
					case 1002:
						{
							_this->mWebBrowser->GoForward();
							break;
						}
					case 1003:
						{
							//mWebBrowser->GoHome();
							VARIANT	myURL;
							VariantInit(&myURL);
							myURL.vt = VT_BSTR;
							myURL.bstrVal = SysAllocString(HOME);
							_this->mWebBrowser->Navigate(myURL.bstrVal,0, 0, 0, 0);
							VariantClear(&myURL);
							break;
						}
					}
					break;
				}
		}
		return(DefWindowProc(hwnd, uMsg, wParam, lParam));
	}
	//---------------------------------------------------------------------
	LRESULT CALLBACK  Browser::browserWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
		Browser* _this = Browser::getSingletonPtr();
		switch (uMsg)
		{
			case WM_SIZE:
				{
					_this->mWebBrowser->put_Width(LOWORD(lParam));
					_this->mWebBrowser->put_Height(HIWORD(lParam));
					return(0);
				}
			case WM_CREATE:
				{
					IClassFactory* pClassFactory = 0;
					HRESULT result = CoGetClassObject(CLSID_WebBrowser, 3, NULL, IID_IClassFactory, (void **)&pClassFactory);
					if(SUCCEEDED(result))
					{
						IOleObject* browserObject = 0;
						result = pClassFactory->CreateInstance(0, IID_IOleObject, (void**)&browserObject);
						if(SUCCEEDED(result))
						{	
							_this->setBrowserObject(browserObject);
							_this->inPlaceFrame = new OleInPlaceFrame(_this->mMainWindow);
							_this->inPlaceSite  = new OleInPlaceSite(browserObject, _this->inPlaceFrame, hwnd);
							_this->docHostUiHandler = new DocHostUiHandler(_this->hwndProgress, _this->mFilePath);
							_this->clientSite = new OleClientSite(_this->inPlaceSite, _this->docHostUiHandler);

							RECT rect;
							GetClientRect(hwnd, &rect);

							_this->mBrowserObject->SetClientSite(_this->clientSite);
							_this->mBrowserObject->SetHostNames(HOST_NAME, 0);

							// Let browser object know that it is embedded in an OLE container.
							if (!OleSetContainedObject(_this->mBrowserObject, TRUE))
							{
								// Set the display area of our browser control the same as our window's size and actually put the browser object into our window.
								if(!_this->mBrowserObject->DoVerb(OLEIVERB_SHOW, NULL, _this->clientSite, -1, hwnd, &rect))
								{
									IWebBrowser2* webBrowser = 0;
									result = _this->mBrowserObject->QueryInterface(IID_IWebBrowser2,(void**)&webBrowser);
									if(SUCCEEDED(result))
									{
										_this->setWebBrowser(webBrowser);
									}
								}								 
							}
						}
						
					}
					pClassFactory->Release();
					// Success
					return(0);
				}
		}
		return(DefWindowProc(hwnd, uMsg, wParam, lParam));
	}
	//---------------------------------------------------------------------
	void Browser::setBrowserObject( IOleObject* browserObj )
	{
		mBrowserObject = browserObj;
	}
	//---------------------------------------------------------------------
	void Browser::setWebBrowser( IWebBrowser2* webBrowser )
	{
		mWebBrowser = webBrowser;
	}	
}
