/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHEAR_H__
#define __COLLADAFW_SHEAR_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /**
    Important assumptions on skew and shears:

    1) COLLADA uses the RenderMan standard:
    [ 1+s*dx*ex   s*dx*ey   s*dx*ez  0 ]
    [   s*dy*ex 1+s*dy*ey   s*dy*ez  0 ]
    [   s*dz*ex   s*dz*ey 1+s*dz*ez  0 ]
    [         0         0         0  1 ]
    where s = tan(skewAngle), if the axises are normalized

    2) COLLADA and Maya use different matrix row/column ordering.

    3) Maya uses the following shear transform:
    [  1  0  0  0 ]
    [ xy  1  0  0 ]
    [ xz yx  1  0 ]
    [  0  0  0  1 ]
    */
	class Shear 	
    {
	private:

        /**< The axis which is rotated. */
        COLLADABU::Math::Vector3 mRotateAxis; 

        /**< The axis around which to rotate. */
        COLLADABU::Math::Vector3 mAroundAxis; 

        /**< The angle of rotation. */
        float mAngle;

    public:

        /** Constructor. */
        Shear() : mAngle (0) {}

        /** Destructor. */
        virtual ~Shear() {}

        /**< The axis which is rotated. */
        COLLADABU::Math::Vector3 getRotateAxis() const { return mRotateAxis; }
        void setRotateAxis(COLLADABU::Math::Vector3 val) { mRotateAxis = val; }

        /**< The axis around which to rotate. */
        COLLADABU::Math::Vector3 getAroundAxis() const { return mAroundAxis; }
        void setAroundAxis(COLLADABU::Math::Vector3 val) { mAroundAxis = val; }

        /**< The angle of rotation. */
        float getAngle() const { return mAngle; }
        void setAngle(float val) { mAngle = val; }

	private:

        /** Disable default copy ctor. */
		Shear( const Shear& pre );

        /** Disable default assignment operator. */
		const Shear& operator= ( const Shear& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHEAR_H__
