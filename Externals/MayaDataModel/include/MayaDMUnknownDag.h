/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNKNOWNDAG_H__
#define __MayaDM_UNKNOWNDAG_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDagNode.h"
namespace MayaDM
{
/*
<p><pre> This dependency graph node takes the place of any Dag node the createNode
 cannot find in the registration table.
 It carries along all attribute info for the node so that on file write
 it can save back all the info.
 The node will never evaluate since it knows nothing about the original
 attributes and their dependencies.
</pre></p>
*/
class UnknownDag : public DagNode
{
public:
public:
	UnknownDag(FILE* file,const std::string& name,const std::string& parent=""):DagNode(file, name, parent, "unknownDag"){}
	virtual ~UnknownDag(){}
protected:
	UnknownDag(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DagNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNKNOWNDAG_H__
