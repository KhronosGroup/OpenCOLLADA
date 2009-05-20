/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SKINCONTROLLER_H__
#define __COLLADAFW_SKINCONTROLLER_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWController.h"

#include "COLLADAFWUniqueId.h"

namespace COLLADAFW
{

    /** A skin controller. This class binds the skeleton (the joints ) to the skin data 
	( the weights  and the bind matrices). */
	class SkinController : public Controller 
	{
	private:

		/** The unique id of the skin controller data.*/
		UniqueId mSkinControllerData;

		/** The unique ids of the nodes, referenced by the skin controller.*/
		UniqueIdArray mJoints;

		/** The unique id of the source that gets modified by this controller. Must be a mesh or a 
		morph controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		UniqueId mSource;

	public:

        /** Constructor. */
		SkinController( ObjectId objectId );

		SkinController( const SkinController& pre );

		/** Destructor. */
		virtual ~SkinController(){}

		/** The unique id of the skin controller data.*/
		const COLLADAFW::UniqueId& getSkinControllerData() const { return mSkinControllerData; }

		/** The unique id of the skin controller data.*/
		void setSkinControllerData( const COLLADAFW::UniqueId& skinControllerData) { mSkinControllerData = skinControllerData; }

		/** The unique ids of the nodes, referenced by the skin controller.*/
		COLLADAFW::UniqueIdArray& getJoints() { return mJoints; }

		/** The unique ids of the nodes, referenced by the skin controller.*/
		const COLLADAFW::UniqueIdArray& getJoints() const { return mJoints; }

		/** Returns the unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		const COLLADAFW::UniqueId& getSource() const { return mSource; }

		/** Sets the unique id of the source that gets modified by this controller. Must be a mesh or a 
		controller. The vertex count of the source must be equal to the vertex count of the skin 
		controller.*/
		void setSource( const COLLADAFW::UniqueId& source) { mSource = source; }

	private:

        /** Disable default assignment operator. */
		const SkinController& operator= ( const SkinController& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SKINCONTROLLER_H__
