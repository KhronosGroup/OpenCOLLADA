/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_TYPES_H__
#define __COLLADASAXFWL_TYPES_H__

#include "COLLADASaxFWLPrerequisites.h"

#include "COLLADAFWUniqueId.h"
#include "COLLADAFWAnimationList.h"

namespace COLLADASaxFWL
{

	struct AnimationInfo
	{
		static const AnimationInfo INVALID;
		/** The unique id of the animation*/
		COLLADAFW::UniqueId uniqueId;

		/** The class of the animation.*/
		COLLADAFW::AnimationList::AnimationClass animationClass;
	};

} // namespace COLLADASAXFWL

#endif // __COLLADASAXFWL_TYPES_H__
