/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TIMETOUNITCONVERSION_H__
#define __MayaDM_TIMETOUNITCONVERSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class TimeToUnitConversion : public DependNode
{
public:
public:
	TimeToUnitConversion():DependNode(){}
	TimeToUnitConversion(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "timeToUnitConversion"){}
	virtual ~TimeToUnitConversion(){}
	void setConversionFactor(double cf)
	{
		if(cf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cf\" %f;\n", cf);

	}
	void getInput()
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());

	}
	void getOutput()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	TimeToUnitConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TIMETOUNITCONVERSION_H__
