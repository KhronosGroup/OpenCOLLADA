/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYFLIPEDGE_H__
#define __MayaDM_POLYFLIPEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
/*
<p><pre>    This node handles flipping of the edges of the quad of a polyMesh
    The node re-assigns the start and end Vertex Ids of the selected
  edge to the other two corners of the quad containing the edge.

    This node is created when edges are selected and flipped through
    polyFlipEdge command

</pre></p>
*/
class PolyFlipEdge : public PolyModifier
{
public:
public:
	PolyFlipEdge(FILE* file,const std::string& name,const std::string& parent=""):PolyModifier(file, name, parent, "polyFlipEdge"){}
	virtual ~PolyFlipEdge(){}
	/*Edge List to be flipped in the geometry data flowing through the node*/
	void setEdge(const componentList& e){fprintf_s(mFile, "setAttr \".e\" -type \"componentList\" ");e.write(mFile);fprintf_s(mFile,";\n");}
	/*Edge List to be flipped in the geometry data flowing through the node*/
	void setEdge(const ComponentListID& e){fprintf_s(mFile,"connectAttr \"");e.write(mFile);fprintf_s(mFile,"\" \"%s.e\";\n",mName.c_str());}
	/*Edge List to be flipped in the geometry data flowing through the node*/
	ComponentListID getEdge(){char buffer[4096];sprintf_s (buffer, "%s.e",mName.c_str());return (const char*)buffer;}
protected:
	PolyFlipEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifier(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYFLIPEDGE_H__
