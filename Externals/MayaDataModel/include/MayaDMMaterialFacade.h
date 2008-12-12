/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MATERIALFACADE_H__
#define __MayaDM_MATERIALFACADE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFacade.h"
namespace MayaDM
{
/*
<b>materialFacade</b> is a node to which dynamic attributes
        can be added to define the parameters of a material.
*/
class MaterialFacade : public Facade
{
public:
public:
	MaterialFacade(FILE* file,const std::string& name,const std::string& parent=""):Facade(file, name, parent, "materialFacade"){}
	virtual ~MaterialFacade(){}
	/*Connection to a hardware shader for interactive drawning override.*/
	void setHardwareProxy(const MessageID& hp){fprintf_s(mFile,"connectAttr \"");hp.write(mFile);fprintf_s(mFile,"\" \"%s.hp\";\n",mName.c_str());}
	/*For internal use only*/
	void setProxyInitProc(const string& pip){if(pip == "NULL") return; fprintf_s(mFile, "setAttr \".pip\" -type \"string\" ");pip.write(mFile);fprintf_s(mFile,";\n");}
	/*For internal use only*/
	void setProxyInitProc(const StringID& pip){fprintf_s(mFile,"connectAttr \"");pip.write(mFile);fprintf_s(mFile,"\" \"%s.pip\";\n",mName.c_str());}
	/*
	<b>Out Color</b>.
	Defines the resulting color of the under-lying material
	*/
	void setOutColor(const float3& oc){if(oc == float3(1.0, 0.6, 0.4)) return; fprintf_s(mFile, "setAttr \".oc\" -type \"float3\" ");oc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Color</b>.
	Defines the resulting color of the under-lying material
	*/
	void setOutColor(const Float3ID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*Out Color red value*/
	void setOutColorR(float ocr){if(ocr == 0.0) return; fprintf_s(mFile, "setAttr \".oc.ocr\" %f;\n", ocr);}
	/*Out Color red value*/
	void setOutColorR(const FloatID& ocr){fprintf_s(mFile,"connectAttr \"");ocr.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocr\";\n",mName.c_str());}
	/*Out Color green value*/
	void setOutColorG(float ocg){if(ocg == 0.0) return; fprintf_s(mFile, "setAttr \".oc.ocg\" %f;\n", ocg);}
	/*Out Color green value*/
	void setOutColorG(const FloatID& ocg){fprintf_s(mFile,"connectAttr \"");ocg.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocg\";\n",mName.c_str());}
	/*Out Color blue value*/
	void setOutColorB(float ocb){if(ocb == 0.0) return; fprintf_s(mFile, "setAttr \".oc.ocb\" %f;\n", ocb);}
	/*Out Color blue value*/
	void setOutColorB(const FloatID& ocb){fprintf_s(mFile,"connectAttr \"");ocb.write(mFile);fprintf_s(mFile,"\" \"%s.oc.ocb\";\n",mName.c_str());}
	/*Connection to a hardware shader for interactive drawning override.*/
	MessageID getHardwareProxy(){char buffer[4096];sprintf_s (buffer, "%s.hp",mName.c_str());return (const char*)buffer;}
	/*For internal use only*/
	StringID getProxyInitProc(){char buffer[4096];sprintf_s (buffer, "%s.pip",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Color</b>.
	Defines the resulting color of the under-lying material
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Out Color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*Out Color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*Out Color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
protected:
	MaterialFacade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Facade(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MATERIALFACADE_H__
