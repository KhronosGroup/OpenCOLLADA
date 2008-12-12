/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SURFACELUMINANCE_H__
#define __MayaDM_SURFACELUMINANCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Surface Luminance</b> is a utility node that tells you
 the luminance (brightness) of a point on a surface as it is
 being rendered.  This luminance takes into account all the light
 sources shining on the object, and the angle at which they shine
 on the object.  It does not take into account the specular properties
 of the object itself, such as 'hotspots'.
 <p/>
 You can use this node to make interesting shaders that change
 based on the light in the environment.
 <p/>
 <b>Example:</b>  Say you are modelling a windscreen of a car, made of
 a special glass that
 becomes darker (more opaque) in bright light.  To do this,
 create a Surface Luminance node, and connect its output to all three
 input channels of a Reverse node.  Then connect the output of the
 Reverse node to the Transparency attribute of a shader.
 <p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class SurfaceLuminance : public DependNode
{
public:
public:
	SurfaceLuminance(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "surfaceLuminance"){}
	virtual ~SurfaceLuminance(){}
	/*The input normal*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*
	<b>Out Value</b> is the surface luminance of the surface
	being rendered.
	*/
	void setOutValue(const FloatID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*The input normal*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Out Value</b> is the surface luminance of the surface
	being rendered.
	*/
	FloatID getOutValue(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	SurfaceLuminance(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SURFACELUMINANCE_H__
