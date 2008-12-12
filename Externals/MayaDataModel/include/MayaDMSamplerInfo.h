/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SAMPLERINFO_H__
#define __MayaDM_SAMPLERINFO_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>Sampler Info</b> is a utility node you can use to get all
 kinds of information useful for building shader networks.
 The job of Sampler Info is to give you information about the
 each point on a surface as it is being "sampled", that is,
 calculated for rendering purposes.
 <p/>
 Sampler Info can give you information about a point's position
 in space, its orientation and tangency, and its location relative to
 the camera.
<p/>
 Many of the attributes for this node provide values in "camera
 coordinate space".  This is the local object space of the camera.
 Each camera (in its own space) is located at the point 0, 0, 0.
 It is looking straight along the negative Z axis, and
 the positive Y axis is pointing up.
<p/>
 In the table below, important attributes have their names
 listed in <b>bold</b> in the description column.
*/
class SamplerInfo : public DependNode
{
public:
public:
	SamplerInfo(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "samplerInfo"){}
	virtual ~SamplerInfo(){}
	/*
	<b>Point Camera</b> gives you the position of the point
	being sampled, in camera coordinate space.
	*/
	void setPointCamera(const float3& p){if(p == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".p\" -type \"float3\" ");p.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Point Camera</b> gives you the position of the point
	being sampled, in camera coordinate space.
	*/
	void setPointCamera(const Float3ID& p){fprintf_s(mFile,"connectAttr \"");p.write(mFile);fprintf_s(mFile,"\" \"%s.p\";\n",mName.c_str());}
	/*The X component of Point Camera*/
	void setPointCameraX(float px){if(px == 0.0) return; fprintf_s(mFile, "setAttr \".p.px\" %f;\n", px);}
	/*The X component of Point Camera*/
	void setPointCameraX(const FloatID& px){fprintf_s(mFile,"connectAttr \"");px.write(mFile);fprintf_s(mFile,"\" \"%s.p.px\";\n",mName.c_str());}
	/*The Y component of Point Camera*/
	void setPointCameraY(float py){if(py == 0.0) return; fprintf_s(mFile, "setAttr \".p.py\" %f;\n", py);}
	/*The Y component of Point Camera*/
	void setPointCameraY(const FloatID& py){fprintf_s(mFile,"connectAttr \"");py.write(mFile);fprintf_s(mFile,"\" \"%s.p.py\";\n",mName.c_str());}
	/*The Z component of Point Camera*/
	void setPointCameraZ(float pz){if(pz == 0.0) return; fprintf_s(mFile, "setAttr \".p.pz\" %f;\n", pz);}
	/*The Z component of Point Camera*/
	void setPointCameraZ(const FloatID& pz){fprintf_s(mFile,"connectAttr \"");pz.write(mFile);fprintf_s(mFile,"\" \"%s.p.pz\";\n",mName.c_str());}
	/*
	<b>Point Obj</b> gives you the position of the point
	being sampled, in the object's local coordinate space.
	*/
	void setPointObj(const float3& po){if(po == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".po\" -type \"float3\" ");po.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Point Obj</b> gives you the position of the point
	being sampled, in the object's local coordinate space.
	*/
	void setPointObj(const Float3ID& po){fprintf_s(mFile,"connectAttr \"");po.write(mFile);fprintf_s(mFile,"\" \"%s.po\";\n",mName.c_str());}
	/*The X component of Point Obj*/
	void setPointObjX(float pox){if(pox == 0.0) return; fprintf_s(mFile, "setAttr \".po.pox\" %f;\n", pox);}
	/*The X component of Point Obj*/
	void setPointObjX(const FloatID& pox){fprintf_s(mFile,"connectAttr \"");pox.write(mFile);fprintf_s(mFile,"\" \"%s.po.pox\";\n",mName.c_str());}
	/*The Y component of Point Obj*/
	void setPointObjY(float poy){if(poy == 0.0) return; fprintf_s(mFile, "setAttr \".po.poy\" %f;\n", poy);}
	/*The Y component of Point Obj*/
	void setPointObjY(const FloatID& poy){fprintf_s(mFile,"connectAttr \"");poy.write(mFile);fprintf_s(mFile,"\" \"%s.po.poy\";\n",mName.c_str());}
	/*The Z component of Point Obj*/
	void setPointObjZ(float poz){if(poz == 0.0) return; fprintf_s(mFile, "setAttr \".po.poz\" %f;\n", poz);}
	/*The Z component of Point Obj*/
	void setPointObjZ(const FloatID& poz){fprintf_s(mFile,"connectAttr \"");poz.write(mFile);fprintf_s(mFile,"\" \"%s.po.poz\";\n",mName.c_str());}
	/*
	<b>Point World</b> gives you the position of the point
	being sampled, in world coordinate space.
	*/
	void setPointWorld(const float3& pw){if(pw == float3(0.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pw\" -type \"float3\" ");pw.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Point World</b> gives you the position of the point
	being sampled, in world coordinate space.
	*/
	void setPointWorld(const Float3ID& pw){fprintf_s(mFile,"connectAttr \"");pw.write(mFile);fprintf_s(mFile,"\" \"%s.pw\";\n",mName.c_str());}
	/*The X component of Point World*/
	void setPointWorldX(float pwx){if(pwx == 0.0) return; fprintf_s(mFile, "setAttr \".pw.pwx\" %f;\n", pwx);}
	/*The X component of Point World*/
	void setPointWorldX(const FloatID& pwx){fprintf_s(mFile,"connectAttr \"");pwx.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwx\";\n",mName.c_str());}
	/*The Y component of Point World*/
	void setPointWorldY(float pwy){if(pwy == 0.0) return; fprintf_s(mFile, "setAttr \".pw.pwy\" %f;\n", pwy);}
	/*The Y component of Point World*/
	void setPointWorldY(const FloatID& pwy){fprintf_s(mFile,"connectAttr \"");pwy.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwy\";\n",mName.c_str());}
	/*The Z component of Point World*/
	void setPointWorldZ(float pwz){if(pwz == 0.0) return; fprintf_s(mFile, "setAttr \".pw.pwz\" %f;\n", pwz);}
	/*The Z component of Point World*/
	void setPointWorldZ(const FloatID& pwz){fprintf_s(mFile,"connectAttr \"");pwz.write(mFile);fprintf_s(mFile,"\" \"%s.pw.pwz\";\n",mName.c_str());}
	/*
	<b>Normal Camera</b> gives you the surface normal at
	the point being sampled, in camera coordinate space.
	<p/>
	The "surface normal" is a vector that points directly
	away from the surface (at right angles to it) at that point.
	*/
	void setNormalCamera(const float3& n){if(n == float3(0.0, 0.0, 1.0)) return; fprintf_s(mFile, "setAttr \".n\" -type \"float3\" ");n.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Normal Camera</b> gives you the surface normal at
	the point being sampled, in camera coordinate space.
	<p/>
	The "surface normal" is a vector that points directly
	away from the surface (at right angles to it) at that point.
	*/
	void setNormalCamera(const Float3ID& n){fprintf_s(mFile,"connectAttr \"");n.write(mFile);fprintf_s(mFile,"\" \"%s.n\";\n",mName.c_str());}
	/*The X component of Normal Camera*/
	void setNormalCameraX(float nx){if(nx == 0.0) return; fprintf_s(mFile, "setAttr \".n.nx\" %f;\n", nx);}
	/*The X component of Normal Camera*/
	void setNormalCameraX(const FloatID& nx){fprintf_s(mFile,"connectAttr \"");nx.write(mFile);fprintf_s(mFile,"\" \"%s.n.nx\";\n",mName.c_str());}
	/*The Y component of Normal Camera*/
	void setNormalCameraY(float ny){if(ny == 0.0) return; fprintf_s(mFile, "setAttr \".n.ny\" %f;\n", ny);}
	/*The Y component of Normal Camera*/
	void setNormalCameraY(const FloatID& ny){fprintf_s(mFile,"connectAttr \"");ny.write(mFile);fprintf_s(mFile,"\" \"%s.n.ny\";\n",mName.c_str());}
	/*The Z component of Normal Camera*/
	void setNormalCameraZ(float nz){if(nz == 0.0) return; fprintf_s(mFile, "setAttr \".n.nz\" %f;\n", nz);}
	/*The Z component of Normal Camera*/
	void setNormalCameraZ(const FloatID& nz){fprintf_s(mFile,"connectAttr \"");nz.write(mFile);fprintf_s(mFile,"\" \"%s.n.nz\";\n",mName.c_str());}
	/*
	<b>U V Coord</b> gives you the U and V surface coordinates
	of the point being sampled.
	*/
	void setUvCoord(const float2& uv){if(uv == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".uv\" -type \"float2\" ");uv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>U V Coord</b> gives you the U and V surface coordinates
	of the point being sampled.
	*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of U V Coord*/
	void setUCoord(float u){if(u == 0.0) return; fprintf_s(mFile, "setAttr \".uv.u\" %f;\n", u);}
	/*The u component of U V Coord*/
	void setUCoord(const FloatID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.uv.u\";\n",mName.c_str());}
	/*The v component of U V Coord*/
	void setVCoord(float v){if(v == 0.0) return; fprintf_s(mFile, "setAttr \".uv.v\" %f;\n", v);}
	/*The v component of U V Coord*/
	void setVCoord(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.uv.v\";\n",mName.c_str());}
	/*
	<b>Ray Direction</b> gives you a vector that points
	from the point being sampled to the camera position,
	in camera coordinate space.
	*/
	void setRayDirection(const float3& r){if(r == float3(0.0, 0.0, 1.0)) return; fprintf_s(mFile, "setAttr \".r\" -type \"float3\" ");r.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Ray Direction</b> gives you a vector that points
	from the point being sampled to the camera position,
	in camera coordinate space.
	*/
	void setRayDirection(const Float3ID& r){fprintf_s(mFile,"connectAttr \"");r.write(mFile);fprintf_s(mFile,"\" \"%s.r\";\n",mName.c_str());}
	/*The x component of Ray Direction*/
	void setRayDirectionX(float rx){if(rx == 0.0) return; fprintf_s(mFile, "setAttr \".r.rx\" %f;\n", rx);}
	/*The x component of Ray Direction*/
	void setRayDirectionX(const FloatID& rx){fprintf_s(mFile,"connectAttr \"");rx.write(mFile);fprintf_s(mFile,"\" \"%s.r.rx\";\n",mName.c_str());}
	/*The y component of Ray Direction*/
	void setRayDirectionY(float ry){if(ry == 0.0) return; fprintf_s(mFile, "setAttr \".r.ry\" %f;\n", ry);}
	/*The y component of Ray Direction*/
	void setRayDirectionY(const FloatID& ry){fprintf_s(mFile,"connectAttr \"");ry.write(mFile);fprintf_s(mFile,"\" \"%s.r.ry\";\n",mName.c_str());}
	/*The z component of Ray Direction*/
	void setRayDirectionZ(float rz){if(rz == 0.0) return; fprintf_s(mFile, "setAttr \".r.rz\" %f;\n", rz);}
	/*The z component of Ray Direction*/
	void setRayDirectionZ(const FloatID& rz){fprintf_s(mFile,"connectAttr \"");rz.write(mFile);fprintf_s(mFile,"\" \"%s.r.rz\";\n",mName.c_str());}
	/*
	<b>Tangent U Camera</b> is the surface tangent in the U
	direction at the point being sampled, in camera
	coordinate space.
	<p/>
	Tangents are not well-defined for polygon objects.
	*/
	void setTangentUCamera(const float3& tu){if(tu == float3(1.0, 0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tu\" -type \"float3\" ");tu.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Tangent U Camera</b> is the surface tangent in the U
	direction at the point being sampled, in camera
	coordinate space.
	<p/>
	Tangents are not well-defined for polygon objects.
	*/
	void setTangentUCamera(const Float3ID& tu){fprintf_s(mFile,"connectAttr \"");tu.write(mFile);fprintf_s(mFile,"\" \"%s.tu\";\n",mName.c_str());}
	/*The X component of Tangent U Camera*/
	void setTangentUx(float tux){if(tux == 0.0) return; fprintf_s(mFile, "setAttr \".tu.tux\" %f;\n", tux);}
	/*The X component of Tangent U Camera*/
	void setTangentUx(const FloatID& tux){fprintf_s(mFile,"connectAttr \"");tux.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tux\";\n",mName.c_str());}
	/*The Y component of Tangent U Camera*/
	void setTangentUy(float tuy){if(tuy == 0.0) return; fprintf_s(mFile, "setAttr \".tu.tuy\" %f;\n", tuy);}
	/*The Y component of Tangent U Camera*/
	void setTangentUy(const FloatID& tuy){fprintf_s(mFile,"connectAttr \"");tuy.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tuy\";\n",mName.c_str());}
	/*The Z component of Tangent U Camera*/
	void setTangentUz(float tuz){if(tuz == 0.0) return; fprintf_s(mFile, "setAttr \".tu.tuz\" %f;\n", tuz);}
	/*The Z component of Tangent U Camera*/
	void setTangentUz(const FloatID& tuz){fprintf_s(mFile,"connectAttr \"");tuz.write(mFile);fprintf_s(mFile,"\" \"%s.tu.tuz\";\n",mName.c_str());}
	/*
	<b>Tangent V Camera</b> is the surface tangent in the V
	direction at the point being sampled, in camera
	coordinate space.
	<p/>
	Tangents are not well-defined for polygon objects.
	*/
	void setTangentVCamera(const float3& tv){if(tv == float3(0.0, 1.0, 0.0)) return; fprintf_s(mFile, "setAttr \".tv\" -type \"float3\" ");tv.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Tangent V Camera</b> is the surface tangent in the V
	direction at the point being sampled, in camera
	coordinate space.
	<p/>
	Tangents are not well-defined for polygon objects.
	*/
	void setTangentVCamera(const Float3ID& tv){fprintf_s(mFile,"connectAttr \"");tv.write(mFile);fprintf_s(mFile,"\" \"%s.tv\";\n",mName.c_str());}
	/*The X component of Tangent V Camera*/
	void setTangentVx(float tvx){if(tvx == 0.0) return; fprintf_s(mFile, "setAttr \".tv.tvx\" %f;\n", tvx);}
	/*The X component of Tangent V Camera*/
	void setTangentVx(const FloatID& tvx){fprintf_s(mFile,"connectAttr \"");tvx.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvx\";\n",mName.c_str());}
	/*The Y component of Tangent V Camera*/
	void setTangentVy(float tvy){if(tvy == 0.0) return; fprintf_s(mFile, "setAttr \".tv.tvy\" %f;\n", tvy);}
	/*The Y component of Tangent V Camera*/
	void setTangentVy(const FloatID& tvy){fprintf_s(mFile,"connectAttr \"");tvy.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvy\";\n",mName.c_str());}
	/*The Z component of Tangent V Camera*/
	void setTangentVz(float tvz){if(tvz == 0.0) return; fprintf_s(mFile, "setAttr \".tv.tvz\" %f;\n", tvz);}
	/*The Z component of Tangent V Camera*/
	void setTangentVz(const FloatID& tvz){fprintf_s(mFile,"connectAttr \"");tvz.write(mFile);fprintf_s(mFile,"\" \"%s.tv.tvz\";\n",mName.c_str());}
	/*The transform to go from eye to world space*/
	void setMatrixEyeToWorld(const FltMatrixID& e2w){fprintf_s(mFile,"connectAttr \"");e2w.write(mFile);fprintf_s(mFile,"\" \"%s.e2w\";\n",mName.c_str());}
	/*
	<b>Pixel Center</b> gives you the location of the pixel
	in the final image that corresponds to the point being
	sampled.
	<p/>
	For example, let's say you are rendering an image at a
	resolution of 200 x 200.  Then 0, 0 is the position of the
	lower-left corner of the image, and 200, 200 is the position
	of the upper-right corner.  If we are sampling a point in
	the middle of the image, its Pixel Centre value would
	be approximately 100, 100.
	*/
	void setPixelCenter(const float2& pc){if(pc == float2(0.0, 0.0)) return; fprintf_s(mFile, "setAttr \".pc\" -type \"float2\" ");pc.write(mFile);fprintf_s(mFile,";\n");}
	/*
	<b>Pixel Center</b> gives you the location of the pixel
	in the final image that corresponds to the point being
	sampled.
	<p/>
	For example, let's say you are rendering an image at a
	resolution of 200 x 200.  Then 0, 0 is the position of the
	lower-left corner of the image, and 200, 200 is the position
	of the upper-right corner.  If we are sampling a point in
	the middle of the image, its Pixel Centre value would
	be approximately 100, 100.
	*/
	void setPixelCenter(const Float2ID& pc){fprintf_s(mFile,"connectAttr \"");pc.write(mFile);fprintf_s(mFile,"\" \"%s.pc\";\n",mName.c_str());}
	/*The X component of Pixel Center*/
	void setPixelCenterX(float pcx){if(pcx == 0.0) return; fprintf_s(mFile, "setAttr \".pc.pcx\" %f;\n", pcx);}
	/*The X component of Pixel Center*/
	void setPixelCenterX(const FloatID& pcx){fprintf_s(mFile,"connectAttr \"");pcx.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcx\";\n",mName.c_str());}
	/*The Y component of Pixel Center*/
	void setPixelCenterY(float pcy){if(pcy == 0.0) return; fprintf_s(mFile, "setAttr \".pc.pcy\" %f;\n", pcy);}
	/*The Y component of Pixel Center*/
	void setPixelCenterY(const FloatID& pcy){fprintf_s(mFile,"connectAttr \"");pcy.write(mFile);fprintf_s(mFile,"\" \"%s.pc.pcy\";\n",mName.c_str());}
	/*
	<b>Flipped Normal</b> tells you which side of a surface
	is being sampled.  Most shaders treat both sides of a
	surface the same, but you may want to have them different.
	<p/>
	For example, if you were creating an image of money,
	you would want single flat surfaces with one image on
	one side, and a different image on the other side.
	*/
	void setFlippedNormal(bool fn){if(fn == false) return; fprintf_s(mFile, "setAttr \".fn\" %i;\n", fn);}
	/*
	<b>Flipped Normal</b> tells you which side of a surface
	is being sampled.  Most shaders treat both sides of a
	surface the same, but you may want to have them different.
	<p/>
	For example, if you were creating an image of money,
	you would want single flat surfaces with one image on
	one side, and a different image on the other side.
	*/
	void setFlippedNormal(const BoolID& fn){fprintf_s(mFile,"connectAttr \"");fn.write(mFile);fprintf_s(mFile,"\" \"%s.fn\";\n",mName.c_str());}
	/*
	<b>Facing Ratio</b> gives you a number between 0 and
	1 that tells you if the point being sampled is facing
	towards or away from the camera.  A value of 1 means that
	it is facing the camera head-on.  A value of 0 means that
	is is facing 90 degrees from the camera.
	<p/>
	In mathematical terms, Facing Ratio is the cosine of the
	angle between Ray Direction and Normal Camera.
	*/
	void setFacingRatio(float fr){if(fr == 0.0) return; fprintf_s(mFile, "setAttr \".fr\" %f;\n", fr);}
	/*
	<b>Facing Ratio</b> gives you a number between 0 and
	1 that tells you if the point being sampled is facing
	towards or away from the camera.  A value of 1 means that
	it is facing the camera head-on.  A value of 0 means that
	is is facing 90 degrees from the camera.
	<p/>
	In mathematical terms, Facing Ratio is the cosine of the
	angle between Ray Direction and Normal Camera.
	*/
	void setFacingRatio(const FloatID& fr){fprintf_s(mFile,"connectAttr \"");fr.write(mFile);fprintf_s(mFile,"\" \"%s.fr\";\n",mName.c_str());}
	/*
	<b>Point Camera</b> gives you the position of the point
	being sampled, in camera coordinate space.
	*/
	Float3ID getPointCamera(){char buffer[4096];sprintf_s (buffer, "%s.p",mName.c_str());return (const char*)buffer;}
	/*The X component of Point Camera*/
	FloatID getPointCameraX(){char buffer[4096];sprintf_s (buffer, "%s.p.px",mName.c_str());return (const char*)buffer;}
	/*The Y component of Point Camera*/
	FloatID getPointCameraY(){char buffer[4096];sprintf_s (buffer, "%s.p.py",mName.c_str());return (const char*)buffer;}
	/*The Z component of Point Camera*/
	FloatID getPointCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.p.pz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Point Obj</b> gives you the position of the point
	being sampled, in the object's local coordinate space.
	*/
	Float3ID getPointObj(){char buffer[4096];sprintf_s (buffer, "%s.po",mName.c_str());return (const char*)buffer;}
	/*The X component of Point Obj*/
	FloatID getPointObjX(){char buffer[4096];sprintf_s (buffer, "%s.po.pox",mName.c_str());return (const char*)buffer;}
	/*The Y component of Point Obj*/
	FloatID getPointObjY(){char buffer[4096];sprintf_s (buffer, "%s.po.poy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Point Obj*/
	FloatID getPointObjZ(){char buffer[4096];sprintf_s (buffer, "%s.po.poz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Point World</b> gives you the position of the point
	being sampled, in world coordinate space.
	*/
	Float3ID getPointWorld(){char buffer[4096];sprintf_s (buffer, "%s.pw",mName.c_str());return (const char*)buffer;}
	/*The X component of Point World*/
	FloatID getPointWorldX(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Point World*/
	FloatID getPointWorldY(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Point World*/
	FloatID getPointWorldZ(){char buffer[4096];sprintf_s (buffer, "%s.pw.pwz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Normal Camera</b> gives you the surface normal at
	the point being sampled, in camera coordinate space.
	<p/>
	The "surface normal" is a vector that points directly
	away from the surface (at right angles to it) at that point.
	*/
	Float3ID getNormalCamera(){char buffer[4096];sprintf_s (buffer, "%s.n",mName.c_str());return (const char*)buffer;}
	/*The X component of Normal Camera*/
	FloatID getNormalCameraX(){char buffer[4096];sprintf_s (buffer, "%s.n.nx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Normal Camera*/
	FloatID getNormalCameraY(){char buffer[4096];sprintf_s (buffer, "%s.n.ny",mName.c_str());return (const char*)buffer;}
	/*The Z component of Normal Camera*/
	FloatID getNormalCameraZ(){char buffer[4096];sprintf_s (buffer, "%s.n.nz",mName.c_str());return (const char*)buffer;}
	/*
	<b>U V Coord</b> gives you the U and V surface coordinates
	of the point being sampled.
	*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of U V Coord*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.u",mName.c_str());return (const char*)buffer;}
	/*The v component of U V Coord*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.v",mName.c_str());return (const char*)buffer;}
	/*
	<b>Ray Direction</b> gives you a vector that points
	from the point being sampled to the camera position,
	in camera coordinate space.
	*/
	Float3ID getRayDirection(){char buffer[4096];sprintf_s (buffer, "%s.r",mName.c_str());return (const char*)buffer;}
	/*The x component of Ray Direction*/
	FloatID getRayDirectionX(){char buffer[4096];sprintf_s (buffer, "%s.r.rx",mName.c_str());return (const char*)buffer;}
	/*The y component of Ray Direction*/
	FloatID getRayDirectionY(){char buffer[4096];sprintf_s (buffer, "%s.r.ry",mName.c_str());return (const char*)buffer;}
	/*The z component of Ray Direction*/
	FloatID getRayDirectionZ(){char buffer[4096];sprintf_s (buffer, "%s.r.rz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Tangent U Camera</b> is the surface tangent in the U
	direction at the point being sampled, in camera
	coordinate space.
	<p/>
	Tangents are not well-defined for polygon objects.
	*/
	Float3ID getTangentUCamera(){char buffer[4096];sprintf_s (buffer, "%s.tu",mName.c_str());return (const char*)buffer;}
	/*The X component of Tangent U Camera*/
	FloatID getTangentUx(){char buffer[4096];sprintf_s (buffer, "%s.tu.tux",mName.c_str());return (const char*)buffer;}
	/*The Y component of Tangent U Camera*/
	FloatID getTangentUy(){char buffer[4096];sprintf_s (buffer, "%s.tu.tuy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Tangent U Camera*/
	FloatID getTangentUz(){char buffer[4096];sprintf_s (buffer, "%s.tu.tuz",mName.c_str());return (const char*)buffer;}
	/*
	<b>Tangent V Camera</b> is the surface tangent in the V
	direction at the point being sampled, in camera
	coordinate space.
	<p/>
	Tangents are not well-defined for polygon objects.
	*/
	Float3ID getTangentVCamera(){char buffer[4096];sprintf_s (buffer, "%s.tv",mName.c_str());return (const char*)buffer;}
	/*The X component of Tangent V Camera*/
	FloatID getTangentVx(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Tangent V Camera*/
	FloatID getTangentVy(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvy",mName.c_str());return (const char*)buffer;}
	/*The Z component of Tangent V Camera*/
	FloatID getTangentVz(){char buffer[4096];sprintf_s (buffer, "%s.tv.tvz",mName.c_str());return (const char*)buffer;}
	/*The transform to go from eye to world space*/
	FltMatrixID getMatrixEyeToWorld(){char buffer[4096];sprintf_s (buffer, "%s.e2w",mName.c_str());return (const char*)buffer;}
	/*
	<b>Pixel Center</b> gives you the location of the pixel
	in the final image that corresponds to the point being
	sampled.
	<p/>
	For example, let's say you are rendering an image at a
	resolution of 200 x 200.  Then 0, 0 is the position of the
	lower-left corner of the image, and 200, 200 is the position
	of the upper-right corner.  If we are sampling a point in
	the middle of the image, its Pixel Centre value would
	be approximately 100, 100.
	*/
	Float2ID getPixelCenter(){char buffer[4096];sprintf_s (buffer, "%s.pc",mName.c_str());return (const char*)buffer;}
	/*The X component of Pixel Center*/
	FloatID getPixelCenterX(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcx",mName.c_str());return (const char*)buffer;}
	/*The Y component of Pixel Center*/
	FloatID getPixelCenterY(){char buffer[4096];sprintf_s (buffer, "%s.pc.pcy",mName.c_str());return (const char*)buffer;}
	/*
	<b>Flipped Normal</b> tells you which side of a surface
	is being sampled.  Most shaders treat both sides of a
	surface the same, but you may want to have them different.
	<p/>
	For example, if you were creating an image of money,
	you would want single flat surfaces with one image on
	one side, and a different image on the other side.
	*/
	BoolID getFlippedNormal(){char buffer[4096];sprintf_s (buffer, "%s.fn",mName.c_str());return (const char*)buffer;}
	/*
	<b>Facing Ratio</b> gives you a number between 0 and
	1 that tells you if the point being sampled is facing
	towards or away from the camera.  A value of 1 means that
	it is facing the camera head-on.  A value of 0 means that
	is is facing 90 degrees from the camera.
	<p/>
	In mathematical terms, Facing Ratio is the cosine of the
	angle between Ray Direction and Normal Camera.
	*/
	FloatID getFacingRatio(){char buffer[4096];sprintf_s (buffer, "%s.fr",mName.c_str());return (const char*)buffer;}
protected:
	SamplerInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SAMPLERINFO_H__
