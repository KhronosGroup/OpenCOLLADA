/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_UNKNOWNTRANSFORM_H__
#define __MayaDM_UNKNOWNTRANSFORM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
/*
<p><pre> This dependency graph node takes the place of any transform node
 (ie. a Dag object that some other node tries to parent to) the createNode
 cannot find in the registration table.
 It carries along all attribute info for the node so that on file write
 it can save back all the info.
 The node will never evaluate since it knows nothing about the original
 attributes and their dependencies.
</pre></p>
*/
class UnknownTransform : public Transform
{
public:
public:
	UnknownTransform(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "unknownTransform"){}
	virtual ~UnknownTransform(){}
protected:
	UnknownTransform(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_UNKNOWNTRANSFORM_H__
