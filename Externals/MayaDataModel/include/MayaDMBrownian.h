/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BROWNIAN_H__
#define __MayaDM_BROWNIAN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTexture3d.h"
namespace MayaDM
{
/*
<b>Brownian</b> textures can be used to create rough, bumpy surfaces.
 Used as a bump map, it is good for creating effects such as thickly-painted
 metal.
<p/>This texture gets its name from "Brownian Motion", that is, the random motion
 of molecules in a liquid as they bump into one another.
<p/>
 Aside from the attributes listed here, Brownian textures inherit many
 other attributes from the parent class <a href="texture3d.html">Texture3d</a>.
<p/>
 In the table below, important attributes have their names shown in <b>bold</b>
 in the Description column.
*/
class Brownian : public Texture3d
{
public:
public:
	Brownian(FILE* file,const std::string& name,const std::string& parent=""):Texture3d(file, name, parent, "brownian"){}
	virtual ~Brownian(){}
	/*The pixel angle*/
	void setXPixelAngle(float xpa){if(xpa == 0.002053) return; fprintf_s(mFile, "setAttr \".xpa\" %f;\n", xpa);}
	/*The input normal*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of the input normal*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of the input normal*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of the input normal*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointObj(const Float3ID& rpo){fprintf_s(mFile,"connectAttr \"");rpo.write(mFile);fprintf_s(mFile,"\" \"%s.rpo\";\n",mName.c_str());}
	/*The x component of the current reference sample position*/
	void setRefPointObjX(const FloatID& rox){fprintf_s(mFile,"connectAttr \"");rox.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.rox\";\n",mName.c_str());}
	/*The y component of the current reference sample position*/
	void setRefPointObjY(const FloatID& roy){fprintf_s(mFile,"connectAttr \"");roy.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roy\";\n",mName.c_str());}
	/*The z component of the current reference sample position*/
	void setRefPointObjZ(const FloatID& roz){fprintf_s(mFile,"connectAttr \"");roz.write(mFile);fprintf_s(mFile,"\" \"%s.rpo.roz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*
	<b>Lacunarity</b> defines the gap between the various frequencies
	that are added together to form the Brownian texture.  Increase Lacunarity
	to increase the complexity and detail in the texture.  Decrease
	it to make the texture smoother with less detail.
	*/
	void setLacunarity(float l){if(l == 4.0) return; fprintf_s(mFile, "setAttr \".l\" %f;\n", l);}
	/*
	<b>Lacunarity</b> defines the gap between the various frequencies
	that are added together to form the Brownian texture.  Increase Lacunarity
	to increase the complexity and detail in the texture.  Decrease
	it to make the texture smoother with less detail.
	*/
	void setLacunarity(const FloatID& l){fprintf_s(mFile,"connectAttr \"");l.write(mFile);fprintf_s(mFile,"\" \"%s.l\";\n",mName.c_str());}
	/*
	<b>Increment</b> controls the ratio for the fractal noise in the
	texture.  Increase Increment to make the light and dark areas
	of the texture blend together more.  Decrease Increment to make
	the texture more contrasty.
	*/
	void setIncrement(float ic){if(ic == 0.1) return; fprintf_s(mFile, "setAttr \".ic\" %f;\n", ic);}
	/*
	<b>Increment</b> controls the ratio for the fractal noise in the
	texture.  Increase Increment to make the light and dark areas
	of the texture blend together more.  Decrease Increment to make
	the texture more contrasty.
	*/
	void setIncrement(const FloatID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*
	<b>Octaves</b> controls the number of calculation iterations this
	texture does.  Fractal textures, such as this one, work by running
	an algorithm iteratively.  The longer it runs, the more detail it
	it creates, but the slower it goes.  Increase Octaves to make the
	Brownian texture more detailed.  (This is good to do if it will
	be seen up close in the final rendered image).
	*/
	void setOctaves(float oct){if(oct == 3.0) return; fprintf_s(mFile, "setAttr \".oct\" %f;\n", oct);}
	/*
	<b>Octaves</b> controls the number of calculation iterations this
	texture does.  Fractal textures, such as this one, work by running
	an algorithm iteratively.  The longer it runs, the more detail it
	it creates, but the slower it goes.  Increase Octaves to make the
	Brownian texture more detailed.  (This is good to do if it will
	be seen up close in the final rendered image).
	*/
	void setOctaves(const FloatID& oct){fprintf_s(mFile,"connectAttr \"");oct.write(mFile);fprintf_s(mFile,"\" \"%s.oct\";\n",mName.c_str());}
	/*
	<b>Weight3d</b> can be used to make the texture wavy or smeared
	out.  Internally this controls the fundamental frequency of
	the fractal.
	*/
	void setWeight3d(const float3& w3){if(w3 == float3(1.0, 1.0, 1.0)) return; fprintf_s(mFile, "setAttr \".w3\" -type \"float3\" ");w3.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Weight3d</b> can be used to make the texture wavy or smeared
	out.  Internally this controls the fundamental frequency of
	the fractal.
	*/
	void setWeight3d(const Float3ID& w3){fprintf_s(mFile,"connectAttr \"");w3.write(mFile);fprintf_s(mFile,"\" \"%s.w3\";\n",mName.c_str());}
	/*The x component of Weight3d*/
	void setWeight3dX(float w3x){if(w3x == 0.0) return; fprintf_s(mFile, "setAttr \".w3.w3x\" %f;\n", w3x);}
	/*The x component of Weight3d*/
	void setWeight3dX(const FloatID& w3x){fprintf_s(mFile,"connectAttr \"");w3x.write(mFile);fprintf_s(mFile,"\" \"%s.w3.w3x\";\n",mName.c_str());}
	/*The y component of Weight3d*/
	void setWeight3dY(float w3y){if(w3y == 0.0) return; fprintf_s(mFile, "setAttr \".w3.w3y\" %f;\n", w3y);}
	/*The y component of Weight3d*/
	void setWeight3dY(const FloatID& w3y){fprintf_s(mFile,"connectAttr \"");w3y.write(mFile);fprintf_s(mFile,"\" \"%s.w3.w3y\";\n",mName.c_str());}
	/*The z component of Weight3d*/
	void setWeight3dZ(float w3z){if(w3z == 0.0) return; fprintf_s(mFile, "setAttr \".w3.w3z\" %f;\n", w3z);}
	/*The z component of Weight3d*/
	void setWeight3dZ(const FloatID& w3z){fprintf_s(mFile,"connectAttr \"");w3z.write(mFile);fprintf_s(mFile,"\" \"%s.w3.w3z\";\n",mName.c_str());}
	/*The input normal*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of the input normal*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of the input normal*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of the input normal*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointObj(){char buffer[4096];sprintf_s (buffer, "%s.rpo",mName.c_str());return (const char*)buffer;}
	/*The x component of the current reference sample position*/
	FloatID getRefPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.rpo.rox",mName.c_str());return (const char*)buffer;}
	/*The y component of the current reference sample position*/
	FloatID getRefPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current reference sample position*/
	FloatID getRefPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.rpo.roz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Lacunarity</b> defines the gap between the various frequencies
	that are added together to form the Brownian texture.  Increase Lacunarity
	to increase the complexity and detail in the texture.  Decrease
	it to make the texture smoother with less detail.
	*/
	FloatID getLacunarity(){char buffer[4096];sprintf_s (buffer, "%s.l",mName.c_str());return (const char*)buffer;}
	/*
	<b>Increment</b> controls the ratio for the fractal noise in the
	texture.  Increase Increment to make the light and dark areas
	of the texture blend together more.  Decrease Increment to make
	the texture more contrasty.
	*/
	FloatID getIncrement(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*
	<b>Octaves</b> controls the number of calculation iterations this
	texture does.  Fractal textures, such as this one, work by running
	an algorithm iteratively.  The longer it runs, the more detail it
	it creates, but the slower it goes.  Increase Octaves to make the
	Brownian texture more detailed.  (This is good to do if it will
	be seen up close in the final rendered image).
	*/
	FloatID getOctaves(){char buffer[4096];sprintf_s (buffer, "%s.oct",mName.c_str());return (const char*)buffer;}
	/*
	<b>Weight3d</b> can be used to make the texture wavy or smeared
	out.  Internally this controls the fundamental frequency of
	the fractal.
	*/
	Float3ID getWeight3d(){char buffer[4096];sprintf_s (buffer, "%s.w3",mName.c_str());return (const char*)buffer;}
	/*The x component of Weight3d*/
	FloatID getWeight3dX(){char buffer[4096];sprintf_s (buffer, "%s.w3.w3x",mName.c_str());return (const char*)buffer;}
	/*The y component of Weight3d*/
	FloatID getWeight3dY(){char buffer[4096];sprintf_s (buffer, "%s.w3.w3y",mName.c_str());return (const char*)buffer;}
	/*The z component of Weight3d*/
	FloatID getWeight3dZ(){char buffer[4096];sprintf_s (buffer, "%s.w3.w3z",mName.c_str());return (const char*)buffer;}
protected:
	Brownian(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Texture3d(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_BROWNIAN_H__
