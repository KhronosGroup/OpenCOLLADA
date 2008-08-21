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

#include "COLLADAMaxController.h"

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
	Object* Controller::getInitialPose() const
	{
		Object* initialPose = 0;
		// Remember that 3dsMax has the modifier stack reversed
		// So that evaluating the zero'th modifier implies evaluating the whole modifier stack.
		int modifierCount = mDerivedObject->NumModifiers();
		if (mModifierIndex < modifierCount - 1)
		{
			ObjectState state = mDerivedObject->Eval(TIME_INITIAL_POSE, mModifierIndex + 1);
//			ObjectState state = mDerivedObject->Eval(TIME_INITIAL_POSE, mModifierIndex + 1);
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
//		else 
//			return classId == PHYSIQUE_CLASSID;

		return false;
	}

	//---------------------------------------------------------------
	ISkin* SkinController::getSkin() const
	{
		Modifier* modifier = getModifier();
		if ( modifier )
			return (ISkin *)modifier->GetInterface(I_SKIN);
		return 0;
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
