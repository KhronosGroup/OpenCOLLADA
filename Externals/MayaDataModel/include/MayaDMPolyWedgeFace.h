/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYWEDGEFACE_H__
#define __MayaDM_POLYWEDGEFACE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyWedgeFace : public PolyModifierWorld
{
public:
public:

	PolyWedgeFace():PolyModifierWorld(){}
	PolyWedgeFace(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyWedgeFace", shared, create){}
	virtual ~PolyWedgeFace(){}

	void setWedgeAngle(double wa)
	{
		if(wa == 0) return;
		fprintf(mFile,"\tsetAttr \".wa\" %f;\n", wa);
	}
	void setDivisions(int d)
	{
		if(d == 1) return;
		fprintf(mFile,"\tsetAttr \".d\" %i;\n", d);
	}
	void setEdge(size_t ed_i,int ed)
	{
		if(ed == 0) return;
		fprintf(mFile,"\tsetAttr \".ed[%i]\" %i;\n", ed_i,ed);
	}
	void setEdge(size_t ed_start,size_t ed_end,int* ed)
	{
		fprintf(mFile,"\tsetAttr \".ed[%i:%i]\" ", ed_start,ed_end);
		size_t size = (ed_end-ed_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ed[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startEdge(size_t ed_start,size_t ed_end)const
	{
		fprintf(mFile,"\tsetAttr \".ed[%i:%i]\"",ed_start,ed_end);
	}
	void appendEdge(int ed)const
	{
		fprintf(mFile," %i",ed);
	}
	void endEdge()const
	{
		fprintf(mFile,";\n");
	}
	void getWedgeAngle()const
	{
		fprintf(mFile,"\"%s.wa\"",mName.c_str());
	}
	void getDivisions()const
	{
		fprintf(mFile,"\"%s.d\"",mName.c_str());
	}
	void getEdge(size_t ed_i)const
	{
		fprintf(mFile,"\"%s.ed[%i]\"",mName.c_str(),ed_i);
	}
	void getEdge()const
	{

		fprintf(mFile,"\"%s.ed\"",mName.c_str());
	}
protected:
	PolyWedgeFace(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYWEDGEFACE_H__
