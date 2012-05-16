/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYDUPLICATEEDGE_H__
#define __MayaDM_POLYDUPLICATEEDGE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifier.h"
namespace MayaDM
{
class PolyDuplicateEdge : public PolyModifier
{
public:
public:

	PolyDuplicateEdge():PolyModifier(){}
	PolyDuplicateEdge(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, "polyDuplicateEdge", shared, create){}
	virtual ~PolyDuplicateEdge(){}

	void setOffset(float of)
	{
		if(of == 0.5) return;
		fprintf(mFile,"\tsetAttr \".of\" %f;\n", of);
	}
	void setStartVertexOffset(float svo)
	{
		if(svo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".svo\" %f;\n", svo);
	}
	void setEndVertexOffset(float evo)
	{
		if(evo == 0.0) return;
		fprintf(mFile,"\tsetAttr \".evo\" %f;\n", evo);
	}
	void setDeleteEdge(bool de)
	{
		if(de == true) return;
		fprintf(mFile,"\tsetAttr \".de\" %i;\n", de);
	}
	void setSmoothingAngle(double sma)
	{
		if(sma == 1) return;
		fprintf(mFile,"\tsetAttr \".sma\" %f;\n", sma);
	}
	void setSplitType(unsigned int stp)
	{
		if(stp == 1) return;
		fprintf(mFile,"\tsetAttr \".stp\" %i;\n", stp);
	}
	void getOffset()const
	{
		fprintf(mFile,"\"%s.of\"",mName.c_str());
	}
	void getStartVertexOffset()const
	{
		fprintf(mFile,"\"%s.svo\"",mName.c_str());
	}
	void getEndVertexOffset()const
	{
		fprintf(mFile,"\"%s.evo\"",mName.c_str());
	}
	void getDeleteEdge()const
	{
		fprintf(mFile,"\"%s.de\"",mName.c_str());
	}
	void getSmoothingAngle()const
	{
		fprintf(mFile,"\"%s.sma\"",mName.c_str());
	}
	void getSplitType()const
	{
		fprintf(mFile,"\"%s.stp\"",mName.c_str());
	}
protected:
	PolyDuplicateEdge(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifier(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYDUPLICATEEDGE_H__
