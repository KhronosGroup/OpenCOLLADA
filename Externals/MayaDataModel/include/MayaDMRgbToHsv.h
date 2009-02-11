/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RGBTOHSV_H__
#define __MayaDM_RGBTOHSV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class RgbToHsv : public DependNode
{
public:
public:
	RgbToHsv():DependNode(){}
	RgbToHsv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "rgbToHsv"){}
	virtual ~RgbToHsv(){}
	void setInRgb(const float3& i_)
	{
		if(i_ == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".i\" -type \"float3\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setInRgbR(float ir)
	{
		if(ir == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ir\" %f;\n", ir);

	}
	void setInRgbG(float ig)
	{
		if(ig == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ig\" %f;\n", ig);

	}
	void setInRgbB(float ib)
	{
		if(ib == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i.ib\" %f;\n", ib);

	}
	void getInRgb()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getInRgbR()
	{
		fprintf(mFile,"\"%s.i.ir\"",mName.c_str());

	}
	void getInRgbG()
	{
		fprintf(mFile,"\"%s.i.ig\"",mName.c_str());

	}
	void getInRgbB()
	{
		fprintf(mFile,"\"%s.i.ib\"",mName.c_str());

	}
	void getOutHsv()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getOutHsvH()
	{
		fprintf(mFile,"\"%s.o.oh\"",mName.c_str());

	}
	void getOutHsvS()
	{
		fprintf(mFile,"\"%s.o.os\"",mName.c_str());

	}
	void getOutHsvV()
	{
		fprintf(mFile,"\"%s.o.ov\"",mName.c_str());

	}
protected:
	RgbToHsv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RGBTOHSV_H__
