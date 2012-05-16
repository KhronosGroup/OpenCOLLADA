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

#include "COLLADAMaxController.h"
#include "COLLADAMaxISkinInterface.h"
#include "COLLADAMaxSkinInterface.h"
#include "COLLADAMaxPhysiqueSkinInterface.h"

#include <max.h>
#include <iskin.h> 
#include "MorphR3.h"

namespace COLLADAMax
{


    //---------------------------------------------------------------
    Controller::Controller(IDerivedObject * derivedObject, int modifierIndex, bool enabled, ControllerType controllerType)
		: mDerivedObject(derivedObject),
		mModifierIndex(modifierIndex),
		mEnabled(enabled),
		mControllerType(controllerType)
    {}


	//---------------------------------------------------------------
	Object* Controller::getPoseBefore() const
	{
		Object* initialPose = 0;
		// Remember that 3dsMax has the modifier stack reversed
		// So that evaluating the zero'th modifier implies evaluating the whole modifier stack.
		int modifierCount = mDerivedObject->NumModifiers();
		if (mModifierIndex < modifierCount - 1)
		{
			ObjectState state = mDerivedObject->Eval(TIME_INITIAL_POSE, mModifierIndex + 1);
			initialPose = state.obj;
		}
		else
		{
			initialPose = mDerivedObject->GetObjRef();
		}
		return initialPose;

	}


	//---------------------------------------------------------------
	Object* Controller::getPoseAfter() const
	{
		Object* initialPose = 0;
		// Remember that 3dsMax has the modifier stack reversed
		// So that evaluating the zero'th modifier implies evaluating the whole modifier stack.
		int modifierCount = mDerivedObject->NumModifiers();
		if ( mModifierIndex < modifierCount )
		{
			ObjectState state = mDerivedObject->Eval(TIME_INITIAL_POSE, mModifierIndex);
			initialPose = state.obj;
		}
		else
		{
			initialPose = mDerivedObject->GetObjRef();
		}
		return initialPose;

	}


	//---------------------------------------------------------------
	bool SkinController::isSkinController( Modifier * modifier )
	{
		Class_ID classId = modifier->ClassID();
		if (classId == SKIN_CLASSID)
		{
			ISkin* skin = (ISkin*) modifier->GetInterface(I_SKIN);
			if ( !skin) 
				return false;
			return skin->GetNumBonesFlat() > 0;
		}
		else 
			return (classId == PHYSIQUE_CLASSID) != false;

		return false;
	}

	//---------------------------------------------------------------
/*	ISkin* SkinController::getSkin() const
	{
		Modifier* modifier = getModifier();
		if ( modifier )
			return (ISkin *)modifier->GetInterface(I_SKIN);
		return 0;
	}
*/
	//---------------------------------------------------------------
	ISkinInterface* SkinController::getSkinInterface( INode *node ) 
	{
		Modifier *m = getModifier();
		if (m->ClassID() == SKIN_CLASSID)
			return new SkinInterface(m, node );
		if (m->ClassID() == PHYSIQUE_CLASSID)
			return new PhysiqueSkinInterface(m, node);
		return 0;
	}

	//---------------------------------------------------------------
	bool SkinController::isSkinned( Object* object )
	{
		if ( !object )
			return false;

		IDerivedObject* derivedObject;
		Object *currentObject = object;

		SClass_ID superClassId = object->SuperClassID();
		if ( superClassId == GEN_DERIVOB_CLASS_ID || superClassId == DERIVOB_CLASS_ID || superClassId == WSM_DERIVOB_CLASS_ID)
		{
			derivedObject = (IDerivedObject*)object;
			if ( derivedObject->NumModifiers() < 1 )
				return false;
			Modifier* modifier = derivedObject->GetModifier(0);
			return  SkinController::isSkinController(modifier);
		}
		return false;

	}
	//---------------------------------------------------------------
	bool MorphController::isMorphController( Modifier * modifier )
	{
		return ( modifier->ClassID() == MORPHER_CLASS_ID ) != 0;
	}

	//---------------------------------------------------------------
	MorphR3* MorphController::getMorph() const
	{
		return (MorphR3*)getModifier();
	}
}
