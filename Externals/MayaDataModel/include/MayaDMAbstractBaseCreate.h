/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ABSTRACTBASECREATE_H__
#define __MayaDM_ABSTRACTBASECREATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
A base node for the nurbs modelling nodes.  It
 defines no attributes of its own.
*/
class AbstractBaseCreate : public DependNode
{
public:
public:
	AbstractBaseCreate(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "abstractBaseCreate"){}
	virtual ~AbstractBaseCreate(){}
protected:
	AbstractBaseCreate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ABSTRACTBASECREATE_H__
