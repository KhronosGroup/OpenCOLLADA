/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_VALIDATE_H__
#define __COLLADAFW_VALIDATE_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{
	class AnimationCurve;
	class SkinControllerData;
   
	/** Validates an animation curve. 
	@return True, if the animation is valid, false otherwise.*/
	bool validate( const AnimationCurve* animationCurve );

	/** Validates skin controller data. 
	@return True, if the data is valid, false otherwise.*/
	bool validate( const SkinControllerData* skinControllerData );



} // namespace COLLADAFW

#endif // __COLLADAFW_VALIDATE_H__
