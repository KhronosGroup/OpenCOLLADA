/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DEFORMTWIST_H__
#define __MayaDM_DEFORMTWIST_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDeformFunc.h"
namespace MayaDM
{
class DeformTwist : public DeformFunc
{
public:
public:

	DeformTwist():DeformFunc(){}
	DeformTwist(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, "deformTwist", shared, create){}
	virtual ~DeformTwist(){}

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
	void setStartAngle(double sa)
	{
		if(sa == 0) return;
		fprintf(mFile,"\tsetAttr \".sa\" %f;\n", sa);
	}
	void setEndAngle(double ea)
	{
		if(ea == 0) return;
		fprintf(mFile,"\tsetAttr \".ea\" %f;\n", ea);
	}
	void getLowBound()const
	{
		fprintf(mFile,"\"%s.lb\"",mName.c_str());
	}
	void getHighBound()const
	{
		fprintf(mFile,"\"%s.hb\"",mName.c_str());
	}
	void getStartAngle()const
	{
		fprintf(mFile,"\"%s.sa\"",mName.c_str());
	}
	void getEndAngle()const
	{
		fprintf(mFile,"\"%s.ea\"",mName.c_str());
	}
protected:
	DeformTwist(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DeformFunc(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DEFORMTWIST_H__
