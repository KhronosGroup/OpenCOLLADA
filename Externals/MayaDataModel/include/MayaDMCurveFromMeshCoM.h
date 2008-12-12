/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMMESHCOM_H__
#define __MayaDM_CURVEFROMMESHCOM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromMesh.h"
namespace MayaDM
{
/*
This node defines a NURBS curve that is derived from a curve
 on a PolyMesh.  This curve must be a 2-dimensional curve in the
 underworld of the surface.
 The curve is specified by the input attribute, "curveOnMesh".
*/
class CurveFromMeshCoM : public CurveFromMesh
{
public:
public:
	CurveFromMeshCoM(FILE* file,const std::string& name,const std::string& parent=""):CurveFromMesh(file, name, parent, "curveFromMeshCoM"){}
	virtual ~CurveFromMeshCoM(){}
	/*The input curve-on-mesh.  This curve is a 2D curve.*/
	void setCurveOnMesh(const NurbsCurveID& com){fprintf_s(mFile,"connectAttr \"");com.write(mFile);fprintf_s(mFile,"\" \"%s.com\";\n",mName.c_str());}
	/*The input curve-on-mesh.  This curve is a 2D curve.*/
	NurbsCurveID getCurveOnMesh(){char buffer[4096];sprintf_s (buffer, "%s.com",mName.c_str());return (const char*)buffer;}
protected:
	CurveFromMeshCoM(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromMesh(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMMESHCOM_H__
