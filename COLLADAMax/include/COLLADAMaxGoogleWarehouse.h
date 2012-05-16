/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMax.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAX_GOOGLEWAREHOUSE_H__
#define __COLLADAMAX_GOOGLEWAREHOUSE_H__

#include "COLLADAMaxPrerequisites.h"
#include "COLLADAMaxGoogleWarehouseActionItem.h"

#include <max.h>
#include <guplib.h>


namespace COLLADAMax
{

    /** TODO Documentation */
	class GoogleWarehouse : public GUP
	{
	public:
		static const Class_ID GOOGLEWAREHOUSE_CLASS_ID;

	private:
		IMenuManager* mMenuManager;
		IActionManager* mActionManager;

		IMenu* mFileMenu;

		IMenuItem* mWarehouseItem;

		GoogleWarehouseActionItem mGoogleWarehouseActionItem;


	
	public:

        /** Constructor. */
		GoogleWarehouse();

        /** Destructor. */
		virtual ~GoogleWarehouse(){}

		DWORD Start();

		void Stop();

	private:

        /** Disable default copy ctor. */
		GoogleWarehouse( const GoogleWarehouse& pre );

        /** Disable default assignment operator. */
		const GoogleWarehouse& operator= ( const GoogleWarehouse& pre );

	};


	ClassDesc2* getGoogleWarehouseDesc();


	class GoogleWarehouseDesc : public ClassDesc2
	{
	public:
		int IsPublic()
		{
			return TRUE;
		}

		void * Create ( BOOL isLoading = FALSE )
		{
			isLoading;
			return new GoogleWarehouse();
		}

		const TCHAR * ClassName()
		{
			return "GoogleWarehouse";
		}

		SClass_ID SuperClassID()
		{
			return GUP_CLASS_ID;
		}

		Class_ID ClassID()
		{
			return GoogleWarehouse::GOOGLEWAREHOUSE_CLASS_ID;
		}

		const TCHAR* Category()
		{
			return "Import";
		} 

		const TCHAR* InternalName()
		{
			return "GoogleWarehouse";
		} 

		HINSTANCE HInstance()
		{
			return hInstance;
		} 

		int             NumActionTables() { return 1; }
		ActionTable*  GetActionTable(int i) { return GetActions(); }

		ActionTable* GetActions();


	};


} // namespace COLLADAMAX

#endif // __COLLADAMAX_GOOGLEWAREHOUSE_H__
