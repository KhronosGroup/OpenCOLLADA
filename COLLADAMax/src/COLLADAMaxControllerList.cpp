/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADA Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "ColladaMaxStableHeaders.h"

#include "COLLADAMaxControllerList.h"
#include "COLLADAMaxExportNode.h"

#include <max.h>


namespace COLLADAMax
{


    //---------------------------------------------------------------
    ControllerList::ControllerList(const ExportNode& exportNode)
    {
		Object* object = exportNode.getINode()->GetObjectRef();
		resolveControllers(exportNode, object);
	}

	//---------------------------------------------------------------
	void ControllerList::resolveControllers( const ExportNode& exportNode, Object * object )
	{
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
				for (int modifierIndex = 0; modifierIndex < derivedObject->NumModifiers(); ++modifierIndex/*, modIdx++*/)
				{
					Modifier* modifier = derivedObject->GetModifier(modifierIndex);
					if ( SkinController::isSkinController(modifier) )
					{
						SkinController * skinController = new SkinController(derivedObject, modifierIndex, modifier->IsEnabled() != false);
						mControllers.push_back(skinController);
					//	object = derivedObject;
					//	modifierIndex = modifierIndex;
					//	modifierStackIndex = modIdx;
					//	resolved = true;
					//	return;
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
			return mControllers.back()->getInitialPose();
		else
			return 0;
	}

}
