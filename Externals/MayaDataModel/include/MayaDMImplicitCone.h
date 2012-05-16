/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IMPLICITCONE_H__
#define __MayaDM_IMPLICITCONE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryShape.h"
namespace MayaDM
{
class ImplicitCone : public GeometryShape
{
public:
public:

	ImplicitCone():GeometryShape(){}
	ImplicitCone(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, "implicitCone", shared, create){}
	virtual ~ImplicitCone(){}

	void setConeAngle(double ca)
	{
		if(ca == 4) return;
		fprintf(mFile,"\tsetAttr \".ca\" %f;\n", ca);
	}
	void setConeCap(double cap)
	{
		if(cap == 10.0) return;
		fprintf(mFile,"\tsetAttr \".cap\" %f;\n", cap);
	}
	void getCone()const
	{
		fprintf(mFile,"\"%s.cn\"",mName.c_str());
	}
	void getConeAngle()const
	{
		fprintf(mFile,"\"%s.ca\"",mName.c_str());
	}
	void getConeCap()const
	{
		fprintf(mFile,"\"%s.cap\"",mName.c_str());
	}
protected:
	ImplicitCone(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IMPLICITCONE_H__
