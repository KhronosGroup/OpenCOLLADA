/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ARRAYMAPPER_H__
#define __MayaDM_ARRAYMAPPER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ArrayMapper : public DependNode
{
public:
public:

	ArrayMapper():DependNode(){}
	ArrayMapper(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "arrayMapper", shared, create){}
	virtual ~ArrayMapper(){}

	void setMinValue(double min)
	{
		if(min == 0.0) return;
		fprintf(mFile,"\tsetAttr \".min\" %f;\n", min);
	}
	void setMaxValue(double max)
	{
		if(max == 1.0) return;
		fprintf(mFile,"\tsetAttr \".max\" %f;\n", max);
	}
	void getComputeNode()const
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getUCoordPP()const
	{
		fprintf(mFile,"\"%s.upp\"",mName.c_str());
	}
	void getVCoordPP()const
	{
		fprintf(mFile,"\"%s.vpp\"",mName.c_str());
	}
	void getMinValue()const
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());
	}
	void getMaxValue()const
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());
	}
	void getComputeNodeColor()const
	{
		fprintf(mFile,"\"%s.cnc\"",mName.c_str());
	}
	void getComputeNodeColorR()const
	{
		fprintf(mFile,"\"%s.cnc.cncr\"",mName.c_str());
	}
	void getComputeNodeColorG()const
	{
		fprintf(mFile,"\"%s.cnc.cncg\"",mName.c_str());
	}
	void getComputeNodeColorB()const
	{
		fprintf(mFile,"\"%s.cnc.cncb\"",mName.c_str());
	}
	void getTime()const
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());
	}
	void getOutColorPP()const
	{
		fprintf(mFile,"\"%s.ocpp\"",mName.c_str());
	}
	void getOutValuePP()const
	{
		fprintf(mFile,"\"%s.ovpp\"",mName.c_str());
	}
protected:
	ArrayMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ARRAYMAPPER_H__
