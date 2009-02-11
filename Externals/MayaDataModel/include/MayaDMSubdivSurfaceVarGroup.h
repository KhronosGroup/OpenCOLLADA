/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDIVSURFACEVARGROUP_H__
#define __MayaDM_SUBDIVSURFACEVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
class SubdivSurfaceVarGroup : public BaseGeometryVarGroup
{
public:
public:
	SubdivSurfaceVarGroup():BaseGeometryVarGroup(){}
	SubdivSurfaceVarGroup(FILE* file,const std::string& name,const std::string& parent=""):BaseGeometryVarGroup(file, name, parent, "subdivSurfaceVarGroup"){}
	virtual ~SubdivSurfaceVarGroup(){}
	void getCreate(size_t cr_i)
	{
		fprintf(mFile,"\"%s.cr[%i]\"",mName.c_str(),cr_i);

	}
	void getLocal(size_t l_i)
	{
		fprintf(mFile,"\"%s.l[%i]\"",mName.c_str(),l_i);

	}
protected:
	SubdivSurfaceVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:BaseGeometryVarGroup(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SUBDIVSURFACEVARGROUP_H__
