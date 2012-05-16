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


namespace COLLADAMaya
{
    
    // COLLADA NetAllied Systems
    static const char* TRANSLATOR_VENDOR                            = "NetAllied Systems GmbH";
    static const char* TRANSLATOR_VERSION                           = "1.3.0";
    static const char* USERNAME                                     = "USERNAME";
    static const char* USER                                         = "USER";

    // Names for the creation of the plug-in
    static const char* COLLADA_EXPORTER                             = "OpenCOLLADA exporter";
    static const char* COLLADA_IMPORTER                             = "OpenCOLLADA importer";
    static const char* COLLADA_DOCUMENT                             = "colladaDocument";
    static const String AUTHORING_TOOL_NAME                         = "OpenCOLLADA";

    /** Profile specific extra attribute parameters. */
    static const char* PROFILE_COLLADA                              = "COLLADA";
    static const char* PROFILE_MAYA                                 = "OpenCOLLADAMaya";
    static const char* PROFILE_MAX                                  = "OpenCOLLADA3dsMax";

    /** Extra technique parameters. */
    static const String PARAMETER_MAYA_ID                           = "originalMayaNodeId";
    static const String PARAMETER_DOUBLE_SIDED                      = "double_sided";

    /** Empty strings. */
    static const String EMPTY_STRING                                = "";
    static const char* EMPTY_CSTRING                                = "";

    /** The unique name for the visual scene node on export. */
    static const String VISUAL_SCENE_NODE_ID                        = "VisualSceneNode";

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
    static char*  MEL_EXPORT_OPTS                                   = "openColladaExporterOpts";
    static char*  MEL_IMPORT_OPTS                                   = "openColladaImporterOpts";

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

    /** Shader constants */
    static const char* COLLADA_FX_SHADER                            = "colladafxShader";
    static const char* COLLADA_FX_PASSES                            = "colladafxPasses";
    
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
