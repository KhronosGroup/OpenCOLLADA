/*
    Copyright (c) 2008 NetAllied Systems GmbH

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
		void write(FILE* file) const
		{
			size_t size = sizeof(uvPoints)/sizeof(float2);
			for(size_t i=0; i<size; ++i)
			{
				uvPoints[i].write(file);
				if(i+1<size) fprintf(file," ");
			}
		}
	};
public:
	PolyToSubdiv(FILE* file,const std::string& name,const std::string& parent=""):DependNode(file, name, parent, "polyToSubdiv"){}
	virtual ~PolyToSubdiv(){}
	void setInMesh(const mesh& i_)
	{
		fprintf(mFile,"setAttr \".i\" -type \"mesh\" ");
		i_.write(mFile);
		fprintf(mFile,";\n");

	}
	void setMaxPolyCount(int mpc)
	{
		if(mpc == 1000) return;
		fprintf(mFile,"setAttr \".mpc\" %i;\n", mpc);

	}
	void setMaxEdgesPerVert(int me)
	{
		if(me == 32) return;
		fprintf(mFile,"setAttr \".me\" %i;\n", me);

	}
	void setApplyMatrixToResult(bool amr)
	{
		if(amr == true) return;
		fprintf(mFile,"setAttr \".amr\" %i;\n", amr);

	}
	void setAbsolutePosition(bool ap)
	{
		if(ap == false) return;
		fprintf(mFile,"setAttr \".ap\" %i;\n", ap);

	}
	void setUvTreatment(unsigned int uvt)
	{
		if(uvt == 0) return;
		fprintf(mFile,"setAttr \".uvt\" %i;\n", uvt);

	}
	void setCachedUVs(size_t cuv_i,const CachedUVs& cuv)
	{
		fprintf(mFile,"setAttr \".cuv[%i]\" ",cuv_i);
		cuv.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvPoints(size_t cuv_i,size_t uvp_i,const float2& uvp)
	{
		fprintf(mFile,"setAttr \".cuv[%i].uvp[%i]\" -type \"float2\" ",cuv_i,uvp_i);
		uvp.write(mFile);
		fprintf(mFile,";\n");

	}
	void setUvPoints(size_t cuv_i,size_t uvp_start,size_t uvp_end,float* uvp)
	{
		fprintf(mFile,"setAttr \".cuv[%i].uvp[%i:%i]\" ", cuv_i,uvp_start,uvp_end);
		size_t size = (uvp_end-uvp_start)*2+2;
		for(size_t i=0;i<size;++i)
		{
			fprintf(mFile,"%f",uvp[i]);
			if(i+1<size) fprintf(mFile," ");
		}
		fprintf(mFile,";\n");

	}
	void startUvPoints(size_t cuv_i,size_t uvp_start,size_t uvp_end)
	{
		fprintf(mFile,"setAttr \".cuv[%i].uvp[%i:%i]\"",cuv_i,uvp_start,uvp_end);

	}
	void appendUvPoints(float uvp)
	{
		fprintf(mFile," %f",uvp);

	}
	void endUvPoints()
	{
		fprintf(mFile,";\n");

	}
	void setUvPointsU(size_t cuv_i,size_t uvp_i,float uvu)
	{
		if(uvu == 0.0) return;
		fprintf(mFile,"setAttr \".cuv[%i].uvp[%i].uvu\" %f;\n", cuv_i,uvp_i,uvu);

	}
	void setUvPointsV(size_t cuv_i,size_t uvp_i,float uvv)
	{
		if(uvv == 0.0) return;
		fprintf(mFile,"setAttr \".cuv[%i].uvp[%i].uvv\" %f;\n", cuv_i,uvp_i,uvv);

	}
	void setPreserveVertexOrdering(bool pvo)
	{
		if(pvo == true) return;
		fprintf(mFile,"setAttr \".pvo\" %i;\n", pvo);

	}
	void setQuickConvert(bool qc)
	{
		if(qc == true) return;
		fprintf(mFile,"setAttr \".qc\" %i;\n", qc);

	}
	void getOutSubdiv()
	{
		fprintf(mFile,"\"%s.o\"",mName.c_str());

	}
	void getMaxPolyCount()
	{
		fprintf(mFile,"\"%s.mpc\"",mName.c_str());

	}
	void getMaxEdgesPerVert()
	{
		fprintf(mFile,"\"%s.me\"",mName.c_str());

	}
	void getApplyMatrixToResult()
	{
		fprintf(mFile,"\"%s.amr\"",mName.c_str());

	}
	void getAbsolutePosition()
	{
		fprintf(mFile,"\"%s.ap\"",mName.c_str());

	}
	void getUvTreatment()
	{
		fprintf(mFile,"\"%s.uvt\"",mName.c_str());

	}
	void getCachedUVs(size_t cuv_i)
	{
		fprintf(mFile,"\"%s.cuv[%i]\"",mName.c_str(),cuv_i);

	}
	void getUvPoints(size_t cuv_i,size_t uvp_i)
	{
		fprintf(mFile,"\"%s.cuv[%i].uvp[%i]\"",mName.c_str(),cuv_i,uvp_i);

	}
	void getUvPointsU(size_t cuv_i,size_t uvp_i)
	{
		fprintf(mFile,"\"%s.cuv[%i].uvp[%i].uvu\"",mName.c_str(),cuv_i,uvp_i);

	}
	void getUvPointsV(size_t cuv_i,size_t uvp_i)
	{
		fprintf(mFile,"\"%s.cuv[%i].uvp[%i].uvv\"",mName.c_str(),cuv_i,uvp_i);

	}
	void getPreserveVertexOrdering()
	{
		fprintf(mFile,"\"%s.pvo\"",mName.c_str());

	}
	void getQuickConvert()
	{
		fprintf(mFile,"\"%s.qc\"",mName.c_str());

	}
protected:
	PolyToSubdiv(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):DependNode(file, name, parent, nodeType) {}

};
}//namespace MayaDM
#endif//__MayaDM_POLYTOSUBDIV_H__
