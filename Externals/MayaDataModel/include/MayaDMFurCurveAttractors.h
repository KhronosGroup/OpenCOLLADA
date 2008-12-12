/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FURCURVEATTRACTORS_H__
#define __MayaDM_FURCURVEATTRACTORS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*"FurCurveAttractors" node is used to style Fur and create realistic dynamic Fur simulations.*/
class FurCurveAttractors : public DependNode
{
public:
	/*Used to map values for curve attractor set attribute "CurveRadius" by importing file textures.*/
	struct CurveRadiusMap{
	};
	/*Used to map values for curve attractor set attribute "CurveRadius" along U direction by importing file textures.*/
	struct CurveRadiusMapUSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveRadius" along V direction by importing file textures.*/
	struct CurveRadiusMapVSamples{
	};
	/*Used to map values for curve attractor set attribute "CurvePower" by importing file textures.*/
	struct CurvePowerMap{
	};
	/*Used to map values for curve attractor set attribute "CurvePower" along U direction by importing file textures.*/
	struct CurvePowerMapUSamples{
	};
	/*Used to map values for curve attractor set attribute "CurvePower" along V direction by importing file textures.*/
	struct CurvePowerMapVSamples{
	};
	/*Used to map values for attractor set attribute "CurveInfluence" by importing file textures.*/
	struct CurveInfluenceMap{
	};
	/*Used to map values for curve attractor set attribute "CurveInfluence" along U direction by importing file textures.*/
	struct CurveInfluenceMapUSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveInfluence" along V direction by importing file textures.*/
	struct CurveInfluenceMapVSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveStartLength" by importing file textures.*/
	struct CurveStartLengthMap{
	};
	/*Used to map values for curve attractor set attribute "CurveStartLength" along U direction by importing file textures.*/
	struct CurveStartLengthMapUSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveStartLength" along V direction by importing file textures.*/
	struct CurveStartLengthMapVSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveEndLength" by importing file textures.*/
	struct CurveEndLengthMap{
	};
	/*Used to map values for curve attractor set attribute "CurveEndLength" along U direction by importing file textures.*/
	struct CurveEndLengthMapUSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveEndLength" along V direction by importing file textures.*/
	struct CurveEndLengthMapVSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" by importing file textures.*/
	struct CurveThresholdLengthMap{
	};
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" along U direction by importing file textures.*/
	struct CurveThresholdLengthMapUSamples{
	};
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" along V direction by importing file textures.*/
	struct CurveThresholdLengthMapVSamples{
	};
public:
	FurCurveAttractors(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "FurCurveAttractors"){}
	virtual ~FurCurveAttractors(){}
	/*
	Defines the type of curveAttractor.
	0-Local Each hair mimics the closest dynamic curve(s) within the defined radius.
	1-Global Each hair grows towards the closest dynamic curve(s) within the defined radius.
	*/
	void setCurveAttractorModel(unsigned int camd){if(camd == 0) return; fprintf_s(mFile, "setAttr \".camd\" %i;\n", camd);}
	/*
	Defines the type of curveAttractor.
	0-Local Each hair mimics the closest dynamic curve(s) within the defined radius.
	1-Global Each hair grows towards the closest dynamic curve(s) within the defined radius.
	*/
	void setCurveAttractorModel(const UnsignedintID& camd){fprintf_s(mFile,"connectAttr \"");camd.write(mFile);fprintf_s(mFile,"\" \"%s.camd\";\n",mName.c_str());}
	/*
	Defines the number of dynamic curves a fur should be influenced by.
	e.g. 1 Every fur is influenced by one dynamic curve closest to it.
	2 Every fur is influenced by two dynamic curves closest to it.
	3 Every hair is influenced by three dynamic curves closest to it.
	*/
	void setCurveAttractorsPerHair(int caph){if(caph == 1) return; fprintf_s(mFile, "setAttr \".caph\" %i;\n", caph);}
	/*Defines to adjust the CurveRadius, CurvePower, Influence, and Length values by a common factor (including mapped values).*/
	void setCurveGlobalScale(float cgs){if(cgs == 1.0) return; fprintf_s(mFile, "setAttr \".cgs\" %f;\n", cgs);}
	/*Used to set the radius in which to search for the closest dynamic curve, in world units. This value can help prevent fur from being influenced by dynamic curves that are unreasonably far away.*/
	void setCurveRadius(double dcr){if(dcr == 1) return; fprintf_s(mFile, "setAttr \".dcr\" %f;\n", dcr);}
	/*Used to set the radius in which to search for the closest dynamic curve, in world units. This value can help prevent fur from being influenced by dynamic curves that are unreasonably far away.*/
	void setCurveRadius(const DoubleID& dcr){fprintf_s(mFile,"connectAttr \"");dcr.write(mFile);fprintf_s(mFile,"\" \"%s.dcr\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveRadius" along U direction by importing file textures.*/
	void setCurveRadiusMapUSamples(const CurveRadiusMapUSamplesID& crmus){fprintf_s(mFile,"connectAttr \"");crmus.write(mFile);fprintf_s(mFile,"\" \"%s.crmus\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveRadius" along V direction by importing file textures.*/
	void setCurveRadiusMapVSamples(const CurveRadiusMapVSamplesID& crmvs){fprintf_s(mFile,"connectAttr \"");crmvs.write(mFile);fprintf_s(mFile,"\" \"%s.crmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveRadiusMapOffset(double crmo){if(crmo == 0) return; fprintf_s(mFile, "setAttr \".crmo\" %f;\n", crmo);}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveRadiusMapOffset(const DoubleID& crmo){fprintf_s(mFile,"connectAttr \"");crmo.write(mFile);fprintf_s(mFile,"\" \"%s.crmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveRadiusMapMult(double crmm){if(crmm == 1) return; fprintf_s(mFile, "setAttr \".crmm\" %f;\n", crmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveRadiusMapMult(const DoubleID& crmm){fprintf_s(mFile,"connectAttr \"");crmm.write(mFile);fprintf_s(mFile,"\" \"%s.crmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveRadiusNoise(double crn){if(crn == 0) return; fprintf_s(mFile, "setAttr \".crn\" %f;\n", crn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveRadiusNoise(const DoubleID& crn){fprintf_s(mFile,"connectAttr \"");crn.write(mFile);fprintf_s(mFile,"\" \"%s.crn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setCurveRadiusNoiseFreq(float crnf){if(crnf == 10.0) return; fprintf_s(mFile, "setAttr \".crnf\" %f;\n", crnf);}
	/*
	Set how the dynamic curve will influence the fur. The value you enter is the power to a falloff function that makes fur become less influenced at the base of the fur than at the tip.
	0.0 The entire length of the fur is influenced.
	1.0 Fur is much less influenced at the base.
	*/
	void setCurvePower(float dcp){if(dcp == 1.0) return; fprintf_s(mFile, "setAttr \".dcp\" %f;\n", dcp);}
	/*
	Set how the dynamic curve will influence the fur. The value you enter is the power to a falloff function that makes fur become less influenced at the base of the fur than at the tip.
	0.0 The entire length of the fur is influenced.
	1.0 Fur is much less influenced at the base.
	*/
	void setCurvePower(const FloatID& dcp){fprintf_s(mFile,"connectAttr \"");dcp.write(mFile);fprintf_s(mFile,"\" \"%s.dcp\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurvePower" along U direction by importing file textures.*/
	void setCurvePowerMapUSamples(const CurvePowerMapUSamplesID& cpmus){fprintf_s(mFile,"connectAttr \"");cpmus.write(mFile);fprintf_s(mFile,"\" \"%s.cpmus\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurvePower" along V direction by importing file textures.*/
	void setCurvePowerMapVSamples(const CurvePowerMapVSamplesID& cpmvs){fprintf_s(mFile,"connectAttr \"");cpmvs.write(mFile);fprintf_s(mFile,"\" \"%s.cpmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurvePowerMapOffset(float cpmo){if(cpmo == 0.0) return; fprintf_s(mFile, "setAttr \".cpmo\" %f;\n", cpmo);}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurvePowerMapOffset(const FloatID& cpmo){fprintf_s(mFile,"connectAttr \"");cpmo.write(mFile);fprintf_s(mFile,"\" \"%s.cpmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurvePowerMapMult(float cpmm){if(cpmm == 1.0) return; fprintf_s(mFile, "setAttr \".cpmm\" %f;\n", cpmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurvePowerMapMult(const FloatID& cpmm){fprintf_s(mFile,"connectAttr \"");cpmm.write(mFile);fprintf_s(mFile,"\" \"%s.cpmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurvePowerNoise(float cpn){if(cpn == 0.0) return; fprintf_s(mFile, "setAttr \".cpn\" %f;\n", cpn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurvePowerNoise(const FloatID& cpn){fprintf_s(mFile,"connectAttr \"");cpn.write(mFile);fprintf_s(mFile,"\" \"%s.cpn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setCurvePowerNoiseFreq(float cpnf){if(cpnf == 10.0) return; fprintf_s(mFile, "setAttr \".cpnf\" %f;\n", cpnf);}
	/*
	Set how much influence the dynamic curve will have on the fur. The value you enter linearly increases or decreases the influence over the length of the fur.
	0.0 No influence.
	1.0 Standard influence.
	*/
	void setCurveInfluence(float dci){if(dci == 1.0) return; fprintf_s(mFile, "setAttr \".dci\" %f;\n", dci);}
	/*
	Set how much influence the dynamic curve will have on the fur. The value you enter linearly increases or decreases the influence over the length of the fur.
	0.0 No influence.
	1.0 Standard influence.
	*/
	void setCurveInfluence(const FloatID& dci){fprintf_s(mFile,"connectAttr \"");dci.write(mFile);fprintf_s(mFile,"\" \"%s.dci\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveInfluence" along U direction by importing file textures.*/
	void setCurveInfluenceMapUSamples(const CurveInfluenceMapUSamplesID& cimus){fprintf_s(mFile,"connectAttr \"");cimus.write(mFile);fprintf_s(mFile,"\" \"%s.cimus\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveInfluence" along V direction by importing file textures.*/
	void setCurveInfluenceMapVSamples(const CurveInfluenceMapVSamplesID& cimvs){fprintf_s(mFile,"connectAttr \"");cimvs.write(mFile);fprintf_s(mFile,"\" \"%s.cimvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the  curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveInfluenceMapOffset(float cimo){if(cimo == 0.0) return; fprintf_s(mFile, "setAttr \".cimo\" %f;\n", cimo);}
	/*Defines to set the factor to offset the  curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveInfluenceMapOffset(const FloatID& cimo){fprintf_s(mFile,"connectAttr \"");cimo.write(mFile);fprintf_s(mFile,"\" \"%s.cimo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveInfluenceMapMult(float cimm){if(cimm == 1.0) return; fprintf_s(mFile, "setAttr \".cimm\" %f;\n", cimm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveInfluenceMapMult(const FloatID& cimm){fprintf_s(mFile,"connectAttr \"");cimm.write(mFile);fprintf_s(mFile,"\" \"%s.cimm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveInfluenceNoise(float cin){if(cin == 0.0) return; fprintf_s(mFile, "setAttr \".cin\" %f;\n", cin);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveInfluenceNoise(const FloatID& cin){fprintf_s(mFile,"connectAttr \"");cin.write(mFile);fprintf_s(mFile,"\" \"%s.cin\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setCurveInfluenceNoiseFreq(float cinf){if(cinf == 10.0) return; fprintf_s(mFile, "setAttr \".cinf\" %f;\n", cinf);}
	/*Defines to set the point along the fur, in world units, at which the hair will start being influenced. In general, this value should be 0.0, unless you want the hair to grow in its normal direction up to a point along the hair.*/
	void setCurveStartLength(float dcsl){if(dcsl == 0.0) return; fprintf_s(mFile, "setAttr \".dcsl\" %f;\n", dcsl);}
	/*Defines to set the point along the fur, in world units, at which the hair will start being influenced. In general, this value should be 0.0, unless you want the hair to grow in its normal direction up to a point along the hair.*/
	void setCurveStartLength(const FloatID& dcsl){fprintf_s(mFile,"connectAttr \"");dcsl.write(mFile);fprintf_s(mFile,"\" \"%s.dcsl\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveStartLength" along U direction by importing file textures.*/
	void setCurveStartLengthMapUSamples(const CurveStartLengthMapUSamplesID& cslmus){fprintf_s(mFile,"connectAttr \"");cslmus.write(mFile);fprintf_s(mFile,"\" \"%s.cslmus\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveStartLength" along V direction by importing file textures.*/
	void setCurveStartLengthMapVSamples(const CurveStartLengthMapVSamplesID& cslmvs){fprintf_s(mFile,"connectAttr \"");cslmvs.write(mFile);fprintf_s(mFile,"\" \"%s.cslmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveStartLengthMapOffset(double cslmo){if(cslmo == 0) return; fprintf_s(mFile, "setAttr \".cslmo\" %f;\n", cslmo);}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveStartLengthMapOffset(const DoubleID& cslmo){fprintf_s(mFile,"connectAttr \"");cslmo.write(mFile);fprintf_s(mFile,"\" \"%s.cslmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveStartLengthMapMult(double cslmm){if(cslmm == 1) return; fprintf_s(mFile, "setAttr \".cslmm\" %f;\n", cslmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveStartLengthMapMult(const DoubleID& cslmm){fprintf_s(mFile,"connectAttr \"");cslmm.write(mFile);fprintf_s(mFile,"\" \"%s.cslmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveStartLengthNoise(double csln){if(csln == 0) return; fprintf_s(mFile, "setAttr \".csln\" %f;\n", csln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveStartLengthNoise(const DoubleID& csln){fprintf_s(mFile,"connectAttr \"");csln.write(mFile);fprintf_s(mFile,"\" \"%s.csln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setCurveStartLengthNoiseFreq(float cslnf){if(cslnf == 10.0) return; fprintf_s(mFile, "setAttr \".cslnf\" %f;\n", cslnf);}
	/*Defines to set the point along the fur, in world units, at which the fur will no longer be influenced. For the best effect, this should be at least as large as the longest fur length. With smaller values the tips of the fur will not be influenced.*/
	void setCurveEndLength(float dcel){if(dcel == 5.0) return; fprintf_s(mFile, "setAttr \".dcel\" %f;\n", dcel);}
	/*Defines to set the point along the fur, in world units, at which the fur will no longer be influenced. For the best effect, this should be at least as large as the longest fur length. With smaller values the tips of the fur will not be influenced.*/
	void setCurveEndLength(const FloatID& dcel){fprintf_s(mFile,"connectAttr \"");dcel.write(mFile);fprintf_s(mFile,"\" \"%s.dcel\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveEndLength" along U direction by importing file textures.*/
	void setCurveEndLengthMapUSamples(const CurveEndLengthMapUSamplesID& celmus){fprintf_s(mFile,"connectAttr \"");celmus.write(mFile);fprintf_s(mFile,"\" \"%s.celmus\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveEndLength" along V direction by importing file textures.*/
	void setCurveEndLengthMapVSamples(const CurveEndLengthMapVSamplesID& celmvs){fprintf_s(mFile,"connectAttr \"");celmvs.write(mFile);fprintf_s(mFile,"\" \"%s.celmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveEndLengthMapOffset(double celmo){if(celmo == 0) return; fprintf_s(mFile, "setAttr \".celmo\" %f;\n", celmo);}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveEndLengthMapOffset(const DoubleID& celmo){fprintf_s(mFile,"connectAttr \"");celmo.write(mFile);fprintf_s(mFile,"\" \"%s.celmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveEndLengthMapMult(double celmm){if(celmm == 1) return; fprintf_s(mFile, "setAttr \".celmm\" %f;\n", celmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveEndLengthMapMult(const DoubleID& celmm){fprintf_s(mFile,"connectAttr \"");celmm.write(mFile);fprintf_s(mFile,"\" \"%s.celmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveEndLengthNoise(double celn){if(celn == 0) return; fprintf_s(mFile, "setAttr \".celn\" %f;\n", celn);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveEndLengthNoise(const DoubleID& celn){fprintf_s(mFile,"connectAttr \"");celn.write(mFile);fprintf_s(mFile,"\" \"%s.celn\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setCurveEndLengthNoiseFreq(float celnf){if(celnf == 10.0) return; fprintf_s(mFile, "setAttr \".celnf\" %f;\n", celnf);}
	/*Fur shorter than this value will not be influenced at all. Use this value to prevent short fur from being influenced while long fur are influenced.*/
	void setCurveThresholdLength(float dctl){if(dctl == 0.33) return; fprintf_s(mFile, "setAttr \".dctl\" %f;\n", dctl);}
	/*Fur shorter than this value will not be influenced at all. Use this value to prevent short fur from being influenced while long fur are influenced.*/
	void setCurveThresholdLength(const FloatID& dctl){fprintf_s(mFile,"connectAttr \"");dctl.write(mFile);fprintf_s(mFile,"\" \"%s.dctl\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" along U direction by importing file textures.*/
	void setCurveThresholdLengthMapUSamples(const CurveThresholdLengthMapUSamplesID& ctlmus){fprintf_s(mFile,"connectAttr \"");ctlmus.write(mFile);fprintf_s(mFile,"\" \"%s.ctlmus\";\n",mName.c_str());}
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" along V direction by importing file textures.*/
	void setCurveThresholdLengthMapVSamples(const CurveThresholdLengthMapVSamplesID& ctlmvs){fprintf_s(mFile,"connectAttr \"");ctlmvs.write(mFile);fprintf_s(mFile,"\" \"%s.ctlmvs\";\n",mName.c_str());}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveThresholdLengthMapOffset(double ctlmo){if(ctlmo == 0) return; fprintf_s(mFile, "setAttr \".ctlmo\" %f;\n", ctlmo);}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	void setCurveThresholdLengthMapOffset(const DoubleID& ctlmo){fprintf_s(mFile,"connectAttr \"");ctlmo.write(mFile);fprintf_s(mFile,"\" \"%s.ctlmo\";\n",mName.c_str());}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveThresholdLengthMapMult(double ctlmm){if(ctlmm == 1) return; fprintf_s(mFile, "setAttr \".ctlmm\" %f;\n", ctlmm);}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	void setCurveThresholdLengthMapMult(const DoubleID& ctlmm){fprintf_s(mFile,"connectAttr \"");ctlmm.write(mFile);fprintf_s(mFile,"\" \"%s.ctlmm\";\n",mName.c_str());}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveThresholdLengthNoise(double ctln){if(ctln == 0) return; fprintf_s(mFile, "setAttr \".ctln\" %f;\n", ctln);}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	void setCurveThresholdLengthNoise(const DoubleID& ctln){fprintf_s(mFile,"connectAttr \"");ctln.write(mFile);fprintf_s(mFile,"\" \"%s.ctln\";\n",mName.c_str());}
	/*Defines to set the noise frequency for the attribute. The larger the Noise Frequency, the more variation over a distance or area.*/
	void setCurveThresholdLengthNoiseFreq(float ctlnf){if(ctlnf == 10.0) return; fprintf_s(mFile, "setAttr \".ctlnf\" %f;\n", ctlnf);}
	/*
	Defines the type of curveAttractor.
	0-Local Each hair mimics the closest dynamic curve(s) within the defined radius.
	1-Global Each hair grows towards the closest dynamic curve(s) within the defined radius.
	*/
	UnsignedintID getCurveAttractorModel(){char buffer[4096];sprintf_s (buffer, "%s.camd",mName.c_str());return (const char*)buffer;}
	/*Used to set the radius in which to search for the closest dynamic curve, in world units. This value can help prevent fur from being influenced by dynamic curves that are unreasonably far away.*/
	DoubleID getCurveRadius(){char buffer[4096];sprintf_s (buffer, "%s.dcr",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveRadius" along U direction by importing file textures.*/
	CurveRadiusMapUSamplesID getCurveRadiusMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.crmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveRadius" along V direction by importing file textures.*/
	CurveRadiusMapVSamplesID getCurveRadiusMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.crmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getCurveRadiusMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.crmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getCurveRadiusMapMult(){char buffer[4096];sprintf_s (buffer, "%s.crmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getCurveRadiusNoise(){char buffer[4096];sprintf_s (buffer, "%s.crn",mName.c_str());return (const char*)buffer;}
	/*
	Set how the dynamic curve will influence the fur. The value you enter is the power to a falloff function that makes fur become less influenced at the base of the fur than at the tip.
	0.0 The entire length of the fur is influenced.
	1.0 Fur is much less influenced at the base.
	*/
	FloatID getCurvePower(){char buffer[4096];sprintf_s (buffer, "%s.dcp",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurvePower" along U direction by importing file textures.*/
	CurvePowerMapUSamplesID getCurvePowerMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.cpmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurvePower" along V direction by importing file textures.*/
	CurvePowerMapVSamplesID getCurvePowerMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.cpmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	FloatID getCurvePowerMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cpmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getCurvePowerMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cpmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getCurvePowerNoise(){char buffer[4096];sprintf_s (buffer, "%s.cpn",mName.c_str());return (const char*)buffer;}
	/*
	Set how much influence the dynamic curve will have on the fur. The value you enter linearly increases or decreases the influence over the length of the fur.
	0.0 No influence.
	1.0 Standard influence.
	*/
	FloatID getCurveInfluence(){char buffer[4096];sprintf_s (buffer, "%s.dci",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveInfluence" along U direction by importing file textures.*/
	CurveInfluenceMapUSamplesID getCurveInfluenceMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.cimus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveInfluence" along V direction by importing file textures.*/
	CurveInfluenceMapVSamplesID getCurveInfluenceMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.cimvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the  curve attractor attribute value by. The initial map is between 0 and 1.*/
	FloatID getCurveInfluenceMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cimo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	FloatID getCurveInfluenceMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cimm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	FloatID getCurveInfluenceNoise(){char buffer[4096];sprintf_s (buffer, "%s.cin",mName.c_str());return (const char*)buffer;}
	/*Defines to set the point along the fur, in world units, at which the hair will start being influenced. In general, this value should be 0.0, unless you want the hair to grow in its normal direction up to a point along the hair.*/
	FloatID getCurveStartLength(){char buffer[4096];sprintf_s (buffer, "%s.dcsl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveStartLength" along U direction by importing file textures.*/
	CurveStartLengthMapUSamplesID getCurveStartLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.cslmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveStartLength" along V direction by importing file textures.*/
	CurveStartLengthMapVSamplesID getCurveStartLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.cslmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getCurveStartLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.cslmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getCurveStartLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.cslmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getCurveStartLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.csln",mName.c_str());return (const char*)buffer;}
	/*Defines to set the point along the fur, in world units, at which the fur will no longer be influenced. For the best effect, this should be at least as large as the longest fur length. With smaller values the tips of the fur will not be influenced.*/
	FloatID getCurveEndLength(){char buffer[4096];sprintf_s (buffer, "%s.dcel",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveEndLength" along U direction by importing file textures.*/
	CurveEndLengthMapUSamplesID getCurveEndLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.celmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveEndLength" along V direction by importing file textures.*/
	CurveEndLengthMapVSamplesID getCurveEndLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.celmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the curve attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getCurveEndLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.celmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getCurveEndLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.celmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getCurveEndLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.celn",mName.c_str());return (const char*)buffer;}
	/*Fur shorter than this value will not be influenced at all. Use this value to prevent short fur from being influenced while long fur are influenced.*/
	FloatID getCurveThresholdLength(){char buffer[4096];sprintf_s (buffer, "%s.dctl",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" along U direction by importing file textures.*/
	CurveThresholdLengthMapUSamplesID getCurveThresholdLengthMapUSamples(){char buffer[4096];sprintf_s (buffer, "%s.ctlmus",mName.c_str());return (const char*)buffer;}
	/*Used to map values for curve attractor set attribute "CurveThresholdLength" along V direction by importing file textures.*/
	CurveThresholdLengthMapVSamplesID getCurveThresholdLengthMapVSamples(){char buffer[4096];sprintf_s (buffer, "%s.ctlmvs",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to offset the attractor attribute value by. The initial map is between 0 and 1.*/
	DoubleID getCurveThresholdLengthMapOffset(){char buffer[4096];sprintf_s (buffer, "%s.ctlmo",mName.c_str());return (const char*)buffer;}
	/*Defines to set the factor to multiply the value. The initial map is between 0 and 1.*/
	DoubleID getCurveThresholdLengthMapMult(){char buffer[4096];sprintf_s (buffer, "%s.ctlmm",mName.c_str());return (const char*)buffer;}
	/*Defines to set the noise value for the attribute. A value of 0 produces no noise.*/
	DoubleID getCurveThresholdLengthNoise(){char buffer[4096];sprintf_s (buffer, "%s.ctln",mName.c_str());return (const char*)buffer;}
protected:
	FurCurveAttractors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FURCURVEATTRACTORS_H__
