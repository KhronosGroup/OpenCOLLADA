/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	EnvBall():TextureEnv(){}
	EnvBall(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:TextureEnv(file, name, parent, "envBall", shared, create){}
	virtual ~EnvBall(){}

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
	void setInclination(float i_)
	{
		if(i_ == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i\" %f;\n", i_);
	}
	void setElevation(float e)
	{
		if(e == 0.0) return;
		fprintf(mFile,"\tsetAttr \".e\" %f;\n", e);
	}
	void setSkyRadius(float sr)
	{
		if(sr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".sr\" %f;\n", sr);
	}
	void setBottom(float bo)
	{
		if(bo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".bo\" %f;\n", bo);
	}
	void setTop(float to)
	{
		if(to == 0.0) return;
		fprintf(mFile,"\tsetAttr \".to\" %f;\n", to);
	}
	void setLeft(float le)
	{
		if(le == 0.0) return;
		fprintf(mFile,"\tsetAttr \".le\" %f;\n", le);
	}
	void setRight(float ri)
	{
		if(ri == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ri\" %f;\n", ri);
	}
	void setFront(float fr)
	{
		if(fr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".fr\" %f;\n", fr);
	}
	void setBack(float ba)
	{
		if(ba == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ba\" %f;\n", ba);
	}
	void setReflect(bool ref)
	{
		if(ref == true) return;
		fprintf(mFile,"\tsetAttr \".ref\" %i;\n", ref);
	}
	void setEyeSpace(bool eye)
	{
		if(eye == false) return;
		fprintf(mFile,"\tsetAttr \".eye\" %i;\n", eye);
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
	void getImage()const
	{
		fprintf(mFile,"\"%s.so\"",mName.c_str());
	}
	void getImageR()const
	{
		fprintf(mFile,"\"%s.so.sor\"",mName.c_str());
	}
	void getImageG()const
	{
		fprintf(mFile,"\"%s.so.sog\"",mName.c_str());
	}
	void getImageB()const
	{
		fprintf(mFile,"\"%s.so.sob\"",mName.c_str());
	}
	void getInclination()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getElevation()const
	{
		fprintf(mFile,"\"%s.e\"",mName.c_str());
	}
	void getSkyRadius()const
	{
		fprintf(mFile,"\"%s.sr\"",mName.c_str());
	}
	void getBottom()const
	{
		fprintf(mFile,"\"%s.bo\"",mName.c_str());
	}
	void getTop()const
	{
		fprintf(mFile,"\"%s.to\"",mName.c_str());
	}
	void getLeft()const
	{
		fprintf(mFile,"\"%s.le\"",mName.c_str());
	}
	void getRight()const
	{
		fprintf(mFile,"\"%s.ri\"",mName.c_str());
	}
	void getFront()const
	{
		fprintf(mFile,"\"%s.fr\"",mName.c_str());
	}
	void getBack()const
	{
		fprintf(mFile,"\"%s.ba\"",mName.c_str());
	}
	void getReflect()const
	{
		fprintf(mFile,"\"%s.ref\"",mName.c_str());
	}
	void getEyeSpace()const
	{
		fprintf(mFile,"\"%s.eye\"",mName.c_str());
	}
	void getInfoBits()const
	{
		fprintf(mFile,"\"%s.ib\"",mName.c_str());
	}
protected:
	EnvBall(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:TextureEnv(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ENVBALL_H__
