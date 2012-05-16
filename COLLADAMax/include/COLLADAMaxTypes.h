/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAMax.

    Portions of the code are:
    Copyright (c) 2005-2007 Feeling Software Inc.
    Copyright (c) 2005-2007 Sony Computer Entertainment America
    
    Based on the 3dsMax COLLADASW Tools:
    Copyright (c) 2005-2006 Autodesk Media Entertainment
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/


#ifndef __COLLADAMAX_TYPES_H__
#define __COLLADAMAX_TYPES_H__

#include "COLLADAMaxPrerequisites.h"

#include "COLLADABUURI.h"

#include <vector>
#include <map>
#include <set>

class INode;

namespace COLLADAMax
{

	class ExportNode;

	typedef std::vector<String> StringList;

	struct EffectIdAndName
	{
		EffectIdAndName( const String& _effectId, const String& _effectName ) 
			: effectId(_effectId)
			, effectName(_effectName)
		{}

		String effectId;
		String effectName;
	};


    /** A list of ids of effects that are exported*/
    typedef std::vector<EffectIdAndName> ExportedEffectIdAndNameList;

    /** A list of wire frame colors that are exported*/
    typedef std::vector<DWORD> WireFrameColorEffectList;

    /** Maps material pointers to effect ids*/
    typedef std::map<Mtl*, String> EffectMap;

	struct ImageInfo
	{
		/** The id of the image element in the COLLADA file.*/
		String imageId;

		/** The location of the image to reference in the COLLADA image element.*/
		COLLADABU::URI fileLocation;
	};

    /**map<filename(original max absolute file location),imageID>*/
	typedef std::map<COLLADABU::URI, ImageInfo> ExportedImageMap;

	/** List of INodes*/
	typedef std::vector<INode*> INodeList;

	/** List of ImpNodes*/
	typedef std::vector<ImpNode*> ImpNodeList;

	typedef std::set<ExportNode*> ExportNodeSet;

	typedef std::vector<float> FloatList;


	typedef std::map<Object*, String> ObjectStringMap;

	struct SkyLightParameters
	{
		float colorMapAmount;
		bool colorMapOn;
		int raysPerSample;
		float mode;
		float multiplier;
		float rayBias;
		bool castShadows;
		bool intensityOn;
	};


}

// extra class ID from the samples (systems/sunlight/natLight.cpp)
#define SKY_LIGHT_CLASS_ID			Class_ID(0x7bf61478, 0x522e4705)
#define SKY_LIGHT_CLASS_ID_PART_A	0x7bf61478



// Information found in the 3dsMax SDK from the 'light' object sample.
namespace MaxLight
{
	// reference #s
	const unsigned int PBLOCK_REF = 0;		// This is a IParamBlock
	const unsigned int PBLOCK_REF_SKY = 0;	// This is a IParamBlock2
	const unsigned int PROJMAP_REF = 1;
	const unsigned int SHADPROJMAP_REF = 2;
	const unsigned int SHADTYPE_REF = 3;

	// Parameter block indices common to all lights (except SkyLight)
	const unsigned int PB_COLOR = 0;
	const unsigned int PB_INTENSITY = 1;
	const unsigned int PB_CONTRAST = 2;
	const unsigned int PB_DIFFSOFT = 3;

	// Parameter block indices for non-OMNI lights.
	const unsigned int PB_HOTSIZE = 4;
	const unsigned int PB_FALLSIZE = 5;
	const unsigned int PB_ASPECT = 6;
	const unsigned int PB_ATTENSTART1 = 7;
	const unsigned int PB_ATTENEND1 = 8;
	const unsigned int PB_ATTENSTART = 9;
	const unsigned int PB_ATTENEND = 10;
	const unsigned int PB_DECAY = 11;
	const unsigned int PB_SHADCOLOR = 12;
	const unsigned int PB_ATMOS_SHAD = 13;
	const unsigned int PB_ATMOS_OPACITY = 14;
	const unsigned int PB_ATMOS_COLAMT = 15;
	const unsigned int PB_SHADMULT = 16;
	const unsigned int PB_SHAD_COLMAP = 17;
	const unsigned int PB_TDIST = 18;

	// Parameter block indices for OMNI only
	const unsigned int PB_OMNIATSTART1 = 4;
	const unsigned int PB_OMNIATEND1 = 5;
	const unsigned int PB_OMNIATSTART = 6;
	const unsigned int PB_OMNIATEND = 7;
	const unsigned int PB_OMNIDECAY = 8;
	const unsigned int PB_OMNISHADCOLOR = 9;
	const unsigned int PB_OMNIATMOS_SHAD = 10;
	const unsigned int PB_OMNIATMOS_OPACITY = 11;
	const unsigned int PB_OMNIATMOS_COLAMT = 12;
	const unsigned int PB_OMNISHADMULT = 13;
	const unsigned int PB_OMNISHAD_COLMAP = 14;

	// Parameter block indices for SkyLights (by looking at the ParamBlockDesc)
	const unsigned int PB_SKY_COLOR = 0;
	const unsigned int PB_SKY_SKY_COLOR_MAP_AMOUNT = 1;
	const unsigned int PB_SKY_COLOR_MAP = 2; // TYPE_TEXMAP
	const unsigned int PB_SKY_SKY_COLOR_MAP_ON = 3;
	const unsigned int PB_SKY_RAYS_PER_SAMPLE = 4;
	// baad food
	const unsigned int PB_SKY_MODE = 7; // ??
	// baad food
	const unsigned int PB_SKY_INTENSITY = 0xa;
	const unsigned int PB_SKY_RAY_BIAS = 0xb;
	const unsigned int PB_SKY_CAST_SHADOWS = 0xc;
	const unsigned int PB_SKY_MULTIPLIER_ON = 0xd;
};




#endif //__COLLADAMAX_TYPES_H__
