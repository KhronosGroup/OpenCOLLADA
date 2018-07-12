/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	CurveFromSubdivEdge():CurveFromSubdiv(){}
	CurveFromSubdivEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CurveFromSubdiv(file, name, parent, "curveFromSubdivEdge", shared, create){}
	virtual ~CurveFromSubdivEdge(){}

	void setEdgeIndexL(size_t eil_i,int eil)
	{
		if(eil == 0) return;
		fprintf(mFile,"\tsetAttr \".eil[%i]\" %i;\n", eil_i,eil);
	}
	void setEdgeIndexL(size_t eil_start,size_t eil_end,int* eil)
	{
		fprintf(mFile,"\tsetAttr \".eil[%i:%i]\" ", eil_start,eil_end);
		size_t size = (eil_end-eil_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",eil[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEdgeIndexL(size_t eil_start,size_t eil_end)const
	{
		fprintf(mFile,"\tsetAttr \".eil[%i:%i]\"",eil_start,eil_end);
	}
	void appendEdgeIndexL(int eil)const
	{
		fprintf(mFile," %i",eil);
	}
	void endEdgeIndexL()const
	{
		fprintf(mFile,";\n");
	}
	void setEdgeIndexR(size_t eir_i,int eir)
	{
		if(eir == 0) return;
		fprintf(mFile,"\tsetAttr \".eir[%i]\" %i;\n", eir_i,eir);
	}
	void setEdgeIndexR(size_t eir_start,size_t eir_end,int* eir)
	{
		fprintf(mFile,"\tsetAttr \".eir[%i:%i]\" ", eir_start,eir_end);
		size_t size = (eir_end-eir_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",eir[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEdgeIndexR(size_t eir_start,size_t eir_end)const
	{
		fprintf(mFile,"\tsetAttr \".eir[%i:%i]\"",eir_start,eir_end);
	}
	void appendEdgeIndexR(int eir)const
	{
		fprintf(mFile," %i",eir);
	}
	void endEdgeIndexR()const
	{
		fprintf(mFile,";\n");
	}
	void getEdgeIndexL(size_t eil_i)const
	{
		fprintf(mFile,"\"%s.eil[%i]\"",mName.c_str(),eil_i);
	}
	void getEdgeIndexL()const
	{

		fprintf(mFile,"\"%s.eil\"",mName.c_str());
	}
	void getEdgeIndexR(size_t eir_i)const
	{
		fprintf(mFile,"\"%s.eir[%i]\"",mName.c_str(),eir_i);
	}
	void getEdgeIndexR()const
	{

		fprintf(mFile,"\"%s.eir\"",mName.c_str());
	}
protected:
	CurveFromSubdivEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CurveFromSubdiv(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMSUBDIVEDGE_H__
