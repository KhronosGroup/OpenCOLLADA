/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	IkPASolver():IkSolver(){}
	IkPASolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:IkSolver(file, name, parent, "ikPASolver", shared, create){}
	virtual ~IkPASolver(){}

protected:
	IkPASolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:IkSolver(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKPASOLVER_H__
