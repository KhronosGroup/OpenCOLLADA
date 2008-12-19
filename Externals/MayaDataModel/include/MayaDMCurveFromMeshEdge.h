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
class CurveFromMeshEdge : public CurveFromMesh
{
public:
public:
	CurveFromMeshEdge(FILE* file,const std::string& name,const std::string& parent=""):CurveFromMesh(file, name, parent, "curveFromMeshEdge"){}
	virtual ~CurveFromMeshEdge(){}
	void setEdgeIndex(size_t ei_i,int ei)
	{
		if(ei == 0) return;
		fprintf(mFile,"setAttr \".ei[%i]\" %i;\n", ei_i,ei);

	}
	void getEdgeIndex(size_t ei_i)
	{
		fprintf(mFile,"\"%s.ei[%i]\"",mName.c_str(),ei_i);

	}
protected:
	CurveFromMeshEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromMesh(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMMESHEDGE_H__
