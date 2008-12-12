/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BLENDCOLORS_H__
#define __MayaDM_BLENDCOLORS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Blend Colors</b> is a utility node that allows you to blend
 together two input colors or textures, using a third value to
 control the blend.
<p/>
 The color of the output is determined by the
 Blender attribute, which can range from 0 to 1.  When Blender
 is 1, the Output is set to Color 1.  When Blender is 0, Output is
 set to Color 2.  When Blender is 0.5, Output is an equal mix of
 the two colors.
<p/>
 By applying a texture map to Blender (say, an image of white text
 on a black background) you can create a shader that uses Color 1
 for the text, and Color 2 for the background.
<p/>
 Here is the formula used for color blending:
 <ul>
 Output[i] = Color1[i] * Blender[i] + Color2[i] * (1.0 - Blender[i])
 </ul>
<p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class BlendColors : public DependNode
{
public:
public:
	BlendColors(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "blendColors"){}
	virtual ~BlendColors(){}
	/*
	<b>Blender</b> controls how much of each of the input
	colors is mixed into the final Output.  As Blender
	increases, you see more of Color 1 and less of Color 2.
	As it decreases, you see more of Color 2 and less of Color 1.
	*/
	void setBlender(float b){if(b == 0.5) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*
	<b>Blender</b> controls how much of each of the input
	colors is mixed into the final Output.  As Blender
	increases, you see more of Color 1 and less of Color 2.
	As it decreases, you see more of Color 2 and less of Color 1.
	*/
	void setBlender(const FloatID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*<b>Color 1</b> is the first input color.*/
	void setColor1(const float3& c1){if(c1 == float3(1.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".c1\" -type \"float3\" ");c1.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Color 1</b> is the first input color.*/
	void setColor1(const Float3ID& c1){fprintf_s(mFile,"connectAttr \"");c1.write(mFile);fprintf_s(mFile,"\" \"%s.c1\";\n",mName.c_str());}
	/*The red component of Color 1*/
	void setColor1R(float c1r){if(c1r == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1r\" %f;\n", c1r);}
	/*The red component of Color 1*/
	void setColor1R(const FloatID& c1r){fprintf_s(mFile,"connectAttr \"");c1r.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1r\";\n",mName.c_str());}
	/*The green component of Color 1*/
	void setColor1G(float c1g){if(c1g == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1g\" %f;\n", c1g);}
	/*The green component of Color 1*/
	void setColor1G(const FloatID& c1g){fprintf_s(mFile,"connectAttr \"");c1g.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1g\";\n",mName.c_str());}
	/*The blue component of Color 1*/
	void setColor1B(float c1b){if(c1b == 0.0) return; fprintf_s(mFile, "setAttr \".c1.c1b\" %f;\n", c1b);}
	/*The blue component of Color 1*/
	void setColor1B(const FloatID& c1b){fprintf_s(mFile,"connectAttr \"");c1b.write(mFile);fprintf_s(mFile,"\" \"%s.c1.c1b\";\n",mName.c_str());}
	/*<b>Color 2</b> is the second input color.*/
	void setColor2(const float3& c2){if(c2 == float3(0.0, 0.0, 1.0)) return; fprintf_s(mFile, "setAttr \".c2\" -type \"float3\" ");c2.write(mFile);fprintf_s(mFile,";\n");}
	/*<b>Color 2</b> is the second input color.*/
	void setColor2(const Float3ID& c2){fprintf_s(mFile,"connectAttr \"");c2.write(mFile);fprintf_s(mFile,"\" \"%s.c2\";\n",mName.c_str());}
	/*The red component of Color 2*/
	void setColor2R(float c2r){if(c2r == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2r\" %f;\n", c2r);}
	/*The red component of Color 2*/
	void setColor2R(const FloatID& c2r){fprintf_s(mFile,"connectAttr \"");c2r.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2r\";\n",mName.c_str());}
	/*The green component of Color 2*/
	void setColor2G(float c2g){if(c2g == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2g\" %f;\n", c2g);}
	/*The green component of Color 2*/
	void setColor2G(const FloatID& c2g){fprintf_s(mFile,"connectAttr \"");c2g.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2g\";\n",mName.c_str());}
	/*The blue component of Color 2*/
	void setColor2B(float c2b){if(c2b == 0.0) return; fprintf_s(mFile, "setAttr \".c2.c2b\" %f;\n", c2b);}
	/*The blue component of Color 2*/
	void setColor2B(const FloatID& c2b){fprintf_s(mFile,"connectAttr \"");c2b.write(mFile);fprintf_s(mFile,"\" \"%s.c2.c2b\";\n",mName.c_str());}
	/*<b>Output</b> is the final blended color.*/
	void setOutput(const Float3ID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*The X component of Output*/
	void setOutputR(const FloatID& opr){fprintf_s(mFile,"connectAttr \"");opr.write(mFile);fprintf_s(mFile,"\" \"%s.op.opr\";\n",mName.c_str());}
	/*The Y component of Output*/
	void setOutputG(const FloatID& opg){fprintf_s(mFile,"connectAttr \"");opg.write(mFile);fprintf_s(mFile,"\" \"%s.op.opg\";\n",mName.c_str());}
	/*The Z component of Output*/
	void setOutputB(const FloatID& opb){fprintf_s(mFile,"connectAttr \"");opb.write(mFile);fprintf_s(mFile,"\" \"%s.op.opb\";\n",mName.c_str());}
	/*
	<b>Blender</b> controls how much of each of the input
	colors is mixed into the final Output.  As Blender
	increases, you see more of Color 1 and less of Color 2.
	As it decreases, you see more of Color 2 and less of Color 1.
	*/
	FloatID getBlender(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*<b>Color 1</b> is the first input color.*/
	Float3ID getColor1(){char buffer[4096];sprintf_s (buffer, "%s.c1",mName.c_str());return (const char*)buffer;}
	/*The red component of Color 1*/
	FloatID getColor1R(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1r",mName.c_str());return (const char*)buffer;}
	/*The green component of Color 1*/
	FloatID getColor1G(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1g",mName.c_str());return (const char*)buffer;}
	/*The blue component of Color 1*/
	FloatID getColor1B(){char buffer[4096];sprintf_s (buffer, "%s.c1.c1b",mName.c_str());return (const char*)buffer;}
	/*<b>Color 2</b> is the second input color.*/
	Float3ID getColor2(){char buffer[4096];sprintf_s (buffer, "%s.c2",mName.c_str());return (const char*)buffer;}
	/*The red component of Color 2*/
	FloatID getColor2R(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2r",mName.c_str());return (const char*)buffer;}
	/*The green component of Color 2*/
	FloatID getColor2G(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2g",mName.c_str());return (const char*)buffer;}
	/*The blue component of Color 2*/
	FloatID getColor2B(){char buffer[4096];sprintf_s (buffer, "%s.c2.c2b",mName.c_str());return (const char*)buffer;}
	/*<b>Output</b> is the final blended color.*/
	Float3ID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*The X component of Output*/
	FloatID getOutputR(){char buffer[4096];sprintf_s (buffer, "%s.op.opr",mName.c_str());return (const char*)buffer;}
	/*The Y component of Output*/
	FloatID getOutputG(){char buffer[4096];sprintf_s (buffer, "%s.op.opg",mName.c_str());return (const char*)buffer;}
	/*The Z component of Output*/
	FloatID getOutputB(){char buffer[4096];sprintf_s (buffer, "%s.op.opb",mName.c_str());return (const char*)buffer;}
protected:
	BlendColors(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BLENDCOLORS_H__
