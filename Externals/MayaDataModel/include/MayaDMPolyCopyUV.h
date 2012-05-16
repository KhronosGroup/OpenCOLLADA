/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOPYUV_H__
#define __MayaDM_POLYCOPYUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyCopyUV : public PolyModifierUV
{
public:
public:

	PolyCopyUV():PolyModifierUV(){}
	PolyCopyUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, "polyCopyUV", shared, create){}
	virtual ~PolyCopyUV(){}

	void setUvSetNameInput(const string& uvi)
	{
		if(uvi == "NULL") return;
		fprintf(mFile,"\tsetAttr \".uvi\" -type \"string\" ");
		uvi.write(mFile);
		fprintf(mFile,";\n");
	}
	void getUvSetNameInput()const
	{
		fprintf(mFile,"\"%s.uvi\"",mName.c_str());
	}
protected:
	PolyCopyUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOPYUV_H__
