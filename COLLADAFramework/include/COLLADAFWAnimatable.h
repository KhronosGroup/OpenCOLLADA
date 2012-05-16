/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ANIMATABLE_H__
#define __COLLADAFW_ANIMATABLE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"


namespace COLLADAFW
{

    /** This is the base class for all objects, that can be animated. It connect the animatable object with 
	the list of animations that animate the object.*/
	class Animatable 
	{
	private:
		/** The uniqueId of the AnimationList that animates the object.*/
		UniqueId mAnimationList;
	public:

        /** Constructor. */
		Animatable(){}

        /** Destructor. */
		virtual ~Animatable(){}

		const UniqueId& getAnimationList() const { return mAnimationList; }

		void setAnimationList( const UniqueId& animationList) { mAnimationList = animationList; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ANIMATABLE_H__
