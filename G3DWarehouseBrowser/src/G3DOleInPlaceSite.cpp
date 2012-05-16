/*
    Copyright (c) 2009 NetAllied Systems GmbH

	  This file is part of G3DWarehouseBrowser.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "G3DStableHeaders.h"
#include "G3DOleInPlaceSite.h"

namespace G3D
{
	//---------------------------------------------------------------------
	OleInPlaceSite::OleInPlaceSite(IOleObject* browserObject, OleInPlaceFrame* inPlaceFrame, HWND h) 
		: mClientSite(0)
		, mInPlaceFrame(inPlaceFrame)
		, mBrowserObject(browserObject)
		, mHwnd(h) 
	{
	}
	//---------------------------------------------------------------------
	HRESULT  OleInPlaceSite::QueryInterface( REFIID riid, LPVOID FAR* ppvObj) {
	  return mClientSite->QueryInterface(riid, ppvObj);
	}
	//---------------------------------------------------------------------
	void OleInPlaceSite::setBrowserObject(IOleObject* o) {
	  mBrowserObject = o;
	}
}
