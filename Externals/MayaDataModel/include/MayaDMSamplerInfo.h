/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class SamplerInfo : public DependNode
{
public:
public:

	SamplerInfo():DependNode(){}
	SamplerInfo(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "samplerInfo", shared, create){}
	virtual ~SamplerInfo(){}

	void setPointCamera(const float3& p)
	{
		if(p == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".p\" -type \"float3\" ");
		p.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointCameraX(float px)
	{
		if(px == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.px\" %f;\n", px);
	}
	void setPointCameraY(float py)
	{
		if(py == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.py\" %f;\n", py);
	}
	void setPointCameraZ(float pz)
	{
		if(pz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".p.pz\" %f;\n", pz);
	}
	void setPointObj(const float3& po)
	{
		if(po == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".po\" -type \"float3\" ");
		po.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointObjX(float pox)
	{
		if(pox == 0.0) return;
		fprintf(mFile,"\tsetAttr \".po.pox\" %f;\n", pox);
	}
	void setPointObjY(float poy)
	{
		if(poy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".po.poy\" %f;\n", poy);
	}
	void setPointObjZ(float poz)
	{
		if(poz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".po.poz\" %f;\n", poz);
	}
	void setPointWorld(const float3& pw)
	{
		if(pw == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".pw\" -type \"float3\" ");
		pw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPointWorldX(float pwx)
	{
		if(pwx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pw.pwx\" %f;\n", pwx);
	}
	void setPointWorldY(float pwy)
	{
		if(pwy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pw.pwy\" %f;\n", pwy);
	}
	void setPointWorldZ(float pwz)
	{
		if(pwz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pw.pwz\" %f;\n", pwz);
	}
	void setNormalCamera(const float3& n)
	{
		if(n == float3(0.0f,0.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".n\" -type \"float3\" ");
		n.write(mFile);
		fprintf(mFile,";\n");
	}
	void setNormalCameraX(float nx)
	{
		if(nx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.nx\" %f;\n", nx);
	}
	void setNormalCameraY(float ny)
	{
		if(ny == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.ny\" %f;\n", ny);
	}
	void setNormalCameraZ(float nz)
	{
		if(nz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".n.nz\" %f;\n", nz);
	}
	void setUvCoord(const float2& uv)
	{
		if(uv == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".uv\" -type \"float2\" ");
		uv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUCoord(float u)
	{
		if(u == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uv.u\" %f;\n", u);
	}
	void setVCoord(float v)
	{
		if(v == 0.0) return;
		fprintf(mFile,"\tsetAttr \".uv.v\" %f;\n", v);
	}
	void setRayDirection(const float3& r)
	{
		if(r == float3(0.0f,0.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".r\" -type \"float3\" ");
		r.write(mFile);
		fprintf(mFile,";\n");
	}
	void setRayDirectionX(float rx)
	{
		if(rx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.rx\" %f;\n", rx);
	}
	void setRayDirectionY(float ry)
	{
		if(ry == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.ry\" %f;\n", ry);
	}
	void setRayDirectionZ(float rz)
	{
		if(rz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".r.rz\" %f;\n", rz);
	}
	void setTangentUCamera(const float3& tu)
	{
		if(tu == float3(1.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".tu\" -type \"float3\" ");
		tu.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTangentUx(float tux)
	{
		if(tux == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tu.tux\" %f;\n", tux);
	}
	void setTangentUy(float tuy)
	{
		if(tuy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tu.tuy\" %f;\n", tuy);
	}
	void setTangentUz(float tuz)
	{
		if(tuz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tu.tuz\" %f;\n", tuz);
	}
	void setTangentVCamera(const float3& tv)
	{
		if(tv == float3(0.0f,1.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".tv\" -type \"float3\" ");
		tv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setTangentVx(float tvx)
	{
		if(tvx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tv.tvx\" %f;\n", tvx);
	}
	void setTangentVy(float tvy)
	{
		if(tvy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tv.tvy\" %f;\n", tvy);
	}
	void setTangentVz(float tvz)
	{
		if(tvz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".tv.tvz\" %f;\n", tvz);
	}
	void setPixelCenter(const float2& pc)
	{
		if(pc == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".pc\" -type \"float2\" ");
		pc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPixelCenterX(float pcx)
	{
		if(pcx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pc.pcx\" %f;\n", pcx);
	}
	void setPixelCenterY(float pcy)
	{
		if(pcy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".pc.pcy\" %f;\n", pcy);
	}
	void setFlippedNormal(bool fn)
	{
		if(fn == false) return;
		fprintf(mFile,"\tsetAttr \".fn\" %i;\n", fn);
	}
	void setFacingRatio(float fr)
	{
		if(fr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void getPointCamera()const
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getPointCameraX()const
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());
	}
	void getPointCameraY()const
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());
	}
	void getPointCameraZ()const
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());
	}
	void getPointObj()const
	{
		fprintf(mFile,"\"%s.po\"",mName.c_str());
	}
	void getPointObjX()const
	{
		fprintf(mFile,"\"%s.po.pox\"",mName.c_str());
	}
	void getPointObjY()const
	{
		fprintf(mFile,"\"%s.po.poy\"",mName.c_str());
	}
	void getPointObjZ()const
	{
		fprintf(mFile,"\"%s.po.poz\"",mName.c_str());
	}
	void getPointWorld()const
	{
		fprintf(mFile,"\"%s.pw\"",mName.c_str());
	}
	void getPointWorldX()const
	{
		fprintf(mFile,"\"%s.pw.pwx\"",mName.c_str());
	}
	void getPointWorldY()const
	{
		fprintf(mFile,"\"%s.pw.pwy\"",mName.c_str());
	}
	void getPointWorldZ()const
	{
		fprintf(mFile,"\"%s.pw.pwz\"",mName.c_str());
	}
	void getNormalCamera()const
	{
		fprintf(mFile,"\"%s.n\"",mName.c_str());
	}
	void getNormalCameraX()const
	{
		fprintf(mFile,"\"%s.n.nx\"",mName.c_str());
	}
	void getNormalCameraY()const
	{
		fprintf(mFile,"\"%s.n.ny\"",mName.c_str());
	}
	void getNormalCameraZ()const
	{
		fprintf(mFile,"\"%s.n.nz\"",mName.c_str());
	}
	void getUvCoord()const
	{
		fprintf(mFile,"\"%s.uv\"",mName.c_str());
	}
	void getUCoord()const
	{
		fprintf(mFile,"\"%s.uv.u\"",mName.c_str());
	}
	void getVCoord()const
	{
		fprintf(mFile,"\"%s.uv.v\"",mName.c_str());
	}
	void getRayDirection()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getRayDirectionX()const
	{
		fprintf(mFile,"\"%s.r.rx\"",mName.c_str());
	}
	void getRayDirectionY()const
	{
		fprintf(mFile,"\"%s.r.ry\"",mName.c_str());
	}
	void getRayDirectionZ()const
	{
		fprintf(mFile,"\"%s.r.rz\"",mName.c_str());
	}
	void getTangentUCamera()const
	{
		fprintf(mFile,"\"%s.tu\"",mName.c_str());
	}
	void getTangentUx()const
	{
		fprintf(mFile,"\"%s.tu.tux\"",mName.c_str());
	}
	void getTangentUy()const
	{
		fprintf(mFile,"\"%s.tu.tuy\"",mName.c_str());
	}
	void getTangentUz()const
	{
		fprintf(mFile,"\"%s.tu.tuz\"",mName.c_str());
	}
	void getTangentVCamera()const
	{
		fprintf(mFile,"\"%s.tv\"",mName.c_str());
	}
	void getTangentVx()const
	{
		fprintf(mFile,"\"%s.tv.tvx\"",mName.c_str());
	}
	void getTangentVy()const
	{
		fprintf(mFile,"\"%s.tv.tvy\"",mName.c_str());
	}
	void getTangentVz()const
	{
		fprintf(mFile,"\"%s.tv.tvz\"",mName.c_str());
	}
	void getMatrixEyeToWorld()const
	{
		fprintf(mFile,"\"%s.e2w\"",mName.c_str());
	}
	void getPixelCenter()const
	{
		fprintf(mFile,"\"%s.pc\"",mName.c_str());
	}
	void getPixelCenterX()const
	{
		fprintf(mFile,"\"%s.pc.pcx\"",mName.c_str());
	}
	void getPixelCenterY()const
	{
		fprintf(mFile,"\"%s.pc.pcy\"",mName.c_str());
	}
	void getFlippedNormal()const
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());
	}
	void getFacingRatio()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
protected:
	SamplerInfo(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SAMPLERINFO_H__
