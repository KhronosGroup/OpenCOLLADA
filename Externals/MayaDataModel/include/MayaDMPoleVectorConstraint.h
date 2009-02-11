/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLEVECTORCONSTRAINT_H__
#define __MayaDM_POLEVECTORCONSTRAINT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPointConstraint.h"
namespace MayaDM
{
class PoleVectorConstraint : public PointConstraint
{
public:
public:
	PoleVectorConstraint():PointConstraint(){}
	PoleVectorConstraint(FILE* file,const std::string& name,const std::string& parent=""):PointConstraint(file, name, parent, "poleVectorConstraint"){}
	virtual ~PoleVectorConstraint(){}
	void setPivotSpace(const matrix& ps)
	{
		if(ps == identity) return;
		fprintf(mFile,"\tsetAttr \".ps\" -type \"matrix\" ");
		ps.write(mFile);
		fprintf(mFile,";\n");

	}
	void getPivotSpace()
	{
		fprintf(mFile,"\"%s.ps\"",mName.c_str());

	}
protected:
	PoleVectorConstraint(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:PointConstraint(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLEVECTORCONSTRAINT_H__
