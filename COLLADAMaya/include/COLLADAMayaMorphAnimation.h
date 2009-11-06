/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAMAYA_MORPHCONTROLLERANIMATION_H__
#define __COLLADAMAYA_MORPHCONTROLLERANIMATION_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADAMayaBaseAnimation.h"

#include "COLLADAFWFloatOrDoubleArray.h"

#include "MayaDMBlendShape.h"


namespace COLLADAMaya
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

} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_MORPHCONTROLLERANIMATION_H__
