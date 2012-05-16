/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of DAE2MA.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __DAE2MA_SYNTAX_H__
#define __DAE2MA_SYNTAX_H__

#include "DAE2MAPrerequisites.h"


namespace DAE2MA
{
    /** The default maya version. */
    static const char* MAYA_VERSION_DEFAULT                         = "2009";

    /** Profile specific extra attribute parameters. */
    static const char* PROFILE_MAYA                                 = "OpenCOLLADAMaya";

    /** Extra technique parameters. */
    static const String PARAMETER_MAYA_ID                           = "originalMayaNodeId";

    /** Empty strings. */
    static const String EMPTY_STRING                                = "";
    static const char* EMPTY_CSTRING                                = "";

    /** The standard name for the collada id attribute. */
    static const String COLLADA_ID_ATTRIBUTE_NAME                   = "colladaId";
    static const String COLLADA_EFFECT_ID_ATTRIBUTE_NAME            = "colladaEffectId";
    static const String COLLADA_MATERIAL_ID_ATTRIBUTE_NAME          = "colladaMaterialId";
    static const String COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME     = "colladaEffectCommonId";

    /** Maya import attributes. */
    static const char* ATTR_TRANSLATE                               = "translate";
    static const char* ATTR_ROTATE                                  = "rotate";
    static const char* ATTR_ROTATE_ORDER                            = "rotateOrder";
    static const char* ATTR_SCALE                                   = "scale";
    static const char* FLAG_LOCK                                    = "lock";

    /** Constants for the cameras */
    static const char* CAMERA_PERSP_SHAPE                           = "perspShape";
    static const char* CAMERA_TOP_SHAPE                             = "topShape";
    static const char* CAMERA_SIDE_SHAPE                            = "sideShape";
    static const char* CAMERA_FRONT_SHAPE                           = "frontShape";

    /** Script parameters */
    static const char* SCRIPT_NODE_UP_AXIS                          = "upAxisScriptNode";
    static const char* SCRIPT_NODE_SCENE_CONFIG                     = "sceneConfigurationScriptNode";

}


#endif // __DAE2MA_SYNTAX_H__
