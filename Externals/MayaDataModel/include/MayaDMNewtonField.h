/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_NEWTONFIELD_H__
#define __MayaDM_NEWTONFIELD_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMField.h"
namespace MayaDM
{
class NewtonField : public Field
{
public:
public:

	NewtonField():Field(){}
	NewtonField(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Field(file, name, parent, "newtonField", shared, create){}
	virtual ~NewtonField(){}

	void setMinDistance(double min)
	{
		if(min == 0.0) return;
		fprintf(mFile,"\tsetAttr \".min\" %f;\n", min);
	}
	void setOwnerMassData(const doubleArray& omd)
	{
		if(omd.size == 0) return;
		fprintf(mFile,"\tsetAttr \".omd\" -type \"doubleArray\" ");
		omd.write(mFile);
		fprintf(mFile,";\n");
	}
	void getMinDistance()const
	{
		fprintf(mFile,"\"%s.min\"",mName.c_str());
	}
	void getOwnerMassData()const
	{
		fprintf(mFile,"\"%s.omd\"",mName.c_str());
	}
protected:
	NewtonField(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Field(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_NEWTONFIELD_H__
