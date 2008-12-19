/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyCopyUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyCopyUV"){}
	virtual ~PolyCopyUV(){}
	void setUvSetNameInput(const string& uvi)
	{
		if(uvi == "NULL") return;
		fprintf(mFile,"setAttr \".uvi\" -type \"string\" ");
		uvi.write(mFile);
		fprintf(mFile,";\n");

	}
	void getUvSetNameInput()
	{
		fprintf(mFile,"\"%s.uvi\"",mName.c_str());

	}
protected:
	PolyCopyUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOPYUV_H__
