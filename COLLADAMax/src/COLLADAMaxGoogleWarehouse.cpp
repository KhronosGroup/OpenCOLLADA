/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMax.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAMaxStableHeaders.h"
#include "COLLADAMaxGoogleWarehouse.h"
#include "COLLADAMaxGoogleWarehouseActionItem.h"

#include <imenuman.h>

namespace COLLADAMax
{

	const Class_ID GoogleWarehouse::GOOGLEWAREHOUSE_CLASS_ID(0x23c83f50, 0x6bc428f4);


	//------------------------------
	ClassDesc2* getGoogleWarehouseDesc()
	{
		static GoogleWarehouseDesc description;
		return &description;
	}

	//------------------------------
	GoogleWarehouse::GoogleWarehouse()
		: mMenuManager(GetCOREInterface()->GetMenuManager())
		, mActionManager(GetCOREInterface()->GetActionManager())
		, mFileMenu(mMenuManager ? mMenuManager->GetMainMenuBar()->GetItem(0)->GetSubMenu() : 0)
		, mWarehouseItem(0)
	{

	}

	const ActionTableId googleWarehouseTableActions = 0x7ff73cb5;
	const ActionContextId googleWarehouseTableContext = 0x7ff73cb5;

	class MyCallback : public ActionCallback
	{
		BOOL ExecuteAction(int id) 
		{ 
			return FALSE; 
		}
	};

	//------------------------------
	DWORD GoogleWarehouse::Start()
	{

		if ( !mWarehouseItem )
		{
			mWarehouseItem= GetIMenuItem(); 
		}

		if ( !mWarehouseItem || !mFileMenu)
		{
			return GUPRESULT_ABORT;
		}

		for ( int i = 0, count = mFileMenu->NumItems(); i < mFileMenu->NumItems(); ++i)
		{
			IMenuItem* item = mFileMenu->GetItem(i);
			IMenu* menu = item->GetSubMenu();
			if ( menu )
			{
				const TSTR& name = menu->GetTitle();
			}
			const TSTR& name = item->GetTitle();
			if ( name == (TSTR)GoogleWarehouseActionItem::mMenuText)
			{
				mFileMenu->RemoveItem(i);
			}
		}

		ActionTable* actionTable = GetCOREInterface()->GetActionManager()->FindTable( googleWarehouseTableActions );

		ActionCallback* callback = new MyCallback();
		actionTable->SetCallback(callback);

		ActionItem* actionItem = actionTable->GetAction(0);

		mWarehouseItem->SetTitle(GoogleWarehouseActionItem::mMenuText);

		mWarehouseItem->SetActionItem( actionItem );
		mWarehouseItem->SetVisible( true );
		mWarehouseItem->SetEnabled( true );

		// add warehouse item before import
		mFileMenu->AddItem(mWarehouseItem, 29);

		mMenuManager->RegisterMenu(mFileMenu, 0);

		mMenuManager->UpdateMenuBar();

#if 0
		if ( menuManager->RegisterMenuBarContext(kWeightTableMenuBar, warehouseMenuName) ) 
		{
			//add Edit Menu
			IMenu* warehouseMenu = GetIMenu();
			warehouseMenu->SetTitle(warehouseMenuName);
			menuManager->RegisterMenu(warehouseMenu, 0);


//			IMenuItem* warehouseItem= GetIMenuItem(); 
//			warehouseItem->SetSubMenu(warehouseMenu);

			IMenuBarContext* pContext = (IMenuBarContext*) menuManager->GetContext(kWeightTableMenuBar);
			pContext->SetMenu(warehouseMenu);
			pContext->CreateWindowsMenu();

		}

		IMenu* warehouseMenu = GetIMenu();
		warehouseMenu->SetTitle(warehouseMenuName);
		menuManager->RegisterMenu(warehouseMenu, 0);

		IMenuItem* warehouseItem= GetIMenuItem(); 
		ActionItem* warehouseActionItem = GetActionItem();
		warehouseItem->SetActionItem()
		warehouseItem->SetSubMenu(warehouseMenu);

		fileMenu->AddItem(warehouseItem);

		IMenu* pMenu = menuManager->FindMenu(warehouseMenuName);
		IMenu* pMenu2 = menuManager->FindMenu("pferd");
		IMenu* pMenu3 = menuManager->FindMenu("warehouse");

		for ( int i = 0, count = fileMenu->NumItems(); i < fileMenu->NumItems(); ++i)
		{
			IMenuItem* item = fileMenu->GetItem(i);
			IMenu* menu = item->GetSubMenu();
			if ( menu )
			{
				const TSTR& name = menu->GetTitle();
				if ( name == warehouseMenuName)
				{
					fileMenu->RemoveItem(item);
					--i;
					int g = 6;
				}
			}
		}
#endif

		return GUPRESULT_KEEP;
	}

	//------------------------------
	void GoogleWarehouse::Stop()
	{
	}

	//------------------------------
	ActionTable* GoogleWarehouseDesc::GetActions()
	{
		ActionTable* pTab = new ActionTable(googleWarehouseTableActions, googleWarehouseTableContext, (TSTR)GoogleWarehouseActionItem::mMenuText);        

		GoogleWarehouseActionItem* actionItem =  new GoogleWarehouseActionItem();
		pTab->AppendOperation(actionItem);
		GetCOREInterface()->GetActionManager()->RegisterActionContext(googleWarehouseTableContext, (TSTR)GoogleWarehouseActionItem::mMenuText);
		return pTab;
	}


} // namespace COLLADAMax
