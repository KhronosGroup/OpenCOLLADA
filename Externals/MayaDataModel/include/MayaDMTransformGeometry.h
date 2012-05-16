/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TRANSFORMGEOMETRY_H__
#define __MayaDM_TRANSFORMGEOMETRY_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class TransformGeometry : public AbstractBaseCreate
{
public:
public:

	TransformGeometry():AbstractBaseCreate(){}
	TransformGeometry(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "transformGeometry", shared, create){}
	virtual ~TransformGeometry(){}

	void setTransform(const matrix& txf)
	{
		if(txf == identity) return;
		fprintf(mFile,"\tsetAttr \".txf\" -type \"matrix\" ");
		txf.write(mFile);
		fprintf(mFile,";\n");
	}
	void setInvertTransform(bool itf)
	{
		if(itf == false) return;
		fprintf(mFile,"\tsetAttr \".itf\" %i;\n", itf);
	}
	void setFreezeNormals(unsigned int fn)
	{
		if(fn == 0) return;
		fprintf(mFile,"\tsetAttr \".fn\" %i;\n", fn);
	}
	void getInputGeometry()const
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());
	}
	void getTransform()const
	{
		fprintf(mFile,"\"%s.txf\"",mName.c_str());
	}
	void getInvertTransform()const
	{
		fprintf(mFile,"\"%s.itf\"",mName.c_str());
	}
	void getFreezeNormals()const
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());
	}
	void getOutputGeometry()const
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());
	}
protected:
	TransformGeometry(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFORMGEOMETRY_H__
