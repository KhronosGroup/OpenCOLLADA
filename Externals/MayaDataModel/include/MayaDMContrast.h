/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Contrast(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "contrast"){}
	virtual ~Contrast(){}
	void setValue(const float3& v)
	{
		if(v == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".v\" -type \"float3\" ");
		v.write(mFile);
		fprintf(mFile,";\n");

	}
	void setValueX(float vx)
	{
		if(vx == 0.0) return;
		fprintf(mFile,"setAttr \".v.vx\" %f;\n", vx);

	}
	void setValueY(float vy)
	{
		if(vy == 0.0) return;
		fprintf(mFile,"setAttr \".v.vy\" %f;\n", vy);

	}
	void setValueZ(float vz)
	{
		if(vz == 0.0) return;
		fprintf(mFile,"setAttr \".v.vz\" %f;\n", vz);

	}
	void setContrast(const float3& c)
	{
		if(c == float3(2.0f,2.0f,2.0f)) return;
		fprintf(mFile,"setAttr \".c\" -type \"float3\" ");
		c.write(mFile);
		fprintf(mFile,";\n");

	}
	void setContrastX(float cx)
	{
		if(cx == 0.0) return;
		fprintf(mFile,"setAttr \".c.cx\" %f;\n", cx);

	}
	void setContrastY(float cy)
	{
		if(cy == 0.0) return;
		fprintf(mFile,"setAttr \".c.cy\" %f;\n", cy);

	}
	void setContrastZ(float cz)
	{
		if(cz == 0.0) return;
		fprintf(mFile,"setAttr \".c.cz\" %f;\n", cz);

	}
	void setBias(const float3& b)
	{
		if(b == float3(0.5f,0.5f,0.5f)) return;
		fprintf(mFile,"setAttr \".b\" -type \"float3\" ");
		b.write(mFile);
		fprintf(mFile,";\n");

	}
	void setBiasX(float bx)
	{
		if(bx == 0.0) return;
		fprintf(mFile,"setAttr \".b.bx\" %f;\n", bx);

	}
	void setBiasY(float by)
	{
		if(by == 0.0) return;
		fprintf(mFile,"setAttr \".b.by\" %f;\n", by);

	}
	void setBiasZ(float bz)
	{
		if(bz == 0.0) return;
		fprintf(mFile,"setAttr \".b.bz\" %f;\n", bz);

	}
	void getValue()
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());

	}
	void getValueX()
	{
		fprintf(mFile,"\"%s.v.vx\"",mName.c_str());

	}
	void getValueY()
	{
		fprintf(mFile,"\"%s.v.vy\"",mName.c_str());

	}
	void getValueZ()
	{
		fprintf(mFile,"\"%s.v.vz\"",mName.c_str());

	}
	void getContrast()
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());

	}
	void getContrastX()
	{
		fprintf(mFile,"\"%s.c.cx\"",mName.c_str());

	}
	void getContrastY()
	{
		fprintf(mFile,"\"%s.c.cy\"",mName.c_str());

	}
	void getContrastZ()
	{
		fprintf(mFile,"\"%s.c.cz\"",mName.c_str());

	}
	void getBias()
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());

	}
	void getBiasX()
	{
		fprintf(mFile,"\"%s.b.bx\"",mName.c_str());

	}
	void getBiasY()
	{
		fprintf(mFile,"\"%s.b.by\"",mName.c_str());

	}
	void getBiasZ()
	{
		fprintf(mFile,"\"%s.b.bz\"",mName.c_str());

	}
	void getOutValue()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutValueX()
	{
		fprintf(mFile,"\"%s.o.ox\"",mName.c_str());

	}
	void getOutValueY()
	{
		fprintf(mFile,"\"%s.o.oy\"",mName.c_str());

	}
	void getOutValueZ()
	{
		fprintf(mFile,"\"%s.o.oz\"",mName.c_str());

	}
protected:
	Contrast(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CONTRAST_H__
