/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GROUPPARTS_H__
#define __MayaDM_GROUPPARTS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    This node is either used to add or modify grouping information to objects.
    Groups are uniquely identified by the groupId that feeds into the node.
    Either new groups can be added or previously created groups can be
    modified using this node.

    These nodes are created when objectSets are created or edited using the
    "sets" command.

</pre></p>
*/
class GroupParts : public DependNode
{
public:
public:
	GroupParts(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "groupParts"){}
	virtual ~GroupParts(){}
	/*The input geometry to add the grouping information to.*/
	void setInputGeometry(const GenericID& ig){fprintf_s(mFile,"connectAttr \"");ig.write(mFile);fprintf_s(mFile,"\" \"%s.ig\";\n",mName.c_str());}
	/*
	Components to be added either to a new group or to a previously
	exiting group.
	*/
	void setInputComponents(const componentList& ic){fprintf_s(mFile, "setAttr \".ic\" -type \"componentList\" ");ic.write(mFile);fprintf_s(mFile,";\n");}
	/*
	Components to be added either to a new group or to a previously
	exiting group.
	*/
	void setInputComponents(const ComponentListID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Components to be removed from a group when the group is being edited.*/
	void setInputRemoveComponent(const componentList& irc){fprintf_s(mFile, "setAttr \".irc\" -type \"componentList\" ");irc.write(mFile);fprintf_s(mFile,";\n");}
	/*Components to be removed from a group when the group is being edited.*/
	void setInputRemoveComponent(const ComponentListID& irc){fprintf_s(mFile,"connectAttr \"");irc.write(mFile);fprintf_s(mFile,"\" \"%s.irc\";\n",mName.c_str());}
	/*The output geometry with the grouping information added to it.*/
	void setOutputGeometry(const GenericID& og){fprintf_s(mFile,"connectAttr \"");og.write(mFile);fprintf_s(mFile,"\" \"%s.og\";\n",mName.c_str());}
	/*Id of group to be created or modified.*/
	void setGroupId(int gi){if(gi == -1) return; fprintf_s(mFile, "setAttr \".gi\" %i;\n", gi);}
	/*Id of group to be created or modified.*/
	void setGroupId(const IntID& gi){fprintf_s(mFile,"connectAttr \"");gi.write(mFile);fprintf_s(mFile,"\" \"%s.gi\";\n",mName.c_str());}
	/*The input geometry to add the grouping information to.*/
	GenericID getInputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.ig",mName.c_str());return (const char*)buffer;}
	/*
	Components to be added either to a new group or to a previously
	exiting group.
	*/
	ComponentListID getInputComponents(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Components to be removed from a group when the group is being edited.*/
	ComponentListID getInputRemoveComponent(){char buffer[4096];sprintf_s (buffer, "%s.irc",mName.c_str());return (const char*)buffer;}
	/*The output geometry with the grouping information added to it.*/
	GenericID getOutputGeometry(){char buffer[4096];sprintf_s (buffer, "%s.og",mName.c_str());return (const char*)buffer;}
	/*Id of group to be created or modified.*/
	IntID getGroupId(){char buffer[4096];sprintf_s (buffer, "%s.gi",mName.c_str());return (const char*)buffer;}
protected:
	GroupParts(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GROUPPARTS_H__
