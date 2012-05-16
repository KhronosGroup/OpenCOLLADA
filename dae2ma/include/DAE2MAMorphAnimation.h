/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_MORPHCONTROLLERANIMATION_H__
#define __DAE2MA_MORPHCONTROLLERANIMATION_H__

#include "DAE2MAPrerequisites.h"
#include "DAE2MABaseAnimation.h"

#include "COLLADAFWFloatOrDoubleArray.h"

#include "MayaDMBlendShape.h"


namespace DAE2MA
{

    /** TODO Documentation */
    class MorphAnimation : public BaseAnimation
    {
	private:
        /** The animation target (for morph, only the weights for the blend shape are animatable). */
        MayaDM::BlendShape mBlendShapeTarget;

	public:

        /** Constructor. */
        MorphAnimation();

        /** Destructor. */
		virtual ~MorphAnimation();

        /** The animation target (for morph, only the weights for the blend shape are animatable). */
        const MayaDM::BlendShape& getBlendShapeTarget () const { return mBlendShapeTarget; }
        /** The animation target (for morph, only the weights for the blend shape are animatable). */
        void setBlendShapeTarget ( const MayaDM::BlendShape& val ) { mBlendShapeTarget = val; }

	};

} // namespace DAE2MA

#endif // __DAE2MA_MORPHCONTROLLERANIMATION_H__
