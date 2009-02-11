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
	TransformGeometry(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "transformGeometry"){}
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
	void getInputGeometry()
	{
		fprintf(mFile,"\"%s.ig\"",mName.c_str());

	}
	void getTransform()
	{
		fprintf(mFile,"\"%s.txf\"",mName.c_str());

	}
	void getInvertTransform()
	{
		fprintf(mFile,"\"%s.itf\"",mName.c_str());

	}
	void getFreezeNormals()
	{
		fprintf(mFile,"\"%s.fn\"",mName.c_str());

	}
	void getOutputGeometry()
	{
		fprintf(mFile,"\"%s.og\"",mName.c_str());

	}
protected:
	TransformGeometry(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TRANSFORMGEOMETRY_H__
