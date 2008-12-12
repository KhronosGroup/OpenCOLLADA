/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SUBDMODIFIER_H__
#define __MayaDM_SUBDMODIFIER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMSubdBase.h"
namespace MayaDM
{
/*
A base node for the subdivision surface modifiers nodes.
 Subdivision surface modifier nodes apply topological, geometrical, or texture
 mapping transformations to existing subdiv surfaces.<p/>
*/
class SubdModifier : public SubdBase
{
public:
public:
	SubdModifier(FILE* file,const std::string& name,const std::string& parent=""):SubdBase(file, name, parent, "subdModifier"){}
	virtual ~SubdModifier(){}
	/*Input object : the object to modify.*/
	void setInSubdiv(const SubdivisionSurfaceID& is){fprintf_s(mFile,"connectAttr \"");is.write(mFile);fprintf_s(mFile,"\" \"%s.is\";\n",mName.c_str());}
	/*Cached output object (for interaction mode).*/
	void setCachedSubdiv(const SubdivisionSurfaceID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Input components that this node is to work on.*/
	void setInputComponents(const componentList& ics){fprintf_s(mFile, "setAttr \".ics\" -type \"componentList\" ");ics.write(mFile);fprintf_s(mFile,";\n");}
	/*Input components that this node is to work on.*/
	void setInputComponents(const ComponentListID& ics){fprintf_s(mFile,"connectAttr \"");ics.write(mFile);fprintf_s(mFile,"\" \"%s.ics\";\n",mName.c_str());}
	/*Input object : the object to modify.*/
	SubdivisionSurfaceID getInSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.is",mName.c_str());return (const char*)buffer;}
	/*Cached output object (for interaction mode).*/
	SubdivisionSurfaceID getCachedSubdiv(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Input components that this node is to work on.*/
	ComponentListID getInputComponents(){char buffer[4096];sprintf_s (buffer, "%s.ics",mName.c_str());return (const char*)buffer;}
protected:
	SubdModifier(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):SubdBase(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_SUBDMODIFIER_H__
