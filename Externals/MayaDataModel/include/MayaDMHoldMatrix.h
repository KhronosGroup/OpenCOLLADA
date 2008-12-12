/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HOLDMATRIX_H__
#define __MayaDM_HOLDMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>        Cache a matrix.
</pre></p>
*/
class HoldMatrix : public DependNode
{
public:
public:
	HoldMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "holdMatrix"){}
	virtual ~HoldMatrix(){}
	/*Matrix to hold in the cache*/
	void setInMatrix(const matrix& i){if(i == identity) return; fprintf_s(mFile, "setAttr \".i\" -type \"matrix\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*Matrix to hold in the cache*/
	void setInMatrix(const MatrixID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Matrix in the cache*/
	void setOutMatrix(const matrix& o){if(o == identity) return; fprintf_s(mFile, "setAttr \".o\" -type \"matrix\" ");o.write(mFile);fprintf_s(mFile,";\n");}
	/*Matrix in the cache*/
	void setOutMatrix(const MatrixID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Matrix to hold in the cache*/
	MatrixID getInMatrix(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Matrix in the cache*/
	MatrixID getOutMatrix(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	HoldMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HOLDMATRIX_H__
