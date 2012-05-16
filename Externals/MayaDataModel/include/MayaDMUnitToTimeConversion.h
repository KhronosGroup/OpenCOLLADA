/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	UnitToTimeConversion():DependNode(){}
	UnitToTimeConversion(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "unitToTimeConversion", shared, create){}
	virtual ~UnitToTimeConversion(){}

	void setInput(double i_)
	{
		if(i_ == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i\" %f;\n", i_);
	}
	void setConversionFactor(double cf)
	{
		if(cf == 1.0) return;
		fprintf(mFile,"\tsetAttr \".cf\" %f;\n", cf);
	}
	void getInput()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutput()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	UnitToTimeConversion(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_UNITTOTIMECONVERSION_H__
