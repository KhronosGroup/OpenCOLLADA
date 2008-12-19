/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	DynBase(FILE* file,const std::string& name,const std::string& parent=""):Transform(file, name, parent, "dynBase"){}
	virtual ~DynBase(){}
	void setFromWhere(short fw)
	{
		if(fw == 0) return;
		fprintf(mFile,"setAttr \".fw\" %i;\n", fw);

	}
	void setSubsetId(int sid)
	{
		if(sid == -1) return;
		fprintf(mFile,"setAttr \".sid\" %i;\n", sid);

	}
	void getOwner()
	{
		fprintf(mFile,"\"%s.ow\"",mName.c_str());

	}
	void getFromWhere()
	{
		fprintf(mFile,"\"%s.fw\"",mName.c_str());

	}
	void getSubsetId()
	{
		fprintf(mFile,"\"%s.sid\"",mName.c_str());

	}
	void getPositional()
	{
		fprintf(mFile,"\"%s.psl\"",mName.c_str());

	}
	void getOwnerCentroid()
	{
		fprintf(mFile,"\"%s.ocd\"",mName.c_str());

	}
	void getOwnerCentroidX()
	{
		fprintf(mFile,"\"%s.ocd.ocx\"",mName.c_str());

	}
	void getOwnerCentroidY()
	{
		fprintf(mFile,"\"%s.ocd.ocy\"",mName.c_str());

	}
	void getOwnerCentroidZ()
	{
		fprintf(mFile,"\"%s.ocd.ocz\"",mName.c_str());

	}
	void getOwnerPosData()
	{
		fprintf(mFile,"\"%s.opd\"",mName.c_str());

	}
	void getOwnerVelData()
	{
		fprintf(mFile,"\"%s.ovd\"",mName.c_str());

	}
protected:
	DynBase(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):Transform(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DYNBASE_H__
