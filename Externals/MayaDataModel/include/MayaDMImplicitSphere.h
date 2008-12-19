/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	ImplicitSphere(FILE* file,const std::string& name,const std::string& parent=""):GeometryShape(file, name, parent, "implicitSphere"){}
	virtual ~ImplicitSphere(){}
	void setRadius(double rd)
	{
		if(rd == 1) return;
		fprintf(mFile,"setAttr \".rd\" %f;\n", rd);

	}
	void getSphere()
	{
		fprintf(mFile,"\"%s.s\"",mName.c_str());

	}
	void getRadius()
	{
		fprintf(mFile,"\"%s.rd\"",mName.c_str());

	}
protected:
	ImplicitSphere(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITSPHERE_H__
