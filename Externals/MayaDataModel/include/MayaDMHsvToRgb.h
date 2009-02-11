/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HSVTORGB_H__
#define __MayaDM_HSVTORGB_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class HsvToRgb : public DependNode
{
public:
public:
	HsvToRgb():DependNode(){}
	HsvToRgb(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "hsvToRgb"){}
	virtual ~HsvToRgb(){}
	void setInHsv(const float3& i_)
	{
		if(i_ == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i\" -type \"float3\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInHsvR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ir\" %f;\n", ir);

	}
	void setInHsvG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ig\" %f;\n", ig);

	}
	void setInHsvB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ib\" %f;\n", ib);

	}
	void getInHsv()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getInHsvR()
	{
		fprintf(mFile,"\"%s.i.ir\"",mName.c_str());

	}
	void getInHsvG()
	{
		fprintf(mFile,"\"%s.i.ig\"",mName.c_str());

	}
	void getInHsvB()
	{
		fprintf(mFile,"\"%s.i.ib\"",mName.c_str());

	}
	void getOutRgb()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutRgbR()
	{
		fprintf(mFile,"\"%s.o.or\"",mName.c_str());

	}
	void getOutRgbG()
	{
		fprintf(mFile,"\"%s.o.og\"",mName.c_str());

	}
	void getOutRgbB()
	{
		fprintf(mFile,"\"%s.o.ob\"",mName.c_str());

	}
protected:
	HsvToRgb(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_HSVTORGB_H__
