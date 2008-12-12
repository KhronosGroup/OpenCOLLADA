/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSEPARATE_H__
#define __MayaDM_POLYSEPARATE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
This node creates a new poly object for each shell in the inputPoly.
 (A shell is a section of the mesh that is not edge-connected to
 the rest of the mesh.)<p/>
*/
class PolySeparate : public DependNode
{
public:
public:
	PolySeparate(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polySeparate"){}
	virtual ~PolySeparate(){}
	/*
	Attribute to specify if the old poly architecture needs to be used
	for the evaluation of this node. SHOULD NOT BE SET OR MODIFIED
	BY THE USER!!
	*/
	void setUseOldPolyArchitecture(bool uopa){if(uopa == false) return; fprintf_s(mFile, "setAttr \".uopa\" %i;\n", uopa);}
	/*The input polygon.*/
	void setInputPoly(const MeshID& ip){fprintf_s(mFile,"connectAttr \"");ip.write(mFile);fprintf_s(mFile,"\" \"%s.ip\";\n",mName.c_str());}
	/*
	Shell count : the number of shells in the input polygon
	at the first computation of the node.
	*/
	void setIcount(int ic){if(ic == -1) return; fprintf_s(mFile, "setAttr \".ic\" %i;\n", ic);}
	/*
	Shell count : the number of shells in the input polygon
	at the first computation of the node.
	*/
	void setIcount(const IntID& ic){fprintf_s(mFile,"connectAttr \"");ic.write(mFile);fprintf_s(mFile,"\" \"%s.ic\";\n",mName.c_str());}
	/*Specific shells to do the operation on. Test attribute*/
	void setRemShells(const intArray& rs){if(rs.size == 0) return; fprintf_s(mFile, "setAttr \".rs\" -type \"intArray\" ");rs.write(mFile);fprintf_s(mFile,";\n");}
	/*Specific shells to do the operation on. Test attribute*/
	void setRemShells(const IntArrayID& rs){fprintf_s(mFile,"connectAttr \"");rs.write(mFile);fprintf_s(mFile,"\" \"%s.rs\";\n",mName.c_str());}
	/*Output objects.*/
	void setOutput(size_t out_i,const MeshID& out){fprintf_s(mFile,"connectAttr \"");out.write(mFile);fprintf_s(mFile,"\" \"%s.out[%i]\";\n",mName.c_str(),out_i);}
	/*The input polygon.*/
	MeshID getInputPoly(){char buffer[4096];sprintf_s (buffer, "%s.ip",mName.c_str());return (const char*)buffer;}
	/*
	Shell count : the number of shells in the input polygon
	at the first computation of the node.
	*/
	IntID getIcount(){char buffer[4096];sprintf_s (buffer, "%s.ic",mName.c_str());return (const char*)buffer;}
	/*Specific shells to do the operation on. Test attribute*/
	IntArrayID getRemShells(){char buffer[4096];sprintf_s (buffer, "%s.rs",mName.c_str());return (const char*)buffer;}
	/*Output objects.*/
	const MeshID& getOutput(size_t out_i){char buffer[4096];sprintf_s (buffer, "%s.out[%i]",mName.c_str(),out_i);return (const char*)buffer;}
protected:
	PolySeparate(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_POLYSEPARATE_H__
