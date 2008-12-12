/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKPASOLVER_H__
#define __MayaDM_IKPASOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
/*
ikPAsolver works the same as ikRPsolver does except that it may
 produce different solution (assignment of values to all the
 rotation attributes at its disposal).
 <p/>
*/
class IkPASolver : public IkSolver
{
public:
public:
	IkPASolver(FILE* file,const std::string& name,const std::string& parent=""):IkSolver(file, name, parent, "ikPASolver"){}
	virtual ~IkPASolver(){}
protected:
	IkPASolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSolver(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_IKPASOLVER_H__
