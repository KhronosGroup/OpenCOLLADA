/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_SKINCLUSTER_H__
#define __MayaDM_SKINCLUSTER_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMGeometryFilter.h"
namespace MayaDM
{
class SkinCluster : public GeometryFilter
{
public:
	struct WeightList{
		double* weights;
		size_t nbWeights;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbWeights; ++i)
			{
				fprintf(file,"%f", weights[i]);
				if (i + 1<nbWeights) fprintf(file, " ");
			}
		}
	};
public:

	SkinCluster():GeometryFilter(){}
	SkinCluster(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, "skinCluster", shared, create){}
	virtual ~SkinCluster(){}

	void setWeightList(size_t wl_i,const WeightList& wl)
	{
		fprintf(mFile,"\tsetAttr \".wl[%i]\" ",wl_i);
		wl.write(mFile);
		fprintf(mFile,";\n");
	}
	void setWeightList(size_t wl_start,size_t wl_end,WeightList* wl)
	{
		fprintf(mFile,"\tsetAttr \".wl[%i:%i]\" ", wl_start,wl_end);
		size_t size = (wl_end-wl_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			wl[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startWeightList(size_t wl_start,size_t wl_end)const
	{
		fprintf(mFile,"\tsetAttr \".wl[%i:%i]\"",wl_start,wl_end);
		fprintf(mFile," -type \"WeightList\" ");
	}
	void appendWeightList(const WeightList& wl)const
	{
		fprintf(mFile," ");
		wl.write(mFile);
	}
	void endWeightList()const
	{
		fprintf(mFile,";\n");
	}
	void setWeights(size_t wl_i,size_t w_i,double w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"\tsetAttr \".wl[%i].w[%i]\" %f;\n", wl_i,w_i,w);
	}
	void setWeights(size_t wl_i,size_t w_start,size_t w_end,double* w)
	{
		fprintf(mFile,"\tsetAttr \".wl[%i].w[%i:%i]\" ", wl_i,w_start,w_end);
		size_t size = (w_end-w_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",w[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startWeights(size_t wl_i,size_t w_start,size_t w_end)const
	{
		fprintf(mFile,"\tsetAttr \".wl[%i].w[%i:%i]\"",wl_i,w_start,w_end);
	}
	void appendWeights(double w)const
	{
		fprintf(mFile," %f",w);
	}
	void endWeights()const
	{
		fprintf(mFile,";\n");
	}
	void setBindPreMatrix(size_t pm_i,const matrix& pm)
	{
		if(pm == identity) return;
		fprintf(mFile,"\tsetAttr \".pm[%i]\" -type \"matrix\" ",pm_i);
		pm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setBindPreMatrix(size_t pm_start,size_t pm_end,matrix* pm)
	{
		fprintf(mFile,"\tsetAttr \".pm[%i:%i]\" ", pm_start,pm_end);
		size_t size = (pm_end-pm_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			pm[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startBindPreMatrix(size_t pm_start,size_t pm_end)const
	{
		fprintf(mFile,"\tsetAttr \".pm[%i:%i]\"",pm_start,pm_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendBindPreMatrix(const matrix& pm)const
	{
		fprintf(mFile," ");
		pm.write(mFile);
	}
	void endBindPreMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setGeomMatrix(const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"\tsetAttr \".gm\" -type \"matrix\" ");
		gm.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMatrix(size_t ma_i,const matrix& ma)
	{
		if(ma == identity) return;
		fprintf(mFile,"\tsetAttr \".ma[%i]\" -type \"matrix\" ",ma_i);
		ma.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMatrix(size_t ma_start,size_t ma_end,matrix* ma)
	{
		fprintf(mFile,"\tsetAttr \".ma[%i:%i]\" ", ma_start,ma_end);
		size_t size = (ma_end-ma_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			ma[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startMatrix(size_t ma_start,size_t ma_end)const
	{
		fprintf(mFile,"\tsetAttr \".ma[%i:%i]\"",ma_start,ma_end);
		fprintf(mFile," -type \"matrix\" ");
	}
	void appendMatrix(const matrix& ma)const
	{
		fprintf(mFile," ");
		ma.write(mFile);
	}
	void endMatrix()const
	{
		fprintf(mFile,";\n");
	}
	void setDropoff(size_t dpf_i,double dpf)
	{
		if(dpf == 4.0) return;
		fprintf(mFile,"\tsetAttr \".dpf[%i]\" %f;\n", dpf_i,dpf);
	}
	void setDropoff(size_t dpf_start,size_t dpf_end,double* dpf)
	{
		fprintf(mFile,"\tsetAttr \".dpf[%i:%i]\" ", dpf_start,dpf_end);
		size_t size = (dpf_end-dpf_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",dpf[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startDropoff(size_t dpf_start,size_t dpf_end)const
	{
		fprintf(mFile,"\tsetAttr \".dpf[%i:%i]\"",dpf_start,dpf_end);
	}
	void appendDropoff(double dpf)const
	{
		fprintf(mFile," %f",dpf);
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
	void setLockWeights(size_t lw_i,bool lw)
	{
		if(lw == false) return;
		fprintf(mFile,"\tsetAttr \".lw[%i]\" %i;\n", lw_i,lw);
	}
	void setLockWeights(size_t lw_start,size_t lw_end,bool* lw)
	{
		fprintf(mFile,"\tsetAttr \".lw[%i:%i]\" ", lw_start,lw_end);
		size_t size = (lw_end-lw_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%i",lw[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startLockWeights(size_t lw_start,size_t lw_end)const
	{
		fprintf(mFile,"\tsetAttr \".lw[%i:%i]\"",lw_start,lw_end);
	}
	void appendLockWeights(bool lw)const
	{
		fprintf(mFile," %i",lw);
	}
	void endLockWeights()const
	{
		fprintf(mFile,";\n");
	}
	void setMaintainMaxInfluences(bool mmi)
	{
		if(mmi == false) return;
		fprintf(mFile,"\tsetAttr \".mmi\" %i;\n", mmi);
	}
	void setMaxInfluences(int mi)
	{
		if(mi == 2) return;
		fprintf(mFile,"\tsetAttr \".mi\" %i;\n", mi);
	}
	void setBindMethod(int bm)
	{
		if(bm == 1) return;
		fprintf(mFile,"\tsetAttr \".bm\" %i;\n", bm);
	}
	void setPaintWeights(const doubleArray& ptw)
	{
		if(ptw.size == 0) return;
		fprintf(mFile,"\tsetAttr \".ptw\" -type \"doubleArray\" ");
		ptw.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUseComponents(bool uc)
	{
		if(uc == 0) return;
		fprintf(mFile,"\tsetAttr \".uc\" %i;\n", uc);
	}
	void setNurbsSamples(size_t ns_i,int ns)
	{
		if(ns == 10) return;
		fprintf(mFile,"\tsetAttr \".ns[%i]\" %i;\n", ns_i,ns);
	}
	void setNurbsSamples(size_t ns_start,size_t ns_end,int* ns)
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
	void appendNurbsSamples(int ns)const
	{
		fprintf(mFile," %i",ns);
	}
	void endNurbsSamples()const
	{
		fprintf(mFile,";\n");
	}
	void setUseComponentsMatrix(bool ucm)
	{
		if(ucm == false) return;
		fprintf(mFile,"\tsetAttr \".ucm\" %i;\n", ucm);
	}
	void setNormalizeWeights(bool nw)
	{
		if(nw == true) return;
		fprintf(mFile,"\tsetAttr \".nw\" %i;\n", nw);
	}
	void setDeformUserNormals(bool dun)
	{
		if(dun == true) return;
		fprintf(mFile,"\tsetAttr \".dun\" %i;\n", dun);
	}
	void getWeightList(size_t wl_i)const
	{
		fprintf(mFile,"\"%s.wl[%i]\"",mName.c_str(),wl_i);
	}
	void getWeightList()const
	{

		fprintf(mFile,"\"%s.wl\"",mName.c_str());
	}
	void getWeights(size_t wl_i,size_t w_i)const
	{
		fprintf(mFile,"\"%s.wl[%i].w[%i]\"",mName.c_str(),wl_i,w_i);
	}
	void getWeights(size_t w_i)const
	{

		fprintf(mFile,"\"%s.wl.w[%i]\"",mName.c_str(),w_i);
	}
	void getBindPreMatrix(size_t pm_i)const
	{
		fprintf(mFile,"\"%s.pm[%i]\"",mName.c_str(),pm_i);
	}
	void getBindPreMatrix()const
	{

		fprintf(mFile,"\"%s.pm\"",mName.c_str());
	}
	void getGeomMatrix()const
	{
		fprintf(mFile,"\"%s.gm\"",mName.c_str());
	}
	void getMatrix(size_t ma_i)const
	{
		fprintf(mFile,"\"%s.ma[%i]\"",mName.c_str(),ma_i);
	}
	void getMatrix()const
	{

		fprintf(mFile,"\"%s.ma\"",mName.c_str());
	}
	void getDropoffRate()const
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());
	}
	void getDropoff(size_t dpf_i)const
	{
		fprintf(mFile,"\"%s.dpf[%i]\"",mName.c_str(),dpf_i);
	}
	void getDropoff()const
	{

		fprintf(mFile,"\"%s.dpf\"",mName.c_str());
	}
	void getSmoothness(size_t smt_i)const
	{
		fprintf(mFile,"\"%s.smt[%i]\"",mName.c_str(),smt_i);
	}
	void getSmoothness()const
	{

		fprintf(mFile,"\"%s.smt\"",mName.c_str());
	}
	void getLockWeights(size_t lw_i)const
	{
		fprintf(mFile,"\"%s.lw[%i]\"",mName.c_str(),lw_i);
	}
	void getLockWeights()const
	{

		fprintf(mFile,"\"%s.lw\"",mName.c_str());
	}
	void getMaintainMaxInfluences()const
	{
		fprintf(mFile,"\"%s.mmi\"",mName.c_str());
	}
	void getMaxInfluences()const
	{
		fprintf(mFile,"\"%s.mi\"",mName.c_str());
	}
	void getBindMethod()const
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());
	}
	void getDriverPoints(size_t drp_i)const
	{
		fprintf(mFile,"\"%s.drp[%i]\"",mName.c_str(),drp_i);
	}
	void getDriverPoints()const
	{

		fprintf(mFile,"\"%s.drp\"",mName.c_str());
	}
	void getBasePoints(size_t bsp_i)const
	{
		fprintf(mFile,"\"%s.bsp[%i]\"",mName.c_str(),bsp_i);
	}
	void getBasePoints()const
	{

		fprintf(mFile,"\"%s.bsp\"",mName.c_str());
	}
	void getBaseDirty()const
	{
		fprintf(mFile,"\"%s.bsd\"",mName.c_str());
	}
	void getPaintWeights()const
	{
		fprintf(mFile,"\"%s.ptw\"",mName.c_str());
	}
	void getPaintTrans()const
	{
		fprintf(mFile,"\"%s.ptt\"",mName.c_str());
	}
	void getPaintArrDirty()const
	{
		fprintf(mFile,"\"%s.pad\"",mName.c_str());
	}
	void getUseComponents()const
	{
		fprintf(mFile,"\"%s.uc\"",mName.c_str());
	}
	void getNurbsSamples(size_t ns_i)const
	{
		fprintf(mFile,"\"%s.ns[%i]\"",mName.c_str(),ns_i);
	}
	void getNurbsSamples()const
	{

		fprintf(mFile,"\"%s.ns\"",mName.c_str());
	}
	void getUseComponentsMatrix()const
	{
		fprintf(mFile,"\"%s.ucm\"",mName.c_str());
	}
	void getNormalizeWeights()const
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());
	}
	void getDeformUserNormals()const
	{
		fprintf(mFile,"\"%s.dun\"",mName.c_str());
	}
	void getWtDrty()const
	{
		fprintf(mFile,"\"%s.wtd\"",mName.c_str());
	}
	void getBindPose()const
	{
		fprintf(mFile,"\"%s.bp\"",mName.c_str());
	}
protected:
	SkinCluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:GeometryFilter(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_SKINCLUSTER_H__
