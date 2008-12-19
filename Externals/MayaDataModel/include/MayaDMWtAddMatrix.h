/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	WtAddMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "wtAddMatrix"){}
	virtual ~WtAddMatrix(){}
	void setWtMatrix(size_t i_i,const WtMatrix& i)
	{
		fprintf(mFile,"setAttr \".i[%i]\" ",i_i);
		i.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMatrixIn(size_t i_i,const matrix& m)
	{
		if(m == identity) return;
		fprintf(mFile,"setAttr \".i[%i].m\" -type \"matrix\" ",i_i);
		m.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWeightIn(size_t i_i,double w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"setAttr \".i[%i].w\" %f;\n", i_i,w);

	}
	void getWtMatrix(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i]\"",mName.c_str(),i_i);

	}
	void getMatrixIn(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].m\"",mName.c_str(),i_i);

	}
	void getWeightIn(size_t i_i)
	{
		fprintf(mFile,"\"%s.i[%i].w\"",mName.c_str(),i_i);

	}
	void getMatrixSum()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
protected:
	WtAddMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_WTADDMATRIX_H__
