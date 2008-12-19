/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
	Wrap(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "wrap"){}
	virtual ~Wrap(){}
	void setGeomMatrix(const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"setAttr \".gm\" -type \"matrix\" ");
		gm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDropoff(size_t dr_i,double dr)
	{
		if(dr == 4.0) return;
		fprintf(mFile,"setAttr \".dr[%i]\" %f;\n", dr_i,dr);

	}
	void setSmoothness(size_t smt_i,double smt)
	{
		if(smt == 0.0) return;
		fprintf(mFile,"setAttr \".smt[%i]\" %f;\n", smt_i,smt);

	}
	void setInflType(size_t it_i,short it)
	{
		if(it == 2) return;
		fprintf(mFile,"setAttr \".it[%i]\" %i;\n", it_i,it);

	}
	void setNurbsSamples(size_t ns_i,short ns)
	{
		if(ns == 10) return;
		fprintf(mFile,"setAttr \".ns[%i]\" %i;\n", ns_i,ns);

	}
	void setWeightThreshold(double wt)
	{
		if(wt == 0) return;
		fprintf(mFile,"setAttr \".wt\" %f;\n", wt);

	}
	void setMaxDistance(double md)
	{
		if(md == 0) return;
		fprintf(mFile,"setAttr \".md\" %f;\n", md);

	}
	void setExclusiveBind(bool rb)
	{
		if(rb == false) return;
		fprintf(mFile,"setAttr \".rb\" %i;\n", rb);

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
	Wrap(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_WRAP_H__
