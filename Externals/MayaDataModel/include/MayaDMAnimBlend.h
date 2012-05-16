/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANIMBLEND_H__
#define __MayaDM_ANIMBLEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class AnimBlend : public DependNode
{
public:
public:

	AnimBlend():DependNode(){}
	AnimBlend(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "animBlend", shared, create){}
	virtual ~AnimBlend(){}

	void setWeight(double w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"\tsetAttr \".w\" %f;\n", w);
	}
	void getBlend()const
	{
		fprintf(mFile,"\"%s.b\"",mName.c_str());
	}
	void getWeight()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
protected:
	AnimBlend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANIMBLEND_H__
