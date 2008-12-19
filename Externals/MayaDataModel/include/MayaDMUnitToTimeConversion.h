/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNITTOTIMECONVERSION_H__
#define __MayaDM_UNITTOTIMECONVERSION_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class UnitToTimeConversion : public DependNode
{
public:
public:
	UnitToTimeConversion(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "unitToTimeConversion"){}
	virtual ~UnitToTimeConversion(){}
	void setInput(double i)
	{
		if(i == 0.0) return;
		fprintf(mFile,"setAttr \".i\" %f;\n", i);

	}
	void setConversionFactor(double cf)
	{
		if(cf == 1.0) return;
		fprintf(mFile,"setAttr \".cf\" %f;\n", cf);

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
	UnitToTimeConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_UNITTOTIMECONVERSION_H__
