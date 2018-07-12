/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEVARGROUP_H__
#define __MayaDM_CURVEVARGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBaseGeometryVarGroup.h"
namespace MayaDM
{
class CurveVarGroup : public BaseGeometryVarGroup
{
public:
public:

	CurveVarGroup():BaseGeometryVarGroup(){}
	CurveVarGroup(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BaseGeometryVarGroup(file, name, parent, "curveVarGroup", shared, create){}
	virtual ~CurveVarGroup(){}

	void setDisplaySmoothness(int ds)
	{
		if(ds == -1) return;
		fprintf(mFile,"\tsetAttr \".ds\" %i;\n", ds);
	}
	void getCreate(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i]\"",mName.c_str(),cr_i);
	}
	void getCreate()const
	{

		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getLocal(size_t l_i)const
	{
		fprintf(mFile,"\"%s.l[%i]\"",mName.c_str(),l_i);
	}
	void getLocal()const
	{

		fprintf(mFile,"\"%s.l\"",mName.c_str());
	}
	void getDisplaySmoothness()const
	{
		fprintf(mFile,"\"%s.ds\"",mName.c_str());
	}
protected:
	CurveVarGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BaseGeometryVarGroup(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEVARGROUP_H__
