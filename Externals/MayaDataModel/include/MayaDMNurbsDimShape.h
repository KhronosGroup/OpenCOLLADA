/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NURBSDIMSHAPE_H__
#define __MayaDM_NURBSDIMSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDimensionShape.h"
namespace MayaDM
{
class NurbsDimShape : public DimensionShape
{
public:
public:

	NurbsDimShape():DimensionShape(){}
	NurbsDimShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DimensionShape(file, name, parent, "nurbsDimShape", shared, create){}
	virtual ~NurbsDimShape(){}

	void setUParamValue(double upv)
	{
		if(upv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".upv\" %f;\n", upv);
	}
	void setVParamValue(double vpv)
	{
		if(vpv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".vpv\" %f;\n", vpv);
	}
	void getUParamValue()const
	{
		fprintf(mFile,"\"%s.upv\"",mName.c_str());
	}
	void getVParamValue()const
	{
		fprintf(mFile,"\"%s.vpv\"",mName.c_str());
	}
	void getNurbsGeometry()const
	{
		fprintf(mFile,"\"%s.ng\"",mName.c_str());
	}
protected:
	NurbsDimShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DimensionShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSDIMSHAPE_H__
