/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ANIMATION_H__
#define __COLLADAFW_ANIMATION_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWObject.h"


namespace COLLADAFW
{

	/** The base class for animation. Currently we only support animation curves, but in future probably 
	formulas, too. */
	class Animation : public ObjectTemplate<COLLADA_TYPE::ANIMATION>
	{
	public:
		enum AnimationType
		{
			ANIMATION_CURVE,
			ANIMATION_FORMULA   // for the future
		};

	private:

        /**
        * The original object id, if it in the original file format exist. 
        */
        String mOriginalId;

        /** Pretty-print name for this animation. Optional. */
        String mName; 

		/** The type of the animation. */
		AnimationType mAnimationType;

	public:

		/** Destructor. */
		virtual ~Animation(){}

        /**
        * The original object id, if it in the original file format exist. 
        */
        const String& getOriginalId () const { return mOriginalId; }

        /**
        * The original object id, if it in the original file format exist. 
        */
        void setOriginalId ( const String& val ) { mOriginalId = val; }

        /** Pretty-print name for this animation. Optional. */
        const String& getName () const { return mName; }

        /** Pretty-print name for this animation. Optional. */
        void setName ( const String& val ) { mName = val; }

        /** The type of the animation.*/
		AnimationType getAnimationType() const { return mAnimationType; }

	protected:

		/** Constructor. */
		Animation( const UniqueId& uniqueId, AnimationType animationType)
			: ObjectTemplate<COLLADA_TYPE::ANIMATION>(uniqueId)
			, mAnimationType(animationType)
		{}

	private:

		/** Disable default copy ctor. */
		Animation( const Animation& pre );

		/** Disable default assignment operator. */
		const Animation& operator= ( const Animation& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ANIMATION_H__
