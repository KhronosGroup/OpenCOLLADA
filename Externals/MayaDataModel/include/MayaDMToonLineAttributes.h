/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TOONLINEATTRIBUTES_H__
#define __MayaDM_TOONLINEATTRIBUTES_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class ToonLineAttributes : public DependNode
{
public:
public:
	ToonLineAttributes(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "toonLineAttributes"){}
	virtual ~ToonLineAttributes(){}
	void setLineWidth(float lwd)
	{
		if(lwd == 1) return;
		fprintf(mFile,"setAttr \".lwd\" %f;\n", lwd);

	}
	void setLineVisibility(bool lv)
	{
		if(lv == true) return;
		fprintf(mFile,"setAttr \".lv\" %i;\n", lv);

	}
	void setViewUpdate(unsigned int vu)
	{
		if(vu == 1) return;
		fprintf(mFile,"setAttr \".vu\" %i;\n", vu);

	}
	void getLineWidth()
	{
		fprintf(mFile,"\"%s.lwd\"",mName.c_str());

	}
	void getLineVisibility()
	{
		fprintf(mFile,"\"%s.lv\"",mName.c_str());

	}
	void getViewUpdate()
	{
		fprintf(mFile,"\"%s.vu\"",mName.c_str());

	}
protected:
	ToonLineAttributes(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TOONLINEATTRIBUTES_H__
