/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GEOMETRYVARGROUP_H__
#define __MayaDM_GEOMETRYVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
class GeometryVarGroup : public BaseGeometryVarGroup
{
public:
public:
	GeometryVarGroup(FILE* file,const std::string& name,const std::string& parent=""):BaseGeometryVarGroup(file, name, parent, "geometryVarGroup"){}
	virtual ~GeometryVarGroup(){}
	void getCreate(size_t cr_i)
	{
		fprintf(mFile,"\"%s.cr[%i]\"",mName.c_str(),cr_i);

	}
	void getLocal(size_t l_i)
	{
		fprintf(mFile,"\"%s.l[%i]\"",mName.c_str(),l_i);

	}
protected:
	GeometryVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):BaseGeometryVarGroup(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_GEOMETRYVARGROUP_H__
