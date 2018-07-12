/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYUNITE_H__
#define __MayaDM_POLYUNITE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMPolyCreator.h"
namespace MayaDM
{
class PolyUnite : public PolyCreator
{
public:
public:

	PolyUnite():PolyCreator(){}
	PolyUnite(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:PolyCreator(file, name, parent, "polyUnite", shared, create){}
	virtual ~PolyUnite(){}

	void setUseOldPolyArchitecture(bool uopa)
	{
		if(uopa == false) return;
		fprintf(mFile,"\tsetAttr \".uopa\" %i;\n", uopa);
	}
	void getInputPoly(size_t ip_i)const
	{
		fprintf(mFile,"\"%s.ip[%i]\"",mName.c_str(),ip_i);
	}
	void getInputPoly()const
	{

		fprintf(mFile,"\"%s.ip\"",mName.c_str());
	}
	void getInputMat(size_t im_i)const
	{
		fprintf(mFile,"\"%s.im[%i]\"",mName.c_str(),im_i);
	}
	void getInputMat()const
	{

		fprintf(mFile,"\"%s.im\"",mName.c_str());
	}
protected:
	PolyUnite(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:PolyCreator(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYUNITE_H__
