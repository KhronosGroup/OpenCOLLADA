/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ANIMATIONLIST_H__
#define __COLLADAFW_ANIMATIONLIST_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADAFWArrayPrimitiveType.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

    /** An animation list contains all the animations that animate an animatable. 
	Not all animatables support all animation classes. See the documentation of each animatable for supported 
	animation classes and their meaning.*/
	class AnimationList : public ObjectTemplate<COLLADA_TYPE::ANIMATIONLIST>	
	{
	public:
		/** Classifies animations.*/
		enum AnimationClass
		{
			UNKNOWN_CLASS,
			TIME,
			POSITION_XYZ,			//!< Animation of all three coordinates of a position
			POSITION_X,
			POSITION_Y,
			POSITION_Z,
			COLOR_RGB,
			COLOR_RGBA,
			COLOR_R,
			COLOR_G,
			COLOR_B,
			COLOR_A,
			AXISANGLE,
			ANGLE,
			MATRIX4X4,
			ARRAY_ELEMENT_1D,       //!< Array element accessed via one index
			ARRAY_ELEMENT_2D,		//!< Array element accessed via two indices	
			FLOAT
		};

		/** Binds the animated part of an animatable to the animation.*/
		struct  AnimationBinding
		{ 
			/** The uniqueId of the animation.*/
			UniqueId animation;

			/** The class of the animation.*/
			AnimationClass animationClass;

			/** The first index of the value to animate. Meaning is Animatable depended.*/
			size_t firstIndex;

			/** The second index of the value to animate. Meaning is Animatable depended.*/
			size_t secondIndex;
		};

		typedef ArrayPrimitiveType<AnimationBinding> AnimationBindings;

	private:
		AnimationBindings mAnimationBindings;

	public:

        /** Constructor. */
		AnimationList( const UniqueId& uniqueId ) 
			: ObjectTemplate<COLLADA_TYPE::ANIMATIONLIST>(uniqueId)
			, mAnimationBindings(AnimationBindings::OWNER)
		{}

        /** Destructor. */
		virtual ~AnimationList(){}

		const AnimationBindings& getAnimationBindings() const { return mAnimationBindings; }

		AnimationBindings& getAnimationBindings() { return mAnimationBindings; }

        /**  */
		AnimationList( const AnimationList& pre )
			: ObjectTemplate<COLLADA_TYPE::ANIMATIONLIST>( pre.getUniqueId())
		{
			pre.getAnimationBindings().cloneArray( mAnimationBindings );
		}

        /** */
		const AnimationList& operator= ( const AnimationList& pre )
		{
			mAnimationBindings.clear();
			pre.getAnimationBindings().cloneArray( mAnimationBindings );
            return *this;
		}

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ANIMATIONLIST_H__
