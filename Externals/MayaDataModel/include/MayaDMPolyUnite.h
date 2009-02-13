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
	PolyUnite(FILE* file,const std::string& name,const std::string& parent="",bool create=true)
		:PolyCreator(file, name, parent, "polyUnite", create){}
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
	void getInputMat(size_t im_i)const
	{
		fprintf(mFile,"\"%s.im[%i]\"",mName.c_str(),im_i);

	}
protected:
	PolyUnite(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool create=true)
		:PolyCreator(file, name, parent, nodeType, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYUNITE_H__
