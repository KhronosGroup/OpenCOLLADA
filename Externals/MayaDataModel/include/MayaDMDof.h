/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DOF_H__
#define __MayaDM_DOF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class Dof : public DependNode
{
public:
	Dof():DependNode(){}
	Dof(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "dof"){}
	virtual ~Dof(){}
protected:
	Dof(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DOF_H__
