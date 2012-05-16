/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMBEND_H__
#define __MayaDM_DEFORMBEND_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
class DeformBend : public DeformFunc
{
public:
public:

	DeformBend():DeformFunc(){}
	DeformBend(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, "deformBend", shared, create){}
	virtual ~DeformBend(){}

	void setLowBound(double lb)
	{
		if(lb == -1.0) return;
		fprintf(mFile,"\tsetAttr \".lb\" %f;\n", lb);
	}
	void setHighBound(double hb)
	{
		if(hb == 1.0) return;
		fprintf(mFile,"\tsetAttr \".hb\" %f;\n", hb);
	}
	void setCurvature(double cur)
	{
		if(cur == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cur\" %f;\n", cur);
	}
	void getLowBound()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getHighBound()const
	{
		fprintf(mFile,"\"%s.hb\"",mName.c_str());
	}
	void getCurvature()const
	{
		fprintf(mFile,"\"%s.cur\"",mName.c_str());
	}
protected:
	DeformBend(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMBEND_H__
