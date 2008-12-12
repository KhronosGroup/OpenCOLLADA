/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMEAR_H__
#define __MayaDM_SMEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Smear</b> is a utility node that allows you to
  convert an RGB color into a UV coordinate offset.
  <p/>
  This allows you to "smear" UV coordinates using a texture
  to define how the coordinates are remapped.  To better
  understand how this works, the color is converted internally
  to the HSV "color wheel" representation, and the angle on
  the wheel and distance from its center are treated as polar
  coordinates in the UV space, which are then converted to
  rectangular coordinates and ouput as the resulting UV offset.
  <p/>
  In the table below, important attributes have their names
  listed in <b>bold</b> in the description column.
*/
class Smear : public DependNode
{
public:
public:
	Smear(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "smear"){}
	virtual ~Smear(){}
	/*
	<b>Input Color</b> is the RGB value which determines how
	far and in what direction to offset in UV.
	*/
	void setInRgb(const float3& i){if(i == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".i\" -type \"float3\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Input Color</b> is the RGB value which determines how
	far and in what direction to offset in UV.
	*/
	void setInRgb(const Float3ID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*The red component of Input Color.*/
	void setInColorR(float ir){if(ir == 0.0) return; fprintf_s(mFile, "setAttr \".i.ir\" %f;\n", ir);}
	/*The red component of Input Color.*/
	void setInColorR(const FloatID& ir){fprintf_s(mFile,"connectAttr \"");ir.write(mFile);fprintf_s(mFile,"\" \"%s.i.ir\";\n",mName.c_str());}
	/*The green component of Input Color.*/
	void setInColorG(float ig){if(ig == 0.0) return; fprintf_s(mFile, "setAttr \".i.ig\" %f;\n", ig);}
	/*The green component of Input Color.*/
	void setInColorG(const FloatID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.i.ig\";\n",mName.c_str());}
	/*The blue component of Input Color.*/
	void setInColorB(float ib){if(ib == 0.0) return; fprintf_s(mFile, "setAttr \".i.ib\" %f;\n", ib);}
	/*The blue component of Input Color.*/
	void setInColorB(const FloatID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.i.ib\";\n",mName.c_str());}
	/*
	<b>Out UV</b>:  This attribute should be connected
	to the UV Coord attribute of the 2d texture being placed.
	*/
	void setOutUV(const Float2ID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The U component of OutUV*/
	void setOutU(const FloatID& ou){fprintf_s(mFile,"connectAttr \"");ou.write(mFile);fprintf_s(mFile,"\" \"%s.o.ou\";\n",mName.c_str());}
	/*The V component of OutUV*/
	void setOutV(const FloatID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.o.ov\";\n",mName.c_str());}
	/*
	<b>Input Color</b> is the RGB value which determines how
	far and in what direction to offset in UV.
	*/
	Float3ID getInRgb(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*The red component of Input Color.*/
	FloatID getInColorR(){char buffer[4096];sprintf_s (buffer, "%s.i.ir",mName.c_str());return (const char*)buffer;}
	/*The green component of Input Color.*/
	FloatID getInColorG(){char buffer[4096];sprintf_s (buffer, "%s.i.ig",mName.c_str());return (const char*)buffer;}
	/*The blue component of Input Color.*/
	FloatID getInColorB(){char buffer[4096];sprintf_s (buffer, "%s.i.ib",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out UV</b>:  This attribute should be connected
	to the UV Coord attribute of the 2d texture being placed.
	*/
	Float2ID getOutUV(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
	/*The U component of OutUV*/
	FloatID getOutU(){char buffer[4096];sprintf_s (buffer, "%s.o.ou",mName.c_str());return (const char*)buffer;}
	/*The V component of OutUV*/
	FloatID getOutV(){char buffer[4096];sprintf_s (buffer, "%s.o.ov",mName.c_str());return (const char*)buffer;}
protected:
	Smear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SMEAR_H__
