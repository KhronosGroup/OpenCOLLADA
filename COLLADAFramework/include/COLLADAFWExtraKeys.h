/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_EXTRAKEYS_H__
#define __COLLADAFW_EXTRAKEYS_H__

#include "COLLADAFWPrerequisites.h"


namespace COLLADAFW
{

    /** TODO Documentation */
	class ExtraKeys 	
	{
	public:

        /** The key separartor "/" */
		static const char* KEYSEPARATOR;

        /** COLLADA base key */
		static const char* BASEKEY;

        /** Camera keys */
		static const char* CAMERA;
		static const char* OPTICS;

        /** Geometry keys */
        static const char* GEOMETRY;
        static const char* MESH;
        static const char* VERTICES;
        static const char* PRIMITIVE_ELEMENT;

        /** Effect keys */
        static const char* EFFECT;
        static const char* PROFILE_COMMON;
        static const char* PROFILE_CG;
        static const char* PROFILE_GLSL;
        static const char* PROFILE_GLES;
        static const char* TECHNIQUE;
        static const char* TEXTURE;
        static const char* SURFACE;
        static const char* SAMPLER2D;

        /** Material keys */
        static const char* MATERIAL;
        static const char* INSTANCE_EFFECT;


		/************ kinematics ****************/
		static const char* INSTANCEJOINT;
		static const char* KINEMATICS;
		static const char* ARTICULATEDSYSTEM;

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_EXTRAKEYS_H__
