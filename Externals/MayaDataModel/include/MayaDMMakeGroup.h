/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MAKEGROUP_H__
#define __MayaDM_MAKEGROUP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This utility node takes a poly mesh as input, creates a named
 collection of components, and outputs the resulting mesh.
 The list of elements is stored in the elemList array,
 which stores components of the type specified by groupType.
 groupType can be vertex, face, edge or uvmap.<p/>

 This node has special meaning to polyModifier nodes. Most polyModifier
 nodes which act on components use makeGroup nodes with the
 current group specifier (TDI_GGRP_CURRENT - the default)
 to determine which components to act upon.<p/>
*/
class MakeGroup : public DependNode
{
public:
public:
	MakeGroup(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "makeGroup"){}
	virtual ~MakeGroup(){}
	/*Input geometry without the grouping info.*/
	void setInputGeometry(const MeshID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*Output geometry with the grouping info.*/
	void setOutputGeometry(const MeshID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*
	Specifies which kind of elements are belonging to the group.
	The following are legal values : 0=none, 1=vertex, 2=edge, 3=facet, 4=uvmap.
	*/
	void setGroupType(unsigned int gt){if(gt == 0) return; fprintf_s(mFile, "setAttr \".gt\" %i;\n", gt);}
	/*
	Specifies which kind of elements are belonging to the group.
	The following are legal values : 0=none, 1=vertex, 2=edge, 3=facet, 4=uvmap.
	*/
	void setGroupType(const UnsignedintID& gt){fprintf_s(mFile,"connectAttr \"");gt.write(mFile);fprintf_s(mFile,"\" \"%s.gt\";\n",mName.c_str());}
	/*Identifier for the group. By default, the current group is used.*/
	void setGroupName(int gn){if(gn == -1) return; fprintf_s(mFile, "setAttr \".gn\" %i;\n", gn);}
	/*Identifier for the group. By default, the current group is used.*/
	void setGroupName(const IntID& gn){fprintf_s(mFile,"connectAttr \"");gn.write(mFile);fprintf_s(mFile,"\" \"%s.gn\";\n",mName.c_str());}
	/*The array of the elements to add to the group.*/
	void setElemList(const intArray& el){if(el.size == 0) return; fprintf_s(mFile, "setAttr \".el\" -type \"intArray\" ");el.write(mFile);fprintf_s(mFile,";\n");}
	/*The array of the elements to add to the group.*/
	void setElemList(const IntArrayID& el){fprintf_s(mFile,"connectAttr \"");el.write(mFile);fprintf_s(mFile,"\" \"%s.el\";\n",mName.c_str());}
	/*Input components.*/
	void setInputComponents(const componentList& ic){fprintf_s(mFile, "setAttr \".ic\" -type \"componentList\" ");ic.write(mFile);fprintf_s(mFile,";\n");}
	/*Input components.*/
	void setInputComponents(const ComponentListID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Input geometry without the grouping info.*/
	MeshID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*Output geometry with the grouping info.*/
	MeshID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*
	Specifies which kind of elements are belonging to the group.
	The following are legal values : 0=none, 1=vertex, 2=edge, 3=facet, 4=uvmap.
	*/
	UnsignedintID getGroupType(){char buffer[4096];sprintf_s (buffer, "%s.gt",mName.c_str());return (const char*)buffer;}
	/*Identifier for the group. By default, the current group is used.*/
	IntID getGroupName(){char buffer[4096];sprintf_s (buffer, "%s.gn",mName.c_str());return (const char*)buffer;}
	/*The array of the elements to add to the group.*/
	IntArrayID getElemList(){char buffer[4096];sprintf_s (buffer, "%s.el",mName.c_str());return (const char*)buffer;}
	/*Input components.*/
	ComponentListID getInputComponents(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
protected:
	MakeGroup(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MAKEGROUP_H__
