/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SKEW_H__
#define __COLLADAFW_SKEW_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"

#include "Math/COLLADABUMathMatrix4.h"


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
    class Skew : public Transformation
    {
	private:

        /**< The axis which is rotated. */
        COLLADABU::Math::Vector3 mRotateAxis; 

        /**< The axis around which to rotate. */
        COLLADABU::Math::Vector3 mTranslateAxis; 

        /**< The angle of rotation. */
        float mAngle;

    public:

        /** Constructor. */
        Skew() : Transformation ( Transformation::SKEW ), mAngle (0) {}

        /** Destructor. */
        virtual ~Skew() {}

        /** The axis which is rotated. */
        COLLADABU::Math::Vector3& getRotateAxis() { return mRotateAxis; }
		const COLLADABU::Math::Vector3& getRotateAxis() const { return mRotateAxis; }
        void setRotateAxis(COLLADABU::Math::Vector3 val) { mRotateAxis = val; }

        /** The axis around which to rotate. */
		COLLADABU::Math::Vector3& getTranslateAxis() { return mTranslateAxis; }
		const COLLADABU::Math::Vector3& getTranslateAxis() const { return mTranslateAxis; }
        void setTranslateAxis(COLLADABU::Math::Vector3 val) { mTranslateAxis = val; }

        /** The angle of rotation. */
        float getAngle() const { return mAngle; }
        void setAngle(float val) { mAngle = val; }

		/** Clones the skew.*/
		virtual Skew* clone() const { return new Skew(*this); }

	private:

        /** Disable default copy ctor. */
		//Skew( const Skew& pre );

        /** Disable default assignment operator. */
		const Skew& operator= ( const Skew& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SKEW_H__
