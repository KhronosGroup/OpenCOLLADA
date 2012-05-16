/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONTRAST_H__
#define __MayaDM_CONTRAST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Contrast : public DependNode
{
public:
public:

	Contrast():DependNode(){}
	Contrast(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "contrast", shared, create){}
	virtual ~Contrast(){}

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
	void setContrast(const float3& c)
	{
		if(c == float3(2.0f,2.0f,2.0f)) return;
		fprintf(mFile,"\tsetAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");
	}
	void setContrastX(float cx)
	{
		if(cx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cx\" %f;\n", cx);
	}
	void setContrastY(float cy)
	{
		if(cy == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cy\" %f;\n", cy);
	}
	void setContrastZ(float cz)
	{
		if(cz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".c.cz\" %f;\n", cz);
	}
	void setBias(const float3& b)
	{
		if(b == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"\tsetAttr \".b\" -type \"float3\" ");
		b.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBiasX(float bx)
	{
		if(bx == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b.bx\" %f;\n", bx);
	}
	void setBiasY(float by)
	{
		if(by == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b.by\" %f;\n", by);
	}
	void setBiasZ(float bz)
	{
		if(bz == 0.0) return;
		fprintf(mFile,"\tsetAttr \".b.bz\" %f;\n", bz);
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
	void getContrast()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getContrastX()const
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());
	}
	void getContrastY()const
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());
	}
	void getContrastZ()const
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());
	}
	void getBias()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getBiasX()const
	{
		fprintf(mFile,"\"%s.b.bx\"",mName.c_str());
	}
	void getBiasY()const
	{
		fprintf(mFile,"\"%s.b.by\"",mName.c_str());
	}
	void getBiasZ()const
	{
		fprintf(mFile,"\"%s.b.bz\"",mName.c_str());
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
	Contrast(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CONTRAST_H__
