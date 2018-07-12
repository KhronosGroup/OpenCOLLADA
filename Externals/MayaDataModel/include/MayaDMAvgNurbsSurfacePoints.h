/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_AVGNURBSSURFACEPOINTS_H__
#define __MayaDM_AVGNURBSSURFACEPOINTS_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMAbstractBaseCreate.h"
namespace MayaDM
{
class AvgNurbsSurfacePoints : public AbstractBaseCreate
{
public:
	struct SurfacePoint{
		nurbsSurface inputSurface;
		double weight;
		double parameterU;
		double parameterV;
		int cvIthIndex;
		int cvJthIndex;
		void write(FILE* file) const
		{
			inputSurface.write(file);
			fprintf(file, " ");
			fprintf(file,"%f ", weight);
			fprintf(file,"%f ", parameterU);
			fprintf(file,"%f ", parameterV);
			fprintf(file,"%i ", cvIthIndex);
			fprintf(file,"%i", cvJthIndex);
		}
	};
	struct Result{
		void write(FILE* file) const
		{
		}
	};
public:

	AvgNurbsSurfacePoints():AbstractBaseCreate(){}
	AvgNurbsSurfacePoints(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, "avgNurbsSurfacePoints", shared, create){}
	virtual ~AvgNurbsSurfacePoints(){}

	void setSurfacePoint(size_t sp_i,const SurfacePoint& sp)
	{
		fprintf(mFile,"\tsetAttr \".sp[%i]\" ",sp_i);
		sp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setSurfacePoint(size_t sp_start,size_t sp_end,SurfacePoint* sp)
	{
		fprintf(mFile,"\tsetAttr \".sp[%i:%i]\" ", sp_start,sp_end);
		size_t size = (sp_end-sp_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			sp[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startSurfacePoint(size_t sp_start,size_t sp_end)const
	{
		fprintf(mFile,"\tsetAttr \".sp[%i:%i]\"",sp_start,sp_end);
		fprintf(mFile," -type \"SurfacePoint\" ");
	}
	void appendSurfacePoint(const SurfacePoint& sp)const
	{
		fprintf(mFile," ");
		sp.write(mFile);
	}
	void endSurfacePoint()const
	{
		fprintf(mFile,";\n");
	}
	void setInputSurface(size_t sp_i,const nurbsSurface& is)
	{
		fprintf(mFile,"\tsetAttr \".sp[%i].is\" -type \"nurbsSurface\" ",sp_i);
		is.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWeight(size_t sp_i,double wt)
	{
		if(wt == 0.5) return;
		fprintf(mFile,"\tsetAttr \".sp[%i].wt\" %f;\n", sp_i,wt);
	}
	void setParameterU(size_t sp_i,double u)
	{
		if(u == -1000.0) return;
		fprintf(mFile,"\tsetAttr \".sp[%i].u\" %f;\n", sp_i,u);
	}
	void setParameterV(size_t sp_i,double v)
	{
		if(v == -1000.0) return;
		fprintf(mFile,"\tsetAttr \".sp[%i].v\" %f;\n", sp_i,v);
	}
	void setCvIthIndex(size_t sp_i,int ci)
	{
		if(ci == -1) return;
		fprintf(mFile,"\tsetAttr \".sp[%i].ci\" %i;\n", sp_i,ci);
	}
	void setCvJthIndex(size_t sp_i,int cj)
	{
		if(cj == -1) return;
		fprintf(mFile,"\tsetAttr \".sp[%i].cj\" %i;\n", sp_i,cj);
	}
	void getInputSurface(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i].is\"",mName.c_str(),sp_i);
	}
	void getInputSurface()const
	{

		fprintf(mFile,"\"%s.sp.is\"",mName.c_str());
	}
	void getWeight(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i].wt\"",mName.c_str(),sp_i);
	}
	void getWeight()const
	{

		fprintf(mFile,"\"%s.sp.wt\"",mName.c_str());
	}
	void getParameterU(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i].u\"",mName.c_str(),sp_i);
	}
	void getParameterU()const
	{

		fprintf(mFile,"\"%s.sp.u\"",mName.c_str());
	}
	void getParameterV(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i].v\"",mName.c_str(),sp_i);
	}
	void getParameterV()const
	{

		fprintf(mFile,"\"%s.sp.v\"",mName.c_str());
	}
	void getCvIthIndex(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i].ci\"",mName.c_str(),sp_i);
	}
	void getCvIthIndex()const
	{

		fprintf(mFile,"\"%s.sp.ci\"",mName.c_str());
	}
	void getCvJthIndex(size_t sp_i)const
	{
		fprintf(mFile,"\"%s.sp[%i].cj\"",mName.c_str(),sp_i);
	}
	void getCvJthIndex()const
	{

		fprintf(mFile,"\"%s.sp.cj\"",mName.c_str());
	}
	void getResult()const
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());
	}
	void getPosition()const
	{
		fprintf(mFile,"\"%s.r.p\"",mName.c_str());
	}
	void getPositionX()const
	{
		fprintf(mFile,"\"%s.r.p.px\"",mName.c_str());
	}
	void getPositionY()const
	{
		fprintf(mFile,"\"%s.r.p.py\"",mName.c_str());
	}
	void getPositionZ()const
	{
		fprintf(mFile,"\"%s.r.p.pz\"",mName.c_str());
	}
	void getNormal()const
	{
		fprintf(mFile,"\"%s.r.n\"",mName.c_str());
	}
	void getNormalX()const
	{
		fprintf(mFile,"\"%s.r.n.nx\"",mName.c_str());
	}
	void getNormalY()const
	{
		fprintf(mFile,"\"%s.r.n.ny\"",mName.c_str());
	}
	void getNormalZ()const
	{
		fprintf(mFile,"\"%s.r.n.nz\"",mName.c_str());
	}
protected:
	AvgNurbsSurfacePoints(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:AbstractBaseCreate(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_AVGNURBSSURFACEPOINTS_H__
