/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CHARACTERMAP_H__
#define __MayaDM_CHARACTERMAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node is used to store the correlation between the attributes in
 two or more characters.
*/
class CharacterMap : public DependNode
{
public:
public:
	CharacterMap(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "characterMap"){}
	virtual ~CharacterMap(){}
	/*Characters or clipLibraries with map data*/
	void setMember(size_t m_i,const MessageID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.m[%i]\";\n",mName.c_str(),m_i);}
	/*Stores the map index for the members*/
	void setMemberIndex(size_t mi_i,const intArray& mi){if(mi.size == 0) return; fprintf_s(mFile, "setAttr \".mi[%i]\" -type \"intArray\" ",mi_i);mi.write(mFile);fprintf_s(mFile,";\n");}
	/*Characters or clipLibraries with map data*/
	const MessageID& getMember(size_t m_i){char buffer[4096];sprintf_s (buffer, "%s.m[%i]",mName.c_str(),m_i);return (const char*)buffer;}
protected:
	CharacterMap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CHARACTERMAP_H__
