/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BASEGEOMETRYVARGROUP_H__
#define __MayaDM_BASEGEOMETRYVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class BaseGeometryVarGroup : public Transform
{
public:
public:
	BaseGeometryVarGroup():Transform(){}
	BaseGeometryVarGroup(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "baseGeometryVarGroup"){}
	virtual ~BaseGeometryVarGroup(){}
	void setMaxCreated(int mc)
	{
		if(mc == -1) return;
		fprintf(mFile,"\tsetAttr \".mc\" %i;\n", mc);

	}
	void getMaxCreated()
	{
		fprintf(mFile,"\"%s.mc\"",mName.c_str());

	}
protected:
	BaseGeometryVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_BASEGEOMETRYVARGROUP_H__
