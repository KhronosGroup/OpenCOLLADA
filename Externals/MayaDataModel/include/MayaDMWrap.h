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
	Wrap(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "wrap", shared, create){}
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
	void startDropoff(size_t dr_start,size_t dr_end)const
	{
		fprintf(mFile,"\tsetAttr \".dr[%i:%i]\"",dr_start,dr_end);
	}
	void appendDropoff(double dr)const
	{
		fprintf(mFile," %f",dr);
	}
	void endDropoff()const
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
	void startSmoothness(size_t smt_start,size_t smt_end)const
	{
		fprintf(mFile,"\tsetAttr \".smt[%i:%i]\"",smt_start,smt_end);
	}
	void appendSmoothness(double smt)const
	{
		fprintf(mFile," %f",smt);
	}
	void endSmoothness()const
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
	void startInflType(size_t it_start,size_t it_end)const
	{
		fprintf(mFile,"\tsetAttr \".it[%i:%i]\"",it_start,it_end);
	}
	void appendInflType(short it)const
	{
		fprintf(mFile," %i",it);
	}
	void endInflType()const
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
	void startNurbsSamples(size_t ns_start,size_t ns_end)const
	{
		fprintf(mFile,"\tsetAttr \".ns[%i:%i]\"",ns_start,ns_end);
	}
	void appendNurbsSamples(short ns)const
	{
		fprintf(mFile," %i",ns);
	}
	void endNurbsSamples()const
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
	void getGeomMatrix()const
	{
		fprintf(mFile,"\"%s.gm\"",mName.c_str());
	}
	void getDriverPoints(size_t dp_i)const
	{
		fprintf(mFile,"\"%s.dp[%i]\"",mName.c_str(),dp_i);
	}
	void getDriverPoints()const
	{

		fprintf(mFile,"\"%s.dp\"",mName.c_str());
	}
	void getBasePoints(size_t bp_i)const
	{
		fprintf(mFile,"\"%s.bp[%i]\"",mName.c_str(),bp_i);
	}
	void getBasePoints()const
	{

		fprintf(mFile,"\"%s.bp\"",mName.c_str());
	}
	void getDropoff(size_t dr_i)const
	{
		fprintf(mFile,"\"%s.dr[%i]\"",mName.c_str(),dr_i);
	}
	void getDropoff()const
	{

		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getSmoothness(size_t smt_i)const
	{
		fprintf(mFile,"\"%s.smt[%i]\"",mName.c_str(),smt_i);
	}
	void getSmoothness()const
	{

		fprintf(mFile,"\"%s.smt\"",mName.c_str());
	}
	void getInflType(size_t it_i)const
	{
		fprintf(mFile,"\"%s.it[%i]\"",mName.c_str(),it_i);
	}
	void getInflType()const
	{

		fprintf(mFile,"\"%s.it\"",mName.c_str());
	}
	void getNurbsSamples(size_t ns_i)const
	{
		fprintf(mFile,"\"%s.ns[%i]\"",mName.c_str(),ns_i);
	}
	void getNurbsSamples()const
	{

		fprintf(mFile,"\"%s.ns\"",mName.c_str());
	}
	void getWeightThreshold()const
	{
		fprintf(mFile,"\"%s.wt\"",mName.c_str());
	}
	void getMaxDistance()const
	{
		fprintf(mFile,"\"%s.md\"",mName.c_str());
	}
	void getExclusiveBind()const
	{
		fprintf(mFile,"\"%s.rb\"",mName.c_str());
	}
	void getWtDrty()const
	{
		fprintf(mFile,"\"%s.wtd\"",mName.c_str());
	}
	void getBaseDrt()const
	{
		fprintf(mFile,"\"%s.bsd\"",mName.c_str());
	}
protected:
	Wrap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_WRAP_H__
