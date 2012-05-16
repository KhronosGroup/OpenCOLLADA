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

#include "COLLADAMaxControllerList.h"
#include "COLLADAMaxExportNode.h"

#include "COLLADAMaxXRefFunctions.h"
	
#include <max.h>


namespace COLLADAMax
{


    //---------------------------------------------------------------
    ControllerList::ControllerList(const ExportNode& exportNode)
    {
		resolveControllers(exportNode);
	}

	//---------------------------------------------------------------
	void ControllerList::resolveControllers( const ExportNode& exportNode )
	{
		Object* object = exportNode.getINode()->GetObjectRef();

		if ( !object )
			return;

		if ( exportNode.getIsXRefObject() )
			object = XRefFunctions::getXRefItemSource(object);

		if ( !object )
			return;

		SClass_ID		superClassId;
		IDerivedObject* derivedObject;
		Object *currentObject = object;

		//int modIdx = 0;
		superClassId = object->SuperClassID();
		if (superClassId == GEN_DERIVOB_CLASS_ID || superClassId == DERIVOB_CLASS_ID || superClassId == WSM_DERIVOB_CLASS_ID)
		{
			derivedObject = (IDerivedObject*)object;
			while (superClassId == GEN_DERIVOB_CLASS_ID || superClassId == DERIVOB_CLASS_ID || superClassId == WSM_DERIVOB_CLASS_ID)
			{
				for (int modifierIndex = 0; modifierIndex < derivedObject->NumModifiers(); ++modifierIndex)
				{
					Modifier* modifier = derivedObject->GetModifier(modifierIndex);
					//no iskin support for xrefs
					// TODO needs further investigation...

					if ( SkinController::isSkinController(modifier) /*&& !exportNode.getIsXRefObject() */) 
					{
						SkinController * skinController = new SkinController(derivedObject, modifierIndex, modifier->IsEnabled() != false);
						mControllers.push_back(skinController);
					}
					else if ( MorphController::isMorphController(modifier) )
					{
						MorphController * morphController = new MorphController(derivedObject, modifierIndex, modifier->IsEnabled() != false);
						mControllers.push_back(morphController);
					}
					else
						return;
				}
				derivedObject = (IDerivedObject*) derivedObject->GetObjRef();
				currentObject = (Object*) derivedObject;
				superClassId = derivedObject->SuperClassID();
			}
		}

/*		int bct = currentObject->NumPipeBranches(FALSE);
		if (bct > 0)
		{
			for (int bi = 0; bi < bct; bi++)
			{
				Object* bobj = currentObject->GetPipeBranch(bi,FALSE);
				Resolve(bobj);
				return;
			}
		}
*/
	}

	//---------------------------------------------------------------
	ControllerList::~ControllerList()
	{
		for ( Controllers::iterator it = mControllers.begin(); it != mControllers.end(); ++it )
			delete (*it);
	}


	//---------------------------------------------------------------
	Object* ControllerList::getInitialPose() const
	{
		if ( !mControllers.empty() )
			return mControllers.back()->getPoseBefore();
		else
			return 0;
	}

}
