/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_DAGPOSE_H__
#define __MayaDM_DAGPOSE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class DagPose : public DependNode
{
public:
public:
	DagPose(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "dagPose"){}
	virtual ~DagPose(){}
	void setWorldMatrix(size_t wm_i,const matrix& wm)
	{
		if(wm == identity) return;
		fprintf(mFile,"setAttr \".wm[%i]\" -type \"matrix\" ",wm_i);
		wm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setXformMatrix(size_t xm_i,const matrix& xm)
	{
		if(xm == identity) return;
		fprintf(mFile,"setAttr \".xm[%i]\" -type \"matrix\" ",xm_i);
		xm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGlobal(size_t g_i,bool g)
	{
		if(g == false) return;
		fprintf(mFile,"setAttr \".g[%i]\" %i;\n", g_i,g);

	}
	void setBindPose(bool bp)
	{
		if(bp == false) return;
		fprintf(mFile,"setAttr \".bp\" %i;\n", bp);

	}
	void getWorldMatrix(size_t wm_i)
	{
		fprintf(mFile,"\"%s.wm[%i]\"",mName.c_str(),wm_i);

	}
	void getMembers(size_t m_i)
	{
		fprintf(mFile,"\"%s.m[%i]\"",mName.c_str(),m_i);

	}
	void getParents(size_t p_i)
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);

	}
	void getWorld()
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());

	}
protected:
	DagPose(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_DAGPOSE_H__
