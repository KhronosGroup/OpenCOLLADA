/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_PASSMATRIX_H__
#define __MayaDM_PASSMATRIX_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
/*
<p><pre>        Multiply a matrix by a constant without caching anything
</pre></p>
*/
class PassMatrix : public DependNode
{
public:
public:
	PassMatrix(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "passMatrix"){}
	virtual ~PassMatrix(){}
	/*Matrix to be passed through*/
	void setInMatrix(const matrix& i){if(i == identity) return; fprintf_s(mFile, "setAttr \".i\" -type \"matrix\" ");i.write(mFile);fprintf_s(mFile,";\n");}
	/*Matrix to be passed through*/
	void setInMatrix(const MatrixID& i){fprintf_s(mFile,"connectAttr \"");i.write(mFile);fprintf_s(mFile,"\" \"%s.i\";\n",mName.c_str());}
	/*Scale factor on input matrix*/
	void setInScale(double s){if(s == 2.0) return; fprintf_s(mFile, "setAttr \".s\" %f;\n", s);}
	/*Scale factor on input matrix*/
	void setInScale(const DoubleID& s){fprintf_s(mFile,"connectAttr \"");s.write(mFile);fprintf_s(mFile,"\" \"%s.s\";\n",mName.c_str());}
	/*Scaled matrix that has been passed through*/
	void setOutMatrix(const MatrixID& o){fprintf_s(mFile,"connectAttr \"");o.write(mFile);fprintf_s(mFile,"\" \"%s.o\";\n",mName.c_str());}
	/*Matrix to be passed through*/
	MatrixID getInMatrix(){char buffer[4096];sprintf_s (buffer, "%s.i",mName.c_str());return (const char*)buffer;}
	/*Scale factor on input matrix*/
	DoubleID getInScale(){char buffer[4096];sprintf_s (buffer, "%s.s",mName.c_str());return (const char*)buffer;}
	/*Scaled matrix that has been passed through*/
	MatrixID getOutMatrix(){char buffer[4096];sprintf_s (buffer, "%s.o",mName.c_str());return (const char*)buffer;}
protected:
	PassMatrix(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_PASSMATRIX_H__
