/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURDESCRIPTION_H__
#define __MayaDM_FURDESCRIPTION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*"FurDescription" node defines all the attributes for a particular type of fur, for example, fur color, width, length, baldness, opacity, scraggle, curl, density, and so on.*/
class FurDescription : public DependNode
{
public:
	/*Used to map values for Fur description attribute "BaseColor" by importing file textures.*/
	struct BaseColorMap{
	};
	/*Used to map values for fur description attribute "BaseColor" along U direction by importing file textures.*/
	struct BaseColorMapUSamples{
	};
	/*Used to map values for fur description attribute "BaseColor" along V direction by importing file textures.*/
	struct BaseColorMapVSamples{
	};
	/*Used to map values for Fur description attribute "TipColor" by importing file textures.*/
	struct TipColorMap{
	};
	/*Used to map values for fur description attribute "TipColor" along U direction by importing file textures.*/
	struct TipColorMapUSamples{
	};
	/*Used to map values for fur description attribute "TipColor" along V direction by importing file textures.*/
	struct TipColorMapVSamples{
	};
	/*Used to map values for Fur description attribute "BaseAmbientColor" by importing file textures.*/
	struct BaseAmbientColorMap{
	};
	/*Used to map values for fur description attribute "BaseAmbientColor" along U direction by importing file textures.*/
	struct BaseAmbientColorMapUSamples{
	};
	/*Used to map values for fur description attribute "BaseAmbientColor" along V direction by importing file textures.*/
	struct BaseAmbientColorMapVSamples{
	};
	/*Used to map values for Fur description attribute "TipAmbientColor" by importing file textures.*/
	struct TipAmbientColorMap{
	};
	/*Used to map values for fur description attribute "TpAmbientColor" along U direction by importing file textures.*/
	struct TipAmbientColorMapUSamples{
	};
	/*Used to map values for fur description attribute "TpAmbientColor" along V direction by importing file textures.*/
	struct TipAmbientColorMapVSamples{
	};
	/*Used to map values for Fur description attribute "SpecularColor" by importing file textures.*/
	struct SpecularColorMap{
	};
	/*Used to map values for fur description attribute "SpecularColor" along U direction by importing file textures.*/
	struct SpecularColorMapUSamples{
	};
	/*Used to map values for fur description attribute "SpecularColor" along V direction by importing file textures.*/
	struct SpecularColorMapVSamples{
	};
	/*Used to map values for fur description attribute "Length" by importing file textures.*/
	struct LengthMap{
	};
	/*Used to map values for fur description attribute "Length" along U direction by importing file textures.*/
	struct LengthMapUSamples{
	};
	/*Used to map values for fur description attribute "Length" along V direction by importing file textures.*/
	struct LengthMapVSamples{
	};
	/*Used to map values for fur description attribute "SpecularSharpness" by importing file textures.*/
	struct SpecularSharpnessMap{
	};
	/*Used to map values for fur description attribute "SpecularSharpness" along U direction by importing file textures.*/
	struct SpecularSharpnessMapUSamples{
	};
	/*Used to map values for fur description attribute "SpecularSharpness" along V direction by importing file textures.*/
	struct SpecularSharpnessMapVSamples{
	};
	/*Used to map values for fur description attribute "Baldness" by importing file textures.*/
	struct BaldnessMap{
	};
	/*Used to map values for fur description attribute "Baldness" along U direction by importing file textures.*/
	struct BaldnessMapUSamples{
	};
	/*Used to map values for fur description attribute "Baldness" along V direction by importing file textures.*/
	struct BaldnessMapVSamples{
	};
	/*Used to map values for fur description attribute "BaseOpacity" by importing file textures.*/
	struct BaseOpacityMap{
	};
	/*Used to map values for fur description attribute "BaseOpacity" along U direction by importing file textures.*/
	struct BaseOpacityMapUSamples{
	};
	/*Used to map values for fur description attribute "BaseOpacity" along V direction by importing file textures.*/
	struct BaseOpacityMapVSamples{
	};
	/*Used to map values for fur description attribute "TipOpacity" by importing file textures.*/
	struct TipOpacityMap{
	};
	/*Used to map values for fur description attribute "TipOpacity" along U direction by importing file textures.*/
	struct TipOpacityMapUSamples{
	};
	/*Used to map values for fur description attribute "TipOpacity" along V direction by importing file textures.*/
	struct TipOpacityMapVSamples{
	};
	/*Used to map values for fur description attribute "BaseWidth" by importing file textures.*/
	struct BaseWidthMap{
	};
	/*Used to map values for fur description attribute "BaseWidth" along U direction by importing file textures.*/
	struct BaseWidthMapUSamples{
	};
	/*Used to map values for fur description attribute "BaseWidth" along V direction by importing file textures.*/
	struct BaseWidthMapVSamples{
	};
	/*Used to map values for fur description attribute "TipWidth" by importing file textures.*/
	struct TipWidthMap{
	};
	/*Used to map values for fur description attribute "TipWidth" along U direction by importing file textures.*/
	struct TipWidthMapUSamples{
	};
	/*Used to map values for fur description attribute "TipWidth" along V direction by importing file textures.*/
	struct TipWidthMapVSamples{
	};
	/*Used to map values for fur description attribute "Segments" by importing file textures.*/
	struct SegmentsMap{
	};
	/*Used to map values for fur description attribute "Segments" along U direction by importing file textures.*/
	struct SegmentsMapUSamples{
	};
	/*Used to map values for fur description attribute "Segments" along V direction by importing file textures.*/
	struct SegmentsMapVSamples{
	};
	/*Used to map values for fur description attribute "BaseCurl" by importing file textures.*/
	struct BaseCurlMap{
	};
	/*Used to map values for fur description attribute "BaseCurl" along U direction by importing file textures.*/
	struct BaseCurlMapUSamples{
	};
	/*Used to map values for fur description attribute "BaseCurl" along V direction by importing file textures.*/
	struct BaseCurlMapVSamples{
	};
	/*Used to map values for fur description attribute "TipCurl" by importing file textures.*/
	struct TipCurlMap{
	};
	/*Used to map values for fur description attribute "TipCurl" along U direction by importing file textures.*/
	struct TipCurlMapUSamples{
	};
	/*Used to map values for fur description attribute "TipCurl" along V direction by importing file textures.*/
	struct TipCurlMapVSamples{
	};
	/*Used to map values for fur description attribute "Scraggle" by importing file textures.*/
	struct ScraggleMap{
	};
	/*Used to map values for fur description attribute "Scraggle" along U direction by importing file textures.*/
	struct ScraggleMapUSamples{
	};
	/*Used to map values for fur description attribute "Scraggle" along V direction by importing file textures.*/
	struct ScraggleMapVSamples{
	};
	/*Used to map values for fur description attribute "ScraggleFrequency" by importing file textures.*/
	struct ScraggleFrequencyMap{
	};
	/*Used to map values for fur description attribute "ScraggleFrequency" along U direction by importing file textures.*/
	struct ScraggleFrequencyMapUSamples{
	};
	/*Used to map values for fur description attribute "ScraggleFrequency" along V direction by importing file textures.*/
	struct ScraggleFrequencyMapVSamples{
	};
	/*Used to map values for fur description attribute "ScraggleCorrelation" by importing file textures.*/
	struct ScraggleCorrelationMap{
	};
	/*Used to map values for fur description attribute "ScraggleCorrelation" along U direction by importing file textures.*/
	struct ScraggleCorrelationMapUSamples{
	};
	/*Used to map values for fur description attribute "ScraggleCorrelation" along V direction by importing file textures.*/
	struct ScraggleCorrelationMapVSamples{
	};
	/*Used to map values for fur description attribute "Inclination" by importing file textures.*/
	struct InclinationMap{
	};
	/*Used to map values for fur description attribute "Inclination" along U direction by importing file textures.*/
	struct InclinationMapUSamples{
	};
	/*Used to map values for fur description attribute "Inclination" along V direction by importing file textures.*/
	struct InclinationMapVSamples{
	};
	/*Used to map values for fur description attribute "Roll" by importing file textures.*/
	struct RollMap{
	};
	/*Used to map values for fur description attribute "Roll" along U direction by importing file textures.*/
	struct RollMapUSamples{
	};
	/*Used to map values for fur description attribute "Roll" along V direction by importing file textures.*/
	struct RollMapVSamples{
	};
	/*Used to map values for fur description attribute "Polar" by importing file textures.*/
	struct PolarMap{
	};
	/*Used to map values for fur description attribute "Polar" along U direction by importing file textures.*/
	struct PolarMapUSamples{
	};
	/*Used to map values for fur description attribute "Polar" along V direction by importing file textures.*/
	struct PolarMapVSamples{
	};
	/*Used to map values for fur description attribute "Attraction" by importing file textures.*/
	struct AttractionMap{
	};
	/*Used to map values for fur description attribute "Attraction" along U direction by importing file textures.*/
	struct AttractionMapUSamples{
	};
	/*Used to map values for fur description attribute "Attraction" along V direction by importing file textures.*/
	struct AttractionMapVSamples{
	};
	/*Used to map values for fur description attribute "Offset" by importing file textures.*/
	struct OffsetMap{
	};
	/*Used to map values for fur description attribute "Offset" along U direction by importing file textures.*/
	struct OffsetMapUSamples{
	};
	/*Used to map values for fur description attribute "Offset" along V direction by importing file textures.*/
	struct OffsetMapVSamples{
	};
	/*Used to map values for fur description attribute "Clumping" by importing file textures.*/
	struct ClumpingMap{
	};
	/*Used to map values for fur description attribute "Clumping" along U direction by importing file textures.*/
	struct ClumpingMapUSamples{
	};
	/*Used to map values for fur description attribute "Clumping" along V direction by importing file textures.*/
	struct ClumpingMapVSamples{
	};
	/*Used to map values for fur description attribute "ClumpingFrequency" by importing file textures.*/
	struct ClumpingFrequencyMap{
	};
	/*Used to map values for fur description attribute "ClumpingFrequency" along U direction by importing file textures.*/
	struct ClumpingFrequencyMapUSamples{
	};
	/*Used to map values for fur description attribute "ClumpingFrequency" along V direction by importing file textures.*/
	struct ClumpingFrequencyMapVSamples{
	};
	/*Used to map values for fur description attribute "ClumpShape" by importing file textures.*/
	struct ClumpShapeMap{
	};
	/*Used to map values for fur description attribute "ClumpShape" along U direction by importing file textures.*/
	struct ClumpShapeMapUSamples{
	};
	/*Used to map values for fur description attribute "ClumpShape" along V direction by importing file textures.*/
	struct ClumpShapeMapVSamples{
	};
public:
	FurDescription(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurDescription"){}
	virtual ~FurDescription(){}
	/*
	Defines the light model, which is applied to the fur description.
	Ambient(0): Only the Base Ambient Color and Tip Ambient Color of the fur are used in the final color calculation.
	Ambient + Diffuse(1): The Base Ambient Color and Tip Ambient Color values are added to the Base Color and Tip Color values respectively.
	Ambient + Diffuse + Specular(2): The Base Ambient Color and Tip Ambient Color values are added to the Base Color and Tip Color values respectively, and the Specular values are added to the hairs according to the Specular Sharpness.
	Specular(3): Only the Specular lights (highlights) for the fur are rendered.
	*/
	void setLightModel(unsigned int lmd){if(lmd == 2) return; fprintf_s(mFile, "setAttr \".lmd\" %i;\n", lmd);}
	/*
	Defines the light model, which is applied to the fur description.
	Ambient(0): Only the Base Ambient Color and Tip Ambient Color of the fur are used in the final color calculation.
	Ambient + Diffuse(1): The Base Ambient Color and Tip Ambient Color values are added to the Base Color and Tip Color values respectively.
	Ambient + Diffuse + Specular(2): The Base Ambient Color and Tip Ambient Color values are added to the Base Color and Tip Color values respectively, and the Specular values are added to the hairs according to the Specular Sharpness.
	Specular(3): Only the Specular lights (highlights) for the fur are rendered.
	*/
	void setLightModel(const UnsignedintID& lmd){fprintf_s(mFile,"connectAttr \"");lmd.write(mFile);fprintf_s(mFile,"\" \"%s.lmd\";\n",mName.c_str());}
	/*Defines number of hairs that distributed either across all surfaces or on each surface.*/
	void setDensity(int d){if(d == 1000.0) return; fprintf_s(mFile, "setAttr \".d\" %i;\n", d);}
	/*Define to scale the hairs uniformly. This is used to adjust the Base Width, Tip Width, Length, and Offset values by a common factor (including mapped values).*/
	void setGlobalScale(float gs){if(gs == 1.0) return; fprintf_s(mFile, "setAttr \".gs\" %f;\n", gs);}
	/*Defines the color of the fur base.*/
	void setBaseColor(const float3& dbc){if(dbc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".dbc\" -type \"float3\" ");dbc.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the color of the fur base.*/
	void setBaseColor(const Float3ID& dbc){fprintf_s(mFile,"connectAttr \"");dbc.write(mFile);fprintf_s(mFile,"\" \"%s.dbc\";\n",mName.c_str());}
	/*Defines the Red channel of the fur base.*/
	void setBaseColorR(float dbcr){if(dbcr == 1.0) return; fprintf_s(mFile, "setAttr \".dbcr\" %f;\n", dbcr);}
	/*Defines the Red channel of the fur base.*/
	void setBaseColorR(const FloatID& dbcr){fprintf_s(mFile,"connectAttr \"");dbcr.write(mFile);fprintf_s(mFile,"\" \"%s.dbcr\";\n",mName.c_str());}
	/*Defines the GREEN channel of the fur base.*/
	void setBaseColorG(float dbcg){if(dbcg == 1.0) return; fprintf_s(mFile, "setAttr \".dbcg\" %f;\n", dbcg);}
	/*Defines the GREEN channel of the fur base.*/
	void setBaseColorG(const FloatID& dbcg){fprintf_s(mFile,"connectAttr \"");dbcg.write(mFile);fprintf_s(mFile,"\" \"%s.dbcg\";\n",mName.c_str());}
	/*Defines the Blue channel of the fur base.*/
	void setBaseColorB(float dbcb){if(dbcb == 1.0) return; fprintf_s(mFile, "setAttr \".dbcb\" %f;\n", dbcb);}
	/*Defines the Blue channel of the fur base.*/
	void setBaseColorB(const FloatID& dbcb){fprintf_s(mFile,"connectAttr \"");dbcb.write(mFile);fprintf_s(mFile,"\" \"%s.dbcb\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseColor" along U direction by importing file textures.*/
	void setBaseColorMapUSamples(const BaseColorMapUSamplesID& bcmus){fprintf_s(mFile,"connectAttr \"");bcmus.write(mFile);fprintf_s(mFile,"\" \"%s.bcmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseColor" along V direction by importing file textures.*/
	void setBaseColorMapVSamples(const BaseColorMapVSamplesID& bcmvs){fprintf_s(mFile,"connectAttr \"");bcmvs.write(mFile);fprintf_s(mFile,"\" \"%s.bcmvs\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseColorNoise(float bcn){if(bcn == 0.0) return; fprintf_s(mFile, "setAttr \".bcn\" %f;\n", bcn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseColorNoise(const FloatID& bcn){fprintf_s(mFile,"connectAttr \"");bcn.write(mFile);fprintf_s(mFile,"\" \"%s.bcn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseColorNoiseFreq(float bcnf){if(bcnf == 10.0) return; fprintf_s(mFile, "setAttr \".bcnf\" %f;\n", bcnf);}
	/*Defines the color of the fur tip.*/
	void setTipColor(const float3& dtc){if(dtc == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".dtc\" -type \"float3\" ");dtc.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the color of the fur tip.*/
	void setTipColor(const Float3ID& dtc){fprintf_s(mFile,"connectAttr \"");dtc.write(mFile);fprintf_s(mFile,"\" \"%s.dtc\";\n",mName.c_str());}
	/*Defines the red channel of the fur tip.*/
	void setTipColorR(float dtcr){if(dtcr == 1.0) return; fprintf_s(mFile, "setAttr \".dtcr\" %f;\n", dtcr);}
	/*Defines the red channel of the fur tip.*/
	void setTipColorR(const FloatID& dtcr){fprintf_s(mFile,"connectAttr \"");dtcr.write(mFile);fprintf_s(mFile,"\" \"%s.dtcr\";\n",mName.c_str());}
	/*Defines the green channel of the fur tip.*/
	void setTipColorG(float dtcg){if(dtcg == 1.0) return; fprintf_s(mFile, "setAttr \".dtcg\" %f;\n", dtcg);}
	/*Defines the green channel of the fur tip.*/
	void setTipColorG(const FloatID& dtcg){fprintf_s(mFile,"connectAttr \"");dtcg.write(mFile);fprintf_s(mFile,"\" \"%s.dtcg\";\n",mName.c_str());}
	/*Defines the blue channel of the fur tip.*/
	void setTipColorB(float dtcb){if(dtcb == 1.0) return; fprintf_s(mFile, "setAttr \".dtcb\" %f;\n", dtcb);}
	/*Defines the blue channel of the fur tip.*/
	void setTipColorB(const FloatID& dtcb){fprintf_s(mFile,"connectAttr \"");dtcb.write(mFile);fprintf_s(mFile,"\" \"%s.dtcb\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipColor" along U direction by importing file textures.*/
	void setTipColorMapUSamples(const TipColorMapUSamplesID& tcmus){fprintf_s(mFile,"connectAttr \"");tcmus.write(mFile);fprintf_s(mFile,"\" \"%s.tcmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipColor" along V direction by importing file textures.*/
	void setTipColorMapVSamples(const TipColorMapVSamplesID& tcmvs){fprintf_s(mFile,"connectAttr \"");tcmvs.write(mFile);fprintf_s(mFile,"\" \"%s.tcmvs\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipColorNoise(float tcn){if(tcn == 0.0) return; fprintf_s(mFile, "setAttr \".tcn\" %f;\n", tcn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipColorNoise(const FloatID& tcn){fprintf_s(mFile,"connectAttr \"");tcn.write(mFile);fprintf_s(mFile,"\" \"%s.tcn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipColorNoiseFreq(float tcnf){if(tcnf == 10.0) return; fprintf_s(mFile, "setAttr \".tcnf\" %f;\n", tcnf);}
	/*Defines the ambient color of the fur base.*/
	void setBaseAmbientColor(const float3& dbac){if(dbac == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".dbac\" -type \"float3\" ");dbac.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the ambient color of the fur base.*/
	void setBaseAmbientColor(const Float3ID& dbac){fprintf_s(mFile,"connectAttr \"");dbac.write(mFile);fprintf_s(mFile,"\" \"%s.dbac\";\n",mName.c_str());}
	/*Defines the ambient red channel of the fur base.*/
	void setBaseAmbientColorR(float dbacr){if(dbacr == 0.0) return; fprintf_s(mFile, "setAttr \".dbacr\" %f;\n", dbacr);}
	/*Defines the ambient red channel of the fur base.*/
	void setBaseAmbientColorR(const FloatID& dbacr){fprintf_s(mFile,"connectAttr \"");dbacr.write(mFile);fprintf_s(mFile,"\" \"%s.dbacr\";\n",mName.c_str());}
	/*Defines the ambient green channel of the fur base.*/
	void setBaseAmbientColorG(float dbacg){if(dbacg == 0.0) return; fprintf_s(mFile, "setAttr \".dbacg\" %f;\n", dbacg);}
	/*Defines the ambient green channel of the fur base.*/
	void setBaseAmbientColorG(const FloatID& dbacg){fprintf_s(mFile,"connectAttr \"");dbacg.write(mFile);fprintf_s(mFile,"\" \"%s.dbacg\";\n",mName.c_str());}
	/*Defines the ambient blue channel of the fur base.*/
	void setBaseAmbientColorB(float dbacb){if(dbacb == 0.0) return; fprintf_s(mFile, "setAttr \".dbacb\" %f;\n", dbacb);}
	/*Defines the ambient blue channel of the fur base.*/
	void setBaseAmbientColorB(const FloatID& dbacb){fprintf_s(mFile,"connectAttr \"");dbacb.write(mFile);fprintf_s(mFile,"\" \"%s.dbacb\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseAmbientColor" along U direction by importing file textures.*/
	void setBaseAmbientColorMapUSamples(const BaseAmbientColorMapUSamplesID& bacmus){fprintf_s(mFile,"connectAttr \"");bacmus.write(mFile);fprintf_s(mFile,"\" \"%s.bacmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseAmbientColor" along V direction by importing file textures.*/
	void setBaseAmbientColorMapVSamples(const BaseAmbientColorMapVSamplesID& bacmvs){fprintf_s(mFile,"connectAttr \"");bacmvs.write(mFile);fprintf_s(mFile,"\" \"%s.bacmvs\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseAmbientColorNoise(float bacn){if(bacn == 0.0) return; fprintf_s(mFile, "setAttr \".bacn\" %f;\n", bacn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseAmbientColorNoise(const FloatID& bacn){fprintf_s(mFile,"connectAttr \"");bacn.write(mFile);fprintf_s(mFile,"\" \"%s.bacn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseAmbientColorNoiseFreq(float bacnf){if(bacnf == 10.0) return; fprintf_s(mFile, "setAttr \".bacnf\" %f;\n", bacnf);}
	/*Defines the ambient color of the fur tip.*/
	void setTipAmbientColor(const float3& dtac){if(dtac == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".dtac\" -type \"float3\" ");dtac.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the ambient color of the fur tip.*/
	void setTipAmbientColor(const Float3ID& dtac){fprintf_s(mFile,"connectAttr \"");dtac.write(mFile);fprintf_s(mFile,"\" \"%s.dtac\";\n",mName.c_str());}
	/*Defines the ambient red channel of the fur tip.*/
	void setTipAmbientColorR(float dtacr){if(dtacr == 0.0) return; fprintf_s(mFile, "setAttr \".dtacr\" %f;\n", dtacr);}
	/*Defines the ambient red channel of the fur tip.*/
	void setTipAmbientColorR(const FloatID& dtacr){fprintf_s(mFile,"connectAttr \"");dtacr.write(mFile);fprintf_s(mFile,"\" \"%s.dtacr\";\n",mName.c_str());}
	/*Defines the ambient green channel of the fur tip.*/
	void setTipAmbientColorG(float dtacg){if(dtacg == 0.0) return; fprintf_s(mFile, "setAttr \".dtacg\" %f;\n", dtacg);}
	/*Defines the ambient green channel of the fur tip.*/
	void setTipAmbientColorG(const FloatID& dtacg){fprintf_s(mFile,"connectAttr \"");dtacg.write(mFile);fprintf_s(mFile,"\" \"%s.dtacg\";\n",mName.c_str());}
	/*Defines the ambient blue channel of the fur tip.*/
	void setTipAmbientColorB(float dtacb){if(dtacb == 0.0) return; fprintf_s(mFile, "setAttr \".dtacb\" %f;\n", dtacb);}
	/*Defines the ambient blue channel of the fur tip.*/
	void setTipAmbientColorB(const FloatID& dtacb){fprintf_s(mFile,"connectAttr \"");dtacb.write(mFile);fprintf_s(mFile,"\" \"%s.dtacb\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TpAmbientColor" along U direction by importing file textures.*/
	void setTipAmbientColorMapUSamples(const TipAmbientColorMapUSamplesID& tacmus){fprintf_s(mFile,"connectAttr \"");tacmus.write(mFile);fprintf_s(mFile,"\" \"%s.tacmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TpAmbientColor" along V direction by importing file textures.*/
	void setTipAmbientColorMapVSamples(const TipAmbientColorMapVSamplesID& tacmvs){fprintf_s(mFile,"connectAttr \"");tacmvs.write(mFile);fprintf_s(mFile,"\" \"%s.tacmvs\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipAmbientColorNoise(float tacn){if(tacn == 0.0) return; fprintf_s(mFile, "setAttr \".tacn\" %f;\n", tacn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipAmbientColorNoise(const FloatID& tacn){fprintf_s(mFile,"connectAttr \"");tacn.write(mFile);fprintf_s(mFile,"\" \"%s.tacn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipAmbientColorNoiseFreq(float tacnf){if(tacnf == 10.0) return; fprintf_s(mFile, "setAttr \".tacnf\" %f;\n", tacnf);}
	/*Defines the color of shiny highlights on the fur*/
	void setSpecularColor(const float3& dsc){if(dsc == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".dsc\" -type \"float3\" ");dsc.write(mFile);fprintf_s(mFile,";\n");}
	/*Defines the color of shiny highlights on the fur*/
	void setSpecularColor(const Float3ID& dsc){fprintf_s(mFile,"connectAttr \"");dsc.write(mFile);fprintf_s(mFile,"\" \"%s.dsc\";\n",mName.c_str());}
	/*Defines the red channel of shiny highlights on the fur*/
	void setSpecularColorR(float dscr){if(dscr == 0.5) return; fprintf_s(mFile, "setAttr \".dscr\" %f;\n", dscr);}
	/*Defines the red channel of shiny highlights on the fur*/
	void setSpecularColorR(const FloatID& dscr){fprintf_s(mFile,"connectAttr \"");dscr.write(mFile);fprintf_s(mFile,"\" \"%s.dscr\";\n",mName.c_str());}
	/*Defines the green channel of shiny highlights on the fur*/
	void setSpecularColorG(float dscg){if(dscg == 0.5) return; fprintf_s(mFile, "setAttr \".dscg\" %f;\n", dscg);}
	/*Defines the green channel of shiny highlights on the fur*/
	void setSpecularColorG(const FloatID& dscg){fprintf_s(mFile,"connectAttr \"");dscg.write(mFile);fprintf_s(mFile,"\" \"%s.dscg\";\n",mName.c_str());}
	/*Defines the blue channel of shiny highlights on the fur*/
	void setSpecularColorB(float dscb){if(dscb == 0.5) return; fprintf_s(mFile, "setAttr \".dscb\" %f;\n", dscb);}
	/*Defines the blue channel of shiny highlights on the fur*/
	void setSpecularColorB(const FloatID& dscb){fprintf_s(mFile,"connectAttr \"");dscb.write(mFile);fprintf_s(mFile,"\" \"%s.dscb\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "SpecularColor" along U direction by importing file textures.*/
	void setSpecularColorMapUSamples(const SpecularColorMapUSamplesID& scmus){fprintf_s(mFile,"connectAttr \"");scmus.write(mFile);fprintf_s(mFile,"\" \"%s.scmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "SpecularColor" along V direction by importing file textures.*/
	void setSpecularColorMapVSamples(const SpecularColorMapVSamplesID& scmvs){fprintf_s(mFile,"connectAttr \"");scmvs.write(mFile);fprintf_s(mFile,"\" \"%s.scmvs\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSpecularColorNoise(float scn){if(scn == 0.0) return; fprintf_s(mFile, "setAttr \".scn\" %f;\n", scn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSpecularColorNoise(const FloatID& scn){fprintf_s(mFile,"connectAttr \"");scn.write(mFile);fprintf_s(mFile,"\" \"%s.scn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setSpecularColorNoiseFreq(float scnf){if(scnf == 10.0) return; fprintf_s(mFile, "setAttr \".scnf\" %f;\n", scnf);}
	/*Defines the fur length in world units.*/
	void setLength(double dl){if(dl == 1) return; fprintf_s(mFile, "setAttr \".dl\" %f;\n", dl);}
	/*Defines the fur length in world units.*/
	void setLength(const DoubleID& dl){fprintf_s(mFile,"connectAttr \"");dl.write(mFile);fprintf_s(mFile,"\" \"%s.dl\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Length" along U direction by importing file textures.*/
	void setLengthMapUSamples(const LengthMapUSamplesID& lmus){fprintf_s(mFile,"connectAttr \"");lmus.write(mFile);fprintf_s(mFile,"\" \"%s.lmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Length" along V direction by importing file textures.*/
	void setLengthMapVSamples(const LengthMapVSamplesID& lmvs){fprintf_s(mFile,"connectAttr \"");lmvs.write(mFile);fprintf_s(mFile,"\" \"%s.lmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setLengthMapOffset(double lmo){if(lmo == 0) return; fprintf_s(mFile, "setAttr \".lmo\" %f;\n", lmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setLengthMapOffset(const DoubleID& lmo){fprintf_s(mFile,"connectAttr \"");lmo.write(mFile);fprintf_s(mFile,"\" \"%s.lmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setLengthMapMult(double lmm){if(lmm == 1) return; fprintf_s(mFile, "setAttr \".lmm\" %f;\n", lmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setLengthMapMult(const DoubleID& lmm){fprintf_s(mFile,"connectAttr \"");lmm.write(mFile);fprintf_s(mFile,"\" \"%s.lmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setLengthNoise(double ln){if(ln == 0) return; fprintf_s(mFile, "setAttr \".ln\" %f;\n", ln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setLengthNoise(const DoubleID& ln){fprintf_s(mFile,"connectAttr \"");ln.write(mFile);fprintf_s(mFile,"\" \"%s.ln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setLengthNoiseFreq(float lnf){if(lnf == 10.0) return; fprintf_s(mFile, "setAttr \".lnf\" %f;\n", lnf);}
	/*Defines the sharpness of the fur highlight. A larger number yields a sharper (smaller) specular highlight.*/
	void setSpecularSharpness(double dss){if(dss == 5) return; fprintf_s(mFile, "setAttr \".dss\" %f;\n", dss);}
	/*Defines the sharpness of the fur highlight. A larger number yields a sharper (smaller) specular highlight.*/
	void setSpecularSharpness(const DoubleID& dss){fprintf_s(mFile,"connectAttr \"");dss.write(mFile);fprintf_s(mFile,"\" \"%s.dss\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "SpecularSharpness" along U direction by importing file textures.*/
	void setSpecularSharpnessMapUSamples(const SpecularSharpnessMapUSamplesID& ssmus){fprintf_s(mFile,"connectAttr \"");ssmus.write(mFile);fprintf_s(mFile,"\" \"%s.ssmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "SpecularSharpness" along V direction by importing file textures.*/
	void setSpecularSharpnessMapVSamples(const SpecularSharpnessMapVSamplesID& ssmvs){fprintf_s(mFile,"connectAttr \"");ssmvs.write(mFile);fprintf_s(mFile,"\" \"%s.ssmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setSpecularSharpnessMapOffset(double ssmo){if(ssmo == 0) return; fprintf_s(mFile, "setAttr \".ssmo\" %f;\n", ssmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setSpecularSharpnessMapOffset(const DoubleID& ssmo){fprintf_s(mFile,"connectAttr \"");ssmo.write(mFile);fprintf_s(mFile,"\" \"%s.ssmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setSpecularSharpnessMapMult(double ssmm){if(ssmm == 1) return; fprintf_s(mFile, "setAttr \".ssmm\" %f;\n", ssmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setSpecularSharpnessMapMult(const DoubleID& ssmm){fprintf_s(mFile,"connectAttr \"");ssmm.write(mFile);fprintf_s(mFile,"\" \"%s.ssmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSpecularSharpnessNoise(double ssn){if(ssn == 0) return; fprintf_s(mFile, "setAttr \".ssn\" %f;\n", ssn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSpecularSharpnessNoise(const DoubleID& ssn){fprintf_s(mFile,"connectAttr \"");ssn.write(mFile);fprintf_s(mFile,"\" \"%s.ssn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setSpecularSharpnessNoiseFreq(float ssnf){if(ssnf == 10.0) return; fprintf_s(mFile, "setAttr \".ssnf\" %f;\n", ssnf);}
	/*
	Defines how much fur is on the surface.
	1.0-Full fur 0.0-Total baldness.
	*/
	void setBaldness(double db){if(db == 1) return; fprintf_s(mFile, "setAttr \".db\" %f;\n", db);}
	/*
	Defines how much fur is on the surface.
	1.0-Full fur 0.0-Total baldness.
	*/
	void setBaldness(const DoubleID& db){fprintf_s(mFile,"connectAttr \"");db.write(mFile);fprintf_s(mFile,"\" \"%s.db\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Baldness" along U direction by importing file textures.*/
	void setBaldnessMapUSamples(const BaldnessMapUSamplesID& bmus){fprintf_s(mFile,"connectAttr \"");bmus.write(mFile);fprintf_s(mFile,"\" \"%s.bmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Baldness" along V direction by importing file textures.*/
	void setBaldnessMapVSamples(const BaldnessMapVSamplesID& bmvs){fprintf_s(mFile,"connectAttr \"");bmvs.write(mFile);fprintf_s(mFile,"\" \"%s.bmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaldnessMapOffset(double bmo){if(bmo == 0) return; fprintf_s(mFile, "setAttr \".bmo\" %f;\n", bmo);}
	/*Defines to set the factor to offset fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaldnessMapOffset(const DoubleID& bmo){fprintf_s(mFile,"connectAttr \"");bmo.write(mFile);fprintf_s(mFile,"\" \"%s.bmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaldnessMapMult(double bmm){if(bmm == 1) return; fprintf_s(mFile, "setAttr \".bmm\" %f;\n", bmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaldnessMapMult(const DoubleID& bmm){fprintf_s(mFile,"connectAttr \"");bmm.write(mFile);fprintf_s(mFile,"\" \"%s.bmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaldnessNoise(double bn){if(bn == 0) return; fprintf_s(mFile, "setAttr \".bn\" %f;\n", bn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaldnessNoise(const DoubleID& bn){fprintf_s(mFile,"connectAttr \"");bn.write(mFile);fprintf_s(mFile,"\" \"%s.bn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaldnessNoiseFreq(float bnf){if(bnf == 10.0) return; fprintf_s(mFile, "setAttr \".bnf\" %f;\n", bnf);}
	/*
	Defines the opacity of the fur base.
	0.0-Completely transparent base. 1.0-Completely opaque base.
	*/
	void setBaseOpacity(double dbo){if(dbo == 1) return; fprintf_s(mFile, "setAttr \".dbo\" %f;\n", dbo);}
	/*
	Defines the opacity of the fur base.
	0.0-Completely transparent base. 1.0-Completely opaque base.
	*/
	void setBaseOpacity(const DoubleID& dbo){fprintf_s(mFile,"connectAttr \"");dbo.write(mFile);fprintf_s(mFile,"\" \"%s.dbo\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseOpacity" along U direction by importing file textures.*/
	void setBaseOpacityMapUSamples(const BaseOpacityMapUSamplesID& bomus){fprintf_s(mFile,"connectAttr \"");bomus.write(mFile);fprintf_s(mFile,"\" \"%s.bomus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseOpacity" along V direction by importing file textures.*/
	void setBaseOpacityMapVSamples(const BaseOpacityMapVSamplesID& bomvs){fprintf_s(mFile,"connectAttr \"");bomvs.write(mFile);fprintf_s(mFile,"\" \"%s.bomvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaseOpacityMapOffset(double bomo){if(bomo == 0) return; fprintf_s(mFile, "setAttr \".bomo\" %f;\n", bomo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaseOpacityMapOffset(const DoubleID& bomo){fprintf_s(mFile,"connectAttr \"");bomo.write(mFile);fprintf_s(mFile,"\" \"%s.bomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseOpacityMapMult(double bomm){if(bomm == 1) return; fprintf_s(mFile, "setAttr \".bomm\" %f;\n", bomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseOpacityMapMult(const DoubleID& bomm){fprintf_s(mFile,"connectAttr \"");bomm.write(mFile);fprintf_s(mFile,"\" \"%s.bomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseOpacityNoise(double bon){if(bon == 0) return; fprintf_s(mFile, "setAttr \".bon\" %f;\n", bon);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseOpacityNoise(const DoubleID& bon){fprintf_s(mFile,"connectAttr \"");bon.write(mFile);fprintf_s(mFile,"\" \"%s.bon\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseOpacityNoiseFreq(float bonf){if(bonf == 10.0) return; fprintf_s(mFile, "setAttr \".bonf\" %f;\n", bonf);}
	/*
	Defines the opacity of the fur tip.
	0.0-Completely transparent tip. 1.0-Completely opaque tip.
	*/
	void setTipOpacity(double dto){if(dto == 1) return; fprintf_s(mFile, "setAttr \".dto\" %f;\n", dto);}
	/*
	Defines the opacity of the fur tip.
	0.0-Completely transparent tip. 1.0-Completely opaque tip.
	*/
	void setTipOpacity(const DoubleID& dto){fprintf_s(mFile,"connectAttr \"");dto.write(mFile);fprintf_s(mFile,"\" \"%s.dto\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipOpacity" along U direction by importing file textures.*/
	void setTipOpacityMapUSamples(const TipOpacityMapUSamplesID& tomus){fprintf_s(mFile,"connectAttr \"");tomus.write(mFile);fprintf_s(mFile,"\" \"%s.tomus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipOpacity" along V direction by importing file textures.*/
	void setTipOpacityMapVSamples(const TipOpacityMapVSamplesID& tomvs){fprintf_s(mFile,"connectAttr \"");tomvs.write(mFile);fprintf_s(mFile,"\" \"%s.tomvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setTipOpacityMapOffset(double tomo){if(tomo == 0) return; fprintf_s(mFile, "setAttr \".tomo\" %f;\n", tomo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setTipOpacityMapOffset(const DoubleID& tomo){fprintf_s(mFile,"connectAttr \"");tomo.write(mFile);fprintf_s(mFile,"\" \"%s.tomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipOpacityMapMult(double tomm){if(tomm == 1) return; fprintf_s(mFile, "setAttr \".tomm\" %f;\n", tomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipOpacityMapMult(const DoubleID& tomm){fprintf_s(mFile,"connectAttr \"");tomm.write(mFile);fprintf_s(mFile,"\" \"%s.tomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipOpacityNoise(double ton){if(ton == 0) return; fprintf_s(mFile, "setAttr \".ton\" %f;\n", ton);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipOpacityNoise(const DoubleID& ton){fprintf_s(mFile,"connectAttr \"");ton.write(mFile);fprintf_s(mFile,"\" \"%s.ton\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipOpacityNoiseFreq(float tonf){if(tonf == 10.0) return; fprintf_s(mFile, "setAttr \".tonf\" %f;\n", tonf);}
	/*Defines the width of each hair at the base, in world units.*/
	void setBaseWidth(double dbw){if(dbw == 0) return; fprintf_s(mFile, "setAttr \".dbw\" %f;\n", dbw);}
	/*Defines the width of each hair at the base, in world units.*/
	void setBaseWidth(const DoubleID& dbw){fprintf_s(mFile,"connectAttr \"");dbw.write(mFile);fprintf_s(mFile,"\" \"%s.dbw\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseWidth" along U direction by importing file textures.*/
	void setBaseWidthMapUSamples(const BaseWidthMapUSamplesID& bwmus){fprintf_s(mFile,"connectAttr \"");bwmus.write(mFile);fprintf_s(mFile,"\" \"%s.bwmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseWidth" along V direction by importing file textures.*/
	void setBaseWidthMapVSamples(const BaseWidthMapVSamplesID& bwmvs){fprintf_s(mFile,"connectAttr \"");bwmvs.write(mFile);fprintf_s(mFile,"\" \"%s.bwmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaseWidthMapOffset(double bwmo){if(bwmo == 0) return; fprintf_s(mFile, "setAttr \".bwmo\" %f;\n", bwmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaseWidthMapOffset(const DoubleID& bwmo){fprintf_s(mFile,"connectAttr \"");bwmo.write(mFile);fprintf_s(mFile,"\" \"%s.bwmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseWidthMapMult(double bwmm){if(bwmm == 1) return; fprintf_s(mFile, "setAttr \".bwmm\" %f;\n", bwmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseWidthMapMult(const DoubleID& bwmm){fprintf_s(mFile,"connectAttr \"");bwmm.write(mFile);fprintf_s(mFile,"\" \"%s.bwmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseWidthNoise(double bwn){if(bwn == 0) return; fprintf_s(mFile, "setAttr \".bwn\" %f;\n", bwn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseWidthNoise(const DoubleID& bwn){fprintf_s(mFile,"connectAttr \"");bwn.write(mFile);fprintf_s(mFile,"\" \"%s.bwn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseWidthNoiseFreq(float bwnf){if(bwnf == 10.0) return; fprintf_s(mFile, "setAttr \".bwnf\" %f;\n", bwnf);}
	/*Defines the width of each hair at the tip, in world units.*/
	void setTipWidth(double dtw){if(dtw == 0) return; fprintf_s(mFile, "setAttr \".dtw\" %f;\n", dtw);}
	/*Defines the width of each hair at the tip, in world units.*/
	void setTipWidth(const DoubleID& dtw){fprintf_s(mFile,"connectAttr \"");dtw.write(mFile);fprintf_s(mFile,"\" \"%s.dtw\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipWidth" along U direction by importing file textures.*/
	void setTipWidthMapUSamples(const TipWidthMapUSamplesID& twmus){fprintf_s(mFile,"connectAttr \"");twmus.write(mFile);fprintf_s(mFile,"\" \"%s.twmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipWidth" along V direction by importing file textures.*/
	void setTipWidthMapVSamples(const TipWidthMapVSamplesID& twmvs){fprintf_s(mFile,"connectAttr \"");twmvs.write(mFile);fprintf_s(mFile,"\" \"%s.twmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setTipWidthMapOffset(double twmo){if(twmo == 0) return; fprintf_s(mFile, "setAttr \".twmo\" %f;\n", twmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setTipWidthMapOffset(const DoubleID& twmo){fprintf_s(mFile,"connectAttr \"");twmo.write(mFile);fprintf_s(mFile,"\" \"%s.twmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipWidthMapMult(double twmm){if(twmm == 1) return; fprintf_s(mFile, "setAttr \".twmm\" %f;\n", twmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipWidthMapMult(const DoubleID& twmm){fprintf_s(mFile,"connectAttr \"");twmm.write(mFile);fprintf_s(mFile,"\" \"%s.twmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipWidthNoise(double twn){if(twn == 0) return; fprintf_s(mFile, "setAttr \".twn\" %f;\n", twn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipWidthNoise(const DoubleID& twn){fprintf_s(mFile,"connectAttr \"");twn.write(mFile);fprintf_s(mFile,"\" \"%s.twn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipWidthNoiseFreq(float twnf){if(twnf == 10.0) return; fprintf_s(mFile, "setAttr \".twnf\" %f;\n", twnf);}
	/*Defines the number of segments each fur is comprised of. For smoother curves, use more segments*/
	void setSegments(double dsg){if(dsg == 1) return; fprintf_s(mFile, "setAttr \".dsg\" %f;\n", dsg);}
	/*Defines the number of segments each fur is comprised of. For smoother curves, use more segments*/
	void setSegments(const DoubleID& dsg){fprintf_s(mFile,"connectAttr \"");dsg.write(mFile);fprintf_s(mFile,"\" \"%s.dsg\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Segments" along U direction by importing file textures.*/
	void setSegmentsMapUSamples(const SegmentsMapUSamplesID& sgmus){fprintf_s(mFile,"connectAttr \"");sgmus.write(mFile);fprintf_s(mFile,"\" \"%s.sgmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Segments" along V direction by importing file textures.*/
	void setSegmentsMapVSamples(const SegmentsMapVSamplesID& sgmvs){fprintf_s(mFile,"connectAttr \"");sgmvs.write(mFile);fprintf_s(mFile,"\" \"%s.sgmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setSegmentsMapOffset(double sgmo){if(sgmo == 0) return; fprintf_s(mFile, "setAttr \".sgmo\" %f;\n", sgmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setSegmentsMapOffset(const DoubleID& sgmo){fprintf_s(mFile,"connectAttr \"");sgmo.write(mFile);fprintf_s(mFile,"\" \"%s.sgmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setSegmentsMapMult(double sgmm){if(sgmm == 1) return; fprintf_s(mFile, "setAttr \".sgmm\" %f;\n", sgmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setSegmentsMapMult(const DoubleID& sgmm){fprintf_s(mFile,"connectAttr \"");sgmm.write(mFile);fprintf_s(mFile,"\" \"%s.sgmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSegmentsNoise(double sgn){if(sgn == 0) return; fprintf_s(mFile, "setAttr \".sgn\" %f;\n", sgn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setSegmentsNoise(const DoubleID& sgn){fprintf_s(mFile,"connectAttr \"");sgn.write(mFile);fprintf_s(mFile,"\" \"%s.sgn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setSegmentsNoiseFreq(float sgnf){if(sgnf == 10.0) return; fprintf_s(mFile, "setAttr \".sgnf\" %f;\n", sgnf);}
	/*
	Defines the amount of curl at the base of the fur. The fur tip is not influenced by this value.
	0.0- Half-circle curl to one side. 0.5-No curl. 1.0-Half-circle curl to the other side.
	*/
	void setBaseCurl(double dbcl){if(dbcl == 0) return; fprintf_s(mFile, "setAttr \".dbcl\" %f;\n", dbcl);}
	/*
	Defines the amount of curl at the base of the fur. The fur tip is not influenced by this value.
	0.0- Half-circle curl to one side. 0.5-No curl. 1.0-Half-circle curl to the other side.
	*/
	void setBaseCurl(const DoubleID& dbcl){fprintf_s(mFile,"connectAttr \"");dbcl.write(mFile);fprintf_s(mFile,"\" \"%s.dbcl\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseCurl" along U direction by importing file textures.*/
	void setBaseCurlMapUSamples(const BaseCurlMapUSamplesID& bclmus){fprintf_s(mFile,"connectAttr \"");bclmus.write(mFile);fprintf_s(mFile,"\" \"%s.bclmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "BaseCurl" along V direction by importing file textures.*/
	void setBaseCurlMapVSamples(const BaseCurlMapVSamplesID& bclmvs){fprintf_s(mFile,"connectAttr \"");bclmvs.write(mFile);fprintf_s(mFile,"\" \"%s.bclmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaseCurlMapOffset(double bclmo){if(bclmo == 0) return; fprintf_s(mFile, "setAttr \".bclmo\" %f;\n", bclmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setBaseCurlMapOffset(const DoubleID& bclmo){fprintf_s(mFile,"connectAttr \"");bclmo.write(mFile);fprintf_s(mFile,"\" \"%s.bclmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseCurlMapMult(double bclmm){if(bclmm == 1) return; fprintf_s(mFile, "setAttr \".bclmm\" %f;\n", bclmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setBaseCurlMapMult(const DoubleID& bclmm){fprintf_s(mFile,"connectAttr \"");bclmm.write(mFile);fprintf_s(mFile,"\" \"%s.bclmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseCurlNoise(double bcln){if(bcln == 0) return; fprintf_s(mFile, "setAttr \".bcln\" %f;\n", bcln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setBaseCurlNoise(const DoubleID& bcln){fprintf_s(mFile,"connectAttr \"");bcln.write(mFile);fprintf_s(mFile,"\" \"%s.bcln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setBaseCurlNoiseFreq(float bclnf){if(bclnf == 10.0) return; fprintf_s(mFile, "setAttr \".bclnf\" %f;\n", bclnf);}
	/*
	Defines the amount of curl at the tip of the fur. The fur base is not influenced by this value.
	0.0-Half-circle curl to one side. 0.5-No curl. 1.0- Half-circle curl to the other side
	*/
	void setTipCurl(double dtcl){if(dtcl == 0) return; fprintf_s(mFile, "setAttr \".dtcl\" %f;\n", dtcl);}
	/*
	Defines the amount of curl at the tip of the fur. The fur base is not influenced by this value.
	0.0-Half-circle curl to one side. 0.5-No curl. 1.0- Half-circle curl to the other side
	*/
	void setTipCurl(const DoubleID& dtcl){fprintf_s(mFile,"connectAttr \"");dtcl.write(mFile);fprintf_s(mFile,"\" \"%s.dtcl\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipCurl" along U direction by importing file textures.*/
	void setTipCurlMapUSamples(const TipCurlMapUSamplesID& tclmus){fprintf_s(mFile,"connectAttr \"");tclmus.write(mFile);fprintf_s(mFile,"\" \"%s.tclmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "TipCurl" along V direction by importing file textures.*/
	void setTipCurlMapVSamples(const TipCurlMapVSamplesID& tclmvs){fprintf_s(mFile,"connectAttr \"");tclmvs.write(mFile);fprintf_s(mFile,"\" \"%s.tclmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setTipCurlMapOffset(double tclmo){if(tclmo == 0) return; fprintf_s(mFile, "setAttr \".tclmo\" %f;\n", tclmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setTipCurlMapOffset(const DoubleID& tclmo){fprintf_s(mFile,"connectAttr \"");tclmo.write(mFile);fprintf_s(mFile,"\" \"%s.tclmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipCurlMapMult(double tclmm){if(tclmm == 1) return; fprintf_s(mFile, "setAttr \".tclmm\" %f;\n", tclmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setTipCurlMapMult(const DoubleID& tclmm){fprintf_s(mFile,"connectAttr \"");tclmm.write(mFile);fprintf_s(mFile,"\" \"%s.tclmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipCurlNoise(double tcln){if(tcln == 0) return; fprintf_s(mFile, "setAttr \".tcln\" %f;\n", tcln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setTipCurlNoise(const DoubleID& tcln){fprintf_s(mFile,"connectAttr \"");tcln.write(mFile);fprintf_s(mFile,"\" \"%s.tcln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setTipCurlNoiseFreq(float tclnf){if(tclnf == 10.0) return; fprintf_s(mFile, "setAttr \".tclnf\" %f;\n", tclnf);}
	/*
	Defines how crooked the fur is.
	0.0-No scraggle. 1.0-Full scraggle.
	*/
	void setScraggle(double ds){if(ds == 0) return; fprintf_s(mFile, "setAttr \".ds\" %f;\n", ds);}
	/*
	Defines how crooked the fur is.
	0.0-No scraggle. 1.0-Full scraggle.
	*/
	void setScraggle(const DoubleID& ds){fprintf_s(mFile,"connectAttr \"");ds.write(mFile);fprintf_s(mFile,"\" \"%s.ds\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Scraggle" along U direction by importing file textures.*/
	void setScraggleMapUSamples(const ScraggleMapUSamplesID& smus){fprintf_s(mFile,"connectAttr \"");smus.write(mFile);fprintf_s(mFile,"\" \"%s.smus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Scraggle" along V direction by importing file textures.*/
	void setScraggleMapVSamples(const ScraggleMapVSamplesID& smvs){fprintf_s(mFile,"connectAttr \"");smvs.write(mFile);fprintf_s(mFile,"\" \"%s.smvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setScraggleMapOffset(double smo){if(smo == 0) return; fprintf_s(mFile, "setAttr \".smo\" %f;\n", smo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setScraggleMapOffset(const DoubleID& smo){fprintf_s(mFile,"connectAttr \"");smo.write(mFile);fprintf_s(mFile,"\" \"%s.smo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleMapMult(double smm){if(smm == 1) return; fprintf_s(mFile, "setAttr \".smm\" %f;\n", smm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleMapMult(const DoubleID& smm){fprintf_s(mFile,"connectAttr \"");smm.write(mFile);fprintf_s(mFile,"\" \"%s.smm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleNoise(double sn){if(sn == 0) return; fprintf_s(mFile, "setAttr \".sn\" %f;\n", sn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleNoise(const DoubleID& sn){fprintf_s(mFile,"connectAttr \"");sn.write(mFile);fprintf_s(mFile,"\" \"%s.sn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleNoiseFreq(float snf){if(snf == 10.0) return; fprintf_s(mFile, "setAttr \".snf\" %f;\n", snf);}
	/*Defines the amount of change over each length of hair. The higher the value, the more changes there will be along each length of hair (the hair becomes more deformed).*/
	void setScraggleFrequency(double dsf){if(dsf == 5) return; fprintf_s(mFile, "setAttr \".dsf\" %f;\n", dsf);}
	/*Defines the amount of change over each length of hair. The higher the value, the more changes there will be along each length of hair (the hair becomes more deformed).*/
	void setScraggleFrequency(const DoubleID& dsf){fprintf_s(mFile,"connectAttr \"");dsf.write(mFile);fprintf_s(mFile,"\" \"%s.dsf\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ScraggleFrequency" along U direction by importing file textures.*/
	void setScraggleFrequencyMapUSamples(const ScraggleFrequencyMapUSamplesID& sfmus){fprintf_s(mFile,"connectAttr \"");sfmus.write(mFile);fprintf_s(mFile,"\" \"%s.sfmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ScraggleFrequency" along V direction by importing file textures.*/
	void setScraggleFrequencyMapVSamples(const ScraggleFrequencyMapVSamplesID& sfmvs){fprintf_s(mFile,"connectAttr \"");sfmvs.write(mFile);fprintf_s(mFile,"\" \"%s.sfmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapOffset(double sfmo){if(sfmo == 0) return; fprintf_s(mFile, "setAttr \".sfmo\" %f;\n", sfmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapOffset(const DoubleID& sfmo){fprintf_s(mFile,"connectAttr \"");sfmo.write(mFile);fprintf_s(mFile,"\" \"%s.sfmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapMult(double sfmm){if(sfmm == 1) return; fprintf_s(mFile, "setAttr \".sfmm\" %f;\n", sfmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleFrequencyMapMult(const DoubleID& sfmm){fprintf_s(mFile,"connectAttr \"");sfmm.write(mFile);fprintf_s(mFile,"\" \"%s.sfmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleFrequencyNoise(double sfn){if(sfn == 0) return; fprintf_s(mFile, "setAttr \".sfn\" %f;\n", sfn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleFrequencyNoise(const DoubleID& sfn){fprintf_s(mFile,"connectAttr \"");sfn.write(mFile);fprintf_s(mFile,"\" \"%s.sfn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleFrequencyNoiseFreq(float sfnf){if(sfnf == 10.0) return; fprintf_s(mFile, "setAttr \".sfnf\" %f;\n", sfnf);}
	/*
	Defines how the scraggle of each hair relates to each other hair.
	0.0-No correlation, so each hair has a unique scraggle. 1.0-Total correlation, so all hair "scraggles" in exactly the same way.
	*/
	void setScraggleCorrelation(double dsco){if(dsco == 0) return; fprintf_s(mFile, "setAttr \".dsco\" %f;\n", dsco);}
	/*
	Defines how the scraggle of each hair relates to each other hair.
	0.0-No correlation, so each hair has a unique scraggle. 1.0-Total correlation, so all hair "scraggles" in exactly the same way.
	*/
	void setScraggleCorrelation(const DoubleID& dsco){fprintf_s(mFile,"connectAttr \"");dsco.write(mFile);fprintf_s(mFile,"\" \"%s.dsco\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ScraggleCorrelation" along U direction by importing file textures.*/
	void setScraggleCorrelationMapUSamples(const ScraggleCorrelationMapUSamplesID& scomus){fprintf_s(mFile,"connectAttr \"");scomus.write(mFile);fprintf_s(mFile,"\" \"%s.scomus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ScraggleCorrelation" along V direction by importing file textures.*/
	void setScraggleCorrelationMapVSamples(const ScraggleCorrelationMapVSamplesID& scomvs){fprintf_s(mFile,"connectAttr \"");scomvs.write(mFile);fprintf_s(mFile,"\" \"%s.scomvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapOffset(double scomo){if(scomo == 0) return; fprintf_s(mFile, "setAttr \".scomo\" %f;\n", scomo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapOffset(const DoubleID& scomo){fprintf_s(mFile,"connectAttr \"");scomo.write(mFile);fprintf_s(mFile,"\" \"%s.scomo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapMult(double scomm){if(scomm == 1) return; fprintf_s(mFile, "setAttr \".scomm\" %f;\n", scomm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setScraggleCorrelationMapMult(const DoubleID& scomm){fprintf_s(mFile,"connectAttr \"");scomm.write(mFile);fprintf_s(mFile,"\" \"%s.scomm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleCorrelationNoise(double scon){if(scon == 0) return; fprintf_s(mFile, "setAttr \".scon\" %f;\n", scon);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setScraggleCorrelationNoise(const DoubleID& scon){fprintf_s(mFile,"connectAttr \"");scon.write(mFile);fprintf_s(mFile,"\" \"%s.scon\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setScraggleCorrelationNoiseFreq(float sconf){if(sconf == 10.0) return; fprintf_s(mFile, "setAttr \".sconf\" %f;\n", sconf);}
	/*
	Sets the amount of inclination.
	0.0-No inclination. The fur is fully erect (normal to the surface). This is the default.
	0.5-Partial inclination. 1.0- Fully inclined. The fur lies flat (tangent to the surface at the root).
	*/
	void setInclination(double di){if(di == 0) return; fprintf_s(mFile, "setAttr \".di\" %f;\n", di);}
	/*
	Sets the amount of inclination.
	0.0-No inclination. The fur is fully erect (normal to the surface). This is the default.
	0.5-Partial inclination. 1.0- Fully inclined. The fur lies flat (tangent to the surface at the root).
	*/
	void setInclination(const DoubleID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.di\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Inclination" along U direction by importing file textures.*/
	void setInclinationMapUSamples(const InclinationMapUSamplesID& imus){fprintf_s(mFile,"connectAttr \"");imus.write(mFile);fprintf_s(mFile,"\" \"%s.imus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Inclination" along V direction by importing file textures.*/
	void setInclinationMapVSamples(const InclinationMapVSamplesID& imvs){fprintf_s(mFile,"connectAttr \"");imvs.write(mFile);fprintf_s(mFile,"\" \"%s.imvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setInclinationMapOffset(double imo){if(imo == 0) return; fprintf_s(mFile, "setAttr \".imo\" %f;\n", imo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setInclinationMapOffset(const DoubleID& imo){fprintf_s(mFile,"connectAttr \"");imo.write(mFile);fprintf_s(mFile,"\" \"%s.imo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInclinationMapMult(double imm){if(imm == 1) return; fprintf_s(mFile, "setAttr \".imm\" %f;\n", imm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInclinationMapMult(const DoubleID& imm){fprintf_s(mFile,"connectAttr \"");imm.write(mFile);fprintf_s(mFile,"\" \"%s.imm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInclinationNoise(double in){if(in == 0) return; fprintf_s(mFile, "setAttr \".in\" %f;\n", in);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInclinationNoise(const DoubleID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setInclinationNoiseFreq(float inf){if(inf == 10.0) return; fprintf_s(mFile, "setAttr \".inf\" %f;\n", inf);}
	/*
	Rotates the fur about the surface V axis. You can achieve almost any fur angle using Polar and Inclination, so use this option only when the fur has curl and you want the curls to lie flat.
	0.0-90 degree rotation. 0.5-No rotation. This is the default.1.0-90 degree rotation.
	*/
	void setRoll(double dr){if(dr == 0) return; fprintf_s(mFile, "setAttr \".dr\" %f;\n", dr);}
	/*
	Rotates the fur about the surface V axis. You can achieve almost any fur angle using Polar and Inclination, so use this option only when the fur has curl and you want the curls to lie flat.
	0.0-90 degree rotation. 0.5-No rotation. This is the default.1.0-90 degree rotation.
	*/
	void setRoll(const DoubleID& dr){fprintf_s(mFile,"connectAttr \"");dr.write(mFile);fprintf_s(mFile,"\" \"%s.dr\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Roll" along U direction by importing file textures.*/
	void setRollMapUSamples(const RollMapUSamplesID& rmus){fprintf_s(mFile,"connectAttr \"");rmus.write(mFile);fprintf_s(mFile,"\" \"%s.rmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Roll" along V direction by importing file textures.*/
	void setRollMapVSamples(const RollMapVSamplesID& rmvs){fprintf_s(mFile,"connectAttr \"");rmvs.write(mFile);fprintf_s(mFile,"\" \"%s.rmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setRollMapOffset(double rmo){if(rmo == 0) return; fprintf_s(mFile, "setAttr \".rmo\" %f;\n", rmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setRollMapOffset(const DoubleID& rmo){fprintf_s(mFile,"connectAttr \"");rmo.write(mFile);fprintf_s(mFile,"\" \"%s.rmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRollMapMult(double rmm){if(rmm == 1) return; fprintf_s(mFile, "setAttr \".rmm\" %f;\n", rmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRollMapMult(const DoubleID& rmm){fprintf_s(mFile,"connectAttr \"");rmm.write(mFile);fprintf_s(mFile,"\" \"%s.rmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRollNoise(double rn){if(rn == 0) return; fprintf_s(mFile, "setAttr \".rn\" %f;\n", rn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRollNoise(const DoubleID& rn){fprintf_s(mFile,"connectAttr \"");rn.write(mFile);fprintf_s(mFile,"\" \"%s.rn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setRollNoiseFreq(float rnf){if(rnf == 10.0) return; fprintf_s(mFile, "setAttr \".rnf\" %f;\n", rnf);}
	/*
	Rotates the fur about the surface normal.
	0.0-180 degree rotation. 0.5-No rotation. This is the default. 1.0-180 degree rotation.
	*/
	void setPolar(double dp){if(dp == 0) return; fprintf_s(mFile, "setAttr \".dp\" %f;\n", dp);}
	/*
	Rotates the fur about the surface normal.
	0.0-180 degree rotation. 0.5-No rotation. This is the default. 1.0-180 degree rotation.
	*/
	void setPolar(const DoubleID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Polar" along U direction by importing file textures.*/
	void setPolarMapUSamples(const PolarMapUSamplesID& pmus){fprintf_s(mFile,"connectAttr \"");pmus.write(mFile);fprintf_s(mFile,"\" \"%s.pmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Polar" along V direction by importing file textures.*/
	void setPolarMapVSamples(const PolarMapVSamplesID& pmvs){fprintf_s(mFile,"connectAttr \"");pmvs.write(mFile);fprintf_s(mFile,"\" \"%s.pmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setPolarMapOffset(double pmo){if(pmo == 0) return; fprintf_s(mFile, "setAttr \".pmo\" %f;\n", pmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setPolarMapOffset(const DoubleID& pmo){fprintf_s(mFile,"connectAttr \"");pmo.write(mFile);fprintf_s(mFile,"\" \"%s.pmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPolarMapMult(double pmm){if(pmm == 1) return; fprintf_s(mFile, "setAttr \".pmm\" %f;\n", pmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPolarMapMult(const DoubleID& pmm){fprintf_s(mFile,"connectAttr \"");pmm.write(mFile);fprintf_s(mFile,"\" \"%s.pmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPolarNoise(double pn){if(pn == 0) return; fprintf_s(mFile, "setAttr \".pn\" %f;\n", pn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPolarNoise(const DoubleID& pn){fprintf_s(mFile,"connectAttr \"");pn.write(mFile);fprintf_s(mFile,"\" \"%s.pn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setPolarNoiseFreq(float pnf){if(pnf == 10.0) return; fprintf_s(mFile, "setAttr \".pnf\" %f;\n", pnf);}
	/*
	Defines the amount of attraction this fur description has towards attractors.
	0.0 No attraction. 1.0 Full attraction.
	*/
	void setAttraction(double dat){if(dat == 1) return; fprintf_s(mFile, "setAttr \".dat\" %f;\n", dat);}
	/*
	Defines the amount of attraction this fur description has towards attractors.
	0.0 No attraction. 1.0 Full attraction.
	*/
	void setAttraction(const DoubleID& dat){fprintf_s(mFile,"connectAttr \"");dat.write(mFile);fprintf_s(mFile,"\" \"%s.dat\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Attraction" along U direction by importing file textures.*/
	void setAttractionMapUSamples(const AttractionMapUSamplesID& atmus){fprintf_s(mFile,"connectAttr \"");atmus.write(mFile);fprintf_s(mFile,"\" \"%s.atmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Attraction" along V direction by importing file textures.*/
	void setAttractionMapVSamples(const AttractionMapVSamplesID& atmvs){fprintf_s(mFile,"connectAttr \"");atmvs.write(mFile);fprintf_s(mFile,"\" \"%s.atmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setAttractionMapOffset(double atmo){if(atmo == 0) return; fprintf_s(mFile, "setAttr \".atmo\" %f;\n", atmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setAttractionMapOffset(const DoubleID& atmo){fprintf_s(mFile,"connectAttr \"");atmo.write(mFile);fprintf_s(mFile,"\" \"%s.atmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setAttractionMapMult(double atmm){if(atmm == 1) return; fprintf_s(mFile, "setAttr \".atmm\" %f;\n", atmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setAttractionMapMult(const DoubleID& atmm){fprintf_s(mFile,"connectAttr \"");atmm.write(mFile);fprintf_s(mFile,"\" \"%s.atmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setAttractionNoise(double atn){if(atn == 0) return; fprintf_s(mFile, "setAttr \".atn\" %f;\n", atn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setAttractionNoise(const DoubleID& atn){fprintf_s(mFile,"connectAttr \"");atn.write(mFile);fprintf_s(mFile,"\" \"%s.atn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setAttractionNoiseFreq(float atnf){if(atnf == 10.0) return; fprintf_s(mFile, "setAttr \".atnf\" %f;\n", atnf);}
	/*
	Defines how much to offset the fur description (in world units) from the surface it is attached to.
	When the Offset value is 0, the roots of the fur hairs start growing from the surface.
	When the value is less than zero, the roots start growing from inside the surface.
	When the value is greater than zero, the roots start growing from outside the surface
	*/
	void setOffset(double dofs){if(dofs == 0) return; fprintf_s(mFile, "setAttr \".dofs\" %f;\n", dofs);}
	/*
	Defines how much to offset the fur description (in world units) from the surface it is attached to.
	When the Offset value is 0, the roots of the fur hairs start growing from the surface.
	When the value is less than zero, the roots start growing from inside the surface.
	When the value is greater than zero, the roots start growing from outside the surface
	*/
	void setOffset(const DoubleID& dofs){fprintf_s(mFile,"connectAttr \"");dofs.write(mFile);fprintf_s(mFile,"\" \"%s.dofs\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Offset" along U direction by importing file textures.*/
	void setOffsetMapUSamples(const OffsetMapUSamplesID& ofsmus){fprintf_s(mFile,"connectAttr \"");ofsmus.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Offset" along V direction by importing file textures.*/
	void setOffsetMapVSamples(const OffsetMapVSamplesID& ofsmvs){fprintf_s(mFile,"connectAttr \"");ofsmvs.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setOffsetMapOffset(double ofsmo){if(ofsmo == 0) return; fprintf_s(mFile, "setAttr \".ofsmo\" %f;\n", ofsmo);}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	void setOffsetMapOffset(const DoubleID& ofsmo){fprintf_s(mFile,"connectAttr \"");ofsmo.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setOffsetMapMult(double ofsmm){if(ofsmm == 1) return; fprintf_s(mFile, "setAttr \".ofsmm\" %f;\n", ofsmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setOffsetMapMult(const DoubleID& ofsmm){fprintf_s(mFile,"connectAttr \"");ofsmm.write(mFile);fprintf_s(mFile,"\" \"%s.ofsmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setOffsetNoise(double ofsn){if(ofsn == 0) return; fprintf_s(mFile, "setAttr \".ofsn\" %f;\n", ofsn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setOffsetNoise(const DoubleID& ofsn){fprintf_s(mFile,"connectAttr \"");ofsn.write(mFile);fprintf_s(mFile,"\" \"%s.ofsn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setOffsetNoiseFreq(float ofsnf){if(ofsnf == 10.0) return; fprintf_s(mFile, "setAttr \".ofsnf\" %f;\n", ofsnf);}
	/*
	The degree to which the hairs are pulled in towards the centreof the clump.
	The higher the clumping value, the more the hairs are pulled in.
	The defaultis 0, which means no clumping.
	*/
	void setClumping(float dc){if(dc == 0.0) return; fprintf_s(mFile, "setAttr \".dc\" %f;\n", dc);}
	/*
	The degree to which the hairs are pulled in towards the centreof the clump.
	The higher the clumping value, the more the hairs are pulled in.
	The defaultis 0, which means no clumping.
	*/
	void setClumping(const FloatID& dc){fprintf_s(mFile,"connectAttr \"");dc.write(mFile);fprintf_s(mFile,"\" \"%s.dc\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Clumping" along U direction by importing file textures.*/
	void setClumpingMapUSamples(const ClumpingMapUSamplesID& cmus){fprintf_s(mFile,"connectAttr \"");cmus.write(mFile);fprintf_s(mFile,"\" \"%s.cmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "Clumping" along V direction by importing file textures.*/
	void setClumpingMapVSamples(const ClumpingMapVSamplesID& cmvs){fprintf_s(mFile,"connectAttr \"");cmvs.write(mFile);fprintf_s(mFile,"\" \"%s.cmvs\";\n",mName.c_str());}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	void setClumpingMapOffset(float cmo){if(cmo == 0.0) return; fprintf_s(mFile, "setAttr \".cmo\" %f;\n", cmo);}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	void setClumpingMapOffset(const FloatID& cmo){fprintf_s(mFile,"connectAttr \"");cmo.write(mFile);fprintf_s(mFile,"\" \"%s.cmo\";\n",mName.c_str());}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingMapMult(float cmm){if(cmm == 1.0) return; fprintf_s(mFile, "setAttr \".cmm\" %f;\n", cmm);}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingMapMult(const FloatID& cmm){fprintf_s(mFile,"connectAttr \"");cmm.write(mFile);fprintf_s(mFile,"\" \"%s.cmm\";\n",mName.c_str());}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingNoise(float cn){if(cn == 0.0) return; fprintf_s(mFile, "setAttr \".cn\" %f;\n", cn);}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingNoise(const FloatID& cn){fprintf_s(mFile,"connectAttr \"");cn.write(mFile);fprintf_s(mFile,"\" \"%s.cn\";\n",mName.c_str());}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingNoiseFreq(float cnf){if(cnf == 10.0) return; fprintf_s(mFile, "setAttr \".cnf\" %f;\n", cnf);}
	/*
	Controls how many clumps occur across the surface.
	The higher the frequency, the greater the number, and therefore smaller-sized, clumps.
	The default is 50.As you increase the Clumping Frequency, the rendering time increases.
	*/
	void setClumpingFrequency(float dcf){if(dcf == 50) return; fprintf_s(mFile, "setAttr \".dcf\" %f;\n", dcf);}
	/*
	Controls how many clumps occur across the surface.
	The higher the frequency, the greater the number, and therefore smaller-sized, clumps.
	The default is 50.As you increase the Clumping Frequency, the rendering time increases.
	*/
	void setClumpingFrequency(const FloatID& dcf){fprintf_s(mFile,"connectAttr \"");dcf.write(mFile);fprintf_s(mFile,"\" \"%s.dcf\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ClumpingFrequency" along U direction by importing file textures.*/
	void setClumpingFrequencyMapUSamples(const ClumpingFrequencyMapUSamplesID& cfmus){fprintf_s(mFile,"connectAttr \"");cfmus.write(mFile);fprintf_s(mFile,"\" \"%s.cfmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ClumpingFrequency" along V direction by importing file textures.*/
	void setClumpingFrequencyMapVSamples(const ClumpingFrequencyMapVSamplesID& cfmvs){fprintf_s(mFile,"connectAttr \"");cfmvs.write(mFile);fprintf_s(mFile,"\" \"%s.cfmvs\";\n",mName.c_str());}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapOffset(float cfmo){if(cfmo == 0.0) return; fprintf_s(mFile, "setAttr \".cfmo\" %f;\n", cfmo);}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapOffset(const FloatID& cfmo){fprintf_s(mFile,"connectAttr \"");cfmo.write(mFile);fprintf_s(mFile,"\" \"%s.cfmo\";\n",mName.c_str());}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapMult(float cfmm){if(cfmm == 1.0) return; fprintf_s(mFile, "setAttr \".cfmm\" %f;\n", cfmm);}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpingFrequencyMapMult(const FloatID& cfmm){fprintf_s(mFile,"connectAttr \"");cfmm.write(mFile);fprintf_s(mFile,"\" \"%s.cfmm\";\n",mName.c_str());}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingFrequencyNoise(float cfn){if(cfn == 0.0) return; fprintf_s(mFile, "setAttr \".cfn\" %f;\n", cfn);}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpingFrequencyNoise(const FloatID& cfn){fprintf_s(mFile,"connectAttr \"");cfn.write(mFile);fprintf_s(mFile,"\" \"%s.cfn\";\n",mName.c_str());}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpingFrequencyNoiseFreq(float cfnf){if(cfnf == 10.0) return; fprintf_s(mFile, "setAttr \".cfnf\" %f;\n", cfnf);}
	/*
	Controls the shape of the curve of the hair as it is attracted to the center of the clump.
	A value of -10 creates a concave shape and a value of 10 creates a convex shape.
	*/
	void setClumpShape(float dcs){if(dcs == 0.0) return; fprintf_s(mFile, "setAttr \".dcs\" %f;\n", dcs);}
	/*
	Controls the shape of the curve of the hair as it is attracted to the center of the clump.
	A value of -10 creates a concave shape and a value of 10 creates a convex shape.
	*/
	void setClumpShape(const FloatID& dcs){fprintf_s(mFile,"connectAttr \"");dcs.write(mFile);fprintf_s(mFile,"\" \"%s.dcs\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ClumpShape" along U direction by importing file textures.*/
	void setClumpShapeMapUSamples(const ClumpShapeMapUSamplesID& csmus){fprintf_s(mFile,"connectAttr \"");csmus.write(mFile);fprintf_s(mFile,"\" \"%s.csmus\";\n",mName.c_str());}
	/*Used to map values for fur description attribute "ClumpShape" along V direction by importing file textures.*/
	void setClumpShapeMapVSamples(const ClumpShapeMapVSamplesID& csmvs){fprintf_s(mFile,"connectAttr \"");csmvs.write(mFile);fprintf_s(mFile,"\" \"%s.csmvs\";\n",mName.c_str());}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	void setClumpShapeMapOffset(float csmo){if(csmo == 0.0) return; fprintf_s(mFile, "setAttr \".csmo\" %f;\n", csmo);}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	void setClumpShapeMapOffset(const FloatID& csmo){fprintf_s(mFile,"connectAttr \"");csmo.write(mFile);fprintf_s(mFile,"\" \"%s.csmo\";\n",mName.c_str());}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpShapeMapMult(float csmm){if(csmm == 1.0) return; fprintf_s(mFile, "setAttr \".csmm\" %f;\n", csmm);}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setClumpShapeMapMult(const FloatID& csmm){fprintf_s(mFile,"connectAttr \"");csmm.write(mFile);fprintf_s(mFile,"\" \"%s.csmm\";\n",mName.c_str());}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpShapeNoise(float csn){if(csn == 0.0) return; fprintf_s(mFile, "setAttr \".csn\" %f;\n", csn);}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setClumpShapeNoise(const FloatID& csn){fprintf_s(mFile,"connectAttr \"");csn.write(mFile);fprintf_s(mFile,"\" \"%s.csn\";\n",mName.c_str());}
	/*Used to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setClumpShapeNoiseFreq(float csnf){if(csnf == 10.0) return; fprintf_s(mFile, "setAttr \".csnf\" %f;\n", csnf);}
	/*
	Defines the light model, which is applied to the fur description.
	Ambient(0): Only the Base Ambient Color and Tip Ambient Color of the fur are used in the final color calculation.
	Ambient + Diffuse(1): The Base Ambient Color and Tip Ambient Color values are added to the Base Color and Tip Color values respectively.
	Ambient + Diffuse + Specular(2): The Base Ambient Color and Tip Ambient Color values are added to the Base Color and Tip Color values respectively, and the Specular values are added to the hairs according to the Specular Sharpness.
	Specular(3): Only the Specular lights (highlights) for the fur are rendered.
	*/
	UnsignedintID getLightModel(){char buffer[4096];sprintf_s (buffer, "%s.lmd",mName.c_str());return (const char*)buffer;}
	/*Defines the color of the fur base.*/
	Float3ID getBaseColor(){char buffer[4096];sprintf_s (buffer, "%s.dbc",mName.c_str());return (const char*)buffer;}
	/*Defines the Red channel of the fur base.*/
	FloatID getBaseColorR(){char buffer[4096];sprintf_s (buffer, "%s.dbcr",mName.c_str());return (const char*)buffer;}
	/*Defines the GREEN channel of the fur base.*/
	FloatID getBaseColorG(){char buffer[4096];sprintf_s (buffer, "%s.dbcg",mName.c_str());return (const char*)buffer;}
	/*Defines the Blue channel of the fur base.*/
	FloatID getBaseColorB(){char buffer[4096];sprintf_s (buffer, "%s.dbcb",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseColor" along U direction by importing file textures.*/
	BaseColorMapUSamplesID getBaseColorMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.bcmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseColor" along V direction by importing file textures.*/
	BaseColorMapVSamplesID getBaseColorMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.bcmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getBaseColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.bcn",mName.c_str());return (const char*)buffer;}
	/*Defines the color of the fur tip.*/
	Float3ID getTipColor(){char buffer[4096];sprintf_s (buffer, "%s.dtc",mName.c_str());return (const char*)buffer;}
	/*Defines the red channel of the fur tip.*/
	FloatID getTipColorR(){char buffer[4096];sprintf_s (buffer, "%s.dtcr",mName.c_str());return (const char*)buffer;}
	/*Defines the green channel of the fur tip.*/
	FloatID getTipColorG(){char buffer[4096];sprintf_s (buffer, "%s.dtcg",mName.c_str());return (const char*)buffer;}
	/*Defines the blue channel of the fur tip.*/
	FloatID getTipColorB(){char buffer[4096];sprintf_s (buffer, "%s.dtcb",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipColor" along U direction by importing file textures.*/
	TipColorMapUSamplesID getTipColorMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.tcmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipColor" along V direction by importing file textures.*/
	TipColorMapVSamplesID getTipColorMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.tcmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getTipColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.tcn",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient color of the fur base.*/
	Float3ID getBaseAmbientColor(){char buffer[4096];sprintf_s (buffer, "%s.dbac",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient red channel of the fur base.*/
	FloatID getBaseAmbientColorR(){char buffer[4096];sprintf_s (buffer, "%s.dbacr",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient green channel of the fur base.*/
	FloatID getBaseAmbientColorG(){char buffer[4096];sprintf_s (buffer, "%s.dbacg",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient blue channel of the fur base.*/
	FloatID getBaseAmbientColorB(){char buffer[4096];sprintf_s (buffer, "%s.dbacb",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseAmbientColor" along U direction by importing file textures.*/
	BaseAmbientColorMapUSamplesID getBaseAmbientColorMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.bacmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseAmbientColor" along V direction by importing file textures.*/
	BaseAmbientColorMapVSamplesID getBaseAmbientColorMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.bacmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getBaseAmbientColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.bacn",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient color of the fur tip.*/
	Float3ID getTipAmbientColor(){char buffer[4096];sprintf_s (buffer, "%s.dtac",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient red channel of the fur tip.*/
	FloatID getTipAmbientColorR(){char buffer[4096];sprintf_s (buffer, "%s.dtacr",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient green channel of the fur tip.*/
	FloatID getTipAmbientColorG(){char buffer[4096];sprintf_s (buffer, "%s.dtacg",mName.c_str());return (const char*)buffer;}
	/*Defines the ambient blue channel of the fur tip.*/
	FloatID getTipAmbientColorB(){char buffer[4096];sprintf_s (buffer, "%s.dtacb",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TpAmbientColor" along U direction by importing file textures.*/
	TipAmbientColorMapUSamplesID getTipAmbientColorMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.tacmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TpAmbientColor" along V direction by importing file textures.*/
	TipAmbientColorMapVSamplesID getTipAmbientColorMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.tacmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getTipAmbientColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.tacn",mName.c_str());return (const char*)buffer;}
	/*Defines the color of shiny highlights on the fur*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.dsc",mName.c_str());return (const char*)buffer;}
	/*Defines the red channel of shiny highlights on the fur*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.dscr",mName.c_str());return (const char*)buffer;}
	/*Defines the green channel of shiny highlights on the fur*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.dscg",mName.c_str());return (const char*)buffer;}
	/*Defines the blue channel of shiny highlights on the fur*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.dscb",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "SpecularColor" along U direction by importing file textures.*/
	SpecularColorMapUSamplesID getSpecularColorMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.scmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "SpecularColor" along V direction by importing file textures.*/
	SpecularColorMapVSamplesID getSpecularColorMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.scmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getSpecularColorNoise(){char buffer[4096];sprintf_s (buffer, "%s.scn",mName.c_str());return (const char*)buffer;}
	/*Defines the fur length in world units.*/
	DoubleID getLength(){char buffer[4096];sprintf_s (buffer, "%s.dl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Length" along U direction by importing file textures.*/
	LengthMapUSamplesID getLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.lmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Length" along V direction by importing file textures.*/
	LengthMapVSamplesID getLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.lmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.lmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.lmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.ln",mName.c_str());return (const char*)buffer;}
	/*Defines the sharpness of the fur highlight. A larger number yields a sharper (smaller) specular highlight.*/
	DoubleID getSpecularSharpness(){char buffer[4096];sprintf_s (buffer, "%s.dss",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "SpecularSharpness" along U direction by importing file textures.*/
	SpecularSharpnessMapUSamplesID getSpecularSharpnessMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.ssmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "SpecularSharpness" along V direction by importing file textures.*/
	SpecularSharpnessMapVSamplesID getSpecularSharpnessMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.ssmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getSpecularSharpnessMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.ssmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getSpecularSharpnessMapMult(){char buffer[4096];sprintf_s (buffer, "%s.ssmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getSpecularSharpnessNoise(){char buffer[4096];sprintf_s (buffer, "%s.ssn",mName.c_str());return (const char*)buffer;}
	/*
	Defines how much fur is on the surface.
	1.0-Full fur 0.0-Total baldness.
	*/
	DoubleID getBaldness(){char buffer[4096];sprintf_s (buffer, "%s.db",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Baldness" along U direction by importing file textures.*/
	BaldnessMapUSamplesID getBaldnessMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.bmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Baldness" along V direction by importing file textures.*/
	BaldnessMapVSamplesID getBaldnessMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.bmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getBaldnessMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getBaldnessMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getBaldnessNoise(){char buffer[4096];sprintf_s (buffer, "%s.bn",mName.c_str());return (const char*)buffer;}
	/*
	Defines the opacity of the fur base.
	0.0-Completely transparent base. 1.0-Completely opaque base.
	*/
	DoubleID getBaseOpacity(){char buffer[4096];sprintf_s (buffer, "%s.dbo",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseOpacity" along U direction by importing file textures.*/
	BaseOpacityMapUSamplesID getBaseOpacityMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.bomus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseOpacity" along V direction by importing file textures.*/
	BaseOpacityMapVSamplesID getBaseOpacityMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.bomvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getBaseOpacityMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getBaseOpacityMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getBaseOpacityNoise(){char buffer[4096];sprintf_s (buffer, "%s.bon",mName.c_str());return (const char*)buffer;}
	/*
	Defines the opacity of the fur tip.
	0.0-Completely transparent tip. 1.0-Completely opaque tip.
	*/
	DoubleID getTipOpacity(){char buffer[4096];sprintf_s (buffer, "%s.dto",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipOpacity" along U direction by importing file textures.*/
	TipOpacityMapUSamplesID getTipOpacityMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.tomus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipOpacity" along V direction by importing file textures.*/
	TipOpacityMapVSamplesID getTipOpacityMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.tomvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getTipOpacityMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.tomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getTipOpacityMapMult(){char buffer[4096];sprintf_s (buffer, "%s.tomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getTipOpacityNoise(){char buffer[4096];sprintf_s (buffer, "%s.ton",mName.c_str());return (const char*)buffer;}
	/*Defines the width of each hair at the base, in world units.*/
	DoubleID getBaseWidth(){char buffer[4096];sprintf_s (buffer, "%s.dbw",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseWidth" along U direction by importing file textures.*/
	BaseWidthMapUSamplesID getBaseWidthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.bwmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseWidth" along V direction by importing file textures.*/
	BaseWidthMapVSamplesID getBaseWidthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.bwmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getBaseWidthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bwmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getBaseWidthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bwmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getBaseWidthNoise(){char buffer[4096];sprintf_s (buffer, "%s.bwn",mName.c_str());return (const char*)buffer;}
	/*Defines the width of each hair at the tip, in world units.*/
	DoubleID getTipWidth(){char buffer[4096];sprintf_s (buffer, "%s.dtw",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipWidth" along U direction by importing file textures.*/
	TipWidthMapUSamplesID getTipWidthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.twmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipWidth" along V direction by importing file textures.*/
	TipWidthMapVSamplesID getTipWidthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.twmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getTipWidthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.twmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getTipWidthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.twmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getTipWidthNoise(){char buffer[4096];sprintf_s (buffer, "%s.twn",mName.c_str());return (const char*)buffer;}
	/*Defines the number of segments each fur is comprised of. For smoother curves, use more segments*/
	DoubleID getSegments(){char buffer[4096];sprintf_s (buffer, "%s.dsg",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Segments" along U direction by importing file textures.*/
	SegmentsMapUSamplesID getSegmentsMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.sgmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Segments" along V direction by importing file textures.*/
	SegmentsMapVSamplesID getSegmentsMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.sgmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getSegmentsMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.sgmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getSegmentsMapMult(){char buffer[4096];sprintf_s (buffer, "%s.sgmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getSegmentsNoise(){char buffer[4096];sprintf_s (buffer, "%s.sgn",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of curl at the base of the fur. The fur tip is not influenced by this value.
	0.0- Half-circle curl to one side. 0.5-No curl. 1.0-Half-circle curl to the other side.
	*/
	DoubleID getBaseCurl(){char buffer[4096];sprintf_s (buffer, "%s.dbcl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseCurl" along U direction by importing file textures.*/
	BaseCurlMapUSamplesID getBaseCurlMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.bclmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "BaseCurl" along V direction by importing file textures.*/
	BaseCurlMapVSamplesID getBaseCurlMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.bclmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getBaseCurlMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.bclmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getBaseCurlMapMult(){char buffer[4096];sprintf_s (buffer, "%s.bclmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getBaseCurlNoise(){char buffer[4096];sprintf_s (buffer, "%s.bcln",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of curl at the tip of the fur. The fur base is not influenced by this value.
	0.0-Half-circle curl to one side. 0.5-No curl. 1.0- Half-circle curl to the other side
	*/
	DoubleID getTipCurl(){char buffer[4096];sprintf_s (buffer, "%s.dtcl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipCurl" along U direction by importing file textures.*/
	TipCurlMapUSamplesID getTipCurlMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.tclmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "TipCurl" along V direction by importing file textures.*/
	TipCurlMapVSamplesID getTipCurlMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.tclmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getTipCurlMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.tclmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getTipCurlMapMult(){char buffer[4096];sprintf_s (buffer, "%s.tclmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getTipCurlNoise(){char buffer[4096];sprintf_s (buffer, "%s.tcln",mName.c_str());return (const char*)buffer;}
	/*
	Defines how crooked the fur is.
	0.0-No scraggle. 1.0-Full scraggle.
	*/
	DoubleID getScraggle(){char buffer[4096];sprintf_s (buffer, "%s.ds",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Scraggle" along U direction by importing file textures.*/
	ScraggleMapUSamplesID getScraggleMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.smus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Scraggle" along V direction by importing file textures.*/
	ScraggleMapVSamplesID getScraggleMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.smvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getScraggleMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.smo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getScraggleMapMult(){char buffer[4096];sprintf_s (buffer, "%s.smm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getScraggleNoise(){char buffer[4096];sprintf_s (buffer, "%s.sn",mName.c_str());return (const char*)buffer;}
	/*Defines the amount of change over each length of hair. The higher the value, the more changes there will be along each length of hair (the hair becomes more deformed).*/
	DoubleID getScraggleFrequency(){char buffer[4096];sprintf_s (buffer, "%s.dsf",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ScraggleFrequency" along U direction by importing file textures.*/
	ScraggleFrequencyMapUSamplesID getScraggleFrequencyMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.sfmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ScraggleFrequency" along V direction by importing file textures.*/
	ScraggleFrequencyMapVSamplesID getScraggleFrequencyMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.sfmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getScraggleFrequencyMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.sfmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getScraggleFrequencyMapMult(){char buffer[4096];sprintf_s (buffer, "%s.sfmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getScraggleFrequencyNoise(){char buffer[4096];sprintf_s (buffer, "%s.sfn",mName.c_str());return (const char*)buffer;}
	/*
	Defines how the scraggle of each hair relates to each other hair.
	0.0-No correlation, so each hair has a unique scraggle. 1.0-Total correlation, so all hair "scraggles" in exactly the same way.
	*/
	DoubleID getScraggleCorrelation(){char buffer[4096];sprintf_s (buffer, "%s.dsco",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ScraggleCorrelation" along U direction by importing file textures.*/
	ScraggleCorrelationMapUSamplesID getScraggleCorrelationMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.scomus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ScraggleCorrelation" along V direction by importing file textures.*/
	ScraggleCorrelationMapVSamplesID getScraggleCorrelationMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.scomvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getScraggleCorrelationMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.scomo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getScraggleCorrelationMapMult(){char buffer[4096];sprintf_s (buffer, "%s.scomm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getScraggleCorrelationNoise(){char buffer[4096];sprintf_s (buffer, "%s.scon",mName.c_str());return (const char*)buffer;}
	/*
	Sets the amount of inclination.
	0.0-No inclination. The fur is fully erect (normal to the surface). This is the default.
	0.5-Partial inclination. 1.0- Fully inclined. The fur lies flat (tangent to the surface at the root).
	*/
	DoubleID getInclination(){char buffer[4096];sprintf_s (buffer, "%s.di",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Inclination" along U direction by importing file textures.*/
	InclinationMapUSamplesID getInclinationMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.imus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Inclination" along V direction by importing file textures.*/
	InclinationMapVSamplesID getInclinationMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.imvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getInclinationMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.imo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getInclinationMapMult(){char buffer[4096];sprintf_s (buffer, "%s.imm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getInclinationNoise(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*
	Rotates the fur about the surface V axis. You can achieve almost any fur angle using Polar and Inclination, so use this option only when the fur has curl and you want the curls to lie flat.
	0.0-90 degree rotation. 0.5-No rotation. This is the default.1.0-90 degree rotation.
	*/
	DoubleID getRoll(){char buffer[4096];sprintf_s (buffer, "%s.dr",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Roll" along U direction by importing file textures.*/
	RollMapUSamplesID getRollMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.rmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Roll" along V direction by importing file textures.*/
	RollMapVSamplesID getRollMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.rmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getRollMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.rmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getRollMapMult(){char buffer[4096];sprintf_s (buffer, "%s.rmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getRollNoise(){char buffer[4096];sprintf_s (buffer, "%s.rn",mName.c_str());return (const char*)buffer;}
	/*
	Rotates the fur about the surface normal.
	0.0-180 degree rotation. 0.5-No rotation. This is the default. 1.0-180 degree rotation.
	*/
	DoubleID getPolar(){char buffer[4096];sprintf_s (buffer, "%s.dp",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Polar" along U direction by importing file textures.*/
	PolarMapUSamplesID getPolarMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.pmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Polar" along V direction by importing file textures.*/
	PolarMapVSamplesID getPolarMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.pmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getPolarMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.pmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getPolarMapMult(){char buffer[4096];sprintf_s (buffer, "%s.pmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getPolarNoise(){char buffer[4096];sprintf_s (buffer, "%s.pn",mName.c_str());return (const char*)buffer;}
	/*
	Defines the amount of attraction this fur description has towards attractors.
	0.0 No attraction. 1.0 Full attraction.
	*/
	DoubleID getAttraction(){char buffer[4096];sprintf_s (buffer, "%s.dat",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Attraction" along U direction by importing file textures.*/
	AttractionMapUSamplesID getAttractionMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.atmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Attraction" along V direction by importing file textures.*/
	AttractionMapVSamplesID getAttractionMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.atmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getAttractionMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.atmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getAttractionMapMult(){char buffer[4096];sprintf_s (buffer, "%s.atmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getAttractionNoise(){char buffer[4096];sprintf_s (buffer, "%s.atn",mName.c_str());return (const char*)buffer;}
	/*
	Defines how much to offset the fur description (in world units) from the surface it is attached to.
	When the Offset value is 0, the roots of the fur hairs start growing from the surface.
	When the value is less than zero, the roots start growing from inside the surface.
	When the value is greater than zero, the roots start growing from outside the surface
	*/
	DoubleID getOffset(){char buffer[4096];sprintf_s (buffer, "%s.dofs",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Offset" along U direction by importing file textures.*/
	OffsetMapUSamplesID getOffsetMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.ofsmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Offset" along V direction by importing file textures.*/
	OffsetMapVSamplesID getOffsetMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.ofsmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the fur description attribute value by. The initial map is between 0 and 1.*/
	DoubleID getOffsetMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.ofsmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getOffsetMapMult(){char buffer[4096];sprintf_s (buffer, "%s.ofsmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getOffsetNoise(){char buffer[4096];sprintf_s (buffer, "%s.ofsn",mName.c_str());return (const char*)buffer;}
	/*
	The degree to which the hairs are pulled in towards the centreof the clump.
	The higher the clumping value, the more the hairs are pulled in.
	The defaultis 0, which means no clumping.
	*/
	FloatID getClumping(){char buffer[4096];sprintf_s (buffer, "%s.dc",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Clumping" along U direction by importing file textures.*/
	ClumpingMapUSamplesID getClumpingMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.cmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "Clumping" along V direction by importing file textures.*/
	ClumpingMapVSamplesID getClumpingMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.cmvs",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	FloatID getClumpingMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cmo",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getClumpingMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cmm",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getClumpingNoise(){char buffer[4096];sprintf_s (buffer, "%s.cn",mName.c_str());return (const char*)buffer;}
	/*
	Controls how many clumps occur across the surface.
	The higher the frequency, the greater the number, and therefore smaller-sized, clumps.
	The default is 50.As you increase the Clumping Frequency, the rendering time increases.
	*/
	FloatID getClumpingFrequency(){char buffer[4096];sprintf_s (buffer, "%s.dcf",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ClumpingFrequency" along U direction by importing file textures.*/
	ClumpingFrequencyMapUSamplesID getClumpingFrequencyMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.cfmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ClumpingFrequency" along V direction by importing file textures.*/
	ClumpingFrequencyMapVSamplesID getClumpingFrequencyMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.cfmvs",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	FloatID getClumpingFrequencyMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cfmo",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getClumpingFrequencyMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cfmm",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getClumpingFrequencyNoise(){char buffer[4096];sprintf_s (buffer, "%s.cfn",mName.c_str());return (const char*)buffer;}
	/*
	Controls the shape of the curve of the hair as it is attracted to the center of the clump.
	A value of -10 creates a concave shape and a value of 10 creates a convex shape.
	*/
	FloatID getClumpShape(){char buffer[4096];sprintf_s (buffer, "%s.dcs",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ClumpShape" along U direction by importing file textures.*/
	ClumpShapeMapUSamplesID getClumpShapeMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.csmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for fur description attribute "ClumpShape" along V direction by importing file textures.*/
	ClumpShapeMapVSamplesID getClumpShapeMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.csmvs",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to offset the fur description attribute. The initial map is between 0 and 1.*/
	FloatID getClumpShapeMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.csmo",mName.c_str());return (const char*)buffer;}
	/*Used to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getClumpShapeMapMult(){char buffer[4096];sprintf_s (buffer, "%s.csmm",mName.c_str());return (const char*)buffer;}
	/*Used to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getClumpShapeNoise(){char buffer[4096];sprintf_s (buffer, "%s.csn",mName.c_str());return (const char*)buffer;}
protected:
	FurDescription(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURDESCRIPTION_H__
