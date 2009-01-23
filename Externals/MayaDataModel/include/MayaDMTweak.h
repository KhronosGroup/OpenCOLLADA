/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		void write(FILE* file) const
		{
			size_t size = sizeof(controlPoints)/sizeof(double3);
			for(size_t i=0; i<size; ++i)
			{
				controlPoints[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
	struct Vlist{
		float3* vertex;
		void write(FILE* file) const
		{
			size_t size = sizeof(vertex)/sizeof(float3);
			for(size_t i=0; i<size; ++i)
			{
				vertex[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	Tweak(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "tweak"){}
	virtual ~Tweak(){}
	void setRelativeTweak(bool rtw)
	{
		if(rtw == true) return;
		fprintf(mFile,"setAttr \".rtw\" %i;\n", rtw);

	}
	void setPlist(size_t pl_i,const Plist& pl)
	{
		fprintf(mFile,"setAttr \".pl[%i]\" ",pl_i);
		pl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setControlPoints(size_t pl_i,size_t cp_i,const double3& cp)
	{
		fprintf(mFile,"setAttr \".pl[%i].cp[%i]\" -type \"double3\" ",pl_i,cp_i);
		cp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setControlPoints(size_t pl_i,size_t cp_start,size_t cp_end,double* cp)
	{
		fprintf(mFile,"setAttr \".pl[%i].cp[%i:%i]\" ", pl_i,cp_start,cp_end);
		size_t size = (cp_end-cp_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",cp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startControlPoints(size_t pl_i,size_t cp_start,size_t cp_end)
	{
		fprintf(mFile,"setAttr \".pl[%i].cp[%i:%i]\"",pl_i,cp_start,cp_end);

	}
	void appendControlPoints(double cp)
	{
		fprintf(mFile," %f",cp);

	}
	void endControlPoints()
	{
		fprintf(mFile,";\n");

	}
	void setXValue(size_t pl_i,size_t cp_i,double xv)
	{
		if(xv == 0) return;
		fprintf(mFile,"setAttr \".pl[%i].cp[%i].xv\" %f;\n", pl_i,cp_i,xv);

	}
	void setYValue(size_t pl_i,size_t cp_i,double yv)
	{
		if(yv == 0) return;
		fprintf(mFile,"setAttr \".pl[%i].cp[%i].yv\" %f;\n", pl_i,cp_i,yv);

	}
	void setZValue(size_t pl_i,size_t cp_i,double zv)
	{
		if(zv == 0) return;
		fprintf(mFile,"setAttr \".pl[%i].cp[%i].zv\" %f;\n", pl_i,cp_i,zv);

	}
	void setVlist(size_t vl_i,const Vlist& vl)
	{
		fprintf(mFile,"setAttr \".vl[%i]\" ",vl_i);
		vl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertex(size_t vl_i,size_t vt_i,const float3& vt)
	{
		fprintf(mFile,"setAttr \".vl[%i].vt[%i]\" -type \"float3\" ",vl_i,vt_i);
		vt.write(mFile);
		fprintf(mFile,";\n");

	}
	void setVertex(size_t vl_i,size_t vt_start,size_t vt_end,float* vt)
	{
		fprintf(mFile,"setAttr \".vl[%i].vt[%i:%i]\" ", vl_i,vt_start,vt_end);
		size_t size = (vt_end-vt_start)*3+3;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",vt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startVertex(size_t vl_i,size_t vt_start,size_t vt_end)
	{
		fprintf(mFile,"setAttr \".vl[%i].vt[%i:%i]\"",vl_i,vt_start,vt_end);

	}
	void appendVertex(float vt)
	{
		fprintf(mFile," %f",vt);

	}
	void endVertex()
	{
		fprintf(mFile,";\n");

	}
	void setXVertex(size_t vl_i,size_t vt_i,float vx)
	{
		if(vx == 0) return;
		fprintf(mFile,"setAttr \".vl[%i].vt[%i].vx\" %f;\n", vl_i,vt_i,vx);

	}
	void setYVertex(size_t vl_i,size_t vt_i,float vy)
	{
		if(vy == 0) return;
		fprintf(mFile,"setAttr \".vl[%i].vt[%i].vy\" %f;\n", vl_i,vt_i,vy);

	}
	void setZVertex(size_t vl_i,size_t vt_i,float vz)
	{
		if(vz == 0) return;
		fprintf(mFile,"setAttr \".vl[%i].vt[%i].vz\" %f;\n", vl_i,vt_i,vz);

	}
	void getRelativeTweak()
	{
		fprintf(mFile,"\"%s.rtw\"",mName.c_str());

	}
	void getPlist(size_t pl_i)
	{
		fprintf(mFile,"\"%s.pl[%i]\"",mName.c_str(),pl_i);

	}
	void getControlPoints(size_t pl_i,size_t cp_i)
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i]\"",mName.c_str(),pl_i,cp_i);

	}
	void getXValue(size_t pl_i,size_t cp_i)
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i].xv\"",mName.c_str(),pl_i,cp_i);

	}
	void getYValue(size_t pl_i,size_t cp_i)
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i].yv\"",mName.c_str(),pl_i,cp_i);

	}
	void getZValue(size_t pl_i,size_t cp_i)
	{
		fprintf(mFile,"\"%s.pl[%i].cp[%i].zv\"",mName.c_str(),pl_i,cp_i);

	}
	void getVlist(size_t vl_i)
	{
		fprintf(mFile,"\"%s.vl[%i]\"",mName.c_str(),vl_i);

	}
	void getVertex(size_t vl_i,size_t vt_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i]\"",mName.c_str(),vl_i,vt_i);

	}
	void getXVertex(size_t vl_i,size_t vt_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i].vx\"",mName.c_str(),vl_i,vt_i);

	}
	void getYVertex(size_t vl_i,size_t vt_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i].vy\"",mName.c_str(),vl_i,vt_i);

	}
	void getZVertex(size_t vl_i,size_t vt_i)
	{
		fprintf(mFile,"\"%s.vl[%i].vt[%i].vz\"",mName.c_str(),vl_i,vt_i);

	}
protected:
	Tweak(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_TWEAK_H__
