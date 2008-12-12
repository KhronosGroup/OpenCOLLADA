/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREASE_H__
#define __MayaDM_POLYCREASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
/*
<p><pre> Selectively assigns weights to edges and vertices.

</pre></p>
*/
class PolyCrease : public PolyModifierWorld
{
public:
public:
	PolyCrease(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierWorld(file, name, parent, "polyCrease"){}
	virtual ~PolyCrease(){}
	/*Crease values for the edges*/
	void setCrease(size_t cr_i,float cr){if(cr == -1.0) return; fprintf_s(mFile, "setAttr \".cr[%i]\" %f;\n", cr_i,cr);}
	/*Crease values for the edges*/
	void setCrease(size_t cr_i,const FloatID& cr){fprintf_s(mFile,"connectAttr \"");cr.write(mFile);fprintf_s(mFile,"\" \"%s.cr[%i]\";\n",mName.c_str(),cr_i);}
	/*Input vertex components that this node is to work on.*/
	void setInputVertexComponents(const componentList& ivc){fprintf_s(mFile, "setAttr \".ivc\" -type \"componentList\" ");ivc.write(mFile);fprintf_s(mFile,";\n");}
	/*Input vertex components that this node is to work on.*/
	void setInputVertexComponents(const ComponentListID& ivc){fprintf_s(mFile,"connectAttr \"");ivc.write(mFile);fprintf_s(mFile,"\" \"%s.ivc\";\n",mName.c_str());}
	/*Crease values for the vertices*/
	void setCreaseVertex(size_t crv_i,float crv){if(crv == -1.0) return; fprintf_s(mFile, "setAttr \".crv[%i]\" %f;\n", crv_i,crv);}
	/*Crease values for the vertices*/
	void setCreaseVertex(size_t crv_i,const FloatID& crv){fprintf_s(mFile,"connectAttr \"");crv.write(mFile);fprintf_s(mFile,"\" \"%s.crv[%i]\";\n",mName.c_str(),crv_i);}
	/*Crease values for the edges*/
	const FloatID& getCrease(size_t cr_i){char buffer[4096];sprintf_s (buffer, "%s.cr[%i]",mName.c_str(),cr_i);return (const char*)buffer;}
	/*Input vertex components that this node is to work on.*/
	ComponentListID getInputVertexComponents(){char buffer[4096];sprintf_s (buffer, "%s.ivc",mName.c_str());return (const char*)buffer;}
	/*Crease values for the vertices*/
	const FloatID& getCreaseVertex(size_t crv_i){char buffer[4096];sprintf_s (buffer, "%s.crv[%i]",mName.c_str(),crv_i);return (const char*)buffer;}
protected:
	PolyCrease(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierWorld(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREASE_H__
