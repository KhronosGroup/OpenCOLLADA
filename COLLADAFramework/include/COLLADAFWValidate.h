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
   
	/** Validates an animation curve. 
	@return True, if the animation is valid, false otherwise.*/
	bool validate( const AnimationCurve* animationCurve );


} // namespace COLLADAFW

#endif // __COLLADAFW_VALIDATE_H__
