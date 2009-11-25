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
	const char* ExtraKeys::KEYSEPARATOR                     = "/";

    /** COLLADA base key */
	const char* ExtraKeys::BASEKEY                          = "COLLADA";

    /** Visual scene keys */
    const char* ExtraKeys::VISUAL_SCENE                     = "EDK_VISUAL_SCENE";
    const char* ExtraKeys::NODE                             = "EDK_NODE"; 
    const char* ExtraKeys::INSTANCE_CAMERA                  = "EDK_INSTANCE_CAMERA";
    const char* ExtraKeys::INSTANCE_CONTROLLER              = "EDK_INSTANCE_CONTROLLER";
    const char* ExtraKeys::INSTANCE_GEOMETRY                = "EDK_INSTANCE_GEOMETRY";
    const char* ExtraKeys::INSTANCE_LIGHT                   = "EDK_INSTANCE_LIGHT";
    const char* ExtraKeys::INSTANCE_NODE                    = "EDK_INSTANCE_NODE";
    const char* ExtraKeys::BIND_MATERIAL_CONTROLLER         = "EDK_BIND_MATERIAL_CONTROLLER";
    const char* ExtraKeys::BIND_MATERIAL_GEOMETRY           = "EDK_BIND_MATERIAL_GEOMETRY";
    const char* ExtraKeys::INSTANCE_MATERIAL_CONTROLLER     = "EDK_INSTANCE_MATERIAL_CONTROLLER";
    const char* ExtraKeys::INSTANCE_MATERIAL_GEOMETRY       = "EDK_INSTANCE_MATERIAL_GEOMETRY";

    /** Camera keys */
	const char* ExtraKeys::CAMERA                           = "EDK_CAMERA";
	const char* ExtraKeys::OPTICS                           = "EDK_OPTICS";

    /** Light key */
    const char* ExtraKeys::LIGHT                            = "EDK_LIGHT";

    /** Image key */
    const char* ExtraKeys::IMAGE                            = "EDK_IMAGE";

    /** Geometry keys */
    const char* ExtraKeys::GEOMETRY                         = "EDK_GEOMETRY";
    const char* ExtraKeys::MESH                             = "EDK_MESH";
    const char* ExtraKeys::VERTICES                         = "EDK_VERTICES";
    const char* ExtraKeys::PRIMITIVE_ELEMENT                = "EDK_PRIMITIVE_ELEMENT";

    /** Effect keys */
    const char* ExtraKeys::EFFECT                           = "EDK_EFFECT";
    const char* ExtraKeys::PROFILE_COMMON                   = "EDK_PROFILE_COMMON";
    const char* ExtraKeys::PROFILE_CG                       = "EDK_PROFILE_CG";
    const char* ExtraKeys::PROFILE_GLSL                     = "EDK_PROFILE_GLSL";
    const char* ExtraKeys::PROFILE_GLES                     = "EDK_PROFILE_GLES";
    const char* ExtraKeys::TECHNIQUE                        = "EDK_TECHNIQUE";
    const char* ExtraKeys::TEXTURE                          = "EDK_TEXTURE";
    const char* ExtraKeys::SURFACE                          = "EDK_SURFACE";
    const char* ExtraKeys::SAMPLER2D                        = "EDK_SAMPLER2D";

    /** Material keys */
    const char* ExtraKeys::MATERIAL                         = "EDK_MATERIAL";
    const char* ExtraKeys::INSTANCE_EFFECT                  = "EDK_INSTANCE_EFFECT";

    /** Controller keys */
    const char* ExtraKeys::CONTROLLER                       = "EDK_CONTROLLER";
    const char* ExtraKeys::SKIN_CONTROLLER                  = "EDK_SKIN";
    const char* ExtraKeys::SKIN_CONTROLLER_JOINTS           = "EDK_JOINTS";
    const char* ExtraKeys::SKIN_CONTROLLER_VERTEX_WEIGHTS   = "EDK_VERTEX_WEIGHTS";
    const char* ExtraKeys::MORPH_CONTROLLER                 = "EDK_MORPH";
    const char* ExtraKeys::MORPH_CONTROLLER_TARGETS         = "EDK_TARGETS";

    /** Animation key */
    const char* ExtraKeys::ANIMATION                        = "EDK_ANIMATION";

	/** Kinematics */
	const char* ExtraKeys::INSTANCE_JOINT                   = "EDK_INSTANCE_JOINT";
	const char* ExtraKeys::KINEMATICS                       = "EDK_KINEMATICS";
	const char* ExtraKeys::ARTICULATEDSYSTEM                = "EDK_ARTICULATED_SYSTEM";

} // namespace COLLADAFW
