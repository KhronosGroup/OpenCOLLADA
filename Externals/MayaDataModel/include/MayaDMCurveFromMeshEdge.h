/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMMESHEDGE_H__
#define __MayaDM_CURVEFROMMESHEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromMesh.h"
namespace MayaDM
{
/*This node defines a NURBS curve that is derived from a mesh edge.*/
class CurveFromMeshEdge : public CurveFromMesh
{
public:
public:
	CurveFromMeshEdge(FILE* file,const std::string& name,const std::string& parent=""):CurveFromMesh(file, name, parent, "curveFromMeshEdge"){}
	virtual ~CurveFromMeshEdge(){}
	/*Index for the edge*/
	void setEdgeIndex(size_t ei_i,int ei){if(ei == 0) return; fprintf_s(mFile, "setAttr \".ei[%i]\" %i;\n", ei_i,ei);}
	/*Index for the edge*/
	void setEdgeIndex(size_t ei_i,const IntID& ei){fprintf_s(mFile,"connectAttr \"");ei.write(mFile);fprintf_s(mFile,"\" \"%s.ei[%i]\";\n",mName.c_str(),ei_i);}
	/*Index for the edge*/
	const IntID& getEdgeIndex(size_t ei_i){char buffer[4096];sprintf_s (buffer, "%s.ei[%i]",mName.c_str(),ei_i);return (const char*)buffer;}
protected:
	CurveFromMeshEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromMesh(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMMESHEDGE_H__
