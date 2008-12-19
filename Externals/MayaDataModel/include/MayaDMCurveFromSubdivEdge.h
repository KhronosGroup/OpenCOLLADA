/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_CURVEFROMSUBDIVEDGE_H__
#define __MayaDM_CURVEFROMSUBDIVEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMCurveFromSubdiv.h"
namespace MayaDM
{
class CurveFromSubdivEdge : public CurveFromSubdiv
{
public:
public:
	CurveFromSubdivEdge(FILE* file,const std::string& name,const std::string& parent=""):CurveFromSubdiv(file, name, parent, "curveFromSubdivEdge"){}
	virtual ~CurveFromSubdivEdge(){}
	void setEdgeIndexL(size_t eil_i,int eil)
	{
		if(eil == 0) return;
		fprintf(mFile,"setAttr \".eil[%i]\" %i;\n", eil_i,eil);

	}
	void setEdgeIndexR(size_t eir_i,int eir)
	{
		if(eir == 0) return;
		fprintf(mFile,"setAttr \".eir[%i]\" %i;\n", eir_i,eir);

	}
	void getEdgeIndexL(size_t eil_i)
	{
		fprintf(mFile,"\"%s.eil[%i]\"",mName.c_str(),eil_i);

	}
	void getEdgeIndexR(size_t eir_i)
	{
		fprintf(mFile,"\"%s.eir[%i]\"",mName.c_str(),eir_i);

	}
protected:
	CurveFromSubdivEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):CurveFromSubdiv(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIVEDGE_H__
