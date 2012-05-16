/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSMOOTH_H__
#define __MayaDM_POLYSMOOTH_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolySmooth : public PolyModifier
{
public:
public:

	PolySmooth():PolyModifier(){}
	PolySmooth(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polySmooth", shared, create){}
	virtual ~PolySmooth(){}

	void setSmoothness(short sm)
	{
		if(sm == 1) return;
		fprintf(mFile,"\tsetAttr \".sm\" %i;\n", sm);
	}
	void getSmoothness()const
	{
		fprintf(mFile,"\"%s.sm\"",mName.c_str());
	}
protected:
	PolySmooth(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSMOOTH_H__
