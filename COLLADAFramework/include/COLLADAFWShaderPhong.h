/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_SHADERPHONG_H__
#define __COLLADAFW_SHADERPHONG_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWShaderLambert.h"


namespace COLLADAFW
{

    /** 
    Produces a specularly shaded surface where the specular reflection is shaded according the 
    Phong BRDF approximation.

    Used inside a <profile_COMMON> effect, declares a fixed-function pipeline that produces a 
    specularly shaded surface that reflects ambient, diffuse, and specular reflection, where the 
    specular reflection is shaded according the Phong BRDF approximation.

    The <phong> shader uses the common Phong shading equation, that is:
    color = <emission> + <ambient> * al + <diffuse> * max ( N * L, 0 ) + <specular> * max ( R * I, 0 )^<shininess>
    
    where:
    • al — A constant amount of ambient light contribution coming from the scene. In the COMMON
    profile, this is the sum of all the <light><technique_common><ambient><color> values in
    the <visual_scene>.
    • N — Normal vector
    • L — Light vector
    • I — Eye vector
    • R — Perfect reflection vector (reflect (L around N))
    */
	class ShaderPhong : public ShaderLambert 
	{
	private:
	
        /** Declares the color of light specularly reflected from the surface of this object. */
        ColorOrTexture mSpecular;

        /** Declares the specularity or roughness of the specular reflection lobe. */
        FloatOrParam mShininess;

	public:

        /** Constructor. */
        ShaderPhong() {};

        /** Destructor. */
		virtual ~ShaderPhong() {};

        /** Declares the color of light specularly reflected from the surface of this object. */
        const ColorOrTexture getSpecular () const { return mSpecular; }

        /** Declares the color of light specularly reflected from the surface of this object. */
        void setSpecular ( const ColorOrTexture Specular ) { mSpecular = Specular; }

        /** Declares the specularity or roughness of the specular reflection lobe. */
        const FloatOrParam getShininess () const { return mShininess; }

        /** Declares the specularity or roughness of the specular reflection lobe. */
        void setShininess ( const FloatOrParam Shininess ) { mShininess = Shininess; }

    private:

        /** Disable default copy ctor. */
		ShaderPhong( const ShaderPhong& pre );

        /** Disable default assignment operator. */
		const ShaderPhong& operator= ( const ShaderPhong& pre );

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_SHADERPHONG_H__
