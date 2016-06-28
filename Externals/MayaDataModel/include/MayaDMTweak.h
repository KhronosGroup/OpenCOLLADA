/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_TWEAK_H__
#define __MayaDM_TWEAK_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class Tweak : public GeometryFilter
{
public:
	struct Plist{
		double3* controlPoints;
		size_t nbControlPoints;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbControlPoints; ++i)
			{
				controlPoints[i].write(file);
				if (i + 1<nbControlPoints) fprintf(file, " ");
			}
		}
	};
	struct Vlist{
		float3* vertex;
		size_t nbVertex;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbVertex; ++i)
			{
				vertex[i].write(file);
				if (i + 1<nbVertex) fprintf(file, " ");
			}
		}
	};
public:

	Tweak():GeometryFilter(){}
	Tweak(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "tweak", shared, create){}
	virtual ~Tweak(){}

	void setRelativeTweak(bool rtw)
	{
		if(rtw == true) return;
		fprintf(mFile,"\tsetAttr \".rtw\" %i;\n", rtw);
	}
	void setPlist(size_t pl_i,const Plist& pl)
	{
		fprintf(mFile,"\tsetAttr \".pl[%i]\" ",pl_i);
		pl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setPlist(size_t pl_start,size_t pl_end,Plist* pl)
	{
		fprintf(mFile,"\tsetAttr \".pl[%i:%i]\" ", pl_start,pl_end);
		size_t size = (pl_end-pl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			pl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startPlist(size_t pl_start,size_t pl_end)const
	{
		fprintf(mFile,"\tsetAttr \".pl[%i:%i]\"",pl_start,pl_end);
		fprintf(mFile," -type \"Plist\" ");
	}
	void appendPlist(const Plist& pl)const
	{
		fprintf(mFile," ");
		pl.write(mFile);
	}
	void endPlist()const
	{
		fprintf(mFile,";\n");
	}
	void setControlPoints(size_t pl_i,size_t cp_i,const double3& cp)
	{
		fprintf(mFile,"\tsetAttr \".pl[%i].cp[%i]\" -type \"double3\" ",pl_i,cp_i);
		cp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setControlPoints(size_t pl_i,size_t cp_start,size_t cp_end,double* cp)
	{
		fprintf(mFile,"\tsetAttr \".pl[%i].cp[%i:%i]\" ", pl_i,cp_start,cp_end);
		size_t size = (cp_end-cp_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startControlPoints(size_t pl_i,size_t cp_start,size_t cp_end)const
	{
		fprintf(mFile,"\tsetAttr \".pl[%i].cp[%i:%i]\"",pl_i,cp_start,cp_end);
	}
	void appendControlPoints(double cp)const
	{
		fprintf(mFile," %f",cp);
	}
	void endControlPoints()const
	{
		fprintf(mFile,";\n");
	}
	void setXValue(size_t pl_i,size_t cp_i,double xv)
	{
		if(xv == 0) return;
		fprintf(mFile,"\tsetAttr \".pl[%i].cp[%i].xv\" %f;\n", pl_i,cp_i,xv);
	}
	void setYValue(size_t pl_i,size_t cp_i,double yv)
	{
		if(yv == 0) return;
		fprintf(mFile,"\tsetAttr \".pl[%i].cp[%i].yv\" %f;\n", pl_i,cp_i,yv);
	}
	void setZValue(size_t pl_i,size_t cp_i,double zv)
	{
		if(zv == 0) return;
		fprintf(mFile,"\tsetAttr \".pl[%i].cp[%i].zv\" %f;\n", pl_i,cp_i,zv);
	}
	void setVlist(size_t vl_i,const Vlist& vl)
	{
		fprintf(mFile,"\tsetAttr \".vl[%i]\" ",vl_i);
		vl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVlist(size_t vl_start,size_t vl_end,Vlist* vl)
	{
		fprintf(mFile,"\tsetAttr \".vl[%i:%i]\" ", vl_start,vl_end);
		size_t size = (vl_end-vl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			vl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startVlist(size_t vl_start,size_t vl_end)const
	{
		fprintf(mFile,"\tsetAttr \".vl[%i:%i]\"",vl_start,vl_end);
		fprintf(mFile," -type \"Vlist\" ");
	}
	void appendVlist(const Vlist& vl)const
	{
		fprintf(mFile," ");
		vl.write(mFile);
	}
	void endVlist()const
	{
		fprintf(mFile,";\n");
	}
	void setVertex(size_t vl_i,size_t vt_i,const float3& vt)
	{
		fprintf(mFile,"\tsetAttr \".vl[%i].vt[%i]\" -type \"float3\" ",vl_i,vt_i);
		vt.write(mFile);
		fprintf(mFile,";\n");
	}
	void setVertex(size_t vl_i,size_t vt_start,size_t vt_end,float* vt)
	{
		fprintf(mFile,"\tsetAttr \".vl[%i].vt[%i:%i]\" ", vl_i,vt_start,vt_end);
		size_t size = (vt_end-vt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",vt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startVertex(size_t vl_i,size_t vt_start,size_t vt_end)const
	{
		fprintf(mFile,"\tsetAttr \".vl[%i].vt[%i:%i]\"",vl_i,vt_start,vt_end);
	}
	void appendVertex(float vt)const
	{
		fprintf(mFile," %f",vt);
	}
	void endVertex()const
	{
		fprintf(mFile,";\n");
	}
	void setXVertex(size_t vl_i,size_t vt_i,float vx)
	{
		if(vx == 0) return;
		fprintf(mFile,"\tsetAttr \".vl[%i].vt[%i].vx\" %f;\n", vl_i,vt_i,vx);
	}
	void setYVertex(size_t vl_i,size_t vt_i,float vy)
	{
		if(vy == 0) return;
		fprintf(mFile,"\tsetAttr \".vl[%i].vt[%i].vy\" %f;\n", vl_i,vt_i,vy);
	}
	void setZVertex(size_t vl_i,size_t vt_i,float vz)
	{
		if(vz == 0) return;
		fprintf(mFile,"\tsetAttr \".vl[%i].vt[%i].vz\" %f;\n", vl_i,vt_i,vz);
	}
	void getRelativeTweak()const
	{
		fprintf(mFile,"\"%s.rtw\"",mName.c_str());
	}
	void getPlist(size_t pl_i)const
	{
		fprintf(mFile,"\"%s.pl[%i]\"",mName.c_str(),pl_i);
	}
	void getPlist()const
	{

		fprintf(mFile,"\"%s.pl\"",mName.c_str());
	}
	void getControlPoints(size_t pl_i,size_t cp_i)const
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i]\"",mName.c_str(),pl_i,cp_i);
	}
	void getControlPoints(size_t cp_i)const
	{

		fprintf(mFile,"\"%s.pl.cp[%i]\"",mName.c_str(),cp_i);
	}
	void getXValue(size_t pl_i,size_t cp_i)const
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i].xv\"",mName.c_str(),pl_i,cp_i);
	}
	void getXValue(size_t cp_i)const
	{

		fprintf(mFile,"\"%s.pl.cp[%i].xv\"",mName.c_str(),cp_i);
	}
	void getYValue(size_t pl_i,size_t cp_i)const
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i].yv\"",mName.c_str(),pl_i,cp_i);
	}
	void getYValue(size_t cp_i)const
	{

		fprintf(mFile,"\"%s.pl.cp[%i].yv\"",mName.c_str(),cp_i);
	}
	void getZValue(size_t pl_i,size_t cp_i)const
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i].zv\"",mName.c_str(),pl_i,cp_i);
	}
	void getZValue(size_t cp_i)const
	{

		fprintf(mFile,"\"%s.pl.cp[%i].zv\"",mName.c_str(),cp_i);
	}
	void getVlist(size_t vl_i)const
	{
		fprintf(mFile,"\"%s.vl[%i]\"",mName.c_str(),vl_i);
	}
	void getVlist()const
	{

		fprintf(mFile,"\"%s.vl\"",mName.c_str());
	}
	void getVertex(size_t vl_i,size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i]\"",mName.c_str(),vl_i,vt_i);
	}
	void getVertex(size_t vt_i)const
	{

		fprintf(mFile,"\"%s.vl.vt[%i]\"",mName.c_str(),vt_i);
	}
	void getXVertex(size_t vl_i,size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i].vx\"",mName.c_str(),vl_i,vt_i);
	}
	void getXVertex(size_t vt_i)const
	{

		fprintf(mFile,"\"%s.vl.vt[%i].vx\"",mName.c_str(),vt_i);
	}
	void getYVertex(size_t vl_i,size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i].vy\"",mName.c_str(),vl_i,vt_i);
	}
	void getYVertex(size_t vt_i)const
	{

		fprintf(mFile,"\"%s.vl.vt[%i].vy\"",mName.c_str(),vt_i);
	}
	void getZVertex(size_t vl_i,size_t vt_i)const
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i].vz\"",mName.c_str(),vl_i,vt_i);
	}
	void getZVertex(size_t vt_i)const
	{

		fprintf(mFile,"\"%s.vl.vt[%i].vz\"",mName.c_str(),vt_i);
	}
protected:
	Tweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_TWEAK_H__
