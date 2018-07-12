/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYCREASE_H__
#define __MayaDM_POLYCREASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyModifierWorld.h"
namespace MayaDM
{
class PolyCrease : public PolyModifierWorld
{
public:
public:

	PolyCrease():PolyModifierWorld(){}
	PolyCrease(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, "polyCrease", shared, create){}
	virtual ~PolyCrease(){}

	void setCrease(size_t cr_i,float cr)
	{
		if(cr == -1.0) return;
		fprintf(mFile,"\tsetAttr \".cr[%i]\" %f;\n", cr_i,cr);
	}
	void setCrease(size_t cr_start,size_t cr_end,float* cr)
	{
		fprintf(mFile,"\tsetAttr \".cr[%i:%i]\" ", cr_start,cr_end);
		size_t size = (cr_end-cr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startCrease(size_t cr_start,size_t cr_end)const
	{
		fprintf(mFile,"\tsetAttr \".cr[%i:%i]\"",cr_start,cr_end);
	}
	void appendCrease(float cr)const
	{
		fprintf(mFile," %f",cr);
	}
	void endCrease()const
	{
		fprintf(mFile,";\n");
	}
	void setInputVertexComponents(const componentList& ivc)
	{
		fprintf(mFile,"\tsetAttr \".ivc\" -type \"componentList\" ");
		ivc.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCreaseVertex(size_t crv_i,float crv)
	{
		if(crv == -1.0) return;
		fprintf(mFile,"\tsetAttr \".crv[%i]\" %f;\n", crv_i,crv);
	}
	void setCreaseVertex(size_t crv_start,size_t crv_end,float* crv)
	{
		fprintf(mFile,"\tsetAttr \".crv[%i:%i]\" ", crv_start,crv_end);
		size_t size = (crv_end-crv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",crv[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startCreaseVertex(size_t crv_start,size_t crv_end)const
	{
		fprintf(mFile,"\tsetAttr \".crv[%i:%i]\"",crv_start,crv_end);
	}
	void appendCreaseVertex(float crv)const
	{
		fprintf(mFile," %f",crv);
	}
	void endCreaseVertex()const
	{
		fprintf(mFile,";\n");
	}
	void getCrease(size_t cr_i)const
	{
		fprintf(mFile,"\"%s.cr[%i]\"",mName.c_str(),cr_i);
	}
	void getCrease()const
	{

		fprintf(mFile,"\"%s.cr\"",mName.c_str());
	}
	void getInputVertexComponents()const
	{
		fprintf(mFile,"\"%s.ivc\"",mName.c_str());
	}
	void getCreaseVertex(size_t crv_i)const
	{
		fprintf(mFile,"\"%s.crv[%i]\"",mName.c_str(),crv_i);
	}
	void getCreaseVertex()const
	{

		fprintf(mFile,"\"%s.crv\"",mName.c_str());
	}
protected:
	PolyCrease(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyModifierWorld(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYCREASE_H__
