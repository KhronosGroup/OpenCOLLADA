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
	AvgNurbsSurfacePoints(FILE* file,const std::string& name,const std::string& parent=""):AbstractBaseCreate(file, name, parent, "avgNurbsSurfacePoints"){}
	virtual ~AvgNurbsSurfacePoints(){}
	void setSurfacePoint(size_t sp_i,const SurfacePoint& sp)
	{
		fprintf(mFile,"\tsetAttr \".sp[%i]\" ",sp_i);
		sp.write(mFile);
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
	void getInputSurface(size_t sp_i)
	{
		fprintf(mFile,"\"%s.sp[%i].is\"",mName.c_str(),sp_i);

	}
	void getWeight(size_t sp_i)
	{
		fprintf(mFile,"\"%s.sp[%i].wt\"",mName.c_str(),sp_i);

	}
	void getParameterU(size_t sp_i)
	{
		fprintf(mFile,"\"%s.sp[%i].u\"",mName.c_str(),sp_i);

	}
	void getParameterV(size_t sp_i)
	{
		fprintf(mFile,"\"%s.sp[%i].v\"",mName.c_str(),sp_i);

	}
	void getCvIthIndex(size_t sp_i)
	{
		fprintf(mFile,"\"%s.sp[%i].ci\"",mName.c_str(),sp_i);

	}
	void getCvJthIndex(size_t sp_i)
	{
		fprintf(mFile,"\"%s.sp[%i].cj\"",mName.c_str(),sp_i);

	}
	void getResult()
	{
		fprintf(mFile,"\"%s.r\"",mName.c_str());

	}
	void getPosition()
	{
		fprintf(mFile,"\"%s.r.p\"",mName.c_str());

	}
	void getPositionX()
	{
		fprintf(mFile,"\"%s.r.p.px\"",mName.c_str());

	}
	void getPositionY()
	{
		fprintf(mFile,"\"%s.r.p.py\"",mName.c_str());

	}
	void getPositionZ()
	{
		fprintf(mFile,"\"%s.r.p.pz\"",mName.c_str());

	}
	void getNormal()
	{
		fprintf(mFile,"\"%s.r.n\"",mName.c_str());

	}
	void getNormalX()
	{
		fprintf(mFile,"\"%s.r.n.nx\"",mName.c_str());

	}
	void getNormalY()
	{
		fprintf(mFile,"\"%s.r.n.ny\"",mName.c_str());

	}
	void getNormalZ()
	{
		fprintf(mFile,"\"%s.r.n.nz\"",mName.c_str());

	}
protected:
	AvgNurbsSurfacePoints(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:AbstractBaseCreate(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_AVGNURBSSURFACEPOINTS_H__
