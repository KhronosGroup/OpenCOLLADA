/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ANIMATABLEFLOAT_H__
#define __COLLADAFW_ANIMATABLEFLOAT_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWAnimatable.h"


namespace COLLADAFW
{

    /** A single float value that can be animated. */
	class AnimatableFloat : public Animatable 
	{
	private:
		/** The float value. This value is to be used, if there is no animation.*/
		double mValue;
	
	public:

        /** Constructor. */
		AnimatableFloat(){}

		/** Constructor. */
		AnimatableFloat(double value) : mValue(value) {}

        /** Destructor. */
		virtual ~AnimatableFloat(){}

		/** The float value. This value is to be used, if there is no animation.*/
		double getValue() const { return mValue; }

		/** The float value. This value is to be used, if there is no animation.*/
		void setValue(double value) { mValue = value; }

		operator double() const { return mValue; }

		const AnimatableFloat& operator=( double value ) { mValue = value; return *this; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ANIMATABLEFLOAT_H__
