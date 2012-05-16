/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America

    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxGoogleWarehouseActionItem.h"
#include "COLLADAMaxColladaImporter.h"

#include "G3DBrowser.h"
#include "G3DFileUnzipper.h"

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>


namespace COLLADAMax
{

	const char GoogleWarehouseActionItem::mMenuText[]="Google Warehouse";
	const char GoogleWarehouseActionItem::mButtonText[]="Google Warehouse";
	const char GoogleWarehouseActionItem::mCatText[]="Google Warehouse";
	const char GoogleWarehouseActionItem::mDescText[]="Google Warehouse";


    //------------------------------
	GoogleWarehouseActionItem::GoogleWarehouseActionItem()
	{
	}
	
    //------------------------------
	GoogleWarehouseActionItem::~GoogleWarehouseActionItem()
	{
	}

	//------------------------------
	BOOL GoogleWarehouseActionItem::IsChecked()
	{
		return false;
	}

	//------------------------------
	void GoogleWarehouseActionItem::GetMenuText( TSTR& menuText )
	{
		menuText.printf("%s",mMenuText);
	}

	//------------------------------
	void GoogleWarehouseActionItem::GetButtonText( TSTR& buttonText )
	{
		buttonText.printf("%s",mButtonText);
	}

	//------------------------------
	void GoogleWarehouseActionItem::GetCategoryText( TSTR& catText )
	{
		catText.printf("%s",mCatText);
	}

	//------------------------------
	void GoogleWarehouseActionItem::GetDescriptionText( TSTR& descText )
	{
		descText.printf("%s",mDescText);
	}

	//------------------------------
	BOOL GoogleWarehouseActionItem::ExecuteAction()
	{
		G3D::Browser browser;

		char tmpDirPath[MAX_PATH];

		if( GetTempPath( sizeof(tmpDirPath), tmpDirPath) == 0 )
		{
			// Could not get temp dir
			return true;
		}

		COLLADABU::NativeString tmpDirPathNativeString(tmpDirPath);

		WideString tmpDirPathString(tmpDirPathNativeString.toWideString());

		boost::filesystem::wpath tmpDirPathWpath(tmpDirPathString);
		if ( !boost::filesystem::exists(tmpDirPathWpath) && !boost::filesystem::create_directory(tmpDirPathWpath) )
		{
			// TODO handle error could not create temp dir
			return true;
		}

		WideString warehouseFilePath = browser.openBrowser(hInstance, tmpDirPathString, GetCOREInterface()->GetMAXHWnd());

		if ( warehouseFilePath.empty() )
		{
			// no file was downloaded
			return true;
		}

		NativeString nativeWarehouseFilePath(warehouseFilePath);
		NativeString nativetmpDirPath(tmpDirPath);
		G3D::FileUnzipper fileUnzipper( nativeWarehouseFilePath, nativetmpDirPath);

		if ( !fileUnzipper.getSucceeded() )
		{
			return true;
		}

		const String& modelPath = fileUnzipper.getDAEFilePath();

		ClassDesc2* importerClassDescription = getCOLLADAImporterDesc();
		Class_ID importerClassClassId = importerClassDescription->ClassID();

		GetCOREInterface()->ImportFromFile(  modelPath.c_str(), true, &importerClassClassId );

		return true;
	}

	//------------------------------
	BOOL GoogleWarehouseActionItem::IsEnabled()
	{
		return true;
	}

	//------------------------------
	int GoogleWarehouseActionItem::GetId()
	{
		return 0;
	}

	//------------------------------
	BOOL GoogleWarehouseActionItem::IsItemVisible()
	{
		return true;
	}

	//------------------------------
	MaxIcon* GoogleWarehouseActionItem::GetIcon()
	{
		return 0;
	}
} // namespace COLLADAMax
