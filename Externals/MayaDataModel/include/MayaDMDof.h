/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
/*
<p><pre>
        This node is for Depth Of Field (DOF) postprocess.
        Note, its not a true dependency node, it has attributes
        but no computePlug. DOF can be evaluated by
        calling computeDOF.  Don't bother trying to hook
        this up in a network, it only makes sense when it is
        connected to the postProcesses node.

</pre></p>
*/
class Dof : public DependNode
{
public:
public:
	Dof(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "dof"){}
	virtual ~Dof(){}
protected:
	Dof(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_DOF_H__
