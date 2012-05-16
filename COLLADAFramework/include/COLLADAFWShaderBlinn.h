/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHADERBLINN_H__
#define __COLLADAFW_SHADERBLINN_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWShaderConstantFX.h"


namespace COLLADAFW
{

    /** 
    Produces a specularly shaded surface with a Blinn BRDF approximation.
    
    Used inside a <profile_COMMON> effect, <blinn> declares a fixed-function pipeline that 
    produces a shaded surface according to the Blinn-Torrance-Sparrow lighting model or a close 
    approximation. This equation is complex and detailed via the ACM, so it is not detailed here. 
    Refer to "Models of Light Reflection for Computer Synthesized Pictures," SIGGRAPH 77, pp 192-198
    (http://portal.acm.org/citation.cfm?id=563893).
    
    To maximize application compatibility, it is suggested that developers use the 
    Blinn-Torrance-Sparrow for <shininess> range of 0 to 1. For <shininess> greater than 1.0, the 
    COLLADA author was probably using an application that followed the Blinn-Phong lighting model, 
    so it is recommended to support both Blinn equations according to whichever range the shininess 
    resides in.
    
    The Blinn-Phong equation is:
    color = <emission> + <ambient> * al + <diffuse> * max ( N * L, 0 ) + <specular> * max ( H * N, 0 )^<shininess>

    where:
    • al — A constant amount of ambient light contribution coming from the scene. In the COMMON
    profile, this is the sum of all the <light><technique_common><ambient> values in the
    <visual_scene>.
    • N — Normal vector (normalized)
    • L — Light vector (normalized)
    • I — Eye vector (normalized)
    • H — Half-angle vector,calculated as halfway between the unit Eye and Light vectors, using the
    equation H= normalize(I+L)
    */
	class ShaderBlinn : public ShaderPhong 
		{
	private:
	
	public:

        /** Constructor. */
		ShaderBlinn() {};

        /** Destructor. */
		virtual ~ShaderBlinn() {};

	private:

        /** Disable default copy ctor. */
		ShaderBlinn( const ShaderBlinn& pre );

        /** Disable default assignment operator. */
		const ShaderBlinn& operator= ( const ShaderBlinn& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHADERBLINN_H__
