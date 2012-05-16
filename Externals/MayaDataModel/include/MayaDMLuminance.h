/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LUMINANCE_H__
#define __MayaDM_LUMINANCE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Luminance : public DependNode
{
public:
public:

	Luminance():DependNode(){}
	Luminance(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "luminance", shared, create){}
	virtual ~Luminance(){}

	void setValue(const float3& v)
	{
		if(v == float3(0.0f,0.0f,0.0f)) return;
		fprintf(mFile,"\tsetAttr \".v\" -type \"float3\" ");
		v.write(mFile);
		fprintf(mFile,";\n");
	}
	void setValueR(float vr)
	{
		if(vr == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vr\" %f;\n", vr);
	}
	void setValueG(float vg)
	{
		if(vg == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vg\" %f;\n", vg);
	}
	void setValueB(float vb)
	{
		if(vb == 0.0) return;
		fprintf(mFile,"\tsetAttr \".v.vb\" %f;\n", vb);
	}
	void getValue()const
	{
		fprintf(mFile,"\"%s.v\"",mName.c_str());
	}
	void getValueR()const
	{
		fprintf(mFile,"\"%s.v.vr\"",mName.c_str());
	}
	void getValueG()const
	{
		fprintf(mFile,"\"%s.v.vg\"",mName.c_str());
	}
	void getValueB()const
	{
		fprintf(mFile,"\"%s.v.vb\"",mName.c_str());
	}
	void getOutValue()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	Luminance(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LUMINANCE_H__
