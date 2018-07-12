/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKSYSTEM_H__
#define __MayaDM_IKSYSTEM_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class IkSystem : public DependNode
{
public:
public:

	IkSystem():DependNode(){}
	IkSystem(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "ikSystem", shared, create){}
	virtual ~IkSystem(){}

	void setGlobalSnap(bool gsn)
	{
		if(gsn == true) return;
		fprintf(mFile,"\tsetAttr \".gsn\" %i;\n", gsn);
	}
	void setGlobalSolve(bool gsv)
	{
		if(gsv == true) return;
		fprintf(mFile,"\tsetAttr \".gsv\" %i;\n", gsv);
	}
	void getGlobalSnap()const
	{
		fprintf(mFile,"\"%s.gsn\"",mName.c_str());
	}
	void getGlobalSolve()const
	{
		fprintf(mFile,"\"%s.gsv\"",mName.c_str());
	}
	void getIkSolver(size_t sol_i)const
	{
		fprintf(mFile,"\"%s.sol[%i]\"",mName.c_str(),sol_i);
	}
	void getIkSolver()const
	{

		fprintf(mFile,"\"%s.sol\"",mName.c_str());
	}
protected:
	IkSystem(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKSYSTEM_H__
