/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYBASE_H__
#define __MayaDM_POLYBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
A base node for the polygonal modelling nodes.
 All polygon creation and transformation nodes
 derive from this one.<p/>
*/
class PolyBase : public DependNode
{
public:
public:
	PolyBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polyBase"){}
	virtual ~PolyBase(){}
	/*
	Output object: the mesh node that results from creation or
	a geometrical, topological, or texture mapping transformation.
	*/
	void setOutput(const MeshID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out\";\n",mName.c_str());}
	/*
	Output object: the mesh node that results from creation or
	a geometrical, topological, or texture mapping transformation.
	*/
	MeshID getOutput(){char buffer[4096];sprintf_s (buffer, "%s.out",mName.c_str());return (const char*)buffer;}
protected:
	PolyBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYBASE_H__
