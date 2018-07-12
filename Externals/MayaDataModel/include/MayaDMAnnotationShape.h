/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_ANNOTATIONSHAPE_H__
#define __MayaDM_ANNOTATIONSHAPE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDimensionShape.h"
namespace MayaDM
{
class AnnotationShape : public DimensionShape
{
public:
public:

	AnnotationShape():DimensionShape(){}
	AnnotationShape(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DimensionShape(file, name, parent, "annotationShape", shared, create){}
	virtual ~AnnotationShape(){}

	void setText(const string& txt)
	{
		if(txt == "NULL") return;
		fprintf(mFile,"\tsetAttr \".txt\" -type \"string\" ");
		txt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDagObjectMatrix(size_t dom_i,const matrix& dom)
	{
		if(dom == identity) return;
		fprintf(mFile,"\tsetAttr \".dom[%i]\" -type \"matrix\" ",dom_i);
		dom.write(mFile);
		fprintf(mFile,";\n");
	}
	void setDagObjectMatrix(size_t dom_start,size_t dom_end,matrix* dom)
	{
		fprintf(mFile,"\tsetAttr \".dom[%i:%i]\" ", dom_start,dom_end);
		size_t size = (dom_end-dom_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			dom[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startDagObjectMatrix(size_t dom_start,size_t dom_end)const
	{
		fprintf(mFile,"\tsetAttr \".dom[%i:%i]\"",dom_start,dom_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendDagObjectMatrix(const matrix& dom)const
	{
		fprintf(mFile," ");
		dom.write(mFile);
	}
	void endDagObjectMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setDisplayArrow(bool daro)
	{
		if(daro == true) return;
		fprintf(mFile,"\tsetAttr \".daro\" %i;\n", daro);
	}
	void getText()const
	{
		fprintf(mFile,"\"%s.txt\"",mName.c_str());
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.tp\"",mName.c_str());
	}
	void getPositionX()const
	{
		fprintf(mFile,"\"%s.tp.tpx\"",mName.c_str());
	}
	void getPositionY()const
	{
		fprintf(mFile,"\"%s.tp.tpy\"",mName.c_str());
	}
	void getPositionZ()const
	{
		fprintf(mFile,"\"%s.tp.tpz\"",mName.c_str());
	}
	void getDagObjectMatrix(size_t dom_i)const
	{
		fprintf(mFile,"\"%s.dom[%i]\"",mName.c_str(),dom_i);
	}
	void getDagObjectMatrix()const
	{

		fprintf(mFile,"\"%s.dom\"",mName.c_str());
	}
	void getDisplayArrow()const
	{
		fprintf(mFile,"\"%s.daro\"",mName.c_str());
	}
protected:
	AnnotationShape(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DimensionShape(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_ANNOTATIONSHAPE_H__
