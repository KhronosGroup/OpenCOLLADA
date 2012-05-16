/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_OLE_IN_PLACE_SITE_H__
#define __G3D_OLE_IN_PLACE_SITE_H__

#include "G3DPrerequisites.h"
#include "G3DOleClientSite.h"
#include "G3DOleInPlaceFrame.h"

#include <windows.h>

namespace G3D
{
	class OleInPlaceSite : public IOleInPlaceSite {
	private:
		OleClientSite*   mClientSite;
		OleInPlaceFrame* mInPlaceFrame;
		IOleObject*	   mBrowserObject;
		HWND              mHwnd;

	public:
		OleInPlaceSite(IOleObject* browserObject, OleInPlaceFrame* inPlaceFrame, HWND h);
		virtual ~OleInPlaceSite(){
			mClientSite -> Release();
//			mInPlaceFrame -> Release();
			mBrowserObject -> Release();
			mHwnd = 0;
		 }
		void setBrowserObject(IOleObject* o);

		void setClientSite(OleClientSite* o) {mClientSite=o;}

	public:	// IOleInPlaceSite interface
	  HRESULT STDMETHODCALLTYPE QueryInterface( REFIID riid, LPVOID FAR* ppvObj); 

	  ULONG STDMETHODCALLTYPE AddRef() {
  		return(1);
	  }
	  
	  ULONG STDMETHODCALLTYPE Release() {
  		return(1);
	  }
	  
	  HRESULT STDMETHODCALLTYPE GetWindow( HWND FAR* lphwnd) {
		*lphwnd = mHwnd;
  		return(S_OK);
	  }
	  
	  HRESULT STDMETHODCALLTYPE ContextSensitiveHelp(BOOL fEnterMode) {
  		NOTIMPLEMENTED;
	  }
	  
	  HRESULT STDMETHODCALLTYPE CanInPlaceActivate() {
  		return S_OK;
	  }
	  
	  HRESULT STDMETHODCALLTYPE OnInPlaceActivate() {
  		return S_OK;
	  }
	  
	  HRESULT STDMETHODCALLTYPE OnUIActivate() { return(S_OK); }
	  
	  HRESULT STDMETHODCALLTYPE GetWindowContext( LPOLEINPLACEFRAME FAR* lplpFrame, LPOLEINPLACEUIWINDOW FAR* lplpDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo) {
		*lplpFrame = mInPlaceFrame;
  		*lplpDoc = 0;
	  
  		lpFrameInfo->fMDIApp = FALSE;
  		lpFrameInfo->hwndFrame = mHwnd;
  		lpFrameInfo->haccel = 0;
  		lpFrameInfo->cAccelEntries = 0;
	  
  		return S_OK;
	  }
	  
	  HRESULT STDMETHODCALLTYPE Scroll(SIZE scrollExtent) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE OnUIDeactivate( BOOL fUndoable) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE OnInPlaceDeactivate() { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE DiscardUndoState() { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE DeactivateAndUndo() { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE OnPosRectChange( LPCRECT lprcPosRect) {
  		IOleInPlaceObject	*inplace;
  		if (!mBrowserObject->QueryInterface(IID_IOleInPlaceObject, (void**)&inplace)) {
  			inplace->SetObjectRects(lprcPosRect, lprcPosRect);
  		}
  		return(S_OK);
	  }
	};
}
#endif // __G3D_OLE_IN_PLACE_SITE_H__
