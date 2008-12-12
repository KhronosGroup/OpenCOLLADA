/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_GROUPID_H__
#define __MayaDM_GROUPID_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node is used to specify a unique id for objectGroups in dagObjects
        that are a part of an objectSet. This is the all important node that
        connects up groupPart, objectSet and dagObjects all of which combine to
        define objectGroups that are members of objectSets. These nodes along with
        the groupParts node are used when parts (components) of a dagObject are
        in an objectSet. <p/>

        The node gets created by the "sets" command when new sets are created,
        and additional connections could be made to it when existing sets are
        edited. <p/>
*/
class GroupId : public DependNode
{
public:
public:
	GroupId(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "groupId"){}
	virtual ~GroupId(){}
	/*
	System defined id used to uniquely identify an objectGroup in
	dagObjects
	*/
	void setGroupId(const IntID& id){fprintf_s(mFile,"connectAttr \"");id.write(mFile);fprintf_s(mFile,"\" \"%s.id\";\n",mName.c_str());}
	/*
	System defined id used to uniquely identify an objectGroup in
	dagObjects
	*/
	IntID getGroupId(){char buffer[4096];sprintf_s (buffer, "%s.id",mName.c_str());return (const char*)buffer;}
protected:
	GroupId(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_GROUPID_H__
