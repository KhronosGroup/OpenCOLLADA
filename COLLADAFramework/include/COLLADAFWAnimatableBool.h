/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ANIMATABLEBOOL_H__
#define __COLLADAFW_ANIMATABLEBOOL_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWAnimatable.h"


namespace COLLADAFW
{

    /** A single Bool value that can be animated. */
	class AnimatableBool : public Animatable 
	{
	private:
		/** The Bool value. This value is to be used, if there is no animation.*/
		bool mValue;
	
	public:

        /** Constructor. */
		AnimatableBool(){}

		/** Constructor. */
		AnimatableBool(bool value) : mValue(value) {}

        /** Destructor. */
		virtual ~AnimatableBool(){}

		/** The Bool value. This value is to be used, if there is no animation.*/
		bool getValue() const { return mValue; }

		/** The Bool value. This value is to be used, if there is no animation.*/
		void setValue(bool value) { mValue = value; }

		operator bool() const { return mValue; }

		const AnimatableBool& operator=( bool value ) { mValue = value; return *this; }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ANIMATABLEBool_H__
