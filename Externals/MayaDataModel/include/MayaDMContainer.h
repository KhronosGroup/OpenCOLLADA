/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CONTAINER_H__
#define __MayaDM_CONTAINER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*This node represents a foldable container used in Hypergraph/Hypershade editors*/
class Container : public DependNode
{
public:
public:
	Container(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "container"){}
	virtual ~Container(){}
	/*The hyperLayout attribute that stores depend nodes belonging to this container node.*/
	void setHyperLayout(const MessageID& hl){fprintf_s(mFile,"connectAttr \"");hl.write(mFile);fprintf_s(mFile,"\" \"%s.hl\";\n",mName.c_str());}
	/*collapsed state of container*/
	void setIsCollapsed(bool isc){if(isc == false) return; fprintf_s(mFile, "setAttr \".isc\" %i;\n", isc);}
	/*collapsed state of container*/
	void setIsCollapsed(const BoolID& isc){fprintf_s(mFile,"connectAttr \"");isc.write(mFile);fprintf_s(mFile,"\" \"%s.isc\";\n",mName.c_str());}
	/*The hyperLayout attribute that stores depend nodes belonging to this container node.*/
	MessageID getHyperLayout(){char buffer[4096];sprintf_s (buffer, "%s.hl",mName.c_str());return (const char*)buffer;}
	/*collapsed state of container*/
	BoolID getIsCollapsed(){char buffer[4096];sprintf_s (buffer, "%s.isc",mName.c_str());return (const char*)buffer;}
protected:
	Container(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CONTAINER_H__
