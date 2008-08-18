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


#ifndef __COLLADAMAX_CONTROLLER_H__
#define __COLLADAMAX_CONTROLLER_H__

#include "COLLADAMaxPrerequisites.h"

#include <vector>
#include <memory>

class Modifier;
class ISkin;

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

		Object* getInitialPose()const;

		/** Returns the controller type*/
		ControllerType getControllerType()const{return mControllerType;}

		/** Returns the modifier.*/
		Modifier* getModifier()const {return mDerivedObject->GetModifier(mModifierIndex);}

    protected:
		/** Sets the controller type*/
		void setControllerType(ControllerType controllerType){mControllerType=controllerType;}

		/** Constructor.*/
		Controller ( IDerivedObject * derivedObject, int modifierIndex, bool enabled, ControllerType controllerType );


    };


	typedef std::vector<Controller*> Controllers;

	//typedef std::auto_ptr<ControllerList> ControllerListPtr;


	class SkinController : public Controller
	{
	public:
		SkinController(IDerivedObject * object, int modifierIndex, bool enabled) : Controller(object, modifierIndex, enabled, SKIN){}

		/** Returns true, if the modifier is as skin controller.*/
		static bool isSkinController(Modifier * modifier);

		/** Returns the skin controller.*/
		ISkin* getSkin()const;

	};

}


#endif //__COLLADAMAX_CONTROLLER_H__

