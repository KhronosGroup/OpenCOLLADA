/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVSPHERE_H__
#define __MayaDM_ENVSPHERE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
/*
The <b>Env Sphere</b> texture simulates an environment by mapping a
 texture or image file directly onto the inner surface of an infinite
 sphere. The best way to create a sphere environment is to use a
 ramp texture and paint objects onto it, being sure to avoid the
 poles and edges.
<p/>
 You can use the Env Sphere texture as a reflection map, by connecting
 its Out Color attribute to the Reflected Color attribute of an specular
 shader, such as Blinn or PhongE.
<p/>
 Aside from the attributes listed here, Env Sphere inherits additional
 attributes from <a href="textureEnv.html">TextureEnv</a>.
 <p/>
 In the table below, important attributes have their names listed
 in <b>bold</b> in the description column.
*/
class EnvSphere : public TextureEnv
{
public:
public:
	EnvSphere(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envSphere"){}
	virtual ~EnvSphere(){}
	/*The current sample point that has to be shaded*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*The current reference sample point that has to be shaded*/
	void setRefPointCamera(const Float3ID& rpc){fprintf_s(mFile,"connectAttr \"");rpc.write(mFile);fprintf_s(mFile,"\" \"%s.rpc\";\n",mName.c_str());}
	/*The x component of the current sample position*/
	void setRefPointCameraX(const FloatID& rcx){fprintf_s(mFile,"connectAttr \"");rcx.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcx\";\n",mName.c_str());}
	/*The y component of the current sample position*/
	void setRefPointCameraY(const FloatID& rcy){fprintf_s(mFile,"connectAttr \"");rcy.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcy\";\n",mName.c_str());}
	/*The z component of the current sample position*/
	void setRefPointCameraZ(const FloatID& rcz){fprintf_s(mFile,"connectAttr \"");rcz.write(mFile);fprintf_s(mFile,"\" \"%s.rpc.rcz\";\n",mName.c_str());}
	/*
	<b>Image</b> is the texture or image that will be
	mapped to the inside of the sphere.
	*/
	void setImage(const float3& so){if(so == float3(0.5, 0.5, 0.5)) return; fprintf_s(mFile, "setAttr \".so\" -type \"float3\" ");so.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Image</b> is the texture or image that will be
	mapped to the inside of the sphere.
	*/
	void setImage(const Float3ID& so){fprintf_s(mFile,"connectAttr \"");so.write(mFile);fprintf_s(mFile,"\" \"%s.so\";\n",mName.c_str());}
	/*The red component of Image*/
	void setImageR(float sor){if(sor == 0.0) return; fprintf_s(mFile, "setAttr \".so.sor\" %f;\n", sor);}
	/*The red component of Image*/
	void setImageR(const FloatID& sor){fprintf_s(mFile,"connectAttr \"");sor.write(mFile);fprintf_s(mFile,"\" \"%s.so.sor\";\n",mName.c_str());}
	/*The green component of Image*/
	void setImageG(float sog){if(sog == 0.0) return; fprintf_s(mFile, "setAttr \".so.sog\" %f;\n", sog);}
	/*The green component of Image*/
	void setImageG(const FloatID& sog){fprintf_s(mFile,"connectAttr \"");sog.write(mFile);fprintf_s(mFile,"\" \"%s.so.sog\";\n",mName.c_str());}
	/*The blue component of Image*/
	void setImageB(float sob){if(sob == 0.0) return; fprintf_s(mFile, "setAttr \".so.sob\" %f;\n", sob);}
	/*The blue component of Image*/
	void setImageB(const FloatID& sob){fprintf_s(mFile,"connectAttr \"");sob.write(mFile);fprintf_s(mFile,"\" \"%s.so.sob\";\n",mName.c_str());}
	/*
	<b>Shear UV</b> allows you to shear the texture
	along the longitude or latitudes of the sphere.
	*/
	void setShearUV(const float2& suv){if(suv == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".suv\" -type \"float2\" ");suv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Shear UV</b> allows you to shear the texture
	along the longitude or latitudes of the sphere.
	*/
	void setShearUV(const Float2ID& suv){fprintf_s(mFile,"connectAttr \"");suv.write(mFile);fprintf_s(mFile,"\" \"%s.suv\";\n",mName.c_str());}
	/*
	<b>Shear U</b>. Adjusting this will shear longitudinal
	lines.  For example, straight vertical lines
	could be warped into a barber-pole arrangment.
	*/
	void setShearU(float su){if(su == 0.0) return; fprintf_s(mFile, "setAttr \".suv.su\" %f;\n", su);}
	/*
	<b>Shear U</b>. Adjusting this will shear longitudinal
	lines.  For example, straight vertical lines
	could be warped into a barber-pole arrangment.
	*/
	void setShearU(const FloatID& su){fprintf_s(mFile,"connectAttr \"");su.write(mFile);fprintf_s(mFile,"\" \"%s.suv.su\";\n",mName.c_str());}
	/*
	<b>Shear V</b>.  Adjusting this will shear latitudinal
	lines.  For example, lines that ran concentrically
	around the poles would spiral inwards.
	*/
	void setShearV(float sv){if(sv == 0.0) return; fprintf_s(mFile, "setAttr \".suv.sv\" %f;\n", sv);}
	/*
	<b>Shear V</b>.  Adjusting this will shear latitudinal
	lines.  For example, lines that ran concentrically
	around the poles would spiral inwards.
	*/
	void setShearV(const FloatID& sv){fprintf_s(mFile,"connectAttr \"");sv.write(mFile);fprintf_s(mFile,"\" \"%s.suv.sv\";\n",mName.c_str());}
	/*
	<b>Flip</b> allows you to flip your input texture
	so that U and V are switched;  the texture at the poles
	is moves to the equator and vice-versa.
	*/
	void setFlip(bool f){if(f == false) return; fprintf_s(mFile, "setAttr \".f\" %i;\n", f);}
	/*
	<b>Flip</b> allows you to flip your input texture
	so that U and V are switched;  the texture at the poles
	is moves to the equator and vice-versa.
	*/
	void setFlip(const BoolID& f){fprintf_s(mFile,"connectAttr \"");f.write(mFile);fprintf_s(mFile,"\" \"%s.f\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*The current sample point that has to be shaded*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*The current reference sample point that has to be shaded*/
	Float3ID getRefPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.rpc",mName.c_str());return (const char*)buffer;}
	/*The x component of the current sample position*/
	FloatID getRefPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcx",mName.c_str());return (const char*)buffer;}
	/*The y component of the current sample position*/
	FloatID getRefPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcy",mName.c_str());return (const char*)buffer;}
	/*The z component of the current sample position*/
	FloatID getRefPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.rpc.rcz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Image</b> is the texture or image that will be
	mapped to the inside of the sphere.
	*/
	Float3ID getImage(){char buffer[4096];sprintf_s (buffer, "%s.so",mName.c_str());return (const char*)buffer;}
	/*The red component of Image*/
	FloatID getImageR(){char buffer[4096];sprintf_s (buffer, "%s.so.sor",mName.c_str());return (const char*)buffer;}
	/*The green component of Image*/
	FloatID getImageG(){char buffer[4096];sprintf_s (buffer, "%s.so.sog",mName.c_str());return (const char*)buffer;}
	/*The blue component of Image*/
	FloatID getImageB(){char buffer[4096];sprintf_s (buffer, "%s.so.sob",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shear UV</b> allows you to shear the texture
	along the longitude or latitudes of the sphere.
	*/
	Float2ID getShearUV(){char buffer[4096];sprintf_s (buffer, "%s.suv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shear U</b>. Adjusting this will shear longitudinal
	lines.  For example, straight vertical lines
	could be warped into a barber-pole arrangment.
	*/
	FloatID getShearU(){char buffer[4096];sprintf_s (buffer, "%s.suv.su",mName.c_str());return (const char*)buffer;}
	/*
	<b>Shear V</b>.  Adjusting this will shear latitudinal
	lines.  For example, lines that ran concentrically
	around the poles would spiral inwards.
	*/
	FloatID getShearV(){char buffer[4096];sprintf_s (buffer, "%s.suv.sv",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flip</b> allows you to flip your input texture
	so that U and V are switched;  the texture at the poles
	is moves to the equator and vice-versa.
	*/
	BoolID getFlip(){char buffer[4096];sprintf_s (buffer, "%s.f",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
protected:
	EnvSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ENVSPHERE_H__
