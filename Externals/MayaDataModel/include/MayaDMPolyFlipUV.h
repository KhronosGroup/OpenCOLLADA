/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYFLIPUV_H__
#define __MayaDM_POLYFLIPUV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyFlipUV : public PolyModifierUV
{
public:
public:
	PolyFlipUV(FILE* file,const std::string& name,const std::string& parent=""):PolyModifierUV(file, name, parent, "polyFlipUV"){}
	virtual ~PolyFlipUV(){}
	void setFlipType(unsigned int ft)
	{
		if(ft == 0) return;
		fprintf(mFile,"setAttr \".ft\" %i;\n", ft);

	}
	void setLocal(bool l)
	{
		if(l == true) return;
		fprintf(mFile,"setAttr \".l\" %i;\n", l);

	}
	void getFlipType()
	{
		fprintf(mFile,"\"%s.ft\"",mName.c_str());

	}
	void getLocal()
	{
		fprintf(mFile,"\"%s.l\"",mName.c_str());

	}
protected:
	PolyFlipUV(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):PolyModifierUV(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYFLIPUV_H__
