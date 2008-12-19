/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONDITION_H__
#define __MayaDM_CONDITION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Condition : public DependNode
{
public:
public:
	Condition(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "condition"){}
	virtual ~Condition(){}
	void setOperation(unsigned int op)
	{
		if(op == 0) return;
		fprintf(mFile,"setAttr \".op\" %i;\n", op);

	}
	void setFirstTerm(float ft)
	{
		if(ft == 0.0) return;
		fprintf(mFile,"setAttr \".ft\" %f;\n", ft);

	}
	void setSecondTerm(float st)
	{
		if(st == 0.0) return;
		fprintf(mFile,"setAttr \".st\" %f;\n", st);

	}
	void setColorIfTrue(const float3& ct)
	{
		if(ct == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"setAttr \".ct\" -type \"float3\" ");
		ct.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorIfTrueR(float ctr)
	{
		if(ctr == 0.0) return;
		fprintf(mFile,"setAttr \".ct.ctr\" %f;\n", ctr);

	}
	void setColorIfTrueG(float ctg)
	{
		if(ctg == 0.0) return;
		fprintf(mFile,"setAttr \".ct.ctg\" %f;\n", ctg);

	}
	void setColorIfTrueB(float ctb)
	{
		if(ctb == 0.0) return;
		fprintf(mFile,"setAttr \".ct.ctb\" %f;\n", ctb);

	}
	void setColorIfFalse(const float3& cf)
	{
		if(cf == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"setAttr \".cf\" -type \"float3\" ");
		cf.write(mFile);
		fprintf(mFile,";\n");

	}
	void setColorIfFalseR(float cfr)
	{
		if(cfr == 0.0) return;
		fprintf(mFile,"setAttr \".cf.cfr\" %f;\n", cfr);

	}
	void setColorIfFalseG(float cfg)
	{
		if(cfg == 0.0) return;
		fprintf(mFile,"setAttr \".cf.cfg\" %f;\n", cfg);

	}
	void setColorIfFalseB(float cfb)
	{
		if(cfb == 0.0) return;
		fprintf(mFile,"setAttr \".cf.cfb\" %f;\n", cfb);

	}
	void getOperation()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getFirstTerm()
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getSecondTerm()
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());

	}
	void getColorIfTrue()
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());

	}
	void getColorIfTrueR()
	{
		fprintf(mFile,"\"%s.ct.ctr\"",mName.c_str());

	}
	void getColorIfTrueG()
	{
		fprintf(mFile,"\"%s.ct.ctg\"",mName.c_str());

	}
	void getColorIfTrueB()
	{
		fprintf(mFile,"\"%s.ct.ctb\"",mName.c_str());

	}
	void getColorIfFalse()
	{
		fprintf(mFile,"\"%s.cf\"",mName.c_str());

	}
	void getColorIfFalseR()
	{
		fprintf(mFile,"\"%s.cf.cfr\"",mName.c_str());

	}
	void getColorIfFalseG()
	{
		fprintf(mFile,"\"%s.cf.cfg\"",mName.c_str());

	}
	void getColorIfFalseB()
	{
		fprintf(mFile,"\"%s.cf.cfb\"",mName.c_str());

	}
	void getOutColor()
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());

	}
	void getOutColorR()
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());

	}
	void getOutColorG()
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());

	}
	void getOutColorB()
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());

	}
protected:
	Condition(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CONDITION_H__
