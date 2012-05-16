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
	
        /** The unique id of the source that gets modified by this controller. Must be a mesh or a 
        morph controller. The vertex count of the source must be equal to the vertex count of the skin 
        controller.*/
        UniqueId mSource;

    protected:
        /** Constructor. */
        Controller( const UniqueId& uniqueId, ControllerType controllerType )
            : ObjectTemplate<COLLADA_TYPE::CONTROLLER>(uniqueId)
            , mControllerType(controllerType)
        {}

        /** Constructor. */
        Controller( const UniqueId& uniqueId, ControllerType controllerType, UniqueId source )
            : ObjectTemplate<COLLADA_TYPE::CONTROLLER>(uniqueId)
            , mControllerType(controllerType)
            , mSource(source)
        {}

	public:
        /** Destructor. */
		virtual ~Controller(){}

		/** Type of the controller.*/
		ControllerType getControllerType() const { return mControllerType; }

        /** Returns the unique id of the source that gets modified by this controller. Must be a mesh or a 
        controller. The vertex count of the source must be equal to the vertex count of the skin 
        controller.*/
        const UniqueId& getSource() const { return mSource; }

        /** Sets the unique id of the source that gets modified by this controller. Must be a mesh or a 
        controller. The vertex count of the source must be equal to the vertex count of the skin 
        controller.*/
        void setSource( const UniqueId& source) { mSource = source; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_CONTROLLER_H__
