/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WTADDMATRIX_H__
#define __MayaDM_WTADDMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class WtAddMatrix : public DependNode
{
public:
	struct WtMatrix{
		matrix matrixIn;
		double weightIn;
		void write(FILE* file) const
		{
			matrixIn.write(file);
			fprintf(file, " ");
			fprintf(file,"%f", weightIn);
		}
	};
public:

	WtAddMatrix():DependNode(){}
	WtAddMatrix(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "wtAddMatrix", shared, create){}
	virtual ~WtAddMatrix(){}

	void setWtMatrix(size_t i_i,const WtMatrix& i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i]\" ",i_i);
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWtMatrix(size_t i_start,size_t i_end,WtMatrix* i_)
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\" ", i_start,i_end);
		size_t size = (i_end-i_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			i_[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWtMatrix(size_t i_start,size_t i_end)const
	{
		fprintf(mFile,"\tsetAttr \".i[%i:%i]\"",i_start,i_end);
		fprintf(mFile," -type \"WtMatrix\" ");
	}
	void appendWtMatrix(const WtMatrix& i)const
	{
		fprintf(mFile," ");
		i.write(mFile);
	}
	void endWtMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setMatrixIn(size_t i_i,const matrix& m)
	{
		if(m == identity) return;
		fprintf(mFile,"\tsetAttr \".i[%i].m\" -type \"matrix\" ",i_i);
		m.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWeightIn(size_t i_i,double w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"\tsetAttr \".i[%i].w\" %f;\n", i_i,w);
	}
	void getWtMatrix(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);
	}
	void getWtMatrix()const
	{

		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getMatrixIn(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].m\"",mName.c_str(),i_i);
	}
	void getMatrixIn()const
	{

		fprintf(mFile,"\"%s.i.m\"",mName.c_str());
	}
	void getWeightIn(size_t i_i)const
	{
		fprintf(mFile,"\"%s.i[%i].w\"",mName.c_str(),i_i);
	}
	void getWeightIn()const
	{

		fprintf(mFile,"\"%s.i.w\"",mName.c_str());
	}
	void getMatrixSum()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
protected:
	WtAddMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_WTADDMATRIX_H__
