/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMaya.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    Copyright (c) 2004-2005 Alias Systems Corp.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_SYNTAX_H__
#define __COLLADA_MAYA_SYNTAX_H__

#include "COLLADAMayaPrerequisites.h"
#include "COLLADABUVersionInfo.h"

namespace COLLADAMaya
{
    // COLLADA NetAllied Systems
    static const char* TRANSLATOR_VENDOR                            = "NetAllied Systems GmbH";
    static const char* USERNAME                                     = "USERNAME";
    static const char* USER                                         = "USER";

    // Names for the creation of the plug-in
    static const char* COLLADA_EXPORTER                             = "OpenCOLLADA exporter";
    static const char* COLLADA_IMPORTER                             = "OpenCOLLADA importer";
    static const char* COLLADA_DOCUMENT                             = "colladaDocument";
    static const String AUTHORING_TOOL_NAME                         = "OpenCOLLADA";

    /** Profile specific extra attribute parameters. */
    static const char* PROFILE_COLLADA                              = "COLLADA";
    static const String PROFILE_MAYA                                 = "OpenCOLLADAMaya";
    static const char* PROFILE_MAX                                  = "OpenCOLLADA3dsMax";
	
    /** Extra technique parameters. */
    static const String PARAMETER_MAYA_ID                           = "originalMayaNodeId";
    static const String PARAMETER_DOUBLE_SIDED                      = "double_sided";
	static const String PARAMETER_PROXY								= "proxy";
	static const String PARAMETER_EVENT								= "event";

    /** Empty strings. */
    static const String EMPTY_STRING                                = "";
    static const char* EMPTY_CSTRING                                = "";

    /** The unique name for the visual scene node on export. */
    static const String VISUAL_SCENE_NODE_ID                        = "VisualSceneNode";

	/** The unique name for the physics scene node on export. */
	static const String PHYSICS_SCENE_NODE_ID						= "collada_physics_scene";


    /** The standard name for the collada id attribute. */
    static const String COLLADA_ID_ATTRIBUTE_NAME                   = "colladaId";
    static const String COLLADA_EFFECT_ID_ATTRIBUTE_NAME            = "colladaEffectId";
    static const String COLLADA_MATERIAL_ID_ATTRIBUTE_NAME          = "colladaMaterialId";
    static const String COLLADA_EFFECT_COMMON_ID_ATTRIBUTE_NAME     = "colladaEffectCommonId";

    /** Node types. */
    static const char* NODE_TYPE_NODE                               = "NODE";
    static const char* NODE_TYPE_JOINT                              = "JOINT";

    // Mel-Scripts
    // Name of a MEL script that will be used to display the contents of the
    // options dialog during file open and save
    static const char*  MEL_EXPORT_OPTS                                   = "openColladaExporterOpts";
    static const char*  MEL_IMPORT_OPTS                                   = "openColladaImporterOpts";

    // COLLADA 1.4 Maya-specific definitions
    static const char* MAYA_TEXTURE_NODETYPE                        = "dgnode_type";
    static const char* MAYA_TEXTURE_FILETEXTURE                     = "kFile";
    static const char* MAYA_TEXTURE_PSDTEXTURE                      = "kPSDFile";
    static const char* MAYA_TEXTURE_IMAGE_SEQUENCE                  = "image_sequence";

    static const char* MAYA_PENUMBRA_LIGHT_PARAMETER				= "penumbra_angle";
    static const char* MAYA_DROPOFF_LIGHT_PARAMETER					= "dropoff";
    static const char* MAYA_AMBIENTSHADE_LIGHT_PARAMETER			= "ambient_shade";

    // COLLADA 1.3 Maya-specific definitions
    static const char* MAYA_BLINDNAME_PARAMETER                     = "BLINDNAME";
    static const char* MAYA_BLINDTYPEID_PARAMETER                   = "BLINDTYPEID";
    static const char* MAYA_DOUBLE_SIDED_PARAMETER                  = "DOUBLE_SIDED";
    static const char* MAYA_LAYER_PARAMETER                         = "layer";
    static const char* MAYA_LONGNAME_PARAMETER                      = "long_name";
    static const char* MAYA_PREINFINITY_PARAMETER                   = "pre_infinity";
    static const char* MAYA_POSTINFINITY_PARAMETER                  = "post_infinity";
    static const char* MAYA_SHORTNAME_PARAMETER                     = "short_name";

    static const char* MAYA_TEXTURE_WRAPU_PARAMETER                 = "wrapU";
    static const char* MAYA_TEXTURE_WRAPV_PARAMETER                 = "wrapV";
    static const char* MAYA_TEXTURE_MIRRORU_PARAMETER               = "mirrorU";
    static const char* MAYA_TEXTURE_MIRRORV_PARAMETER               = "mirrorV";
    static const char* MAYA_TEXTURE_COVERAGEU_PARAMETER             = "coverageU";
    static const char* MAYA_TEXTURE_COVERAGEV_PARAMETER             = "coverageV";
    static const char* MAYA_TEXTURE_TRANSFRAMEU_PARAMETER           = "translateFrameU";
    static const char* MAYA_TEXTURE_TRANSFRAMEV_PARAMETER           = "translateFrameV";
    static const char* MAYA_TEXTURE_ROTFRAME_PARAMETER              = "rotateFrame";
    static const char* MAYA_TEXTURE_STAGGER_PARAMETER               = "stagger";
    static const char* MAYA_TEXTURE_REPEATU_PARAMETER               = "repeatU";
    static const char* MAYA_TEXTURE_REPEATV_PARAMETER               = "repeatV";
    static const char* MAYA_TEXTURE_OFFSETU_PARAMETER               = "offsetU";
    static const char* MAYA_TEXTURE_OFFSETV_PARAMETER               = "offsetV";
    static const char* MAYA_TEXTURE_ROTATEUV_PARAMETER              = "rotateUV";
    static const char* MAYA_TEXTURE_NOISEU_PARAMETER                = "noiseU";
    static const char* MAYA_TEXTURE_NOISEV_PARAMETER                = "noiseV";
    static const char* MAYA_TEXTURE_FAST_PARAMETER                  = "fast";
    static const char* MAYA_TEXTURE_BLENDMODE_PARAMETER             = "blend_mode";

    static const char* MAYA_PROJECTION_ELEMENT                      = "projection";
    static const char* MAYA_PROJECTION_TYPE_PARAMETER               = "type";
    static const char* MAYA_PROJECTION_MATRIX_PARAMETER             = "matrix";

    // ColladaMaya enumerated types
    static const char* MAYA_CONSTANT_INFINITY                       = "CONSTANT";
    static const char* MAYA_LINEAR_INFINITY                         = "LINEAR";
    static const char* MAYA_CYCLE_INFINITY                          = "CYCLE";
    static const char* MAYA_CYCLE_RELATIVE_INFINITY                 = "CYCLE_RELATIVE";
    static const char* MAYA_OSCILLATE_INFINITY                      = "OSCILLATE";

    static const char* MAYA_BLENDMODE_NONE                          = "NONE";
    static const char* MAYA_BLENDMODE_OVER                          = "OVER";
    static const char* MAYA_BLENDMODE_IN                            = "IN";
    static const char* MAYA_BLENDMODE_OUT                           = "OUT";
    static const char* MAYA_BLENDMODE_ADD                           = "ADD";
    static const char* MAYA_BLENDMODE_SUBTRACT                      = "SUBTRACT";
    static const char* MAYA_BLENDMODE_MULTIPLY                      = "MULTIPLY";
    static const char* MAYA_BLENDMODE_DIFFERENCE                    = "DIFFERENCE";
    static const char* MAYA_BLENDMODE_LIGHTEN                       = "LIGHTEN";
    static const char* MAYA_BLENDMODE_DARKEN                        = "DARKEN";
    static const char* MAYA_BLENDMODE_SATURATE                      = "SATURATE";
    static const char* MAYA_BLENDMODE_DESATURATE                    = "DESATURATE";
    static const char* MAYA_BLENDMODE_ILLUMINATE                    = "ILLUMINATE";

    static const char* MAYA_NOTE_PARAMETER                          = "note";
    static const char* MAYA_ENDTIME_PARAMETER                       = "end_time";
    static const char* MAYA_STARTTIME_PARAMETER                     = "start_time";
    static const char* MAYA_SEGMENTSCALECOMP_PARAMETER              = "segment_scale_compensate";
    static const char* MAYA_BUMP_PARAMETER                          = "bump";

    /** Parameters for the animation exports. */
    static const String EMPTY_PARAMETER[1]                          = { "" };
    static const String X_PARAMETER[1]                              = { "X" };
    static const String Y_PARAMETER[1]                              = { "Y" };
    static const String Z_PARAMETER[1]                              = { "Z" };
    static const String XY_PARAMETER[1]                             = { "XY" };
    static const String XZ_PARAMETER[1]                             = { "XZ" };
    static const String YZ_PARAMETER[1]                             = { "YZ" };
    static const String XY_PARAMETERS[2]                            = { "X", "Y" };
    static const String XYZ_PARAMETERS[3]                           = { "X", "Y", "Z" };
    static const String ZYX_PARAMETERS[3]                           = { "Z", "Y", "X" };
    static const String XYZW_PARAMETERS[4]                          = { "X", "Y", "Z", "W" };
    static const String STPQ_PARAMETERS[4]                          = { "S", "T", "P", "Q" };
    static const String RGBA_PARAMETERS[4]                          = { "R", "G", "B", "A" };
    static const String ANGLE_PARAMETER[1]                          = { "ANGLE" };
    static const String MATRIX_PARAMETER[1]                         = { "MATRIX" };
    static const String TRANSFORM_PARAMETER[1]                      = { "TRANSFORM" };

    static const String A_PARAMETER[1]                              = { "A" };
    static const String RGB_PARAMETERS[3]                           = { "R", "G", "B" };
    static const String ST_PARAMETERS[2]                            = { "S", "T" };

    static const String VERTEX_SID                                  = "VERTEX";
    static const String SKEW_XY_SID                                 = "skewXY";
    static const String SKEW_XZ_SID                                 = "skewXZ";
    static const String SKEW_YZ_SID                                 = "skewYZ";

    /** Attribute names and sids for camera animation. */
    static const String XMAG_SID                                    = "xmag";
    static const String YFOV_SID                                    = "yfov";
    static const String XFOV_SID                                    = "xfov";
    static const String NEAR_CLIP_SID                               = "near_clip";
    static const String FAR_CLIP_SID                                = "far_clip";
    static const String VERTICAL_APERTURE_SID                       = "vertical_aperture";
    static const String HORIZONTAL_APERTURE_SID                     = "horizontal_aperture";
    static const String LENS_SQUEEZE_SID                            = "lens_squeeze";
    static const String FILM_FIT_OFFSET_SID                         = "film_fit_offset";
    static const String HORIZONTAL_FILM_OFFSET_SID                  = "horizontal_film_offset";
    static const String VERTICAL_FILM_OFFSET_SID                    = "vertical_film_offset";

    static const String ATTR_ORTHOGRAPHIC_WIDTH                     = "orthographicWidth";
    static const String ATTR_FOCAL_LENGTH                           = "focalLength";
    static const String ATTR_NEAR_CLIP_PLANE                        = "nearClipPlane";
    static const String ATTR_FAR_CLIP_PLANE                         = "farClipPlane";
    static const String ATTR_VERTICAL_FILM_APERTURE                 = "verticalFilmAperture";
    static const String ATTR_HORIZONTAL_FILM_APERTURE               = "horizontalFilmAperture";
    static const String ATTR_LENS_SQUEEZE_RATIO                     = "lensSqueezeRatio";
    static const String ATTR_FILM_FIT_OFFSET                        = "filmFitOffset";
    static const String ATTR_HORIZONTAL_FILM_OFFSET                 = "horizontalFilmOffset"; // XYZ
    static const String ATTR_VERTICAL_FILM_OFFSET                   = "verticalFilmOffset"; // XYZ

    static const String MAYA_VAPERTURE_PARAMETER                    = "vertical_aperture";
    static const String MAYA_HAPERTURE_PARAMETER                    = "horizontal_aperture";
    static const String MAYA_LENS_SQUEEZE_PARAMETER                 = "lens_squeeze";
    static const String MAYA_FILM_FIT_PARAMETER                     = "film_fit";
    static const String MAYA_FILM_FIT_OFFSET_PARAMETER              = "film_fit_offset";
    static const String MAYA_FILM_OFFSET_X_PARAMETER                = "film_offsetX";
    static const String MAYA_FILM_OFFSET_Y_PARAMETER                = "film_offsetY";

    /** The plug ids for the animation exports. */
    static const char* ATTR_ALPHA_GAIN                              = "alphaGain";
    static const char* ATTR_ALPHA_OFFSET                            = "alphaOffset";
    static const char* ATTR_AMBIENT_COLOR                           = "ambientColor";
    static const char* ATTR_AMBIENT_SHADE                           = "ambientShade";
    static const char* ATTR_BACKFACE_CULLING                        = "backfaceCulling";
    static const char* ATTR_BUMP_DEPTH                              = "bumpDepth";
    static const char* ATTR_BUMP_INTERP                             = "bumpInterp";
    static const char* ATTR_BUMP_VALUE                              = "bumpValue";
    static const char* ATTR_COLOR                                   = "color";
    static const char* ATTR_COLOR_NAME                              = "cn";
    static const char* ATTR_COLOR_PER_VERTEX                        = "colorPerVertex";
    static const char* ATTR_COLORSET                                = "colorSet";
    static const char* ATTR_COLORSET_NAME                           = "clsn";
    static const char* ATTR_COLORSET_POINTS                         = "clsp";
    static const char* ATTR_CONE_ANGLE                              = "coneAngle";
    static const char* ATTR_COSINE_POWER                            = "cosinePower";
    static const char* ATTR_DEFAULT_SHADER_LIST1                    = "defaultShaderList1";
    static const char* ATTR_DOUBLE_SIDED                            = "doubleSided";
    static const char* ATTR_DROP_OFF                                = "dropoff";
    static const char* ATTR_ENVELOPE                                = "en";
    static const char* ATTR_ECCENTRICITY                            = "eccentricity";
    static const char* ATTR_FILE_TEXTURE_NAME                       = "fileTextureName";
    static const char* ATTR_GEOM_MATRIX                             = "geomMatrix";
    static const char* ATTR_IMAGE                                   = "image";
    static const char* ATTR_IMAGE_SEQUENCE                          = "useFrameExtension";
    /** The standard input attribute of the polyShape node. This attribute accepts input
    mesh data from other DG nodes and forwards the data through the node to the
    outMesh. It stores its own internal copy of the geometry being passed into the
    node. inMesh is only valid if there is an input connection. Otherwise it is ignored. */
    static const char* ATTR_IN_MESH                                 = "inMesh";
    static const char* ATTR_INCANDESCENCE                           = "incandescence";
    static const char* ATTR_INPUt                                   = "input";
    static const char* ATTR_INPUT_GEOM_TARGET                       = "igt";
    static const char* ATTR_INPUT_GEOMETRY                          = "ig";
    static const char* ATTR_INPUT_COMPONENT_TARGET                  = "ict";
    static const char* ATTR_INPUT_POINTS_TARGET                     = "ipt";
    static const char* ATTR_INPUT_TARGET                            = "it";
    static const char* ATTR_INPUT_TARGET_GROUP                      = "itg";
    static const char* ATTR_INPUT_TARGET_INPUT                      = "iti";
    static const char* ATTR_INTENSITY                               = "intensity";
    static const char* ATTR_INTERMEDIATE_OBJECT                     = "io";
    static const char* ATTR_INVERT                                  = "invert";
    static const char* ATTR_JOINT_ORIENT                            = "jointOrient";
    static const char* ATTR_MATRIX                                  = "matrix";
    static const char* ATTR_NODE_STATE                              = "nodeState";
    static const char* ATTR_NORMAL_CAMERA                           = "normalCamera";
    static const char* ATTR_OUT_ALPHA                               = "oa"; 
    static const char* ATTR_OUT_COLOR                               = "oc"; // "outColor"
    /** The standard output attribute of the polyShape node. This attribute receives input
    mesh data from either the inMesh or cachedInMesh (depending on the node
    state) and stores it as its own internal copy of the mesh. The outMesh geometry
    represents the final geometry of the shape and is always valid. */
    static const char* ATTR_OUT_MESH                                = "outMesh";
    static const char* ATTR_OUTPUT                                  = "output";
    static const char* ATTR_OUT_TRANSPARENCY                        = "ot"; // "outTransparency" 
    static const char* ATTR_PENUMBRA_ANGLE                          = "penumbraAngle";
    static const char* ATTR_PLACEMENT_MATRIX                        = "placementMatrix";
    static const char* ATTR_PROJECTION_TYPE                         = "projType";
    static const char* ATTR_REFLECTIVITY                            = "reflectivity";
    static const char* ATTR_REFLECTED_COLOR                         = "reflectedColor";
    static const char* ATTR_REFRACTIONS                             = "refractions";
    static const char* ATTR_REFRACTIVE_INDEX                        = "refractiveIndex";
    static const char* ATTR_ROTATE                                  = "rotate";
    static const char* ATTR_ROTATE_AXIS                             = "rotateAxis";
    static const char* ATTR_ROTATE_ORDER                            = "rotateOrder";
    static const char* ATTR_ROTATE_PIVOT                            = "rotatePivot";
    static const char* ATTR_ROTATE_PIVOT_TRANSLATION                = "rotatePivotTranslation";
    static const char* ATTR_ROTATE_PIVOT_INVERSE                    = "rotatePivotInverse";
    static const char* ATTR_ROTATE_X                                = "rotateX";
    static const char* ATTR_ROTATE_Y                                = "rotateY";
    static const char* ATTR_ROTATE_Z                                = "rotateZ";
    static const char* ATTR_SCALE                                   = "scale";
    static const char* ATTR_SCALE_PIVOT_INVERSE                     = "scalePivotInverse";
    static const char* ATTR_SCALE_PIVOT                             = "scalePivot";
    static const char* ATTR_SCALE_PIVOT_TRANSLATION                 = "scalePivotTranslation";
    static const char* ATTR_SHADERS                                 = "shaders";
    static const char* ATTR_SEGMENT_SCALE_COMPENSATE                = "ssc";
    static const char* ATTR_SKEW                                    = "skew";
    static const char* ATTR_SPECULAR_COLOR                          = "specularColor";
    static const char* ATTR_SURFACE_SHADER                          = "surfaceShader";
    static const char* ATTR_TRANSFORM                               = "transform";
    static const char* ATTR_TRANSLATE                               = "translate";
    static const char* ATTR_TRANSPARENCY                            = "transparency";
    static const char* ATTR_UV_COORD                                = "uvCoord";
    static const char* ATTR_UV_SET                                  = "uvSet";
    static const char* ATTR_UV_SET_NAME                             = "uvsn";
    static const char* ATTR_VISIBILITY                              = "visibility";
    static const char* ATTR_VERTEX_POSITION_TWEAKS                  = "pt";
    static const char* ATTR_VERTEX_ALPHA                            = "vxal";
    static const char* ATTR_VERTEX_COLOR                            = "vclr";
    static const char* ATTR_VERTEX_COLOR_RGB                        = "vrgb";
    static const char* ATTR_VERTEX_FACE_ALPHA                       = "vfal";
    static const char* ATTR_VERTEX_FACE_COLOR                       = "vfcl";
    static const char* ATTR_VERTEX_FACE_COLOR_RGB                   = "frgb";
    static const char* ATTR_WEIGHT                                  = "w";
	static const char* ATTR_EVENT_ANIMATION							= "animationEvent";
	static const char* ATTR_CLIP_SOURCE_START						= "sourceStart";
	static const char* ATTR_CLIP_SOURCE_END							= "sourceEnd";
	static const char* ATTR_THRESHOLD								= "threshold";

    /** Constants for the cameras */
    static const char* CAMERA_PERSP                                 = "persp";
    static const char* CAMERA_TOP                                   = "top";
    static const char* CAMERA_SIDE                                  = "side";
    static const char* CAMERA_FRONT                                 = "front";
    static const char* CAMERA_PERSP_SHAPE                           = "perspShape";
    static const char* CAMERA_TOP_SHAPE                             = "topShape";
    static const char* CAMERA_SIDE_SHAPE                            = "sideShape";
    static const char* CAMERA_FRONT_SHAPE                           = "frontShape";

    /** Constants for the physical scenes. */
    static const char* NIMA_INTERNAL_PHYSIKS                        = "nimaInternalPhysics";
    static const char* AGEIA_PHYSIKS_MODEL                          = "AgeiaPhysicsModel";
	static const char* BULLET_PHYSIKS_NODE							= "bulletRigidBodyShape";
	static const char* BULLET_PHYSIKS_SOLVER_NODE					= "bulletSolverShape";
    static const char* NX_RIGID_SOLVER                              = "nxRigidSolver";
    static const char* NX_RIGID_BODY                                = "nxRigidBody";
    static const char* NX_SHAPE                                     = "physicsShape";
    static const char* NX_RIGID_CONSTRAINT                          = "nxRigidConstraint";
	static const char* PHYSICS_MODEL_ID								= "PhysicsModel";
	static const char* PHYSICS_WORLD_REFERENCE						= "world";
	static const char* ATTR_MASS									= "mass";
	static const char* ATTR_BODY_TYPE								= "bodyType";
	static const char* ATTR_DYNAMIC									= "dynamic";
	static const char* ATTR_INERTIA									= "inertia";
	static const char* ATTR_EXTENT									= "extent";
    static const char* ATTR_RIGID_BODY_1                            = "rigidBody1";
    static const char* ATTR_RIGID_BODY_2                            = "rigidBody2";
    static const char* ATTR_CONSTRAIN                               = "constrain";
    static const char* ATTR_USE_ACCELERATION                        = "useAcceleration";
    static const char* ATTR_RADIUS_SCALE                            = "radiusScale";
    static const char* ATTR_ORIENTATION_MODE                        = "orientationMode";
    static const char* ATTR_SWING_1_LIMIT_RESTITUTION               = "swing1LimitRestitution";
    static const char* ATTR_SWING_1_LIMIT_SPRING                    = "swing1LimitSpring";
    static const char* ATTR_SWING_1_LIMIT_DAMPING                   = "swing1LimitDamping";
    static const char* ATTR_SWING_2_LIMIT_RESTITUTION               = "swing2LimitRestitution";
    static const char* ATTR_SWING_2_LIMIT_SPRING                    = "swing2LimitSpring";
    static const char* ATTR_SWING_2_LIMIT_DAMPING                   = "swing2LimitDamping";
    static const char* ATTR_TWIST_LOW_LIMIT_RESTITUTION             = "twistLowLimitRestitution";
    static const char* ATTR_TWIST_LOW_LIMIT_SPRING                  = "twistLowLimitSpring";
    static const char* ATTR_TWIST_LOW_LIMIT_DAMPING                 = "twistLowLimitDamping";
    static const char* ATTR_TWIST_HIGH_LIMIT_RESTITUTION            = "twistHighLimitRestitution";
    static const char* ATTR_TWIST_HIGH_LIMIT_SPRING                 = "twistHighLimitSpring";
    static const char* ATTR_TWIST_HIGH_LIMIT_DAMPING                = "twistHighLimitDamping";
    static const char* ATTR_LINEAR_LIMIT_VALUE                      = "linearLimitValue";
    static const char* ATTR_LINEAR_LIMIT_RESTITUTION                = "linearLimitRestitution";
    static const char* ATTR_LINEAR_LIMIT_SPRING                     = "linearLimitSpring";
    static const char* ATTR_LINEAR_LIMIT_DAMPING                    = "linearLimitDamping";
    static const char* ATTR_DRIVE_DAMPING_SLERP                     = "driveDampingSlerp";
    static const char* ATTR_DRIVE_SPRING_SLERP                      = "driveSpringSlerp";
    static const char* ATTR_BREAKABLE_FORCE                         = "breakableForce";
    static const char* ATTR_MAX_FORCE                               = "maxForce";
    static const char* ATTR_BREAKABLE_TORQUE                        = "breakableTorque";
    static const char* ATTR_MAX_TORQUE                              = "maxTorque";
    static const char* ATTR_REVERSE                                 = "reverse";
    static const char* ATTR_PROJECTION_MODE                         = "projectionMode";
    static const char* ATTR_PROJECTION_DISTANCE                     = "projectionDistance";
    static const char* ATTR_PROJECTION_ANGLE                        = "projectionAngle";
    static const char* ATTR_ANGULAR_DRIVE_MODE                      = "angularDriveMode";
    static const char* ATTR_INTERPENETRATE                          = "interpenetrate";
    static const char* ATTR_TARGET                                  = "target";
    static const char* ATTR_SIMULATION_TYPE                         = "simulationType";
    static const char* ATTR_SWITCH_TO_DYNAMIC                       = "switchToDynamic";
    static const char* ATTR_SWITCH_AT_FRAME                         = "switchAtFrame";
    static const char* ATTR_ENABLE_GRAVITY                          = "enableGravity";
    static const char* ATTR_FORCE_TO_SLEEP                          = "forceToSleep";
    static const char* ATTR_OVERRIDE_MASS_OR_DENSITY                = "overrideMassOrDensity";
    static const char* ATTR_DENSITY                                 = "density";
    static const char* ATTR_BOUNCINESS                              = "bounciness";
    static const char* ATTR_STATIC_FRICTION                         = "staticFriction";
    static const char* ATTR_DYNAMIC_FRICTION                        = "dynamicFriction";
    static const char* ATTR_PHYSICS_SHAPES                          = "physicsShapes";
    static const char* ATTR_OVERRIDE_GLOBAL_ITERATION_COUNT         = "overrideGlobalIterationCount";
    static const char* ATTR_POSITION_ITERATION_COUNT                = "positionIterationCount";
    static const char* ATTR_VELOCITY_ITERATION_COUNT                = "velocityIterationCount";
    static const char* ATTR_CONTACT_SHELL_OVERRIDE                  = "contactShellOverride";
    static const char* ATTR_CONTACT_SHELL_DEPTH                     = "contactShellDepth";
    static const char* ATTR_CONTACT_SHELL_OFFSET                    = "contactShellOffset";
    static const char* ATTR_SLEEP_THRESHOLDS_OVERRIDE               = "sleepThesholdsOverride"; // Missing 'r' comes from a typo in attribute name (PhysX plugin)
    static const char* ATTR_SLEEP_ENERGY_THRESHOLD                  = "sleepEnergyThreshold";
    static const char* ATTR_LINEAR_DAMPING                          = "linearDamping";
    static const char* ATTR_ANGULAR_DAMPING                         = "angularDamping";
    static const char* ATTR_CENTER_OF_MASS_MODE                     = "centerOfMassMode";
    static const char* ATTR_CENTER_OF_MASS_OVERRIDE                 = "centerOfMassOverride";
    static const char* ATTR_CENTER_OF_MASS_OVERRIDE_X               = "centerOfMassOverrideX";
    static const char* ATTR_CENTER_OF_MASS_OVERRIDE_Y               = "centerOfMassOverrideY";
    static const char* ATTR_CENTER_OF_MASS_OVERRIDE_Z               = "centerOfMassOverrideZ";
    static const char* ATTR_INITIAL_POSITION                        = "initialPosition";
    static const char* ATTR_INITIAL_POSITION_X                      = "initialPositionX";
    static const char* ATTR_INITIAL_POSITION_Y                      = "initialPositionY";
    static const char* ATTR_INITIAL_POSITION_Z                      = "initialPositionZ";
    static const char* ATTR_INITIAL_ORIENTATION                     = "initialOrientation";
    static const char* ATTR_INITIAL_ORIENTATION_X                   = "initialOrientationX";
    static const char* ATTR_INITIAL_ORIENTATION_Y                   = "initialOrientationY";
    static const char* ATTR_INITIAL_ORIENTATION_Z                   = "initialOrientationZ";
    static const char* ATTR_INITIAL_VELOCITY                        = "initialVelocity";
    static const char* ATTR_INITIAL_VELOCITY_X                      = "initialVelocityX";
    static const char* ATTR_INITIAL_VELOCITY_Y                      = "initialVelocityY";
    static const char* ATTR_INITIAL_VELOCITY_Z                      = "initialVelocityZ";
    static const char* ATTR_INITIAL_SPIN                            = "initialSpin";
    static const char* ATTR_INITIAL_SPIN_X                          = "initialSpinX";
    static const char* ATTR_INITIAL_SPIN_Y                          = "initialSpinY";
    static const char* ATTR_INITIAL_SPIN_Z                          = "initialSpinZ";
    static const char* ATTR_ENABLE_CCD                              = "enableCCD";
    static const char* ATTR_CCD_MOTION_THRESHOLD                    = "CCDMotionThreshold";
    static const char* ATTR_HIDDEN_IN_OUTLINER                      = "hiddenInOutliner";
    static const char* ATTR_WIRE_COLOR_RGB                          = "wireColorRGB";
    static const char* ATTR_SHAPE_TYPE                              = "shapeType";
    static const char* ATTR_SIZE                                    = "size";
    static const char* ATTR_RADIUS                                  = "radius";
    static const char* ATTR_POINT_1                                 = "point1";
    static const char* ATTR_POINT_2                                 = "point2";
    static const char* ATTR_HEIGHT                                  = "height";
    static const char* ATTR_BEST_FIT                                = "bestFit";
    static const char* ATTR_OUT_PHYSICS_SHAPE                       = "outPhysicsShape";
    static const char* ATTR_CONNECT_TO_CLOTH_SPHERE                 = "connectToClothSphere";
    static const char* ATTR_INFLATE                                 = "inflate";
    static const char* ATTR_BOUNDING_BOX_SIZE                       = "boundingBoxSize";
    static const char* ATTR_USE_MASS_OR_DENSITY                     = "useMassOrDensity";
    static const char* ATTR_BOUNDING_BOX_MIN                        = "boundingBoxMin";
    static const char* ATTR_BOUNDING_BOX_MAX                        = "boundingBoxMax";
    static const char* ATTR_MOTION_TWIST                            = "motionTwist";
    static const char* ATTR_MOTION_SWING_Y                          = "motionSwingY";
    static const char* ATTR_MOTION_SWING_Z                          = "motionSwingZ";
    static const char* ATTR_TWIST_LOW_LIMIT_VALUE                   = "twistLowLimitValue";
    static const char* ATTR_TWIST_HIGH_LIMIT_VALUE                  = "twistHighLimitValue";
    static const char* ATTR_SWING_1_LIMIT_VALUE                     = "swing1LimitValue";
    static const char* ATTR_SWING_2_LIMIT_VALUE                     = "swing2LimitValue";
    static const char* ATTR_MOTION_X                                = "motionX";
    static const char* ATTR_MOTION_Y                                = "motionY";
    static const char* ATTR_MOTION_Z                                = "motionZ";
    static const char* ATTR_DRIVE_SPRING_X                          = "driveSpringX";
    static const char* ATTR_DRIVE_SPRING_Y                          = "driveSpringY";
    static const char* ATTR_DRIVE_SPRING_Z                          = "driveSpringZ";
    static const char* ATTR_DRIVE_DAMPING_X                         = "driveDampingX";
    static const char* ATTR_DRIVE_DAMPING_Y                         = "driveDampingY";
    static const char* ATTR_DRIVE_DAMPING_Z                         = "driveDampingZ";
    static const char* ATTR_DRIVE_SPRING_TWIST                      = "driveSpringTwist";
    static const char* ATTR_DRIVE_SPRING_SWING                      = "driveSpringSwing";
    static const char* ATTR_DRIVE_DAMPING_TWIST                     = "driveDampingTwist";
    static const char* ATTR_DRIVE_DAMPING_SWING                     = "driveDampingSwing";
    static const char* ATTR_GOAL_SPACE                              = "goalSpace";
    static const char* ATTR_GOAL_POSITION                           = "goalPosition";
    static const char* ATTR_GOAL_POSITION_X                         = "goalPositionX";
    static const char* ATTR_GOAL_POSITION_Y                         = "goalPositionY";
    static const char* ATTR_GOAL_POSITION_Z                         = "goalPositionZ";
    static const char* ATTR_GOAL_ORIENTATION                        = "goalOrientation";
    static const char* ATTR_GOAL_ORIENTATION_X                      = "goalOrientationX";
    static const char* ATTR_GOAL_ORIENTATION_Y                      = "goalOrientationY";
    static const char* ATTR_GOAL_ORIENTATION_Z                      = "goalOrientationZ";
    static const char* ATTR_GRAVITY                                 = "gravity";
    static const char* ATTR_GRAVITY_MAGNITUDE                       = "gravityMagnitude";
    static const char* ATTR_GRAVITY_DIRECTION                       = "gravityDirection";
    static const char* SIMULATION_TYPE_STATIC                       = "Static";
    static const char* SIMULATION_TYPE_KINEMATIC                    = "Kinematic";
    static const char* SIMULATION_TYPE_DYNAMIC                      = "Dynamic";
    static const char* OVERRIDE_MASS_OR_DENSITY_DISABLED            = "Disabled";
    static const char* OVERRIDE_MASS_OR_DENSITY_MASS                = "Mass";
    static const char* OVERRIDE_MASS_OR_DENSITY_DENSITY             = "Density";
    static const char* CENTER_OF_MASS_MODE_CALCULATE_FROM_SHAPES    = "Calculate From Shapes";
    static const char* CENTER_OF_MASS_MODE_MANUAL_OVERRIDE          = "Manual Override";
    static const char* SHAPE_TYPE_BOX                               = "Box";
    static const char* SHAPE_TYPE_SPHERE                            = "Sphere";
    static const char* SHAPE_TYPE_CAPSULE                           = "Capsule";
    static const char* SHAPE_TYPE_CONVEX_HULL                       = "Convex Hull";
    static const char* SHAPE_TYPE_TRIANGLE_MESH                     = "Triangle Mesh";
    static const char* SHAPE_TYPE_CLOTH_SPHERES                     = "ClothSpheres";
    static const char* USE_MASS_OR_DENSITY_MASS                     = "mass";
    static const char* USE_MASS_OR_DENSITY_DENSITY                  = "density";
    static const char* LOCKED                                       = "locked";
    static const char* LIMITED                                      = "limited";
    static const char* FREE                                         = "free";
    static const char* CENTERED                                     = "Centered";
    static const char* TARGET_ORIGIN                                = "Target Origin";
    static const String LOCAL_POSE                                  = "localPose";
    static const String GROUND_PLANE_NAME                           = "groundPlane";
    static const String ATTR_USE_GROUND_PLANE                       = "useGroundPlane";
    static const String ATTR_GROUND_PLANE_POSITION                  = "groundPlanePosition";

	static const char* ATTR_ACTIVE									= "active";
	static const char* ATTR_COLLISION_SHAPE							= "collision_shape";
	static const char* ATTR_COLLISION_EXPORT_NODE					= "export_node";
	
    /** Constants for light probes. */
    static const char* ATTR_LIGHT_PROBE                             = "light_probe";
    static const String CSW_ELEMENT_INSTANCE_LIGHT_PROBE            = "instance_light_probe";
    static const String CSW_ELEMENT_LIGHT_PROBE                     = "light_probe";
    static const String CSW_ELEMENT_LIBRARY_LIGHT_PROBES            = "library_light_probes";

    /** Shader constants */
    static const char* COLLADA_FX_SHADER                            = "colladafxShader";
    static const char* COLLADA_FX_PASSES                            = "colladafxPasses";

	/** ShaderFX constants */
	static const String SHADERFX_SHADER								= "ShaderfxShader";
	static const String SHADERFX									= "shaderfx";
	static const String SHADERFX_ATTRIBUTE							= "attribute";
	static const String SHADERFX_TRUE								= "true";
	static const String SHADERFX_FALSE								= "false";
	static const String PARAM_TYPE_BOOL								= "bool";
	static const String PARAM_TYPE_BYTE								= "byte";
	static const String PARAM_TYPE_CHAR								= "char";
	static const String PARAM_TYPE_SHORT							= "short";
	static const String PARAM_TYPE_SHORT2							= "short2";
	static const String PARAM_TYPE_SHORT3							= "short3";
	static const String PARAM_TYPE_LONG								= "long";
	static const String PARAM_TYPE_LONG2							= "long2";
	static const String PARAM_TYPE_LONG3							= "long3";
	static const String PARAM_TYPE_INT								= "int";
	static const String PARAM_TYPE_INT2								= "int2";
	static const String PARAM_TYPE_INT3								= "int3";
	static const String PARAM_TYPE_FLOAT							= "float";
	static const String PARAM_TYPE_FLOAT2							= "float2";
	static const String PARAM_TYPE_FLOAT3							= "float3";
	static const String PARAM_TYPE_DOUBLE							= "double";
	static const String PARAM_TYPE_DOUBLE2							= "double2";
	static const String PARAM_TYPE_DOUBLE3							= "double3";
	static const String PARAM_TYPE_DOUBLE4							= "double4";
	static const String PARAM_TYPE_ENUM								= "enum";
	static const String PARAM_TYPE_STRING							= "string";

    // COLLADA 1.4 Max-specific profile
    static const char* MAX_TARGET_CAMERA_PARAMETER                  = "target";
    static const char* MAX_ASPECTRATIO_LIGHT_PARAMETER              = "aspect_ratio";
    static const char* MAX_TARGET_LIGHT_PARAMETER                   = "target";
    static const char* MAX_DEFAULT_TARGET_DIST_LIGHT_PARAMETER      = "target_default_dist";
    static const char* MAX_OUTERCONE_LIGHT_PARAMETER                = "outer_cone";
    static const char* MAX_OVERSHOOT_LIGHT_PARAMETER                = "overshoot";
    static const char* MAX_SPECLEVEL_MATERIAL_PARAMETER             = "spec_level";
    static const char* MAX_DISPLACEMENT_MATERIAL_PARAMETER          = "displacement";
    static const char* MAX_EMISSIONLEVEL_MATERIAL_PARAMETER         = "emission_level";
    static const char* MAX_FACETED_MATERIAL_PARAMETER               = "faceted";
    static const char* MAX_FILTERCOLOR_MATERIAL_PARAMETER           = "filter_color";
    static const char* MAX_INDEXOFREFRACTION_MATERIAL_PARAMETER     = "index_of_refraction";
    static const char* MAX_USERPROPERTIES_NODE_PARAMETER            = "user_properties";
    static const char* MAX_WIREFRAME_MATERIAL_PARAMETER             = "wireframe";
    static const char* MAX_FACEMAP_MATERIAL_PARAMETER               = "face_map";
    static const char* MAX_AMOUNT_TEXTURE_PARAMETER                 = "amount";
    static const char* MAX_BUMP_INTERP_TEXTURE_PARAMETER            = "bumpInterp";
    static const char* MAX_CAMERA_TARGETDISTANCE_PARAMETER          = "target_distance";
    static const char* MAX_FRAMERATE_PARAMETER                      = "frame_rate";

}


#endif // __COLLADA_MAYA_SYNTAX_H__
