/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	LookAt(FILE* file,const std::string& name,const std::string& parent=""):AimConstraint(file, name, parent, "lookAt"){}
	virtual ~LookAt(){}
	void setDistanceBetween(double db)
	{
		if(db == 0.0) return;
		fprintf(mFile,"setAttr \".db\" %f;\n", db);

	}
	void setTwist(double tws)
	{
		if(tws == 0) return;
		fprintf(mFile,"setAttr \".tws\" %f;\n", tws);

	}
	void setDisplayConnector(bool dc)
	{
		if(dc == true) return;
		fprintf(mFile,"setAttr \".dc\" %i;\n", dc);

	}
	void getDistanceBetween()
	{
		fprintf(mFile,"\"%s.db\"",mName.c_str());

	}
	void getTwist()
	{
		fprintf(mFile,"\"%s.tws\"",mName.c_str());

	}
	void getDisplayConnector()
	{
		fprintf(mFile,"\"%s.dc\"",mName.c_str());

	}
protected:
	LookAt(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):AimConstraint(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_LOOKAT_H__
