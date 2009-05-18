/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_CONTROLLER_H__
#define __COLLADAFW_CONTROLLER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** Base class for all controllers (mesh modifiers). */
	class Controller : public ObjectTemplate<COLLADA_TYPE::CONTROLLER>
	{
	public:
		/** Controller types. */
		enum ControllerType
		{
			CONTROLLER_TYPE_SKIN,
			CONTROLLER_TYPE_MORPH
		};

	private:
		/** Type of the controller.*/
		ControllerType mControllerType;
	
	public:
        /** Destructor. */
		virtual ~Controller(){}

	public:
		/** Type of the controller.*/
		ControllerType getControllerType() const { return mControllerType; }

	protected:
		/** Constructor. */
		Controller( ObjectId objectId, ControllerType controllerType)
			: ObjectTemplate<COLLADA_TYPE::CONTROLLER>(objectId)
			, mControllerType(controllerType)
		{}

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_CONTROLLER_H__
