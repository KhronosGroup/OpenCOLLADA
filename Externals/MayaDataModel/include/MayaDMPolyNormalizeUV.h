/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYNORMALIZEUV_H__
#define __MayaDM_POLYNORMALIZEUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyNormalizeUV : public PolyModifierUV
{
public:
public:

	PolyNormalizeUV():PolyModifierUV(){}
	PolyNormalizeUV(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, "polyNormalizeUV", shared, create){}
	virtual ~PolyNormalizeUV(){}

	void setNormalizeType(unsigned int nt)
	{
		if(nt == 1) return;
		fprintf(mFile,"\tsetAttr \".nt\" %i;\n", nt);
	}
	void setPreserveAspectRatio(bool pa)
	{
		if(pa == true) return;
		fprintf(mFile,"\tsetAttr \".pa\" %i;\n", pa);
	}
	void getNormalizeType()const
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());
	}
	void getPreserveAspectRatio()const
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());
	}
protected:
	PolyNormalizeUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMALIZEUV_H__
