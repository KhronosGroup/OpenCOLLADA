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
/*
<p><pre>    Add a weighted list of matrices together.
</pre></p>
*/
class WtAddMatrix : public DependNode
{
public:
	/*List of matrices to be added*/
	struct WtMatrix{
		matrix matrixIn;
		double weightIn;
		void write(FILE* file) const
		{
			matrixIn.write(file);
			fprintf_s(file, " ");
			fprintf_s(file,"%f", weightIn);
		}
	};
public:
	WtAddMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "wtAddMatrix"){}
	virtual ~WtAddMatrix(){}
	/*List of matrices to be added*/
	void setWtMatrix(size_t i_i,const WtMatrix& i){fprintf_s(mFile, "setAttr \".i[%i]\" ",i_i);i.write(mFile);fprintf_s(mFile,";\n");}
	/*List of matrices to be added*/
	void setWtMatrix(size_t i_i,const WtMatrixID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*Single matrix to be in the sum*/
	void setMatrixIn(size_t i_i,const matrix& m){if(m == identity) return; fprintf_s(mFile, "setAttr \".i[%i].m\" -type \"matrix\" ",i_i);m.write(mFile);fprintf_s(mFile,";\n");}
	/*Single matrix to be in the sum*/
	void setMatrixIn(size_t i_i,const MatrixID& m){fprintf_s(mFile,"connectAttr \"");m.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].m\";\n",mName.c_str(),i_i);}
	/*Weight for this matrix*/
	void setWeightIn(size_t i_i,double w){if(w == 0.0) return; fprintf_s(mFile, "setAttr \".i[%i].w\" %f;\n", i_i,w);}
	/*Weight for this matrix*/
	void setWeightIn(size_t i_i,const DoubleID& w){fprintf_s(mFile,"connectAttr \"");w.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i].w\";\n",mName.c_str(),i_i);}
	/*The weighted sum of all input matrices*/
	void setMatrixSum(const MatrixID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*List of matrices to be added*/
	const WtMatrixID& getWtMatrix(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*Single matrix to be in the sum*/
	const MatrixID& getMatrixIn(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].m",mName.c_str(),i_i);return (const char*)buffer;}
	/*Weight for this matrix*/
	const DoubleID& getWeightIn(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i].w",mName.c_str(),i_i);return (const char*)buffer;}
	/*The weighted sum of all input matrices*/
	MatrixID getMatrixSum(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	WtAddMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_WTADDMATRIX_H__
