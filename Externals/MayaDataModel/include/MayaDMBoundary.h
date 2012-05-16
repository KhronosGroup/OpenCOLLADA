/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_BOUNDARY_H__
#define __MayaDM_BOUNDARY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMBoundaryBase.h"
namespace MayaDM
{
class Boundary : public BoundaryBase
{
public:
public:

	Boundary():BoundaryBase(){}
	Boundary(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:BoundaryBase(file, name, parent, "boundary", shared, create){}
	virtual ~Boundary(){}

	void setOrder(bool _or)
	{
		if(_or == true) return;
		fprintf(mFile,"\tsetAttr \".or\" %i;\n", _or);
	}
	void setEndPoint(bool ep)
	{
		if(ep == false) return;
		fprintf(mFile,"\tsetAttr \".ep\" %i;\n", ep);
	}
	void getOrder()const
	{
		fprintf(mFile,"\"%s.or\"",mName.c_str());
	}
	void getEndPoint()const
	{
		fprintf(mFile,"\"%s.ep\"",mName.c_str());
	}
protected:
	Boundary(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:BoundaryBase(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_BOUNDARY_H__
