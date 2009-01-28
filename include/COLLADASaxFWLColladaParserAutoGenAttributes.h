/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGENATTRIBUTES_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGENATTRIBUTES_H__


#include "GeneratedSaxParserTypes.h"


namespace COLLADASaxFWL
{


typedef GeneratedSaxParser::StringHash StringHash;
typedef GeneratedSaxParser::ParserChar ParserChar;
typedef GeneratedSaxParser::ParserAttributes ParserAttributes;


const StringHash HASH_ELEMENT_COLLADA = 138479041;
extern const char* NAME_ELEMENT_COLLADA;
const StringHash HASH_ATTRIBUTE_VERSION = 214540334;
extern const char* NAME_ATTRIBUTE_VERSION;
const StringHash HASH_ATTRIBUTE_BASE = 428181;
extern const char* NAME_ATTRIBUTE_BASE;
struct COLLADA__AttributeData
{
    static const COLLADA__AttributeData DEFAULT;

    const ParserChar* version;
    const ParserChar* base;
};

const StringHash HASH_ELEMENT_ASSET = 21558580;
extern const char* NAME_ELEMENT_ASSET;
const StringHash HASH_ELEMENT_COLLADA__ASSET = 21558580;
extern const char* NAME_ELEMENT_COLLADA__ASSET;

const StringHash HASH_ELEMENT_CONTRIBUTOR = 187503730;
extern const char* NAME_ELEMENT_CONTRIBUTOR;
const StringHash HASH_ELEMENT_ASSET__CONTRIBUTOR = 187503730;
extern const char* NAME_ELEMENT_ASSET__CONTRIBUTOR;

const StringHash HASH_ELEMENT_AUTHOR = 104615810;
extern const char* NAME_ELEMENT_AUTHOR;
const StringHash HASH_ELEMENT_CONTRIBUTOR__AUTHOR = 104615810;
extern const char* NAME_ELEMENT_CONTRIBUTOR__AUTHOR;

const StringHash HASH_ELEMENT_AUTHORING_TOOL = 144260236;
extern const char* NAME_ELEMENT_AUTHORING_TOOL;
const StringHash HASH_ELEMENT_CONTRIBUTOR__AUTHORING_TOOL = 144260236;
extern const char* NAME_ELEMENT_CONTRIBUTOR__AUTHORING_TOOL;

const StringHash HASH_ELEMENT_COMMENTS = 115565443;
extern const char* NAME_ELEMENT_COMMENTS;
const StringHash HASH_ELEMENT_CONTRIBUTOR__COMMENTS = 115565443;
extern const char* NAME_ELEMENT_CONTRIBUTOR__COMMENTS;

const StringHash HASH_ELEMENT_COPYRIGHT = 168205972;
extern const char* NAME_ELEMENT_COPYRIGHT;
const StringHash HASH_ELEMENT_CONTRIBUTOR__COPYRIGHT = 168205972;
extern const char* NAME_ELEMENT_CONTRIBUTOR__COPYRIGHT;

const StringHash HASH_ELEMENT_SOURCE_DATA = 134662689;
extern const char* NAME_ELEMENT_SOURCE_DATA;
const StringHash HASH_ELEMENT_CONTRIBUTOR__SOURCE_DATA = 134662689;
extern const char* NAME_ELEMENT_CONTRIBUTOR__SOURCE_DATA;

const StringHash HASH_ELEMENT_CREATED = 1517924;
extern const char* NAME_ELEMENT_CREATED;
const StringHash HASH_ELEMENT_ASSET__CREATED = 1517924;
extern const char* NAME_ELEMENT_ASSET__CREATED;

const StringHash HASH_ELEMENT_KEYWORDS = 113792515;
extern const char* NAME_ELEMENT_KEYWORDS;
const StringHash HASH_ELEMENT_ASSET__KEYWORDS = 113792515;
extern const char* NAME_ELEMENT_ASSET__KEYWORDS;

const StringHash HASH_ELEMENT_MODIFIED = 208007444;
extern const char* NAME_ELEMENT_MODIFIED;
const StringHash HASH_ELEMENT_ASSET__MODIFIED = 208007444;
extern const char* NAME_ELEMENT_ASSET__MODIFIED;

const StringHash HASH_ELEMENT_REVISION = 85631614;
extern const char* NAME_ELEMENT_REVISION;
const StringHash HASH_ELEMENT_ASSET__REVISION = 85631614;
extern const char* NAME_ELEMENT_ASSET__REVISION;

const StringHash HASH_ELEMENT_SUBJECT = 2467908;
extern const char* NAME_ELEMENT_SUBJECT;
const StringHash HASH_ELEMENT_ASSET__SUBJECT = 2467908;
extern const char* NAME_ELEMENT_ASSET__SUBJECT;

const StringHash HASH_ELEMENT_TITLE = 65116037;
extern const char* NAME_ELEMENT_TITLE;
const StringHash HASH_ELEMENT_ASSET__TITLE = 65116037;
extern const char* NAME_ELEMENT_ASSET__TITLE;

const StringHash HASH_ELEMENT_UNIT = 171847364;
extern const char* NAME_ELEMENT_UNIT;
const StringHash HASH_ELEMENT_ASSET__UNIT = 171847364;
extern const char* NAME_ELEMENT_ASSET__UNIT;
const StringHash HASH_ATTRIBUTE_METER = 7588546;
extern const char* NAME_ATTRIBUTE_METER;
const StringHash HASH_ATTRIBUTE_NAME = 477237;
extern const char* NAME_ATTRIBUTE_NAME;
struct unit__AttributeData
{
    static const unit__AttributeData DEFAULT;

    double meter;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_UP_AXIS = 114896611;
extern const char* NAME_ELEMENT_UP_AXIS;
const StringHash HASH_ELEMENT_ASSET__UP_AXIS = 114896611;
extern const char* NAME_ELEMENT_ASSET__UP_AXIS;

const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS = 257283875;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_ANIMATIONS = 257283875;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_ANIMATIONS;
const StringHash HASH_ATTRIBUTE_ID = 1780;
extern const char* NAME_ATTRIBUTE_ID;
struct library_animations__AttributeData
{
    static const library_animations__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__ASSET = 39388324;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__ASSET;

const StringHash HASH_ELEMENT_ANIMATION = 56293822;
extern const char* NAME_ELEMENT_ANIMATION;
const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__ANIMATION = 56293822;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__ANIMATION;
struct animation__AttributeData
{
    static const animation__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_ANIMATION__ASSET = 148121732;
extern const char* NAME_ELEMENT_ANIMATION__ASSET;

const StringHash HASH_ELEMENT_SOURCE = 242146325;
extern const char* NAME_ELEMENT_SOURCE;
const StringHash HASH_ELEMENT_ANIMATION__SOURCE = 242146325;
extern const char* NAME_ELEMENT_ANIMATION__SOURCE;
struct animation__source__AttributeData
{
    static const animation__source__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_SOURCE__ASSET = 255074340;
extern const char* NAME_ELEMENT_SOURCE__ASSET;

const StringHash HASH_ELEMENT_IDREF_ARRAY = 84510713;
extern const char* NAME_ELEMENT_IDREF_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__IDREF_ARRAY = 84510713;
extern const char* NAME_ELEMENT_SOURCE__IDREF_ARRAY;
const StringHash HASH_ATTRIBUTE_COUNT = 6974548;
extern const char* NAME_ATTRIBUTE_COUNT;
struct IDREF_array__AttributeData
{
    static const IDREF_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    unsigned long long count;
};

const StringHash HASH_ELEMENT_NAME_ARRAY = 95291433;
extern const char* NAME_ELEMENT_NAME_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__NAME_ARRAY = 95291433;
extern const char* NAME_ELEMENT_SOURCE__NAME_ARRAY;
struct Name_array__AttributeData
{
    static const Name_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    unsigned long long count;
};

const StringHash HASH_ELEMENT_BOOL_ARRAY = 11257449;
extern const char* NAME_ELEMENT_BOOL_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__BOOL_ARRAY = 11257449;
extern const char* NAME_ELEMENT_SOURCE__BOOL_ARRAY;
struct bool_array__AttributeData
{
    static const bool_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    unsigned long long count;
};

const StringHash HASH_ELEMENT_FLOAT_ARRAY = 124331241;
extern const char* NAME_ELEMENT_FLOAT_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__FLOAT_ARRAY = 124331241;
extern const char* NAME_ELEMENT_SOURCE__FLOAT_ARRAY;
const StringHash HASH_ATTRIBUTE_DIGITS = 112189619;
extern const char* NAME_ATTRIBUTE_DIGITS;
const StringHash HASH_ATTRIBUTE_MAGNITUDE = 240175317;
extern const char* NAME_ATTRIBUTE_MAGNITUDE;
struct float_array__AttributeData
{
    static const float_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    unsigned long long count;
    int digits;
    int magnitude;
};

const StringHash HASH_ELEMENT_INT_ARRAY = 28814425;
extern const char* NAME_ELEMENT_INT_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__INT_ARRAY = 28814425;
extern const char* NAME_ELEMENT_SOURCE__INT_ARRAY;
const StringHash HASH_ATTRIBUTE_MININCLUSIVE = 259829893;
extern const char* NAME_ATTRIBUTE_MININCLUSIVE;
const StringHash HASH_ATTRIBUTE_MAXINCLUSIVE = 251940997;
extern const char* NAME_ATTRIBUTE_MAXINCLUSIVE;
struct int_array__AttributeData
{
    static const int_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    unsigned long long count;
    long minInclusive;
    long maxInclusive;
};

const StringHash HASH_ELEMENT_TECHNIQUE_COMMON = 73854190;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON;
const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE_COMMON = 73854190;
extern const char* NAME_ELEMENT_SOURCE__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ACCESSOR = 230035506;
extern const char* NAME_ELEMENT_ACCESSOR;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ACCESSOR = 230035506;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ACCESSOR;
const StringHash HASH_ATTRIBUTE_OFFSET = 123525572;
extern const char* NAME_ATTRIBUTE_OFFSET;
const StringHash HASH_ATTRIBUTE_SOURCE = 128370837;
extern const char* NAME_ATTRIBUTE_SOURCE;
const StringHash HASH_ATTRIBUTE_STRIDE = 128683941;
extern const char* NAME_ATTRIBUTE_STRIDE;
struct accessor__AttributeData
{
    static const accessor__AttributeData DEFAULT;

    unsigned long long count;
    unsigned long long offset;
    const ParserChar* source;
    unsigned long long stride;
};

const StringHash HASH_ELEMENT_PARAM = 246253965;
extern const char* NAME_ELEMENT_PARAM;
const StringHash HASH_ELEMENT_ACCESSOR__PARAM = 246253965;
extern const char* NAME_ELEMENT_ACCESSOR__PARAM;
const StringHash HASH_ATTRIBUTE_SID = 31220;
extern const char* NAME_ATTRIBUTE_SID;
const StringHash HASH_ATTRIBUTE_SEMANTIC = 205020515;
extern const char* NAME_ATTRIBUTE_SEMANTIC;
const StringHash HASH_ATTRIBUTE_TYPE = 508005;
extern const char* NAME_ATTRIBUTE_TYPE;
struct accessor__param__AttributeData
{
    static const accessor__param__AttributeData DEFAULT;

    const ParserChar* name;
    const ParserChar* sid;
    const ParserChar* semantic;
    const ParserChar* type;
};

const StringHash HASH_ELEMENT_TECHNIQUE = 1838725;
extern const char* NAME_ELEMENT_TECHNIQUE;
const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE = 1838725;
extern const char* NAME_ELEMENT_SOURCE__TECHNIQUE;
const StringHash HASH_ATTRIBUTE_PROFILE = 127258709;
extern const char* NAME_ATTRIBUTE_PROFILE;
struct source__technique__AttributeData
{
    static const source__technique__AttributeData DEFAULT;

    const ParserChar* profile;
};

const StringHash HASH_ELEMENT_SAMPLER = 101005858;
extern const char* NAME_ELEMENT_SAMPLER;
const StringHash HASH_ELEMENT_ANIMATION__SAMPLER = 101005858;
extern const char* NAME_ELEMENT_ANIMATION__SAMPLER;
struct sampler__AttributeData
{
    static const sampler__AttributeData DEFAULT;

    const ParserChar* id;
};

const StringHash HASH_ELEMENT_INPUT = 219774004;
extern const char* NAME_ELEMENT_INPUT;
const StringHash HASH_ELEMENT_SAMPLER__INPUT = 219774004;
extern const char* NAME_ELEMENT_SAMPLER__INPUT;
struct sampler__input__AttributeData
{
    static const sampler__input__AttributeData DEFAULT;

    const ParserChar* semantic;
    const ParserChar* source;
};

const StringHash HASH_ELEMENT_CHANNEL = 90643564;
extern const char* NAME_ELEMENT_CHANNEL;
const StringHash HASH_ELEMENT_ANIMATION__CHANNEL = 90643564;
extern const char* NAME_ELEMENT_ANIMATION__CHANNEL;
const StringHash HASH_ATTRIBUTE_TARGET = 128486852;
extern const char* NAME_ATTRIBUTE_TARGET;
struct channel__AttributeData
{
    static const channel__AttributeData DEFAULT;

    const ParserChar* source;
    const ParserChar* target;
};

const StringHash HASH_ELEMENT_ANIMATION__ANIMATION = 259028126;
extern const char* NAME_ELEMENT_ANIMATION__ANIMATION;

const StringHash HASH_ELEMENT_EXTRA = 147880641;
extern const char* NAME_ELEMENT_EXTRA;
const StringHash HASH_ELEMENT_ANIMATION__EXTRA = 147880641;
extern const char* NAME_ELEMENT_ANIMATION__EXTRA;
struct extra__AttributeData
{
    static const extra__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    const ParserChar* type;
};

const StringHash HASH_ELEMENT_EXTRA__ASSET = 60232116;
extern const char* NAME_ELEMENT_EXTRA__ASSET;

const StringHash HASH_ELEMENT_EXTRA__TECHNIQUE = 27831733;
extern const char* NAME_ELEMENT_EXTRA__TECHNIQUE;
typedef source__technique__AttributeData extra__technique__AttributeData;

const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__EXTRA = 39671521;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS = 95259907;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_ANIMATION_CLIPS = 95259907;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_ANIMATION_CLIPS;
struct library_animation_clips__AttributeData
{
    static const library_animation_clips__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__ASSET = 227259540;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__ASSET;

const StringHash HASH_ELEMENT_ANIMATION_CLIP = 18076080;
extern const char* NAME_ELEMENT_ANIMATION_CLIP;
const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__ANIMATION_CLIP = 18076080;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__ANIMATION_CLIP;
const StringHash HASH_ATTRIBUTE_START = 8038548;
extern const char* NAME_ATTRIBUTE_START;
const StringHash HASH_ATTRIBUTE_END = 27716;
extern const char* NAME_ATTRIBUTE_END;
struct animation_clip__AttributeData
{
    static const animation_clip__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    double start;
    double end;
};

const StringHash HASH_ELEMENT_ANIMATION_CLIP__ASSET = 20599188;
extern const char* NAME_ELEMENT_ANIMATION_CLIP__ASSET;

const StringHash HASH_ELEMENT_INSTANCE_ANIMATION = 155834222;
extern const char* NAME_ELEMENT_INSTANCE_ANIMATION;
const StringHash HASH_ELEMENT_ANIMATION_CLIP__INSTANCE_ANIMATION = 155834222;
extern const char* NAME_ELEMENT_ANIMATION_CLIP__INSTANCE_ANIMATION;
const StringHash HASH_ATTRIBUTE_URL = 31884;
extern const char* NAME_ATTRIBUTE_URL;
struct instance_animation__AttributeData
{
    static const instance_animation__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_ANIMATION__EXTRA = 249155953;
extern const char* NAME_ELEMENT_INSTANCE_ANIMATION__EXTRA;

const StringHash HASH_ELEMENT_ANIMATION_CLIP__EXTRA = 20841425;
extern const char* NAME_ELEMENT_ANIMATION_CLIP__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA = 227534545;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_CAMERAS = 203031923;
extern const char* NAME_ELEMENT_LIBRARY_CAMERAS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_CAMERAS = 203031923;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_CAMERAS;
struct library_cameras__AttributeData
{
    static const library_cameras__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__ASSET = 99285860;
extern const char* NAME_ELEMENT_LIBRARY_CAMERAS__ASSET;

const StringHash HASH_ELEMENT_CAMERA = 246617809;
extern const char* NAME_ELEMENT_CAMERA;
const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__CAMERA = 246617809;
extern const char* NAME_ELEMENT_LIBRARY_CAMERAS__CAMERA;
struct camera__AttributeData
{
    static const camera__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_CAMERA__ASSET = 249258452;
extern const char* NAME_ELEMENT_CAMERA__ASSET;

const StringHash HASH_ELEMENT_OPTICS = 240856643;
extern const char* NAME_ELEMENT_OPTICS;
const StringHash HASH_ELEMENT_CAMERA__OPTICS = 240856643;
extern const char* NAME_ELEMENT_CAMERA__OPTICS;

const StringHash HASH_ELEMENT_OPTICS__TECHNIQUE_COMMON = 170249678;
extern const char* NAME_ELEMENT_OPTICS__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ORTHOGRAPHIC = 163965699;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ORTHOGRAPHIC = 163965699;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ORTHOGRAPHIC;

const StringHash HASH_ELEMENT_XMAG = 45560535;
extern const char* NAME_ELEMENT_XMAG;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__XMAG = 45560535;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__XMAG;
struct xmag__AttributeData
{
    static const xmag__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_YMAG = 45564631;
extern const char* NAME_ELEMENT_YMAG;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__YMAG = 45564631;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__YMAG;
struct ymag__AttributeData
{
    static const ymag__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ASPECT_RATIO = 237192175;
extern const char* NAME_ELEMENT_ASPECT_RATIO;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO = 237192175;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO;
struct aspect_ratio__AttributeData
{
    static const aspect_ratio__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ZNEAR = 193810850;
extern const char* NAME_ELEMENT_ZNEAR;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZNEAR = 193810850;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ZNEAR;
struct znear__AttributeData
{
    static const znear__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ZFAR = 45665570;
extern const char* NAME_ELEMENT_ZFAR;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZFAR = 45665570;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ZFAR;
struct zfar__AttributeData
{
    static const zfar__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PERSPECTIVE = 216939461;
extern const char* NAME_ELEMENT_PERSPECTIVE;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__PERSPECTIVE = 216939461;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__PERSPECTIVE;

const StringHash HASH_ELEMENT_XFOV = 228234758;
extern const char* NAME_ELEMENT_XFOV;
const StringHash HASH_ELEMENT_PERSPECTIVE__XFOV = 228234758;
extern const char* NAME_ELEMENT_PERSPECTIVE__XFOV;
struct xfov__AttributeData
{
    static const xfov__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_YFOV = 228230662;
extern const char* NAME_ELEMENT_YFOV;
const StringHash HASH_ELEMENT_PERSPECTIVE__YFOV = 228230662;
extern const char* NAME_ELEMENT_PERSPECTIVE__YFOV;
struct yfov__AttributeData
{
    static const yfov__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PERSPECTIVE__ASPECT_RATIO = 26971343;
extern const char* NAME_ELEMENT_PERSPECTIVE__ASPECT_RATIO;

const StringHash HASH_ELEMENT_PERSPECTIVE__ZNEAR = 163110226;
extern const char* NAME_ELEMENT_PERSPECTIVE__ZNEAR;

const StringHash HASH_ELEMENT_PERSPECTIVE__ZFAR = 228292066;
extern const char* NAME_ELEMENT_PERSPECTIVE__ZFAR;

const StringHash HASH_ELEMENT_OPTICS__TECHNIQUE = 49813749;
extern const char* NAME_ELEMENT_OPTICS__TECHNIQUE;
typedef source__technique__AttributeData optics__technique__AttributeData;

const StringHash HASH_ELEMENT_OPTICS__EXTRA = 52822145;
extern const char* NAME_ELEMENT_OPTICS__EXTRA;

const StringHash HASH_ELEMENT_IMAGER = 232782882;
extern const char* NAME_ELEMENT_IMAGER;
const StringHash HASH_ELEMENT_CAMERA__IMAGER = 232782882;
extern const char* NAME_ELEMENT_CAMERA__IMAGER;

const StringHash HASH_ELEMENT_IMAGER__TECHNIQUE = 100816341;
extern const char* NAME_ELEMENT_IMAGER__TECHNIQUE;
typedef source__technique__AttributeData imager__technique__AttributeData;

const StringHash HASH_ELEMENT_IMAGER__EXTRA = 90908561;
extern const char* NAME_ELEMENT_IMAGER__EXTRA;

const StringHash HASH_ELEMENT_CAMERA__EXTRA = 249508753;
extern const char* NAME_ELEMENT_CAMERA__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__EXTRA = 99526945;
extern const char* NAME_ELEMENT_LIBRARY_CAMERAS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS = 113250531;
extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_CONTROLLERS = 113250531;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_CONTROLLERS;
struct library_controllers__AttributeData
{
    static const library_controllers__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__ASSET = 85243076;
extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__ASSET;

const StringHash HASH_ELEMENT_CONTROLLER = 199579458;
extern const char* NAME_ELEMENT_CONTROLLER;
const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__CONTROLLER = 199579458;
extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__CONTROLLER;
struct controller__AttributeData
{
    static const controller__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_CONTROLLER__ASSET = 236052500;
extern const char* NAME_ELEMENT_CONTROLLER__ASSET;

const StringHash HASH_ELEMENT_SKIN = 232920430;
extern const char* NAME_ELEMENT_SKIN;
const StringHash HASH_ELEMENT_CONTROLLER__SKIN = 232920430;
extern const char* NAME_ELEMENT_CONTROLLER__SKIN;
struct skin__AttributeData
{
    static const skin__AttributeData DEFAULT;

    const ParserChar* source;
};

const StringHash HASH_ELEMENT_BIND_SHAPE_MATRIX = 126147416;
extern const char* NAME_ELEMENT_BIND_SHAPE_MATRIX;
const StringHash HASH_ELEMENT_SKIN__BIND_SHAPE_MATRIX = 126147416;
extern const char* NAME_ELEMENT_SKIN__BIND_SHAPE_MATRIX;

const StringHash HASH_ELEMENT_SKIN__SOURCE = 21286085;
extern const char* NAME_ELEMENT_SKIN__SOURCE;
typedef animation__source__AttributeData skin__source__AttributeData;

const StringHash HASH_ELEMENT_JOINTS = 62390755;
extern const char* NAME_ELEMENT_JOINTS;
const StringHash HASH_ELEMENT_SKIN__JOINTS = 62390755;
extern const char* NAME_ELEMENT_SKIN__JOINTS;

const StringHash HASH_ELEMENT_JOINTS__INPUT = 104860612;
extern const char* NAME_ELEMENT_JOINTS__INPUT;
typedef sampler__input__AttributeData joints__input__AttributeData;

const StringHash HASH_ELEMENT_JOINTS__EXTRA = 104638337;
extern const char* NAME_ELEMENT_JOINTS__EXTRA;

const StringHash HASH_ELEMENT_VERTEX_WEIGHTS = 52511411;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS;
const StringHash HASH_ELEMENT_SKIN__VERTEX_WEIGHTS = 52511411;
extern const char* NAME_ELEMENT_SKIN__VERTEX_WEIGHTS;
struct vertex_weights__AttributeData
{
    static const vertex_weights__AttributeData DEFAULT;

    unsigned long long count;
};

const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__INPUT = 118429284;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__INPUT;
const StringHash HASH_ATTRIBUTE_SET = 31172;
extern const char* NAME_ATTRIBUTE_SET;
struct vertex_weights__input__AttributeData
{
    static const vertex_weights__input__AttributeData DEFAULT;

    unsigned long long offset;
    const ParserChar* semantic;
    const ParserChar* source;
    unsigned long long set;
};

const StringHash HASH_ELEMENT_VCOUNT = 64909860;
extern const char* NAME_ELEMENT_VCOUNT;
const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__VCOUNT = 64909860;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__VCOUNT;

const StringHash HASH_ELEMENT_V = 21079862;
extern const char* NAME_ELEMENT_V;
const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__V = 21079862;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__V;

const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__EXTRA = 118340129;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__EXTRA;

const StringHash HASH_ELEMENT_SKIN__EXTRA = 86432705;
extern const char* NAME_ELEMENT_SKIN__EXTRA;

const StringHash HASH_ELEMENT_MORPH = 237707448;
extern const char* NAME_ELEMENT_MORPH;
const StringHash HASH_ELEMENT_CONTROLLER__MORPH = 237707448;
extern const char* NAME_ELEMENT_CONTROLLER__MORPH;
const StringHash HASH_ATTRIBUTE_METHOD = 121417556;
extern const char* NAME_ATTRIBUTE_METHOD;
struct morph__AttributeData
{
    static const morph__AttributeData DEFAULT;

    const ParserChar* method;
    const ParserChar* source;
};

const StringHash HASH_ELEMENT_MORPH__SOURCE = 51357397;
extern const char* NAME_ELEMENT_MORPH__SOURCE;
typedef animation__source__AttributeData morph__source__AttributeData;

const StringHash HASH_ELEMENT_TARGETS = 203307155;
extern const char* NAME_ELEMENT_TARGETS;
const StringHash HASH_ELEMENT_MORPH__TARGETS = 203307155;
extern const char* NAME_ELEMENT_MORPH__TARGETS;

const StringHash HASH_ELEMENT_TARGETS__INPUT = 231971828;
extern const char* NAME_ELEMENT_TARGETS__INPUT;
typedef sampler__input__AttributeData targets__input__AttributeData;

const StringHash HASH_ELEMENT_TARGETS__EXTRA = 231815089;
extern const char* NAME_ELEMENT_TARGETS__EXTRA;

const StringHash HASH_ELEMENT_MORPH__EXTRA = 68840801;
extern const char* NAME_ELEMENT_MORPH__EXTRA;

const StringHash HASH_ELEMENT_CONTROLLER__EXTRA = 236302929;
extern const char* NAME_ELEMENT_CONTROLLER__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__EXTRA = 84993665;
extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES = 252969491;
extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_GEOMETRIES = 252969491;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_GEOMETRIES;
struct library_geometries__AttributeData
{
    static const library_geometries__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__ASSET = 105126820;
extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__ASSET;

const StringHash HASH_ELEMENT_GEOMETRY = 25538441;
extern const char* NAME_ELEMENT_GEOMETRY;
const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__GEOMETRY = 25538441;
extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__GEOMETRY;
struct geometry__AttributeData
{
    static const geometry__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_GEOMETRY__ASSET = 56917492;
extern const char* NAME_ELEMENT_GEOMETRY__ASSET;

const StringHash HASH_ELEMENT_CONVEX_MESH = 264547688;
extern const char* NAME_ELEMENT_CONVEX_MESH;
const StringHash HASH_ELEMENT_GEOMETRY__CONVEX_MESH = 264547688;
extern const char* NAME_ELEMENT_GEOMETRY__CONVEX_MESH;
const StringHash HASH_ATTRIBUTE_CONVEX_HULL_OF = 167766694;
extern const char* NAME_ATTRIBUTE_CONVEX_HULL_OF;
struct convex_mesh__AttributeData
{
    static const convex_mesh__AttributeData DEFAULT;

    const ParserChar* convex_hull_of;
};

const StringHash HASH_ELEMENT_CONVEX_MESH__SOURCE = 115317301;
extern const char* NAME_ELEMENT_CONVEX_MESH__SOURCE;
typedef animation__source__AttributeData convex_mesh__source__AttributeData;

const StringHash HASH_ELEMENT_VERTICES = 97017683;
extern const char* NAME_ELEMENT_VERTICES;
const StringHash HASH_ELEMENT_CONVEX_MESH__VERTICES = 97017683;
extern const char* NAME_ELEMENT_CONVEX_MESH__VERTICES;
struct vertices__AttributeData
{
    static const vertices__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_VERTICES__INPUT = 250722196;
extern const char* NAME_ELEMENT_VERTICES__INPUT;
typedef sampler__input__AttributeData vertices__input__AttributeData;

const StringHash HASH_ELEMENT_VERTICES__EXTRA = 250813393;
extern const char* NAME_ELEMENT_VERTICES__EXTRA;

const StringHash HASH_ELEMENT_LINES = 174551523;
extern const char* NAME_ELEMENT_LINES;
const StringHash HASH_ELEMENT_CONVEX_MESH__LINES = 174551523;
extern const char* NAME_ELEMENT_CONVEX_MESH__LINES;
const StringHash HASH_ATTRIBUTE_MATERIAL = 145524812;
extern const char* NAME_ATTRIBUTE_MATERIAL;
struct lines__AttributeData
{
    static const lines__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_LINES__INPUT = 74455892;
extern const char* NAME_ELEMENT_LINES__INPUT;
typedef vertex_weights__input__AttributeData lines__input__AttributeData;

const StringHash HASH_ELEMENT_P = 5018704;
extern const char* NAME_ELEMENT_P;
const StringHash HASH_ELEMENT_LINES__P = 5018704;
extern const char* NAME_ELEMENT_LINES__P;

const StringHash HASH_ELEMENT_LINES__EXTRA = 74233617;
extern const char* NAME_ELEMENT_LINES__EXTRA;

const StringHash HASH_ELEMENT_LINESTRIPS = 235800419;
extern const char* NAME_ELEMENT_LINESTRIPS;
const StringHash HASH_ELEMENT_CONVEX_MESH__LINESTRIPS = 235800419;
extern const char* NAME_ELEMENT_CONVEX_MESH__LINESTRIPS;
struct linestrips__AttributeData
{
    static const linestrips__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_LINESTRIPS__INPUT = 261379220;
extern const char* NAME_ELEMENT_LINESTRIPS__INPUT;
typedef vertex_weights__input__AttributeData linestrips__input__AttributeData;

const StringHash HASH_ELEMENT_LINESTRIPS__P = 201547680;
extern const char* NAME_ELEMENT_LINESTRIPS__P;

const StringHash HASH_ELEMENT_LINESTRIPS__EXTRA = 261159121;
extern const char* NAME_ELEMENT_LINESTRIPS__EXTRA;

const StringHash HASH_ELEMENT_POLYGONS = 225281043;
extern const char* NAME_ELEMENT_POLYGONS;
const StringHash HASH_ELEMENT_CONVEX_MESH__POLYGONS = 225281043;
extern const char* NAME_ELEMENT_CONVEX_MESH__POLYGONS;
struct polygons__AttributeData
{
    static const polygons__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_POLYGONS__INPUT = 144860468;
extern const char* NAME_ELEMENT_POLYGONS__INPUT;
typedef vertex_weights__input__AttributeData polygons__input__AttributeData;

const StringHash HASH_ELEMENT_POLYGONS__P = 238221456;
extern const char* NAME_ELEMENT_POLYGONS__P;

const StringHash HASH_ELEMENT_PH = 53447048;
extern const char* NAME_ELEMENT_PH;
const StringHash HASH_ELEMENT_POLYGONS__PH = 53447048;
extern const char* NAME_ELEMENT_POLYGONS__PH;

const StringHash HASH_ELEMENT_PH__P = 7791968;
extern const char* NAME_ELEMENT_PH__P;

const StringHash HASH_ELEMENT_H = 7791960;
extern const char* NAME_ELEMENT_H;
const StringHash HASH_ELEMENT_PH__H = 7791960;
extern const char* NAME_ELEMENT_PH__H;

const StringHash HASH_ELEMENT_POLYGONS__EXTRA = 144886129;
extern const char* NAME_ELEMENT_POLYGONS__EXTRA;

const StringHash HASH_ELEMENT_POLYLIST = 225351396;
extern const char* NAME_ELEMENT_POLYLIST;
const StringHash HASH_ELEMENT_CONVEX_MESH__POLYLIST = 225351396;
extern const char* NAME_ELEMENT_CONVEX_MESH__POLYLIST;
struct polylist__AttributeData
{
    static const polylist__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_POLYLIST__INPUT = 22882756;
extern const char* NAME_ELEMENT_POLYLIST__INPUT;
typedef vertex_weights__input__AttributeData polylist__input__AttributeData;

const StringHash HASH_ELEMENT_POLYLIST__VCOUNT = 117410884;
extern const char* NAME_ELEMENT_POLYLIST__VCOUNT;

const StringHash HASH_ELEMENT_POLYLIST__P = 58589536;
extern const char* NAME_ELEMENT_POLYLIST__P;

const StringHash HASH_ELEMENT_POLYLIST__EXTRA = 23037313;
extern const char* NAME_ELEMENT_POLYLIST__EXTRA;

const StringHash HASH_ELEMENT_TRIANGLES = 175033555;
extern const char* NAME_ELEMENT_TRIANGLES;
const StringHash HASH_ELEMENT_CONVEX_MESH__TRIANGLES = 175033555;
extern const char* NAME_ELEMENT_CONVEX_MESH__TRIANGLES;
struct triangles__AttributeData
{
    static const triangles__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_TRIANGLES__INPUT = 219530052;
extern const char* NAME_ELEMENT_TRIANGLES__INPUT;
typedef vertex_weights__input__AttributeData triangles__input__AttributeData;

const StringHash HASH_ELEMENT_TRIANGLES__P = 194284832;
extern const char* NAME_ELEMENT_TRIANGLES__P;

const StringHash HASH_ELEMENT_TRIANGLES__EXTRA = 219639553;
extern const char* NAME_ELEMENT_TRIANGLES__EXTRA;

const StringHash HASH_ELEMENT_TRIFANS = 236645939;
extern const char* NAME_ELEMENT_TRIFANS;
const StringHash HASH_ELEMENT_CONVEX_MESH__TRIFANS = 236645939;
extern const char* NAME_ELEMENT_CONVEX_MESH__TRIFANS;
struct trifans__AttributeData
{
    static const trifans__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_TRIFANS__INPUT = 228906372;
extern const char* NAME_ELEMENT_TRIFANS__INPUT;
typedef vertex_weights__input__AttributeData trifans__input__AttributeData;

const StringHash HASH_ELEMENT_TRIFANS__P = 209866128;
extern const char* NAME_ELEMENT_TRIFANS__P;

const StringHash HASH_ELEMENT_TRIFANS__EXTRA = 228620737;
extern const char* NAME_ELEMENT_TRIFANS__EXTRA;

const StringHash HASH_ELEMENT_TRISTRIPS = 92405331;
extern const char* NAME_ELEMENT_TRISTRIPS;
const StringHash HASH_ELEMENT_CONVEX_MESH__TRISTRIPS = 92405331;
extern const char* NAME_ELEMENT_CONVEX_MESH__TRISTRIPS;
struct tristrips__AttributeData
{
    static const tristrips__AttributeData DEFAULT;

    const ParserChar* name;
    unsigned long long count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_TRISTRIPS__INPUT = 262203732;
extern const char* NAME_ELEMENT_TRISTRIPS__INPUT;
typedef vertex_weights__input__AttributeData tristrips__input__AttributeData;

const StringHash HASH_ELEMENT_TRISTRIPS__P = 12492704;
extern const char* NAME_ELEMENT_TRISTRIPS__P;

const StringHash HASH_ELEMENT_TRISTRIPS__EXTRA = 261899537;
extern const char* NAME_ELEMENT_TRISTRIPS__EXTRA;

const StringHash HASH_ELEMENT_CONVEX_MESH__EXTRA = 173633185;
extern const char* NAME_ELEMENT_CONVEX_MESH__EXTRA;

const StringHash HASH_ELEMENT_MESH = 53998040;
extern const char* NAME_ELEMENT_MESH;
const StringHash HASH_ELEMENT_GEOMETRY__MESH = 53998040;
extern const char* NAME_ELEMENT_GEOMETRY__MESH;

const StringHash HASH_ELEMENT_MESH__SOURCE = 28989125;
extern const char* NAME_ELEMENT_MESH__SOURCE;
typedef animation__source__AttributeData mesh__source__AttributeData;

const StringHash HASH_ELEMENT_MESH__VERTICES = 305203;
extern const char* NAME_ELEMENT_MESH__VERTICES;

const StringHash HASH_ELEMENT_MESH__LINES = 87117091;
extern const char* NAME_ELEMENT_MESH__LINES;

const StringHash HASH_ELEMENT_MESH__LINESTRIPS = 49849507;
extern const char* NAME_ELEMENT_MESH__LINESTRIPS;

const StringHash HASH_ELEMENT_MESH__POLYGONS = 178361651;
extern const char* NAME_ELEMENT_MESH__POLYGONS;

const StringHash HASH_ELEMENT_MESH__POLYLIST = 178422212;
extern const char* NAME_ELEMENT_MESH__POLYLIST;

const StringHash HASH_ELEMENT_MESH__TRIANGLES = 111270531;
extern const char* NAME_ELEMENT_MESH__TRIANGLES;

const StringHash HASH_ELEMENT_MESH__TRIFANS = 138814275;
extern const char* NAME_ELEMENT_MESH__TRIFANS;

const StringHash HASH_ELEMENT_MESH__TRISTRIPS = 156149795;
extern const char* NAME_ELEMENT_MESH__TRISTRIPS;

const StringHash HASH_ELEMENT_MESH__EXTRA = 86979169;
extern const char* NAME_ELEMENT_MESH__EXTRA;

const StringHash HASH_ELEMENT_SPLINE = 90991989;
extern const char* NAME_ELEMENT_SPLINE;
const StringHash HASH_ELEMENT_GEOMETRY__SPLINE = 90991989;
extern const char* NAME_ELEMENT_GEOMETRY__SPLINE;
const StringHash HASH_ATTRIBUTE_CLOSED = 111372724;
extern const char* NAME_ATTRIBUTE_CLOSED;
struct spline__AttributeData
{
    static const spline__AttributeData DEFAULT;

    bool closed;
};

const StringHash HASH_ELEMENT_SPLINE__SOURCE = 28739173;
extern const char* NAME_ELEMENT_SPLINE__SOURCE;
typedef animation__source__AttributeData spline__source__AttributeData;

const StringHash HASH_ELEMENT_CONTROL_VERTICES = 152193299;
extern const char* NAME_ELEMENT_CONTROL_VERTICES;
const StringHash HASH_ELEMENT_SPLINE__CONTROL_VERTICES = 152193299;
extern const char* NAME_ELEMENT_SPLINE__CONTROL_VERTICES;

const StringHash HASH_ELEMENT_CONTROL_VERTICES__INPUT = 96321988;
extern const char* NAME_ELEMENT_CONTROL_VERTICES__INPUT;
typedef sampler__input__AttributeData control_vertices__input__AttributeData;

const StringHash HASH_ELEMENT_CONTROL_VERTICES__EXTRA = 96431489;
extern const char* NAME_ELEMENT_CONTROL_VERTICES__EXTRA;

const StringHash HASH_ELEMENT_SPLINE__EXTRA = 254803809;
extern const char* NAME_ELEMENT_SPLINE__EXTRA;

const StringHash HASH_ELEMENT_GEOMETRY__EXTRA = 56635313;
extern const char* NAME_ELEMENT_GEOMETRY__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__EXTRA = 104876513;
extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_EFFECTS = 246773571;
extern const char* NAME_ELEMENT_LIBRARY_EFFECTS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_EFFECTS = 246773571;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_EFFECTS;
struct library_effects__AttributeData
{
    static const library_effects__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__ASSET = 18733172;
extern const char* NAME_ELEMENT_LIBRARY_EFFECTS__ASSET;

const StringHash HASH_ELEMENT_EFFECT = 32231604;
extern const char* NAME_ELEMENT_EFFECT;
const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__EFFECT = 32231604;
extern const char* NAME_ELEMENT_LIBRARY_EFFECTS__EFFECT;
struct effect__AttributeData
{
    static const effect__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_EFFECT__ASSET = 9704148;
extern const char* NAME_ELEMENT_EFFECT__ASSET;

const StringHash HASH_ELEMENT_ANNOTATE = 17277301;
extern const char* NAME_ELEMENT_ANNOTATE;
const StringHash HASH_ELEMENT_EFFECT__ANNOTATE = 17277301;
extern const char* NAME_ELEMENT_EFFECT__ANNOTATE;
struct annotate__AttributeData
{
    static const annotate__AttributeData DEFAULT;

    const ParserChar* name;
};

const StringHash HASH_ELEMENT_BOOL = 2309228;
extern const char* NAME_ELEMENT_BOOL;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL = 2309228;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL;

const StringHash HASH_ELEMENT_BOOL2 = 36947698;
extern const char* NAME_ELEMENT_BOOL2;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL2 = 36947698;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL2;

const StringHash HASH_ELEMENT_BOOL3 = 36947699;
extern const char* NAME_ELEMENT_BOOL3;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL3 = 36947699;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL3;

const StringHash HASH_ELEMENT_BOOL4 = 36947700;
extern const char* NAME_ELEMENT_BOOL4;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL4 = 36947700;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL4;

const StringHash HASH_ELEMENT_INT = 50476724;
extern const char* NAME_ELEMENT_INT;
const StringHash HASH_ELEMENT_ANNOTATE__INT = 50476724;
extern const char* NAME_ELEMENT_ANNOTATE__INT;

const StringHash HASH_ELEMENT_INT2 = 2321218;
extern const char* NAME_ELEMENT_INT2;
const StringHash HASH_ELEMENT_ANNOTATE__INT2 = 2321218;
extern const char* NAME_ELEMENT_ANNOTATE__INT2;

const StringHash HASH_ELEMENT_INT3 = 2321219;
extern const char* NAME_ELEMENT_INT3;
const StringHash HASH_ELEMENT_ANNOTATE__INT3 = 2321219;
extern const char* NAME_ELEMENT_ANNOTATE__INT3;

const StringHash HASH_ELEMENT_INT4 = 2321220;
extern const char* NAME_ELEMENT_INT4;
const StringHash HASH_ELEMENT_ANNOTATE__INT4 = 2321220;
extern const char* NAME_ELEMENT_ANNOTATE__INT4;

const StringHash HASH_ELEMENT_FLOAT = 37213828;
extern const char* NAME_ELEMENT_FLOAT;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT = 37213828;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT;

const StringHash HASH_ELEMENT_FLOAT2 = 58550354;
extern const char* NAME_ELEMENT_FLOAT2;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2 = 58550354;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT2;

const StringHash HASH_ELEMENT_FLOAT3 = 58550355;
extern const char* NAME_ELEMENT_FLOAT3;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3 = 58550355;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT3;

const StringHash HASH_ELEMENT_FLOAT4 = 58550356;
extern const char* NAME_ELEMENT_FLOAT4;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4 = 58550356;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT4;

const StringHash HASH_ELEMENT_FLOAT2X2 = 224942786;
extern const char* NAME_ELEMENT_FLOAT2X2;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2X2 = 224942786;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT2X2;

const StringHash HASH_ELEMENT_FLOAT3X3 = 224942531;
extern const char* NAME_ELEMENT_FLOAT3X3;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3X3 = 224942531;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT3X3;

const StringHash HASH_ELEMENT_FLOAT4X4 = 224942276;
extern const char* NAME_ELEMENT_FLOAT4X4;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4X4 = 224942276;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT4X4;

const StringHash HASH_ELEMENT_STRING = 376935;
extern const char* NAME_ELEMENT_STRING;
const StringHash HASH_ELEMENT_ANNOTATE__STRING = 376935;
extern const char* NAME_ELEMENT_ANNOTATE__STRING;

const StringHash HASH_ELEMENT_IMAGE = 9735365;
extern const char* NAME_ELEMENT_IMAGE;
const StringHash HASH_ELEMENT_EFFECT__IMAGE = 9735365;
extern const char* NAME_ELEMENT_EFFECT__IMAGE;
const StringHash HASH_ATTRIBUTE_FORMAT = 114725764;
extern const char* NAME_ATTRIBUTE_FORMAT;
const StringHash HASH_ATTRIBUTE_HEIGHT = 116129268;
extern const char* NAME_ATTRIBUTE_HEIGHT;
const StringHash HASH_ATTRIBUTE_WIDTH = 8256424;
extern const char* NAME_ATTRIBUTE_WIDTH;
const StringHash HASH_ATTRIBUTE_DEPTH = 6997928;
extern const char* NAME_ATTRIBUTE_DEPTH;
struct image__AttributeData
{
    static const image__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    const ParserChar* format;
    unsigned long long height;
    unsigned long long width;
    unsigned long long depth;
};

const StringHash HASH_ELEMENT_IMAGE__ASSET = 73127028;
extern const char* NAME_ELEMENT_IMAGE__ASSET;

const StringHash HASH_ELEMENT_DATA = 189112177;
extern const char* NAME_ELEMENT_DATA;
const StringHash HASH_ELEMENT_IMAGE__DATA = 189112177;
extern const char* NAME_ELEMENT_IMAGE__DATA;

const StringHash HASH_ELEMENT_INIT_FROM = 221349405;
extern const char* NAME_ELEMENT_INIT_FROM;
const StringHash HASH_ELEMENT_IMAGE__INIT_FROM = 221349405;
extern const char* NAME_ELEMENT_IMAGE__INIT_FROM;

const StringHash HASH_ELEMENT_IMAGE__EXTRA = 73369137;
extern const char* NAME_ELEMENT_IMAGE__EXTRA;

const StringHash HASH_ELEMENT_NEWPARAM = 123175677;
extern const char* NAME_ELEMENT_NEWPARAM;
const StringHash HASH_ELEMENT_EFFECT__NEWPARAM = 123175677;
extern const char* NAME_ELEMENT_EFFECT__NEWPARAM;
struct effect__newparam__AttributeData
{
    static const effect__newparam__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_NEWPARAM__ANNOTATE = 202972325;
extern const char* NAME_ELEMENT_NEWPARAM__ANNOTATE;

const StringHash HASH_ELEMENT_SEMANTIC = 91876067;
extern const char* NAME_ELEMENT_SEMANTIC;
const StringHash HASH_ELEMENT_NEWPARAM__SEMANTIC = 91876067;
extern const char* NAME_ELEMENT_NEWPARAM__SEMANTIC;

const StringHash HASH_ELEMENT_MODIFIER = 182483714;
extern const char* NAME_ELEMENT_MODIFIER;
const StringHash HASH_ELEMENT_NEWPARAM__MODIFIER = 182483714;
extern const char* NAME_ELEMENT_NEWPARAM__MODIFIER;

const StringHash HASH_ELEMENT_NEWPARAM__BOOL = 263396124;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL;

const StringHash HASH_ELEMENT_NEWPARAM__BOOL2 = 187805954;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL2;

const StringHash HASH_ELEMENT_NEWPARAM__BOOL3 = 187805955;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL3;

const StringHash HASH_ELEMENT_NEWPARAM__BOOL4 = 187805956;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL4;

const StringHash HASH_ELEMENT_NEWPARAM__INT = 83572900;
extern const char* NAME_ELEMENT_NEWPARAM__INT;

const StringHash HASH_ELEMENT_NEWPARAM__INT2 = 263424562;
extern const char* NAME_ELEMENT_NEWPARAM__INT2;

const StringHash HASH_ELEMENT_NEWPARAM__INT3 = 263424563;
extern const char* NAME_ELEMENT_NEWPARAM__INT3;

const StringHash HASH_ELEMENT_NEWPARAM__INT4 = 263424564;
extern const char* NAME_ELEMENT_NEWPARAM__INT4;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT = 188080500;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2 = 56498114;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3 = 56498115;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4 = 56498116;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4;

const StringHash HASH_ELEMENT_FLOAT1X1 = 236440545;
extern const char* NAME_ELEMENT_FLOAT1X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X1 = 236440545;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X1;

const StringHash HASH_ELEMENT_FLOAT1X2 = 236440546;
extern const char* NAME_ELEMENT_FLOAT1X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X2 = 236440546;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X2;

const StringHash HASH_ELEMENT_FLOAT1X3 = 236440547;
extern const char* NAME_ELEMENT_FLOAT1X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X3 = 236440547;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X3;

const StringHash HASH_ELEMENT_FLOAT1X4 = 236440548;
extern const char* NAME_ELEMENT_FLOAT1X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X4 = 236440548;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X4;

const StringHash HASH_ELEMENT_FLOAT2X1 = 236440289;
extern const char* NAME_ELEMENT_FLOAT2X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X1 = 236440289;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X1;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X2 = 236440290;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X2;

const StringHash HASH_ELEMENT_FLOAT2X3 = 236440291;
extern const char* NAME_ELEMENT_FLOAT2X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X3 = 236440291;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X3;

const StringHash HASH_ELEMENT_FLOAT2X4 = 236440292;
extern const char* NAME_ELEMENT_FLOAT2X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X4 = 236440292;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X4;

const StringHash HASH_ELEMENT_FLOAT3X1 = 236440033;
extern const char* NAME_ELEMENT_FLOAT3X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X1 = 236440033;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X1;

const StringHash HASH_ELEMENT_FLOAT3X2 = 236440034;
extern const char* NAME_ELEMENT_FLOAT3X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X2 = 236440034;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X2;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X3 = 236440035;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X3;

const StringHash HASH_ELEMENT_FLOAT3X4 = 236440036;
extern const char* NAME_ELEMENT_FLOAT3X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X4 = 236440036;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X4;

const StringHash HASH_ELEMENT_FLOAT4X1 = 236439777;
extern const char* NAME_ELEMENT_FLOAT4X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X1 = 236439777;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X1;

const StringHash HASH_ELEMENT_FLOAT4X2 = 236439778;
extern const char* NAME_ELEMENT_FLOAT4X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X2 = 236439778;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X2;

const StringHash HASH_ELEMENT_FLOAT4X3 = 236439779;
extern const char* NAME_ELEMENT_FLOAT4X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X3 = 236439779;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X3;

const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X4 = 236439780;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X4;

const StringHash HASH_ELEMENT_SURFACE = 37502101;
extern const char* NAME_ELEMENT_SURFACE;
const StringHash HASH_ELEMENT_NEWPARAM__SURFACE = 37502101;
extern const char* NAME_ELEMENT_NEWPARAM__SURFACE;
struct newparam__surface__AttributeData
{
    static const newparam__surface__AttributeData DEFAULT;

    const ParserChar* type;
};

const StringHash HASH_ELEMENT_INIT_AS_NULL = 97694700;
extern const char* NAME_ELEMENT_INIT_AS_NULL;
const StringHash HASH_ELEMENT_SURFACE__INIT_AS_NULL = 97694700;
extern const char* NAME_ELEMENT_SURFACE__INIT_AS_NULL;

const StringHash HASH_ELEMENT_INIT_AS_TARGET = 37832724;
extern const char* NAME_ELEMENT_INIT_AS_TARGET;
const StringHash HASH_ELEMENT_SURFACE__INIT_AS_TARGET = 37832724;
extern const char* NAME_ELEMENT_SURFACE__INIT_AS_TARGET;

const StringHash HASH_ELEMENT_INIT_CUBE = 245137349;
extern const char* NAME_ELEMENT_INIT_CUBE;
const StringHash HASH_ELEMENT_SURFACE__INIT_CUBE = 245137349;
extern const char* NAME_ELEMENT_SURFACE__INIT_CUBE;

const StringHash HASH_ELEMENT_ALL = 230624156;
extern const char* NAME_ELEMENT_ALL;
const StringHash HASH_ELEMENT_INIT_CUBE__ALL = 230624156;
extern const char* NAME_ELEMENT_INIT_CUBE__ALL;
const StringHash HASH_ATTRIBUTE_REF = 30902;
extern const char* NAME_ATTRIBUTE_REF;
struct init_cube__all__AttributeData
{
    static const init_cube__all__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_PRIMARY = 171149225;
extern const char* NAME_ELEMENT_PRIMARY;
const StringHash HASH_ELEMENT_INIT_CUBE__PRIMARY = 171149225;
extern const char* NAME_ELEMENT_INIT_CUBE__PRIMARY;
struct init_cube__primary__AttributeData
{
    static const init_cube__primary__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_ORDER = 241501282;
extern const char* NAME_ELEMENT_ORDER;
const StringHash HASH_ELEMENT_PRIMARY__ORDER = 241501282;
extern const char* NAME_ELEMENT_PRIMARY__ORDER;

const StringHash HASH_ELEMENT_FACE = 200285253;
extern const char* NAME_ELEMENT_FACE;
const StringHash HASH_ELEMENT_INIT_CUBE__FACE = 200285253;
extern const char* NAME_ELEMENT_INIT_CUBE__FACE;
struct init_cube__face__AttributeData
{
    static const init_cube__face__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_INIT_VOLUME = 253916837;
extern const char* NAME_ELEMENT_INIT_VOLUME;
const StringHash HASH_ELEMENT_SURFACE__INIT_VOLUME = 253916837;
extern const char* NAME_ELEMENT_SURFACE__INIT_VOLUME;

const StringHash HASH_ELEMENT_INIT_VOLUME__ALL = 165229292;
extern const char* NAME_ELEMENT_INIT_VOLUME__ALL;
struct init_volume__all__AttributeData
{
    static const init_volume__all__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_INIT_VOLUME__PRIMARY = 21488025;
extern const char* NAME_ELEMENT_INIT_VOLUME__PRIMARY;
struct init_volume__primary__AttributeData
{
    static const init_volume__primary__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_INIT_PLANAR = 264653330;
extern const char* NAME_ELEMENT_INIT_PLANAR;
const StringHash HASH_ELEMENT_SURFACE__INIT_PLANAR = 264653330;
extern const char* NAME_ELEMENT_SURFACE__INIT_PLANAR;

const StringHash HASH_ELEMENT_INIT_PLANAR__ALL = 36140396;
extern const char* NAME_ELEMENT_INIT_PLANAR__ALL;
struct init_planar__all__AttributeData
{
    static const init_planar__all__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_SURFACE__INIT_FROM = 245107997;
extern const char* NAME_ELEMENT_SURFACE__INIT_FROM;
const StringHash HASH_ATTRIBUTE_MIP = 29696;
extern const char* NAME_ATTRIBUTE_MIP;
const StringHash HASH_ATTRIBUTE_SLICE = 8007573;
extern const char* NAME_ATTRIBUTE_SLICE;
const StringHash HASH_ATTRIBUTE_FACE = 444309;
extern const char* NAME_ATTRIBUTE_FACE;
struct surface__init_from__AttributeData
{
    static const surface__init_from__AttributeData DEFAULT;

    unsigned long mip;
    unsigned long slice;
    const ParserChar* face;
};

const StringHash HASH_ELEMENT_FORMAT = 219247124;
extern const char* NAME_ELEMENT_FORMAT;
const StringHash HASH_ELEMENT_SURFACE__FORMAT = 219247124;
extern const char* NAME_ELEMENT_SURFACE__FORMAT;

const StringHash HASH_ELEMENT_FORMAT_HINT = 22346100;
extern const char* NAME_ELEMENT_FORMAT_HINT;
const StringHash HASH_ELEMENT_SURFACE__FORMAT_HINT = 22346100;
extern const char* NAME_ELEMENT_SURFACE__FORMAT_HINT;

const StringHash HASH_ELEMENT_CHANNELS = 153491235;
extern const char* NAME_ELEMENT_CHANNELS;
const StringHash HASH_ELEMENT_FORMAT_HINT__CHANNELS = 153491235;
extern const char* NAME_ELEMENT_FORMAT_HINT__CHANNELS;

const StringHash HASH_ELEMENT_RANGE = 98570949;
extern const char* NAME_ELEMENT_RANGE;
const StringHash HASH_ELEMENT_FORMAT_HINT__RANGE = 98570949;
extern const char* NAME_ELEMENT_FORMAT_HINT__RANGE;

const StringHash HASH_ELEMENT_PRECISION = 227897774;
extern const char* NAME_ELEMENT_PRECISION;
const StringHash HASH_ELEMENT_FORMAT_HINT__PRECISION = 227897774;
extern const char* NAME_ELEMENT_FORMAT_HINT__PRECISION;

const StringHash HASH_ELEMENT_OPTION = 249614094;
extern const char* NAME_ELEMENT_OPTION;
const StringHash HASH_ELEMENT_FORMAT_HINT__OPTION = 249614094;
extern const char* NAME_ELEMENT_FORMAT_HINT__OPTION;

const StringHash HASH_ELEMENT_FORMAT_HINT__EXTRA = 97815953;
extern const char* NAME_ELEMENT_FORMAT_HINT__EXTRA;

const StringHash HASH_ELEMENT_SIZE = 27158757;
extern const char* NAME_ELEMENT_SIZE;
const StringHash HASH_ELEMENT_SURFACE__SIZE = 27158757;
extern const char* NAME_ELEMENT_SURFACE__SIZE;

const StringHash HASH_ELEMENT_VIEWPORT_RATIO = 39354991;
extern const char* NAME_ELEMENT_VIEWPORT_RATIO;
const StringHash HASH_ELEMENT_SURFACE__VIEWPORT_RATIO = 39354991;
extern const char* NAME_ELEMENT_SURFACE__VIEWPORT_RATIO;

const StringHash HASH_ELEMENT_MIP_LEVELS = 95669747;
extern const char* NAME_ELEMENT_MIP_LEVELS;
const StringHash HASH_ELEMENT_SURFACE__MIP_LEVELS = 95669747;
extern const char* NAME_ELEMENT_SURFACE__MIP_LEVELS;

const StringHash HASH_ELEMENT_MIPMAP_GENERATE = 57490693;
extern const char* NAME_ELEMENT_MIPMAP_GENERATE;
const StringHash HASH_ELEMENT_SURFACE__MIPMAP_GENERATE = 57490693;
extern const char* NAME_ELEMENT_SURFACE__MIPMAP_GENERATE;

const StringHash HASH_ELEMENT_SURFACE__EXTRA = 164660625;
extern const char* NAME_ELEMENT_SURFACE__EXTRA;

const StringHash HASH_ELEMENT_SAMPLER1D = 11125956;
extern const char* NAME_ELEMENT_SAMPLER1D;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER1D = 11125956;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER1D;

const StringHash HASH_ELEMENT_SAMPLER1D__SOURCE = 70915797;
extern const char* NAME_ELEMENT_SAMPLER1D__SOURCE;

const StringHash HASH_ELEMENT_WRAP_S = 72637475;
extern const char* NAME_ELEMENT_WRAP_S;
const StringHash HASH_ELEMENT_SAMPLER1D__WRAP_S = 72637475;
extern const char* NAME_ELEMENT_SAMPLER1D__WRAP_S;

const StringHash HASH_ELEMENT_MINFILTER = 153924226;
extern const char* NAME_ELEMENT_MINFILTER;
const StringHash HASH_ELEMENT_SAMPLER1D__MINFILTER = 153924226;
extern const char* NAME_ELEMENT_SAMPLER1D__MINFILTER;

const StringHash HASH_ELEMENT_MAGFILTER = 2929266;
extern const char* NAME_ELEMENT_MAGFILTER;
const StringHash HASH_ELEMENT_SAMPLER1D__MAGFILTER = 2929266;
extern const char* NAME_ELEMENT_SAMPLER1D__MAGFILTER;

const StringHash HASH_ELEMENT_MIPFILTER = 187478786;
extern const char* NAME_ELEMENT_MIPFILTER;
const StringHash HASH_ELEMENT_SAMPLER1D__MIPFILTER = 187478786;
extern const char* NAME_ELEMENT_SAMPLER1D__MIPFILTER;

const StringHash HASH_ELEMENT_BORDER_COLOR = 18094050;
extern const char* NAME_ELEMENT_BORDER_COLOR;
const StringHash HASH_ELEMENT_SAMPLER1D__BORDER_COLOR = 18094050;
extern const char* NAME_ELEMENT_SAMPLER1D__BORDER_COLOR;

const StringHash HASH_ELEMENT_MIPMAP_MAXLEVEL = 72229196;
extern const char* NAME_ELEMENT_MIPMAP_MAXLEVEL;
const StringHash HASH_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL = 72229196;
extern const char* NAME_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL;

const StringHash HASH_ELEMENT_MIPMAP_BIAS = 216810323;
extern const char* NAME_ELEMENT_MIPMAP_BIAS;
const StringHash HASH_ELEMENT_SAMPLER1D__MIPMAP_BIAS = 216810323;
extern const char* NAME_ELEMENT_SAMPLER1D__MIPMAP_BIAS;

const StringHash HASH_ELEMENT_SAMPLER1D__EXTRA = 74921569;
extern const char* NAME_ELEMENT_SAMPLER1D__EXTRA;

const StringHash HASH_ELEMENT_SAMPLER2D = 11126004;
extern const char* NAME_ELEMENT_SAMPLER2D;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER2D = 11126004;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER2D;

const StringHash HASH_ELEMENT_SAMPLER2D__SOURCE = 70919893;
extern const char* NAME_ELEMENT_SAMPLER2D__SOURCE;

const StringHash HASH_ELEMENT_SAMPLER2D__WRAP_S = 72641571;
extern const char* NAME_ELEMENT_SAMPLER2D__WRAP_S;

const StringHash HASH_ELEMENT_WRAP_T = 72641572;
extern const char* NAME_ELEMENT_WRAP_T;
const StringHash HASH_ELEMENT_SAMPLER2D__WRAP_T = 72641572;
extern const char* NAME_ELEMENT_SAMPLER2D__WRAP_T;

const StringHash HASH_ELEMENT_SAMPLER2D__MINFILTER = 170701442;
extern const char* NAME_ELEMENT_SAMPLER2D__MINFILTER;

const StringHash HASH_ELEMENT_SAMPLER2D__MAGFILTER = 53260914;
extern const char* NAME_ELEMENT_SAMPLER2D__MAGFILTER;

const StringHash HASH_ELEMENT_SAMPLER2D__MIPFILTER = 137147138;
extern const char* NAME_ELEMENT_SAMPLER2D__MIPFILTER;

const StringHash HASH_ELEMENT_SAMPLER2D__BORDER_COLOR = 18106338;
extern const char* NAME_ELEMENT_SAMPLER2D__BORDER_COLOR;

const StringHash HASH_ELEMENT_SAMPLER2D__MIPMAP_MAXLEVEL = 21897548;
extern const char* NAME_ELEMENT_SAMPLER2D__MIPMAP_MAXLEVEL;

const StringHash HASH_ELEMENT_SAMPLER2D__MIPMAP_BIAS = 216811091;
extern const char* NAME_ELEMENT_SAMPLER2D__MIPMAP_BIAS;

const StringHash HASH_ELEMENT_SAMPLER2D__EXTRA = 74921313;
extern const char* NAME_ELEMENT_SAMPLER2D__EXTRA;

const StringHash HASH_ELEMENT_SAMPLER3D = 11125988;
extern const char* NAME_ELEMENT_SAMPLER3D;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER3D = 11125988;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER3D;

const StringHash HASH_ELEMENT_SAMPLER3D__SOURCE = 70923989;
extern const char* NAME_ELEMENT_SAMPLER3D__SOURCE;

const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_S = 72645667;
extern const char* NAME_ELEMENT_SAMPLER3D__WRAP_S;

const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_T = 72645668;
extern const char* NAME_ELEMENT_SAMPLER3D__WRAP_T;

const StringHash HASH_ELEMENT_WRAP_P = 72645664;
extern const char* NAME_ELEMENT_WRAP_P;
const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_P = 72645664;
extern const char* NAME_ELEMENT_SAMPLER3D__WRAP_P;

const StringHash HASH_ELEMENT_SAMPLER3D__MINFILTER = 187478658;
extern const char* NAME_ELEMENT_SAMPLER3D__MINFILTER;

const StringHash HASH_ELEMENT_SAMPLER3D__MAGFILTER = 36483698;
extern const char* NAME_ELEMENT_SAMPLER3D__MAGFILTER;

const StringHash HASH_ELEMENT_SAMPLER3D__MIPFILTER = 153924354;
extern const char* NAME_ELEMENT_SAMPLER3D__MIPFILTER;

const StringHash HASH_ELEMENT_SAMPLER3D__BORDER_COLOR = 18102242;
extern const char* NAME_ELEMENT_SAMPLER3D__BORDER_COLOR;

const StringHash HASH_ELEMENT_SAMPLER3D__MIPMAP_MAXLEVEL = 38674764;
extern const char* NAME_ELEMENT_SAMPLER3D__MIPMAP_MAXLEVEL;

const StringHash HASH_ELEMENT_SAMPLER3D__MIPMAP_BIAS = 216810835;
extern const char* NAME_ELEMENT_SAMPLER3D__MIPMAP_BIAS;

const StringHash HASH_ELEMENT_SAMPLER3D__EXTRA = 74921057;
extern const char* NAME_ELEMENT_SAMPLER3D__EXTRA;

const StringHash HASH_ELEMENT_SAMPLERCUBE = 164043205;
extern const char* NAME_ELEMENT_SAMPLERCUBE;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERCUBE = 164043205;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERCUBE;

const StringHash HASH_ELEMENT_SAMPLERCUBE__SOURCE = 162255509;
extern const char* NAME_ELEMENT_SAMPLERCUBE__SOURCE;

const StringHash HASH_ELEMENT_SAMPLERCUBE__WRAP_S = 166043747;
extern const char* NAME_ELEMENT_SAMPLERCUBE__WRAP_S;

const StringHash HASH_ELEMENT_SAMPLERCUBE__WRAP_T = 166043748;
extern const char* NAME_ELEMENT_SAMPLERCUBE__WRAP_T;

const StringHash HASH_ELEMENT_SAMPLERCUBE__WRAP_P = 166043744;
extern const char* NAME_ELEMENT_SAMPLERCUBE__WRAP_P;

const StringHash HASH_ELEMENT_SAMPLERCUBE__MINFILTER = 91261426;
extern const char* NAME_ELEMENT_SAMPLERCUBE__MINFILTER;

const StringHash HASH_ELEMENT_SAMPLERCUBE__MAGFILTER = 208701794;
extern const char* NAME_ELEMENT_SAMPLERCUBE__MAGFILTER;

const StringHash HASH_ELEMENT_SAMPLERCUBE__MIPFILTER = 124816914;
extern const char* NAME_ELEMENT_SAMPLERCUBE__MIPFILTER;

const StringHash HASH_ELEMENT_SAMPLERCUBE__BORDER_COLOR = 247714722;
extern const char* NAME_ELEMENT_SAMPLERCUBE__BORDER_COLOR;

const StringHash HASH_ELEMENT_SAMPLERCUBE__MIPMAP_MAXLEVEL = 9059932;
extern const char* NAME_ELEMENT_SAMPLERCUBE__MIPMAP_MAXLEVEL;

const StringHash HASH_ELEMENT_SAMPLERCUBE__MIPMAP_BIAS = 150034195;
extern const char* NAME_ELEMENT_SAMPLERCUBE__MIPMAP_BIAS;

const StringHash HASH_ELEMENT_SAMPLERCUBE__EXTRA = 11282977;
extern const char* NAME_ELEMENT_SAMPLERCUBE__EXTRA;

const StringHash HASH_ELEMENT_SAMPLERRECT = 164034852;
extern const char* NAME_ELEMENT_SAMPLERRECT;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERRECT = 164034852;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERRECT;

const StringHash HASH_ELEMENT_SAMPLERRECT__SOURCE = 143340949;
extern const char* NAME_ELEMENT_SAMPLERRECT__SOURCE;

const StringHash HASH_ELEMENT_SAMPLERRECT__WRAP_S = 134576483;
extern const char* NAME_ELEMENT_SAMPLERRECT__WRAP_S;

const StringHash HASH_ELEMENT_SAMPLERRECT__WRAP_T = 134576484;
extern const char* NAME_ELEMENT_SAMPLERRECT__WRAP_T;

const StringHash HASH_ELEMENT_SAMPLERRECT__MINFILTER = 186710002;
extern const char* NAME_ELEMENT_SAMPLERRECT__MINFILTER;

const StringHash HASH_ELEMENT_SAMPLERRECT__MAGFILTER = 35714914;
extern const char* NAME_ELEMENT_SAMPLERRECT__MAGFILTER;

const StringHash HASH_ELEMENT_SAMPLERRECT__MIPFILTER = 153154578;
extern const char* NAME_ELEMENT_SAMPLERRECT__MIPFILTER;

const StringHash HASH_ELEMENT_SAMPLERRECT__BORDER_COLOR = 220411554;
extern const char* NAME_ELEMENT_SAMPLERRECT__BORDER_COLOR;

const StringHash HASH_ELEMENT_SAMPLERRECT__MIPMAP_MAXLEVEL = 35283036;
extern const char* NAME_ELEMENT_SAMPLERRECT__MIPMAP_MAXLEVEL;

const StringHash HASH_ELEMENT_SAMPLERRECT__MIPMAP_BIAS = 145446243;
extern const char* NAME_ELEMENT_SAMPLERRECT__MIPMAP_BIAS;

const StringHash HASH_ELEMENT_SAMPLERRECT__EXTRA = 11674705;
extern const char* NAME_ELEMENT_SAMPLERRECT__EXTRA;

const StringHash HASH_ELEMENT_SAMPLERDEPTH = 208776984;
extern const char* NAME_ELEMENT_SAMPLERDEPTH;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERDEPTH = 208776984;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERDEPTH;

const StringHash HASH_ELEMENT_SAMPLERDEPTH__SOURCE = 109342549;
extern const char* NAME_ELEMENT_SAMPLERDEPTH__SOURCE;

const StringHash HASH_ELEMENT_SAMPLERDEPTH__WRAP_S = 101327779;
extern const char* NAME_ELEMENT_SAMPLERDEPTH__WRAP_S;

const StringHash HASH_ELEMENT_SAMPLERDEPTH__WRAP_T = 101327780;
extern const char* NAME_ELEMENT_SAMPLERDEPTH__WRAP_T;

const StringHash HASH_ELEMENT_SAMPLERDEPTH__MINFILTER = 246699810;
extern const char* NAME_ELEMENT_SAMPLERDEPTH__MINFILTER;

const StringHash HASH_ELEMENT_SAMPLERDEPTH__MAGFILTER = 129259410;
extern const char* NAME_ELEMENT_SAMPLERDEPTH__MAGFILTER;

const StringHash HASH_ELEMENT_SAMPLERDEPTH__EXTRA = 206754289;
extern const char* NAME_ELEMENT_SAMPLERDEPTH__EXTRA;

const StringHash HASH_ELEMENT_ENUM = 263408381;
extern const char* NAME_ELEMENT_ENUM;
const StringHash HASH_ELEMENT_NEWPARAM__ENUM = 263408381;
extern const char* NAME_ELEMENT_NEWPARAM__ENUM;

const StringHash HASH_ELEMENT_FX_PROFILE_ABSTRACT = 70540052;
extern const char* NAME_ELEMENT_FX_PROFILE_ABSTRACT;
const StringHash HASH_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT = 70540052;
extern const char* NAME_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT;

const StringHash HASH_ELEMENT_EFFECT__EXTRA = 9453713;
extern const char* NAME_ELEMENT_EFFECT__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__EXTRA = 18450993;
extern const char* NAME_ELEMENT_LIBRARY_EFFECTS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS = 175028019;
extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS = 175028019;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS;
struct library_force_fields__AttributeData
{
    static const library_force_fields__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__ASSET = 256178756;
extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__ASSET;

const StringHash HASH_ELEMENT_FORCE_FIELD = 102613300;
extern const char* NAME_ELEMENT_FORCE_FIELD;
const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__FORCE_FIELD = 102613300;
extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__FORCE_FIELD;
struct force_field__AttributeData
{
    static const force_field__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_FORCE_FIELD__ASSET = 138535668;
extern const char* NAME_ELEMENT_FORCE_FIELD__ASSET;

const StringHash HASH_ELEMENT_FORCE_FIELD__TECHNIQUE = 49118021;
extern const char* NAME_ELEMENT_FORCE_FIELD__TECHNIQUE;
typedef source__technique__AttributeData force_field__technique__AttributeData;

const StringHash HASH_ELEMENT_FORCE_FIELD__EXTRA = 138784945;
extern const char* NAME_ELEMENT_FORCE_FIELD__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA = 255895553;
extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_IMAGES = 263512339;
extern const char* NAME_ELEMENT_LIBRARY_IMAGES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_IMAGES = 263512339;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_IMAGES;
struct library_images__AttributeData
{
    static const library_images__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_IMAGES__ASSET = 82286836;
extern const char* NAME_ELEMENT_LIBRARY_IMAGES__ASSET;

const StringHash HASH_ELEMENT_LIBRARY_IMAGES__IMAGE = 81856229;
extern const char* NAME_ELEMENT_LIBRARY_IMAGES__IMAGE;

const StringHash HASH_ELEMENT_LIBRARY_IMAGES__EXTRA = 82037425;
extern const char* NAME_ELEMENT_LIBRARY_IMAGES__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_LIGHTS = 7881555;
extern const char* NAME_ELEMENT_LIBRARY_LIGHTS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_LIGHTS = 7881555;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_LIGHTS;
struct library_lights__AttributeData
{
    static const library_lights__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__ASSET = 2998164;
extern const char* NAME_ELEMENT_LIBRARY_LIGHTS__ASSET;

const StringHash HASH_ELEMENT_LIGHT = 3664804;
extern const char* NAME_ELEMENT_LIGHT;
const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__LIGHT = 3664804;
extern const char* NAME_ELEMENT_LIBRARY_LIGHTS__LIGHT;
struct light__AttributeData
{
    static const light__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIGHT__ASSET = 74937956;
extern const char* NAME_ELEMENT_LIGHT__ASSET;

const StringHash HASH_ELEMENT_LIGHT__TECHNIQUE_COMMON = 9633678;
extern const char* NAME_ELEMENT_LIGHT__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_AMBIENT = 108679732;
extern const char* NAME_ELEMENT_AMBIENT;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__AMBIENT = 108679732;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__AMBIENT;

const StringHash HASH_ELEMENT_COLOR = 148349506;
extern const char* NAME_ELEMENT_COLOR;
const StringHash HASH_ELEMENT_AMBIENT__COLOR = 148349506;
extern const char* NAME_ELEMENT_AMBIENT__COLOR;
struct ambient__color__AttributeData
{
    static const ambient__color__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_DIRECTIONAL = 13053548;
extern const char* NAME_ELEMENT_DIRECTIONAL;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DIRECTIONAL = 13053548;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__DIRECTIONAL;

const StringHash HASH_ELEMENT_DIRECTIONAL__COLOR = 152088738;
extern const char* NAME_ELEMENT_DIRECTIONAL__COLOR;
typedef ambient__color__AttributeData directional__color__AttributeData;

const StringHash HASH_ELEMENT_POINT = 173350644;
extern const char* NAME_ELEMENT_POINT;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__POINT = 173350644;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__POINT;

const StringHash HASH_ELEMENT_POINT__COLOR = 70281410;
extern const char* NAME_ELEMENT_POINT__COLOR;
typedef ambient__color__AttributeData point__color__AttributeData;

const StringHash HASH_ELEMENT_CONSTANT_ATTENUATION = 98628030;
extern const char* NAME_ELEMENT_CONSTANT_ATTENUATION;
const StringHash HASH_ELEMENT_POINT__CONSTANT_ATTENUATION = 98628030;
extern const char* NAME_ELEMENT_POINT__CONSTANT_ATTENUATION;
struct constant_attenuation__AttributeData
{
    static const constant_attenuation__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LINEAR_ATTENUATION = 11535838;
extern const char* NAME_ELEMENT_LINEAR_ATTENUATION;
const StringHash HASH_ELEMENT_POINT__LINEAR_ATTENUATION = 11535838;
extern const char* NAME_ELEMENT_POINT__LINEAR_ATTENUATION;
struct linear_attenuation__AttributeData
{
    static const linear_attenuation__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_QUADRATIC_ATTENUATION = 251429214;
extern const char* NAME_ELEMENT_QUADRATIC_ATTENUATION;
const StringHash HASH_ELEMENT_POINT__QUADRATIC_ATTENUATION = 251429214;
extern const char* NAME_ELEMENT_POINT__QUADRATIC_ATTENUATION;
struct quadratic_attenuation__AttributeData
{
    static const quadratic_attenuation__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SPOT = 178619204;
extern const char* NAME_ELEMENT_SPOT;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPOT = 178619204;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPOT;

const StringHash HASH_ELEMENT_SPOT__COLOR = 86259138;
extern const char* NAME_ELEMENT_SPOT__COLOR;
typedef ambient__color__AttributeData spot__color__AttributeData;

const StringHash HASH_ELEMENT_SPOT__CONSTANT_ATTENUATION = 248571118;
extern const char* NAME_ELEMENT_SPOT__CONSTANT_ATTENUATION;

const StringHash HASH_ELEMENT_SPOT__LINEAR_ATTENUATION = 6894894;
extern const char* NAME_ELEMENT_SPOT__LINEAR_ATTENUATION;

const StringHash HASH_ELEMENT_SPOT__QUADRATIC_ATTENUATION = 268275406;
extern const char* NAME_ELEMENT_SPOT__QUADRATIC_ATTENUATION;

const StringHash HASH_ELEMENT_FALLOFF_ANGLE = 239328965;
extern const char* NAME_ELEMENT_FALLOFF_ANGLE;
const StringHash HASH_ELEMENT_SPOT__FALLOFF_ANGLE = 239328965;
extern const char* NAME_ELEMENT_SPOT__FALLOFF_ANGLE;
struct falloff_angle__AttributeData
{
    static const falloff_angle__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_FALLOFF_EXPONENT = 108835012;
extern const char* NAME_ELEMENT_FALLOFF_EXPONENT;
const StringHash HASH_ELEMENT_SPOT__FALLOFF_EXPONENT = 108835012;
extern const char* NAME_ELEMENT_SPOT__FALLOFF_EXPONENT;
struct falloff_exponent__AttributeData
{
    static const falloff_exponent__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIGHT__TECHNIQUE = 105991637;
extern const char* NAME_ELEMENT_LIGHT__TECHNIQUE;
typedef source__technique__AttributeData light__technique__AttributeData;

const StringHash HASH_ELEMENT_LIGHT__EXTRA = 74654753;
extern const char* NAME_ELEMENT_LIGHT__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__EXTRA = 2747857;
extern const char* NAME_ELEMENT_LIBRARY_LIGHTS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_MATERIALS = 50787011;
extern const char* NAME_ELEMENT_LIBRARY_MATERIALS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_MATERIALS = 50787011;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_MATERIALS;
struct library_materials__AttributeData
{
    static const library_materials__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__ASSET = 118246004;
extern const char* NAME_ELEMENT_LIBRARY_MATERIALS__ASSET;

const StringHash HASH_ELEMENT_MATERIAL = 110624268;
extern const char* NAME_ELEMENT_MATERIAL;
const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__MATERIAL = 110624268;
extern const char* NAME_ELEMENT_LIBRARY_MATERIALS__MATERIAL;
struct material__AttributeData
{
    static const material__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_MATERIAL__ASSET = 261106788;
extern const char* NAME_ELEMENT_MATERIAL__ASSET;

const StringHash HASH_ELEMENT_INSTANCE_EFFECT = 179640868;
extern const char* NAME_ELEMENT_INSTANCE_EFFECT;
const StringHash HASH_ELEMENT_MATERIAL__INSTANCE_EFFECT = 179640868;
extern const char* NAME_ELEMENT_MATERIAL__INSTANCE_EFFECT;
struct instance_effect__AttributeData
{
    static const instance_effect__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_TECHNIQUE_HINT = 28302980;
extern const char* NAME_ELEMENT_TECHNIQUE_HINT;
const StringHash HASH_ELEMENT_INSTANCE_EFFECT__TECHNIQUE_HINT = 28302980;
extern const char* NAME_ELEMENT_INSTANCE_EFFECT__TECHNIQUE_HINT;
const StringHash HASH_ATTRIBUTE_PLATFORM = 42652157;
extern const char* NAME_ATTRIBUTE_PLATFORM;
struct technique_hint__AttributeData
{
    static const technique_hint__AttributeData DEFAULT;

    const ParserChar* platform;
    const ParserChar* profile;
    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_SETPARAM = 219277853;
extern const char* NAME_ELEMENT_SETPARAM;
const StringHash HASH_ELEMENT_INSTANCE_EFFECT__SETPARAM = 219277853;
extern const char* NAME_ELEMENT_INSTANCE_EFFECT__SETPARAM;
struct instance_effect__setparam__AttributeData
{
    static const instance_effect__setparam__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_SETPARAM__BOOL = 206428;
extern const char* NAME_ELEMENT_SETPARAM__BOOL;

const StringHash HASH_ELEMENT_SETPARAM__BOOL2 = 3302898;
extern const char* NAME_ELEMENT_SETPARAM__BOOL2;

const StringHash HASH_ELEMENT_SETPARAM__BOOL3 = 3302899;
extern const char* NAME_ELEMENT_SETPARAM__BOOL3;

const StringHash HASH_ELEMENT_SETPARAM__BOOL4 = 3302900;
extern const char* NAME_ELEMENT_SETPARAM__BOOL4;

const StringHash HASH_ELEMENT_SETPARAM__INT = 14164;
extern const char* NAME_ELEMENT_SETPARAM__INT;

const StringHash HASH_ELEMENT_SETPARAM__INT2 = 226674;
extern const char* NAME_ELEMENT_SETPARAM__INT2;

const StringHash HASH_ELEMENT_SETPARAM__INT3 = 226675;
extern const char* NAME_ELEMENT_SETPARAM__INT3;

const StringHash HASH_ELEMENT_SETPARAM__INT4 = 226676;
extern const char* NAME_ELEMENT_SETPARAM__INT4;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT = 3552644;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT2 = 56842354;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT2;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT3 = 56842355;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT3;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT4 = 56842356;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT4;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X1 = 56130513;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X1;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X2 = 56130514;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X2;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X3 = 56130515;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X3;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X4 = 56130516;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X4;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X1 = 56130257;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X1;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X2 = 56130258;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X2;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X3 = 56130259;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X3;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X4 = 56130260;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X4;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X1 = 56130001;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X1;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X2 = 56130002;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X2;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X3 = 56130003;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X3;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X4 = 56130004;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X4;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X1 = 56129745;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X1;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X2 = 56129746;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X2;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X3 = 56129747;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X3;

const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X4 = 56129748;
extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X4;

const StringHash HASH_ELEMENT_SETPARAM__SURFACE = 63489941;
extern const char* NAME_ELEMENT_SETPARAM__SURFACE;
typedef newparam__surface__AttributeData setparam__surface__AttributeData;

const StringHash HASH_ELEMENT_SETPARAM__SAMPLER1D = 74630612;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLER1D;

const StringHash HASH_ELEMENT_SETPARAM__SAMPLER2D = 74630628;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLER2D;

const StringHash HASH_ELEMENT_SETPARAM__SAMPLER3D = 74630644;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLER3D;

const StringHash HASH_ELEMENT_SETPARAM__SAMPLERCUBE = 46533909;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLERCUBE;

const StringHash HASH_ELEMENT_SETPARAM__SAMPLERRECT = 46657012;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLERRECT;

const StringHash HASH_ELEMENT_SETPARAM__SAMPLERDEPTH = 207676072;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLERDEPTH;

const StringHash HASH_ELEMENT_SETPARAM__ENUM = 210365;
extern const char* NAME_ELEMENT_SETPARAM__ENUM;

const StringHash HASH_ELEMENT_INSTANCE_EFFECT__EXTRA = 101966321;
extern const char* NAME_ELEMENT_INSTANCE_EFFECT__EXTRA;

const StringHash HASH_ELEMENT_MATERIAL__EXTRA = 261389857;
extern const char* NAME_ELEMENT_MATERIAL__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__EXTRA = 117970993;
extern const char* NAME_ELEMENT_LIBRARY_MATERIALS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_NODES = 235021059;
extern const char* NAME_ELEMENT_LIBRARY_NODES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_NODES = 235021059;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_NODES;
struct library_nodes__AttributeData
{
    static const library_nodes__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_NODES__ASSET = 11897780;
extern const char* NAME_ELEMENT_LIBRARY_NODES__ASSET;

const StringHash HASH_ELEMENT_NODE = 118269829;
extern const char* NAME_ELEMENT_NODE;
const StringHash HASH_ELEMENT_LIBRARY_NODES__NODE = 118269829;
extern const char* NAME_ELEMENT_LIBRARY_NODES__NODE;
const StringHash HASH_ATTRIBUTE_LAYER = 7507906;
extern const char* NAME_ATTRIBUTE_LAYER;
struct node__AttributeData
{
    static const node__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    const ParserChar* sid;
    const ParserChar* type;
    const ParserChar* layer;
};

const StringHash HASH_ELEMENT_NODE__ASSET = 86897524;
extern const char* NAME_ELEMENT_NODE__ASSET;

const StringHash HASH_ELEMENT_LOOKAT = 58854100;
extern const char* NAME_ELEMENT_LOOKAT;
const StringHash HASH_ELEMENT_NODE__LOOKAT = 58854100;
extern const char* NAME_ELEMENT_NODE__LOOKAT;
struct lookat__AttributeData
{
    static const lookat__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MATRIX = 57480280;
extern const char* NAME_ELEMENT_MATRIX;
const StringHash HASH_ELEMENT_NODE__MATRIX = 57480280;
extern const char* NAME_ELEMENT_NODE__MATRIX;
struct matrix__AttributeData
{
    static const matrix__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ROTATE = 31654901;
extern const char* NAME_ELEMENT_ROTATE;
const StringHash HASH_ELEMENT_NODE__ROTATE = 31654901;
extern const char* NAME_ELEMENT_NODE__ROTATE;
struct rotate__AttributeData
{
    static const rotate__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SCALE = 85773973;
extern const char* NAME_ELEMENT_SCALE;
const StringHash HASH_ELEMENT_NODE__SCALE = 85773973;
extern const char* NAME_ELEMENT_NODE__SCALE;
struct scale__AttributeData
{
    static const scale__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SKEW = 189912167;
extern const char* NAME_ELEMENT_SKEW;
const StringHash HASH_ELEMENT_NODE__SKEW = 189912167;
extern const char* NAME_ELEMENT_NODE__SKEW;
struct skew__AttributeData
{
    static const skew__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TRANSLATE = 250426997;
extern const char* NAME_ELEMENT_TRANSLATE;
const StringHash HASH_ELEMENT_NODE__TRANSLATE = 250426997;
extern const char* NAME_ELEMENT_NODE__TRANSLATE;
struct translate__AttributeData
{
    static const translate__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INSTANCE_CAMERA = 92626481;
extern const char* NAME_ELEMENT_INSTANCE_CAMERA;
const StringHash HASH_ELEMENT_NODE__INSTANCE_CAMERA = 92626481;
extern const char* NAME_ELEMENT_NODE__INSTANCE_CAMERA;
struct instance_camera__AttributeData
{
    static const instance_camera__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_CAMERA__EXTRA = 22844193;
extern const char* NAME_ELEMENT_INSTANCE_CAMERA__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER = 155305458;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER;
const StringHash HASH_ELEMENT_NODE__INSTANCE_CONTROLLER = 155305458;
extern const char* NAME_ELEMENT_NODE__INSTANCE_CONTROLLER;
struct instance_controller__AttributeData
{
    static const instance_controller__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_SKELETON = 220539054;
extern const char* NAME_ELEMENT_SKELETON;
const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__SKELETON = 220539054;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER__SKELETON;

const StringHash HASH_ELEMENT_BIND_MATERIAL = 132281260;
extern const char* NAME_ELEMENT_BIND_MATERIAL;
const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__BIND_MATERIAL = 132281260;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER__BIND_MATERIAL;

const StringHash HASH_ELEMENT_BIND_MATERIAL__PARAM = 266607469;
extern const char* NAME_ELEMENT_BIND_MATERIAL__PARAM;
typedef accessor__param__AttributeData bind_material__param__AttributeData;

const StringHash HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON = 90983294;
extern const char* NAME_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_INSTANCE_MATERIAL = 109789516;
extern const char* NAME_ELEMENT_INSTANCE_MATERIAL;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_MATERIAL = 109789516;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INSTANCE_MATERIAL;
const StringHash HASH_ATTRIBUTE_SYMBOL = 128989532;
extern const char* NAME_ATTRIBUTE_SYMBOL;
struct instance_material__AttributeData
{
    static const instance_material__AttributeData DEFAULT;

    const ParserChar* symbol;
    const ParserChar* target;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_BIND = 48435636;
extern const char* NAME_ELEMENT_BIND;
const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__BIND = 48435636;
extern const char* NAME_ELEMENT_INSTANCE_MATERIAL__BIND;
struct instance_material__bind__AttributeData
{
    static const instance_material__bind__AttributeData DEFAULT;

    const ParserChar* semantic;
    const ParserChar* target;
};

const StringHash HASH_ELEMENT_BIND_VERTEX_INPUT = 111400644;
extern const char* NAME_ELEMENT_BIND_VERTEX_INPUT;
const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__BIND_VERTEX_INPUT = 111400644;
extern const char* NAME_ELEMENT_INSTANCE_MATERIAL__BIND_VERTEX_INPUT;
const StringHash HASH_ATTRIBUTE_INPUT_SEMANTIC = 256703331;
extern const char* NAME_ATTRIBUTE_INPUT_SEMANTIC;
const StringHash HASH_ATTRIBUTE_INPUT_SET = 130685332;
extern const char* NAME_ATTRIBUTE_INPUT_SET;
struct bind_vertex_input__AttributeData
{
    static const bind_vertex_input__AttributeData DEFAULT;

    const ParserChar* semantic;
    const ParserChar* input_semantic;
    unsigned long long input_set;
};

const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__EXTRA = 238355617;
extern const char* NAME_ELEMENT_INSTANCE_MATERIAL__EXTRA;

const StringHash HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE = 185393301;
extern const char* NAME_ELEMENT_BIND_MATERIAL__TECHNIQUE;
typedef source__technique__AttributeData bind_material__technique__AttributeData;

const StringHash HASH_ELEMENT_BIND_MATERIAL__EXTRA = 266234001;
extern const char* NAME_ELEMENT_BIND_MATERIAL__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__EXTRA = 250294769;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY = 155287129;
extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY;
const StringHash HASH_ELEMENT_NODE__INSTANCE_GEOMETRY = 155287129;
extern const char* NAME_ELEMENT_NODE__INSTANCE_GEOMETRY;
struct instance_geometry__AttributeData
{
    static const instance_geometry__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY__BIND_MATERIAL = 208059788;
extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY__BIND_MATERIAL;

const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY__EXTRA = 79738161;
extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_LIGHT = 191089620;
extern const char* NAME_ELEMENT_INSTANCE_LIGHT;
const StringHash HASH_ELEMENT_NODE__INSTANCE_LIGHT = 191089620;
extern const char* NAME_ELEMENT_NODE__INSTANCE_LIGHT;
struct instance_light__AttributeData
{
    static const instance_light__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_LIGHT__EXTRA = 98246161;
extern const char* NAME_ELEMENT_INSTANCE_LIGHT__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_NODE = 45508293;
extern const char* NAME_ELEMENT_INSTANCE_NODE;
const StringHash HASH_ELEMENT_NODE__INSTANCE_NODE = 45508293;
extern const char* NAME_ELEMENT_NODE__INSTANCE_NODE;
struct instance_node__AttributeData
{
    static const instance_node__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_NODE__EXTRA = 106111633;
extern const char* NAME_ELEMENT_INSTANCE_NODE__EXTRA;

const StringHash HASH_ELEMENT_NODE__NODE = 189997061;
extern const char* NAME_ELEMENT_NODE__NODE;

const StringHash HASH_ELEMENT_NODE__EXTRA = 86614321;
extern const char* NAME_ELEMENT_NODE__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_NODES__EXTRA = 11655665;
extern const char* NAME_ELEMENT_LIBRARY_NODES__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS = 144977635;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_MATERIALS = 144977635;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_MATERIALS;
struct library_physics_materials__AttributeData
{
    static const library_physics_materials__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__ASSET = 207189460;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__ASSET;

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL = 9537676;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL;
const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL = 9537676;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL;
struct physics_material__AttributeData
{
    static const physics_material__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__ASSET = 40910036;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL__ASSET;

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON = 99789790;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_DYNAMIC_FRICTION = 107186158;
extern const char* NAME_ELEMENT_DYNAMIC_FRICTION;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DYNAMIC_FRICTION = 107186158;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__DYNAMIC_FRICTION;
struct dynamic_friction__AttributeData
{
    static const dynamic_friction__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_RESTITUTION = 182855758;
extern const char* NAME_ELEMENT_RESTITUTION;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__RESTITUTION = 182855758;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__RESTITUTION;
struct restitution__AttributeData
{
    static const restitution__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_STATIC_FRICTION = 50283374;
extern const char* NAME_ELEMENT_STATIC_FRICTION;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__STATIC_FRICTION = 50283374;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__STATIC_FRICTION;
struct static_friction__AttributeData
{
    static const static_friction__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE = 218581653;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE;
typedef source__technique__AttributeData physics_material__technique__AttributeData;

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__EXTRA = 41184913;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA = 207431569;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS = 229674739;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_MODELS = 229674739;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_MODELS;
struct library_physics_models__AttributeData
{
    static const library_physics_models__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__ASSET = 158347956;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__ASSET;

const StringHash HASH_ELEMENT_PHYSICS_MODEL = 121224284;
extern const char* NAME_ELEMENT_PHYSICS_MODEL;
const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__PHYSICS_MODEL = 121224284;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__PHYSICS_MODEL;
struct physics_model__AttributeData
{
    static const physics_model__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_MODEL__ASSET = 51707876;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__ASSET;

const StringHash HASH_ELEMENT_RIGID_BODY = 230153993;
extern const char* NAME_ELEMENT_RIGID_BODY;
const StringHash HASH_ELEMENT_PHYSICS_MODEL__RIGID_BODY = 230153993;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__RIGID_BODY;
struct rigid_body__AttributeData
{
    static const rigid_body__AttributeData DEFAULT;

    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON = 140646974;
extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_DYNAMIC = 164030867;
extern const char* NAME_ELEMENT_DYNAMIC;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DYNAMIC = 164030867;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__DYNAMIC;
struct dynamic__AttributeData
{
    static const dynamic__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MASS = 178723971;
extern const char* NAME_ELEMENT_MASS;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS = 178723971;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS;
struct mass__AttributeData
{
    static const mass__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MASS_FRAME = 66755765;
extern const char* NAME_ELEMENT_MASS_FRAME;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME = 66755765;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME;

const StringHash HASH_ELEMENT_MASS_FRAME__TRANSLATE = 253554469;
extern const char* NAME_ELEMENT_MASS_FRAME__TRANSLATE;

const StringHash HASH_ELEMENT_MASS_FRAME__ROTATE = 206978181;
extern const char* NAME_ELEMENT_MASS_FRAME__ROTATE;

const StringHash HASH_ELEMENT_INERTIA = 235810961;
extern const char* NAME_ELEMENT_INERTIA;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INERTIA = 235810961;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INERTIA;
struct inertia__AttributeData
{
    static const inertia__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL = 110655340;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MATERIAL;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL = 110655340;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL;
struct instance_physics_material__AttributeData
{
    static const instance_physics_material__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA = 49406769;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA;

const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL = 200496492;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL;

const StringHash HASH_ELEMENT_SHAPE = 173779653;
extern const char* NAME_ELEMENT_SHAPE;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SHAPE = 173779653;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SHAPE;

const StringHash HASH_ELEMENT_HOLLOW = 203315751;
extern const char* NAME_ELEMENT_HOLLOW;
const StringHash HASH_ELEMENT_SHAPE__HOLLOW = 203315751;
extern const char* NAME_ELEMENT_SHAPE__HOLLOW;
struct hollow__AttributeData
{
    static const hollow__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SHAPE__MASS = 189649091;
extern const char* NAME_ELEMENT_SHAPE__MASS;

const StringHash HASH_ELEMENT_DENSITY = 71513209;
extern const char* NAME_ELEMENT_DENSITY;
const StringHash HASH_ELEMENT_SHAPE__DENSITY = 71513209;
extern const char* NAME_ELEMENT_SHAPE__DENSITY;
struct density__AttributeData
{
    static const density__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SHAPE__INSTANCE_PHYSICS_MATERIAL = 182289868;
extern const char* NAME_ELEMENT_SHAPE__INSTANCE_PHYSICS_MATERIAL;

const StringHash HASH_ELEMENT_SHAPE__PHYSICS_MATERIAL = 169447724;
extern const char* NAME_ELEMENT_SHAPE__PHYSICS_MATERIAL;

const StringHash HASH_ELEMENT_SHAPE__INSTANCE_GEOMETRY = 15221321;
extern const char* NAME_ELEMENT_SHAPE__INSTANCE_GEOMETRY;

const StringHash HASH_ELEMENT_PLANE = 83469045;
extern const char* NAME_ELEMENT_PLANE;
const StringHash HASH_ELEMENT_SHAPE__PLANE = 83469045;
extern const char* NAME_ELEMENT_SHAPE__PLANE;

const StringHash HASH_ELEMENT_EQUATION = 15986366;
extern const char* NAME_ELEMENT_EQUATION;
const StringHash HASH_ELEMENT_PLANE__EQUATION = 15986366;
extern const char* NAME_ELEMENT_PLANE__EQUATION;

const StringHash HASH_ELEMENT_PLANE__EXTRA = 70156081;
extern const char* NAME_ELEMENT_PLANE__EXTRA;

const StringHash HASH_ELEMENT_BOX = 112510952;
extern const char* NAME_ELEMENT_BOX;
const StringHash HASH_ELEMENT_SHAPE__BOX = 112510952;
extern const char* NAME_ELEMENT_SHAPE__BOX;

const StringHash HASH_ELEMENT_HALF_EXTENTS = 158729139;
extern const char* NAME_ELEMENT_HALF_EXTENTS;
const StringHash HASH_ELEMENT_BOX__HALF_EXTENTS = 158729139;
extern const char* NAME_ELEMENT_BOX__HALF_EXTENTS;

const StringHash HASH_ELEMENT_BOX__EXTRA = 89812321;
extern const char* NAME_ELEMENT_BOX__EXTRA;

const StringHash HASH_ELEMENT_SPHERE = 256804805;
extern const char* NAME_ELEMENT_SPHERE;
const StringHash HASH_ELEMENT_SHAPE__SPHERE = 256804805;
extern const char* NAME_ELEMENT_SHAPE__SPHERE;

const StringHash HASH_ELEMENT_RADIUS = 7028275;
extern const char* NAME_ELEMENT_RADIUS;
const StringHash HASH_ELEMENT_SPHERE__RADIUS = 7028275;
extern const char* NAME_ELEMENT_SPHERE__RADIUS;

const StringHash HASH_ELEMENT_SPHERE__EXTRA = 254948193;
extern const char* NAME_ELEMENT_SPHERE__EXTRA;

const StringHash HASH_ELEMENT_CYLINDER = 138741378;
extern const char* NAME_ELEMENT_CYLINDER;
const StringHash HASH_ELEMENT_SHAPE__CYLINDER = 138741378;
extern const char* NAME_ELEMENT_SHAPE__CYLINDER;

const StringHash HASH_ELEMENT_HEIGHT = 94864756;
extern const char* NAME_ELEMENT_HEIGHT;
const StringHash HASH_ELEMENT_CYLINDER__HEIGHT = 94864756;
extern const char* NAME_ELEMENT_CYLINDER__HEIGHT;

const StringHash HASH_ELEMENT_CYLINDER__RADIUS = 114026563;
extern const char* NAME_ELEMENT_CYLINDER__RADIUS;

const StringHash HASH_ELEMENT_CYLINDER__EXTRA = 140000257;
extern const char* NAME_ELEMENT_CYLINDER__EXTRA;

const StringHash HASH_ELEMENT_TAPERED_CYLINDER = 166506338;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER;
const StringHash HASH_ELEMENT_SHAPE__TAPERED_CYLINDER = 166506338;
extern const char* NAME_ELEMENT_SHAPE__TAPERED_CYLINDER;

const StringHash HASH_ELEMENT_TAPERED_CYLINDER__HEIGHT = 32307460;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER__HEIGHT;

const StringHash HASH_ELEMENT_RADIUS1 = 134955841;
extern const char* NAME_ELEMENT_RADIUS1;
const StringHash HASH_ELEMENT_TAPERED_CYLINDER__RADIUS1 = 134955841;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER__RADIUS1;

const StringHash HASH_ELEMENT_RADIUS2 = 134955842;
extern const char* NAME_ELEMENT_RADIUS2;
const StringHash HASH_ELEMENT_TAPERED_CYLINDER__RADIUS2 = 134955842;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER__RADIUS2;

const StringHash HASH_ELEMENT_TAPERED_CYLINDER__EXTRA = 253529025;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER__EXTRA;

const StringHash HASH_ELEMENT_CAPSULE = 117514469;
extern const char* NAME_ELEMENT_CAPSULE;
const StringHash HASH_ELEMENT_SHAPE__CAPSULE = 117514469;
extern const char* NAME_ELEMENT_SHAPE__CAPSULE;

const StringHash HASH_ELEMENT_CAPSULE__HEIGHT = 38254884;
extern const char* NAME_ELEMENT_CAPSULE__HEIGHT;

const StringHash HASH_ELEMENT_CAPSULE__RADIUS = 19657747;
extern const char* NAME_ELEMENT_CAPSULE__RADIUS;

const StringHash HASH_ELEMENT_CAPSULE__EXTRA = 220610497;
extern const char* NAME_ELEMENT_CAPSULE__EXTRA;

const StringHash HASH_ELEMENT_TAPERED_CAPSULE = 167503477;
extern const char* NAME_ELEMENT_TAPERED_CAPSULE;
const StringHash HASH_ELEMENT_SHAPE__TAPERED_CAPSULE = 167503477;
extern const char* NAME_ELEMENT_SHAPE__TAPERED_CAPSULE;

const StringHash HASH_ELEMENT_TAPERED_CAPSULE__HEIGHT = 177933284;
extern const char* NAME_ELEMENT_TAPERED_CAPSULE__HEIGHT;

const StringHash HASH_ELEMENT_TAPERED_CAPSULE__RADIUS1 = 259419633;
extern const char* NAME_ELEMENT_TAPERED_CAPSULE__RADIUS1;

const StringHash HASH_ELEMENT_TAPERED_CAPSULE__RADIUS2 = 259419634;
extern const char* NAME_ELEMENT_TAPERED_CAPSULE__RADIUS2;

const StringHash HASH_ELEMENT_TAPERED_CAPSULE__EXTRA = 28046561;
extern const char* NAME_ELEMENT_TAPERED_CAPSULE__EXTRA;

const StringHash HASH_ELEMENT_SHAPE__TRANSLATE = 49208741;
extern const char* NAME_ELEMENT_SHAPE__TRANSLATE;

const StringHash HASH_ELEMENT_SHAPE__ROTATE = 259965925;
extern const char* NAME_ELEMENT_SHAPE__ROTATE;

const StringHash HASH_ELEMENT_SHAPE__EXTRA = 79854897;
extern const char* NAME_ELEMENT_SHAPE__EXTRA;

const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE = 266093477;
extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE;
typedef source__technique__AttributeData rigid_body__technique__AttributeData;

const StringHash HASH_ELEMENT_RIGID_BODY__EXTRA = 259874209;
extern const char* NAME_ELEMENT_RIGID_BODY__EXTRA;

const StringHash HASH_ELEMENT_RIGID_CONSTRAINT = 118460596;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT;
const StringHash HASH_ELEMENT_PHYSICS_MODEL__RIGID_CONSTRAINT = 118460596;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__RIGID_CONSTRAINT;
struct rigid_constraint__AttributeData
{
    static const rigid_constraint__AttributeData DEFAULT;

    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_REF_ATTACHMENT = 166190372;
extern const char* NAME_ELEMENT_REF_ATTACHMENT;
const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__REF_ATTACHMENT = 166190372;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__REF_ATTACHMENT;
const StringHash HASH_ATTRIBUTE_RIGID_BODY = 262281833;
extern const char* NAME_ATTRIBUTE_RIGID_BODY;
struct ref_attachment__AttributeData
{
    static const ref_attachment__AttributeData DEFAULT;

    const ParserChar* rigid_body;
};

const StringHash HASH_ELEMENT_REF_ATTACHMENT__TRANSLATE = 20744357;
extern const char* NAME_ELEMENT_REF_ATTACHMENT__TRANSLATE;

const StringHash HASH_ELEMENT_REF_ATTACHMENT__ROTATE = 172940933;
extern const char* NAME_ELEMENT_REF_ATTACHMENT__ROTATE;

const StringHash HASH_ELEMENT_REF_ATTACHMENT__EXTRA = 43482337;
extern const char* NAME_ELEMENT_REF_ATTACHMENT__EXTRA;

const StringHash HASH_ELEMENT_ATTACHMENT = 183690788;
extern const char* NAME_ELEMENT_ATTACHMENT;
const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__ATTACHMENT = 183690788;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__ATTACHMENT;
struct attachment__AttributeData
{
    static const attachment__AttributeData DEFAULT;

    const ParserChar* rigid_body;
};

const StringHash HASH_ELEMENT_ATTACHMENT__TRANSLATE = 162060341;
extern const char* NAME_ELEMENT_ATTACHMENT__TRANSLATE;

const StringHash HASH_ELEMENT_ATTACHMENT__ROTATE = 256333637;
extern const char* NAME_ELEMENT_ATTACHMENT__ROTATE;

const StringHash HASH_ELEMENT_ATTACHMENT__EXTRA = 247981169;
extern const char* NAME_ELEMENT_ATTACHMENT__EXTRA;

const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON = 28989358;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ENABLED = 168114388;
extern const char* NAME_ELEMENT_ENABLED;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ENABLED = 168114388;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ENABLED;
struct enabled__AttributeData
{
    static const enabled__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INTERPENETRATE = 88979653;
extern const char* NAME_ELEMENT_INTERPENETRATE;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INTERPENETRATE = 88979653;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INTERPENETRATE;
struct interpenetrate__AttributeData
{
    static const interpenetrate__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIMITS = 118237715;
extern const char* NAME_ELEMENT_LIMITS;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__LIMITS = 118237715;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__LIMITS;

const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST = 23389540;
extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST;
const StringHash HASH_ELEMENT_LIMITS__SWING_CONE_AND_TWIST = 23389540;
extern const char* NAME_ELEMENT_LIMITS__SWING_CONE_AND_TWIST;

const StringHash HASH_ELEMENT_MIN = 185017758;
extern const char* NAME_ELEMENT_MIN;
const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MIN = 185017758;
extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MIN;
struct min__AttributeData
{
    static const min__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MAX = 185017832;
extern const char* NAME_ELEMENT_MAX;
const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MAX = 185017832;
extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MAX;
struct max__AttributeData
{
    static const max__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LINEAR = 108038914;
extern const char* NAME_ELEMENT_LINEAR;
const StringHash HASH_ELEMENT_LIMITS__LINEAR = 108038914;
extern const char* NAME_ELEMENT_LIMITS__LINEAR;

const StringHash HASH_ELEMENT_LINEAR__MIN = 135817038;
extern const char* NAME_ELEMENT_LINEAR__MIN;

const StringHash HASH_ELEMENT_LINEAR__MAX = 135817016;
extern const char* NAME_ELEMENT_LINEAR__MAX;

const StringHash HASH_ELEMENT_SPRING = 92514023;
extern const char* NAME_ELEMENT_SPRING;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPRING = 92514023;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPRING;

const StringHash HASH_ELEMENT_ANGULAR = 256544162;
extern const char* NAME_ELEMENT_ANGULAR;
const StringHash HASH_ELEMENT_SPRING__ANGULAR = 256544162;
extern const char* NAME_ELEMENT_SPRING__ANGULAR;

const StringHash HASH_ELEMENT_STIFFNESS = 13552163;
extern const char* NAME_ELEMENT_STIFFNESS;
const StringHash HASH_ELEMENT_ANGULAR__STIFFNESS = 13552163;
extern const char* NAME_ELEMENT_ANGULAR__STIFFNESS;
struct stiffness__AttributeData
{
    static const stiffness__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_DAMPING = 107704311;
extern const char* NAME_ELEMENT_DAMPING;
const StringHash HASH_ELEMENT_ANGULAR__DAMPING = 107704311;
extern const char* NAME_ELEMENT_ANGULAR__DAMPING;
struct damping__AttributeData
{
    static const damping__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TARGET_VALUE = 33955429;
extern const char* NAME_ELEMENT_TARGET_VALUE;
const StringHash HASH_ELEMENT_ANGULAR__TARGET_VALUE = 33955429;
extern const char* NAME_ELEMENT_ANGULAR__TARGET_VALUE;
struct target_value__AttributeData
{
    static const target_value__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SPRING__LINEAR = 62916466;
extern const char* NAME_ELEMENT_SPRING__LINEAR;

const StringHash HASH_ELEMENT_LINEAR__STIFFNESS = 131408563;
extern const char* NAME_ELEMENT_LINEAR__STIFFNESS;

const StringHash HASH_ELEMENT_LINEAR__DAMPING = 249329687;
extern const char* NAME_ELEMENT_LINEAR__DAMPING;

const StringHash HASH_ELEMENT_LINEAR__TARGET_VALUE = 9408485;
extern const char* NAME_ELEMENT_LINEAR__TARGET_VALUE;

const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE = 71550805;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE;
typedef source__technique__AttributeData rigid_constraint__technique__AttributeData;

const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__EXTRA = 117024337;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL = 133635772;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL;
const StringHash HASH_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL = 133635772;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL;
const StringHash HASH_ATTRIBUTE_PARENT = 124292180;
extern const char* NAME_ATTRIBUTE_PARENT;
struct instance_physics_model__AttributeData
{
    static const instance_physics_model__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
    const ParserChar* parent;
};

const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD = 38290564;
extern const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD;
const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD = 38290564;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD;
struct instance_force_field__AttributeData
{
    static const instance_force_field__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA = 267250353;
extern const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY = 204998505;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY;
const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_BODY = 204998505;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_BODY;
const StringHash HASH_ATTRIBUTE_BODY = 431545;
extern const char* NAME_ATTRIBUTE_BODY;
struct instance_rigid_body__AttributeData
{
    static const instance_rigid_body__AttributeData DEFAULT;

    const ParserChar* body;
    const ParserChar* sid;
    const ParserChar* name;
    const ParserChar* target;
};

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON = 107721262;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ANGULAR_VELOCITY = 180078265;
extern const char* NAME_ELEMENT_ANGULAR_VELOCITY;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ANGULAR_VELOCITY = 180078265;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ANGULAR_VELOCITY;

const StringHash HASH_ELEMENT_VELOCITY = 2049353;
extern const char* NAME_ELEMENT_VELOCITY;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__VELOCITY = 2049353;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__VELOCITY;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE = 205322533;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE;
typedef source__technique__AttributeData instance_rigid_body__technique__AttributeData;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__EXTRA = 264756801;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT = 110069972;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_CONSTRAINT;
const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_CONSTRAINT = 110069972;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_RIGID_CONSTRAINT;
const StringHash HASH_ATTRIBUTE_CONSTRAINT = 180279812;
extern const char* NAME_ATTRIBUTE_CONSTRAINT;
struct instance_rigid_constraint__AttributeData
{
    static const instance_rigid_constraint__AttributeData DEFAULT;

    const ParserChar* constraint;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT__EXTRA = 105326065;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_CONSTRAINT__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA = 189441489;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA;

const StringHash HASH_ELEMENT_PHYSICS_MODEL__EXTRA = 51424673;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA = 158621937;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES = 252486147;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_SCENES = 252486147;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_SCENES;
struct library_physics_scenes__AttributeData
{
    static const library_physics_scenes__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__ASSET = 112385460;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__ASSET;

const StringHash HASH_ELEMENT_PHYSICS_SCENE = 100496229;
extern const char* NAME_ELEMENT_PHYSICS_SCENE;
const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__PHYSICS_SCENE = 100496229;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__PHYSICS_SCENE;
struct physics_scene__AttributeData
{
    static const physics_scene__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_SCENE__ASSET = 63501172;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__ASSET;

const StringHash HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD = 33737508;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD;

const StringHash HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL = 16473708;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL;

const StringHash HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON = 53159934;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_GRAVITY = 214596313;
extern const char* NAME_ELEMENT_GRAVITY;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__GRAVITY = 214596313;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__GRAVITY;
struct gravity__AttributeData
{
    static const gravity__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TIME_STEP = 18674176;
extern const char* NAME_ELEMENT_TIME_STEP;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__TIME_STEP = 18674176;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__TIME_STEP;
struct time_step__AttributeData
{
    static const time_step__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE = 57209429;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__TECHNIQUE;
typedef source__technique__AttributeData physics_scene__technique__AttributeData;

const StringHash HASH_ELEMENT_PHYSICS_SCENE__EXTRA = 63742257;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA = 112627697;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES = 216719139;
extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_VISUAL_SCENES = 216719139;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_VISUAL_SCENES;
struct library_visual_scenes__AttributeData
{
    static const library_visual_scenes__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__ASSET = 115825748;
extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__ASSET;

const StringHash HASH_ELEMENT_VISUAL_SCENE = 220621413;
extern const char* NAME_ELEMENT_VISUAL_SCENE;
const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__VISUAL_SCENE = 220621413;
extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__VISUAL_SCENE;
struct visual_scene__AttributeData
{
    static const visual_scene__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_VISUAL_SCENE__ASSET = 13350196;
extern const char* NAME_ELEMENT_VISUAL_SCENE__ASSET;

const StringHash HASH_ELEMENT_VISUAL_SCENE__NODE = 252544101;
extern const char* NAME_ELEMENT_VISUAL_SCENE__NODE;

const StringHash HASH_ELEMENT_EVALUATE_SCENE = 145043477;
extern const char* NAME_ELEMENT_EVALUATE_SCENE;
const StringHash HASH_ELEMENT_VISUAL_SCENE__EVALUATE_SCENE = 145043477;
extern const char* NAME_ELEMENT_VISUAL_SCENE__EVALUATE_SCENE;
struct evaluate_scene__AttributeData
{
    static const evaluate_scene__AttributeData DEFAULT;

    const ParserChar* name;
};

const StringHash HASH_ELEMENT_RENDER = 212755570;
extern const char* NAME_ELEMENT_RENDER;
const StringHash HASH_ELEMENT_EVALUATE_SCENE__RENDER = 212755570;
extern const char* NAME_ELEMENT_EVALUATE_SCENE__RENDER;
const StringHash HASH_ATTRIBUTE_CAMERA_NODE = 136173157;
extern const char* NAME_ATTRIBUTE_CAMERA_NODE;
struct render__AttributeData
{
    static const render__AttributeData DEFAULT;

    const ParserChar* camera_node;
};

const StringHash HASH_ELEMENT_LAYER = 228991954;
extern const char* NAME_ELEMENT_LAYER;
const StringHash HASH_ELEMENT_RENDER__LAYER = 228991954;
extern const char* NAME_ELEMENT_RENDER__LAYER;

const StringHash HASH_ELEMENT_RENDER__INSTANCE_EFFECT = 50798276;
extern const char* NAME_ELEMENT_RENDER__INSTANCE_EFFECT;

const StringHash HASH_ELEMENT_VISUAL_SCENE__EXTRA = 13625201;
extern const char* NAME_ELEMENT_VISUAL_SCENE__EXTRA;

const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA = 115543569;
extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA;

const StringHash HASH_ELEMENT_SCENE = 24758453;
extern const char* NAME_ELEMENT_SCENE;
const StringHash HASH_ELEMENT_COLLADA__SCENE = 24758453;
extern const char* NAME_ELEMENT_COLLADA__SCENE;

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_SCENE = 10609013;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_SCENE;
const StringHash HASH_ELEMENT_SCENE__INSTANCE_PHYSICS_SCENE = 10609013;
extern const char* NAME_ELEMENT_SCENE__INSTANCE_PHYSICS_SCENE;
struct instance_physics_scene__AttributeData
{
    static const instance_physics_scene__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_SCENE__EXTRA = 200714369;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_SCENE__EXTRA;

const StringHash HASH_ELEMENT_INSTANCE_VISUAL_SCENE = 177061637;
extern const char* NAME_ELEMENT_INSTANCE_VISUAL_SCENE;
const StringHash HASH_ELEMENT_SCENE__INSTANCE_VISUAL_SCENE = 177061637;
extern const char* NAME_ELEMENT_SCENE__INSTANCE_VISUAL_SCENE;
struct instance_visual_scene__AttributeData
{
    static const instance_visual_scene__AttributeData DEFAULT;

    const ParserChar* url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_VISUAL_SCENE__EXTRA = 105662417;
extern const char* NAME_ELEMENT_INSTANCE_VISUAL_SCENE__EXTRA;

const StringHash HASH_ELEMENT_SCENE__EXTRA = 80035633;
extern const char* NAME_ELEMENT_SCENE__EXTRA;

const StringHash HASH_ELEMENT_COLLADA__EXTRA = 21800817;
extern const char* NAME_ELEMENT_COLLADA__EXTRA;



}
#endif
