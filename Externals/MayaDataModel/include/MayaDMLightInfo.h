/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LIGHTINFO_H__
#define __MayaDM_LIGHTINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Light Info</b> is a utility node that you can use to obtain
 information about the position of a light relative to a texture.
 As each point on the texture is being shaded, the attributes of
 the Light Info node can tell you the precise distance from the
 light to the point being shaded.  It also returns other
 information that can be useful when creating a shading network.
<p/>
 To make this work, you must connect the World Matrix attribute
 of the light to the World Matrix attribute of the Light Info node.
 Once that is done, the Light Info utility node is ready to use.
<p/>
 This node provides the following information:
<ul>
   <li>The position of the light in world space</li>
   <li>The direction the light is shining (if it is not a point light)</li>
   <li>The distance from the light to the point being shaded.</li>
</ul>
<p/>
 You can use this information as the input to other shading nodes,
 to produce interesting effects.  For example, you could
 connect the Sample Distance attribute to one of the color
 channels of a shader. That way, the color of the shader will change
 depending on how far it is from the light.
<p/>
 Note: You can actually attach the World Matrix of any object (not
 just a light) to this node, to get information about the object's position
 relative to the point being shaded.
<p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class LightInfo : public DependNode
{
public:
public:
	LightInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "lightInfo"){}
	virtual ~LightInfo(){}
	/*
	<b>Light Direction Only</b> controls how the Sample Distance
	attribute is calculated.
	<p/>If Light Direction Only is turned off, then the
	Sample Distance attribute returns the world-space distance from the
	light to the point being sampled.
	<p/>
	If Light Direction Only is turned on, then the Sample Distance
	attribute returns the distance
	along the light direction vector, to the closest point on that
	vector to the point being sampled.  In more mathematical terms,
	it returns the <i>length of the projection of the light-to-object vector onto the
	light-direction vector.</i>
	<p/>
	See the Rendering documentation for an explanatory diagram.
	<p/>
	*/
	void setLightDirectionOnly(bool ldo){if(ldo == false) return; fprintf_s(mFile, "setAttr \".ldo\" %i;\n", ldo);}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*
	<b>Light Position</b>.  This attribute gives the position
	of the connected light in world space.
	<p/>
	The "connected light" is the light (or other object) whose
	World Matrix attribute is connected to the World Matrix
	attribute of this node.
	*/
	void setLightPosition(const Float3ID& lp){fprintf_s(mFile,"connectAttr \"");lp.write(mFile);fprintf_s(mFile,"\" \"%s.lp\";\n",mName.c_str());}
	/*The X component of Light Position in world space*/
	void setLightPositionX(const FloatID& lpx){fprintf_s(mFile,"connectAttr \"");lpx.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpx\";\n",mName.c_str());}
	/*The Y component of Light Position in world space*/
	void setLightPositionY(const FloatID& lpy){fprintf_s(mFile,"connectAttr \"");lpy.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpy\";\n",mName.c_str());}
	/*The Z component of Light Position in world space*/
	void setLightPositionZ(const FloatID& lpz){fprintf_s(mFile,"connectAttr \"");lpz.write(mFile);fprintf_s(mFile,"\" \"%s.lp.lpz\";\n",mName.c_str());}
	/*
	<b>Light Direction</b>.  This attribute gives the direction
	in which the connected light is shining.
	<p/>
	Point lights, of course, shine in all directions.
	*/
	void setLightDirection(const Float3ID& ld){fprintf_s(mFile,"connectAttr \"");ld.write(mFile);fprintf_s(mFile,"\" \"%s.ld\";\n",mName.c_str());}
	/*The X component of the Light Direction in world space*/
	void setLightDirectionX(const FloatID& ldx){fprintf_s(mFile,"connectAttr \"");ldx.write(mFile);fprintf_s(mFile,"\" \"%s.ld.ldx\";\n",mName.c_str());}
	/*The Y component of the Light Direction in world space*/
	void setLightDirectionY(const FloatID& ldy){fprintf_s(mFile,"connectAttr \"");ldy.write(mFile);fprintf_s(mFile,"\" \"%s.ld.ldy\";\n",mName.c_str());}
	/*The Z component of the Light Direction in world space*/
	void setLightDirectionZ(const FloatID& ldz){fprintf_s(mFile,"connectAttr \"");ldz.write(mFile);fprintf_s(mFile,"\" \"%s.ld.ldz\";\n",mName.c_str());}
	/*
	<b>Sample Distance</b> is the world-space disatance between the
	connected light and the point on the surface being shaded.
	This can be caculated in different ways.  For details,
	see also the Light Direction Only attribute.
	*/
	void setSampleDistance(const FloatID& sd){fprintf_s(mFile,"connectAttr \"");sd.write(mFile);fprintf_s(mFile,"\" \"%s.sd\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Position</b>.  This attribute gives the position
	of the connected light in world space.
	<p/>
	The "connected light" is the light (or other object) whose
	World Matrix attribute is connected to the World Matrix
	attribute of this node.
	*/
	Float3ID getLightPosition(){char buffer[4096];sprintf_s (buffer, "%s.lp",mName.c_str());return (const char*)buffer;}
	/*The X component of Light Position in world space*/
	FloatID getLightPositionX(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Light Position in world space*/
	FloatID getLightPositionY(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Light Position in world space*/
	FloatID getLightPositionZ(){char buffer[4096];sprintf_s (buffer, "%s.lp.lpz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Light Direction</b>.  This attribute gives the direction
	in which the connected light is shining.
	<p/>
	Point lights, of course, shine in all directions.
	*/
	Float3ID getLightDirection(){char buffer[4096];sprintf_s (buffer, "%s.ld",mName.c_str());return (const char*)buffer;}
	/*The X component of the Light Direction in world space*/
	FloatID getLightDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.ld.ldx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the Light Direction in world space*/
	FloatID getLightDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.ld.ldy",mName.c_str());return (const char*)buffer;}
	/*The Z component of the Light Direction in world space*/
	FloatID getLightDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.ld.ldz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Sample Distance</b> is the world-space disatance between the
	connected light and the point on the surface being shaded.
	This can be caculated in different ways.  For details,
	see also the Light Direction Only attribute.
	*/
	FloatID getSampleDistance(){char buffer[4096];sprintf_s (buffer, "%s.sd",mName.c_str());return (const char*)buffer;}
protected:
	LightInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_LIGHTINFO_H__
