/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_REFLECT_H__
#define __MayaDM_REFLECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMLambert.h"
namespace MayaDM
{
/*
The <b>Reflect</b> node has attributes that control how light is reflected
  from a surface.  Reflect nodes never exist by themselves;  they are part
  of the makeup of other shading nodes, such as Blinn or PhongE.
  <p/>
  Aside from the attributes described here, the Reflect node inherits
  many attributes from its parent <a href="lambert.html">Lambert</a> node.
  <p/>
  In the table below, important attribute have their names indicated
  in <b>bold</b> in the description column.
*/
class Reflect : public Lambert
{
public:
public:
	Reflect(FILE* file,const std::string& name,const std::string& parent=""):Lambert(file, name, parent, "reflect"){}
	virtual ~Reflect(){}
	/*reflected ray depth limit*/
	void setReflectionLimit(short fll){if(fll == 1) return; fprintf_s(mFile, "setAttr \".fll\" %i;\n", fll);}
	/*reflected ray depth limit*/
	void setReflectionLimit(const ShortID& fll){fprintf_s(mFile,"connectAttr \"");fll.write(mFile);fprintf_s(mFile,"\" \"%s.fll\";\n",mName.c_str());}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	void setSpecularColor(const float3& sc){fprintf_s(mFile, "setAttr \".sc\" -type \"float3\" ");sc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	void setSpecularColor(const Float3ID& sc){fprintf_s(mFile,"connectAttr \"");sc.write(mFile);fprintf_s(mFile,"\" \"%s.sc\";\n",mName.c_str());}
	/*specular color red value*/
	void setSpecularColorR(float sr){if(sr == 0.5) return; fprintf_s(mFile, "setAttr \".sc.sr\" %f;\n", sr);}
	/*specular color red value*/
	void setSpecularColorR(const FloatID& sr){fprintf_s(mFile,"connectAttr \"");sr.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sr\";\n",mName.c_str());}
	/*specular color green value*/
	void setSpecularColorG(float sg){if(sg == 0.5) return; fprintf_s(mFile, "setAttr \".sc.sg\" %f;\n", sg);}
	/*specular color green value*/
	void setSpecularColorG(const FloatID& sg){fprintf_s(mFile,"connectAttr \"");sg.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sg\";\n",mName.c_str());}
	/*specular color blue value*/
	void setSpecularColorB(float sb){if(sb == 0.5) return; fprintf_s(mFile, "setAttr \".sc.sb\" %f;\n", sb);}
	/*specular color blue value*/
	void setSpecularColorB(const FloatID& sb){fprintf_s(mFile,"connectAttr \"");sb.write(mFile);fprintf_s(mFile,"\" \"%s.sc.sb\";\n",mName.c_str());}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you do not want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	void setReflectivity(float rfl){if(rfl == 0.5) return; fprintf_s(mFile, "setAttr \".rfl\" %f;\n", rfl);}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you do not want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	void setReflectivity(const FloatID& rfl){fprintf_s(mFile,"connectAttr \"");rfl.write(mFile);fprintf_s(mFile,"\" \"%s.rfl\";\n",mName.c_str());}
	/*
	<b>Reflected Color</b> affects the color of light reflected from
	the material.
	<p/>You can map an image or texture  or environment map to this
	attribute in order to make 'fake reflections', which are less
	expensive than ray-tracing.  This is called Reflection Mapping.
	<p/>Reflection Mapping and raytracing may be used together, in
	which case the reflection map is used as 'background', and
	raytraced reflections appear in the 'foreground'.
	*/
	void setReflectedColor(const float3& rc){fprintf_s(mFile, "setAttr \".rc\" -type \"float3\" ");rc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Reflected Color</b> affects the color of light reflected from
	the material.
	<p/>You can map an image or texture  or environment map to this
	attribute in order to make 'fake reflections', which are less
	expensive than ray-tracing.  This is called Reflection Mapping.
	<p/>Reflection Mapping and raytracing may be used together, in
	which case the reflection map is used as 'background', and
	raytraced reflections appear in the 'foreground'.
	*/
	void setReflectedColor(const Float3ID& rc){fprintf_s(mFile,"connectAttr \"");rc.write(mFile);fprintf_s(mFile,"\" \"%s.rc\";\n",mName.c_str());}
	/*reflected color red value*/
	void setReflectedColorR(float rr){if(rr == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rr\" %f;\n", rr);}
	/*reflected color red value*/
	void setReflectedColorR(const FloatID& rr){fprintf_s(mFile,"connectAttr \"");rr.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rr\";\n",mName.c_str());}
	/*reflected color green value*/
	void setReflectedColorG(float rg){if(rg == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rg\" %f;\n", rg);}
	/*reflected color green value*/
	void setReflectedColorG(const FloatID& rg){fprintf_s(mFile,"connectAttr \"");rg.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rg\";\n",mName.c_str());}
	/*reflected color blue value*/
	void setReflectedColorB(float rb){if(rb == 0.0) return; fprintf_s(mFile, "setAttr \".rc.rb\" %f;\n", rb);}
	/*reflected color blue value*/
	void setReflectedColorB(const FloatID& rb){fprintf_s(mFile,"connectAttr \"");rb.write(mFile);fprintf_s(mFile,"\" \"%s.rc.rb\";\n",mName.c_str());}
	/*
	<b>Triangle Normal In Camera Space</b> This is the normal
	of the visible triangle in the camera space.
	<p/>This normal is used to check the reflection direction is not
	in the opposite direction of the normal of the visible triangle.
	*/
	void setTriangleNormalCamera(const Float3ID& tnc){fprintf_s(mFile,"connectAttr \"");tnc.write(mFile);fprintf_s(mFile,"\" \"%s.tnc\";\n",mName.c_str());}
	/*triangle normal x value*/
	void setTriangleNormalCameraX(const FloatID& tnx){fprintf_s(mFile,"connectAttr \"");tnx.write(mFile);fprintf_s(mFile,"\" \"%s.tnc.tnx\";\n",mName.c_str());}
	/*triangle normal y value*/
	void setTriangleNormalCameraY(const FloatID& tny){fprintf_s(mFile,"connectAttr \"");tny.write(mFile);fprintf_s(mFile,"\" \"%s.tnc.tny\";\n",mName.c_str());}
	/*triangle normal z value*/
	void setTriangleNormalCameraZ(const FloatID& tnz){fprintf_s(mFile,"connectAttr \"");tnz.write(mFile);fprintf_s(mFile,"\" \"%s.tnc.tnz\";\n",mName.c_str());}
	/*
	<b>Reflection Specular </b> controls the contribution of the
	specular component when dealing with reflection rays for ray
	tracing.  I.e., the specular contribution when seen as a
	mirror reflection.
	*/
	void setReflectionSpecularity(float rsp){if(rsp == 1.0) return; fprintf_s(mFile, "setAttr \".rsp\" %f;\n", rsp);}
	/*
	<b>Reflection Specular </b> controls the contribution of the
	specular component when dealing with reflection rays for ray
	tracing.  I.e., the specular contribution when seen as a
	mirror reflection.
	*/
	void setReflectionSpecularity(const FloatID& rsp){fprintf_s(mFile,"connectAttr \"");rsp.write(mFile);fprintf_s(mFile,"\" \"%s.rsp\";\n",mName.c_str());}
	/*reflected ray depth limit*/
	ShortID getReflectionLimit(){char buffer[4096];sprintf_s (buffer, "%s.fll",mName.c_str());return (const char*)buffer;}
	/*
	<b>Specular Color</b> is the color of the specular reflections
	(also called 'hot spots') on the material.  The final color
	of a specular reflection is a combination of the Specular Color
	and the color of the light.
	<p/>By making the Specular Color brighter or dimmer, you can control
	the brightness of the specular reflections on an object.
	<p/>
	<i>Tip:</i> To make a material look more plastic, use white for the specular
	color.  To make a material look more metallic, make the specular
	color similar to the surface color.
	*/
	Float3ID getSpecularColor(){char buffer[4096];sprintf_s (buffer, "%s.sc",mName.c_str());return (const char*)buffer;}
	/*specular color red value*/
	FloatID getSpecularColorR(){char buffer[4096];sprintf_s (buffer, "%s.sc.sr",mName.c_str());return (const char*)buffer;}
	/*specular color green value*/
	FloatID getSpecularColorG(){char buffer[4096];sprintf_s (buffer, "%s.sc.sg",mName.c_str());return (const char*)buffer;}
	/*specular color blue value*/
	FloatID getSpecularColorB(){char buffer[4096];sprintf_s (buffer, "%s.sc.sb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflectivity</b> is used to make an object reflect light
	like a mirror.  Set this to 0 is you do not want your material
	to reflect at all.  Increase the value to make brighter
	reflections.  Note that brighter reflections hide more of the
	base surface color.
	<p/>
	This attribute is only meaningful if there is a reflection map, or
	if you are doing Ray Tracing.
	<p/>
	Here are some useful values for Reflectivity:
	<ul>
	Car Paint: 0.4<br/>
	Glass: 0.7<br/>
	Mirror: 1.0<br/>
	Chrome: 1.0
	</ul>
	<p/>
	<i>Note:</i> If you are doing Ray Tracing, and you want
	other objects in the scene to be seen in reflections, then
	you must turn on the Visible In Reflections attribute of
	those objects.
	*/
	FloatID getReflectivity(){char buffer[4096];sprintf_s (buffer, "%s.rfl",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflected Color</b> affects the color of light reflected from
	the material.
	<p/>You can map an image or texture  or environment map to this
	attribute in order to make 'fake reflections', which are less
	expensive than ray-tracing.  This is called Reflection Mapping.
	<p/>Reflection Mapping and raytracing may be used together, in
	which case the reflection map is used as 'background', and
	raytraced reflections appear in the 'foreground'.
	*/
	Float3ID getReflectedColor(){char buffer[4096];sprintf_s (buffer, "%s.rc",mName.c_str());return (const char*)buffer;}
	/*reflected color red value*/
	FloatID getReflectedColorR(){char buffer[4096];sprintf_s (buffer, "%s.rc.rr",mName.c_str());return (const char*)buffer;}
	/*reflected color green value*/
	FloatID getReflectedColorG(){char buffer[4096];sprintf_s (buffer, "%s.rc.rg",mName.c_str());return (const char*)buffer;}
	/*reflected color blue value*/
	FloatID getReflectedColorB(){char buffer[4096];sprintf_s (buffer, "%s.rc.rb",mName.c_str());return (const char*)buffer;}
	/*
	<b>Triangle Normal In Camera Space</b> This is the normal
	of the visible triangle in the camera space.
	<p/>This normal is used to check the reflection direction is not
	in the opposite direction of the normal of the visible triangle.
	*/
	Float3ID getTriangleNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.tnc",mName.c_str());return (const char*)buffer;}
	/*triangle normal x value*/
	FloatID getTriangleNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.tnc.tnx",mName.c_str());return (const char*)buffer;}
	/*triangle normal y value*/
	FloatID getTriangleNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.tnc.tny",mName.c_str());return (const char*)buffer;}
	/*triangle normal z value*/
	FloatID getTriangleNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.tnc.tnz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Reflection Specular </b> controls the contribution of the
	specular component when dealing with reflection rays for ray
	tracing.  I.e., the specular contribution when seen as a
	mirror reflection.
	*/
	FloatID getReflectionSpecularity(){char buffer[4096];sprintf_s (buffer, "%s.rsp",mName.c_str());return (const char*)buffer;}
protected:
	Reflect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Lambert(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_REFLECT_H__
