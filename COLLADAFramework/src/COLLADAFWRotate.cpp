/*
Copyright (c) 2008-2009 NetAllied Systems GmbH

This file is part of COLLADAFramework.

Licensed under the MIT Open Source License, 
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWRotate.h"

namespace COLLADAFW
{
	//--------------------------------------------------------------------
	Rotate::Rotate()
		: Transformation(Transformation::ROTATE),
		mRotationAxis(COLLADABU::Math::Vector3::ZERO),
		mRotationAngle(0.0)
	{
	}

	//--------------------------------------------------------------------
	Rotate::Rotate( const COLLADABU::Math::Vector3& rotationAxis, double rotationAngle )
		: Transformation(Transformation::ROTATE),
		mRotationAxis(rotationAxis),
		mRotationAngle(rotationAngle)
	{
	}

	Rotate::Rotate( double x, double y, double z, double rotationAngle )
		: Transformation(Transformation::ROTATE),
		mRotationAxis(COLLADABU::Math::Vector3(x, y, z)),
		mRotationAngle(rotationAngle)
	{
	}

	//--------------------------------------------------------------------
	Rotate::~Rotate()
	{
	}

} // namespace COLLADAFW
