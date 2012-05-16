/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKRPSOLVER_H__
#define __MayaDM_IKRPSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMIkSCsolver.h"
namespace MayaDM
{
class IkRPsolver : public IkSCsolver
{
public:

	IkRPsolver():IkSCsolver(){}
	IkRPsolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:IkSCsolver(file, name, parent, "ikRPsolver", shared, create){}
	virtual ~IkRPsolver(){}

protected:
	IkRPsolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:IkSCsolver(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKRPSOLVER_H__
