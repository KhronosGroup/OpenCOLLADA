/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	PolyNormalizeUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyNormalizeUV"){}
	virtual ~PolyNormalizeUV(){}
	void setNormalizeType(unsigned int nt)
	{
		if(nt == 1) return;
		fprintf(mFile,"setAttr \".nt\" %i;\n", nt);

	}
	void setPreserveAspectRatio(bool pa)
	{
		if(pa == true) return;
		fprintf(mFile,"setAttr \".pa\" %i;\n", pa);

	}
	void getNormalizeType()
	{
		fprintf(mFile,"\"%s.nt\"",mName.c_str());

	}
	void getPreserveAspectRatio()
	{
		fprintf(mFile,"\"%s.pa\"",mName.c_str());

	}
protected:
	PolyNormalizeUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYNORMALIZEUV_H__
