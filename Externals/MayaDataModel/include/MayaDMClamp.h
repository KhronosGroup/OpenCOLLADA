/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLAMP_H__
#define __MayaDM_CLAMP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Clamp</b> is a utility node that can be used to
 keep a color value within a specified range.  Input values outside
 the range are "clamped" to the allowed range.
 <p/>
 For example, if you set MinR to 0.3 and MaxR to 0.6, here are the
 outputs you would get for various inputs:
 <pre>
 InputR:    0.1   0.2   0.3   0.4   0.5   0.6   0.7   0.8   0.9
 OutputR:   0.3   0.3   0.3   0.4   0.5   0.6   0.6   0.6   0.6
 </pre>
 <p/>
 You can also use this node to clamp individual values (not just colors)
 to a specified
 range.  To do this, just attach the value to one of the R, G, or B channels
 of the input (<i>e.g.</i> Input R or Input G).
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class Clamp : public DependNode
{
public:
public:
	Clamp(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "clamp"){}
	virtual ~Clamp(){}
	/*
	<b>Min</b> is the minimum values for the color channels
	that will be allowed in the output.
	*/
	void setMin(const float3& mn){if(mn == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".mn\" -type \"float3\" ");mn.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Min</b> is the minimum values for the color channels
	that will be allowed in the output.
	*/
	void setMin(const Float3ID& mn){fprintf_s(mFile,"connectAttr \"");mn.write(mFile);fprintf_s(mFile,"\" \"%s.mn\";\n",mName.c_str());}
	/*Red component of Min*/
	void setMinR(float mnr){if(mnr == 0.0) return; fprintf_s(mFile, "setAttr \".mn.mnr\" %f;\n", mnr);}
	/*Red component of Min*/
	void setMinR(const FloatID& mnr){fprintf_s(mFile,"connectAttr \"");mnr.write(mFile);fprintf_s(mFile,"\" \"%s.mn.mnr\";\n",mName.c_str());}
	/*Green component of Min*/
	void setMinG(float mng){if(mng == 0.0) return; fprintf_s(mFile, "setAttr \".mn.mng\" %f;\n", mng);}
	/*Green component of Min*/
	void setMinG(const FloatID& mng){fprintf_s(mFile,"connectAttr \"");mng.write(mFile);fprintf_s(mFile,"\" \"%s.mn.mng\";\n",mName.c_str());}
	/*Blue component of Min*/
	void setMinB(float mnb){if(mnb == 0.0) return; fprintf_s(mFile, "setAttr \".mn.mnb\" %f;\n", mnb);}
	/*Blue component of Min*/
	void setMinB(const FloatID& mnb){fprintf_s(mFile,"connectAttr \"");mnb.write(mFile);fprintf_s(mFile,"\" \"%s.mn.mnb\";\n",mName.c_str());}
	/*
	<b>Max</b> is the maximum values for the color channels
	that will be allowed in the output.
	*/
	void setMax(const float3& mx){if(mx == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".mx\" -type \"float3\" ");mx.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Max</b> is the maximum values for the color channels
	that will be allowed in the output.
	*/
	void setMax(const Float3ID& mx){fprintf_s(mFile,"connectAttr \"");mx.write(mFile);fprintf_s(mFile,"\" \"%s.mx\";\n",mName.c_str());}
	/*Red component of Max*/
	void setMaxR(float mxr){if(mxr == 0.0) return; fprintf_s(mFile, "setAttr \".mx.mxr\" %f;\n", mxr);}
	/*Red component of Max*/
	void setMaxR(const FloatID& mxr){fprintf_s(mFile,"connectAttr \"");mxr.write(mFile);fprintf_s(mFile,"\" \"%s.mx.mxr\";\n",mName.c_str());}
	/*Green component of Max*/
	void setMaxG(float mxg){if(mxg == 0.0) return; fprintf_s(mFile, "setAttr \".mx.mxg\" %f;\n", mxg);}
	/*Green component of Max*/
	void setMaxG(const FloatID& mxg){fprintf_s(mFile,"connectAttr \"");mxg.write(mFile);fprintf_s(mFile,"\" \"%s.mx.mxg\";\n",mName.c_str());}
	/*Blue component of Max*/
	void setMaxB(float mxb){if(mxb == 0.0) return; fprintf_s(mFile, "setAttr \".mx.mxb\" %f;\n", mxb);}
	/*Blue component of Max*/
	void setMaxB(const FloatID& mxb){fprintf_s(mFile,"connectAttr \"");mxb.write(mFile);fprintf_s(mFile,"\" \"%s.mx.mxb\";\n",mName.c_str());}
	/*
	<b>Input</b> is the input color or texture that will be clamped
	by this node.
	*/
	void setInput(const float3& ip){if(ip == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ip\" -type \"float3\" ");ip.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input</b> is the input color or texture that will be clamped
	by this node.
	*/
	void setInput(const Float3ID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*Red component of Input*/
	void setInputR(float ipr){if(ipr == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipr\" %f;\n", ipr);}
	/*Red component of Input*/
	void setInputR(const FloatID& ipr){fprintf_s(mFile,"connectAttr \"");ipr.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipr\";\n",mName.c_str());}
	/*Green component of Input*/
	void setInputG(float ipg){if(ipg == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipg\" %f;\n", ipg);}
	/*Green component of Input*/
	void setInputG(const FloatID& ipg){fprintf_s(mFile,"connectAttr \"");ipg.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipg\";\n",mName.c_str());}
	/*Blue component of Input*/
	void setInputB(float ipb){if(ipb == 0.0) return; fprintf_s(mFile, "setAttr \".ip.ipb\" %f;\n", ipb);}
	/*Blue component of Input*/
	void setInputB(const FloatID& ipb){fprintf_s(mFile,"connectAttr \"");ipb.write(mFile);fprintf_s(mFile,"\" \"%s.ip.ipb\";\n",mName.c_str());}
	/*
	<b>Ouput</b> is the final clamped value.  It is calculated
	by taking Input, and clamping all the values that go
	outside the range defined by Min and Max for each channel.
	*/
	void setOutput(const Float3ID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Red component of Output*/
	void setOutputR(const FloatID& opr){fprintf_s(mFile,"connectAttr \"");opr.write(mFile);fprintf_s(mFile,"\" \"%s.op.opr\";\n",mName.c_str());}
	/*Green component of Output*/
	void setOutputG(const FloatID& opg){fprintf_s(mFile,"connectAttr \"");opg.write(mFile);fprintf_s(mFile,"\" \"%s.op.opg\";\n",mName.c_str());}
	/*Blue component of Output*/
	void setOutputB(const FloatID& opb){fprintf_s(mFile,"connectAttr \"");opb.write(mFile);fprintf_s(mFile,"\" \"%s.op.opb\";\n",mName.c_str());}
	/*
	<b>Min</b> is the minimum values for the color channels
	that will be allowed in the output.
	*/
	Float3ID getMin(){char buffer[4096];sprintf_s (buffer, "%s.mn",mName.c_str());return (const char*)buffer;}
	/*Red component of Min*/
	FloatID getMinR(){char buffer[4096];sprintf_s (buffer, "%s.mn.mnr",mName.c_str());return (const char*)buffer;}
	/*Green component of Min*/
	FloatID getMinG(){char buffer[4096];sprintf_s (buffer, "%s.mn.mng",mName.c_str());return (const char*)buffer;}
	/*Blue component of Min*/
	FloatID getMinB(){char buffer[4096];sprintf_s (buffer, "%s.mn.mnb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Max</b> is the maximum values for the color channels
	that will be allowed in the output.
	*/
	Float3ID getMax(){char buffer[4096];sprintf_s (buffer, "%s.mx",mName.c_str());return (const char*)buffer;}
	/*Red component of Max*/
	FloatID getMaxR(){char buffer[4096];sprintf_s (buffer, "%s.mx.mxr",mName.c_str());return (const char*)buffer;}
	/*Green component of Max*/
	FloatID getMaxG(){char buffer[4096];sprintf_s (buffer, "%s.mx.mxg",mName.c_str());return (const char*)buffer;}
	/*Blue component of Max*/
	FloatID getMaxB(){char buffer[4096];sprintf_s (buffer, "%s.mx.mxb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Input</b> is the input color or texture that will be clamped
	by this node.
	*/
	Float3ID getInput(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*Red component of Input*/
	FloatID getInputR(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipr",mName.c_str());return (const char*)buffer;}
	/*Green component of Input*/
	FloatID getInputG(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipg",mName.c_str());return (const char*)buffer;}
	/*Blue component of Input*/
	FloatID getInputB(){char buffer[4096];sprintf_s (buffer, "%s.ip.ipb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ouput</b> is the final clamped value.  It is calculated
	by taking Input, and clamping all the values that go
	outside the range defined by Min and Max for each channel.
	*/
	Float3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*Red component of Output*/
	FloatID getOutputR(){char buffer[4096];sprintf_s (buffer, "%s.op.opr",mName.c_str());return (const char*)buffer;}
	/*Green component of Output*/
	FloatID getOutputG(){char buffer[4096];sprintf_s (buffer, "%s.op.opg",mName.c_str());return (const char*)buffer;}
	/*Blue component of Output*/
	FloatID getOutputB(){char buffer[4096];sprintf_s (buffer, "%s.op.opb",mName.c_str());return (const char*)buffer;}
protected:
	Clamp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CLAMP_H__
