/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UVCHOOSER_H__
#define __MayaDM_UVCHOOSER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
uvChooser node to handle multiple uv sets <p/>

      The uvChooser has a multi attribute that gets connected to the shape
                connected to the parent shading group.  The virtual connection is
      the st attribute. This node does most of his work during analysis
      and will only copy the st attribute to his output uv attribute
      during evaluation. The uvChooser node will feed any existing
      shading node that accept a uv. <p/>
*/
class UvChooser : public DependNode
{
public:
public:
	UvChooser(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "uvChooser"){}
	virtual ~UvChooser(){}
	/*The uvSet to be use for the connected shape*/
	void setUvSets(size_t uvs_i,const string& uvs){if(uvs == "NULL") return; fprintf_s(mFile, "setAttr \".uvs[%i]\" -type \"string\" ",uvs_i);uvs.write(mFile);fprintf_s(mFile,";\n");}
	/*The uvSet to be use for the connected shape*/
	void setUvSets(size_t uvs_i,const StringID& uvs){fprintf_s(mFile,"connectAttr \"");uvs.write(mFile);fprintf_s(mFile,"\" \"%s.uvs[%i]\";\n",mName.c_str(),uvs_i);}
	/*The UV coords of the current sample point*/
	void setUvCoord(const Float2ID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setUCoord(const FloatID& u){fprintf_s(mFile,"connectAttr \"");u.write(mFile);fprintf_s(mFile,"\" \"%s.uv.u\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setVCoord(const FloatID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.uv.v\";\n",mName.c_str());}
	/*Triangle's first vertex, in texture space*/
	void setVertexUvOne(const float2& vt1){fprintf_s(mFile, "setAttr \".vt1\" -type \"float2\" ");vt1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle's first vertex, in texture space*/
	void setVertexUvOne(const Float2ID& vt1){fprintf_s(mFile,"connectAttr \"");vt1.write(mFile);fprintf_s(mFile,"\" \"%s.vt1\";\n",mName.c_str());}
	/*X component of aVertexUvOne*/
	void setVertexUvOneU(float t1u){if(t1u == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1u\" %f;\n", t1u);}
	/*X component of aVertexUvOne*/
	void setVertexUvOneU(const FloatID& t1u){fprintf_s(mFile,"connectAttr \"");t1u.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1u\";\n",mName.c_str());}
	/*Y component of aVertexUvOne*/
	void setVertexUvOneV(float t1v){if(t1v == 0.0) return; fprintf_s(mFile, "setAttr \".vt1.t1v\" %f;\n", t1v);}
	/*Y component of aVertexUvOne*/
	void setVertexUvOneV(const FloatID& t1v){fprintf_s(mFile,"connectAttr \"");t1v.write(mFile);fprintf_s(mFile,"\" \"%s.vt1.t1v\";\n",mName.c_str());}
	/*Triangle s second vertex, in texture space*/
	void setVertexUvTwo(const float2& vt2){fprintf_s(mFile, "setAttr \".vt2\" -type \"float2\" ");vt2.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s second vertex, in texture space*/
	void setVertexUvTwo(const Float2ID& vt2){fprintf_s(mFile,"connectAttr \"");vt2.write(mFile);fprintf_s(mFile,"\" \"%s.vt2\";\n",mName.c_str());}
	/*X component of aVertexUvTwo*/
	void setVertexUvTwoU(float t2u){if(t2u == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2u\" %f;\n", t2u);}
	/*X component of aVertexUvTwo*/
	void setVertexUvTwoU(const FloatID& t2u){fprintf_s(mFile,"connectAttr \"");t2u.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2u\";\n",mName.c_str());}
	/*Y component of aVertexUvTwo*/
	void setVertexUvTwoV(float t2v){if(t2v == 0.0) return; fprintf_s(mFile, "setAttr \".vt2.t2v\" %f;\n", t2v);}
	/*Y component of aVertexUvTwo*/
	void setVertexUvTwoV(const FloatID& t2v){fprintf_s(mFile,"connectAttr \"");t2v.write(mFile);fprintf_s(mFile,"\" \"%s.vt2.t2v\";\n",mName.c_str());}
	/*Triangle s third vertex, in texture space*/
	void setVertexUvThree(const float2& vt3){fprintf_s(mFile, "setAttr \".vt3\" -type \"float2\" ");vt3.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s third vertex, in texture space*/
	void setVertexUvThree(const Float2ID& vt3){fprintf_s(mFile,"connectAttr \"");vt3.write(mFile);fprintf_s(mFile,"\" \"%s.vt3\";\n",mName.c_str());}
	/*X component of aVertexUvThree*/
	void setVertexUvThreeU(float t3u){if(t3u == 0.0) return; fprintf_s(mFile, "setAttr \".vt3.t3u\" %f;\n", t3u);}
	/*X component of aVertexUvThree*/
	void setVertexUvThreeU(const FloatID& t3u){fprintf_s(mFile,"connectAttr \"");t3u.write(mFile);fprintf_s(mFile,"\" \"%s.vt3.t3u\";\n",mName.c_str());}
	/*Y component of aVertexUvThree*/
	void setVertexUvThreeV(float t3v){if(t3v == 0.0) return; fprintf_s(mFile, "setAttr \".vt3.t3v\" %f;\n", t3v);}
	/*Y component of aVertexUvThree*/
	void setVertexUvThreeV(const FloatID& t3v){fprintf_s(mFile,"connectAttr \"");t3v.write(mFile);fprintf_s(mFile,"\" \"%s.vt3.t3v\";\n",mName.c_str());}
	/*Triangle s first vertex, in camera space*/
	void setVertexCameraOne(const float3& vc1){fprintf_s(mFile, "setAttr \".vc1\" -type \"float3\" ");vc1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first vertex, in camera space*/
	void setVertexCameraOne(const Float3ID& vc1){fprintf_s(mFile,"connectAttr \"");vc1.write(mFile);fprintf_s(mFile,"\" \"%s.vc1\";\n",mName.c_str());}
	/*X component of aVertexCameraOne*/
	void setVertexCameraOneX(float c1x){if(c1x == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1x\" %f;\n", c1x);}
	/*X component of aVertexCameraOne*/
	void setVertexCameraOneX(const FloatID& c1x){fprintf_s(mFile,"connectAttr \"");c1x.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1x\";\n",mName.c_str());}
	/*Y component of aVertexCameraOne*/
	void setVertexCameraOneY(float c1y){if(c1y == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1y\" %f;\n", c1y);}
	/*Y component of aVertexCameraOne*/
	void setVertexCameraOneY(const FloatID& c1y){fprintf_s(mFile,"connectAttr \"");c1y.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1y\";\n",mName.c_str());}
	/*Z component of aVertexCameraOne*/
	void setVertexCameraOneZ(float c1z){if(c1z == 0.0) return; fprintf_s(mFile, "setAttr \".vc1.c1z\" %f;\n", c1z);}
	/*Z component of aVertexCameraOne*/
	void setVertexCameraOneZ(const FloatID& c1z){fprintf_s(mFile,"connectAttr \"");c1z.write(mFile);fprintf_s(mFile,"\" \"%s.vc1.c1z\";\n",mName.c_str());}
	/*Information bits passing along information about type of shading*/
	void setInfoBits(const IntID& ib){fprintf_s(mFile,"connectAttr \"");ib.write(mFile);fprintf_s(mFile,"\" \"%s.ib\";\n",mName.c_str());}
	/*The UV coords from the selected uv set of the current sample point*/
	void setOutUv(const Float2ID& ouv){fprintf_s(mFile,"connectAttr \"");ouv.write(mFile);fprintf_s(mFile,"\" \"%s.ouv\";\n",mName.c_str());}
	/*The u component of the current sample position*/
	void setOutU(const FloatID& ou){fprintf_s(mFile,"connectAttr \"");ou.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ou\";\n",mName.c_str());}
	/*The v component of the current sample position*/
	void setOutV(const FloatID& ov){fprintf_s(mFile,"connectAttr \"");ov.write(mFile);fprintf_s(mFile,"\" \"%s.ouv.ov\";\n",mName.c_str());}
	/*Triangle s first outVertex, in resulting texture space*/
	void setOutVertexUvOne(const float2& ov1){fprintf_s(mFile, "setAttr \".ov1\" -type \"float2\" ");ov1.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s first outVertex, in resulting texture space*/
	void setOutVertexUvOne(const Float2ID& ov1){fprintf_s(mFile,"connectAttr \"");ov1.write(mFile);fprintf_s(mFile,"\" \"%s.ov1\";\n",mName.c_str());}
	/*U component of aOutVertexUvOne*/
	void setOutVertexUvOneU(float o1u){if(o1u == 0.0) return; fprintf_s(mFile, "setAttr \".ov1.o1u\" %f;\n", o1u);}
	/*U component of aOutVertexUvOne*/
	void setOutVertexUvOneU(const FloatID& o1u){fprintf_s(mFile,"connectAttr \"");o1u.write(mFile);fprintf_s(mFile,"\" \"%s.ov1.o1u\";\n",mName.c_str());}
	/*V component of aOutVertexUvOne*/
	void setOutVertexUvOneV(float o1v){if(o1v == 0.0) return; fprintf_s(mFile, "setAttr \".ov1.o1v\" %f;\n", o1v);}
	/*V component of aOutVertexUvOne*/
	void setOutVertexUvOneV(const FloatID& o1v){fprintf_s(mFile,"connectAttr \"");o1v.write(mFile);fprintf_s(mFile,"\" \"%s.ov1.o1v\";\n",mName.c_str());}
	/*Triangle s second outVertex, in resulting texture space*/
	void setOutVertexUvTwo(const float2& ov2){fprintf_s(mFile, "setAttr \".ov2\" -type \"float2\" ");ov2.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s second outVertex, in resulting texture space*/
	void setOutVertexUvTwo(const Float2ID& ov2){fprintf_s(mFile,"connectAttr \"");ov2.write(mFile);fprintf_s(mFile,"\" \"%s.ov2\";\n",mName.c_str());}
	/*U component of aOutVertexUvTwo*/
	void setOutVertexUvTwoU(float o2u){if(o2u == 0.0) return; fprintf_s(mFile, "setAttr \".ov2.o2u\" %f;\n", o2u);}
	/*U component of aOutVertexUvTwo*/
	void setOutVertexUvTwoU(const FloatID& o2u){fprintf_s(mFile,"connectAttr \"");o2u.write(mFile);fprintf_s(mFile,"\" \"%s.ov2.o2u\";\n",mName.c_str());}
	/*V component of aOutVertexUvTwo*/
	void setOutVertexUvTwoV(float o2v){if(o2v == 0.0) return; fprintf_s(mFile, "setAttr \".ov2.o2v\" %f;\n", o2v);}
	/*V component of aOutVertexUvTwo*/
	void setOutVertexUvTwoV(const FloatID& o2v){fprintf_s(mFile,"connectAttr \"");o2v.write(mFile);fprintf_s(mFile,"\" \"%s.ov2.o2v\";\n",mName.c_str());}
	/*Triangle s third outVertex, in resulting texture space*/
	void setOutVertexUvThree(const float2& ov3){fprintf_s(mFile, "setAttr \".ov3\" -type \"float2\" ");ov3.write(mFile);fprintf_s(mFile,";\n");}
	/*Triangle s third outVertex, in resulting texture space*/
	void setOutVertexUvThree(const Float2ID& ov3){fprintf_s(mFile,"connectAttr \"");ov3.write(mFile);fprintf_s(mFile,"\" \"%s.ov3\";\n",mName.c_str());}
	/*U component of aOutVertexUvThree*/
	void setOutVertexUvThreeU(float o3u){if(o3u == 0.0) return; fprintf_s(mFile, "setAttr \".ov3.o3u\" %f;\n", o3u);}
	/*U component of aOutVertexUvThree*/
	void setOutVertexUvThreeU(const FloatID& o3u){fprintf_s(mFile,"connectAttr \"");o3u.write(mFile);fprintf_s(mFile,"\" \"%s.ov3.o3u\";\n",mName.c_str());}
	/*V component of aOutVertexUvThree*/
	void setOutVertexUvThreeV(float o3v){if(o3v == 0.0) return; fprintf_s(mFile, "setAttr \".ov3.o3v\" %f;\n", o3v);}
	/*V component of aOutVertexUvThree*/
	void setOutVertexUvThreeV(const FloatID& o3v){fprintf_s(mFile,"connectAttr \"");o3v.write(mFile);fprintf_s(mFile,"\" \"%s.ov3.o3v\";\n",mName.c_str());}
	/*
	For filtering of file textures with bump map, the x and y components
	of this field contains the chose space coordinates of original
	sample point.
	*/
	void setOutVertexCameraOne(const float3& oc1){fprintf_s(mFile, "setAttr \".oc1\" -type \"float3\" ");oc1.write(mFile);fprintf_s(mFile,";\n");}
	/*
	For filtering of file textures with bump map, the x and y components
	of this field contains the chose space coordinates of original
	sample point.
	*/
	void setOutVertexCameraOne(const Float3ID& oc1){fprintf_s(mFile,"connectAttr \"");oc1.write(mFile);fprintf_s(mFile,"\" \"%s.oc1\";\n",mName.c_str());}
	/*
	X component of aOutVertexCameraOne, but really s coordinate of
	original sample point.
	*/
	void setOutVertexCameraOneX(float o1x){if(o1x == 0.0) return; fprintf_s(mFile, "setAttr \".oc1.o1x\" %f;\n", o1x);}
	/*
	X component of aOutVertexCameraOne, but really s coordinate of
	original sample point.
	*/
	void setOutVertexCameraOneX(const FloatID& o1x){fprintf_s(mFile,"connectAttr \"");o1x.write(mFile);fprintf_s(mFile,"\" \"%s.oc1.o1x\";\n",mName.c_str());}
	/*
	Y component of aOutVertexCameraOne, but really t coordinate of
	original sample point.
	*/
	void setOutVertexCameraOneY(float o1y){if(o1y == 0.0) return; fprintf_s(mFile, "setAttr \".oc1.o1y\" %f;\n", o1y);}
	/*
	Y component of aOutVertexCameraOne, but really t coordinate of
	original sample point.
	*/
	void setOutVertexCameraOneY(const FloatID& o1y){fprintf_s(mFile,"connectAttr \"");o1y.write(mFile);fprintf_s(mFile,"\" \"%s.oc1.o1y\";\n",mName.c_str());}
	/*Z component of aOutVertexCameraOne, but really unused.*/
	void setOutVertexCameraOneZ(float o1z){if(o1z == 0.0) return; fprintf_s(mFile, "setAttr \".oc1.o1z\" %f;\n", o1z);}
	/*Z component of aOutVertexCameraOne, but really unused.*/
	void setOutVertexCameraOneZ(const FloatID& o1z){fprintf_s(mFile,"connectAttr \"");o1z.write(mFile);fprintf_s(mFile,"\" \"%s.oc1.o1z\";\n",mName.c_str());}
	/*The uvSet to be use for the connected shape*/
	const StringID& getUvSets(size_t uvs_i){char buffer[4096];sprintf_s (buffer, "%s.uvs[%i]",mName.c_str(),uvs_i);return (const char*)buffer;}
	/*The UV coords of the current sample point*/
	Float2ID getUvCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getUCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.u",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getVCoord(){char buffer[4096];sprintf_s (buffer, "%s.uv.v",mName.c_str());return (const char*)buffer;}
	/*Triangle's first vertex, in texture space*/
	Float2ID getVertexUvOne(){char buffer[4096];sprintf_s (buffer, "%s.vt1",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvOne*/
	FloatID getVertexUvOneU(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvOne*/
	FloatID getVertexUvOneV(){char buffer[4096];sprintf_s (buffer, "%s.vt1.t1v",mName.c_str());return (const char*)buffer;}
	/*Triangle s second vertex, in texture space*/
	Float2ID getVertexUvTwo(){char buffer[4096];sprintf_s (buffer, "%s.vt2",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvTwo*/
	FloatID getVertexUvTwoU(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvTwo*/
	FloatID getVertexUvTwoV(){char buffer[4096];sprintf_s (buffer, "%s.vt2.t2v",mName.c_str());return (const char*)buffer;}
	/*Triangle s third vertex, in texture space*/
	Float2ID getVertexUvThree(){char buffer[4096];sprintf_s (buffer, "%s.vt3",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexUvThree*/
	FloatID getVertexUvThreeU(){char buffer[4096];sprintf_s (buffer, "%s.vt3.t3u",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexUvThree*/
	FloatID getVertexUvThreeV(){char buffer[4096];sprintf_s (buffer, "%s.vt3.t3v",mName.c_str());return (const char*)buffer;}
	/*Triangle s first vertex, in camera space*/
	Float3ID getVertexCameraOne(){char buffer[4096];sprintf_s (buffer, "%s.vc1",mName.c_str());return (const char*)buffer;}
	/*X component of aVertexCameraOne*/
	FloatID getVertexCameraOneX(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1x",mName.c_str());return (const char*)buffer;}
	/*Y component of aVertexCameraOne*/
	FloatID getVertexCameraOneY(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1y",mName.c_str());return (const char*)buffer;}
	/*Z component of aVertexCameraOne*/
	FloatID getVertexCameraOneZ(){char buffer[4096];sprintf_s (buffer, "%s.vc1.c1z",mName.c_str());return (const char*)buffer;}
	/*Information bits passing along information about type of shading*/
	IntID getInfoBits(){char buffer[4096];sprintf_s (buffer, "%s.ib",mName.c_str());return (const char*)buffer;}
	/*The UV coords from the selected uv set of the current sample point*/
	Float2ID getOutUv(){char buffer[4096];sprintf_s (buffer, "%s.ouv",mName.c_str());return (const char*)buffer;}
	/*The u component of the current sample position*/
	FloatID getOutU(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ou",mName.c_str());return (const char*)buffer;}
	/*The v component of the current sample position*/
	FloatID getOutV(){char buffer[4096];sprintf_s (buffer, "%s.ouv.ov",mName.c_str());return (const char*)buffer;}
	/*Triangle s first outVertex, in resulting texture space*/
	Float2ID getOutVertexUvOne(){char buffer[4096];sprintf_s (buffer, "%s.ov1",mName.c_str());return (const char*)buffer;}
	/*U component of aOutVertexUvOne*/
	FloatID getOutVertexUvOneU(){char buffer[4096];sprintf_s (buffer, "%s.ov1.o1u",mName.c_str());return (const char*)buffer;}
	/*V component of aOutVertexUvOne*/
	FloatID getOutVertexUvOneV(){char buffer[4096];sprintf_s (buffer, "%s.ov1.o1v",mName.c_str());return (const char*)buffer;}
	/*Triangle s second outVertex, in resulting texture space*/
	Float2ID getOutVertexUvTwo(){char buffer[4096];sprintf_s (buffer, "%s.ov2",mName.c_str());return (const char*)buffer;}
	/*U component of aOutVertexUvTwo*/
	FloatID getOutVertexUvTwoU(){char buffer[4096];sprintf_s (buffer, "%s.ov2.o2u",mName.c_str());return (const char*)buffer;}
	/*V component of aOutVertexUvTwo*/
	FloatID getOutVertexUvTwoV(){char buffer[4096];sprintf_s (buffer, "%s.ov2.o2v",mName.c_str());return (const char*)buffer;}
	/*Triangle s third outVertex, in resulting texture space*/
	Float2ID getOutVertexUvThree(){char buffer[4096];sprintf_s (buffer, "%s.ov3",mName.c_str());return (const char*)buffer;}
	/*U component of aOutVertexUvThree*/
	FloatID getOutVertexUvThreeU(){char buffer[4096];sprintf_s (buffer, "%s.ov3.o3u",mName.c_str());return (const char*)buffer;}
	/*V component of aOutVertexUvThree*/
	FloatID getOutVertexUvThreeV(){char buffer[4096];sprintf_s (buffer, "%s.ov3.o3v",mName.c_str());return (const char*)buffer;}
	/*
	For filtering of file textures with bump map, the x and y components
	of this field contains the chose space coordinates of original
	sample point.
	*/
	Float3ID getOutVertexCameraOne(){char buffer[4096];sprintf_s (buffer, "%s.oc1",mName.c_str());return (const char*)buffer;}
	/*
	X component of aOutVertexCameraOne, but really s coordinate of
	original sample point.
	*/
	FloatID getOutVertexCameraOneX(){char buffer[4096];sprintf_s (buffer, "%s.oc1.o1x",mName.c_str());return (const char*)buffer;}
	/*
	Y component of aOutVertexCameraOne, but really t coordinate of
	original sample point.
	*/
	FloatID getOutVertexCameraOneY(){char buffer[4096];sprintf_s (buffer, "%s.oc1.o1y",mName.c_str());return (const char*)buffer;}
	/*Z component of aOutVertexCameraOne, but really unused.*/
	FloatID getOutVertexCameraOneZ(){char buffer[4096];sprintf_s (buffer, "%s.oc1.o1z",mName.c_str());return (const char*)buffer;}
protected:
	UvChooser(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UVCHOOSER_H__
