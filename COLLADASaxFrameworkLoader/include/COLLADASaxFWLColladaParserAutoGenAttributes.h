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


	const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS = 175028019;
	extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS;
	const StringHash HASH_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS = 175028019;
	extern const char* NAME_ELEMENT_COLLADA__LIBRARY_FORCE_FIELDS;
	const StringHash HASH_ATTRIBUTE_ID = 1780;
	extern const char* NAME_ATTRIBUTE_ID;
	const StringHash HASH_ATTRIBUTE_NAME = 477237;
	extern const char* NAME_ATTRIBUTE_NAME;
	struct library_force_fields__AttributeData
	{
		static const library_force_fields__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_ASSET = 256178756;
	extern const char* NAME_ELEMENT_ASSET;
	const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__ASSET = 256178756;
	extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__ASSET;

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
	struct unit__AttributeData
	{
		static const unit__AttributeData DEFAULT;

		float meter;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_UP_AXIS = 114896611;
	extern const char* NAME_ELEMENT_UP_AXIS;
	const StringHash HASH_ELEMENT_ASSET__UP_AXIS = 114896611;
	extern const char* NAME_ELEMENT_ASSET__UP_AXIS;

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

	const StringHash HASH_ELEMENT_TECHNIQUE = 49118021;
	extern const char* NAME_ELEMENT_TECHNIQUE;
	const StringHash HASH_ELEMENT_FORCE_FIELD__TECHNIQUE = 49118021;
	extern const char* NAME_ELEMENT_FORCE_FIELD__TECHNIQUE;
	const StringHash HASH_ATTRIBUTE_PROFILE = 127258709;
	extern const char* NAME_ATTRIBUTE_PROFILE;
	struct force_field__technique__AttributeData
	{
		static const force_field__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_EXTRA = 138784945;
	extern const char* NAME_ELEMENT_EXTRA;
	const StringHash HASH_ELEMENT_FORCE_FIELD__EXTRA = 138784945;
	extern const char* NAME_ELEMENT_FORCE_FIELD__EXTRA;
	const StringHash HASH_ATTRIBUTE_TYPE = 508005;
	extern const char* NAME_ATTRIBUTE_TYPE;
	struct force_field__extra__AttributeData
	{
		static const force_field__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_EXTRA__ASSET = 60232116;
	extern const char* NAME_ELEMENT_EXTRA__ASSET;

	const StringHash HASH_ELEMENT_EXTRA__TECHNIQUE = 27831733;
	extern const char* NAME_ELEMENT_EXTRA__TECHNIQUE;
	struct extra__technique__AttributeData
	{
		static const extra__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA = 255895553;
	extern const char* NAME_ELEMENT_LIBRARY_FORCE_FIELDS__EXTRA;
	struct library_force_fields__extra__AttributeData
	{
		static const library_force_fields__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_INSTANCE_EFFECT = 50798276;
	extern const char* NAME_ELEMENT_INSTANCE_EFFECT;
	const StringHash HASH_ELEMENT_RENDER__INSTANCE_EFFECT = 50798276;
	extern const char* NAME_ELEMENT_RENDER__INSTANCE_EFFECT;
	const StringHash HASH_ATTRIBUTE_URL = 31884;
	extern const char* NAME_ATTRIBUTE_URL;
	const StringHash HASH_ATTRIBUTE_SID = 31220;
	extern const char* NAME_ATTRIBUTE_SID;
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
	const StringHash HASH_ATTRIBUTE_REF = 30902;
	extern const char* NAME_ATTRIBUTE_REF;
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

	const StringHash HASH_ELEMENT_BOOL = 206428;
	extern const char* NAME_ELEMENT_BOOL;
	const StringHash HASH_ELEMENT_SETPARAM__BOOL = 206428;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL;

	const StringHash HASH_ELEMENT_BOOL2 = 3302898;
	extern const char* NAME_ELEMENT_BOOL2;
	const StringHash HASH_ELEMENT_SETPARAM__BOOL2 = 3302898;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL2;

	const StringHash HASH_ELEMENT_BOOL3 = 3302899;
	extern const char* NAME_ELEMENT_BOOL3;
	const StringHash HASH_ELEMENT_SETPARAM__BOOL3 = 3302899;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL3;

	const StringHash HASH_ELEMENT_BOOL4 = 3302900;
	extern const char* NAME_ELEMENT_BOOL4;
	const StringHash HASH_ELEMENT_SETPARAM__BOOL4 = 3302900;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL4;

	const StringHash HASH_ELEMENT_INT = 14164;
	extern const char* NAME_ELEMENT_INT;
	const StringHash HASH_ELEMENT_SETPARAM__INT = 14164;
	extern const char* NAME_ELEMENT_SETPARAM__INT;

	const StringHash HASH_ELEMENT_INT2 = 226674;
	extern const char* NAME_ELEMENT_INT2;
	const StringHash HASH_ELEMENT_SETPARAM__INT2 = 226674;
	extern const char* NAME_ELEMENT_SETPARAM__INT2;

	const StringHash HASH_ELEMENT_INT3 = 226675;
	extern const char* NAME_ELEMENT_INT3;
	const StringHash HASH_ELEMENT_SETPARAM__INT3 = 226675;
	extern const char* NAME_ELEMENT_SETPARAM__INT3;

	const StringHash HASH_ELEMENT_INT4 = 226676;
	extern const char* NAME_ELEMENT_INT4;
	const StringHash HASH_ELEMENT_SETPARAM__INT4 = 226676;
	extern const char* NAME_ELEMENT_SETPARAM__INT4;

	const StringHash HASH_ELEMENT_FLOAT = 3552644;
	extern const char* NAME_ELEMENT_FLOAT;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT = 3552644;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT;

	const StringHash HASH_ELEMENT_FLOAT2 = 56842354;
	extern const char* NAME_ELEMENT_FLOAT2;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT2 = 56842354;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT2;

	const StringHash HASH_ELEMENT_FLOAT3 = 56842355;
	extern const char* NAME_ELEMENT_FLOAT3;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT3 = 56842355;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT3;

	const StringHash HASH_ELEMENT_FLOAT4 = 56842356;
	extern const char* NAME_ELEMENT_FLOAT4;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT4 = 56842356;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT4;

	const StringHash HASH_ELEMENT_FLOAT1X1 = 56130513;
	extern const char* NAME_ELEMENT_FLOAT1X1;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X1 = 56130513;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X1;

	const StringHash HASH_ELEMENT_FLOAT1X2 = 56130514;
	extern const char* NAME_ELEMENT_FLOAT1X2;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X2 = 56130514;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X2;

	const StringHash HASH_ELEMENT_FLOAT1X3 = 56130515;
	extern const char* NAME_ELEMENT_FLOAT1X3;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X3 = 56130515;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X3;

	const StringHash HASH_ELEMENT_FLOAT1X4 = 56130516;
	extern const char* NAME_ELEMENT_FLOAT1X4;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT1X4 = 56130516;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT1X4;

	const StringHash HASH_ELEMENT_FLOAT2X1 = 56130257;
	extern const char* NAME_ELEMENT_FLOAT2X1;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X1 = 56130257;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X1;

	const StringHash HASH_ELEMENT_FLOAT2X2 = 56130258;
	extern const char* NAME_ELEMENT_FLOAT2X2;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X2 = 56130258;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X2;

	const StringHash HASH_ELEMENT_FLOAT2X3 = 56130259;
	extern const char* NAME_ELEMENT_FLOAT2X3;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X3 = 56130259;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X3;

	const StringHash HASH_ELEMENT_FLOAT2X4 = 56130260;
	extern const char* NAME_ELEMENT_FLOAT2X4;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT2X4 = 56130260;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT2X4;

	const StringHash HASH_ELEMENT_FLOAT3X1 = 56130001;
	extern const char* NAME_ELEMENT_FLOAT3X1;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X1 = 56130001;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X1;

	const StringHash HASH_ELEMENT_FLOAT3X2 = 56130002;
	extern const char* NAME_ELEMENT_FLOAT3X2;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X2 = 56130002;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X2;

	const StringHash HASH_ELEMENT_FLOAT3X3 = 56130003;
	extern const char* NAME_ELEMENT_FLOAT3X3;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X3 = 56130003;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X3;

	const StringHash HASH_ELEMENT_FLOAT3X4 = 56130004;
	extern const char* NAME_ELEMENT_FLOAT3X4;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT3X4 = 56130004;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT3X4;

	const StringHash HASH_ELEMENT_FLOAT4X1 = 56129745;
	extern const char* NAME_ELEMENT_FLOAT4X1;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X1 = 56129745;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X1;

	const StringHash HASH_ELEMENT_FLOAT4X2 = 56129746;
	extern const char* NAME_ELEMENT_FLOAT4X2;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X2 = 56129746;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X2;

	const StringHash HASH_ELEMENT_FLOAT4X3 = 56129747;
	extern const char* NAME_ELEMENT_FLOAT4X3;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X3 = 56129747;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X3;

	const StringHash HASH_ELEMENT_FLOAT4X4 = 56129748;
	extern const char* NAME_ELEMENT_FLOAT4X4;
	const StringHash HASH_ELEMENT_SETPARAM__FLOAT4X4 = 56129748;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT4X4;

	const StringHash HASH_ELEMENT_SURFACE = 63489941;
	extern const char* NAME_ELEMENT_SURFACE;
	const StringHash HASH_ELEMENT_SETPARAM__SURFACE = 63489941;
	extern const char* NAME_ELEMENT_SETPARAM__SURFACE;
	struct setparam__surface__AttributeData
	{
		static const setparam__surface__AttributeData DEFAULT;

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

	const StringHash HASH_ELEMENT_INIT_FROM = 245107997;
	extern const char* NAME_ELEMENT_INIT_FROM;
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
	struct format_hint__extra__AttributeData
	{
		static const format_hint__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct surface__extra__AttributeData
	{
		static const surface__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLER1D = 74630612;
	extern const char* NAME_ELEMENT_SAMPLER1D;
	const StringHash HASH_ELEMENT_SETPARAM__SAMPLER1D = 74630612;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLER1D;

	const StringHash HASH_ELEMENT_SOURCE = 70915797;
	extern const char* NAME_ELEMENT_SOURCE;
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
	struct sampler1D__extra__AttributeData
	{
		static const sampler1D__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLER2D = 74630628;
	extern const char* NAME_ELEMENT_SAMPLER2D;
	const StringHash HASH_ELEMENT_SETPARAM__SAMPLER2D = 74630628;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLER2D;

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
	struct sampler2D__extra__AttributeData
	{
		static const sampler2D__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLER3D = 74630644;
	extern const char* NAME_ELEMENT_SAMPLER3D;
	const StringHash HASH_ELEMENT_SETPARAM__SAMPLER3D = 74630644;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLER3D;

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
	struct sampler3D__extra__AttributeData
	{
		static const sampler3D__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLERCUBE = 46533909;
	extern const char* NAME_ELEMENT_SAMPLERCUBE;
	const StringHash HASH_ELEMENT_SETPARAM__SAMPLERCUBE = 46533909;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLERCUBE;

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
	struct samplerCUBE__extra__AttributeData
	{
		static const samplerCUBE__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLERRECT = 46657012;
	extern const char* NAME_ELEMENT_SAMPLERRECT;
	const StringHash HASH_ELEMENT_SETPARAM__SAMPLERRECT = 46657012;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLERRECT;

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
	struct samplerRECT__extra__AttributeData
	{
		static const samplerRECT__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLERDEPTH = 207676072;
	extern const char* NAME_ELEMENT_SAMPLERDEPTH;
	const StringHash HASH_ELEMENT_SETPARAM__SAMPLERDEPTH = 207676072;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLERDEPTH;

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
	struct samplerDEPTH__extra__AttributeData
	{
		static const samplerDEPTH__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_ENUM = 210365;
	extern const char* NAME_ELEMENT_ENUM;
	const StringHash HASH_ELEMENT_SETPARAM__ENUM = 210365;
	extern const char* NAME_ELEMENT_SETPARAM__ENUM;

	const StringHash HASH_ELEMENT_INSTANCE_EFFECT__EXTRA = 101966321;
	extern const char* NAME_ELEMENT_INSTANCE_EFFECT__EXTRA;
	struct instance_effect__extra__AttributeData
	{
		static const instance_effect__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
		const ParserChar* count;
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
		const ParserChar* count;
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
		const ParserChar* count;
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
		const ParserChar* count;
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
		const ParserChar* count;
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

		const ParserChar* count;
		const ParserChar* offset;
		const ParserChar* source;
		const ParserChar* stride;
	};

	const StringHash HASH_ELEMENT_PARAM = 246253965;
	extern const char* NAME_ELEMENT_PARAM;
	const StringHash HASH_ELEMENT_ACCESSOR__PARAM = 246253965;
	extern const char* NAME_ELEMENT_ACCESSOR__PARAM;
	const StringHash HASH_ATTRIBUTE_SEMANTIC = 205020515;
	extern const char* NAME_ATTRIBUTE_SEMANTIC;
	struct accessor__param__AttributeData
	{
		static const accessor__param__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* sid;
		const ParserChar* semantic;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SOURCE__TECHNIQUE = 1838725;
	extern const char* NAME_ELEMENT_SOURCE__TECHNIQUE;
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

	const StringHash HASH_ELEMENT_ANIMATION__EXTRA = 147880641;
	extern const char* NAME_ELEMENT_ANIMATION__EXTRA;
	struct animation__extra__AttributeData
	{
		static const animation__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_TRIFANS = 138814275;
	extern const char* NAME_ELEMENT_TRIFANS;
	const StringHash HASH_ELEMENT_MESH__TRIFANS = 138814275;
	extern const char* NAME_ELEMENT_MESH__TRIFANS;
	const StringHash HASH_ATTRIBUTE_MATERIAL = 145524812;
	extern const char* NAME_ATTRIBUTE_MATERIAL;
	struct trifans__AttributeData
	{
		static const trifans__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_TRIFANS__INPUT = 228906372;
	extern const char* NAME_ELEMENT_TRIFANS__INPUT;
	const StringHash HASH_ATTRIBUTE_SET = 31172;
	extern const char* NAME_ATTRIBUTE_SET;
	struct trifans__input__AttributeData
	{
		static const trifans__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_P = 209866128;
	extern const char* NAME_ELEMENT_P;
	const StringHash HASH_ELEMENT_TRIFANS__P = 209866128;
	extern const char* NAME_ELEMENT_TRIFANS__P;

	const StringHash HASH_ELEMENT_TRIFANS__EXTRA = 228620737;
	extern const char* NAME_ELEMENT_TRIFANS__EXTRA;
	struct trifans__extra__AttributeData
	{
		static const trifans__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct source__AttributeData
	{
		static const source__AttributeData DEFAULT;

		const ParserChar* id;
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

	const StringHash HASH_ELEMENT_PROFILE_GLES__ASSET = 200766244;
	extern const char* NAME_ELEMENT_PROFILE_GLES__ASSET;

	const StringHash HASH_ELEMENT_IMAGE = 200404277;
	extern const char* NAME_ELEMENT_IMAGE;
	const StringHash HASH_ELEMENT_PROFILE_GLES__IMAGE = 200404277;
	extern const char* NAME_ELEMENT_PROFILE_GLES__IMAGE;
	const StringHash HASH_ATTRIBUTE_FORMAT = 114725764;
	extern const char* NAME_ATTRIBUTE_FORMAT;
	const StringHash HASH_ATTRIBUTE_HEIGHT = 116129268;
	extern const char* NAME_ATTRIBUTE_HEIGHT;
	const StringHash HASH_ATTRIBUTE_WIDTH = 8256424;
	extern const char* NAME_ATTRIBUTE_WIDTH;
	const StringHash HASH_ATTRIBUTE_DEPTH = 6997928;
	extern const char* NAME_ATTRIBUTE_DEPTH;
	struct profile_GLES__image__AttributeData
	{
		static const profile_GLES__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_IMAGE__ASSET = 73127028;
	extern const char* NAME_ELEMENT_IMAGE__ASSET;

	const StringHash HASH_ELEMENT_DATA = 189112177;
	extern const char* NAME_ELEMENT_DATA;
	const StringHash HASH_ELEMENT_IMAGE__DATA = 189112177;
	extern const char* NAME_ELEMENT_IMAGE__DATA;

	const StringHash HASH_ELEMENT_IMAGE__INIT_FROM = 221349405;
	extern const char* NAME_ELEMENT_IMAGE__INIT_FROM;

	const StringHash HASH_ELEMENT_IMAGE__EXTRA = 73369137;
	extern const char* NAME_ELEMENT_IMAGE__EXTRA;
	struct image__extra__AttributeData
	{
		static const image__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_NEWPARAM = 21514445;
	extern const char* NAME_ELEMENT_NEWPARAM;
	const StringHash HASH_ELEMENT_PROFILE_GLES__NEWPARAM = 21514445;
	extern const char* NAME_ELEMENT_PROFILE_GLES__NEWPARAM;
	struct profile_GLES__newparam__AttributeData
	{
		static const profile_GLES__newparam__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_ANNOTATE = 202972325;
	extern const char* NAME_ELEMENT_ANNOTATE;
	const StringHash HASH_ELEMENT_NEWPARAM__ANNOTATE = 202972325;
	extern const char* NAME_ELEMENT_NEWPARAM__ANNOTATE;
	struct newparam__annotate__AttributeData
	{
		static const newparam__annotate__AttributeData DEFAULT;

		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_ANNOTATE__BOOL = 2309228;
	extern const char* NAME_ELEMENT_ANNOTATE__BOOL;

	const StringHash HASH_ELEMENT_ANNOTATE__BOOL2 = 36947698;
	extern const char* NAME_ELEMENT_ANNOTATE__BOOL2;

	const StringHash HASH_ELEMENT_ANNOTATE__BOOL3 = 36947699;
	extern const char* NAME_ELEMENT_ANNOTATE__BOOL3;

	const StringHash HASH_ELEMENT_ANNOTATE__BOOL4 = 36947700;
	extern const char* NAME_ELEMENT_ANNOTATE__BOOL4;

	const StringHash HASH_ELEMENT_ANNOTATE__INT = 50476724;
	extern const char* NAME_ELEMENT_ANNOTATE__INT;

	const StringHash HASH_ELEMENT_ANNOTATE__INT2 = 2321218;
	extern const char* NAME_ELEMENT_ANNOTATE__INT2;

	const StringHash HASH_ELEMENT_ANNOTATE__INT3 = 2321219;
	extern const char* NAME_ELEMENT_ANNOTATE__INT3;

	const StringHash HASH_ELEMENT_ANNOTATE__INT4 = 2321220;
	extern const char* NAME_ELEMENT_ANNOTATE__INT4;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT = 37213828;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2 = 58550354;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT2;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3 = 58550355;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT3;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4 = 58550356;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT4;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT2X2 = 224942786;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT2X2;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT3X3 = 224942531;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT3X3;

	const StringHash HASH_ELEMENT_ANNOTATE__FLOAT4X4 = 224942276;
	extern const char* NAME_ELEMENT_ANNOTATE__FLOAT4X4;

	const StringHash HASH_ELEMENT_STRING = 376935;
	extern const char* NAME_ELEMENT_STRING;
	const StringHash HASH_ELEMENT_ANNOTATE__STRING = 376935;
	extern const char* NAME_ELEMENT_ANNOTATE__STRING;

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

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X1 = 236440545;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X1;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X2 = 236440546;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X2;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X3 = 236440547;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X3;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1X4 = 236440548;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1X4;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X1 = 236440289;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X1;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X2 = 236440290;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X2;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X3 = 236440291;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X3;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT2X4 = 236440292;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT2X4;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X1 = 236440033;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X1;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X2 = 236440034;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X2;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X3 = 236440035;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X3;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT3X4 = 236440036;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT3X4;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X1 = 236439777;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X1;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X2 = 236439778;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X2;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X3 = 236439779;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X3;

	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT4X4 = 236439780;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT4X4;

	const StringHash HASH_ELEMENT_NEWPARAM__SURFACE = 37502101;
	extern const char* NAME_ELEMENT_NEWPARAM__SURFACE;
	struct newparam__surface__AttributeData
	{
		static const newparam__surface__AttributeData DEFAULT;

		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_TEXTURE_PIPELINE = 68467621;
	extern const char* NAME_ELEMENT_TEXTURE_PIPELINE;
	const StringHash HASH_ELEMENT_NEWPARAM__TEXTURE_PIPELINE = 68467621;
	extern const char* NAME_ELEMENT_NEWPARAM__TEXTURE_PIPELINE;
	struct newparam__texture_pipeline__AttributeData
	{
		static const newparam__texture_pipeline__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TEXCOMBINER = 184640514;
	extern const char* NAME_ELEMENT_TEXCOMBINER;
	const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__TEXCOMBINER = 184640514;
	extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__TEXCOMBINER;

	const StringHash HASH_ELEMENT_CONSTANT = 3715492;
	extern const char* NAME_ELEMENT_CONSTANT;
	const StringHash HASH_ELEMENT_TEXCOMBINER__CONSTANT = 3715492;
	extern const char* NAME_ELEMENT_TEXCOMBINER__CONSTANT;
	const StringHash HASH_ATTRIBUTE_VALUE = 8160181;
	extern const char* NAME_ATTRIBUTE_VALUE;
	const StringHash HASH_ATTRIBUTE_PARAM = 7768189;
	extern const char* NAME_ATTRIBUTE_PARAM;
	struct texcombiner__constant__AttributeData
	{
		static const texcombiner__constant__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_RGB = 102851090;
	extern const char* NAME_ELEMENT_RGB;
	const StringHash HASH_ELEMENT_TEXCOMBINER__RGB = 102851090;
	extern const char* NAME_ELEMENT_TEXCOMBINER__RGB;
	const StringHash HASH_ATTRIBUTE__OPERATOR = 113831170;
	extern const char* NAME_ATTRIBUTE__OPERATOR;
	const StringHash HASH_ATTRIBUTE_SCALE = 7968805;
	extern const char* NAME_ATTRIBUTE_SCALE;
	struct RGB__AttributeData
	{
		static const RGB__AttributeData DEFAULT;

		const ParserChar* _operator;
		float scale;
	};

	const StringHash HASH_ELEMENT_ARGUMENT = 240414596;
	extern const char* NAME_ELEMENT_ARGUMENT;
	const StringHash HASH_ELEMENT_RGB__ARGUMENT = 240414596;
	extern const char* NAME_ELEMENT_RGB__ARGUMENT;
	const StringHash HASH_ATTRIBUTE_OPERAND = 107776052;
	extern const char* NAME_ATTRIBUTE_OPERAND;
	const StringHash HASH_ATTRIBUTE_UNIT = 509188;
	extern const char* NAME_ATTRIBUTE_UNIT;
	struct RGB__argument__AttributeData
	{
		static const RGB__argument__AttributeData DEFAULT;

		const ParserChar* source;
		const ParserChar* operand;
		const ParserChar* unit;
	};

	const StringHash HASH_ELEMENT_ALPHA = 24416449;
	extern const char* NAME_ELEMENT_ALPHA;
	const StringHash HASH_ELEMENT_TEXCOMBINER__ALPHA = 24416449;
	extern const char* NAME_ELEMENT_TEXCOMBINER__ALPHA;
	struct texcombiner__alpha__AttributeData
	{
		static const texcombiner__alpha__AttributeData DEFAULT;

		const ParserChar* _operator;
		float scale;
	};

	const StringHash HASH_ELEMENT_ALPHA__ARGUMENT = 235735012;
	extern const char* NAME_ELEMENT_ALPHA__ARGUMENT;
	struct alpha__argument__AttributeData
	{
		static const alpha__argument__AttributeData DEFAULT;

		const ParserChar* source;
		const ParserChar* operand;
		const ParserChar* unit;
	};

	const StringHash HASH_ELEMENT_TEXENV = 60426918;
	extern const char* NAME_ELEMENT_TEXENV;
	const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__TEXENV = 60426918;
	extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__TEXENV;
	struct texture_pipeline__texenv__AttributeData
	{
		static const texture_pipeline__texenv__AttributeData DEFAULT;

		const ParserChar* _operator;
		const ParserChar* unit;
	};

	const StringHash HASH_ELEMENT_TEXENV__CONSTANT = 168255444;
	extern const char* NAME_ELEMENT_TEXENV__CONSTANT;
	struct texenv__constant__AttributeData
	{
		static const texenv__constant__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__EXTRA = 252679585;
	extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__EXTRA;
	struct texture_pipeline__extra__AttributeData
	{
		static const texture_pipeline__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SAMPLER_STATE = 133824869;
	extern const char* NAME_ELEMENT_SAMPLER_STATE;
	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER_STATE = 133824869;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER_STATE;
	struct newparam__sampler_state__AttributeData
	{
		static const newparam__sampler_state__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SAMPLER_STATE__WRAP_S = 137532627;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__WRAP_S;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__WRAP_T = 137532628;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__WRAP_T;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__MINFILTER = 94762146;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__MINFILTER;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__MAGFILTER = 212202514;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__MAGFILTER;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__MIPFILTER = 128316770;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__MIPFILTER;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__MIPMAP_MAXLEVEL = 12674860;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__MIPMAP_MAXLEVEL;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__MIPMAP_BIAS = 61482963;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__MIPMAP_BIAS;

	const StringHash HASH_ELEMENT_SAMPLER_STATE__EXTRA = 196172513;
	extern const char* NAME_ELEMENT_SAMPLER_STATE__EXTRA;
	struct sampler_state__extra__AttributeData
	{
		static const sampler_state__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_TEXTURE_UNIT = 143987060;
	extern const char* NAME_ELEMENT_TEXTURE_UNIT;
	const StringHash HASH_ELEMENT_NEWPARAM__TEXTURE_UNIT = 143987060;
	extern const char* NAME_ELEMENT_NEWPARAM__TEXTURE_UNIT;
	struct newparam__texture_unit__AttributeData
	{
		static const newparam__texture_unit__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TEXTURE_UNIT__SURFACE = 214217045;
	extern const char* NAME_ELEMENT_TEXTURE_UNIT__SURFACE;

	const StringHash HASH_ELEMENT_TEXTURE_UNIT__SAMPLER_STATE = 165842085;
	extern const char* NAME_ELEMENT_TEXTURE_UNIT__SAMPLER_STATE;

	const StringHash HASH_ELEMENT_TEXCOORD = 204425796;
	extern const char* NAME_ELEMENT_TEXCOORD;
	const StringHash HASH_ELEMENT_TEXTURE_UNIT__TEXCOORD = 204425796;
	extern const char* NAME_ELEMENT_TEXTURE_UNIT__TEXCOORD;
	struct texcoord__AttributeData
	{
		static const texcoord__AttributeData DEFAULT;

		const ParserChar* semantic;
	};

	const StringHash HASH_ELEMENT_TEXTURE_UNIT__EXTRA = 117110769;
	extern const char* NAME_ELEMENT_TEXTURE_UNIT__EXTRA;
	struct texture_unit__extra__AttributeData
	{
		static const texture_unit__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_NEWPARAM__ENUM = 263408381;
	extern const char* NAME_ELEMENT_NEWPARAM__ENUM;

	const StringHash HASH_ELEMENT_PROFILE_GLES__TECHNIQUE = 52481493;
	extern const char* NAME_ELEMENT_PROFILE_GLES__TECHNIQUE;
	struct profile_GLES__technique__AttributeData
	{
		static const profile_GLES__technique__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__ASSET = 202344836;
	extern const char* NAME_ELEMENT_TECHNIQUE__ASSET;

	const StringHash HASH_ELEMENT_TECHNIQUE__ANNOTATE = 122841269;
	extern const char* NAME_ELEMENT_TECHNIQUE__ANNOTATE;
	struct technique__annotate__AttributeData
	{
		static const technique__annotate__AttributeData DEFAULT;

		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__IMAGE = 201922453;
	extern const char* NAME_ELEMENT_TECHNIQUE__IMAGE;
	struct technique__image__AttributeData
	{
		static const technique__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__NEWPARAM = 249710925;
	extern const char* NAME_ELEMENT_TECHNIQUE__NEWPARAM;
	struct technique__newparam__AttributeData
	{
		static const technique__newparam__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__SETPARAM = 246565789;
	extern const char* NAME_ELEMENT_TECHNIQUE__SETPARAM;
	struct technique__setparam__AttributeData
	{
		static const technique__setparam__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_SETPARAM__ANNOTATE = 89566037;
	extern const char* NAME_ELEMENT_SETPARAM__ANNOTATE;
	struct setparam__annotate__AttributeData
	{
		static const setparam__annotate__AttributeData DEFAULT;

		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_SETPARAM__TEXTURE_PIPELINE = 195331813;
	extern const char* NAME_ELEMENT_SETPARAM__TEXTURE_PIPELINE;
	struct setparam__texture_pipeline__AttributeData
	{
		static const setparam__texture_pipeline__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SETPARAM__SAMPLER_STATE = 149871205;
	extern const char* NAME_ELEMENT_SETPARAM__SAMPLER_STATE;
	struct setparam__sampler_state__AttributeData
	{
		static const setparam__sampler_state__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SETPARAM__TEXTURE_UNIT = 145383620;
	extern const char* NAME_ELEMENT_SETPARAM__TEXTURE_UNIT;
	struct setparam__texture_unit__AttributeData
	{
		static const setparam__texture_unit__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_PASS = 79895203;
	extern const char* NAME_ELEMENT_PASS;
	const StringHash HASH_ELEMENT_TECHNIQUE__PASS = 79895203;
	extern const char* NAME_ELEMENT_TECHNIQUE__PASS;
	struct pass__AttributeData
	{
		static const pass__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_PASS__ANNOTATE = 234879621;
	extern const char* NAME_ELEMENT_PASS__ANNOTATE;
	struct pass__annotate__AttributeData
	{
		static const pass__annotate__AttributeData DEFAULT;

		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_COLOR_TARGET = 94769908;
	extern const char* NAME_ELEMENT_COLOR_TARGET;
	const StringHash HASH_ELEMENT_PASS__COLOR_TARGET = 94769908;
	extern const char* NAME_ELEMENT_PASS__COLOR_TARGET;

	const StringHash HASH_ELEMENT_DEPTH_TARGET = 74210900;
	extern const char* NAME_ELEMENT_DEPTH_TARGET;
	const StringHash HASH_ELEMENT_PASS__DEPTH_TARGET = 74210900;
	extern const char* NAME_ELEMENT_PASS__DEPTH_TARGET;

	const StringHash HASH_ELEMENT_STENCIL_TARGET = 75842084;
	extern const char* NAME_ELEMENT_STENCIL_TARGET;
	const StringHash HASH_ELEMENT_PASS__STENCIL_TARGET = 75842084;
	extern const char* NAME_ELEMENT_PASS__STENCIL_TARGET;

	const StringHash HASH_ELEMENT_COLOR_CLEAR = 57328242;
	extern const char* NAME_ELEMENT_COLOR_CLEAR;
	const StringHash HASH_ELEMENT_PASS__COLOR_CLEAR = 57328242;
	extern const char* NAME_ELEMENT_PASS__COLOR_CLEAR;

	const StringHash HASH_ELEMENT_DEPTH_CLEAR = 158754482;
	extern const char* NAME_ELEMENT_DEPTH_CLEAR;
	const StringHash HASH_ELEMENT_PASS__DEPTH_CLEAR = 158754482;
	extern const char* NAME_ELEMENT_PASS__DEPTH_CLEAR;

	const StringHash HASH_ELEMENT_STENCIL_CLEAR = 243070834;
	extern const char* NAME_ELEMENT_STENCIL_CLEAR;
	const StringHash HASH_ELEMENT_PASS__STENCIL_CLEAR = 243070834;
	extern const char* NAME_ELEMENT_PASS__STENCIL_CLEAR;

	const StringHash HASH_ELEMENT_DRAW = 156422183;
	extern const char* NAME_ELEMENT_DRAW;
	const StringHash HASH_ELEMENT_PASS__DRAW = 156422183;
	extern const char* NAME_ELEMENT_PASS__DRAW;

	const StringHash HASH_ELEMENT_ALPHA_FUNC = 122155395;
	extern const char* NAME_ELEMENT_ALPHA_FUNC;
	const StringHash HASH_ELEMENT_PASS__ALPHA_FUNC = 122155395;
	extern const char* NAME_ELEMENT_PASS__ALPHA_FUNC;

	const StringHash HASH_ELEMENT_FUNC = 122061667;
	extern const char* NAME_ELEMENT_FUNC;
	const StringHash HASH_ELEMENT_ALPHA_FUNC__FUNC = 122061667;
	extern const char* NAME_ELEMENT_ALPHA_FUNC__FUNC;
	struct alpha_func__func__AttributeData
	{
		static const alpha_func__func__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_VALUE = 73003461;
	extern const char* NAME_ELEMENT_VALUE;
	const StringHash HASH_ELEMENT_ALPHA_FUNC__VALUE = 73003461;
	extern const char* NAME_ELEMENT_ALPHA_FUNC__VALUE;
	struct alpha_func__value__AttributeData
	{
		static const alpha_func__value__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_BLEND_FUNC = 232202851;
	extern const char* NAME_ELEMENT_BLEND_FUNC;
	const StringHash HASH_ELEMENT_PASS__BLEND_FUNC = 232202851;
	extern const char* NAME_ELEMENT_PASS__BLEND_FUNC;

	const StringHash HASH_ELEMENT_SRC = 148856355;
	extern const char* NAME_ELEMENT_SRC;
	const StringHash HASH_ELEMENT_BLEND_FUNC__SRC = 148856355;
	extern const char* NAME_ELEMENT_BLEND_FUNC__SRC;
	struct src__AttributeData
	{
		static const src__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_DEST = 234284580;
	extern const char* NAME_ELEMENT_DEST;
	const StringHash HASH_ELEMENT_BLEND_FUNC__DEST = 234284580;
	extern const char* NAME_ELEMENT_BLEND_FUNC__DEST;
	struct dest__AttributeData
	{
		static const dest__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CLEAR_COLOR = 57345138;
	extern const char* NAME_ELEMENT_CLEAR_COLOR;
	const StringHash HASH_ELEMENT_PASS__CLEAR_COLOR = 57345138;
	extern const char* NAME_ELEMENT_PASS__CLEAR_COLOR;
	struct clear_color__AttributeData
	{
		static const clear_color__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CLEAR_STENCIL = 168516268;
	extern const char* NAME_ELEMENT_CLEAR_STENCIL;
	const StringHash HASH_ELEMENT_PASS__CLEAR_STENCIL = 168516268;
	extern const char* NAME_ELEMENT_PASS__CLEAR_STENCIL;
	struct clear_stencil__AttributeData
	{
		static const clear_stencil__AttributeData DEFAULT;

		long value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CLEAR_DEPTH = 57304760;
	extern const char* NAME_ELEMENT_CLEAR_DEPTH;
	const StringHash HASH_ELEMENT_PASS__CLEAR_DEPTH = 57304760;
	extern const char* NAME_ELEMENT_PASS__CLEAR_DEPTH;
	struct clear_depth__AttributeData
	{
		static const clear_depth__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CLIP_PLANE = 221654501;
	extern const char* NAME_ELEMENT_CLIP_PLANE;
	const StringHash HASH_ELEMENT_PASS__CLIP_PLANE = 221654501;
	extern const char* NAME_ELEMENT_PASS__CLIP_PLANE;
	const StringHash HASH_ATTRIBUTE_INDEX = 7359176;
	extern const char* NAME_ATTRIBUTE_INDEX;
	struct clip_plane__AttributeData
	{
		static const clip_plane__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_COLOR_MASK = 255276555;
	extern const char* NAME_ELEMENT_COLOR_MASK;
	const StringHash HASH_ELEMENT_PASS__COLOR_MASK = 255276555;
	extern const char* NAME_ELEMENT_PASS__COLOR_MASK;
	struct color_mask__AttributeData
	{
		static const color_mask__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CULL_FACE = 160492501;
	extern const char* NAME_ELEMENT_CULL_FACE;
	const StringHash HASH_ELEMENT_PASS__CULL_FACE = 160492501;
	extern const char* NAME_ELEMENT_PASS__CULL_FACE;
	struct cull_face__AttributeData
	{
		static const cull_face__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_DEPTH_FUNC = 60235923;
	extern const char* NAME_ELEMENT_DEPTH_FUNC;
	const StringHash HASH_ELEMENT_PASS__DEPTH_FUNC = 60235923;
	extern const char* NAME_ELEMENT_PASS__DEPTH_FUNC;
	struct depth_func__AttributeData
	{
		static const depth_func__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_DEPTH_MASK = 60357707;
	extern const char* NAME_ELEMENT_DEPTH_MASK;
	const StringHash HASH_ELEMENT_PASS__DEPTH_MASK = 60357707;
	extern const char* NAME_ELEMENT_PASS__DEPTH_MASK;
	struct depth_mask__AttributeData
	{
		static const depth_mask__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_DEPTH_RANGE = 155470309;
	extern const char* NAME_ELEMENT_DEPTH_RANGE;
	const StringHash HASH_ELEMENT_PASS__DEPTH_RANGE = 155470309;
	extern const char* NAME_ELEMENT_PASS__DEPTH_RANGE;
	struct depth_range__AttributeData
	{
		static const depth_range__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FOG_COLOR = 130910898;
	extern const char* NAME_ELEMENT_FOG_COLOR;
	const StringHash HASH_ELEMENT_PASS__FOG_COLOR = 130910898;
	extern const char* NAME_ELEMENT_PASS__FOG_COLOR;
	struct fog_color__AttributeData
	{
		static const fog_color__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FOG_DENSITY = 263083897;
	extern const char* NAME_ELEMENT_FOG_DENSITY;
	const StringHash HASH_ELEMENT_PASS__FOG_DENSITY = 263083897;
	extern const char* NAME_ELEMENT_PASS__FOG_DENSITY;
	struct fog_density__AttributeData
	{
		static const fog_density__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FOG_MODE = 226326293;
	extern const char* NAME_ELEMENT_FOG_MODE;
	const StringHash HASH_ELEMENT_PASS__FOG_MODE = 226326293;
	extern const char* NAME_ELEMENT_PASS__FOG_MODE;
	struct fog_mode__AttributeData
	{
		static const fog_mode__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FOG_START = 134185796;
	extern const char* NAME_ELEMENT_FOG_START;
	const StringHash HASH_ELEMENT_PASS__FOG_START = 134185796;
	extern const char* NAME_ELEMENT_PASS__FOG_START;
	struct fog_start__AttributeData
	{
		static const fog_start__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FOG_END = 198692708;
	extern const char* NAME_ELEMENT_FOG_END;
	const StringHash HASH_ELEMENT_PASS__FOG_END = 198692708;
	extern const char* NAME_ELEMENT_PASS__FOG_END;
	struct fog_end__AttributeData
	{
		static const fog_end__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FRONT_FACE = 215446933;
	extern const char* NAME_ELEMENT_FRONT_FACE;
	const StringHash HASH_ELEMENT_PASS__FRONT_FACE = 215446933;
	extern const char* NAME_ELEMENT_PASS__FRONT_FACE;
	struct front_face__AttributeData
	{
		static const front_face__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_PASS__TEXTURE_PIPELINE = 49503749;
	extern const char* NAME_ELEMENT_PASS__TEXTURE_PIPELINE;
	struct pass__texture_pipeline__AttributeData
	{
		static const pass__texture_pipeline__AttributeData DEFAULT;

		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_TEXTURE_PIPELINE__VALUE = 255798677;
	extern const char* NAME_ELEMENT_TEXTURE_PIPELINE__VALUE;
	struct texture_pipeline__value__AttributeData
	{
		static const texture_pipeline__value__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_VALUE__TEXCOMBINER = 43651570;
	extern const char* NAME_ELEMENT_VALUE__TEXCOMBINER;

	const StringHash HASH_ELEMENT_VALUE__TEXENV = 170873110;
	extern const char* NAME_ELEMENT_VALUE__TEXENV;
	struct value__texenv__AttributeData
	{
		static const value__texenv__AttributeData DEFAULT;

		const ParserChar* _operator;
		const ParserChar* unit;
	};

	const StringHash HASH_ELEMENT_VALUE__EXTRA = 76857393;
	extern const char* NAME_ELEMENT_VALUE__EXTRA;
	struct value__extra__AttributeData
	{
		static const value__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LOGIC_OP = 225896240;
	extern const char* NAME_ELEMENT_LOGIC_OP;
	const StringHash HASH_ELEMENT_PASS__LOGIC_OP = 225896240;
	extern const char* NAME_ELEMENT_PASS__LOGIC_OP;
	struct logic_op__AttributeData
	{
		static const logic_op__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_LIGHT_AMBIENT = 72324916;
	extern const char* NAME_ELEMENT_LIGHT_AMBIENT;
	const StringHash HASH_ELEMENT_PASS__LIGHT_AMBIENT = 72324916;
	extern const char* NAME_ELEMENT_PASS__LIGHT_AMBIENT;
	struct light_ambient__AttributeData
	{
		static const light_ambient__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_DIFFUSE = 244036085;
	extern const char* NAME_ELEMENT_LIGHT_DIFFUSE;
	const StringHash HASH_ELEMENT_PASS__LIGHT_DIFFUSE = 244036085;
	extern const char* NAME_ELEMENT_PASS__LIGHT_DIFFUSE;
	struct light_diffuse__AttributeData
	{
		static const light_diffuse__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_SPECULAR = 30177122;
	extern const char* NAME_ELEMENT_LIGHT_SPECULAR;
	const StringHash HASH_ELEMENT_PASS__LIGHT_SPECULAR = 30177122;
	extern const char* NAME_ELEMENT_PASS__LIGHT_SPECULAR;
	struct light_specular__AttributeData
	{
		static const light_specular__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_POSITION = 32930670;
	extern const char* NAME_ELEMENT_LIGHT_POSITION;
	const StringHash HASH_ELEMENT_PASS__LIGHT_POSITION = 32930670;
	extern const char* NAME_ELEMENT_PASS__LIGHT_POSITION;
	struct light_position__AttributeData
	{
		static const light_position__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_CONSTANT_ATTENUATION = 248277070;
	extern const char* NAME_ELEMENT_LIGHT_CONSTANT_ATTENUATION;
	const StringHash HASH_ELEMENT_PASS__LIGHT_CONSTANT_ATTENUATION = 248277070;
	extern const char* NAME_ELEMENT_PASS__LIGHT_CONSTANT_ATTENUATION;
	struct light_constant_attenuation__AttributeData
	{
		static const light_constant_attenuation__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_LINEAR_ATTENUTATION = 263246110;
	extern const char* NAME_ELEMENT_LIGHT_LINEAR_ATTENUTATION;
	const StringHash HASH_ELEMENT_PASS__LIGHT_LINEAR_ATTENUTATION = 263246110;
	extern const char* NAME_ELEMENT_PASS__LIGHT_LINEAR_ATTENUTATION;
	struct light_linear_attenutation__AttributeData
	{
		static const light_linear_attenutation__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_QUADRATIC_ATTENUATION = 204850382;
	extern const char* NAME_ELEMENT_LIGHT_QUADRATIC_ATTENUATION;
	const StringHash HASH_ELEMENT_PASS__LIGHT_QUADRATIC_ATTENUATION = 204850382;
	extern const char* NAME_ELEMENT_PASS__LIGHT_QUADRATIC_ATTENUATION;
	struct light_quadratic_attenuation__AttributeData
	{
		static const light_quadratic_attenuation__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_SPOT_CUTOFF = 150116294;
	extern const char* NAME_ELEMENT_LIGHT_SPOT_CUTOFF;
	const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_CUTOFF = 150116294;
	extern const char* NAME_ELEMENT_PASS__LIGHT_SPOT_CUTOFF;
	struct light_spot_cutoff__AttributeData
	{
		static const light_spot_cutoff__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_SPOT_DIRECTION = 177881278;
	extern const char* NAME_ELEMENT_LIGHT_SPOT_DIRECTION;
	const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_DIRECTION = 177881278;
	extern const char* NAME_ELEMENT_PASS__LIGHT_SPOT_DIRECTION;
	struct light_spot_direction__AttributeData
	{
		static const light_spot_direction__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_SPOT_EXPONENT = 22561988;
	extern const char* NAME_ELEMENT_LIGHT_SPOT_EXPONENT;
	const StringHash HASH_ELEMENT_PASS__LIGHT_SPOT_EXPONENT = 22561988;
	extern const char* NAME_ELEMENT_PASS__LIGHT_SPOT_EXPONENT;
	struct light_spot_exponent__AttributeData
	{
		static const light_spot_exponent__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHT_MODEL_AMBIENT = 1382244;
	extern const char* NAME_ELEMENT_LIGHT_MODEL_AMBIENT;
	const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_AMBIENT = 1382244;
	extern const char* NAME_ELEMENT_PASS__LIGHT_MODEL_AMBIENT;
	struct light_model_ambient__AttributeData
	{
		static const light_model_ambient__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_LINE_WIDTH = 71217992;
	extern const char* NAME_ELEMENT_LINE_WIDTH;
	const StringHash HASH_ELEMENT_PASS__LINE_WIDTH = 71217992;
	extern const char* NAME_ELEMENT_PASS__LINE_WIDTH;
	struct line_width__AttributeData
	{
		static const line_width__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MATERIAL_AMBIENT = 65325572;
	extern const char* NAME_ELEMENT_MATERIAL_AMBIENT;
	const StringHash HASH_ELEMENT_PASS__MATERIAL_AMBIENT = 65325572;
	extern const char* NAME_ELEMENT_PASS__MATERIAL_AMBIENT;
	struct material_ambient__AttributeData
	{
		static const material_ambient__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MATERIAL_DIFFUSE = 253816517;
	extern const char* NAME_ELEMENT_MATERIAL_DIFFUSE;
	const StringHash HASH_ELEMENT_PASS__MATERIAL_DIFFUSE = 253816517;
	extern const char* NAME_ELEMENT_PASS__MATERIAL_DIFFUSE;
	struct material_diffuse__AttributeData
	{
		static const material_diffuse__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MATERIAL_EMISSION = 264879022;
	extern const char* NAME_ELEMENT_MATERIAL_EMISSION;
	const StringHash HASH_ELEMENT_PASS__MATERIAL_EMISSION = 264879022;
	extern const char* NAME_ELEMENT_PASS__MATERIAL_EMISSION;
	struct material_emission__AttributeData
	{
		static const material_emission__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MATERIAL_SHININESS = 75374739;
	extern const char* NAME_ELEMENT_MATERIAL_SHININESS;
	const StringHash HASH_ELEMENT_PASS__MATERIAL_SHININESS = 75374739;
	extern const char* NAME_ELEMENT_PASS__MATERIAL_SHININESS;
	struct material_shininess__AttributeData
	{
		static const material_shininess__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MATERIAL_SPECULAR = 192521330;
	extern const char* NAME_ELEMENT_MATERIAL_SPECULAR;
	const StringHash HASH_ELEMENT_PASS__MATERIAL_SPECULAR = 192521330;
	extern const char* NAME_ELEMENT_PASS__MATERIAL_SPECULAR;
	struct material_specular__AttributeData
	{
		static const material_specular__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MODEL_VIEW_MATRIX = 23238152;
	extern const char* NAME_ELEMENT_MODEL_VIEW_MATRIX;
	const StringHash HASH_ELEMENT_PASS__MODEL_VIEW_MATRIX = 23238152;
	extern const char* NAME_ELEMENT_PASS__MODEL_VIEW_MATRIX;
	struct model_view_matrix__AttributeData
	{
		static const model_view_matrix__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POINT_DISTANCE_ATTENUATION = 220636846;
	extern const char* NAME_ELEMENT_POINT_DISTANCE_ATTENUATION;
	const StringHash HASH_ELEMENT_PASS__POINT_DISTANCE_ATTENUATION = 220636846;
	extern const char* NAME_ELEMENT_PASS__POINT_DISTANCE_ATTENUATION;
	struct point_distance_attenuation__AttributeData
	{
		static const point_distance_attenuation__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POINT_FADE_THRESHOLD_SIZE = 13010885;
	extern const char* NAME_ELEMENT_POINT_FADE_THRESHOLD_SIZE;
	const StringHash HASH_ELEMENT_PASS__POINT_FADE_THRESHOLD_SIZE = 13010885;
	extern const char* NAME_ELEMENT_PASS__POINT_FADE_THRESHOLD_SIZE;
	struct point_fade_threshold_size__AttributeData
	{
		static const point_fade_threshold_size__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POINT_SIZE = 215457381;
	extern const char* NAME_ELEMENT_POINT_SIZE;
	const StringHash HASH_ELEMENT_PASS__POINT_SIZE = 215457381;
	extern const char* NAME_ELEMENT_PASS__POINT_SIZE;
	struct point_size__AttributeData
	{
		static const point_size__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POINT_SIZE_MIN = 241669230;
	extern const char* NAME_ELEMENT_POINT_SIZE_MIN;
	const StringHash HASH_ELEMENT_PASS__POINT_SIZE_MIN = 241669230;
	extern const char* NAME_ELEMENT_PASS__POINT_SIZE_MIN;
	struct point_size_min__AttributeData
	{
		static const point_size_min__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POINT_SIZE_MAX = 241669144;
	extern const char* NAME_ELEMENT_POINT_SIZE_MAX;
	const StringHash HASH_ELEMENT_PASS__POINT_SIZE_MAX = 241669144;
	extern const char* NAME_ELEMENT_PASS__POINT_SIZE_MAX;
	struct point_size_max__AttributeData
	{
		static const point_size_max__AttributeData DEFAULT;

		float value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POLYGON_OFFSET = 214584564;
	extern const char* NAME_ELEMENT_POLYGON_OFFSET;
	const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET = 214584564;
	extern const char* NAME_ELEMENT_PASS__POLYGON_OFFSET;
	struct polygon_offset__AttributeData
	{
		static const polygon_offset__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_PROJECTION_MATRIX = 209936312;
	extern const char* NAME_ELEMENT_PROJECTION_MATRIX;
	const StringHash HASH_ELEMENT_PASS__PROJECTION_MATRIX = 209936312;
	extern const char* NAME_ELEMENT_PASS__PROJECTION_MATRIX;
	struct projection_matrix__AttributeData
	{
		static const projection_matrix__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_SCISSOR = 254426482;
	extern const char* NAME_ELEMENT_SCISSOR;
	const StringHash HASH_ELEMENT_PASS__SCISSOR = 254426482;
	extern const char* NAME_ELEMENT_PASS__SCISSOR;
	struct scissor__AttributeData
	{
		static const scissor__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_SHADE_MODEL = 6109180;
	extern const char* NAME_ELEMENT_SHADE_MODEL;
	const StringHash HASH_ELEMENT_PASS__SHADE_MODEL = 6109180;
	extern const char* NAME_ELEMENT_PASS__SHADE_MODEL;
	struct shade_model__AttributeData
	{
		static const shade_model__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_STENCIL_FUNC = 266860419;
	extern const char* NAME_ELEMENT_STENCIL_FUNC;
	const StringHash HASH_ELEMENT_PASS__STENCIL_FUNC = 266860419;
	extern const char* NAME_ELEMENT_PASS__STENCIL_FUNC;

	const StringHash HASH_ELEMENT_STENCIL_FUNC__FUNC = 43711635;
	extern const char* NAME_ELEMENT_STENCIL_FUNC__FUNC;
	struct stencil_func__func__AttributeData
	{
		static const stencil_func__func__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_REF = 220830390;
	extern const char* NAME_ELEMENT_REF;
	const StringHash HASH_ELEMENT_STENCIL_FUNC__REF = 220830390;
	extern const char* NAME_ELEMENT_STENCIL_FUNC__REF;
	struct stencil_func__ref__AttributeData
	{
		static const stencil_func__ref__AttributeData DEFAULT;

		unsigned short value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MASK = 43718731;
	extern const char* NAME_ELEMENT_MASK;
	const StringHash HASH_ELEMENT_STENCIL_FUNC__MASK = 43718731;
	extern const char* NAME_ELEMENT_STENCIL_FUNC__MASK;
	struct stencil_func__mask__AttributeData
	{
		static const stencil_func__mask__AttributeData DEFAULT;

		unsigned short value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_STENCIL_MASK = 266868059;
	extern const char* NAME_ELEMENT_STENCIL_MASK;
	const StringHash HASH_ELEMENT_PASS__STENCIL_MASK = 266868059;
	extern const char* NAME_ELEMENT_PASS__STENCIL_MASK;
	struct stencil_mask__AttributeData
	{
		static const stencil_mask__AttributeData DEFAULT;

		long value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_STENCIL_OP = 231729216;
	extern const char* NAME_ELEMENT_STENCIL_OP;
	const StringHash HASH_ELEMENT_PASS__STENCIL_OP = 231729216;
	extern const char* NAME_ELEMENT_PASS__STENCIL_OP;

	const StringHash HASH_ELEMENT_FAIL = 49026908;
	extern const char* NAME_ELEMENT_FAIL;
	const StringHash HASH_ELEMENT_STENCIL_OP__FAIL = 49026908;
	extern const char* NAME_ELEMENT_STENCIL_OP__FAIL;
	struct stencil_op__fail__AttributeData
	{
		static const stencil_op__fail__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_ZFAIL = 252562908;
	extern const char* NAME_ELEMENT_ZFAIL;
	const StringHash HASH_ELEMENT_STENCIL_OP__ZFAIL = 252562908;
	extern const char* NAME_ELEMENT_STENCIL_OP__ZFAIL;
	struct stencil_op__zfail__AttributeData
	{
		static const stencil_op__zfail__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_ZPASS = 252469891;
	extern const char* NAME_ELEMENT_ZPASS;
	const StringHash HASH_ELEMENT_STENCIL_OP__ZPASS = 252469891;
	extern const char* NAME_ELEMENT_STENCIL_OP__ZPASS;
	struct stencil_op__zpass__AttributeData
	{
		static const stencil_op__zpass__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_ALPHA_TEST_ENABLE = 34344917;
	extern const char* NAME_ELEMENT_ALPHA_TEST_ENABLE;
	const StringHash HASH_ELEMENT_PASS__ALPHA_TEST_ENABLE = 34344917;
	extern const char* NAME_ELEMENT_PASS__ALPHA_TEST_ENABLE;
	struct alpha_test_enable__AttributeData
	{
		static const alpha_test_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_BLEND_ENABLE = 123623157;
	extern const char* NAME_ELEMENT_BLEND_ENABLE;
	const StringHash HASH_ELEMENT_PASS__BLEND_ENABLE = 123623157;
	extern const char* NAME_ELEMENT_PASS__BLEND_ENABLE;
	struct blend_enable__AttributeData
	{
		static const blend_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CLIP_PLANE_ENABLE = 115779493;
	extern const char* NAME_ELEMENT_CLIP_PLANE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__CLIP_PLANE_ENABLE = 115779493;
	extern const char* NAME_ELEMENT_PASS__CLIP_PLANE_ENABLE;
	struct clip_plane_enable__AttributeData
	{
		static const clip_plane_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_COLOR_LOGIC_OP_ENABLE = 29904597;
	extern const char* NAME_ELEMENT_COLOR_LOGIC_OP_ENABLE;
	const StringHash HASH_ELEMENT_PASS__COLOR_LOGIC_OP_ENABLE = 29904597;
	extern const char* NAME_ELEMENT_PASS__COLOR_LOGIC_OP_ENABLE;
	struct color_logic_op_enable__AttributeData
	{
		static const color_logic_op_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_COLOR_MATERIAL_ENABLE = 111148709;
	extern const char* NAME_ELEMENT_COLOR_MATERIAL_ENABLE;
	const StringHash HASH_ELEMENT_PASS__COLOR_MATERIAL_ENABLE = 111148709;
	extern const char* NAME_ELEMENT_PASS__COLOR_MATERIAL_ENABLE;
	struct color_material_enable__AttributeData
	{
		static const color_material_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_CULL_FACE_ENABLE = 214615653;
	extern const char* NAME_ELEMENT_CULL_FACE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__CULL_FACE_ENABLE = 214615653;
	extern const char* NAME_ELEMENT_PASS__CULL_FACE_ENABLE;
	struct cull_face_enable__AttributeData
	{
		static const cull_face_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_DEPTH_TEST_ENABLE = 218300565;
	extern const char* NAME_ELEMENT_DEPTH_TEST_ENABLE;
	const StringHash HASH_ELEMENT_PASS__DEPTH_TEST_ENABLE = 218300565;
	extern const char* NAME_ELEMENT_PASS__DEPTH_TEST_ENABLE;
	struct depth_test_enable__AttributeData
	{
		static const depth_test_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_DITHER_ENABLE = 138674757;
	extern const char* NAME_ELEMENT_DITHER_ENABLE;
	const StringHash HASH_ELEMENT_PASS__DITHER_ENABLE = 138674757;
	extern const char* NAME_ELEMENT_PASS__DITHER_ENABLE;
	struct dither_enable__AttributeData
	{
		static const dither_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_FOG_ENABLE = 217499221;
	extern const char* NAME_ELEMENT_FOG_ENABLE;
	const StringHash HASH_ELEMENT_PASS__FOG_ENABLE = 217499221;
	extern const char* NAME_ELEMENT_PASS__FOG_ENABLE;
	struct fog_enable__AttributeData
	{
		static const fog_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_TEXTURE_PIPELINE_ENABLE = 177314229;
	extern const char* NAME_ELEMENT_TEXTURE_PIPELINE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__TEXTURE_PIPELINE_ENABLE = 177314229;
	extern const char* NAME_ELEMENT_PASS__TEXTURE_PIPELINE_ENABLE;
	struct texture_pipeline_enable__AttributeData
	{
		static const texture_pipeline_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_LIGHT_ENABLE = 117641205;
	extern const char* NAME_ELEMENT_LIGHT_ENABLE;
	const StringHash HASH_ELEMENT_PASS__LIGHT_ENABLE = 117641205;
	extern const char* NAME_ELEMENT_PASS__LIGHT_ENABLE;
	struct light_enable__AttributeData
	{
		static const light_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
		long long index;
	};

	const StringHash HASH_ELEMENT_LIGHTING_ENABLE = 48998885;
	extern const char* NAME_ELEMENT_LIGHTING_ENABLE;
	const StringHash HASH_ELEMENT_PASS__LIGHTING_ENABLE = 48998885;
	extern const char* NAME_ELEMENT_PASS__LIGHTING_ENABLE;
	struct lighting_enable__AttributeData
	{
		static const lighting_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE = 255891349;
	extern const char* NAME_ELEMENT_LIGHT_MODEL_TWO_SIDE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__LIGHT_MODEL_TWO_SIDE_ENABLE = 255891349;
	extern const char* NAME_ELEMENT_PASS__LIGHT_MODEL_TWO_SIDE_ENABLE;
	struct light_model_two_side_enable__AttributeData
	{
		static const light_model_two_side_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_LINE_SMOOTH_ENABLE = 239794133;
	extern const char* NAME_ELEMENT_LINE_SMOOTH_ENABLE;
	const StringHash HASH_ELEMENT_PASS__LINE_SMOOTH_ENABLE = 239794133;
	extern const char* NAME_ELEMENT_PASS__LINE_SMOOTH_ENABLE;
	struct line_smooth_enable__AttributeData
	{
		static const line_smooth_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_MULTISAMPLE_ENABLE = 266698789;
	extern const char* NAME_ELEMENT_MULTISAMPLE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__MULTISAMPLE_ENABLE = 266698789;
	extern const char* NAME_ELEMENT_PASS__MULTISAMPLE_ENABLE;
	struct multisample_enable__AttributeData
	{
		static const multisample_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_NORMALIZE_ENABLE = 261502853;
	extern const char* NAME_ELEMENT_NORMALIZE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__NORMALIZE_ENABLE = 261502853;
	extern const char* NAME_ELEMENT_PASS__NORMALIZE_ENABLE;
	struct normalize_enable__AttributeData
	{
		static const normalize_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POINT_SMOOTH_ENABLE = 206626965;
	extern const char* NAME_ELEMENT_POINT_SMOOTH_ENABLE;
	const StringHash HASH_ELEMENT_PASS__POINT_SMOOTH_ENABLE = 206626965;
	extern const char* NAME_ELEMENT_PASS__POINT_SMOOTH_ENABLE;
	struct point_smooth_enable__AttributeData
	{
		static const point_smooth_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_POLYGON_OFFSET_FILL_ENABLE = 53655765;
	extern const char* NAME_ELEMENT_POLYGON_OFFSET_FILL_ENABLE;
	const StringHash HASH_ELEMENT_PASS__POLYGON_OFFSET_FILL_ENABLE = 53655765;
	extern const char* NAME_ELEMENT_PASS__POLYGON_OFFSET_FILL_ENABLE;
	struct polygon_offset_fill_enable__AttributeData
	{
		static const polygon_offset_fill_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_RESCALE_NORMAL_ENABLE = 233340005;
	extern const char* NAME_ELEMENT_RESCALE_NORMAL_ENABLE;
	const StringHash HASH_ELEMENT_PASS__RESCALE_NORMAL_ENABLE = 233340005;
	extern const char* NAME_ELEMENT_PASS__RESCALE_NORMAL_ENABLE;
	struct rescale_normal_enable__AttributeData
	{
		static const rescale_normal_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 173355765;
	extern const char* NAME_ELEMENT_SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE = 173355765;
	extern const char* NAME_ELEMENT_PASS__SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
	struct sample_alpha_to_coverage_enable__AttributeData
	{
		static const sample_alpha_to_coverage_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE = 103906693;
	extern const char* NAME_ELEMENT_SAMPLE_ALPHA_TO_ONE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__SAMPLE_ALPHA_TO_ONE_ENABLE = 103906693;
	extern const char* NAME_ELEMENT_PASS__SAMPLE_ALPHA_TO_ONE_ENABLE;
	struct sample_alpha_to_one_enable__AttributeData
	{
		static const sample_alpha_to_one_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_SAMPLE_COVERAGE_ENABLE = 152395877;
	extern const char* NAME_ELEMENT_SAMPLE_COVERAGE_ENABLE;
	const StringHash HASH_ELEMENT_PASS__SAMPLE_COVERAGE_ENABLE = 152395877;
	extern const char* NAME_ELEMENT_PASS__SAMPLE_COVERAGE_ENABLE;
	struct sample_coverage_enable__AttributeData
	{
		static const sample_coverage_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_SCISSOR_TEST_ENABLE = 218403029;
	extern const char* NAME_ELEMENT_SCISSOR_TEST_ENABLE;
	const StringHash HASH_ELEMENT_PASS__SCISSOR_TEST_ENABLE = 218403029;
	extern const char* NAME_ELEMENT_PASS__SCISSOR_TEST_ENABLE;
	struct scissor_test_enable__AttributeData
	{
		static const scissor_test_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_STENCIL_TEST_ENABLE = 202141525;
	extern const char* NAME_ELEMENT_STENCIL_TEST_ENABLE;
	const StringHash HASH_ELEMENT_PASS__STENCIL_TEST_ENABLE = 202141525;
	extern const char* NAME_ELEMENT_PASS__STENCIL_TEST_ENABLE;
	struct stencil_test_enable__AttributeData
	{
		static const stencil_test_enable__AttributeData DEFAULT;

		const ParserChar* value;
		const ParserChar* param;
	};

	const StringHash HASH_ELEMENT_PASS__EXTRA = 86667537;
	extern const char* NAME_ELEMENT_PASS__EXTRA;
	struct pass__extra__AttributeData
	{
		static const pass__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__EXTRA = 202103745;
	extern const char* NAME_ELEMENT_TECHNIQUE__EXTRA;
	struct technique__extra__AttributeData
	{
		static const technique__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLES__EXTRA = 200483169;
	extern const char* NAME_ELEMENT_PROFILE_GLES__EXTRA;
	struct profile_GLES__extra__AttributeData
	{
		static const profile_GLES__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_FX_PROFILE_ABSTRACT = 70540052;
	extern const char* NAME_ELEMENT_FX_PROFILE_ABSTRACT;
	const StringHash HASH_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT = 70540052;
	extern const char* NAME_ELEMENT_EFFECT__FX_PROFILE_ABSTRACT;

	const StringHash HASH_ELEMENT_MESH = 53998040;
	extern const char* NAME_ELEMENT_MESH;
	const StringHash HASH_ELEMENT_GEOMETRY__MESH = 53998040;
	extern const char* NAME_ELEMENT_GEOMETRY__MESH;

	const StringHash HASH_ELEMENT_MESH__SOURCE = 28989125;
	extern const char* NAME_ELEMENT_MESH__SOURCE;
	struct mesh__source__AttributeData
	{
		static const mesh__source__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_VERTICES = 305203;
	extern const char* NAME_ELEMENT_VERTICES;
	const StringHash HASH_ELEMENT_MESH__VERTICES = 305203;
	extern const char* NAME_ELEMENT_MESH__VERTICES;
	struct mesh__vertices__AttributeData
	{
		static const mesh__vertices__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_VERTICES__INPUT = 250722196;
	extern const char* NAME_ELEMENT_VERTICES__INPUT;
	struct vertices__input__AttributeData
	{
		static const vertices__input__AttributeData DEFAULT;

		const ParserChar* semantic;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_VERTICES__EXTRA = 250813393;
	extern const char* NAME_ELEMENT_VERTICES__EXTRA;
	struct vertices__extra__AttributeData
	{
		static const vertices__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LINES = 87117091;
	extern const char* NAME_ELEMENT_LINES;
	const StringHash HASH_ELEMENT_MESH__LINES = 87117091;
	extern const char* NAME_ELEMENT_MESH__LINES;
	struct mesh__lines__AttributeData
	{
		static const mesh__lines__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_LINES__INPUT = 74455892;
	extern const char* NAME_ELEMENT_LINES__INPUT;
	struct lines__input__AttributeData
	{
		static const lines__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_LINES__P = 5018704;
	extern const char* NAME_ELEMENT_LINES__P;

	const StringHash HASH_ELEMENT_LINES__EXTRA = 74233617;
	extern const char* NAME_ELEMENT_LINES__EXTRA;
	struct lines__extra__AttributeData
	{
		static const lines__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LINESTRIPS = 49849507;
	extern const char* NAME_ELEMENT_LINESTRIPS;
	const StringHash HASH_ELEMENT_MESH__LINESTRIPS = 49849507;
	extern const char* NAME_ELEMENT_MESH__LINESTRIPS;
	struct mesh__linestrips__AttributeData
	{
		static const mesh__linestrips__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_LINESTRIPS__INPUT = 261379220;
	extern const char* NAME_ELEMENT_LINESTRIPS__INPUT;
	struct linestrips__input__AttributeData
	{
		static const linestrips__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_LINESTRIPS__P = 201547680;
	extern const char* NAME_ELEMENT_LINESTRIPS__P;

	const StringHash HASH_ELEMENT_LINESTRIPS__EXTRA = 261159121;
	extern const char* NAME_ELEMENT_LINESTRIPS__EXTRA;
	struct linestrips__extra__AttributeData
	{
		static const linestrips__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_POLYGONS = 178361651;
	extern const char* NAME_ELEMENT_POLYGONS;
	const StringHash HASH_ELEMENT_MESH__POLYGONS = 178361651;
	extern const char* NAME_ELEMENT_MESH__POLYGONS;
	struct mesh__polygons__AttributeData
	{
		static const mesh__polygons__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_POLYGONS__INPUT = 144860468;
	extern const char* NAME_ELEMENT_POLYGONS__INPUT;
	struct polygons__input__AttributeData
	{
		static const polygons__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

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
	struct polygons__extra__AttributeData
	{
		static const polygons__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_POLYLIST = 178422212;
	extern const char* NAME_ELEMENT_POLYLIST;
	const StringHash HASH_ELEMENT_MESH__POLYLIST = 178422212;
	extern const char* NAME_ELEMENT_MESH__POLYLIST;
	struct mesh__polylist__AttributeData
	{
		static const mesh__polylist__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_POLYLIST__INPUT = 22882756;
	extern const char* NAME_ELEMENT_POLYLIST__INPUT;
	struct polylist__input__AttributeData
	{
		static const polylist__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_VCOUNT = 117410884;
	extern const char* NAME_ELEMENT_VCOUNT;
	const StringHash HASH_ELEMENT_POLYLIST__VCOUNT = 117410884;
	extern const char* NAME_ELEMENT_POLYLIST__VCOUNT;

	const StringHash HASH_ELEMENT_POLYLIST__P = 58589536;
	extern const char* NAME_ELEMENT_POLYLIST__P;

	const StringHash HASH_ELEMENT_POLYLIST__EXTRA = 23037313;
	extern const char* NAME_ELEMENT_POLYLIST__EXTRA;
	struct polylist__extra__AttributeData
	{
		static const polylist__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_TRIANGLES = 111270531;
	extern const char* NAME_ELEMENT_TRIANGLES;
	const StringHash HASH_ELEMENT_MESH__TRIANGLES = 111270531;
	extern const char* NAME_ELEMENT_MESH__TRIANGLES;
	struct mesh__triangles__AttributeData
	{
		static const mesh__triangles__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_TRIANGLES__INPUT = 219530052;
	extern const char* NAME_ELEMENT_TRIANGLES__INPUT;
	struct triangles__input__AttributeData
	{
		static const triangles__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_TRIANGLES__P = 194284832;
	extern const char* NAME_ELEMENT_TRIANGLES__P;

	const StringHash HASH_ELEMENT_TRIANGLES__EXTRA = 219639553;
	extern const char* NAME_ELEMENT_TRIANGLES__EXTRA;
	struct triangles__extra__AttributeData
	{
		static const triangles__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct mesh__trifans__AttributeData
	{
		static const mesh__trifans__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_TRISTRIPS = 156149795;
	extern const char* NAME_ELEMENT_TRISTRIPS;
	const StringHash HASH_ELEMENT_MESH__TRISTRIPS = 156149795;
	extern const char* NAME_ELEMENT_MESH__TRISTRIPS;
	struct mesh__tristrips__AttributeData
	{
		static const mesh__tristrips__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_TRISTRIPS__INPUT = 262203732;
	extern const char* NAME_ELEMENT_TRISTRIPS__INPUT;
	struct tristrips__input__AttributeData
	{
		static const tristrips__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_TRISTRIPS__P = 12492704;
	extern const char* NAME_ELEMENT_TRISTRIPS__P;

	const StringHash HASH_ELEMENT_TRISTRIPS__EXTRA = 261899537;
	extern const char* NAME_ELEMENT_TRISTRIPS__EXTRA;
	struct tristrips__extra__AttributeData
	{
		static const tristrips__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_MESH__EXTRA = 86979169;
	extern const char* NAME_ELEMENT_MESH__EXTRA;
	struct mesh__extra__AttributeData
	{
		static const mesh__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct lines__AttributeData
	{
		static const lines__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

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
	struct instance_node__extra__AttributeData
	{
		static const instance_node__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_NODE = 252544101;
	extern const char* NAME_ELEMENT_NODE;
	const StringHash HASH_ELEMENT_VISUAL_SCENE__NODE = 252544101;
	extern const char* NAME_ELEMENT_VISUAL_SCENE__NODE;
	const StringHash HASH_ATTRIBUTE_LAYER = 7507906;
	extern const char* NAME_ATTRIBUTE_LAYER;
	struct visual_scene__node__AttributeData
	{
		static const visual_scene__node__AttributeData DEFAULT;

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
	struct node__rotate__AttributeData
	{
		static const node__rotate__AttributeData DEFAULT;

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
	struct node__translate__AttributeData
	{
		static const node__translate__AttributeData DEFAULT;

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
	struct instance_camera__extra__AttributeData
	{
		static const instance_camera__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct bind_material__param__AttributeData
	{
		static const bind_material__param__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* sid;
		const ParserChar* semantic;
		const ParserChar* type;
	};

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
		const ParserChar* input_set;
	};

	const StringHash HASH_ELEMENT_INSTANCE_MATERIAL__EXTRA = 238355617;
	extern const char* NAME_ELEMENT_INSTANCE_MATERIAL__EXTRA;
	struct instance_material__extra__AttributeData
	{
		static const instance_material__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_BIND_MATERIAL__TECHNIQUE = 185393301;
	extern const char* NAME_ELEMENT_BIND_MATERIAL__TECHNIQUE;
	struct bind_material__technique__AttributeData
	{
		static const bind_material__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_BIND_MATERIAL__EXTRA = 266234001;
	extern const char* NAME_ELEMENT_BIND_MATERIAL__EXTRA;
	struct bind_material__extra__AttributeData
	{
		static const bind_material__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_INSTANCE_CONTROLLER__EXTRA = 250294769;
	extern const char* NAME_ELEMENT_INSTANCE_CONTROLLER__EXTRA;
	struct instance_controller__extra__AttributeData
	{
		static const instance_controller__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY = 155287129;
	extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY;
	const StringHash HASH_ELEMENT_NODE__INSTANCE_GEOMETRY = 155287129;
	extern const char* NAME_ELEMENT_NODE__INSTANCE_GEOMETRY;
	struct node__instance_geometry__AttributeData
	{
		static const node__instance_geometry__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY__BIND_MATERIAL = 208059788;
	extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY__BIND_MATERIAL;

	const StringHash HASH_ELEMENT_INSTANCE_GEOMETRY__EXTRA = 79738161;
	extern const char* NAME_ELEMENT_INSTANCE_GEOMETRY__EXTRA;
	struct instance_geometry__extra__AttributeData
	{
		static const instance_geometry__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct instance_light__extra__AttributeData
	{
		static const instance_light__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_NODE__EXTRA = 86614321;
	extern const char* NAME_ELEMENT_NODE__EXTRA;
	struct node__extra__AttributeData
	{
		static const node__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	struct render__instance_effect__AttributeData
	{
		static const render__instance_effect__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_VISUAL_SCENE__EXTRA = 13625201;
	extern const char* NAME_ELEMENT_VISUAL_SCENE__EXTRA;
	struct visual_scene__extra__AttributeData
	{
		static const visual_scene__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_MATERIAL__INSTANCE_EFFECT = 179640868;
	extern const char* NAME_ELEMENT_MATERIAL__INSTANCE_EFFECT;
	struct material__instance_effect__AttributeData
	{
		static const material__instance_effect__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_MATERIAL__EXTRA = 261389857;
	extern const char* NAME_ELEMENT_MATERIAL__EXTRA;
	struct material__extra__AttributeData
	{
		static const material__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_CAPSULE = 117514469;
	extern const char* NAME_ELEMENT_CAPSULE;
	const StringHash HASH_ELEMENT_SHAPE__CAPSULE = 117514469;
	extern const char* NAME_ELEMENT_SHAPE__CAPSULE;

	const StringHash HASH_ELEMENT_HEIGHT = 38254884;
	extern const char* NAME_ELEMENT_HEIGHT;
	const StringHash HASH_ELEMENT_CAPSULE__HEIGHT = 38254884;
	extern const char* NAME_ELEMENT_CAPSULE__HEIGHT;

	const StringHash HASH_ELEMENT_RADIUS = 19657747;
	extern const char* NAME_ELEMENT_RADIUS;
	const StringHash HASH_ELEMENT_CAPSULE__RADIUS = 19657747;
	extern const char* NAME_ELEMENT_CAPSULE__RADIUS;

	const StringHash HASH_ELEMENT_CAPSULE__EXTRA = 220610497;
	extern const char* NAME_ELEMENT_CAPSULE__EXTRA;
	struct capsule__extra__AttributeData
	{
		static const capsule__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};


	const StringHash HASH_ELEMENT_ELLIPSOID = 50858436;
	extern const char* NAME_ELEMENT_ELLIPSOID;

	const StringHash HASH_ELEMENT_ELLIPSOID__SIZE = 190753477;
	extern const char* NAME_ELEMENT_ELLIPSOID__SIZE;

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

	const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD = 33737508;
	extern const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD;
	const StringHash HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD = 33737508;
	extern const char* NAME_ELEMENT_PHYSICS_SCENE__INSTANCE_FORCE_FIELD;
	struct physics_scene__instance_force_field__AttributeData
	{
		static const physics_scene__instance_force_field__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA = 267250353;
	extern const char* NAME_ELEMENT_INSTANCE_FORCE_FIELD__EXTRA;
	struct instance_force_field__extra__AttributeData
	{
		static const instance_force_field__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL = 16473708;
	extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL;
	const StringHash HASH_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL = 16473708;
	extern const char* NAME_ELEMENT_PHYSICS_SCENE__INSTANCE_PHYSICS_MODEL;
	const StringHash HASH_ATTRIBUTE_PARENT = 124292180;
	extern const char* NAME_ATTRIBUTE_PARENT;
	struct physics_scene__instance_physics_model__AttributeData
	{
		static const physics_scene__instance_physics_model__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
		const ParserChar* parent;
	};

	const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD = 38290564;
	extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__INSTANCE_FORCE_FIELD;
	struct instance_physics_model__instance_force_field__AttributeData
	{
		static const instance_physics_model__instance_force_field__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

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
	struct technique_common__mass__AttributeData
	{
		static const technique_common__mass__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_MASS_FRAME = 66755765;
	extern const char* NAME_ELEMENT_MASS_FRAME;
	const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME = 66755765;
	extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__MASS_FRAME;

	const StringHash HASH_ELEMENT_MASS_FRAME__TRANSLATE = 253554469;
	extern const char* NAME_ELEMENT_MASS_FRAME__TRANSLATE;
	struct mass_frame__translate__AttributeData
	{
		static const mass_frame__translate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_MASS_FRAME__ROTATE = 206978181;
	extern const char* NAME_ELEMENT_MASS_FRAME__ROTATE;
	struct mass_frame__rotate__AttributeData
	{
		static const mass_frame__rotate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

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
	struct technique_common__instance_physics_material__AttributeData
	{
		static const technique_common__instance_physics_material__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA = 49406769;
	extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MATERIAL__EXTRA;
	struct instance_physics_material__extra__AttributeData
	{
		static const instance_physics_material__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_PHYSICS_MATERIAL = 200496492;
	extern const char* NAME_ELEMENT_PHYSICS_MATERIAL;
	const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL = 200496492;
	extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__PHYSICS_MATERIAL;
	struct technique_common__physics_material__AttributeData
	{
		static const technique_common__physics_material__AttributeData DEFAULT;

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
	struct physics_material__technique__AttributeData
	{
		static const physics_material__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_PHYSICS_MATERIAL__EXTRA = 41184913;
	extern const char* NAME_ELEMENT_PHYSICS_MATERIAL__EXTRA;
	struct physics_material__extra__AttributeData
	{
		static const physics_material__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct shape__mass__AttributeData
	{
		static const shape__mass__AttributeData DEFAULT;

		const ParserChar* sid;
	};

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
	struct shape__instance_physics_material__AttributeData
	{
		static const shape__instance_physics_material__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_SHAPE__PHYSICS_MATERIAL = 169447724;
	extern const char* NAME_ELEMENT_SHAPE__PHYSICS_MATERIAL;
	struct shape__physics_material__AttributeData
	{
		static const shape__physics_material__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_SHAPE__INSTANCE_GEOMETRY = 15221321;
	extern const char* NAME_ELEMENT_SHAPE__INSTANCE_GEOMETRY;
	struct shape__instance_geometry__AttributeData
	{
		static const shape__instance_geometry__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

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
	struct plane__extra__AttributeData
	{
		static const plane__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct box__extra__AttributeData
	{
		static const box__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SPHERE = 256804805;
	extern const char* NAME_ELEMENT_SPHERE;
	const StringHash HASH_ELEMENT_SHAPE__SPHERE = 256804805;
	extern const char* NAME_ELEMENT_SHAPE__SPHERE;

	const StringHash HASH_ELEMENT_SPHERE__RADIUS = 7028275;
	extern const char* NAME_ELEMENT_SPHERE__RADIUS;

	const StringHash HASH_ELEMENT_SPHERE__EXTRA = 254948193;
	extern const char* NAME_ELEMENT_SPHERE__EXTRA;
	struct sphere__extra__AttributeData
	{
		static const sphere__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_CYLINDER = 138741378;
	extern const char* NAME_ELEMENT_CYLINDER;
	const StringHash HASH_ELEMENT_SHAPE__CYLINDER = 138741378;
	extern const char* NAME_ELEMENT_SHAPE__CYLINDER;

	const StringHash HASH_ELEMENT_CYLINDER__HEIGHT = 94864756;
	extern const char* NAME_ELEMENT_CYLINDER__HEIGHT;

	const StringHash HASH_ELEMENT_CYLINDER__RADIUS = 114026563;
	extern const char* NAME_ELEMENT_CYLINDER__RADIUS;

	const StringHash HASH_ELEMENT_CYLINDER__EXTRA = 140000257;
	extern const char* NAME_ELEMENT_CYLINDER__EXTRA;
	struct cylinder__extra__AttributeData
	{
		static const cylinder__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct tapered_cylinder__extra__AttributeData
	{
		static const tapered_cylinder__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct tapered_capsule__extra__AttributeData
	{
		static const tapered_capsule__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SHAPE__TRANSLATE = 49208741;
	extern const char* NAME_ELEMENT_SHAPE__TRANSLATE;
	struct shape__translate__AttributeData
	{
		static const shape__translate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SHAPE__ROTATE = 259965925;
	extern const char* NAME_ELEMENT_SHAPE__ROTATE;
	struct shape__rotate__AttributeData
	{
		static const shape__rotate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SHAPE__EXTRA = 79854897;
	extern const char* NAME_ELEMENT_SHAPE__EXTRA;
	struct shape__extra__AttributeData
	{
		static const shape__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE = 205322533;
	extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__TECHNIQUE;
	struct instance_rigid_body__technique__AttributeData
	{
		static const instance_rigid_body__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_INSTANCE_RIGID_BODY__EXTRA = 264756801;
	extern const char* NAME_ELEMENT_INSTANCE_RIGID_BODY__EXTRA;
	struct instance_rigid_body__extra__AttributeData
	{
		static const instance_rigid_body__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct instance_rigid_constraint__extra__AttributeData
	{
		static const instance_rigid_constraint__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA = 189441489;
	extern const char* NAME_ELEMENT_INSTANCE_PHYSICS_MODEL__EXTRA;
	struct instance_physics_model__extra__AttributeData
	{
		static const instance_physics_model__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct physics_scene__technique__AttributeData
	{
		static const physics_scene__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_PHYSICS_SCENE__EXTRA = 63742257;
	extern const char* NAME_ELEMENT_PHYSICS_SCENE__EXTRA;
	struct physics_scene__extra__AttributeData
	{
		static const physics_scene__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA = 112627697;
	extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_SCENES__EXTRA;
	struct library_physics_scenes__extra__AttributeData
	{
		static const library_physics_scenes__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_COLLADA__ASSET = 21558580;
	extern const char* NAME_ELEMENT_COLLADA__ASSET;

	const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS = 257283875;
	extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS;
	const StringHash HASH_ELEMENT_COLLADA__LIBRARY_ANIMATIONS = 257283875;
	extern const char* NAME_ELEMENT_COLLADA__LIBRARY_ANIMATIONS;
	struct library_animations__AttributeData
	{
		static const library_animations__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__ASSET = 39388324;
	extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__ASSET;

	const StringHash HASH_ELEMENT_LIBRARY_ANIMATIONS__EXTRA = 39671521;
	extern const char* NAME_ELEMENT_LIBRARY_ANIMATIONS__EXTRA;
	struct library_animations__extra__AttributeData
	{
		static const library_animations__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct instance_animation__AttributeData
	{
		static const instance_animation__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_INSTANCE_ANIMATION__EXTRA = 249155953;
	extern const char* NAME_ELEMENT_INSTANCE_ANIMATION__EXTRA;
	struct instance_animation__extra__AttributeData
	{
		static const instance_animation__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_ANIMATION_CLIP__EXTRA = 20841425;
	extern const char* NAME_ELEMENT_ANIMATION_CLIP__EXTRA;
	struct animation_clip__extra__AttributeData
	{
		static const animation_clip__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA = 227534545;
	extern const char* NAME_ELEMENT_LIBRARY_ANIMATION_CLIPS__EXTRA;
	struct library_animation_clips__extra__AttributeData
	{
		static const library_animation_clips__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct orthographic__aspect_ratio__AttributeData
	{
		static const orthographic__aspect_ratio__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_ZNEAR = 193810850;
	extern const char* NAME_ELEMENT_ZNEAR;
	const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZNEAR = 193810850;
	extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ZNEAR;
	struct orthographic__znear__AttributeData
	{
		static const orthographic__znear__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_ZFAR = 45665570;
	extern const char* NAME_ELEMENT_ZFAR;
	const StringHash HASH_ELEMENT_ORTHOGRAPHIC__ZFAR = 45665570;
	extern const char* NAME_ELEMENT_ORTHOGRAPHIC__ZFAR;
	struct orthographic__zfar__AttributeData
	{
		static const orthographic__zfar__AttributeData DEFAULT;

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
	struct perspective__aspect_ratio__AttributeData
	{
		static const perspective__aspect_ratio__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_PERSPECTIVE__ZNEAR = 163110226;
	extern const char* NAME_ELEMENT_PERSPECTIVE__ZNEAR;
	struct perspective__znear__AttributeData
	{
		static const perspective__znear__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_PERSPECTIVE__ZFAR = 228292066;
	extern const char* NAME_ELEMENT_PERSPECTIVE__ZFAR;
	struct perspective__zfar__AttributeData
	{
		static const perspective__zfar__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_OPTICS__TECHNIQUE = 49813749;
	extern const char* NAME_ELEMENT_OPTICS__TECHNIQUE;
	struct optics__technique__AttributeData
	{
		static const optics__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_OPTICS__EXTRA = 52822145;
	extern const char* NAME_ELEMENT_OPTICS__EXTRA;
	struct optics__extra__AttributeData
	{
		static const optics__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_IMAGER = 232782882;
	extern const char* NAME_ELEMENT_IMAGER;
	const StringHash HASH_ELEMENT_CAMERA__IMAGER = 232782882;
	extern const char* NAME_ELEMENT_CAMERA__IMAGER;

	const StringHash HASH_ELEMENT_IMAGER__TECHNIQUE = 100816341;
	extern const char* NAME_ELEMENT_IMAGER__TECHNIQUE;
	struct imager__technique__AttributeData
	{
		static const imager__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_IMAGER__EXTRA = 90908561;
	extern const char* NAME_ELEMENT_IMAGER__EXTRA;
	struct imager__extra__AttributeData
	{
		static const imager__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_CAMERA__EXTRA = 249508753;
	extern const char* NAME_ELEMENT_CAMERA__EXTRA;
	struct camera__extra__AttributeData
	{
		static const camera__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_CAMERAS__EXTRA = 99526945;
	extern const char* NAME_ELEMENT_LIBRARY_CAMERAS__EXTRA;
	struct library_cameras__extra__AttributeData
	{
		static const library_cameras__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct skin__source__AttributeData
	{
		static const skin__source__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_JOINTS = 62390755;
	extern const char* NAME_ELEMENT_JOINTS;
	const StringHash HASH_ELEMENT_SKIN__JOINTS = 62390755;
	extern const char* NAME_ELEMENT_SKIN__JOINTS;

	const StringHash HASH_ELEMENT_JOINTS__INPUT = 104860612;
	extern const char* NAME_ELEMENT_JOINTS__INPUT;
	struct joints__input__AttributeData
	{
		static const joints__input__AttributeData DEFAULT;

		const ParserChar* semantic;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_JOINTS__EXTRA = 104638337;
	extern const char* NAME_ELEMENT_JOINTS__EXTRA;
	struct joints__extra__AttributeData
	{
		static const joints__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_VERTEX_WEIGHTS = 52511411;
	extern const char* NAME_ELEMENT_VERTEX_WEIGHTS;
	const StringHash HASH_ELEMENT_SKIN__VERTEX_WEIGHTS = 52511411;
	extern const char* NAME_ELEMENT_SKIN__VERTEX_WEIGHTS;
	struct vertex_weights__AttributeData
	{
		static const vertex_weights__AttributeData DEFAULT;

		const ParserChar* count;
	};

	const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__INPUT = 118429284;
	extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__INPUT;
	struct vertex_weights__input__AttributeData
	{
		static const vertex_weights__input__AttributeData DEFAULT;

		const ParserChar* offset;
		const ParserChar* semantic;
		const ParserChar* source;
		const ParserChar* set;
	};

	const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__VCOUNT = 64909860;
	extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__VCOUNT;

	const StringHash HASH_ELEMENT_V = 21079862;
	extern const char* NAME_ELEMENT_V;
	const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__V = 21079862;
	extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__V;

	const StringHash HASH_ELEMENT_VERTEX_WEIGHTS__EXTRA = 118340129;
	extern const char* NAME_ELEMENT_VERTEX_WEIGHTS__EXTRA;
	struct vertex_weights__extra__AttributeData
	{
		static const vertex_weights__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SKIN__EXTRA = 86432705;
	extern const char* NAME_ELEMENT_SKIN__EXTRA;
	struct skin__extra__AttributeData
	{
		static const skin__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct morph__source__AttributeData
	{
		static const morph__source__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_TARGETS = 203307155;
	extern const char* NAME_ELEMENT_TARGETS;
	const StringHash HASH_ELEMENT_MORPH__TARGETS = 203307155;
	extern const char* NAME_ELEMENT_MORPH__TARGETS;

	const StringHash HASH_ELEMENT_TARGETS__INPUT = 231971828;
	extern const char* NAME_ELEMENT_TARGETS__INPUT;
	struct targets__input__AttributeData
	{
		static const targets__input__AttributeData DEFAULT;

		const ParserChar* semantic;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_TARGETS__EXTRA = 231815089;
	extern const char* NAME_ELEMENT_TARGETS__EXTRA;
	struct targets__extra__AttributeData
	{
		static const targets__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_MORPH__EXTRA = 68840801;
	extern const char* NAME_ELEMENT_MORPH__EXTRA;
	struct morph__extra__AttributeData
	{
		static const morph__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_CONTROLLER__EXTRA = 236302929;
	extern const char* NAME_ELEMENT_CONTROLLER__EXTRA;
	struct controller__extra__AttributeData
	{
		static const controller__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_CONTROLLERS__EXTRA = 84993665;
	extern const char* NAME_ELEMENT_LIBRARY_CONTROLLERS__EXTRA;
	struct library_controllers__extra__AttributeData
	{
		static const library_controllers__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct convex_mesh__source__AttributeData
	{
		static const convex_mesh__source__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__VERTICES = 97017683;
	extern const char* NAME_ELEMENT_CONVEX_MESH__VERTICES;
	struct convex_mesh__vertices__AttributeData
	{
		static const convex_mesh__vertices__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__LINES = 174551523;
	extern const char* NAME_ELEMENT_CONVEX_MESH__LINES;
	struct convex_mesh__lines__AttributeData
	{
		static const convex_mesh__lines__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__LINESTRIPS = 235800419;
	extern const char* NAME_ELEMENT_CONVEX_MESH__LINESTRIPS;
	struct convex_mesh__linestrips__AttributeData
	{
		static const convex_mesh__linestrips__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__POLYGONS = 225281043;
	extern const char* NAME_ELEMENT_CONVEX_MESH__POLYGONS;
	struct convex_mesh__polygons__AttributeData
	{
		static const convex_mesh__polygons__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__POLYLIST = 225351396;
	extern const char* NAME_ELEMENT_CONVEX_MESH__POLYLIST;
	struct convex_mesh__polylist__AttributeData
	{
		static const convex_mesh__polylist__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__TRIANGLES = 175033555;
	extern const char* NAME_ELEMENT_CONVEX_MESH__TRIANGLES;
	struct convex_mesh__triangles__AttributeData
	{
		static const convex_mesh__triangles__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__TRIFANS = 236645939;
	extern const char* NAME_ELEMENT_CONVEX_MESH__TRIFANS;
	struct convex_mesh__trifans__AttributeData
	{
		static const convex_mesh__trifans__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__TRISTRIPS = 92405331;
	extern const char* NAME_ELEMENT_CONVEX_MESH__TRISTRIPS;
	struct convex_mesh__tristrips__AttributeData
	{
		static const convex_mesh__tristrips__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_CONVEX_MESH__EXTRA = 173633185;
	extern const char* NAME_ELEMENT_CONVEX_MESH__EXTRA;
	struct convex_mesh__extra__AttributeData
	{
		static const convex_mesh__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SPLINE = 90991989;
	extern const char* NAME_ELEMENT_SPLINE;
	const StringHash HASH_ELEMENT_GEOMETRY__SPLINE = 90991989;
	extern const char* NAME_ELEMENT_GEOMETRY__SPLINE;
	const StringHash HASH_ATTRIBUTE_CLOSED = 111372724;
	extern const char* NAME_ATTRIBUTE_CLOSED;
	struct spline__AttributeData
	{
		static const spline__AttributeData DEFAULT;

		const ParserChar* closed;
	};

	const StringHash HASH_ELEMENT_SPLINE__SOURCE = 28739173;
	extern const char* NAME_ELEMENT_SPLINE__SOURCE;
	struct spline__source__AttributeData
	{
		static const spline__source__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_CONTROL_VERTICES = 152193299;
	extern const char* NAME_ELEMENT_CONTROL_VERTICES;
	const StringHash HASH_ELEMENT_SPLINE__CONTROL_VERTICES = 152193299;
	extern const char* NAME_ELEMENT_SPLINE__CONTROL_VERTICES;

	const StringHash HASH_ELEMENT_CONTROL_VERTICES__INPUT = 96321988;
	extern const char* NAME_ELEMENT_CONTROL_VERTICES__INPUT;
	struct control_vertices__input__AttributeData
	{
		static const control_vertices__input__AttributeData DEFAULT;

		const ParserChar* semantic;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_CONTROL_VERTICES__EXTRA = 96431489;
	extern const char* NAME_ELEMENT_CONTROL_VERTICES__EXTRA;
	struct control_vertices__extra__AttributeData
	{
		static const control_vertices__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SPLINE__EXTRA = 254803809;
	extern const char* NAME_ELEMENT_SPLINE__EXTRA;
	struct spline__extra__AttributeData
	{
		static const spline__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_GEOMETRY__EXTRA = 56635313;
	extern const char* NAME_ELEMENT_GEOMETRY__EXTRA;
	struct geometry__extra__AttributeData
	{
		static const geometry__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_GEOMETRIES__EXTRA = 104876513;
	extern const char* NAME_ELEMENT_LIBRARY_GEOMETRIES__EXTRA;
	struct library_geometries__extra__AttributeData
	{
		static const library_geometries__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_EFFECT__ANNOTATE = 17277301;
	extern const char* NAME_ELEMENT_EFFECT__ANNOTATE;
	struct effect__annotate__AttributeData
	{
		static const effect__annotate__AttributeData DEFAULT;

		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_EFFECT__IMAGE = 9735365;
	extern const char* NAME_ELEMENT_EFFECT__IMAGE;
	struct effect__image__AttributeData
	{
		static const effect__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_EFFECT__NEWPARAM = 123175677;
	extern const char* NAME_ELEMENT_EFFECT__NEWPARAM;
	struct effect__newparam__AttributeData
	{
		static const effect__newparam__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER1D = 11125956;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER1D;

	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER2D = 11126004;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER2D;

	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLER3D = 11125988;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLER3D;

	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERCUBE = 164043205;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERCUBE;

	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERRECT = 164034852;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERRECT;

	const StringHash HASH_ELEMENT_NEWPARAM__SAMPLERDEPTH = 208776984;
	extern const char* NAME_ELEMENT_NEWPARAM__SAMPLERDEPTH;

	const StringHash HASH_ELEMENT_EFFECT__EXTRA = 9453713;
	extern const char* NAME_ELEMENT_EFFECT__EXTRA;
	struct effect__extra__AttributeData
	{
		static const effect__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_EFFECTS__EXTRA = 18450993;
	extern const char* NAME_ELEMENT_LIBRARY_EFFECTS__EXTRA;
	struct library_effects__extra__AttributeData
	{
		static const library_effects__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct library_images__image__AttributeData
	{
		static const library_images__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_LIBRARY_IMAGES__EXTRA = 82037425;
	extern const char* NAME_ELEMENT_LIBRARY_IMAGES__EXTRA;
	struct library_images__extra__AttributeData
	{
		static const library_images__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct directional__color__AttributeData
	{
		static const directional__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_POINT = 173350644;
	extern const char* NAME_ELEMENT_POINT;
	const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__POINT = 173350644;
	extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__POINT;

	const StringHash HASH_ELEMENT_POINT__COLOR = 70281410;
	extern const char* NAME_ELEMENT_POINT__COLOR;
	struct point__color__AttributeData
	{
		static const point__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_CONSTANT_ATTENUATION = 98628030;
	extern const char* NAME_ELEMENT_CONSTANT_ATTENUATION;
	const StringHash HASH_ELEMENT_POINT__CONSTANT_ATTENUATION = 98628030;
	extern const char* NAME_ELEMENT_POINT__CONSTANT_ATTENUATION;
	struct point__constant_attenuation__AttributeData
	{
		static const point__constant_attenuation__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_LINEAR_ATTENUATION = 11535838;
	extern const char* NAME_ELEMENT_LINEAR_ATTENUATION;
	const StringHash HASH_ELEMENT_POINT__LINEAR_ATTENUATION = 11535838;
	extern const char* NAME_ELEMENT_POINT__LINEAR_ATTENUATION;
	struct point__linear_attenuation__AttributeData
	{
		static const point__linear_attenuation__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_QUADRATIC_ATTENUATION = 251429214;
	extern const char* NAME_ELEMENT_QUADRATIC_ATTENUATION;
	const StringHash HASH_ELEMENT_POINT__QUADRATIC_ATTENUATION = 251429214;
	extern const char* NAME_ELEMENT_POINT__QUADRATIC_ATTENUATION;
	struct point__quadratic_attenuation__AttributeData
	{
		static const point__quadratic_attenuation__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SPOT = 178619204;
	extern const char* NAME_ELEMENT_SPOT;
	const StringHash HASH_ELEMENT_TECHNIQUE_COMMON__SPOT = 178619204;
	extern const char* NAME_ELEMENT_TECHNIQUE_COMMON__SPOT;

	const StringHash HASH_ELEMENT_SPOT__COLOR = 86259138;
	extern const char* NAME_ELEMENT_SPOT__COLOR;
	struct spot__color__AttributeData
	{
		static const spot__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SPOT__CONSTANT_ATTENUATION = 248571118;
	extern const char* NAME_ELEMENT_SPOT__CONSTANT_ATTENUATION;
	struct spot__constant_attenuation__AttributeData
	{
		static const spot__constant_attenuation__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SPOT__LINEAR_ATTENUATION = 6894894;
	extern const char* NAME_ELEMENT_SPOT__LINEAR_ATTENUATION;
	struct spot__linear_attenuation__AttributeData
	{
		static const spot__linear_attenuation__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SPOT__QUADRATIC_ATTENUATION = 268275406;
	extern const char* NAME_ELEMENT_SPOT__QUADRATIC_ATTENUATION;
	struct spot__quadratic_attenuation__AttributeData
	{
		static const spot__quadratic_attenuation__AttributeData DEFAULT;

		const ParserChar* sid;
	};

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
	struct light__technique__AttributeData
	{
		static const light__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_LIGHT__EXTRA = 74654753;
	extern const char* NAME_ELEMENT_LIGHT__EXTRA;
	struct light__extra__AttributeData
	{
		static const light__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_LIGHTS__EXTRA = 2747857;
	extern const char* NAME_ELEMENT_LIBRARY_LIGHTS__EXTRA;
	struct library_lights__extra__AttributeData
	{
		static const library_lights__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_LIBRARY_MATERIALS__EXTRA = 117970993;
	extern const char* NAME_ELEMENT_LIBRARY_MATERIALS__EXTRA;
	struct library_materials__extra__AttributeData
	{
		static const library_materials__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_LIBRARY_NODES__NODE = 118269829;
	extern const char* NAME_ELEMENT_LIBRARY_NODES__NODE;
	struct library_nodes__node__AttributeData
	{
		static const library_nodes__node__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* sid;
		const ParserChar* type;
		const ParserChar* layer;
	};

	const StringHash HASH_ELEMENT_LIBRARY_NODES__EXTRA = 11655665;
	extern const char* NAME_ELEMENT_LIBRARY_NODES__EXTRA;
	struct library_nodes__extra__AttributeData
	{
		static const library_nodes__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL = 9537676;
	extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__PHYSICS_MATERIAL;
	struct library_physics_materials__physics_material__AttributeData
	{
		static const library_physics_materials__physics_material__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA = 207431569;
	extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MATERIALS__EXTRA;
	struct library_physics_materials__extra__AttributeData
	{
		static const library_physics_materials__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_RIGID_BODY__TECHNIQUE = 266093477;
	extern const char* NAME_ELEMENT_RIGID_BODY__TECHNIQUE;
	struct rigid_body__technique__AttributeData
	{
		static const rigid_body__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_RIGID_BODY__EXTRA = 259874209;
	extern const char* NAME_ELEMENT_RIGID_BODY__EXTRA;
	struct rigid_body__extra__AttributeData
	{
		static const rigid_body__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct ref_attachment__translate__AttributeData
	{
		static const ref_attachment__translate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_REF_ATTACHMENT__ROTATE = 172940933;
	extern const char* NAME_ELEMENT_REF_ATTACHMENT__ROTATE;
	struct ref_attachment__rotate__AttributeData
	{
		static const ref_attachment__rotate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_REF_ATTACHMENT__EXTRA = 43482337;
	extern const char* NAME_ELEMENT_REF_ATTACHMENT__EXTRA;
	struct ref_attachment__extra__AttributeData
	{
		static const ref_attachment__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct attachment__translate__AttributeData
	{
		static const attachment__translate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_ATTACHMENT__ROTATE = 256333637;
	extern const char* NAME_ELEMENT_ATTACHMENT__ROTATE;
	struct attachment__rotate__AttributeData
	{
		static const attachment__rotate__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_ATTACHMENT__EXTRA = 247981169;
	extern const char* NAME_ELEMENT_ATTACHMENT__EXTRA;
	struct attachment__extra__AttributeData
	{
		static const attachment__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct swing_cone_and_twist__min__AttributeData
	{
		static const swing_cone_and_twist__min__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_MAX = 185017832;
	extern const char* NAME_ELEMENT_MAX;
	const StringHash HASH_ELEMENT_SWING_CONE_AND_TWIST__MAX = 185017832;
	extern const char* NAME_ELEMENT_SWING_CONE_AND_TWIST__MAX;
	struct swing_cone_and_twist__max__AttributeData
	{
		static const swing_cone_and_twist__max__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_LINEAR = 108038914;
	extern const char* NAME_ELEMENT_LINEAR;
	const StringHash HASH_ELEMENT_LIMITS__LINEAR = 108038914;
	extern const char* NAME_ELEMENT_LIMITS__LINEAR;

	const StringHash HASH_ELEMENT_LINEAR__MIN = 135817038;
	extern const char* NAME_ELEMENT_LINEAR__MIN;
	struct linear__min__AttributeData
	{
		static const linear__min__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_LINEAR__MAX = 135817016;
	extern const char* NAME_ELEMENT_LINEAR__MAX;
	struct linear__max__AttributeData
	{
		static const linear__max__AttributeData DEFAULT;

		const ParserChar* sid;
	};

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
	struct angular__stiffness__AttributeData
	{
		static const angular__stiffness__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_DAMPING = 107704311;
	extern const char* NAME_ELEMENT_DAMPING;
	const StringHash HASH_ELEMENT_ANGULAR__DAMPING = 107704311;
	extern const char* NAME_ELEMENT_ANGULAR__DAMPING;
	struct angular__damping__AttributeData
	{
		static const angular__damping__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TARGET_VALUE = 33955429;
	extern const char* NAME_ELEMENT_TARGET_VALUE;
	const StringHash HASH_ELEMENT_ANGULAR__TARGET_VALUE = 33955429;
	extern const char* NAME_ELEMENT_ANGULAR__TARGET_VALUE;
	struct angular__target_value__AttributeData
	{
		static const angular__target_value__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SPRING__LINEAR = 62916466;
	extern const char* NAME_ELEMENT_SPRING__LINEAR;

	const StringHash HASH_ELEMENT_LINEAR__STIFFNESS = 131408563;
	extern const char* NAME_ELEMENT_LINEAR__STIFFNESS;
	struct linear__stiffness__AttributeData
	{
		static const linear__stiffness__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_LINEAR__DAMPING = 249329687;
	extern const char* NAME_ELEMENT_LINEAR__DAMPING;
	struct linear__damping__AttributeData
	{
		static const linear__damping__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_LINEAR__TARGET_VALUE = 9408485;
	extern const char* NAME_ELEMENT_LINEAR__TARGET_VALUE;
	struct linear__target_value__AttributeData
	{
		static const linear__target_value__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE = 71550805;
	extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__TECHNIQUE;
	struct rigid_constraint__technique__AttributeData
	{
		static const rigid_constraint__technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	const StringHash HASH_ELEMENT_RIGID_CONSTRAINT__EXTRA = 117024337;
	extern const char* NAME_ELEMENT_RIGID_CONSTRAINT__EXTRA;
	struct rigid_constraint__extra__AttributeData
	{
		static const rigid_constraint__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL = 133635772;
	extern const char* NAME_ELEMENT_PHYSICS_MODEL__INSTANCE_PHYSICS_MODEL;
	struct physics_model__instance_physics_model__AttributeData
	{
		static const physics_model__instance_physics_model__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
		const ParserChar* parent;
	};

	const StringHash HASH_ELEMENT_PHYSICS_MODEL__EXTRA = 51424673;
	extern const char* NAME_ELEMENT_PHYSICS_MODEL__EXTRA;
	struct physics_model__extra__AttributeData
	{
		static const physics_model__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA = 158621937;
	extern const char* NAME_ELEMENT_LIBRARY_PHYSICS_MODELS__EXTRA;
	struct library_physics_models__extra__AttributeData
	{
		static const library_physics_models__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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

	const StringHash HASH_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA = 115543569;
	extern const char* NAME_ELEMENT_LIBRARY_VISUAL_SCENES__EXTRA;
	struct library_visual_scenes__extra__AttributeData
	{
		static const library_visual_scenes__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct instance_physics_scene__extra__AttributeData
	{
		static const instance_physics_scene__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

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
	struct instance_visual_scene__extra__AttributeData
	{
		static const instance_visual_scene__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_SCENE__EXTRA = 80035633;
	extern const char* NAME_ELEMENT_SCENE__EXTRA;
	struct scene__extra__AttributeData
	{
		static const scene__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_COLLADA__EXTRA = 21800817;
	extern const char* NAME_ELEMENT_COLLADA__EXTRA;
	struct COLLADA__extra__AttributeData
	{
		static const COLLADA__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct param__AttributeData
	{
		static const param__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* sid;
		const ParserChar* semantic;
		const ParserChar* type;
	};

	struct instance_geometry__AttributeData
	{
		static const instance_geometry__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLSL = 99286140;
	extern const char* NAME_ELEMENT_PROFILE_GLSL;
	struct profile_GLSL__AttributeData
	{
		static const profile_GLSL__AttributeData DEFAULT;

		const ParserChar* id;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLSL__ASSET = 200761748;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__ASSET;

	const StringHash HASH_ELEMENT_CODE = 96434469;
	extern const char* NAME_ELEMENT_CODE;
	const StringHash HASH_ELEMENT_PROFILE_GLSL__CODE = 96434469;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__CODE;
	struct profile_GLSL__code__AttributeData
	{
		static const profile_GLSL__code__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_INCLUDE = 25321557;
	extern const char* NAME_ELEMENT_INCLUDE;
	const StringHash HASH_ELEMENT_PROFILE_GLSL__INCLUDE = 25321557;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__INCLUDE;
	struct profile_GLSL__include__AttributeData
	{
		static const profile_GLSL__include__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* url;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLSL__IMAGE = 200408965;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__IMAGE;
	struct profile_GLSL__image__AttributeData
	{
		static const profile_GLSL__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLSL__NEWPARAM = 6506701;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__NEWPARAM;
	struct profile_GLSL__newparam__AttributeData
	{
		static const profile_GLSL__newparam__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_ARRAY = 187722873;
	extern const char* NAME_ELEMENT_ARRAY;
	const StringHash HASH_ELEMENT_NEWPARAM__ARRAY = 187722873;
	extern const char* NAME_ELEMENT_NEWPARAM__ARRAY;
	const StringHash HASH_ATTRIBUTE_LENGTH = 120344232;
	extern const char* NAME_ATTRIBUTE_LENGTH;
	struct newparam__array__AttributeData
	{
		static const newparam__array__AttributeData DEFAULT;

		long length;
	};

	const StringHash HASH_ELEMENT_ARRAY__BOOL = 255667932;
	extern const char* NAME_ELEMENT_ARRAY__BOOL;

	const StringHash HASH_ELEMENT_ARRAY__BOOL2 = 64154882;
	extern const char* NAME_ELEMENT_ARRAY__BOOL2;

	const StringHash HASH_ELEMENT_ARRAY__BOOL3 = 64154883;
	extern const char* NAME_ELEMENT_ARRAY__BOOL3;

	const StringHash HASH_ELEMENT_ARRAY__BOOL4 = 64154884;
	extern const char* NAME_ELEMENT_ARRAY__BOOL4;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT = 64404852;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT2 = 225171266;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT2;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT3 = 225171267;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT3;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT4 = 225171268;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT4;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT2X2 = 198657234;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT2X2;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT3X3 = 198658003;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT3X3;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT4X4 = 198657748;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT4X4;

	const StringHash HASH_ELEMENT_ARRAY__INT = 150198228;
	extern const char* NAME_ELEMENT_ARRAY__INT;

	const StringHash HASH_ELEMENT_ARRAY__INT2 = 255688178;
	extern const char* NAME_ELEMENT_ARRAY__INT2;

	const StringHash HASH_ELEMENT_ARRAY__INT3 = 255688179;
	extern const char* NAME_ELEMENT_ARRAY__INT3;

	const StringHash HASH_ELEMENT_ARRAY__INT4 = 255688180;
	extern const char* NAME_ELEMENT_ARRAY__INT4;

	const StringHash HASH_ELEMENT_ARRAY__SURFACE = 54539381;
	extern const char* NAME_ELEMENT_ARRAY__SURFACE;
	struct array__surface__AttributeData
	{
		static const array__surface__AttributeData DEFAULT;

		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_GENERATOR = 181492914;
	extern const char* NAME_ELEMENT_GENERATOR;
	const StringHash HASH_ELEMENT_SURFACE__GENERATOR = 181492914;
	extern const char* NAME_ELEMENT_SURFACE__GENERATOR;

	const StringHash HASH_ELEMENT_GENERATOR__ANNOTATE = 233977093;
	extern const char* NAME_ELEMENT_GENERATOR__ANNOTATE;
	struct generator__annotate__AttributeData
	{
		static const generator__annotate__AttributeData DEFAULT;

		const ParserChar* name;
	};

	const StringHash HASH_ELEMENT_GENERATOR__CODE = 77434117;
	extern const char* NAME_ELEMENT_GENERATOR__CODE;
	struct generator__code__AttributeData
	{
		static const generator__code__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_GENERATOR__INCLUDE = 46428789;
	extern const char* NAME_ELEMENT_GENERATOR__INCLUDE;
	struct generator__include__AttributeData
	{
		static const generator__include__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* url;
	};

	const StringHash HASH_ELEMENT_NAME = 77508757;
	extern const char* NAME_ELEMENT_NAME;
	const StringHash HASH_ELEMENT_GENERATOR__NAME = 77508757;
	extern const char* NAME_ELEMENT_GENERATOR__NAME;
	struct generator__name__AttributeData
	{
		static const generator__name__AttributeData DEFAULT;

		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_GENERATOR__SETPARAM = 68294157;
	extern const char* NAME_ELEMENT_GENERATOR__SETPARAM;
	struct generator__setparam__AttributeData
	{
		static const generator__setparam__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_ARRAY__SAMPLER1D = 211887188;
	extern const char* NAME_ELEMENT_ARRAY__SAMPLER1D;

	const StringHash HASH_ELEMENT_ARRAY__SAMPLER2D = 211887204;
	extern const char* NAME_ELEMENT_ARRAY__SAMPLER2D;

	const StringHash HASH_ELEMENT_ARRAY__SAMPLER3D = 211887220;
	extern const char* NAME_ELEMENT_ARRAY__SAMPLER3D;

	const StringHash HASH_ELEMENT_ARRAY__SAMPLERCUBE = 19367365;
	extern const char* NAME_ELEMENT_ARRAY__SAMPLERCUBE;

	const StringHash HASH_ELEMENT_ARRAY__SAMPLERRECT = 19293476;
	extern const char* NAME_ELEMENT_ARRAY__SAMPLERRECT;

	const StringHash HASH_ELEMENT_ARRAY__SAMPLERDEPTH = 41447320;
	extern const char* NAME_ELEMENT_ARRAY__SAMPLERDEPTH;

	const StringHash HASH_ELEMENT_ARRAY__ENUM = 255671613;
	extern const char* NAME_ELEMENT_ARRAY__ENUM;

	const StringHash HASH_ELEMENT_ARRAY__ARRAY = 64032889;
	extern const char* NAME_ELEMENT_ARRAY__ARRAY;
	struct array__array__AttributeData
	{
		static const array__array__AttributeData DEFAULT;

		long length;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLSL__TECHNIQUE = 30461381;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__TECHNIQUE;
	struct profile_GLSL__technique__AttributeData
	{
		static const profile_GLSL__technique__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__CODE = 79755173;
	extern const char* NAME_ELEMENT_TECHNIQUE__CODE;
	struct technique__code__AttributeData
	{
		static const technique__code__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TECHNIQUE__INCLUDE = 157972389;
	extern const char* NAME_ELEMENT_TECHNIQUE__INCLUDE;
	struct technique__include__AttributeData
	{
		static const technique__include__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* url;
	};

	const StringHash HASH_ELEMENT_PROFILE_GLSL__EXTRA = 200487889;
	extern const char* NAME_ELEMENT_PROFILE_GLSL__EXTRA;
	struct profile_GLSL__extra__AttributeData
	{
		static const profile_GLSL__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct image__AttributeData
	{
		static const image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	struct instance_physics_model__AttributeData
	{
		static const instance_physics_model__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
		const ParserChar* parent;
	};

	struct physics_material__AttributeData
	{
		static const physics_material__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	struct linestrips__AttributeData
	{
		static const linestrips__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_GL_HOOK_ABSTRACT = 28530724;
	extern const char* NAME_ELEMENT_GL_HOOK_ABSTRACT;
	const StringHash HASH_ELEMENT_PASS__GL_HOOK_ABSTRACT = 28530724;
	extern const char* NAME_ELEMENT_PASS__GL_HOOK_ABSTRACT;

	struct node__AttributeData
	{
		static const node__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* sid;
		const ParserChar* type;
		const ParserChar* layer;
	};

	struct technique__AttributeData
	{
		static const technique__AttributeData DEFAULT;

		const ParserChar* profile;
	};

	struct tristrips__AttributeData
	{
		static const tristrips__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG = 218491431;
	extern const char* NAME_ELEMENT_PROFILE_CG;
	struct profile_CG__AttributeData
	{
		static const profile_CG__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* platform;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG__ASSET = 84282340;
	extern const char* NAME_ELEMENT_PROFILE_CG__ASSET;

	const StringHash HASH_ELEMENT_PROFILE_CG__CODE = 38834053;
	extern const char* NAME_ELEMENT_PROFILE_CG__CODE;
	struct profile_CG__code__AttributeData
	{
		static const profile_CG__code__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG__INCLUDE = 49028773;
	extern const char* NAME_ELEMENT_PROFILE_CG__INCLUDE;
	struct profile_CG__include__AttributeData
	{
		static const profile_CG__include__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* url;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG__IMAGE = 84055541;
	extern const char* NAME_ELEMENT_PROFILE_CG__IMAGE;
	struct profile_CG__image__AttributeData
	{
		static const profile_CG__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG__NEWPARAM = 113564125;
	extern const char* NAME_ELEMENT_PROFILE_CG__NEWPARAM;
	struct profile_CG__newparam__AttributeData
	{
		static const profile_CG__newparam__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_BOOL1 = 187805953;
	extern const char* NAME_ELEMENT_BOOL1;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL1 = 187805953;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL1;

	const StringHash HASH_ELEMENT_BOOL1X1 = 28377985;
	extern const char* NAME_ELEMENT_BOOL1X1;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X1 = 28377985;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X1;

	const StringHash HASH_ELEMENT_BOOL1X2 = 28377986;
	extern const char* NAME_ELEMENT_BOOL1X2;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X2 = 28377986;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X2;

	const StringHash HASH_ELEMENT_BOOL1X3 = 28377987;
	extern const char* NAME_ELEMENT_BOOL1X3;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X3 = 28377987;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X3;

	const StringHash HASH_ELEMENT_BOOL1X4 = 28377988;
	extern const char* NAME_ELEMENT_BOOL1X4;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL1X4 = 28377988;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL1X4;

	const StringHash HASH_ELEMENT_BOOL2X1 = 28377729;
	extern const char* NAME_ELEMENT_BOOL2X1;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X1 = 28377729;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X1;

	const StringHash HASH_ELEMENT_BOOL2X2 = 28377730;
	extern const char* NAME_ELEMENT_BOOL2X2;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X2 = 28377730;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X2;

	const StringHash HASH_ELEMENT_BOOL2X3 = 28377731;
	extern const char* NAME_ELEMENT_BOOL2X3;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X3 = 28377731;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X3;

	const StringHash HASH_ELEMENT_BOOL2X4 = 28377732;
	extern const char* NAME_ELEMENT_BOOL2X4;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL2X4 = 28377732;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL2X4;

	const StringHash HASH_ELEMENT_BOOL3X1 = 28377473;
	extern const char* NAME_ELEMENT_BOOL3X1;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X1 = 28377473;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X1;

	const StringHash HASH_ELEMENT_BOOL3X2 = 28377474;
	extern const char* NAME_ELEMENT_BOOL3X2;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X2 = 28377474;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X2;

	const StringHash HASH_ELEMENT_BOOL3X3 = 28377475;
	extern const char* NAME_ELEMENT_BOOL3X3;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X3 = 28377475;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X3;

	const StringHash HASH_ELEMENT_BOOL3X4 = 28377476;
	extern const char* NAME_ELEMENT_BOOL3X4;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL3X4 = 28377476;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL3X4;

	const StringHash HASH_ELEMENT_BOOL4X1 = 28377217;
	extern const char* NAME_ELEMENT_BOOL4X1;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X1 = 28377217;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X1;

	const StringHash HASH_ELEMENT_BOOL4X2 = 28377218;
	extern const char* NAME_ELEMENT_BOOL4X2;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X2 = 28377218;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X2;

	const StringHash HASH_ELEMENT_BOOL4X3 = 28377219;
	extern const char* NAME_ELEMENT_BOOL4X3;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X3 = 28377219;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X3;

	const StringHash HASH_ELEMENT_BOOL4X4 = 28377220;
	extern const char* NAME_ELEMENT_BOOL4X4;
	const StringHash HASH_ELEMENT_NEWPARAM__BOOL4X4 = 28377220;
	extern const char* NAME_ELEMENT_NEWPARAM__BOOL4X4;

	const StringHash HASH_ELEMENT_FLOAT1 = 56498113;
	extern const char* NAME_ELEMENT_FLOAT1;
	const StringHash HASH_ELEMENT_NEWPARAM__FLOAT1 = 56498113;
	extern const char* NAME_ELEMENT_NEWPARAM__FLOAT1;

	const StringHash HASH_ELEMENT_INT1 = 263424561;
	extern const char* NAME_ELEMENT_INT1;
	const StringHash HASH_ELEMENT_NEWPARAM__INT1 = 263424561;
	extern const char* NAME_ELEMENT_NEWPARAM__INT1;

	const StringHash HASH_ELEMENT_INT1X1 = 59389697;
	extern const char* NAME_ELEMENT_INT1X1;
	const StringHash HASH_ELEMENT_NEWPARAM__INT1X1 = 59389697;
	extern const char* NAME_ELEMENT_NEWPARAM__INT1X1;

	const StringHash HASH_ELEMENT_INT1X2 = 59389698;
	extern const char* NAME_ELEMENT_INT1X2;
	const StringHash HASH_ELEMENT_NEWPARAM__INT1X2 = 59389698;
	extern const char* NAME_ELEMENT_NEWPARAM__INT1X2;

	const StringHash HASH_ELEMENT_INT1X3 = 59389699;
	extern const char* NAME_ELEMENT_INT1X3;
	const StringHash HASH_ELEMENT_NEWPARAM__INT1X3 = 59389699;
	extern const char* NAME_ELEMENT_NEWPARAM__INT1X3;

	const StringHash HASH_ELEMENT_INT1X4 = 59389700;
	extern const char* NAME_ELEMENT_INT1X4;
	const StringHash HASH_ELEMENT_NEWPARAM__INT1X4 = 59389700;
	extern const char* NAME_ELEMENT_NEWPARAM__INT1X4;

	const StringHash HASH_ELEMENT_INT2X1 = 59389441;
	extern const char* NAME_ELEMENT_INT2X1;
	const StringHash HASH_ELEMENT_NEWPARAM__INT2X1 = 59389441;
	extern const char* NAME_ELEMENT_NEWPARAM__INT2X1;

	const StringHash HASH_ELEMENT_INT2X2 = 59389442;
	extern const char* NAME_ELEMENT_INT2X2;
	const StringHash HASH_ELEMENT_NEWPARAM__INT2X2 = 59389442;
	extern const char* NAME_ELEMENT_NEWPARAM__INT2X2;

	const StringHash HASH_ELEMENT_INT2X3 = 59389443;
	extern const char* NAME_ELEMENT_INT2X3;
	const StringHash HASH_ELEMENT_NEWPARAM__INT2X3 = 59389443;
	extern const char* NAME_ELEMENT_NEWPARAM__INT2X3;

	const StringHash HASH_ELEMENT_INT2X4 = 59389444;
	extern const char* NAME_ELEMENT_INT2X4;
	const StringHash HASH_ELEMENT_NEWPARAM__INT2X4 = 59389444;
	extern const char* NAME_ELEMENT_NEWPARAM__INT2X4;

	const StringHash HASH_ELEMENT_INT3X1 = 59389185;
	extern const char* NAME_ELEMENT_INT3X1;
	const StringHash HASH_ELEMENT_NEWPARAM__INT3X1 = 59389185;
	extern const char* NAME_ELEMENT_NEWPARAM__INT3X1;

	const StringHash HASH_ELEMENT_INT3X2 = 59389186;
	extern const char* NAME_ELEMENT_INT3X2;
	const StringHash HASH_ELEMENT_NEWPARAM__INT3X2 = 59389186;
	extern const char* NAME_ELEMENT_NEWPARAM__INT3X2;

	const StringHash HASH_ELEMENT_INT3X3 = 59389187;
	extern const char* NAME_ELEMENT_INT3X3;
	const StringHash HASH_ELEMENT_NEWPARAM__INT3X3 = 59389187;
	extern const char* NAME_ELEMENT_NEWPARAM__INT3X3;

	const StringHash HASH_ELEMENT_INT3X4 = 59389188;
	extern const char* NAME_ELEMENT_INT3X4;
	const StringHash HASH_ELEMENT_NEWPARAM__INT3X4 = 59389188;
	extern const char* NAME_ELEMENT_NEWPARAM__INT3X4;

	const StringHash HASH_ELEMENT_INT4X1 = 59388929;
	extern const char* NAME_ELEMENT_INT4X1;
	const StringHash HASH_ELEMENT_NEWPARAM__INT4X1 = 59388929;
	extern const char* NAME_ELEMENT_NEWPARAM__INT4X1;

	const StringHash HASH_ELEMENT_INT4X2 = 59388930;
	extern const char* NAME_ELEMENT_INT4X2;
	const StringHash HASH_ELEMENT_NEWPARAM__INT4X2 = 59388930;
	extern const char* NAME_ELEMENT_NEWPARAM__INT4X2;

	const StringHash HASH_ELEMENT_INT4X3 = 59388931;
	extern const char* NAME_ELEMENT_INT4X3;
	const StringHash HASH_ELEMENT_NEWPARAM__INT4X3 = 59388931;
	extern const char* NAME_ELEMENT_NEWPARAM__INT4X3;

	const StringHash HASH_ELEMENT_INT4X4 = 59388932;
	extern const char* NAME_ELEMENT_INT4X4;
	const StringHash HASH_ELEMENT_NEWPARAM__INT4X4 = 59388932;
	extern const char* NAME_ELEMENT_NEWPARAM__INT4X4;

	const StringHash HASH_ELEMENT_HALF = 263416166;
	extern const char* NAME_ELEMENT_HALF;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF = 263416166;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF;

	const StringHash HASH_ELEMENT_HALF1 = 188126817;
	extern const char* NAME_ELEMENT_HALF1;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF1 = 188126817;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF1;

	const StringHash HASH_ELEMENT_HALF2 = 188126818;
	extern const char* NAME_ELEMENT_HALF2;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF2 = 188126818;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF2;

	const StringHash HASH_ELEMENT_HALF3 = 188126819;
	extern const char* NAME_ELEMENT_HALF3;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF3 = 188126819;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF3;

	const StringHash HASH_ELEMENT_HALF4 = 188126820;
	extern const char* NAME_ELEMENT_HALF4;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF4 = 188126820;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF4;

	const StringHash HASH_ELEMENT_HALF1X1 = 110519169;
	extern const char* NAME_ELEMENT_HALF1X1;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF1X1 = 110519169;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF1X1;

	const StringHash HASH_ELEMENT_HALF1X2 = 110519170;
	extern const char* NAME_ELEMENT_HALF1X2;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF1X2 = 110519170;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF1X2;

	const StringHash HASH_ELEMENT_HALF1X3 = 110519171;
	extern const char* NAME_ELEMENT_HALF1X3;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF1X3 = 110519171;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF1X3;

	const StringHash HASH_ELEMENT_HALF1X4 = 110519172;
	extern const char* NAME_ELEMENT_HALF1X4;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF1X4 = 110519172;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF1X4;

	const StringHash HASH_ELEMENT_HALF2X1 = 110518913;
	extern const char* NAME_ELEMENT_HALF2X1;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF2X1 = 110518913;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF2X1;

	const StringHash HASH_ELEMENT_HALF2X2 = 110518914;
	extern const char* NAME_ELEMENT_HALF2X2;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF2X2 = 110518914;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF2X2;

	const StringHash HASH_ELEMENT_HALF2X3 = 110518915;
	extern const char* NAME_ELEMENT_HALF2X3;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF2X3 = 110518915;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF2X3;

	const StringHash HASH_ELEMENT_HALF2X4 = 110518916;
	extern const char* NAME_ELEMENT_HALF2X4;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF2X4 = 110518916;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF2X4;

	const StringHash HASH_ELEMENT_HALF3X1 = 110518657;
	extern const char* NAME_ELEMENT_HALF3X1;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF3X1 = 110518657;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF3X1;

	const StringHash HASH_ELEMENT_HALF3X2 = 110518658;
	extern const char* NAME_ELEMENT_HALF3X2;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF3X2 = 110518658;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF3X2;

	const StringHash HASH_ELEMENT_HALF3X3 = 110518659;
	extern const char* NAME_ELEMENT_HALF3X3;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF3X3 = 110518659;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF3X3;

	const StringHash HASH_ELEMENT_HALF3X4 = 110518660;
	extern const char* NAME_ELEMENT_HALF3X4;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF3X4 = 110518660;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF3X4;

	const StringHash HASH_ELEMENT_HALF4X1 = 110518401;
	extern const char* NAME_ELEMENT_HALF4X1;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF4X1 = 110518401;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF4X1;

	const StringHash HASH_ELEMENT_HALF4X2 = 110518402;
	extern const char* NAME_ELEMENT_HALF4X2;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF4X2 = 110518402;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF4X2;

	const StringHash HASH_ELEMENT_HALF4X3 = 110518403;
	extern const char* NAME_ELEMENT_HALF4X3;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF4X3 = 110518403;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF4X3;

	const StringHash HASH_ELEMENT_HALF4X4 = 110518404;
	extern const char* NAME_ELEMENT_HALF4X4;
	const StringHash HASH_ELEMENT_NEWPARAM__HALF4X4 = 110518404;
	extern const char* NAME_ELEMENT_NEWPARAM__HALF4X4;

	const StringHash HASH_ELEMENT_FIXED = 188086852;
	extern const char* NAME_ELEMENT_FIXED;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED = 188086852;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED;

	const StringHash HASH_ELEMENT_FIXED1 = 56599745;
	extern const char* NAME_ELEMENT_FIXED1;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED1 = 56599745;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED1;

	const StringHash HASH_ELEMENT_FIXED2 = 56599746;
	extern const char* NAME_ELEMENT_FIXED2;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED2 = 56599746;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED2;

	const StringHash HASH_ELEMENT_FIXED3 = 56599747;
	extern const char* NAME_ELEMENT_FIXED3;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED3 = 56599747;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED3;

	const StringHash HASH_ELEMENT_FIXED4 = 56599748;
	extern const char* NAME_ELEMENT_FIXED4;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED4 = 56599748;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED4;

	const StringHash HASH_ELEMENT_FIXED1X1 = 262458337;
	extern const char* NAME_ELEMENT_FIXED1X1;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X1 = 262458337;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X1;

	const StringHash HASH_ELEMENT_FIXED1X2 = 262458338;
	extern const char* NAME_ELEMENT_FIXED1X2;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X2 = 262458338;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X2;

	const StringHash HASH_ELEMENT_FIXED1X3 = 262458339;
	extern const char* NAME_ELEMENT_FIXED1X3;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X3 = 262458339;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X3;

	const StringHash HASH_ELEMENT_FIXED1X4 = 262458340;
	extern const char* NAME_ELEMENT_FIXED1X4;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED1X4 = 262458340;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED1X4;

	const StringHash HASH_ELEMENT_FIXED2X1 = 262458081;
	extern const char* NAME_ELEMENT_FIXED2X1;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X1 = 262458081;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X1;

	const StringHash HASH_ELEMENT_FIXED2X2 = 262458082;
	extern const char* NAME_ELEMENT_FIXED2X2;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X2 = 262458082;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X2;

	const StringHash HASH_ELEMENT_FIXED2X3 = 262458083;
	extern const char* NAME_ELEMENT_FIXED2X3;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X3 = 262458083;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X3;

	const StringHash HASH_ELEMENT_FIXED2X4 = 262458084;
	extern const char* NAME_ELEMENT_FIXED2X4;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED2X4 = 262458084;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED2X4;

	const StringHash HASH_ELEMENT_FIXED3X1 = 262457825;
	extern const char* NAME_ELEMENT_FIXED3X1;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X1 = 262457825;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X1;

	const StringHash HASH_ELEMENT_FIXED3X2 = 262457826;
	extern const char* NAME_ELEMENT_FIXED3X2;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X2 = 262457826;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X2;

	const StringHash HASH_ELEMENT_FIXED3X3 = 262457827;
	extern const char* NAME_ELEMENT_FIXED3X3;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X3 = 262457827;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X3;

	const StringHash HASH_ELEMENT_FIXED3X4 = 262457828;
	extern const char* NAME_ELEMENT_FIXED3X4;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED3X4 = 262457828;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED3X4;

	const StringHash HASH_ELEMENT_FIXED4X1 = 262457569;
	extern const char* NAME_ELEMENT_FIXED4X1;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X1 = 262457569;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X1;

	const StringHash HASH_ELEMENT_FIXED4X2 = 262457570;
	extern const char* NAME_ELEMENT_FIXED4X2;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X2 = 262457570;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X2;

	const StringHash HASH_ELEMENT_FIXED4X3 = 262457571;
	extern const char* NAME_ELEMENT_FIXED4X3;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X3 = 262457571;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X3;

	const StringHash HASH_ELEMENT_FIXED4X4 = 262457572;
	extern const char* NAME_ELEMENT_FIXED4X4;
	const StringHash HASH_ELEMENT_NEWPARAM__FIXED4X4 = 262457572;
	extern const char* NAME_ELEMENT_NEWPARAM__FIXED4X4;

	const StringHash HASH_ELEMENT_NEWPARAM__STRING = 2408951;
	extern const char* NAME_ELEMENT_NEWPARAM__STRING;

	const StringHash HASH_ELEMENT_USERTYPE = 109449253;
	extern const char* NAME_ELEMENT_USERTYPE;
	const StringHash HASH_ELEMENT_NEWPARAM__USERTYPE = 109449253;
	extern const char* NAME_ELEMENT_NEWPARAM__USERTYPE;
	struct newparam__usertype__AttributeData
	{
		static const newparam__usertype__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_USERTYPE__BOOL = 77353980;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL1 = 163921841;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL1;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL2 = 163921842;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL2;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL3 = 163921843;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL3;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL4 = 163921844;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL4;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL1X1 = 88060273;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL1X1;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL1X2 = 88060274;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL1X2;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL1X3 = 88060275;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL1X3;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL1X4 = 88060276;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL1X4;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL2X1 = 88060017;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL2X1;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL2X2 = 88060018;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL2X2;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL2X3 = 88060019;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL2X3;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL2X4 = 88060020;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL2X4;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL3X1 = 88060785;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL3X1;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL3X2 = 88060786;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL3X2;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL3X3 = 88060787;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL3X3;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL3X4 = 88060788;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL3X4;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL4X1 = 88060529;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL4X1;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL4X2 = 88060530;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL4X2;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL4X3 = 88060531;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL4X3;

	const StringHash HASH_ELEMENT_USERTYPE__BOOL4X4 = 88060532;
	extern const char* NAME_ELEMENT_USERTYPE__BOOL4X4;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT = 163672004;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT1 = 202833121;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT1;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT2 = 202833122;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT2;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT3 = 202833123;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT3;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT4 = 202833124;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT4;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X1 = 117236897;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT1X1;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X2 = 117236898;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT1X2;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X3 = 117236899;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT1X3;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT1X4 = 117236900;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT1X4;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X1 = 117237153;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT2X1;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X2 = 117237154;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT2X2;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X3 = 117237155;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT2X3;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT2X4 = 117237156;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT2X4;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X1 = 117237409;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT3X1;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X2 = 117237410;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT3X2;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X3 = 117237411;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT3X3;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT3X4 = 117237412;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT3X4;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X1 = 117237665;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT4X1;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X2 = 117237666;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT4X2;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X3 = 117237667;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT4X3;

	const StringHash HASH_ELEMENT_USERTYPE__FLOAT4X4 = 117237668;
	extern const char* NAME_ELEMENT_USERTYPE__FLOAT4X4;

	const StringHash HASH_ELEMENT_USERTYPE__INT = 172606500;
	extern const char* NAME_ELEMENT_USERTYPE__INT;

	const StringHash HASH_ELEMENT_USERTYPE__INT1 = 77349585;
	extern const char* NAME_ELEMENT_USERTYPE__INT1;

	const StringHash HASH_ELEMENT_USERTYPE__INT2 = 77349586;
	extern const char* NAME_ELEMENT_USERTYPE__INT2;

	const StringHash HASH_ELEMENT_USERTYPE__INT3 = 77349587;
	extern const char* NAME_ELEMENT_USERTYPE__INT3;

	const StringHash HASH_ELEMENT_USERTYPE__INT4 = 77349588;
	extern const char* NAME_ELEMENT_USERTYPE__INT4;

	const StringHash HASH_ELEMENT_USERTYPE__INT1X1 = 205708321;
	extern const char* NAME_ELEMENT_USERTYPE__INT1X1;

	const StringHash HASH_ELEMENT_USERTYPE__INT1X2 = 205708322;
	extern const char* NAME_ELEMENT_USERTYPE__INT1X2;

	const StringHash HASH_ELEMENT_USERTYPE__INT1X3 = 205708323;
	extern const char* NAME_ELEMENT_USERTYPE__INT1X3;

	const StringHash HASH_ELEMENT_USERTYPE__INT1X4 = 205708324;
	extern const char* NAME_ELEMENT_USERTYPE__INT1X4;

	const StringHash HASH_ELEMENT_USERTYPE__INT2X1 = 205708577;
	extern const char* NAME_ELEMENT_USERTYPE__INT2X1;

	const StringHash HASH_ELEMENT_USERTYPE__INT2X2 = 205708578;
	extern const char* NAME_ELEMENT_USERTYPE__INT2X2;

	const StringHash HASH_ELEMENT_USERTYPE__INT2X3 = 205708579;
	extern const char* NAME_ELEMENT_USERTYPE__INT2X3;

	const StringHash HASH_ELEMENT_USERTYPE__INT2X4 = 205708580;
	extern const char* NAME_ELEMENT_USERTYPE__INT2X4;

	const StringHash HASH_ELEMENT_USERTYPE__INT3X1 = 205708833;
	extern const char* NAME_ELEMENT_USERTYPE__INT3X1;

	const StringHash HASH_ELEMENT_USERTYPE__INT3X2 = 205708834;
	extern const char* NAME_ELEMENT_USERTYPE__INT3X2;

	const StringHash HASH_ELEMENT_USERTYPE__INT3X3 = 205708835;
	extern const char* NAME_ELEMENT_USERTYPE__INT3X3;

	const StringHash HASH_ELEMENT_USERTYPE__INT3X4 = 205708836;
	extern const char* NAME_ELEMENT_USERTYPE__INT3X4;

	const StringHash HASH_ELEMENT_USERTYPE__INT4X1 = 205709089;
	extern const char* NAME_ELEMENT_USERTYPE__INT4X1;

	const StringHash HASH_ELEMENT_USERTYPE__INT4X2 = 205709090;
	extern const char* NAME_ELEMENT_USERTYPE__INT4X2;

	const StringHash HASH_ELEMENT_USERTYPE__INT4X3 = 205709091;
	extern const char* NAME_ELEMENT_USERTYPE__INT4X3;

	const StringHash HASH_ELEMENT_USERTYPE__INT4X4 = 205709092;
	extern const char* NAME_ELEMENT_USERTYPE__INT4X4;

	const StringHash HASH_ELEMENT_USERTYPE__HALF = 77341062;
	extern const char* NAME_ELEMENT_USERTYPE__HALF;

	const StringHash HASH_ELEMENT_USERTYPE__HALF1 = 163715281;
	extern const char* NAME_ELEMENT_USERTYPE__HALF1;

	const StringHash HASH_ELEMENT_USERTYPE__HALF2 = 163715282;
	extern const char* NAME_ELEMENT_USERTYPE__HALF2;

	const StringHash HASH_ELEMENT_USERTYPE__HALF3 = 163715283;
	extern const char* NAME_ELEMENT_USERTYPE__HALF3;

	const StringHash HASH_ELEMENT_USERTYPE__HALF4 = 163715284;
	extern const char* NAME_ELEMENT_USERTYPE__HALF4;

	const StringHash HASH_ELEMENT_USERTYPE__HALF1X1 = 35180913;
	extern const char* NAME_ELEMENT_USERTYPE__HALF1X1;

	const StringHash HASH_ELEMENT_USERTYPE__HALF1X2 = 35180914;
	extern const char* NAME_ELEMENT_USERTYPE__HALF1X2;

	const StringHash HASH_ELEMENT_USERTYPE__HALF1X3 = 35180915;
	extern const char* NAME_ELEMENT_USERTYPE__HALF1X3;

	const StringHash HASH_ELEMENT_USERTYPE__HALF1X4 = 35180916;
	extern const char* NAME_ELEMENT_USERTYPE__HALF1X4;

	const StringHash HASH_ELEMENT_USERTYPE__HALF2X1 = 35180657;
	extern const char* NAME_ELEMENT_USERTYPE__HALF2X1;

	const StringHash HASH_ELEMENT_USERTYPE__HALF2X2 = 35180658;
	extern const char* NAME_ELEMENT_USERTYPE__HALF2X2;

	const StringHash HASH_ELEMENT_USERTYPE__HALF2X3 = 35180659;
	extern const char* NAME_ELEMENT_USERTYPE__HALF2X3;

	const StringHash HASH_ELEMENT_USERTYPE__HALF2X4 = 35180660;
	extern const char* NAME_ELEMENT_USERTYPE__HALF2X4;

	const StringHash HASH_ELEMENT_USERTYPE__HALF3X1 = 35181425;
	extern const char* NAME_ELEMENT_USERTYPE__HALF3X1;

	const StringHash HASH_ELEMENT_USERTYPE__HALF3X2 = 35181426;
	extern const char* NAME_ELEMENT_USERTYPE__HALF3X2;

	const StringHash HASH_ELEMENT_USERTYPE__HALF3X3 = 35181427;
	extern const char* NAME_ELEMENT_USERTYPE__HALF3X3;

	const StringHash HASH_ELEMENT_USERTYPE__HALF3X4 = 35181428;
	extern const char* NAME_ELEMENT_USERTYPE__HALF3X4;

	const StringHash HASH_ELEMENT_USERTYPE__HALF4X1 = 35181169;
	extern const char* NAME_ELEMENT_USERTYPE__HALF4X1;

	const StringHash HASH_ELEMENT_USERTYPE__HALF4X2 = 35181170;
	extern const char* NAME_ELEMENT_USERTYPE__HALF4X2;

	const StringHash HASH_ELEMENT_USERTYPE__HALF4X3 = 35181171;
	extern const char* NAME_ELEMENT_USERTYPE__HALF4X3;

	const StringHash HASH_ELEMENT_USERTYPE__HALF4X4 = 35181172;
	extern const char* NAME_ELEMENT_USERTYPE__HALF4X4;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED = 163673332;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED1 = 202854369;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED1;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED2 = 202854370;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED2;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED3 = 202854371;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED3;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED4 = 202854372;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED4;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED1X1 = 122676385;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED1X1;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED1X2 = 122676386;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED1X2;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED1X3 = 122676387;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED1X3;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED1X4 = 122676388;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED1X4;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED2X1 = 122676641;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED2X1;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED2X2 = 122676642;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED2X2;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED2X3 = 122676643;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED2X3;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED2X4 = 122676644;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED2X4;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED3X1 = 122676897;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED3X1;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED3X2 = 122676898;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED3X2;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED3X3 = 122676899;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED3X3;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED3X4 = 122676900;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED3X4;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED4X1 = 122677153;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED4X1;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED4X2 = 122677154;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED4X2;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED4X3 = 122677155;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED4X3;

	const StringHash HASH_ELEMENT_USERTYPE__FIXED4X4 = 122677156;
	extern const char* NAME_ELEMENT_USERTYPE__FIXED4X4;

	const StringHash HASH_ELEMENT_USERTYPE__SURFACE = 112365157;
	extern const char* NAME_ELEMENT_USERTYPE__SURFACE;
	struct usertype__surface__AttributeData
	{
		static const usertype__surface__AttributeData DEFAULT;

		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_USERTYPE__SAMPLER1D = 238760004;
	extern const char* NAME_ELEMENT_USERTYPE__SAMPLER1D;

	const StringHash HASH_ELEMENT_USERTYPE__SAMPLER2D = 238760052;
	extern const char* NAME_ELEMENT_USERTYPE__SAMPLER2D;

	const StringHash HASH_ELEMENT_USERTYPE__SAMPLER3D = 238760036;
	extern const char* NAME_ELEMENT_USERTYPE__SAMPLER3D;

	const StringHash HASH_ELEMENT_USERTYPE__SAMPLERRECT = 187856820;
	extern const char* NAME_ELEMENT_USERTYPE__SAMPLERRECT;

	const StringHash HASH_ELEMENT_USERTYPE__SAMPLERCUBE = 187930453;
	extern const char* NAME_ELEMENT_USERTYPE__SAMPLERCUBE;

	const StringHash HASH_ELEMENT_USERTYPE__SAMPLERDEPTH = 54085176;
	extern const char* NAME_ELEMENT_USERTYPE__SAMPLERDEPTH;

	const StringHash HASH_ELEMENT_USERTYPE__STRING = 258747607;
	extern const char* NAME_ELEMENT_USERTYPE__STRING;

	const StringHash HASH_ELEMENT_USERTYPE__ENUM = 77365789;
	extern const char* NAME_ELEMENT_USERTYPE__ENUM;

	const StringHash HASH_ELEMENT_USERTYPE__ARRAY = 163898057;
	extern const char* NAME_ELEMENT_USERTYPE__ARRAY;
	struct usertype__array__AttributeData
	{
		static const usertype__array__AttributeData DEFAULT;

		long length;
	};

	const StringHash HASH_ELEMENT_ARRAY__BOOL1 = 64154881;
	extern const char* NAME_ELEMENT_ARRAY__BOOL1;

	const StringHash HASH_ELEMENT_ARRAY__BOOL1X1 = 49089377;
	extern const char* NAME_ELEMENT_ARRAY__BOOL1X1;

	const StringHash HASH_ELEMENT_ARRAY__BOOL1X2 = 49089378;
	extern const char* NAME_ELEMENT_ARRAY__BOOL1X2;

	const StringHash HASH_ELEMENT_ARRAY__BOOL1X3 = 49089379;
	extern const char* NAME_ELEMENT_ARRAY__BOOL1X3;

	const StringHash HASH_ELEMENT_ARRAY__BOOL1X4 = 49089380;
	extern const char* NAME_ELEMENT_ARRAY__BOOL1X4;

	const StringHash HASH_ELEMENT_ARRAY__BOOL2X1 = 49089121;
	extern const char* NAME_ELEMENT_ARRAY__BOOL2X1;

	const StringHash HASH_ELEMENT_ARRAY__BOOL2X2 = 49089122;
	extern const char* NAME_ELEMENT_ARRAY__BOOL2X2;

	const StringHash HASH_ELEMENT_ARRAY__BOOL2X3 = 49089123;
	extern const char* NAME_ELEMENT_ARRAY__BOOL2X3;

	const StringHash HASH_ELEMENT_ARRAY__BOOL2X4 = 49089124;
	extern const char* NAME_ELEMENT_ARRAY__BOOL2X4;

	const StringHash HASH_ELEMENT_ARRAY__BOOL3X1 = 49088865;
	extern const char* NAME_ELEMENT_ARRAY__BOOL3X1;

	const StringHash HASH_ELEMENT_ARRAY__BOOL3X2 = 49088866;
	extern const char* NAME_ELEMENT_ARRAY__BOOL3X2;

	const StringHash HASH_ELEMENT_ARRAY__BOOL3X3 = 49088867;
	extern const char* NAME_ELEMENT_ARRAY__BOOL3X3;

	const StringHash HASH_ELEMENT_ARRAY__BOOL3X4 = 49088868;
	extern const char* NAME_ELEMENT_ARRAY__BOOL3X4;

	const StringHash HASH_ELEMENT_ARRAY__BOOL4X1 = 49088609;
	extern const char* NAME_ELEMENT_ARRAY__BOOL4X1;

	const StringHash HASH_ELEMENT_ARRAY__BOOL4X2 = 49088610;
	extern const char* NAME_ELEMENT_ARRAY__BOOL4X2;

	const StringHash HASH_ELEMENT_ARRAY__BOOL4X3 = 49088611;
	extern const char* NAME_ELEMENT_ARRAY__BOOL4X3;

	const StringHash HASH_ELEMENT_ARRAY__BOOL4X4 = 49088612;
	extern const char* NAME_ELEMENT_ARRAY__BOOL4X4;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT1 = 225171265;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT1;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT1X1 = 198657489;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT1X1;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT1X2 = 198657490;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT1X2;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT1X3 = 198657491;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT1X3;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT1X4 = 198657492;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT1X4;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT2X1 = 198657233;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT2X1;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT2X3 = 198657235;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT2X3;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT2X4 = 198657236;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT2X4;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT3X1 = 198658001;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT3X1;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT3X2 = 198658002;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT3X2;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT3X4 = 198658004;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT3X4;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT4X1 = 198657745;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT4X1;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT4X2 = 198657746;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT4X2;

	const StringHash HASH_ELEMENT_ARRAY__FLOAT4X3 = 198657747;
	extern const char* NAME_ELEMENT_ARRAY__FLOAT4X3;

	const StringHash HASH_ELEMENT_ARRAY__INT1 = 255688177;
	extern const char* NAME_ELEMENT_ARRAY__INT1;

	const StringHash HASH_ELEMENT_ARRAY__INT1X1 = 226359169;
	extern const char* NAME_ELEMENT_ARRAY__INT1X1;

	const StringHash HASH_ELEMENT_ARRAY__INT1X2 = 226359170;
	extern const char* NAME_ELEMENT_ARRAY__INT1X2;

	const StringHash HASH_ELEMENT_ARRAY__INT1X3 = 226359171;
	extern const char* NAME_ELEMENT_ARRAY__INT1X3;

	const StringHash HASH_ELEMENT_ARRAY__INT1X4 = 226359172;
	extern const char* NAME_ELEMENT_ARRAY__INT1X4;

	const StringHash HASH_ELEMENT_ARRAY__INT2X1 = 226358913;
	extern const char* NAME_ELEMENT_ARRAY__INT2X1;

	const StringHash HASH_ELEMENT_ARRAY__INT2X2 = 226358914;
	extern const char* NAME_ELEMENT_ARRAY__INT2X2;

	const StringHash HASH_ELEMENT_ARRAY__INT2X3 = 226358915;
	extern const char* NAME_ELEMENT_ARRAY__INT2X3;

	const StringHash HASH_ELEMENT_ARRAY__INT2X4 = 226358916;
	extern const char* NAME_ELEMENT_ARRAY__INT2X4;

	const StringHash HASH_ELEMENT_ARRAY__INT3X1 = 226358657;
	extern const char* NAME_ELEMENT_ARRAY__INT3X1;

	const StringHash HASH_ELEMENT_ARRAY__INT3X2 = 226358658;
	extern const char* NAME_ELEMENT_ARRAY__INT3X2;

	const StringHash HASH_ELEMENT_ARRAY__INT3X3 = 226358659;
	extern const char* NAME_ELEMENT_ARRAY__INT3X3;

	const StringHash HASH_ELEMENT_ARRAY__INT3X4 = 226358660;
	extern const char* NAME_ELEMENT_ARRAY__INT3X4;

	const StringHash HASH_ELEMENT_ARRAY__INT4X1 = 226358401;
	extern const char* NAME_ELEMENT_ARRAY__INT4X1;

	const StringHash HASH_ELEMENT_ARRAY__INT4X2 = 226358402;
	extern const char* NAME_ELEMENT_ARRAY__INT4X2;

	const StringHash HASH_ELEMENT_ARRAY__INT4X3 = 226358403;
	extern const char* NAME_ELEMENT_ARRAY__INT4X3;

	const StringHash HASH_ELEMENT_ARRAY__INT4X4 = 226358404;
	extern const char* NAME_ELEMENT_ARRAY__INT4X4;

	const StringHash HASH_ELEMENT_ARRAY__HALF = 255688870;
	extern const char* NAME_ELEMENT_ARRAY__HALF;

	const StringHash HASH_ELEMENT_ARRAY__HALF1 = 64490081;
	extern const char* NAME_ELEMENT_ARRAY__HALF1;

	const StringHash HASH_ELEMENT_ARRAY__HALF2 = 64490082;
	extern const char* NAME_ELEMENT_ARRAY__HALF2;

	const StringHash HASH_ELEMENT_ARRAY__HALF3 = 64490083;
	extern const char* NAME_ELEMENT_ARRAY__HALF3;

	const StringHash HASH_ELEMENT_ARRAY__HALF4 = 64490084;
	extern const char* NAME_ELEMENT_ARRAY__HALF4;

	const StringHash HASH_ELEMENT_ARRAY__HALF1X1 = 134900577;
	extern const char* NAME_ELEMENT_ARRAY__HALF1X1;

	const StringHash HASH_ELEMENT_ARRAY__HALF1X2 = 134900578;
	extern const char* NAME_ELEMENT_ARRAY__HALF1X2;

	const StringHash HASH_ELEMENT_ARRAY__HALF1X3 = 134900579;
	extern const char* NAME_ELEMENT_ARRAY__HALF1X3;

	const StringHash HASH_ELEMENT_ARRAY__HALF1X4 = 134900580;
	extern const char* NAME_ELEMENT_ARRAY__HALF1X4;

	const StringHash HASH_ELEMENT_ARRAY__HALF2X1 = 134900321;
	extern const char* NAME_ELEMENT_ARRAY__HALF2X1;

	const StringHash HASH_ELEMENT_ARRAY__HALF2X2 = 134900322;
	extern const char* NAME_ELEMENT_ARRAY__HALF2X2;

	const StringHash HASH_ELEMENT_ARRAY__HALF2X3 = 134900323;
	extern const char* NAME_ELEMENT_ARRAY__HALF2X3;

	const StringHash HASH_ELEMENT_ARRAY__HALF2X4 = 134900324;
	extern const char* NAME_ELEMENT_ARRAY__HALF2X4;

	const StringHash HASH_ELEMENT_ARRAY__HALF3X1 = 134900065;
	extern const char* NAME_ELEMENT_ARRAY__HALF3X1;

	const StringHash HASH_ELEMENT_ARRAY__HALF3X2 = 134900066;
	extern const char* NAME_ELEMENT_ARRAY__HALF3X2;

	const StringHash HASH_ELEMENT_ARRAY__HALF3X3 = 134900067;
	extern const char* NAME_ELEMENT_ARRAY__HALF3X3;

	const StringHash HASH_ELEMENT_ARRAY__HALF3X4 = 134900068;
	extern const char* NAME_ELEMENT_ARRAY__HALF3X4;

	const StringHash HASH_ELEMENT_ARRAY__HALF4X1 = 134899809;
	extern const char* NAME_ELEMENT_ARRAY__HALF4X1;

	const StringHash HASH_ELEMENT_ARRAY__HALF4X2 = 134899810;
	extern const char* NAME_ELEMENT_ARRAY__HALF4X2;

	const StringHash HASH_ELEMENT_ARRAY__HALF4X3 = 134899811;
	extern const char* NAME_ELEMENT_ARRAY__HALF4X3;

	const StringHash HASH_ELEMENT_ARRAY__HALF4X4 = 134899812;
	extern const char* NAME_ELEMENT_ARRAY__HALF4X4;

	const StringHash HASH_ELEMENT_ARRAY__FIXED = 64390724;
	extern const char* NAME_ELEMENT_ARRAY__FIXED;

	const StringHash HASH_ELEMENT_ARRAY__FIXED1 = 224945217;
	extern const char* NAME_ELEMENT_ARRAY__FIXED1;

	const StringHash HASH_ELEMENT_ARRAY__FIXED2 = 224945218;
	extern const char* NAME_ELEMENT_ARRAY__FIXED2;

	const StringHash HASH_ELEMENT_ARRAY__FIXED3 = 224945219;
	extern const char* NAME_ELEMENT_ARRAY__FIXED3;

	const StringHash HASH_ELEMENT_ARRAY__FIXED4 = 224945220;
	extern const char* NAME_ELEMENT_ARRAY__FIXED4;

	const StringHash HASH_ELEMENT_ARRAY__FIXED1X1 = 140789201;
	extern const char* NAME_ELEMENT_ARRAY__FIXED1X1;

	const StringHash HASH_ELEMENT_ARRAY__FIXED1X2 = 140789202;
	extern const char* NAME_ELEMENT_ARRAY__FIXED1X2;

	const StringHash HASH_ELEMENT_ARRAY__FIXED1X3 = 140789203;
	extern const char* NAME_ELEMENT_ARRAY__FIXED1X3;

	const StringHash HASH_ELEMENT_ARRAY__FIXED1X4 = 140789204;
	extern const char* NAME_ELEMENT_ARRAY__FIXED1X4;

	const StringHash HASH_ELEMENT_ARRAY__FIXED2X1 = 140788945;
	extern const char* NAME_ELEMENT_ARRAY__FIXED2X1;

	const StringHash HASH_ELEMENT_ARRAY__FIXED2X2 = 140788946;
	extern const char* NAME_ELEMENT_ARRAY__FIXED2X2;

	const StringHash HASH_ELEMENT_ARRAY__FIXED2X3 = 140788947;
	extern const char* NAME_ELEMENT_ARRAY__FIXED2X3;

	const StringHash HASH_ELEMENT_ARRAY__FIXED2X4 = 140788948;
	extern const char* NAME_ELEMENT_ARRAY__FIXED2X4;

	const StringHash HASH_ELEMENT_ARRAY__FIXED3X1 = 140789713;
	extern const char* NAME_ELEMENT_ARRAY__FIXED3X1;

	const StringHash HASH_ELEMENT_ARRAY__FIXED3X2 = 140789714;
	extern const char* NAME_ELEMENT_ARRAY__FIXED3X2;

	const StringHash HASH_ELEMENT_ARRAY__FIXED3X3 = 140789715;
	extern const char* NAME_ELEMENT_ARRAY__FIXED3X3;

	const StringHash HASH_ELEMENT_ARRAY__FIXED3X4 = 140789716;
	extern const char* NAME_ELEMENT_ARRAY__FIXED3X4;

	const StringHash HASH_ELEMENT_ARRAY__FIXED4X1 = 140789457;
	extern const char* NAME_ELEMENT_ARRAY__FIXED4X1;

	const StringHash HASH_ELEMENT_ARRAY__FIXED4X2 = 140789458;
	extern const char* NAME_ELEMENT_ARRAY__FIXED4X2;

	const StringHash HASH_ELEMENT_ARRAY__FIXED4X3 = 140789459;
	extern const char* NAME_ELEMENT_ARRAY__FIXED4X3;

	const StringHash HASH_ELEMENT_ARRAY__FIXED4X4 = 140789460;
	extern const char* NAME_ELEMENT_ARRAY__FIXED4X4;

	const StringHash HASH_ELEMENT_ARRAY__STRING = 238223735;
	extern const char* NAME_ELEMENT_ARRAY__STRING;

	const StringHash HASH_ELEMENT_ARRAY__USERTYPE = 21405237;
	extern const char* NAME_ELEMENT_ARRAY__USERTYPE;
	struct array__usertype__AttributeData
	{
		static const array__usertype__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_USERTYPE__USERTYPE = 242040677;
	extern const char* NAME_ELEMENT_USERTYPE__USERTYPE;
	struct usertype__usertype__AttributeData
	{
		static const usertype__usertype__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_CONNECT_PARAM = 5868045;
	extern const char* NAME_ELEMENT_CONNECT_PARAM;
	const StringHash HASH_ELEMENT_USERTYPE__CONNECT_PARAM = 5868045;
	extern const char* NAME_ELEMENT_USERTYPE__CONNECT_PARAM;
	struct usertype__connect_param__AttributeData
	{
		static const usertype__connect_param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_USERTYPE__SETPARAM = 185734957;
	extern const char* NAME_ELEMENT_USERTYPE__SETPARAM;
	const StringHash HASH_ATTRIBUTE_PROGRAM = 127264781;
	extern const char* NAME_ATTRIBUTE_PROGRAM;
	struct usertype__setparam__AttributeData
	{
		static const usertype__setparam__AttributeData DEFAULT;

		const ParserChar* ref;
		const ParserChar* program;
	};

	const StringHash HASH_ELEMENT_SETPARAM__BOOL1 = 3302897;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL1;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL1X1 = 40237185;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL1X1;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL1X2 = 40237186;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL1X2;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL1X3 = 40237187;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL1X3;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL1X4 = 40237188;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL1X4;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL2X1 = 40237441;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL2X1;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL2X2 = 40237442;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL2X2;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL2X3 = 40237443;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL2X3;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL2X4 = 40237444;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL2X4;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL3X1 = 40237697;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL3X1;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL3X2 = 40237698;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL3X2;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL3X3 = 40237699;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL3X3;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL3X4 = 40237700;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL3X4;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL4X1 = 40237953;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL4X1;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL4X2 = 40237954;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL4X2;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL4X3 = 40237955;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL4X3;

	const StringHash HASH_ELEMENT_SETPARAM__BOOL4X4 = 40237956;
	extern const char* NAME_ELEMENT_SETPARAM__BOOL4X4;

	const StringHash HASH_ELEMENT_SETPARAM__FLOAT1 = 56842353;
	extern const char* NAME_ELEMENT_SETPARAM__FLOAT1;

	const StringHash HASH_ELEMENT_SETPARAM__INT1 = 226673;
	extern const char* NAME_ELEMENT_SETPARAM__INT1;

	const StringHash HASH_ELEMENT_SETPARAM__INT1X1 = 58030257;
	extern const char* NAME_ELEMENT_SETPARAM__INT1X1;

	const StringHash HASH_ELEMENT_SETPARAM__INT1X2 = 58030258;
	extern const char* NAME_ELEMENT_SETPARAM__INT1X2;

	const StringHash HASH_ELEMENT_SETPARAM__INT1X3 = 58030259;
	extern const char* NAME_ELEMENT_SETPARAM__INT1X3;

	const StringHash HASH_ELEMENT_SETPARAM__INT1X4 = 58030260;
	extern const char* NAME_ELEMENT_SETPARAM__INT1X4;

	const StringHash HASH_ELEMENT_SETPARAM__INT2X1 = 58030513;
	extern const char* NAME_ELEMENT_SETPARAM__INT2X1;

	const StringHash HASH_ELEMENT_SETPARAM__INT2X2 = 58030514;
	extern const char* NAME_ELEMENT_SETPARAM__INT2X2;

	const StringHash HASH_ELEMENT_SETPARAM__INT2X3 = 58030515;
	extern const char* NAME_ELEMENT_SETPARAM__INT2X3;

	const StringHash HASH_ELEMENT_SETPARAM__INT2X4 = 58030516;
	extern const char* NAME_ELEMENT_SETPARAM__INT2X4;

	const StringHash HASH_ELEMENT_SETPARAM__INT3X1 = 58030769;
	extern const char* NAME_ELEMENT_SETPARAM__INT3X1;

	const StringHash HASH_ELEMENT_SETPARAM__INT3X2 = 58030770;
	extern const char* NAME_ELEMENT_SETPARAM__INT3X2;

	const StringHash HASH_ELEMENT_SETPARAM__INT3X3 = 58030771;
	extern const char* NAME_ELEMENT_SETPARAM__INT3X3;

	const StringHash HASH_ELEMENT_SETPARAM__INT3X4 = 58030772;
	extern const char* NAME_ELEMENT_SETPARAM__INT3X4;

	const StringHash HASH_ELEMENT_SETPARAM__INT4X1 = 58031025;
	extern const char* NAME_ELEMENT_SETPARAM__INT4X1;

	const StringHash HASH_ELEMENT_SETPARAM__INT4X2 = 58031026;
	extern const char* NAME_ELEMENT_SETPARAM__INT4X2;

	const StringHash HASH_ELEMENT_SETPARAM__INT4X3 = 58031027;
	extern const char* NAME_ELEMENT_SETPARAM__INT4X3;

	const StringHash HASH_ELEMENT_SETPARAM__INT4X4 = 58031028;
	extern const char* NAME_ELEMENT_SETPARAM__INT4X4;

	const StringHash HASH_ELEMENT_SETPARAM__HALF = 227366;
	extern const char* NAME_ELEMENT_SETPARAM__HALF;

	const StringHash HASH_ELEMENT_SETPARAM__HALF1 = 3637905;
	extern const char* NAME_ELEMENT_SETPARAM__HALF1;

	const StringHash HASH_ELEMENT_SETPARAM__HALF2 = 3637906;
	extern const char* NAME_ELEMENT_SETPARAM__HALF2;

	const StringHash HASH_ELEMENT_SETPARAM__HALF3 = 3637907;
	extern const char* NAME_ELEMENT_SETPARAM__HALF3;

	const StringHash HASH_ELEMENT_SETPARAM__HALF4 = 3637908;
	extern const char* NAME_ELEMENT_SETPARAM__HALF4;

	const StringHash HASH_ELEMENT_SETPARAM__HALF1X1 = 125999233;
	extern const char* NAME_ELEMENT_SETPARAM__HALF1X1;

	const StringHash HASH_ELEMENT_SETPARAM__HALF1X2 = 125999234;
	extern const char* NAME_ELEMENT_SETPARAM__HALF1X2;

	const StringHash HASH_ELEMENT_SETPARAM__HALF1X3 = 125999235;
	extern const char* NAME_ELEMENT_SETPARAM__HALF1X3;

	const StringHash HASH_ELEMENT_SETPARAM__HALF1X4 = 125999236;
	extern const char* NAME_ELEMENT_SETPARAM__HALF1X4;

	const StringHash HASH_ELEMENT_SETPARAM__HALF2X1 = 125999489;
	extern const char* NAME_ELEMENT_SETPARAM__HALF2X1;

	const StringHash HASH_ELEMENT_SETPARAM__HALF2X2 = 125999490;
	extern const char* NAME_ELEMENT_SETPARAM__HALF2X2;

	const StringHash HASH_ELEMENT_SETPARAM__HALF2X3 = 125999491;
	extern const char* NAME_ELEMENT_SETPARAM__HALF2X3;

	const StringHash HASH_ELEMENT_SETPARAM__HALF2X4 = 125999492;
	extern const char* NAME_ELEMENT_SETPARAM__HALF2X4;

	const StringHash HASH_ELEMENT_SETPARAM__HALF3X1 = 125999745;
	extern const char* NAME_ELEMENT_SETPARAM__HALF3X1;

	const StringHash HASH_ELEMENT_SETPARAM__HALF3X2 = 125999746;
	extern const char* NAME_ELEMENT_SETPARAM__HALF3X2;

	const StringHash HASH_ELEMENT_SETPARAM__HALF3X3 = 125999747;
	extern const char* NAME_ELEMENT_SETPARAM__HALF3X3;

	const StringHash HASH_ELEMENT_SETPARAM__HALF3X4 = 125999748;
	extern const char* NAME_ELEMENT_SETPARAM__HALF3X4;

	const StringHash HASH_ELEMENT_SETPARAM__HALF4X1 = 126000001;
	extern const char* NAME_ELEMENT_SETPARAM__HALF4X1;

	const StringHash HASH_ELEMENT_SETPARAM__HALF4X2 = 126000002;
	extern const char* NAME_ELEMENT_SETPARAM__HALF4X2;

	const StringHash HASH_ELEMENT_SETPARAM__HALF4X3 = 126000003;
	extern const char* NAME_ELEMENT_SETPARAM__HALF4X3;

	const StringHash HASH_ELEMENT_SETPARAM__HALF4X4 = 126000004;
	extern const char* NAME_ELEMENT_SETPARAM__HALF4X4;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED = 3542708;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED1 = 56683377;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED1;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED2 = 56683378;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED2;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED3 = 56683379;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED3;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED4 = 56683380;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED4;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED1X1 = 15432657;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED1X1;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED1X2 = 15432658;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED1X2;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED1X3 = 15432659;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED1X3;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED1X4 = 15432660;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED1X4;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED2X1 = 15432401;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED2X1;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED2X2 = 15432402;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED2X2;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED2X3 = 15432403;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED2X3;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED2X4 = 15432404;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED2X4;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED3X1 = 15432145;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED3X1;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED3X2 = 15432146;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED3X2;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED3X3 = 15432147;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED3X3;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED3X4 = 15432148;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED3X4;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED4X1 = 15431889;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED4X1;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED4X2 = 15431890;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED4X2;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED4X3 = 15431891;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED4X3;

	const StringHash HASH_ELEMENT_SETPARAM__FIXED4X4 = 15431892;
	extern const char* NAME_ELEMENT_SETPARAM__FIXED4X4;

	const StringHash HASH_ELEMENT_SETPARAM__STRING = 3903559;
	extern const char* NAME_ELEMENT_SETPARAM__STRING;

	const StringHash HASH_ELEMENT_SETPARAM__USERTYPE = 164216885;
	extern const char* NAME_ELEMENT_SETPARAM__USERTYPE;
	struct setparam__usertype__AttributeData
	{
		static const setparam__usertype__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* source;
	};

	const StringHash HASH_ELEMENT_SETPARAM__ARRAY = 3250313;
	extern const char* NAME_ELEMENT_SETPARAM__ARRAY;
	struct setparam__array__AttributeData
	{
		static const setparam__array__AttributeData DEFAULT;

		long length;
	};

	const StringHash HASH_ELEMENT_SETPARAM__CONNECT_PARAM = 151241709;
	extern const char* NAME_ELEMENT_SETPARAM__CONNECT_PARAM;
	struct setparam__connect_param__AttributeData
	{
		static const setparam__connect_param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG__TECHNIQUE = 198327461;
	extern const char* NAME_ELEMENT_PROFILE_CG__TECHNIQUE;
	struct profile_CG__technique__AttributeData
	{
		static const profile_CG__technique__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_PROFILE_CG__EXTRA = 84040097;
	extern const char* NAME_ELEMENT_PROFILE_CG__EXTRA;
	struct profile_CG__extra__AttributeData
	{
		static const profile_CG__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_PROFILE_COMMON = 171910622;
	extern const char* NAME_ELEMENT_PROFILE_COMMON;
	struct profile_COMMON__AttributeData
	{
		static const profile_COMMON__AttributeData DEFAULT;

		const ParserChar* id;
	};

	const StringHash HASH_ELEMENT_PROFILE_COMMON__ASSET = 145422180;
	extern const char* NAME_ELEMENT_PROFILE_COMMON__ASSET;

	const StringHash HASH_ELEMENT_PROFILE_COMMON__IMAGE = 145647989;
	extern const char* NAME_ELEMENT_PROFILE_COMMON__IMAGE;
	struct profile_COMMON__image__AttributeData
	{
		static const profile_COMMON__image__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* format;
		const ParserChar* height;
		const ParserChar* width;
		const ParserChar* depth;
	};

	const StringHash HASH_ELEMENT_PROFILE_COMMON__NEWPARAM = 151782173;
	extern const char* NAME_ELEMENT_PROFILE_COMMON__NEWPARAM;
	struct profile_COMMON__newparam__AttributeData
	{
		static const profile_COMMON__newparam__AttributeData DEFAULT;

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

	const StringHash HASH_ELEMENT_TECHNIQUE__CONSTANT = 140404900;
	extern const char* NAME_ELEMENT_TECHNIQUE__CONSTANT;

	const StringHash HASH_ELEMENT_EMISSION = 17478014;
	extern const char* NAME_ELEMENT_EMISSION;
	const StringHash HASH_ELEMENT_CONSTANT__EMISSION = 17478014;
	extern const char* NAME_ELEMENT_CONSTANT__EMISSION;

	const StringHash HASH_ELEMENT_EMISSION__COLOR = 99748322;
	extern const char* NAME_ELEMENT_EMISSION__COLOR;
	struct emission__color__AttributeData
	{
		static const emission__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_EMISSION__PARAM = 97460989;
	extern const char* NAME_ELEMENT_EMISSION__PARAM;
	struct emission__param__AttributeData
	{
		static const emission__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_TEXTURE = 56965445;
	extern const char* NAME_ELEMENT_TEXTURE;
	const StringHash HASH_ELEMENT_EMISSION__TEXTURE = 56965445;
	extern const char* NAME_ELEMENT_EMISSION__TEXTURE;
	const StringHash HASH_ATTRIBUTE_TEXTURE = 181386485;
	extern const char* NAME_ATTRIBUTE_TEXTURE;
	const StringHash HASH_ATTRIBUTE_TEXCOORD = 216686884;
	extern const char* NAME_ATTRIBUTE_TEXCOORD;
	struct emission__texture__AttributeData
	{
		static const emission__texture__AttributeData DEFAULT;

		const ParserChar* texture;
		const ParserChar* texcoord;
	};

	const StringHash HASH_ELEMENT_TEXTURE__EXTRA = 161952913;
	extern const char* NAME_ELEMENT_TEXTURE__EXTRA;
	struct texture__extra__AttributeData
	{
		static const texture__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	const StringHash HASH_ELEMENT_REFLECTIVE = 43423765;
	extern const char* NAME_ELEMENT_REFLECTIVE;
	const StringHash HASH_ELEMENT_CONSTANT__REFLECTIVE = 43423765;
	extern const char* NAME_ELEMENT_CONSTANT__REFLECTIVE;

	const StringHash HASH_ELEMENT_REFLECTIVE__COLOR = 9172162;
	extern const char* NAME_ELEMENT_REFLECTIVE__COLOR;
	struct reflective__color__AttributeData
	{
		static const reflective__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_REFLECTIVE__PARAM = 11876829;
	extern const char* NAME_ELEMENT_REFLECTIVE__PARAM;
	struct reflective__param__AttributeData
	{
		static const reflective__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_REFLECTIVE__TEXTURE = 159259701;
	extern const char* NAME_ELEMENT_REFLECTIVE__TEXTURE;
	struct reflective__texture__AttributeData
	{
		static const reflective__texture__AttributeData DEFAULT;

		const ParserChar* texture;
		const ParserChar* texcoord;
	};

	const StringHash HASH_ELEMENT_REFLECTIVITY = 110633513;
	extern const char* NAME_ELEMENT_REFLECTIVITY;
	const StringHash HASH_ELEMENT_CONSTANT__REFLECTIVITY = 110633513;
	extern const char* NAME_ELEMENT_CONSTANT__REFLECTIVITY;

	const StringHash HASH_ELEMENT_REFLECTIVITY__FLOAT = 149886404;
	extern const char* NAME_ELEMENT_REFLECTIVITY__FLOAT;
	struct reflectivity__float__AttributeData
	{
		static const reflectivity__float__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_REFLECTIVITY__PARAM = 148154429;
	extern const char* NAME_ELEMENT_REFLECTIVITY__PARAM;
	struct reflectivity__param__AttributeData
	{
		static const reflectivity__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_TRANSPARENT = 145306628;
	extern const char* NAME_ELEMENT_TRANSPARENT;
	const StringHash HASH_ELEMENT_CONSTANT__TRANSPARENT = 145306628;
	extern const char* NAME_ELEMENT_CONSTANT__TRANSPARENT;
	const StringHash HASH_ATTRIBUTE_OPAQUE = 124160181;
	extern const char* NAME_ATTRIBUTE_OPAQUE;
	struct constant__transparent__AttributeData
	{
		static const constant__transparent__AttributeData DEFAULT;

		const ParserChar* opaque;
	};

	const StringHash HASH_ELEMENT_TRANSPARENT__COLOR = 107619106;
	extern const char* NAME_ELEMENT_TRANSPARENT__COLOR;
	struct transparent__color__AttributeData
	{
		static const transparent__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TRANSPARENT__PARAM = 106350653;
	extern const char* NAME_ELEMENT_TRANSPARENT__PARAM;
	struct transparent__param__AttributeData
	{
		static const transparent__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_TRANSPARENT__TEXTURE = 177208021;
	extern const char* NAME_ELEMENT_TRANSPARENT__TEXTURE;
	struct transparent__texture__AttributeData
	{
		static const transparent__texture__AttributeData DEFAULT;

		const ParserChar* texture;
		const ParserChar* texcoord;
	};

	const StringHash HASH_ELEMENT_TRANSPARENCY = 177422633;
	extern const char* NAME_ELEMENT_TRANSPARENCY;
	const StringHash HASH_ELEMENT_CONSTANT__TRANSPARENCY = 177422633;
	extern const char* NAME_ELEMENT_CONSTANT__TRANSPARENCY;

	const StringHash HASH_ELEMENT_TRANSPARENCY__FLOAT = 140067972;
	extern const char* NAME_ELEMENT_TRANSPARENCY__FLOAT;
	struct transparency__float__AttributeData
	{
		static const transparency__float__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_TRANSPARENCY__PARAM = 140679549;
	extern const char* NAME_ELEMENT_TRANSPARENCY__PARAM;
	struct transparency__param__AttributeData
	{
		static const transparency__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION = 195491134;
	extern const char* NAME_ELEMENT_INDEX_OF_REFRACTION;
	const StringHash HASH_ELEMENT_CONSTANT__INDEX_OF_REFRACTION = 195491134;
	extern const char* NAME_ELEMENT_CONSTANT__INDEX_OF_REFRACTION;

	const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION__FLOAT = 70494564;
	extern const char* NAME_ELEMENT_INDEX_OF_REFRACTION__FLOAT;
	struct index_of_refraction__float__AttributeData
	{
		static const index_of_refraction__float__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_INDEX_OF_REFRACTION__PARAM = 67646621;
	extern const char* NAME_ELEMENT_INDEX_OF_REFRACTION__PARAM;
	struct index_of_refraction__param__AttributeData
	{
		static const index_of_refraction__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_LAMBERT = 90423428;
	extern const char* NAME_ELEMENT_LAMBERT;
	const StringHash HASH_ELEMENT_TECHNIQUE__LAMBERT = 90423428;
	extern const char* NAME_ELEMENT_TECHNIQUE__LAMBERT;

	const StringHash HASH_ELEMENT_LAMBERT__EMISSION = 15092238;
	extern const char* NAME_ELEMENT_LAMBERT__EMISSION;

	const StringHash HASH_ELEMENT_LAMBERT__AMBIENT = 16135972;
	extern const char* NAME_ELEMENT_LAMBERT__AMBIENT;

	const StringHash HASH_ELEMENT_AMBIENT__PARAM = 149506909;
	extern const char* NAME_ELEMENT_AMBIENT__PARAM;
	struct ambient__param__AttributeData
	{
		static const ambient__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_AMBIENT__TEXTURE = 84710501;
	extern const char* NAME_ELEMENT_AMBIENT__TEXTURE;
	struct ambient__texture__AttributeData
	{
		static const ambient__texture__AttributeData DEFAULT;

		const ParserChar* texture;
		const ParserChar* texcoord;
	};

	const StringHash HASH_ELEMENT_DIFFUSE = 36835829;
	extern const char* NAME_ELEMENT_DIFFUSE;
	const StringHash HASH_ELEMENT_LAMBERT__DIFFUSE = 36835829;
	extern const char* NAME_ELEMENT_LAMBERT__DIFFUSE;

	const StringHash HASH_ELEMENT_DIFFUSE__COLOR = 211136114;
	extern const char* NAME_ELEMENT_DIFFUSE__COLOR;
	struct diffuse__color__AttributeData
	{
		static const diffuse__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_DIFFUSE__PARAM = 212551533;
	extern const char* NAME_ELEMENT_DIFFUSE__PARAM;
	struct diffuse__param__AttributeData
	{
		static const diffuse__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_DIFFUSE__TEXTURE = 117481509;
	extern const char* NAME_ELEMENT_DIFFUSE__TEXTURE;
	struct diffuse__texture__AttributeData
	{
		static const diffuse__texture__AttributeData DEFAULT;

		const ParserChar* texture;
		const ParserChar* texcoord;
	};

	const StringHash HASH_ELEMENT_LAMBERT__REFLECTIVE = 242202613;
	extern const char* NAME_ELEMENT_LAMBERT__REFLECTIVE;

	const StringHash HASH_ELEMENT_LAMBERT__REFLECTIVITY = 263720665;
	extern const char* NAME_ELEMENT_LAMBERT__REFLECTIVITY;

	const StringHash HASH_ELEMENT_LAMBERT__TRANSPARENT = 121356996;
	extern const char* NAME_ELEMENT_LAMBERT__TRANSPARENT;
	struct lambert__transparent__AttributeData
	{
		static const lambert__transparent__AttributeData DEFAULT;

		const ParserChar* opaque;
	};

	const StringHash HASH_ELEMENT_LAMBERT__TRANSPARENCY = 62664153;
	extern const char* NAME_ELEMENT_LAMBERT__TRANSPARENCY;

	const StringHash HASH_ELEMENT_LAMBERT__INDEX_OF_REFRACTION = 87566030;
	extern const char* NAME_ELEMENT_LAMBERT__INDEX_OF_REFRACTION;

	const StringHash HASH_ELEMENT_PHONG = 204592647;
	extern const char* NAME_ELEMENT_PHONG;
	const StringHash HASH_ELEMENT_TECHNIQUE__PHONG = 204592647;
	extern const char* NAME_ELEMENT_TECHNIQUE__PHONG;

	const StringHash HASH_ELEMENT_PHONG__EMISSION = 105372942;
	extern const char* NAME_ELEMENT_PHONG__EMISSION;

	const StringHash HASH_ELEMENT_PHONG__AMBIENT = 157036644;
	extern const char* NAME_ELEMENT_PHONG__AMBIENT;

	const StringHash HASH_ELEMENT_PHONG__DIFFUSE = 93849765;
	extern const char* NAME_ELEMENT_PHONG__DIFFUSE;

	const StringHash HASH_ELEMENT_SPECULAR = 16253650;
	extern const char* NAME_ELEMENT_SPECULAR;
	const StringHash HASH_ELEMENT_PHONG__SPECULAR = 16253650;
	extern const char* NAME_ELEMENT_PHONG__SPECULAR;

	const StringHash HASH_ELEMENT_SPECULAR__COLOR = 16126290;
	extern const char* NAME_ELEMENT_SPECULAR__COLOR;
	struct specular__color__AttributeData
	{
		static const specular__color__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SPECULAR__PARAM = 13294157;
	extern const char* NAME_ELEMENT_SPECULAR__PARAM;
	struct specular__param__AttributeData
	{
		static const specular__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_SPECULAR__TEXTURE = 110988357;
	extern const char* NAME_ELEMENT_SPECULAR__TEXTURE;
	struct specular__texture__AttributeData
	{
		static const specular__texture__AttributeData DEFAULT;

		const ParserChar* texture;
		const ParserChar* texcoord;
	};

	const StringHash HASH_ELEMENT_SHININESS = 211569187;
	extern const char* NAME_ELEMENT_SHININESS;
	const StringHash HASH_ELEMENT_PHONG__SHININESS = 211569187;
	extern const char* NAME_ELEMENT_PHONG__SHININESS;

	const StringHash HASH_ELEMENT_SHININESS__FLOAT = 39878676;
	extern const char* NAME_ELEMENT_SHININESS__FLOAT;
	struct shininess__float__AttributeData
	{
		static const shininess__float__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	const StringHash HASH_ELEMENT_SHININESS__PARAM = 40230381;
	extern const char* NAME_ELEMENT_SHININESS__PARAM;
	struct shininess__param__AttributeData
	{
		static const shininess__param__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	const StringHash HASH_ELEMENT_PHONG__REFLECTIVE = 268102997;
	extern const char* NAME_ELEMENT_PHONG__REFLECTIVE;

	const StringHash HASH_ELEMENT_PHONG__REFLECTIVITY = 183332681;
	extern const char* NAME_ELEMENT_PHONG__REFLECTIVITY;

	const StringHash HASH_ELEMENT_PHONG__TRANSPARENT = 241987796;
	extern const char* NAME_ELEMENT_PHONG__TRANSPARENT;
	struct phong__transparent__AttributeData
	{
		static const phong__transparent__AttributeData DEFAULT;

		const ParserChar* opaque;
	};

	const StringHash HASH_ELEMENT_PHONG__TRANSPARENCY = 113708105;
	extern const char* NAME_ELEMENT_PHONG__TRANSPARENCY;

	const StringHash HASH_ELEMENT_PHONG__INDEX_OF_REFRACTION = 215105534;
	extern const char* NAME_ELEMENT_PHONG__INDEX_OF_REFRACTION;

	const StringHash HASH_ELEMENT_BLINN = 202379278;
	extern const char* NAME_ELEMENT_BLINN;
	const StringHash HASH_ELEMENT_TECHNIQUE__BLINN = 202379278;
	extern const char* NAME_ELEMENT_TECHNIQUE__BLINN;

	const StringHash HASH_ELEMENT_BLINN__EMISSION = 73311438;
	extern const char* NAME_ELEMENT_BLINN__EMISSION;

	const StringHash HASH_ELEMENT_BLINN__AMBIENT = 87931284;
	extern const char* NAME_ELEMENT_BLINN__AMBIENT;

	const StringHash HASH_ELEMENT_BLINN__DIFFUSE = 167354197;
	extern const char* NAME_ELEMENT_BLINN__DIFFUSE;

	const StringHash HASH_ELEMENT_BLINN__SPECULAR = 116301074;
	extern const char* NAME_ELEMENT_BLINN__SPECULAR;

	const StringHash HASH_ELEMENT_BLINN__SHININESS = 185448003;
	extern const char* NAME_ELEMENT_BLINN__SHININESS;

	const StringHash HASH_ELEMENT_BLINN__REFLECTIVE = 109390693;
	extern const char* NAME_ELEMENT_BLINN__REFLECTIVE;

	const StringHash HASH_ELEMENT_BLINN__REFLECTIVITY = 86734393;
	extern const char* NAME_ELEMENT_BLINN__REFLECTIVITY;

	const StringHash HASH_ELEMENT_BLINN__TRANSPARENT = 160434500;
	extern const char* NAME_ELEMENT_BLINN__TRANSPARENT;
	struct blinn__transparent__AttributeData
	{
		static const blinn__transparent__AttributeData DEFAULT;

		const ParserChar* opaque;
	};

	const StringHash HASH_ELEMENT_BLINN__TRANSPARENCY = 151033145;
	extern const char* NAME_ELEMENT_BLINN__TRANSPARENCY;

	const StringHash HASH_ELEMENT_BLINN__INDEX_OF_REFRACTION = 24357934;
	extern const char* NAME_ELEMENT_BLINN__INDEX_OF_REFRACTION;

	const StringHash HASH_ELEMENT_PROFILE_COMMON__EXTRA = 145663265;
	extern const char* NAME_ELEMENT_PROFILE_COMMON__EXTRA;
	struct profile_COMMON__extra__AttributeData
	{
		static const profile_COMMON__extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct triangles__AttributeData
	{
		static const triangles__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	struct rotate__AttributeData
	{
		static const rotate__AttributeData DEFAULT;

		const ParserChar* sid;
	};


	struct instance_force_field__AttributeData
	{
		static const instance_force_field__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};


	struct polygons__AttributeData
	{
		static const polygons__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	struct vertices__AttributeData
	{
		static const vertices__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	struct extra__AttributeData
	{
		static const extra__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* type;
	};

	struct instance_physics_material__AttributeData
	{
		static const instance_physics_material__AttributeData DEFAULT;

		const ParserChar* url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	struct polylist__AttributeData
	{
		static const polylist__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* count;
		const ParserChar* material;
	};

	struct translate__AttributeData
	{
		static const translate__AttributeData DEFAULT;

		const ParserChar* sid;
	};



}
#endif
