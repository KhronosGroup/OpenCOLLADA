/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	NurbsDimShape(FILE* file,const std::string& name,const std::string& parent=""):DimensionShape(file, name, parent, "nurbsDimShape"){}
	virtual ~NurbsDimShape(){}
	void setUParamValue(double upv)
	{
		if(upv == 0.0) return;
		fprintf(mFile,"setAttr \".upv\" %f;\n", upv);

	}
	void setVParamValue(double vpv)
	{
		if(vpv == 0.0) return;
		fprintf(mFile,"setAttr \".vpv\" %f;\n", vpv);

	}
	void getUParamValue()
	{
		fprintf(mFile,"\"%s.upv\"",mName.c_str());

	}
	void getVParamValue()
	{
		fprintf(mFile,"\"%s.vpv\"",mName.c_str());

	}
	void getNurbsGeometry()
	{
		fprintf(mFile,"\"%s.ng\"",mName.c_str());

	}
protected:
	NurbsDimShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DimensionShape(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_NURBSDIMSHAPE_H__
