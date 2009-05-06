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
		COLLADAFW::UniqueId mSkinControllerData;

		/** The unique ids of the nodes, referenced by the skin controller.*/
		UniqueIdArray mBones;
	
	public:

        /** Constructor. */
		SkinController( ObjectId objectId )
			: Controller( objectId, Controller::CONTROLLER_TYPE_SKIN )
		{}

        /** Destructor. */
		virtual ~SkinController();

	private:

        /** Disable default copy ctor. */
		SkinController( const SkinController& pre );

        /** Disable default assignment operator. */
		const SkinController& operator= ( const SkinController& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SKINCONTROLLER_H__
