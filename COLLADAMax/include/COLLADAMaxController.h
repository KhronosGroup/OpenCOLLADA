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


#ifndef __COLLADAMAX_CONTROLLER_H__
#define __COLLADAMAX_CONTROLLER_H__

#include "COLLADAMaxPrerequisites.h"

#include "max.h"
#include "cs/phyexp.h"

#define PHYSIQUE_CLASSID Class_ID(PHYSIQUE_CLASS_ID_A, PHYSIQUE_CLASS_ID_B)


#include <vector>
#include <memory>

class Modifier;
class ISkin;
class MorphR3;

namespace COLLADAMax
{

	class ExportNode;

	/** Base class to export extra tags in max.*/

    class Controller 
    {

    public:
		enum ControllerType
		{
			SKIN,
			MORPH
		};

    private:
		//ExportNode * exportNode;
		IDerivedObject * mDerivedObject;
		int mModifierIndex;
		bool mEnabled;
		ControllerType mControllerType;

    public:
        /** Destructor*/
        virtual ~Controller()
        {}

		/** Returns the pose before the application of the controller.*/
		Object* getPoseBefore()const;

		/** Returns the pose after the application of the controller.*/
		Object* getPoseAfter()const;


		/** Returns the controller type*/
		ControllerType getControllerType()const{return mControllerType;}

		/** Returns the modifier.*/
		Modifier* getModifier()const {return mDerivedObject->GetModifier(mModifierIndex);}

		/** Returns the type of the controller*/
		ControllerType getType()const { return mControllerType; }

		/** Returns the modifier index of the controller.*/
		int getModifierIndex()const { return mModifierIndex; }

		/** Returns the derived object.*/
		IDerivedObject* getDerivedObject()const{ return mDerivedObject; }

    protected:
		/** Sets the controller type*/
		void setControllerType(ControllerType controllerType){mControllerType=controllerType;}

		/** Constructor.*/
		Controller ( IDerivedObject * derivedObject, int modifierIndex, bool enabled, ControllerType controllerType );


    };


	typedef std::vector<Controller*> Controllers;

	class ISkinInterface;

	class SkinController : public Controller
	{
	public:
		SkinController(IDerivedObject * object, int modifierIndex, bool enabled) 
			: Controller(object, modifierIndex, enabled, SKIN){}

		/** Returns true, if the modifier is as skin controller.*/
		static bool isSkinController(Modifier * modifier);

		/** Returns true, if @a obj is a derived object and the first modifier is as skin controller.*/
		static bool isSkinned(Object* object);

		/** Returns the skin controller.*/
		ISkinInterface* getSkinInterface( INode *node );

	};



	class MorphController : public Controller
	{
	public:
		MorphController(IDerivedObject * object, int modifierIndex, bool enabled) : Controller(object, modifierIndex, enabled, MORPH){}

		/** Returns true, if the modifier is as morph controller.*/
		static bool isMorphController(Modifier * modifier);

		/** Returns the skin controller.*/
		MorphR3* getMorph()const;

	};

}


#endif //__COLLADAMAX_CONTROLLER_H__

