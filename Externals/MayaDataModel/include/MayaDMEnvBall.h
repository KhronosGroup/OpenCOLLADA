/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ENVBALL_H__
#define __MayaDM_ENVBALL_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTextureEnv.h"
namespace MayaDM
{
class EnvBall : public TextureEnv
{
public:
public:
	EnvBall(FILE* file,const std::string& name,const std::string& parent=""):TextureEnv(file, name, parent, "envBall"){}
	virtual ~EnvBall(){}
	void setImage(const float3& so)
	{
		if(so == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".so\" -type \"float3\" ");
		so.write(mFile);
		fprintf(mFile,";\n");

	}
	void setImageR(float sor)
	{
		if(sor == 0.0) return;
		fprintf(mFile,"setAttr \".so.sor\" %f;\n", sor);

	}
	void setImageG(float sog)
	{
		if(sog == 0.0) return;
		fprintf(mFile,"setAttr \".so.sog\" %f;\n", sog);

	}
	void setImageB(float sob)
	{
		if(sob == 0.0) return;
		fprintf(mFile,"setAttr \".so.sob\" %f;\n", sob);

	}
	void setInclination(float i)
	{
		if(i == 0.0) return;
		fprintf(mFile,"setAttr \".i\" %f;\n", i);

	}
	void setElevation(float e)
	{
		if(e == 0.0) return;
		fprintf(mFile,"setAttr \".e\" %f;\n", e);

	}
	void setSkyRadius(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"setAttr \".sr\" %f;\n", sr);

	}
	void setBottom(float bo)
	{
		if(bo == 0.0) return;
		fprintf(mFile,"setAttr \".bo\" %f;\n", bo);

	}
	void setTop(float to)
	{
		if(to == 0.0) return;
		fprintf(mFile,"setAttr \".to\" %f;\n", to);

	}
	void setLeft(float le)
	{
		if(le == 0.0) return;
		fprintf(mFile,"setAttr \".le\" %f;\n", le);

	}
	void setRight(float ri)
	{
		if(ri == 0.0) return;
		fprintf(mFile,"setAttr \".ri\" %f;\n", ri);

	}
	void setFront(float fr)
	{
		if(fr == 0.0) return;
		fprintf(mFile,"setAttr \".fr\" %f;\n", fr);

	}
	void setBack(float ba)
	{
		if(ba == 0.0) return;
		fprintf(mFile,"setAttr \".ba\" %f;\n", ba);

	}
	void setReflect(bool ref)
	{
		if(ref == true) return;
		fprintf(mFile,"setAttr \".ref\" %i;\n", ref);

	}
	void setEyeSpace(bool eye)
	{
		if(eye == false) return;
		fprintf(mFile,"setAttr \".eye\" %i;\n", eye);

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
	void getInclination()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getElevation()
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());

	}
	void getSkyRadius()
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());

	}
	void getBottom()
	{
		fprintf(mFile,"\"%s.bo\"",mName.c_str());

	}
	void getTop()
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());

	}
	void getLeft()
	{
		fprintf(mFile,"\"%s.le\"",mName.c_str());

	}
	void getRight()
	{
		fprintf(mFile,"\"%s.ri\"",mName.c_str());

	}
	void getFront()
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());

	}
	void getBack()
	{
		fprintf(mFile,"\"%s.ba\"",mName.c_str());

	}
	void getReflect()
	{
		fprintf(mFile,"\"%s.ref\"",mName.c_str());

	}
	void getEyeSpace()
	{
		fprintf(mFile,"\"%s.eye\"",mName.c_str());

	}
	void getInfoBits()
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());

	}
protected:
	EnvBall(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):TextureEnv(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVBALL_H__
