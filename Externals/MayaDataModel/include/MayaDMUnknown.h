/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNKNOWN_H__
#define __MayaDM_UNKNOWN_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre> This dependency graph node takes the place of any node the createNode
 cannot find in the registration table.
 It carries along all attribute info for the node so that on file write
 it can save back all the info.
 The node will never evaluate since it knows nothing about the original
 attributes and their dependencies.
</pre></p>
*/
class Unknown : public DependNode
{
public:
public:
	Unknown(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "unknown"){}
	virtual ~Unknown(){}
protected:
	Unknown(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNKNOWN_H__
