/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NONLINEAR_H__
#define __MayaDM_NONLINEAR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
/*
The nonLinear deformer node is used to
 deform components according to an arbitrary deformer function.
 The deformation function and its required parameters reside on a deformFunc
 node that should be connected to the nonLinear through the deformerData
 attribute. Examples of deformFunc nodes are deformBend, deformSine,
 deformSquash, deformWave, etc.
 <p/>
*/
class NonLinear : public GeometryFilter
{
public:
public:
	NonLinear(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "nonLinear"){}
	virtual ~NonLinear(){}
	/*
	The transformation matrix which defines the point about which
	the deformation takes place
	*/
	void setMatrix(const matrix& ma){if(ma == identity) return; fprintf_s(mFile, "setAttr \".ma\" -type \"matrix\" ");ma.write(mFile);fprintf_s(mFile,";\n");}
	/*
	The transformation matrix which defines the point about which
	the deformation takes place
	*/
	void setMatrix(const MatrixID& ma){fprintf_s(mFile,"connectAttr \"");ma.write(mFile);fprintf_s(mFile,"\" \"%s.ma\";\n",mName.c_str());}
	/*
	The transformation matrix which defines the point about which
	the deformation takes place
	*/
	MatrixID getMatrix(){char buffer[4096];sprintf_s (buffer, "%s.ma",mName.c_str());return (const char*)buffer;}
protected:
	NonLinear(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_NONLINEAR_H__
