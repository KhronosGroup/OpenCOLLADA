/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ARRAYMAPPER_H__
#define __MayaDM_ARRAYMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Node used for mapping array attribute to the color attributes
    of texture nodes. Typically used by particle objects to invoke
    color values from the texture node for each particle.
</pre></p>
*/
class ArrayMapper : public DependNode
{
public:
public:
	ArrayMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "arrayMapper"){}
	virtual ~ArrayMapper(){}
	/*The u component of an array of sample positions.*/
	void setUCoordPP(const DoubleArrayID& upp){fprintf_s(mFile,"connectAttr \"");upp.write(mFile);fprintf_s(mFile,"\" \"%s.upp\";\n",mName.c_str());}
	/*The v component of an array of sample positions.*/
	void setVCoordPP(const DoubleArrayID& vpp){fprintf_s(mFile,"connectAttr \"");vpp.write(mFile);fprintf_s(mFile,"\" \"%s.vpp\";\n",mName.c_str());}
	/*The minimum limit on the output attribute outValuePP.*/
	void setMinValue(double min){if(min == 0.0) return; fprintf_s(mFile, "setAttr \".min\" %f;\n", min);}
	/*The minimum limit on the output attribute outValuePP.*/
	void setMinValue(const DoubleID& min){fprintf_s(mFile,"connectAttr \"");min.write(mFile);fprintf_s(mFile,"\" \"%s.min\";\n",mName.c_str());}
	/*The maximum limit on the output attribute outValuePP.*/
	void setMaxValue(double max){if(max == 1.0) return; fprintf_s(mFile, "setAttr \".max\" %f;\n", max);}
	/*The maximum limit on the output attribute outValuePP.*/
	void setMaxValue(const DoubleID& max){fprintf_s(mFile,"connectAttr \"");max.write(mFile);fprintf_s(mFile,"\" \"%s.max\";\n",mName.c_str());}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	void setComputeNodeColor(const Double3ID& cnc){fprintf_s(mFile,"connectAttr \"");cnc.write(mFile);fprintf_s(mFile,"\" \"%s.cnc\";\n",mName.c_str());}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	void setComputeNodeColorR(const DoubleID& cncr){fprintf_s(mFile,"connectAttr \"");cncr.write(mFile);fprintf_s(mFile,"\" \"%s.cnc.cncr\";\n",mName.c_str());}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	void setComputeNodeColorG(const DoubleID& cncg){fprintf_s(mFile,"connectAttr \"");cncg.write(mFile);fprintf_s(mFile,"\" \"%s.cnc.cncg\";\n",mName.c_str());}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	void setComputeNodeColorB(const DoubleID& cncb){fprintf_s(mFile,"connectAttr \"");cncb.write(mFile);fprintf_s(mFile,"\" \"%s.cnc.cncb\";\n",mName.c_str());}
	/*This holds the value for time to be queried in seconds.*/
	void setTime(const TimeID& tim){fprintf_s(mFile,"connectAttr \"");tim.write(mFile);fprintf_s(mFile,"\" \"%s.tim\";\n",mName.c_str());}
	/*The array of output colors for the array of sample positions.*/
	void setOutColorPP(const VectorArrayID& ocpp){fprintf_s(mFile,"connectAttr \"");ocpp.write(mFile);fprintf_s(mFile,"\" \"%s.ocpp\";\n",mName.c_str());}
	/*The array of output values for the array of sample positions.*/
	void setOutValuePP(const DoubleArrayID& ovpp){fprintf_s(mFile,"connectAttr \"");ovpp.write(mFile);fprintf_s(mFile,"\" \"%s.ovpp\";\n",mName.c_str());}
	/*The u component of an array of sample positions.*/
	DoubleArrayID getUCoordPP(){char buffer[4096];sprintf_s (buffer, "%s.upp",mName.c_str());return (const char*)buffer;}
	/*The v component of an array of sample positions.*/
	DoubleArrayID getVCoordPP(){char buffer[4096];sprintf_s (buffer, "%s.vpp",mName.c_str());return (const char*)buffer;}
	/*The minimum limit on the output attribute outValuePP.*/
	DoubleID getMinValue(){char buffer[4096];sprintf_s (buffer, "%s.min",mName.c_str());return (const char*)buffer;}
	/*The maximum limit on the output attribute outValuePP.*/
	DoubleID getMaxValue(){char buffer[4096];sprintf_s (buffer, "%s.max",mName.c_str());return (const char*)buffer;}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	Double3ID getComputeNodeColor(){char buffer[4096];sprintf_s (buffer, "%s.cnc",mName.c_str());return (const char*)buffer;}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	DoubleID getComputeNodeColorR(){char buffer[4096];sprintf_s (buffer, "%s.cnc.cncr",mName.c_str());return (const char*)buffer;}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	DoubleID getComputeNodeColorG(){char buffer[4096];sprintf_s (buffer, "%s.cnc.cncg",mName.c_str());return (const char*)buffer;}
	/*
	This attribute allows the propogation of any changes to the
	computeNode's outColor through the arrayMapper and on to the
	attribute that the arrayMapper is driving.
	*/
	DoubleID getComputeNodeColorB(){char buffer[4096];sprintf_s (buffer, "%s.cnc.cncb",mName.c_str());return (const char*)buffer;}
	/*This holds the value for time to be queried in seconds.*/
	TimeID getTime(){char buffer[4096];sprintf_s (buffer, "%s.tim",mName.c_str());return (const char*)buffer;}
	/*The array of output colors for the array of sample positions.*/
	VectorArrayID getOutColorPP(){char buffer[4096];sprintf_s (buffer, "%s.ocpp",mName.c_str());return (const char*)buffer;}
	/*The array of output values for the array of sample positions.*/
	DoubleArrayID getOutValuePP(){char buffer[4096];sprintf_s (buffer, "%s.ovpp",mName.c_str());return (const char*)buffer;}
protected:
	ArrayMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ARRAYMAPPER_H__
