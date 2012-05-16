/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_ROTATE_H__
#define __COLLADAFW_ROTATE_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWTransformation.h"

#include "Math/COLLADABUMathVector3.h"


namespace COLLADAFW
{

	class Rotate : public Transformation
	{
	private:
		/** The rotation axis.*/
        COLLADABU::Math::Vector3 mRotationAxis;

		/** Rotation angle.*/
		double mRotationAngle;
	
	public:
		/** Default constructor. Constructs identity translation.*/ 
		Rotate();

		/** Sets rotation axis to @a rotationAxis and the angle to @a rotationAngle.*/ 
		Rotate(const COLLADABU::Math::Vector3& rotationAxis, double rotationAngle);

		/** Sets the components of the rotation axis to @a x, @a y, @a z and the angle to @a rotationAngle.*/
		Rotate(double x, double y, double z, double rotationAngle);

		virtual ~Rotate();

		/** Returns the rotation angle in radians.*/
		double getRotationAngle() const { return mRotationAngle; }

		/** Sets the rotation angle to @a rotationAngle. The angle must be radians.*/
		void setRotationAngle( double rotationAngle ) { mRotationAngle = rotationAngle; }

		/** Returns the rotation axis.*/
		COLLADABU::Math::Vector3& getRotationAxis() { return mRotationAxis; }

		/** Returns the rotation axis.*/
		const COLLADABU::Math::Vector3& getRotationAxis() const { return mRotationAxis; }

		/** Sets rotation axis to @a rotationAxis.*/
		void setRotationAxis(const COLLADABU::Math::Vector3& rotationAxis) { mRotationAxis = rotationAxis; }

		/** Sets the components of the rotation axis to @a x, @a y, @a z.*/
		void setRotationAxis(double x, double y, double z) { mRotationAxis = COLLADABU::Math::Vector3(x, y, z); }

		/** Clones the rotation.*/
		Rotate* clone() const { return new Rotate(*this); }

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_ROTATE_H__
