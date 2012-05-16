/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SHAPE_H__
#define __MayaDM_SHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDagNode.h"
namespace MayaDM
{
class Shape : public DagNode
{
public:

	Shape():DagNode(){}
	Shape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DagNode(file, name, parent, "shape", shared, create){}
	virtual ~Shape(){}

protected:
	Shape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DagNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SHAPE_H__
