/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGENATTRIBUTES_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGENATTRIBUTES_H__


#include "COLLADASaxFWLColladaParserAutoGenEnums.h"


namespace COLLADASaxFWL
{


const StringHash HASH_ELEMENT_COLLADA = 138479041;
extern const char* NAME_ELEMENT_COLLADA;
const StringHash HASH_ATTRIBUTE_VERSION = 214540334;
extern const char* NAME_ATTRIBUTE_VERSION;
const StringHash HASH_ATTRIBUTE_BASE = 428181;
extern const char* NAME_ATTRIBUTE_BASE;
struct COLLADA__AttributeData
{
    static const COLLADA__AttributeData DEFAULT;

    ENUM__VersionType version;
    COLLADABU::URI base;
};

const StringHash HASH_ELEMENT_ASSET = 6859204;
extern const char* NAME_ELEMENT_ASSET;
const StringHash HASH_ELEMENT_COLLADA__ASSET = 21558580;
extern const char* NAME_ELEMENT_COLLADA__ASSET;

const StringHash HASH_ELEMENT_CONTRIBUTOR = 143896786;
extern const char* NAME_ELEMENT_CONTRIBUTOR;
const StringHash HASH_ELEMENT_ASSET__CONTRIBUTOR = 187503730;
extern const char* NAME_ELEMENT_ASSET__CONTRIBUTOR;

const StringHash HASH_ELEMENT_AUTHOR = 109883234;
extern const char* NAME_ELEMENT_AUTHOR;
const StringHash HASH_ELEMENT_CONTRIBUTOR__AUTHOR = 104615810;
extern const char* NAME_ELEMENT_CONTRIBUTOR__AUTHOR;

const StringHash HASH_ELEMENT_AUTHORING_TOOL = 142204124;
extern const char* NAME_ELEMENT_AUTHORING_TOOL;
const StringHash HASH_ELEMENT_CONTRIBUTOR__AUTHORING_TOOL = 144260236;
extern const char* NAME_ELEMENT_CONTRIBUTOR__AUTHORING_TOOL;

const StringHash HASH_ELEMENT_COMMENTS = 105104147;
extern const char* NAME_ELEMENT_COMMENTS;
const StringHash HASH_ELEMENT_CONTRIBUTOR__COMMENTS = 115565443;
extern const char* NAME_ELEMENT_CONTRIBUTOR__COMMENTS;

const StringHash HASH_ELEMENT_COPYRIGHT = 134780820;
extern const char* NAME_ELEMENT_COPYRIGHT;
const StringHash HASH_ELEMENT_CONTRIBUTOR__COPYRIGHT = 168205972;
extern const char* NAME_ELEMENT_CONTRIBUTOR__COPYRIGHT;

const StringHash HASH_ELEMENT_SOURCE_DATA = 166708257;
extern const char* NAME_ELEMENT_SOURCE_DATA;
const StringHash HASH_ELEMENT_CONTRIBUTOR__SOURCE_DATA = 134662689;
extern const char* NAME_ELEMENT_CONTRIBUTOR__SOURCE_DATA;

const StringHash HASH_ELEMENT_CREATED = 176917204;
extern const char* NAME_ELEMENT_CREATED;
const StringHash HASH_ELEMENT_ASSET__CREATED = 1517924;
extern const char* NAME_ELEMENT_ASSET__CREATED;

const StringHash HASH_ELEMENT_KEYWORDS = 219049891;
extern const char* NAME_ELEMENT_KEYWORDS;
const StringHash HASH_ELEMENT_ASSET__KEYWORDS = 113792515;
extern const char* NAME_ELEMENT_ASSET__KEYWORDS;

const StringHash HASH_ELEMENT_MODIFIED = 95406324;
extern const char* NAME_ELEMENT_MODIFIED;
const StringHash HASH_ELEMENT_ASSET__MODIFIED = 208007444;
extern const char* NAME_ELEMENT_ASSET__MODIFIED;

const StringHash HASH_ELEMENT_REVISION = 214997470;
extern const char* NAME_ELEMENT_REVISION;
const StringHash HASH_ELEMENT_ASSET__REVISION = 85631614;
extern const char* NAME_ELEMENT_ASSET__REVISION;

const StringHash HASH_ELEMENT_SUBJECT = 179899348;
extern const char* NAME_ELEMENT_SUBJECT;
const StringHash HASH_ELEMENT_ASSET__SUBJECT = 2467908;
extern const char* NAME_ELEMENT_ASSET__SUBJECT;

const StringHash HASH_ELEMENT_TITLE = 8063781;
extern const char* NAME_ELEMENT_TITLE;
const StringHash HASH_ELEMENT_ASSET__TITLE = 65116037;
extern const char* NAME_ELEMENT_ASSET__TITLE;

const StringHash HASH_ELEMENT_UNIT = 509188;
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

    float meter;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_UP_AXIS = 207982451;
extern const char* NAME_ELEMENT_UP_AXIS;
const StringHash HASH_ELEMENT_ASSET__UP_AXIS = 114896611;
extern const char* NAME_ELEMENT_ASSET__UP_AXIS;

const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS = 223353555;
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

const StringHash HASH_ELEMENT_ANIMATION = 3721230;
extern const char* NAME_ELEMENT_ANIMATION;
const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__ANIMATION = 56293822;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__ANIMATION;
struct animation__AttributeData
{
    static const animation__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_SOURCE = 128370837;
extern const char* NAME_ELEMENT_SOURCE;
const StringHash HASH_ELEMENT_ANIMATION__SOURCE = 242146325;
extern const char* NAME_ELEMENT_ANIMATION__SOURCE;
struct source__AttributeData
{
    static const source__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_IDREF_ARRAY = 202706457;
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
    uint64 count;
};

const StringHash HASH_ELEMENT_NAME_ARRAY = 190697657;
extern const char* NAME_ELEMENT_NAME_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__NAME_ARRAY = 95291433;
extern const char* NAME_ELEMENT_SOURCE__NAME_ARRAY;
struct Name_array__AttributeData
{
    static const Name_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    uint64 count;
};

const StringHash HASH_ELEMENT_BOOL_ARRAY = 39718633;
extern const char* NAME_ELEMENT_BOOL_ARRAY;
const StringHash HASH_ELEMENT_SOURCE__BOOL_ARRAY = 11257449;
extern const char* NAME_ELEMENT_SOURCE__BOOL_ARRAY;
struct bool_array__AttributeData
{
    static const bool_array__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
    uint64 count;
};

const StringHash HASH_ELEMENT_FLOAT_ARRAY = 171289865;
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
    uint64 count;
    sint16 digits;
    sint16 magnitude;
};

const StringHash HASH_ELEMENT_INT_ARRAY = 173598937;
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
    uint64 count;
    sint64 minInclusive;
    sint64 maxInclusive;
};

const StringHash HASH_ELEMENT_ANIMATION__SOURCE__TECHNIQUE_COMMON = 154067054;
extern const char* NAME_ELEMENT_ANIMATION__SOURCE__TECHNIQUE_COMMON;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON = 181609502;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON;
const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE_COMMON = 73854190;
extern const char* NAME_ELEMENT_SOURCE__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ACCESSOR = 161263634;
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

    uint64 count;
    uint64 offset;
    COLLADABU::URI source;
    uint64 stride;
};

const StringHash HASH_ELEMENT_PARAM = 7768189;
extern const char* NAME_ELEMENT_PARAM;
const StringHash HASH_ELEMENT_ACCESSOR__PARAM = 246253965;
extern const char* NAME_ELEMENT_ACCESSOR__PARAM;
const StringHash HASH_ATTRIBUTE_SID = 31220;
extern const char* NAME_ATTRIBUTE_SID;
const StringHash HASH_ATTRIBUTE_SEMANTIC = 205020515;
extern const char* NAME_ATTRIBUTE_SEMANTIC;
const StringHash HASH_ATTRIBUTE_TYPE = 508005;
extern const char* NAME_ATTRIBUTE_TYPE;
struct param__AttributeData
{
    static const param__AttributeData DEFAULT;

    const ParserChar* name;
    const ParserChar* sid;
    const ParserChar* semantic;
    const ParserChar* type;
};

const StringHash HASH_ELEMENT_TECHNIQUE = 167080453;
extern const char* NAME_ELEMENT_TECHNIQUE;
const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE = 1838725;
extern const char* NAME_ELEMENT_SOURCE__TECHNIQUE;
const StringHash HASH_ATTRIBUTE_PROFILE = 127258709;
extern const char* NAME_ATTRIBUTE_PROFILE;
struct technique__AttributeData
{
    static const technique__AttributeData DEFAULT;

    const ParserChar* profile;
};

const StringHash HASH_ELEMENT_SAMPLER = 159675058;
extern const char* NAME_ELEMENT_SAMPLER;
const StringHash HASH_ELEMENT_ANIMATION__SAMPLER = 101005858;
extern const char* NAME_ELEMENT_ANIMATION__SAMPLER;
struct sampler__AttributeData
{
    static const sampler__AttributeData DEFAULT;

    const ParserChar* id;
};

const StringHash HASH_ELEMENT_INPUT____INPUTLOCAL = 162993740;
extern const char* NAME_ELEMENT_INPUT____INPUTLOCAL;
const StringHash HASH_ELEMENT_INPUT = 7362500;
extern const char* NAME_ELEMENT_INPUT;
const StringHash HASH_ELEMENT_SAMPLER__INPUT = 219774004;
extern const char* NAME_ELEMENT_SAMPLER__INPUT;
struct input____InputLocal__AttributeData
{
    static const input____InputLocal__AttributeData DEFAULT;

    const ParserChar* semantic;
    const ParserChar* source;
};

const StringHash HASH_ELEMENT_CHANNEL = 166221020;
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

const StringHash HASH_ELEMENT_EXTRA = 7142273;
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

const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS = 210579923;
extern const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_ANIMATION_CLIPS = 95259907;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_ANIMATION_CLIPS;
struct library_animation_clips__AttributeData
{
    static const library_animation_clips__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_ANIMATION_CLIP = 21376896;
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
    float start;
    float end;
};

const StringHash HASH_ELEMENT_INSTANCE_ANIMATION = 228086430;
extern const char* NAME_ELEMENT_INSTANCE_ANIMATION;
const StringHash HASH_ELEMENT_ANIMATION_CLIP__INSTANCE_ANIMATION = 155834222;
extern const char* NAME_ELEMENT_ANIMATION_CLIP__INSTANCE_ANIMATION;
const StringHash HASH_ATTRIBUTE_URL = 31884;
extern const char* NAME_ATTRIBUTE_URL;
struct instance_animation__AttributeData
{
    static const instance_animation__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_CAMERAS = 17507619;
extern const char* NAME_ELEMENT_LIBRARY_CAMERAS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_CAMERAS = 203031923;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_CAMERAS;
struct library_cameras__AttributeData
{
    static const library_cameras__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_CAMERA = 110640257;
extern const char* NAME_ELEMENT_CAMERA;
const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__CAMERA = 246617809;
extern const char* NAME_ELEMENT_LIBRARY_CAMERAS__CAMERA;
struct camera__AttributeData
{
    static const camera__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_OPTICS = 124235683;
extern const char* NAME_ELEMENT_OPTICS;
const StringHash HASH_ELEMENT_CAMERA__OPTICS = 240856643;
extern const char* NAME_ELEMENT_CAMERA__OPTICS;

const StringHash HASH_ELEMENT_OPTICS__TECHNIQUE_COMMON = 170249678;
extern const char* NAME_ELEMENT_OPTICS__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ORTHOGRAPHIC = 165790115;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ORTHOGRAPHIC = 163965699;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ORTHOGRAPHIC;

const StringHash HASH_ELEMENT_XMAG = 521079;
extern const char* NAME_ELEMENT_XMAG;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__XMAG = 45560535;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__XMAG;
struct xmag__AttributeData
{
    static const xmag__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_YMAG = 525175;
extern const char* NAME_ELEMENT_YMAG;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__YMAG = 45564631;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__YMAG;
struct ymag__AttributeData
{
    static const ymag__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ASPECT_RATIO = 14868815;
extern const char* NAME_ELEMENT_ASPECT_RATIO;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO = 237192175;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ASPECT_RATIO;
struct aspect_ratio__AttributeData
{
    static const aspect_ratio__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ZNEAR = 8473474;
extern const char* NAME_ELEMENT_ZNEAR;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZNEAR = 193810850;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ZNEAR;
struct znear__AttributeData
{
    static const znear__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ZFAR = 527490;
extern const char* NAME_ELEMENT_ZFAR;
const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZFAR = 45665570;
extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ZFAR;
struct zfar__AttributeData
{
    static const zfar__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PERSPECTIVE = 114063717;
extern const char* NAME_ELEMENT_PERSPECTIVE;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__PERSPECTIVE = 216939461;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__PERSPECTIVE;

const StringHash HASH_ELEMENT_XFOV = 519526;
extern const char* NAME_ELEMENT_XFOV;
const StringHash HASH_ELEMENT_PERSPECTIVE__XFOV = 228234758;
extern const char* NAME_ELEMENT_PERSPECTIVE__XFOV;
struct xfov__AttributeData
{
    static const xfov__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_YFOV = 523622;
extern const char* NAME_ELEMENT_YFOV;
const StringHash HASH_ELEMENT_PERSPECTIVE__YFOV = 228230662;
extern const char* NAME_ELEMENT_PERSPECTIVE__YFOV;
struct yfov__AttributeData
{
    static const yfov__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_IMAGER = 117669314;
extern const char* NAME_ELEMENT_IMAGER;
const StringHash HASH_ELEMENT_CAMERA__IMAGER = 232782882;
extern const char* NAME_ELEMENT_CAMERA__IMAGER;

const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS = 117752259;
extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_CONTROLLERS = 113250531;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_CONTROLLERS;
struct library_controllers__AttributeData
{
    static const library_controllers__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_CONTROLLER = 194286738;
extern const char* NAME_ELEMENT_CONTROLLER;
const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__CONTROLLER = 199579458;
extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__CONTROLLER;
struct controller__AttributeData
{
    static const controller__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_SKIN = 500222;
extern const char* NAME_ELEMENT_SKIN;
const StringHash HASH_ELEMENT_CONTROLLER__SKIN = 232920430;
extern const char* NAME_ELEMENT_CONTROLLER__SKIN;
struct skin__AttributeData
{
    static const skin__AttributeData DEFAULT;

    COLLADABU::URI source;
};

const StringHash HASH_ELEMENT_BIND_SHAPE_MATRIX = 80689944;
extern const char* NAME_ELEMENT_BIND_SHAPE_MATRIX;
const StringHash HASH_ELEMENT_SKIN__BIND_SHAPE_MATRIX = 126147416;
extern const char* NAME_ELEMENT_SKIN__BIND_SHAPE_MATRIX;

const StringHash HASH_ELEMENT_JOINTS = 118883763;
extern const char* NAME_ELEMENT_JOINTS;
const StringHash HASH_ELEMENT_SKIN__JOINTS = 62390755;
extern const char* NAME_ELEMENT_SKIN__JOINTS;

const StringHash HASH_ELEMENT_VERTEX_WEIGHTS = 19207187;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS;
const StringHash HASH_ELEMENT_SKIN__VERTEX_WEIGHTS = 52511411;
extern const char* NAME_ELEMENT_SKIN__VERTEX_WEIGHTS;
struct vertex_weights__AttributeData
{
    static const vertex_weights__AttributeData DEFAULT;

    uint64 count;
};

const StringHash HASH_ELEMENT_INPUT____INPUTLOCALOFFSET = 183226260;
extern const char* NAME_ELEMENT_INPUT____INPUTLOCALOFFSET;
const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__INPUT = 118429284;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__INPUT;
const StringHash HASH_ATTRIBUTE_SET = 31172;
extern const char* NAME_ATTRIBUTE_SET;
struct input____InputLocalOffset__AttributeData
{
    static const input____InputLocalOffset__AttributeData DEFAULT;

    uint64 offset;
    const ParserChar* semantic;
    const ParserChar* source;
    uint64 set;
};

const StringHash HASH_ELEMENT_VCOUNT = 130706516;
extern const char* NAME_ELEMENT_VCOUNT;
const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__VCOUNT = 64909860;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__VCOUNT;

const StringHash HASH_ELEMENT_V = 118;
extern const char* NAME_ELEMENT_V;
const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__V = 21079862;
extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__V;

const StringHash HASH_ELEMENT_MORPH = 7629160;
extern const char* NAME_ELEMENT_MORPH;
const StringHash HASH_ELEMENT_CONTROLLER__MORPH = 237707448;
extern const char* NAME_ELEMENT_CONTROLLER__MORPH;
const StringHash HASH_ATTRIBUTE_METHOD = 121417556;
extern const char* NAME_ATTRIBUTE_METHOD;
struct morph__AttributeData
{
    static const morph__AttributeData DEFAULT;

    ENUM__MorphMethodType method;
    COLLADABU::URI source;
};

const StringHash HASH_ELEMENT_TARGETS = 176741571;
extern const char* NAME_ELEMENT_TARGETS;
const StringHash HASH_ELEMENT_MORPH__TARGETS = 203307155;
extern const char* NAME_ELEMENT_MORPH__TARGETS;

const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES = 219269923;
extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_GEOMETRIES = 252969491;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_GEOMETRIES;
struct library_geometries__AttributeData
{
    static const library_geometries__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_GEOMETRY = 207867209;
extern const char* NAME_ELEMENT_GEOMETRY;
const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__GEOMETRY = 25538441;
extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__GEOMETRY;
struct geometry__AttributeData
{
    static const geometry__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_CONVEX_MESH = 214980952;
extern const char* NAME_ELEMENT_CONVEX_MESH;
const StringHash HASH_ELEMENT_GEOMETRY__CONVEX_MESH = 264547688;
extern const char* NAME_ELEMENT_GEOMETRY__CONVEX_MESH;
const StringHash HASH_ATTRIBUTE_CONVEX_HULL_OF = 167766694;
extern const char* NAME_ATTRIBUTE_CONVEX_HULL_OF;
struct convex_mesh__AttributeData
{
    static const convex_mesh__AttributeData DEFAULT;

    COLLADABU::URI convex_hull_of;
};

const StringHash HASH_ELEMENT_VERTICES = 211484163;
extern const char* NAME_ELEMENT_VERTICES;
const StringHash HASH_ELEMENT_CONVEX_MESH__VERTICES = 97017683;
extern const char* NAME_ELEMENT_CONVEX_MESH__VERTICES;
struct vertices__AttributeData
{
    static const vertices__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LINES = 7537859;
extern const char* NAME_ELEMENT_LINES;
const StringHash HASH_ELEMENT_CONVEX_MESH__LINES = 174551523;
extern const char* NAME_ELEMENT_CONVEX_MESH__LINES;
const StringHash HASH_ATTRIBUTE_MATERIAL = 145524812;
extern const char* NAME_ATTRIBUTE_MATERIAL;
struct lines__AttributeData
{
    static const lines__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_P = 112;
extern const char* NAME_ELEMENT_P;
const StringHash HASH_ELEMENT_LINES__P = 5018704;
extern const char* NAME_ELEMENT_LINES__P;

const StringHash HASH_ELEMENT_LINESTRIPS = 212647987;
extern const char* NAME_ELEMENT_LINESTRIPS;
const StringHash HASH_ELEMENT_CONVEX_MESH__LINESTRIPS = 235800419;
extern const char* NAME_ELEMENT_CONVEX_MESH__LINESTRIPS;
struct linestrips__AttributeData
{
    static const linestrips__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_POLYGONS = 104850211;
extern const char* NAME_ELEMENT_POLYGONS;
const StringHash HASH_ELEMENT_CONVEX_MESH__POLYGONS = 225281043;
extern const char* NAME_ELEMENT_CONVEX_MESH__POLYGONS;
struct polygons__AttributeData
{
    static const polygons__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_PH = 1896;
extern const char* NAME_ELEMENT_PH;
const StringHash HASH_ELEMENT_POLYGONS__PH = 53447048;
extern const char* NAME_ELEMENT_POLYGONS__PH;

const StringHash HASH_ELEMENT_H = 104;
extern const char* NAME_ELEMENT_H;
const StringHash HASH_ELEMENT_PH__H = 7791960;
extern const char* NAME_ELEMENT_PH__H;

const StringHash HASH_ELEMENT_POLYLIST = 104871892;
extern const char* NAME_ELEMENT_POLYLIST;
const StringHash HASH_ELEMENT_CONVEX_MESH__POLYLIST = 225351396;
extern const char* NAME_ELEMENT_CONVEX_MESH__POLYLIST;
struct polylist__AttributeData
{
    static const polylist__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_TRIANGLES = 260356419;
extern const char* NAME_ELEMENT_TRIANGLES;
const StringHash HASH_ELEMENT_CONVEX_MESH__TRIANGLES = 175033555;
extern const char* NAME_ELEMENT_CONVEX_MESH__TRIANGLES;
struct triangles__AttributeData
{
    static const triangles__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_TRIFANS = 193972259;
extern const char* NAME_ELEMENT_TRIFANS;
const StringHash HASH_ELEMENT_CONVEX_MESH__TRIFANS = 236645939;
extern const char* NAME_ELEMENT_CONVEX_MESH__TRIFANS;
struct trifans__AttributeData
{
    static const trifans__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_TRISTRIPS = 11275235;
extern const char* NAME_ELEMENT_TRISTRIPS;
const StringHash HASH_ELEMENT_CONVEX_MESH__TRISTRIPS = 92405331;
extern const char* NAME_ELEMENT_CONVEX_MESH__TRISTRIPS;
struct tristrips__AttributeData
{
    static const tristrips__AttributeData DEFAULT;

    const ParserChar* name;
    uint64 count;
    const ParserChar* material;
};

const StringHash HASH_ELEMENT_MESH = 474264;
extern const char* NAME_ELEMENT_MESH;
const StringHash HASH_ELEMENT_GEOMETRY__MESH = 53998040;
extern const char* NAME_ELEMENT_GEOMETRY__MESH;

const StringHash HASH_ELEMENT_SPLINE = 128397381;
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

const StringHash HASH_ELEMENT_CONTROL_VERTICES = 118372691;
extern const char* NAME_ELEMENT_CONTROL_VERTICES;
const StringHash HASH_ELEMENT_SPLINE__CONTROL_VERTICES = 152193299;
extern const char* NAME_ELEMENT_SPLINE__CONTROL_VERTICES;

const StringHash HASH_ELEMENT_LIBRARY_EFFECTS = 38033171;
extern const char* NAME_ELEMENT_LIBRARY_EFFECTS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_EFFECTS = 246773571;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_EFFECTS;
struct library_effects__AttributeData
{
    static const library_effects__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_EFFECT = 113036196;
extern const char* NAME_ELEMENT_EFFECT;
const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__EFFECT = 32231604;
extern const char* NAME_ELEMENT_LIBRARY_EFFECTS__EFFECT;
struct effect__AttributeData
{
    static const effect__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_ANNOTATE = 89566757;
extern const char* NAME_ELEMENT_ANNOTATE;
const StringHash HASH_ELEMENT_EFFECT__ANNOTATE = 17277301;
extern const char* NAME_ELEMENT_EFFECT__ANNOTATE;
struct annotate__AttributeData
{
    static const annotate__AttributeData DEFAULT;

    const ParserChar* name;
};

const StringHash HASH_ELEMENT_BOOL____BOOL = 65271820;
extern const char* NAME_ELEMENT_BOOL____BOOL;
const StringHash HASH_ELEMENT_BOOL = 431708;
extern const char* NAME_ELEMENT_BOOL;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL = 2309228;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL;

const StringHash HASH_ELEMENT_BOOL2____BOOL2 = 50914834;
extern const char* NAME_ELEMENT_BOOL2____BOOL2;
const StringHash HASH_ELEMENT_BOOL2 = 6907378;
extern const char* NAME_ELEMENT_BOOL2;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL2 = 36947698;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL2;

const StringHash HASH_ELEMENT_BOOL3____BOOL3 = 50910739;
extern const char* NAME_ELEMENT_BOOL3____BOOL3;
const StringHash HASH_ELEMENT_BOOL3 = 6907379;
extern const char* NAME_ELEMENT_BOOL3;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL3 = 36947699;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL3;

const StringHash HASH_ELEMENT_BOOL4____BOOL4 = 50923028;
extern const char* NAME_ELEMENT_BOOL4____BOOL4;
const StringHash HASH_ELEMENT_BOOL4 = 6907380;
extern const char* NAME_ELEMENT_BOOL4;
const StringHash HASH_ELEMENT_ANNOTATE__BOOL4 = 36947700;
extern const char* NAME_ELEMENT_ANNOTATE__BOOL4;

const StringHash HASH_ELEMENT_INT____INT = 89414644;
extern const char* NAME_ELEMENT_INT____INT;
const StringHash HASH_ELEMENT_INT = 28756;
extern const char* NAME_ELEMENT_INT;
const StringHash HASH_ELEMENT_ANNOTATE__INT = 50476724;
extern const char* NAME_ELEMENT_ANNOTATE__INT;

const StringHash HASH_ELEMENT_INT2____INT2 = 72391970;
extern const char* NAME_ELEMENT_INT2____INT2;
const StringHash HASH_ELEMENT_INT2 = 460146;
extern const char* NAME_ELEMENT_INT2;
const StringHash HASH_ELEMENT_ANNOTATE__INT2 = 2321218;
extern const char* NAME_ELEMENT_ANNOTATE__INT2;

const StringHash HASH_ELEMENT_INT3____INT3 = 72391715;
extern const char* NAME_ELEMENT_INT3____INT3;
const StringHash HASH_ELEMENT_INT3 = 460147;
extern const char* NAME_ELEMENT_INT3;
const StringHash HASH_ELEMENT_ANNOTATE__INT3 = 2321219;
extern const char* NAME_ELEMENT_ANNOTATE__INT3;

const StringHash HASH_ELEMENT_INT4____INT4 = 72392484;
extern const char* NAME_ELEMENT_INT4____INT4;
const StringHash HASH_ELEMENT_INT4 = 460148;
extern const char* NAME_ELEMENT_INT4;
const StringHash HASH_ELEMENT_ANNOTATE__INT4 = 2321220;
extern const char* NAME_ELEMENT_ANNOTATE__INT4;

const StringHash HASH_ELEMENT_FLOAT____FLOAT = 134583844;
extern const char* NAME_ELEMENT_FLOAT____FLOAT;
const StringHash HASH_ELEMENT_FLOAT = 7157124;
extern const char* NAME_ELEMENT_FLOAT;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT = 37213828;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT;

const StringHash HASH_ELEMENT_FLOAT2____FLOAT2 = 230813778;
extern const char* NAME_ELEMENT_FLOAT2____FLOAT2;
const StringHash HASH_ELEMENT_FLOAT2 = 114514034;
extern const char* NAME_ELEMENT_FLOAT2;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2 = 58550354;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT2;

const StringHash HASH_ELEMENT_FLOAT3____FLOAT3 = 231665747;
extern const char* NAME_ELEMENT_FLOAT3____FLOAT3;
const StringHash HASH_ELEMENT_FLOAT3 = 114514035;
extern const char* NAME_ELEMENT_FLOAT3;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3 = 58550355;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT3;

const StringHash HASH_ELEMENT_FLOAT4____FLOAT4 = 223604820;
extern const char* NAME_ELEMENT_FLOAT4____FLOAT4;
const StringHash HASH_ELEMENT_FLOAT4 = 114514036;
extern const char* NAME_ELEMENT_FLOAT4;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4 = 58550356;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT4;

const StringHash HASH_ELEMENT_FLOAT2X2____FLOAT2X2 = 141898498;
extern const char* NAME_ELEMENT_FLOAT2X2____FLOAT2X2;
const StringHash HASH_ELEMENT_FLOAT2X2 = 56131426;
extern const char* NAME_ELEMENT_FLOAT2X2;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2X2 = 224942786;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT2X2;

const StringHash HASH_ELEMENT_FLOAT3X3____FLOAT3X3 = 259339011;
extern const char* NAME_ELEMENT_FLOAT3X3____FLOAT3X3;
const StringHash HASH_ELEMENT_FLOAT3X3 = 56130659;
extern const char* NAME_ELEMENT_FLOAT3X3;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3X3 = 224942531;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT3X3;

const StringHash HASH_ELEMENT_FLOAT4X4____FLOAT4X4 = 175452932;
extern const char* NAME_ELEMENT_FLOAT4X4____FLOAT4X4;
const StringHash HASH_ELEMENT_FLOAT4X4 = 56130916;
extern const char* NAME_ELEMENT_FLOAT4X4;
const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4X4 = 224942276;
extern const char* NAME_ELEMENT_ANNOTATE__FLOAT4X4;

const StringHash HASH_ELEMENT_STRING = 128684103;
extern const char* NAME_ELEMENT_STRING;
const StringHash HASH_ELEMENT_ANNOTATE__STRING = 376935;
extern const char* NAME_ELEMENT_ANNOTATE__STRING;

const StringHash HASH_ELEMENT_IMAGE = 7354325;
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
    uint64 height;
    uint64 width;
    uint64 depth;
};

const StringHash HASH_ELEMENT_DATA = 436385;
extern const char* NAME_ELEMENT_DATA;
const StringHash HASH_ELEMENT_IMAGE__DATA = 189112177;
extern const char* NAME_ELEMENT_IMAGE__DATA;

const StringHash HASH_ELEMENT_INIT_FROM____ANYURI = 209066137;
extern const char* NAME_ELEMENT_INIT_FROM____ANYURI;
const StringHash HASH_ELEMENT_INIT_FROM = 10856717;
extern const char* NAME_ELEMENT_INIT_FROM;
const StringHash HASH_ELEMENT_IMAGE__INIT_FROM = 221349405;
extern const char* NAME_ELEMENT_IMAGE__INIT_FROM;

const StringHash HASH_ELEMENT_NEWPARAM____FX_NEWPARAM_COMMON = 25121566;
extern const char* NAME_ELEMENT_NEWPARAM____FX_NEWPARAM_COMMON;
const StringHash HASH_ELEMENT_NEWPARAM = 216436541;
extern const char* NAME_ELEMENT_NEWPARAM;
const StringHash HASH_ELEMENT_EFFECT__NEWPARAM = 123175677;
extern const char* NAME_ELEMENT_EFFECT__NEWPARAM;
struct newparam____fx_newparam_common__AttributeData
{
    static const newparam____fx_newparam_common__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SEMANTIC = 205020515;
extern const char* NAME_ELEMENT_SEMANTIC;
const StringHash HASH_ELEMENT_NEWPARAM__SEMANTIC = 91876067;
extern const char* NAME_ELEMENT_NEWPARAM__SEMANTIC;

const StringHash HASH_ELEMENT_MODIFIER = 95406210;
extern const char* NAME_ELEMENT_MODIFIER;
const StringHash HASH_ELEMENT_NEWPARAM__MODIFIER = 182483714;
extern const char* NAME_ELEMENT_NEWPARAM__MODIFIER;

const StringHash HASH_ELEMENT_FLOAT1X1____FLOAT = 79386452;
extern const char* NAME_ELEMENT_FLOAT1X1____FLOAT;
const StringHash HASH_ELEMENT_FLOAT1X1 = 56131169;
extern const char* NAME_ELEMENT_FLOAT1X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X1 = 236440545;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X1;

const StringHash HASH_ELEMENT_FLOAT1X2____FLOAT2 = 196638002;
extern const char* NAME_ELEMENT_FLOAT1X2____FLOAT2;
const StringHash HASH_ELEMENT_FLOAT1X2 = 56131170;
extern const char* NAME_ELEMENT_FLOAT1X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X2 = 236440546;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X2;

const StringHash HASH_ELEMENT_FLOAT1X3____FLOAT3 = 197096755;
extern const char* NAME_ELEMENT_FLOAT1X3____FLOAT3;
const StringHash HASH_ELEMENT_FLOAT1X3 = 56131171;
extern const char* NAME_ELEMENT_FLOAT1X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X3 = 236440547;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X3;

const StringHash HASH_ELEMENT_FLOAT1X4____FLOAT4 = 196769076;
extern const char* NAME_ELEMENT_FLOAT1X4____FLOAT4;
const StringHash HASH_ELEMENT_FLOAT1X4 = 56131172;
extern const char* NAME_ELEMENT_FLOAT1X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X4 = 236440548;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X4;

const StringHash HASH_ELEMENT_FLOAT2X1____FLOAT2 = 179664178;
extern const char* NAME_ELEMENT_FLOAT2X1____FLOAT2;
const StringHash HASH_ELEMENT_FLOAT2X1 = 56131425;
extern const char* NAME_ELEMENT_FLOAT2X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X1 = 236440289;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X1;

const StringHash HASH_ELEMENT_FLOAT2X3____FLOAT2X3 = 259339011;
extern const char* NAME_ELEMENT_FLOAT2X3____FLOAT2X3;
const StringHash HASH_ELEMENT_FLOAT2X3 = 56131427;
extern const char* NAME_ELEMENT_FLOAT2X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X3 = 236440291;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X3;

const StringHash HASH_ELEMENT_FLOAT2X4____FLOAT2X4 = 175452932;
extern const char* NAME_ELEMENT_FLOAT2X4____FLOAT2X4;
const StringHash HASH_ELEMENT_FLOAT2X4 = 56131428;
extern const char* NAME_ELEMENT_FLOAT2X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X4 = 236440292;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X4;

const StringHash HASH_ELEMENT_FLOAT3X1____FLOAT3 = 162886963;
extern const char* NAME_ELEMENT_FLOAT3X1____FLOAT3;
const StringHash HASH_ELEMENT_FLOAT3X1 = 56130657;
extern const char* NAME_ELEMENT_FLOAT3X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X1 = 236440033;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X1;

const StringHash HASH_ELEMENT_FLOAT3X2____FLOAT3X2 = 141898498;
extern const char* NAME_ELEMENT_FLOAT3X2____FLOAT3X2;
const StringHash HASH_ELEMENT_FLOAT3X2 = 56130658;
extern const char* NAME_ELEMENT_FLOAT3X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X2 = 236440034;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X2;

const StringHash HASH_ELEMENT_FLOAT3X4____FLOAT3X4 = 175452932;
extern const char* NAME_ELEMENT_FLOAT3X4____FLOAT3X4;
const StringHash HASH_ELEMENT_FLOAT3X4 = 56130660;
extern const char* NAME_ELEMENT_FLOAT3X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X4 = 236440036;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X4;

const StringHash HASH_ELEMENT_FLOAT4X1____FLOAT4 = 146109748;
extern const char* NAME_ELEMENT_FLOAT4X1____FLOAT4;
const StringHash HASH_ELEMENT_FLOAT4X1 = 56130913;
extern const char* NAME_ELEMENT_FLOAT4X1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X1 = 236439777;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X1;

const StringHash HASH_ELEMENT_FLOAT4X2____FLOAT4X2 = 141898498;
extern const char* NAME_ELEMENT_FLOAT4X2____FLOAT4X2;
const StringHash HASH_ELEMENT_FLOAT4X2 = 56130914;
extern const char* NAME_ELEMENT_FLOAT4X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X2 = 236439778;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X2;

const StringHash HASH_ELEMENT_FLOAT4X3____FLOAT4X3 = 259339011;
extern const char* NAME_ELEMENT_FLOAT4X3____FLOAT4X3;
const StringHash HASH_ELEMENT_FLOAT4X3 = 56130915;
extern const char* NAME_ELEMENT_FLOAT4X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X3 = 236439779;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X3;

const StringHash HASH_ELEMENT_SURFACE____FX_SURFACE_COMMON = 4957886;
extern const char* NAME_ELEMENT_SURFACE____FX_SURFACE_COMMON;
const StringHash HASH_ELEMENT_SURFACE = 180930533;
extern const char* NAME_ELEMENT_SURFACE;
const StringHash HASH_ELEMENT_NEWPARAM__SURFACE = 37502101;
extern const char* NAME_ELEMENT_NEWPARAM__SURFACE;
struct surface____fx_surface_common__AttributeData
{
    static const surface____fx_surface_common__AttributeData DEFAULT;

    ENUM__fx_surface_type_enum type;
};

const StringHash HASH_ELEMENT_INIT_AS_NULL = 261182076;
extern const char* NAME_ELEMENT_INIT_AS_NULL;
const StringHash HASH_ELEMENT_SURFACE__INIT_AS_NULL = 97694700;
extern const char* NAME_ELEMENT_SURFACE__INIT_AS_NULL;

const StringHash HASH_ELEMENT_INIT_AS_TARGET = 61002324;
extern const char* NAME_ELEMENT_INIT_AS_TARGET;
const StringHash HASH_ELEMENT_SURFACE__INIT_AS_TARGET = 37832724;
extern const char* NAME_ELEMENT_SURFACE__INIT_AS_TARGET;

const StringHash HASH_ELEMENT_INIT_CUBE = 10869717;
extern const char* NAME_ELEMENT_INIT_CUBE;
const StringHash HASH_ELEMENT_SURFACE__INIT_CUBE = 245137349;
extern const char* NAME_ELEMENT_SURFACE__INIT_CUBE;

const StringHash HASH_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____ALL = 189838860;
extern const char* NAME_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____ALL;
const StringHash HASH_ELEMENT_ALL = 26668;
extern const char* NAME_ELEMENT_ALL;
const StringHash HASH_ELEMENT_INIT_CUBE__ALL = 230624156;
extern const char* NAME_ELEMENT_INIT_CUBE__ALL;
const StringHash HASH_ATTRIBUTE_REF = 30902;
extern const char* NAME_ATTRIBUTE_REF;
struct fx_surface_init_cube_common____all__AttributeData
{
    static const fx_surface_init_cube_common____all__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____PRIMARY = 94726169;
extern const char* NAME_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____PRIMARY;
const StringHash HASH_ELEMENT_PRIMARY = 126892265;
extern const char* NAME_ELEMENT_PRIMARY;
const StringHash HASH_ELEMENT_INIT_CUBE__PRIMARY = 171149225;
extern const char* NAME_ELEMENT_INIT_CUBE__PRIMARY;
struct fx_surface_init_cube_common____primary__AttributeData
{
    static const fx_surface_init_cube_common____primary__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_ORDER = 7768770;
extern const char* NAME_ELEMENT_ORDER;
const StringHash HASH_ELEMENT_PRIMARY__ORDER = 241501282;
extern const char* NAME_ELEMENT_PRIMARY__ORDER;

const StringHash HASH_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____FACE = 84665637;
extern const char* NAME_ELEMENT_FX_SURFACE_INIT_CUBE_COMMON____FACE;
const StringHash HASH_ELEMENT_FACE = 444309;
extern const char* NAME_ELEMENT_FACE;
const StringHash HASH_ELEMENT_INIT_CUBE__FACE = 200285253;
extern const char* NAME_ELEMENT_INIT_CUBE__FACE;
struct fx_surface_init_cube_common____face__AttributeData
{
    static const fx_surface_init_cube_common____face__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_INIT_VOLUME = 113667221;
extern const char* NAME_ELEMENT_INIT_VOLUME;
const StringHash HASH_ELEMENT_SURFACE__INIT_VOLUME = 253916837;
extern const char* NAME_ELEMENT_SURFACE__INIT_VOLUME;

const StringHash HASH_ELEMENT_FX_SURFACE_INIT_VOLUME_COMMON____ALL = 124181564;
extern const char* NAME_ELEMENT_FX_SURFACE_INIT_VOLUME_COMMON____ALL;
const StringHash HASH_ELEMENT_INIT_VOLUME__ALL = 165229292;
extern const char* NAME_ELEMENT_INIT_VOLUME__ALL;
struct fx_surface_init_volume_common____all__AttributeData
{
    static const fx_surface_init_volume_common____all__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_FX_SURFACE_INIT_VOLUME_COMMON____PRIMARY = 194600569;
extern const char* NAME_ELEMENT_FX_SURFACE_INIT_VOLUME_COMMON____PRIMARY;
const StringHash HASH_ELEMENT_INIT_VOLUME__PRIMARY = 21488025;
extern const char* NAME_ELEMENT_INIT_VOLUME__PRIMARY;
struct fx_surface_init_volume_common____primary__AttributeData
{
    static const fx_surface_init_volume_common____primary__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_INIT_PLANAR = 102904866;
extern const char* NAME_ELEMENT_INIT_PLANAR;
const StringHash HASH_ELEMENT_SURFACE__INIT_PLANAR = 264653330;
extern const char* NAME_ELEMENT_SURFACE__INIT_PLANAR;

const StringHash HASH_ELEMENT_FX_SURFACE_INIT_PLANAR_COMMON____ALL = 266015324;
extern const char* NAME_ELEMENT_FX_SURFACE_INIT_PLANAR_COMMON____ALL;
const StringHash HASH_ELEMENT_INIT_PLANAR__ALL = 36140396;
extern const char* NAME_ELEMENT_INIT_PLANAR__ALL;
struct fx_surface_init_planar_common____all__AttributeData
{
    static const fx_surface_init_planar_common____all__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_INIT_FROM____FX_SURFACE_INIT_FROM_COMMON = 1012638;
extern const char* NAME_ELEMENT_INIT_FROM____FX_SURFACE_INIT_FROM_COMMON;
const StringHash HASH_ELEMENT_SURFACE__INIT_FROM = 245107997;
extern const char* NAME_ELEMENT_SURFACE__INIT_FROM;
const StringHash HASH_ATTRIBUTE_MIP = 29696;
extern const char* NAME_ATTRIBUTE_MIP;
const StringHash HASH_ATTRIBUTE_SLICE = 8007573;
extern const char* NAME_ATTRIBUTE_SLICE;
const StringHash HASH_ATTRIBUTE_FACE = 444309;
extern const char* NAME_ATTRIBUTE_FACE;
struct init_from____fx_surface_init_from_common__AttributeData
{
    static const init_from____fx_surface_init_from_common__AttributeData DEFAULT;

    uint32 mip;
    uint32 slice;
    ENUM__fx_surface_face_enum face;
};

const StringHash HASH_ELEMENT_FORMAT = 114725764;
extern const char* NAME_ELEMENT_FORMAT;
const StringHash HASH_ELEMENT_SURFACE__FORMAT = 219247124;
extern const char* NAME_ELEMENT_SURFACE__FORMAT;

const StringHash HASH_ELEMENT_FORMAT_HINT = 151553892;
extern const char* NAME_ELEMENT_FORMAT_HINT;
const StringHash HASH_ELEMENT_SURFACE__FORMAT_HINT = 22346100;
extern const char* NAME_ELEMENT_SURFACE__FORMAT_HINT;

const StringHash HASH_ELEMENT_CHANNELS = 243617443;
extern const char* NAME_ELEMENT_CHANNELS;
const StringHash HASH_ELEMENT_FORMAT_HINT__CHANNELS = 153491235;
extern const char* NAME_ELEMENT_FORMAT_HINT__CHANNELS;

const StringHash HASH_ELEMENT_RANGE = 7898325;
extern const char* NAME_ELEMENT_RANGE;
const StringHash HASH_ELEMENT_FORMAT_HINT__RANGE = 98570949;
extern const char* NAME_ELEMENT_FORMAT_HINT__RANGE;

const StringHash HASH_ELEMENT_PRECISION = 195095006;
extern const char* NAME_ELEMENT_PRECISION;
const StringHash HASH_ELEMENT_FORMAT_HINT__PRECISION = 227897774;
extern const char* NAME_ELEMENT_FORMAT_HINT__PRECISION;

const StringHash HASH_ELEMENT_OPTION = 124235870;
extern const char* NAME_ELEMENT_OPTION;
const StringHash HASH_ELEMENT_FORMAT_HINT__OPTION = 249614094;
extern const char* NAME_ELEMENT_FORMAT_HINT__OPTION;

const StringHash HASH_ELEMENT_SIZE____INT3 = 83168803;
extern const char* NAME_ELEMENT_SIZE____INT3;
const StringHash HASH_ELEMENT_SIZE = 499973;
extern const char* NAME_ELEMENT_SIZE;
const StringHash HASH_ELEMENT_SURFACE__SIZE = 27158757;
extern const char* NAME_ELEMENT_SURFACE__SIZE;

const StringHash HASH_ELEMENT_VIEWPORT_RATIO = 128383919;
extern const char* NAME_ELEMENT_VIEWPORT_RATIO;
const StringHash HASH_ELEMENT_SURFACE__VIEWPORT_RATIO = 39354991;
extern const char* NAME_ELEMENT_SURFACE__VIEWPORT_RATIO;

const StringHash HASH_ELEMENT_MIP_LEVELS = 103517267;
extern const char* NAME_ELEMENT_MIP_LEVELS;
const StringHash HASH_ELEMENT_SURFACE__MIP_LEVELS = 95669747;
extern const char* NAME_ELEMENT_SURFACE__MIP_LEVELS;

const StringHash HASH_ELEMENT_MIPMAP_GENERATE = 225753461;
extern const char* NAME_ELEMENT_MIPMAP_GENERATE;
const StringHash HASH_ELEMENT_SURFACE__MIPMAP_GENERATE = 57490693;
extern const char* NAME_ELEMENT_SURFACE__MIPMAP_GENERATE;

const StringHash HASH_ELEMENT_SAMPLER1D____FX_SAMPLER1D_COMMON = 51154702;
extern const char* NAME_ELEMENT_SAMPLER1D____FX_SAMPLER1D_COMMON;
const StringHash HASH_ELEMENT_SAMPLER1D = 74628308;
extern const char* NAME_ELEMENT_SAMPLER1D;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER1D = 11125956;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER1D;

const StringHash HASH_ELEMENT_SOURCE____NCNAME = 213562789;
extern const char* NAME_ELEMENT_SOURCE____NCNAME;
const StringHash HASH_ELEMENT_SAMPLER1D__SOURCE = 70915797;
extern const char* NAME_ELEMENT_SAMPLER1D__SOURCE;

const StringHash HASH_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON = 22902798;
extern const char* NAME_ELEMENT_WRAP_S____FX_SAMPLER_WRAP_COMMON;
const StringHash HASH_ELEMENT_WRAP_S = 132679267;
extern const char* NAME_ELEMENT_WRAP_S;
const StringHash HASH_ELEMENT_SAMPLER1D__WRAP_S = 72637475;
extern const char* NAME_ELEMENT_SAMPLER1D__WRAP_S;

const StringHash HASH_ELEMENT_MINFILTER = 80760514;
extern const char* NAME_ELEMENT_MINFILTER;
const StringHash HASH_ELEMENT_SAMPLER1D__MINFILTER = 153924226;
extern const char* NAME_ELEMENT_SAMPLER1D__MINFILTER;

const StringHash HASH_ELEMENT_MAGFILTER = 231754162;
extern const char* NAME_ELEMENT_MAGFILTER;
const StringHash HASH_ELEMENT_SAMPLER1D__MAGFILTER = 2929266;
extern const char* NAME_ELEMENT_SAMPLER1D__MAGFILTER;

const StringHash HASH_ELEMENT_MIPFILTER = 114314946;
extern const char* NAME_ELEMENT_MIPFILTER;
const StringHash HASH_ELEMENT_SAMPLER1D__MIPFILTER = 187478786;
extern const char* NAME_ELEMENT_SAMPLER1D__MIPFILTER;

const StringHash HASH_ELEMENT_BORDER_COLOR = 47245730;
extern const char* NAME_ELEMENT_BORDER_COLOR;
const StringHash HASH_ELEMENT_SAMPLER1D__BORDER_COLOR = 18094050;
extern const char* NAME_ELEMENT_SAMPLER1D__BORDER_COLOR;

const StringHash HASH_ELEMENT_MIPMAP_MAXLEVEL = 267058828;
extern const char* NAME_ELEMENT_MIPMAP_MAXLEVEL;
const StringHash HASH_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL = 72229196;
extern const char* NAME_ELEMENT_SAMPLER1D__MIPMAP_MAXLEVEL;

const StringHash HASH_ELEMENT_MIPMAP_BIAS = 137463987;
extern const char* NAME_ELEMENT_MIPMAP_BIAS;
const StringHash HASH_ELEMENT_SAMPLER1D__MIPMAP_BIAS = 216810323;
extern const char* NAME_ELEMENT_SAMPLER1D__MIPMAP_BIAS;

const StringHash HASH_ELEMENT_SAMPLER2D____FX_SAMPLER2D_COMMON = 67931662;
extern const char* NAME_ELEMENT_SAMPLER2D____FX_SAMPLER2D_COMMON;
const StringHash HASH_ELEMENT_SAMPLER2D = 74628324;
extern const char* NAME_ELEMENT_SAMPLER2D;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER2D = 11126004;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER2D;

const StringHash HASH_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON = 22899470;
extern const char* NAME_ELEMENT_WRAP_T____FX_SAMPLER_WRAP_COMMON;
const StringHash HASH_ELEMENT_WRAP_T = 132679268;
extern const char* NAME_ELEMENT_WRAP_T;
const StringHash HASH_ELEMENT_SAMPLER2D__WRAP_T = 72641572;
extern const char* NAME_ELEMENT_SAMPLER2D__WRAP_T;

const StringHash HASH_ELEMENT_SAMPLER3D____FX_SAMPLER3D_COMMON = 17599758;
extern const char* NAME_ELEMENT_SAMPLER3D____FX_SAMPLER3D_COMMON;
const StringHash HASH_ELEMENT_SAMPLER3D = 74628340;
extern const char* NAME_ELEMENT_SAMPLER3D;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER3D = 11125988;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER3D;

const StringHash HASH_ELEMENT_WRAP_P = 132679264;
extern const char* NAME_ELEMENT_WRAP_P;
const StringHash HASH_ELEMENT_SAMPLER3D__WRAP_P = 72645664;
extern const char* NAME_ELEMENT_SAMPLER3D__WRAP_P;

const StringHash HASH_ELEMENT_SAMPLERCUBE____FX_SAMPLERCUBE_COMMON = 264208206;
extern const char* NAME_ELEMENT_SAMPLERCUBE____FX_SAMPLERCUBE_COMMON;
const StringHash HASH_ELEMENT_SAMPLERCUBE = 46075157;
extern const char* NAME_ELEMENT_SAMPLERCUBE;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERCUBE = 164043205;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERCUBE;

const StringHash HASH_ELEMENT_SAMPLERRECT____FX_SAMPLERRECT_COMMON = 266305518;
extern const char* NAME_ELEMENT_SAMPLERRECT____FX_SAMPLERRECT_COMMON;
const StringHash HASH_ELEMENT_SAMPLERRECT = 46067188;
extern const char* NAME_ELEMENT_SAMPLERRECT;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERRECT = 164034852;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERRECT;

const StringHash HASH_ELEMENT_SAMPLERDEPTH____FX_SAMPLERDEPTH_COMMON = 266163102;
extern const char* NAME_ELEMENT_SAMPLERDEPTH____FX_SAMPLERDEPTH_COMMON;
const StringHash HASH_ELEMENT_SAMPLERDEPTH = 200336040;
extern const char* NAME_ELEMENT_SAMPLERDEPTH;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERDEPTH = 208776984;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERDEPTH;

const StringHash HASH_ELEMENT_ENUM____STRING = 57204183;
extern const char* NAME_ELEMENT_ENUM____STRING;
const StringHash HASH_ELEMENT_ENUM = 443837;
extern const char* NAME_ELEMENT_ENUM;
const StringHash HASH_ELEMENT_NEWPARAM__ENUM = 263408381;
extern const char* NAME_ELEMENT_NEWPARAM__ENUM;

const StringHash HASH_ELEMENT_FX_PROFILE_ABSTRACT = 143616996;
extern const char* NAME_ELEMENT_FX_PROFILE_ABSTRACT;
const StringHash HASH_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT = 70540052;
extern const char* NAME_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT;

const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS = 262260019;
extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS = 175028019;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS;
struct library_force_fields__AttributeData
{
    static const library_force_fields__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_FORCE_FIELD = 187798708;
extern const char* NAME_ELEMENT_FORCE_FIELD;
const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__FORCE_FIELD = 102613300;
extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__FORCE_FIELD;
struct force_field__AttributeData
{
    static const force_field__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_IMAGES = 175895315;
extern const char* NAME_ELEMENT_LIBRARY_IMAGES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_IMAGES = 263512339;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_IMAGES;
struct library_images__AttributeData
{
    static const library_images__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_LIGHTS = 196563299;
extern const char* NAME_ELEMENT_LIBRARY_LIGHTS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_LIGHTS = 7881555;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_LIGHTS;
struct library_lights__AttributeData
{
    static const library_lights__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIGHT = 7536116;
extern const char* NAME_ELEMENT_LIGHT;
const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__LIGHT = 3664804;
extern const char* NAME_ELEMENT_LIBRARY_LIGHTS__LIGHT;
struct light__AttributeData
{
    static const light__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIGHT__TECHNIQUE_COMMON = 9633678;
extern const char* NAME_ELEMENT_LIGHT__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_LIGHT__TECHNIQUE_COMMON__AMBIENT = 163690020;
extern const char* NAME_ELEMENT_LIGHT__TECHNIQUE_COMMON__AMBIENT;
const StringHash HASH_ELEMENT_AMBIENT = 137952308;
extern const char* NAME_ELEMENT_AMBIENT;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__AMBIENT = 108679732;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__AMBIENT;

const StringHash HASH_ELEMENT_COLOR____TARGETABLEFLOAT3 = 189850083;
extern const char* NAME_ELEMENT_COLOR____TARGETABLEFLOAT3;
const StringHash HASH_ELEMENT_COLOR = 6972258;
extern const char* NAME_ELEMENT_COLOR;
const StringHash HASH_ELEMENT_AMBIENT__COLOR = 148349506;
extern const char* NAME_ELEMENT_AMBIENT__COLOR;
struct color____TargetableFloat3__AttributeData
{
    static const color____TargetableFloat3__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_DIRECTIONAL = 180710604;
extern const char* NAME_ELEMENT_DIRECTIONAL;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DIRECTIONAL = 13053548;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__DIRECTIONAL;

const StringHash HASH_ELEMENT_POINT = 7823444;
extern const char* NAME_ELEMENT_POINT;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__POINT = 173350644;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__POINT;

const StringHash HASH_ELEMENT_CONSTANT_ATTENUATION = 96122782;
extern const char* NAME_ELEMENT_CONSTANT_ATTENUATION;
const StringHash HASH_ELEMENT_POINT__CONSTANT_ATTENUATION = 98628030;
extern const char* NAME_ELEMENT_POINT__CONSTANT_ATTENUATION;
struct constant_attenuation__AttributeData
{
    static const constant_attenuation__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LINEAR_ATTENUATION = 80764702;
extern const char* NAME_ELEMENT_LINEAR_ATTENUATION;
const StringHash HASH_ELEMENT_POINT__LINEAR_ATTENUATION = 11535838;
extern const char* NAME_ELEMENT_POINT__LINEAR_ATTENUATION;
struct linear_attenuation__AttributeData
{
    static const linear_attenuation__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_QUADRATIC_ATTENUATION = 89712814;
extern const char* NAME_ELEMENT_QUADRATIC_ATTENUATION;
const StringHash HASH_ELEMENT_POINT__QUADRATIC_ATTENUATION = 251429214;
extern const char* NAME_ELEMENT_POINT__QUADRATIC_ATTENUATION;
struct quadratic_attenuation__AttributeData
{
    static const quadratic_attenuation__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SPOT = 501604;
extern const char* NAME_ELEMENT_SPOT;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPOT = 178619204;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPOT;

const StringHash HASH_ELEMENT_FALLOFF_ANGLE = 148208005;
extern const char* NAME_ELEMENT_FALLOFF_ANGLE;
const StringHash HASH_ELEMENT_SPOT__FALLOFF_ANGLE = 239328965;
extern const char* NAME_ELEMENT_SPOT__FALLOFF_ANGLE;
struct falloff_angle__AttributeData
{
    static const falloff_angle__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_FALLOFF_EXPONENT = 206620580;
extern const char* NAME_ELEMENT_FALLOFF_EXPONENT;
const StringHash HASH_ELEMENT_SPOT__FALLOFF_EXPONENT = 108835012;
extern const char* NAME_ELEMENT_SPOT__FALLOFF_EXPONENT;
struct falloff_exponent__AttributeData
{
    static const falloff_exponent__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIBRARY_MATERIALS = 35999283;
extern const char* NAME_ELEMENT_LIBRARY_MATERIALS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_MATERIALS = 50787011;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_MATERIALS;
struct library_materials__AttributeData
{
    static const library_materials__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_MATERIAL = 145524812;
extern const char* NAME_ELEMENT_MATERIAL;
const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__MATERIAL = 110624268;
extern const char* NAME_ELEMENT_LIBRARY_MATERIALS__MATERIAL;
struct material__AttributeData
{
    static const material__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_EFFECT = 253030820;
extern const char* NAME_ELEMENT_INSTANCE_EFFECT;
const StringHash HASH_ELEMENT_MATERIAL__INSTANCE_EFFECT = 179640868;
extern const char* NAME_ELEMENT_MATERIAL__INSTANCE_EFFECT;
struct instance_effect__AttributeData
{
    static const instance_effect__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_TECHNIQUE_HINT = 4897140;
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

const StringHash HASH_ELEMENT_INSTANCE_EFFECT__SETPARAM = 219277853;
extern const char* NAME_ELEMENT_INSTANCE_EFFECT__SETPARAM;
const StringHash HASH_ELEMENT_SETPARAM = 213290989;
extern const char* NAME_ELEMENT_SETPARAM;
struct instance_effect__setparam__AttributeData
{
    static const instance_effect__setparam__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_LIBRARY_NODES = 230609443;
extern const char* NAME_ELEMENT_LIBRARY_NODES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_NODES = 235021059;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_NODES;
struct library_nodes__AttributeData
{
    static const library_nodes__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_NODE = 480677;
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
    ENUM__NodeType type;
    GeneratedSaxParser::XSList<ParserString> layer;
};

const StringHash HASH_ELEMENT_LOOKAT = 121004420;
extern const char* NAME_ELEMENT_LOOKAT;
const StringHash HASH_ELEMENT_NODE__LOOKAT = 58854100;
extern const char* NAME_ELEMENT_NODE__LOOKAT;
struct lookat__AttributeData
{
    static const lookat__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MATRIX = 121157896;
extern const char* NAME_ELEMENT_MATRIX;
const StringHash HASH_ELEMENT_NODE__MATRIX = 57480280;
extern const char* NAME_ELEMENT_NODE__MATRIX;
struct matrix__AttributeData
{
    static const matrix__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_ROTATE = 127314085;
extern const char* NAME_ELEMENT_ROTATE;
const StringHash HASH_ELEMENT_NODE__ROTATE = 31654901;
extern const char* NAME_ELEMENT_NODE__ROTATE;
struct rotate__AttributeData
{
    static const rotate__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SCALE = 7968805;
extern const char* NAME_ELEMENT_SCALE;
const StringHash HASH_ELEMENT_NODE__SCALE = 85773973;
extern const char* NAME_ELEMENT_NODE__SCALE;
struct scale__AttributeData
{
    static const scale__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SKEW = 500167;
extern const char* NAME_ELEMENT_SKEW;
const StringHash HASH_ELEMENT_NODE__SKEW = 189912167;
extern const char* NAME_ELEMENT_NODE__SKEW;
struct skew__AttributeData
{
    static const skew__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TRANSLATE = 140137253;
extern const char* NAME_ELEMENT_TRANSLATE;
const StringHash HASH_ELEMENT_NODE__TRANSLATE = 250426997;
extern const char* NAME_ELEMENT_NODE__TRANSLATE;
struct translate__AttributeData
{
    static const translate__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INSTANCE_CAMERA = 255854209;
extern const char* NAME_ELEMENT_INSTANCE_CAMERA;
const StringHash HASH_ELEMENT_NODE__INSTANCE_CAMERA = 92626481;
extern const char* NAME_ELEMENT_NODE__INSTANCE_CAMERA;
struct instance_camera__AttributeData
{
    static const instance_camera__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER = 26967202;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER;
const StringHash HASH_ELEMENT_NODE__INSTANCE_CONTROLLER = 155305458;
extern const char* NAME_ELEMENT_NODE__INSTANCE_CONTROLLER;
struct instance_controller__AttributeData
{
    static const instance_controller__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_SKELETON = 29544190;
extern const char* NAME_ELEMENT_SKELETON;
const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__SKELETON = 220539054;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER__SKELETON;

const StringHash HASH_ELEMENT_BIND_MATERIAL = 27797804;
extern const char* NAME_ELEMENT_BIND_MATERIAL;
const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__BIND_MATERIAL = 132281260;
extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER__BIND_MATERIAL;

const StringHash HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON = 90983294;
extern const char* NAME_ELEMENT_BIND_MATERIAL__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_INSTANCE_MATERIAL = 9871340;
extern const char* NAME_ELEMENT_INSTANCE_MATERIAL;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_MATERIAL = 109789516;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INSTANCE_MATERIAL;
const StringHash HASH_ATTRIBUTE_SYMBOL = 128989532;
extern const char* NAME_ATTRIBUTE_SYMBOL;
struct instance_material__AttributeData
{
    static const instance_material__AttributeData DEFAULT;

    const ParserChar* symbol;
    COLLADABU::URI target;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__BIND = 48435636;
extern const char* NAME_ELEMENT_INSTANCE_MATERIAL__BIND;
const StringHash HASH_ELEMENT_BIND = 430148;
extern const char* NAME_ELEMENT_BIND;
struct instance_material__bind__AttributeData
{
    static const instance_material__bind__AttributeData DEFAULT;

    const ParserChar* semantic;
    const ParserChar* target;
};

const StringHash HASH_ELEMENT_BIND_VERTEX_INPUT = 217827748;
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
    uint64 input_set;
};

const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY = 75089129;
extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY;
const StringHash HASH_ELEMENT_NODE__INSTANCE_GEOMETRY = 155287129;
extern const char* NAME_ELEMENT_NODE__INSTANCE_GEOMETRY;
struct instance_geometry__AttributeData
{
    static const instance_geometry__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_LIGHT = 17333844;
extern const char* NAME_ELEMENT_INSTANCE_LIGHT;
const StringHash HASH_ELEMENT_NODE__INSTANCE_LIGHT = 191089620;
extern const char* NAME_ELEMENT_NODE__INSTANCE_LIGHT;
struct instance_light__AttributeData
{
    static const instance_light__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_NODE = 168885653;
extern const char* NAME_ELEMENT_INSTANCE_NODE;
const StringHash HASH_ELEMENT_NODE__INSTANCE_NODE = 45508293;
extern const char* NAME_ELEMENT_NODE__INSTANCE_NODE;
struct instance_node__AttributeData
{
    static const instance_node__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS = 149953987;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_MATERIALS = 144977635;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_MATERIALS;
struct library_physics_materials__AttributeData
{
    static const library_physics_materials__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL = 22186316;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL;
const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL = 9537676;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL;
struct physics_material__AttributeData
{
    static const physics_material__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON = 99789790;
extern const char* NAME_ELEMENT_PHYSICS_MATERIAL__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_DYNAMIC_FRICTION = 12843982;
extern const char* NAME_ELEMENT_DYNAMIC_FRICTION;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DYNAMIC_FRICTION = 107186158;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__DYNAMIC_FRICTION;
struct dynamic_friction__AttributeData
{
    static const dynamic_friction__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_RESTITUTION = 12871406;
extern const char* NAME_ELEMENT_RESTITUTION;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__RESTITUTION = 182855758;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__RESTITUTION;
struct restitution__AttributeData
{
    static const restitution__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_STATIC_FRICTION = 4890926;
extern const char* NAME_ELEMENT_STATIC_FRICTION;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__STATIC_FRICTION = 50283374;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__STATIC_FRICTION;
struct static_friction__AttributeData
{
    static const static_friction__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS = 247630259;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_MODELS = 229674739;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_MODELS;
struct library_physics_models__AttributeData
{
    static const library_physics_models__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_MODEL = 6604124;
extern const char* NAME_ELEMENT_PHYSICS_MODEL;
const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__PHYSICS_MODEL = 121224284;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__PHYSICS_MODEL;
struct physics_model__AttributeData
{
    static const physics_model__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_RIGID_BODY = 262281833;
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

const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__DYNAMIC = 174112899;
extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__DYNAMIC;
const StringHash HASH_ELEMENT_DYNAMIC = 201622419;
extern const char* NAME_ELEMENT_DYNAMIC;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__DYNAMIC = 164030867;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__DYNAMIC;
struct rigid_body__technique_common__dynamic__AttributeData
{
    static const rigid_body__technique_common__dynamic__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MASS = 473251;
extern const char* NAME_ELEMENT_MASS;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS = 178723971;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS;
struct mass__AttributeData
{
    static const mass__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__MASS_FRAME = 90547925;
extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__MASS_FRAME;
const StringHash HASH_ELEMENT_MASS_FRAME = 156942485;
extern const char* NAME_ELEMENT_MASS_FRAME;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME = 66755765;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME;

const StringHash HASH_ELEMENT_INERTIA = 5020289;
extern const char* NAME_ELEMENT_INERTIA;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INERTIA = 235810961;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INERTIA;
struct inertia__AttributeData
{
    static const inertia__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL = 190501244;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MATERIAL;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL = 110655340;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INSTANCE_PHYSICS_MATERIAL;
struct instance_physics_material__AttributeData
{
    static const instance_physics_material__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__SHAPE = 55069861;
extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__SHAPE;
const StringHash HASH_ELEMENT_SHAPE = 7989349;
extern const char* NAME_ELEMENT_SHAPE;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SHAPE = 173779653;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SHAPE;

const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__SHAPE__HOLLOW = 230332791;
extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE_COMMON__SHAPE__HOLLOW;
const StringHash HASH_ELEMENT_HOLLOW = 116798311;
extern const char* NAME_ELEMENT_HOLLOW;
const StringHash HASH_ELEMENT_SHAPE__HOLLOW = 203315751;
extern const char* NAME_ELEMENT_SHAPE__HOLLOW;
struct rigid_body__technique_common__shape__hollow__AttributeData
{
    static const rigid_body__technique_common__shape__hollow__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_DENSITY = 180723929;
extern const char* NAME_ELEMENT_DENSITY;
const StringHash HASH_ELEMENT_SHAPE__DENSITY = 71513209;
extern const char* NAME_ELEMENT_SHAPE__DENSITY;
struct density__AttributeData
{
    static const density__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PLANE = 7809093;
extern const char* NAME_ELEMENT_PLANE;
const StringHash HASH_ELEMENT_SHAPE__PLANE = 83469045;
extern const char* NAME_ELEMENT_SHAPE__PLANE;

const StringHash HASH_ELEMENT_EQUATION = 146320030;
extern const char* NAME_ELEMENT_EQUATION;
const StringHash HASH_ELEMENT_PLANE__EQUATION = 15986366;
extern const char* NAME_ELEMENT_PLANE__EQUATION;

const StringHash HASH_ELEMENT_BOX = 26984;
extern const char* NAME_ELEMENT_BOX;
const StringHash HASH_ELEMENT_SHAPE__BOX = 112510952;
extern const char* NAME_ELEMENT_SHAPE__BOX;

const StringHash HASH_ELEMENT_HALF_EXTENTS = 168995299;
extern const char* NAME_ELEMENT_HALF_EXTENTS;
const StringHash HASH_ELEMENT_BOX__HALF_EXTENTS = 158729139;
extern const char* NAME_ELEMENT_BOX__HALF_EXTENTS;

const StringHash HASH_ELEMENT_SPHERE = 128380037;
extern const char* NAME_ELEMENT_SPHERE;
const StringHash HASH_ELEMENT_SHAPE__SPHERE = 256804805;
extern const char* NAME_ELEMENT_SHAPE__SPHERE;

const StringHash HASH_ELEMENT_RADIUS____FLOAT = 5388500;
extern const char* NAME_ELEMENT_RADIUS____FLOAT;
const StringHash HASH_ELEMENT_RADIUS = 126333123;
extern const char* NAME_ELEMENT_RADIUS;
const StringHash HASH_ELEMENT_SPHERE__RADIUS = 7028275;
extern const char* NAME_ELEMENT_SPHERE__RADIUS;

const StringHash HASH_ELEMENT_CYLINDER = 3165298;
extern const char* NAME_ELEMENT_CYLINDER;
const StringHash HASH_ELEMENT_SHAPE__CYLINDER = 138741378;
extern const char* NAME_ELEMENT_SHAPE__CYLINDER;

const StringHash HASH_ELEMENT_HEIGHT = 116129268;
extern const char* NAME_ELEMENT_HEIGHT;
const StringHash HASH_ELEMENT_CYLINDER__HEIGHT = 94864756;
extern const char* NAME_ELEMENT_CYLINDER__HEIGHT;

const StringHash HASH_ELEMENT_RADIUS____FLOAT2 = 86216050;
extern const char* NAME_ELEMENT_RADIUS____FLOAT2;
const StringHash HASH_ELEMENT_CYLINDER__RADIUS = 114026563;
extern const char* NAME_ELEMENT_CYLINDER__RADIUS;

const StringHash HASH_ELEMENT_TAPERED_CYLINDER = 77858562;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER;
const StringHash HASH_ELEMENT_SHAPE__TAPERED_CYLINDER = 166506338;
extern const char* NAME_ELEMENT_SHAPE__TAPERED_CYLINDER;

const StringHash HASH_ELEMENT_RADIUS1 = 142281745;
extern const char* NAME_ELEMENT_RADIUS1;
const StringHash HASH_ELEMENT_TAPERED_CYLINDER__RADIUS1 = 134955841;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER__RADIUS1;

const StringHash HASH_ELEMENT_RADIUS2 = 142281746;
extern const char* NAME_ELEMENT_RADIUS2;
const StringHash HASH_ELEMENT_TAPERED_CYLINDER__RADIUS2 = 134955842;
extern const char* NAME_ELEMENT_TAPERED_CYLINDER__RADIUS2;

const StringHash HASH_ELEMENT_CAPSULE = 159886405;
extern const char* NAME_ELEMENT_CAPSULE;
const StringHash HASH_ELEMENT_SHAPE__CAPSULE = 117514469;
extern const char* NAME_ELEMENT_SHAPE__CAPSULE;

const StringHash HASH_ELEMENT_TAPERED_CAPSULE = 256864501;
extern const char* NAME_ELEMENT_TAPERED_CAPSULE;
const StringHash HASH_ELEMENT_SHAPE__TAPERED_CAPSULE = 167503477;
extern const char* NAME_ELEMENT_SHAPE__TAPERED_CAPSULE;

const StringHash HASH_ELEMENT_RIGID_CONSTRAINT = 85611988;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT;
const StringHash HASH_ELEMENT_PHYSICS_MODEL__RIGID_CONSTRAINT = 118460596;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__RIGID_CONSTRAINT;
struct rigid_constraint__AttributeData
{
    static const rigid_constraint__AttributeData DEFAULT;

    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_REF_ATTACHMENT = 207403124;
extern const char* NAME_ELEMENT_REF_ATTACHMENT;
const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__REF_ATTACHMENT = 166190372;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__REF_ATTACHMENT;
const StringHash HASH_ATTRIBUTE_RIGID_BODY = 262281833;
extern const char* NAME_ATTRIBUTE_RIGID_BODY;
struct ref_attachment__AttributeData
{
    static const ref_attachment__AttributeData DEFAULT;

    COLLADABU::URI rigid_body;
};

const StringHash HASH_ELEMENT_ATTACHMENT = 127513076;
extern const char* NAME_ELEMENT_ATTACHMENT;
const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__ATTACHMENT = 183690788;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__ATTACHMENT;
struct attachment__AttributeData
{
    static const attachment__AttributeData DEFAULT;

    COLLADABU::URI rigid_body;
};

const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON = 28989358;
extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ENABLED = 206017236;
extern const char* NAME_ELEMENT_ENABLED;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ENABLED = 168114388;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ENABLED;
struct enabled__AttributeData
{
    static const enabled__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INTERPENETRATE = 23533925;
extern const char* NAME_ELEMENT_INTERPENETRATE;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__INTERPENETRATE = 88979653;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__INTERPENETRATE;
struct interpenetrate__AttributeData
{
    static const interpenetrate__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIMITS = 120602803;
extern const char* NAME_ELEMENT_LIMITS;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__LIMITS = 118237715;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__LIMITS;

const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST = 103048868;
extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST;
const StringHash HASH_ELEMENT_LIMITS__SWING_CONE_AND_TWIST = 23389540;
extern const char* NAME_ELEMENT_LIMITS__SWING_CONE_AND_TWIST;

const StringHash HASH_ELEMENT_MIN = 29694;
extern const char* NAME_ELEMENT_MIN;
const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MIN = 185017758;
extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MIN;
struct min__AttributeData
{
    static const min__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_MAX = 29576;
extern const char* NAME_ELEMENT_MAX;
const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MAX = 185017832;
extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MAX;
struct max__AttributeData
{
    static const max__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIMITS__LINEAR = 108038914;
extern const char* NAME_ELEMENT_LIMITS__LINEAR;
const StringHash HASH_ELEMENT_LINEAR = 120605570;
extern const char* NAME_ELEMENT_LINEAR;

const StringHash HASH_ELEMENT_SPRING = 128421959;
extern const char* NAME_ELEMENT_SPRING;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPRING = 92514023;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPRING;

const StringHash HASH_ELEMENT_ANGULAR = 139379426;
extern const char* NAME_ELEMENT_ANGULAR;
const StringHash HASH_ELEMENT_SPRING__ANGULAR = 256544162;
extern const char* NAME_ELEMENT_SPRING__ANGULAR;

const StringHash HASH_ELEMENT_STIFFNESS = 265106947;
extern const char* NAME_ELEMENT_STIFFNESS;
const StringHash HASH_ELEMENT_ANGULAR__STIFFNESS = 13552163;
extern const char* NAME_ELEMENT_ANGULAR__STIFFNESS;
struct stiffness__AttributeData
{
    static const stiffness__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_DAMPING = 176451623;
extern const char* NAME_ELEMENT_DAMPING;
const StringHash HASH_ELEMENT_ANGULAR__DAMPING = 107704311;
extern const char* NAME_ELEMENT_ANGULAR__DAMPING;
struct damping__AttributeData
{
    static const damping__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TARGET_VALUE = 264572533;
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

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL = 98657756;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL;
const StringHash HASH_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL = 133635772;
extern const char* NAME_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL;
const StringHash HASH_ATTRIBUTE_PARENT = 124292180;
extern const char* NAME_ATTRIBUTE_PARENT;
struct instance_physics_model__AttributeData
{
    static const instance_physics_model__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
    COLLADABU::URI parent;
};

const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD = 195760404;
extern const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD;
const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD = 38290564;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD;
struct instance_force_field__AttributeData
{
    static const instance_force_field__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY = 95007321;
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
    COLLADABU::URI target;
};

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON = 107721262;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_ANGULAR_VELOCITY = 135963289;
extern const char* NAME_ELEMENT_ANGULAR_VELOCITY;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__ANGULAR_VELOCITY = 180078265;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__ANGULAR_VELOCITY;

const StringHash HASH_ELEMENT_VELOCITY = 204842873;
extern const char* NAME_ELEMENT_VELOCITY;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__VELOCITY = 2049353;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__VELOCITY;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__DYNAMIC = 15147027;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__DYNAMIC;
struct instance_rigid_body__technique_common__dynamic__AttributeData
{
    static const instance_rigid_body__technique_common__dynamic__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__MASS_FRAME = 258084517;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__MASS_FRAME;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__SHAPE = 64146181;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__SHAPE;

const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__SHAPE__HOLLOW = 121584071;
extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE_COMMON__SHAPE__HOLLOW;
struct instance_rigid_body__technique_common__shape__hollow__AttributeData
{
    static const instance_rigid_body__technique_common__shape__hollow__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INSTANCE_RIGID_CONSTRAINT = 252820964;
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

const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES = 236889923;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_PHYSICS_SCENES = 252486147;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_PHYSICS_SCENES;
struct library_physics_scenes__AttributeData
{
    static const library_physics_scenes__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_SCENE = 6882725;
extern const char* NAME_ELEMENT_PHYSICS_SCENE;
const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__PHYSICS_SCENE = 100496229;
extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__PHYSICS_SCENE;
struct physics_scene__AttributeData
{
    static const physics_scene__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON = 53159934;
extern const char* NAME_ELEMENT_PHYSICS_SCENE__TECHNIQUE_COMMON;

const StringHash HASH_ELEMENT_GRAVITY = 243847385;
extern const char* NAME_ELEMENT_GRAVITY;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__GRAVITY = 214596313;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__GRAVITY;
struct gravity__AttributeData
{
    static const gravity__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TIME_STEP = 62312896;
extern const char* NAME_ELEMENT_TIME_STEP;
const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__TIME_STEP = 18674176;
extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__TIME_STEP;
struct time_step__AttributeData
{
    static const time_step__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES = 1834835;
extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES;
const StringHash HASH_ELEMENT_COLLADA__LIBRARY_VISUAL_SCENES = 216719139;
extern const char* NAME_ELEMENT_COLLADA__LIBRARY_VISUAL_SCENES;
struct library_visual_scenes__AttributeData
{
    static const library_visual_scenes__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_VISUAL_SCENE = 129577413;
extern const char* NAME_ELEMENT_VISUAL_SCENE;
const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__VISUAL_SCENE = 220621413;
extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__VISUAL_SCENE;
struct visual_scene__AttributeData
{
    static const visual_scene__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_EVALUATE_SCENE = 132785701;
extern const char* NAME_ELEMENT_EVALUATE_SCENE;
const StringHash HASH_ELEMENT_VISUAL_SCENE__EVALUATE_SCENE = 145043477;
extern const char* NAME_ELEMENT_VISUAL_SCENE__EVALUATE_SCENE;
struct evaluate_scene__AttributeData
{
    static const evaluate_scene__AttributeData DEFAULT;

    const ParserChar* name;
};

const StringHash HASH_ELEMENT_RENDER = 126634690;
extern const char* NAME_ELEMENT_RENDER;
const StringHash HASH_ELEMENT_EVALUATE_SCENE__RENDER = 212755570;
extern const char* NAME_ELEMENT_EVALUATE_SCENE__RENDER;
const StringHash HASH_ATTRIBUTE_CAMERA_NODE = 136173157;
extern const char* NAME_ATTRIBUTE_CAMERA_NODE;
struct render__AttributeData
{
    static const render__AttributeData DEFAULT;

    COLLADABU::URI camera_node;
};

const StringHash HASH_ELEMENT_LAYER = 7507906;
extern const char* NAME_ELEMENT_LAYER;
const StringHash HASH_ELEMENT_RENDER__LAYER = 228991954;
extern const char* NAME_ELEMENT_RENDER__LAYER;

const StringHash HASH_ELEMENT_SCENE = 7969861;
extern const char* NAME_ELEMENT_SCENE;
const StringHash HASH_ELEMENT_COLLADA__SCENE = 24758453;
extern const char* NAME_ELEMENT_COLLADA__SCENE;

const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_SCENE = 99263781;
extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_SCENE;
const StringHash HASH_ELEMENT_SCENE__INSTANCE_PHYSICS_SCENE = 10609013;
extern const char* NAME_ELEMENT_SCENE__INSTANCE_PHYSICS_SCENE;
struct instance_physics_scene__AttributeData
{
    static const instance_physics_scene__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_INSTANCE_VISUAL_SCENE = 235998149;
extern const char* NAME_ELEMENT_INSTANCE_VISUAL_SCENE;
const StringHash HASH_ELEMENT_SCENE__INSTANCE_VISUAL_SCENE = 177061637;
extern const char* NAME_ELEMENT_SCENE__INSTANCE_VISUAL_SCENE;
struct instance_visual_scene__AttributeData
{
    static const instance_visual_scene__AttributeData DEFAULT;

    COLLADABU::URI url;
    const ParserChar* sid;
    const ParserChar* name;
};

const StringHash HASH_ELEMENT_PROFILE_GLES = 99286435;
extern const char* NAME_ELEMENT_PROFILE_GLES;
struct profile_GLES__AttributeData
{
    static const profile_GLES__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* platform;
};

const StringHash HASH_ELEMENT_NEWPARAM____GLES_NEWPARAM = 103891357;
extern const char* NAME_ELEMENT_NEWPARAM____GLES_NEWPARAM;
const StringHash HASH_ELEMENT_PROFILE_GLES__NEWPARAM = 21514445;
extern const char* NAME_ELEMENT_PROFILE_GLES__NEWPARAM;
struct newparam____gles_newparam__AttributeData
{
    static const newparam____gles_newparam__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TEXTURE_PIPELINE____GLES_TEXTURE_PIPELINE = 136209125;
extern const char* NAME_ELEMENT_TEXTURE_PIPELINE____GLES_TEXTURE_PIPELINE;
const StringHash HASH_ELEMENT_TEXTURE_PIPELINE = 195376869;
extern const char* NAME_ELEMENT_TEXTURE_PIPELINE;
const StringHash HASH_ELEMENT_NEWPARAM__TEXTURE_PIPELINE = 68467621;
extern const char* NAME_ELEMENT_NEWPARAM__TEXTURE_PIPELINE;
struct texture_pipeline____gles_texture_pipeline__AttributeData
{
    static const texture_pipeline____gles_texture_pipeline__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_TEXCOMBINER = 105007714;
extern const char* NAME_ELEMENT_TEXCOMBINER;
const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__TEXCOMBINER = 184640514;
extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__TEXCOMBINER;

const StringHash HASH_ELEMENT_CONSTANT____GLES_TEXTURE_CONSTANT_TYPE = 9903477;
extern const char* NAME_ELEMENT_CONSTANT____GLES_TEXTURE_CONSTANT_TYPE;
const StringHash HASH_ELEMENT_CONSTANT = 106603252;
extern const char* NAME_ELEMENT_CONSTANT;
const StringHash HASH_ELEMENT_TEXCOMBINER__CONSTANT = 3715492;
extern const char* NAME_ELEMENT_TEXCOMBINER__CONSTANT;
const StringHash HASH_ATTRIBUTE_VALUE = 8160181;
extern const char* NAME_ATTRIBUTE_VALUE;
const StringHash HASH_ATTRIBUTE_PARAM = 7768189;
extern const char* NAME_ATTRIBUTE_PARAM;
struct constant____gles_texture_constant_type__AttributeData
{
    static const constant____gles_texture_constant_type__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_RGB = 22194;
extern const char* NAME_ELEMENT_RGB;
const StringHash HASH_ELEMENT_TEXCOMBINER__RGB = 102851090;
extern const char* NAME_ELEMENT_TEXCOMBINER__RGB;
const StringHash HASH_ATTRIBUTE_OPERATOR = 113806850;
extern const char* NAME_ATTRIBUTE_OPERATOR;
const StringHash HASH_ATTRIBUTE_SCALE = 7968805;
extern const char* NAME_ATTRIBUTE_SCALE;
struct RGB__AttributeData
{
    static const RGB__AttributeData DEFAULT;

    ENUM__gles_texcombiner_operatorRGB_enums _operator;
    float scale;
};

const StringHash HASH_ELEMENT_ARGUMENT____GLES_TEXCOMBINER_ARGUMENTRGB_TYPE = 189989461;
extern const char* NAME_ELEMENT_ARGUMENT____GLES_TEXCOMBINER_ARGUMENTRGB_TYPE;
const StringHash HASH_ELEMENT_ARGUMENT = 149700308;
extern const char* NAME_ELEMENT_ARGUMENT;
const StringHash HASH_ELEMENT_RGB__ARGUMENT = 240414596;
extern const char* NAME_ELEMENT_RGB__ARGUMENT;
const StringHash HASH_ATTRIBUTE_OPERAND = 107776052;
extern const char* NAME_ATTRIBUTE_OPERAND;
const StringHash HASH_ATTRIBUTE_UNIT = 509188;
extern const char* NAME_ATTRIBUTE_UNIT;
struct argument____gles_texcombiner_argumentRGB_type__AttributeData
{
    static const argument____gles_texcombiner_argumentRGB_type__AttributeData DEFAULT;

    ENUM__gles_texcombiner_source_enums source;
    ENUM__gles_texcombiner_operandRGB_enums operand;
    const ParserChar* unit;
};

const StringHash HASH_ELEMENT_ALPHA____GLES_TEXCOMBINER_COMMANDALPHA_TYPE = 179777157;
extern const char* NAME_ELEMENT_ALPHA____GLES_TEXCOMBINER_COMMANDALPHA_TYPE;
const StringHash HASH_ELEMENT_ALPHA = 6829793;
extern const char* NAME_ELEMENT_ALPHA;
const StringHash HASH_ELEMENT_TEXCOMBINER__ALPHA = 24416449;
extern const char* NAME_ELEMENT_TEXCOMBINER__ALPHA;
struct alpha____gles_texcombiner_commandAlpha_type__AttributeData
{
    static const alpha____gles_texcombiner_commandAlpha_type__AttributeData DEFAULT;

    ENUM__gles_texcombiner_operatorAlpha_enums _operator;
    float scale;
};

const StringHash HASH_ELEMENT_ARGUMENT____GLES_TEXCOMBINER_ARGUMENTALPHA_TYPE = 171283253;
extern const char* NAME_ELEMENT_ARGUMENT____GLES_TEXCOMBINER_ARGUMENTALPHA_TYPE;
const StringHash HASH_ELEMENT_ALPHA__ARGUMENT = 235735012;
extern const char* NAME_ELEMENT_ALPHA__ARGUMENT;
struct argument____gles_texcombiner_argumentAlpha_type__AttributeData
{
    static const argument____gles_texcombiner_argumentAlpha_type__AttributeData DEFAULT;

    ENUM__gles_texcombiner_source_enums source;
    ENUM__gles_texcombiner_operandAlpha_enums operand;
    const ParserChar* unit;
};

const StringHash HASH_ELEMENT_TEXENV = 128773206;
extern const char* NAME_ELEMENT_TEXENV;
const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__TEXENV = 60426918;
extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__TEXENV;
struct texenv__AttributeData
{
    static const texenv__AttributeData DEFAULT;

    ENUM__gles_texenv_mode_enums _operator;
    const ParserChar* unit;
};

const StringHash HASH_ELEMENT_SAMPLER_STATE____GLES_SAMPLER_STATE = 47877797;
extern const char* NAME_ELEMENT_SAMPLER_STATE____GLES_SAMPLER_STATE;
const StringHash HASH_ELEMENT_SAMPLER_STATE = 267311637;
extern const char* NAME_ELEMENT_SAMPLER_STATE;
const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER_STATE = 133824869;
extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER_STATE;
struct sampler_state____gles_sampler_state__AttributeData
{
    static const sampler_state____gles_sampler_state__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_WRAP_S____GLES_SAMPLER_WRAP = 132876992;
extern const char* NAME_ELEMENT_WRAP_S____GLES_SAMPLER_WRAP;
const StringHash HASH_ELEMENT_SAMPLER_STATE__WRAP_S = 137532627;
extern const char* NAME_ELEMENT_SAMPLER_STATE__WRAP_S;

const StringHash HASH_ELEMENT_WRAP_T____GLES_SAMPLER_WRAP = 132807360;
extern const char* NAME_ELEMENT_WRAP_T____GLES_SAMPLER_WRAP;
const StringHash HASH_ELEMENT_SAMPLER_STATE__WRAP_T = 137532628;
extern const char* NAME_ELEMENT_SAMPLER_STATE__WRAP_T;

const StringHash HASH_ELEMENT_TEXTURE_UNIT = 253386948;
extern const char* NAME_ELEMENT_TEXTURE_UNIT;
const StringHash HASH_ELEMENT_NEWPARAM__TEXTURE_UNIT = 143987060;
extern const char* NAME_ELEMENT_NEWPARAM__TEXTURE_UNIT;
struct texture_unit__AttributeData
{
    static const texture_unit__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SURFACE____NCNAME = 96983973;
extern const char* NAME_ELEMENT_SURFACE____NCNAME;
const StringHash HASH_ELEMENT_TEXTURE_UNIT__SURFACE = 214217045;
extern const char* NAME_ELEMENT_TEXTURE_UNIT__SURFACE;

const StringHash HASH_ELEMENT_SAMPLER_STATE____NCNAME = 171113877;
extern const char* NAME_ELEMENT_SAMPLER_STATE____NCNAME;
const StringHash HASH_ELEMENT_TEXTURE_UNIT__SAMPLER_STATE = 165842085;
extern const char* NAME_ELEMENT_TEXTURE_UNIT__SAMPLER_STATE;

const StringHash HASH_ELEMENT_TEXCOORD = 216686884;
extern const char* NAME_ELEMENT_TEXCOORD;
const StringHash HASH_ELEMENT_TEXTURE_UNIT__TEXCOORD = 204425796;
extern const char* NAME_ELEMENT_TEXTURE_UNIT__TEXCOORD;
struct texcoord__AttributeData
{
    static const texcoord__AttributeData DEFAULT;

    const ParserChar* semantic;
};

const StringHash HASH_ELEMENT_ENUM____GLES_ENUMERATION = 4511230;
extern const char* NAME_ELEMENT_ENUM____GLES_ENUMERATION;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE = 52481493;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE;
struct profile_GLES__technique__AttributeData
{
    static const profile_GLES__technique__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__SETPARAM = 23920173;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__SETPARAM;
const StringHash HASH_ELEMENT_TECHNIQUE__SETPARAM = 246565789;
extern const char* NAME_ELEMENT_TECHNIQUE__SETPARAM;
struct profile_GLES__technique__setparam__AttributeData
{
    static const profile_GLES__technique__setparam__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS = 175547763;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS;
const StringHash HASH_ELEMENT_PASS = 485539;
extern const char* NAME_ELEMENT_PASS;
const StringHash HASH_ELEMENT_TECHNIQUE__PASS = 79895203;
extern const char* NAME_ELEMENT_TECHNIQUE__PASS;
struct profile_GLES__technique__pass__AttributeData
{
    static const profile_GLES__technique__pass__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_COLOR_TARGET____GLES_RENDERTARGET_COMMON = 155379502;
extern const char* NAME_ELEMENT_COLOR_TARGET____GLES_RENDERTARGET_COMMON;
const StringHash HASH_ELEMENT_COLOR_TARGET = 965444;
extern const char* NAME_ELEMENT_COLOR_TARGET;
const StringHash HASH_ELEMENT_PASS__COLOR_TARGET = 94769908;
extern const char* NAME_ELEMENT_PASS__COLOR_TARGET;

const StringHash HASH_ELEMENT_DEPTH_TARGET____GLES_RENDERTARGET_COMMON = 81980142;
extern const char* NAME_ELEMENT_DEPTH_TARGET____GLES_RENDERTARGET_COMMON;
const StringHash HASH_ELEMENT_DEPTH_TARGET = 325412;
extern const char* NAME_ELEMENT_DEPTH_TARGET;
const StringHash HASH_ELEMENT_PASS__DEPTH_TARGET = 74210900;
extern const char* NAME_ELEMENT_PASS__DEPTH_TARGET;

const StringHash HASH_ELEMENT_STENCIL_TARGET____GLES_RENDERTARGET_COMMON = 110019150;
extern const char* NAME_ELEMENT_STENCIL_TARGET____GLES_RENDERTARGET_COMMON;
const StringHash HASH_ELEMENT_STENCIL_TARGET = 208409604;
extern const char* NAME_ELEMENT_STENCIL_TARGET;
const StringHash HASH_ELEMENT_PASS__STENCIL_TARGET = 75842084;
extern const char* NAME_ELEMENT_PASS__STENCIL_TARGET;

const StringHash HASH_ELEMENT_COLOR_CLEAR____FX_COLOR_COMMON = 135547134;
extern const char* NAME_ELEMENT_COLOR_CLEAR____FX_COLOR_COMMON;
const StringHash HASH_ELEMENT_COLOR_CLEAR = 137644258;
extern const char* NAME_ELEMENT_COLOR_CLEAR;
const StringHash HASH_ELEMENT_PASS__COLOR_CLEAR = 57328242;
extern const char* NAME_ELEMENT_PASS__COLOR_CLEAR;

const StringHash HASH_ELEMENT_DEPTH_CLEAR____FLOAT = 195009940;
extern const char* NAME_ELEMENT_DEPTH_CLEAR____FLOAT;
const StringHash HASH_ELEMENT_DEPTH_CLEAR = 238349346;
extern const char* NAME_ELEMENT_DEPTH_CLEAR;
const StringHash HASH_ELEMENT_PASS__DEPTH_CLEAR = 158754482;
extern const char* NAME_ELEMENT_PASS__DEPTH_CLEAR;

const StringHash HASH_ELEMENT_STENCIL_CLEAR____BYTE = 53976165;
extern const char* NAME_ELEMENT_STENCIL_CLEAR____BYTE;
const StringHash HASH_ELEMENT_STENCIL_CLEAR = 217473554;
extern const char* NAME_ELEMENT_STENCIL_CLEAR;
const StringHash HASH_ELEMENT_PASS__STENCIL_CLEAR = 243070834;
extern const char* NAME_ELEMENT_PASS__STENCIL_CLEAR;

const StringHash HASH_ELEMENT_DRAW = 440455;
extern const char* NAME_ELEMENT_DRAW;
const StringHash HASH_ELEMENT_PASS__DRAW = 156422183;
extern const char* NAME_ELEMENT_PASS__DRAW;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC = 221658707;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC;
const StringHash HASH_ELEMENT_ALPHA_FUNC = 242440483;
extern const char* NAME_ELEMENT_ALPHA_FUNC;
const StringHash HASH_ELEMENT_PASS__ALPHA_FUNC = 122155395;
extern const char* NAME_ELEMENT_PASS__ALPHA_FUNC;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC__FUNC = 109307411;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC__FUNC;
const StringHash HASH_ELEMENT_FUNC = 449603;
extern const char* NAME_ELEMENT_FUNC;
const StringHash HASH_ELEMENT_ALPHA_FUNC__FUNC = 122061667;
extern const char* NAME_ELEMENT_ALPHA_FUNC__FUNC;
struct profile_GLES__technique__pass__alpha_func__func__AttributeData
{
    static const profile_GLES__technique__pass__alpha_func__func__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC__VALUE = 135243477;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_FUNC__VALUE;
const StringHash HASH_ELEMENT_VALUE = 8160181;
extern const char* NAME_ELEMENT_VALUE;
const StringHash HASH_ELEMENT_ALPHA_FUNC__VALUE = 73003461;
extern const char* NAME_ELEMENT_ALPHA_FUNC__VALUE;
struct profile_GLES__technique__pass__alpha_func__value__AttributeData
{
    static const profile_GLES__technique__pass__alpha_func__value__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC = 132574611;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC;
const StringHash HASH_ELEMENT_BLEND_FUNC = 77810307;
extern const char* NAME_ELEMENT_BLEND_FUNC;
const StringHash HASH_ELEMENT_PASS__BLEND_FUNC = 232202851;
extern const char* NAME_ELEMENT_PASS__BLEND_FUNC;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC__SRC = 168494163;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC__SRC;
const StringHash HASH_ELEMENT_SRC = 31363;
extern const char* NAME_ELEMENT_SRC;
const StringHash HASH_ELEMENT_BLEND_FUNC__SRC = 148856355;
extern const char* NAME_ELEMENT_BLEND_FUNC__SRC;
struct profile_GLES__technique__pass__blend_func__src__AttributeData
{
    static const profile_GLES__technique__pass__blend_func__src__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC__DEST = 11747588;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_FUNC__DEST;
const StringHash HASH_ELEMENT_DEST = 437412;
extern const char* NAME_ELEMENT_DEST;
const StringHash HASH_ELEMENT_BLEND_FUNC__DEST = 234284580;
extern const char* NAME_ELEMENT_BLEND_FUNC__DEST;
struct profile_GLES__technique__pass__blend_func__dest__AttributeData
{
    static const profile_GLES__technique__pass__blend_func__dest__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_COLOR = 74334162;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_COLOR;
const StringHash HASH_ELEMENT_CLEAR_COLOR = 137661154;
extern const char* NAME_ELEMENT_CLEAR_COLOR;
const StringHash HASH_ELEMENT_PASS__CLEAR_COLOR = 57345138;
extern const char* NAME_ELEMENT_PASS__CLEAR_COLOR;
struct profile_GLES__technique__pass__clear_color__AttributeData
{
    static const profile_GLES__technique__pass__clear_color__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_STENCIL = 249101740;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_STENCIL;
const StringHash HASH_ELEMENT_CLEAR_STENCIL = 8503804;
extern const char* NAME_ELEMENT_CLEAR_STENCIL;
const StringHash HASH_ELEMENT_PASS__CLEAR_STENCIL = 168516268;
extern const char* NAME_ELEMENT_PASS__CLEAR_STENCIL;
struct profile_GLES__technique__pass__clear_stencil__AttributeData
{
    static const profile_GLES__technique__pass__clear_stencil__AttributeData DEFAULT;

    sint64 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_DEPTH = 74365720;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLEAR_DEPTH;
const StringHash HASH_ELEMENT_CLEAR_DEPTH = 137423912;
extern const char* NAME_ELEMENT_CLEAR_DEPTH;
const StringHash HASH_ELEMENT_PASS__CLEAR_DEPTH = 57304760;
extern const char* NAME_ELEMENT_PASS__CLEAR_DEPTH;
struct profile_GLES__technique__pass__clear_depth__AttributeData
{
    static const profile_GLES__technique__pass__clear_depth__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLIP_PLANE = 119959605;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLIP_PLANE;
const StringHash HASH_ELEMENT_CLIP_PLANE = 107054405;
extern const char* NAME_ELEMENT_CLIP_PLANE;
const StringHash HASH_ELEMENT_PASS__CLIP_PLANE = 221654501;
extern const char* NAME_ELEMENT_PASS__CLIP_PLANE;
const StringHash HASH_ATTRIBUTE_INDEX = 7359176;
extern const char* NAME_ATTRIBUTE_INDEX;
struct profile_GLES__technique__pass__clip_plane__AttributeData
{
    static const profile_GLES__technique__pass__clip_plane__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<bool> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_MASK = 88570363;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_MASK;
const StringHash HASH_ELEMENT_COLOR_MASK = 109354667;
extern const char* NAME_ELEMENT_COLOR_MASK;
const StringHash HASH_ELEMENT_PASS__COLOR_MASK = 255276555;
extern const char* NAME_ELEMENT_PASS__COLOR_MASK;
struct profile_GLES__technique__pass__color_mask__AttributeData
{
    static const profile_GLES__technique__pass__color_mask__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<bool> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CULL_FACE = 103937893;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CULL_FACE;
const StringHash HASH_ELEMENT_CULL_FACE = 52800853;
extern const char* NAME_ELEMENT_CULL_FACE;
const StringHash HASH_ELEMENT_PASS__CULL_FACE = 160492501;
extern const char* NAME_ELEMENT_PASS__CULL_FACE;
struct profile_GLES__technique__pass__cull_face__AttributeData
{
    static const profile_GLES__technique__pass__cull_face__AttributeData DEFAULT;

    ENUM__gl_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_FUNC = 161928003;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_FUNC;
const StringHash HASH_ELEMENT_DEPTH_FUNC = 182679603;
extern const char* NAME_ELEMENT_DEPTH_FUNC;
const StringHash HASH_ELEMENT_PASS__DEPTH_FUNC = 60235923;
extern const char* NAME_ELEMENT_PASS__DEPTH_FUNC;
struct profile_GLES__technique__pass__depth_func__AttributeData
{
    static const profile_GLES__technique__pass__depth_func__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_MASK = 161952155;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_MASK;
const StringHash HASH_ELEMENT_DEPTH_MASK = 182752491;
extern const char* NAME_ELEMENT_DEPTH_MASK;
const StringHash HASH_ELEMENT_PASS__DEPTH_MASK = 60357707;
extern const char* NAME_ELEMENT_PASS__DEPTH_MASK;
struct profile_GLES__technique__pass__depth_mask__AttributeData
{
    static const profile_GLES__technique__pass__depth_mask__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_RANGE = 173601861;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_RANGE;
const StringHash HASH_ELEMENT_DEPTH_RANGE = 235062133;
extern const char* NAME_ELEMENT_DEPTH_RANGE;
const StringHash HASH_ELEMENT_PASS__DEPTH_RANGE = 155470309;
extern const char* NAME_ELEMENT_PASS__DEPTH_RANGE;
struct profile_GLES__technique__pass__depth_range__AttributeData
{
    static const profile_GLES__technique__pass__depth_range__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_COLOR = 208565858;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_COLOR;
const StringHash HASH_ELEMENT_FOG_COLOR = 224022578;
extern const char* NAME_ELEMENT_FOG_COLOR;
const StringHash HASH_ELEMENT_PASS__FOG_COLOR = 130910898;
extern const char* NAME_ELEMENT_PASS__FOG_COLOR;
struct profile_GLES__technique__pass__fog_color__AttributeData
{
    static const profile_GLES__technique__pass__fog_color__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_DENSITY = 244493529;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_DENSITY;
const StringHash HASH_ELEMENT_FOG_DENSITY = 183033321;
extern const char* NAME_ELEMENT_FOG_DENSITY;
const StringHash HASH_ELEMENT_PASS__FOG_DENSITY = 263083897;
extern const char* NAME_ELEMENT_PASS__FOG_DENSITY;
struct profile_GLES__technique__pass__fog_density__AttributeData
{
    static const profile_GLES__technique__pass__fog_density__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_MODE = 13076181;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_MODE;
const StringHash HASH_ELEMENT_FOG_MODE = 97928053;
extern const char* NAME_ELEMENT_FOG_MODE;
const StringHash HASH_ELEMENT_PASS__FOG_MODE = 226326293;
extern const char* NAME_ELEMENT_PASS__FOG_MODE;
struct profile_GLES__technique__pass__fog_mode__AttributeData
{
    static const profile_GLES__technique__pass__fog_mode__AttributeData DEFAULT;

    ENUM__gl_fog_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_START = 207527828;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_START;
const StringHash HASH_ELEMENT_FOG_START = 225101252;
extern const char* NAME_ELEMENT_FOG_START;
const StringHash HASH_ELEMENT_PASS__FOG_START = 134185796;
extern const char* NAME_ELEMENT_PASS__FOG_START;
struct profile_GLES__technique__pass__fog_start__AttributeData
{
    static const profile_GLES__technique__pass__fog_start__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_END = 118255732;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_END;
const StringHash HASH_ELEMENT_FOG_END = 224222244;
extern const char* NAME_ELEMENT_FOG_END;
const StringHash HASH_ELEMENT_PASS__FOG_END = 198692708;
extern const char* NAME_ELEMENT_PASS__FOG_END;
struct profile_GLES__technique__pass__fog_end__AttributeData
{
    static const profile_GLES__technique__pass__fog_end__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FRONT_FACE = 115784101;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FRONT_FACE;
const StringHash HASH_ELEMENT_FRONT_FACE = 94576373;
extern const char* NAME_ELEMENT_FRONT_FACE;
const StringHash HASH_ELEMENT_PASS__FRONT_FACE = 215446933;
extern const char* NAME_ELEMENT_PASS__FRONT_FACE;
struct profile_GLES__technique__pass__front_face__AttributeData
{
    static const profile_GLES__technique__pass__front_face__AttributeData DEFAULT;

    ENUM__gl_front_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__TEXTURE_PIPELINE = 149197237;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__TEXTURE_PIPELINE;
const StringHash HASH_ELEMENT_PASS__TEXTURE_PIPELINE = 49503749;
extern const char* NAME_ELEMENT_PASS__TEXTURE_PIPELINE;
struct profile_GLES__technique__pass__texture_pipeline__AttributeData
{
    static const profile_GLES__technique__pass__texture_pipeline__AttributeData DEFAULT;

    const ParserChar* param;
};

const StringHash HASH_ELEMENT_VALUE____GLES_TEXTURE_PIPELINE = 59331413;
extern const char* NAME_ELEMENT_VALUE____GLES_TEXTURE_PIPELINE;
const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__VALUE = 255798677;
extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__VALUE;
typedef texture_pipeline____gles_texture_pipeline__AttributeData value____gles_texture_pipeline__AttributeData;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LOGIC_OP = 11326192;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LOGIC_OP;
const StringHash HASH_ELEMENT_LOGIC_OP = 98538320;
extern const char* NAME_ELEMENT_LOGIC_OP;
const StringHash HASH_ELEMENT_PASS__LOGIC_OP = 225896240;
extern const char* NAME_ELEMENT_PASS__LOGIC_OP;
struct profile_GLES__technique__pass__logic_op__AttributeData
{
    static const profile_GLES__technique__pass__logic_op__AttributeData DEFAULT;

    ENUM__gl_logic_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_AMBIENT = 9582196;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_AMBIENT;
const StringHash HASH_ELEMENT_LIGHT_AMBIENT = 113574516;
extern const char* NAME_ELEMENT_LIGHT_AMBIENT;
const StringHash HASH_ELEMENT_PASS__LIGHT_AMBIENT = 72324916;
extern const char* NAME_ELEMENT_PASS__LIGHT_AMBIENT;
struct profile_GLES__technique__pass__light_ambient__AttributeData
{
    static const profile_GLES__technique__pass__light_ambient__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_DIFFUSE = 39195269;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_DIFFUSE;
const StringHash HASH_ELEMENT_LIGHT_DIFFUSE = 134293173;
extern const char* NAME_ELEMENT_LIGHT_DIFFUSE;
const StringHash HASH_ELEMENT_PASS__LIGHT_DIFFUSE = 244036085;
extern const char* NAME_ELEMENT_PASS__LIGHT_DIFFUSE;
struct profile_GLES__technique__pass__light_diffuse__AttributeData
{
    static const profile_GLES__technique__pass__light_diffuse__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPECULAR = 202793122;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPECULAR;
const StringHash HASH_ELEMENT_LIGHT_SPECULAR = 157623042;
extern const char* NAME_ELEMENT_LIGHT_SPECULAR;
const StringHash HASH_ELEMENT_PASS__LIGHT_SPECULAR = 30177122;
extern const char* NAME_ELEMENT_PASS__LIGHT_SPECULAR;
struct profile_GLES__technique__pass__light_specular__AttributeData
{
    static const profile_GLES__technique__pass__light_specular__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_POSITION = 206327470;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_POSITION;
const StringHash HASH_ELEMENT_LIGHT_POSITION = 157224718;
extern const char* NAME_ELEMENT_LIGHT_POSITION;
const StringHash HASH_ELEMENT_PASS__LIGHT_POSITION = 32930670;
extern const char* NAME_ELEMENT_PASS__LIGHT_POSITION;
struct profile_GLES__technique__pass__light_position__AttributeData
{
    static const profile_GLES__technique__pass__light_position__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION = 253121470;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION;
const StringHash HASH_ELEMENT_LIGHT_CONSTANT_ATTENUATION = 107287662;
extern const char* NAME_ELEMENT_LIGHT_CONSTANT_ATTENUATION;
const StringHash HASH_ELEMENT_PASS__LIGHT_CONSTANT_ATTENUATION = 248277070;
extern const char* NAME_ELEMENT_PASS__LIGHT_CONSTANT_ATTENUATION;
struct profile_GLES__technique__pass__light_constant_attenuation__AttributeData
{
    static const profile_GLES__technique__pass__light_constant_attenuation__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_LIGHT_LINEAR_ATTENUTATION = 154814046;
extern const char* NAME_ELEMENT_LIGHT_LINEAR_ATTENUTATION;
const StringHash HASH_ELEMENT_PASS__LIGHT_LINEAR_ATTENUTATION = 263246110;
extern const char* NAME_ELEMENT_PASS__LIGHT_LINEAR_ATTENUTATION;
struct light_linear_attenutation__AttributeData
{
    static const light_linear_attenutation__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION = 60211262;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION;
const StringHash HASH_ELEMENT_LIGHT_QUADRATIC_ATTENUATION = 111314510;
extern const char* NAME_ELEMENT_LIGHT_QUADRATIC_ATTENUATION;
const StringHash HASH_ELEMENT_PASS__LIGHT_QUADRATIC_ATTENUATION = 204850382;
extern const char* NAME_ELEMENT_PASS__LIGHT_QUADRATIC_ATTENUATION;
struct profile_GLES__technique__pass__light_quadratic_attenuation__AttributeData
{
    static const profile_GLES__technique__pass__light_quadratic_attenuation__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF = 193890726;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF;
const StringHash HASH_ELEMENT_LIGHT_SPOT_CUTOFF = 263462582;
extern const char* NAME_ELEMENT_LIGHT_SPOT_CUTOFF;
const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_CUTOFF = 150116294;
extern const char* NAME_ELEMENT_PASS__LIGHT_SPOT_CUTOFF;
struct profile_GLES__technique__pass__light_spot_cutoff__AttributeData
{
    static const profile_GLES__technique__pass__light_spot_cutoff__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION = 92018558;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION;
const StringHash HASH_ELEMENT_LIGHT_SPOT_DIRECTION = 34428126;
extern const char* NAME_ELEMENT_LIGHT_SPOT_DIRECTION;
const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_DIRECTION = 177881278;
extern const char* NAME_ELEMENT_PASS__LIGHT_SPOT_DIRECTION;
struct profile_GLES__technique__pass__light_spot_direction__AttributeData
{
    static const profile_GLES__technique__pass__light_spot_direction__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT = 231350708;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT;
const StringHash HASH_ELEMENT_LIGHT_SPOT_EXPONENT = 132068740;
extern const char* NAME_ELEMENT_LIGHT_SPOT_EXPONENT;
const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_EXPONENT = 22561988;
extern const char* NAME_ELEMENT_PASS__LIGHT_SPOT_EXPONENT;
struct profile_GLES__technique__pass__light_spot_exponent__AttributeData
{
    static const profile_GLES__technique__pass__light_spot_exponent__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT = 214461476;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT;
const StringHash HASH_ELEMENT_LIGHT_MODEL_AMBIENT = 111126580;
extern const char* NAME_ELEMENT_LIGHT_MODEL_AMBIENT;
const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_AMBIENT = 1382244;
extern const char* NAME_ELEMENT_PASS__LIGHT_MODEL_AMBIENT;
struct profile_GLES__technique__pass__light_model_ambient__AttributeData
{
    static const profile_GLES__technique__pass__light_model_ambient__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LINE_WIDTH = 170487960;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LINE_WIDTH;
const StringHash HASH_ELEMENT_LINE_WIDTH = 191548392;
extern const char* NAME_ELEMENT_LINE_WIDTH;
const StringHash HASH_ELEMENT_PASS__LINE_WIDTH = 71217992;
extern const char* NAME_ELEMENT_PASS__LINE_WIDTH;
struct profile_GLES__technique__pass__line_width__AttributeData
{
    static const profile_GLES__technique__pass__line_width__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_AMBIENT = 166922196;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_AMBIENT;
const StringHash HASH_ELEMENT_MATERIAL_AMBIENT = 212902564;
extern const char* NAME_ELEMENT_MATERIAL_AMBIENT;
const StringHash HASH_ELEMENT_PASS__MATERIAL_AMBIENT = 65325572;
extern const char* NAME_ELEMENT_PASS__MATERIAL_AMBIENT;
struct profile_GLES__technique__pass__material_ambient__AttributeData
{
    static const profile_GLES__technique__pass__material_ambient__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_DIFFUSE = 87499029;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_DIFFUSE;
const StringHash HASH_ELEMENT_MATERIAL_DIFFUSE = 108299877;
extern const char* NAME_ELEMENT_MATERIAL_DIFFUSE;
const StringHash HASH_ELEMENT_PASS__MATERIAL_DIFFUSE = 253816517;
extern const char* NAME_ELEMENT_PASS__MATERIAL_DIFFUSE;
struct profile_GLES__technique__pass__material_diffuse__AttributeData
{
    static const profile_GLES__technique__pass__material_diffuse__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_EMISSION = 11880510;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_EMISSION;
const StringHash HASH_ELEMENT_MATERIAL_EMISSION = 210711006;
extern const char* NAME_ELEMENT_MATERIAL_EMISSION;
const StringHash HASH_ELEMENT_PASS__MATERIAL_EMISSION = 264879022;
extern const char* NAME_ELEMENT_PASS__MATERIAL_EMISSION;
struct profile_GLES__technique__pass__material_emission__AttributeData
{
    static const profile_GLES__technique__pass__material_emission__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_SHININESS = 95681155;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_SHININESS;
const StringHash HASH_ELEMENT_MATERIAL_SHININESS = 135694787;
extern const char* NAME_ELEMENT_MATERIAL_SHININESS;
const StringHash HASH_ELEMENT_PASS__MATERIAL_SHININESS = 75374739;
extern const char* NAME_ELEMENT_PASS__MATERIAL_SHININESS;
struct profile_GLES__technique__pass__material_shininess__AttributeData
{
    static const profile_GLES__technique__pass__material_shininess__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_SPECULAR = 168131026;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MATERIAL_SPECULAR;
const StringHash HASH_ELEMENT_MATERIAL_SPECULAR = 239021794;
extern const char* NAME_ELEMENT_MATERIAL_SPECULAR;
const StringHash HASH_ELEMENT_PASS__MATERIAL_SPECULAR = 192521330;
extern const char* NAME_ELEMENT_PASS__MATERIAL_SPECULAR;
struct profile_GLES__technique__pass__material_specular__AttributeData
{
    static const profile_GLES__technique__pass__material_specular__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MODEL_VIEW_MATRIX = 69093992;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MODEL_VIEW_MATRIX;
const StringHash HASH_ELEMENT_MODEL_VIEW_MATRIX = 136322840;
extern const char* NAME_ELEMENT_MODEL_VIEW_MATRIX;
const StringHash HASH_ELEMENT_PASS__MODEL_VIEW_MATRIX = 23238152;
extern const char* NAME_ELEMENT_PASS__MODEL_VIEW_MATRIX;
struct profile_GLES__technique__pass__model_view_matrix__AttributeData
{
    static const profile_GLES__technique__pass__model_view_matrix__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION = 249345518;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION;
const StringHash HASH_ELEMENT_POINT_DISTANCE_ATTENUATION = 139457678;
extern const char* NAME_ELEMENT_POINT_DISTANCE_ATTENUATION;
const StringHash HASH_ELEMENT_PASS__POINT_DISTANCE_ATTENUATION = 220636846;
extern const char* NAME_ELEMENT_PASS__POINT_DISTANCE_ATTENUATION;
struct profile_GLES__technique__pass__point_distance_attenuation__AttributeData
{
    static const profile_GLES__technique__pass__point_distance_attenuation__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE = 209316021;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE;
const StringHash HASH_ELEMENT_POINT_FADE_THRESHOLD_SIZE = 101782757;
extern const char* NAME_ELEMENT_POINT_FADE_THRESHOLD_SIZE;
const StringHash HASH_ELEMENT_PASS__POINT_FADE_THRESHOLD_SIZE = 13010885;
extern const char* NAME_ELEMENT_PASS__POINT_FADE_THRESHOLD_SIZE;
struct profile_GLES__technique__pass__point_fade_threshold_size__AttributeData
{
    static const profile_GLES__technique__pass__point_fade_threshold_size__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE = 115757461;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE;
const StringHash HASH_ELEMENT_POINT_SIZE = 94500613;
extern const char* NAME_ELEMENT_POINT_SIZE;
const StringHash HASH_ELEMENT_PASS__POINT_SIZE = 215457381;
extern const char* NAME_ELEMENT_PASS__POINT_SIZE;
struct profile_GLES__technique__pass__point_size__AttributeData
{
    static const profile_GLES__technique__pass__point_size__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE_MIN = 27116974;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE_MIN;
const StringHash HASH_ELEMENT_POINT_SIZE_MIN = 118555150;
extern const char* NAME_ELEMENT_POINT_SIZE_MIN;
const StringHash HASH_ELEMENT_PASS__POINT_SIZE_MIN = 241669230;
extern const char* NAME_ELEMENT_PASS__POINT_SIZE_MIN;
struct profile_GLES__technique__pass__point_size_min__AttributeData
{
    static const profile_GLES__technique__pass__point_size_min__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE_MAX = 27117016;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SIZE_MAX;
const StringHash HASH_ELEMENT_POINT_SIZE_MAX = 118555256;
extern const char* NAME_ELEMENT_POINT_SIZE_MAX;
const StringHash HASH_ELEMENT_PASS__POINT_SIZE_MAX = 241669144;
extern const char* NAME_ELEMENT_PASS__POINT_SIZE_MAX;
struct profile_GLES__technique__pass__point_size_max__AttributeData
{
    static const profile_GLES__technique__pass__point_size_max__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POLYGON_OFFSET = 84967220;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POLYGON_OFFSET;
const StringHash HASH_ELEMENT_POLYGON_OFFSET = 73611924;
extern const char* NAME_ELEMENT_POLYGON_OFFSET;
const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET = 214584564;
extern const char* NAME_ELEMENT_PASS__POLYGON_OFFSET;
struct profile_GLES__technique__pass__polygon_offset__AttributeData
{
    static const profile_GLES__technique__pass__polygon_offset__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__PROJECTION_MATRIX = 195010584;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__PROJECTION_MATRIX;
const StringHash HASH_ELEMENT_PROJECTION_MATRIX = 266718536;
extern const char* NAME_ELEMENT_PROJECTION_MATRIX;
const StringHash HASH_ELEMENT_PASS__PROJECTION_MATRIX = 209936312;
extern const char* NAME_ELEMENT_PASS__PROJECTION_MATRIX;
struct profile_GLES__technique__pass__projection_matrix__AttributeData
{
    static const profile_GLES__technique__pass__projection_matrix__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SCISSOR = 64462434;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SCISSOR;
const StringHash HASH_ELEMENT_SCISSOR = 161524242;
extern const char* NAME_ELEMENT_SCISSOR;
const StringHash HASH_ELEMENT_PASS__SCISSOR = 254426482;
extern const char* NAME_ELEMENT_PASS__SCISSOR;
struct profile_GLES__technique__pass__scissor__AttributeData
{
    static const profile_GLES__technique__pass__scissor__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<sint64> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SHADE_MODEL = 258075180;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SHADE_MODEL;
const StringHash HASH_ELEMENT_SHADE_MODEL = 188464412;
extern const char* NAME_ELEMENT_SHADE_MODEL;
const StringHash HASH_ELEMENT_PASS__SHADE_MODEL = 6109180;
extern const char* NAME_ELEMENT_PASS__SHADE_MODEL;
struct profile_GLES__technique__pass__shade_model__AttributeData
{
    static const profile_GLES__technique__pass__shade_model__AttributeData DEFAULT;

    ENUM__gl_shade_model_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC = 2756003;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC;
const StringHash HASH_ELEMENT_STENCIL_FUNC = 164569299;
extern const char* NAME_ELEMENT_STENCIL_FUNC;
const StringHash HASH_ELEMENT_PASS__STENCIL_FUNC = 266860419;
extern const char* NAME_ELEMENT_PASS__STENCIL_FUNC;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__FUNC = 159373283;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__FUNC;
const StringHash HASH_ELEMENT_STENCIL_FUNC__FUNC = 43711635;
extern const char* NAME_ELEMENT_STENCIL_FUNC__FUNC;
struct profile_GLES__technique__pass__stencil_func__func__AttributeData
{
    static const profile_GLES__technique__pass__stencil_func__func__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__REF = 177719398;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__REF;
const StringHash HASH_ELEMENT_REF = 30902;
extern const char* NAME_ELEMENT_REF;
const StringHash HASH_ELEMENT_STENCIL_FUNC__REF = 220830390;
extern const char* NAME_ELEMENT_STENCIL_FUNC__REF;
struct profile_GLES__technique__pass__stencil_func__ref__AttributeData
{
    static const profile_GLES__technique__pass__stencil_func__ref__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__MASK = 159397179;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_FUNC__MASK;
const StringHash HASH_ELEMENT_MASK = 473243;
extern const char* NAME_ELEMENT_MASK;
const StringHash HASH_ELEMENT_STENCIL_FUNC__MASK = 43718731;
extern const char* NAME_ELEMENT_STENCIL_FUNC__MASK;
struct profile_GLES__technique__pass__stencil_func__mask__AttributeData
{
    static const profile_GLES__technique__pass__stencil_func__mask__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_MASK = 2879355;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_MASK;
const StringHash HASH_ELEMENT_STENCIL_MASK = 164690955;
extern const char* NAME_ELEMENT_STENCIL_MASK;
const StringHash HASH_ELEMENT_PASS__STENCIL_MASK = 266868059;
extern const char* NAME_ELEMENT_PASS__STENCIL_MASK;
struct profile_GLES__technique__pass__stencil_mask__AttributeData
{
    static const profile_GLES__technique__pass__stencil_mask__AttributeData DEFAULT;

    sint64 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP = 132131760;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP;
const StringHash HASH_ELEMENT_STENCIL_OP = 77189280;
extern const char* NAME_ELEMENT_STENCIL_OP;
const StringHash HASH_ELEMENT_PASS__STENCIL_OP = 231729216;
extern const char* NAME_ELEMENT_PASS__STENCIL_OP;

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__FAIL = 62254156;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__FAIL;
const StringHash HASH_ELEMENT_FAIL = 444412;
extern const char* NAME_ELEMENT_FAIL;
const StringHash HASH_ELEMENT_STENCIL_OP__FAIL = 49026908;
extern const char* NAME_ELEMENT_STENCIL_OP__FAIL;
struct profile_GLES__technique__pass__stencil_op__fail__AttributeData
{
    static const profile_GLES__technique__pass__stencil_op__fail__AttributeData DEFAULT;

    ENUM__gles_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__ZFAIL = 192052428;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__ZFAIL;
const StringHash HASH_ELEMENT_ZFAIL = 8439804;
extern const char* NAME_ELEMENT_ZFAIL;
const StringHash HASH_ELEMENT_STENCIL_OP__ZFAIL = 252562908;
extern const char* NAME_ELEMENT_STENCIL_OP__ZFAIL;
struct profile_GLES__technique__pass__stencil_op__zfail__AttributeData
{
    static const profile_GLES__technique__pass__stencil_op__zfail__AttributeData DEFAULT;

    ENUM__gles_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__ZPASS = 192140179;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_OP__ZPASS;
const StringHash HASH_ELEMENT_ZPASS = 8480931;
extern const char* NAME_ELEMENT_ZPASS;
const StringHash HASH_ELEMENT_STENCIL_OP__ZPASS = 252469891;
extern const char* NAME_ELEMENT_STENCIL_OP__ZPASS;
struct profile_GLES__technique__pass__stencil_op__zpass__AttributeData
{
    static const profile_GLES__technique__pass__stencil_op__zpass__AttributeData DEFAULT;

    ENUM__gles_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_TEST_ENABLE = 116446325;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__ALPHA_TEST_ENABLE;
const StringHash HASH_ELEMENT_ALPHA_TEST_ENABLE = 46564773;
extern const char* NAME_ELEMENT_ALPHA_TEST_ENABLE;
const StringHash HASH_ELEMENT_PASS__ALPHA_TEST_ENABLE = 34344917;
extern const char* NAME_ELEMENT_PASS__ALPHA_TEST_ENABLE;
struct profile_GLES__technique__pass__alpha_test_enable__AttributeData
{
    static const profile_GLES__technique__pass__alpha_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_ENABLE = 110342341;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__BLEND_ENABLE;
const StringHash HASH_ELEMENT_BLEND_ENABLE = 53919109;
extern const char* NAME_ELEMENT_BLEND_ENABLE;
const StringHash HASH_ELEMENT_PASS__BLEND_ENABLE = 123623157;
extern const char* NAME_ELEMENT_PASS__BLEND_ENABLE;
struct profile_GLES__technique__pass__blend_enable__AttributeData
{
    static const profile_GLES__technique__pass__blend_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLIP_PLANE_ENABLE = 132349125;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CLIP_PLANE_ENABLE;
const StringHash HASH_ELEMENT_CLIP_PLANE_ENABLE = 62664181;
extern const char* NAME_ELEMENT_CLIP_PLANE_ENABLE;
const StringHash HASH_ELEMENT_PASS__CLIP_PLANE_ENABLE = 115779493;
extern const char* NAME_ELEMENT_PASS__CLIP_PLANE_ENABLE;
struct profile_GLES__technique__pass__clip_plane_enable__AttributeData
{
    static const profile_GLES__technique__pass__clip_plane_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE = 237586949;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE;
const StringHash HASH_ELEMENT_COLOR_LOGIC_OP_ENABLE = 188045397;
extern const char* NAME_ELEMENT_COLOR_LOGIC_OP_ENABLE;
const StringHash HASH_ELEMENT_PASS__COLOR_LOGIC_OP_ENABLE = 29904597;
extern const char* NAME_ELEMENT_PASS__COLOR_LOGIC_OP_ENABLE;
struct profile_GLES__technique__pass__color_logic_op_enable__AttributeData
{
    static const profile_GLES__technique__pass__color_logic_op_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE = 154729141;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE;
const StringHash HASH_ELEMENT_COLOR_MATERIAL_ENABLE = 203733285;
extern const char* NAME_ELEMENT_COLOR_MATERIAL_ENABLE;
const StringHash HASH_ELEMENT_PASS__COLOR_MATERIAL_ENABLE = 111148709;
extern const char* NAME_ELEMENT_PASS__COLOR_MATERIAL_ENABLE;
struct profile_GLES__technique__pass__color_material_enable__AttributeData
{
    static const profile_GLES__technique__pass__color_material_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CULL_FACE_ENABLE = 112922613;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__CULL_FACE_ENABLE;
const StringHash HASH_ELEMENT_CULL_FACE_ENABLE = 134131333;
extern const char* NAME_ELEMENT_CULL_FACE_ENABLE;
const StringHash HASH_ELEMENT_PASS__CULL_FACE_ENABLE = 214615653;
extern const char* NAME_ELEMENT_PASS__CULL_FACE_ENABLE;
struct profile_GLES__technique__pass__cull_face_enable__AttributeData
{
    static const profile_GLES__technique__pass__cull_face_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_TEST_ENABLE = 268313397;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DEPTH_TEST_ENABLE;
const StringHash HASH_ELEMENT_DEPTH_TEST_ENABLE = 197424741;
extern const char* NAME_ELEMENT_DEPTH_TEST_ENABLE;
const StringHash HASH_ELEMENT_PASS__DEPTH_TEST_ENABLE = 218300565;
extern const char* NAME_ELEMENT_PASS__DEPTH_TEST_ENABLE;
struct profile_GLES__technique__pass__depth_test_enable__AttributeData
{
    static const profile_GLES__technique__pass__depth_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DITHER_ENABLE = 83468661;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__DITHER_ENABLE;
const StringHash HASH_ELEMENT_DITHER_ENABLE = 248419589;
extern const char* NAME_ELEMENT_DITHER_ENABLE;
const StringHash HASH_ELEMENT_PASS__DITHER_ENABLE = 138674757;
extern const char* NAME_ELEMENT_PASS__DITHER_ENABLE;
struct profile_GLES__technique__pass__dither_enable__AttributeData
{
    static const profile_GLES__technique__pass__dither_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_ENABLE = 117901797;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__FOG_ENABLE;
const StringHash HASH_ELEMENT_FOG_ENABLE = 96644853;
extern const char* NAME_ELEMENT_FOG_ENABLE;
const StringHash HASH_ELEMENT_PASS__FOG_ENABLE = 217499221;
extern const char* NAME_ELEMENT_PASS__FOG_ENABLE;
struct profile_GLES__technique__pass__fog_enable__AttributeData
{
    static const profile_GLES__technique__pass__fog_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_TEXTURE_PIPELINE_ENABLE = 267851525;
extern const char* NAME_ELEMENT_TEXTURE_PIPELINE_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTURE_PIPELINE_ENABLE = 177314229;
extern const char* NAME_ELEMENT_PASS__TEXTURE_PIPELINE_ENABLE;
struct texture_pipeline_enable__AttributeData
{
    static const texture_pipeline_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_ENABLE = 21943749;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_ENABLE;
const StringHash HASH_ELEMENT_LIGHT_ENABLE = 44804229;
extern const char* NAME_ELEMENT_LIGHT_ENABLE;
const StringHash HASH_ELEMENT_PASS__LIGHT_ENABLE = 117641205;
extern const char* NAME_ELEMENT_PASS__LIGHT_ENABLE;
struct profile_GLES__technique__pass__light_enable__AttributeData
{
    static const profile_GLES__technique__pass__light_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHTING_ENABLE = 260748629;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHTING_ENABLE;
const StringHash HASH_ELEMENT_LIGHTING_ENABLE = 140439397;
extern const char* NAME_ELEMENT_LIGHTING_ENABLE;
const StringHash HASH_ELEMENT_PASS__LIGHTING_ENABLE = 48998885;
extern const char* NAME_ELEMENT_PASS__LIGHTING_ENABLE;
struct profile_GLES__technique__pass__lighting_enable__AttributeData
{
    static const profile_GLES__technique__pass__lighting_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE = 6145669;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
const StringHash HASH_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE = 26336277;
extern const char* NAME_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE;
const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_TWO_SIDE_ENABLE = 255891349;
extern const char* NAME_ELEMENT_PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
struct profile_GLES__technique__pass__light_model_two_side_enable__AttributeData
{
    static const profile_GLES__technique__pass__light_model_two_side_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE = 193669669;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE;
const StringHash HASH_ELEMENT_LINE_SMOOTH_ENABLE = 179460837;
extern const char* NAME_ELEMENT_LINE_SMOOTH_ENABLE;
const StringHash HASH_ELEMENT_PASS__LINE_SMOOTH_ENABLE = 239794133;
extern const char* NAME_ELEMENT_PASS__LINE_SMOOTH_ENABLE;
struct profile_GLES__technique__pass__line_smooth_enable__AttributeData
{
    static const profile_GLES__technique__pass__line_smooth_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MULTISAMPLE_ENABLE = 137314773;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__MULTISAMPLE_ENABLE;
const StringHash HASH_ELEMENT_MULTISAMPLE_ENABLE = 202117781;
extern const char* NAME_ELEMENT_MULTISAMPLE_ENABLE;
const StringHash HASH_ELEMENT_PASS__MULTISAMPLE_ENABLE = 266698789;
extern const char* NAME_ELEMENT_PASS__MULTISAMPLE_ENABLE;
struct profile_GLES__technique__pass__multisample_enable__AttributeData
{
    static const profile_GLES__technique__pass__multisample_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__NORMALIZE_ENABLE = 101481877;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__NORMALIZE_ENABLE;
const StringHash HASH_ELEMENT_NORMALIZE_ENABLE = 104996709;
extern const char* NAME_ELEMENT_NORMALIZE_ENABLE;
const StringHash HASH_ELEMENT_PASS__NORMALIZE_ENABLE = 261502853;
extern const char* NAME_ELEMENT_PASS__NORMALIZE_ENABLE;
struct profile_GLES__technique__pass__normalize_enable__AttributeData
{
    static const profile_GLES__technique__pass__normalize_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE = 17399269;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE;
const StringHash HASH_ELEMENT_POINT_SMOOTH_ENABLE = 182602229;
extern const char* NAME_ELEMENT_POINT_SMOOTH_ENABLE;
const StringHash HASH_ELEMENT_PASS__POINT_SMOOTH_ENABLE = 206626965;
extern const char* NAME_ELEMENT_PASS__POINT_SMOOTH_ENABLE;
struct profile_GLES__technique__pass__point_smooth_enable__AttributeData
{
    static const profile_GLES__technique__pass__point_smooth_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE = 151578389;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE;
const StringHash HASH_ELEMENT_POLYGON_OFFSET_FILL_ENABLE = 194749109;
extern const char* NAME_ELEMENT_POLYGON_OFFSET_FILL_ENABLE;
const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET_FILL_ENABLE = 53655765;
extern const char* NAME_ELEMENT_PASS__POLYGON_OFFSET_FILL_ENABLE;
struct profile_GLES__technique__pass__polygon_offset_fill_enable__AttributeData
{
    static const profile_GLES__technique__pass__polygon_offset_fill_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE = 243886325;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE;
const StringHash HASH_ELEMENT_RESCALE_NORMAL_ENABLE = 190127845;
extern const char* NAME_ELEMENT_RESCALE_NORMAL_ENABLE;
const StringHash HASH_ELEMENT_PASS__RESCALE_NORMAL_ENABLE = 233340005;
extern const char* NAME_ELEMENT_PASS__RESCALE_NORMAL_ENABLE;
struct profile_GLES__technique__pass__rescale_normal_enable__AttributeData
{
    static const profile_GLES__technique__pass__rescale_normal_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 143218709;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
const StringHash HASH_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 47727685;
extern const char* NAME_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
const StringHash HASH_ELEMENT_PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 173355765;
extern const char* NAME_ELEMENT_PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
struct profile_GLES__technique__pass__sample_alpha_to_coverage_enable__AttributeData
{
    static const profile_GLES__technique__pass__sample_alpha_to_coverage_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE = 99783653;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
const StringHash HASH_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE = 251778565;
extern const char* NAME_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE;
const StringHash HASH_ELEMENT_PASS__SAMPLE_ALPHA_TO_ONE_ENABLE = 103906693;
extern const char* NAME_ELEMENT_PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
struct profile_GLES__technique__pass__sample_alpha_to_one_enable__AttributeData
{
    static const profile_GLES__technique__pass__sample_alpha_to_one_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE = 254242853;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE;
const StringHash HASH_ELEMENT_SAMPLE_COVERAGE_ENABLE = 241354933;
extern const char* NAME_ELEMENT_SAMPLE_COVERAGE_ENABLE;
const StringHash HASH_ELEMENT_PASS__SAMPLE_COVERAGE_ENABLE = 152395877;
extern const char* NAME_ELEMENT_PASS__SAMPLE_COVERAGE_ENABLE;
struct profile_GLES__technique__pass__sample_coverage_enable__AttributeData
{
    static const profile_GLES__technique__pass__sample_coverage_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE = 1650213;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE;
const StringHash HASH_ELEMENT_SCISSOR_TEST_ENABLE = 177084853;
extern const char* NAME_ELEMENT_SCISSOR_TEST_ENABLE;
const StringHash HASH_ELEMENT_PASS__SCISSOR_TEST_ENABLE = 218403029;
extern const char* NAME_ELEMENT_PASS__SCISSOR_TEST_ENABLE;
struct profile_GLES__technique__pass__scissor_test_enable__AttributeData
{
    static const profile_GLES__technique__pass__scissor_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_TEST_ENABLE = 120835461;
extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE__PASS__STENCIL_TEST_ENABLE;
const StringHash HASH_ELEMENT_STENCIL_TEST_ENABLE = 159579189;
extern const char* NAME_ELEMENT_STENCIL_TEST_ENABLE;
const StringHash HASH_ELEMENT_PASS__STENCIL_TEST_ENABLE = 202141525;
extern const char* NAME_ELEMENT_PASS__STENCIL_TEST_ENABLE;
struct profile_GLES__technique__pass__stencil_test_enable__AttributeData
{
    static const profile_GLES__technique__pass__stencil_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_SIZE____FLOAT3 = 81398915;
extern const char* NAME_ELEMENT_SIZE____FLOAT3;
const StringHash HASH_ELEMENT_ELLIPSOID__SIZE = 190753477;
extern const char* NAME_ELEMENT_ELLIPSOID__SIZE;

const StringHash HASH_ELEMENT_PROFILE_GLSL = 99286140;
extern const char* NAME_ELEMENT_PROFILE_GLSL;
struct profile_GLSL__AttributeData
{
    static const profile_GLSL__AttributeData DEFAULT;

    const ParserChar* id;
};

const StringHash HASH_ELEMENT_CODE = 435621;
extern const char* NAME_ELEMENT_CODE;
const StringHash HASH_ELEMENT_PROFILE_GLSL__CODE = 96434469;
extern const char* NAME_ELEMENT_PROFILE_GLSL__CODE;
struct code__AttributeData
{
    static const code__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_INCLUDE = 4864981;
extern const char* NAME_ELEMENT_INCLUDE;
const StringHash HASH_ELEMENT_PROFILE_GLSL__INCLUDE = 25321557;
extern const char* NAME_ELEMENT_PROFILE_GLSL__INCLUDE;
struct include__AttributeData
{
    static const include__AttributeData DEFAULT;

    const ParserChar* sid;
    COLLADABU::URI url;
};

const StringHash HASH_ELEMENT_NEWPARAM____GLSL_NEWPARAM = 103133597;
extern const char* NAME_ELEMENT_NEWPARAM____GLSL_NEWPARAM;
const StringHash HASH_ELEMENT_PROFILE_GLSL__NEWPARAM = 6506701;
extern const char* NAME_ELEMENT_PROFILE_GLSL__NEWPARAM;
struct newparam____glsl_newparam__AttributeData
{
    static const newparam____glsl_newparam__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_BOOL____GLSL_BOOL = 222022220;
extern const char* NAME_ELEMENT_BOOL____GLSL_BOOL;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL = 263396124;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL;

const StringHash HASH_ELEMENT_BOOL2____GLSL_BOOL2 = 6913586;
extern const char* NAME_ELEMENT_BOOL2____GLSL_BOOL2;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL2 = 187805954;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL2;

const StringHash HASH_ELEMENT_BOOL3____GLSL_BOOL3 = 6913843;
extern const char* NAME_ELEMENT_BOOL3____GLSL_BOOL3;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL3 = 187805955;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL3;

const StringHash HASH_ELEMENT_BOOL4____GLSL_BOOL4 = 6913076;
extern const char* NAME_ELEMENT_BOOL4____GLSL_BOOL4;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL4 = 187805956;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL4;

const StringHash HASH_ELEMENT_FLOAT____GLSL_FLOAT = 215833652;
extern const char* NAME_ELEMENT_FLOAT____GLSL_FLOAT;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT = 188080500;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT;

const StringHash HASH_ELEMENT_FLOAT2____GLSL_FLOAT2 = 120212690;
extern const char* NAME_ELEMENT_FLOAT2____GLSL_FLOAT2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2 = 56498114;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2;

const StringHash HASH_ELEMENT_FLOAT3____GLSL_FLOAT3 = 120233171;
extern const char* NAME_ELEMENT_FLOAT3____GLSL_FLOAT3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3 = 56498115;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3;

const StringHash HASH_ELEMENT_FLOAT4____GLSL_FLOAT4 = 119893204;
extern const char* NAME_ELEMENT_FLOAT4____GLSL_FLOAT4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4 = 56498116;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4;

const StringHash HASH_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2 = 255109314;
extern const char* NAME_ELEMENT_FLOAT2X2____GLSL_FLOAT2X2;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X2 = 236440290;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X2;

const StringHash HASH_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3 = 262450131;
extern const char* NAME_ELEMENT_FLOAT3X3____GLSL_FLOAT3X3;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X3 = 236440035;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X3;

const StringHash HASH_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4 = 265595620;
extern const char* NAME_ELEMENT_FLOAT4X4____GLSL_FLOAT4X4;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X4 = 236439780;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X4;

const StringHash HASH_ELEMENT_INT____GLSL_INT = 164961220;
extern const char* NAME_ELEMENT_INT____GLSL_INT;
const StringHash HASH_ELEMENT_NEWPARAM__INT = 83572900;
extern const char* NAME_ELEMENT_NEWPARAM__INT;

const StringHash HASH_ELEMENT_INT2____GLSL_INT2 = 224464578;
extern const char* NAME_ELEMENT_INT2____GLSL_INT2;
const StringHash HASH_ELEMENT_NEWPARAM__INT2 = 263424562;
extern const char* NAME_ELEMENT_NEWPARAM__INT2;

const StringHash HASH_ELEMENT_INT3____GLSL_INT3 = 224464595;
extern const char* NAME_ELEMENT_INT3____GLSL_INT3;
const StringHash HASH_ELEMENT_NEWPARAM__INT3 = 263424563;
extern const char* NAME_ELEMENT_NEWPARAM__INT3;

const StringHash HASH_ELEMENT_INT4____GLSL_INT4 = 224464612;
extern const char* NAME_ELEMENT_INT4____GLSL_INT4;
const StringHash HASH_ELEMENT_NEWPARAM__INT4 = 263424564;
extern const char* NAME_ELEMENT_NEWPARAM__INT4;

const StringHash HASH_ELEMENT_SURFACE____GLSL_SURFACE_TYPE = 104738245;
extern const char* NAME_ELEMENT_SURFACE____GLSL_SURFACE_TYPE;
struct surface____glsl_surface_type__AttributeData
{
    static const surface____glsl_surface_type__AttributeData DEFAULT;

    ENUM__fx_surface_type_enum type;
};

const StringHash HASH_ELEMENT_GLSL_SURFACE_TYPE____GENERATOR = 14595458;
extern const char* NAME_ELEMENT_GLSL_SURFACE_TYPE____GENERATOR;
const StringHash HASH_ELEMENT_GENERATOR = 80275618;
extern const char* NAME_ELEMENT_GENERATOR;
const StringHash HASH_ELEMENT_SURFACE__GENERATOR = 181492914;
extern const char* NAME_ELEMENT_SURFACE__GENERATOR;

const StringHash HASH_ELEMENT_PROFILE_GLSL__NEWPARAM__SURFACE__GENERATOR__NAME = 15584837;
extern const char* NAME_ELEMENT_PROFILE_GLSL__NEWPARAM__SURFACE__GENERATOR__NAME;
const StringHash HASH_ELEMENT_NAME = 477237;
extern const char* NAME_ELEMENT_NAME;
const StringHash HASH_ELEMENT_GENERATOR__NAME = 77508757;
extern const char* NAME_ELEMENT_GENERATOR__NAME;
struct profile_GLSL__newparam__surface__generator__name__AttributeData
{
    static const profile_GLSL__newparam__surface__generator__name__AttributeData DEFAULT;

    const ParserChar* source;
};

const StringHash HASH_ELEMENT_SETPARAM____GLSL_SETPARAM_SIMPLE = 240470837;
extern const char* NAME_ELEMENT_SETPARAM____GLSL_SETPARAM_SIMPLE;
const StringHash HASH_ELEMENT_GENERATOR__SETPARAM = 68294157;
extern const char* NAME_ELEMENT_GENERATOR__SETPARAM;
struct setparam____glsl_setparam_simple__AttributeData
{
    static const setparam____glsl_setparam_simple__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_SAMPLER1D____GL_SAMPLER1D = 223536340;
extern const char* NAME_ELEMENT_SAMPLER1D____GL_SAMPLER1D;
const StringHash HASH_ELEMENT_SETPARAM__SAMPLER1D = 74630612;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLER1D;

const StringHash HASH_ELEMENT_SAMPLER2D____GL_SAMPLER2D = 222487780;
extern const char* NAME_ELEMENT_SAMPLER2D____GL_SAMPLER2D;
const StringHash HASH_ELEMENT_SETPARAM__SAMPLER2D = 74630628;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLER2D;

const StringHash HASH_ELEMENT_SAMPLER3D____GL_SAMPLER3D = 221439220;
extern const char* NAME_ELEMENT_SAMPLER3D____GL_SAMPLER3D;
const StringHash HASH_ELEMENT_SETPARAM__SAMPLER3D = 74630644;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLER3D;

const StringHash HASH_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE = 245609893;
extern const char* NAME_ELEMENT_SAMPLERCUBE____GL_SAMPLERCUBE;
const StringHash HASH_ELEMENT_SETPARAM__SAMPLERCUBE = 46533909;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLERCUBE;

const StringHash HASH_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT = 262518244;
extern const char* NAME_ELEMENT_SAMPLERRECT____GL_SAMPLERRECT;
const StringHash HASH_ELEMENT_SETPARAM__SAMPLERRECT = 46657012;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLERRECT;

const StringHash HASH_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH = 111516376;
extern const char* NAME_ELEMENT_SAMPLERDEPTH____GL_SAMPLERDEPTH;
const StringHash HASH_ELEMENT_SETPARAM__SAMPLERDEPTH = 207676072;
extern const char* NAME_ELEMENT_SETPARAM__SAMPLERDEPTH;

const StringHash HASH_ELEMENT_ENUM____GL_ENUMERATION = 260138062;
extern const char* NAME_ELEMENT_ENUM____GL_ENUMERATION;
const StringHash HASH_ELEMENT_SETPARAM__ENUM = 210365;
extern const char* NAME_ELEMENT_SETPARAM__ENUM;

const StringHash HASH_ELEMENT_ARRAY____GLSL_NEWARRAY_TYPE = 22516773;
extern const char* NAME_ELEMENT_ARRAY____GLSL_NEWARRAY_TYPE;
const StringHash HASH_ELEMENT_ARRAY = 6854793;
extern const char* NAME_ELEMENT_ARRAY;
const StringHash HASH_ELEMENT_NEWPARAM__ARRAY = 187722873;
extern const char* NAME_ELEMENT_NEWPARAM__ARRAY;
const StringHash HASH_ATTRIBUTE_LENGTH = 120344232;
extern const char* NAME_ATTRIBUTE_LENGTH;
struct array____glsl_newarray_type__AttributeData
{
    static const array____glsl_newarray_type__AttributeData DEFAULT;

    uint64 length;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE = 30461381;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE;
struct profile_GLSL__technique__AttributeData
{
    static const profile_GLSL__technique__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_SETPARAM____GLSL_SETPARAM = 42774717;
extern const char* NAME_ELEMENT_SETPARAM____GLSL_SETPARAM;
const StringHash HASH_ATTRIBUTE_PROGRAM = 127264781;
extern const char* NAME_ATTRIBUTE_PROGRAM;
struct setparam____glsl_setparam__AttributeData
{
    static const setparam____glsl_setparam__AttributeData DEFAULT;

    const ParserChar* ref;
    const ParserChar* program;
};

const StringHash HASH_ELEMENT_ARRAY____GLSL_SETARRAY_TYPE = 206607461;
extern const char* NAME_ELEMENT_ARRAY____GLSL_SETARRAY_TYPE;
const StringHash HASH_ELEMENT_SETPARAM__ARRAY = 3250313;
extern const char* NAME_ELEMENT_SETPARAM__ARRAY;
struct array____glsl_setarray_type__AttributeData
{
    static const array____glsl_setarray_type__AttributeData DEFAULT;

    uint64 length;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS = 212247907;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS;
struct profile_GLSL__technique__pass__AttributeData
{
    static const profile_GLSL__technique__pass__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_COLOR_TARGET____FX_COLORTARGET_COMMON = 260850126;
extern const char* NAME_ELEMENT_COLOR_TARGET____FX_COLORTARGET_COMMON;
struct color_target____fx_colortarget_common__AttributeData
{
    static const color_target____fx_colortarget_common__AttributeData DEFAULT;

    uint64 index;
    ENUM__fx_surface_face_enum face;
    uint64 mip;
    uint64 slice;
};

const StringHash HASH_ELEMENT_DEPTH_TARGET____FX_DEPTHTARGET_COMMON = 264162222;
extern const char* NAME_ELEMENT_DEPTH_TARGET____FX_DEPTHTARGET_COMMON;
struct depth_target____fx_depthtarget_common__AttributeData
{
    static const depth_target____fx_depthtarget_common__AttributeData DEFAULT;

    uint64 index;
    ENUM__fx_surface_face_enum face;
    uint64 mip;
    uint64 slice;
};

const StringHash HASH_ELEMENT_STENCIL_TARGET____FX_STENCILTARGET_COMMON = 62244350;
extern const char* NAME_ELEMENT_STENCIL_TARGET____FX_STENCILTARGET_COMMON;
struct stencil_target____fx_stenciltarget_common__AttributeData
{
    static const stencil_target____fx_stenciltarget_common__AttributeData DEFAULT;

    uint64 index;
    ENUM__fx_surface_face_enum face;
    uint64 mip;
    uint64 slice;
};

const StringHash HASH_ELEMENT_COLOR_CLEAR____FX_CLEARCOLOR_COMMON = 64562366;
extern const char* NAME_ELEMENT_COLOR_CLEAR____FX_CLEARCOLOR_COMMON;
struct color_clear____fx_clearcolor_common__AttributeData
{
    static const color_clear____fx_clearcolor_common__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_DEPTH_CLEAR____FX_CLEARDEPTH_COMMON = 99740910;
extern const char* NAME_ELEMENT_DEPTH_CLEAR____FX_CLEARDEPTH_COMMON;
struct depth_clear____fx_cleardepth_common__AttributeData
{
    static const depth_clear____fx_cleardepth_common__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_STENCIL_CLEAR____FX_CLEARSTENCIL_COMMON = 71235438;
extern const char* NAME_ELEMENT_STENCIL_CLEAR____FX_CLEARSTENCIL_COMMON;
struct stencil_clear____fx_clearstencil_common__AttributeData
{
    static const stencil_clear____fx_clearstencil_common__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC = 195444291;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC;

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC__FUNC = 83092995;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC__FUNC;
struct profile_GLSL__technique__pass__alpha_func__func__AttributeData
{
    static const profile_GLSL__technique__pass__alpha_func__func__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC__VALUE = 252684277;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_FUNC__VALUE;
struct profile_GLSL__technique__pass__alpha_func__value__AttributeData
{
    static const profile_GLSL__technique__pass__alpha_func__value__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC = 24571299;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC;

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC__SRC = 178521171;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC__SRC;
struct profile_GLSL__technique__pass__blend_func__src__AttributeData
{
    static const profile_GLSL__technique__pass__blend_func__src__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC__DEST = 172179716;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_FUNC__DEST;
struct profile_GLSL__technique__pass__blend_func__dest__AttributeData
{
    static const profile_GLSL__technique__pass__blend_func__dest__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_BLEND_FUNC_SEPARATE = 146822149;
extern const char* NAME_ELEMENT_BLEND_FUNC_SEPARATE;
const StringHash HASH_ELEMENT_PASS__BLEND_FUNC_SEPARATE = 240051013;
extern const char* NAME_ELEMENT_PASS__BLEND_FUNC_SEPARATE;

const StringHash HASH_ELEMENT_SRC_RGB = 176777378;
extern const char* NAME_ELEMENT_SRC_RGB;
const StringHash HASH_ELEMENT_BLEND_FUNC_SEPARATE__SRC_RGB = 264851890;
extern const char* NAME_ELEMENT_BLEND_FUNC_SEPARATE__SRC_RGB;
struct src_rgb__AttributeData
{
    static const src_rgb__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_DEST_RGB = 212495986;
extern const char* NAME_ELEMENT_DEST_RGB;
const StringHash HASH_ELEMENT_BLEND_FUNC_SEPARATE__DEST_RGB = 145489186;
extern const char* NAME_ELEMENT_BLEND_FUNC_SEPARATE__DEST_RGB;
struct dest_rgb__AttributeData
{
    static const dest_rgb__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_SRC_ALPHA = 156781665;
extern const char* NAME_ELEMENT_SRC_ALPHA;
const StringHash HASH_ELEMENT_BLEND_FUNC_SEPARATE__SRC_ALPHA = 158292257;
extern const char* NAME_ELEMENT_BLEND_FUNC_SEPARATE__SRC_ALPHA;
struct src_alpha__AttributeData
{
    static const src_alpha__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_DEST_ALPHA = 173185601;
extern const char* NAME_ELEMENT_DEST_ALPHA;
const StringHash HASH_ELEMENT_BLEND_FUNC_SEPARATE__DEST_ALPHA = 197381697;
extern const char* NAME_ELEMENT_BLEND_FUNC_SEPARATE__DEST_ALPHA;
struct dest_alpha__AttributeData
{
    static const dest_alpha__AttributeData DEFAULT;

    ENUM__gl_blend_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_BLEND_EQUATION = 175901966;
extern const char* NAME_ELEMENT_BLEND_EQUATION;
const StringHash HASH_ELEMENT_PASS__BLEND_EQUATION = 43350382;
extern const char* NAME_ELEMENT_PASS__BLEND_EQUATION;
struct blend_equation__AttributeData
{
    static const blend_equation__AttributeData DEFAULT;

    ENUM__gl_blend_equation_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_BLEND_EQUATION_SEPARATE = 213461493;
extern const char* NAME_ELEMENT_BLEND_EQUATION_SEPARATE;
const StringHash HASH_ELEMENT_PASS__BLEND_EQUATION_SEPARATE = 201303909;
extern const char* NAME_ELEMENT_PASS__BLEND_EQUATION_SEPARATE;

const StringHash HASH_ELEMENT_BLEND_EQUATION_SEPARATE__RGB = 260110914;
extern const char* NAME_ELEMENT_BLEND_EQUATION_SEPARATE__RGB;
struct rgb__AttributeData
{
    static const rgb__AttributeData DEFAULT;

    ENUM__gl_blend_equation_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_BLEND_EQUATION_SEPARATE__ALPHA = 13019489;
extern const char* NAME_ELEMENT_BLEND_EQUATION_SEPARATE__ALPHA;
struct blend_equation_separate__alpha__AttributeData
{
    static const blend_equation_separate__alpha__AttributeData DEFAULT;

    ENUM__gl_blend_equation_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_COLOR_MATERIAL = 244976620;
extern const char* NAME_ELEMENT_COLOR_MATERIAL;
const StringHash HASH_ELEMENT_PASS__COLOR_MATERIAL = 104052812;
extern const char* NAME_ELEMENT_PASS__COLOR_MATERIAL;

const StringHash HASH_ELEMENT_COLOR_MATERIAL__FACE = 15715221;
extern const char* NAME_ELEMENT_COLOR_MATERIAL__FACE;
struct color_material__face__AttributeData
{
    static const color_material__face__AttributeData DEFAULT;

    ENUM__gl_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_COLOR_MATERIAL__MODE = 15747493;
extern const char* NAME_ELEMENT_COLOR_MATERIAL__MODE;
const StringHash HASH_ELEMENT_MODE = 476581;
extern const char* NAME_ELEMENT_MODE;
struct color_material__mode__AttributeData
{
    static const color_material__mode__AttributeData DEFAULT;

    ENUM__gl_material_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE = 89847653;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE;
struct profile_GLSL__technique__pass__cull_face__AttributeData
{
    static const profile_GLSL__technique__pass__cull_face__AttributeData DEFAULT;

    ENUM__gl_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_FUNC = 255251283;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_FUNC;
struct profile_GLSL__technique__pass__depth_func__AttributeData
{
    static const profile_GLSL__technique__pass__depth_func__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_MODE = 11654869;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_MODE;
struct profile_GLSL__technique__pass__fog_mode__AttributeData
{
    static const profile_GLSL__technique__pass__fog_mode__AttributeData DEFAULT;

    ENUM__gl_fog_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_FOG_COORD_SRC = 198521027;
extern const char* NAME_ELEMENT_FOG_COORD_SRC;
const StringHash HASH_ELEMENT_PASS__FOG_COORD_SRC = 224372483;
extern const char* NAME_ELEMENT_PASS__FOG_COORD_SRC;
struct fog_coord_src__AttributeData
{
    static const fog_coord_src__AttributeData DEFAULT;

    ENUM__gl_fog_coord_src_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FRONT_FACE = 7780821;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FRONT_FACE;
struct profile_GLSL__technique__pass__front_face__AttributeData
{
    static const profile_GLSL__technique__pass__front_face__AttributeData DEFAULT;

    ENUM__gl_front_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_LIGHT_MODEL_COLOR_CONTROL = 90408300;
extern const char* NAME_ELEMENT_LIGHT_MODEL_COLOR_CONTROL;
const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_COLOR_CONTROL = 215299116;
extern const char* NAME_ELEMENT_PASS__LIGHT_MODEL_COLOR_CONTROL;
struct light_model_color_control__AttributeData
{
    static const light_model_color_control__AttributeData DEFAULT;

    ENUM__gl_light_model_color_control_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LOGIC_OP = 12223216;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LOGIC_OP;
struct profile_GLSL__technique__pass__logic_op__AttributeData
{
    static const profile_GLSL__technique__pass__logic_op__AttributeData DEFAULT;

    ENUM__gl_logic_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_POLYGON_MODE = 55843397;
extern const char* NAME_ELEMENT_POLYGON_MODE;
const StringHash HASH_ELEMENT_PASS__POLYGON_MODE = 87864117;
extern const char* NAME_ELEMENT_PASS__POLYGON_MODE;

const StringHash HASH_ELEMENT_POLYGON_MODE__FACE = 169991637;
extern const char* NAME_ELEMENT_POLYGON_MODE__FACE;
struct polygon_mode__face__AttributeData
{
    static const polygon_mode__face__AttributeData DEFAULT;

    ENUM__gl_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_POLYGON_MODE__MODE = 170016741;
extern const char* NAME_ELEMENT_POLYGON_MODE__MODE;
struct polygon_mode__mode__AttributeData
{
    static const polygon_mode__mode__AttributeData DEFAULT;

    ENUM__gl_polygon_mode_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADE_MODEL = 107080524;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADE_MODEL;
struct profile_GLSL__technique__pass__shade_model__AttributeData
{
    static const profile_GLSL__technique__pass__shade_model__AttributeData DEFAULT;

    ENUM__gl_shade_model_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC = 2767667;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC;

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__FUNC = 159375731;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__FUNC;
struct profile_GLSL__technique__pass__stencil_func__func__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_func__func__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__REF = 60279558;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__REF;
struct profile_GLSL__technique__pass__stencil_func__ref__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_func__ref__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__MASK = 159384491;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_FUNC__MASK;
struct profile_GLSL__technique__pass__stencil_func__mask__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_func__mask__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP = 24128384;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP;

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__FAIL = 88468604;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__FAIL;
struct profile_GLSL__technique__pass__stencil_op__fail__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_op__fail__AttributeData DEFAULT;

    ENUM__gl_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__ZFAIL = 74612652;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__ZFAIL;
struct profile_GLSL__technique__pass__stencil_op__zfail__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_op__zfail__AttributeData DEFAULT;

    ENUM__gl_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__ZPASS = 74698995;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_OP__ZPASS;
struct profile_GLSL__technique__pass__stencil_op__zpass__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_op__zpass__AttributeData DEFAULT;

    ENUM__gl_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_FUNC_SEPARATE = 241541829;
extern const char* NAME_ELEMENT_STENCIL_FUNC_SEPARATE;
const StringHash HASH_ELEMENT_PASS__STENCIL_FUNC_SEPARATE = 51380293;
extern const char* NAME_ELEMENT_PASS__STENCIL_FUNC_SEPARATE;

const StringHash HASH_ELEMENT_FRONT = 7181908;
extern const char* NAME_ELEMENT_FRONT;
const StringHash HASH_ELEMENT_STENCIL_FUNC_SEPARATE__FRONT = 50838020;
extern const char* NAME_ELEMENT_STENCIL_FUNC_SEPARATE__FRONT;
struct front__AttributeData
{
    static const front__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_BACK = 427931;
extern const char* NAME_ELEMENT_BACK;
const StringHash HASH_ELEMENT_STENCIL_FUNC_SEPARATE__BACK = 87041371;
extern const char* NAME_ELEMENT_STENCIL_FUNC_SEPARATE__BACK;
struct back__AttributeData
{
    static const back__AttributeData DEFAULT;

    ENUM__gl_func_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_FUNC_SEPARATE__REF = 206779030;
extern const char* NAME_ELEMENT_STENCIL_FUNC_SEPARATE__REF;
struct stencil_func_separate__ref__AttributeData
{
    static const stencil_func_separate__ref__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_FUNC_SEPARATE__MASK = 87136859;
extern const char* NAME_ELEMENT_STENCIL_FUNC_SEPARATE__MASK;
struct stencil_func_separate__mask__AttributeData
{
    static const stencil_func_separate__mask__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_OP_SEPARATE = 23242661;
extern const char* NAME_ELEMENT_STENCIL_OP_SEPARATE;
const StringHash HASH_ELEMENT_PASS__STENCIL_OP_SEPARATE = 49025733;
extern const char* NAME_ELEMENT_PASS__STENCIL_OP_SEPARATE;

const StringHash HASH_ELEMENT_STENCIL_OP_SEPARATE__FACE = 204955701;
extern const char* NAME_ELEMENT_STENCIL_OP_SEPARATE__FACE;
struct stencil_op_separate__face__AttributeData
{
    static const stencil_op_separate__face__AttributeData DEFAULT;

    ENUM__gl_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_OP_SEPARATE__FAIL = 204955740;
extern const char* NAME_ELEMENT_STENCIL_OP_SEPARATE__FAIL;
struct stencil_op_separate__fail__AttributeData
{
    static const stencil_op_separate__fail__AttributeData DEFAULT;

    ENUM__gl_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_OP_SEPARATE__ZFAIL = 56278332;
extern const char* NAME_ELEMENT_STENCIL_OP_SEPARATE__ZFAIL;
struct stencil_op_separate__zfail__AttributeData
{
    static const stencil_op_separate__zfail__AttributeData DEFAULT;

    ENUM__gl_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_OP_SEPARATE__ZPASS = 56300131;
extern const char* NAME_ELEMENT_STENCIL_OP_SEPARATE__ZPASS;
struct stencil_op_separate__zpass__AttributeData
{
    static const stencil_op_separate__zpass__AttributeData DEFAULT;

    ENUM__gl_stencil_op_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_MASK_SEPARATE = 61416245;
extern const char* NAME_ELEMENT_STENCIL_MASK_SEPARATE;
const StringHash HASH_ELEMENT_PASS__STENCIL_MASK_SEPARATE = 222265525;
extern const char* NAME_ELEMENT_PASS__STENCIL_MASK_SEPARATE;

const StringHash HASH_ELEMENT_STENCIL_MASK_SEPARATE__FACE = 184345765;
extern const char* NAME_ELEMENT_STENCIL_MASK_SEPARATE__FACE;
struct stencil_mask_separate__face__AttributeData
{
    static const stencil_mask_separate__face__AttributeData DEFAULT;

    ENUM__gl_face_type value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_STENCIL_MASK_SEPARATE__MASK = 184359851;
extern const char* NAME_ELEMENT_STENCIL_MASK_SEPARATE__MASK;
struct stencil_mask_separate__mask__AttributeData
{
    static const stencil_mask_separate__mask__AttributeData DEFAULT;

    uint8 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_ENABLE = 21939029;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_ENABLE;
struct profile_GLSL__technique__pass__light_enable__AttributeData
{
    static const profile_GLSL__technique__pass__light_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_AMBIENT = 9657716;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_AMBIENT;
struct profile_GLSL__technique__pass__light_ambient__AttributeData
{
    static const profile_GLSL__technique__pass__light_ambient__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_DIFFUSE = 39287685;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_DIFFUSE;
struct profile_GLSL__technique__pass__light_diffuse__AttributeData
{
    static const profile_GLSL__technique__pass__light_diffuse__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPECULAR = 201380002;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPECULAR;
struct profile_GLSL__technique__pass__light_specular__AttributeData
{
    static const profile_GLSL__technique__pass__light_specular__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_POSITION = 205184686;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_POSITION;
struct profile_GLSL__technique__pass__light_position__AttributeData
{
    static const profile_GLSL__technique__pass__light_position__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION = 251708350;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_CONSTANT_ATTENUATION;
struct profile_GLSL__technique__pass__light_constant_attenuation__AttributeData
{
    static const profile_GLSL__technique__pass__light_constant_attenuation__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_LIGHT_LINEAR_ATTENUATION = 14779134;
extern const char* NAME_ELEMENT_LIGHT_LINEAR_ATTENUATION;
const StringHash HASH_ELEMENT_PASS__LIGHT_LINEAR_ATTENUATION = 76097966;
extern const char* NAME_ELEMENT_PASS__LIGHT_LINEAR_ATTENUATION;
struct light_linear_attenuation__AttributeData
{
    static const light_linear_attenuation__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION = 16760894;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_QUADRATIC_ATTENUATION;
struct profile_GLSL__technique__pass__light_quadratic_attenuation__AttributeData
{
    static const profile_GLSL__technique__pass__light_quadratic_attenuation__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF = 42895494;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_CUTOFF;
struct profile_GLSL__technique__pass__light_spot_cutoff__AttributeData
{
    static const profile_GLSL__technique__pass__light_spot_cutoff__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION = 91129726;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_DIRECTION;
struct profile_GLSL__technique__pass__light_spot_direction__AttributeData
{
    static const profile_GLSL__technique__pass__light_spot_direction__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT = 231279284;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_SPOT_EXPONENT;
struct profile_GLSL__technique__pass__light_spot_exponent__AttributeData
{
    static const profile_GLSL__technique__pass__light_spot_exponent__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURE1D = 264041108;
extern const char* NAME_ELEMENT_TEXTURE1D;
const StringHash HASH_ELEMENT_PASS__TEXTURE1D = 86610964;
extern const char* NAME_ELEMENT_PASS__TEXTURE1D;
struct texture1D__AttributeData
{
    static const texture1D__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_VALUE____GL_SAMPLER1D = 36300260;
extern const char* NAME_ELEMENT_VALUE____GL_SAMPLER1D;
const StringHash HASH_ELEMENT_TEXTURE1D__VALUE = 10709557;
extern const char* NAME_ELEMENT_TEXTURE1D__VALUE;

const StringHash HASH_ELEMENT_PARAM____NCNAME = 212141541;
extern const char* NAME_ELEMENT_PARAM____NCNAME;
const StringHash HASH_ELEMENT_TEXTURE1D__PARAM = 11117053;
extern const char* NAME_ELEMENT_TEXTURE1D__PARAM;

const StringHash HASH_ELEMENT_TEXTURE2D = 264041124;
extern const char* NAME_ELEMENT_TEXTURE2D;
const StringHash HASH_ELEMENT_PASS__TEXTURE2D = 86610980;
extern const char* NAME_ELEMENT_PASS__TEXTURE2D;
struct texture2D__AttributeData
{
    static const texture2D__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_VALUE____GL_SAMPLER2D = 36300244;
extern const char* NAME_ELEMENT_VALUE____GL_SAMPLER2D;
const StringHash HASH_ELEMENT_TEXTURE2D__VALUE = 10709301;
extern const char* NAME_ELEMENT_TEXTURE2D__VALUE;

const StringHash HASH_ELEMENT_TEXTURE3D = 264041140;
extern const char* NAME_ELEMENT_TEXTURE3D;
const StringHash HASH_ELEMENT_PASS__TEXTURE3D = 86610996;
extern const char* NAME_ELEMENT_PASS__TEXTURE3D;
struct texture3D__AttributeData
{
    static const texture3D__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_VALUE____GL_SAMPLER3D = 36300228;
extern const char* NAME_ELEMENT_VALUE____GL_SAMPLER3D;
const StringHash HASH_ELEMENT_TEXTURE3D__VALUE = 10709045;
extern const char* NAME_ELEMENT_TEXTURE3D__VALUE;

const StringHash HASH_ELEMENT_TEXTURECUBE = 217269973;
extern const char* NAME_ELEMENT_TEXTURECUBE;
const StringHash HASH_ELEMENT_PASS__TEXTURECUBE = 160812101;
extern const char* NAME_ELEMENT_PASS__TEXTURECUBE;
struct textureCUBE__AttributeData
{
    static const textureCUBE__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_VALUE____GL_SAMPLERCUBE = 166083397;
extern const char* NAME_ELEMENT_VALUE____GL_SAMPLERCUBE;
const StringHash HASH_ELEMENT_TEXTURECUBE__VALUE = 207105733;
extern const char* NAME_ELEMENT_TEXTURECUBE__VALUE;

const StringHash HASH_ELEMENT_TEXTURERECT = 217097780;
extern const char* NAME_ELEMENT_TEXTURERECT;
const StringHash HASH_ELEMENT_PASS__TEXTURERECT = 160836772;
extern const char* NAME_ELEMENT_PASS__TEXTURERECT;
struct textureRECT__AttributeData
{
    static const textureRECT__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_VALUE____GL_SAMPLERRECT = 166189988;
extern const char* NAME_ELEMENT_VALUE____GL_SAMPLERRECT;
const StringHash HASH_ELEMENT_TEXTURERECT__VALUE = 208019669;
extern const char* NAME_ELEMENT_TEXTURERECT__VALUE;

const StringHash HASH_ELEMENT_TEXTUREDEPTH = 255090248;
extern const char* NAME_ELEMENT_TEXTUREDEPTH;
const StringHash HASH_ELEMENT_PASS__TEXTUREDEPTH = 157087512;
extern const char* NAME_ELEMENT_PASS__TEXTUREDEPTH;
struct textureDEPTH__AttributeData
{
    static const textureDEPTH__AttributeData DEFAULT;

    uint64 index;
};

const StringHash HASH_ELEMENT_VALUE____GL_SAMPLERDEPTH = 241403672;
extern const char* NAME_ELEMENT_VALUE____GL_SAMPLERDEPTH;
const StringHash HASH_ELEMENT_TEXTUREDEPTH__VALUE = 136947589;
extern const char* NAME_ELEMENT_TEXTUREDEPTH__VALUE;

const StringHash HASH_ELEMENT_TEXTURE1D_ENABLE = 244011605;
extern const char* NAME_ELEMENT_TEXTURE1D_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTURE1D_ENABLE = 121453301;
extern const char* NAME_ELEMENT_PASS__TEXTURE1D_ENABLE;
struct texture1D_enable__AttributeData
{
    static const texture1D_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURE2D_ENABLE = 244011861;
extern const char* NAME_ELEMENT_TEXTURE2D_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTURE2D_ENABLE = 121453557;
extern const char* NAME_ELEMENT_PASS__TEXTURE2D_ENABLE;
struct texture2D_enable__AttributeData
{
    static const texture2D_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURE3D_ENABLE = 244012117;
extern const char* NAME_ELEMENT_TEXTURE3D_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTURE3D_ENABLE = 121453813;
extern const char* NAME_ELEMENT_PASS__TEXTURE3D_ENABLE;
struct texture3D_enable__AttributeData
{
    static const texture3D_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURECUBE_ENABLE = 177215061;
extern const char* NAME_ELEMENT_TEXTURECUBE_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTURECUBE_ENABLE = 217628005;
extern const char* NAME_ELEMENT_PASS__TEXTURECUBE_ENABLE;
struct textureCUBE_enable__AttributeData
{
    static const textureCUBE_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURERECT_ENABLE = 181279813;
extern const char* NAME_ELEMENT_TEXTURERECT_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTURERECT_ENABLE = 216445749;
extern const char* NAME_ELEMENT_PASS__TEXTURERECT_ENABLE;
struct textureRECT_enable__AttributeData
{
    static const textureRECT_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTUREDEPTH_ENABLE = 117546261;
extern const char* NAME_ELEMENT_TEXTUREDEPTH_ENABLE;
const StringHash HASH_ELEMENT_PASS__TEXTUREDEPTH_ENABLE = 9112181;
extern const char* NAME_ELEMENT_PASS__TEXTUREDEPTH_ENABLE;
struct textureDEPTH_enable__AttributeData
{
    static const textureDEPTH_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURE_ENV_COLOR = 145348738;
extern const char* NAME_ELEMENT_TEXTURE_ENV_COLOR;
const StringHash HASH_ELEMENT_PASS__TEXTURE_ENV_COLOR = 63921682;
extern const char* NAME_ELEMENT_PASS__TEXTURE_ENV_COLOR;
struct texture_env_color__AttributeData
{
    static const texture_env_color__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_TEXTURE_ENV_MODE = 244006133;
extern const char* NAME_ELEMENT_TEXTURE_ENV_MODE;
const StringHash HASH_ELEMENT_PASS__TEXTURE_ENV_MODE = 121459797;
extern const char* NAME_ELEMENT_PASS__TEXTURE_ENV_MODE;
struct texture_env_mode__AttributeData
{
    static const texture_env_mode__AttributeData DEFAULT;

    const ParserChar* value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE = 26636325;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE;
struct profile_GLSL__technique__pass__clip_plane__AttributeData
{
    static const profile_GLSL__technique__pass__clip_plane__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE_ENABLE = 216234981;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLIP_PLANE_ENABLE;
struct profile_GLSL__technique__pass__clip_plane_enable__AttributeData
{
    static const profile_GLSL__technique__pass__clip_plane_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
    uint64 index;
};

const StringHash HASH_ELEMENT_BLEND_COLOR = 171020066;
extern const char* NAME_ELEMENT_BLEND_COLOR;
const StringHash HASH_ELEMENT_PASS__BLEND_COLOR = 225968562;
extern const char* NAME_ELEMENT_PASS__BLEND_COLOR;
struct blend_color__AttributeData
{
    static const blend_color__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_COLOR = 158220466;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_COLOR;
struct profile_GLSL__technique__pass__clear_color__AttributeData
{
    static const profile_GLSL__technique__pass__clear_color__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_STENCIL = 249008300;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_STENCIL;
struct profile_GLSL__technique__pass__clear_stencil__AttributeData
{
    static const profile_GLSL__technique__pass__clear_stencil__AttributeData DEFAULT;

    sint64 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_DEPTH = 158251640;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CLEAR_DEPTH;
struct profile_GLSL__technique__pass__clear_depth__AttributeData
{
    static const profile_GLSL__technique__pass__clear_depth__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MASK = 60258763;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MASK;
struct profile_GLSL__technique__pass__color_mask__AttributeData
{
    static const profile_GLSL__technique__pass__color_mask__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<bool> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_DEPTH_BOUNDS = 54189651;
extern const char* NAME_ELEMENT_DEPTH_BOUNDS;
const StringHash HASH_ELEMENT_PASS__DEPTH_BOUNDS = 122844963;
extern const char* NAME_ELEMENT_PASS__DEPTH_BOUNDS;
struct depth_bounds__AttributeData
{
    static const depth_bounds__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_MASK = 255275403;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_MASK;
struct profile_GLSL__technique__pass__depth_mask__AttributeData
{
    static const profile_GLSL__technique__pass__depth_mask__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_RANGE = 56161573;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_RANGE;
struct profile_GLSL__technique__pass__depth_range__AttributeData
{
    static const profile_GLSL__technique__pass__depth_range__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_DENSITY = 93498297;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_DENSITY;
struct profile_GLSL__technique__pass__fog_density__AttributeData
{
    static const profile_GLSL__technique__pass__fog_density__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_START = 188063636;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_START;
struct profile_GLSL__technique__pass__fog_start__AttributeData
{
    static const profile_GLSL__technique__pass__fog_start__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_END = 118162804;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_END;
struct profile_GLSL__technique__pass__fog_end__AttributeData
{
    static const profile_GLSL__technique__pass__fog_end__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_COLOR = 185038434;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_COLOR;
struct profile_GLSL__technique__pass__fog_color__AttributeData
{
    static const profile_GLSL__technique__pass__fog_color__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT = 214555940;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_AMBIENT;
struct profile_GLSL__technique__pass__light_model_ambient__AttributeData
{
    static const profile_GLSL__technique__pass__light_model_ambient__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHTING_ENABLE = 237090133;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHTING_ENABLE;
struct profile_GLSL__technique__pass__lighting_enable__AttributeData
{
    static const profile_GLSL__technique__pass__lighting_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_LINE_STIPPLE = 228605509;
extern const char* NAME_ELEMENT_LINE_STIPPLE;
const StringHash HASH_ELEMENT_PASS__LINE_STIPPLE = 167285525;
extern const char* NAME_ELEMENT_PASS__LINE_STIPPLE;
struct line_stipple__AttributeData
{
    static const line_stipple__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<sint64> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_WIDTH = 10055832;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_WIDTH;
struct profile_GLSL__technique__pass__line_width__AttributeData
{
    static const profile_GLSL__technique__pass__line_width__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_AMBIENT = 256051140;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_AMBIENT;
struct profile_GLSL__technique__pass__material_ambient__AttributeData
{
    static const profile_GLSL__technique__pass__material_ambient__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_DIFFUSE = 59187461;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_DIFFUSE;
struct profile_GLSL__technique__pass__material_diffuse__AttributeData
{
    static const profile_GLSL__technique__pass__material_diffuse__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_EMISSION = 95766382;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_EMISSION;
struct profile_GLSL__technique__pass__material_emission__AttributeData
{
    static const profile_GLSL__technique__pass__material_emission__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SHININESS = 95677491;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SHININESS;
struct profile_GLSL__technique__pass__material_shininess__AttributeData
{
    static const profile_GLSL__technique__pass__material_shininess__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SPECULAR = 17135794;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MATERIAL_SPECULAR;
struct profile_GLSL__technique__pass__material_specular__AttributeData
{
    static const profile_GLSL__technique__pass__material_specular__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MODEL_VIEW_MATRIX = 186534216;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MODEL_VIEW_MATRIX;
struct profile_GLSL__technique__pass__model_view_matrix__AttributeData
{
    static const profile_GLSL__technique__pass__model_view_matrix__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION = 250217966;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_DISTANCE_ATTENUATION;
struct profile_GLSL__technique__pass__point_distance_attenuation__AttributeData
{
    static const profile_GLSL__technique__pass__point_distance_attenuation__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE = 209367477;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_FADE_THRESHOLD_SIZE;
struct profile_GLSL__technique__pass__point_fade_threshold_size__AttributeData
{
    static const profile_GLSL__technique__pass__point_fade_threshold_size__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE = 7754149;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE;
struct profile_GLSL__technique__pass__point_size__AttributeData
{
    static const profile_GLSL__technique__pass__point_size__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MIN = 27997614;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MIN;
struct profile_GLSL__technique__pass__point_size_min__AttributeData
{
    static const profile_GLSL__technique__pass__point_size_min__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MAX = 27997656;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SIZE_MAX;
struct profile_GLSL__technique__pass__point_size_max__AttributeData
{
    static const profile_GLSL__technique__pass__point_size_max__AttributeData DEFAULT;

    float value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET = 84340532;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET;
struct profile_GLSL__technique__pass__polygon_offset__AttributeData
{
    static const profile_GLSL__technique__pass__polygon_offset__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__PROJECTION_MATRIX = 44014456;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__PROJECTION_MATRIX;
struct profile_GLSL__technique__pass__projection_matrix__AttributeData
{
    static const profile_GLSL__technique__pass__projection_matrix__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<float> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR = 64419682;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR;
struct profile_GLSL__technique__pass__scissor__AttributeData
{
    static const profile_GLSL__technique__pass__scissor__AttributeData DEFAULT;

    GeneratedSaxParser::XSList<sint64> value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_MASK = 2873835;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_MASK;
struct profile_GLSL__technique__pass__stencil_mask__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_mask__AttributeData DEFAULT;

    sint64 value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_TEST_ENABLE = 267440917;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__ALPHA_TEST_ENABLE;
struct profile_GLSL__technique__pass__alpha_test_enable__AttributeData
{
    static const profile_GLSL__technique__pass__alpha_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_AUTO_NORMAL_ENABLE = 107084965;
extern const char* NAME_ELEMENT_AUTO_NORMAL_ENABLE;
const StringHash HASH_ELEMENT_PASS__AUTO_NORMAL_ENABLE = 38359861;
extern const char* NAME_ELEMENT_PASS__AUTO_NORMAL_ENABLE;
struct auto_normal_enable__AttributeData
{
    static const auto_normal_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_ENABLE = 110336597;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__BLEND_ENABLE;
struct profile_GLSL__technique__pass__blend_enable__AttributeData
{
    static const profile_GLSL__technique__pass__blend_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE = 226904581;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_LOGIC_OP_ENABLE;
struct profile_GLSL__technique__pass__color_logic_op_enable__AttributeData
{
    static const profile_GLSL__technique__pass__color_logic_op_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE = 173406901;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__COLOR_MATERIAL_ENABLE;
struct profile_GLSL__technique__pass__color_material_enable__AttributeData
{
    static const profile_GLSL__technique__pass__color_material_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE_ENABLE = 2822181;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__CULL_FACE_ENABLE;
struct profile_GLSL__technique__pass__cull_face_enable__AttributeData
{
    static const profile_GLSL__technique__pass__cull_face_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_DEPTH_BOUNDS_ENABLE = 103390949;
extern const char* NAME_ELEMENT_DEPTH_BOUNDS_ENABLE;
const StringHash HASH_ELEMENT_PASS__DEPTH_BOUNDS_ENABLE = 10685477;
extern const char* NAME_ELEMENT_PASS__DEPTH_BOUNDS_ENABLE;
struct depth_bounds_enable__AttributeData
{
    static const depth_bounds_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_DEPTH_CLAMP_ENABLE = 118122469;
extern const char* NAME_ELEMENT_DEPTH_CLAMP_ENABLE;
const StringHash HASH_ELEMENT_PASS__DEPTH_CLAMP_ENABLE = 48419061;
extern const char* NAME_ELEMENT_PASS__DEPTH_CLAMP_ENABLE;
struct depth_clamp_enable__AttributeData
{
    static const depth_clamp_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_TEST_ENABLE = 117318741;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DEPTH_TEST_ENABLE;
struct profile_GLSL__technique__pass__depth_test_enable__AttributeData
{
    static const profile_GLSL__technique__pass__depth_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DITHER_ENABLE = 83414133;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__DITHER_ENABLE;
struct profile_GLSL__technique__pass__dither_enable__AttributeData
{
    static const profile_GLSL__technique__pass__dither_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_ENABLE = 5704085;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__FOG_ENABLE;
struct profile_GLSL__technique__pass__fog_enable__AttributeData
{
    static const profile_GLSL__technique__pass__fog_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_LIGHT_MODEL_LOCAL_VIEWER_ENABLE = 147233621;
extern const char* NAME_ELEMENT_LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_LOCAL_VIEWER_ENABLE = 38537749;
extern const char* NAME_ELEMENT_PASS__LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
struct light_model_local_viewer_enable__AttributeData
{
    static const light_model_local_viewer_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE = 67815045;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
struct profile_GLSL__technique__pass__light_model_two_side_enable__AttributeData
{
    static const profile_GLSL__technique__pass__light_model_two_side_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE = 193667957;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__LINE_SMOOTH_ENABLE;
struct profile_GLSL__technique__pass__line_smooth_enable__AttributeData
{
    static const profile_GLSL__technique__pass__line_smooth_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_LINE_STIPPLE_ENABLE = 264740261;
extern const char* NAME_ELEMENT_LINE_STIPPLE_ENABLE;
const StringHash HASH_ELEMENT_PASS__LINE_STIPPLE_ENABLE = 172837477;
extern const char* NAME_ELEMENT_PASS__LINE_STIPPLE_ENABLE;
struct line_stipple_enable__AttributeData
{
    static const line_stipple_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_LOGIC_OP_ENABLE = 140332597;
extern const char* NAME_ELEMENT_LOGIC_OP_ENABLE;
const StringHash HASH_ELEMENT_PASS__LOGIC_OP_ENABLE = 48893109;
extern const char* NAME_ELEMENT_PASS__LOGIC_OP_ENABLE;
struct logic_op_enable__AttributeData
{
    static const logic_op_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MULTISAMPLE_ENABLE = 137325381;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__MULTISAMPLE_ENABLE;
struct profile_GLSL__technique__pass__multisample_enable__AttributeData
{
    static const profile_GLSL__technique__pass__multisample_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__NORMALIZE_ENABLE = 54295621;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__NORMALIZE_ENABLE;
struct profile_GLSL__technique__pass__normalize_enable__AttributeData
{
    static const profile_GLSL__technique__pass__normalize_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE = 15996645;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POINT_SMOOTH_ENABLE;
struct profile_GLSL__technique__pass__point_smooth_enable__AttributeData
{
    static const profile_GLSL__technique__pass__point_smooth_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE = 150886165;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__POLYGON_OFFSET_FILL_ENABLE;
struct profile_GLSL__technique__pass__polygon_offset_fill_enable__AttributeData
{
    static const profile_GLSL__technique__pass__polygon_offset_fill_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_POLYGON_OFFSET_LINE_ENABLE = 201697125;
extern const char* NAME_ELEMENT_POLYGON_OFFSET_LINE_ENABLE;
const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET_LINE_ENABLE = 53260613;
extern const char* NAME_ELEMENT_PASS__POLYGON_OFFSET_LINE_ENABLE;
struct polygon_offset_line_enable__AttributeData
{
    static const polygon_offset_line_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_POLYGON_OFFSET_POINT_ENABLE = 98702757;
extern const char* NAME_ELEMENT_POLYGON_OFFSET_POINT_ENABLE;
const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET_POINT_ENABLE = 259339301;
extern const char* NAME_ELEMENT_PASS__POLYGON_OFFSET_POINT_ENABLE;
struct polygon_offset_point_enable__AttributeData
{
    static const polygon_offset_point_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_POLYGON_SMOOTH_ENABLE = 242755781;
extern const char* NAME_ELEMENT_POLYGON_SMOOTH_ENABLE;
const StringHash HASH_ELEMENT_PASS__POLYGON_SMOOTH_ENABLE = 82395717;
extern const char* NAME_ELEMENT_PASS__POLYGON_SMOOTH_ENABLE;
struct polygon_smooth_enable__AttributeData
{
    static const polygon_smooth_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_POLYGON_STIPPLE_ENABLE = 56638309;
extern const char* NAME_ELEMENT_POLYGON_STIPPLE_ENABLE;
const StringHash HASH_ELEMENT_PASS__POLYGON_STIPPLE_ENABLE = 137761669;
extern const char* NAME_ELEMENT_PASS__POLYGON_STIPPLE_ENABLE;
struct polygon_stipple_enable__AttributeData
{
    static const polygon_stipple_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE = 153512181;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__RESCALE_NORMAL_ENABLE;
struct profile_GLSL__technique__pass__rescale_normal_enable__AttributeData
{
    static const profile_GLSL__technique__pass__rescale_normal_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 143294229;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
struct profile_GLSL__technique__pass__sample_alpha_to_coverage_enable__AttributeData
{
    static const profile_GLSL__technique__pass__sample_alpha_to_coverage_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE = 99353573;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
struct profile_GLSL__technique__pass__sample_alpha_to_one_enable__AttributeData
{
    static const profile_GLSL__technique__pass__sample_alpha_to_one_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE = 230125525;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SAMPLE_COVERAGE_ENABLE;
struct profile_GLSL__technique__pass__sample_coverage_enable__AttributeData
{
    static const profile_GLSL__technique__pass__sample_coverage_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE = 1591077;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SCISSOR_TEST_ENABLE;
struct profile_GLSL__technique__pass__scissor_test_enable__AttributeData
{
    static const profile_GLSL__technique__pass__scissor_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_TEST_ENABLE = 120628869;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__STENCIL_TEST_ENABLE;
struct profile_GLSL__technique__pass__stencil_test_enable__AttributeData
{
    static const profile_GLSL__technique__pass__stencil_test_enable__AttributeData DEFAULT;

    bool value;
    const ParserChar* param;
};

const StringHash HASH_ELEMENT_GL_HOOK_ABSTRACT = 114258052;
extern const char* NAME_ELEMENT_GL_HOOK_ABSTRACT;
const StringHash HASH_ELEMENT_PASS__GL_HOOK_ABSTRACT = 28530724;
extern const char* NAME_ELEMENT_PASS__GL_HOOK_ABSTRACT;

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER = 3874610;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER;
const StringHash HASH_ELEMENT_SHADER = 127826626;
extern const char* NAME_ELEMENT_SHADER;
const StringHash HASH_ELEMENT_PASS__SHADER = 32953234;
extern const char* NAME_ELEMENT_PASS__SHADER;
const StringHash HASH_ATTRIBUTE_STAGE = 8038357;
extern const char* NAME_ATTRIBUTE_STAGE;
struct profile_GLSL__technique__pass__shader__AttributeData
{
    static const profile_GLSL__technique__pass__shader__AttributeData DEFAULT;

    ENUM__glsl_pipeline_stage stage;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__COMPILER_TARGET = 20989972;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__COMPILER_TARGET;
const StringHash HASH_ELEMENT_COMPILER_TARGET = 47762404;
extern const char* NAME_ELEMENT_COMPILER_TARGET;
const StringHash HASH_ELEMENT_SHADER__COMPILER_TARGET = 249192772;
extern const char* NAME_ELEMENT_SHADER__COMPILER_TARGET;

const StringHash HASH_ELEMENT_COMPILER_OPTIONS = 25077875;
extern const char* NAME_ELEMENT_COMPILER_OPTIONS;
const StringHash HASH_ELEMENT_SHADER__COMPILER_OPTIONS = 22302387;
extern const char* NAME_ELEMENT_SHADER__COMPILER_OPTIONS;

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__NAME = 143612165;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__NAME;
const StringHash HASH_ELEMENT_SHADER__NAME = 32259829;
extern const char* NAME_ELEMENT_SHADER__NAME;
struct profile_GLSL__technique__pass__shader__name__AttributeData
{
    static const profile_GLSL__technique__pass__shader__name__AttributeData DEFAULT;

    const ParserChar* source;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__BIND = 143561076;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__BIND;
const StringHash HASH_ELEMENT_SHADER__BIND = 32241284;
extern const char* NAME_ELEMENT_SHADER__BIND;
struct profile_GLSL__technique__pass__shader__bind__AttributeData
{
    static const profile_GLSL__technique__pass__shader__bind__AttributeData DEFAULT;

    const ParserChar* symbol;
};

const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__BIND__PARAM = 227516253;
extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE__PASS__SHADER__BIND__PARAM;
const StringHash HASH_ELEMENT_BIND__PARAM = 84905181;
extern const char* NAME_ELEMENT_BIND__PARAM;
struct profile_GLSL__technique__pass__shader__bind__param__AttributeData
{
    static const profile_GLSL__technique__pass__shader__bind__param__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_PROFILE_CG = 218491431;
extern const char* NAME_ELEMENT_PROFILE_CG;
struct profile_CG__AttributeData
{
    static const profile_CG__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* platform;
};

const StringHash HASH_ELEMENT_NEWPARAM____CG_NEWPARAM = 21743373;
extern const char* NAME_ELEMENT_NEWPARAM____CG_NEWPARAM;
const StringHash HASH_ELEMENT_PROFILE_CG__NEWPARAM = 113564125;
extern const char* NAME_ELEMENT_PROFILE_CG__NEWPARAM;
struct newparam____cg_newparam__AttributeData
{
    static const newparam____cg_newparam__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_BOOL____CG_BOOL = 267439212;
extern const char* NAME_ELEMENT_BOOL____CG_BOOL;

const StringHash HASH_ELEMENT_BOOL1 = 6907377;
extern const char* NAME_ELEMENT_BOOL1;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL1 = 187805953;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL1;

const StringHash HASH_ELEMENT_BOOL2____CG_BOOL2 = 90666386;
extern const char* NAME_ELEMENT_BOOL2____CG_BOOL2;

const StringHash HASH_ELEMENT_BOOL3____CG_BOOL3 = 107443603;
extern const char* NAME_ELEMENT_BOOL3____CG_BOOL3;

const StringHash HASH_ELEMENT_BOOL4____CG_BOOL4 = 124220820;
extern const char* NAME_ELEMENT_BOOL4____CG_BOOL4;

const StringHash HASH_ELEMENT_BOOL1X1 = 157677777;
extern const char* NAME_ELEMENT_BOOL1X1;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X1 = 28377985;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X1;

const StringHash HASH_ELEMENT_BOOL1X2 = 157677778;
extern const char* NAME_ELEMENT_BOOL1X2;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X2 = 28377986;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X2;

const StringHash HASH_ELEMENT_BOOL1X3 = 157677779;
extern const char* NAME_ELEMENT_BOOL1X3;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X3 = 28377987;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X3;

const StringHash HASH_ELEMENT_BOOL1X4 = 157677780;
extern const char* NAME_ELEMENT_BOOL1X4;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X4 = 28377988;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X4;

const StringHash HASH_ELEMENT_BOOL2X1 = 157678033;
extern const char* NAME_ELEMENT_BOOL2X1;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X1 = 28377729;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X1;

const StringHash HASH_ELEMENT_BOOL2X2 = 157678034;
extern const char* NAME_ELEMENT_BOOL2X2;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X2 = 28377730;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X2;

const StringHash HASH_ELEMENT_BOOL2X3 = 157678035;
extern const char* NAME_ELEMENT_BOOL2X3;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X3 = 28377731;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X3;

const StringHash HASH_ELEMENT_BOOL2X4 = 157678036;
extern const char* NAME_ELEMENT_BOOL2X4;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X4 = 28377732;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X4;

const StringHash HASH_ELEMENT_BOOL3X1 = 157678289;
extern const char* NAME_ELEMENT_BOOL3X1;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X1 = 28377473;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X1;

const StringHash HASH_ELEMENT_BOOL3X2 = 157678290;
extern const char* NAME_ELEMENT_BOOL3X2;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X2 = 28377474;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X2;

const StringHash HASH_ELEMENT_BOOL3X3 = 157678291;
extern const char* NAME_ELEMENT_BOOL3X3;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X3 = 28377475;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X3;

const StringHash HASH_ELEMENT_BOOL3X4 = 157678292;
extern const char* NAME_ELEMENT_BOOL3X4;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X4 = 28377476;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X4;

const StringHash HASH_ELEMENT_BOOL4X1 = 157678545;
extern const char* NAME_ELEMENT_BOOL4X1;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X1 = 28377217;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X1;

const StringHash HASH_ELEMENT_BOOL4X2 = 157678546;
extern const char* NAME_ELEMENT_BOOL4X2;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X2 = 28377218;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X2;

const StringHash HASH_ELEMENT_BOOL4X3 = 157678547;
extern const char* NAME_ELEMENT_BOOL4X3;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X3 = 28377219;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X3;

const StringHash HASH_ELEMENT_BOOL4X4 = 157678548;
extern const char* NAME_ELEMENT_BOOL4X4;
const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X4 = 28377220;
extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X4;

const StringHash HASH_ELEMENT_FLOAT____CG_FLOAT = 124237204;
extern const char* NAME_ELEMENT_FLOAT____CG_FLOAT;

const StringHash HASH_ELEMENT_FLOAT1 = 114514033;
extern const char* NAME_ELEMENT_FLOAT1;
const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1 = 56498113;
extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1;

const StringHash HASH_ELEMENT_FLOAT2____CG_FLOAT2 = 257001090;
extern const char* NAME_ELEMENT_FLOAT2____CG_FLOAT2;

const StringHash HASH_ELEMENT_FLOAT3____CG_FLOAT3 = 257001011;
extern const char* NAME_ELEMENT_FLOAT3____CG_FLOAT3;

const StringHash HASH_ELEMENT_FLOAT4____CG_FLOAT4 = 257001892;
extern const char* NAME_ELEMENT_FLOAT4____CG_FLOAT4;

const StringHash HASH_ELEMENT_FLOAT1X1____CG_FLOAT1X1 = 132632465;
extern const char* NAME_ELEMENT_FLOAT1X1____CG_FLOAT1X1;

const StringHash HASH_ELEMENT_FLOAT1X2____CG_FLOAT1X2 = 132636562;
extern const char* NAME_ELEMENT_FLOAT1X2____CG_FLOAT1X2;

const StringHash HASH_ELEMENT_FLOAT1X3____CG_FLOAT1X3 = 132607891;
extern const char* NAME_ELEMENT_FLOAT1X3____CG_FLOAT1X3;

const StringHash HASH_ELEMENT_FLOAT1X4____CG_FLOAT1X4 = 132644756;
extern const char* NAME_ELEMENT_FLOAT1X4____CG_FLOAT1X4;

const StringHash HASH_ELEMENT_FLOAT2X1____CG_FLOAT2X1 = 133680785;
extern const char* NAME_ELEMENT_FLOAT2X1____CG_FLOAT2X1;

const StringHash HASH_ELEMENT_FLOAT2X2____CG_FLOAT2X2 = 133684882;
extern const char* NAME_ELEMENT_FLOAT2X2____CG_FLOAT2X2;

const StringHash HASH_ELEMENT_FLOAT2X3____CG_FLOAT2X3 = 133656211;
extern const char* NAME_ELEMENT_FLOAT2X3____CG_FLOAT2X3;

const StringHash HASH_ELEMENT_FLOAT2X4____CG_FLOAT2X4 = 133693076;
extern const char* NAME_ELEMENT_FLOAT2X4____CG_FLOAT2X4;

const StringHash HASH_ELEMENT_FLOAT3X1____CG_FLOAT3X1 = 130534801;
extern const char* NAME_ELEMENT_FLOAT3X1____CG_FLOAT3X1;

const StringHash HASH_ELEMENT_FLOAT3X2____CG_FLOAT3X2 = 130538898;
extern const char* NAME_ELEMENT_FLOAT3X2____CG_FLOAT3X2;

const StringHash HASH_ELEMENT_FLOAT3X3____CG_FLOAT3X3 = 130510227;
extern const char* NAME_ELEMENT_FLOAT3X3____CG_FLOAT3X3;

const StringHash HASH_ELEMENT_FLOAT3X4____CG_FLOAT3X4 = 130547092;
extern const char* NAME_ELEMENT_FLOAT3X4____CG_FLOAT3X4;

const StringHash HASH_ELEMENT_FLOAT4X1____CG_FLOAT4X1 = 131583121;
extern const char* NAME_ELEMENT_FLOAT4X1____CG_FLOAT4X1;

const StringHash HASH_ELEMENT_FLOAT4X2____CG_FLOAT4X2 = 131587218;
extern const char* NAME_ELEMENT_FLOAT4X2____CG_FLOAT4X2;

const StringHash HASH_ELEMENT_FLOAT4X3____CG_FLOAT4X3 = 131558547;
extern const char* NAME_ELEMENT_FLOAT4X3____CG_FLOAT4X3;

const StringHash HASH_ELEMENT_FLOAT4X4____CG_FLOAT4X4 = 131595412;
extern const char* NAME_ELEMENT_FLOAT4X4____CG_FLOAT4X4;

const StringHash HASH_ELEMENT_INT____CG_INT = 96930580;
extern const char* NAME_ELEMENT_INT____CG_INT;

const StringHash HASH_ELEMENT_INT1 = 460145;
extern const char* NAME_ELEMENT_INT1;
const StringHash HASH_ELEMENT_NEWPARAM__INT1 = 263424561;
extern const char* NAME_ELEMENT_NEWPARAM__INT1;

const StringHash HASH_ELEMENT_INT2____CG_INT2 = 240173170;
extern const char* NAME_ELEMENT_INT2____CG_INT2;

const StringHash HASH_ELEMENT_INT3____CG_INT3 = 241221747;
extern const char* NAME_ELEMENT_INT3____CG_INT3;

const StringHash HASH_ELEMENT_INT4____CG_INT4 = 242270324;
extern const char* NAME_ELEMENT_INT4____CG_INT4;

const StringHash HASH_ELEMENT_INT1X1 = 117799089;
extern const char* NAME_ELEMENT_INT1X1;
const StringHash HASH_ELEMENT_NEWPARAM__INT1X1 = 59389697;
extern const char* NAME_ELEMENT_NEWPARAM__INT1X1;

const StringHash HASH_ELEMENT_INT1X2 = 117799090;
extern const char* NAME_ELEMENT_INT1X2;
const StringHash HASH_ELEMENT_NEWPARAM__INT1X2 = 59389698;
extern const char* NAME_ELEMENT_NEWPARAM__INT1X2;

const StringHash HASH_ELEMENT_INT1X3 = 117799091;
extern const char* NAME_ELEMENT_INT1X3;
const StringHash HASH_ELEMENT_NEWPARAM__INT1X3 = 59389699;
extern const char* NAME_ELEMENT_NEWPARAM__INT1X3;

const StringHash HASH_ELEMENT_INT1X4 = 117799092;
extern const char* NAME_ELEMENT_INT1X4;
const StringHash HASH_ELEMENT_NEWPARAM__INT1X4 = 59389700;
extern const char* NAME_ELEMENT_NEWPARAM__INT1X4;

const StringHash HASH_ELEMENT_INT2X1 = 117799345;
extern const char* NAME_ELEMENT_INT2X1;
const StringHash HASH_ELEMENT_NEWPARAM__INT2X1 = 59389441;
extern const char* NAME_ELEMENT_NEWPARAM__INT2X1;

const StringHash HASH_ELEMENT_INT2X2 = 117799346;
extern const char* NAME_ELEMENT_INT2X2;
const StringHash HASH_ELEMENT_NEWPARAM__INT2X2 = 59389442;
extern const char* NAME_ELEMENT_NEWPARAM__INT2X2;

const StringHash HASH_ELEMENT_INT2X3 = 117799347;
extern const char* NAME_ELEMENT_INT2X3;
const StringHash HASH_ELEMENT_NEWPARAM__INT2X3 = 59389443;
extern const char* NAME_ELEMENT_NEWPARAM__INT2X3;

const StringHash HASH_ELEMENT_INT2X4 = 117799348;
extern const char* NAME_ELEMENT_INT2X4;
const StringHash HASH_ELEMENT_NEWPARAM__INT2X4 = 59389444;
extern const char* NAME_ELEMENT_NEWPARAM__INT2X4;

const StringHash HASH_ELEMENT_INT3X1 = 117799601;
extern const char* NAME_ELEMENT_INT3X1;
const StringHash HASH_ELEMENT_NEWPARAM__INT3X1 = 59389185;
extern const char* NAME_ELEMENT_NEWPARAM__INT3X1;

const StringHash HASH_ELEMENT_INT3X2 = 117799602;
extern const char* NAME_ELEMENT_INT3X2;
const StringHash HASH_ELEMENT_NEWPARAM__INT3X2 = 59389186;
extern const char* NAME_ELEMENT_NEWPARAM__INT3X2;

const StringHash HASH_ELEMENT_INT3X3 = 117799603;
extern const char* NAME_ELEMENT_INT3X3;
const StringHash HASH_ELEMENT_NEWPARAM__INT3X3 = 59389187;
extern const char* NAME_ELEMENT_NEWPARAM__INT3X3;

const StringHash HASH_ELEMENT_INT3X4 = 117799604;
extern const char* NAME_ELEMENT_INT3X4;
const StringHash HASH_ELEMENT_NEWPARAM__INT3X4 = 59389188;
extern const char* NAME_ELEMENT_NEWPARAM__INT3X4;

const StringHash HASH_ELEMENT_INT4X1 = 117799857;
extern const char* NAME_ELEMENT_INT4X1;
const StringHash HASH_ELEMENT_NEWPARAM__INT4X1 = 59388929;
extern const char* NAME_ELEMENT_NEWPARAM__INT4X1;

const StringHash HASH_ELEMENT_INT4X2 = 117799858;
extern const char* NAME_ELEMENT_INT4X2;
const StringHash HASH_ELEMENT_NEWPARAM__INT4X2 = 59388930;
extern const char* NAME_ELEMENT_NEWPARAM__INT4X2;

const StringHash HASH_ELEMENT_INT4X3 = 117799859;
extern const char* NAME_ELEMENT_INT4X3;
const StringHash HASH_ELEMENT_NEWPARAM__INT4X3 = 59388931;
extern const char* NAME_ELEMENT_NEWPARAM__INT4X3;

const StringHash HASH_ELEMENT_INT4X4 = 117799860;
extern const char* NAME_ELEMENT_INT4X4;
const StringHash HASH_ELEMENT_NEWPARAM__INT4X4 = 59388932;
extern const char* NAME_ELEMENT_NEWPARAM__INT4X4;

const StringHash HASH_ELEMENT_HALF = 452646;
extern const char* NAME_ELEMENT_HALF;
const StringHash HASH_ELEMENT_NEWPARAM__HALF = 263416166;
extern const char* NAME_ELEMENT_NEWPARAM__HALF;

const StringHash HASH_ELEMENT_HALF1 = 7242385;
extern const char* NAME_ELEMENT_HALF1;
const StringHash HASH_ELEMENT_NEWPARAM__HALF1 = 188126817;
extern const char* NAME_ELEMENT_NEWPARAM__HALF1;

const StringHash HASH_ELEMENT_HALF2 = 7242386;
extern const char* NAME_ELEMENT_HALF2;
const StringHash HASH_ELEMENT_NEWPARAM__HALF2 = 188126818;
extern const char* NAME_ELEMENT_NEWPARAM__HALF2;

const StringHash HASH_ELEMENT_HALF3 = 7242387;
extern const char* NAME_ELEMENT_HALF3;
const StringHash HASH_ELEMENT_NEWPARAM__HALF3 = 188126819;
extern const char* NAME_ELEMENT_NEWPARAM__HALF3;

const StringHash HASH_ELEMENT_HALF4 = 7242388;
extern const char* NAME_ELEMENT_HALF4;
const StringHash HASH_ELEMENT_NEWPARAM__HALF4 = 188126820;
extern const char* NAME_ELEMENT_NEWPARAM__HALF4;

const StringHash HASH_ELEMENT_HALF1X1 = 243439825;
extern const char* NAME_ELEMENT_HALF1X1;
const StringHash HASH_ELEMENT_NEWPARAM__HALF1X1 = 110519169;
extern const char* NAME_ELEMENT_NEWPARAM__HALF1X1;

const StringHash HASH_ELEMENT_HALF1X2 = 243439826;
extern const char* NAME_ELEMENT_HALF1X2;
const StringHash HASH_ELEMENT_NEWPARAM__HALF1X2 = 110519170;
extern const char* NAME_ELEMENT_NEWPARAM__HALF1X2;

const StringHash HASH_ELEMENT_HALF1X3 = 243439827;
extern const char* NAME_ELEMENT_HALF1X3;
const StringHash HASH_ELEMENT_NEWPARAM__HALF1X3 = 110519171;
extern const char* NAME_ELEMENT_NEWPARAM__HALF1X3;

const StringHash HASH_ELEMENT_HALF1X4 = 243439828;
extern const char* NAME_ELEMENT_HALF1X4;
const StringHash HASH_ELEMENT_NEWPARAM__HALF1X4 = 110519172;
extern const char* NAME_ELEMENT_NEWPARAM__HALF1X4;

const StringHash HASH_ELEMENT_HALF2X1 = 243440081;
extern const char* NAME_ELEMENT_HALF2X1;
const StringHash HASH_ELEMENT_NEWPARAM__HALF2X1 = 110518913;
extern const char* NAME_ELEMENT_NEWPARAM__HALF2X1;

const StringHash HASH_ELEMENT_HALF2X2 = 243440082;
extern const char* NAME_ELEMENT_HALF2X2;
const StringHash HASH_ELEMENT_NEWPARAM__HALF2X2 = 110518914;
extern const char* NAME_ELEMENT_NEWPARAM__HALF2X2;

const StringHash HASH_ELEMENT_HALF2X3 = 243440083;
extern const char* NAME_ELEMENT_HALF2X3;
const StringHash HASH_ELEMENT_NEWPARAM__HALF2X3 = 110518915;
extern const char* NAME_ELEMENT_NEWPARAM__HALF2X3;

const StringHash HASH_ELEMENT_HALF2X4 = 243440084;
extern const char* NAME_ELEMENT_HALF2X4;
const StringHash HASH_ELEMENT_NEWPARAM__HALF2X4 = 110518916;
extern const char* NAME_ELEMENT_NEWPARAM__HALF2X4;

const StringHash HASH_ELEMENT_HALF3X1 = 243440337;
extern const char* NAME_ELEMENT_HALF3X1;
const StringHash HASH_ELEMENT_NEWPARAM__HALF3X1 = 110518657;
extern const char* NAME_ELEMENT_NEWPARAM__HALF3X1;

const StringHash HASH_ELEMENT_HALF3X2 = 243440338;
extern const char* NAME_ELEMENT_HALF3X2;
const StringHash HASH_ELEMENT_NEWPARAM__HALF3X2 = 110518658;
extern const char* NAME_ELEMENT_NEWPARAM__HALF3X2;

const StringHash HASH_ELEMENT_HALF3X3 = 243440339;
extern const char* NAME_ELEMENT_HALF3X3;
const StringHash HASH_ELEMENT_NEWPARAM__HALF3X3 = 110518659;
extern const char* NAME_ELEMENT_NEWPARAM__HALF3X3;

const StringHash HASH_ELEMENT_HALF3X4 = 243440340;
extern const char* NAME_ELEMENT_HALF3X4;
const StringHash HASH_ELEMENT_NEWPARAM__HALF3X4 = 110518660;
extern const char* NAME_ELEMENT_NEWPARAM__HALF3X4;

const StringHash HASH_ELEMENT_HALF4X1 = 243440593;
extern const char* NAME_ELEMENT_HALF4X1;
const StringHash HASH_ELEMENT_NEWPARAM__HALF4X1 = 110518401;
extern const char* NAME_ELEMENT_NEWPARAM__HALF4X1;

const StringHash HASH_ELEMENT_HALF4X2 = 243440594;
extern const char* NAME_ELEMENT_HALF4X2;
const StringHash HASH_ELEMENT_NEWPARAM__HALF4X2 = 110518402;
extern const char* NAME_ELEMENT_NEWPARAM__HALF4X2;

const StringHash HASH_ELEMENT_HALF4X3 = 243440595;
extern const char* NAME_ELEMENT_HALF4X3;
const StringHash HASH_ELEMENT_NEWPARAM__HALF4X3 = 110518403;
extern const char* NAME_ELEMENT_NEWPARAM__HALF4X3;

const StringHash HASH_ELEMENT_HALF4X4 = 243440596;
extern const char* NAME_ELEMENT_HALF4X4;
const StringHash HASH_ELEMENT_NEWPARAM__HALF4X4 = 110518404;
extern const char* NAME_ELEMENT_NEWPARAM__HALF4X4;

const StringHash HASH_ELEMENT_FIXED = 7147188;
extern const char* NAME_ELEMENT_FIXED;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED = 188086852;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED;

const StringHash HASH_ELEMENT_FIXED1 = 114355057;
extern const char* NAME_ELEMENT_FIXED1;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED1 = 56599745;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED1;

const StringHash HASH_ELEMENT_FIXED2 = 114355058;
extern const char* NAME_ELEMENT_FIXED2;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED2 = 56599746;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED2;

const StringHash HASH_ELEMENT_FIXED3 = 114355059;
extern const char* NAME_ELEMENT_FIXED3;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED3 = 56599747;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED3;

const StringHash HASH_ELEMENT_FIXED4 = 114355060;
extern const char* NAME_ELEMENT_FIXED4;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED4 = 56599748;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED4;

const StringHash HASH_ELEMENT_FIXED1X1 = 15433313;
extern const char* NAME_ELEMENT_FIXED1X1;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X1 = 262458337;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X1;

const StringHash HASH_ELEMENT_FIXED1X2 = 15433314;
extern const char* NAME_ELEMENT_FIXED1X2;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X2 = 262458338;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X2;

const StringHash HASH_ELEMENT_FIXED1X3 = 15433315;
extern const char* NAME_ELEMENT_FIXED1X3;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X3 = 262458339;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X3;

const StringHash HASH_ELEMENT_FIXED1X4 = 15433316;
extern const char* NAME_ELEMENT_FIXED1X4;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X4 = 262458340;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X4;

const StringHash HASH_ELEMENT_FIXED2X1 = 15433569;
extern const char* NAME_ELEMENT_FIXED2X1;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X1 = 262458081;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X1;

const StringHash HASH_ELEMENT_FIXED2X2 = 15433570;
extern const char* NAME_ELEMENT_FIXED2X2;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X2 = 262458082;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X2;

const StringHash HASH_ELEMENT_FIXED2X3 = 15433571;
extern const char* NAME_ELEMENT_FIXED2X3;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X3 = 262458083;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X3;

const StringHash HASH_ELEMENT_FIXED2X4 = 15433572;
extern const char* NAME_ELEMENT_FIXED2X4;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X4 = 262458084;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X4;

const StringHash HASH_ELEMENT_FIXED3X1 = 15432801;
extern const char* NAME_ELEMENT_FIXED3X1;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X1 = 262457825;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X1;

const StringHash HASH_ELEMENT_FIXED3X2 = 15432802;
extern const char* NAME_ELEMENT_FIXED3X2;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X2 = 262457826;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X2;

const StringHash HASH_ELEMENT_FIXED3X3 = 15432803;
extern const char* NAME_ELEMENT_FIXED3X3;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X3 = 262457827;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X3;

const StringHash HASH_ELEMENT_FIXED3X4 = 15432804;
extern const char* NAME_ELEMENT_FIXED3X4;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X4 = 262457828;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X4;

const StringHash HASH_ELEMENT_FIXED4X1 = 15433057;
extern const char* NAME_ELEMENT_FIXED4X1;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X1 = 262457569;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X1;

const StringHash HASH_ELEMENT_FIXED4X2 = 15433058;
extern const char* NAME_ELEMENT_FIXED4X2;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X2 = 262457570;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X2;

const StringHash HASH_ELEMENT_FIXED4X3 = 15433059;
extern const char* NAME_ELEMENT_FIXED4X3;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X3 = 262457571;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X3;

const StringHash HASH_ELEMENT_FIXED4X4 = 15433060;
extern const char* NAME_ELEMENT_FIXED4X4;
const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X4 = 262457572;
extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X4;

const StringHash HASH_ELEMENT_SURFACE____CG_SURFACE_TYPE = 115551221;
extern const char* NAME_ELEMENT_SURFACE____CG_SURFACE_TYPE;
struct surface____cg_surface_type__AttributeData
{
    static const surface____cg_surface_type__AttributeData DEFAULT;

    ENUM__fx_surface_type_enum type;
};

const StringHash HASH_ELEMENT_CG_SURFACE_TYPE____GENERATOR = 37457026;
extern const char* NAME_ELEMENT_CG_SURFACE_TYPE____GENERATOR;

const StringHash HASH_ELEMENT_PROFILE_CG__NEWPARAM__SURFACE__GENERATOR__NAME = 159447349;
extern const char* NAME_ELEMENT_PROFILE_CG__NEWPARAM__SURFACE__GENERATOR__NAME;
struct profile_CG__newparam__surface__generator__name__AttributeData
{
    static const profile_CG__newparam__surface__generator__name__AttributeData DEFAULT;

    const ParserChar* source;
};

const StringHash HASH_ELEMENT_SETPARAM____CG_SETPARAM_SIMPLE = 141273397;
extern const char* NAME_ELEMENT_SETPARAM____CG_SETPARAM_SIMPLE;
struct setparam____cg_setparam_simple__AttributeData
{
    static const setparam____cg_setparam_simple__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_SAMPLER1D____CG_SAMPLER1D = 221373652;
extern const char* NAME_ELEMENT_SAMPLER1D____CG_SAMPLER1D;

const StringHash HASH_ELEMENT_SAMPLER2D____CG_SAMPLER2D = 220325092;
extern const char* NAME_ELEMENT_SAMPLER2D____CG_SAMPLER2D;

const StringHash HASH_ELEMENT_SAMPLER3D____CG_SAMPLER3D = 219276532;
extern const char* NAME_ELEMENT_SAMPLER3D____CG_SAMPLER3D;

const StringHash HASH_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT = 10859924;
extern const char* NAME_ELEMENT_SAMPLERRECT____CG_SAMPLERRECT;

const StringHash HASH_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE = 94614933;
extern const char* NAME_ELEMENT_SAMPLERCUBE____CG_SAMPLERCUBE;

const StringHash HASH_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH = 111514472;
extern const char* NAME_ELEMENT_SAMPLERDEPTH____CG_SAMPLERDEPTH;

const StringHash HASH_ELEMENT_USERTYPE = 164218789;
extern const char* NAME_ELEMENT_USERTYPE;
const StringHash HASH_ELEMENT_NEWPARAM__USERTYPE = 109449253;
extern const char* NAME_ELEMENT_NEWPARAM__USERTYPE;
struct usertype__AttributeData
{
    static const usertype__AttributeData DEFAULT;

    const ParserChar* name;
    const ParserChar* source;
};

const StringHash HASH_ELEMENT_ARRAY____CG_SETARRAY_TYPE = 215039413;
extern const char* NAME_ELEMENT_ARRAY____CG_SETARRAY_TYPE;
const StringHash HASH_ELEMENT_USERTYPE__ARRAY = 163898057;
extern const char* NAME_ELEMENT_USERTYPE__ARRAY;
struct array____cg_setarray_type__AttributeData
{
    static const array____cg_setarray_type__AttributeData DEFAULT;

    uint64 length;
};

const StringHash HASH_ELEMENT_CONNECT_PARAM = 67355581;
extern const char* NAME_ELEMENT_CONNECT_PARAM;
const StringHash HASH_ELEMENT_USERTYPE__CONNECT_PARAM = 5868045;
extern const char* NAME_ELEMENT_USERTYPE__CONNECT_PARAM;
struct connect_param__AttributeData
{
    static const connect_param__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_SETPARAM____CG_SETPARAM = 49241821;
extern const char* NAME_ELEMENT_SETPARAM____CG_SETPARAM;
const StringHash HASH_ELEMENT_USERTYPE__SETPARAM = 185734957;
extern const char* NAME_ELEMENT_USERTYPE__SETPARAM;
struct setparam____cg_setparam__AttributeData
{
    static const setparam____cg_setparam__AttributeData DEFAULT;

    const ParserChar* ref;
    const ParserChar* program;
};

const StringHash HASH_ELEMENT_ARRAY____CG_NEWARRAY_TYPE = 30817685;
extern const char* NAME_ELEMENT_ARRAY____CG_NEWARRAY_TYPE;
struct array____cg_newarray_type__AttributeData
{
    static const array____cg_newarray_type__AttributeData DEFAULT;

    uint64 length;
};

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE = 198327461;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE;
struct profile_CG__technique__AttributeData
{
    static const profile_CG__technique__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS = 44323843;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE__PASS;
struct profile_CG__technique__pass__AttributeData
{
    static const profile_CG__technique__pass__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER = 46821682;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER;
struct profile_CG__technique__pass__shader__AttributeData
{
    static const profile_CG__technique__pass__shader__AttributeData DEFAULT;

    ENUM__cg_pipeline_stage stage;
};

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__COMPILER_TARGET = 28270324;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__COMPILER_TARGET;

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__NAME = 111163141;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__NAME;
struct profile_CG__technique__pass__shader__name__AttributeData
{
    static const profile_CG__technique__pass__shader__name__AttributeData DEFAULT;

    const ParserChar* source;
};

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__BIND = 111148916;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__BIND;
struct profile_CG__technique__pass__shader__bind__AttributeData
{
    static const profile_CG__technique__pass__shader__bind__AttributeData DEFAULT;

    const ParserChar* symbol;
};

const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__BIND__PARAM = 244936829;
extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE__PASS__SHADER__BIND__PARAM;
struct profile_CG__technique__pass__shader__bind__param__AttributeData
{
    static const profile_CG__technique__pass__shader__bind__param__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_PROFILE_COMMON = 171910622;
extern const char* NAME_ELEMENT_PROFILE_COMMON;
struct profile_COMMON__AttributeData
{
    static const profile_COMMON__AttributeData DEFAULT;

    const ParserChar* id;
};

const StringHash HASH_ELEMENT_NEWPARAM____COMMON_NEWPARAM_TYPE = 159994405;
extern const char* NAME_ELEMENT_NEWPARAM____COMMON_NEWPARAM_TYPE;
const StringHash HASH_ELEMENT_PROFILE_COMMON__NEWPARAM = 151782173;
extern const char* NAME_ELEMENT_PROFILE_COMMON__NEWPARAM;
struct newparam____common_newparam_type__AttributeData
{
    static const newparam____common_newparam_type__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PROFILE_COMMON__TECHNIQUE = 123572309;
extern const char* NAME_ELEMENT_PROFILE_COMMON__TECHNIQUE;
struct profile_COMMON__technique__AttributeData
{
    static const profile_COMMON__technique__AttributeData DEFAULT;

    const ParserChar* id;
    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_PROFILE_COMMON__TECHNIQUE__CONSTANT = 100962372;
extern const char* NAME_ELEMENT_PROFILE_COMMON__TECHNIQUE__CONSTANT;
const StringHash HASH_ELEMENT_TECHNIQUE__CONSTANT = 140404900;
extern const char* NAME_ELEMENT_TECHNIQUE__CONSTANT;

const StringHash HASH_ELEMENT_EMISSION = 67803806;
extern const char* NAME_ELEMENT_EMISSION;
const StringHash HASH_ELEMENT_CONSTANT__EMISSION = 17478014;
extern const char* NAME_ELEMENT_CONSTANT__EMISSION;

const StringHash HASH_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____COLOR = 143009378;
extern const char* NAME_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____COLOR;
const StringHash HASH_ELEMENT_EMISSION__COLOR = 99748322;
extern const char* NAME_ELEMENT_EMISSION__COLOR;
struct common_color_or_texture_type____color__AttributeData
{
    static const common_color_or_texture_type____color__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____PARAM = 146460541;
extern const char* NAME_ELEMENT_COMMON_COLOR_OR_TEXTURE_TYPE____PARAM;
const StringHash HASH_ELEMENT_EMISSION__PARAM = 97460989;
extern const char* NAME_ELEMENT_EMISSION__PARAM;
struct common_color_or_texture_type____param__AttributeData
{
    static const common_color_or_texture_type____param__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_TEXTURE = 181386485;
extern const char* NAME_ELEMENT_TEXTURE;
const StringHash HASH_ELEMENT_EMISSION__TEXTURE = 56965445;
extern const char* NAME_ELEMENT_EMISSION__TEXTURE;
const StringHash HASH_ATTRIBUTE_TEXTURE = 181386485;
extern const char* NAME_ATTRIBUTE_TEXTURE;
const StringHash HASH_ATTRIBUTE_TEXCOORD = 216686884;
extern const char* NAME_ATTRIBUTE_TEXCOORD;
struct texture__AttributeData
{
    static const texture__AttributeData DEFAULT;

    const ParserChar* texture;
    const ParserChar* texcoord;
};

const StringHash HASH_ELEMENT_REFLECTIVE = 45955861;
extern const char* NAME_ELEMENT_REFLECTIVE;
const StringHash HASH_ELEMENT_CONSTANT__REFLECTIVE = 43423765;
extern const char* NAME_ELEMENT_CONSTANT__REFLECTIVE;

const StringHash HASH_ELEMENT_REFLECTIVITY = 221979145;
extern const char* NAME_ELEMENT_REFLECTIVITY;
const StringHash HASH_ELEMENT_CONSTANT__REFLECTIVITY = 110633513;
extern const char* NAME_ELEMENT_CONSTANT__REFLECTIVITY;

const StringHash HASH_ELEMENT_COMMON_FLOAT_OR_PARAM_TYPE____FLOAT = 148509924;
extern const char* NAME_ELEMENT_COMMON_FLOAT_OR_PARAM_TYPE____FLOAT;
const StringHash HASH_ELEMENT_REFLECTIVITY__FLOAT = 149886404;
extern const char* NAME_ELEMENT_REFLECTIVITY__FLOAT;
struct common_float_or_param_type____float__AttributeData
{
    static const common_float_or_param_type____float__AttributeData DEFAULT;

    const ParserChar* sid;
};

const StringHash HASH_ELEMENT_COMMON_FLOAT_OR_PARAM_TYPE____PARAM = 149137693;
extern const char* NAME_ELEMENT_COMMON_FLOAT_OR_PARAM_TYPE____PARAM;
const StringHash HASH_ELEMENT_REFLECTIVITY__PARAM = 148154429;
extern const char* NAME_ELEMENT_REFLECTIVITY__PARAM;
struct common_float_or_param_type____param__AttributeData
{
    static const common_float_or_param_type____param__AttributeData DEFAULT;

    const ParserChar* ref;
};

const StringHash HASH_ELEMENT_TRANSPARENT = 169018372;
extern const char* NAME_ELEMENT_TRANSPARENT;
const StringHash HASH_ELEMENT_CONSTANT__TRANSPARENT = 145306628;
extern const char* NAME_ELEMENT_CONSTANT__TRANSPARENT;
const StringHash HASH_ATTRIBUTE_OPAQUE = 124160181;
extern const char* NAME_ATTRIBUTE_OPAQUE;
struct transparent__AttributeData
{
    static const transparent__AttributeData DEFAULT;

    ENUM__fx_opaque_enum opaque;
};

const StringHash HASH_ELEMENT_TRANSPARENCY = 19939593;
extern const char* NAME_ELEMENT_TRANSPARENCY;
const StringHash HASH_ELEMENT_CONSTANT__TRANSPARENCY = 177422633;
extern const char* NAME_ELEMENT_CONSTANT__TRANSPARENCY;

const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION = 242674622;
extern const char* NAME_ELEMENT_INDEX_OF_REFRACTION;
const StringHash HASH_ELEMENT_CONSTANT__INDEX_OF_REFRACTION = 195491134;
extern const char* NAME_ELEMENT_CONSTANT__INDEX_OF_REFRACTION;

const StringHash HASH_ELEMENT_LAMBERT = 42175716;
extern const char* NAME_ELEMENT_LAMBERT;
const StringHash HASH_ELEMENT_TECHNIQUE__LAMBERT = 90423428;
extern const char* NAME_ELEMENT_TECHNIQUE__LAMBERT;

const StringHash HASH_ELEMENT_AMBIENT____COMMON_COLOR_OR_TEXTURE_TYPE = 14131013;
extern const char* NAME_ELEMENT_AMBIENT____COMMON_COLOR_OR_TEXTURE_TYPE;
const StringHash HASH_ELEMENT_LAMBERT__AMBIENT = 16135972;
extern const char* NAME_ELEMENT_LAMBERT__AMBIENT;

const StringHash HASH_ELEMENT_DIFFUSE = 184343797;
extern const char* NAME_ELEMENT_DIFFUSE;
const StringHash HASH_ELEMENT_LAMBERT__DIFFUSE = 36835829;
extern const char* NAME_ELEMENT_LAMBERT__DIFFUSE;

const StringHash HASH_ELEMENT_PHONG = 7796295;
extern const char* NAME_ELEMENT_PHONG;
const StringHash HASH_ELEMENT_TECHNIQUE__PHONG = 204592647;
extern const char* NAME_ELEMENT_TECHNIQUE__PHONG;

const StringHash HASH_ELEMENT_SPECULAR = 112903458;
extern const char* NAME_ELEMENT_SPECULAR;
const StringHash HASH_ELEMENT_PHONG__SPECULAR = 16253650;
extern const char* NAME_ELEMENT_PHONG__SPECULAR;

const StringHash HASH_ELEMENT_SHININESS = 5256531;
extern const char* NAME_ELEMENT_SHININESS;
const StringHash HASH_ELEMENT_PHONG__SHININESS = 211569187;
extern const char* NAME_ELEMENT_PHONG__SHININESS;

const StringHash HASH_ELEMENT_BLINN = 6893646;
extern const char* NAME_ELEMENT_BLINN;
const StringHash HASH_ELEMENT_TECHNIQUE__BLINN = 202379278;
extern const char* NAME_ELEMENT_TECHNIQUE__BLINN;



} // namespace
#endif
