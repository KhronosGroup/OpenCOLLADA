/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSOLVER_H__
#define __MayaDM_IKSOLVER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class IkSolver : public DependNode
{
public:
public:

	IkSolver():DependNode(){}
	IkSolver(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "ikSolver", shared, create){}
	virtual ~IkSolver(){}

	void setMaxIterations(int mxi)
	{
		if(mxi == 2147483647) return;
		fprintf(mFile,"\tsetAttr \".mxi\" %i;\n", mxi);
	}
	void setTolerance(double tol)
	{
		if(tol == 0.00001) return;
		fprintf(mFile,"\tsetAttr \".tol\" %f;\n", tol);
	}
protected:
	IkSolver(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKSOLVER_H__
