/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CLAMP_H__
#define __MayaDM_CLAMP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Clamp : public DependNode
{
public:
public:
	Clamp():DependNode(){}
	Clamp(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "clamp"){}
	virtual ~Clamp(){}
	void setMin(const float3& mn)
	{
		if(mn == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".mn\" -type \"float3\" ");
		mn.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMinR(float mnr)
	{
		if(mnr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mn.mnr\" %f;\n", mnr);

	}
	void setMinG(float mng)
	{
		if(mng == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mn.mng\" %f;\n", mng);

	}
	void setMinB(float mnb)
	{
		if(mnb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mn.mnb\" %f;\n", mnb);

	}
	void setMax(const float3& mx)
	{
		if(mx == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".mx\" -type \"float3\" ");
		mx.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxR(float mxr)
	{
		if(mxr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mx.mxr\" %f;\n", mxr);

	}
	void setMaxG(float mxg)
	{
		if(mxg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mx.mxg\" %f;\n", mxg);

	}
	void setMaxB(float mxb)
	{
		if(mxb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".mx.mxb\" %f;\n", mxb);

	}
	void setInput(const float3& ip)
	{
		if(ip == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".ip\" -type \"float3\" ");
		ip.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInputR(float ipr)
	{
		if(ipr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipr\" %f;\n", ipr);

	}
	void setInputG(float ipg)
	{
		if(ipg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipg\" %f;\n", ipg);

	}
	void setInputB(float ipb)
	{
		if(ipb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".ip.ipb\" %f;\n", ipb);

	}
	void getMin()
	{
		fprintf(mFile,"\"%s.mn\"",mName.c_str());

	}
	void getMinR()
	{
		fprintf(mFile,"\"%s.mn.mnr\"",mName.c_str());

	}
	void getMinG()
	{
		fprintf(mFile,"\"%s.mn.mng\"",mName.c_str());

	}
	void getMinB()
	{
		fprintf(mFile,"\"%s.mn.mnb\"",mName.c_str());

	}
	void getMax()
	{
		fprintf(mFile,"\"%s.mx\"",mName.c_str());

	}
	void getMaxR()
	{
		fprintf(mFile,"\"%s.mx.mxr\"",mName.c_str());

	}
	void getMaxG()
	{
		fprintf(mFile,"\"%s.mx.mxg\"",mName.c_str());

	}
	void getMaxB()
	{
		fprintf(mFile,"\"%s.mx.mxb\"",mName.c_str());

	}
	void getInput()
	{
		fprintf(mFile,"\"%s.ip\"",mName.c_str());

	}
	void getInputR()
	{
		fprintf(mFile,"\"%s.ip.ipr\"",mName.c_str());

	}
	void getInputG()
	{
		fprintf(mFile,"\"%s.ip.ipg\"",mName.c_str());

	}
	void getInputB()
	{
		fprintf(mFile,"\"%s.ip.ipb\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.op\"",mName.c_str());

	}
	void getOutputR()
	{
		fprintf(mFile,"\"%s.op.opr\"",mName.c_str());

	}
	void getOutputG()
	{
		fprintf(mFile,"\"%s.op.opg\"",mName.c_str());

	}
	void getOutputB()
	{
		fprintf(mFile,"\"%s.op.opb\"",mName.c_str());

	}
protected:
	Clamp(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CLAMP_H__
