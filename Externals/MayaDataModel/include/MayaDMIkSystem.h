/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	IkSystem(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "ikSystem"){}
	virtual ~IkSystem(){}
	void setGlobalSnap(bool gsn)
	{
		if(gsn == true) return;
		fprintf(mFile,"setAttr \".gsn\" %i;\n", gsn);

	}
	void setGlobalSolve(bool gsv)
	{
		if(gsv == true) return;
		fprintf(mFile,"setAttr \".gsv\" %i;\n", gsv);

	}
	void getGlobalSnap()
	{
		fprintf(mFile,"\"%s.gsn\"",mName.c_str());

	}
	void getGlobalSolve()
	{
		fprintf(mFile,"\"%s.gsv\"",mName.c_str());

	}
protected:
	IkSystem(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKSYSTEM_H__
