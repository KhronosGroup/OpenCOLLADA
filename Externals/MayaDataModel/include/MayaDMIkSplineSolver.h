/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSPLINESOLVER_H__
#define __MayaDM_IKSPLINESOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
/*
The objective of the ikSplineSolver is to solve for joint
 rotations such that the joints lie along the ikSplineHandle's curve.

 The ikSplineSolver works on one ikSplineHandle at a time.
 Therefore, the weight attribute of the ikSplineHandle
 is ignored by this solver. <p/>

 The ikSplineSolver is history independent, meaning that
 it will produce the same solution after the ikSplineHandle's curve
 is moved or rotated away, and put back again. <p/>
*/
class IkSplineSolver : public IkSolver
{
public:
public:
	IkSplineSolver(FILE* file,const std::string& name,const std::string& parent=""):IkSolver(file, name, parent, "ikSplineSolver"){}
	virtual ~IkSplineSolver(){}
protected:
	IkSplineSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSolver(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKSPLINESOLVER_H__
