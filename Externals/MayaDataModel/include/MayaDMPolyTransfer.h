/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTRANSFER_H__
#define __MayaDM_POLYTRANSFER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
This node creates a new poly
 by applying a boolean operation on the input polys.
 Unlike the parent node polyUnite, this node only
 functions with exactly two input polys.<p/>
*/
class PolyTransfer : public PolyModifier
{
public:
public:
	PolyTransfer(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyTransfer"){}
	virtual ~PolyTransfer(){}
	/*Second input object : the object to extract some fields from.*/
	void setOtherPoly(const mesh& op){fprintf_s(mFile, "setAttr \".op\" -type \"mesh\" ");op.write(mFile);fprintf_s(mFile,";\n");}
	/*Second input object : the object to extract some fields from.*/
	void setOtherPoly(const MeshID& op){fprintf_s(mFile,"connectAttr \"");op.write(mFile);fprintf_s(mFile,"\" \"%s.op\";\n",mName.c_str());}
	/*Import vertices from second object*/
	void setVertices(bool v){if(v == false) return; fprintf_s(mFile, "setAttr \".v\" %i;\n", v);}
	/*Import vertices from second object*/
	void setVertices(const BoolID& v){fprintf_s(mFile,"connectAttr \"");v.write(mFile);fprintf_s(mFile,"\" \"%s.v\";\n",mName.c_str());}
	/*Import UV sets from second object*/
	void setUvSets(bool uv){if(uv == true) return; fprintf_s(mFile, "setAttr \".uv\" %i;\n", uv);}
	/*Import UV sets from second object*/
	void setUvSets(const BoolID& uv){fprintf_s(mFile,"connectAttr \"");uv.write(mFile);fprintf_s(mFile,"\" \"%s.uv\";\n",mName.c_str());}
	/*Import color per vertex from second object*/
	void setVertexColor(bool vc){if(vc == false) return; fprintf_s(mFile, "setAttr \".vc\" %i;\n", vc);}
	/*Import color per vertex from second object*/
	void setVertexColor(const BoolID& vc){fprintf_s(mFile,"connectAttr \"");vc.write(mFile);fprintf_s(mFile,"\" \"%s.vc\";\n",mName.c_str());}
	/*Second input object : the object to extract some fields from.*/
	MeshID getOtherPoly(){char buffer[4096];sprintf_s (buffer, "%s.op",mName.c_str());return (const char*)buffer;}
	/*Import vertices from second object*/
	BoolID getVertices(){char buffer[4096];sprintf_s (buffer, "%s.v",mName.c_str());return (const char*)buffer;}
	/*Import UV sets from second object*/
	BoolID getUvSets(){char buffer[4096];sprintf_s (buffer, "%s.uv",mName.c_str());return (const char*)buffer;}
	/*Import color per vertex from second object*/
	BoolID getVertexColor(){char buffer[4096];sprintf_s (buffer, "%s.vc",mName.c_str());return (const char*)buffer;}
protected:
	PolyTransfer(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYTRANSFER_H__
