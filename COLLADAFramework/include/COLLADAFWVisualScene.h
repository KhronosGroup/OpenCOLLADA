/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_VISUALSCENE_H__
#define __COLLADAFW_VISUALSCENE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWNode.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

	class VisualScene : public ObjectTemplate<COLLADA_TYPE::VISUAL_SCENE>
	{
	private:
		/**
		* The name attribute is the text string name of this element. 
		* Optional attribute.
		*/
		String mName;

		/** All the root nodes of the visual scene.*/
		NodePointerArray mRootNodes;
	
	public:

		VisualScene(const UniqueId& uniqueId);
		virtual ~VisualScene();

		/** Returns the name of the visual scene*/
		const String& getName() const { return mName; }

		/** Sets the name of the visual scene*/
		void setName(const String& name) { mName = name; }

		/** Returns a reference to the root nodes of the visual scene. */
		NodePointerArray& getRootNodes() { return mRootNodes; }

		/** Returns a reference to the root nodes of the visual scene.*/
		const NodePointerArray& getRootNodes() const { return mRootNodes; }

		/** Returns a reference to the root nodes of the visual scene.*/
//		void setRootNodes(const NodeArray& rootNodes) { mRootNodes = rootNodes; }


	protected:
	
	private:
        /** Disable default copy ctor. */
//		VisualScene( const VisualScene& pre );
        /** Disable default assignment operator. */
//		const VisualScene& operator= ( const VisualScene& pre );

	};
} // namespace COLLADAFW

#endif // __COLLADAFW_VISUALSCENE_H__
