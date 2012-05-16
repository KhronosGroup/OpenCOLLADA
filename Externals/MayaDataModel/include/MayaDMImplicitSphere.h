/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMPLICITSPHERE_H__
#define __MayaDM_IMPLICITSPHERE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
class ImplicitSphere : public GeometryShape
{
public:
public:

	ImplicitSphere():GeometryShape(){}
	ImplicitSphere(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, "implicitSphere", shared, create){}
	virtual ~ImplicitSphere(){}

	void setRadius(double rd)
	{
		if(rd == 1) return;
		fprintf(mFile,"\tsetAttr \".rd\" %f;\n", rd);
	}
	void getSphere()const
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());
	}
	void getRadius()const
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());
	}
protected:
	ImplicitSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITSPHERE_H__
