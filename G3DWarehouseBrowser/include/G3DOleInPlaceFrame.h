/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_OLE_IN_PLACE_FRAME_H__
#define __G3D_OLE_IN_PLACE_FRAME_H__

#include "G3DPrerequisites.h"
#define NOTIMPLEMENTED assert(0); return(E_NOTIMPL)

namespace G3D
{
	class OleInPlaceFrame : public IOleInPlaceFrame
	{
	private:
		HWND mHwnd;

	public:
		OleInPlaceFrame(HWND hwnd):mHwnd(hwnd){}
		virtual ~OleInPlaceFrame(){mHwnd = 0;}

	public:  // IOleInPlaceFrame interface
	  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID FAR* ppvObj) {
  		NOTIMPLEMENTED;
	  }

	  ULONG STDMETHODCALLTYPE AddRef() { return 1; }
	  
	  ULONG STDMETHODCALLTYPE Release() { return 1; }
	  
	  HRESULT STDMETHODCALLTYPE GetWindow( HWND FAR* lphwnd) {
		*lphwnd = mHwnd;
  		return S_OK;
	  }
	 
	  HRESULT STDMETHODCALLTYPE ContextSensitiveHelp( BOOL fEnterMode) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE GetBorder( LPRECT lprectBorder) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE RequestBorderSpace( LPCBORDERWIDTHS pborderwidths) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE SetBorderSpace( LPCBORDERWIDTHS pborderwidths) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE SetActiveObject( IOleInPlaceActiveObject *pActiveObject, LPCOLESTR pszObjName) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE InsertMenus( HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE SetMenu( HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE RemoveMenus( HMENU hmenuShared) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE SetStatusText( LPCOLESTR pszStatusText) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE EnableModeless( BOOL fEnable) { return S_FALSE; }
	  
	  HRESULT STDMETHODCALLTYPE TranslateAccelerator( LPMSG lpmsg, WORD wID) {
		  NOTIMPLEMENTED;
	  }
	};
}
#endif // __G3D_OLE_IN_PLACE_FRAME_H__