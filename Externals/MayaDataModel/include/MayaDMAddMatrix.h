/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ADDMATRIX_H__
#define __MayaDM_ADDMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>    Add a list of matrices together.
</pre></p>
*/
class AddMatrix : public DependNode
{
public:
public:
	AddMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "addMatrix"){}
	virtual ~AddMatrix(){}
	/*List of matrices to be added*/
	void setMatrixIn(size_t i_i,const matrix& i){if(i == identity) return; fprintf_s(mFile, "setAttr \".i[%i]\" -type \"matrix\" ",i_i);i.write(mFile);fprintf_s(mFile,";\n");}
	/*List of matrices to be added*/
	void setMatrixIn(size_t i_i,const MatrixID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i[%i]\";\n",mName.c_str(),i_i);}
	/*The sum of all input matrices*/
	void setMatrixSum(const MatrixID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*List of matrices to be added*/
	const MatrixID& getMatrixIn(size_t i_i){char buffer[4096];sprintf_s (buffer, "%s.i[%i]",mName.c_str(),i_i);return (const char*)buffer;}
	/*The sum of all input matrices*/
	MatrixID getMatrixSum(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	AddMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_ADDMATRIX_H__
