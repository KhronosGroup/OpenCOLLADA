/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMMESH_H__
#define __MayaDM_CURVEFROMMESH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
A curveFromMesh node is the basis node for
 curveFromMeshIso, curveFromMeshBnd, and curveFromMeshCos.
 This node describes a NURBS curve derived from a mesh edge
 or a face boundary.  The resulting NURBS curve is the
 attribute "outputCurve" and its extent can be controlled by the
 minValue and maxValue parameters.
*/
class CurveFromMesh : public DependNode
{
public:
public:
	CurveFromMesh(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "curveFromMesh"){}
	virtual ~CurveFromMesh(){}
	/*The input mesh*/
	void setInputMesh(const MeshID& im){fprintf_s(mFile,"connectAttr \"");im.write(mFile);fprintf_s(mFile,"\" \"%s.im\";\n",mName.c_str());}
	/*The output curve*/
	void setOutputCurve(const NurbsCurveID& oc){fprintf_s(mFile,"connectAttr \"");oc.write(mFile);fprintf_s(mFile,"\" \"%s.oc\";\n",mName.c_str());}
	/*The input mesh*/
	MeshID getInputMesh(){char buffer[4096];sprintf_s (buffer, "%s.im",mName.c_str());return (const char*)buffer;}
	/*The output curve*/
	NurbsCurveID getOutputCurve(){char buffer[4096];sprintf_s (buffer, "%s.oc",mName.c_str());return (const char*)buffer;}
protected:
	CurveFromMesh(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMMESH_H__
