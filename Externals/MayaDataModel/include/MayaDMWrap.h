/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_WRAP_H__
#define __MayaDM_WRAP_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class Wrap : public GeometryFilter
{
public:
public:
	Wrap():GeometryFilter(){}
	Wrap(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "wrap"){}
	virtual ~Wrap(){}
	void setGeomMatrix(const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"\tsetAttr \".gm\" -type \"matrix\" ");
		gm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDropoff(size_t dr_i,double dr)
	{
		if(dr == 4.0) return;
		fprintf(mFile,"\tsetAttr \".dr[%i]\" %f;\n", dr_i,dr);

	}
	void setDropoff(size_t dr_start,size_t dr_end,double* dr)
	{
		fprintf(mFile,"\tsetAttr \".dr[%i:%i]\" ", dr_start,dr_end);
		size_t size = (dr_end-dr_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",dr[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startDropoff(size_t dr_start,size_t dr_end)
	{
		fprintf(mFile,"\tsetAttr \".dr[%i:%i]\"",dr_start,dr_end);

	}
	void appendDropoff(double dr)
	{
		fprintf(mFile," %f",dr);

	}
	void endDropoff()
	{
		fprintf(mFile,";\n");

	}
	void setSmoothness(size_t smt_i,double smt)
	{
		if(smt == 0.0) return;
		fprintf(mFile,"\tsetAttr \".smt[%i]\" %f;\n", smt_i,smt);

	}
	void setSmoothness(size_t smt_start,size_t smt_end,double* smt)
	{
		fprintf(mFile,"\tsetAttr \".smt[%i:%i]\" ", smt_start,smt_end);
		size_t size = (smt_end-smt_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",smt[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startSmoothness(size_t smt_start,size_t smt_end)
	{
		fprintf(mFile,"\tsetAttr \".smt[%i:%i]\"",smt_start,smt_end);

	}
	void appendSmoothness(double smt)
	{
		fprintf(mFile," %f",smt);

	}
	void endSmoothness()
	{
		fprintf(mFile,";\n");

	}
	void setInflType(size_t it_i,short it)
	{
		if(it == 2) return;
		fprintf(mFile,"\tsetAttr \".it[%i]\" %i;\n", it_i,it);

	}
	void setInflType(size_t it_start,size_t it_end,short* it)
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\" ", it_start,it_end);
		size_t size = (it_end-it_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",it[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startInflType(size_t it_start,size_t it_end)
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\"",it_start,it_end);

	}
	void appendInflType(short it)
	{
		fprintf(mFile," %i",it);

	}
	void endInflType()
	{
		fprintf(mFile,";\n");

	}
	void setNurbsSamples(size_t ns_i,short ns)
	{
		if(ns == 10) return;
		fprintf(mFile,"\tsetAttr \".ns[%i]\" %i;\n", ns_i,ns);

	}
	void setNurbsSamples(size_t ns_start,size_t ns_end,short* ns)
	{
		fprintf(mFile,"\tsetAttr \".ns[%i:%i]\" ", ns_start,ns_end);
		size_t size = (ns_end-ns_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",ns[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startNurbsSamples(size_t ns_start,size_t ns_end)
	{
		fprintf(mFile,"\tsetAttr \".ns[%i:%i]\"",ns_start,ns_end);

	}
	void appendNurbsSamples(short ns)
	{
		fprintf(mFile," %i",ns);

	}
	void endNurbsSamples()
	{
		fprintf(mFile,";\n");

	}
	void setWeightThreshold(double wt)
	{
		if(wt == 0) return;
		fprintf(mFile,"\tsetAttr \".wt\" %f;\n", wt);

	}
	void setMaxDistance(double md)
	{
		if(md == 0) return;
		fprintf(mFile,"\tsetAttr \".md\" %f;\n", md);

	}
	void setExclusiveBind(bool rb)
	{
		if(rb == false) return;
		fprintf(mFile,"\tsetAttr \".rb\" %i;\n", rb);

	}
	void getGeomMatrix()
	{
		fprintf(mFile,"\"%s.gm\"",mName.c_str());

	}
	void getDriverPoints(size_t dp_i)
	{
		fprintf(mFile,"\"%s.dp[%i]\"",mName.c_str(),dp_i);

	}
	void getBasePoints(size_t bp_i)
	{
		fprintf(mFile,"\"%s.bp[%i]\"",mName.c_str(),bp_i);

	}
	void getDropoff(size_t dr_i)
	{
		fprintf(mFile,"\"%s.dr[%i]\"",mName.c_str(),dr_i);

	}
	void getSmoothness(size_t smt_i)
	{
		fprintf(mFile,"\"%s.smt[%i]\"",mName.c_str(),smt_i);

	}
	void getInflType(size_t it_i)
	{
		fprintf(mFile,"\"%s.it[%i]\"",mName.c_str(),it_i);

	}
	void getNurbsSamples(size_t ns_i)
	{
		fprintf(mFile,"\"%s.ns[%i]\"",mName.c_str(),ns_i);

	}
	void getWeightThreshold()
	{
		fprintf(mFile,"\"%s.wt\"",mName.c_str());

	}
	void getMaxDistance()
	{
		fprintf(mFile,"\"%s.md\"",mName.c_str());

	}
	void getExclusiveBind()
	{
		fprintf(mFile,"\"%s.rb\"",mName.c_str());

	}
	void getWtDrty()
	{
		fprintf(mFile,"\"%s.wtd\"",mName.c_str());

	}
	void getBaseDrt()
	{
		fprintf(mFile,"\"%s.bsd\"",mName.c_str());

	}
protected:
	Wrap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType)
		:GeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_WRAP_H__
