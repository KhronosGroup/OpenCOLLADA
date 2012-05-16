/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_DOC_HOST_UI_HANDLER_H__
#define __G3D_DOC_HOST_UI_HANDLER_H__

#include "G3DPrerequisites.h"
#include <mshtml.h>
#include <mshtmhst.h>
#include <oaidl.h>
#include <string>

namespace G3D
{
	static const wchar_t* URL_START_STRING = L"skp:getSkp@";
	static const wchar_t* URL_START_STRING2 = L"skp:getKmz@";

	class DocHostUiHandler : public IDocHostUIHandler {

	private:
		IOleClientSite*  mClientSite;
		HWND mHwndProgress;
		WideString& mFilePath;

	public:
		DocHostUiHandler(HWND hwndProgress, WideString& filePath)
			: mHwndProgress(hwndProgress)
			, mFilePath(filePath)
			, mClientSite(0) {};
		virtual ~DocHostUiHandler() { mClientSite->Release(); }
		void setClientSite(IOleClientSite*);
		HRESULT cancelNavigation(OLECHAR __RPC_FAR* __RPC_FAR* ppchURLOut);

	public:	// IDocHostUIHandler interface
	  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID FAR* ppvObj) {
		if (mClientSite) {
		  return mClientSite->QueryInterface(riid, ppvObj);
		}  
		return E_NOINTERFACE;
	  }
	  
	  ULONG STDMETHODCALLTYPE AddRef() { return 1; }
	  
	  ULONG STDMETHODCALLTYPE Release() { return 1; }

	  HRESULT STDMETHODCALLTYPE ShowContextMenu(
		  DWORD                dwID, 
		  POINT     __RPC_FAR *ppt, 
		  IUnknown  __RPC_FAR *pcmdtReserved, 
		  IDispatch __RPC_FAR *pdispReserved){ return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE ShowUI(
		  DWORD                              dwID, 
		  IOleInPlaceActiveObject __RPC_FAR *pActiveObject, 
		  IOleCommandTarget       __RPC_FAR *pCommandTarget, 
		  IOleInPlaceFrame        __RPC_FAR *pFrame, 
		  IOleInPlaceUIWindow     __RPC_FAR *pDoc) { return S_OK; }

	  HRESULT STDMETHODCALLTYPE GetHostInfo(DOCHOSTUIINFO __RPC_FAR *pInfo);
	  
	  HRESULT STDMETHODCALLTYPE HideUI() { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE UpdateUI() { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE EnableModeless(BOOL fEnable) { return S_FALSE; }
	  
	  HRESULT STDMETHODCALLTYPE OnDocWindowActivate(BOOL fActivate) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE OnFrameWindowActivate(BOOL fActivate) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE ResizeBorder(LPCRECT prcBorder, IOleInPlaceUIWindow __RPC_FAR *pUIWindow, BOOL fRameWindow) { return S_OK; }
	  
	  HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG lpMsg, const GUID __RPC_FAR *pguidCmdGroup, DWORD nCmdID) 
	  {  
		pguidCmdGroup = 0; 
		return S_FALSE; 
	  }

	  HRESULT STDMETHODCALLTYPE GetOptionKeyPath(LPOLESTR __RPC_FAR *pchKey, DWORD dw) { return S_FALSE; }
	  
	  HRESULT STDMETHODCALLTYPE GetDropTarget(IDropTarget __RPC_FAR *pDropTarget, IDropTarget __RPC_FAR *__RPC_FAR *ppDropTarget) 
	  { return S_FALSE; }
	  
	  HRESULT STDMETHODCALLTYPE GetExternal(IDispatch __RPC_FAR *__RPC_FAR *ppDispatch){
		  *ppDispatch = 0;
		  return S_FALSE;
	  }
	  
	  HRESULT STDMETHODCALLTYPE TranslateUrl(DWORD dwTranslate, OLECHAR __RPC_FAR *pchURLIn, OLECHAR __RPC_FAR *__RPC_FAR *ppchURLOut); 
	  
	  HRESULT STDMETHODCALLTYPE FilterDataObject(IDataObject __RPC_FAR *pDO, IDataObject __RPC_FAR *__RPC_FAR *ppDORet) {

		  NOTIMPLEMENTED;
		  //*ppDORet = 0;
  		//return S_FALSE;
	  }
	};
}
#endif // __G3D_DOC_HOST_UI_HANDLER_H__