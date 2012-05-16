/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "G3DStableHeaders.h"
#include "G3DOleClientSite.h"
#include "G3DOleInPlaceSite.h"
#include "G3DDocHostUiHandler.h"

namespace G3D
{
	//---------------------------------------------------------------------
	OleClientSite::OleClientSite ( OleInPlaceSite* inPlace, DocHostUiHandler*  docHostUiHandler) 
		: mInPlace(inPlace)
		, mDocHostUiHandler(docHostUiHandler)
		{
			mInPlace->setClientSite(this);
			mDocHostUiHandler->setClientSite(this);
		}
	//---------------------------------------------------------------------
	OleClientSite::~OleClientSite()
	{
		//mInPlace -> Release();
		//mDocHostUiHandler -> Release();
	}
	//---------------------------------------------------------------------
	HRESULT OleClientSite::QueryInterface(REFIID riid, void ** ppvObject) {
		if (!memcmp((const void*) &riid, (const void*)&IID_IUnknown,       sizeof(GUID)) || 
			!memcmp((const void*) &riid, (const void*)&IID_IOleClientSite, sizeof(GUID))) {

			*ppvObject = this;
			return S_OK;
		}
		else if (!memcmp((const void*)&riid, &IID_IOleInPlaceSite, sizeof(GUID))) {
			*ppvObject = mInPlace;
			return S_OK;
		}
		else if (!memcmp((const void*)&riid, &IID_IDocHostUIHandler, sizeof(GUID))) {
			*ppvObject = mDocHostUiHandler;
			return S_OK;
		}
		else {
			*ppvObject = 0;
			return E_NOINTERFACE;
		}
	}
}
