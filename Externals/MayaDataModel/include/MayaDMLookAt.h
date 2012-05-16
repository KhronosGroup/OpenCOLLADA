/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_LOOKAT_H__
#define __MayaDM_LOOKAT_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAimConstraint.h"
namespace MayaDM
{
class LookAt : public AimConstraint
{
public:
public:

	LookAt():AimConstraint(){}
	LookAt(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AimConstraint(file, name, parent, "lookAt", shared, create){}
	virtual ~LookAt(){}

	void setDistanceBetween(double db)
	{
		if(db == 0.0) return;
		fprintf(mFile,"\tsetAttr \".db\" %f;\n", db);
	}
	void setTwist(double tws)
	{
		if(tws == 0) return;
		fprintf(mFile,"\tsetAttr \".tws\" %f;\n", tws);
	}
	void setDisplayConnector(bool dc)
	{
		if(dc == true) return;
		fprintf(mFile,"\tsetAttr \".dc\" %i;\n", dc);
	}
	void getDistanceBetween()const
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());
	}
	void getTwist()const
	{
		fprintf(mFile,"\"%s.tws\"",mName.c_str());
	}
	void getDisplayConnector()const
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());
	}
protected:
	LookAt(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AimConstraint(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_LOOKAT_H__
