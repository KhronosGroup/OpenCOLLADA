/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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

	DagPose():DependNode(){}
	DagPose(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "dagPose", shared, create){}
	virtual ~DagPose(){}

	void setWorldMatrix(size_t wm_i,const matrix& wm)
	{
		if(wm == identity) return;
		fprintf(mFile,"\tsetAttr \".wm[%i]\" -type \"matrix\" ",wm_i);
		wm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWorldMatrix(size_t wm_start,size_t wm_end,matrix* wm)
	{
		fprintf(mFile,"\tsetAttr \".wm[%i:%i]\" ", wm_start,wm_end);
		size_t size = (wm_end-wm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWorldMatrix(size_t wm_start,size_t wm_end)const
	{
		fprintf(mFile,"\tsetAttr \".wm[%i:%i]\"",wm_start,wm_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendWorldMatrix(const matrix& wm)const
	{
		fprintf(mFile," ");
		wm.write(mFile);
	}
	void endWorldMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setXformMatrix(size_t xm_i,const matrix& xm)
	{
		if(xm == identity) return;
		fprintf(mFile,"\tsetAttr \".xm[%i]\" -type \"matrix\" ",xm_i);
		xm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setXformMatrix(size_t xm_start,size_t xm_end,matrix* xm)
	{
		fprintf(mFile,"\tsetAttr \".xm[%i:%i]\" ", xm_start,xm_end);
		size_t size = (xm_end-xm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			xm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startXformMatrix(size_t xm_start,size_t xm_end)const
	{
		fprintf(mFile,"\tsetAttr \".xm[%i:%i]\"",xm_start,xm_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendXformMatrix(const matrix& xm)const
	{
		fprintf(mFile," ");
		xm.write(mFile);
	}
	void endXformMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setGlobal(size_t g_i,bool g)
	{
		if(g == false) return;
		fprintf(mFile,"\tsetAttr \".g[%i]\" %i;\n", g_i,g);
	}
	void setGlobal(size_t g_start,size_t g_end,bool* g)
	{
		fprintf(mFile,"\tsetAttr \".g[%i:%i]\" ", g_start,g_end);
		size_t size = (g_end-g_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",g[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startGlobal(size_t g_start,size_t g_end)const
	{
		fprintf(mFile,"\tsetAttr \".g[%i:%i]\"",g_start,g_end);
	}
	void appendGlobal(bool g)const
	{
		fprintf(mFile," %i",g);
	}
	void endGlobal()const
	{
		fprintf(mFile,";\n");
	}
	void setBindPose(bool bp)
	{
		if(bp == false) return;
		fprintf(mFile,"\tsetAttr \".bp\" %i;\n", bp);
	}
	void getWorldMatrix(size_t wm_i)const
	{
		fprintf(mFile,"\"%s.wm[%i]\"",mName.c_str(),wm_i);
	}
	void getWorldMatrix()const
	{

		fprintf(mFile,"\"%s.wm\"",mName.c_str());
	}
	void getMembers(size_t m_i)const
	{
		fprintf(mFile,"\"%s.m[%i]\"",mName.c_str(),m_i);
	}
	void getMembers()const
	{

		fprintf(mFile,"\"%s.m\"",mName.c_str());
	}
	void getParents(size_t p_i)const
	{
		fprintf(mFile,"\"%s.p[%i]\"",mName.c_str(),p_i);
	}
	void getParents()const
	{

		fprintf(mFile,"\"%s.p\"",mName.c_str());
	}
	void getWorld()const
	{
		fprintf(mFile,"\"%s.w\"",mName.c_str());
	}
protected:
	DagPose(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_DAGPOSE_H__
