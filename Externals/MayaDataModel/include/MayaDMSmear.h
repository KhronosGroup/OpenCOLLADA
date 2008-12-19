/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SMEAR_H__
#define __MayaDM_SMEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Smear : public DependNode
{
public:
public:
	Smear(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "smear"){}
	virtual ~Smear(){}
	void setInRgb(const float3& i)
	{
		if(i == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".i\" -type \"float3\" ");
		i.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInColorR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"setAttr \".i.ir\" %f;\n", ir);

	}
	void setInColorG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"setAttr \".i.ig\" %f;\n", ig);

	}
	void setInColorB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"setAttr \".i.ib\" %f;\n", ib);

	}
	void getInRgb()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getInColorR()
	{
		fprintf(mFile,"\"%s.i.ir\"",mName.c_str());

	}
	void getInColorG()
	{
		fprintf(mFile,"\"%s.i.ig\"",mName.c_str());

	}
	void getInColorB()
	{
		fprintf(mFile,"\"%s.i.ib\"",mName.c_str());

	}
	void getOutUV()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutU()
	{
		fprintf(mFile,"\"%s.o.ou\"",mName.c_str());

	}
	void getOutV()
	{
		fprintf(mFile,"\"%s.o.ov\"",mName.c_str());

	}
protected:
	Smear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SMEAR_H__
