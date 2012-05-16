/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKMCSOLVER_H__
#define __MayaDM_IKMCSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
class IkMCsolver : public IkSolver
{
public:

	IkMCsolver():IkSolver(){}
	IkMCsolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:IkSolver(file, name, parent, "ikMCsolver", shared, create){}
	virtual ~IkMCsolver(){}

protected:
	IkMCsolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:IkSolver(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKMCSOLVER_H__
