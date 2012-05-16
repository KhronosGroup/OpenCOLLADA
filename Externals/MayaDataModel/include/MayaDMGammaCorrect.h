/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GAMMACORRECT_H__
#define __MayaDM_GAMMACORRECT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class GammaCorrect : public DependNode
{
public:
public:

	GammaCorrect():DependNode(){}
	GammaCorrect(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "gammaCorrect", shared, create){}
	virtual ~GammaCorrect(){}

	void setValue(const float3& v)
	{
		if(v == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".v\" -type \"float3\" ");
		v.write(mFile);
		fprintf(mFile,";\n");
	}
	void setValueX(float vx)
	{
		if(vx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vx\" %f;\n", vx);
	}
	void setValueY(float vy)
	{
		if(vy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vy\" %f;\n", vy);
	}
	void setValueZ(float vz)
	{
		if(vz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vz\" %f;\n", vz);
	}
	void setGamma(const float3& g)
	{
		if(g == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".g\" -type \"float3\" ");
		g.write(mFile);
		fprintf(mFile,";\n");
	}
	void setGammaX(float gx)
	{
		if(gx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g.gx\" %f;\n", gx);
	}
	void setGammaY(float gy)
	{
		if(gy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g.gy\" %f;\n", gy);
	}
	void setGammaZ(float gz)
	{
		if(gz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".g.gz\" %f;\n", gz);
	}
	void getValue()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getValueX()const
	{
		fprintf(mFile,"\"%s.v.vx\"",mName.c_str());
	}
	void getValueY()const
	{
		fprintf(mFile,"\"%s.v.vy\"",mName.c_str());
	}
	void getValueZ()const
	{
		fprintf(mFile,"\"%s.v.vz\"",mName.c_str());
	}
	void getGamma()const
	{
		fprintf(mFile,"\"%s.g\"",mName.c_str());
	}
	void getGammaX()const
	{
		fprintf(mFile,"\"%s.g.gx\"",mName.c_str());
	}
	void getGammaY()const
	{
		fprintf(mFile,"\"%s.g.gy\"",mName.c_str());
	}
	void getGammaZ()const
	{
		fprintf(mFile,"\"%s.g.gz\"",mName.c_str());
	}
	void getOutValue()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getOutValueX()const
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());
	}
	void getOutValueY()const
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());
	}
	void getOutValueZ()const
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());
	}
protected:
	GammaCorrect(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_GAMMACORRECT_H__
