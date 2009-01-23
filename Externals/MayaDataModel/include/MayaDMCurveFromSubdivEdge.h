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
	void setEdgeIndexL(size_t eil_start,size_t eil_end,int* eil)
	{
		fprintf(mFile,"setAttr \".eil[%i:%i]\" ", eil_start,eil_end);
		size_t size = (eil_end-eil_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",eil[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEdgeIndexL(size_t eil_start,size_t eil_end)
	{
		fprintf(mFile,"setAttr \".eil[%i:%i]\"",eil_start,eil_end);

	}
	void appendEdgeIndexL(int eil)
	{
		fprintf(mFile," %i",eil);

	}
	void endEdgeIndexL()
	{
		fprintf(mFile,";\n");

	}
	void setEdgeIndexR(size_t eir_i,int eir)
	{
		if(eir == 0) return;
		fprintf(mFile,"setAttr \".eir[%i]\" %i;\n", eir_i,eir);

	}
	void setEdgeIndexR(size_t eir_start,size_t eir_end,int* eir)
	{
		fprintf(mFile,"setAttr \".eir[%i:%i]\" ", eir_start,eir_end);
		size_t size = (eir_end-eir_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",eir[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startEdgeIndexR(size_t eir_start,size_t eir_end)
	{
		fprintf(mFile,"setAttr \".eir[%i:%i]\"",eir_start,eir_end);

	}
	void appendEdgeIndexR(int eir)
	{
		fprintf(mFile," %i",eir);

	}
	void endEdgeIndexR()
	{
		fprintf(mFile,";\n");

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
