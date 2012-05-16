/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	Condition():DependNode(){}
	Condition(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "condition", shared, create){}
	virtual ~Condition(){}

	void setOperation(unsigned int op)
	{
		if(op == 0) return;
		fprintf(mFile,"\tsetAttr \".op\" %i;\n", op);
	}
	void setFirstTerm(float ft)
	{
		if(ft == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ft\" %f;\n", ft);
	}
	void setSecondTerm(float st)
	{
		if(st == 0.0) return;
		fprintf(mFile,"\tsetAttr \".st\" %f;\n", st);
	}
	void setColorIfTrue(const float3& ct)
	{
		if(ct == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".ct\" -type \"float3\" ");
		ct.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorIfTrueR(float ctr)
	{
		if(ctr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ct.ctr\" %f;\n", ctr);
	}
	void setColorIfTrueG(float ctg)
	{
		if(ctg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ct.ctg\" %f;\n", ctg);
	}
	void setColorIfTrueB(float ctb)
	{
		if(ctb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ct.ctb\" %f;\n", ctb);
	}
	void setColorIfFalse(const float3& cf)
	{
		if(cf == float3(1.0f,1.0f,1.0f)) return;
		fprintf(mFile,"\tsetAttr \".cf\" -type \"float3\" ");
		cf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setColorIfFalseR(float cfr)
	{
		if(cfr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfr\" %f;\n", cfr);
	}
	void setColorIfFalseG(float cfg)
	{
		if(cfg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfg\" %f;\n", cfg);
	}
	void setColorIfFalseB(float cfb)
	{
		if(cfb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cf.cfb\" %f;\n", cfb);
	}
	void getOperation()const
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());
	}
	void getFirstTerm()const
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());
	}
	void getSecondTerm()const
	{
		fprintf(mFile,"\"%s.st\"",mName.c_str());
	}
	void getColorIfTrue()const
	{
		fprintf(mFile,"\"%s.ct\"",mName.c_str());
	}
	void getColorIfTrueR()const
	{
		fprintf(mFile,"\"%s.ct.ctr\"",mName.c_str());
	}
	void getColorIfTrueG()const
	{
		fprintf(mFile,"\"%s.ct.ctg\"",mName.c_str());
	}
	void getColorIfTrueB()const
	{
		fprintf(mFile,"\"%s.ct.ctb\"",mName.c_str());
	}
	void getColorIfFalse()const
	{
		fprintf(mFile,"\"%s.cf\"",mName.c_str());
	}
	void getColorIfFalseR()const
	{
		fprintf(mFile,"\"%s.cf.cfr\"",mName.c_str());
	}
	void getColorIfFalseG()const
	{
		fprintf(mFile,"\"%s.cf.cfg\"",mName.c_str());
	}
	void getColorIfFalseB()const
	{
		fprintf(mFile,"\"%s.cf.cfb\"",mName.c_str());
	}
	void getOutColor()const
	{
		fprintf(mFile,"\"%s.oc\"",mName.c_str());
	}
	void getOutColorR()const
	{
		fprintf(mFile,"\"%s.oc.ocr\"",mName.c_str());
	}
	void getOutColorG()const
	{
		fprintf(mFile,"\"%s.oc.ocg\"",mName.c_str());
	}
	void getOutColorB()const
	{
		fprintf(mFile,"\"%s.oc.ocb\"",mName.c_str());
	}
protected:
	Condition(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CONDITION_H__
