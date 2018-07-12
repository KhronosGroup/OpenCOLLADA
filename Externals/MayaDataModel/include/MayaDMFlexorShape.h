/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_FLEXORSHAPE_H__
#define __MayaDM_FLEXORSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMShape.h"
namespace MayaDM
{
class FlexorShape : public Shape
{
public:
public:

	FlexorShape():Shape(){}
	FlexorShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Shape(file, name, parent, "flexorShape", shared, create){}
	virtual ~FlexorShape(){}

	void setCurrentDriver(short cdr)
	{
		if(cdr == -1) return;
		fprintf(mFile,"\tsetAttr \".cdr\" %i;\n", cdr);
	}
	void getDriver(size_t dr_i)const
	{
		fprintf(mFile,"\"%s.dr[%i]\"",mName.c_str(),dr_i);
	}
	void getDriver()const
	{

		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getCurrentDriver()const
	{
		fprintf(mFile,"\"%s.cdr\"",mName.c_str());
	}
	void getFlexorNodes(size_t fn_i)const
	{
		fprintf(mFile,"\"%s.fn[%i]\"",mName.c_str(),fn_i);
	}
	void getFlexorNodes()const
	{

		fprintf(mFile,"\"%s.fn\"",mName.c_str());
	}
protected:
	FlexorShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Shape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_FLEXORSHAPE_H__
