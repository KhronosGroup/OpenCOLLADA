/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_IKEFFECTOR_H__
#define __MayaDM_IKEFFECTOR_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class IkEffector : public Transform
{
public:
public:

	IkEffector():Transform(){}
	IkEffector(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "ikEffector", shared, create){}
	virtual ~IkEffector(){}

	void setHideDisplay(bool hd)
	{
		if(hd == false) return;
		fprintf(mFile,"\tsetAttr \".hd\" %i;\n", hd);
	}
	void getHideDisplay()const
	{
		fprintf(mFile,"\"%s.hd\"",mName.c_str());
	}
	void getHandlePath(size_t hp_i)const
	{
		fprintf(mFile,"\"%s.hp[%i]\"",mName.c_str(),hp_i);
	}
	void getHandlePath()const
	{

		fprintf(mFile,"\"%s.hp\"",mName.c_str());
	}
protected:
	IkEffector(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_IKEFFECTOR_H__
