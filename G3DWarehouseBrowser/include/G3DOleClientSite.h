/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_OLE_CLIENT_SITE_H__
#define __G3D_OLE_CLIENT_SITE_H__

#include "G3DPrerequisites.h"
#include <windows.h>
#include <mshtml.h>
#include <mshtmhst.h>
#include <oaidl.h>

namespace G3D
{
	class OleInPlaceSite;
	class DocHostUiHandler;

	class OleClientSite : public IOleClientSite {

	private:
		OleInPlaceSite* mInPlace;
		DocHostUiHandler* mDocHostUiHandler;

	public:
		OleClientSite ( OleInPlaceSite* inPlace, DocHostUiHandler* docHostUiHandler);
		virtual ~OleClientSite();

	public:  // IOleClientSite interface
	  HRESULT STDMETHODCALLTYPE QueryInterface( REFIID riid, void ** ppvObject);
	  
	  ULONG STDMETHODCALLTYPE AddRef() { return(1); }
	  
	  ULONG STDMETHODCALLTYPE Release() { return(1); }
	  
	  HRESULT STDMETHODCALLTYPE SaveObject() { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE GetMoniker( DWORD dwAssign, DWORD dwWhichMoniker, IMoniker ** ppmk) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE GetContainer( LPOLECONTAINER FAR* ppContainer) {
  		*ppContainer = 0;
  		return(E_NOINTERFACE);
	  }
	  
	  HRESULT STDMETHODCALLTYPE ShowObject() { return(NOERROR); }
	  
	  HRESULT STDMETHODCALLTYPE OnShowWindow( BOOL fShow) { NOTIMPLEMENTED; }
	  
	  HRESULT STDMETHODCALLTYPE RequestNewObjectLayout() { NOTIMPLEMENTED; }
	};
}
#endif // __G3D_OLE_CLIENT_SITE_H__