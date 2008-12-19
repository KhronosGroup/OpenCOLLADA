/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TIME_H__
#define __MayaDM_TIME_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Time : public DependNode
{
public:
public:
	Time(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "time"){}
	virtual ~Time(){}
	void getOutTime()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	Time(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TIME_H__
