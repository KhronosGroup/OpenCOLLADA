/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SCENEGRAPHINSTANCE_H__
#define __COLLADAFW_SCENEGRAPHINSTANCE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWPointerArray.h"


namespace COLLADAFW
{

	/** Base class for all classes, that represent the instantiation of an object within the scene graph*/
	class SceneGraphInstance
	{
	private:
		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		/** The unique id of the instantiated object.*/
		UniqueId mInstanciatedObjectId;

	public:

		/** Constructor. Creates an instance of an object with UniqueId @a instanciatedObjectId.
		@param instanciatedObjectId The UniqueId of the object instantiated.*/ 
		SceneGraphInstance(UniqueId instanciatedObjectId);

		virtual ~SceneGraphInstance();

		/** Returns the name of the node*/
		const String& getName() const { return mName; }

		/** Sets the name of the node*/
		void getName(const String& name) { mName = name; }

		/** Returns the unique id of the instantiated object.*/
		const UniqueId& getInstanciatedObjectId() const { return mInstanciatedObjectId; }

		virtual SceneGraphInstance* clone() const { return new SceneGraphInstance(*this); }

	};

	typedef PointerArray<SceneGraphInstance> SceneGraphInstancePointerArray;


} // namespace COLLADAFW

#endif // __COLLADAFW_SCENEGRAPHINSTANCE_H__
