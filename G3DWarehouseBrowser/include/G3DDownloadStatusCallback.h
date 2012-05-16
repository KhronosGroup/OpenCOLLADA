/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __G3D_DOWNLOAD_STATUS_CALLBACK_H__
#define __G3D_DOWNLOAD_STATUS_CALLBACK_H__

class DownloadStatusCallback : public IBindStatusCallback  
{
private: 
	HWND hwndProgress;
	double stepFactor;

public:
	DownloadStatusCallback(HWND hwndProgress):hwndProgress(hwndProgress){};
	virtual ~DownloadStatusCallback(){};

	// IBindStatusCallback methods.  Note that the only method called by IE
	// is OnProgress()
	STDMETHOD(OnStartBinding)(DWORD dwReserved, IBinding __RPC_FAR *pib) { return E_NOTIMPL; }

	STDMETHOD(GetPriority)( LONG __RPC_FAR *pnPriority ) { return E_NOTIMPL; }

	STDMETHOD(OnLowResource)( DWORD reserved ) { return E_NOTIMPL; }

	STDMETHOD(OnProgress)( ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR wszStatusText);

	STDMETHOD(OnStopBinding)( HRESULT hresult, LPCWSTR szError) { return E_NOTIMPL; }

	STDMETHOD(GetBindInfo)( DWORD __RPC_FAR *grfBINDF, BINDINFO __RPC_FAR *pbindinfo) { return E_NOTIMPL; }

	STDMETHOD(OnDataAvailable)( DWORD grfBSCF, DWORD dwSize, FORMATETC __RPC_FAR *pformatetc, STGMEDIUM __RPC_FAR *pstgmed)
	{ return E_NOTIMPL; }

	STDMETHOD(OnObjectAvailable)( REFIID riid, IUnknown __RPC_FAR *punk) { return E_NOTIMPL; }

	

	STDMETHOD_(ULONG,AddRef)() { return 0; }
	STDMETHOD_(ULONG,Release)() { return 0; }
	STDMETHOD(QueryInterface)( REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject) { return E_NOTIMPL; }
};


#endif // __G3D_DOWNLOAD_STATUS_CALLBACK_H__
