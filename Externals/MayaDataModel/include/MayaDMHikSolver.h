/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_HIKSOLVER_H__
#define __MayaDM_HIKSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
/*
The hikSolver is the Human IK solver also used by Alias MotionBuilder.
 Unlike the other Maya IK solvers such as the single-chain solver, the
 hikSolver can only be used with Human IK control rigs made up of
 hikEffectors on a characterized skeleton.
 <p/>
*/
class HikSolver : public IkSolver
{
public:
public:
	HikSolver(FILE* file,const std::string& name,const std::string& parent=""):IkSolver(file, name, parent, "hikSolver"){}
	virtual ~HikSolver(){}
protected:
	HikSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSolver(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_HIKSOLVER_H__
