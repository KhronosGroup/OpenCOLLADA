/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACESAMPLER_H__
#define __MayaDM_SURFACESAMPLER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
The <i>surfaceSampler</i> node is for use by the Transfer Maps tool only.  Any
other use of this node is not supported.
*/
class SurfaceSampler : public DependNode
{
public:
public:
	SurfaceSampler(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "surfaceSampler"){}
	virtual ~SurfaceSampler(){}
	/*
	Max distance to the sample point in internal space
	0 means infinity. If the nearest hit is beyond
	maxDist, defaultColor will be returned.
	*/
	void setMaxDist(float S00){if(S00 == 0) return; fprintf_s(mFile, "setAttr \".S00\" %f;\n", S00);}
	/*
	Max distance to the sample point in internal space
	0 means infinity. If the nearest hit is beyond
	maxDist, defaultColor will be returned.
	*/
	void setMaxDist(const FloatID& S00){fprintf_s(mFile,"connectAttr \"");S00.write(mFile);fprintf_s(mFile,"\" \"%s.S00\";\n",mName.c_str());}
	/*
	This array specifies envelope geometry.
	If it is empty there is no envelope geometry
	*/
	void setEnvelopes(size_t S01_i,const MessageID& S01){fprintf_s(mFile,"connectAttr \"");S01.write(mFile);fprintf_s(mFile,"\" \"%s.S01[%i]\";\n",mName.c_str(),S01_i);}
	/*
	If using envelope geometry then specify how source
	geometry should be selected:
	0 - closest to envelope
	1 - inside then outside of envelope
	2 - inside of envelope only
	*/
	void setEnveloperSearch(int S02){if(S02 == 0) return; fprintf_s(mFile, "setAttr \".S02\" %i;\n", S02);}
	/*
	If using envelope geometry then specify how source
	geometry should be selected:
	0 - closest to envelope
	1 - inside then outside of envelope
	2 - inside of envelope only
	*/
	void setEnveloperSearch(const IntID& S02){fprintf_s(mFile,"connectAttr \"");S02.write(mFile);fprintf_s(mFile,"\" \"%s.S02\";\n",mName.c_str());}
	/*Evaluate material shader at the sample point*/
	void setEvaluateMaterial(bool S03){if(S03 == 0) return; fprintf_s(mFile, "setAttr \".S03\" %i;\n", S03);}
	/*Evaluate material shader at the sample point*/
	void setEvaluateMaterial(const BoolID& S03){fprintf_s(mFile,"connectAttr \"");S03.write(mFile);fprintf_s(mFile,"\" \"%s.S03\";\n",mName.c_str());}
	/*Evaluate custom shader at the sample point*/
	void setEvaluateCustomShader(bool S04){if(S04 == 0) return; fprintf_s(mFile, "setAttr \".S04\" %i;\n", S04);}
	/*Evaluate custom shader at the sample point*/
	void setEvaluateCustomShader(const BoolID& S04){fprintf_s(mFile,"connectAttr \"");S04.write(mFile);fprintf_s(mFile,"\" \"%s.S04\";\n",mName.c_str());}
	/*
	Connect custom shader to evaluate. If nothing is
	connected, customColor will be copied to outCustomColor.
	*/
	void setCustomColor(const float3& S05){if(S05 == float3(1, 1, 1)) return; fprintf_s(mFile, "setAttr \".S05\" -type \"float3\" ");S05.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Connect custom shader to evaluate. If nothing is
	connected, customColor will be copied to outCustomColor.
	*/
	void setCustomColor(const Float3ID& S05){fprintf_s(mFile,"connectAttr \"");S05.write(mFile);fprintf_s(mFile,"\" \"%s.S05\";\n",mName.c_str());}
	/*Color to be used if the sample ray did not hit any object*/
	void setDefaultColor(const float3& S06){fprintf_s(mFile, "setAttr \".S06\" -type \"float3\" ");S06.write(mFile);fprintf_s(mFile,";\n");}
	/*Color to be used if the sample ray did not hit any object*/
	void setDefaultColor(const Float3ID& S06){fprintf_s(mFile,"connectAttr \"");S06.write(mFile);fprintf_s(mFile,"\" \"%s.S06\";\n",mName.c_str());}
	/*Coordinate system for outNormal and outGeoNormal*/
	void setCoordinate(int S07){if(S07 == 1) return; fprintf_s(mFile, "setAttr \".S07\" %i;\n", S07);}
	/*Coordinate system for outNormal and outGeoNormal*/
	void setCoordinate(const IntID& S07){fprintf_s(mFile,"connectAttr \"");S07.write(mFile);fprintf_s(mFile,"\" \"%s.S07\";\n",mName.c_str());}
	/*Inverse outNormal and outGeoNormal if they are flipped*/
	void setAutoInverseNormal(bool S08){if(S08 == 1) return; fprintf_s(mFile, "setAttr \".S08\" %i;\n", S08);}
	/*Inverse outNormal and outGeoNormal if they are flipped*/
	void setAutoInverseNormal(const BoolID& S08){fprintf_s(mFile,"connectAttr \"");S08.write(mFile);fprintf_s(mFile,"\" \"%s.S08\";\n",mName.c_str());}
	/*Map the result in [-1,1] to [0,1]*/
	void setVectorToColor(bool S09){if(S09 == 0) return; fprintf_s(mFile, "setAttr \".S09\" %i;\n", S09);}
	/*Map the result in [-1,1] to [0,1]*/
	void setVectorToColor(const BoolID& S09){fprintf_s(mFile,"connectAttr \"");S09.write(mFile);fprintf_s(mFile,"\" \"%s.S09\";\n",mName.c_str());}
	/*Source geometries to consider for the intersection*/
	void setSources(size_t S10_i,const MessageID& S10){fprintf_s(mFile,"connectAttr \"");S10.write(mFile);fprintf_s(mFile,"\" \"%s.S10[%i]\";\n",mName.c_str(),S10_i);}
	/*
	Max distance to the sample point in internal space
	0 means infinity. If the nearest hit is beyond
	maxDist, defaultColor will be returned.
	*/
	FloatID getMaxDist(){char buffer[4096];sprintf_s (buffer, "%s.S00",mName.c_str());return (const char*)buffer;}
	/*
	This array specifies envelope geometry.
	If it is empty there is no envelope geometry
	*/
	const MessageID& getEnvelopes(size_t S01_i){char buffer[4096];sprintf_s (buffer, "%s.S01[%i]",mName.c_str(),S01_i);return (const char*)buffer;}
	/*
	If using envelope geometry then specify how source
	geometry should be selected:
	0 - closest to envelope
	1 - inside then outside of envelope
	2 - inside of envelope only
	*/
	IntID getEnveloperSearch(){char buffer[4096];sprintf_s (buffer, "%s.S02",mName.c_str());return (const char*)buffer;}
	/*Evaluate material shader at the sample point*/
	BoolID getEvaluateMaterial(){char buffer[4096];sprintf_s (buffer, "%s.S03",mName.c_str());return (const char*)buffer;}
	/*Evaluate custom shader at the sample point*/
	BoolID getEvaluateCustomShader(){char buffer[4096];sprintf_s (buffer, "%s.S04",mName.c_str());return (const char*)buffer;}
	/*
	Connect custom shader to evaluate. If nothing is
	connected, customColor will be copied to outCustomColor.
	*/
	Float3ID getCustomColor(){char buffer[4096];sprintf_s (buffer, "%s.S05",mName.c_str());return (const char*)buffer;}
	/*Color to be used if the sample ray did not hit any object*/
	Float3ID getDefaultColor(){char buffer[4096];sprintf_s (buffer, "%s.S06",mName.c_str());return (const char*)buffer;}
	/*Coordinate system for outNormal and outGeoNormal*/
	IntID getCoordinate(){char buffer[4096];sprintf_s (buffer, "%s.S07",mName.c_str());return (const char*)buffer;}
	/*Inverse outNormal and outGeoNormal if they are flipped*/
	BoolID getAutoInverseNormal(){char buffer[4096];sprintf_s (buffer, "%s.S08",mName.c_str());return (const char*)buffer;}
	/*Map the result in [-1,1] to [0,1]*/
	BoolID getVectorToColor(){char buffer[4096];sprintf_s (buffer, "%s.S09",mName.c_str());return (const char*)buffer;}
	/*Source geometries to consider for the intersection*/
	const MessageID& getSources(size_t S10_i){char buffer[4096];sprintf_s (buffer, "%s.S10[%i]",mName.c_str(),S10_i);return (const char*)buffer;}
protected:
	SurfaceSampler(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SURFACESAMPLER_H__
