/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMODIFIER_H__
#define __MayaDM_POLYMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyBase.h"
namespace MayaDM
{
/*
A base node for the polygonal modifiers nodes.
 Polygonal modifier nodes apply topological, geometrical, or texture
 mapping transformations to existing polygons.<p/>
*/
class PolyModifier : public PolyBase
{
public:
public:
	PolyModifier(FILE* file,const std::string& name,const std::string& parent=""):PolyBase(file, name, parent, "polyModifier"){}
	virtual ~PolyModifier(){}
	/*Input object : the object to modify. A mesh is another DG node.*/
	void setInputPolymesh(const MeshID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*
	Attribute to specify if the old poly architecture needs to be used
	for the evaluation of this node. SHOULD NOT BE SET OR MODIFIED
	BY THE USER!!
	*/
	void setUseOldPolyArchitecture(bool uopa){if(uopa == false) return; fprintf_s(mFile, "setAttr \".uopa\" %i;\n", uopa);}
	/*Input components that this node is to work on.*/
	void setInputComponents(const componentList& ics){fprintf_s(mFile, "setAttr \".ics\" -type \"componentList\" ");ics.write(mFile);fprintf_s(mFile,";\n");}
	/*Input components that this node is to work on.*/
	void setInputComponents(const ComponentListID& ics){fprintf_s(mFile,"connectAttr \"");ics.write(mFile);fprintf_s(mFile,"\" \"%s.ics\";\n",mName.c_str());}
	/*Input object : the object to modify. A mesh is another DG node.*/
	MeshID getInputPolymesh(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*Input components that this node is to work on.*/
	ComponentListID getInputComponents(){char buffer[4096];sprintf_s (buffer, "%s.ics",mName.c_str());return (const char*)buffer;}
protected:
	PolyModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYMODIFIER_H__
