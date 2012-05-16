/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSCSOLVER_H__
#define __MayaDM_IKSCSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSolver.h"
namespace MayaDM
{
class IkSCsolver : public IkSolver
{
public:

	IkSCsolver():IkSolver(){}
	IkSCsolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:IkSolver(file, name, parent, "ikSCsolver", shared, create){}
	virtual ~IkSCsolver(){}

protected:
	IkSCsolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:IkSolver(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKSCSOLVER_H__
