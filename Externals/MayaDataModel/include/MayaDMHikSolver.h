/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
class HikSolver : public IkSolver
{
public:

	HikSolver():IkSolver(){}
	HikSolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:IkSolver(file, name, parent, "hikSolver", shared, create){}
	virtual ~HikSolver(){}

protected:
	HikSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:IkSolver(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_HIKSOLVER_H__
