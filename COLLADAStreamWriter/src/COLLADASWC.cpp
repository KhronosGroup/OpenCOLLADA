/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Licensed under the MIT Open Source License, for details 
    please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#include "COLLADASWC.h"

namespace COLLADA
{

    const String CSWC::EMPTY_STRING = "";


    const String CSWC::XML_START_ELEMENT = "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
    const String CSWC::COLLADA_NAMESPACE = "http://www.collada.org/2005/11/COLLADASchema";
    const String CSWC::COLLADA_VERSION = "1.4.1";


    const String CSWC::COLLADA_ELEMENT_ACCESSOR = "accessor";
    const String CSWC::COLLADA_ELEMENT_AMBIENT = "ambient";
    const String CSWC::COLLADA_ELEMENT_ANIMATION = "animation";
    const String CSWC::COLLADA_ELEMENT_ANIMATION_CLIP = "animation_clip";
    const String CSWC::COLLADA_ELEMENT_ASSET = "asset";
    const String CSWC::COLLADA_ELEMENT_AUTHOR = "author";
    const String CSWC::COLLADA_ELEMENT_AUTHORING_TOOL = "authoring_tool";
    const String CSWC::COLLADA_ELEMENT_BLINN = "blinn";
    const String CSWC::COLLADA_ELEMENT_BIND_MATERIAL = "bind_material";
    const String CSWC::COLLADA_ELEMENT_BIND_SHAPE_MATRIX = "bind_shape_matrix";
    const String CSWC::COLLADA_ELEMENT_CHANNEL = "channel";
    const String CSWC::COLLADA_ELEMENT_COMMENTS = "comments";
    const String CSWC::COLLADA_ELEMENT_CONSTANT = "constant";
    const String CSWC::COLLADA_ELEMENT_CONTRIBUTOR = "contributor";
    const String CSWC::COLLADA_ELEMENT_CONTROLLER = "controller";
    const String CSWC::COLLADA_ELEMENT_COPYRIGHT = "copyright";
    const String CSWC::COLLADA_ELEMENT_CREATED = "created";
    const String CSWC::COLLADA_ELEMENT_COLLADA = "COLLADA";
    const String CSWC::COLLADA_ELEMENT_COLOR = "color";
    const String CSWC::COLLADA_ELEMENT_DIFFUSE = "diffuse";
    const String CSWC::COLLADA_ELEMENT_EFFECT = "effect";
    const String CSWC::COLLADA_ELEMENT_EMISSION = "emission";
    const String CSWC::COLLADA_ELEMENT_EXTRA = "extra";
    const String CSWC::COLLADA_ELEMENT_FLOAT = "float";
    const String CSWC::COLLADA_ELEMENT_FLOAT_ARRAY = "float_array";
    const String CSWC::COLLADA_ELEMENT_FORMAT = "format";
    const String CSWC::COLLADA_ELEMENT_GEOMETRY = "geometry";
    const String CSWC::COLLADA_ELEMENT_H = "h";
    const String CSWC::COLLADA_ELEMENT_IMAGE = "image";
    const String CSWC::COLLADA_ELEMENT_INIT_FROM = "init_from";
    const String CSWC::COLLADA_ELEMENT_INPUT = "input";
    const String CSWC::COLLADA_ELEMENT_INSTANCE_ANIMATION = "instance_animation";
    const String CSWC::COLLADA_ELEMENT_INSTANCE_CONTROLLER = "instance_controller";
    const String CSWC::COLLADA_ELEMENT_INSTANCE_EFFECT = "instance_effect";
    const String CSWC::COLLADA_ELEMENT_INSTANCE_GEOMETRY = "instance_geometry";
    const String CSWC::COLLADA_ELEMENT_INSTANCE_MATERIAL = "instance_material";
    const String CSWC::COLLADA_ELEMENT_INSTANCE_VISUAL_SCENE = "instance_visual_scene";
    const String CSWC::COLLADA_ELEMENT_JOINTS = "joints";
    const String CSWC::COLLADA_ELEMENT_KEYWORDS = "keywords";
    const String CSWC::COLLADA_ELEMENT_LAMBERT = "lambert";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_ANIMATIONS = "library_animations";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_ANIMATION_CLIPS = "library_animation_clips";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_CONTROLLERS = "library_controllers";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_EFFECTS = "library_effects";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_GEOMETRIES = "library_geometries";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_IMAGES = "library_images";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_MATERIALS = "library_materials";
    const String CSWC::COLLADA_ELEMENT_LIBRARY_VISUAL_SCENES = "library_visual_scenes";
    const String CSWC::COLLADA_ELEMENT_MAGFILTER = "magfilter";
    const String CSWC::COLLADA_ELEMENT_MATERIAL = "material";
    const String CSWC::COLLADA_ELEMENT_MATRIX = "matrix";
    const String CSWC::COLLADA_ELEMENT_MESH = "mesh";
    const String CSWC::COLLADA_ELEMENT_MINFILTER = "minfilter";
    const String CSWC::COLLADA_ELEMENT_MIPFILTER = "mipfilter";
    const String CSWC::COLLADA_ELEMENT_MODIFIED = "modified";
    const String CSWC::COLLADA_ELEMENT_NAME_ARRAY = "Name_array";
    const String CSWC::COLLADA_ELEMENT_NEWPARAM = "newparam";
    const String CSWC::COLLADA_ELEMENT_NODE = "node";
    const String CSWC::COLLADA_ELEMENT_P = "p";
    const String CSWC::COLLADA_ELEMENT_PARAM = "param";
    const String CSWC::COLLADA_ELEMENT_PH = "ph";
    const String CSWC::COLLADA_ELEMENT_PHONG = "phong";
    const String CSWC::COLLADA_ELEMENT_POLYLIST = "polylist";
    const String CSWC::COLLADA_ELEMENT_POLYGONS = "polygons";
    const String CSWC::COLLADA_ELEMENT_PROFILE_COMMON = "profile_COMMON";
    const String CSWC::COLLADA_ELEMENT_REFLECTIVE = "reflective";
    const String CSWC::COLLADA_ELEMENT_REFLECTIVITY = "reflectivity";
    const String CSWC::COLLADA_ELEMENT_REVISION = "revision";
    const String CSWC::COLLADA_ELEMENT_ROTATE = "rotate";
    const String CSWC::COLLADA_ELEMENT_SAMPLER = "sampler";
    const String CSWC::COLLADA_ELEMENT_SAMPLER2D = "sampler2D";
    const String CSWC::COLLADA_ELEMENT_SCALE = "scale";
    const String CSWC::COLLADA_ELEMENT_SCENE = "scene";
    const String CSWC::COLLADA_ELEMENT_SHININESS = "shininess";
    const String CSWC::COLLADA_ELEMENT_SKEW = "skew";
    const String CSWC::COLLADA_ELEMENT_SKIN = "skin";
    const String CSWC::COLLADA_ELEMENT_SPECULAR = "specular";
    const String CSWC::COLLADA_ELEMENT_SOURCE = "source";
    const String CSWC::COLLADA_ELEMENT_SOURCE_DATA = "source_data";
    const String CSWC::COLLADA_ELEMENT_SUBJECT = "subject";
    const String CSWC::COLLADA_ELEMENT_SURFACE = "surface";
    const String CSWC::COLLADA_ELEMENT_TECHNIQUE = "technique";
    const String CSWC::COLLADA_ELEMENT_TECHNIQUE_COMMON = "technique_common";
    const String CSWC::COLLADA_ELEMENT_TEXTURE = "texture";
    const String CSWC::COLLADA_ELEMENT_TITLE = "title";
    const String CSWC::COLLADA_ELEMENT_TRANSLATE = "translate";
    const String CSWC::COLLADA_ELEMENT_TRANSPARENCY = "transparency";
    const String CSWC::COLLADA_ELEMENT_TRANSPARENT = "transparent";
    const String CSWC::COLLADA_ELEMENT_TRIANGLES = "triangles";
    const String CSWC::COLLADA_ELEMENT_UNIT = "unit";
    const String CSWC::COLLADA_ELEMENT_UP_AXIS = "up_axis";
    const String CSWC::COLLADA_ELEMENT_VCOUNT = "vcount";
    const String CSWC::COLLADA_ELEMENT_VERTEX_WEIGHTS = "vertex_weights";
    const String CSWC::COLLADA_ELEMENT_VERTICES = "vertices";
    const String CSWC::COLLADA_ELEMENT_VISUAL_SCENE = "visual_scene";
    const String CSWC::COLLADA_ELEMENT_WRAP_S = "wrap_s";
    const String CSWC::COLLADA_ELEMENT_WRAP_T = "wrap_t";
    const String CSWC::COLLADA_ELEMENT_WRAP_P = "wrap_p";


    const String CSWC::COLLADA_ATTRIBUTE_COUNT = "count";
    const String CSWC::COLLADA_ATTRIBUTE_END = "end";
    const String CSWC::COLLADA_ATTRIBUTE_ID = "id";
    const String CSWC::COLLADA_ATTRIBUTE_MATERIAL = "material";
    const String CSWC::COLLADA_ATTRIBUTE_METER = "meter";
    const String CSWC::COLLADA_ATTRIBUTE_NAME = "name";
    const String CSWC::COLLADA_ATTRIBUTE_OFFSET = "offset";
    const String CSWC::COLLADA_ATTRIBUTE_OPAQUE = "opaque";
    const String CSWC::COLLADA_ATTRIBUTE_PROFILE = "profile";
    const String CSWC::COLLADA_ATTRIBUTE_SEMANTIC = "semantic";
    const String CSWC::COLLADA_ATTRIBUTE_SET = "set";
    const String CSWC::COLLADA_ATTRIBUTE_SID = "sid";
    const String CSWC::COLLADA_ATTRIBUTE_SOURCE = "source";
    const String CSWC::COLLADA_ATTRIBUTE_START = "start";
    const String CSWC::COLLADA_ATTRIBUTE_STRIDE = "stride";
    const String CSWC::COLLADA_ATTRIBUTE_SYMBOL = "symbol";
    const String CSWC::COLLADA_ATTRIBUTE_TARGET = "target";
    const String CSWC::COLLADA_ATTRIBUTE_TEXCOORD = "texcoord";
    const String CSWC::COLLADA_ATTRIBUTE_TEXTURE = "texture";
    const String CSWC::COLLADA_ATTRIBUTE_TYPE = "type";
    const String CSWC::COLLADA_ATTRIBUTE_URL = "url";
    const String CSWC::COLLADA_ATTRIBUTE_VERSION = "version";
    const String CSWC::COLLADA_ATTRIBUTE_XMLNS = "xmlns";


    const String CSWC::COLLADA_SEMANTIC_BINDMATRIX = "INV_BIND_MATRIX";
    const String CSWC::COLLADA_SEMANTIC_COLOR = "COLOR";
    const String CSWC::COLLADA_SEMANTIC_CONTINUITY = "CONTINUITY";
    const String CSWC::COLLADA_SEMANTIC_INTERPOLATION = "INTERPOLATION";
    const String CSWC::COLLADA_SEMANTIC_INPUT = "INPUT";
    const String CSWC::COLLADA_SEMANTIC_IN_TANGENT = "IN_TANGENT";
    const String CSWC::COLLADA_SEMANTIC_JOINT = "JOINT";
    const String CSWC::COLLADA_SEMANTIC_LINEAR_STEPS = "LINEAR_STEPS";
    const String CSWC::COLLADA_SEMANTIC_NORMAL = "NORMAL";
    const String CSWC::COLLADA_SEMANTIC_OUTPUT = "OUTPUT";
    const String CSWC::COLLADA_SEMANTIC_OUT_TANGENT = "OUT_TANGENT";
    const String CSWC::COLLADA_SEMANTIC_POSITION = "POSITION";
    const String CSWC::COLLADA_SEMANTIC_TEXCOORD = "TEXCOORD";
    const String CSWC::COLLADA_SEMANTIC_VERTEX = "VERTEX";
    const String CSWC::COLLADA_SEMANTIC_WEIGHT = "WEIGHT";

    const String CSWC::COLLADA_TEXT_X_UP = "X_UP";
    const String CSWC::COLLADA_TEXT_Y_UP = "Y_UP";
    const String CSWC::COLLADA_TEXT_Z_UP = "Z_UP";


    const String CSWC::COLLADA_NODE_TYPE_JOINT = "JOINT";
    const String CSWC::COLLADA_NODE_TYPE_NODE = "NODE";

    const String CSWC::COLLADA_PARAM_TYPE_FLOAT = "float";
    const String CSWC::COLLADA_PARAM_TYPE_FLOAT4x4 = "float4x4";
    const String CSWC::COLLADA_PARAM_TYPE_NAME = "name";


    const String CSWC::COLLADA_SAMPLER_FILTER_LINEAR = "LINEAR";
    const String CSWC::COLLADA_SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR = "LINEAR_MIPMAP_LINEAR" ;
    const String CSWC::COLLADA_SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST = "LINEAR_MIPMAP_NEAREST";
    const String CSWC::COLLADA_SAMPLER_FILTER_NEAREST = "NEAREST";
    const String CSWC::COLLADA_SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST = "NEAREST_MIPMAP_NEAREST";
    const String CSWC::COLLADA_SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR = "NEAREST_MIPMAP_LINEAR";
    const String CSWC::COLLADA_SAMPLER_FILTER_NONE = "NONE";

    // texture wrap modes
    const String CSWC::COLLADA_TEXTURE_WRAP_NONE = "NONE";
    const String CSWC::COLLADA_TEXTURE_WRAP_WRAP = "WRAP";
    const String CSWC::COLLADA_TEXTURE_WRAP_MIRROR = "MIRROR";
    const String CSWC::COLLADA_TEXTURE_WRAP_CLAMP = "CLAMP";
    const String CSWC::COLLADA_TEXTURE_WRAP_BORDER = "BORDER";
    const String CSWC::COLLADA_TEXTURE_WRAP_UNKNOWN = "UNKNOWN";

    const String CSWC::COLLADA_SURFACE_TYPE_UNTYPED = "UNTYPED";
    const String CSWC::COLLADA_SURFACE_TYPE_1D = "1D";
    const String CSWC::COLLADA_SURFACE_TYPE_2D = "2D";
    const String CSWC::COLLADA_SURFACE_TYPE_3D = "3D";
    const String CSWC::COLLADA_SURFACE_TYPE_RECT = "RECT";
    const String CSWC::COLLADA_SURFACE_TYPE_CUBE = "CUBE";
    const String CSWC::COLLADA_SURFACE_TYPE_DEPTH = "DEPTH";


    const String CSWC::COLLADA_OPAQUE_TYPE_A_ONE = "A_ONE";
    const String CSWC::COLLADA_OPAQUE_TYPE_RGB_ONE = "RGB_ONE";
    const String CSWC::COLLADA_OPAQUE_TYPE_RGB_ZERO = "RGB_ZERO";
    const String CSWC::COLLADA_OPAQUE_TYPE_A_ZERO = "A_ZERO";


}
