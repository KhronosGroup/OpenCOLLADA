/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	CurveFromMeshEdge():CurveFromMesh(){}
	CurveFromMeshEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:CurveFromMesh(file, name, parent, "curveFromMeshEdge", shared, create){}
	virtual ~CurveFromMeshEdge(){}

	void setEdgeIndex(size_t ei_i,int ei)
	{
		if(ei == 0) return;
		fprintf(mFile,"\tsetAttr \".ei[%i]\" %i;\n", ei_i,ei);
	}
	void setEdgeIndex(size_t ei_start,size_t ei_end,int* ei)
	{
		fprintf(mFile,"\tsetAttr \".ei[%i:%i]\" ", ei_start,ei_end);
		size_t size = (ei_end-ei_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ei[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEdgeIndex(size_t ei_start,size_t ei_end)const
	{
		fprintf(mFile,"\tsetAttr \".ei[%i:%i]\"",ei_start,ei_end);
	}
	void appendEdgeIndex(int ei)const
	{
		fprintf(mFile," %i",ei);
	}
	void endEdgeIndex()const
	{
		fprintf(mFile,";\n");
	}
	void getEdgeIndex(size_t ei_i)const
	{
		fprintf(mFile,"\"%s.ei[%i]\"",mName.c_str(),ei_i);
	}
	void getEdgeIndex()const
	{

		fprintf(mFile,"\"%s.ei\"",mName.c_str());
	}
protected:
	CurveFromMeshEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:CurveFromMesh(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_CURVEFROMMESHEDGE_H__
