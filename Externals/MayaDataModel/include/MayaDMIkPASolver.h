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
class IkPASolver : public IkSolver
{
public:
	IkPASolver(FILE* file,const std::string& name,const std::string& parent=""):IkSolver(file, name, parent, "ikPASolver"){}
	virtual ~IkPASolver(){}
protected:
	IkPASolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):IkSolver(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKPASOLVER_H__
