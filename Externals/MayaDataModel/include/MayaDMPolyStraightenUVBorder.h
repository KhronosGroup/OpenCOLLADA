/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYSTRAIGHTENUVBORDER_H__
#define __MayaDM_POLYSTRAIGHTENUVBORDER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierUV.h"
namespace MayaDM
{
class PolyStraightenUVBorder : public PolyModifierUV
{
public:
public:

	PolyStraightenUVBorder():PolyModifierUV(){}
	PolyStraightenUVBorder(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, "polyStraightenUVBorder", shared, create){}
	virtual ~PolyStraightenUVBorder(){}

	void setCurvature(float c)
	{
		if(c == 0.) return;
		fprintf(mFile,"\tsetAttr \".c\" %f;\n", c);
	}
	void setPreserveLength(float pl)
	{
		if(pl == 1.) return;
		fprintf(mFile,"\tsetAttr \".pl\" %f;\n", pl);
	}
	void setBlendOriginal(float bo)
	{
		if(bo == 0.) return;
		fprintf(mFile,"\tsetAttr \".bo\" %f;\n", bo);
	}
	void setGapTolerance(int gt)
	{
		if(gt == 5) return;
		fprintf(mFile,"\tsetAttr \".gt\" %i;\n", gt);
	}
	void getCurvature()const
	{
		fprintf(mFile,"\"%s.c\"",mName.c_str());
	}
	void getPreserveLength()const
	{
		fprintf(mFile,"\"%s.pl\"",mName.c_str());
	}
	void getBlendOriginal()const
	{
		fprintf(mFile,"\"%s.bo\"",mName.c_str());
	}
	void getGapTolerance()const
	{
		fprintf(mFile,"\"%s.gt\"",mName.c_str());
	}
protected:
	PolyStraightenUVBorder(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierUV(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYSTRAIGHTENUVBORDER_H__
