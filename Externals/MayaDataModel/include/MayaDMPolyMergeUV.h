/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYMERGEUV_H__
#define __MayaDM_POLYMERGEUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyMergeUV : public PolyModifierUV
{
public:
public:

	PolyMergeUV():PolyModifierUV(){}
	PolyMergeUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, "polyMergeUV", shared, create){}
	virtual ~PolyMergeUV(){}

	void setDistance(float d)
	{
		if(d == 10000) return;
		fprintf(mFile,"\tsetAttr \".d\" %f;\n", d);
	}
	void getDistance()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
protected:
	PolyMergeUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYMERGEUV_H__
