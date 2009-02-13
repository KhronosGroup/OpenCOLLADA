/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MESHVARGROUP_H__
#define __MayaDM_MESHVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
class MeshVarGroup : public BaseGeometryVarGroup
{
public:
public:
	MeshVarGroup():BaseGeometryVarGroup(){}
	MeshVarGroup(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:BaseGeometryVarGroup(file, name, parent, "meshVarGroup", create){}
	virtual ~MeshVarGroup(){}
	void getCreate(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i]\"",mName.c_str(),cr_i);

	}
	void getLocal(size_t l_i)const
	{
		fprintf(mFile,"\"%s.l[%i]\"",mName.c_str(),l_i);

	}
protected:
	MeshVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:BaseGeometryVarGroup(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_MESHVARGROUP_H__
