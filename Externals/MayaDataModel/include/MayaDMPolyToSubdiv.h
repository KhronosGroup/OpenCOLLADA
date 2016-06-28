/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_POLYTOSUBDIV_H__
#define __MayaDM_POLYTOSUBDIV_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMDependNode.h"
namespace MayaDM
{
class PolyToSubdiv : public DependNode
{
public:
	struct CachedUVs{
		float2* uvPoints;
		size_t nbUvPoints;
		void write(FILE* file) const
		{
			for (size_t i = 0; i<nbUvPoints; ++i)
			{
				uvPoints[i].write(file);
				if (i + 1<nbUvPoints) fprintf(file, " ");
			}
		}
	};
public:

	PolyToSubdiv():DependNode(){}
	PolyToSubdiv(FILE* file,const std::string& name,const std::string& parent="",bool shared=false,bool create=true)
		:DependNode(file, name, parent, "polyToSubdiv", shared, create){}
	virtual ~PolyToSubdiv(){}

	void setInMesh(const mesh& i_)
	{
		fprintf(mFile,"\tsetAttr \".i\" -type \"mesh\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");
	}
	void setMaxPolyCount(int mpc)
	{
		if(mpc == 1000) return;
		fprintf(mFile,"\tsetAttr \".mpc\" %i;\n", mpc);
	}
	void setMaxEdgesPerVert(int me)
	{
		if(me == 32) return;
		fprintf(mFile,"\tsetAttr \".me\" %i;\n", me);
	}
	void setApplyMatrixToResult(bool amr)
	{
		if(amr == true) return;
		fprintf(mFile,"\tsetAttr \".amr\" %i;\n", amr);
	}
	void setAbsolutePosition(bool ap)
	{
		if(ap == false) return;
		fprintf(mFile,"\tsetAttr \".ap\" %i;\n", ap);
	}
	void setUvTreatment(unsigned int uvt)
	{
		if(uvt == 0) return;
		fprintf(mFile,"\tsetAttr \".uvt\" %i;\n", uvt);
	}
	void setCachedUVs(size_t cuv_i,const CachedUVs& cuv)
	{
		fprintf(mFile,"\tsetAttr \".cuv[%i]\" ",cuv_i);
		cuv.write(mFile);
		fprintf(mFile,";\n");
	}
	void setCachedUVs(size_t cuv_start,size_t cuv_end,CachedUVs* cuv)
	{
		fprintf(mFile,"\tsetAttr \".cuv[%i:%i]\" ", cuv_start,cuv_end);
		size_t size = (cuv_end-cuv_start)*1+1;
		for(size_t i=0;i<size;++i)
		{
			cuv[i].write(mFile);
			fprintf(mFile,"\n");
		}
		fprintf(mFile,";\n");
	}
	void startCachedUVs(size_t cuv_start,size_t cuv_end)const
	{
		fprintf(mFile,"\tsetAttr \".cuv[%i:%i]\"",cuv_start,cuv_end);
		fprintf(mFile," -type \"CachedUVs\" ");
	}
	void appendCachedUVs(const CachedUVs& cuv)const
	{
		fprintf(mFile," ");
		cuv.write(mFile);
	}
	void endCachedUVs()const
	{
		fprintf(mFile,";\n");
	}
	void setUvPoints(size_t cuv_i,size_t uvp_i,const float2& uvp)
	{
		fprintf(mFile,"\tsetAttr \".cuv[%i].uvp[%i]\" -type \"float2\" ",cuv_i,uvp_i);
		uvp.write(mFile);
		fprintf(mFile,";\n");
	}
	void setUvPoints(size_t cuv_i,size_t uvp_start,size_t uvp_end,float* uvp)
	{
		fprintf(mFile,"\tsetAttr \".cuv[%i].uvp[%i:%i]\" ", cuv_i,uvp_start,uvp_end);
		size_t size = (uvp_end-uvp_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uvp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");
	}
	void startUvPoints(size_t cuv_i,size_t uvp_start,size_t uvp_end)const
	{
		fprintf(mFile,"\tsetAttr \".cuv[%i].uvp[%i:%i]\"",cuv_i,uvp_start,uvp_end);
	}
	void appendUvPoints(float uvp)const
	{
		fprintf(mFile," %f",uvp);
	}
	void endUvPoints()const
	{
		fprintf(mFile,";\n");
	}
	void setUvPointsU(size_t cuv_i,size_t uvp_i,float uvu)
	{
		if(uvu == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cuv[%i].uvp[%i].uvu\" %f;\n", cuv_i,uvp_i,uvu);
	}
	void setUvPointsV(size_t cuv_i,size_t uvp_i,float uvv)
	{
		if(uvv == 0.0) return;
		fprintf(mFile,"\tsetAttr \".cuv[%i].uvp[%i].uvv\" %f;\n", cuv_i,uvp_i,uvv);
	}
	void setPreserveVertexOrdering(bool pvo)
	{
		if(pvo == true) return;
		fprintf(mFile,"\tsetAttr \".pvo\" %i;\n", pvo);
	}
	void setQuickConvert(bool qc)
	{
		if(qc == true) return;
		fprintf(mFile,"\tsetAttr \".qc\" %i;\n", qc);
	}
	void getInMesh()const
	{
		fprintf(mFile,"\"%s.i\"",mName.c_str());
	}
	void getOutSubdiv()const
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());
	}
	void getMaxPolyCount()const
	{
		fprintf(mFile,"\"%s.mpc\"",mName.c_str());
	}
	void getMaxEdgesPerVert()const
	{
		fprintf(mFile,"\"%s.me\"",mName.c_str());
	}
	void getApplyMatrixToResult()const
	{
		fprintf(mFile,"\"%s.amr\"",mName.c_str());
	}
	void getAbsolutePosition()const
	{
		fprintf(mFile,"\"%s.ap\"",mName.c_str());
	}
	void getUvTreatment()const
	{
		fprintf(mFile,"\"%s.uvt\"",mName.c_str());
	}
	void getCachedUVs(size_t cuv_i)const
	{
		fprintf(mFile,"\"%s.cuv[%i]\"",mName.c_str(),cuv_i);
	}
	void getCachedUVs()const
	{

		fprintf(mFile,"\"%s.cuv\"",mName.c_str());
	}
	void getUvPoints(size_t cuv_i,size_t uvp_i)const
	{
		fprintf(mFile,"\"%s.cuv[%i].uvp[%i]\"",mName.c_str(),cuv_i,uvp_i);
	}
	void getUvPoints(size_t uvp_i)const
	{

		fprintf(mFile,"\"%s.cuv.uvp[%i]\"",mName.c_str(),uvp_i);
	}
	void getUvPointsU(size_t cuv_i,size_t uvp_i)const
	{
		fprintf(mFile,"\"%s.cuv[%i].uvp[%i].uvu\"",mName.c_str(),cuv_i,uvp_i);
	}
	void getUvPointsU(size_t uvp_i)const
	{

		fprintf(mFile,"\"%s.cuv.uvp[%i].uvu\"",mName.c_str(),uvp_i);
	}
	void getUvPointsV(size_t cuv_i,size_t uvp_i)const
	{
		fprintf(mFile,"\"%s.cuv[%i].uvp[%i].uvv\"",mName.c_str(),cuv_i,uvp_i);
	}
	void getUvPointsV(size_t uvp_i)const
	{

		fprintf(mFile,"\"%s.cuv.uvp[%i].uvv\"",mName.c_str(),uvp_i);
	}
	void getPreserveVertexOrdering()const
	{
		fprintf(mFile,"\"%s.pvo\"",mName.c_str());
	}
	void getQuickConvert()const
	{
		fprintf(mFile,"\"%s.qc\"",mName.c_str());
	}
protected:
	PolyToSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType,bool shared=false,bool create=true)
		:DependNode(file, name, parent, nodeType, shared, create) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTOSUBDIV_H__
