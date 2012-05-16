/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCOLLAPSEF_H__
#define __MayaDM_POLYCOLLAPSEF_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyCollapseF : public PolyModifier
{
public:
public:

	PolyCollapseF():PolyModifier(){}
	PolyCollapseF(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyCollapseF", shared, create){}
	virtual ~PolyCollapseF(){}

	void setUseAreaThreshold(bool uat)
	{
		if(uat == false) return;
		fprintf(mFile,"\tsetAttr \".uat\" %i;\n", uat);
	}
	void setAreaThreshold(double at)
	{
		if(at == 0.1) return;
		fprintf(mFile,"\tsetAttr \".at\" %f;\n", at);
	}
	void getUseAreaThreshold()const
	{
		fprintf(mFile,"\"%s.uat\"",mName.c_str());
	}
	void getAreaThreshold()const
	{
		fprintf(mFile,"\"%s.at\"",mName.c_str());
	}
protected:
	PolyCollapseF(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCOLLAPSEF_H__
