/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SIMPLEVOLUMESHADER_H__
#define __MayaDM_SIMPLEVOLUMESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>
        This class describes a simple volume shader.

</pre></p>
*/
class SimpleVolumeShader : public DependNode
{
public:
public:
	SimpleVolumeShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "simpleVolumeShader"){}
	virtual ~SimpleVolumeShader(){}
	/*The parameter.*/
	void setParameter1(float p1){if(p1 == 0.45) return; fprintf_s(mFile, "setAttr \".p1\" %f;\n", p1);}
	/*The parameter.*/
	void setParameter1(const FloatID& p1){fprintf_s(mFile,"connectAttr \"");p1.write(mFile);fprintf_s(mFile,"\" \"%s.p1\";\n",mName.c_str());}
	/*Input color*/
	void setColor(const float3& c){fprintf_s(mFile, "setAttr \".c\" -type \"float3\" ");c.write(mFile);fprintf_s(mFile,";\n");}
	/*Input color*/
	void setColor(const Float3ID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*Input color red value*/
	void setColorR(float cr){if(cr == 0.0) return; fprintf_s(mFile, "setAttr \".c.cr\" %f;\n", cr);}
	/*Input color red value*/
	void setColorR(const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.c.cr\";\n",mName.c_str());}
	/*Input color green value*/
	void setColorG(float cg){if(cg == 0.58824) return; fprintf_s(mFile, "setAttr \".c.cg\" %f;\n", cg);}
	/*Input color green value*/
	void setColorG(const FloatID& cg){fprintf_s(mFile,"connectAttr \"");cg.write(mFile);fprintf_s(mFile,"\" \"%s.c.cg\";\n",mName.c_str());}
	/*Input color blue value*/
	void setColorB(float cb){if(cb == 0.644) return; fprintf_s(mFile, "setAttr \".c.cb\" %f;\n", cb);}
	/*Input color blue value*/
	void setColorB(const FloatID& cb){fprintf_s(mFile,"connectAttr \"");cb.write(mFile);fprintf_s(mFile,"\" \"%s.c.cb\";\n",mName.c_str());}
	/*The surface point.*/
	void setPointWorld(const float3& p){if(p == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".p\" -type \"float3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the position.*/
	void setPointWorldX(float px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*The y-component of the position.*/
	void setPointWorldY(float py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*The z-component of the position.*/
	void setPointWorldZ(float pz){if(pz == 0.0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*The surface farPoint.*/
	void setFarPointWorld(const float3& fp){if(fp == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".fp\" -type \"float3\" ");fp.write(mFile);fprintf_s(mFile,";\n");}
	/*The x-component of the far point.*/
	void setFarPointWorldX(float fpx){if(fpx == 0.0) return; fprintf_s(mFile, "setAttr \".fp.fpx\" %f;\n", fpx);}
	/*The y-component of the far point.*/
	void setFarPointWorldY(float fpy){if(fpy == 0.0) return; fprintf_s(mFile, "setAttr \".fp.fpy\" %f;\n", fpy);}
	/*The z-component of the far point.*/
	void setFarPointWorldZ(float fpz){if(fpz == 0.0) return; fprintf_s(mFile, "setAttr \".fp.fpz\" %f;\n", fpz);}
	/*Output color*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Output color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*Output color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*Output color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*Output transparency*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Output transparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*Output transparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*Output transparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*The parameter.*/
	FloatID getParameter1(){char buffer[4096];sprintf_s (buffer, "%s.p1",mName.c_str());return (const char*)buffer;}
	/*Input color*/
	Float3ID getColor(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*Input color red value*/
	FloatID getColorR(){char buffer[4096];sprintf_s (buffer, "%s.c.cr",mName.c_str());return (const char*)buffer;}
	/*Input color green value*/
	FloatID getColorG(){char buffer[4096];sprintf_s (buffer, "%s.c.cg",mName.c_str());return (const char*)buffer;}
	/*Input color blue value*/
	FloatID getColorB(){char buffer[4096];sprintf_s (buffer, "%s.c.cb",mName.c_str());return (const char*)buffer;}
	/*Output color*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Output color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*Output color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*Output color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*Output transparency*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Output transparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*Output transparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*Output transparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
protected:
	SimpleVolumeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SIMPLEVOLUMESHADER_H__
