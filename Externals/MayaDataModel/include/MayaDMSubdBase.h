/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDBASE_H__
#define __MayaDM_SUBDBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
A base node for the subd modelling nodes.
 All subd creation and transformation nodes
 derive from this one.<p/>
*/
class SubdBase : public DependNode
{
public:
public:
	SubdBase(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "subdBase"){}
	virtual ~SubdBase(){}
	/*
	Output object: the subdiv geometry that results from creation
	or a geometrical, topological, or texture mapping
	transformation.
	*/
	void setOutSubdiv(const SubdivisionSurfaceID& os){fprintf_s(mFile,"connectAttr \"");os.write(mFile);fprintf_s(mFile,"\" \"%s.os\";\n",mName.c_str());}
	/*
	Output object: the subdiv geometry that results from creation
	or a geometrical, topological, or texture mapping
	transformation.
	*/
	SubdivisionSurfaceID getOutSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.os",mName.c_str());return (const char*)buffer;}
protected:
	SubdBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDBASE_H__
