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
	int validate( const AnimationCurve* animationCurve, bool verbose );

	/** Validates skin controller data. 
	@return numberof found validation failures.*/
	int validate( const SkinControllerData* skinControllerData, bool verbose );



} // namespace COLLADAFW

#endif // __COLLADAFW_VALIDATE_H__
