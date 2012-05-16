/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DYNBASE_H__
#define __MayaDM_DYNBASE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMTransform.h"
namespace MayaDM
{
class DynBase : public Transform
{
public:
public:

	DynBase():Transform(){}
	DynBase(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:Transform(file, name, parent, "dynBase", shared, create){}
	virtual ~DynBase(){}

	void setFromWhere(short fw)
	{
		if(fw == 0) return;
		fprintf(mFile,"\tsetAttr \".fw\" %i;\n", fw);
	}
	void setSubsetId(int sid)
	{
		if(sid == -1) return;
		fprintf(mFile,"\tsetAttr \".sid\" %i;\n", sid);
	}
	void getOwner()const
	{
		fprintf(mFile,"\"%s.ow\"",mName.c_str());
	}
	void getFromWhere()const
	{
		fprintf(mFile,"\"%s.fw\"",mName.c_str());
	}
	void getSubsetId()const
	{
		fprintf(mFile,"\"%s.sid\"",mName.c_str());
	}
	void getPositional()const
	{
		fprintf(mFile,"\"%s.psl\"",mName.c_str());
	}
	void getOwnerCentroid()const
	{
		fprintf(mFile,"\"%s.ocd\"",mName.c_str());
	}
	void getOwnerCentroidX()const
	{
		fprintf(mFile,"\"%s.ocd.ocx\"",mName.c_str());
	}
	void getOwnerCentroidY()const
	{
		fprintf(mFile,"\"%s.ocd.ocy\"",mName.c_str());
	}
	void getOwnerCentroidZ()const
	{
		fprintf(mFile,"\"%s.ocd.ocz\"",mName.c_str());
	}
	void getOwnerPosData()const
	{
		fprintf(mFile,"\"%s.opd\"",mName.c_str());
	}
	void getOwnerVelData()const
	{
		fprintf(mFile,"\"%s.ovd\"",mName.c_str());
	}
protected:
	DynBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:Transform(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DYNBASE_H__
