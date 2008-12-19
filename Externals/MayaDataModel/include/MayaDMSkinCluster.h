/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		void write(FILE* file) const
		{
			size_t size = sizeof(weights)/sizeof(double);
			for(size_t i=0; i<size; ++i)
			{
				fprintf(file,"%f", weights[i]);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	SkinCluster(FILE* file,const std::string& name,const std::string& parent=""):GeometryFilter(file, name, parent, "skinCluster"){}
	virtual ~SkinCluster(){}
	void setWeightList(size_t wl_i,const WeightList& wl)
	{
		fprintf(mFile,"setAttr \".wl[%i]\" ",wl_i);
		wl.write(mFile);
		fprintf(mFile,";\n");

	}
	void setWeights(size_t wl_i,size_t w_i,double w)
	{
		if(w == 0.0) return;
		fprintf(mFile,"setAttr \".wl[%i].w[%i]\" %f;\n", wl_i,w_i,w);

	}
	void setBindPreMatrix(size_t pm_i,const matrix& pm)
	{
		if(pm == identity) return;
		fprintf(mFile,"setAttr \".pm[%i]\" -type \"matrix\" ",pm_i);
		pm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setGeomMatrix(const matrix& gm)
	{
		if(gm == identity) return;
		fprintf(mFile,"setAttr \".gm\" -type \"matrix\" ");
		gm.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMatrix(size_t ma_i,const matrix& ma)
	{
		if(ma == identity) return;
		fprintf(mFile,"setAttr \".ma[%i]\" -type \"matrix\" ",ma_i);
		ma.write(mFile);
		fprintf(mFile,";\n");

	}
	void setDropoff(size_t dpf_i,double dpf)
	{
		if(dpf == 4.0) return;
		fprintf(mFile,"setAttr \".dpf[%i]\" %f;\n", dpf_i,dpf);

	}
	void setSmoothness(size_t smt_i,double smt)
	{
		if(smt == 0.0) return;
		fprintf(mFile,"setAttr \".smt[%i]\" %f;\n", smt_i,smt);

	}
	void setLockWeights(size_t lw_i,bool lw)
	{
		if(lw == false) return;
		fprintf(mFile,"setAttr \".lw[%i]\" %i;\n", lw_i,lw);

	}
	void setMaintainMaxInfluences(bool mmi)
	{
		if(mmi == false) return;
		fprintf(mFile,"setAttr \".mmi\" %i;\n", mmi);

	}
	void setMaxInfluences(int mi)
	{
		if(mi == 2) return;
		fprintf(mFile,"setAttr \".mi\" %i;\n", mi);

	}
	void setBindMethod(int bm)
	{
		if(bm == 1) return;
		fprintf(mFile,"setAttr \".bm\" %i;\n", bm);

	}
	void setPaintWeights(const doubleArray& ptw)
	{
		if(ptw.size == 0) return;
		fprintf(mFile,"setAttr \".ptw\" -type \"doubleArray\" ");
		ptw.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUseComponents(bool uc)
	{
		if(uc == 0) return;
		fprintf(mFile,"setAttr \".uc\" %i;\n", uc);

	}
	void setNurbsSamples(size_t ns_i,int ns)
	{
		if(ns == 10) return;
		fprintf(mFile,"setAttr \".ns[%i]\" %i;\n", ns_i,ns);

	}
	void setUseComponentsMatrix(bool ucm)
	{
		if(ucm == false) return;
		fprintf(mFile,"setAttr \".ucm\" %i;\n", ucm);

	}
	void setNormalizeWeights(bool nw)
	{
		if(nw == true) return;
		fprintf(mFile,"setAttr \".nw\" %i;\n", nw);

	}
	void setDeformUserNormals(bool dun)
	{
		if(dun == true) return;
		fprintf(mFile,"setAttr \".dun\" %i;\n", dun);

	}
	void getWeightList(size_t wl_i)
	{
		fprintf(mFile,"\"%s.wl[%i]\"",mName.c_str(),wl_i);

	}
	void getWeights(size_t wl_i,size_t w_i)
	{
		fprintf(mFile,"\"%s.wl[%i].w[%i]\"",mName.c_str(),wl_i,w_i);

	}
	void getBindPreMatrix(size_t pm_i)
	{
		fprintf(mFile,"\"%s.pm[%i]\"",mName.c_str(),pm_i);

	}
	void getGeomMatrix()
	{
		fprintf(mFile,"\"%s.gm\"",mName.c_str());

	}
	void getMatrix(size_t ma_i)
	{
		fprintf(mFile,"\"%s.ma[%i]\"",mName.c_str(),ma_i);

	}
	void getDropoffRate()
	{
		fprintf(mFile,"\"%s.dr\"",mName.c_str());

	}
	void getDropoff(size_t dpf_i)
	{
		fprintf(mFile,"\"%s.dpf[%i]\"",mName.c_str(),dpf_i);

	}
	void getSmoothness(size_t smt_i)
	{
		fprintf(mFile,"\"%s.smt[%i]\"",mName.c_str(),smt_i);

	}
	void getLockWeights(size_t lw_i)
	{
		fprintf(mFile,"\"%s.lw[%i]\"",mName.c_str(),lw_i);

	}
	void getMaintainMaxInfluences()
	{
		fprintf(mFile,"\"%s.mmi\"",mName.c_str());

	}
	void getMaxInfluences()
	{
		fprintf(mFile,"\"%s.mi\"",mName.c_str());

	}
	void getBindMethod()
	{
		fprintf(mFile,"\"%s.bm\"",mName.c_str());

	}
	void getDriverPoints(size_t drp_i)
	{
		fprintf(mFile,"\"%s.drp[%i]\"",mName.c_str(),drp_i);

	}
	void getBasePoints(size_t bsp_i)
	{
		fprintf(mFile,"\"%s.bsp[%i]\"",mName.c_str(),bsp_i);

	}
	void getBaseDirty()
	{
		fprintf(mFile,"\"%s.bsd\"",mName.c_str());

	}
	void getPaintWeights()
	{
		fprintf(mFile,"\"%s.ptw\"",mName.c_str());

	}
	void getPaintTrans()
	{
		fprintf(mFile,"\"%s.ptt\"",mName.c_str());

	}
	void getPaintArrDirty()
	{
		fprintf(mFile,"\"%s.pad\"",mName.c_str());

	}
	void getUseComponents()
	{
		fprintf(mFile,"\"%s.uc\"",mName.c_str());

	}
	void getNurbsSamples(size_t ns_i)
	{
		fprintf(mFile,"\"%s.ns[%i]\"",mName.c_str(),ns_i);

	}
	void getUseComponentsMatrix()
	{
		fprintf(mFile,"\"%s.ucm\"",mName.c_str());

	}
	void getNormalizeWeights()
	{
		fprintf(mFile,"\"%s.nw\"",mName.c_str());

	}
	void getDeformUserNormals()
	{
		fprintf(mFile,"\"%s.dun\"",mName.c_str());

	}
	void getWtDrty()
	{
		fprintf(mFile,"\"%s.wtd\"",mName.c_str());

	}
	void getBindPose()
	{
		fprintf(mFile,"\"%s.bp\"",mName.c_str());

	}
protected:
	SkinCluster(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):GeometryFilter(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_SKINCLUSTER_H__
