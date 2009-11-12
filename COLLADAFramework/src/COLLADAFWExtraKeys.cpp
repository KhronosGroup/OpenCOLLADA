/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWExtraKeys.h"


namespace COLLADAFW
{

    /** The key separartor "/" */
	const char* ExtraKeys::KEYSEPARATOR         = "/";

    /** COLLADA base key */
	const char* ExtraKeys::BASEKEY              = "COLLADA";

    /** Camera keys */
	const char* ExtraKeys::CAMERA               = "EDK_CAMERA";
	const char* ExtraKeys::OPTICS               = "EDK_OPTICS";
	
    /** Geometry keys */
    const char* ExtraKeys::GEOMETRY             = "EDK_GEOMETRY";
    const char* ExtraKeys::MESH                 = "EDK_MESH";
    const char* ExtraKeys::VERTICES             = "EDK_VERTICES";
    const char* ExtraKeys::PRIMITIVE_ELEMENT    = "EDK_PRIMITIVE_ELEMENT";

    /** Effect keys */
    const char* ExtraKeys::EFFECT               = "EDK_EFFECT";
    const char* ExtraKeys::PROFILE_COMMON       = "EDK_PROFILE_COMMON";
    const char* ExtraKeys::PROFILE_CG           = "EDK_PROFILE_CG";
    const char* ExtraKeys::PROFILE_GLSL         = "EDK_PROFILE_GLSL";
    const char* ExtraKeys::PROFILE_GLES         = "EDK_PROFILE_GLES";
    const char* ExtraKeys::TECHNIQUE            = "EDK_TECHNIQUE";
    const char* ExtraKeys::TEXTURE              = "EDK_TEXTURE";
    const char* ExtraKeys::SURFACE              = "EDK_SURFACE";
    const char* ExtraKeys::SAMPLER2D            = "EDK_SAMPLER2D";

    /** Material keys */
    const char* ExtraKeys::MATERIAL             = "EDK_MATERIAL";
    const char* ExtraKeys::INSTANCE_EFFECT      = "EDK_INSTANCE_EFFECT";


	/************ kinematics ****************/
	const char* ExtraKeys::INSTANCEJOINT        = "EDK_INSTANCE_JOINT";
	const char* ExtraKeys::KINEMATICS           = "EDK_KINEMATICS";
	const char* ExtraKeys::ARTICULATEDSYSTEM    = "EDK_ARTICULATED_SYSTEM";

} // namespace COLLADAFW
