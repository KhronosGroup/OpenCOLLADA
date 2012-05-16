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

#ifndef __COLLADAMAX_GOOGLEWAREHOUSEACTIONITEM_H__
#define __COLLADAMAX_GOOGLEWAREHOUSEACTIONITEM_H__

#include "COLLADAMaxPrerequisites.h"


namespace COLLADAMax
{


    /** TODO Documentation */
	class GoogleWarehouseActionItem : public ActionItem
	{
	public:
		static const char mMenuText[];
		static const char mButtonText[];
		static const char mCatText[];
		static const char mDescText[];
	
	public:
		//ActionItem methods
		BOOL IsChecked();

		void GetMenuText(TSTR& menuText);
		void GetButtonText(TSTR& buttonText);
		void GetCategoryText(TSTR& catText);
		void GetDescriptionText(TSTR& descText);
		
		BOOL ExecuteAction();
		BOOL IsEnabled();

		int GetId();
		BOOL IsItemVisible();
		MaxIcon* GetIcon();
		void DeleteThis() {}

        /** Constructor. */
		GoogleWarehouseActionItem();

        /** Destructor. */
		virtual ~GoogleWarehouseActionItem();

	private:

        /** Disable default copy ctor. */
		GoogleWarehouseActionItem( const GoogleWarehouseActionItem& pre );

        /** Disable default assignment operator. */
		const GoogleWarehouseActionItem& operator= ( const GoogleWarehouseActionItem& pre );

	};

} // namespace COLLADAMAX

#endif // __COLLADAMAX_GOOGLEWAREHOUSEACTIONITEM_H__
