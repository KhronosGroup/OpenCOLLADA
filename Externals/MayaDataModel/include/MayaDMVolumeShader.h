/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_VOLUMESHADER_H__
#define __MayaDM_VOLUMESHADER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
Use a <b>Volume Shader</b> when you want to completely control
  the color, transparency, and matte opacity of a volumetric material.
  This kind of shader does no shading calculation of any kind.  Rather,
  it allows you to connect other attributes directly to its
  color, transparency, and matte opacity.  It completely ignores everything
  else that would normally affect a volume shader.
 <p/>
  For example, if you connect the Translate attribute of an object
  to the Out Color attribute of a Volume Shader, then the color
  of the shader will depend on the position of the object in space.
 <p/>
  If you are connecting this node manually to a shading group, then
  you should connect the Out Color attribute of the Volume Shader to
  the Volume Material input of the the
  shading group. (This is sometimes called the Volume Shader input.)
  (Most other shaders connect to the Surface Shader
  input.)
  <p/>
  In the table below, important attributes have their names indicated
  in <b>bold</b> in the decription column.
*/
class VolumeShader : public DependNode
{
public:
public:
	VolumeShader(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "volumeShader"){}
	virtual ~VolumeShader(){}
	/*
	<b>Out Color</b>.  Connect another attribute to this to
	control the color of the volume shader.
	*/
	void setOutColor(const float3& oc){if(oc == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".oc\" -type \"float3\" ");oc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Color</b>.  Connect another attribute to this to
	control the color of the volume shader.
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
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the Shader transparency.  Higher values (that is,
	brighter colors) make the object more transparent;  darker
	colors make it more opaque.
	*/
	void setOutTransparency(const float3& ot){if(ot == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".ot\" -type \"float3\" ");ot.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the Shader transparency.  Higher values (that is,
	brighter colors) make the object more transparent;  darker
	colors make it more opaque.
	*/
	void setOutTransparency(const Float3ID& ot){fprintf_s(mFile,"connectAttr \"");ot.write(mFile);fprintf_s(mFile,"\" \"%s.ot\";\n",mName.c_str());}
	/*Out Transparency red value*/
	void setOutTransparencyR(float otr){if(otr == 0.0) return; fprintf_s(mFile, "setAttr \".ot.otr\" %f;\n", otr);}
	/*Out Transparency red value*/
	void setOutTransparencyR(const FloatID& otr){fprintf_s(mFile,"connectAttr \"");otr.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otr\";\n",mName.c_str());}
	/*Out Transparency green value*/
	void setOutTransparencyG(float otg){if(otg == 0.0) return; fprintf_s(mFile, "setAttr \".ot.otg\" %f;\n", otg);}
	/*Out Transparency green value*/
	void setOutTransparencyG(const FloatID& otg){fprintf_s(mFile,"connectAttr \"");otg.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otg\";\n",mName.c_str());}
	/*Out Transparency blue value*/
	void setOutTransparencyB(float otb){if(otb == 0.0) return; fprintf_s(mFile, "setAttr \".ot.otb\" %f;\n", otb);}
	/*Out Transparency blue value*/
	void setOutTransparencyB(const FloatID& otb){fprintf_s(mFile,"connectAttr \"");otb.write(mFile);fprintf_s(mFile,"\" \"%s.ot.otb\";\n",mName.c_str());}
	/*
	<b>Out Matte Opacity</b>.  Connect another attribute to this
	to control the opacity of the material matte (alpha) channel.
	*/
	void setOutMatteOpacity(const float3& omo){if(omo == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".omo\" -type \"float3\" ");omo.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Out Matte Opacity</b>.  Connect another attribute to this
	to control the opacity of the material matte (alpha) channel.
	*/
	void setOutMatteOpacity(const Float3ID& omo){fprintf_s(mFile,"connectAttr \"");omo.write(mFile);fprintf_s(mFile,"\" \"%s.omo\";\n",mName.c_str());}
	/*Out Matte Opacity red value*/
	void setOutMatteOpacityR(float omor){if(omor == 0.0) return; fprintf_s(mFile, "setAttr \".omo.omor\" %f;\n", omor);}
	/*Out Matte Opacity red value*/
	void setOutMatteOpacityR(const FloatID& omor){fprintf_s(mFile,"connectAttr \"");omor.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omor\";\n",mName.c_str());}
	/*Out Matte Opacity green value*/
	void setOutMatteOpacityG(float omog){if(omog == 0.0) return; fprintf_s(mFile, "setAttr \".omo.omog\" %f;\n", omog);}
	/*Out Matte Opacity green value*/
	void setOutMatteOpacityG(const FloatID& omog){fprintf_s(mFile,"connectAttr \"");omog.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omog\";\n",mName.c_str());}
	/*Out Matte Opacity blue value*/
	void setOutMatteOpacityB(float omob){if(omob == 0.0) return; fprintf_s(mFile, "setAttr \".omo.omob\" %f;\n", omob);}
	/*Out Matte Opacity blue value*/
	void setOutMatteOpacityB(const FloatID& omob){fprintf_s(mFile,"connectAttr \"");omob.write(mFile);fprintf_s(mFile,"\" \"%s.omo.omob\";\n",mName.c_str());}
	/*
	<b>Out Color</b>.  Connect another attribute to this to
	control the color of the volume shader.
	*/
	Float3ID getOutColor(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
	/*Out Color red value*/
	FloatID getOutColorR(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocr",mName.c_str());return (const char*)buffer;}
	/*Out Color green value*/
	FloatID getOutColorG(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocg",mName.c_str());return (const char*)buffer;}
	/*Out Color blue value*/
	FloatID getOutColorB(){char buffer[4096];sprintf_s (buffer, "%s.oc.ocb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Transparency</b>. Connect another attribute to this to
	control the Shader transparency.  Higher values (that is,
	brighter colors) make the object more transparent;  darker
	colors make it more opaque.
	*/
	Float3ID getOutTransparency(){char buffer[4096];sprintf_s (buffer, "%s.ot",mName.c_str());return (const char*)buffer;}
	/*Out Transparency red value*/
	FloatID getOutTransparencyR(){char buffer[4096];sprintf_s (buffer, "%s.ot.otr",mName.c_str());return (const char*)buffer;}
	/*Out Transparency green value*/
	FloatID getOutTransparencyG(){char buffer[4096];sprintf_s (buffer, "%s.ot.otg",mName.c_str());return (const char*)buffer;}
	/*Out Transparency blue value*/
	FloatID getOutTransparencyB(){char buffer[4096];sprintf_s (buffer, "%s.ot.otb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Matte Opacity</b>.  Connect another attribute to this
	to control the opacity of the material matte (alpha) channel.
	*/
	Float3ID getOutMatteOpacity(){char buffer[4096];sprintf_s (buffer, "%s.omo",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity red value*/
	FloatID getOutMatteOpacityR(){char buffer[4096];sprintf_s (buffer, "%s.omo.omor",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity green value*/
	FloatID getOutMatteOpacityG(){char buffer[4096];sprintf_s (buffer, "%s.omo.omog",mName.c_str());return (const char*)buffer;}
	/*Out Matte Opacity blue value*/
	FloatID getOutMatteOpacityB(){char buffer[4096];sprintf_s (buffer, "%s.omo.omob",mName.c_str());return (const char*)buffer;}
protected:
	VolumeShader(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_VOLUMESHADER_H__
