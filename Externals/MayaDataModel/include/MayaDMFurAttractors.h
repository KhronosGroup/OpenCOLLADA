/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURATTRACTORS_H__
#define __MayaDM_FURATTRACTORS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
"FurAttractors" node is used to add movement to fur. Attractors are joint chains (with IK handles, linked rotations, or particles) that "attract" the hairs making up the fur.
 When user moves the attractors (by key framing, moving the object the attractors are attached to, or applying forces), the fur follows that movement according to the attributes.
*/
class FurAttractors : public DependNode
{
public:
	/*Used to map values for attractor set attribute "Radius" by importing file textures.*/
	struct RadiusMap{
	};
	/*Used to map values for attractor set attribute "Radius" along U direction by importing file textures.*/
	struct RadiusMapUSamples{
	};
	/*Used to map values for attractor set attribute "Radius" along V direction by importing file textures.*/
	struct RadiusMapVSamples{
	};
	/*Used to map values for attractor set attribute "Power" by importing file textures.*/
	struct PowerMap{
	};
	/*Used to map values for attractor set attribute "Power" along U direction by importing file textures.*/
	struct PowerMapUSamples{
	};
	/*Used to map values for attractor set attribute "Power" along V direction by importing file textures.*/
	struct PowerMapVSamples{
	};
	/*Used to map values for attractor set attribute "Influence" by importing file textures.*/
	struct InfluenceMap{
	};
	/*Used to map values for attractor set attribute "Influence" along U direction by importing file textures.*/
	struct InfluenceMapUSamples{
	};
	/*Used to map values for attractor set attribute "Influence" along V direction by importing file textures.*/
	struct InfluenceMapVSamples{
	};
	/*Used to map values for attractor set attribute "StartLength" by importing file textures.*/
	struct StartLengthMap{
	};
	/*Used to map values for attractor set attribute "StartLength" along U direction by importing file textures.*/
	struct StartLengthMapUSamples{
	};
	/*Used to map values for attractor set attribute "StartLength" along V direction by importing file textures.*/
	struct StartLengthMapVSamples{
	};
	/*Used to map values for attractor set attribute "EndLength" by importing file textures.*/
	struct EndLengthMap{
	};
	/*Used to map values for attractor set attribute "EndLength" along U direction by importing file textures.*/
	struct EndLengthMapUSamples{
	};
	/*Used to map values for attractor set attribute "EndLength" along V direction by importing file textures.*/
	struct EndLengthMapVSamples{
	};
	/*Used to map values for attractor set attribute "ThresholdLength" by importing file textures.*/
	struct ThresholdLengthMap{
	};
	/*Used to map values for attractor set attribute "ThresholdLength" along U direction by importing file textures.*/
	struct ThresholdLengthMapUSamples{
	};
	/*Used to map values for attractor set attribute "ThresholdLength" along V direction by importing file textures.*/
	struct ThresholdLengthMapVSamples{
	};
public:
	FurAttractors(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurAttractors"){}
	virtual ~FurAttractors(){}
	/*
	Defines the type of attractor.
	0-Local Each hair mimics the closest attractor(s) within the defined radius.
	1-Global Each hair grows towards the closest attractor(s) within the defined radius.
	*/
	void setAttractorModel(unsigned int amd){if(amd == 0) return; fprintf_s(mFile, "setAttr \".amd\" %i;\n", amd);}
	/*
	Defines the type of attractor.
	0-Local Each hair mimics the closest attractor(s) within the defined radius.
	1-Global Each hair grows towards the closest attractor(s) within the defined radius.
	*/
	void setAttractorModel(const UnsignedintID& amd){fprintf_s(mFile,"connectAttr \"");amd.write(mFile);fprintf_s(mFile,"\" \"%s.amd\";\n",mName.c_str());}
	/*
	Defines the number of attractors a hair should be influenced by.
	e.g. 1 Every hair is influenced by one attractor closest to it.
	2 Every hair is influenced by two attractors closest to it.
	3 Every hair is influenced by three attractors closest to it.
	*/
	void setAttractorsPerHair(int aph){if(aph == 1) return; fprintf_s(mFile, "setAttr \".aph\" %i;\n", aph);}
	/*Defines to adjust the Radius, Power, Influence, and Length values by a common factor (including mapped values).*/
	void setGlobalScale(float gs){if(gs == 1.0) return; fprintf_s(mFile, "setAttr \".gs\" %f;\n", gs);}
	/*Used to set the radius in which to search for the closest attractors, in world units. This value can help prevent hairs from being influenced by attractors that are unreasonably far away.*/
	void setRadius(double rd){if(rd == 1) return; fprintf_s(mFile, "setAttr \".rd\" %f;\n", rd);}
	/*Used to set the radius in which to search for the closest attractors, in world units. This value can help prevent hairs from being influenced by attractors that are unreasonably far away.*/
	void setRadius(const DoubleID& rd){fprintf_s(mFile,"connectAttr \"");rd.write(mFile);fprintf_s(mFile,"\" \"%s.rd\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "Radius" along U direction by importing file textures.*/
	void setRadiusMapUSamples(const RadiusMapUSamplesID& rmus){fprintf_s(mFile,"connectAttr \"");rmus.write(mFile);fprintf_s(mFile,"\" \"%s.rmus\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "Radius" along V direction by importing file textures.*/
	void setRadiusMapVSamples(const RadiusMapVSamplesID& rmvs){fprintf_s(mFile,"connectAttr \"");rmvs.write(mFile);fprintf_s(mFile,"\" \"%s.rmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setRadiusMapOffset(double rmo){if(rmo == 0) return; fprintf_s(mFile, "setAttr \".rmo\" %f;\n", rmo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setRadiusMapOffset(const DoubleID& rmo){fprintf_s(mFile,"connectAttr \"");rmo.write(mFile);fprintf_s(mFile,"\" \"%s.rmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRadiusMapMult(double rmm){if(rmm == 1) return; fprintf_s(mFile, "setAttr \".rmm\" %f;\n", rmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setRadiusMapMult(const DoubleID& rmm){fprintf_s(mFile,"connectAttr \"");rmm.write(mFile);fprintf_s(mFile,"\" \"%s.rmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRadiusNoise(double rn){if(rn == 0) return; fprintf_s(mFile, "setAttr \".rn\" %f;\n", rn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setRadiusNoise(const DoubleID& rn){fprintf_s(mFile,"connectAttr \"");rn.write(mFile);fprintf_s(mFile,"\" \"%s.rn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setRadiusNoiseFreq(float rnf){if(rnf == 10.0) return; fprintf_s(mFile, "setAttr \".rnf\" %f;\n", rnf);}
	/*
	Set how the attractor will influence the hairs. The value you enter is the power to a falloff function that makes hairs become less influenced at the base of the hair than at the tip.
	0.0 The entire length of the hair is influenced.
	1.0 Hair is much less influenced at the base.
	*/
	void setPower(float dp){if(dp == 1.0) return; fprintf_s(mFile, "setAttr \".dp\" %f;\n", dp);}
	/*
	Set how the attractor will influence the hairs. The value you enter is the power to a falloff function that makes hairs become less influenced at the base of the hair than at the tip.
	0.0 The entire length of the hair is influenced.
	1.0 Hair is much less influenced at the base.
	*/
	void setPower(const FloatID& dp){fprintf_s(mFile,"connectAttr \"");dp.write(mFile);fprintf_s(mFile,"\" \"%s.dp\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "Power" along U direction by importing file textures.*/
	void setPowerMapUSamples(const PowerMapUSamplesID& pmus){fprintf_s(mFile,"connectAttr \"");pmus.write(mFile);fprintf_s(mFile,"\" \"%s.pmus\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "Power" along V direction by importing file textures.*/
	void setPowerMapVSamples(const PowerMapVSamplesID& pmvs){fprintf_s(mFile,"connectAttr \"");pmvs.write(mFile);fprintf_s(mFile,"\" \"%s.pmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setPowerMapOffset(float pmo){if(pmo == 0.0) return; fprintf_s(mFile, "setAttr \".pmo\" %f;\n", pmo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setPowerMapOffset(const FloatID& pmo){fprintf_s(mFile,"connectAttr \"");pmo.write(mFile);fprintf_s(mFile,"\" \"%s.pmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPowerMapMult(float pmm){if(pmm == 1.0) return; fprintf_s(mFile, "setAttr \".pmm\" %f;\n", pmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setPowerMapMult(const FloatID& pmm){fprintf_s(mFile,"connectAttr \"");pmm.write(mFile);fprintf_s(mFile,"\" \"%s.pmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPowerNoise(float pn){if(pn == 0.0) return; fprintf_s(mFile, "setAttr \".pn\" %f;\n", pn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setPowerNoise(const FloatID& pn){fprintf_s(mFile,"connectAttr \"");pn.write(mFile);fprintf_s(mFile,"\" \"%s.pn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setPowerNoiseFreq(float pnf){if(pnf == 10.0) return; fprintf_s(mFile, "setAttr \".pnf\" %f;\n", pnf);}
	/*
	Set how much influence the attractor will have on the hairs. The value you enter linearly increases or decreases the influence over the length of the hair.
	0.0 No influence.
	1.0 Standard influence.
	*/
	void setInfluence(float di){if(di == 1.0) return; fprintf_s(mFile, "setAttr \".di\" %f;\n", di);}
	/*
	Set how much influence the attractor will have on the hairs. The value you enter linearly increases or decreases the influence over the length of the hair.
	0.0 No influence.
	1.0 Standard influence.
	*/
	void setInfluence(const FloatID& di){fprintf_s(mFile,"connectAttr \"");di.write(mFile);fprintf_s(mFile,"\" \"%s.di\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "Influence" along U direction by importing file textures.*/
	void setInfluenceMapUSamples(const InfluenceMapUSamplesID& imus){fprintf_s(mFile,"connectAttr \"");imus.write(mFile);fprintf_s(mFile,"\" \"%s.imus\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "Influence" along V direction by importing file textures.*/
	void setInfluenceMapVSamples(const InfluenceMapVSamplesID& imvs){fprintf_s(mFile,"connectAttr \"");imvs.write(mFile);fprintf_s(mFile,"\" \"%s.imvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setInfluenceMapOffset(float imo){if(imo == 0.0) return; fprintf_s(mFile, "setAttr \".imo\" %f;\n", imo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setInfluenceMapOffset(const FloatID& imo){fprintf_s(mFile,"connectAttr \"");imo.write(mFile);fprintf_s(mFile,"\" \"%s.imo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInfluenceMapMult(float imm){if(imm == 1.0) return; fprintf_s(mFile, "setAttr \".imm\" %f;\n", imm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setInfluenceMapMult(const FloatID& imm){fprintf_s(mFile,"connectAttr \"");imm.write(mFile);fprintf_s(mFile,"\" \"%s.imm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInfluenceNoise(float in){if(in == 0.0) return; fprintf_s(mFile, "setAttr \".in\" %f;\n", in);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setInfluenceNoise(const FloatID& in){fprintf_s(mFile,"connectAttr \"");in.write(mFile);fprintf_s(mFile,"\" \"%s.in\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setInfluenceNoiseFreq(float inf){if(inf == 10.0) return; fprintf_s(mFile, "setAttr \".inf\" %f;\n", inf);}
	/*Defines to set the point along the hair, in world units, at which the hair will start being influenced. In general, this value should be 0.0, unless you want the hair to grow in its normal direction up to a point along the hair.*/
	void setStartLength(float dsl){if(dsl == 0.0) return; fprintf_s(mFile, "setAttr \".dsl\" %f;\n", dsl);}
	/*Defines to set the point along the hair, in world units, at which the hair will start being influenced. In general, this value should be 0.0, unless you want the hair to grow in its normal direction up to a point along the hair.*/
	void setStartLength(const FloatID& dsl){fprintf_s(mFile,"connectAttr \"");dsl.write(mFile);fprintf_s(mFile,"\" \"%s.dsl\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "StartLength" along U direction by importing file textures.*/
	void setStartLengthMapUSamples(const StartLengthMapUSamplesID& slmus){fprintf_s(mFile,"connectAttr \"");slmus.write(mFile);fprintf_s(mFile,"\" \"%s.slmus\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "StartLength" along V direction by importing file textures.*/
	void setStartLengthMapVSamples(const StartLengthMapVSamplesID& slmvs){fprintf_s(mFile,"connectAttr \"");slmvs.write(mFile);fprintf_s(mFile,"\" \"%s.slmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setStartLengthMapOffset(double slmo){if(slmo == 0) return; fprintf_s(mFile, "setAttr \".slmo\" %f;\n", slmo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setStartLengthMapOffset(const DoubleID& slmo){fprintf_s(mFile,"connectAttr \"");slmo.write(mFile);fprintf_s(mFile,"\" \"%s.slmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setStartLengthMapMult(double slmm){if(slmm == 1) return; fprintf_s(mFile, "setAttr \".slmm\" %f;\n", slmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setStartLengthMapMult(const DoubleID& slmm){fprintf_s(mFile,"connectAttr \"");slmm.write(mFile);fprintf_s(mFile,"\" \"%s.slmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setStartLengthNoise(double sln){if(sln == 0) return; fprintf_s(mFile, "setAttr \".sln\" %f;\n", sln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setStartLengthNoise(const DoubleID& sln){fprintf_s(mFile,"connectAttr \"");sln.write(mFile);fprintf_s(mFile,"\" \"%s.sln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setStartLengthNoiseFreq(float slnf){if(slnf == 10.0) return; fprintf_s(mFile, "setAttr \".slnf\" %f;\n", slnf);}
	/*Defines to set the point along the hair, in world units, at which the hair will no longer be influenced. For the best effect, this should be at least as large as the longest hair length. With smaller values the tips of the hairs will not be influenced.*/
	void setEndLength(float del){if(del == 5.0) return; fprintf_s(mFile, "setAttr \".del\" %f;\n", del);}
	/*Defines to set the point along the hair, in world units, at which the hair will no longer be influenced. For the best effect, this should be at least as large as the longest hair length. With smaller values the tips of the hairs will not be influenced.*/
	void setEndLength(const FloatID& del){fprintf_s(mFile,"connectAttr \"");del.write(mFile);fprintf_s(mFile,"\" \"%s.del\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "EndLength" along U direction by importing file textures.*/
	void setEndLengthMapUSamples(const EndLengthMapUSamplesID& elmus){fprintf_s(mFile,"connectAttr \"");elmus.write(mFile);fprintf_s(mFile,"\" \"%s.elmus\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "EndLength" along V direction by importing file textures.*/
	void setEndLengthMapVSamples(const EndLengthMapVSamplesID& elmvs){fprintf_s(mFile,"connectAttr \"");elmvs.write(mFile);fprintf_s(mFile,"\" \"%s.elmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setEndLengthMapOffset(double elmo){if(elmo == 0) return; fprintf_s(mFile, "setAttr \".elmo\" %f;\n", elmo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setEndLengthMapOffset(const DoubleID& elmo){fprintf_s(mFile,"connectAttr \"");elmo.write(mFile);fprintf_s(mFile,"\" \"%s.elmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setEndLengthMapMult(double elmm){if(elmm == 1) return; fprintf_s(mFile, "setAttr \".elmm\" %f;\n", elmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setEndLengthMapMult(const DoubleID& elmm){fprintf_s(mFile,"connectAttr \"");elmm.write(mFile);fprintf_s(mFile,"\" \"%s.elmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setEndLengthNoise(double eln){if(eln == 0) return; fprintf_s(mFile, "setAttr \".eln\" %f;\n", eln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setEndLengthNoise(const DoubleID& eln){fprintf_s(mFile,"connectAttr \"");eln.write(mFile);fprintf_s(mFile,"\" \"%s.eln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setEndLengthNoiseFreq(float elnf){if(elnf == 10.0) return; fprintf_s(mFile, "setAttr \".elnf\" %f;\n", elnf);}
	/*Hairs shorter than this value will not be influenced at all. Use this value to prevent short hairs from being influenced while long hairs are influenced.*/
	void setThresholdLength(float dtl){if(dtl == 0.33) return; fprintf_s(mFile, "setAttr \".dtl\" %f;\n", dtl);}
	/*Hairs shorter than this value will not be influenced at all. Use this value to prevent short hairs from being influenced while long hairs are influenced.*/
	void setThresholdLength(const FloatID& dtl){fprintf_s(mFile,"connectAttr \"");dtl.write(mFile);fprintf_s(mFile,"\" \"%s.dtl\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "ThresholdLength" along U direction by importing file textures.*/
	void setThresholdLengthMapUSamples(const ThresholdLengthMapUSamplesID& tlmus){fprintf_s(mFile,"connectAttr \"");tlmus.write(mFile);fprintf_s(mFile,"\" \"%s.tlmus\";\n",mName.c_str());}
	/*Used to map values for attractor set attribute "ThresholdLength" along V direction by importing file textures.*/
	void setThresholdLengthMapVSamples(const ThresholdLengthMapVSamplesID& tlmvs){fprintf_s(mFile,"connectAttr \"");tlmvs.write(mFile);fprintf_s(mFile,"\" \"%s.tlmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setThresholdLengthMapOffset(double tlmo){if(tlmo == 0) return; fprintf_s(mFile, "setAttr \".tlmo\" %f;\n", tlmo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setThresholdLengthMapOffset(const DoubleID& tlmo){fprintf_s(mFile,"connectAttr \"");tlmo.write(mFile);fprintf_s(mFile,"\" \"%s.tlmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setThresholdLengthMapMult(double tlmm){if(tlmm == 1) return; fprintf_s(mFile, "setAttr \".tlmm\" %f;\n", tlmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setThresholdLengthMapMult(const DoubleID& tlmm){fprintf_s(mFile,"connectAttr \"");tlmm.write(mFile);fprintf_s(mFile,"\" \"%s.tlmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setThresholdLengthNoise(double tln){if(tln == 0) return; fprintf_s(mFile, "setAttr \".tln\" %f;\n", tln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setThresholdLengthNoise(const DoubleID& tln){fprintf_s(mFile,"connectAttr \"");tln.write(mFile);fprintf_s(mFile,"\" \"%s.tln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setThresholdLengthNoiseFreq(float tlnf){if(tlnf == 10.0) return; fprintf_s(mFile, "setAttr \".tlnf\" %f;\n", tlnf);}
	/*
	Defines the type of attractor.
	0-Local Each hair mimics the closest attractor(s) within the defined radius.
	1-Global Each hair grows towards the closest attractor(s) within the defined radius.
	*/
	UnsignedintID getAttractorModel(){char buffer[4096];sprintf_s (buffer, "%s.amd",mName.c_str());return (const char*)buffer;}
	/*Used to set the radius in which to search for the closest attractors, in world units. This value can help prevent hairs from being influenced by attractors that are unreasonably far away.*/
	DoubleID getRadius(){char buffer[4096];sprintf_s (buffer, "%s.rd",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "Radius" along U direction by importing file textures.*/
	RadiusMapUSamplesID getRadiusMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.rmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "Radius" along V direction by importing file textures.*/
	RadiusMapVSamplesID getRadiusMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.rmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getRadiusMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.rmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getRadiusMapMult(){char buffer[4096];sprintf_s (buffer, "%s.rmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getRadiusNoise(){char buffer[4096];sprintf_s (buffer, "%s.rn",mName.c_str());return (const char*)buffer;}
	/*
	Set how the attractor will influence the hairs. The value you enter is the power to a falloff function that makes hairs become less influenced at the base of the hair than at the tip.
	0.0 The entire length of the hair is influenced.
	1.0 Hair is much less influenced at the base.
	*/
	FloatID getPower(){char buffer[4096];sprintf_s (buffer, "%s.dp",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "Power" along U direction by importing file textures.*/
	PowerMapUSamplesID getPowerMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.pmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "Power" along V direction by importing file textures.*/
	PowerMapVSamplesID getPowerMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.pmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	FloatID getPowerMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.pmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getPowerMapMult(){char buffer[4096];sprintf_s (buffer, "%s.pmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getPowerNoise(){char buffer[4096];sprintf_s (buffer, "%s.pn",mName.c_str());return (const char*)buffer;}
	/*
	Set how much influence the attractor will have on the hairs. The value you enter linearly increases or decreases the influence over the length of the hair.
	0.0 No influence.
	1.0 Standard influence.
	*/
	FloatID getInfluence(){char buffer[4096];sprintf_s (buffer, "%s.di",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "Influence" along U direction by importing file textures.*/
	InfluenceMapUSamplesID getInfluenceMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.imus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "Influence" along V direction by importing file textures.*/
	InfluenceMapVSamplesID getInfluenceMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.imvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	FloatID getInfluenceMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.imo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getInfluenceMapMult(){char buffer[4096];sprintf_s (buffer, "%s.imm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getInfluenceNoise(){char buffer[4096];sprintf_s (buffer, "%s.in",mName.c_str());return (const char*)buffer;}
	/*Defines to set the point along the hair, in world units, at which the hair will start being influenced. In general, this value should be 0.0, unless you want the hair to grow in its normal direction up to a point along the hair.*/
	FloatID getStartLength(){char buffer[4096];sprintf_s (buffer, "%s.dsl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "StartLength" along U direction by importing file textures.*/
	StartLengthMapUSamplesID getStartLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.slmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "StartLength" along V direction by importing file textures.*/
	StartLengthMapVSamplesID getStartLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.slmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getStartLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.slmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getStartLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.slmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getStartLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.sln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the point along the hair, in world units, at which the hair will no longer be influenced. For the best effect, this should be at least as large as the longest hair length. With smaller values the tips of the hairs will not be influenced.*/
	FloatID getEndLength(){char buffer[4096];sprintf_s (buffer, "%s.del",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "EndLength" along U direction by importing file textures.*/
	EndLengthMapUSamplesID getEndLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.elmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "EndLength" along V direction by importing file textures.*/
	EndLengthMapVSamplesID getEndLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.elmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getEndLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.elmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getEndLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.elmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getEndLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.eln",mName.c_str());return (const char*)buffer;}
	/*Hairs shorter than this value will not be influenced at all. Use this value to prevent short hairs from being influenced while long hairs are influenced.*/
	FloatID getThresholdLength(){char buffer[4096];sprintf_s (buffer, "%s.dtl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "ThresholdLength" along U direction by importing file textures.*/
	ThresholdLengthMapUSamplesID getThresholdLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.tlmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for attractor set attribute "ThresholdLength" along V direction by importing file textures.*/
	ThresholdLengthMapVSamplesID getThresholdLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.tlmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getThresholdLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.tlmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getThresholdLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.tlmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getThresholdLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.tln",mName.c_str());return (const char*)buffer;}
protected:
	FurAttractors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURATTRACTORS_H__
