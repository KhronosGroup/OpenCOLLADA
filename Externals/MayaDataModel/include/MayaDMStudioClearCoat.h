/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_STUDIOCLEARCOAT_H__
#define __MayaDM_STUDIOCLEARCOAT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>ClearCoat</b> is a utility node that allows you to
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
class StudioClearCoat : public DependNode
{
public:
public:
	StudioClearCoat(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "studioClearCoat"){}
	virtual ~StudioClearCoat(){}
	/*Describes the refraction properties of the material*/
	void setIndex(float ix){if(ix == 1.8) return; fprintf_s(mFile, "setAttr \".ix\" %f;\n", ix);}
	/*Describes the refraction properties of the material*/
	void setIndex(const FloatID& ix){fprintf_s(mFile,"connectAttr \"");ix.write(mFile);fprintf_s(mFile,"\" \"%s.ix\";\n",mName.c_str());}
	/*A simple multiplier on the final result*/
	void setScale(float s){if(s == 1.55) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*A simple multiplier on the final result*/
	void setScale(const FloatID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*
	Controls the middle point of the contrast adjustment and is added
	to the final result. Increase Bias to move the middle point upwards
	(more of the texture becomes dark as contrast increases). Decrease
	Bias to move the middle point down (more of the texture becomes
	light as contrast increases).
	<p/>
	The computation is:<br/>
	<tt>final result= f(index of refraction) * scale + bias</tt><br/>
	Where f(index of refraction) is the studioClearCoat computation
	with the index of refraction as input.
	*/
	void setBias(float b){if(b == -0.1) return; fprintf_s(mFile, "setAttr \".b\" %f;\n", b);}
	/*
	Controls the middle point of the contrast adjustment and is added
	to the final result. Increase Bias to move the middle point upwards
	(more of the texture becomes dark as contrast increases). Decrease
	Bias to move the middle point down (more of the texture becomes
	light as contrast increases).
	<p/>
	The computation is:<br/>
	<tt>final result= f(index of refraction) * scale + bias</tt><br/>
	Where f(index of refraction) is the studioClearCoat computation
	with the index of refraction as input.
	*/
	void setBias(const FloatID& b){fprintf_s(mFile,"connectAttr \"");b.write(mFile);fprintf_s(mFile,"\" \"%s.b\";\n",mName.c_str());}
	/*The current sample normal*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The x component of the normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The y component of the normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The z component of the normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The current incident ray*/
	void setRayDirection(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The x component of the ray*/
	void setRayDirectionX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*The y component of the ray*/
	void setRayDirectionY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*The z component of the ray*/
	void setRayDirectionZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*The output value*/
	void setOutValue(const FloatID& outp){fprintf_s(mFile,"connectAttr \"");outp.write(mFile);fprintf_s(mFile,"\" \"%s.outp\";\n",mName.c_str());}
	/*Describes the refraction properties of the material*/
	FloatID getIndex(){char buffer[4096];sprintf_s (buffer, "%s.ix",mName.c_str());return (const char*)buffer;}
	/*A simple multiplier on the final result*/
	FloatID getScale(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*
	Controls the middle point of the contrast adjustment and is added
	to the final result. Increase Bias to move the middle point upwards
	(more of the texture becomes dark as contrast increases). Decrease
	Bias to move the middle point down (more of the texture becomes
	light as contrast increases).
	<p/>
	The computation is:<br/>
	<tt>final result= f(index of refraction) * scale + bias</tt><br/>
	Where f(index of refraction) is the studioClearCoat computation
	with the index of refraction as input.
	*/
	FloatID getBias(){char buffer[4096];sprintf_s (buffer, "%s.b",mName.c_str());return (const char*)buffer;}
	/*The current sample normal*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The x component of the normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The y component of the normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The z component of the normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The current incident ray*/
	Float3ID getRayDirection(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The x component of the ray*/
	FloatID getRayDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The y component of the ray*/
	FloatID getRayDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The z component of the ray*/
	FloatID getRayDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*The output value*/
	FloatID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.outp",mName.c_str());return (const char*)buffer;}
protected:
	StudioClearCoat(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_STUDIOCLEARCOAT_H__
