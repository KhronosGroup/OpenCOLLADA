/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class EnvSphere : public TextureEnv
{
public:
public:
	EnvSphere():TextureEnv(){}
	EnvSphere(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envSphere"){}
	virtual ~EnvSphere(){}
	void setImage(const float3& so)
	{
		if(so == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".so\" -type \"float3\" ");
		so.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImageR(float sor)
	{
		if(sor == 0.0) return;
		fprintf(mFile,"\tsetAttr \".so.sor\" %f;\n", sor);

	}
	void setImageG(float sog)
	{
		if(sog == 0.0) return;
		fprintf(mFile,"\tsetAttr \".so.sog\" %f;\n", sog);

	}
	void setImageB(float sob)
	{
		if(sob == 0.0) return;
		fprintf(mFile,"\tsetAttr \".so.sob\" %f;\n", sob);

	}
	void setShearUV(const float2& suv)
	{
		if(suv == float2(0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".suv\" -type \"float2\" ");
		suv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setShearU(float su)
	{
		if(su == 0.0) return;
		fprintf(mFile,"\tsetAttr \".suv.su\" %f;\n", su);

	}
	void setShearV(float sv)
	{
		if(sv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".suv.sv\" %f;\n", sv);

	}
	void setFlip(bool f)
	{
		if(f == false) return;
		fprintf(mFile,"\tsetAttr \".f\" %i;\n", f);

	}
	void getPointCamera()
	{
		fprintf(mFile,"\"%s.p\"",mName.c_str());

	}
	void getPointCameraX()
	{
		fprintf(mFile,"\"%s.p.px\"",mName.c_str());

	}
	void getPointCameraY()
	{
		fprintf(mFile,"\"%s.p.py\"",mName.c_str());

	}
	void getPointCameraZ()
	{
		fprintf(mFile,"\"%s.p.pz\"",mName.c_str());

	}
	void getRefPointCamera()
	{
		fprintf(mFile,"\"%s.rpc\"",mName.c_str());

	}
	void getRefPointCameraX()
	{
		fprintf(mFile,"\"%s.rpc.rcx\"",mName.c_str());

	}
	void getRefPointCameraY()
	{
		fprintf(mFile,"\"%s.rpc.rcy\"",mName.c_str());

	}
	void getRefPointCameraZ()
	{
		fprintf(mFile,"\"%s.rpc.rcz\"",mName.c_str());

	}
	void getImage()
	{
		fprintf(mFile,"\"%s.so\"",mName.c_str());

	}
	void getImageR()
	{
		fprintf(mFile,"\"%s.so.sor\"",mName.c_str());

	}
	void getImageG()
	{
		fprintf(mFile,"\"%s.so.sog\"",mName.c_str());

	}
	void getImageB()
	{
		fprintf(mFile,"\"%s.so.sob\"",mName.c_str());

	}
	void getShearUV()
	{
		fprintf(mFile,"\"%s.suv\"",mName.c_str());

	}
	void getShearU()
	{
		fprintf(mFile,"\"%s.suv.su\"",mName.c_str());

	}
	void getShearV()
	{
		fprintf(mFile,"\"%s.suv.sv\"",mName.c_str());

	}
	void getFlip()
	{
		fprintf(mFile,"\"%s.f\"",mName.c_str());

	}
	void getInfoBits()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
protected:
	EnvSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:TextureEnv(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVSPHERE_H__
