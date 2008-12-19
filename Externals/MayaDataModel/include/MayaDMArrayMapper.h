/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	ArrayMapper(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "arrayMapper"){}
	virtual ~ArrayMapper(){}
	void setMinValue(double min)
	{
		if(min == 0.0) return;
		fprintf(mFile,"setAttr \".min\" %f;\n", min);

	}
	void setMaxValue(double max)
	{
		if(max == 1.0) return;
		fprintf(mFile,"setAttr \".max\" %f;\n", max);

	}
	void getUCoordPP()
	{
		fprintf(mFile,"\"%s.upp\"",mName.c_str());

	}
	void getVCoordPP()
	{
		fprintf(mFile,"\"%s.vpp\"",mName.c_str());

	}
	void getMinValue()
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());

	}
	void getMaxValue()
	{
		fprintf(mFile,"\"%s.max\"",mName.c_str());

	}
	void getComputeNodeColor()
	{
		fprintf(mFile,"\"%s.cnc\"",mName.c_str());

	}
	void getComputeNodeColorR()
	{
		fprintf(mFile,"\"%s.cnc.cncr\"",mName.c_str());

	}
	void getComputeNodeColorG()
	{
		fprintf(mFile,"\"%s.cnc.cncg\"",mName.c_str());

	}
	void getComputeNodeColorB()
	{
		fprintf(mFile,"\"%s.cnc.cncb\"",mName.c_str());

	}
	void getTime()
	{
		fprintf(mFile,"\"%s.tim\"",mName.c_str());

	}
	void getOutColorPP()
	{
		fprintf(mFile,"\"%s.ocpp\"",mName.c_str());

	}
	void getOutValuePP()
	{
		fprintf(mFile,"\"%s.ovpp\"",mName.c_str());

	}
protected:
	ArrayMapper(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_ARRAYMAPPER_H__
