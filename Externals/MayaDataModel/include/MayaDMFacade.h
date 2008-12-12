/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FACADE_H__
#define __MayaDM_FACADE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<b>facade</b> is the base class node for the various facade
 node types, where dynamic attributes can be added to define
 the parameters of node.
*/
class Facade : public DependNode
{
public:
public:
	Facade(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "facade"){}
	virtual ~Facade(){}
	/*Name of the facade node in the shared library*/
	void setSharedLibName(const string& sln){if(sln == "NULL") return; fprintf_s(mFile, "setAttr \".sln\" -type \"string\" ");sln.write(mFile);fprintf_s(mFile,";\n");}
	/*Name of the facade node in the shared library*/
	void setSharedLibName(const StringID& sln){fprintf_s(mFile,"connectAttr \"");sln.write(mFile);fprintf_s(mFile,"\" \"%s.sln\";\n",mName.c_str());}
	/*Used to keep relationships with other nodes*/
	void setConnection(const MessageID& c){fprintf_s(mFile,"connectAttr \"");c.write(mFile);fprintf_s(mFile,"\" \"%s.c\";\n",mName.c_str());}
	/*User friendly name for this node.*/
	void setUiName(const string& uin){if(uin == "NULL") return; fprintf_s(mFile, "setAttr \".uin\" -type \"string\" ");uin.write(mFile);fprintf_s(mFile,";\n");}
	/*User friendly name for this node.*/
	void setUiName(const StringID& uin){fprintf_s(mFile,"connectAttr \"");uin.write(mFile);fprintf_s(mFile,"\" \"%s.uin\";\n",mName.c_str());}
	/*User-customisable list of strings attributed to this node*/
	void setKeyWords(const string& kwds){if(kwds == "NULL") return; fprintf_s(mFile, "setAttr \".kwds\" -type \"string\" ");kwds.write(mFile);fprintf_s(mFile,";\n");}
	/*User-customisable list of strings attributed to this node*/
	void setKeyWords(const StringID& kwds){fprintf_s(mFile,"connectAttr \"");kwds.write(mFile);fprintf_s(mFile,"\" \"%s.kwds\";\n",mName.c_str());}
	/*Associated UI script.*/
	void setUiScript(const string& uis){if(uis == "NULL") return; fprintf_s(mFile, "setAttr \".uis\" -type \"string\" ");uis.write(mFile);fprintf_s(mFile,";\n");}
	/*Associated UI script.*/
	void setUiScript(const StringID& uis){fprintf_s(mFile,"connectAttr \"");uis.write(mFile);fprintf_s(mFile,"\" \"%s.uis\";\n",mName.c_str());}
	/*Unique Id representation of the node.*/
	void setUniqueID(const string& uid){if(uid == "NULL") return; fprintf_s(mFile, "setAttr \".uid\" -type \"string\" ");uid.write(mFile);fprintf_s(mFile,";\n");}
	/*Unique Id representation of the node.*/
	void setUniqueID(const StringID& uid){fprintf_s(mFile,"connectAttr \"");uid.write(mFile);fprintf_s(mFile,"\" \"%s.uid\";\n",mName.c_str());}
	/*Name of the facade node in the shared library*/
	StringID getSharedLibName(){char buffer[4096];sprintf_s (buffer, "%s.sln",mName.c_str());return (const char*)buffer;}
	/*Used to keep relationships with other nodes*/
	MessageID getConnection(){char buffer[4096];sprintf_s (buffer, "%s.c",mName.c_str());return (const char*)buffer;}
	/*User friendly name for this node.*/
	StringID getUiName(){char buffer[4096];sprintf_s (buffer, "%s.uin",mName.c_str());return (const char*)buffer;}
	/*User-customisable list of strings attributed to this node*/
	StringID getKeyWords(){char buffer[4096];sprintf_s (buffer, "%s.kwds",mName.c_str());return (const char*)buffer;}
	/*Associated UI script.*/
	StringID getUiScript(){char buffer[4096];sprintf_s (buffer, "%s.uis",mName.c_str());return (const char*)buffer;}
	/*Unique Id representation of the node.*/
	StringID getUniqueID(){char buffer[4096];sprintf_s (buffer, "%s.uid",mName.c_str());return (const char*)buffer;}
protected:
	Facade(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_FACADE_H__
