/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_RADIALFIELD_H__
#define __MayaDM_RADIALFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
class RadialField : public Field
{
public:
public:
	RadialField(FILE* file,const std::string& name,const std::string& parent=""):Field(file, name, parent, "radialField"){}
	virtual ~RadialField(){}
	void setRadialType(double typ)
	{
		if(typ == 0.0) return;
		fprintf(mFile,"setAttr \".typ\" %f;\n", typ);

	}
	void getRadialType()
	{
		fprintf(mFile,"\"%s.typ\"",mName.c_str());

	}
protected:
	RadialField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Field(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_RADIALFIELD_H__
